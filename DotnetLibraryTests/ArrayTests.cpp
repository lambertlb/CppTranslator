#include "gtest/gtest.h"
#include <DotnetTypes.h>

using namespace DotnetLibrary;
TEST(ArrayTests, ConstructorTest) {
	Array	array(CharType, 2, 3, 4);
	ASSERT_TRUE(array.GetElementType() == CharType);
	ASSERT_TRUE(array.get_Rank() == 3);
	ASSERT_TRUE(array.GetLowerBound(0) == 0);
	ASSERT_TRUE(array.GetLowerBound(1) == 0);
	ASSERT_TRUE(array.GetLowerBound(2) == 0);
	ASSERT_TRUE(array.GetUpperBound(0) == 1);
	ASSERT_TRUE(array.GetUpperBound(1) == 2);
	ASSERT_TRUE(array.GetUpperBound(2) == 3);
}
TEST(ArrayTests, Constructor2Test) {
	Array	array(CharType, 6);
	ASSERT_TRUE(array.GetElementType() == CharType);
	ASSERT_TRUE(array.get_Rank() == 1);
	ASSERT_TRUE(array.GetLowerBound(0) == 0);
	ASSERT_TRUE(array.GetUpperBound(0) == 5);
}
TEST(ArrayTests, AddressTest) {
	Array	array(CharType, 6);
	Char	data[] = { L'1', L'2', L'3', L'4', L'5', L'6' };
	array.Initialize(data);
	ASSERT_TRUE(*(Char*)array.Address(0) == L'1');
	ASSERT_TRUE(*(Char*)array.Address(1) == L'2');
	ASSERT_TRUE(*(Char*)array.Address(2) == L'3');
	ASSERT_TRUE(*(Char*)array.Address(3) == L'4');
	ASSERT_TRUE(*(Char*)array.Address(4) == L'5');
	ASSERT_TRUE(*(Char*)array.Address(5) == L'6');
}
TEST(ArrayTests, CopyTest) {
	Array	array(CharType, 6);
	Char	data[] = { L'1', L'2', L'3', L'4', L'5', L'6' };
	array.Initialize(data);
	Array	array2(CharType, 4);
	Char	data2[] = { L'A', L'B', L'C', L'D' };
	array2.Initialize(data2);
	Array::Copy(&array, &array2, 4);
	ASSERT_TRUE(*(Char*)array2.Address(0) == L'1');
	ASSERT_TRUE(*(Char*)array2.Address(1) == L'2');
	ASSERT_TRUE(*(Char*)array2.Address(2) == L'3');
	ASSERT_TRUE(*(Char*)array2.Address(3) == L'4');
}
TEST(ArrayTests, Copy2Test) {
	Array	array(CharType, 6);
	Char	data[] = { L'1', L'2', L'3', L'4', L'5', L'6' };
	array.Initialize(data);
	Array	array2(CharType, 4);
	Char	data2[] = { L'A', L'B', L'C', L'D' };
	array2.Initialize(data2);
	Array::Copy(&array, 2, &array2, 1, 2);
	ASSERT_TRUE(*(Char*)array2.Address(0) == L'A');
	ASSERT_TRUE(*(Char*)array2.Address(1) == L'3');
	ASSERT_TRUE(*(Char*)array2.Address(2) == L'4');
	ASSERT_TRUE(*(Char*)array2.Address(3) == L'D');
}
TEST(ArrayTests, ConstrainedCopyTest) {
	Array	array(CharType, 6);
	Char	data[] = { L'1', L'2', L'3', L'4', L'5', L'6' };
	array.Initialize(data);
	Array	array2(CharType, 4);
	Char	data2[] = { L'A', L'B', L'C', L'D' };
	array2.Initialize(data2);
	Array::ConstrainedCopy(&array, 2, &array2, 1, 2);
	ASSERT_TRUE(*(Char*)array2.Address(0) == L'A');
	ASSERT_TRUE(*(Char*)array2.Address(1) == L'3');
	ASSERT_TRUE(*(Char*)array2.Address(2) == L'4');
	ASSERT_TRUE(*(Char*)array2.Address(3) == L'D');
}
TEST(ArrayTests, CopyToTest) {
	Array	array(CharType, 6);
	Char	data[] = { L'1', L'2', L'3', L'4', L'5', L'6' };
	array.Initialize(data);
	Array	array2(CharType, 4);
	Char	data2[] = { L'A', L'B', L'C', L'D' };
	array2.Initialize(data2);
	array2.CopyTo(&array, 1);
	ASSERT_TRUE(*(Char*)array.Address(0) == L'1');
	ASSERT_TRUE(*(Char*)array.Address(1) == L'A');
	ASSERT_TRUE(*(Char*)array.Address(2) == L'B');
	ASSERT_TRUE(*(Char*)array.Address(3) == L'C');
	ASSERT_TRUE(*(Char*)array.Address(4) == L'D');
	ASSERT_TRUE(*(Char*)array.Address(5) == L'6');
}
TEST(ArrayTests, GetValueTest) {
	Array	array(StringType, 4);
	String	string(L"ABC");
	String	string2(L"DEF");
	String	string3(L"GHI");
	String	string4(L"JKL");
	Object* list[4] = { &string, &string2, &string3, &string4 };
	array.Initialize(list);
	String* value = (String*)array.GetValue(0);
	ASSERT_TRUE(value != nullptr);
	ASSERT_TRUE(wcscmp(value->get_Buffer(), L"ABC") == 0);
	value = (String*)array.GetValue(1);
	ASSERT_TRUE(value != nullptr);
	ASSERT_TRUE(wcscmp(value->get_Buffer(), L"DEF") == 0);
	value = (String*)array.GetValue(3);
	ASSERT_TRUE(value != nullptr);
	ASSERT_TRUE(wcscmp(value->get_Buffer(), L"JKL") == 0);
}
TEST(ArrayTests, SetValueTest) {
	Array	array(StringType, 4);
	String	string(L"ABC");
	String	string2(L"DEF");
	String	string3(L"GHI");
	String	string4(L"JKL");
	String	string5(L"123");
	Object* list[4] = { &string, &string2, &string3, &string4 };
	array.Initialize(list);
	array.SetValue(&string5, 2);
	String* value = (String*)array.GetValue(2);
	ASSERT_TRUE(value != nullptr);
	ASSERT_TRUE(wcscmp(value->get_Buffer(), L"123") == 0);
}
