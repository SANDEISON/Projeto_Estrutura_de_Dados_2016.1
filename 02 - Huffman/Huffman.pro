TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    compressao.c \
    descompressao.c \
    fila_prioridade.c \
    hash.c

HEADERS += \
    compressao.h \
    descompressao.h \
    fila_prioridade.h \
    hash.h
