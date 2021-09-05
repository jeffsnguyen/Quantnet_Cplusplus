cmake_minimum_required(VERSION 3.19)
project(Quantnet_CPP)

set(CMAKE_CXX_STANDARD 14)

include_directories(Level_9/Homework/Group_A)

add_executable(Quantnet_Cplusplus
        Level_9/Homework/Group_A/test_EuropeanOptions.cpp)

message(STATUS "start running cmake...")

find_package(Boost 1.76.0 COMPONENTS system filesystem REQUIRED)

if(Boost_FOUND)

    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
    message(STATUS "Boost_VERSION: ${Boost_VERSION}")

    include_directories(${Boost_INCLUDE_DIRS})
    link_directories(${Boost_LIBRARY_DIRS})

endif()

