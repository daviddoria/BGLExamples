cmake_minimum_required(VERSION 2.6)

project(ExteriorProperty)

set(Boost_USE_MULTITHREADED ON) # which is the default
find_package(Boost 1.46)

include_directories(${Boost_INCLUDE_DIRS})

add_executable(ExteriorProperty ExteriorProperty.cpp)
