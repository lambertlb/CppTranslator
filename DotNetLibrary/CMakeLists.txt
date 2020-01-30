cmake_minimum_required(VERSION 3.10)

# set the project name
project(DotNetLibrary)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_VERBOSE_MAKEFILE ON)
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
add_definitions(-DDOTNETLIBRARY_EXPORTS -D_CRT_SECURE_NO_WARNINGS)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# add the executable
add_library(DotNetLibrary SHARED
src/Array.cpp
src/BooleanValue.cpp
src/Buffer.cpp
src/ByteValue.cpp
src/CharEnumerator.cpp
src/CharValue.cpp
src/DateTimeValue.cpp
src/DotNetMath.cpp
src/DoubleValue.cpp
src/Int16Value.cpp
src/Int32Value.cpp
src/Int64Value.cpp
src/Object.cpp
src/SByteValue.cpp
src/SingleValue.cpp
src/StringBuilder.cpp
src/StringDotNet.cpp
src/TimeSpanValue.cpp
src/UInt16Value.cpp
src/UInt32Value.cpp
src/UInt64Value.cpp
dllmain.cpp
)

add_subdirectory(./InitgrationTest)

enable_testing()
add_subdirectory(./DotnetLibraryTests)

