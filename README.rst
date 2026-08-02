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
  directory, not the runfile location.

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
====================================================

OpenLISEM is event-based. Between rainfall events a coupler can reset the
dynamic state (surface water, cumulative infiltration/erosion, balance totals)
**without** re-reading the static terrain/parameters, by restoring an initial
snapshot taken at ``initialize()``. This is triggered through the write-only
scalar control variable ``model__reset_event`` (grid 1): writing any value calls
``TWorld::ResetEvent()``. ``model__reset_event`` is a control signal, not a
physical variable, and is not aliased.

Input data
=========

An OpenLISEM run needs a runfile plus PCRaster input maps (LDD, DEM, Ksat, mask,
land use, cohesion, gradient, …) and a rainfall table. Set the environment
variable ``LISEM_TEST_RUNFILE`` to an absolute runfile path to exercise the test
suite against real data; without it (and without a bundled tiny dataset) the
data-dependent tests are skipped.

**Standard local invocation, this development environment:**

.. code:: bash

  export LISEM_TEST_RUNFILE=/home/claude/lisem-work/VNIIMZ_20m/res_test/run_test.run

This points at ``VNIIMZ_20m``, a real 20m-resolution catchment (204×89 grid,
6,821 in-catchment cells) kept outside this repo. ``res_test/run_test.run`` is
the one runfile in that dataset with paths already corrected for this machine
(the others use absolute paths from other environments — WSL, a Jupyter
container — and won't resolve here).

Setting this unblocks all 13 currently-skipping tests in
``bmi_lisem/tests/`` (``test_standard_names.py`` and
``test_coupling_vars.py``). **None of them need ``pcraster``** — confirmed by
reading every test file, not assumed:

* Metadata and post-event-value tests only call the BMI array interface
  (``get_value``, ``get_output_var_names``, etc.) — no map I/O of any kind.
* The two tests that do cross-check LISEM's own written ``.map`` output
  (``test_rainfall_amount_matches_own_rainfall_map``,
  ``test_runoff_amount_matches_own_runoff_map``) already read it via
  ``osgeo.gdal`` (``_read_pcraster()`` in ``test_coupling_vars.py`` — the name
  is legacy, the implementation is pure GDAL, worked around a pip-wheel gap
  with raw ``ReadRaster()`` bytes instead of ``ReadAsArray()``).
* ``pcraster`` is only ever imported by ``make_tiny.py``, to generate the
  optional synthetic ``tests/data/tiny/`` scaffold — an alternative to
  ``LISEM_TEST_RUNFILE`` for environments with no real dataset available (e.g.
  a from-scratch CI runner). It isn't installable from PyPI under any name
  here, and there's no conda in this environment either, but that path isn't
  needed at all once a real runfile is set. (It's also a dead end as shipped:
  ``tiny.run`` uses the GUI's human-readable keys, e.g. ``Gradient=grad.map``,
  while the engine's runfile parser looks up entries by internal variable
  name, e.g. ``grad=grad.map`` — the same class of mismatch ``VNIIMZ_20m``'s
  own uncorrected runfiles originally hit; see ``docs/BUILDING.md``.)

Building headless / development
==============================

See ``docs/BUILDING.md`` for the full native build recipe (QWT + CMake steps),
the ``-DBMI_HEADLESS=ON`` option, and the de-shadowing procedure for running the
test suite against a non-editable install.
