project(
    'bmi_lisem',
    'cpp',
    'cython',
    # Single source of truth for the version: bmi_lisem/_version.py.
    version: run_command(
        'python3',
        '-c',
        'import re,pathlib;'
        + 'print(re.search(r\'"([^"]+)"\','
        + ' pathlib.Path("bmi_lisem/_version.py").read_text()).group(1))',
        check: true,
    ).stdout().strip(),
)

py = import('python').find_installation(pure: false)
compiler = meson.get_compiler('cpp')

# python_inc = py.get_path('data') / 'include'
numpy_inc = run_command(
    py,
    [
        '-c',
        'import numpy; print(numpy.get_include())'
    ],
    check: true
).stdout().strip()
incs = include_directories(
    [
        'bmi_lisem/lib',
        # python_inc,
        numpy_inc,
    ]
)

deps = [
]

# Files get copied to <python directory>/site-packages/<subdir>
install_pkg_srcs = [
    'bmi_lisem/__init__.py',
    'bmi_lisem/_bmi.py',
    'bmi_lisem/_version.py',
    'bmi_lisem/scenarios.py',
]
py.install_sources(
    install_pkg_srcs,
    subdir: 'bmi_lisem',
)

install_lib_srcs = [
    'bmi_lisem/lib/__init__.py',
    'bmi_lisem/lib/lisem.pyx',
]
py.install_sources(
    install_lib_srcs,
    subdir: 'bmi_lisem/lib',
)
py.extension_module(
    'lisem',
    [
        'bmi_lisem/lib/lisem.pyx',
    ],
    dependencies: [
        dependency('bmilisem', method : 'pkg-config'),
    ],
    include_directories: incs,
    install: true,
    subdir: 'bmi_lisem/lib',
    override_options : ['cython_language=cpp'],
)

# The bundled catchments under meta/Lisem/ are deliberately NOT installed into
# the wheel. They stay in the repository and are reachable from a source
# checkout (bmi_lisem.scenarios falls back to meta/Lisem/), but a built wheel
# ships code only.
#
# To put them back, restore:
#     install_subdir('meta/Lisem',
#                    install_dir: py.get_install_dir() / 'bmi_lisem/data')
# They add ~8 MB to a ~77 MB wheel (112 MB on disk; PCRaster .map files
# compress hard), so this is not where wheel size mostly comes from -- the bulk
# is the Qt6/GDAL/QWT stack auditwheel bundles.

# This is a temporary fix for editable installs.
run_command('cp', '-r', 'bmi_lisem/data', 'build')
