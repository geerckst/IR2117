cmake_minimum_requiered(VERSION 2.6)
project(tests)

find_package(GTest REQUIRED)
include_directorie(${GTEST_INCLUDE_DIRS})

add_executable(tests.cpp functions.cpp)
target_link_libraries(tests ${})
