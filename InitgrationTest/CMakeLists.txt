cmake_minimum_required(VERSION 3.10)

# set the project name
project(IntegrationTest)

set(CMAKE_VERBOSE_MAKEFILE ON)
include_directories(../DotNetLibrary/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Tests/generated)

# add the executable
add_executable(IntegrationTest
Tests/generated/CaBlock.cpp
InitgrationTest.cpp
)

target_link_libraries(
	IntegrationTest
	DotNetLibrary
)
