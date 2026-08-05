# StLucias_DebrisFlood (legacy SourceForge example dataset)

A real St. Lucia catchment (614×487 grid, 299,018 cells) and a real "5-year"
design storm (`5 year johnson.txt`, 103mm), from openLISEM's own upstream
example datasets (SourceForge, `Example Datasets/StLucias_DebrisFlood.7z`).
Green & Ampt infiltration (`Infil Method=4`, normalized to 3 by the engine
itself), 2 soil layers, channels included, erosion enabled, roads/buildings
included — the most fully-featured of the six legacy fixtures.

Use via `bmi_lisem.scenarios.legacy_dataset_runfile("stlucias_debrisflood")`
— see `bmi_lisem/scenarios.py`. Not the template file directly.

## Provenance and curation

Ported from `[openLISEM runfile version 1.0]` — see
`bmi_lisem/docs/COUPLING_VARS_LEDGER.md`'s "External real-world datasets"
section for the full writeup. `maps/` contains only the 40 files this
configuration's runfile actually references, from the original archive's
`catchment33/` directory. `5 year johnson.txt` is the **original,
unmodified** rainfall file — no format conversion needed once the day-index
parser fix (see the ledger) is applied; this exact file is shared verbatim
with `stlucia_flashflood/`, and both hit the identical silent-zero-rainfall
bug before that fix.

Baseflow was left off in this port even though the original runfile wants it
(`Include channel baseflow=1`): the current engine's baseflow mechanism needs
`lddbase`/`basereach` maps this dataset never had. Enabling it would mean
fabricating routing data — a bigger, separate guess, not a faithful port.

## Verified

`initialize()` → full `update()` loop → `finalize()` succeeds (real
computational cost: ~35 minutes wall-clock at this scale). Real, non-zero
rainfall (103.8mm, matching the file's own documented "103mm" total
exactly), infiltration up to 11.6mm, depth up to 11.4m, channel discharge up
to 252 m³/s, erosion −3452 to 615 kg/m² (both detachment and deposition).
