cmake_minimum_required(VERSION 3.10)

project(Hash_Tests)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

FILE(GLOB InputTestFiles tests/*)

add_library(hash STATIC hash.cc)
target_include_directories(hash PRIVATE . )

add_executable(
    Tests
    ${InputTestFiles}
)
target_include_directories(Tests PRIVATE . )

target_link_libraries(
    Tests
    hash
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(Tests)