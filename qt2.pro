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
    need_save.h \
    selectpart.h \
    capturescreen.h \
    show_background.h

SOURCES += \
        main.cpp \
        mainwindow.cpp \
        src/advance_img.cpp \
        src/basic_img.cpp \
        src/camera/camshift.cpp \
        src/camera/face_detection.cpp \
        src/camera/optical_flow.cpp \
        src/fisheye/fisheye.cpp \
    selectpart.cpp \
    capturescreen.cpp \
    select_pic_first.cpp \
    need_save.cpp \
    show_background.cpp

FORMS += \
        mainwindow.ui \
    select_pic_first.ui \
    need_save.ui

DISTFILES += \
    ../../../../usr/local/Cellar/opencv/3.3.1_1/lib/libopencv_imgcodecs.3.3.1.dylib

INCLUDEPATH += /usr/local/Cellar/opencv/3.3.1_1/include\
               include

QMAKE_MAC_SDK = macosx10.11
QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.10

LIBS += -L/usr/local/lib \
     -lopencv_core \
     -lopencv_face \
     -lopencv_dnn \
     -lopencv_ccalib \
     -lopencv_datasets \
     -lopencv_fuzzy \
     -lopencv_img_hash \
     -lopencv_ml \
     -lopencv_optflow \
     -lopencv_photo \
     -lopencv_plot \
     -lopencv_reg \
     -lopencv_saliency \
     -lopencv_shape \
     -lopencv_stitching \
     -lopencv_surface_matching \
     -lopencv_text \
     -lopencv_tracking \
     -lopencv_videoio \
     -lopencv_xfeatures2d \
     -lopencv_ximgproc \
     -lopencv_xobjdetect \
     -lopencv_xphoto \
     -lopencv_imgproc \
     -lopencv_features2d\
     -lopencv_highgui\
     -lopencv_imgcodecs\
     -lopencv_aruco \
     -lopencv_bgsegm \
     -lopencv_bioinspired \
     -lopencv_calib3d \
     -lopencv_dpm \
     -lopencv_flann \
     -lopencv_imgcodecs \
     -lopencv_imgproc \
     -lopencv_line_descriptor \
     -lopencv_objdetect \
     -lopencv_phase_unwrapping \
     -lopencv_rgbd \
     -lopencv_stereo \
     -lopencv_structured_light \
     -lopencv_superres \
     -lopencv_video \
     -lopencv_videostab \
     -v
