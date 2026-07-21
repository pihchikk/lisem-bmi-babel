"""Shared helper to locate a runfile for the data-dependent tests.

Resolution order:
  1. ``LISEM_TEST_RUNFILE`` environment variable (absolute path), if set.
  2. The bundled tiny synthetic catchment ``tests/data/tiny/tiny.run`` — but
     ONLY if its input maps have actually been generated (see
     ``tests/data/tiny/make_tiny.py``); the map binaries are not committed.
  3. Otherwise return "" so tests skip.
"""

import os
from pathlib import Path

_HERE = Path(__file__).resolve().parent
_TINY_RUN = _HERE / "data" / "tiny" / "tiny.run"
# A representative map the generator produces; its presence signals a usable set.
_TINY_SENTINEL = _HERE / "data" / "tiny" / "ldd.map"


def resolve_runfile() -> str:
    env = os.environ.get("LISEM_TEST_RUNFILE", "")
    if env:
        return env
    if _TINY_RUN.exists() and _TINY_SENTINEL.exists():
        return str(_TINY_RUN)
    return ""
