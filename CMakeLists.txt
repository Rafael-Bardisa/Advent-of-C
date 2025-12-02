cmake_minimum_required(VERSION 3.21...4.0)

project(AdventofC)


set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_C_STANDARD_COMPILER gcc)

file(TO_CMAKE_PATH "${PROJECT_BINARY_DIR}/CMakeLists.txt" LOC_PATH)
if(EXISTS "${LOC_PATH}")
message(FATAL_ERROR "You cannot build in a source directory (or any directory with a CMakeLists.txt file). Please make a build subdirectory. Feel free to remove CMakeCache.txt and CMakeFiles.")
endif()



add_subdirectory(day1)