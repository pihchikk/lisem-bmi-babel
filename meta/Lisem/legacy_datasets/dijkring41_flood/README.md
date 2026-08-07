# Dijkring41_Flood (legacy SourceForge example dataset)

A real Dutch dike-ring flood-hazard domain (875×625 grid, **546,875 cells**)
— by far the largest fixture in this project (~30× the next-largest), from
openLISEM's own upstream example datasets (SourceForge,
`Example Datasets/Dijkring41_Flood.7z`). No infiltration model
(`Infil Method=0`), no erosion, pure overland flood routing driven by a real
rainfall event. The dataset's own runfile points its rainfall directory at
`Ganspoel_Hydrology`'s rain folder (`p980914.txt`) — a deliberate reuse
across the two datasets in the original teaching material, not a mistake;
kept as-is here.

Use via `bmi_lisem.scenarios.legacy_dataset_runfile("dijkring41_flood")` —
see `bmi_lisem/scenarios.py`. Not the template file directly.

## Provenance and curation

Ported from `[openLISEM runfile version 1.0]` the same way as the other
five datasets in this set — see `bmi_lisem/docs/COUPLING_VARS_LEDGER.md`'s
"External real-world datasets" section for the full writeup, including two
real engine bugs found and fixed while porting this batch (a comma-vs-
semicolon crash in `KE parameters`, and a silent rainfall day-index bug).

`maps/` contains only the 20 files this configuration's runfile actually
references, taken from the original archive's `40m_maps/` directory (two
other resolutions, `5m_dem/` and `20m_dem/`, exist in the archive for a
different exercise and aren't used here).

`p980914.txt` here is **converted**, not the original file — the source is
in the old `RUU CSF TIMESERIE` format, a genuinely different, explicitly
unsupported rainfall-file variant from the day-index bug documented in the
ledger (see `ganspoel_hydrology/README.md` for the full explanation,
including a real, separate bug: the engine's own check meant to reject this
format doesn't actually fire for genuine old-format files). Converted here
to the current format, preserving every original minute/intensity value.

## A genuine, unresolved anomaly at this scale — disclosed, not fixed

`soil_water_actual`/`soil_water_actual_layer-1` read **12.5–32.0** over a
full run — outside the physically valid 0–1 range for a volumetric water
content fraction. Root-caused (see the ledger): `Infil Method=0` has no
dedicated code path in this engine version's `cell_InfilMethods()` — it
silently falls through to a real Smith & Parlange infiltration calculation
instead of skipping infiltration, using Ksat/Psi/theta values the dataset
was never validated against for that formula. **Not fixed** — this would be
a genuine behavior change to what `Infil Method=0` does elsewhere too, so it
wasn't changed without a decision on intent first. A coupling partner
reading soil moisture from this specific fixture should expect this.

## Verified

`initialize()` → full `update()` loop → `finalize()` succeeds (real
computational cost: ~35 minutes wall-clock on this scale). Real, non-zero
rainfall (14.1mm, uniform) and infiltration/rainfall volumes closely matched
(~7.18M m³) — physically consistent aside from the theta anomaly above.

## A known data-curation gap: `soildepth1.map` isn't clipped to the catchment

`soil_layer-depth~layer-1` (`SoilDepth1`) reads valid (non-NaN) everywhere on
the full 875×625 grid, while other rasters derived from the same catchment —
e.g. `soil_infiltration~amount` — correctly read NaN outside the catchment
mask (229,699 of 546,875 cells). Caught by the project's own `TestFiniteness`
invariant (every raster output should agree on which cells are outside the
catchment); confirmed at this dataset's full scale, the same gap already
documented for `ganspoel_hydrology`. The soil-depth source map in this port's
`maps/` was never clipped to the mask — a curation gap in this dataset's
`maps/`, not an engine defect. A coupling partner reading soil-depth-related
variables from this specific fixture should expect valid-looking values
outside the real catchment boundary.
