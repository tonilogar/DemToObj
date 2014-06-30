#-------------------------------------------------
#
# Project created by QtCreator 2014-06-17T09:43:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DemToObj
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    coordinate_xyz.cpp \
    readcoordinates_txt.cpp \
    createobj.cpp

HEADERS  += mainwindow.h \
    coordinate_xyz.h \
    readcoordinates_txt.h \
    createobj.h

FORMS    += mainwindow.ui
