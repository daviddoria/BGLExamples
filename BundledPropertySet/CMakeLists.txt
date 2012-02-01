cmake_minimum_required(VERSION 2.6)

project(BundledPropertySet)

find_package(Boost)

include_directories(${INCLUDE_DIRECTORIES} ${Boost_INCLUDE_DIRS})

add_executable(BundledPropertySet BundledPropertySet.cpp)


