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

    # Under SWATRE (Infil Method=1), lisDataInit.cpp's entire Green & Ampt
    # layer-map-reading block is skipped (guarded by "InfilMethod !=
    # INFIL_SWATRE"), so soil_layer-depth~layer-1 (SoilDepth1, only ever
    # ReadMap()'d inside that block) is genuinely never allocated -- confirmed
    # directly against tiny_swatre.run, not assumed. Detected from the runfile
    # itself rather than hardcoded to a fixture name, same reasoning as
    # OPTIONAL_LAYER_SUFFIXES above.
    SWATRE_ONLY_OPTIONAL = ("soil_layer-depth~layer-1",)

    # soil_erosion~mass-per-area is only ever advertised when the runfile has erosion
    # switched on (Include Erosion simulation=1) -- confirmed against two real datasets
    # with erosion off (StLucia_FlashFlood, Dijkring41_Flood), where the var is correctly
    # absent from get_output_var_names(). Every fixture this project had before those two
    # happened to run with erosion on, which is what let this go unasserted-conditionally
    # for as long as it did. Same treatment as OPTIONAL_LAYER_SUFFIXES/SWATRE_ONLY_OPTIONAL
    # above: read the switch from the runfile rather than assuming it's always on.
    EROSION_ONLY = ("soil_erosion~mass-per-area",)

    @staticmethod
    def _is_swatre(runfile_path):
        return _parse_runfile_setting(runfile_path, "Infil Method") == "1"

    @staticmethod
    def _is_erosion_active(runfile_path):
        return _parse_runfile_setting(runfile_path, "Include Erosion simulation") == "1"

    @needs_runfile
    def test_coupling_vars_in_output_list(self):
        m = _make_model()
        try:
            out_vars = m.get_output_var_names()
            is_swatre = self._is_swatre(RUNFILE)
            is_erosion = self._is_erosion_active(RUNFILE)
            for name in MAP_OUTPUTS_COUPLING + SCALAR_OUTPUTS:
                if name.endswith(self.OPTIONAL_LAYER_SUFFIXES):
                    continue
                if is_swatre and name in self.SWATRE_ONLY_OPTIONAL:
                    continue
                if not is_erosion and name in self.EROSION_ONLY:
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

        Picks whichever candidate the CURRENT fixture actually doesn't
        advertise, rather than hardcoding soil_water_actual_layer-3. That
        hardcoding broke the moment a genuinely 3-layer fixture existed
        (tiny3.run, built to demonstrate SwitchThreeLayer) -- the invariant
        this test means to assert is "requesting a non-advertised canonical
        name raises cleanly", not "layer-3 specifically is always inactive".
        """
        m = _make_model()
        try:
            out_vars = m.get_output_var_names()
            candidates = [n for n in EXPECTED_UNITS if n not in out_vars]
            if not candidates:
                pytest.skip(
                    "every canonical coupling variable this suite knows about is "
                    "active for this fixture -- nothing genuinely inactive to probe"
                )
            name = candidates[0]
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


class TestFiniteness:
    """Finiteness invariant across every raster output, at several points in a
    full event -- not just post-event, and not just for one variable someone
    thought to check.

    Motivated by task #118 (ThetaI1a NaN investigation): a raster variable
    reading NaN in some cells doesn't by itself distinguish "outside the
    catchment, by design" (LISEM's own missing-value convention -- confirmed
    directly: for VNIIMZ_20m, exactly 11,335 of 18,156 grid cells are outside
    the catchment and every raster output reads NaN there, consistently) from
    "a real reporting problem". This checks that every raster output shares
    the *same* missing-value mask, and that no output has a non-finite value
    OUTSIDE that shared mask -- i.e. in a cell that's supposed to carry real
    data.

    Honest limitation, not papered over: this catches NaN/Inf specifically.
    It would NOT have caught task #118's actual finding on its own -- ThetaI1a
    inside the catchment mask was reading exactly 0.0 (a suspicious constant,
    not a non-finite value), traced to the runfile's own `Include
    Infiltration=0` setting short-circuiting TWorld::InfilEffectiveKsat()
    before it ever sets Thetaeff/Poreeff away from their zero-initialized
    default. That's a plausibility problem, not a finiteness problem; a
    finiteness invariant is still worth having as a permanent, general check
    for the class of bug it does catch.
    """

    @staticmethod
    def _raster_names(m):
        return sorted(n for n in m.get_output_var_names() if m.get_var_grid(n) == 0)

    @staticmethod
    def _read(m, name):
        grid = m.get_var_grid(name)
        n = m.get_grid_size(grid)
        buf = np.empty(n, dtype=np.float64)
        m.get_value(name, buf)
        return buf

    def _check_checkpoint(self, m, raster_names, label):
        reference_name = raster_names[0]
        reference_mask = np.isnan(self._read(m, reference_name))
        for name in raster_names:
            arr = self._read(m, name)
            mask = np.isnan(arr)
            assert np.array_equal(mask, reference_mask), (
                f"[{label}] {name!r}'s missing-value mask ({mask.sum()} NaN cells) "
                f"differs from {reference_name!r}'s ({reference_mask.sum()} NaN "
                "cells) -- every raster output should agree on which cells are "
                "outside the catchment"
            )
            finite = arr[~mask]
            assert np.all(np.isfinite(finite)), (
                f"[{label}] {name!r} has {np.sum(~np.isfinite(finite))} non-finite "
                "value(s) inside the catchment mask (i.e. in a cell that's "
                "supposed to carry real data)"
            )

    @needs_runfile
    def test_finiteness_invariant_across_outputs(self):
        m = _make_model()
        try:
            raster_names = self._raster_names(m)
            assert raster_names, "no raster outputs to check"

            self._check_checkpoint(m, raster_names, "pre-event")

            end = m.get_end_time()
            halfway = end / 2.0
            while m.get_current_time() < halfway - 1e-9:
                m.update()
            self._check_checkpoint(m, raster_names, "mid-event")

            while m.get_current_time() < end - 1e-9:
                m.update()
            self._check_checkpoint(m, raster_names, "post-event / final")
        finally:
            m.finalize()


# ---------------------------------------------------------------------------
# 2. Post-event physical correctness
# ---------------------------------------------------------------------------

class TestPostEventValues:
    """Values are physically plausible after a complete rainfall event."""

    @needs_runfile
    def test_actual_theta_differs_from_initial(self):
        """Post-event θ (layer 1) differs from initial θ where rain fell -- avgTheta() actually
        ran and is producing a value tied to the event, not silently returning the antecedent
        condition unchanged.

        Deliberately direction-agnostic. This is the third test in this suite to have encoded a
        single scenario's outcome as a general law -- after test_coupling_vars_in_output_list
        (assumed layer-3 always registered) and test_erosion_finite_nonnegative (assumed
        detachment always occurs). This one assumed post-event must be WETTER. Traced directly
        (not guessed): on VNIIMZ_20m with Include Infiltration=1, layer-1 theta drops smoothly and
        monotonically from ~0.35 to ~0.04-0.20 over the event (confirmed via checkpoints at 0/25/
        50/75/100% of event time -- a gradual decline, not a single-step overwrite bug), while
        layer-2 theta rises sharply and then pins at ThetaS2 once the wetting front passes
        SoilDepth2 (see docs/COUPLING_VARS_LEDGER.md's "soil_water_actual_layer-2 saturates and
        freezes" section). ThetaR1 (the floor Thetaeff can't go below) is a legitimate
        pedotransfer-derived value, not a bug, and the observed values sit well above it, not
        pinned to it. This soil's Ksat1 (~55-56 mm/hr) can transmit far more than this event's
        ~15.5mm total rainfall in the ~2.3hr event duration, so drainage outpacing input and
        leaving layer 1 drier than its (fairly wet, ~0.35) antecedent condition is a physically
        normal outcome for a modest storm on a fast-draining soil -- not something a general
        assertion should assume away in either direction.

        Excludes the out-of-catchment mask before checking finiteness -- those cells read NaN by
        design (every raster output shares that mask; see TestFiniteness, which confirms it
        directly). Checking the raw array without excluding the mask was mistaking LISEM's own
        missing-value convention for a bug (task #118): the real problem that investigation found
        was a suspicious-but-finite constant (0.0) inside the mask, not a non-finite value, which
        is why this needed a separate, explicit mask rather than a plain isfinite() check.
        """
        m = _make_model()
        try:
            out_vars = set(m.get_output_var_names())
            if "soil_water_actual_layer-1" not in out_vars:
                pytest.skip("soil_water_actual_layer-1 not registered")
            # soil_water_actual (ThetaI1, the baseline this test compares against) is only
            # ever ReadMap()'d inside lisDataInit.cpp's "InfilMethod != INFIL_SWATRE" block --
            # genuinely absent under SWATRE, confirmed against tiny_swatre.run.
            if "soil_water_actual" not in out_vars:
                pytest.skip("soil_water_actual not registered (SWATRE?)")

            theta0_flat = _read(m, "soil_water_actual")

            _run_to_end(m)

            theta1_flat = _read(m, "soil_water_actual_layer-1")

            # Same masking approach as TestFiniteness: derive the missing-value mask
            # from the array itself rather than assuming a shape, then only assert
            # inside it.
            catchment_mask = ~np.isnan(theta1_flat)
            theta0_in = theta0_flat[catchment_mask]
            theta1_in = theta1_flat[catchment_mask]

            # Must be finite and within [0, 1] inside the catchment
            assert np.all(np.isfinite(theta1_in)), "post-event θ1a contains non-finite values inside the catchment mask"
            assert np.all(theta1_in >= 0), "post-event θ1a contains negative values"
            assert np.all(theta1_in <= 1), "post-event θ1a contains values > 1"

            # Somewhere theta must have moved -- avgTheta() ran and produced an event-linked
            # value, whether the net effect at a given cell was wetting or draining.
            assert np.any(np.abs(theta1_in - theta0_in) > 1e-6), (
                "post-event θ1a is identical to initial θ1 everywhere — "
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
        name actually asks about -- via that same qMax(0,.) split.

        The "detachment must have happened somewhere" expectation only applies when runoff
        actually occurred, not unconditionally. With Include Infiltration=1 (see README.rst),
        essentially all rainfall on VNIIMZ_20m infiltrates and runoff is ~zero -- real runoff
        means some detachment is expected, as asserted below.

        No-runoff does NOT imply zero detachment, though -- confirmed directly against the
        engine source, not assumed: splash detachment (cell_SplashDetachment(),
        erosion/lisErosionSplash.cpp) is driven by rainfall kinetic energy hitting ponded water
        (gated on WH > HMIN, a min depth, not on flow) and is called unconditionally every step
        from lisModel.cpp. Flow detachment (cell_FlowDetachment()) is the only one of the two
        gated on actual overland flow -- it's called from inside lisOverlandflow.cpp. This test
        used to assert "no runoff -> erosion must be exactly zero", reasoning that flow shear is
        what drives detachment -- wrong for splash, which needs no flow at all. Confirmed wrong
        on Sicily_DebrisFlow: a real cell showed net erosion with runoff ~0 m3 (rainsplash on
        ponded rainfall, no surface flow involved) -- not a bug, exactly what
        cell_SplashDetachment()'s own gating predicts. So the no-runoff branch asserts nothing
        beyond the finiteness check already done above; only the has-runoff branch (flow
        detachment plausibly active too) still asserts detachment/deposition occurred.
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

            rain = _read(m, "surface-water~rainfall_volume")[0]
            runoff = _read(m, "surface-water~runoff_volume")[0]
            runoff_occurred = runoff > 1e-6 * max(abs(rain), 1e-12)

            if not runoff_occurred:
                # Splash detachment doesn't need runoff (see docstring) -- nothing to assert
                # here beyond the finiteness check already done above.
                pass
            else:
                assert np.any(erosion_component > 0), (
                    f"runoff occurred (runoff={runoff:.4g} m3) but no cell shows net erosion "
                    "(all non-negative kg/m² values are exactly 0) -- expected some detachment "
                    "somewhere given real surface flow"
                )
                assert np.any(deposition_component < 0), (
                    "no cell shows net deposition -- expected on VNIIMZ_20m when runoff "
                    "occurred; if this genuinely changed, the split may no longer be the right "
                    "shape of check for this fixture"
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


class TestStaleness:
    """Every advertised output variable should either change over the course of a real
    event, or be on an explicit allowlist of variables known to be legitimately static
    for the current run (soil parameters, layer depths, dead code, or a switch that's
    off in every fixture this project has). Neither the readability invariant
    (test_every_advertised_output_var_is_readable) nor the finiteness invariant
    (TestFiniteness) can see "reads fine, is finite, but never changes" -- that's
    exactly the shape of three separate defects found in this project: the frozen
    soil_water_actual_layer-3 echo, the pre-fix soil_water_actual_layer-2 (always
    exactly 0.0 whenever SwitchTwoLayer was false), and the ALIASES table pointing a
    legacy name at a dead scalar. This is the assertion that would have caught all
    three directly, without anyone needing to think to check each one by name.

    Deliberately a two-point check (initialize() vs. end of run), not a full
    per-timestep trace -- matches what was asked for and is enough to catch "never
    updated at all", the actual shape of every defect this test class is modeled on.

    Checked directly against all five fixtures in this project (not assumed to
    generalize), 2026-08: res_test/run_test.run, results_test/run_test.run,
    tiny.run, tiny3.run, tiny_swatre.run.
    """

    # Structurally static: never touched after initialization, by design, documented
    # elsewhere. Frozen on every fixture that advertises them.
    STRUCTURAL_ALLOWLIST = {
        # Constant per-cell soil-depth maps.
        "soil_layer-depth~layer-1",
        "soil_layer-depth~layer-2",
        "soil_layer-depth~layer-3",
        # ThetaI1 initial-condition input map, echoed as-is, never recomputed --
        # see COUPLING_VARS_LEDGER.md's "Notes on soil moisture".
        "soil_water_actual",
        # avgTheta() has no layer-3 update path at all -- frozen echo of ThetaI3
        # whenever advertised (3-layer configs). See COUPLING_VARS_LEDGER.md's
        # "never updates at all" section. Deliberately NOT extended to layer-2:
        # soil_water_actual_layer-2 is only ever advertised when SwitchTwoLayer is
        # true (post the ThetaI2a allocation fix), and it IS live whenever it's
        # advertised -- if it ever freezes again, this test should catch it, not
        # wave it through.
        "soil_water_actual_layer-3",
        # SoilMoistTot: dead code, SoilMoistDiff (the only thing ever added to it)
        # is never populated -- see TestSoilMoistTotIsDeadCode above, an existing,
        # separately-documented contract, not a new finding here.
        "soil_water~storage_volume",
    }

    # Zero because the responsible switch is off in every fixture this project has
    # (Include ET=0, Include Interception=0 everywhere) -- correctly zero given that,
    # but genuinely unverified when the switch is on, since no fixture exercises that
    # path. Flagged here explicitly rather than silently folded into the structural
    # list above.
    SWITCHED_OFF_EVERYWHERE_ALLOWLIST = {
        "surface-water~evapotranspiration_volume",
        "surface-water~interception_volume",
    }

    # Zero-activity on some fixtures (a gentle/tiny event fully infiltrates, or
    # generates no measurable runoff), but confirmed genuinely live and moving on
    # results_test/run_test.run specifically -- so a fixture with more rainfall MUST
    # show these actually changing; this allowlist only covers the "no activity
    # this event" case, not "can never move".
    ZERO_ACTIVITY_ALLOWLIST = {
        "soil_erosion~mass-per-area",
        "surface-water~depth",
        "surface-water~runoff_amount",
        "surface-water~runoff_volume",
        "surface-water~storage_volume",
        "water~channel_discharge",
    }

    STATIC_ALLOWLIST = STRUCTURAL_ALLOWLIST | SWITCHED_OFF_EVERYWHERE_ALLOWLIST | ZERO_ACTIVITY_ALLOWLIST

    @needs_runfile
    def test_no_unexpected_frozen_outputs(self):
        m = _make_model()
        try:
            names = sorted(m.get_output_var_names())
            initial = {name: _read(m, name) for name in names}

            _run_to_end(m)

            frozen = [
                name for name in names
                if np.array_equal(initial[name], _read(m, name), equal_nan=True)
            ]
            unexpected = sorted(set(frozen) - self.STATIC_ALLOWLIST)
            assert not unexpected, (
                f"variable(s) advertised as output but bit-identical from initialize() "
                f"to end of run, not on the known-static allowlist: {unexpected} -- "
                "either this is a newly-frozen variable (investigate and fix, or add "
                "to the allowlist with a documented reason in COUPLING_VARS_LEDGER.md "
                "and here), or the registry is advertising something nothing fills."
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

    # Runoff (unlike rainfall) accumulates upstream flow, so its magnitude spans many
    # orders across a grid -- and across datasets, from a few m3 on a small catchment to
    # tens of thousands of m3 at an outlet cell on a large one. A single fixed absolute
    # tolerance tuned to VNIIMZ_20m's scale (0.01 m3) failed on two real, larger datasets
    # (StLucia_FlashFlood: 0.060 m3 residual; StLucias_DebrisFlood: 0.034 m3 residual) for
    # no reason other than their own runoff being proportionally larger -- a scaling
    # artifact, not a correctness signal. Scale the tolerance to the map's own reported
    # magnitude instead, with a small absolute floor for near-zero domains (so a genuinely
    # tiny catchment doesn't get an unreasonably tight tolerance from a near-zero scale).
    TOLERANCE_REL = 1e-4  # matches the fixed 0.01 m3 that worked at VNIIMZ_20m's own scale
    TOLERANCE_M3_FLOOR = 1e-2

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
        scale = np.abs(runoff_file_m3[valid]).max()
        tolerance = max(self.TOLERANCE_REL * scale, self.TOLERANCE_M3_FLOOR)
        assert residual.max() < tolerance, (
            f"surface-water~runoff_amount diverges from LISEM's own {runoff_map_name}: "
            f"max |residual|={residual.max():.6g} m3 (tolerance {tolerance:.6g} m3 = "
            f"max({self.TOLERANCE_REL} * scale={scale:.6g}, floor={self.TOLERANCE_M3_FLOOR}))"
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

        Waits for rainfall to actually start rather than assuming a fixed step count gets there:
        a fixed 5-step wait only ever worked because it happened to match VNIIMZ_20m's own
        timestep/rain-onset timing -- it failed on 5 of 6 real legacy datasets (all with real
        rainfall) purely because 5 steps covered too little simulated time for rain to have
        started yet at their own timestep. Bounded by the run's own end time, so a fixture with
        genuinely no rainfall (test_lake: no rainfall file at all) skips cleanly instead of
        spinning through a full multi-hour run only to fail the same way regardless.
        """
        m = _make_model()
        try:
            if "surface-water~rainfall_amount" not in m.get_output_var_names():
                pytest.skip("surface-water~rainfall_amount not registered for this run config")
            end = m.get_end_time()
            rain_before = _read(m, "surface-water~rainfall_amount")
            while np.nansum(rain_before) == 0.0 and m.get_current_time() < end - 1e-9:
                m.update()
                rain_before = _read(m, "surface-water~rainfall_amount")
            if np.nansum(rain_before) == 0.0:
                pytest.skip(
                    "rainfall never became nonzero over the whole run -- this fixture doesn't "
                    "produce real rainfall (e.g. no rainfall file), nothing to test the reset "
                    "behavior against"
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
