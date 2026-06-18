"""
test_standard_names.py — verify that BmiLisem exposes ONLY canonical project
standard names (no CSDMS double-underscore names in the public surface).

These tests do NOT require a runfile and do NOT call initialize(); they test
the name tables and class structure.
"""

import pytest

from bmi_lisem import BmiLisem
from bmi_lisem.bmi_lisem import _INPUT_NAMES, _OUTPUT_NAMES


def test_input_var_names_exact():
    """Input names must be exactly the two canonical standard names, in order."""
    m = BmiLisem()
    assert m.get_input_var_names() == ("soil_water_actual", "plant_cover~projective")


def test_output_var_names_exact():
    """Output names must be the four canonical standard names (any order OK, all present)."""
    m = BmiLisem()
    out = set(m.get_output_var_names())
    assert out == {
        "soil_water_actual",
        "soil_infiltration_amount",
        "water_depth~surface",
        "water~channel_discharge",
    }


def test_item_counts_match_name_lists():
    m = BmiLisem()
    assert m.get_input_item_count() == len(m.get_input_var_names())
    assert m.get_output_item_count() == len(m.get_output_var_names())


def test_no_double_underscore_in_public_names():
    """No public variable name may contain '__' (CSDMS convention leak guard)."""
    m = BmiLisem()
    all_public = list(m.get_input_var_names()) + list(m.get_output_var_names())
    leaks = [n for n in all_public if "__" in n]
    assert leaks == [], f"CSDMS names leaked into public surface: {leaks}"


def test_reset_event_not_in_var_lists():
    """model__reset_event must not appear in any public variable list."""
    m = BmiLisem()
    all_public = set(m.get_input_var_names()) | set(m.get_output_var_names())
    assert "model__reset_event" not in all_public


def test_reset_event_method_exists_and_callable():
    """reset_event() must exist as a method (can be called without initialize)."""
    m = BmiLisem()
    assert callable(getattr(m, "reset_event", None))
    # Calling without initialize raises — but AttributeError / not-callable is the
    # failure mode we guard against here.  A RuntimeError from the C++ layer is fine.
    try:
        m.reset_event()
    except Exception as exc:
        # Any exception except AttributeError is acceptable
        assert not isinstance(exc, AttributeError), (
            "reset_event() raised AttributeError — method missing"
        )
