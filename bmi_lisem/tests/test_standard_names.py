"""
Tests for the standard-name alias layer of the C++ BMI (BmiLisem).

The registry stores canonical ESoil standard names; legacy CSDMS names are
accepted on every name-keyed call via BmiLisem::resolveVarAlias(). These tests
verify, for the full alias table, that:
  * get_output_var_names()/get_input_var_names() advertise ONLY canonical names;
  * get_value / get_var_units return identical results for old and new spelling.

Requires an OpenLISEM runfile (LISEM_TEST_RUNFILE). Skipped without it.
Coupling-critical names (soil_water_actual, plant_cover~projective,
soil_water_actual_layer-N) must match the AquaCrop BMI vocabulary.
"""

import os

import numpy as np
import pytest
from _runfile import resolve_runfile

RUNFILE = resolve_runfile()
needs_runfile = pytest.mark.skipif(
    not RUNFILE,
    reason="no runfile: set LISEM_TEST_RUNFILE or generate tests/data/tiny",
)

# Full alias table: legacy CSDMS name -> canonical ESoil name.
# Must stay in sync with kAlias in BmiLisem.cpp -- test_alias_table_matches_cpp_source below
# parses the C++ literal directly and fails if this dict drifts from it. This table had
# drifted before that test existed: domain_soil_water_storage__volume pointed at the wrong
# canonical name here (surface-water~storage_volume instead of C++'s soil_water~storage_volume
# -- two different scalar outputs, one of which is dead code always reading 0.0), and two C++
# aliases were missing entirely. A legacy name silently resolving to the wrong variable is
# worse than a crash: the mismatch (0.0 vs a real accumulated value) has no error to notice.
ALIASES = {
    "soil_water__volume_fraction":            "soil_water_actual",
    "land_vegetation__cover_fraction":        "plant_cover~projective",
    "soil_water__volume_fraction_in_layer_1": "soil_water_actual_layer-1",
    "soil_water__volume_fraction_in_layer_2": "soil_water_actual_layer-2",
    "soil_water__volume_fraction_in_layer_3": "soil_water_actual_layer-3",
    "land_surface_water__depth":              "surface-water~depth",
    "channel_water__volume_flow_rate":        "water~channel_discharge",
    "soil_water__infiltration_depth":         "soil_infiltration~amount",
    "soil__layer_depth_1":                    "soil_layer-depth~layer-1",
    "soil__layer_depth_2":                    "soil_layer-depth~layer-2",
    "soil__layer_depth_3":                    "soil_layer-depth~layer-3",
    "soil__erosion_mass_per_area":            "soil_erosion~mass-per-area",
    "domain_rainfall__volume":                "surface-water~rainfall_volume",
    "domain_interception__volume":            "surface-water~interception_volume",
    "domain_infiltration__volume":            "surface-water~infiltration_volume",
    "domain_evapotranspiration__volume":      "surface-water~evapotranspiration_volume",
    "domain_soil_water_storage__volume":      "soil_water~storage_volume",
    "domain_runoff__volume":                  "surface-water~runoff_volume",
    "atmosphere_water__precipitation_leq-depth": "surface-water~rainfall_amount",
    "surface_water__runoff_depth":            "surface-water~runoff_amount",
}

# Coupling-critical names that MUST match the AquaCrop BMI.
COUPLING_CANONICAL = {
    "soil_water_actual",
    "plant_cover~projective",
    "soil_water_actual_layer-1",
    "soil_water_actual_layer-2",
    "soil_water_actual_layer-3",
}


def _make_model():
    from bmi_lisem import Lisem
    m = Lisem()
    m.initialize(RUNFILE)
    return m


def _run_to_end(m):
    end = m.get_end_time()
    while m.get_current_time() < end - 1e-9:
        m.update()


@needs_runfile
def test_var_lists_are_canonical_only():
    """get_input/output_var_names advertise only canonical names, never legacy."""
    m = _make_model()
    try:
        names = set(m.get_output_var_names()) | set(m.get_input_var_names())
        for legacy in ALIASES:
            assert legacy not in names, (
                f"legacy name {legacy!r} leaked into the advertised var lists"
            )
    finally:
        m.finalize()


@needs_runfile
def test_units_identical_for_both_spellings():
    """get_var_units returns the same UDUNITS string for legacy and canonical."""
    m = _make_model()
    try:
        advertised = set(m.get_output_var_names()) | set(m.get_input_var_names())
        for legacy, canon in ALIASES.items():
            if canon not in advertised:
                continue  # variable not registered for this runfile (inactive layer)
            u_old = m.get_var_units(legacy)
            u_new = m.get_var_units(canon)
            assert u_old == u_new, (
                f"units differ for {legacy}/{canon}: {u_old!r} vs {u_new!r}"
            )
    finally:
        m.finalize()


@needs_runfile
def test_get_value_identical_for_both_spellings():
    """get_value gives identical arrays/scalars for legacy and canonical names."""
    m = _make_model()
    try:
        advertised = set(m.get_output_var_names())
        _run_to_end(m)
        for legacy, canon in ALIASES.items():
            if canon not in advertised:
                continue
            grid = m.get_var_grid(canon)
            n = m.get_grid_size(grid)
            a = np.empty(n, dtype=np.float64)
            b = np.empty(n, dtype=np.float64)
            m.get_value(legacy, a)
            m.get_value(canon, b)
            np.testing.assert_allclose(
                a, b, equal_nan=True,
                err_msg=f"get_value mismatch between {legacy} and {canon}",
            )
    finally:
        m.finalize()


@needs_runfile
def test_erosion_scaled_by_canonical_name():
    """Erosion (kg/m2) scaling must work when called by the canonical name.

    soil_erosion~mass-per-area is TotalSoillossMap (lisTotalsMB.cpp:495), a signed net
    soil-loss quantity by design -- negative cells are net deposition, not a scaling or sign
    bug (see test_coupling_vars.py's test_erosion_finite_nonnegative for the full trace,
    which exercises the erosion/deposition split directly). This test is about the
    canonical-name scaling path specifically, so it only checks finiteness and units here.
    """
    m = _make_model()
    try:
        if "soil_erosion~mass-per-area" not in set(m.get_output_var_names()):
            pytest.skip("erosion not active for this runfile")
        _run_to_end(m)
        n = m.get_grid_size(m.get_var_grid("soil_erosion~mass-per-area"))
        e = np.empty(n, dtype=np.float64)
        m.get_value("soil_erosion~mass-per-area", e)
        finite = e[np.isfinite(e)]
        assert len(finite) > 0
        assert m.get_var_units("soil_erosion~mass-per-area") == "kg m-2"
    finally:
        m.finalize()


def _runfile_infil_method(runfile_path):
    """Reads "Infil Method" directly from the runfile (list-directed .run format), mirroring
    test_coupling_vars.py's _parse_runfile_setting -- duplicated rather than imported to keep
    this file's only cross-module dependency the shared _runfile helper (tests run from a copy
    outside the repo; see docs/BUILDING.md)."""
    with open(runfile_path, encoding="utf-8", errors="replace") as handle:
        for line in handle:
            if line.strip().startswith("Infil Method="):
                return line.split("=", 1)[1].strip()
    return None


@needs_runfile
def test_coupling_names_present():
    """Coupling-critical canonical names shared with AquaCrop are advertised."""
    m = _make_model()
    try:
        advertised = set(m.get_output_var_names()) | set(m.get_input_var_names())
        # layer-2/-3 are optional (depend on runfile layer count)
        required = {"soil_water_actual", "plant_cover~projective",
                    "soil_water_actual_layer-1"}
        # soil_water_actual (ThetaI1) is only ever ReadMap()'d inside lisDataInit.cpp's
        # "InfilMethod != INFIL_SWATRE" block -- genuinely absent under SWATRE (Infil
        # Method=1), confirmed against tiny_swatre.run, not assumed.
        if _runfile_infil_method(RUNFILE) == "1":
            required.discard("soil_water_actual")
        for name in required:
            assert name in advertised, f"coupling name {name!r} not advertised"
    finally:
        m.finalize()


def _find_bmilisem_cpp():
    """Locates BmiLisem.cpp so the alias table can be checked against its actual source of
    truth (kAlias), not just against itself. Checks LISEM_BMI_CPP_SRC first (set by
    scripts/run_local_tests.sh and CI, since tests are deliberately run from a copy outside
    the repo -- see docs/BUILDING.md's "Editable installs and shadowing" -- so a path relative
    to this file only resolves when running directly from a repo checkout); falls back to that
    relative guess for ad hoc invocations. Returns None if neither exists, so the test below
    can skip with a clear reason instead of failing on an unrelated environment gap.
    """
    env_path = os.environ.get("LISEM_BMI_CPP_SRC", "")
    if env_path and os.path.isfile(env_path):
        return env_path
    guess = os.path.join(
        os.path.dirname(__file__), "..", "..", "openlisem_bmi", "bmi_lisem", "BmiLisem.cpp"
    )
    return guess if os.path.isfile(guess) else None


def _parse_cpp_kalias(path):
    """Extracts kAlias's { "legacy", "canonical" } pairs directly from BmiLisem.cpp's source
    text. No native rebuild needed to check this, unlike exposing the table through the BMI
    itself would be -- resolveVarAlias() is private and BMI has no enumerate-aliases call."""
    import re

    text = open(path, encoding="utf-8").read()
    start = text.index("kAlias = {")
    end = text.index("};", start)
    body = text[start:end]
    return dict(re.findall(r'\{\s*"([^"]+)"\s*,\s*"([^"]+)"\s*\}', body))


def test_alias_table_matches_cpp_source():
    """ALIASES (this file) must stay in sync with kAlias (BmiLisem.cpp) -- the C++ table is
    the actual source of truth; this Python copy exists only so the other tests in this file
    have something to iterate over without a BMI call to enumerate aliases. A previous drift
    here (domain_soil_water_storage__volume pointing at the wrong canonical name, and two
    aliases missing outright) went undetected because every OTHER test in this file only
    checks self-consistency of this same wrong copy -- this is the one test that checks it
    against the real thing. Does not need a runfile or an initialized model, only the source
    file, so it isn't gated by @needs_runfile.
    """
    cpp_path = _find_bmilisem_cpp()
    if cpp_path is None:
        pytest.skip(
            "BmiLisem.cpp not found (set LISEM_BMI_CPP_SRC, or run from a repo checkout) "
            "-- cannot check ALIASES against its source of truth"
        )
    cpp_aliases = _parse_cpp_kalias(cpp_path)
    assert cpp_aliases, f"parsed zero entries from kAlias in {cpp_path} -- parser or path is wrong"
    assert ALIASES == cpp_aliases, (
        f"ALIASES has drifted from kAlias in {cpp_path}:\n"
        f"  only in Python ALIASES: {sorted(set(ALIASES) - set(cpp_aliases))}\n"
        f"  only in C++ kAlias:     {sorted(set(cpp_aliases) - set(ALIASES))}\n"
        f"  differing targets:      {sorted(k for k in set(ALIASES) & set(cpp_aliases) if ALIASES[k] != cpp_aliases[k])}"
    )
