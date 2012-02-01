cmake_minimum_required(VERSION 2.6)

project(AdjacentVertices)

set(Boost_USE_MULTITHREADED ON)
find_package(Boost 1.38 COMPONENTS required)

include_directories(${Boost_INCLUDE_DIRS})

add_executable(AdjacentVertices AdjacentVertices.cpp)


