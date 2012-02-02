cmake_minimum_required(VERSION 2.6)

project(DynamicProperty)

set(Boost_USE_MULTITHREADED ON) # which is the default
find_package(Boost 1.46)

include_directories(${Boost_INCLUDE_DIRS})

add_executable(DynamicProperty DynamicProperty.cpp)
