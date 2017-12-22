#-------------------------------------------------
#
# Project created by QtCreator 2017-12-06T23:40:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qt2
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
        mainwindow.h \
        include/advance_img.h \
        include/basic_img.h \
        include/camera.h \
        include/IPP_Core.h \
        include/IPP_World.h \
        include/video.h \
        include/camera/camshift.h \
        include/camera/face_detection.h \
        include/camera/optical_flow.h \
        include/video/fisheye.h \
    select_pic_first.h \
    need_save.h

SOURCES += \
        main.cpp \
        mainwindow.cpp \
        #src/advance_img.cpp \
        src/basic_img.cpp \
        #src/camera/camshift.cpp \
        #src/camera/face_detection.cpp \
        #src/camera/optical_flow.cpp \
        #src/fisheye/fisheye.cpp
    select_pic_first.cpp \
    need_save.cpp

FORMS += \
        mainwindow.ui \
    select_pic_first.ui \
    need_save.ui

DISTFILES += \
    ../../../../usr/local/Cellar/opencv/3.3.1_1/lib/libopencv_imgcodecs.3.3.1.dylib

INCLUDEPATH += /usr/local/Cellar/opencv/3.3.1_1/include\
               include

LIBS += -L/usr/local/lib \
     -lopencv_core \
     -lopencv_imgproc \
     -lopencv_features2d\
     -lopencv_highgui\
     -lopencv_imgcodecs\
     -v