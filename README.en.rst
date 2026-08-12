=========
bmi_lisem
=========

.. image:: https://img.shields.io/badge/CSDMS-Basic%20Model%20Interface-green.svg
        :target: https://bmi.readthedocs.io/
        :alt: Basic Model Interface

.. image:: https://img.shields.io/badge/license-GPL--3.0--or--later-blue.svg
        :target: LICENSE.rst
        :alt: License: GPL-3.0-or-later

.. start-intro

*(This is the English reference README. GitLab renders* ``README.md`` *(Russian
quickstart) by default at the repo root — see that file, or read on here for
the full English documentation.)*

**bmi_lisem** is a native, in-process `Basic Model Interface (BMI)
<https://bmi.readthedocs.io/>`_ for the `OpenLISEM
<https://github.com/vjetten/openlisem>`_ event-based hydrological and soil-erosion
model. The complete OpenLISEM engine is vendored under ``openlisem_bmi/`` and
wrapped by a C++ ``bmi::Bmi`` component (``openlisem_bmi/bmi_lisem/BmiLisem.cpp``);
the babelizer generates the Cython/Python binding ``bmi_lisem.Lisem`` on top of it.

The primary purpose of this package is **physically coupled simulation** — in
particular coupling OpenLISEM (surface water, infiltration, erosion) with
AquaCrop (crop/soil water) through a shared BMI vocabulary of standard variable
names, so post-event soil moisture, layer depths, erosion, and catchment
water-balance totals can be exchanged in-process.

.. list-table::
  :header-rows: 1
  :width: 90%
  :widths: auto

  * - Library
    - Component
    - PyMT
  * - bmilisem
    - :class:`~bmi_lisem.Lisem`
    -
      .. code-block:: pycon

        >>> from pymt.models import Lisem

.. end-intro

License
=======

This distribution as a whole is licensed **GPL-3.0-or-later**. OpenLISEM
(vendored under ``openlisem_bmi/``) is GPL-3.0, and the built wheel statically
links it, so the combined package is a derivative work governed by the GPL-3.0
(see ``LICENSE.rst`` and ``openlisem_bmi/GPL-v3.0.txt``). The original glue code
authored for this repository (the ``BmiLisem`` wrapper, babelizer config, tests,
docs) may additionally be used by its authors under the MIT License
(``LICENSE-MIT``), but the distributed package remains GPL-3.0.

Native dependencies
===================

The engine is a Qt/GDAL C++ application, so building the native library
(``libbmilisem.so``) requires the following to be installed **before** building
the Python package:

* A C++17 compiler and CMake
* **Qt 6** (Core, Gui, Widgets, Network) — even though the BMI runs headless
  (``noInterface = true``), the default engine links the Qt GUI libraries. See
  the optional headless build below to drop the GUI/OpenGL/QWT dependencies.
* **QWT** (Qt widgets for technical applications)
* **GDAL**
* **OpenGL / GLX** (pulled in transitively by the GUI build)

.. warning::

  The default wheel links Qt6 Widgets/Gui, QWT and OpenGL. On a headless machine
  you may need the corresponding system libraries (or an ``xvfb``-style stub) for
  import to succeed. A headless CMake target
  (``-DBMI_HEADLESS=ON``) is available to build the engine without
  Qt Widgets/Gui, QWT and OpenGL — see ``docs/BUILDING.md``.

Install
=======

.. start-quickstart

Install from source
-------------------

Build the native BMI library first, then install the Python package.

.. code:: bash

  # 1. Build the native shared library (libbmilisem.so)
  cd openlisem_bmi
  cmake -S . -B build            # add -DBMI_HEADLESS=ON for a GUI-free build
  cmake --build build -j4
  # ensure libbmilisem.so / bmilisem.pc are discoverable (LD_LIBRARY_PATH /
  # PKG_CONFIG_PATH point at openlisem_bmi/build)

  # 2. Build and install the Python package
  cd ..
  pip install --no-build-isolation .

.. warning::

  A **non-editable** install is recommended. With an editable install the
  ``bmi_lisem`` source directory shadows the compiled extension on the import
  path, so ``from bmi_lisem import Lisem`` may import the pure-Python package
  without the compiled ``Lisem`` class. If you must use an editable install,
  run tests from a directory that is not the repo root.

.. end-quickstart

Usage
=====

.. start-usage

Quickstart with the bundled scenario
------------------------------------

No runfile of your own needed to try the BMI against a real catchment —
``bmi_lisem.scenarios.default_scenario_runfile()`` writes a ready-to-use
runfile for a real 20m-resolution catchment and a single real storm event
(``meta/Lisem/vniimz_20m/``; see that directory's ``README.md`` for exactly
what it is and how it was curated).

.. note::

   These catchments live in the repository and are **not installed into the
   wheel** — a built ``.whl`` ships code only. So this works from a source
   checkout; from an installed wheel ``default_scenario_runfile()`` raises
   ``FileNotFoundError`` (naming both paths it searched), and you pass
   ``initialize()`` a path to your own runfile instead. To bundle the data
   again, restore the ``install_subdir`` call in ``meson.build`` — the
   commented-out block there says how.

.. code-block:: pycon

  >>> import numpy as np
  >>> from bmi_lisem import Lisem
  >>> from bmi_lisem.scenarios import default_scenario_runfile
  >>> model = Lisem()
  >>> model.initialize(default_scenario_runfile())
  >>> model.get_component_name()
  'OpenLISEM'
  >>> end = model.get_end_time()
  >>> while model.get_current_time() < end - 1e-9:
  ...     model.update()
  >>> n = model.get_grid_size(model.get_var_grid("soil_infiltration~amount"))
  >>> fcum = np.empty(n, dtype=np.float64)
  >>> model.get_value("soil_infiltration~amount", fcum)   # cumulative infiltration, metres
  >>> model.finalize()

``default_scenario_runfile(result_dir=...)`` accepts an optional directory
for OpenLISEM's own report outputs (totals.csv, map series); defaults to a
fresh temporary directory if omitted.

Using your own runfile
----------------------

.. code-block:: pycon

  >>> import numpy as np
  >>> from bmi_lisem import Lisem
  >>> model = Lisem()
  >>> model.initialize("/abs/path/to/run.run")   # runfile path
  >>> model.get_component_name()
  'OpenLISEM'
  >>> model.get_output_var_names()               # canonical standard names
  >>> end = model.get_end_time()
  >>> while model.get_current_time() < end - 1e-9:
  ...     model.update()
  >>> n = model.get_grid_size(model.get_var_grid("soil_water_actual"))
  >>> theta = np.empty(n, dtype=np.float64)
  >>> model.get_value("soil_water_actual", theta)
  >>> model.finalize()

.. warning::

  Runfiles reference input maps by path. Prefer **absolute paths** in the
  runfile (or run with the working directory set to the runfile's ``Map
  Directory``); relative paths are resolved against the process working
  directory, not the runfile location. ``default_scenario_runfile()`` above
  already handles this for the bundled scenario.

.. end-usage

Standard variable names
=======================

The registry stores **canonical ESoil standard names**; legacy CSDMS names
(``object__quantity``) are still accepted on every name-keyed call via an alias
layer, but ``get_output_var_names()`` / ``get_input_var_names()`` advertise only
the canonical names. The full old→new table is in
``bmi_lisem/docs/STANDARD_NAMES_ALIASES.md``. Coupling-critical names
(``soil_water_actual``, ``plant_cover~projective``, ``soil_water_actual_layer-N``)
match the AquaCrop BMI vocabulary.

Coupling variables
==================

Exposed for physical coupling (full table with sources/units in
``bmi_lisem/docs/COUPLING_VARS_LEDGER.md``):

* **Per-layer post-event soil moisture** — ``soil_water_actual_layer-{1,2,3}``
  (grid 0, ``m3 m-3``); refreshed by ``avgTheta()`` after every ``update()`` and
  ``update_until()``.
* **Soil layer depths** — ``soil_layer-depth~layer-{1,2,3}`` (grid 0, ``m``).
* **Erosion** — ``soil_erosion~mass-per-area`` (grid 0, ``kg m-2``). Note: this
  variable is scaled on read; ``get_value_ptr`` is intentionally unavailable for
  it (the raw buffer is kg/cell) — use ``get_value``.
* **Catchment water-balance totals** (grid 1, rank-0 scalars, ``m3``) —
  ``surface-water~{rainfall,interception,infiltration,evapotranspiration,storage,runoff}_volume``.

Event reset (``ResetEvent`` / ``model__reset_event``)
=====================================================

OpenLISEM is event-based. Between rainfall events a coupler can reset the
dynamic state (surface water, cumulative infiltration/erosion, balance totals)
**without** re-reading the static terrain/parameters, by restoring an initial
snapshot taken at ``initialize()``. This is triggered through the write-only
scalar control variable ``model__reset_event`` (grid 1): writing any value calls
``TWorld::ResetEvent()``. ``model__reset_event`` is a control signal, not a
physical variable, and is not aliased.

Input data
==========

An OpenLISEM run needs a runfile plus PCRaster input maps (LDD, DEM, Ksat, mask,
land use, cohesion, gradient, …) and a rainfall table. Two ready-to-use datasets
ship **in this repository** — no external download is needed to run the model or
the test suite from a source checkout. Neither is installed into the wheel (see
the note under "Quickstart" above):

* **``meta/Lisem/vniimz_20m/``** — a real, measured 20m-resolution catchment
  (204×89 grid, 6,821 in-catchment cells) and a single real storm event,
  curated down to exactly the ~3.5MB of files this scenario needs. Use it via
  ``bmi_lisem.scenarios.default_scenario_runfile()`` (see "Quickstart with the
  bundled scenario" above) — not the template file directly, which has
  unresolved ``{MAP_DIR}``/``{RAIN_DIR}``/``{RESULT_DIR}`` placeholders.
  Green & Ampt infiltration (``Infil Method=3``), 2 soil layers, erosion
  enabled. ``Include Infiltration=1`` is load-bearing here: with it ``0``,
  ``TWorld::InfilEffectiveKsat()`` early-returns and every
  infiltration-dependent quantity (``ThetaI1a``, infiltration/interception/ET/
  runoff volumes, the water-balance closure) is structurally zero for the
  whole run, not physically computed. See ``meta/Lisem/vniimz_20m/README.md``
  for the full provenance/curation notes.
* **``bmi_lisem/tests/data/tiny/``** — three small synthetic 10×10 catchments
  (``tiny.run`` 1-layer Green & Ampt, ``tiny3.run`` 3-layer, ``tiny_swatre.run``
  SWATRE), built to exercise specific code paths quickly rather than to model
  a real place — disclosed as synthetic in that directory's own ``README.md``.
  The ``.map`` inputs are committed directly, so these run with **no
  ``pcraster`` dependency**. The test suite auto-detects ``tiny.run`` with
  *zero configuration* (no environment variable needed) — see "Running the
  tests" below.

To point the test suite at a different, larger, or your own real dataset
instead, set ``LISEM_TEST_RUNFILE`` to an absolute runfile path — this always
takes priority over the bundled scenario.

Running the tests
=================

.. code:: bash

  scripts/run_local_tests.sh

This is the recommended invocation — it wires up everything the test suite
needs so nothing silently skips:

* ``LD_LIBRARY_PATH`` → the built ``libbmilisem.so``.
* ``LISEM_TEST_RUNFILE`` → the bundled ``vniimz_20m`` scenario by default
  (via ``default_scenario_runfile()``), or whatever you've exported yourself.
* Runs from a copy of ``bmi_lisem/tests/`` *outside* the repo, so
  ``import bmi_lisem`` resolves to the installed wheel (compiled extension)
  rather than being shadowed by the source tree — see docs/BUILDING.md's
  "Editable installs and shadowing" section.
* ``LISEM_BMI_CPP_SRC`` → so the alias-table sync test
  (``test_alias_table_matches_cpp_source``) can check the Python ``ALIASES``
  dict against ``kAlias``, its native source of truth.

Extra arguments pass straight through to ``pytest``, e.g.
``scripts/run_local_tests.sh -k TestFiniteness -v``.

**None of this needs ``pcraster``** — confirmed by reading every test file,
not assumed:

* Metadata and post-event-value tests only call the BMI array interface
  (``get_value``, ``get_output_var_names``, etc.) — no map I/O of any kind.
* The two tests that cross-check LISEM's own written ``.map`` output
  (``test_rainfall_amount_matches_own_rainfall_map``,
  ``test_runoff_amount_matches_own_runoff_map``) read it via ``osgeo.gdal``
  (``_read_pcraster()`` in ``test_coupling_vars.py`` — the name is legacy, the
  implementation is pure GDAL).
* ``pcraster`` is only ever imported by ``bmi_lisem/tests/data/tiny/make_tiny.py``,
  the *generator* that originally produced ``tiny/``'s ``.map`` files — not
  needed to use them, since they're committed. Only relevant if you change
  ``make_tiny.py`` itself and need to regenerate its output; see that
  directory's ``README.md``.

Running without ``scripts/run_local_tests.sh`` directly against ``pytest``
also works and needs no environment variable at all — ``tiny.run`` is
auto-detected whenever its bundled maps are present (always true after a
plain ``git clone``):

.. code:: bash

  LD_LIBRARY_PATH=openlisem_bmi/build pytest bmi_lisem/tests

(subject to the same editable-install shadowing caveat as above if running
from the repo root with an editable install).

Building headless / development
===============================

See ``docs/BUILDING.md`` for the full native build recipe (QWT + CMake steps),
the ``-DBMI_HEADLESS=ON`` option, and the de-shadowing procedure for running the
test suite against a non-editable install.
