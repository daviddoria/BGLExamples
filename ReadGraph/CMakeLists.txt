cmake_minimum_required(VERSION 2.6)

project(ReadGraph)

find_package(Boost 1.46 COMPONENTS graph )

include_directories(${INCLUDE_DIRECTORIES} ${Boost_INCLUDE_DIRS})

# add_executable(ReadGraph ReadGraph.cpp)
# target_link_libraries(ReadGraph ${Boost_LIBRARIES})

add_executable(FixInput FixInput.cpp)
target_link_libraries(FixInput ${Boost_LIBRARIES})
