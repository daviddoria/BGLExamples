cmake_minimum_required(VERSION 2.6)

project(SetAllWeights)

find_package(Boost 1.46)

include_directories(${Boost_INCLUDE_DIRS})

add_executable(SetAllWeights SetAllWeights.cpp)
