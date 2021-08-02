cmake_minimum_required(VERSION 3.19)
project(Quantnet_Cplusplus)

set(CMAKE_CXX_STANDARD 14)

include_directories(Level_8/Homework/Exercise_1)

add_executable(Quantnet_Cplusplus
        Level_8/Homework/Exercise_1/test_smartPointers.cpp)

message(STATUS "start running cmake...")

find_package(Boost 1.76.0 COMPONENTS system filesystem REQUIRED)

if(Boost_FOUND)

    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
    message(STATUS "Boost_VERSION: ${Boost_VERSION}")

    include_directories(${Boost_INCLUDE_DIRS})

endif()
