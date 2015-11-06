#-------------------------------------------------
#
# Project created by QtCreator 2015-11-06T13:06:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TransponerMatriz
TEMPLATE = app


SOURCES += main.cpp\
        Widget.cpp \
    DoubleSpinBoxDelegate.cpp

HEADERS  += Widget.h \
    DoubleSpinBoxDelegate.h

FORMS    += Widget.ui

QMAKE_CXXFLAGS += -std=gnu++14
