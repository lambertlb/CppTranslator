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

# add the library
add_library(PlatformSupport SHARED
PlatformSupport.cpp
dllmain.cpp
)
target_compile_definitions(PlatformSupport PRIVATE PLATFORMSUPPORT_EXPORTS)
IF(MSVC)
   SET_TARGET_PROPERTIES(PlatformSupport PROPERTIES LINK_FLAGS "/MAP")
ENDIF()
