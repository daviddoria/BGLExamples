cmake_minimum_required(VERSION 2.6)

project(WriteGraph)

set(Boost_USE_MULTITHREADED ON)
find_package(Boost 1.46 COMPONENTS program_options graph)

include_directories( ${Boost_INCLUDE_DIRS} )

add_executable(WriteGraph WriteGraph.cpp)
target_link_libraries(WriteGraph ${Boost_LIBRARIES})

