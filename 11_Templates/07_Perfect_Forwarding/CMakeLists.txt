# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Set the project name
project(MyProject)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)

# Add the source files to the project
add_executable(MyProject main.cpp Integer.cpp)
