cmake_minimum_required(VERSION 3.19)
project(Quantnet_Cplusplus)

set(CMAKE_CXX_STANDARD 14)

include_directories(Level_1/Homework/Section_1_7/Exercise_1)

add_executable(Quantnet_Cplusplus
        Level_2/Homework/Section_1_7/Exercise_1/test_Swap.c
        Level_2/Homework/Section_1_7/Exercise_1/Defs.h)
