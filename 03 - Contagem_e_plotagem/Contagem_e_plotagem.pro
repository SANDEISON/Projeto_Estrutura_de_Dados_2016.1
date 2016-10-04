TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    avl.c \
    arvoreBinaria.c \
    menus.c

DISTFILES += \
    script.r

HEADERS += \
    avl.h \
    arvoreBinaria.h \
    menus.h
