"""
BmiLisem — hand-written bmipy 2.0 wrapper around the babelizer-generated
``bmi_lisem.Lisem`` C++ binding.

Responsibilities:
- Expose a clean bmipy 2.0-compliant surface.
- Rename variables to canonical project standard names (no CSDMS __ names).
- Hide the internal control signal ``model__reset_event`` behind an explicit
  ``reset_event()`` method.
- Fill four methods absent from the babelizer stub
  (``get_value_ptr``, ``get_value_at_indices``, ``set_value_at_indices``,
  ``get_grid_face_edges``) and normalise the legacy count method names.
"""

from __future__ import annotations

import numpy as np

try:
    import bmipy
    _BASE = bmipy.Bmi
except ImportError:  # graceful degradation when bmipy not installed
    _BASE = object

# ---------------------------------------------------------------------------
# Variable name mapping: project standard name -> babelizer (raw) name
# ---------------------------------------------------------------------------
# Inputs
_INPUT_STD_TO_RAW: dict[str, str] = {
    "soil_water_actual":    "soil_water__volume_fraction",
    "plant_cover~projective": "land_vegetation__cover_fraction",
}

# Outputs (superset of inputs for soil_water_actual)
_OUTPUT_STD_TO_RAW: dict[str, str] = {
    "soil_water_actual":     "soil_water__volume_fraction",
    "soil_infiltration_amount": "soil_water__infiltration_depth",
    "water_depth~surface":   "land_surface_water__depth",
    "water~channel_discharge": "channel_water__volume_flow_rate",
}

# Units table keyed by project standard name (authoritative)
_UNITS: dict[str, str] = {
    "soil_water_actual":        "m3 m-3",
    "plant_cover~projective":   "1",
    "soil_infiltration_amount": "m",
    "water_depth~surface":      "m",
    "water~channel_discharge":  "m3 s-1",
}

# Grid id for every variable (all on the 2-D raster grid 0)
_VAR_GRID: dict[str, int] = {k: 0 for k in set(_INPUT_STD_TO_RAW) | set(_OUTPUT_STD_TO_RAW)}

_INPUT_NAMES: tuple[str, ...] = ("soil_water_actual", "plant_cover~projective")
_OUTPUT_NAMES: tuple[str, ...] = (
    "soil_water_actual",
    "soil_infiltration_amount",
    "water_depth~surface",
    "water~channel_discharge",
)


class BmiLisem(_BASE):
    """
    Standalone BMI wrapper for OpenLISEM with canonical project standard names.

    Wraps the babelizer-generated ``bmi_lisem.Lisem`` class, which is the
    Python binding of the native C++ ``BmiLisem`` (``libbmilisem.so``).

    Variable naming follows the single-underscore ``object_property_adjective``
    convention of the LISEM modelling group; ``~`` separates qualifiers.
    No CSDMS double-underscore names are exposed in the public surface.

    Parameters
    ----------
    None – pass the runfile path to :meth:`initialize`.

    Examples
    --------
    >>> m = BmiLisem()
    >>> m.initialize("/path/to/probnik_20m.run")
    >>> while m.get_current_time() < m.get_end_time():
    ...     m.update()
    >>> m.finalize()
    """

    _name = "OpenLISEM"

    def __init__(self) -> None:
        from bmi_lisem import Lisem  # babelizer-generated class
        self._raw: Lisem = Lisem()

    # ------------------------------------------------------------------
    # Lifecycle
    # ------------------------------------------------------------------

    def initialize(self, config_file: str) -> None:
        self._raw.initialize(config_file)

    def update(self) -> None:
        self._raw.update()  # returns None from C++; discard

    def update_until(self, time: float) -> None:
        while self.get_current_time() < time - 1e-9:
            if self.get_current_time() >= self.get_end_time():
                break
            self._raw.update()

    def finalize(self) -> None:
        self._raw.finalize()

    # ------------------------------------------------------------------
    # Model identification
    # ------------------------------------------------------------------

    def get_component_name(self) -> str:
        return self._name

    # ------------------------------------------------------------------
    # Variable lists & counts
    # ------------------------------------------------------------------

    def get_input_item_count(self) -> int:
        return len(_INPUT_NAMES)

    def get_output_item_count(self) -> int:
        return len(_OUTPUT_NAMES)

    def get_input_var_names(self) -> tuple[str, ...]:
        return _INPUT_NAMES

    def get_output_var_names(self) -> tuple[str, ...]:
        return _OUTPUT_NAMES

    # ------------------------------------------------------------------
    # Variable metadata  (accept project standard name)
    # ------------------------------------------------------------------

    def get_var_grid(self, name: str) -> int:
        self._check_var(name)
        return _VAR_GRID[name]

    def get_var_type(self, name: str) -> str:
        self._check_var(name)
        return self._raw.get_var_type(self._to_raw(name))

    def get_var_units(self, name: str) -> str:
        self._check_var(name)
        return _UNITS[name]

    def get_var_itemsize(self, name: str) -> int:
        self._check_var(name)
        return self._raw.get_var_itemsize(self._to_raw(name))

    def get_var_nbytes(self, name: str) -> int:
        self._check_var(name)
        return self._raw.get_var_nbytes(self._to_raw(name))

    def get_var_location(self, name: str) -> str:
        self._check_var(name)
        return self._raw.get_var_location(self._to_raw(name))

    # ------------------------------------------------------------------
    # Time
    # ------------------------------------------------------------------

    def get_current_time(self) -> float:
        return self._raw.get_current_time()

    def get_start_time(self) -> float:
        return self._raw.get_start_time()

    def get_end_time(self) -> float:
        return self._raw.get_end_time()

    def get_time_units(self) -> str:
        return self._raw.get_time_units()

    def get_time_step(self) -> float:
        return self._raw.get_time_step()

    # ------------------------------------------------------------------
    # Grid
    # ------------------------------------------------------------------

    def get_grid_rank(self, grid: int) -> int:
        return self._raw.get_grid_rank(grid)

    def get_grid_size(self, grid: int) -> int:
        return self._raw.get_grid_size(grid)

    def get_grid_type(self, grid: int) -> str:
        return self._raw.get_grid_type(grid)

    def get_grid_shape(self, grid: int, shape: np.ndarray) -> np.ndarray:
        return self._raw.get_grid_shape(grid, shape)

    def get_grid_spacing(self, grid: int, spacing: np.ndarray) -> np.ndarray:
        return self._raw.get_grid_spacing(grid, spacing)

    def get_grid_origin(self, grid: int, origin: np.ndarray) -> np.ndarray:
        return self._raw.get_grid_origin(grid, origin)

    def get_grid_x(self, grid: int, x: np.ndarray) -> np.ndarray:
        return self._raw.get_grid_x(grid, x)

    def get_grid_y(self, grid: int, y: np.ndarray) -> np.ndarray:
        return self._raw.get_grid_y(grid, y)

    def get_grid_z(self, grid: int, z: np.ndarray) -> np.ndarray:
        return self._raw.get_grid_z(grid, z)

    def get_grid_node_count(self, grid: int) -> int:
        return self._raw.get_grid_node_count(grid)

    def get_grid_edge_count(self, grid: int) -> int:
        return self._raw.get_grid_edge_count(grid)

    def get_grid_face_count(self, grid: int) -> int:
        return self._raw.get_grid_face_count(grid)

    def get_grid_edge_nodes(self, grid: int, edge_nodes: np.ndarray) -> np.ndarray:
        return self._raw.get_grid_edge_nodes(grid, edge_nodes)

    def get_grid_face_nodes(self, grid: int, face_nodes: np.ndarray) -> np.ndarray:
        return self._raw.get_grid_face_nodes(grid, face_nodes)

    def get_grid_nodes_per_face(self, grid: int, nodes_per_face: np.ndarray) -> np.ndarray:
        return self._raw.get_grid_nodes_per_face(grid, nodes_per_face)

    def get_grid_face_edges(self, grid: int, face_edges: np.ndarray) -> np.ndarray:
        # Not applicable for uniform_rectilinear; raw stub also raises.
        raise NotImplementedError(
            "get_grid_face_edges is not implemented for uniform_rectilinear grids"
        )

    # ------------------------------------------------------------------
    # Value getters / setters  (accept project standard name)
    # ------------------------------------------------------------------

    def get_value(self, name: str, dest: np.ndarray) -> np.ndarray:
        self._check_var(name)
        return self._raw.get_value(self._to_raw(name), dest)

    def get_value_ptr(self, name: str) -> np.ndarray:
        # The C++ layer has no shared memory accessible from Python; raise.
        raise NotImplementedError(
            "get_value_ptr is not supported for the native C++ BmiLisem binding"
        )

    def get_value_at_indices(
        self, name: str, dest: np.ndarray, inds: np.ndarray
    ) -> np.ndarray:
        self._check_var(name)
        n = self.get_grid_size(self.get_var_grid(name))
        buf = np.empty(n, dtype=dest.dtype)
        self.get_value(name, buf)
        dest[:] = buf[inds]
        return dest

    def set_value(self, name: str, src: np.ndarray) -> None:
        self._check_input_var(name)
        self._raw.set_value(self._to_raw(name), src)

    def set_value_at_indices(
        self, name: str, inds: np.ndarray, src: np.ndarray
    ) -> None:
        self._check_input_var(name)
        n = self.get_grid_size(self.get_var_grid(name))
        buf = np.empty(n, dtype=src.dtype)
        self.get_value(name, buf)
        buf[inds] = src
        self._raw.set_value(self._to_raw(name), buf)

    # ------------------------------------------------------------------
    # Custom coupling hook  (NOT part of standard BMI surface)
    # ------------------------------------------------------------------

    def reset_event(self) -> None:
        """
        Reset all dynamic state to the post-Initialize snapshot.

        Intended for event-based coupling: call between two rainfall events
        to reuse the same static terrain/parameter setup without re-reading
        input files.

        This is a non-BMI extension; it does NOT appear in
        get_input_var_names() / get_output_var_names().
        """
        sig = np.array([1.0], dtype=np.float64)
        self._raw.set_value("model__reset_event", sig)

    # ------------------------------------------------------------------
    # Internal helpers
    # ------------------------------------------------------------------

    def _all_vars(self) -> frozenset[str]:
        return frozenset(_INPUT_NAMES) | frozenset(_OUTPUT_NAMES)

    def _check_var(self, name: str) -> None:
        if name not in self._all_vars():
            raise KeyError(
                f"Unknown variable '{name}'. "
                f"Known: {sorted(self._all_vars())}"
            )

    def _check_input_var(self, name: str) -> None:
        if name not in _INPUT_STD_TO_RAW:
            raise KeyError(
                f"'{name}' is not a settable input variable. "
                f"Settable inputs: {sorted(_INPUT_STD_TO_RAW)}"
            )

    def _to_raw(self, std_name: str) -> str:
        """Translate a project standard name to the babelizer raw name."""
        raw = _INPUT_STD_TO_RAW.get(std_name) or _OUTPUT_STD_TO_RAW.get(std_name)
        if raw is None:
            raise KeyError(f"No raw mapping for '{std_name}'")
        return raw
