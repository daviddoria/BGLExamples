cmake_minimum_required(VERSION 2.6)

project(RelabelInputVertices)

find_package(Boost 1.46 COMPONENTS graph)

include_directories(${Boost_INCLUDE_DIRS})

# ADD_EXECUTABLE(ReadGraph ReadGraph.cpp)
# target_link_libraries(ReadGraph boost_graph)

add_executable(RelabelInputVertices RelabelInputVertices.cpp)
target_link_libraries(RelabelInputVertices ${Boost_LIBRARIES})
