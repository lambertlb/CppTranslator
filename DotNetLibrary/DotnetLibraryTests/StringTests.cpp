#include "gtest/gtest.h"
#include <DotnetTypes.h>

using namespace DotnetLibrary;

TEST(StringTests, ConstructorTest) {
	String	string(L"Test String");
	ASSERT_TRUE(!string.allocate);
	ASSERT_TRUE(string.get_Length() == 11);
	ASSERT_TRUE(wcscmp(string.characterData, L"Test String") == 0);
}
TEST(StringTests, Constructor2Test) {
	String	string(L"Test String 1234567890", 12, 10);
	ASSERT_TRUE(string.allocate);
	ASSERT_TRUE(string.get_Length() == 10);
	ASSERT_TRUE(wcscmp(string.characterData, L"1234567890") == 0);
}
TEST(StringTests, Constructor3Test) {
	Array array(CharType, 6);
	Char	data[] = { 'A','B', 'C', 'D', 'E', 'F' };
	array.Initialize(data);
	String	string(&array);
	ASSERT_TRUE(string.allocate);
	ASSERT_TRUE(string.get_Length() == 6);
	ASSERT_TRUE(wcscmp(string.characterData, L"ABCDEF") == 0);
}
TEST(StringTests, Constructor4Test) {
	Array array(CharType, 6);
	Char	data[] = { 'A','B', 'C', 'D', 'E', 'F' };
	array.Initialize(data);
	String	string(&array, 3, 3);
	ASSERT_TRUE(string.allocate);
	ASSERT_TRUE(string.get_Length() == 3);
	ASSERT_TRUE(wcscmp(string.characterData, L"DEF") == 0);
}
