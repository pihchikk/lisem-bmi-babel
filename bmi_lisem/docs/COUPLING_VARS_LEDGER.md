# Coupling Variables Ledger

Variables added to the C++ BMI registry (`BmiLisem::buildVarRegistry()`) for
physical coupling with AquaCrop and other soil-water models.

> **Naming update:** the registry now stores the **canonical ESoil standard
> names** (the "Standard project name" column below). Legacy CSDMS names
> (`object__quantity`) are still accepted on every name-keyed BMI call via
> `BmiLisem::resolveVarAlias()`, but `GetOutputVarNames()`/`GetInputVarNames()`
> advertise only the canonical names. The full old→new table lives in
> `docs/STANDARD_NAMES_ALIASES.md`.

## Raster outputs (grid 0, uniform_rectilinear)

| C++ BMI name | Source (`TWorld` member) | Units | Grid | Standard project name (Python wrapper target) |
|---|---|---|---|---|
| `soil_water__volume_fraction_in_layer_1` | `model->ThetaI1a` | `m3 m-3` | 0 | `soil_water_actual~layer-1` |
| `soil_water__volume_fraction_in_layer_2` | `model->ThetaI2a` | `m3 m-3` | 0 | `soil_water_actual~layer-2` |
| `soil_water__volume_fraction_in_layer_3` | `model->ThetaI3a` | `m3 m-3` | 0 | `soil_water_actual~layer-3` |
| `soil__layer_depth_1`                    | `model->SoilDepth1` | `m` | 0 | `soil_depth~layer-1` (COINED-pending) |
| `soil__layer_depth_2`                    | `model->SoilDepth2` | `m` | 0 | `soil_depth~layer-2` (COINED-pending) |
| `soil__layer_depth_3`                    | `model->SoilDepth3` | `m` | 0 | `soil_depth~layer-3` (COINED-pending) |
| `soil__erosion_mass_per_area`            | `model->TotalSoillossMap` ÷ `_dx²` | `kg m-2` | 0 | `soil_erosion_amount` (COINED-pending) |
| `atmosphere_water__precipitation_leq-depth` | `model->RainCumFlat` | `m` | 0 | `surface-water~rainfall_amount` |
| `surface_water__runoff_depth`            | `model->Qm3total` ÷ `_dx²` | `m` | 0 | `surface-water~runoff_amount` |

### Notes on inactive layers

If a soil layer is not active for the current run configuration, the
corresponding `cTMap*` pointer is `nullptr`.  The `if(!d.map) continue` guard
in `buildVarRegistry()` silently skips these entries; they will not appear in
`GetOutputVarNames()`.

### Notes on soil moisture (`ThetaI*a`)

`ThetaI1` (existing output `soil_water__volume_fraction`) holds the **initial**
soil moisture and is unchanged during a run — it is the input used to set up
the infiltration model.

`ThetaI1a/ThetaI2a/ThetaI3a` are the **post-event actual** moisture computed
by `TWorld::avgTheta()` from the wetting-front depth `Lw`.  This method is a
diagnostic recalculation with no effect on the physics.  `BmiLisem::Update()`
calls `model->avgTheta()` after every `model->Update()`, and
`BmiLisem::Initialize()` calls it once after `model->Initialize()` so that
values are valid at t₀.

### Notes on erosion scaling

`TotalSoillossMap` stores cumulative soil loss in **kg per cell**.
`GetValue("soil__erosion_mass_per_area", …)` divides each cell value by
`_dx²` (m²) to obtain **kg m⁻²**, consistent with
`lisReportmaps.cpp` lines 138–147 (`ErosionUnits == 2, factor = 1.0/(_dx*_dx)`).
`GetValuePtr` returns the raw kg/cell pointer; callers that need kg/m² must use
`GetValue`.

### Per-cell rainfall and runoff

Added for Gate 7.2's system-level conservation check (`docs/bmi/GATE7_2_COUPLING.md` in
`aquacrop-rs`), which needs a per-cell water balance and had no per-cell rainfall or runoff
exposure before this. Both are created via `NewMap()` in `lisDataInit.cpp`, exactly like `Fcum`, so
both are auto-registered in the generic reset registry (`maplistCTMap`, see `NewMap()`'s own
implementation in `lisDataFunctions.cpp`) and zeroed by `model__reset_event` — **cumulative since
the last reset (or simulation start), in metres, identical temporal semantics and units to
`soil_infiltration~amount`** (confirmed directly, not assumed: `bmi_lisem/tests/test_coupling_vars.py`'s
`test_rainfall_and_runoff_reset_with_model_reset_event`).

**Rainfall** (`RainCumFlat`): the *flat* (slope-unadjusted) cumulative rain depth — the exact field
`lisReportmaps.cpp`'s own `rainfall.map` output is derived from (`*1000` there for mm display;
exposed here in metres, unscaled, matching `Fcum`'s own convention). Verified against that same map
file for the same run: max residual `1.1e-7` mm.

**Runoff** (`Qm3total`): cumulative *discharge volume routed through this cell* (`Qn*_dt` summed,
`lisTotalsMB.cpp:347`) — **not local runoff generation net of upstream inflow**. LISEM's SWOF solver
has no separate "generate, then route" step the way a curve-number scheme would (it solves a coupled
2D shallow-water system, so there is no physically separate "this cell's own contribution" once flow
has begun moving between cells). A commented-out, genuinely unused `runoffTotalCell` field exists in
`lisTotalsMB.cpp` with a *derived* formula (`rain - interception - infiltration`, floored at 0) —
deliberately not used here, since wiring a residual-derived quantity would make any balance check
using it close by construction rather than by an independent measurement. `Qm3total` is scaled from
m³ to a per-cell depth (m) at `GetValue` time by dividing by cell area (same pattern as the erosion
scaling above), so the per-cell balance's units are consistent (rainfall/infiltration/runoff/storage
all in metres). Verified against `Qm3total`'s own map output (`Flowcumm3.map` for the VNIIMZ_20m
test config) for the same run: max residual `1.2e-4` m³ (compared before the m³→m conversion) on
values up to `~3043` m³.

**Disclosed limitation, not hidden**: because `Qm3total` includes water merely routed *through* a
cell (not just generated at it), a per-cell balance using `surface-water~runoff_amount` is expected
to close best for headwater/low-accumulation cells and worse for downstream cells receiving
significant upstream flow — this is a property of what LISEM actually computes, not an exposure bug.
See `docs/bmi/GATE7_2_COUPLING.md` for measured per-cell numbers on both kinds.

## Scalar outputs (grid 1, rank 0, size 1)

All values are in **m³** (volumetric totals over the catchment).  Sources are
`double` members of `TWorld`, updated by `MassBalance()` every timestep.
See `openlisem_bmi/model/lisTotalsMB.cpp` for the exact accumulation logic.

| C++ BMI name | `TWorld` member | Units | Standard project name |
|---|---|---|---|
| `domain_rainfall__volume`             | `RainTot`      | `m3` | `air_precipitation_amount~catchment` (COINED-pending) |
| `domain_interception__volume`         | `IntercTot`    | `m3` | `plant_interception_amount~catchment` (COINED-pending) |
| `domain_infiltration__volume`         | `InfilTot`     | `m3` | `soil_infiltration_amount~catchment` (COINED-pending) |
| `domain_evapotranspiration__volume`   | `ETaTotVol`    | `m3` | `air_evapotranspiration~catchment` (COINED-pending) |
| `domain_soil_water_storage__volume`   | `SoilMoistTot` | `m3` | `soil_water_storage~catchment` (COINED-pending) |
| `domain_runoff__volume`               | `Qtot`         | `m3` | `water~surface_runoff~catchment` (COINED-pending) |

### Source lines in `lisTotalsMB.cpp`

```
line  58:  RainTot += ptot*_dx*_dx;               // m3, per timestep
line  82:  IntercTot = MapTotal(*Interc);          // m3
line  90:  ETaTotVol = (ETaTot-SoilETMBcorrection)*_dx*_dx;  // m3
line 132:  InfilTot += MapTotal(*InfilVol);        // m3
line 174:  SoilMoistTot += SoilMoistDiff;         // m3, cumulative
line 371:  Qtot += Qtot_dt;                        // m3, total outflow
```

### Full mass-balance equation (lisTotalsMB.cpp lines 540–542)

```
waterin   = RainTot + WHinitVolTot + BaseFlowTot + BaseFlowInit + QuserInTot
waterstore = IntercTot + IntercLitterTot + IntercHouseTot + InfilTot
           + WaterVolTot + ChannelVolTot + StormDrainVolTot + RetentionVolTot
waterout  = Qtot + IntercETaTot + QTiletot + QBoundaryTot
```

The simplified balance exported through BMI uses only the dominant terms:

```
Rain ≈ Interception + Infiltration + ET + ΔSoilStorage + Runoff
```

## Residual balance: possible unaccounted terms

The simplified balance may not close exactly.  Known unaccounted members:

| Term | `TWorld` member | Comment |
|---|---|---|
| Initial surface water storage | `WHinitVolTot` | Non-zero if there is ponded water at t₀ |
| Channel storage | `ChannelVolTot` | Water remaining in channels at end of event |
| Retention storage | `RetentionVolTot` | Retention/detention basins |
| Storm drain | `StormDrainVolTot` | If storm-drain option active |
| Litter interception | `IntercLitterTot` | If litter option active |
| Baseflow | `BaseFlowTot`, `BaseFlowInit` | If baseflow option active |
| Tile drain outflow | `QTiletot` | Included in `waterout` but not in simplified runoff |
| Boundary outflow | `QBoundaryTot` | Included in `Qtot` via `floodBoundaryTot` |

If `test_coupling_vars.py::TestWaterBalance::test_balance_closure` shows a
residual > 5 %, check which of the above terms is significant for the test
runfile and add it to the balance equation or document it here.
