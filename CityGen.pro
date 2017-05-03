QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CityGen
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    OpenSimplex.cpp \
    roadgen.cpp \
    cellnoise.cpp \
    utility.cpp \
    noise.cpp \
    FastNoise.cpp

HEADERS  += mainwindow.h \
    featuregenerator.h \
    OpenSimplex.h \
    roadgen.h \
    generator.h \
    utility.h \
    noise.h \
    cellnoise.h \
    FastNoise.h

FORMS    += mainwindow.ui
