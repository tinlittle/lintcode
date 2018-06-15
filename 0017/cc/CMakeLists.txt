cmake_minimum_required(VERSION 3.11.0)
project(hello VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(CTest)
enable_testing()

# The following folder will be included
include_directories("${PROJECT_SOURCE_DIR}/src")

add_executable(hello ${PROJECT_SOURCE_DIR}/src/main.cc)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
