cmake_minimum_required(VERSION 2.6)

project(CustomVisitor)

set(Boost_USE_MULTITHREADED ON)
find_package(Boost 1.38)

include_directories(${INCLUDE_DIRECTORIES} ${Boost_INCLUDE_DIRS})

add_executable(CustomVisitor CustomVisitor.cpp)
