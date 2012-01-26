cmake_minimum_required(VERSION 2.6)

Project(d_ary_heap)

set(Boost_USE_MULTITHREADED ON)
FIND_PACKAGE(Boost 1.38 COMPONENTS)

INCLUDE_DIRECTORIES(${INCLUDE_DIRECTORIES} ${Boost_INCLUDE_DIRS})
LINK_DIRECTORIES(${LINK_DIRECTORIES} ${Boost_LIBRARY_DIRS})

ADD_EXECUTABLE(grid_graph grid_graph.cpp)
#target_link_libraries(WriteGraph boost_graph)

