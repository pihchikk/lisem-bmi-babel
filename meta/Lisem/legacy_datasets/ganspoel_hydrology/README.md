# Ganspoel_Hydrology (legacy SourceForge example dataset)

A real, measured catchment (220×160 grid, 35,200 cells) and a real rainfall
event (`p980304.txt`, 1998-03-04), from openLISEM's own upstream example
datasets (SourceForge, `Example Datasets/Ganspoel_Hydrology.7z`). Green &
Ampt infiltration (2 soil layers), erosion enabled, roads/hard surfaces
included, no channels.

Use via `bmi_lisem.scenarios.legacy_dataset_runfile("ganspoel_hydrology")` —
see `bmi_lisem/scenarios.py`. Not the template file directly (unresolved
`{MAP_DIR}`/`{RAIN_DIR}`/`{RESULT_DIR}` placeholders).

## Provenance and curation

Original runfile declared `[openLISEM runfile version 1.0]` — a materially
older schema than this project's `version 6.0` runfiles. `run.run.template`
here is a from-scratch port: real settings preserved where the old schema
maps cleanly (`Infil Method=3`, `Nr input layers=2`, real `KE parameters`,
real calibration values), this project's own validated defaults used where
no clean old-format equivalent exists (documented inline in the template's
own comments). Full writeup of what porting a `version 1.0` runfile forward
actually requires: `bmi_lisem/docs/COUPLING_VARS_LEDGER.md`'s "External
real-world datasets" section.

`maps/` contains only the 43 files this specific configuration's runfile
actually references (out of a much larger real map set in the original
archive, most of it optional features this configuration doesn't use).

`p980304.txt` here is **converted**, not the original file: the source
rainfall table is in the genuinely old `RUU CSF TIMESERIE` format, which
this engine version explicitly rejects (`"The old RUU rainfall file format
is not longer supported"`) — a real, separate format from the day-index bug
documented in the ledger (that fix applies to a *different* rainfall
variant, used by the `stlucia_*` datasets in this set, whose original files
now work unmodified). Worth noting: the engine's own rejection check for
this format is itself broken — it looks for the substring `" RUU"` (a
leading space before RUU), but genuine old-format files have `RUU` as
literally the first word with no leading space, so the check never
actually fires; instead of the intended clear error, an unconverted file
here fails later with a confusing `"Number of stations in rainfall file
(0)"` message. Converted here to the current station-count/`ddd:mmmm`
format, preserving every original minute/intensity(mm/h) value exactly.

## Verified

`initialize()` → full `update()` loop → `finalize()` succeeds. Real,
non-zero results: infiltration 1.9–18mm, rainfall 9.1mm (uniform, single
rain station), plausible runoff and surface depth.

## A known data-curation gap: `soildepth1.map` isn't clipped to the catchment

`soil_layer-depth~layer-1` (`SoilDepth1`) reads valid (non-NaN) everywhere on
the full 220×160 grid, while other rasters derived from the same catchment —
e.g. `soil_erosion~mass-per-area` — correctly read NaN outside the catchment
mask (24,123 of 35,200 cells). This was caught by the project's own
`TestFiniteness` invariant, which expects every raster output to agree on
which cells are outside the catchment. The soil-depth source map in this
port's `maps/` was never clipped to the mask the way most other inputs here
were — a curation gap in this dataset's `maps/`, not an engine defect (the
engine faithfully reports whatever `soildepth1.map` actually contains). A
coupling partner reading soil-depth-related variables from this specific
fixture should expect valid-looking values outside the real catchment
boundary.
