#include "gtest/gtest.h"
#include <DotnetTypes.h>

using namespace DotnetLibrary;

TEST(StringTests, ConstructorTest) {
	String	string(L"Test String");
	ASSERT_TRUE(!string.IsAllocated());
	ASSERT_TRUE(string.get_Length() == 11);
	ASSERT_TRUE(wcscmp(string.get_Buffer(), L"Test String") == 0);
}
TEST(StringTests, Constructor2Test) {
	String	string(L"Test String 1234567890", 12, 10);
	ASSERT_TRUE(string.IsAllocated());
	ASSERT_TRUE(string.get_Length() == 10);
	ASSERT_TRUE(wcscmp(string.get_Buffer(), L"1234567890") == 0);
}
TEST(StringTests, Constructor3Test) {
	Array array(CharType, 6);
	Char	data[] = { 'A','B', 'C', 'D', 'E', 'F' };
	array.Initialize(data);
	String	string(&array);
	ASSERT_TRUE(string.IsAllocated());
	ASSERT_TRUE(string.get_Length() == 6);
	ASSERT_TRUE(wcscmp(string.get_Buffer(), L"ABCDEF") == 0);
}
TEST(StringTests, Constructor4Test) {
	Array array(CharType, 6);
	Char	data[] = { 'A','B', 'C', 'D', 'E', 'F' };
	array.Initialize(data);
	String	string(&array, 3, 3);
	ASSERT_TRUE(string.IsAllocated());
	ASSERT_TRUE(string.get_Length() == 3);
	ASSERT_TRUE(wcscmp(string.get_Buffer(), L"DEF") == 0);
}
TEST(StringTests, Constructor5Test) {
	String	string(L'C', 6);
	ASSERT_TRUE(string.IsAllocated());
	ASSERT_TRUE(string.get_Length() == 6);
	ASSERT_TRUE(wcscmp(string.get_Buffer(), L"CCCCCC") == 0);
}
TEST(StringTests, GetCharsTest) {
	String	string(L"Test String");
	ASSERT_TRUE(string.get_Chars(0) == L'T');
	ASSERT_TRUE(string.get_Chars(10) == L'g');
}
TEST(StringTests, GetLengthTest) {
	String	string(L"Test String");
	ASSERT_TRUE(string.get_Length() == 11);
}
TEST(StringTests, AddressTest) {
	String	string(L"Test String");
	ASSERT_TRUE(*string.Address(0) == L'T');
}
TEST(StringTests, CompareTest) {
	String	string(L"ABCDEFGHI");
	String	string2(L"ABCDEFGHI");
	ASSERT_TRUE(String::Compare(&string,&string2) == 0);
}
TEST(StringTests, Compare2Test) {
	String	string(L"ABCDEFGHI");
	String	string2(L"aBCDEFGHI");
	ASSERT_TRUE(String::Compare(&string, &string2) < 0);
}
TEST(StringTests, Compare3Test) {
	String	string(L"ABCDEFGHI");
	String	string2(L"aBCDEFGHI");
	ASSERT_TRUE(String::Compare(&string, &string2, true) == 0);
}
TEST(StringTests, Compare4Test) {
	String	string(L"1ABCDEFGHI");
	String	string2(L"ABCDEFGHI");
	ASSERT_TRUE(String::Compare(&string, &string2) < 0);
}
TEST(StringTests, Compare5Test) {
	String	string(L"1ABCDEFGHI");
	String	string2(L"ABCXXXXX");
	ASSERT_TRUE(String::Compare(&string, 1, &string2, 0 ,3) == 0);
}
TEST(StringTests, Compare6Test) {
	String	string(L"1ABCDEFGHI");
	String	string2(L"abcXXXXX");
	ASSERT_TRUE(String::Compare(&string, 1, &string2, 0, 3, true) == 0);
}
TEST(StringTests, CompareOrinalTest) {
	String	string(L"ABCDEFGHI");
	String	string2(L"ABCDEFGHI");
	ASSERT_TRUE(String::CompareOrdinal(&string, &string2) == 0);
}
TEST(StringTests, CompareOrinal2Test) {
	String	string(L"ABCDEFGHI");
	String	string2(L"aBCDEFGHI");
	ASSERT_TRUE(String::CompareOrdinal(&string, &string2) < 0);
}
TEST(StringTests, CompareOrinal3Test) {
	String	string(L"1ABCDEFGHI");
	String	string2(L"ABCXXXXX");
	ASSERT_TRUE(String::CompareOrdinal(&string, 1, &string2, 0, 3) == 0);
}
TEST(StringTests, CompareToTest) {
	String	string(L"ABCDEFGHI");
	String	string2(L"ABCDEFGHI");
	ASSERT_TRUE(string.CompareTo(&string2) == 0);
}
TEST(StringTests, CompareTo2Test) {
	String	string(L"ABCDEFGHI");
	ASSERT_TRUE(string.CompareTo((String*)nullptr) == 1);
}
TEST(StringTests, CompareTo3Test) {
	String	string(L"ABCDEFGHI");
	String	string2(L"ABCDEFGHI");
	ASSERT_TRUE(string.CompareTo((Object*)&string2) == 0);
}
TEST(StringTests, ConcatTest) {
	String	string(L"ABC");
	String* s2 = String::Concat(&string);
	ASSERT_TRUE(wcscmp(s2->get_Buffer(), L"ABC") == 0);
}
TEST(StringTests, Concat2Test) {
	String	string(L"ABC");
	String	string2(L"DEF");
	String	string3(L"GHI");
	String	string4(L"JKL");
	String* s2 = String::Concat(&string, &string2, &string3, &string4);
	ASSERT_TRUE(wcscmp(s2->get_Buffer(), L"ABCDEFGHIJKL") == 0);
}
TEST(StringTests, Concat3Test) {
	Array	array(ObjectType, 4);
	String	string(L"ABC");
	String	string2(L"DEF");
	String	string3(L"GHI");
	String	string4(L"JKL");
	Object*  list[4] = { &string, &string2, &string3, &string4 };
	array.Initialize(list);
	String* s2 = String::Concat(&array);
	ASSERT_TRUE(wcscmp(s2->get_Buffer(), L"ABCDEFGHIJKL") == 0);
}
TEST(StringTests, ContainsTest) {
	String	string(L"ABCDEFGHI");
	String	string2(L"ABCDEFGHI");
	ASSERT_TRUE(string.Contains(&string2));
}
TEST(StringTests, Contains2Test) {
	String	string(L"ABCDEFGHI");
	String	string2(L"DEF");
	ASSERT_TRUE(string.Contains(&string2));
}
TEST(StringTests, Contains3Test) {
	String	string(L"ABCDEFGHI");
	String	string2(L"123");
	ASSERT_TRUE(!string.Contains(&string2));
}
TEST(StringTests, CopyTest) {
	String	string(L"ABCDEFGHI");
	String*	string2 = String::Copy(&string);
	ASSERT_TRUE(wcscmp(string2->get_Buffer(), L"ABCDEFGHI") == 0);
}
TEST(StringTests, CopyToTest) {
	String	string(L"1234567890");
	Array array(CharType, 6);
	Char	data[] = { 'A','B', 'C', 'D', 'E', 'F' };
	array.Initialize(data);
	string.CopyTo(3, &array, 2, 3);
	Char* x = (Char*)array.Address(0);
	ASSERT_TRUE(wcsncmp((Char*)array.Address(0), L"AB456F", 6) == 0);
}
