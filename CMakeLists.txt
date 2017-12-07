cmake_minimum_required(VERSION 3.9)
project(IPP)

set(CMAKE_CXX_STANDARD 17)

add_executable(opencv ForTest.cpp include/IPP_World.h include/basic_img.h src/basic_img.cpp include/IPP_Core.h include/advance_img.h include/video.h include/camera.h src/advance_img.cpp src/camera.cpp src/video.cpp include/camera/camshift.h src/camera/camshift.cpp include/camera/optical_flow.h src/camera/optical_flow.cpp include/camera/face_detection.h src/camera/face_detection.cpp)

find_package(opencv)
include_directories( ${OpenCV_INCLUDE_DIRS} include)
target_link_libraries( opencv ${OpenCV_LIBS} )