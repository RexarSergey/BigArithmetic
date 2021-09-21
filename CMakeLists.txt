cmake_minimum_required(VERSION 3.20)
project(BigArithmetic)

set(CMAKE_CXX_STANDARD 20)

add_executable(BigArithmetic main.cpp BA.h BA.cpp)

add_subdirectory(Tests)