cmake_minimum_required(VERSION 2.6)

project(Simple)

set(Boost_USE_MULTITHREADED ON)
find_package(Boost 1.46)

include_directories(${Boost_INCLUDE_DIRS})

add_executable(Simple Simple.cpp)
# add_executable(CreateDirectedGraph CreateDirectedGraph.cpp)
