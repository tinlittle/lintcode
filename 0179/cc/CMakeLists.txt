cmake_minimum_required(VERSION 3.11.0)
project(hello VERSION 0.1.0)

include(CTest)
enable_testing()

# The following folder will be included
include_directories("${PROJECT_SOURCE_DIR}/src")

add_executable(hello ${PROJECT_SOURCE_DIR}/src/main.cpp ${PROJECT_SOURCE_DIR}/src/setBits.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
