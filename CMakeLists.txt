cmake_minimum_required(VERSION 3.19)
project(Quantnet_Cplusplus)

set(CMAKE_CXX_STANDARD 14)

include_directories(Level_6/Homework/Section_4_2_b/Exercise_5)

add_executable(Quantnet_Cplusplus
        Level_6/Homework/Section_4_2_b/Exercise_5/test_StackException.cpp)
