# Specify the minimum version for CMake

cmake_minimum_required(VERSION 3.11)

# Project's name

project(hello)
# Set the output folder where your program will be created
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(RUNTIME_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(ARCHIVE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# The following folder will be included
include_directories("${PROJECT_SOURCE_DIR}")

# For vscode, turn on compile_commands.json generation
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Specify the executable file name
add_executable(hello ${PROJECT_SOURCE_DIR}/src/bitmath.cpp ${PROJECT_SOURCE_DIR}/src/main.cpp)
