Release Notes
=============

.. towncrier-draft-entries:: Not yet released

.. towncrier release notes start


0.2 (2026-08-12)
----------------

36 commits since 0.1.1, which was never re-released -- so "0.1.1" had come
to mean two materially different builds depending on where it came from.

Engine fixes
^^^^^^^^^^^^

- ``KE parameters EQ1/EQ2/EQ3`` no longer abort the process on comma-separated
  legacy runfiles; the parser bounds-checks and raises a catchable error.
- ``getTimefromString()``'s no-colon fallback used day-index 0 while
  ``Begin time`` uses day-index 1, so rainfall files without a ``ddd:`` prefix
  silently placed every record a full day before the run started -- every
  rainfall-dependent output read exactly zero, with no error. Fixed.
- ``Fcum`` is now accumulated under SWATRE (``Infil Method=1``); it had stayed
  at 0.0 for the whole run on that path.
- ``TWorld``'s conditionally-allocated map pointers are default-initialised,
  making BMI registry membership deterministic (it previously depended on heap
  garbage).
- ``ThetaI2a`` is allocated only when ``SwitchTwoLayer`` is set, so
  ``soil_water_actual_layer-2`` is no longer advertised when nothing fills it.
- ``Infil Method=0`` now warns at initialisation that it does *not* disable
  infiltration -- the model falls through to Smith & Parlange. Behaviour is
  deliberately unchanged; see ``bmi_lisem/docs/COUPLING_VARS_LEDGER.md``.

Packaging and data
^^^^^^^^^^^^^^^^^^

- New ``bmi_lisem.scenarios``: ``default_scenario_runfile()`` and
  ``legacy_dataset_runfile()`` return ready-to-use runfiles with absolute paths
  substituted in, so no runfile editing is needed to run the bundled data.
- Seven catchments now ship inside the package: the real VNIIMZ_20m scenario
  plus six upstream SourceForge example datasets.
- The synthetic ``tiny`` fixtures' ``.map`` inputs are committed, so the test
  suite no longer needs ``pcraster``.

Coupling variables
^^^^^^^^^^^^^^^^^^

- Added per-cell ``surface-water~rainfall_amount`` and
  ``surface-water~runoff_amount``, both verified against LISEM's own map output.

Tests
^^^^^

- Four test assumptions that only held for one fixture were made
  dataset-agnostic (rainfall onset, erosion-variable advertisement, runoff
  tolerance, and the "no runoff implies no detachment" assumption, which is
  wrong for rainsplash).
- Bundled runfiles' directory paths are rewritten at test time rather than
  trusted as committed, which is what broke CI when the ``.map`` files landed.


0.1.0 (2026-06-18)
------------------

- Initial release
