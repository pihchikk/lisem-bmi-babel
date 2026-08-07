# VNIIMZ_20m default scenario (real catchment data)

A real, measured 20m-resolution catchment (204×89 grid, 6,821 in-catchment
cells) and a single real rainfall event, curated down to exactly what
`run_test.run.template` needs — not the full project working directory this
was extracted from, which also contains report outputs from repeated runs,
an unrelated stray runfile, and GDAL sidecar files that aren't read by the
engine.

This is the "real dataset" counterpart to `bmi_lisem/tests/data/tiny/`'s
synthetic fixtures: same BMI, a genuine measured catchment and storm event
instead of a hand-built 10×10 grid.

## What is committed

- `maps/` — 50 PCRaster `.map` input files: LDD, DEM, Ksat (2 soil layers),
  porosity, initial moisture, soil depth, cohesion, roughness, land use,
  outlet, and the handful of other maps this configuration's active switches
  read. Real, measured data, not synthetic.
- `rain.txt` — a single real storm event ("fullcatch live coupling event
  rainfall"), the rainfall table this scenario replays.
- `run_test.run.template` — the runfile, with `{MAP_DIR}`, `{RAIN_DIR}`, and
  `{RESULT_DIR}` standing in for the three host-specific absolute paths
  OpenLISEM's runfile format requires. Not usable directly — see "Using this
  scenario" below.

## Configuration

Green & Ampt / Smith & Parlange infiltration (`Infil Method=3`), 2 soil
layers, a single ~12-hour event, erosion enabled, ET and interception
disabled. `Include Infiltration=1` is load-bearing: with it `0`,
`TWorld::InfilEffectiveKsat()` early-returns and several BMI outputs
(`ThetaI1a`, interception/infiltration/ET/runoff volumes) never leave their
zero-initialized default for the entire run — see `README.en.rst`'s "Input
data" section.

## Using this scenario

`run_test.run.template` cannot be passed to `initialize()` directly — its
three directory placeholders need substituting with real, absolute paths
first (`Result Directory` in particular must be a real, writable location on
this machine, not the placeholder). Use the packaged helper rather than
hand-editing the template:

```python
from bmi_lisem.scenarios import default_scenario_runfile
from bmi_lisem import Lisem

runfile = default_scenario_runfile()   # writes a ready runfile, returns its path
m = Lisem()
m.initialize(runfile)
```

See `README.en.rst`'s quickstart section for the full example, including
`result_dir=` to control where reports get written.

## Verified

`initialize()` → full `update()` loop → `finalize()` succeeds against this
exact, copied-into-the-repo copy of the data (not just the original external
directory it was extracted from) — confirmed directly after copying, not
assumed to carry over unchanged.
