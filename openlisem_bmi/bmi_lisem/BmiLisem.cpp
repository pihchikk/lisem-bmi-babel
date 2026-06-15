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

    buildVarRegistry();    // maps are allocated now — wire standard names to them
}

//---------------------------------------------------------------------------
// Output variable registry + grid helpers
//---------------------------------------------------------------------------
void BmiLisem::buildVarRegistry()
{
    _out_names.clear();
    _out_maps.clear();
    _out_units.clear();

    // standard_name -> (TWorld map, BMI units). Order defines GetOutputVarNames().
    struct VarDef { const char *name; cTMap *map; const char *units; };
    const VarDef defs[] = {
        { "land_surface_water__depth",       model->WH,      "m"      },
        { "channel_water__volume_flow_rate", model->Qn,      "m3 s-1" },
        { "soil_water__volume_fraction",     model->ThetaI1, "m3 m-3" },
        { "soil_water__infiltration_depth",  model->Fcum,    "m"      },
    };

    for (const VarDef &d : defs) {
        if (!d.map)
            continue;  // skip variables whose map is inactive for this run config
        _out_names.emplace_back(d.name);
        _out_maps[d.name]  = d.map;
        _out_units[d.name] = d.units;
    }
}

cTMap *BmiLisem::resolveVar(const std::string &name) const
{
    auto it = _out_maps.find(name);
    if (it == _out_maps.end())
        throw std::runtime_error("BmiLisem: unknown variable '" + name + "'");
    return it->second;
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

int BmiLisem::GetInputItemCount()  { return 0; }  // no input vars wired yet (B3)
int BmiLisem::GetOutputItemCount() { return static_cast<int>(_out_names.size()); }
std::vector<std::string> BmiLisem::GetInputVarNames()  { return {}; }
std::vector<std::string> BmiLisem::GetOutputVarNames() { return _out_names; }

//---------------------------------------------------------------------------
// Variable information (stubbed)
//---------------------------------------------------------------------------
int BmiLisem::GetVarGrid(std::string name)      { resolveVar(name); return 0; }
std::string BmiLisem::GetVarType(std::string name)  { resolveVar(name); return "double"; }
std::string BmiLisem::GetVarUnits(std::string name) { resolveVar(name); return _out_units.at(name); }
int BmiLisem::GetVarItemsize(std::string name)  { resolveVar(name); return static_cast<int>(sizeof(Real)); }
int BmiLisem::GetVarNbytes(std::string name)    { resolveVar(name); return nCells() * static_cast<int>(sizeof(Real)); }
std::string BmiLisem::GetVarLocation(std::string name) { resolveVar(name); return "node"; }

//---------------------------------------------------------------------------
// Variable getters (stubbed)
//---------------------------------------------------------------------------
void BmiLisem::GetValue(std::string name, void *dest)
{
    cTMap *m = resolveVar(name);
    std::memcpy(dest, &m->data.cell(0), static_cast<size_t>(nCells()) * sizeof(Real));
}

void *BmiLisem::GetValuePtr(std::string name)
{
    cTMap *m = resolveVar(name);
    return &m->data.cell(0);
}

void BmiLisem::GetValueAtIndices(std::string /*name*/, void * /*dest*/, int * /*inds*/, int /*count*/) { BMI_NOT_IMPLEMENTED(); }

//---------------------------------------------------------------------------
// Variable setters (stubbed)
//---------------------------------------------------------------------------
void BmiLisem::SetValue(std::string /*name*/, void * /*src*/) { BMI_NOT_IMPLEMENTED(); }
void BmiLisem::SetValueAtIndices(std::string /*name*/, int * /*inds*/, int /*count*/, void * /*src*/) { BMI_NOT_IMPLEMENTED(); }

//---------------------------------------------------------------------------
// Grid information (stubbed)
//---------------------------------------------------------------------------
static void checkGrid(const int grid)
{
    if (grid != 0)
        throw std::runtime_error("BmiLisem: only grid 0 exists");
}

int BmiLisem::GetGridRank(const int grid) { checkGrid(grid); return 2; }
int BmiLisem::GetGridSize(const int grid) { checkGrid(grid); return nCells(); }
std::string BmiLisem::GetGridType(const int grid) { checkGrid(grid); return "uniform_rectilinear"; }

void BmiLisem::GetGridShape(const int grid, int *shape)
{
    checkGrid(grid);
    shape[0] = model->_nrRows;   // rows  (y)
    shape[1] = model->_nrCols;   // cols  (x)
}

void BmiLisem::GetGridSpacing(const int grid, double *spacing)
{
    checkGrid(grid);
    const double cs = refMap()->cellSize();
    spacing[0] = cs;   // y spacing
    spacing[1] = cs;   // x spacing (square cells)
}

void BmiLisem::GetGridOrigin(const int grid, double *origin)
{
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
