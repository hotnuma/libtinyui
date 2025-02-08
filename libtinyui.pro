TEMPLATE = app
TARGET = testui
CONFIG = c++11 link_pkgconfig
PKGCONFIG = gtk+-3.0
DEFINES = _GNU_SOURCE __STDC_FORMAT_MACROS
INCLUDEPATH = lib

HEADERS = \
    lib/etkaction.h \
    lib/etktype.h \
    lib/etkwidgetlist.h

SOURCES = \
    lib/etkaction.c \
    lib/etkwidgetlist.c

DISTFILES = \
    install.sh \
    meson.build \
    Readme.md \

