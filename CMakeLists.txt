cmake_minimum_required(VERSION 3.19)
project(Quantnet_Cplusplus)

set(CMAKE_CXX_STANDARD 14)

include_directories(Level_7/Homework/Exercise_3)

add_executable(Quantnet_Cplusplus
        Level_7/Homework/Exercise_3/test_STLalgo.cpp)
