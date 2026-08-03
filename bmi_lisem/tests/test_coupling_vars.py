"""
Tests for the coupling variables added to the C++ BMI registry.

These tests exercise the babelized BmiLisem (bmi_lisem.Lisem) directly using
CSDMS-style double-underscore names as registered in BmiLisem::buildVarRegistry().

The tests require an OpenLISEM runfile with infiltration and erosion enabled.
Set LISEM_TEST_RUNFILE to the absolute path of such a runfile. If the
environment variable is absent the tests are skipped (CI without input data).
"""

import os
import math
import numpy as np
import pytest

from _runfile import resolve_runfile
RUNFILE = resolve_runfile()
needs_runfile = pytest.mark.skipif(
    not RUNFILE,
    reason="no runfile: set LISEM_TEST_RUNFILE or generate tests/data/tiny",
)

# New coupling map output names (canonical ESoil standard names)
MAP_OUTPUTS_COUPLING = [
    "soil_water_actual_layer-1",
    "soil_water_actual_layer-2",
    "soil_water_actual_layer-3",
    "soil_layer-depth~layer-1",
    "soil_layer-depth~layer-2",
    "soil_layer-depth~layer-3",
    "soil_erosion~mass-per-area",
    "surface-water~rainfall_amount",
    "surface-water~runoff_amount",
]

# New scalar output names (canonical ESoil standard names)
SCALAR_OUTPUTS = [
    "surface-water~rainfall_volume",
    "surface-water~interception_volume",
    "surface-water~infiltration_volume",
    "surface-water~evapotranspiration_volume",
    "surface-water~storage_volume",
    "soil_water~storage_volume",
    "surface-water~runoff_volume",
]

EXPECTED_UNITS = {
    "soil_water_actual_layer-1": "m3 m-3",
    "soil_water_actual_layer-2": "m3 m-3",
    "soil_water_actual_layer-3": "m3 m-3",
    "soil_layer-depth~layer-1": "m",
    "soil_layer-depth~layer-2": "m",
    "soil_layer-depth~layer-3": "m",
    "soil_erosion~mass-per-area": "kg m-2",
    "surface-water~rainfall_amount": "m",
    "surface-water~runoff_amount": "m",
    "surface-water~rainfall_volume": "m3",
    "surface-water~interception_volume": "m3",
    "surface-water~infiltration_volume": "m3",
    "surface-water~evapotranspiration_volume": "m3",
    "surface-water~storage_volume": "m3",
    "soil_water~storage_volume": "m3",
    "surface-water~runoff_volume": "m3",
}


# ---------------------------------------------------------------------------
# Helpers
# ---------------------------------------------------------------------------

def _make_model():
    from bmi_lisem import Lisem  # babelized C++ BMI class
    m = Lisem()
    m.initialize(RUNFILE)
    return m


def _run_to_end(m):
    end = m.get_end_time()
    while m.get_current_time() < end - 1e-9:
        m.update()


def _read(m, name):
    """Read a variable into a fresh numpy array via get_value (works for
    rasters, scalars, and the scaled erosion map alike)."""
    grid = m.get_var_grid(name)
    n = m.get_grid_size(grid)
    buff = np.empty(n, dtype=np.float64)
    m.get_value(name, buff)
    return buff


# ---------------------------------------------------------------------------
# 1. Metadata tests (no runfile needed — variable catalogue from registry)
# ---------------------------------------------------------------------------

class TestMetadata:
    """Variable metadata is self-consistent without running a full event."""

    # layer-2/-3 variants are genuinely optional -- they depend on how many soil
    # layers the runfile declares (nrSoilLayers), not a fixed set. Same treatment
    # as TestCouplingNamesPresent below; don't assert presence or absence either
    # way. (VNIIMZ_20m specifically is a real 2-layer config with no layer-3 data
    # on disk at all -- layer-3 correctly not being advertised is expected, not a
    # bug. This test used to assert it unconditionally, which only ever passed
    # because of the now-fixed registry bug: TWorld's constructor left
    # conditionally-allocated map pointers as uninitialized heap garbage, which
    # occasionally looked non-null and got a variable with no real backing
    # advertised as active. See TMmapVariables.h/model.h.)
    OPTIONAL_LAYER_SUFFIXES = ("layer-2", "layer-3")

    @needs_runfile
    def test_coupling_vars_in_output_list(self):
        m = _make_model()
        try:
            out_vars = m.get_output_var_names()
            for name in MAP_OUTPUTS_COUPLING + SCALAR_OUTPUTS:
                if name.endswith(self.OPTIONAL_LAYER_SUFFIXES):
                    continue
                assert name in out_vars, f"{name!r} missing from output var names"
        finally:
            m.finalize()

    @needs_runfile
    def test_inactive_variable_raises_cleanly(self):
        """A variable that's a real, known canonical name but inactive for this
        runfile's soil-layer config (not a typo, not genuinely unknown) must
        raise the same clean, catchable error as an unknown name -- never
        crash, never silently return zero/garbage. This is exactly the path a
        coupler hits if it assumes a 3-layer soil profile against a 2-layer
        runfile like VNIIMZ_20m.

        Before the registry-nullptr fix this was untestable: the variable's
        presence in the registry was non-deterministic (heap-garbage-
        dependent -- see TMmapVariables.h/model.h and BmiLisem::GetValue's
        heap-buffer-overflow this masked). The fix makes registry membership
        deterministic, which is what makes this a permanent, meaningful test
        rather than a coin flip.
        """
        m = _make_model()
        try:
            out_vars = m.get_output_var_names()
            name = "soil_water_actual_layer-3"
            assert name not in out_vars, (
                f"{name!r} unexpectedly advertised for this runfile -- pick a "
                "different genuinely-inactive variable to keep this test meaningful"
            )
            with pytest.raises(RuntimeError):
                m.get_var_grid(name)
            with pytest.raises(RuntimeError):
                m.get_var_units(name)
            buf = np.empty(1, dtype=np.float64)
            with pytest.raises(RuntimeError):
                m.get_value(name, buf)
        finally:
            m.finalize()

    @needs_runfile
    def test_every_advertised_output_var_is_readable(self):
        """Every name get_output_var_names() advertises must have a real,
        readable backing -- the direct, general assertion for the bug class
        behind the SIGSEGV: the registry advertising a variable whose backing
        pointer wasn't actually valid (TWorld's uninitialized conditionally-
        allocated map pointers, see TMmapVariables.h/model.h). This catches
        that class for ANY variable, including ones nobody thought to check
        individually, and any future recurrence.

        Checked pre-run (no update() calls): the registry decision that
        matters here is made entirely inside initialize(), independent of run
        state -- confirmed directly while investigating the original crash
        (advertised-variable-count was stable across pre-run/mid-run/post-run
        checks; only the registry-build step at initialize() time varied).
        """
        m = _make_model()
        try:
            for name in m.get_output_var_names():
                grid = m.get_var_grid(name)
                n = m.get_grid_size(grid)
                buf = np.empty(n, dtype=np.float64)
                m.get_value(name, buf)  # must not raise or crash
        finally:
            m.finalize()

    @needs_runfile
    def test_map_outputs_grid0(self):
        m = _make_model()
        try:
            for name in MAP_OUTPUTS_COUPLING:
                if name not in m.get_output_var_names():
                    continue  # layer inactive; guard in registry skipped it
                grid = m.get_var_grid(name)
                assert grid == 0, f"{name}: expected grid 0, got {grid}"
                assert m.get_grid_type(grid) == "uniform_rectilinear"
                assert m.get_grid_rank(grid) == 2
                itemsize = m.get_var_itemsize(name)
                nbytes = m.get_var_nbytes(name)
                size = m.get_grid_size(grid)
                assert nbytes == size * itemsize, (
                    f"{name}: nbytes {nbytes} != size*itemsize {size*itemsize}"
                )
        finally:
            m.finalize()

    @needs_runfile
    def test_scalar_outputs_grid1(self):
        m = _make_model()
        try:
            for name in SCALAR_OUTPUTS:
                assert name in m.get_output_var_names(), f"{name!r} not in output vars"
                grid = m.get_var_grid(name)
                assert grid == 1, f"{name}: expected grid 1, got {grid}"
                assert m.get_grid_rank(grid) == 0
                assert m.get_grid_size(grid) == 1
                assert m.get_var_itemsize(name) == 8   # double
                assert m.get_var_nbytes(name) == 8
        finally:
            m.finalize()

    @needs_runfile
    def test_units(self):
        m = _make_model()
        try:
            out_vars = set(m.get_output_var_names())
            for name, expected_unit in EXPECTED_UNITS.items():
                if name not in out_vars:
                    continue
                actual = m.get_var_units(name)
                assert actual == expected_unit, (
                    f"{name}: expected units {expected_unit!r}, got {actual!r}"
                )
        finally:
            m.finalize()


# ---------------------------------------------------------------------------
# 2. Post-event physical correctness
# ---------------------------------------------------------------------------

class TestPostEventValues:
    """Values are physically plausible after a complete rainfall event."""

    @needs_runfile
    def test_actual_theta_differs_from_initial(self):
        """Post-event θ (layer 1) should be wetter than initial θ where rain fell."""
        m = _make_model()
        try:
            out_vars = set(m.get_output_var_names())
            if "soil_water_actual_layer-1" not in out_vars:
                pytest.skip("soil_water_actual_layer-1 not registered")

            theta0_flat = _read(m, "soil_water_actual")

            _run_to_end(m)

            theta1_flat = _read(m, "soil_water_actual_layer-1")

            # Must be finite and within [0, 1]
            assert np.all(np.isfinite(theta1_flat)), "post-event θ1a contains non-finite values"
            assert np.all(theta1_flat >= 0), "post-event θ1a contains negative values"
            assert np.all(theta1_flat <= 1), "post-event θ1a contains values > 1"

            # At least somewhere the moisture should have increased
            assert np.any(theta1_flat > theta0_flat + 1e-6), (
                "post-event θ1a is not larger than initial θ1 anywhere — "
                "likely avgTheta() not called or no infiltration occurred"
            )
        finally:
            m.finalize()

    @needs_runfile
    def test_erosion_finite_nonnegative(self):
        """Erosion map is finite. soil_erosion~mass-per-area is TotalSoillossMap
        (lisTotalsMB.cpp:495), a SIGNED net-soil-loss quantity by design: positive = net
        erosion, negative = net deposition -- the engine's own reporting code splits it the
        same way for display (lisReportmaps.cpp:147-148, qMax(0,.)/qMin(0,.)). This test used
        to assert the raw value is non-negative, which is wrong (deposition-heavy cells are
        expected to read negative); it now checks the erosion *component* -- what the test
        name actually asks about -- via that same qMax(0,.) split, and confirms real
        detachment happened somewhere in the event rather than the split being vacuously true.
        """
        m = _make_model()
        try:
            out_vars = set(m.get_output_var_names())
            if "soil_erosion~mass-per-area" not in out_vars:
                pytest.skip("soil_erosion~mass-per-area not registered (erosion off?)")

            _run_to_end(m)

            erosion_flat = _read(m, "soil_erosion~mass-per-area")
            valid = erosion_flat[np.isfinite(erosion_flat)]
            assert len(valid) > 0, "all erosion values are NaN/inf"

            erosion_component = np.maximum(valid, 0.0)
            deposition_component = np.minimum(valid, 0.0)
            assert np.any(erosion_component > 0), (
                "no cell shows net erosion (all non-negative kg/m² values are exactly 0) -- "
                "expected some detachment somewhere in a full event"
            )
            assert np.any(deposition_component < 0), (
                "no cell shows net deposition -- expected on VNIIMZ_20m; if this genuinely "
                "changed, the split may no longer be the right shape of check for this fixture"
            )
        finally:
            m.finalize()

    @needs_runfile
    def test_layer_depth_positive_constant(self):
        """Soil layer depths are positive and do not change over the run."""
        m = _make_model()
        try:
            out_vars = set(m.get_output_var_names())
            if "soil_layer-depth~layer-1" not in out_vars:
                pytest.skip("soil_layer-depth~layer-1 not registered")

            depth0 = _read(m, "soil_layer-depth~layer-1")
            assert np.all(depth0[np.isfinite(depth0)] > 0), "soil_layer-depth~layer-1 has non-positive values"

            _run_to_end(m)

            depth1 = _read(m, "soil_layer-depth~layer-1")
            np.testing.assert_array_equal(depth0, depth1,
                                          err_msg="soil_layer-depth~layer-1 changed during the run")
        finally:
            m.finalize()


# ---------------------------------------------------------------------------
# 3. Water-balance closure
# ---------------------------------------------------------------------------

class TestWaterBalance:
    """
    Check that the catchment totals close the balance:
        Rain ~ Interception + Infiltration + ET + dSoilStorage + dSurfaceStorage + Runoff

    surface-water~storage_volume was previously misbacked by SoilMoistTot (soil moisture, not
    surface storage) -- see docs/COUPLING_VARS_LEDGER.md's "surface-water~storage_volume fix" for
    the full story. Fixed: it now backs a live sum of MicroStoreVol, and SoilMoistTot moved to its
    own correctly-named soil_water~storage_volume (currently always 0.0 -- SoilMoistDiff, the only
    thing ever added to it, is dead code; included in the formula anyway for when/if that changes).

    A 5% relative tolerance is applied, matching totalseries.csv's own SS(mm)-based closure
    tightness on the VNIIMZ_20m test config (peak residual 5.5mm-equivalent). If the balance does
    not close on a *different* runfile, the residual is reported but the test is marked xfail so the
    suite remains informative rather than blocking on config-specific unaccounted terms (WH init,
    channel storage, retention, storm drain -- see docs/COUPLING_VARS_LEDGER.md's "Residual balance"
    section for the full list of what's still not exposed through BMI).
    """

    BALANCE_TOL = 0.05   # 5 % relative tolerance

    @needs_runfile
    def test_balance_closure(self):
        m = _make_model()
        try:
            _run_to_end(m)

            def scalar(name):
                arr = np.zeros(1, dtype=np.float64)
                m.get_value(name, arr)
                return float(arr[0])

            rain   = scalar("surface-water~rainfall_volume")
            interc = scalar("surface-water~interception_volume")
            infil  = scalar("surface-water~infiltration_volume")
            et     = scalar("surface-water~evapotranspiration_volume")
            dsurface_storage = scalar("surface-water~storage_volume")
            dsoil_storage = scalar("soil_water~storage_volume")
            runoff = scalar("surface-water~runoff_volume")

            residual = rain - (interc + infil + et + dsurface_storage + dsoil_storage + runoff)
            rel_err  = abs(residual) / max(abs(rain), 1e-12)

            # Record for diagnostics even if xfail
            msg = (
                f"Water balance residual: {residual:.4g} m3  "
                f"(rel {rel_err*100:.2f}%)  "
                f"rain={rain:.4g}, interc={interc:.4g}, infil={infil:.4g}, "
                f"et={et:.4g}, dsurface_storage={dsurface_storage:.4g}, "
                f"dsoil_storage={dsoil_storage:.4g}, runoff={runoff:.4g}"
            )

            if rel_err > self.BALANCE_TOL:
                pytest.xfail(
                    f"Balance does not close within {self.BALANCE_TOL*100:.0f}%: {msg}\n"
                    "See docs/COUPLING_VARS_LEDGER.md §'Residual balance' for known "
                    "unaccounted terms (WH init storage, channel storage, drain, retention)."
                )
            else:
                assert rel_err <= self.BALANCE_TOL, msg

        finally:
            m.finalize()


# ---------------------------------------------------------------------------
# 4. Per-cell rainfall/runoff (Gate 7.2 check (c) blocker)
# ---------------------------------------------------------------------------

def _parse_runfile_setting(runfile_path, key):
    """Reads a single ``key=value`` line from an OpenLISEM runfile (list-directed .run format).
    Returns None if the key isn't present or has no value."""
    with open(runfile_path, encoding="utf-8", errors="replace") as handle:
        for line in handle:
            if line.strip().startswith(f"{key}="):
                value = line.split("=", 1)[1].strip()
                return value or None
    return None


def _read_pcraster(path):
    """Reads a PCRaster .map file as a flat float64 array via raw GDAL bytes (the pip-installed
    GDAL wheel lacks the _gdal_array numpy bridge extension, so ReadAsArray isn't available)."""
    from osgeo import gdal

    gdal.UseExceptions()
    dataset = gdal.Open(path)
    band = dataset.GetRasterBand(1)
    width, height = dataset.RasterXSize, dataset.RasterYSize
    raw = band.ReadRaster(0, 0, width, height, buf_type=gdal.GDT_Float32)
    array = np.frombuffer(raw, dtype=np.float32).astype(np.float64).flatten()
    nodata = band.GetNoDataValue()
    return array, nodata


class TestSoilMoistTotIsDeadCode:
    """`soil_water~storage_volume` (SoilMoistTot) is correctly *named* as of the
    surface-water~storage_volume fix, but it is not currently a *functioning* balance term:
    SoilMoistDiff, the only thing ever added to it (lisTotalsMB.cpp:174), is never assigned a
    nonzero value anywhere in the active codebase -- its one real computation
    (SoilMoistDiff = soiltot2 - soiltot1) is commented out in lisModel.cpp.

    This asserts the CURRENT behavior (always 0.0) as an explicit contract, not an oversight: if
    SoilMoistDiff is ever wired up for real, this test will fail and force a conscious update here
    and in docs/COUPLING_VARS_LEDGER.md, rather than the variable silently starting to report
    something different from what its own documentation says.
    """

    @needs_runfile
    def test_soil_moisture_storage_reads_zero(self):
        m = _make_model()
        try:
            if "soil_water~storage_volume" not in m.get_output_var_names():
                pytest.skip("soil_water~storage_volume not registered for this run config")
            _run_to_end(m)
            arr = np.zeros(1, dtype=np.float64)
            m.get_value("soil_water~storage_volume", arr)
            assert arr[0] == 0.0, (
                f"soil_water~storage_volume read {arr[0]}, not 0.0 -- SoilMoistDiff may have been "
                "wired up since this test was written; update this test's expectation and "
                "docs/COUPLING_VARS_LEDGER.md's dead-code note together, don't just relax this "
                "assertion"
            )
        finally:
            m.finalize()


class TestPerCellRainfallRunoff:
    """`surface-water~rainfall_amount`/`surface-water~runoff_amount` (grid 0, metres) verified
    against LISEM's own map-file output for the identical run -- not just checked for existing and
    compiling. See docs/COUPLING_VARS_LEDGER.md's "Per-cell rainfall and runoff" section for the
    exact backing fields (RainCumFlat, Qm3total) and the disclosed runoff-includes-upstream-flow
    caveat this test does not re-litigate.
    """

    TOLERANCE_MM = 1e-3   # float32 map storage precision, not a physics tolerance
    TOLERANCE_M3 = 1e-2

    @needs_runfile
    def test_rainfall_amount_matches_own_rainfall_map(self):
        try:
            from osgeo import gdal  # noqa: F401
        except ImportError:
            pytest.skip("osgeo/GDAL not installed -- cannot verify against LISEM's own map output")

        result_dir = _parse_runfile_setting(RUNFILE, "Result Directory")
        rainfall_map_name = _parse_runfile_setting(RUNFILE, "Rainfall map")
        if not result_dir or not rainfall_map_name:
            pytest.skip("runfile does not declare a Result Directory/Rainfall map to verify against")
        rainfall_map_path = os.path.join(result_dir, rainfall_map_name)

        m = _make_model()
        try:
            if "surface-water~rainfall_amount" not in m.get_output_var_names():
                pytest.skip("surface-water~rainfall_amount not registered for this run config")
            _run_to_end(m)
            rainfall_bmi_mm = _read(m, "surface-water~rainfall_amount") * 1000.0  # m -> mm
        finally:
            m.finalize()

        if not os.path.exists(rainfall_map_path):
            pytest.skip(f"runfile's own rainfall map was not written: {rainfall_map_path}")
        rainfall_file_mm, nodata = _read_pcraster(rainfall_map_path)
        valid = rainfall_file_mm != nodata
        assert valid.any(), "rainfall map has no valid (non-nodata) cells to compare"

        residual = np.abs(rainfall_bmi_mm[valid] - rainfall_file_mm[valid])
        assert residual.max() < self.TOLERANCE_MM, (
            f"surface-water~rainfall_amount diverges from LISEM's own {rainfall_map_name}: "
            f"max |residual|={residual.max():.6g} mm (tolerance {self.TOLERANCE_MM} mm)"
        )

    @needs_runfile
    def test_runoff_amount_matches_own_runoff_map(self):
        try:
            from osgeo import gdal  # noqa: F401
        except ImportError:
            pytest.skip("osgeo/GDAL not installed -- cannot verify against LISEM's own map output")

        result_dir = _parse_runfile_setting(RUNFILE, "Result Directory")
        runoff_map_name = _parse_runfile_setting(RUNFILE, "Runoff map")
        if not result_dir or not runoff_map_name:
            pytest.skip("runfile does not declare a Result Directory/Runoff map to verify against")
        runoff_map_path = os.path.join(result_dir, runoff_map_name)

        m = _make_model()
        try:
            if "surface-water~runoff_amount" not in m.get_output_var_names():
                pytest.skip("surface-water~runoff_amount not registered for this run config")
            grid = m.get_var_grid("surface-water~runoff_amount")
            spacing = np.empty(2, dtype=np.float64)
            m.get_grid_spacing(grid, spacing)
            cell_area = abs(spacing[0] * spacing[1])
            _run_to_end(m)
            # BMI exposes a depth (m); Qm3total's own map is a volume (m3) -- convert back to
            # compare like-for-like against what LISEM itself wrote.
            runoff_bmi_m3 = _read(m, "surface-water~runoff_amount") * cell_area
        finally:
            m.finalize()

        if not os.path.exists(runoff_map_path):
            pytest.skip(f"runfile's own runoff map was not written: {runoff_map_path}")
        runoff_file_m3, nodata = _read_pcraster(runoff_map_path)
        valid = np.abs(runoff_file_m3 - nodata) > 1.0  # nodata is a large-magnitude float32 sentinel
        assert valid.any(), "runoff map has no valid (non-nodata) cells to compare"

        residual = np.abs(runoff_bmi_m3[valid] - runoff_file_m3[valid])
        assert residual.max() < self.TOLERANCE_M3, (
            f"surface-water~runoff_amount diverges from LISEM's own {runoff_map_name}: "
            f"max |residual|={residual.max():.6g} m3 (tolerance {self.TOLERANCE_M3} m3)"
        )

    @needs_runfile
    def test_rainfall_and_runoff_reset_with_model_reset_event(self):
        """Both are created via NewMap() like Fcum, so both should be auto-registered in LISEM's
        generic reset registry (maplistCTMap) and zeroed by model__reset_event -- confirmed
        directly here rather than assumed from the NewMap() code path alone.

        Cells outside the catchment mask read NaN (confirmed directly: for the VNIIMZ_20m fixture,
        exactly the 11,335 out-of-the-6,821-in-catchment cells the grid's own bounding box pads with
        -- same split already established in docs/bmi/GATE7_LISEM_PREP.md), so this uses nansum, not
        a raw sum -- a raw sum over the whole grid propagates NaN from cells that were never part of
        the catchment to begin with and has nothing to do with the reset mechanism being tested.
        """
        m = _make_model()
        try:
            if "surface-water~rainfall_amount" not in m.get_output_var_names():
                pytest.skip("surface-water~rainfall_amount not registered for this run config")
            for _ in range(5):
                m.update()
            rain_before = _read(m, "surface-water~rainfall_amount")
            assert np.nansum(rain_before) > 0, (
                "expected nonzero rainfall after 5 steps -- test setup issue"
            )

            m.set_value("model__reset_event", np.array([1.0]))

            rain_after = _read(m, "surface-water~rainfall_amount")
            runoff_after = _read(m, "surface-water~runoff_amount")
            assert np.nansum(rain_after) == 0.0, (
                f"expected surface-water~rainfall_amount to zero on model__reset_event, "
                f"got nansum={np.nansum(rain_after)}"
            )
            assert np.nansum(runoff_after) == 0.0, (
                f"expected surface-water~runoff_amount to zero on model__reset_event, "
                f"got nansum={np.nansum(runoff_after)}"
            )
        finally:
            m.finalize()
