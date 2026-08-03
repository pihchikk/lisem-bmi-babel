# Tiny synthetic catchment (CI test data)

A 10×10 synthetic OpenLISEM catchment used to exercise the BMI in CI without a
real dataset. Two runfiles share this map directory:

- `tiny.run` — single-layer soil (`Nr input layers=1`), ~1-2s per run.
- `tiny3.run` — three-layer soil (`Nr input layers=3`), same catchment,
  built specifically to demonstrate `soil_water_actual_layer-3` /
  `SwitchThreeLayer` actually work, not just argue it from source. See
  "Three-layer fixture" below.

## What is committed

- `make_tiny.py` — generator that writes the PCRaster `.map` inputs (needs
  `pcraster`, which is not installable in this dev environment -- see
  "Regenerating the maps" below).
- `tiny.run`, `tiny3.run` — runfiles (absolute, host-specific paths; see each
  file's own header comment).
- `rain.txt` — a short rainfall table (note: LISEM's rainfall-file format is
  `# comment` / column-count / literal `timestep` / station-count / then
  `DDD:HHMM value` rows -- not raw minutes-since-start, which is what an
  earlier draft of this file used and which fails to parse).

The `.map` binaries are **not committed** (`.gitignore` excludes `*.map` and
`*.csv`) — generate them with `make_tiny.py`, or see "Regenerating the maps"
if `pcraster` isn't available.

## Status: verified working (2026-08)

Both runfiles have been confirmed end-to-end against the real built engine:
`initialize()` → full `update()` loop → `finalize()`, with the actual
`bmi_lisem` pytest suite run against each via `LISEM_TEST_RUNFILE`.

- `tiny.run`: 23 passed / 2 skipped (own-map cross-check tests skip because
  this fixture's runfile doesn't have `OutRunoff`/etc enabled to write those
  maps -- unrelated to the fixture's own correctness) / 1 xfailed (balance
  residual ~20% on this toy catchment -- expected, matches the documented
  unaccounted-terms list in `COUPLING_VARS_LEDGER.md`).
- `tiny3.run`: 25 passed / 1 failed. The one failure
  (`test_inactive_variable_raises_cleanly`) is the test's own hardcoded
  assumption that `soil_water_actual_layer-3` is always inactive -- true for
  every other fixture in this project, false here by design. Not a defect;
  pick a different genuinely-inactive probe variable for this fixture, or
  parametrize the test, if this needs to pass cleanly too.

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
`500.0` (mm). This does not change any of `tiny.run`'s already-reported pass
counts (they were passing regardless), but the *physics* those passes
exercised had an effectively negligible soil-1 layer depth throughout.

Layer-2/3 values are synthetic and plausible (permeability and porosity
decrease with depth, antecedent moisture increases with depth) -- picked to
exercise the code path, not to model a real place. See `make_tiny.py` for
the exact numbers.

## Regenerating the maps

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
```
