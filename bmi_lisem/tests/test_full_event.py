"""
test_full_event.py — full event run and physical sanity check.

Skipped when no runfile is available (LISEM_RUNFILE env var or default path).
"""

import os
import pytest
import numpy as np

from bmi_lisem import BmiLisem

_DEFAULT_RUNFILE = os.environ.get(
    "LISEM_RUNFILE",
    "/home/jovyan/work/LISEM/inputfiles/VNIIMZ_20m/maps/probnik_20m.run",
)

_HAS_RUNFILE = os.path.isfile(_DEFAULT_RUNFILE)

skip_no_data = pytest.mark.skipif(
    not _HAS_RUNFILE,
    reason=f"LISEM runfile not found at {_DEFAULT_RUNFILE}; set LISEM_RUNFILE to enable",
)


@skip_no_data
def test_full_event_infiltration_nonzero():
    """
    After a complete event, soil_infiltration_amount (Fcum) must be non-zero
    in at least some cells (runfile must have infiltration enabled).
    """
    m = BmiLisem()
    m.initialize(_DEFAULT_RUNFILE)

    while m.get_current_time() < m.get_end_time() - 1e-9:
        m.update()

    n = m.get_grid_size(m.get_var_grid("soil_infiltration_amount"))
    fcum = np.empty(n, dtype=np.float64)
    m.get_value("soil_infiltration_amount", fcum)

    # At least one non-MV cell should have positive infiltration.
    valid = fcum[np.isfinite(fcum)]
    assert np.any(valid > 0.0), (
        "soil_infiltration_amount is zero everywhere after a full event — "
        "check that infiltration is enabled in the runfile."
    )

    m.finalize()


@skip_no_data
def test_time_advances_through_event():
    """Current time must equal end time after driving the loop to completion."""
    m = BmiLisem()
    m.initialize(_DEFAULT_RUNFILE)

    end = m.get_end_time()
    while m.get_current_time() < end - 1e-9:
        m.update()

    assert abs(m.get_current_time() - end) < 1.0, (
        f"Expected current_time ≈ end_time={end}, got {m.get_current_time()}"
    )

    m.finalize()
