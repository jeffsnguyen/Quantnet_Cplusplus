cmake_minimum_required(VERSION 3.19)
project(Quantnet_Cplusplus)

set(CMAKE_CXX_STANDARD 14)

include_directories(Level_4/Homework/Section_2_4/Exercise_1)

add_executable(Quantnet_Cplusplus
        Level_4/Homework/Section_2_4/Exercise_1/test_Operators.cpp)
