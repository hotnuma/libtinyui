TEMPLATE = app
TARGET = testui
CONFIG = c++11 link_pkgconfig
PKGCONFIG = gtk+-3.0
DEFINES =
INCLUDEPATH = lib

SOURCES = \
    0Temp.cpp \
    MainActions.cpp \
    MainWindow.cpp \
    lib/CSingleInstance.cpp \
    lib/CWindow.cpp \
    lib/libsocket.cpp \
    main.cpp \

DISTFILES = \
    install.sh \
    meson.build \

HEADERS += \
    MainWindow.h \
    lib/CSingleInstance.h \
    lib/CWindow.h \
    lib/libsocket.h

