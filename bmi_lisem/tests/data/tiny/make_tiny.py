#!/usr/bin/env python3
"""Generate a tiny 10x10 synthetic OpenLISEM catchment for CI tests.

Writes PCRaster ``.map`` inputs next to this file using ``pcraster.numpy2pcr``.
Run where ``pcraster`` is importable (e.g. the CI ``test.yml`` job installs it):

    python bmi_lisem/tests/data/tiny/make_tiny.py

IMPORTANT / HONEST CAVEAT
-------------------------
The exact set of mandatory maps and the runfile keys are specific to this
vendored OpenLISEM build. The list below covers the common core (LDD, DEM,
Ksat, porosity, initial moisture, soil depth, cohesion, roughness, land use,
outlet). If ``initialize()`` still reports a missing map for your build, add it
here with a sensible uniform value — do NOT guess physics, copy the value range
from a known-good runfile. Until this is reconciled against the engine, the
data-dependent tests will skip rather than assert on an incomplete dataset.
"""

import sys
from pathlib import Path

import numpy as np

HERE = Path(__file__).resolve().parent
N = 10          # rows == cols
CELL = 10.0     # m

# Imported lazily inside main() so this module is import-safe (pytest collection
# under --doctest-modules must not fail or exit when pcraster is absent).
pcr = None


def _clone():
    # A raster clone defines geometry for all subsequent maps.
    # cols, rows, cellsize, west, north
    pcr.setclone(N, N, CELL, 0.0, N * CELL)


def _write(name, array, value_scale):
    """array: float ndarray (N,N); value_scale: pcr.Scalar/Nominal/Ldd."""
    m = pcr.numpy2pcr(value_scale, np.asarray(array, dtype=np.float32), -9999.0)
    pcr.report(m, str(HERE / name))
    print("wrote", name)


def main():
    global pcr
    try:
        import pcraster as pcr  # noqa: F401
    except Exception as exc:
        print(f"pcraster not available ({exc}); cannot generate tiny dataset",
              file=sys.stderr)
        return 0

    _clone()
    ones = np.ones((N, N), dtype=np.float32)

    # LDD draining to the SE corner (value 2 = south in PCRaster ldd codes;
    # a real catchment should use lddcreate on a DEM — this is a placeholder).
    ldd = np.full((N, N), 2.0, dtype=np.float32)
    ldd[-1, :] = 6.0  # last row drains east toward the outlet
    ldd[-1, -1] = 5.0  # pit / outlet
    _write("ldd.map", ldd, pcr.Ldd)

    # DEM: gentle planar slope so water moves.
    dem = np.fromfunction(lambda r, c: 100.0 - 0.1 * r - 0.05 * c, (N, N))
    _write("dem.map", dem, pcr.Scalar)

    _write("outlet.map", (np.arange(N * N).reshape(N, N) == (N * N - 1)).astype(np.float32), pcr.Nominal)
    _write("landunit.map", ones, pcr.Nominal)

    # Hydraulics (uniform, physically plausible).
    _write("ksat1.map", 20.0 * ones, pcr.Scalar)     # mm/h
    _write("thetas1.map", 0.45 * ones, pcr.Scalar)   # m3/m3 (porosity)
    _write("thetai1.map", 0.20 * ones, pcr.Scalar)   # m3/m3 (initial)
    _write("psi1.map", 10.0 * ones, pcr.Scalar)      # cm
    _write("soildepth1.map", 0.5 * ones, pcr.Scalar) # m

    # Surface / erosion.
    _write("coh.map", 5.0 * ones, pcr.Scalar)        # kPa
    _write("cohadd.map", 1.0 * ones, pcr.Scalar)
    _write("aggrstab.map", 2.0 * ones, pcr.Scalar)
    _write("d50.map", 50.0 * ones, pcr.Scalar)       # micron
    _write("n.map", 0.05 * ones, pcr.Scalar)         # manning
    _write("rr.map", 1.0 * ones, pcr.Scalar)         # random roughness (cm)
    _write("per.map", 0.05 * ones, pcr.Scalar)       # plant cover fraction
    _write("lai.map", 1.0 * ones, pcr.Scalar)
    _write("ch.map", 1.0 * ones, pcr.Scalar)         # plant height (m)
    _write("grad.map", 0.02 * ones, pcr.Scalar)      # slope (sine)

    print("tiny dataset generated in", HERE)


if __name__ == "__main__":
    main()
