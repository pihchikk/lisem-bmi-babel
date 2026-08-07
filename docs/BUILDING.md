# Building bmi_lisem

`bmi_lisem` is a native, in-process BMI wrapping the vendored OpenLISEM engine.
Building has two stages: (1) build the native shared library `libbmilisem.so`
with CMake, then (2) build/install the Python package with meson-python.

## 1. Native prerequisites

- C++17 compiler + CMake + ninja/make
- **GDAL** (raster I/O)
- **Qt 6**: Core, Gui, Widgets, Network (default build)
- **QWT** (default build)
- **OpenGL / GLX** (pulled in by the GUI build)

On Debian/Ubuntu-like systems these come from `libgdal-dev`, `qt6-base-dev`,
`libqwt-qt6-dev`, and the Mesa GL dev packages; QWT may need a manual prefix
(e.g. `/usr/local/qwt-6.4.0-ma`).

## 2. Build the native library

```bash
cd openlisem_bmi
cmake -S . -B build
cmake --build build -j4
# outputs: build/libbmilisem.so and a pkg-config file bmilisem.pc
```

Make the library and its pkg-config file discoverable when building/using the
Python package:

```bash
export LD_LIBRARY_PATH="$PWD/build:$LD_LIBRARY_PATH"
export PKG_CONFIG_PATH="$PWD/build:$PKG_CONFIG_PATH"
```

### Headless build (no GUI / OpenGL / QWT)

For servers, containers, and conda-forge, build the engine without the Qt GUI
stack. This drops `Qt6Gui`, `Qt6Widgets`, `qwt`, `GLX`, and `OpenGL` from the
link line, greatly shrinking the wheel and removing the runtime GL dependency:

```bash
cd openlisem_bmi
cmake -S . -B build -DBMI_HEADLESS=ON
cmake --build build -j4
```

The BMI already runs with `noInterface = true`, so no GUI functionality is lost
for BMI use.

## 3. Build/install the Python package

```bash
cd ..                      # repo root
pip install --no-build-isolation .
```

`meson.build` reads the project version from `bmi_lisem/_version.py` (single
source of truth) and links `bmilisem` via pkg-config.

### Editable installs and shadowing

A **non-editable** install is recommended. With an editable install the
`bmi_lisem/` source directory shadows the compiled extension on the import path,
so `from bmi_lisem import Lisem` can import the pure-Python package without the
compiled `Lisem` class. If you must use an editable install, run tests from a
directory that is **not** the repo root (so the source tree does not shadow the
installed wheel), e.g.:

```bash
pip install --no-build-isolation --editable .
cd /tmp && pytest -q /path/to/repo/bmi_lisem/tests
```

## 4. Run the tests

```bash
# Against a real runfile:
export LISEM_TEST_RUNFILE=/abs/path/to/run.run
pytest -q bmi_lisem/tests
```

Without `LISEM_TEST_RUNFILE` (and without a bundled tiny dataset), data-dependent
tests are skipped.

**On this development machine**, the standard runfile is
`/home/claude/lisem-work/VNIIMZ_20m/res_test/run_test.run` (real 20m catchment,
paths pre-corrected for this host — the dataset's other `.run` files carry
absolute paths from different environments and won't resolve here). Setting it
unblocks all 13 data-dependent tests with **no `pcraster` install** — see
`scripts/run_local_tests.sh`, which wires this path plus the
`LD_LIBRARY_PATH`/de-shadowing steps above into one command, and README.en.rst's
"Input data" section for why none of these tests actually need `pcraster`
(the two that read `.map` output already do it via `osgeo.gdal`; `pcraster`
is only ever touched by the optional, currently-broken `tests/data/tiny/`
synthetic-scaffold generator, which this project doesn't rely on).

A full run against `VNIIMZ_20m` takes about 4 minutes per event (360
`update()` calls over the full 6,821-cell grid — CPU cost is modest, most of
the wall time is the engine's own per-step console logging). Seven of the 13
tests each run a full event, so the suite takes roughly 25-30 minutes end to
end.
