cmake_minimum_required(VERSION 2.6)

project(GridGraphProperties)

set(Boost_USE_MULTITHREADED ON)
find_package(Boost 1.46)

include_directories(${Boost_INCLUDE_DIRS})

ADD_EXECUTABLE(GridGraphProperties GridGraphProperties.cpp)

