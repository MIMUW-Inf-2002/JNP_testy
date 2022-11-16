cmake_minimum_required(VERSION 3.10)

project(Moneybag_Tests)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -O2")

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
FILE(GLOB UserImplementationFiles *.cc)

add_executable(
    Tests
    ${InputTestFiles}
    ${UserImplementationFiles}
)

target_include_directories(Tests PUBLIC .)

target_link_libraries(
    Tests
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(Tests)
