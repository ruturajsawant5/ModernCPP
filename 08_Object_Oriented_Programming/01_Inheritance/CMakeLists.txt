# Specify the minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Set the project name
project(MyProject)

# Specify the source files
set(SOURCES
        Account.cpp
        Checking.cpp
        Savings.cpp
        main.cpp
)

# Create the executable from the source files
add_executable(MyExecutable ${SOURCES})

# Optionally, specify the C++ standard
set_target_properties(MyExecutable PROPERTIES CXX_STANDARD 11)  # or any C++ standard you prefer
