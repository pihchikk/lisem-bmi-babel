/*************************************************************************
**  openLISEM native C++ BMI wrapper
**
**  BmiLisem implements the CSDMS Basic Model Interface (bmi::Bmi, BMI 2.0)
**  on top of the refactored TWorld engine (Initialize/Update/Finalize).
**
**  Scope (phase B1): lifecycle + time control are functional. All
**  variable/grid/getter/setter methods are stubs that throw
**  std::runtime_error until phases B2/B3 wire them to TWorld maps.
*************************************************************************/

#ifndef BMILISEM_H
#define BMILISEM_H

#include <string>
#include <vector>
#include <map>

#include "bmi.hxx"
#include "fixture.h"  // RAII GDAL driver registration (mirrors main.cpp Fixture fixture)

class TWorld;  // forward declaration: keep Qt/model headers out of this header
class cTMap;   // forward declaration: map pointers only, no Qt/model headers here

class BmiLisem : public bmi::Bmi
{
public:
    BmiLisem() = default;
    ~BmiLisem() override;

    // --- Model control functions (implemented) ---
    void Initialize(std::string config_file) override;
    void Update() override;
    void UpdateUntil(double time) override;
    void Finalize() override;

    // --- Model information functions ---
    std::string GetComponentName() override;
    int GetInputItemCount() override;
    int GetOutputItemCount() override;
    std::vector<std::string> GetInputVarNames() override;
    std::vector<std::string> GetOutputVarNames() override;

    // --- Variable information functions ---
    int GetVarGrid(std::string name) override;
    std::string GetVarType(std::string name) override;
    std::string GetVarUnits(std::string name) override;
    int GetVarItemsize(std::string name) override;
    int GetVarNbytes(std::string name) override;
    std::string GetVarLocation(std::string name) override;

    // --- Time functions (implemented) ---
    double GetCurrentTime() override;
    double GetStartTime() override;
    double GetEndTime() override;
    std::string GetTimeUnits() override;
    double GetTimeStep() override;

    // --- Variable getters ---
    void GetValue(std::string name, void *dest) override;
    void *GetValuePtr(std::string name) override;
    void GetValueAtIndices(std::string name, void *dest, int *inds, int count) override;

    // --- Variable setters ---
    void SetValue(std::string name, void *src) override;
    void SetValueAtIndices(std::string name, int *inds, int count, void *src) override;

    // --- Grid information functions ---
    int GetGridRank(const int grid) override;
    int GetGridSize(const int grid) override;
    std::string GetGridType(const int grid) override;

    void GetGridShape(const int grid, int *shape) override;
    void GetGridSpacing(const int grid, double *spacing) override;
    void GetGridOrigin(const int grid, double *origin) override;

    void GetGridX(const int grid, double *x) override;
    void GetGridY(const int grid, double *y) override;
    void GetGridZ(const int grid, double *z) override;

    int GetGridNodeCount(const int grid) override;
    int GetGridEdgeCount(const int grid) override;
    int GetGridFaceCount(const int grid) override;

    void GetGridEdgeNodes(const int grid, int *edge_nodes) override;
    void GetGridFaceEdges(const int grid, int *face_edges) override;
    void GetGridFaceNodes(const int grid, int *face_nodes) override;
    void GetGridNodesPerFace(const int grid, int *nodes_per_face) override;

    // --- Custom coupling hook (NOT part of standard BMI) ---
    // OpenLISEM is event-based; a coupler resets dynamic state between
    // rainfall events without re-reading the static terrain/parameters.
    void ResetEvent();

    // Diagnostic access to the underlying engine (NOT part of BMI; used by
    // the test driver to cross-check GetValue against MapTotal).
    TWorld *debugModel() const { return model; }

private:
    Fixture _gdal_fixture;  // FIRST member: registers GDAL drivers before any map I/O
    TWorld *model = nullptr;

    // Output variable registry, populated by Initialize() once maps are allocated.
    std::vector<std::string>           _out_names;   // stable order
    std::map<std::string, cTMap*>      _out_maps;

    // Input variable registry (same pattern; also listed in _all_* for var-info).
    std::vector<std::string>           _in_names;    // stable order
    std::map<std::string, cTMap*>      _in_maps;

    // Unified lookup for var-info methods (name->map, name->units).
    std::map<std::string, cTMap*>      _all_maps;
    std::map<std::string, std::string> _all_units;

    // Scalar output registry (grid 1, rank 0): catchment totals from TWorld.
    std::vector<std::string>           _scalar_out_names;
    std::map<std::string, double*>     _scalar_out_ptrs;   // points into TWorld members
    std::map<std::string, std::string> _scalar_out_units;

    void buildVarRegistry();          // wire standard names to TWorld maps
    cTMap *resolveVar(const std::string &name) const;  // throws if unknown
    bool isScalarOutput(const std::string &name) const;
    int nCells() const;               // _nrRows * _nrCols (== GetGridSize(0))
    cTMap *refMap() const;            // a guaranteed-allocated map for grid geometry
};

#endif // BMILISEM_H
