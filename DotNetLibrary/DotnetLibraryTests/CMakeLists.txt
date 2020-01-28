cmake_minimum_required(VERSION 3.10)

# set the project name
project(DotNetLibraryTests)
set(CMAKE_VERBOSE_MAKEFILE ON)
find_package(GTest REQUIRED)

include_directories(../include)

# add the executable
add_executable(DotNetLibraryTests
	ArrayTests.cpp
	BooleanTests.cpp
	BufferTests.cpp
	ByteTests.cpp
	CharTests.cpp
	DateTimeTests.cpp
	DoubleTests.cpp
	Int16Tests.cpp
	Int32Tests.cpp
	Int64Tests.cpp
	MathTests.cpp
	SByteTests.cpp
	SingleTests.cpp
	StringBuilderTests.cpp
	StringTests.cpp
	TimeSpanTests.cpp
	UInt16Tests.cpp
	UInt32Tests.cpp
	UInt64Tests.cpp
)

target_link_libraries(
	DotNetLibraryTests
	DotNetLibrary
	GTest::GTest
	GTest::Main
)

add_test(NAME DotNetLibraryTests COMMAND $<TARGET_FILE:DotNetLibraryTests>)
