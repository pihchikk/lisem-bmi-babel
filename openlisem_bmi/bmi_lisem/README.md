# Native C++ BMI for OpenLISEM

`BmiLisem` implements the CSDMS Basic Model Interface (`bmi::Bmi`, BMI 2.0,
vendored in `../include/bmi.hxx`) on top of the refactored `TWorld` engine
(`Initialize` / `Update` / `Finalize`).

## Files

| File                 | Purpose                                                       |
|----------------------|---------------------------------------------------------------|
| `BmiLisem.h`         | `class BmiLisem : public bmi::Bmi` declaration                |
| `BmiLisem.cpp`       | Implementation                                                 |
| `lisem_bmi_test.cpp` | Minimal driver (`== ./Lisem -ni -bmistep <runfile>`)          |

## Implemented (phase B1)

* **Lifecycle**: `Initialize(runfile)`, `Update()`, `UpdateUntil(t)`, `Finalize()`
* **Time**: `GetStartTime`, `GetEndTime`, `GetCurrentTime`, `GetTimeStep`, `GetTimeUnits`
* `GetComponentName()` → `"OpenLISEM"`
* `ResetEvent()` — non-standard coupling hook for event-based reruns

All variable / grid / getter / setter methods throw
`std::runtime_error("<method>: not implemented (B2/B3)")` until wired to
`TWorld` maps in later phases.

## Build

The targets are part of the normal CMake configuration (no extra flag):

```sh
cmake -S openlisem_bmi -B build
cmake --build build --target lisem_bmi_test
```

Targets: `bmilisem` (static lib = model objects + wrapper) and
`lisem_bmi_test` (driver). The default `Lisem` executable is a separate,
unaffected target.
