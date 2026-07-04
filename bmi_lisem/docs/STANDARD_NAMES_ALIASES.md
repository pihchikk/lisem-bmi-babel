# BMI Standard-Name Alias Layer (LISEM)

The native C++ BMI (`openlisem_bmi/bmi_lisem/BmiLisem.cpp`) registers variables
under **canonical ESoil standard names**. For backward compatibility every
name-keyed BMI method first passes the incoming name through
`BmiLisem::resolveVarAlias()`, which maps the **legacy CSDMS** spelling to the
canonical name. Canonical names — and any name not in the table — pass through
unchanged.

Consequences:
* `get_output_var_names()` / `get_input_var_names()` return **only canonical
  names** (the legacy names are gone from the advertised lists).
* `get_value` / `set_value` / `get_var_units` / `get_var_grid` / … accept
  **both** spellings and return identical results.
* This mirrors the AquaCrop Fortran alias layer (`resolve_var_alias`), so the
  babelized Python class `bmi_lisem.Lisem` exposes the canonical names with no
  extra Python wrapper.

## Alias table (legacy CSDMS → canonical ESoil)

| Legacy CSDMS name | Canonical ESoil name | Units | Status |
|---|---|---|---|
| `soil_water__volume_fraction`            | `soil_water_actual`                         | `m3 m-3` | ✓ confirmed (matches AquaCrop) |
| `land_vegetation__cover_fraction`        | `plant_cover~projective`                    | `1`      | ✓ confirmed (matches AquaCrop) |
| `soil_water__volume_fraction_in_layer_1` | `soil_water_actual_layer-1`                 | `m3 m-3` | agreed with AquaCrop |
| `soil_water__volume_fraction_in_layer_2` | `soil_water_actual_layer-2`                 | `m3 m-3` | agreed with AquaCrop |
| `soil_water__volume_fraction_in_layer_3` | `soil_water_actual_layer-3`                 | `m3 m-3` | agreed with AquaCrop |
| `land_surface_water__depth`              | `surface-water~depth`                       | `m`      | pending owner approval |
| `channel_water__volume_flow_rate`        | `water~channel_discharge`                   | `m3 s-1` | pending owner approval |
| `soil_water__infiltration_depth`         | `soil_infiltration~amount`                  | `m`      | pending — cumulative **depth** (m), distinct from `soil_infiltration~rate` |
| `soil__layer_depth_1`                    | `soil_layer-depth~layer-1`                  | `m`      | pending owner approval |
| `soil__layer_depth_2`                    | `soil_layer-depth~layer-2`                  | `m`      | pending owner approval |
| `soil__layer_depth_3`                    | `soil_layer-depth~layer-3`                  | `m`      | pending owner approval |
| `soil__erosion_mass_per_area`            | `soil_erosion~mass-per-area`                | `kg m-2` | pending owner approval |
| `domain_rainfall__volume`                | `surface-water~rainfall_volume`             | `m3`     | diagnostic; pending |
| `domain_interception__volume`            | `surface-water~interception_volume`         | `m3`     | diagnostic; pending |
| `domain_infiltration__volume`            | `surface-water~infiltration_volume`         | `m3`     | diagnostic; pending |
| `domain_evapotranspiration__volume`      | `surface-water~evapotranspiration_volume`   | `m3`     | diagnostic; pending |
| `domain_soil_water_storage__volume`      | `surface-water~storage_volume`              | `m3`     | diagnostic; pending |
| `domain_runoff__volume`                  | `surface-water~runoff_volume`               | `m3`     | key output; pending |

> Names marked "pending" are **provisional**; the registry owner
> (danilin_iv@esoil.ru) approves final wording via `standard_names_to_add.xlsx`.
> If a name changes, only `kAlias` in `BmiLisem.cpp` (and this table) needs
> editing — no other code changes. Confirmed names
> (`soil_water_actual`, `plant_cover~projective`) are fixed.

## Control signal

`model__reset_event` is a control signal, not a physical variable, and is left
unaliased. Writing any value to it triggers `TWorld::ResetEvent()`.

## Units

LISEM already emits UDUNITS-compatible unit strings (`m`, `m3 s-1`, `kg m-2`,
`m3 m-3`, `1`). No unit conversion is applied during aliasing — the existing
unit strings are preserved.

## Implementation notes

* `resolveVarAlias()` is a `static` member and is called at the top of every
  name-keyed method (`GetValue`, `SetValue`, `GetValuePtr`,
  `GetVar{Units,Grid,Type,Itemsize,Nbytes,Location}`) and inside `resolveVar()`
  and `isScalarOutput()`.
* The erosion kg/cell → kg/m² scaling in `GetValue` compares against the
  **canonical** name (`soil_erosion~mass-per-area`) after resolution, so it
  works for both spellings.

## Reconciliation with the standalone Python wrapper

The `feat/standalone-bmi-standard-names` branch carried a separate, thinner
Python wrapper (partial `~`-names, no per-layer θ / erosion / balance totals).
With the native C++ alias in place it is redundant and should be retired (or
reduced to a thin re-export of the babelized `Lisem` with no name table of its
own). Naming decisions carried over into that branch:

* `water_depth~surface` → **`surface-water~depth`**
* `soil_infiltration_amount` → **`soil_infiltration~amount`** (with `~`)
* `water~channel_discharge` — unchanged (already matches)
