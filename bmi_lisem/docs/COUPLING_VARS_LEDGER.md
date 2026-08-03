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

#### `soil_water_actual_layer-2` saturates and freezes once the wetting front passes it

`avgTheta()`'s formula for layer 2 (`hydro/lisPercolation.cpp`) is a coarse
wetting-front-*position* indicator, not a live mass-balance-tracked state:

```cpp
if (Lw_ > SoilDep1 && Lw_ < SoilDep2 - 1e-3) {
    double f = (Lw_-SoilDep1)/(SoilDep2-SoilDep1);
    ThetaI2a->Drc = f * ThetaS2->Drc + (1-f) * ThetaI2->Drc;
}
if (Lw_ > SoilDep2 - 1e-3)
    ThetaI2a->Drc = ThetaS2->Drc;
```

Once the wetting front `Lw` passes layer 2's bottom depth
(`Lw_ > SoilDep2 - 1e-3`), `ThetaI2a` is pinned to `ThetaS2` (saturation) for
the rest of the run — **it stops reflecting any further dynamics** (drainage,
redistribution, deep percolation) once that threshold is crossed. Confirmed
directly on VNIIMZ_20m: layer 2 rose from ~0.35 to ~0.655 by the first quarter
of the event, then read *bit-identical* at the 25/50/75/100% checkpoints,
matching each probed cell's own `ThetaS2` map value almost exactly (cell
12364: plateau 0.65494 vs `ThetaS2` 0.65645; cell 13986: plateau 0.65920 vs
`ThetaS2` 0.66056) — while layer 1 kept declining smoothly and substantially
over the same interval. Water isn't vanishing; the diagnostic simply can't see
past "the front has arrived."

**Implication for coupling partners:** a caller reading
`soil_water_actual_layer-2` as an evolving moisture signal will see a
constant once this threshold is crossed on a given cell, not ongoing
dynamics — the variable's real semantics are closer to "has this layer been
reached by the wetting front" than "current moisture content of this layer."
Don't build logic downstream that assumes it keeps changing after the event's
early stages; check `soil_layer-depth~layer-2` / `Lw` position if the actual
evolving state matters.

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

| C++ BMI name | Source | Units | Standard project name |
|---|---|---|---|
| `domain_rainfall__volume`             | `RainTot`      | `m3` | `air_precipitation_amount~catchment` (COINED-pending) |
| `domain_interception__volume`         | `IntercTot`    | `m3` | `plant_interception_amount~catchment` (COINED-pending) |
| `domain_infiltration__volume`         | `InfilTot`     | `m3` | `soil_infiltration_amount~catchment` (COINED-pending) |
| `domain_evapotranspiration__volume`   | `ETaTotVol`    | `m3` | `air_evapotranspiration~catchment` (COINED-pending) |
| `domain_soil_water_storage__volume`   | `SoilMoistTot` | `m3` | `soil_water_storage~catchment` (COINED-pending) → canonical `soil_water~storage_volume` |
| —                                      | `_surfaceStorageVolume` (`BmiLisem`-owned, not a `TWorld` member) | `m3` | canonical `surface-water~storage_volume` (previously misbacked by `SoilMoistTot` — **fixed**, see below) |
| `domain_runoff__volume`               | `Qtot`         | `m3` | `water~surface_runoff~catchment` (COINED-pending) |

### `surface-water~storage_volume` fix (2026-07-28)

**Previously backed by `SoilMoistTot`** — soil moisture, not surface storage, despite the name.
Root cause was purely a naming/wiring mismatch, not a computation bug: the *alias table's own*
legacy entry (`domain_soil_water_storage__volume`) already correctly identified `SoilMoistTot` as a
**soil water** quantity — it was only the *canonical* name (`surface-water~storage_volume`) that was
wrong.

**Fixed by separating the two concerns**, not by simply repointing the name:
- `surface-water~storage_volume` now backs `BmiLisem::_surfaceStorageVolume`
  (`recomputeSurfaceStorage()`), a live per-cell sum of `model->MicroStoreVol` — the exact quantity
  `lisTotalsMB.cpp`'s own `SStot`/`SurfStoremm` (the source of `totalseries.csv`'s `SS(mm)` column)
  is built from, recomputed after every `Initialize()`/`Update()`/`model__reset_event` (the same
  read-lag discipline task #26 established — see `Blocker 1`/task #26 write-ups in `aquacrop-rs`).
- `SoilMoistTot` moved to its own, correctly-named `soil_water~storage_volume` — the balance term is
  **not dropped**, just accurately labeled. The legacy alias `domain_soil_water_storage__volume` now
  points here, matching its own original semantic intent.

**Important disclosure, not a regression from this fix**: `SoilMoistTot` is effectively **dead
code** — `SoilMoistDiff` (the only thing ever added to it, `lisTotalsMB.cpp:174`) is *never assigned
a nonzero value anywhere in the active codebase*; its one real computation
(`SoilMoistDiff = soiltot2 - soiltot1`, `lisModel.cpp:652`) is commented out. `SoilMoistTot` reads
`0.0` for every run, regardless of infiltration method — confirmed directly, not assumed, before and
after this fix, same runfile. `soil_water~storage_volume` is now correctly *named*, but it is not
currently a *functioning* balance term; a coupling partner reading it should not expect a nonzero
value until `SoilMoistDiff` is actually wired up (out of this task's scope — flagged, not fixed).

**Verified**: catchment balance (`RainTot = IntercTot + InfilTot + ETaTotVol + SoilMoistTot +
_surfaceStorageVolume + Qtot`) on the VNIIMZ_20m test config, same run used throughout this ledger:
peak residual **5.50 mm**-equivalent (was ~7-8mm-equivalent before the fix), decaying to **0.66
mm**-equivalent by the end of the run — matching `totalseries.csv`'s own `SS(mm)`-based check
tightness (5.5mm max) to two significant figures, as intended.

**Audit for other name/backing mismatches** (same task): checked all five other scalar sources
(`RainTot`, `IntercTot`, `InfilTot`, `ETaTotVol`, `Qtot`) directly in `lisTotalsMB.cpp` — all are
live, actively-computed accumulators with names matching what they compute; no other mismatch found
in the scalar registry. Grid-0 (per-cell) raster variables were not re-audited from scratch here
(established/tested in earlier phases of this project); a full audit of those is a possible
follow-up, not attempted in this pass.

### Source lines in `lisTotalsMB.cpp`

```
line  58:  RainTot += ptot*_dx*_dx;               // m3, per timestep
line  82:  IntercTot = MapTotal(*Interc);          // m3
line  90:  ETaTotVol = (ETaTot-SoilETMBcorrection)*_dx*_dx;  // m3
line 132:  InfilTot += MapTotal(*InfilVol);        // m3
line 154-159: SStot = ΣMicroStoreVol; SurfStoremm = SStot*catchmentAreaFlatMM;  // m3 -> mm, report-only
line 174:  SoilMoistTot += SoilMoistDiff;         // m3, cumulative -- SoilMoistDiff never assigned, dead code
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

**Update (2026-07-28)**: `_surfaceStorageVolume` (`ΣMicroStoreVol` = `ΣWHstore` weighted by channel-
adjusted cell width, `hydro/lisSurfstor.cpp`) is now in the balance via `surface-water~storage_volume`
— this was the dominant unaccounted term (peak residual dropped from ~7-8mm-equivalent to 5.5mm on
the VNIIMZ_20m test config, matching `totalseries.csv`'s own `SS(mm)`-based tightness). The remaining
terms below are still **not** exposed through BMI and account for the residual that's left:

| Term | `TWorld` member | Comment |
|---|---|---|
| Initial surface water storage | `WHinitVolTot` | Non-zero if there is ponded water at t₀ — distinct from `MicroStoreVol`'s *current* storage |
| Channel storage | `ChannelVolTot` | Water remaining in channels at end of event |
| Retention storage | `RetentionVolTot` | Retention/detention basins |
| Storm drain | `StormDrainVolTot` | If storm-drain option active |
| Litter interception | `IntercLitterTot` | If litter option active |
| Baseflow | `BaseFlowTot`, `BaseFlowInit` | If baseflow option active |
| Tile drain outflow | `QTiletot` | Included in `waterout` but not in simplified runoff |
| Boundary outflow | `QBoundaryTot` | Included in `Qtot` via `floodBoundaryTot` |

`test_coupling_vars.py::TestWaterBalance::test_balance_closure`'s 5% tolerance now passes on the
VNIIMZ_20m test config (previously `xfail`'d) — see that test for the current formula, which now
includes `soil_water~storage_volume` and `surface-water~storage_volume` as two separate terms rather
than one mislabeled one. If a *different* runfile still shows a residual above tolerance, check
which of the above still-unaccounted terms is significant for it before assuming a new defect.
