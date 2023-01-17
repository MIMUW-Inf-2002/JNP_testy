cmake_minimum_required(VERSION 3.18)
project(JNP_Testy_07_images)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic -O2")

include_directories(., src)

add_library(coordinate
        src/coordinate.h
        src/coordinate.cc)

add_library(color
        src/color.h
        src/color.cc)

add_library(bmp
        src/bmp.h
        src/bmp.cc)

add_library(functional
        functional.h
        functional.cc)

add_library(images
        images.h
        images.cc)

add_executable(example
        src/example.cc)

add_executable(diff_bmp
        src/diff_bmp.cc)

add_executable(image_test
        src/fib_test.h
        src/test.cc)

target_link_libraries(example coordinate)
target_link_libraries(example color)
target_link_libraries(example bmp)
target_link_libraries(example functional)
target_link_libraries(example images)

target_link_libraries(image_test coordinate)
target_link_libraries(image_test color)
target_link_libraries(image_test bmp)
target_link_libraries(image_test functional)
target_link_libraries(image_test images)
