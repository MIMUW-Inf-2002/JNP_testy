cmake_minimum_required(VERSION 3.18)
project(JNP_Testy_07_images)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic -O2")

include_directories(.)

add_library(coordinate
        coordinate.h
        coordinate.cc)

add_library(color
        color.h
        color.cc)

add_library(bmp
        bmp.h
        bmp.cc)

add_library(functional
        functional.h
        functional.cc)

add_library(images
        images.h
        images.cc)

add_executable(example
        example.cc)

add_executable(diff_bmp
        diff_bmp.cc)

add_executable(image_test
        fib_test.h
        test.cc)

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
