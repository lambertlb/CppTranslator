cmake_minimum_required(VERSION 3.10)

# set the project name
project(DotNetLibrary)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_VERBOSE_MAKEFILE ON)
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
IF(MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
    add_definitions(-D_USRDLL -DUNICODE -D_UNICODE)
ENDIF()
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(../PlatformSupport)

# add the library
add_library(DotNetLibrary SHARED
src/Array.cpp
src/BooleanValue.cpp
src/BitConverter.cpp
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

target_link_libraries(
	DotNetLibrary
	PlatformSupport
)
target_compile_definitions(DotNetLibrary PRIVATE DOTNETLIBRARY_EXPORTS)
IF(MSVC)
   SET_TARGET_PROPERTIES(DotNetLibrary PROPERTIES LINK_FLAGS "/MAP")
ENDIF()
