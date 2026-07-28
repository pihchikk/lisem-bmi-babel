/*************************************************************************
**  openLISEM native C++ BMI wrapper — implementation
**
**  Phase B1: lifecycle + time are functional, mirroring the headless
**  ("-ni -bmistep") branch of model/main.cpp. All variable/grid access
**  methods throw until phases B2/B3.
*************************************************************************/

#include "BmiLisem.h"

#include <stdexcept>
#include <cstring>          // memcpy
#include <unordered_map>   // alias table

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
// Standard-name alias layer
//
// The registry stores CANONICAL ESoil standard names. For backward
// compatibility the legacy CSDMS names (object__quantity) are accepted on
// every name-keyed BMI call and mapped to the canonical name here. Canonical
// names — and any name not in the table — pass through unchanged, so both
// spellings resolve to the same variable while GetOutputVarNames()/
// GetInputVarNames() advertise only the canonical names.
//
// Coupling-critical names (soil_water_actual, plant_cover~projective,
// soil_water_actual_layer-N) are kept identical to the AquaCrop BMI so the two
// components exchange variables by a shared vocabulary.
//---------------------------------------------------------------------------
std::string BmiLisem::resolveVarAlias(const std::string &name)
{
    static const std::unordered_map<std::string, std::string> kAlias = {
        { "soil_water__volume_fraction",            "soil_water_actual" },
        { "land_vegetation__cover_fraction",        "plant_cover~projective" },
        { "soil_water__volume_fraction_in_layer_1", "soil_water_actual_layer-1" },
        { "soil_water__volume_fraction_in_layer_2", "soil_water_actual_layer-2" },
        { "soil_water__volume_fraction_in_layer_3", "soil_water_actual_layer-3" },
        { "land_surface_water__depth",              "surface-water~depth" },
        { "channel_water__volume_flow_rate",        "water~channel_discharge" },
        { "soil_water__infiltration_depth",         "soil_infiltration~amount" },
        { "soil__layer_depth_1",                    "soil_layer-depth~layer-1" },
        { "soil__layer_depth_2",                    "soil_layer-depth~layer-2" },
        { "soil__layer_depth_3",                    "soil_layer-depth~layer-3" },
        { "soil__erosion_mass_per_area",            "soil_erosion~mass-per-area" },
        { "domain_rainfall__volume",                "surface-water~rainfall_volume" },
        { "domain_interception__volume",            "surface-water~interception_volume" },
        { "domain_infiltration__volume",            "surface-water~infiltration_volume" },
        { "domain_evapotranspiration__volume",      "surface-water~evapotranspiration_volume" },
        { "domain_soil_water_storage__volume",      "surface-water~storage_volume" },
        { "domain_runoff__volume",                  "surface-water~runoff_volume" },
        { "atmosphere_water__precipitation_leq-depth", "surface-water~rainfall_amount" },
        { "surface_water__runoff_depth",            "surface-water~runoff_amount" },
    };
    auto it = kAlias.find(name);
    return it == kAlias.end() ? name : it->second;
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
    // Names are the CANONICAL ESoil standard names. Legacy CSDMS spellings are
    // accepted on input via resolveVarAlias(); GetOutputVarNames() lists only
    // these canonical names. See docs/STANDARD_NAMES_ALIASES.md.
    const VarDef defs[] = {
        // existing outputs
        { "surface-water~depth",                  model->WH,             "m",      false, true  },
        { "water~channel_discharge",              model->Qn,             "m3 s-1", false, true  },
        { "soil_infiltration~amount",             model->Fcum,           "m",      false, true  },
        // existing input + output (initial θ — does NOT change during run)
        { "soil_water_actual",                    model->ThetaI1,        "m3 m-3", true,  true  },
        // existing input-only
        { "plant_cover~projective",               model->Cover,          "1",      true,  false },
        // --- new coupling outputs ---
        // post-event actual soil moisture per layer (updated by avgTheta() each step)
        { "soil_water_actual_layer-1",            model->ThetaI1a,       "m3 m-3", false, true  },
        { "soil_water_actual_layer-2",            model->ThetaI2a,       "m3 m-3", false, true  },
        { "soil_water_actual_layer-3",            model->ThetaI3a,       "m3 m-3", false, true  },
        // soil layer bottom depths for depth-mapping
        { "soil_layer-depth~layer-1",             model->SoilDepth1,     "m",      false, true  },
        { "soil_layer-depth~layer-2",             model->SoilDepth2,     "m",      false, true  },
        { "soil_layer-depth~layer-3",             model->SoilDepth3,     "m",      false, true  },
        // net soil loss per unit area (TotalSoillossMap is in kg/cell; scaled in GetValue)
        { "soil_erosion~mass-per-area",           model->TotalSoillossMap, "kg m-2", false, true },
        // Per-cell rainfall and runoff (Gate 7.2 check (c) blocker -- see
        // docs/COUPLING_VARS_LEDGER.md's "Per-cell rainfall and runoff" section for the full
        // rationale). Both cumulative-since-last-reset, in metres, matching soil_infiltration~amount
        // exactly -- both are created via NewMap() like Fcum, so both are auto-registered in
        // maplistCTMap and zeroed by the same model__reset_event mechanism (verified, not assumed;
        // see NewMap()'s own maplistCTMap registration in lisDataFunctions.cpp).
        //
        // Rainfall: RainCumFlat is the *flat* (slope-unadjusted) cumulative rain depth in metres --
        // the exact field lisReportmaps.cpp's own rainfall.map is derived from (*1000 for mm
        // display there; exposed here in metres, unscaled, matching Fcum's own convention).
        { "surface-water~rainfall_amount",        model->RainCumFlat,    "m",      false, true  },
        // Runoff: Qm3total is cumulative *discharge volume routed through this cell* (Qn*_dt summed,
        // lisTotalsMB.cpp:347) -- NOT local runoff generation net of upstream inflow. LISEM's SWOF
        // solver has no separate "generated before routing" step (a real 2D dynamic-wave model,
        // unlike a curve-number scheme); a genuinely unused, commented-out `runoffTotalCell` field
        // exists in lisTotalsMB.cpp with a *derived* formula (rain-interception-infiltration,
        // floored at 0) that was deliberately NOT used here -- wiring a residual-derived quantity
        // would make any balance check that uses it close by construction, not by an independent
        // measurement. Qm3total is scaled from m3 to a per-cell depth (m) at GetValue time by
        // dividing by cell area (_dx*_dx), the same GetValue-time-scaling pattern already used for
        // soil_erosion~mass-per-area, so the per-cell balance's units are consistent
        // (rain/infiltration/runoff/storage all in metres) without a separate conversion step.
        // Consequence, disclosed not hidden: for cells receiving significant upstream flow, this
        // depth-equivalent overstates "locally generated" runoff (it includes water merely passing
        // through) -- the per-cell balance is expected to close best for headwater/low-accumulation
        // cells and worse for downstream ones. See docs/bmi/GATE7_2_COUPLING.md's verification for
        // measured numbers on both kinds.
        { "surface-water~runoff_amount",          model->Qm3total,       "m",      false, true  },
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
        { "surface-water~rainfall_volume",           &model->RainTot,      "m3" },
        { "surface-water~interception_volume",       &model->IntercTot,    "m3" },
        { "surface-water~infiltration_volume",       &model->InfilTot,     "m3" },
        { "surface-water~evapotranspiration_volume", &model->ETaTotVol,    "m3" },
        { "surface-water~storage_volume",            &model->SoilMoistTot, "m3" },
        // Qtot is the total outflow used to close the MB (lisTotalsMB.cpp line 371/542)
        { "surface-water~runoff_volume",             &model->Qtot,         "m3" },
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
    const std::string canon = resolveVarAlias(name);
    auto it = _all_maps.find(canon);
    if (it == _all_maps.end())
        throw std::runtime_error("BmiLisem: unknown variable '" + name + "'");
    return it->second;
}

bool BmiLisem::isScalarOutput(const std::string &name) const
{
    return _scalar_out_ptrs.count(resolveVarAlias(name)) > 0;
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
    model->avgTheta();   // refresh ThetaI*a so post-event soil moisture is
                         // current for BMI reads (Update() does this per-step)
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
    name = resolveVarAlias(name);
    if (isScalarControl(name) || isScalarOutput(name)) return 1;
    resolveVar(name); return 0;
}
std::string BmiLisem::GetVarType(std::string name)
{
    name = resolveVarAlias(name);
    // Scalars are backed by TWorld 'double' members regardless of Real precision.
    if (isScalarControl(name) || isScalarOutput(name)) return "double";
    // Raster maps store 'Real', which is float or double depending on the build
    // (see PrecisionConfig.h). Derive the type string from sizeof(Real) so the
    // Cython layer allocates a matching-width ndarray for the raw memcpy.
    resolveVar(name);
    return (sizeof(Real) == sizeof(double)) ? "double" : "float";
}
std::string BmiLisem::GetVarUnits(std::string name)
{
    name = resolveVarAlias(name);
    auto it = _all_units.find(name);
    if (it != _all_units.end()) return it->second;
    throw std::runtime_error("BmiLisem: unknown variable '" + name + "'");
}
int BmiLisem::GetVarItemsize(std::string name)
{
    name = resolveVarAlias(name);
    if (isScalarControl(name) || isScalarOutput(name)) return static_cast<int>(sizeof(double));
    resolveVar(name); return static_cast<int>(sizeof(Real));
}
int BmiLisem::GetVarNbytes(std::string name)
{
    name = resolveVarAlias(name);
    if (isScalarControl(name) || isScalarOutput(name)) return static_cast<int>(sizeof(double));
    resolveVar(name); return nCells() * static_cast<int>(sizeof(Real));
}
std::string BmiLisem::GetVarLocation(std::string name)
{
    name = resolveVarAlias(name);
    if (isScalarControl(name) || isScalarOutput(name)) return "node";
    resolveVar(name); return "node";
}

//---------------------------------------------------------------------------
// Variable getters (stubbed)
//---------------------------------------------------------------------------
void BmiLisem::GetValue(std::string name, void *dest)
{
    name = resolveVarAlias(name);
    // Scalar catchment totals (grid 1)
    if (isScalarOutput(name)) {
        std::memcpy(dest, _scalar_out_ptrs.at(name), sizeof(double));
        return;
    }
    cTMap *m = resolveVar(name);
    // Erosion map is stored as kg/cell; expose as kg/m² (canonical name after resolve)
    if (name == "soil_erosion~mass-per-area") {
        const Real factor = static_cast<Real>(1.0 / (model->_dx * model->_dx));
        Real *out = static_cast<Real *>(dest);
        const int n = nCells();
        for (int i = 0; i < n; ++i)
            out[i] = m->data.cell(static_cast<size_t>(i)) * factor;
        return;
    }
    // Runoff is stored as Qm3total, a cumulative discharge *volume* (m3) per cell; expose as a
    // depth (m) by dividing by cell area, so it's unit-consistent with the other per-cell water
    // terms (rainfall/infiltration, both metres) -- same scale-at-read pattern as erosion above.
    if (name == "surface-water~runoff_amount") {
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
    name = resolveVarAlias(name);
    // Scalar catchment totals: return pointer to the TWorld double
    if (isScalarOutput(name))
        return static_cast<void *>(_scalar_out_ptrs.at(name));
    // Erosion map is stored as kg/cell but GetValue exposes kg/m². A raw pointer
    // would silently hand back unscaled kg/cell (wrong units), so refuse it and
    // steer callers to GetValue, which applies the 1/_dx² scaling.
    if (name == "soil_erosion~mass-per-area")
        throw std::runtime_error(
            "BmiLisem::GetValuePtr: 'soil_erosion~mass-per-area' has no pointer "
            "representation (stored as kg/cell, exposed as kg/m2); use GetValue()");
    if (name == "surface-water~runoff_amount")
        throw std::runtime_error(
            "BmiLisem::GetValuePtr: 'surface-water~runoff_amount' has no pointer "
            "representation (stored as m3/cell, exposed as m); use GetValue()");
    cTMap *m = resolveVar(name);
    return &m->data.cell(0);
}

void BmiLisem::GetValueAtIndices(std::string /*name*/, void * /*dest*/, int * /*inds*/, int /*count*/) { BMI_NOT_IMPLEMENTED(); }

//---------------------------------------------------------------------------
// Variable setters (stubbed)
//---------------------------------------------------------------------------
void BmiLisem::SetValue(std::string name, void *src)
{
    name = resolveVarAlias(name);
    // Control signal: any write triggers ResetEvent; the buffer value is ignored.
    if (name == "model__reset_event") { model->ResetEvent(); return; }

    cTMap *m = resolveVar(name);
    const size_t nbytes = m->data.nr_cells() * sizeof(Real);
    std::memcpy(&m->data.cell(0), src, nbytes);
}

void BmiLisem::SetValueAtIndices(std::string name, int *inds, int count, void *src)
{
    name = resolveVarAlias(name);
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
