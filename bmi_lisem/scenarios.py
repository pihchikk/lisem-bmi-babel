"""Bundled, ready-to-run OpenLISEM scenarios.

``default_scenario_runfile()`` resolves the packaged VNIIMZ_20m real-catchment
data (installed alongside this package, or found relative to a source
checkout) and writes a ready-to-use runfile with real, absolute paths
substituted in place of the template's ``{MAP_DIR}``/``{RAIN_DIR}``/
``{RESULT_DIR}`` placeholders -- OpenLISEM's runfile format requires literal
absolute paths, so the template on its own is not directly usable.

See ``meta/Lisem/vniimz_20m/README.md`` for what this scenario is (a real,
measured 20m-resolution catchment and a single real storm event, Green &
Ampt infiltration) and exactly what was curated into it.

``legacy_dataset_runfile(name)`` does the same for six real public example
datasets from openLISEM's own upstream project (SourceForge), ported forward
from their original ``[openLISEM runfile version 1.0]`` format -- see
``meta/Lisem/legacy_datasets/<name>/README.md`` for each one's provenance,
curation, and the engine fixes/limitations found while porting it (documented
in full in ``bmi_lisem/docs/COUPLING_VARS_LEDGER.md``).
"""

import os
import tempfile
from pathlib import Path

LEGACY_DATASETS = (
    "ganspoel_hydrology",
    "dijkring41_flood",
    "stlucias_debrisflood",
    "sicily_debrisflow",
    "stlucia_flashflood",
    "test_lake",
)


def _find_scenario_dir(*subdir: str, template_name: str) -> Path:
    """Installed location first (``bmi_lisem/data/Lisem/<subdir>`` -- meson's
    ``install_subdir('meta/Lisem', ...)`` preserves the ``Lisem`` basename, it
    does not flatten ``meta/Lisem``'s contents directly into ``bmi_lisem/data``);
    falls back to a repo-relative path so this also works when running from a
    source checkout that hasn't been installed yet."""
    installed = Path(__file__).resolve().parent / "data" / "Lisem" / Path(*subdir)
    if (installed / template_name).exists():
        return installed

    repo_relative = Path(__file__).resolve().parents[1] / "meta" / "Lisem" / Path(*subdir)
    if (repo_relative / template_name).exists():
        return repo_relative

    raise FileNotFoundError(
        f"scenario data not found for {'/'.join(subdir)} -- looked in "
        f"{installed} and {repo_relative}. Rebuild/reinstall bmi_lisem, or run "
        f"from a source checkout that has meta/Lisem/{'/'.join(subdir)}/."
    )


def _write_runfile(scenario_dir: Path, template_name: str, map_dir: Path,
                    rain_dir: Path, result_dir: str | None, prefix: str) -> str:
    if result_dir is None:
        result_dir = tempfile.mkdtemp(prefix=f"lisem_{prefix}_")
    os.makedirs(result_dir, exist_ok=True)

    template = (scenario_dir / template_name).read_text(encoding="utf-8")
    runfile_text = (
        template.replace("{MAP_DIR}", str(map_dir))
        .replace("{RAIN_DIR}", str(rain_dir))
        .replace("{RESULT_DIR}", str(result_dir))
    )

    fd, runfile_path = tempfile.mkstemp(prefix=f"{prefix}_", suffix=".run")
    with os.fdopen(fd, "w", encoding="utf-8") as handle:
        handle.write(runfile_text)
    return runfile_path


def default_scenario_runfile(result_dir: str | None = None) -> str:
    """Return an absolute path to a ready-to-use runfile for the bundled
    VNIIMZ_20m scenario (Green & Ampt, 2 soil layers, a single real ~12-hour
    storm event, erosion enabled, ET and interception disabled).

    ``result_dir``: where OpenLISEM writes its own report outputs (totals.csv,
    map series, etc). Defaults to a fresh temporary directory if omitted.
    """
    template_name = "run_test.run.template"
    scenario_dir = _find_scenario_dir("vniimz_20m", template_name=template_name)
    return _write_runfile(
        scenario_dir, template_name,
        map_dir=scenario_dir / "maps", rain_dir=scenario_dir,
        result_dir=result_dir, prefix="vniimz_20m",
    )


def legacy_dataset_runfile(name: str, result_dir: str | None = None) -> str:
    """Return an absolute path to a ready-to-use runfile for one of the six
    bundled legacy (SourceForge) example datasets. ``name`` must be one of
    ``LEGACY_DATASETS``. See each dataset's own
    ``meta/Lisem/legacy_datasets/<name>/README.md`` for what it is and what
    was ported to make it run on this engine version.

    ``result_dir``: where OpenLISEM writes its own report outputs. Defaults
    to a fresh temporary directory if omitted.
    """
    if name not in LEGACY_DATASETS:
        raise ValueError(f"Unknown legacy dataset {name!r}; must be one of {LEGACY_DATASETS}")

    template_name = "run.run.template"
    scenario_dir = _find_scenario_dir("legacy_datasets", name, template_name=template_name)
    return _write_runfile(
        scenario_dir, template_name,
        map_dir=scenario_dir / "maps", rain_dir=scenario_dir,
        result_dir=result_dir, prefix=name,
    )
