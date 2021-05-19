cmake_minimum_required(VERSION 3.19)
project(Quantnet_Cplusplus)

set(CMAKE_CXX_STANDARD 14)

include_directories(Level_1/Lecture/1_1)

add_executable(Quantnet_Cplusplus
        Level_1/Lecture/1_1/Hello.cpp
        Level_1/Lecture/1_1/Hello.hpp
        Level_1/Lecture/1_1/TestHello.cpp)
