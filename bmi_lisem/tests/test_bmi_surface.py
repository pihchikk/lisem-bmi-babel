"""
test_bmi_surface.py — metadata consistency and round-trip set/get tests.

All tests that touch the model runtime are skipped when no runfile is
available (LISEM_RUNFILE env var or default path).
"""

import os
import pytest
import numpy as np

from bmi_lisem import BmiLisem
from bmi_lisem.bmi_lisem import _INPUT_NAMES, _OUTPUT_NAMES, _UNITS

# ---------------------------------------------------------------------------
# Fixture: skip when no runfile
# ---------------------------------------------------------------------------
_DEFAULT_RUNFILE = os.environ.get(
    "LISEM_RUNFILE",
    "/home/jovyan/work/LISEM/inputfiles/VNIIMZ_20m/maps/probnik_20m.run",
)

_HAS_RUNFILE = os.path.isfile(_DEFAULT_RUNFILE)

skip_no_data = pytest.mark.skipif(
    not _HAS_RUNFILE,
    reason=f"LISEM runfile not found at {_DEFAULT_RUNFILE}; set LISEM_RUNFILE to enable",
)


@pytest.fixture(scope="module")
def initialized_model():
    m = BmiLisem()
    m.initialize(_DEFAULT_RUNFILE)
    yield m
    m.finalize()


# ---------------------------------------------------------------------------
# Static (no model) tests
# ---------------------------------------------------------------------------

def test_units_table_complete():
    """Every public variable has a units entry."""
    all_names = set(_INPUT_NAMES) | set(_OUTPUT_NAMES)
    missing = all_names - set(_UNITS)
    assert missing == set(), f"No units defined for: {missing}"


# ---------------------------------------------------------------------------
# Runtime metadata tests
# ---------------------------------------------------------------------------

@skip_no_data
def test_var_metadata_consistency(initialized_model):
    """For every variable: nbytes == grid_size * itemsize."""
    m = initialized_model
    all_names = set(m.get_input_var_names()) | set(m.get_output_var_names())
    for name in all_names:
        grid = m.get_var_grid(name)
        size = m.get_grid_size(grid)
        itemsize = m.get_var_itemsize(name)
        nbytes = m.get_var_nbytes(name)
        assert nbytes == size * itemsize, (
            f"{name}: nbytes={nbytes} != grid_size={size} * itemsize={itemsize}"
        )


@skip_no_data
def test_var_units_match_table(initialized_model):
    """get_var_units returns exactly the value from the canonical units table."""
    m = initialized_model
    all_names = set(m.get_input_var_names()) | set(m.get_output_var_names())
    for name in all_names:
        assert m.get_var_units(name) == _UNITS[name], (
            f"{name}: get_var_units='{m.get_var_units(name)}' != table='{_UNITS[name]}'"
        )


@skip_no_data
def test_roundtrip_set_get_inputs(initialized_model):
    """set_value → get_value round-trip for each input variable."""
    m = initialized_model
    for name in m.get_input_var_names():
        n = m.get_grid_size(m.get_var_grid(name))
        orig = np.empty(n, dtype=np.float64)
        m.get_value(name, orig)

        fill = np.full(n, 0.25, dtype=np.float64)
        m.set_value(name, fill)

        readback = np.empty(n, dtype=np.float64)
        m.get_value(name, readback)

        assert np.allclose(readback, 0.25), (
            f"{name}: set 0.25 but got back {readback[:5]}..."
        )

        # Restore original
        m.set_value(name, orig)


@skip_no_data
def test_get_value_at_indices(initialized_model):
    """get_value_at_indices returns same values as full get_value at those indices."""
    m = initialized_model
    name = "water_depth~surface"
    n = m.get_grid_size(m.get_var_grid(name))
    full = np.empty(n, dtype=np.float64)
    m.get_value(name, full)

    inds = np.array([0, 1, n // 2, n - 1], dtype=np.int32)
    dest = np.empty(len(inds), dtype=np.float64)
    m.get_value_at_indices(name, dest, inds)

    np.testing.assert_array_equal(dest, full[inds])


@skip_no_data
def test_get_value_ptr_raises(initialized_model):
    """get_value_ptr must raise NotImplementedError."""
    with pytest.raises(NotImplementedError):
        initialized_model.get_value_ptr("water_depth~surface")


@skip_no_data
def test_grid_face_edges_raises(initialized_model):
    """get_grid_face_edges must raise NotImplementedError."""
    with pytest.raises(NotImplementedError):
        initialized_model.get_grid_face_edges(0, np.empty(0))
