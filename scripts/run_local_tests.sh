#!/usr/bin/env bash
# Standard local test invocation for bmi_lisem.
#
# Wires the three things needed to get real signal instead of 13 silent
# skips, so they don't stay tribal knowledge:
#   1. LD_LIBRARY_PATH -> the built libbmilisem.so (openlisem_bmi/build).
#   2. LISEM_TEST_RUNFILE -> a real runfile. Defaults to VNIIMZ_20m's
#      already-corrected local runfile (see README.rst's "Input data"
#      section for why: the dataset's other .run files carry absolute paths
#      from other environments -- WSL, a Jupyter container -- and won't
#      resolve on this host). Override by exporting LISEM_TEST_RUNFILE
#      yourself before calling this script.
#   3. Running from a copy of tests/ outside the repo, so `import bmi_lisem`
#      resolves to the installed wheel (with the compiled extension) instead
#      of being shadowed by the source tree -- see docs/BUILDING.md's
#      "Editable installs and shadowing" section.
#
# None of this requires pcraster. See README.rst's "Input data" section:
# none of the 13 data-dependent tests import it, and the two that verify
# against LISEM's own .map output already do so via osgeo.gdal.
#
# A full run against VNIIMZ_20m takes ~4 minutes per event; 7 of the 13
# tests each run one, so expect ~25-30 minutes end to end.

set -euo pipefail

REPO_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"

export LD_LIBRARY_PATH="${REPO_ROOT}/openlisem_bmi/build:${LD_LIBRARY_PATH:-}"
export LISEM_TEST_RUNFILE="${LISEM_TEST_RUNFILE:-/home/claude/lisem-work/VNIIMZ_20m/res_test/run_test.run}"

WORKDIR="$(mktemp -d)"
trap 'rm -rf "$WORKDIR"' EXIT
cp -r "${REPO_ROOT}/bmi_lisem/tests" "$WORKDIR/tests"

echo "LISEM_TEST_RUNFILE=${LISEM_TEST_RUNFILE}"
cd "$WORKDIR/tests"
exec python3 -m pytest -q --no-header -rs -o addopts="" "$@" .
