#include "gtest/gtest.h"
#include <DotnetTypes.h>

using namespace DotnetLibrary;

TEST(BooleanTests, CompareToTest) {
	BooleanValue value1(true);
	BooleanValue value2(false);
	ASSERT_TRUE(value1.CompareTo(true) == 0);
	ASSERT_TRUE(value1.CompareTo(false) == 1);
	ASSERT_TRUE(value2.CompareTo(true) == -1);
}
TEST(BooleanTests, CompareTo2Test) {
	BooleanValue value1(true);
	BooleanValue value2(false);
	ASSERT_TRUE(value1.CompareTo(&value1) == 0);
	ASSERT_TRUE(value1.CompareTo(&value2) == 1);
	ASSERT_TRUE(value2.CompareTo(&value1) == -1);
}
TEST(BooleanTests, EqualsTest) {
	BooleanValue value1(true);
	ASSERT_TRUE(value1.Equals(true));
	ASSERT_TRUE(!value1.Equals(false));
}
TEST(BooleanTests, Equals2Test) {
	BooleanValue value1(true);
	BooleanValue value2(false);
	ASSERT_TRUE(value1.Equals(&value1));
	ASSERT_TRUE(!value1.Equals(&value2));
}
TEST(BooleanTests, SimpleConversionTest) {
	BooleanValue value1(true);
	BooleanValue value2(false);
	ASSERT_TRUE(value1.get_AsByte() == 1);
	ASSERT_TRUE(value1.get_AsSByte() == 1);
	ASSERT_TRUE(value1.get_AsInt16() == 1);
	ASSERT_TRUE(value1.get_AsUInt16() == 1);
	ASSERT_TRUE(value1.get_AsInt32() == 1);
	ASSERT_TRUE(value1.get_AsUInt32() == 1);
	ASSERT_TRUE(value1.get_AsInt64() == 1);
	ASSERT_TRUE(value1.get_AsUInt64() == 1);

	ASSERT_TRUE(value2.get_AsByte() == 0);
	ASSERT_TRUE(value2.get_AsSByte() == 0);
	ASSERT_TRUE(value2.get_AsInt16() == 0);
	ASSERT_TRUE(value2.get_AsUInt16() == 0);
	ASSERT_TRUE(value2.get_AsInt32() == 0);
	ASSERT_TRUE(value2.get_AsUInt32() == 0);
	ASSERT_TRUE(value2.get_AsInt64() == 0);
	ASSERT_TRUE(value2.get_AsUInt64() == 0);
}
TEST(BooleanTests, ParseTest) {
	Boolean value1 = BooleanValue::Parse(BooleanValue::TrueString);
	Boolean value2 = BooleanValue::Parse(BooleanValue::FalseString);
	ASSERT_TRUE(value1);
	ASSERT_TRUE(!value2);
}
TEST(BooleanTests, FormatStringTest) {
	Char	where[128];
	BooleanValue value1(true);
	value1.FormatString(where, 128);
	ASSERT_TRUE(wcscmp(where, L"true") == 0);
	BooleanValue value2(false);
	value2.FormatString(where, 128);
	ASSERT_TRUE(wcscmp(where, L"false") == 0);
}
