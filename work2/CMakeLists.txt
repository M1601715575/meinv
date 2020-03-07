cmake_minimum_required(VERSION 2.8)

project(edge)

set(CMAKE_CXX_STANDARD 11)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(edge edge.cc)

target_link_libraries(edge ${OpenCV_LIBS})
