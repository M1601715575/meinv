cmake_minimum_required(VERSION 2.8)

project(dispaly_image)

set(CMAKE_CXX_STANDARD 11)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(display_image display_image.cc)

target_link_libraries(display_image ${OpenCV_LIBS})
