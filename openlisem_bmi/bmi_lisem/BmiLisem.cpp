/*************************************************************************
**  openLISEM native C++ BMI wrapper — implementation
**
**  Phase B1: lifecycle + time are functional, mirroring the headless
**  ("-ni -bmistep") branch of model/main.cpp. All variable/grid access
**  methods throw until phases B2/B3.
*************************************************************************/

#include "BmiLisem.h"

#include <stdexcept>
#include <cstring>   // memcpy

#include <QLocale>
#include <QString>
#include <QFileInfo>

#include "model.h"        // TWorld; defines LDD_COORIN used by LisUIoutput.h
#include "LisUIoutput.h"  // defines 'output' struct (needs model.h first)
#include "global.h"       // extern output op (needs LisUIoutput.h first)
#include "CsfMap.h"       // cTMap: north()/west()/cellSize(), .data MaskedRaster

// Helper to keep stub bodies short and self-describing.
#define BMI_NOT_IMPLEMENTED() \
    throw std::runtime_error(std::string(__func__) + ": not implemented (B2/B3)")

BmiLisem::~BmiLisem()
{
    if (model) {
        // best-effort cleanup if Finalize() was never called by the driver
        delete model;
        model = nullptr;
    }
}

//---------------------------------------------------------------------------
// Model control
//---------------------------------------------------------------------------
void BmiLisem::Initialize(std::string config_file)
{
    if (model)
        throw std::runtime_error("BmiLisem::Initialize: already initialized");

    model = new TWorld();

    // headless / BMI configuration — mirrors model/main.cpp -ni -bmistep branch
    model->noInterface   = true;
    model->bmiMode       = true;
    model->stopRequested = false;
    model->waitRequested = false;

    // runfile numbers always use '.' decimal — pin the C locale
    model->loc = QLocale::c();
    model->loc.setNumberOptions(QLocale::c().numberOptions());
    QLocale::setDefault(model->loc);

    // global output structure: point the engine at the runfile, batch mode
    op.runfilename = QString::fromStdString(config_file);
    op.doBatchmode = true;
    op.forceResDir = false;

    if (!QFileInfo(op.runfilename).exists())
        throw std::runtime_error("BmiLisem::Initialize: runfile not found: " + config_file);

    model->Initialize();   // InitializeStatic + SnapshotInitialState + scalar resets
    model->avgTheta();     // initialise ThetaI*a so they are valid at t0

    buildVarRegistry();    // maps are allocated now — wire standard names to them
}

//---------------------------------------------------------------------------
// Output variable registry + grid helpers
//---------------------------------------------------------------------------
void BmiLisem::buildVarRegistry()
{
    _out_names.clear(); _out_maps.clear();
    _in_names.clear();  _in_maps.clear();
    _all_maps.clear();  _all_units.clear();
    _scalar_out_names.clear(); _scalar_out_ptrs.clear(); _scalar_out_units.clear();

    // --- Raster (grid 0) variables ---
    // Each entry: name, map pointer, units string, is_input, is_output.
    struct VarDef { const char *name; cTMap *map; const char *units; bool in; bool out; };
    const VarDef defs[] = {
        // existing outputs
        { "land_surface_water__depth",            model->WH,             "m",      false, true  },
        { "channel_water__volume_flow_rate",      model->Qn,             "m3 s-1", false, true  },
        { "soil_water__infiltration_depth",       model->Fcum,           "m",      false, true  },
        // existing input + output (initial θ — does NOT change during run)
        { "soil_water__volume_fraction",          model->ThetaI1,        "m3 m-3", true,  true  },
        // existing input-only
        { "land_vegetation__cover_fraction",      model->Cover,          "1",      true,  false },
        // --- new coupling outputs ---
        // post-event actual soil moisture per layer (updated by avgTheta() each step)
        { "soil_water__volume_fraction_in_layer_1", model->ThetaI1a,     "m3 m-3", false, true  },
        { "soil_water__volume_fraction_in_layer_2", model->ThetaI2a,     "m3 m-3", false, true  },
        { "soil_water__volume_fraction_in_layer_3", model->ThetaI3a,     "m3 m-3", false, true  },
        // soil layer bottom depths for depth-mapping
        { "soil__layer_depth_1",                  model->SoilDepth1,     "m",      false, true  },
        { "soil__layer_depth_2",                  model->SoilDepth2,     "m",      false, true  },
        { "soil__layer_depth_3",                  model->SoilDepth3,     "m",      false, true  },
        // net soil loss per unit area (TotalSoillossMap is in kg/cell; scaled in GetValue)
        { "soil__erosion_mass_per_area",          model->TotalSoillossMap, "kg m-2", false, true },
    };

    for (const VarDef &d : defs) {
        if (!d.map)
            continue;  // map inactive / layer disabled for this run config
        _all_maps[d.name]  = d.map;
        _all_units[d.name] = d.units;
        if (d.in)  { _in_names.emplace_back(d.name);  _in_maps[d.name]  = d.map; }
        if (d.out) { _out_names.emplace_back(d.name); _out_maps[d.name] = d.map; }
    }

    // Scalar control signal (grid 1, rank 0): writing any value triggers ResetEvent.
    // Kept outside the map-based registry because it has no backing cTMap.
    _in_names.emplace_back("model__reset_event");
    _all_units["model__reset_event"] = "1";

    // --- Scalar (grid 1) outputs: catchment water-balance totals (all m3) ---
    // Sources: TWorld double members updated by MassBalance() each timestep.
    // Balance: RainTot = IntercTot + InfilTot + ETaTotVol + SoilMoistTot + Qtot
    // (see lisTotalsMB.cpp lines 540-542 for the full MB equation)
    struct ScalarDef { const char *name; double *ptr; const char *units; };
    const ScalarDef sdefs[] = {
        { "domain_rainfall__volume",           &model->RainTot,      "m3" },
        { "domain_interception__volume",       &model->IntercTot,    "m3" },
        { "domain_infiltration__volume",       &model->InfilTot,     "m3" },
        { "domain_evapotranspiration__volume", &model->ETaTotVol,    "m3" },
        { "domain_soil_water_storage__volume", &model->SoilMoistTot, "m3" },
        // Qtot is the total outflow used to close the MB (lisTotalsMB.cpp line 371/542)
        { "domain_runoff__volume",             &model->Qtot,         "m3" },
    };
    for (const ScalarDef &s : sdefs) {
        _scalar_out_names.emplace_back(s.name);
        _out_names.emplace_back(s.name);         // unified output list
        _scalar_out_ptrs[s.name]  = s.ptr;
        _scalar_out_units[s.name] = s.units;
        _all_units[s.name]        = s.units;
    }
}

cTMap *BmiLisem::resolveVar(const std::string &name) const
{
    auto it = _all_maps.find(name);
    if (it == _all_maps.end())
        throw std::runtime_error("BmiLisem: unknown variable '" + name + "'");
    return it->second;
}

bool BmiLisem::isScalarOutput(const std::string &name) const
{
    return _scalar_out_ptrs.count(name) > 0;
}

int BmiLisem::nCells() const
{
    if (!model)
        throw std::runtime_error("BmiLisem::nCells: not initialized");
    return model->_nrRows * model->_nrCols;
}

cTMap *BmiLisem::refMap() const
{
    // LDD is the catchment mask map and is always allocated; use it for geometry.
    if (!model || !model->LDD)
        throw std::runtime_error("BmiLisem::refMap: no reference map available");
    return model->LDD;
}

void BmiLisem::Update()
{
    if (!model)
        throw std::runtime_error("BmiLisem::Update: not initialized");
    model->Update();
    model->avgTheta();   // keep ThetaI*a current for BMI reads
}

void BmiLisem::UpdateUntil(double time)
{
    if (!model)
        throw std::runtime_error("BmiLisem::UpdateUntil: not initialized");
    while (model->time < time && model->time < model->EndTime) {
        if (!model->Update())
            break;
    }
}

void BmiLisem::Finalize()
{
    if (model) {
        model->Finalize();
        delete model;
        model = nullptr;
    }
}

//---------------------------------------------------------------------------
// Custom coupling hook (non-standard)
//---------------------------------------------------------------------------
void BmiLisem::ResetEvent()
{
    if (!model)
        throw std::runtime_error("BmiLisem::ResetEvent: not initialized");
    model->ResetEvent();
}

//---------------------------------------------------------------------------
// Time control (functional)
//---------------------------------------------------------------------------
double BmiLisem::GetStartTime()   { return model ? model->BeginTime : 0.0; }
double BmiLisem::GetEndTime()     { return model ? model->EndTime   : 0.0; }
double BmiLisem::GetCurrentTime() { return model ? model->time      : 0.0; }
double BmiLisem::GetTimeStep()    { return model ? model->_dt       : 0.0; }
std::string BmiLisem::GetTimeUnits() { return "s"; }

//---------------------------------------------------------------------------
// Model information (component name functional; item lists stubbed)
//---------------------------------------------------------------------------
std::string BmiLisem::GetComponentName() { return "OpenLISEM"; }

int BmiLisem::GetInputItemCount()  { return static_cast<int>(_in_names.size()); }
int BmiLisem::GetOutputItemCount() { return static_cast<int>(_out_names.size()); }
std::vector<std::string> BmiLisem::GetInputVarNames()  { return _in_names; }
std::vector<std::string> BmiLisem::GetOutputVarNames() { return _out_names; }

//---------------------------------------------------------------------------
// Variable information (stubbed)
//---------------------------------------------------------------------------
static bool isScalarControl(const std::string &name) { return name == "model__reset_event"; }

int BmiLisem::GetVarGrid(std::string name)
{
    if (isScalarControl(name) || isScalarOutput(name)) return 1;
    resolveVar(name); return 0;
}
std::string BmiLisem::GetVarType(std::string name)
{
    if (isScalarControl(name) || isScalarOutput(name)) return "double";
    resolveVar(name); return "double";
}
std::string BmiLisem::GetVarUnits(std::string name)
{
    auto it = _all_units.find(name);
    if (it != _all_units.end()) return it->second;
    throw std::runtime_error("BmiLisem: unknown variable '" + name + "'");
}
int BmiLisem::GetVarItemsize(std::string name)
{
    if (isScalarControl(name) || isScalarOutput(name)) return static_cast<int>(sizeof(double));
    resolveVar(name); return static_cast<int>(sizeof(Real));
}
int BmiLisem::GetVarNbytes(std::string name)
{
    if (isScalarControl(name) || isScalarOutput(name)) return static_cast<int>(sizeof(double));
    resolveVar(name); return nCells() * static_cast<int>(sizeof(Real));
}
std::string BmiLisem::GetVarLocation(std::string name)
{
    if (isScalarControl(name) || isScalarOutput(name)) return "node";
    resolveVar(name); return "node";
}

//---------------------------------------------------------------------------
// Variable getters (stubbed)
//---------------------------------------------------------------------------
void BmiLisem::GetValue(std::string name, void *dest)
{
    // Scalar catchment totals (grid 1)
    if (isScalarOutput(name)) {
        std::memcpy(dest, _scalar_out_ptrs.at(name), sizeof(double));
        return;
    }
    cTMap *m = resolveVar(name);
    // Erosion map is stored as kg/cell; expose as kg/m²
    if (name == "soil__erosion_mass_per_area") {
        const Real factor = static_cast<Real>(1.0 / (model->_dx * model->_dx));
        Real *out = static_cast<Real *>(dest);
        const int n = nCells();
        for (int i = 0; i < n; ++i)
            out[i] = m->data.cell(static_cast<size_t>(i)) * factor;
        return;
    }
    std::memcpy(dest, &m->data.cell(0), static_cast<size_t>(nCells()) * sizeof(Real));
}

void *BmiLisem::GetValuePtr(std::string name)
{
    // Scalar catchment totals: return pointer to the TWorld double
    if (isScalarOutput(name))
        return static_cast<void *>(_scalar_out_ptrs.at(name));
    // Erosion map requires on-the-fly scaling; a raw pointer would give kg/cell.
    // Callers that need kg/m² must use GetValue instead.
    cTMap *m = resolveVar(name);
    return &m->data.cell(0);
}

void BmiLisem::GetValueAtIndices(std::string /*name*/, void * /*dest*/, int * /*inds*/, int /*count*/) { BMI_NOT_IMPLEMENTED(); }

//---------------------------------------------------------------------------
// Variable setters (stubbed)
//---------------------------------------------------------------------------
void BmiLisem::SetValue(std::string name, void *src)
{
    // Control signal: any write triggers ResetEvent; the buffer value is ignored.
    if (name == "model__reset_event") { model->ResetEvent(); return; }

    cTMap *m = resolveVar(name);
    const size_t nbytes = m->data.nr_cells() * sizeof(Real);
    std::memcpy(&m->data.cell(0), src, nbytes);
}

void BmiLisem::SetValueAtIndices(std::string name, int *inds, int count, void *src)
{
    cTMap *m = resolveVar(name);
    const Real *vals = static_cast<const Real *>(src);
    for (int i = 0; i < count; ++i)
        m->data.cell(static_cast<size_t>(inds[i])) = vals[i];
}

//---------------------------------------------------------------------------
// Grid information (stubbed)
//---------------------------------------------------------------------------
static void checkGrid(const int grid)
{
    if (grid != 0 && grid != 1)
        throw std::runtime_error("BmiLisem: valid grid ids are 0 (raster) and 1 (scalar)");
}

int BmiLisem::GetGridRank(const int grid) { checkGrid(grid); return (grid == 1) ? 0 : 2; }
int BmiLisem::GetGridSize(const int grid) { checkGrid(grid); return (grid == 1) ? 1 : nCells(); }
std::string BmiLisem::GetGridType(const int grid) {
    checkGrid(grid);
    return (grid == 1) ? "scalar" : "uniform_rectilinear";
}

void BmiLisem::GetGridShape(const int grid, int *shape)
{
    if (grid == 1) return;   // rank-0 scalar: no shape
    checkGrid(grid);
    shape[0] = model->_nrRows;   // rows  (y)
    shape[1] = model->_nrCols;   // cols  (x)
}

void BmiLisem::GetGridSpacing(const int grid, double *spacing)
{
    if (grid == 1) return;   // rank-0 scalar: no spacing
    checkGrid(grid);
    const double cs = refMap()->cellSize();
    spacing[0] = cs;   // y spacing
    spacing[1] = cs;   // x spacing (square cells)
}

void BmiLisem::GetGridOrigin(const int grid, double *origin)
{
    if (grid == 1) return;   // rank-0 scalar: no origin
    checkGrid(grid);
    cTMap *m = refMap();
    origin[0] = m->north();   // y origin
    origin[1] = m->west();    // x origin
}

void BmiLisem::GetGridX(const int /*grid*/, double * /*x*/) { BMI_NOT_IMPLEMENTED(); }
void BmiLisem::GetGridY(const int /*grid*/, double * /*y*/) { BMI_NOT_IMPLEMENTED(); }
void BmiLisem::GetGridZ(const int /*grid*/, double * /*z*/) { BMI_NOT_IMPLEMENTED(); }

int BmiLisem::GetGridNodeCount(const int /*grid*/) { BMI_NOT_IMPLEMENTED(); }
int BmiLisem::GetGridEdgeCount(const int /*grid*/) { BMI_NOT_IMPLEMENTED(); }
int BmiLisem::GetGridFaceCount(const int /*grid*/) { BMI_NOT_IMPLEMENTED(); }

void BmiLisem::GetGridEdgeNodes(const int /*grid*/, int * /*edge_nodes*/) { BMI_NOT_IMPLEMENTED(); }
void BmiLisem::GetGridFaceEdges(const int /*grid*/, int * /*face_edges*/) { BMI_NOT_IMPLEMENTED(); }
void BmiLisem::GetGridFaceNodes(const int /*grid*/, int * /*face_nodes*/) { BMI_NOT_IMPLEMENTED(); }
void BmiLisem::GetGridNodesPerFace(const int /*grid*/, int * /*nodes_per_face*/) { BMI_NOT_IMPLEMENTED(); }

//---------------------------------------------------------------------------
// C factory (CSDMS / babelizer convention for C++ BMI components).
// babelizer's generated Cython binding calls bmi_model() to obtain an
// instance and bmi_model_free() to dispose of it.
//---------------------------------------------------------------------------
extern "C" {
    bmi::Bmi *bmi_model() { return new BmiLisem(); }
    void bmi_model_free(bmi::Bmi *m) { delete m; }
}
