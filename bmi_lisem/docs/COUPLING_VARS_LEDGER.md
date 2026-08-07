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
| `soil_water__infiltration_depth`         | `model->Fcum` | `m` | 0 | `soil_infiltration~amount` |

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

#### `soil_water_actual_layer-3` never updates at all — it's a frozen echo of the input map

Same class of issue as layer 2, one step further: `avgTheta()` has **no
layer-3 branch whatsoever**. The whole function (`hydro/lisPercolation.cpp`)
only ever assigns `ThetaI1a` and, inside `if (SwitchTwoLayer)`, `ThetaI2a`.
There is no corresponding `if (SwitchThreeLayer)` block and no assignment to
`ThetaI3a` anywhere in that file. The only place `ThetaI3a` is ever set is
once, at initialization (`lisDataInit.cpp`: `ThetaI3a = NewMap(0);` then
`copy(*ThetaI3a, *ThetaI3)`), and it is never touched again for the rest of
the run.

Confirmed empirically, not inferred from the gap in the code: built a
3-layer fixture (`bmi_lisem/tests/data/tiny/tiny3.run`, `SwitchThreeLayer`
genuinely on) and ran a full event. `theta3_initial == theta3_final` exactly
— bit-for-bit identical — while layer 1 and layer 2 both changed
substantially over the same run. This isn't a "pins once the front arrives"
degradation like layer 2; layer 3 never moves from its t=0 value regardless
of what happens in the simulation.

This matches upstream's own admission, not a defect specific to this fork:
`openLISEM`'s changelog records 3-layer Green & Ampt support as newly added
and explicitly untested —

> 260205 - v7.4.9
> - Added: 3-layer Green and Ampt infiltration and redistribution (not tested!)

**Implication for coupling partners:** the registry fix (`a4965c4`) that
makes `soil_water_actual_layer-3`'s presence/absence deterministic instead of
heap-garbage-dependent is correct and now demonstrated on a real 3-layer
config — the pointer is real, non-null, and readable. But the *value* behind
it is not a diagnostic at all in any meaningful sense for layer 3: it is
whatever `ThetaI3` (the initial-condition input map) held at t=0, for the
entire run. A caller reading `soil_water_actual_layer-3` should treat it as
equivalent to reading the initial condition map directly, not as a live
state variable — there is currently no LISEM-exposed way to see layer 3's
actual moisture evolution through this BMI.

#### SWATRE (`Infil Method=1`): a real crash, fixed, and what it changes for the soil-moisture variables

`BmiLisem::Initialize()`/`Update()`/`UpdateUntil()` called `model->avgTheta()`
unconditionally. `avgTheta()` (`hydro/lisPercolation.cpp`) dereferences
`SoilDepth1->Drc` unconditionally too, but `SoilDepth1` is only ever
allocated inside `lisDataInit.cpp`'s `if (InfilMethod != INFIL_SWATRE)`
block — so under SWATRE it stayed `nullptr` (deterministically, post the
`a4965c4` registry fix) and `avgTheta()` null-derefed on its very first call,
inside `Initialize()`, before any dataset-specific state even mattered.
100% reproducible on any SWATRE-configured runfile, confirmed via `gdb`.

This was a wrapper regression, not an upstream bug: native LISEM's own
`ReportMaps()` (`lisReportmaps.cpp`) already guards both its own `avgTheta()`
call sites with `if (SwitchInfiltration && InfilMethod != INFIL_SWATRE)`.
`BmiLisem.cpp`'s three call sites never picked up that guard. Fixed by
mirroring it exactly — not a new policy, the one the engine already uses.

**What this means for the soil-moisture variables under SWATRE:**

- `soil_water_actual_layer-1` (`ThetaI1a`) — genuinely live, unaffected by
  either the bug or the fix. SWATRE has its own independent, per-timestep
  update path: `InfilSwatre()` (`swatre/lisInfilSwatre.cpp`, called every
  step from `lisModel.cpp` when `InfilMethod == INFIL_SWATRE`) sets
  `ThetaI1a->Drc = theta` from SWATRE's own root-zone moisture calculation.
  Confirmed empirically on `tiny_swatre.run`: evolves genuinely (0.200 →
  0.254 over the event).
- `soil_layer-depth~layer-1` and `soil_water_actual` (`SoilDepth1`/`ThetaI1`)
  — genuinely absent under SWATRE, not a bug: both are only ever read inside
  the same Green & Ampt-only block. The registry correctly excludes them
  (their pointers stay null); `get_output_var_names()` will not advertise
  either under SWATRE.
- `soil_water_actual_layer-2` (`ThetaI2a`) — was **always advertised but
  permanently `0.0`**, and not only under SWATRE. Tracing its allocation
  site showed `ThetaI2a = NewMap(0)` happened unconditionally, regardless of
  layer count or infiltration method — unlike `ThetaI3a`, which was already
  correctly allocated only inside `if (SwitchThreeLayer)`. Since
  `avgTheta()`'s own layer-2 update is itself gated on `SwitchTwoLayer`, any
  configuration where that's false (1-layer Green & Ampt — `tiny.run` did
  this too, unrelated to SWATRE — or SWATRE, where `SwitchTwoLayer` is never
  set at all) left `ThetaI2a` advertised but stuck at its zero-initialized
  default for the entire run. Fixed the same way as the crash: mirror the
  pattern the engine already uses correctly for `ThetaI3a`. `ThetaI2a` is now
  allocated only inside `if (SwitchTwoLayer)`, so the registry correctly
  excludes it whenever nothing will ever write to it. This is the third
  instance of "registry advertises what nothing fills" found in this
  project (after the original heap-garbage registry bug and the frozen
  layer-3 echo above) — but the only one that was a pure allocation-gating
  gap with zero other call sites at risk: every other place in the engine
  that touches `ThetaI2a` (`lisReportmaps.cpp`, `lisTotalsMB.cpp`,
  `lisDisplayMaps.cpp`, `lisSoilmoisture.cpp`) already checked
  `SwitchTwoLayer` (or an equivalent) before touching it — confirmed via a
  full grep of every usage site, not assumed.

#### `soil_infiltration~amount` (`Fcum`) was frozen under SWATRE — fixed (2026-08)

Caught by `TestStaleness::test_no_unexpected_frozen_outputs` on `tiny_swatre.run` —
the fourth instance of this project's recurring "registry advertises a variable
nothing fills" defect shape (after the heap-garbage registry bug, the frozen
`soil_water_actual_layer-3` echo, and the always-zero pre-fix `ThetaI2a`), and the
first one this specific test class was written to catch directly rather than by
someone thinking to check the variable by name.

**Root cause**: `InfilSwatre()` (`swatre/lisInfilSwatre.cpp`) computed
`InfilVol->Drc` (used by the `InfilTot` scalar, see below) every step but never
touched `Fcum->Drc` at all. Green & Ampt's own infiltration path
(`hydro/lisInfiltration.cpp:260`, `Fcum->Drc += fact_;`) has always incremented it
correctly — the SWATRE path simply never had the equivalent line, so under
`Infil Method=1` (SWATRE) `soil_infiltration~amount` read a constant `0.0` for the
entire run, indistinguishable from "correctly zero because nothing infiltrated."

**Fix**: added `Fcum->Drc += (WHorig - WHN);` in `InfilSwatre()`, right next to the
existing `InfilVol->Drc` assignment — `WHorig - WHN` (m) is SWATRE's own per-step
ponded-depth drop, the same quantity already used to compute `InfilVol`, so this
mirrors Green & Ampt's `Fcum->Drc += fact_` pattern exactly rather than inventing
a new accounting method.

**Verified on `tiny_swatre.run`**: `Fcum` moves from `0.0` (t₀) to a uniform
`0.010248` m across all 100 cells by end of run (`TestStaleness` now passes with
no allowlist entry needed for this variable). Cross-checked against
`surface-water~infiltration_volume` (`InfilTot`, the scalar catchment total) for
the same run: `Fcum`-derived volume (`Σ Fcum × cell_area`) = `1.024795` m³ vs.
`InfilTot` = `1.025000` m³ — residual `-0.000205` m³ (0.02% relative). This
residual is **expected, not a bug**: `InfilVol->Drc` (what `InfilTot` actually
accumulates, `lisTotalsMB.cpp:132`) is computed as `(WHorig - WHN) * FlowWidth->Drc
* DX->Drc`, while the cross-check above multiplies `Fcum`'s raw depth by the
nominal grid cell area (`DX * DX`) — the same `FlowWidth`-vs-nominal-area gap
already exists identically in Green & Ampt's `InfilVol->Drc = fact_ * FlowWidth->Drc
* DX->Drc` (`lisInfiltration.cpp:264`), so a caller reconciling `Fcum` against
`InfilTot` should expect this residual whenever `FlowWidth != DX` for any cell
(e.g. channel cells), on either infiltration method — not something introduced by
this fix.

**Regression check**: `Infil Method=1` (SWATRE) is a separate code path from
Green & Ampt (`InfilSwatre()` is only called when `InfilMethod == INFIL_SWATRE`,
`lisModel.cpp:633`) — this fix cannot touch Green & Ampt's own accumulation.
Confirmed empirically, not just by inspection: every advertised output variable's
full initial/final array, dumped via the BMI itself, is byte-for-byte identical
between a build with this fix and one without it, across all four Green & Ampt
fixtures this project has (`res_test`, `results_test`, `tiny.run`, `tiny3.run`).

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

## External real-world datasets: compatible, not incompatible (2026-08)

**Correction to the record**: an earlier conclusion that no compatible external dataset exists — not
written down anywhere, so there is no document to edit, only this correction to make — was drawn from
testing 2 of the 6 datasets openLISEM's own upstream project publishes as examples (SourceForge).
Both of the two originally tried failed, and the failure was read as a format-compatibility verdict.
It wasn't: both failures were the *same* parser bug (`KE parameters EQ1/EQ2/EQ3`, below), not a
property of the format or the datasets. Testing all 6 (`Ganspoel_Hydrology`, `Dijkring41_Flood`,
`StLucias_DebrisFlood`, `Sicily_DebrisFlow`, `StLucia_FlashFlood`, `test_lake`) after fixing that one
bug, all 6 initialize/update/finalize cleanly — none needed anything beyond a runfile/rainfall-file
format port (the same class of work already done for `VNIIMZ_20m`). `Dijkring41_Flood` in particular
is a real 875×625 (546,875-cell) flood-hazard domain — a genuine scale test roughly 30× larger than
anything else exercised in this project, reached only because the original 2-dataset sample happened
not to include it.

These datasets declare `[openLISEM runfile version 1.0]` — a materially older schema than the
`version 6.0` runfiles this project otherwise uses (different section layout entirely: a unified
`[General options]` block, `[Surface Flow]`/`[Debris Flow]`/`[OpenGL visualization]` sections with no
`version 6.0` equivalent). The version number itself is never read by the engine (the parser just
splits on `=`, ignoring any line without it); what actually breaks porting a `version 1.0` runfile
forward is entirely in the specific findings below.

### Fixed: `KE parameters EQ1/EQ2/EQ3` crashed the whole process on legacy input

All six datasets hit an identical crash on first attempt — confirmed via `gdb` backtrace to
`TWorld::ParseRunfileData()`. `KE parameters EQ1/EQ2/EQ3` are split on `;` and indexed
(`param[0..3]`) with no bounds check. Legacy runfiles write these **comma**-separated
(`1,8.950,0.520,0.042`); splitting that on `;` returns a 1-element list, and the very first indexed
access is out of range — a hard Qt assert (`abort()`), not a catchable exception. A malformed or
merely differently-delimited value here killed the entire host process, unacceptable for a coupled
run regardless of these specific datasets.

**Fixed** (`lisRunfile.cpp`): each of the three blocks now checks `param.count()` against the number
of fields it's about to read (4 for EQ1, 3 for EQ2/EQ3) and throws a clear, catchable `ErrorString`
naming the value and its actual field count if the check fails, instead of indexing blindly. Verified
directly: a runfile with the original comma-separated value now raises a Python `RuntimeError` with
an actionable message instead of aborting the process.

### Fixed: rainfall day-index mismatch — a silent wrong-answer bug, not a crash

One further rainfall-file format variant (plain floating-point minutes, no `ddd:` prefix — e.g.
`0.00`, `5.00`) initializes and runs to completion with **no error at all**, but every
rainfall-dependent output reads exactly `0.0` for the entire run. Root cause, in
`TWorld::getTimefromString()` (`meteo/lisRainfall.cpp`): the no-colon fallback defaulted `day` to
`0`, while `Begin time`/`End time` (`lisModel.cpp`) require the `ddd:mmmm` form and subtract 1 from
the parsed day before use (so `Begin time=001:0000` means day-index 0). A rainfall record with no
colon therefore landed at day-index `-1` in the same formula — a full 86,400-second offset that puts
every rainfall timestamp permanently outside the simulation's live clock window. Caught only by
checking that a real, documented storm total (103mm) actually showed up as non-zero
`surface-water~rainfall_amount` — nothing about the run itself signaled anything was wrong.

**Fixed**: the no-colon fallback now defaults `day = 1`, matching the same day-index-0 reference
point `Begin time`/`End time` already use. Verified directly against the original, unmodified legacy
rainfall file (no format conversion needed once this fix is in): `surface-water~rainfall_amount`
reads non-zero and, over a full run, matches the source file's own documented total exactly (103.8mm
computed vs. "103mm" in the file's own header comment). This fix covers the `StLucia_FlashFlood`/
`StLucias_DebrisFlood` rainfall format specifically (plain floating-point minutes, no header line
resembling the old format below) — their original files now work unmodified.

**A separate, related finding while fixing the above**: `Ganspoel_Hydrology`/`Dijkring41_Flood` use a
*third*, genuinely different and older rainfall-file format (`RUU CSF TIMESERIE INTENSITY NORMAL 1`
header, a station-name line, then bare `minute\tvalue` rows) that this engine version explicitly
intends to reject: `oldformat = (rainRecs[0].contains(" RUU")); if (oldformat) { throw "The old RUU
rainfall file format is not longer supported."; }`. That check itself has a bug and never actually
fires on genuine old-format files: it looks for the substring `" RUU"` — a space followed by `RUU` —
but real files have `RUU` as the literal first word, with no leading space, so `.contains(" RUU")` is
always `false` for them. Instead of the intended clear rejection, such a file falls through to
new-format parsing, where the station-name line (`"station_1"`, not an integer) fails to parse as a
station count, silently leaving `nrStations` at its default `0` and producing a confusing, unrelated
error (`"Number of stations in rainfall file (0) < nr of rainfall zones in ID map (1)"`) instead of
the actual problem. Not fixed (out of scope for this pass — the two datasets using this format were
ported by converting their rainfall files to the current format instead, preserving every original
value); flagged here since the fix would be small (match on `rainRecs[0].startsWith("RUU")` instead
of `.contains(" RUU")`) and would turn a confusing downstream error into the clear one already written
and evidently intended.

### Found, not yet fixed: `Infil Method=0` (`INFIL_NONE`) silently runs Smith & Parlange instead of nothing

Two of the six datasets (`Dijkring41_Flood`, `Sicily_DebrisFlow`) set `Infil Method=0` — the option a
user reaches for to mean "no infiltration model" — and both showed `soil_water_actual`/
`soil_water_actual_layer-1` drifting to physically impossible values over the course of a real run
(12.5–32.0 and −110.5–0.283 respectively; volumetric water content must stay in 0–1). A third dataset
using the same setting (`test_lake`, which has no rainfall at all) showed no such drift — output
stayed frozen at a sane initial value the whole run, which is the clue that resolved this: the drift
only appears once real rainfall/ponding actually occurs.

Root cause, traced through the full call chain (`lisModel.cpp` → `cell_InfilMethods()`,
`hydro/lisInfiltration.cpp`): nothing in this path has a dedicated branch for
`InfilMethod == INFIL_NONE` (`model.h:154`, value `0`). The only real branch in
`cell_InfilMethods()` is `if (InfilMethod == INFIL_GREENAMPT) {...} else { /* Smith & Parlange */ }`
— every other value, including `INFIL_NONE`, falls into the `else` branch and runs a real Smith &
Parlange infiltration calculation. `InfilEffectiveKsat()`'s own early-return only excludes SWATRE
(`if (!SwitchInfiltration || InfilMethod == INFIL_SWATRE) return;`), not `INFIL_NONE` either. So
`Infil Method=0` does not disable infiltration at all in this vendored engine version — it silently
aliases to Smith & Parlange, using whatever Ksat/Psi/ThetaS/ThetaI values the runfile happens to
provide, which a dataset author who deliberately set `Infil Method=0` had no reason to validate for
that formula. Over enough timesteps this drives the wetting-front/percolation bookkeeping (which
assumes an actively-maintained infiltration front) into physically nonsensical territory.

This is the same shape as the earlier SWATRE `Fcum` gap in this ledger: a code path written for one
configuration silently reused, unguarded, for a configuration it was never meant to handle. **Not
yet fixed** — genuinely changes engine behavior (anyone currently relying on `Infil Method=0`
producing *some* infiltration, accidental or not, would see that infiltration disappear), so it
wasn't changed without checking first. The two candidate fixes are (1) an explicit early return for
`INFIL_NONE` in `cell_InfilMethods()`, matching the existing `if (Ksateff->Drc == 0) return;` pattern,
or (2) rejecting `Infil Method=0` outright at parse time as an unsupported value in this build, if
`INFIL_NONE` was never meant to reach this code at all.

#### Decision: warn, don't change the computation (2026-08)

Deliberately not implementing either candidate fix above: anyone currently getting accidental Smith &
Parlange infiltration under `Infil Method=0` would silently lose it, and that's a behavior change
requiring its own decision -- not something to bundle into a "just add a warning" pass. The actual
problem being fixed here is the *silence*, not the computation.

Added a warning at initialization, `TWorld::ParseRunfileData()` (`model/lisRunfile.cpp`, right after
`InfilMethod` is finalized -- catches both `Infil Method=0` directly and `Include Infiltration=0`,
which also forces `InfilMethod = INFIL_NONE`), stating plainly that `Infil Method=0` does not disable
infiltration, that the model falls through to Smith & Parlange, and that soil-moisture output may be
physically meaningless if the dataset's Ksat/Psi/theta values weren't prepared for that formula.

Routed through the engine's existing non-fatal diagnostic path (`DEBUG(s)`, `model.h:85`, `emit
debug(QString(s))`) for GUI visibility -- but that signal has **only ever had a GUI listener**
(`ui_full/LisUIModel.cpp:214`, `connect(W, &TWorld::debug, this, &lisemqt::worldDebug)`); nothing in
`BmiLisem.cpp` connects to it, so a BMI-driven run would see nothing from `DEBUG()` alone. Also
printed to `stdout` via the same `QTextStream consoleout` mechanism `TWorld::Update()` already uses
for per-step progress output (`model/lisModel.cpp:453`), gated the same way: `if (op.doBatchmode &&
noInterface)`. `BmiLisem.cpp`'s constructor sets `noInterface = true`, `bmiMode = true`, and
`op.doBatchmode = true` (`bmi_lisem/BmiLisem.cpp:49-61`) before `Initialize()` ever runs -- so this
condition is true for every BMI-driven run, and this is the exact channel a BMI caller already
receives progress text through (confirmed empirically all session: `"progress: step N ..."` lines
appear in captured stdout for every BMI/pytest run). Reusing that channel rather than inventing a new
BMI-specific one.

Purely additive by construction, not just by testing: the new code is entirely inside `if (InfilMethod
== INFIL_NONE) { DEBUG(...); consoleout print; }`, touching no map, no state, no other branch --
zero possible effect on any computed value.

Verified: rebuilt, ran the console binary directly (`build/Lisem -ni -r <runfile>`) against all three
`Infil Method=0` datasets (`test_lake`, `sicily_debrisflow`, `dijkring41_flood`) -- warning printed
exactly once each, before the simulation loop starts. Ran `vniimz_20m` (`Infil Method=3`) -- no
warning. The other three legacy datasets and all `tiny*` fixtures also use non-zero `Infil Method`,
so none of them trigger it either.

### Full 27-test suite run against all six datasets as permanent fixtures (2026-08)

Each dataset run through the complete test suite (not just the one-off `initialize()`/`update()`/
`finalize()` verification above), to check whether test assumptions written against `VNIIMZ_20m` (and
the small `tiny*`/`res_test`/`results_test` fixtures) hold on real, independently-authored datasets
spanning 8,800 to 546,875 cells:

| Dataset | Cells | Infil | Erosion | Channels | Result | Wall time |
|---|---|---|---|---|---|---|
| `test_lake` | 8,800 | none (0) | off | no | 24 passed, 3 failed | 9m39s |
| `ganspoel_hydrology` | 35,200 | Green&Ampt | on | no | 24 passed, 2 failed, 1 xfailed | 7m49s |
| `sicily_debrisflow` | 32,200 | none (0) | on | no | 23 passed, 3 failed, 1 xfailed | 3h12m |
| `stlucia_flashflood` | 61,517 | Green&Ampt | off | no | 21 passed, 3 failed, 2 skipped, 1 xfailed | 2h1m |
| `stlucias_debrisflood` | 299,018 | Green&Ampt | on | yes | 24 passed, 2 failed, 1 xfailed | 14h45m |
| `dijkring41_flood` | 546,875 | none (0) | off | no | 22 passed, 3 failed, 2 skipped | 2h38m |

No test failure here is a regression from this pass's two engine fixes (KE parameters bounds check,
rainfall day-index) — every failure below is either a pre-existing test assumption that happened to
only ever be exercised against `VNIIMZ_20m`, or (for the `Infil Method=0` theta anomaly) the
already-documented finding above, now confirmed on more real data. Four distinct assumption gaps
surfaced, none fixed yet (all are test-side fragility, not engine bugs, except where noted):

**Rainfall-onset-within-5-steps assumption** (`test_rainfall_and_runoff_reset_with_model_reset_event`,
asserts `surface-water~rainfall_amount` is nonzero after exactly 5 `update()` calls) — fails on 5 of 6
datasets (`test_lake` fails degenerately since it has no rainfall at all; `ganspoel_hydrology`,
`sicily_debrisflow`, `stlucia_flashflood`, `stlucias_debrisflood` all fail because 5 steps cover too
little simulated time for rain to have started yet at their timestep). Only `dijkring41_flood` passes
it. The assumption ("5 steps is enough") was tuned to `VNIIMZ_20m`'s specific timestep/rain-onset
timing and doesn't generalize — needs a time-based wait (e.g. step until a wall-clock/sim-time bound)
rather than a fixed step count.

**Soil-depth map not clipped to the catchment mask** (`TestFiniteness.test_finiteness_invariant_across_outputs`,
asserts every raster output agrees on which cells are NaN) — `ganspoel_hydrology`: `soil_layer-depth~layer-1`
has 0 NaN cells against `soil_erosion~mass-per-area`'s 24,123; `dijkring41_flood`: same variable has 0 NaN
cells against `soil_infiltration~amount`'s 229,699. Both datasets' own `soil_layer-depth` source maps
cover the full rectangular grid rather than being masked to the catchment outline the way most other
raster inputs are for these two ports — a curation gap in these two datasets' `maps/` (not an engine
bug), confirmed at both a mid-size (35,200) and the largest (546,875) domain in this set.

**Erosion-off breaks the "erosion var always advertised" assumption**
(`TestMetadata.test_coupling_vars_in_output_list`, asserts `soil_erosion~mass-per-area` is always in
`get_output_var_names()`) — fails on both datasets in this set that have erosion off
(`stlucia_flashflood`, `dijkring41_flood`) — 2 of 2, i.e. every erosion-off config breaks it. The
variable is correctly absent when `Include Erosion simulation=0`; the test's own assumption that it's
always present was never true in general, just true for every fixture used until now.

**Fixed absolute runoff tolerance doesn't scale with domain** (`test_runoff_amount_matches_own_runoff_map`,
`TOLERANCE_M3 = 0.01`) — fails on `stlucia_flashflood` (residual 0.0602949 m3) and `stlucias_debrisflood`
(residual 0.0340201 m3), both real multi-tens-of-thousands-to-hundreds-of-thousands-cell domains with
channels/complex routing; passes on every smaller/simpler fixture. A fixed absolute tolerance in m3
was reasonable for `VNIIMZ_20m`'s scale but not for domains two orders of magnitude larger — needs a
relative or domain-scaled tolerance.

One further, likely-not-a-bug nuance found only on `sicily_debrisflow`: `test_erosion_finite_nonnegative`
fails because a cell shows net erosion while computed runoff is ~zero (rain=9856 m3, runoff=0 m3) — the
test assumed detachment requires surface flow, but rainsplash detachment from raindrop impact is a real
mechanism independent of runoff; the test's assumption, not the engine's output, is likely what's wrong
here.

## Upstream comparison: `openlisem_bmi` vs pristine `vjetten/openlisem` (2026-08)

This section answers a narrower question than "is our physics correct" — there's no second LISEM to
validate against the way official AquaCrop v7.3 served as ground truth elsewhere in this project's BMI
work. It answers: **did the six engine changes below break something upstream did correctly, or fix
something upstream had wrong?**

Every claim in this section is tagged by how it was established, because that distinction has mattered
before in this project and the cost of not tagging it was real: an earlier "no compatible external
datasets exist" conclusion was source-read and generalized from testing 2 of 6 datasets, and turned out
wrong once all 6 were actually tried (see "External real-world datasets" above). The same discipline
applies here.

- **measured** — pristine upstream was actually built and run, and this is a comparison of real output
  (or a real crash/backtrace)
- **source-read** — determined by reading upstream's code without executing it
- **inferred** — reasoned from other evidence, not directly checked

### Scope and what was *not* done — read this before the dispositions below

- **No pinned base commit.** The fork's actual divergence point from upstream was never identified via
  git history or content-matching. "Pristine upstream" throughout this section means `vjetten/openlisem`
  at the tip of its `main_C` branch as of the clone date (2026-08) — not the specific commit this fork
  was originally vendored from. Upstream's own independent development since that real (unknown)
  divergence point is substantial: a plain `diff -rq` between the fork's `openlisem_bmi/` and the cloned
  tree shows **60 of ~69 shared source files differ**. Most of that is unrelated to the six changes below
  and is normal upstream evolution, not a defect on either side — but it means the numerical comparison
  below cannot cleanly isolate "the effect of changes 1-6" from "everything else that changed since the
  actual fork point." Both are mixed together in any observed difference.
- **No AddressSanitizer build.** The original task brief suggested building changes 1-2 under ASan.
  This was not done — upstream was built as a plain CMake Release build. Change 1's disposition below
  rests on a real crash reproduction (a measured SIGSEGV with a `gdb` backtrace), not an ASan report.
- **The upstream clone and build no longer exist.** They were deleted during a disk-space cleanup
  earlier in this pass and were not recreated for this writeup, per instruction. Nothing below can be
  re-verified without re-cloning and rebuilding.

### Per-change disposition

**1. `nullptr`-defaulting `TWorld`'s ~364 raw pointer members — CONFIRMED-NECESSARY**

- *source-read*: upstream's `TMmapVariables.h` declares the same pointers without `= nullptr` (checked
  directly, e.g. `*DEM,` vs the fork's `*DEM = nullptr,`, same line numbers); `TWorld::TWorld()` in
  upstream's `lisModel.cpp` is an empty constructor body — these pointers are genuinely left
  uninitialized (real UB), not merely undocumented.
- *measured*: built pristine upstream's console `Lisem` binary and ran it (`-ni -r <runfile>`) against
  all three `Infil Method=0` datasets (`test_lake`, `sicily_debrisflow`, `dijkring41_flood`). All three
  **SIGSEGV'd**, `gdb` backtrace identical across all three: `TWorld::InfilEffectiveKsat() [clone
  ._omp_fn.0]` ← `GOMP_parallel` ← `TWorld::InfilEffectiveKsat()` ← `TWorld::DoModel()` ← `main()`. The
  fork's own console binary, built from the exact same source tree plus this fix, ran all three to
  completion on the identical runfiles with zero crash.
- *inferred*: the specific causal mechanism was **not** confirmed at the memory level. The release build
  had no debug symbols — `gdb`'s `print W.WHboundarea` / `print W.SwitchWaveUser` both failed ("No
  symbol in current context"), so the actual runtime value of the suspected pointer was never observed.
  The `WHboundarea`-based explanation is inferred from: (a) `WHboundarea` sits at the same declaration
  line in both trees' `TMmapVariables.h`, missing `=nullptr` only upstream; (b) it's the only variable
  dereferenced in `InfilEffectiveKsat()`'s `SwitchWaveUser`-gated branch without another allocation
  guarantee. This is a plausible, not a proven, root cause for *which* pointer crashes — that the crash
  itself is real and fork-vs-upstream-differential is measured; the specific mechanism is inferred.

**2. Gating `ThetaI2a` allocation on `SwitchTwoLayer` — FORK-INTRODUCED (nuanced)**

- *source-read only — no execution was performed or possible for this one*: there's no crash or
  numeric symptom to reproduce upstream-side, since upstream has no BMI to over-advertise a variable
  through in the first place. Confirmed by reading: upstream's `lisDataInit.cpp` allocates
  `ThetaI2a = NewMap(0)` unconditionally (matching the fork's pre-fix state exactly); upstream's own
  `report()` call for `ThetaI2a` (`lisReportmaps.cpp`) **is** gated on `SwitchTwoLayer`, so the
  unconditional allocation is harmless in upstream's own usage.
- The "fork-introduced" call rests on this session's earlier finding (established by reading and testing
  the fork alone, before this upstream-comparison pass, not re-verified against upstream here) that the
  fork's own BMI registry used "pointer is non-null" as its sole advertisement signal — that mechanism
  doesn't exist upstream at all, so the bug it caused can't either.

**3. `SwitchInfiltration && InfilMethod != INFIL_SWATRE` guard on `BmiLisem.cpp`'s `avgTheta()` calls — NOT-COMPARABLE**

- *source-read (repository inspection, not execution)*: `find` over the cloned pristine tree turned up
  zero BMI-related files or directories anywhere — no `BmiLisem.cpp`, no `bmi_lisem/` directory. There is
  no analogous code path to compare against.

**4. `Fcum->Drc += (WHorig - WHN)` in `InfilSwatre()` — FORK-INTRODUCED**

- *source-read only — not measured*: grepped every use of `Fcum` across upstream's
  `hydro/lisInfiltration.cpp` and `swatre/lisInfilSwatre.cpp`. It is used exclusively by the Green &
  Ampt/Smith & Parlange formula; `InfilSwatre()` never references it at all — not a partial or buggy
  implementation, a complete absence. No SWATRE run was performed against pristine upstream to watch
  `Fcum` stay at zero directly; the source absence was judged unambiguous enough not to need it, but
  that judgment call itself is unverified by execution.

**5. `EQ1/EQ2/EQ3` bounds checking in `ParseRunfileData()` — disposition is CONFIRMED-NECESSARY, but this rests entirely on source-read, not a reproduced crash**

- *source-read*: upstream's `lisRunfile.cpp` has the identical unguarded `param[1]/param[2]/param[3]`
  indexing in all three `EQ1`/`EQ2`/`EQ3` blocks, no `param.count()` check anywhere.
- **Gap found while writing this section, 2026-08**: none of the six legacy datasets' actual committed
  runfile templates (`meta/Lisem/legacy_datasets/*/run.run.template`) still use the comma-separated
  format that triggers this crash — checked directly just now, all six use semicolons
  (`KE parameters EQ1=1;8.950;0.520;0.042`, etc.). They were reformatted during this project's own
  curation pass, before the upstream numerical comparison below was ever run. So the numerical-comparison
  test runs against pristine upstream **never exercised this code path on either engine** — no crash was
  observed on upstream for this specific defect in this pass, because the input that would trigger it no
  longer exists in this project's fixtures. The "confirmed-necessary" call rests entirely on comparing
  source code against a defect this project already reproduced **on the fork**, in an earlier phase,
  against the original uncurated comma-separated data (see "Fixed: `KE parameters EQ1/EQ2/EQ3`..."
  above) — it was not re-confirmed against upstream in this pass.

**6. `getTimefromString()`'s no-colon fallback day-index — source-read confirms the identical defect; the measured numerical comparison does not show the expected symptom, and this is an open, unresolved discrepancy, not a clean confirmation**

- *source-read*: upstream's `getTimefromString()` has the identical `double day = 0;` no-colon fallback
  default.
- *measured, and unresolved*: `stlucia_flashflood` and `stlucias_debrisflood` both use `5 year
  johnson.txt`, genuinely in the bare-minutes no-colon format that triggers this exact branch, with
  `Begin time=001:0000` (day-index 0) and `Event based=0` (checked directly — so the function's
  `SwitchEventbased` early-return, which would bypass the `day` variable entirely, is *not* in play
  here; this was checked specifically because it's the obvious first explanation and it doesn't hold).
  Both datasets were run through pristine upstream and the fork; `totals.csv` came back **byte-identical**
  on both. Given the bug's established symptom on the fork's own pre-fix code (verified in an earlier
  phase of this project) was "every rainfall-dependent output reads exactly zero the whole run," and the
  fork's current build has the fix (real ~103mm rainfall observed), an upstream build that still has the
  bug would be expected to diverge sharply on these two datasets — it did not. **This is flagged as an
  open discrepancy, not explained here.** Two of the more obvious candidate explanations were checked and
  ruled out (event-based early return does not apply). Resolving it would need re-running upstream with
  the rainfall array itself instrumented, which is out of scope for this writeup per instruction not to
  rebuild. Until resolved, treat change 6's real-world necessity as source-confirmed but not
  behaviorally confirmed.

### Numerical comparison across fixtures

Ran both engines' own console `Lisem` binary (`-ni -r <runfile>`, not the BMI — upstream has none) on
each fixture, each into its own result directory, diffed `totals.csv` (excluding line 1, which only
echoes the runfile path). One methodology note: upstream's current HEAD requires two runfile keys this
project's runfiles don't have (`Correct extreme WH`, `WH extreme threshold` — schema drift since the
fork's snapshot, unrelated to changes 1-6); patched onto runfile copies fed to upstream only, with safe
disabled-feature defaults (`0` / the UI's own documented default `10.0`).

| Fixture | Result | Provenance |
|---|---|---|
| `tiny`, `tiny3`, `tiny_swatre`, `vniimz_20m` | Identical | measured |
| `stlucia_flashflood`, `stlucias_debrisflood` | Identical | measured — see change 6's open discrepancy above; "identical" here is the surprising half of that finding, not an independent clean result |
| `test_lake`, `dijkring41_flood`, `sicily_debrisflow` | Upstream crashes (SIGSEGV), fork does not | measured — see change 1 |
| `ganspoel_hydrology` | Differs (46 `totals.csv` lines) | measured (the diff itself); attributed to broad unrelated upstream drift (60/69 files differ) rather than changes 1-6 — that attribution is *inferred* from the scale of the file-level diff, not from isolating which specific upstream commits caused which specific `totals.csv` lines to move |

### Honest summary

This is a real comparison with real measured results, not merely a plan — pristine upstream was
genuinely built and executed, the crash reproduction for change 1 is a real `gdb` backtrace, and the
numerical comparison covers ten real fixture pairs. But it is **not a complete verification of changes
5 and 6**: change 5's necessity was never behaviorally reproduced against upstream in this pass (the
triggering input no longer exists in this project's own fixtures), and change 6's expected symptom was
actively looked for and not found, unresolved. Changes 1, 3, and 4 rest on solid source-level evidence
(3 and 4 have no execution path available to strengthen them further even in principle); change 1 alone
has a genuine behavioral reproduction. Change 2's classification is a judgment call carried over from
earlier in this project, not independently re-tested here.
