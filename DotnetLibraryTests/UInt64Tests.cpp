#include "gtest/gtest.h"
#include <DotnetTypes.h>

using namespace DotnetLibrary;

TEST(UInt64Tests, CompareToTest) {
	UInt64Value	value1(1);
	ASSERT_TRUE(value1.CompareTo(1) == 0);
	ASSERT_TRUE(value1.CompareTo(2) < 0);
	ASSERT_TRUE(value1.CompareTo((UInt64)0) > 0);
}
TEST(UInt64Tests, CompareTo2Test) {
	UInt64Value	value1(1);
	UInt64Value	value2(2);
	UInt64Value	value3((UInt64)0);
	ASSERT_TRUE(value1.CompareTo(&value1) == 0);
	ASSERT_TRUE(value1.CompareTo(&value2) < 0);
	ASSERT_TRUE(value1.CompareTo(&value3) > 0);
}
TEST(UInt64Tests, EqualsTest) {
	UInt64Value	value1(1);
	ASSERT_TRUE(value1.Equals(1));
	UInt64Value	value2(1);
	ASSERT_TRUE(value1.Equals(&value2));
}
TEST(UInt64Tests, TryParseTest) {
	UInt64	value = 0;
	String	str(L"11");
	Boolean goodParse = UInt64Value::TryParse(&str, value);
	ASSERT_TRUE(goodParse);
	ASSERT_TRUE(value == 11);
}
TEST(UInt64Tests, TryParse2Test) {
	UInt64	value = 0;
	String	str(L"11A");
	Boolean goodParse = UInt64Value::TryParse(&str, value);
	ASSERT_TRUE(!goodParse);
}
TEST(UInt64Tests, TryParse3Test) {
	UInt64	value = 0;
	String	str(L" 11 ");
	Boolean goodParse = UInt64Value::TryParse(&str, value);
	ASSERT_TRUE(goodParse);
	ASSERT_TRUE(value == 11);
}
TEST(UInt64Tests, ParseTest) {
	String	str(L"11");
	UInt64	value = UInt64Value::Parse(&str);
	ASSERT_TRUE(value == 11);
}
TEST(UInt64Tests, getAsTest) {
	UInt64Value	value1(11);
	ASSERT_TRUE(value1.get_AsDouble() == 11.0);
	ASSERT_TRUE(value1.get_AsSingle() == 11.0F);
	ASSERT_TRUE(value1.get_AsBoolean());
	ASSERT_TRUE(value1.get_AsInt32() == 11);
}
TEST(UInt64Tests, ToStringTest) {
	UInt64Value value(22);
	String* str = value.ToString();
	ASSERT_TRUE(wcscmp(str->get_Buffer(), L"22") == 0);
}
