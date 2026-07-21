# Vendored OpenLISEM

This repository vendors the complete **OpenLISEM** hydrological / soil-erosion
model under `openlisem_bmi/`. OpenLISEM is licensed under **GPL-3.0** (see
`openlisem_bmi/GPL-v3.0.txt`); because the `bmi_lisem` wheel statically links it,
the distributed package is GPL-3.0 as a whole (see `LICENSE.rst`).

## Upstream

- **Project:** OpenLISEM (author: Victor Jetten et al.)
- **Upstream repository:** https://github.com/vjetten/openlisem
- **Base commit (SHA):** `TODO — fill in the exact upstream commit this tree was
  branched from`. Until confirmed, treat the vendored tree as an
  unpinned snapshot; the maintainer (danilin_iv@esoil.ru / pihchikk) should
  record the SHA here.

> **Ideal:** replace the vendored copy with a git submodule pinned to the base
> commit plus a patch series (the files listed below). Minimum acceptable: this
> file, kept up to date.

## Local modifications on top of upstream

The changes made to the vendored engine to expose a native BMI are confined to a
small set of files. Everything else under `openlisem_bmi/` is upstream OpenLISEM.

### New files (BMI wrapper — original glue code)

- `openlisem_bmi/bmi_lisem/BmiLisem.h`
- `openlisem_bmi/bmi_lisem/BmiLisem.cpp`
- `openlisem_bmi/bmi_lisem/lisem_bmi_test.cpp` (test driver)
- `openlisem_bmi/bmi_lisem/babel.toml`
- `openlisem_bmi/bmi_lisem/bmi.hxx` (vendored CSDMS bmi-cxx header)
- CMake targets in `openlisem_bmi/Application.cmake` for `bmilisem*`

### Modified upstream engine files

- `openlisem_bmi/include/model.h`
  - added `bool bmiMode`, `QList<cTMap*> maplistInit`, and the
    `Initialize()/Update()/Finalize()/ResetEvent()/DumpState()` BMI surface plus
    `SnapshotInitialState()/RestoreInitialState()` declarations.
- `openlisem_bmi/model/lisModel.cpp`
  - added `SnapshotInitialState()`, `RestoreInitialState()`, `ResetEvent()`, and
    the refactored `Initialize()/Update()/Finalize()` lifecycle; scalar-total
    resets (including `RainTot`/`SnowTot`).
- `openlisem_bmi/model/main.cpp`
  - headless / batch entry adjustments used by the BMI (`noInterface`,
    `bmiMode`).

## How to regenerate this list

```bash
# files touched relative to the recorded upstream base commit
git diff --name-only <UPSTREAM_BASE_SHA> -- openlisem_bmi/
```
