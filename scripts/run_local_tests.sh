#!/usr/bin/env bash
# Standard local test invocation for bmi_lisem.
#
# Wires the things needed to get real signal instead of silent skips, so they
# don't stay tribal knowledge:
#   1. LD_LIBRARY_PATH -> the built libbmilisem.so (openlisem_bmi/build).
#   2. LISEM_TEST_RUNFILE -> a real runfile. Defaults to the bundled
#      VNIIMZ_20m scenario (bmi_lisem.scenarios.default_scenario_runfile(),
#      see meta/Lisem/vniimz_20m/README.md and README.rst's "Input data"
#      section) -- portable, ships in the repo/wheel, no external dataset or
#      per-machine path correction needed. Override by exporting
#      LISEM_TEST_RUNFILE yourself before calling this script (e.g. to point
#      at a larger real dataset).
#   3. Running from a copy of tests/ outside the repo, so `import bmi_lisem`
#      resolves to the installed wheel (with the compiled extension) instead
#      of being shadowed by the source tree -- see docs/BUILDING.md's
#      "Editable installs and shadowing" section.
#
# None of this requires pcraster. See README.rst's "Input data" section:
# none of the data-dependent tests import it, and the two that verify against
# LISEM's own .map output already do so via osgeo.gdal.
#
#   4. LISEM_BMI_CPP_SRC -> BmiLisem.cpp, so
#      test_standard_names.py::test_alias_table_matches_cpp_source can check the
#      Python ALIASES dict against kAlias (its actual source of truth) even
#      though tests/ runs from a copy outside the repo. Without this it's set
#      relative to the test file, which only resolves for ad hoc in-repo runs.
#   5. PYTHON -> the interpreter with pytest AND the installed bmi_lisem wheel
#      (the compiled extension, not the source tree -- see point 3 above).
#      System python3 has neither on this host; defaults to the dev venv used
#      throughout this project. Override by exporting PYTHON yourself.

set -euo pipefail

REPO_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"

export LD_LIBRARY_PATH="${REPO_ROOT}/openlisem_bmi/build:${LD_LIBRARY_PATH:-}"
export LISEM_BMI_CPP_SRC="${REPO_ROOT}/openlisem_bmi/bmi_lisem/BmiLisem.cpp"
PYTHON="${PYTHON:-/home/claude/venvs/aquacrop-bmi-gate5/bin/python3}"

WORKDIR="$(mktemp -d)"
trap 'rm -rf "$WORKDIR"' EXIT
cp -r "${REPO_ROOT}/bmi_lisem/tests" "$WORKDIR/tests"
cd "$WORKDIR/tests"

if [[ -z "${LISEM_TEST_RUNFILE:-}" ]]; then
  export LISEM_TEST_RUNFILE="$("$PYTHON" -c \
    "from bmi_lisem.scenarios import default_scenario_runfile; print(default_scenario_runfile())")"
fi

echo "LISEM_TEST_RUNFILE=${LISEM_TEST_RUNFILE}"
echo "PYTHON=${PYTHON}"
exec "$PYTHON" -m pytest -q --no-header -rs -o addopts="" "$@" .
