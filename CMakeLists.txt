cmake_minimum_required(VERSION 3.21)
project(test)

set(CMAKE_CXX_STANDARD 14)
MATH(EXPR stack_size "1024*1024*1024")
set(CMAKE_EXE_LINKER_FLAGS "-Wl,--stack,${stack_size}")

add_executable(U91718 U91718.cpp)
add_executable(U87176 U87176.cpp)
add_executable(U128599 U128599.cpp)
add_executable(U103440 U103440.cpp)