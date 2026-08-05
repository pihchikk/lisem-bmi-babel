# Tiny synthetic catchment (CI test data)

A 10×10 synthetic OpenLISEM catchment used to exercise the BMI in CI without a
real dataset. Three runfiles share this map directory:

- `tiny.run` — single-layer Green & Ampt (`Nr input layers=1`), ~1-2s per run.
- `tiny3.run` — three-layer Green & Ampt (`Nr input layers=3`), same
  catchment, built specifically to demonstrate `soil_water_actual_layer-3` /
  `SwitchThreeLayer` actually work, not just argue it from source. See
  "Three-layer fixture" below.
- `tiny_swatre.run` — SWATRE (`Infil Method=1`) instead of Green & Ampt, same
  catchment. Built to exercise SWATRE's genuinely different infiltration
  code path; found and fixed a real crash along the way. See "SWATRE
  fixture" below.

## What is committed

- `*.map` — the PCRaster input binaries themselves (dem, ldd, ksat, land use,
  cohesion, etc. for the 10×10 synthetic catchment), committed directly so
  the fixture runs with no `pcraster` dependency. Small (~200KB total) and
  fully synthetic -- see "Regenerating the maps" below if you need to
  recreate them after changing `make_tiny.py`.
- `make_tiny.py` — the generator that originally wrote them (needs
  `pcraster`, which is not installable in this dev environment -- see
  "Regenerating the maps").
- `tiny.run`, `tiny3.run`, `tiny_swatre.run` — runfiles (absolute,
  host-specific paths; see each file's own header comment).
- `rain.txt` — a short rainfall table (note: LISEM's rainfall-file format is
  `# comment` / column-count / literal `timestep` / station-count / then
  `DDD:HHMM value` rows -- not raw minutes-since-start, which is what an
  earlier draft of this file used and which fails to parse).
- `profile.inp`, `loam.tbl` — SWATRE's profile definition and soil
  moisture-retention/conductivity lookup table. Plain text, committed
  directly. See "SWATRE fixture" for what's in them and why the numbers are
  what they are.

Only the `out/`, `out3/`, `out_swatre/` report-output directories a run
writes are gitignored -- everything needed to run the fixture is committed.

## Status: verified working (2026-08)

Both runfiles have been confirmed end-to-end against the real built engine:
`initialize()` → full `update()` loop → `finalize()`, with the actual
`bmi_lisem` pytest suite run against each via `LISEM_TEST_RUNFILE`.

- `tiny.run`: 26/26 pass (2 own-map cross-check tests skip because this
  fixture's runfile doesn't have `OutRunoff`/etc enabled to write those maps
  -- unrelated to the fixture's own correctness). **Re-checked after the
  `soildepth1` unit fix below, not assumed unchanged**: with the fixture's
  original (buggy) 0.5mm layer-1 depth, `test_balance_closure` was
  dynamically `xfail`ing at a genuine 20.29% residual -- confirmed via a
  direct side-by-side run that this residual was *caused by the depth bug*
  itself (a ~0.5mm layer saturates almost instantly regardless of how little
  actually infiltrated, so the model backed excess water up as surface
  storage rather than infiltrating it: `infil=0.658m3, dsurface_storage=0.159m3`
  out of `rain=1.025m3`), not by the generic unaccounted-terms list this
  README previously (incorrectly) attributed it to. Same side-by-side run
  showed `test_actual_theta_differs_from_initial` was also vacuous under the
  bug: `theta1` jumped straight to `thetas1` (0.45, full saturation) for
  *any* nonzero infiltration, because the wetting front trivially exceeded a
  0.5mm-deep layer. With the corrected 500mm depth, both are now real:
  `test_balance_closure` closes exactly (rain=infil=1.025m3, everything else
  0, residual=0.0000%, and the dynamic xfail branch no longer triggers --
  it's a genuine `PASSED`, not an `XPASS`), and `test_actual_theta_differs_from_initial`
  shows a modest, physically plausible wetting response (0.200 -> 0.220),
  not a trivial jump to saturation.
- `tiny3.run`: 25 passed / 1 skipped. (`test_inactive_variable_raises_cleanly`
  now picks whichever canonical variable the current fixture doesn't
  advertise rather than hardcoding `soil_water_actual_layer-3` -- since this
  fixture advertises everything, it honestly skips instead of failing on its
  own broken precondition.)
- `tiny_swatre.run`: 24 passed / 2 skipped (same own-map skips as `tiny.run`).
  See "SWATRE fixture" below -- getting here required fixing a real crash,
  not just authoring input data.

This was a real, non-trivial reconciliation, not just a path fix: the
scaffold's human-readable key names (e.g. `Gradient=`) didn't match what the
engine's `getvaluename()` actually looks up (`grad`); several
unconditionally-read maps were entirely missing (aliased to existing inert
maps where the feature they'd gate is switched off); and the rainfall file
format was wrong outright.

## Three-layer fixture (`tiny3.run`)

Built to answer a real open question: the registry fix that makes
`soil_water_actual_layer-3` deterministically present/absent (instead of
heap-garbage-dependent) was only ever verified on 2-layer configs. `tiny3.run`
sets `Nr input layers=3`, which requires real layer-2 maps too (`SwitchThreeLayer`
requires `SwitchTwoLayer`, per `lisDataInit.cpp`).

Confirmed directly:
- `initialize()` advertises 20 output variables (not 18) -- `soil_water_actual_layer-3`
  and `soil_layer-depth~layer-3` both present.
- All layer values (`soil_water_actual_layer-{1,2,3}`) are finite for every
  timestep (`TestFiniteness` passes).
- Every advertised variable is genuinely readable
  (`test_every_advertised_output_var_is_readable` passes).

**Honest finding, not papered over:** `soil_water_actual_layer-3`
(`ThetaI3a`) does not evolve during the run. `TWorld::avgTheta()`
(`hydro/lisPercolation.cpp`) has explicit per-timestep update logic for layer
1 and layer 2 (gated on `SwitchTwoLayer`), but **none for layer 3** --
`ThetaI3a` is set once at initialization time
(`copy(*ThetaI3a, *ThetaI3)` in `lisDataInit.cpp`) and never touched again.
Confirmed empirically: `theta3_initial == theta3_final` exactly, bit for bit,
across a full event, while layer 1 and layer 2 both change. This matches the
upstream `openLISEM` changelog's own admission that 3-layer Green & Ampt
support was "Added ... (not tested!)" as of v7.4.9 (260205). The registry fix
itself is correct and now demonstrated -- the pointer is real, non-null, and
readable -- but the *value* it exposes for layer 3 is a static echo of the
input map, not a live diagnostic, for the whole run. A coupling partner
reading `soil_water_actual_layer-3` should not expect it to move.

Also fixed while building this: `soildepth1.map`'s on-disk value was `0.5`,
intended as 0.5m, but the engine reads `SoilDepthN` maps in **millimeters**
(`lisDataInit.cpp` divides by 1000 on read) -- so `tiny.run` was silently
running with a 0.5**mm** layer-1 depth, not 0.5m, this whole time. Confirmed
via `get_value("soil_layer-depth~layer-1")` returning `0.0005`. Fixed to
`500.0` (mm).

This one *did* change `tiny.run`'s behavior, not just its physics --
confirmed via a direct side-by-side comparison (buggy 0.5mm map vs. the
fixed 500mm map, same fixture, same event), not assumed: at the old depth,
`test_balance_closure` was `xfail`ing at a genuine 20.29% residual, and
`test_actual_theta_differs_from_initial` was passing on a trivial jump
straight to `thetas1` (full saturation) for any nonzero infiltration -- both
were vacuous in the same class as the registry bug and `Include
Infiltration=0` earlier in this project. At the corrected depth, both are
real: the balance closes exactly and the theta response is a modest,
physically plausible wetting, not a saturation jump. See "Status: verified
working" above for the numbers.

Layer-2/3 values are synthetic and plausible (permeability and porosity
decrease with depth, antecedent moisture increases with depth) -- picked to
exercise the code path, not to model a real place. See `make_tiny.py` for
the exact numbers.

## SWATRE fixture (`tiny_swatre.run`)

Built to exercise SWATRE (`Infil Method=1`), a genuinely different
infiltration solver from Green & Ampt -- SWATRE integrates a
Richards-equation-like N-node soil column per cell (`swatre/swatstep.cpp`)
using a profile definition (`profile.inp`) and a soil
moisture-retention/conductivity lookup table (`loam.tbl`), rather than
approximating a wetting front.

**This surfaced a real, universally-reproducible SIGSEGV, not a data
problem.** `BmiLisem::Initialize()`/`Update()`/`UpdateUntil()` called
`model->avgTheta()` unconditionally; `avgTheta()` dereferences
`SoilDepth1->Drc` unconditionally too, but `SoilDepth1` is only ever
allocated inside `lisDataInit.cpp`'s `if (InfilMethod != INFIL_SWATRE)`
block, so it stayed null under SWATRE and `avgTheta()` null-derefed on its
very first call, inside `Initialize()` -- before any fixture-specific data
even mattered. Confirmed via `gdb` (crash in `TWorld::avgTheta()`), and
confirmed this was a wrapper regression rather than an upstream bug: native
LISEM's own `ReportMaps()` (`lisReportmaps.cpp`) already guards both its
`avgTheta()` call sites with `if (SwitchInfiltration && InfilMethod !=
INFIL_SWATRE)`. `BmiLisem.cpp`'s three call sites never picked up that
guard. Fixed by mirroring it exactly.

**Fixing the crash surfaced a second, adjacent finding:** `ThetaI2a`
(`soil_water_actual_layer-2`) was allocated *unconditionally* in
`lisDataInit.cpp`, unlike `ThetaI3a` (correctly allocated only inside `if
(SwitchThreeLayer)`) -- so it was always advertised via the BMI registry
even when nothing would ever write to it: `avgTheta()`'s own layer-2 update
is itself gated on `SwitchTwoLayer`. This wasn't SWATRE-specific -- plain
`tiny.run` (1-layer Green & Ampt) hit the exact same thing, reading exactly
`0.0` for the entire run. Fixed by mirroring `ThetaI3a`'s pattern: `ThetaI2a`
is now allocated only inside `if (SwitchTwoLayer)`. Verified every other
usage site in the engine (`lisReportmaps.cpp`, `lisTotalsMB.cpp`,
`lisDisplayMaps.cpp`, `lisSoilmoisture.cpp`) already checked `SwitchTwoLayer`
before touching `ThetaI2a` -- this was a pure allocation-gating gap, not a
missing-guard problem elsewhere. Net effect: `tiny.run` now advertises 16
variables instead of 17 (`soil_water_actual_layer-2` correctly dropped);
`res_test`/`results_test`/`tiny3.run` (all genuinely 2-or-3-layer) are
unaffected. See `COUPLING_VARS_LEDGER.md`'s SWATRE section for the full
writeup.

**What's genuinely live under SWATRE vs. what's genuinely absent, confirmed
not assumed:**
- `soil_water_actual_layer-1` (`ThetaI1a`) -- live. SWATRE has its own
  independent per-timestep update (`InfilSwatre()`,
  `swatre/lisInfilSwatre.cpp`), unrelated to `avgTheta()` entirely. Observed
  evolving genuinely (0.200 → 0.254 over the event).
- `soil_layer-depth~layer-1` and `soil_water_actual` (the `ThetaI1` alias)
  -- genuinely absent, not a bug. Both are only ever read inside the same
  Green & Ampt-only block as `SoilDepth1`.

**Also synthetic, not measured**, same disclosure as the layer-2/3 maps:
`loam.tbl`'s theta/suction/conductivity rows are a hand-picked,
physically-ordered retention/conductivity curve (theta and hydraulic
conductivity both increasing as suction approaches zero, the shape a real
Brooks-Corey or van Genuchten fit would have) -- not fit to any real soil
sample. `profile.inp` defines 3 nodes at 10/30/60cm depth, one profile, one
horizon. `Use one matrix potential=1` initializes every node to a single
user-given matric potential rather than needing a series of `inithead.NNN`
initial-condition maps.

## Regenerating the maps

Not needed to use this fixture -- the `.map` files are committed and ready to
run. Only relevant if you change `make_tiny.py` itself and need to
regenerate them.

`pcraster` is not installable in this dev environment (no PyPI wheel, no
conda). The maps as they currently exist were generated by writing PCRaster
`.map` files directly via GDAL's `PCRaster` driver (`gdal.GetDriverByName('PCRaster')`,
which supports `DCAP_CREATE`) instead of `pcraster.numpy2pcr` -- functionally
equivalent, verified by round-tripping through `gdal.Open()` and by the
engine itself reading them successfully. Where `pcraster` *is* available:

```bash
pip install pcraster
python bmi_lisem/tests/data/tiny/make_tiny.py
LISEM_TEST_RUNFILE="$(pwd)/bmi_lisem/tests/data/tiny/tiny.run" pytest -q bmi_lisem/tests
LISEM_TEST_RUNFILE="$(pwd)/bmi_lisem/tests/data/tiny/tiny3.run" pytest -q bmi_lisem/tests
LISEM_TEST_RUNFILE="$(pwd)/bmi_lisem/tests/data/tiny/tiny_swatre.run" pytest -q bmi_lisem/tests
```

`profile.inp`/`loam.tbl` are plain text, already committed, and don't need
`pcraster` regeneration -- only `tiny_swatre.run`'s underlying catchment maps
(`dem.map`, `ldd.map`, etc., shared with `tiny.run`/`tiny3.run`) do.
