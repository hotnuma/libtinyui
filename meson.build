project(
    'tinyui',
    ['c'],
    version : '1.0',
    license : 'LGPL-2.0',
    default_options : [
        'c_std=c99',
    ],
)

c_args = [
    '-Wall',
    '-Wextra',
    '-D_GNU_SOURCE',
    '-D__STDC_FORMAT_MACROS',
]

if get_option('buildtype') == 'plain'
  c_args += '-O2'
endif

tinyui_deps = [
    #dependency('tinycpp', static : true),
    dependency('gtk+-3.0'),
]

tinyui_headers = [
    'lib/etkaction.h',
    'lib/etktype.h',
]

tinyui_sources = [
    'lib/etkaction.c',
]

# Build and install library ---------------------------------------------------

tinyui = static_library(
    'tinyui',
    include_directories : ['lib'],
    c_args : c_args,
    dependencies : tinyui_deps,
    sources : tinyui_sources,
    install : true,
)

install_headers(tinyui_headers, subdir: 'tinyui')

pkg_mod = import('pkgconfig')
pkg_mod.generate(
    libraries : tinyui,
    version : '1.0',
    name : 'libtinyui',
    filebase : 'tinyui',
    subdirs : 'tinyui',
    description : 'A Gtk3 extension library.',
)

#~ testui_deps = [
#~     dependency('gtk+-3.0'),
#~     dependency('tinyui', static : true),
#~ ]

#~ testui_sources = [
#~     'main.c',
#~ ]

#~ executable(
#~     'testui',
#~     include_directories : 'lib',
#~     c_args : c_args,
#~     dependencies : testui_deps,
#~     sources : testui_sources,
#~     link_with : [tinyui],
#~ )


