cmake_minimum_required(VERSION 3.26)
project(hw2 C)

set(CMAKE_C_STANDARD 11)

add_library(hw2 library.c library.h hw2.c hw2.h)
