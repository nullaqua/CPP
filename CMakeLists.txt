cmake_minimum_required(VERSION 3.21)
project(test)

set(CMAKE_CXX_STANDARD 14)
MATH(EXPR stack_size "1024*1024*1024")
set(CMAKE_EXE_LINKER_FLAGS "-Wl,--stack,${stack_size}")

add_executable(work ./P3834.cpp)
add_executable(CF913E CF913E.cpp)
add_executable(CF920E CF920E.cpp)
add_executable(cyclepath 1121/cyclepath.cpp)
add_executable(_temp _temp.cpp)