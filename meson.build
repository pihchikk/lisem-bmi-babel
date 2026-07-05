project(
    'bmi_lisem',
    'cpp',
    'cython',
    version: '0.1',
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

install_subdir(
    'meta/Lisem',
    install_dir: py.get_install_dir() / 'bmi_lisem/data',
)

# This is a temporary fix for editable installs.
run_command('cp', '-r', 'bmi_lisem/data', 'build')