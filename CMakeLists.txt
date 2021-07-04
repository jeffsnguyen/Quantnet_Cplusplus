cmake_minimum_required(VERSION 3.19)
project(Quantnet_Cplusplus)

set(CMAKE_CXX_STANDARD 14)

include_directories(Level_7/Homework/Exercise_1)

add_executable(Quantnet_Cplusplus
        Level_7/Homework/Exercise_1/test_STLcontainers.cpp)
