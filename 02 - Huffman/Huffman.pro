TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    compressao.c \
    descompressao.c \
    hash.c \
    heap.c

HEADERS += \
    compressao.h \
    descompressao.h \
    hash.h \
    heap.h
