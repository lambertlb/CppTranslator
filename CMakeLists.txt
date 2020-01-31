cmake_minimum_required(VERSION 3.10)

# set the project name
project(DotNetLibrarySupport)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_VERBOSE_MAKEFILE ON)
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(./DotNetLibrary)
add_subdirectory(./DotNetLibrarySupport)
add_subdirectory(./InitgrationTest)

enable_testing()
add_subdirectory(./DotnetLibraryTests)

