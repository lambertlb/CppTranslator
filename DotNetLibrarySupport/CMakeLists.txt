cmake_minimum_required(VERSION 3.10)

# set the project name
project(DotNetLibrarySupport)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_VERBOSE_MAKEFILE ON)
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
IF(MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
    add_definitions(-D_USRDLL -DUNICODE -D_UNICODE)
ENDIF()
include_directories(../DotNetLibrary/include)
include_directories(../DotNetLibrarySupport)

# add the executable
add_library(DotNetLibrarySupport SHARED
DotNetLibrarySupport.cpp
dllmain.cpp
)
target_compile_definitions(DotNetLibrarySupport PRIVATE DOTNETLIBRARYSUPPORT_EXPORTS)
IF(MSVC)
   SET_TARGET_PROPERTIES(DotNetLibrarySupport PROPERTIES LINK_FLAGS "/MAP")
ENDIF()
target_link_libraries(
	DotNetLibrarySupport
	DotNetLibrary
)
