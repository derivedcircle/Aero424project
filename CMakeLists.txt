cmake_minimum_required(VERSION 3.23) # Specify CMake version.
project(Proj) # A project name. This can be anything.
set(CMAKE_CXX_STANDARD 20) # C++ version
include_directories(${CMAKE_SOURCE_DIR})
add_executable(Proj main.cpp plane.h initializer.h initializer.cpp instructions.cpp instructions.h userinterface.h userinterface.cpp B737.cpp B737 B787.cpp
B787.h B767.cpp B767.h B777.cpp B777.h A220.cpp A220.h A320.cpp A320.h A330.cpp A330.h A350.cpp A350.h)