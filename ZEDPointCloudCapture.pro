#-------------------------------------------------
#
# Project created by QtCreator 2017-06-14T03:32:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ZEDPointCloudCapture
TEMPLATE = app


SOURCES += src/main.cpp\
        src/mainwindow.cpp \
    streamwindow.cpp

HEADERS  += mainwindow.h \
    streamwindow.h

FORMS    += forms/mainwindow.ui \
            forms/colorstream.ui \
            forms/depthstream.ui \
    streamwindow.ui
