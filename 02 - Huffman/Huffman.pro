TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    compressao.c \
    descompressao.c \
    filaprioridade.c \
    frequencia.c

HEADERS += \
    compressao.h \
    descompressao.h \
    filaprioridade.h \
    frequencia.h
