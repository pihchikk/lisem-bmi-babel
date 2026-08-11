"""Shared helper to locate a runfile for the data-dependent tests.

Resolution order:
  1. ``LISEM_TEST_RUNFILE`` environment variable (absolute path), if set.
  2. The bundled tiny synthetic catchment ``tests/data/tiny/tiny.run``, whose
     ``.map`` inputs are committed (no pcraster needed).
  3. Otherwise return "" so tests skip.

Path rewriting
--------------
OpenLISEM runfiles carry *absolute* directory paths (``Map Directory``,
``Rainfall Directory``, ``Result Directory``) -- the format has no notion of
"relative to this runfile". The committed ``tiny*.run`` files therefore hold
whatever absolute paths existed on the machine that generated them, which are
meaningless anywhere else.

That is not hypothetical: committing the ``.map`` binaries made the sentinel
below exist in CI for the first time, so CI stopped skipping these tests and
started running them against paths like
``/home/claude/lisem-work/...`` that exist on exactly one machine. Every
data-dependent test failed with ``Filename not found for map ldd.map``.

So a bundled tiny runfile is never handed to the model as-is: its three
directory keys are rewritten to wherever this checkout actually lives, and the
corrected copy is written to a temp file. Same idea as
``bmi_lisem.scenarios``' ``{MAP_DIR}``/``{RESULT_DIR}`` templating for the
VNIIMZ scenario, applied to the fixtures that predate it.

A runfile supplied via ``LISEM_TEST_RUNFILE`` from *outside* the bundled tiny
directory is passed through untouched -- that is a user's own dataset and its
paths are their business.
"""

import os
import tempfile
from pathlib import Path

_HERE = Path(__file__).resolve().parent
_TINY_DIR = _HERE / "data" / "tiny"
_TINY_RUN = _TINY_DIR / "tiny.run"
# A representative committed map; its presence signals a usable input set.
_TINY_SENTINEL = _TINY_DIR / "ldd.map"

# Runfile keys holding a directory that must point at this checkout.
_MAP_DIR_KEYS = ("Map Directory", "Rainfall Directory")
_RESULT_DIR_KEY = "Result Directory"


def _is_bundled_fixture(run_path: Path) -> bool:
    """True if this runfile sits next to the committed tiny ``.map`` inputs.

    Deliberately a property of the runfile's own directory rather than a
    comparison against ``_TINY_DIR``: ``scripts/run_local_tests.sh`` runs the
    suite from a *copy* of ``tests/`` outside the repo, so the same fixture is
    reachable under two different absolute paths and a direct comparison would
    silently miss one of them.
    """
    return run_path.exists() and (run_path.parent / _TINY_SENTINEL.name).exists()


def _materialise(run_path: Path) -> str:
    """Rewrite a bundled tiny runfile's directory keys to where it really is.

    Map and rainfall inputs live next to the runfile, so its own parent is the
    correct directory regardless of which copy of the tree is being used.
    Returns the path of a corrected temp copy; the committed file is never
    modified.
    """
    fixture_dir = run_path.parent
    result_dir = fixture_dir / (run_path.stem + "_out")
    result_dir.mkdir(parents=True, exist_ok=True)

    lines = []
    for line in run_path.read_text(encoding="utf-8", errors="replace").splitlines():
        key, sep, _ = line.partition("=")
        if sep and key.strip() in _MAP_DIR_KEYS:
            line = f"{key}={fixture_dir}"
        elif sep and key.strip() == _RESULT_DIR_KEY:
            line = f"{key}={result_dir}"
        lines.append(line)

    fd, corrected = tempfile.mkstemp(prefix=f"{run_path.stem}_", suffix=".run")
    with os.fdopen(fd, "w", encoding="utf-8") as handle:
        handle.write("\n".join(lines) + "\n")
    return corrected


def resolve_runfile() -> str:
    env = os.environ.get("LISEM_TEST_RUNFILE", "")
    if env:
        env_path = Path(env).resolve()
        # A bundled tiny fixture needs the same rewriting whether it was
        # auto-detected or named explicitly; a user's own dataset elsewhere is
        # passed through untouched.
        if _is_bundled_fixture(env_path):
            return _materialise(env_path)
        return env
    if _TINY_RUN.exists() and _TINY_SENTINEL.exists():
        return _materialise(_TINY_RUN)
    return ""
