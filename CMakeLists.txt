cmake_minimum_required(VERSION 3.29)
project(MERGESORT)

set(CMAKE_CXX_STANDARD 26)

add_executable(MERGESORT main.cpp
        MergeSort.cpp
        MergeSort.h)
