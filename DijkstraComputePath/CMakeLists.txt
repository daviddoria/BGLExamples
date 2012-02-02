cmake_minimum_required(VERSION 2.6)

project(DijkstraComputePath)

set(Boost_USE_MULTITHREADED ON)
find_package(Boost 1.46)

INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})

ADD_EXECUTABLE(DijkstraComputePath DijkstraComputePath.cpp)
