# Coupling Variables Ledger

Variables added to the C++ BMI registry (`BmiLisem::buildVarRegistry()`) for
physical coupling with AquaCrop and other soil-water models.

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
