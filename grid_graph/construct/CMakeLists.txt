cmake_minimum_required(VERSION 2.6)

project(GridGraph)

set(Boost_USE_MULTITHREADED ON)
find_package(Boost 1.46)

include_directories(${INCLUDE_DIRECTORIES} ${Boost_INCLUDE_DIRS})

add_executable(GridGraph GridGraph.cpp)
#target_link_libraries(WriteGraph ${Boost_LIBRARIES})

