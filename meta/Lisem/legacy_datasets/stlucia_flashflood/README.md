# StLucia_FlashFlood (legacy SourceForge example dataset)

A real St. Lucia catchment (227×271 grid, 61,517 cells) and a real "5-year"
design storm (`5 year johnson.txt`, 103mm), from openLISEM's own upstream
example datasets (SourceForge,
`Example Datasets/StLucia_FlashFlood.7z`). Green & Ampt infiltration
(2 soil layers), no erosion, no channels — a simpler flood-focused
counterpart to `stlucias_debrisflood/`, which shares the same rainfall file.

Use via `bmi_lisem.scenarios.legacy_dataset_runfile("stlucia_flashflood")` —
see `bmi_lisem/scenarios.py`. Not the template file directly.

## Provenance and curation

Ported from `[openLISEM runfile version 1.0]` — see
`bmi_lisem/docs/COUPLING_VARS_LEDGER.md`'s "External real-world datasets"
section for the full writeup. `maps/` contains only the 42 files this
configuration's runfile actually references, from the original archive's
`maps/` directory (`m20*`-prefixed files).

`5 year johnson.txt` is the **original, unmodified** rainfall file — this
dataset is where the silent rainfall day-index bug was originally caught:
the file's own plain floating-point-minutes format (no `ddd:` prefix)
defaulted to a day-index one full day earlier than `Begin time=001:0000`
uses, so every rainfall-dependent output read exactly `0.0` for the entire
run, initialize/update/finalize succeeding the whole time with no error at
all. Caught only by checking that a real, documented 103mm storm actually
showed up as non-zero rainfall. Fixed at the engine level (see the ledger);
the original file now works unmodified.

## Verified

`initialize()` → full `update()` loop → `finalize()` succeeds. Real,
non-zero rainfall (103.8mm, matching the file's own documented "103mm"
total exactly), infiltration 8.2–19mm, depth up to 2m, runoff up to
~3990mm-equivalent at high-accumulation cells (the same disclosed
"routed-through, not local generation" characteristic already documented
for `surface-water~runoff_amount` in the coupling ledger).
