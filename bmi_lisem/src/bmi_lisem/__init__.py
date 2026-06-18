"""
bmi_lisem — standalone BMI for OpenLISEM with canonical project standard names.

Public surface:
    BmiLisem   — bmipy 2.0 wrapper with standard project names (no CSDMS __ names)

Usage::

    from bmi_lisem import BmiLisem
    m = BmiLisem()
    m.initialize("path/to/runfile.run")
    while m.get_current_time() < m.get_end_time():
        m.update()
    m.finalize()
"""

from .bmi_lisem import BmiLisem

__version__ = "0.1.0"
__all__ = ["BmiLisem"]
