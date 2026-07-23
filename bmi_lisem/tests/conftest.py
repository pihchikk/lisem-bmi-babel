"""Ensure tests import the INSTALLED bmi_lisem (with the compiled extension),
never the in-repo source package that would shadow it.

When pytest is invoked with the repo on its rootdir, the repo root can land on
sys.path; then ``import bmi_lisem`` resolves to ``<repo>/bmi_lisem`` — the pure
source tree, which lacks the compiled ``lib/lisem`` extension — and every test
that constructs ``Lisem`` fails at import with ModuleNotFoundError.

This conftest removes the repo root (the directory that contains the source
``bmi_lisem`` package) from sys.path before any test module imports the package,
so resolution falls through to site-packages (the installed wheel). Run the
suite from a non-repo working directory as well for belt-and-braces.
"""

import sys
from pathlib import Path

# .../bmi_lisem/tests/conftest.py -> parents[2] is the repo root that holds the
# source `bmi_lisem` package directory.
_REPO_ROOT = Path(__file__).resolve().parents[2]


def _same(path_entry: str, target: Path) -> bool:
    try:
        return Path(path_entry or ".").resolve() == target
    except (OSError, ValueError):
        return False


# Drop the repo root so the source package cannot shadow the installed wheel.
sys.path[:] = [p for p in sys.path if not _same(p, _REPO_ROOT)]
