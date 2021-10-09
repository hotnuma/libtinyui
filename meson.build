project(
    'tinyui',
    ['cpp'],
    version : '1.0',
    license : 'GPL-2.0',
    default_options : [
        'cpp_std=c++11',
    ],
)

cpp_args = [
#    '-DGDK_DISABLE_DEPRECATED',
#    '-DGTK_DISABLE_DEPRECATED',
    '-Wall',
    '-fno-rtti',
    '-fno-exceptions',
    '-O2',
]

tinyui_deps = [
    dependency('gtk+-3.0'),
    dependency('tinycpp', static : true),
]

install_headers(
    'lib/CWindow.h',
    'lib/CSingleInstance.h',
    'lib/libsocket.h',
)

tinyui_sources = [
    'lib/CWindow.cpp',
    'lib/CSingleInstance.cpp',
    'lib/libsocket.cpp',
]

tinyui = static_library(
    'tinyui',
    cpp_args : cpp_args,
    dependencies : tinyui_deps,
    sources : tinyui_sources,
    install : true,
)

pkg_mod = import('pkgconfig')
pkg_mod.generate(
    libraries : tinyui,
    version : '1.0',
    name : 'libtinyui',
    filebase : 'tinyui',
    description : 'A simple C++ library.',
)

#pkg = import('pkgconfig')
#lib = library('winui')
#pkg.generate(lib)

testui_deps = [
    dependency('gtk+-3.0'),
    dependency('tinycpp', static : true),
]

testui_sources = [
    'lib/CWindow.cpp',
    'main.cpp',
    'MainActions.cpp',
    'MainWindow.cpp',
]

executable(
    'testui',
    include_directories : 'lib',
    cpp_args : cpp_args,
    dependencies : testui_deps,
    sources : testui_sources,
    link_with : [tinyui],
)


