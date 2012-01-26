cmake_minimum_required(VERSION 2.6)

Project(FilteredGraph)

set(Boost_USE_MULTITHREADED ON)
FIND_PACKAGE(Boost 1.38 COMPONENTS )

INCLUDE_DIRECTORIES(${INCLUDE_DIRECTORIES} ${Boost_INCLUDE_DIRS})
LINK_DIRECTORIES(${LINK_DIRECTORIES} ${Boost_LIBRARY_DIRS})

ADD_EXECUTABLE(FilteredVertices FilteredVertices.cpp)

ADD_EXECUTABLE(FilteredEdges FilteredEdges.cpp)

ADD_EXECUTABLE(FilteredGridGraph FilteredGridGraph.cpp)