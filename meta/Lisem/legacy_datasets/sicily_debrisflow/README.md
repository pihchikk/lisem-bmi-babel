# Sicily_DebrisFlow (legacy SourceForge example dataset)

A real Sicilian catchment (140×230 grid, 32,200 cells) and a real 2-station
rainfall event, from openLISEM's own upstream example datasets (SourceForge,
`Example Datasets/Sicily_DebrisFlow.7z`). No infiltration model
(`Infil Method=0`), erosion enabled, roads/buildings included, no channels.

Use via `bmi_lisem.scenarios.legacy_dataset_runfile("sicily_debrisflow")` —
see `bmi_lisem/scenarios.py`. Not the template file directly.

## Provenance and curation

Ported from `[openLISEM runfile version 1.0]` — see
`bmi_lisem/docs/COUPLING_VARS_LEDGER.md`'s "External real-world datasets"
section for the full writeup. `maps/` contains only the 34 files this
configuration's runfile actually references. The rain-zone map is
`rainfallregion.map` (2 real zones matching the rainfall file's 2 stations)
rather than the original runfile's own alias to `mask.map` (a coarser
placeholder) — a more faithful choice available directly in the source data.

**`sicily_rainfall.txt` here is not the original file, unlike the other five
datasets in this set.** The original runfile sets `Begin time=-100, End
time=400` (a 100-minute pre-event window before the rain data's own t=0) —
representable in `version 1.0`'s plain-minutes format but not directly in
`version 6.0`'s `ddd:mmmm` scheme, which has no negative-day representation.
Ported by shifting the whole window to `Begin time=001:0000, End
time=001:0500` and shifting every rainfall timestamp by the same +100
minutes, preserving the original's total duration and the exact relative
delay between simulation start and rain onset.

## A genuine, unresolved anomaly — disclosed, not fixed

`soil_water_actual_layer-1` reads **−110.5 to 0.283** over a full run —
negative, physically impossible for a volumetric water content fraction.
Same root cause as `dijkring41_flood`'s anomaly (see that dataset's README
and the ledger): `Infil Method=0` silently runs Smith & Parlange instead of
skipping infiltration. Confirmed here specifically that the input maps
themselves (`ksat.map`, `psi.map`, `thetas.map`, `thetai.map`) are sane,
uniform, physically valid values — the anomaly is in the computation, not
bad input data.

## Verified

`initialize()` → full `update()` loop → `finalize()` succeeds. Real,
non-zero rainfall (117.8mm), infiltration, erosion, depth, runoff, and
channel-adjacent discharge all present and sensible aside from the theta
anomaly above.
