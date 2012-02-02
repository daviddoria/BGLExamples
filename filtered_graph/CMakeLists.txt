cmake_minimum_required(VERSION 2.6)

project(FilteredGraph)

set(Boost_USE_MULTITHREADED ON)
find_package(Boost 1.46)

include_directories(${Boost_INCLUDE_DIRS})

add_executable(FilteredVertices FilteredVertices.cpp)
add_executable(FilteredEdges FilteredEdges.cpp)
add_executable(FilteredGridGraph FilteredGridGraph.cpp)
