cmake_minimum_required(VERSION 3.10)

# set the project name
project(integrationTest)

set(CMAKE_VERBOSE_MAKEFILE ON)
include_directories(../DotNetLibrary/include)
include_directories(../DotNetLibrarySupport)
include_directories(../PlatformSupport)
include_directories(../Debug/generated)

# add the executable
add_executable(integrationTest
IntegrationTest.cpp
../Debug/generated/Translated.cpp
)

target_link_libraries(
	integrationTest
	DotNetLibrary
	DotNetLibrarySupport
	PlatformSupport
)
