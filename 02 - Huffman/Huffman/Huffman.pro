TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    compressao.c \
    descompressao.c \
    hash.c \
    fila_prioridade.c

HEADERS += \
    compressao.h \
    descompressao.h \
    hash.h \
    fila_prioridade.h
