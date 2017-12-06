cmake_minimum_required(VERSION 3.9)
project(IPP)

set(CMAKE_CXX_STANDARD 17)

add_executable(opencv ForTest.cpp include/IPP_World.h include/basic_img.h src/basic_img.cpp include/IPP_USAGE.h include/advance_img.h include/video.h include/camera.h src/advance_img.cpp src/camera.cpp src/video.cpp)

find_package(opencv)
include_directories( ${OpenCV_INCLUDE_DIRS} include)
target_link_libraries( opencv ${OpenCV_LIBS} )