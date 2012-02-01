cmake_minimum_required(VERSION 2.6)

project(CopyGraph)

find_package(Boost 1.46 COMPONENTS graph)

include_directories(${Boost_INCLUDE_DIRS})

add_executable(CopyGraph CopyGraph.cpp)
#target_link_libraries(CopyGraph ${Boost_LIBRARIES})

