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

RUNFILE = os.environ.get("LISEM_TEST_RUNFILE", "")
needs_runfile = pytest.mark.skipif(
    not RUNFILE,
    reason="LISEM_TEST_RUNFILE not set; no input data available",
)

# Full alias table: legacy CSDMS name -> canonical ESoil name.
# Must stay in sync with kAlias in BmiLisem.cpp.
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
    "domain_soil_water_storage__volume":      "surface-water~storage_volume",
    "domain_runoff__volume":                  "surface-water~runoff_volume",
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
    """Erosion (kg/m2) scaling must work when called by the canonical name."""
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
        assert np.all(finite >= 0)
        assert m.get_var_units("soil_erosion~mass-per-area") == "kg m-2"
    finally:
        m.finalize()


@needs_runfile
def test_coupling_names_present():
    """Coupling-critical canonical names shared with AquaCrop are advertised."""
    m = _make_model()
    try:
        advertised = set(m.get_output_var_names()) | set(m.get_input_var_names())
        # layer-2/-3 are optional (depend on runfile layer count)
        required = {"soil_water_actual", "plant_cover~projective",
                    "soil_water_actual_layer-1"}
        for name in required:
            assert name in advertised, f"coupling name {name!r} not advertised"
    finally:
        m.finalize()
