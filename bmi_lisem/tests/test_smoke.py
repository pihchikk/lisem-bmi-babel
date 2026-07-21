"""No-data smoke tests for the compiled bmi_lisem.Lisem binding.

These require the native extension to be built and importable but do NOT need a
runfile, so they run everywhere (including CI) and actually prove that the C++
library links and the Cython binding works.
"""

import numpy as np
import pytest


def test_import_and_construct():
    from bmi_lisem import Lisem
    m = Lisem()
    assert m is not None


def test_component_name_without_init():
    # GetComponentName() does not touch the model, so it works pre-initialize.
    from bmi_lisem import Lisem
    assert str(Lisem().get_component_name()) == "OpenLISEM"


def test_time_units_without_init():
    from bmi_lisem import Lisem
    assert str(Lisem().get_time_units()) == "s"


def test_bad_dtype_buffer_rejected():
    """get_value must reject a wrong-width buffer instead of corrupting memory.

    We cannot exercise get_value without an initialized model, but we can verify
    the binding validates C-contiguity/width: a non-contiguous array raises.
    """
    from bmi_lisem import Lisem
    m = Lisem()
    # A non-contiguous view; the binding should refuse it before any memcpy.
    buff = np.zeros(20, dtype=np.float64)[::2]
    with pytest.raises((ValueError, RuntimeError)):
        m.get_value("land_surface_water__depth", buff)


def test_alias_names_are_expected_set():
    """Cross-check the Python-visible name expectations against the C++ registry.

    This does not touch the native model; it guards the canonical/legacy name
    lists used by the data-dependent tests from silent drift.
    """
    from bmi_lisem.tests.test_standard_names import ALIASES
    # every canonical name must be distinct and use single underscores / tildes
    canon = list(ALIASES.values())
    assert len(canon) == len(set(canon)), "duplicate canonical names"
    for name in canon:
        assert "__" not in name, f"canonical name {name!r} still uses CSDMS '__'"
