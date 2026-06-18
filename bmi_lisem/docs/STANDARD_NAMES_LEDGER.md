# Standard Names Ledger — bmi_lisem

Variable names exposed in the public BMI surface of `BmiLisem` follow the
LISEM modelling group naming convention:

```
object_property_adjective
```

- tokens separated by single underscores `_`
- qualifiers attached with tilde `~`
- no CSDMS double-underscore `__` in the public API

---

## Variable Registry

| Public standard name | Internal LISEM var | Raw babelizer name | Units | Grid | Direction | Status |
|---|---|---|---|---|---|---|
| `soil_water_actual` | `ThetaI1` | `soil_water__volume_fraction` | `m3 m-3` | 0 | in + out | **registered** |
| `plant_cover~projective` | `Cover` | `land_vegetation__cover_fraction` | `1` | 0 | in | **registered** |
| `soil_infiltration_amount` | `Fcum` | `soil_water__infiltration_depth` | `m` | 0 | out | **COINED — pending registration** |
| `water_depth~surface` | `WH` | `land_surface_water__depth` | `m` | 0 | out | **COINED — pending registration** |
| `water~channel_discharge` | `Qn` | `channel_water__volume_flow_rate` | `m3 s-1` | 0 | out | **COINED — pending registration** |

Grid 0: `uniform_rectilinear`, rank 2.  Time units: `s`.

---

## Coined Names Pending Registration

The following three names were coined by applying the project naming
convention (`object_property_adjective`, `~` for qualifiers) to physical
quantities that exist in LISEM but have not yet been submitted to the
standard names registry (`стандартные_имена_25052026.xlsx`).

They should be submitted for confirmation to the registry owner
(**danilin_iv@esoil.ru**) before being used in cross-model coupling
outside of the LISEM project.

### `soil_infiltration_amount`

**Interpretation:** cumulative depth of water that has infiltrated the soil
during the event, expressed as a water-layer depth [m].

**Convention breakdown:**
- `soil` — object (the soil medium)
- `infiltration` — property (process that moves water into the soil)
- `amount` — adjective/qualifier (accumulated scalar, standard cf. `amount` in CF)

**LISEM variable:** `Fcum` (m), calculated by Green–Ampt or SWATRE.

---

### `water_depth~surface`

**Interpretation:** depth of water ponded on the land surface [m].

**Convention breakdown:**
- `water` — object
- `depth` — property (vertical extent of the water body)
- `~surface` — qualifier (restricts to the land-surface ponding layer,
  as opposed to channel or subsurface water)

**LISEM variable:** `WH` (m).

---

### `water~channel_discharge`

**Interpretation:** volumetric flow rate of water in the channel network [m³ s⁻¹].

**Convention breakdown:**
- `water` — object
- `~channel` — qualifier (restricts to the channel/drainage network)
- `discharge` — property (volumetric flow rate)

**LISEM variable:** `Qn` (m³ s⁻¹), kinematic-wave channel discharge.

---

## What This Wrapper Adds to the Babelizer-Generated Class

The babelizer-generated `bmi_lisem.Lisem` class:

| Issue | Resolution in `BmiLisem` |
|---|---|
| Exposes CSDMS `__` names (`soil_water__volume_fraction`, etc.) | Renamed to project standard names in public surface |
| Legacy count methods (`get_input_var_name_count`) from babelizer | Normalised: `get_input_item_count` / `get_output_item_count` |
| `get_value_ptr` absent | `raise NotImplementedError` (no shared memory from Python) |
| `get_value_at_indices` absent | Implemented via full `get_value` + numpy index |
| `set_value_at_indices` absent | Implemented via read-modify-write |
| `get_grid_face_edges` absent | `raise NotImplementedError` (n/a for uniform_rectilinear) |
| `model__reset_event` control signal in input list | Hidden; exposed as explicit `reset_event()` method |
| No `update_until` that respects `None` return of `update()` | Implemented with `get_current_time() < t - 1e-9` guard |

Physics, numerics, and C++ native code are unchanged.

---

## TODO / Known Gaps

- `model__reset_event` metadata (grid 1, scalar) currently causes an abort
  in the C++ layer when introspected via standard var-info methods on the raw
  class. Workaround in `BmiLisem`: the signal is invoked via `reset_event()`
  only (no introspection). A future C++ fix should make the scalar grid
  metadata safe to query. Tracked here, not fixed in this Python-only PR.
