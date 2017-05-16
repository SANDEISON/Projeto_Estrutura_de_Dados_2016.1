TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    avl.c \
    cp.c \
    list.c

DISTFILES += \
    script.r

HEADERS += \
    cp.h
