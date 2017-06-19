cmake_minimum_required(VERSION 3.7)
project(LeetCode)

set(CMAKE_CXX_STANDARD 11)

link_directories(/usr/local/lib)
include_directories(/usr/local/include ${PROJECT_SOURCE_DIR})

add_subdirectory(libs/googletest)

include_directories(libs/googletest/include)

file(GLOB SRC [1-9]*.*.cpp)

add_executable(Test ${SRC})
target_link_libraries(Test gtest_main gtest gmock)