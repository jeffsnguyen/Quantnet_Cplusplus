cmake_minimum_required(VERSION 3.19)
project(Quantnet_Cplusplus)

set(CMAKE_CXX_STANDARD 14)

include_directories(Level_5/Homework/Section_3_6/Exercise_2)

add_executable(Quantnet_Cplusplus
        Level_5/Homework/Section_3_6/Exercise_2/test_ArrayException.cpp)
