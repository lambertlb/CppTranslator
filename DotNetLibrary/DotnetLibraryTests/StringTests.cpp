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
TEST(StringTests, EndsWithTest) {
	String	string(L"ABCDEFGHI");
	String	string1(L"GHI");
	ASSERT_TRUE(string.EndsWith(&string1));
}
TEST(StringTests, EndsWith2Test) {
	String	string(L"ABCDEFGHI");
	String	string1(L"ABCDEFGHI");
	ASSERT_TRUE(string.EndsWith(&string1));
}
TEST(StringTests, EndsWith3Test) {
	String	string(L"ABCDEFGHI");
	ASSERT_TRUE(string.EndsWith(L'I'));
}
TEST(StringTests, EndsWith4Test) {
	String	string(L"");
	ASSERT_TRUE(!string.EndsWith(L'I'));
}
TEST(StringTests, EqualsTest) {
	String	string(L"ABCDEFGHI");
	ASSERT_TRUE(string.Equals(&string));
}
TEST(StringTests, Equals2Test) {
	String	string(L"ABCDEFGHI");
	String	string2(L"ABCDEFGHI");
	ASSERT_TRUE(string.Equals(&string2));
}
TEST(StringTests, Equals3Test) {
	String	string(L"ABCDEFGHI");
	String	string2(L"ABCDEFGHI");
	ASSERT_TRUE(string.Equals((Object*)&string2));
}
TEST(StringTests, Equals4Test) {
	String	string(L"ABCDEFGHI");
	String	string2(L"ABCDEFGHI");
	ASSERT_TRUE(((Object*)&string)->Equals((Object*)&string2));
}
TEST(StringTests, Equals5Test) {
	String	string(L"ABCDEFGHI");
	String	string2(L"ABCDEFGHI");
	ASSERT_TRUE(Object::Equals((Object*)&string, (Object*)&string2));
}
TEST(StringTests, Equals6Test) {
	String	string(L"ABCDEFGHI");
	String	string2(L"ABCDEFGHI");
	ASSERT_TRUE(String::Equals(&string, (Object*)&string2));
}
TEST(StringTests, GetEnumeratorTest) {
	Char* chars = L"ABCDEFGHI";
	String	string(chars);
	CharEnumerator* iter = string.GetEnumerator();
	Int32 i = 0;
	while (iter->MoveNext()) {
		ASSERT_TRUE(iter->get_Current() == chars[i++]);
	}
	i = 0;
	iter->Reset();
	while (iter->MoveNext()) {
		ASSERT_TRUE(iter->get_Current() == chars[i++]);
	}
}
TEST(StringTests, IndexOfTest) {
	String	string(L"ABCDEFGHI");
	ASSERT_TRUE(string.IndexOf(L'A') == 0);
}
TEST(StringTests, IndexOf2Test) {
	String	string(L"ABCDEFGHI");
	ASSERT_TRUE(string.IndexOf(L'I') == 8);
}
TEST(StringTests, IndexOf3Test) {
	String	string(L"ABCDEFGHI");
	ASSERT_TRUE(string.IndexOf(L'C', 2) == 2);
}
TEST(StringTests, IndexOf4Test) {
	String	string(L"ABCDEFGHI");
	ASSERT_TRUE(string.IndexOf(L'C', 2, 3) == 2);
}
TEST(StringTests, IndexOf10Test) {
	String	string(L"ABCDEFGHI");
	ASSERT_TRUE(string.IndexOf(L'C', 0, 2) == -1);
}
TEST(StringTests, IndexOf5Test) {
	String	string(L"ABCDEFGHI");
	ASSERT_TRUE(string.IndexOf(L'1') == -1);
}
TEST(StringTests, IndexOfStringTest) {
	String	string(L"ABCDEFGHI");
	String	string2(L"BCD");
	ASSERT_TRUE(string.IndexOf(&string2) == 1);
}
TEST(StringTests, IndexOfString2Test) {
	String	string(L"ABCDEFGHI");
	String	string2(L"I");
	ASSERT_TRUE(string.IndexOf(&string2, 4) == 8);
}
TEST(StringTests, IndexOfString3Test) {
	String	string(L"ABCDEFGHI");
	String	string2(L"EFG");
	ASSERT_TRUE(string.IndexOf(&string2, 2, 6) == 4);
}
TEST(StringTests, IndexOfString4Test) {
	String	string(L"ABCDEFGHI");
	String	string2(L"123");
	ASSERT_TRUE(string.IndexOf(&string2) == -1);
}
TEST(StringTests, IndexOfString5Test) {
	String	string(L"ABCDEFGHI");
	String	string2(L"ABC");
	ASSERT_TRUE(string.IndexOf(&string2, 2) == -1);
}
TEST(StringTests, IndexOfAnyTest) {
	String	string(L"12 34 56");
	Array array(CharType, 2);
	Char	data[] = { '3','4'};
	array.Initialize(data);
	ASSERT_TRUE(string.IndexOfAny(&array) == 3);
}
TEST(StringTests, IndexOfAny2Test) {
	String	string(L"12 34 56");
	Array array(CharType, 2);
	Char	data[] = { '3','4' };
	array.Initialize(data);
	ASSERT_TRUE(string.IndexOfAny(&array, 3) == 3);
}
TEST(StringTests, IndexOfAny3Test) {
	String	string(L"12 34 56");
	Array array(CharType, 2);
	Char	data[] = { 'X','3' };
	array.Initialize(data);
	ASSERT_TRUE(string.IndexOfAny(&array, 3, 2) == 3);
}
TEST(StringTests, IndexOfAny4Test) {
	String	string(L"12 34 56");
	Array array(CharType, 2);
	Char	data[] = { 'X','Y' };
	array.Initialize(data);
	ASSERT_TRUE(string.IndexOfAny(&array) == -1);
}
TEST(StringTests, InsertTest) {
	String	string(L"ABCDEFGHI");
	String	string2(L"123");
	String* newStr = string.Insert(3, &string2);
	ASSERT_TRUE(wcscmp(newStr->get_Buffer(), L"ABC123DEFGHI") == 0);
}
TEST(StringTests, Insert2Test) {
	String	string(L"ABCDEFGHI");
	String	string2(L"123");
	String* newStr = string.Insert(string.get_Length(), &string2);
	ASSERT_TRUE(wcscmp(newStr->get_Buffer(), L"ABCDEFGHI123") == 0);
}
TEST(StringTests, IsNullOrEmptyTest) {
	ASSERT_TRUE(String::IsNullOrEmpty(String::Empty));
	ASSERT_TRUE(String::IsNullOrEmpty(nullptr));
	String	string2(L"123");
	ASSERT_TRUE(!String::IsNullOrEmpty(&string2));
}
TEST(StringTests, IsNullOrWhiteSpaceTest) {
	ASSERT_TRUE(String::IsNullOrWhiteSpace(String::Empty));
	ASSERT_TRUE(String::IsNullOrWhiteSpace(nullptr));
	String	string2(L" 2 ");
	ASSERT_TRUE(!String::IsNullOrWhiteSpace(&string2));
	String	string3(L" \t ");
	ASSERT_TRUE(String::IsNullOrWhiteSpace(&string3));
}
TEST(StringTests, JoinTest) {
	Array	array(StringType, 4);
	String	string(L"ABC");
	String	string2(L"DEF");
	String	string3(L"GHI");
	String	string4(L"JKL");
	Object* list[4] = { &string, &string2, &string3, &string4 };
	array.Initialize(list);
	String separator(L",");
	String* s2 = String::Join(&separator, &array);
	ASSERT_TRUE(wcscmp(s2->get_Buffer(), L"ABC,DEF,GHI,JKL") == 0);
}
TEST(StringTests, Join2Test) {
	Array	array(StringType, 4);
	String	string(L"ABC");
	String	string2(L"DEF");
	String	string3(L"GHI");
	String	string4(L"JKL");
	Object* list[4] = { &string, &string2, &string3, &string4 };
	array.Initialize(list);
	String* s2 = String::Join(String::Empty, &array);
	ASSERT_TRUE(wcscmp(s2->get_Buffer(), L"ABCDEFGHIJKL") == 0);
}
TEST(StringTests, Join3Test) {
	Array	array(StringType, 4);
	String	string(L"ABC");
	String	string2(L"DEF");
	String	string3(L"GHI");
	String	string4(L"JKL");
	Object* list[4] = { &string, &string2, &string3, &string4 };
	array.Initialize(list);
	String separator(L",");
	String* s2 = String::Join(&separator, &array, 1);
	ASSERT_TRUE(wcscmp(s2->get_Buffer(), L"DEF,GHI,JKL") == 0);
}
TEST(StringTests, Join4Test) {
	Array	array(StringType, 4);
	String	string(L"ABC");
	String	string2(L"DEF");
	String	string3(L"GHI");
	String	string4(L"JKL");
	Object* list[4] = { &string, &string2, &string3, &string4 };
	array.Initialize(list);
	String separator(L",");
	String* s2 = String::Join(&separator, &array, 1, 2);
	ASSERT_TRUE(wcscmp(s2->get_Buffer(), L"DEF,GHI") == 0);
}
TEST(StringTests, LastIndexOfTest) {
	String	string(L"11223311");
	String subString(L"11");
	ASSERT_TRUE(string.LastIndexOf(&subString) == 6);
	ASSERT_TRUE(string.LastIndexOf(&subString, 4) == 0);
	ASSERT_TRUE(string.LastIndexOf(&subString, 4, 5) == 0);
	String subString2(L"1");
	ASSERT_TRUE(string.LastIndexOf(&subString2) == 7);
}
TEST(StringTests, LastIndexOfCharTest) {
	String	string(L"11223311");
	ASSERT_TRUE(string.LastIndexOf(L'1') == 7);
	ASSERT_TRUE(string.LastIndexOf(L'1', 4) == 1);
	ASSERT_TRUE(string.LastIndexOf(L'1', 4, 4) == 1);
}
TEST(StringTests, LastIndexOfAnyTest) {
	String	string(L"11223311");
	Array array(CharType, 2);
	Char	data[] = { '1','2' };
	array.Initialize(data);
	ASSERT_TRUE(string.LastIndexOfAny(&array) == 7);
	ASSERT_TRUE(string.LastIndexOfAny(&array, 4) == 3);
	ASSERT_TRUE(string.LastIndexOfAny(&array, 4, 4) == 3);
}
TEST(StringTests, PadLeftTest) {
	String	string(L"11223311");
	String* rtn = string.PadLeft(5);
	ASSERT_TRUE(wcscmp(rtn->get_Buffer(), L"     11223311") == 0);
	String* rtn2 = string.PadLeft(5, L'-');
	ASSERT_TRUE(wcscmp(rtn2->get_Buffer(), L"-----11223311") == 0);
}
TEST(StringTests, PadRightTest) {
	String	string(L"11223311");
	String* rtn = string.PadRight(5);
	ASSERT_TRUE(wcscmp(rtn->get_Buffer(), L"11223311     ") == 0);
	String* rtn2 = string.PadRight(5, L'-');
	ASSERT_TRUE(wcscmp(rtn2->get_Buffer(), L"11223311-----") == 0);
}
TEST(StringTests, RemoveTest) {
	String	string(L"11223311");
	String* rtn = string.Remove(2,2);
	ASSERT_TRUE(wcscmp(rtn->get_Buffer(), L"113311") == 0);
	String* rtn2 = string.Remove(6, 2);
	ASSERT_TRUE(wcscmp(rtn2->get_Buffer(), L"112233") == 0);
	String* rtn3 = string.Remove(0, 2);
	ASSERT_TRUE(wcscmp(rtn3->get_Buffer(), L"223311") == 0);
}
TEST(StringTests, ReplaceCharTest) {
	String	string(L"11223311");
	String* rtn = string.Replace(L'1', L'A');
	ASSERT_TRUE(wcscmp(rtn->get_Buffer(), L"AA2233AA") == 0);
}
TEST(StringTests, ReplaceStringTest) {
	String	string(L"11223311");
	String	search(L"11");
	String	replacement(L"ZZ");
	String* rtn = string.Replace(&search, &replacement);
	ASSERT_TRUE(wcscmp(rtn->get_Buffer(), L"ZZ2233ZZ") == 0);
}
TEST(StringTests, StartWithTest) {
	String	string(L"11223311");
	String	search(L"11");
	ASSERT_TRUE(string.StartsWith(&search));
	String	search2(L"22");
	ASSERT_TRUE(!string.StartsWith(&search2));
}
TEST(StringTests, SubStringTest) {
	String	string(L"11223311");
	String* str1 = string.Substring(2);
	ASSERT_TRUE(wcscmp(str1->get_Buffer(), L"223311") == 0);
	String* str2 = string.Substring(6,2);
	ASSERT_TRUE(wcscmp(str2->get_Buffer(), L"11") == 0);
}
TEST(StringTests, ToCharArrayTest) {
	String	string(L"11223311");
	Array* array = string.ToCharArray();
	ASSERT_TRUE(array != nullptr);
	ASSERT_TRUE(array->get_Length() == string.get_Length());
	ASSERT_TRUE(*(Char*)array->Address(1) == string.get_Chars(1));
	ASSERT_TRUE(*(Char*)array->Address(7) == string.get_Chars(7));
}
TEST(StringTests, ToCharArray2Test) {
	String	string(L"11223311");
	Array* array = string.ToCharArray(4, 2);
	ASSERT_TRUE(array != nullptr);
	ASSERT_TRUE(array->get_Length() == 2);
	ASSERT_TRUE(*(Char*)array->Address(0) == L'3');
	ASSERT_TRUE(*(Char*)array->Address(1) == L'3');
}
TEST(StringTests, ToLowerTest) {
	String	string(L"ABCDEFGHI");
	String* string2 = string.ToLower();
	ASSERT_TRUE(wcscmp(string2->get_Buffer(), L"abcdefghi") == 0);
}
TEST(StringTests, ToUpperTest) {
	String	string(L"abcdefghi");
	String* string2 = string.ToUpper();
	ASSERT_TRUE(wcscmp(string2->get_Buffer(), L"ABCDEFGHI") == 0);
}
TEST(StringTests, TrimTest) {
	String	string(L" \tABCDEFGHI\n\r");
	String* string2 = string.Trim();
	ASSERT_TRUE(wcscmp(string2->get_Buffer(), L"ABCDEFGHI") == 0);
}
TEST(StringTests, Trim2Test) {
	String	string(L" \tABCDEFGHI\n\r");
	Array array(CharType, 2);
	Char	data[] = { ' ','\t' };
	array.Initialize(data);
	String* string2 = string.Trim(&array);
	ASSERT_TRUE(wcscmp(string2->get_Buffer(), L"ABCDEFGHI\n\r") == 0);
}
TEST(StringTests, Trim3Test) {
	String	string(L" \tABCDEFGHI\n\r");
	Array array(CharType, 2);
	Char	data[] = { ' ','\t' };
	array.Initialize(data);
	String* string2 = string.Trim(nullptr);
	ASSERT_TRUE(wcscmp(string2->get_Buffer(), L"ABCDEFGHI") == 0);
}
TEST(StringTests, TrimEndTest) {
	String	string(L" \tABCDEFGHI\n\r");
	Array array(CharType, 2);
	Char	data[] = { ' ','\t' };
	array.Initialize(data);
	String* string2 = string.TrimEnd(nullptr);
	ASSERT_TRUE(wcscmp(string2->get_Buffer(), L" \tABCDEFGHI") == 0);
}
TEST(StringTests, TrimEnd2Test) {
	String	string(L" \tABCDEFGHI\n\r");
	Array array(CharType, 2);
	Char	data[] = { ' ','\t' };
	array.Initialize(data);
	String* string2 = string.TrimEnd(&array);
	ASSERT_TRUE(wcscmp(string2->get_Buffer(), L" \tABCDEFGHI\n\r") == 0);
}
TEST(StringTests, TrimEnd3Test) {
	String	string(L" \tABCDEFGHI\n\r\t");
	Array array(CharType, 2);
	Char	data[] = { ' ','\t' };
	array.Initialize(data);
	String* string2 = string.TrimEnd(&array);
	ASSERT_TRUE(wcscmp(string2->get_Buffer(), L" \tABCDEFGHI\n\r") == 0);
}
TEST(StringTests, TrimStartTest) {
	String	string(L" \tABCDEFGHI\n\r");
	Array array(CharType, 2);
	Char	data[] = { ' ','\t' };
	array.Initialize(data);
	String* string2 = string.TrimStart(nullptr);
	ASSERT_TRUE(wcscmp(string2->get_Buffer(), L"ABCDEFGHI\n\r") == 0);
}
TEST(StringTests, TrimStart2Test) {
	String	string(L" \tABCDEFGHI\n\r");
	Array array(CharType, 2);
	Char	data[] = { '\n','\r' };
	array.Initialize(data);
	String* string2 = string.TrimStart(&array);
	ASSERT_TRUE(wcscmp(string2->get_Buffer(), L" \tABCDEFGHI\n\r") == 0);
}
TEST(StringTests, TrimStart3Test) {
	String	string(L"\r \tABCDEFGHI\n\r");
	Array array(CharType, 2);
	Char	data[] = { '\n','\r' };
	array.Initialize(data);
	String* string2 = string.TrimStart(&array);
	ASSERT_TRUE(wcscmp(string2->get_Buffer(), L" \tABCDEFGHI\n\r") == 0);
}
