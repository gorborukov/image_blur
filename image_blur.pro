#-------------------------------------------------
#
# Project created by QtCreator 2014-06-16T22:14:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = image_blur
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

INCLUDEPATH += /usr/local/Cellar/opencv/2.4.9/include
INCLUDEPATH += /usr/local/Cellar/opencv/2.4.9/include/opencv
INCLUDEPATH += /usr/local/Cellar/opencv/2.4.9/include/opencv2
LIBS += -L/usr/local/Cellar/opencv/2.4.9/lib

LIBS += -lopencv_core
LIBS += -lopencv_imgproc
LIBS += -lopencv_highgui
LIBS += -lopencv_ml
LIBS += -lopencv_video
LIBS += -lopencv_features2d
LIBS += -lopencv_calib3d
LIBS += -lopencv_objdetect
LIBS += -lopencv_contrib
LIBS += -lopencv_legacy
LIBS += -lopencv_flann
LIBS += -lopencv_nonfree
