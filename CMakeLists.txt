cmake_minimum_required(VERSION 3.23) # Specify CMake version.
project(Proj) # A project name. This can be anything.
set(CMAKE_CXX_STANDARD 20) # C++ version
include_directories(${CMAKE_SOURCE_DIR})
add_executable(Proj main.cpp plane.cpp plane.h initializer.h initializer.cpp instructions.cpp instructions.h)