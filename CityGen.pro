QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CityGen
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    OpenSimplex.cpp \
    roadgen.cpp

HEADERS  += mainwindow.h \
    featuregenerator.h \
    OpenSimplex.h \
    roadgen.h \
    generator.h \
    utility.h

FORMS    += mainwindow.ui
