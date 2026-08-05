# test_lake (legacy SourceForge example dataset)

A small synthetic-scale debris-flow/mass-movement **release** test (110×80
grid, 8,800 cells), from openLISEM's own upstream example datasets
(SourceForge, `Example Datasets/test_lake.7z`). No infiltration model
(`Infil Method=0`), no rainfall, no channels — driven entirely by
`initialfvolume.map`/`initiationtime.map` (a pre-existing volume of material
that releases at a specified time), not by rainfall-runoff hydrology.

Use via `bmi_lisem.scenarios.legacy_dataset_runfile("test_lake")` — see
`bmi_lisem/scenarios.py`. Not the template file directly.

## Provenance and curation

Ported from `[openLISEM runfile version 1.0]` — see
`bmi_lisem/docs/COUPLING_VARS_LEDGER.md`'s "External real-world datasets"
section for the full writeup. `maps/` contains only the 21 files this
configuration's runfile actually references.

**No real rainfall file exists anywhere in the original archive** (the
runfile nominally sets `Include Rainfall=1` with `Rainfall file=0.txt`, but
`0.txt` was never included in the SourceForge download). This is an honest
reflection of the source, not a gap introduced here: this dataset's actual
purpose (a pre-existing debris mass releasing) never needed rainfall to
begin with. Ported with `Include Rainfall=0` and a trivial placeholder file
(`none.txt`) rather than fabricating a plausible-looking rainfall series
that was never part of the original dataset.

## A genuinely different, informative result — not a failure

`initialize()` → full `update()` loop (12,000 steps) → `finalize()`
succeeds, but **every output variable this BMI exposes reads exactly zero**
throughout. This is not a bug: this dataset's actual mechanism (a debris
mass released from `initialfvolume`/`initiationtime`) isn't represented by
any variable in this BMI's registry, which was built for
rainfall-runoff-infiltration-erosion coupling, not debris-flow-specific
diagnostics (solid-phase height, flow velocity, slope-stability safety
factor, etc.). The underlying engine may well be computing something
physically real internally; this BMI simply has no window into it. Useful
precisely because it shows the boundary of what this coupling layer
currently exposes, not because it demonstrates a working coupling scenario.
