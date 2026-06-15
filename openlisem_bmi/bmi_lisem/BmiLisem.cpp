/*************************************************************************
**  openLISEM native C++ BMI wrapper — implementation
**
**  Phase B1: lifecycle + time are functional, mirroring the headless
**  ("-ni -bmistep") branch of model/main.cpp. All variable/grid access
**  methods throw until phases B2/B3.
*************************************************************************/

#include "BmiLisem.h"

#include <stdexcept>

#include <QLocale>
#include <QString>
#include <QFileInfo>

#include "model.h"    // TWorld
#include "global.h"   // extern output op

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

int BmiLisem::GetInputItemCount()  { BMI_NOT_IMPLEMENTED(); }
int BmiLisem::GetOutputItemCount() { BMI_NOT_IMPLEMENTED(); }
std::vector<std::string> BmiLisem::GetInputVarNames()  { BMI_NOT_IMPLEMENTED(); }
std::vector<std::string> BmiLisem::GetOutputVarNames() { BMI_NOT_IMPLEMENTED(); }

//---------------------------------------------------------------------------
// Variable information (stubbed)
//---------------------------------------------------------------------------
int BmiLisem::GetVarGrid(std::string /*name*/)      { BMI_NOT_IMPLEMENTED(); }
std::string BmiLisem::GetVarType(std::string /*name*/)  { BMI_NOT_IMPLEMENTED(); }
std::string BmiLisem::GetVarUnits(std::string /*name*/) { BMI_NOT_IMPLEMENTED(); }
int BmiLisem::GetVarItemsize(std::string /*name*/)  { BMI_NOT_IMPLEMENTED(); }
int BmiLisem::GetVarNbytes(std::string /*name*/)    { BMI_NOT_IMPLEMENTED(); }
std::string BmiLisem::GetVarLocation(std::string /*name*/) { BMI_NOT_IMPLEMENTED(); }

//---------------------------------------------------------------------------
// Variable getters (stubbed)
//---------------------------------------------------------------------------
void BmiLisem::GetValue(std::string /*name*/, void * /*dest*/) { BMI_NOT_IMPLEMENTED(); }
void *BmiLisem::GetValuePtr(std::string /*name*/) { BMI_NOT_IMPLEMENTED(); }
void BmiLisem::GetValueAtIndices(std::string /*name*/, void * /*dest*/, int * /*inds*/, int /*count*/) { BMI_NOT_IMPLEMENTED(); }

//---------------------------------------------------------------------------
// Variable setters (stubbed)
//---------------------------------------------------------------------------
void BmiLisem::SetValue(std::string /*name*/, void * /*src*/) { BMI_NOT_IMPLEMENTED(); }
void BmiLisem::SetValueAtIndices(std::string /*name*/, int * /*inds*/, int /*count*/, void * /*src*/) { BMI_NOT_IMPLEMENTED(); }

//---------------------------------------------------------------------------
// Grid information (stubbed)
//---------------------------------------------------------------------------
int BmiLisem::GetGridRank(const int /*grid*/) { BMI_NOT_IMPLEMENTED(); }
int BmiLisem::GetGridSize(const int /*grid*/) { BMI_NOT_IMPLEMENTED(); }
std::string BmiLisem::GetGridType(const int /*grid*/) { BMI_NOT_IMPLEMENTED(); }

void BmiLisem::GetGridShape(const int /*grid*/, int * /*shape*/)     { BMI_NOT_IMPLEMENTED(); }
void BmiLisem::GetGridSpacing(const int /*grid*/, double * /*spacing*/) { BMI_NOT_IMPLEMENTED(); }
void BmiLisem::GetGridOrigin(const int /*grid*/, double * /*origin*/)   { BMI_NOT_IMPLEMENTED(); }

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
