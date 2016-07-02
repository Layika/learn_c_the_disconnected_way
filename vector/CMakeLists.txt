cmake_minimum_required(VERSION 3.5)
project(vector)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c11")

set(COMMON_FILES array.c)

set(TEST_FILES test.c test_main.c)

set (MAIN_FILES main.c)

add_executable(tests ${TEST_FILES} ${COMMON_FILES})
add_executable(vector ${MAIN_FILES} ${COMMON_FILES})