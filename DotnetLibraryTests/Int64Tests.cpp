#include "gtest/gtest.h"
#include <DotnetTypes.h>

using namespace DotnetLibrary;

TEST(Int64Tests, CompareToTest) {
	Int64Value	value1(1);
	ASSERT_TRUE(value1.CompareTo(1) == 0);
	ASSERT_TRUE(value1.CompareTo(2) < 0);
	ASSERT_TRUE(value1.CompareTo((Int64)0) > 0);
}
TEST(Int64Tests, CompareTo2Test) {
	Int64Value	value1(1);
	Int64Value	value2(2);
	Int64Value	value3((Int64)0);
	ASSERT_TRUE(value1.CompareTo(&value1) == 0);
	ASSERT_TRUE(value1.CompareTo(&value2) < 0);
	ASSERT_TRUE(value1.CompareTo(&value3) > 0);
}
TEST(Int64Tests, EqualsTest) {
	Int64Value	value1(1);
	ASSERT_TRUE(value1.Equals(1));
	Int64Value	value2(1);
	ASSERT_TRUE(value1.Equals(&value2));
}
TEST(Int64Tests, TryParseTest) {
	Int64	value = 0;
	String	str(L"11");
	Boolean goodParse = Int64Value::TryParse(&str, value);
	ASSERT_TRUE(goodParse);
	ASSERT_TRUE(value == 11);
}
TEST(Int64Tests, TryParse2Test) {
	Int64	value = 0;
	String	str(L"11A");
	Boolean goodParse = Int64Value::TryParse(&str, value);
	ASSERT_TRUE(!goodParse);
}
TEST(Int64Tests, TryParse3Test) {
	Int64	value = 0;
	String	str(L" 11 ");
	Boolean goodParse = Int64Value::TryParse(&str, value);
	ASSERT_TRUE(goodParse);
	ASSERT_TRUE(value == 11);
}
TEST(Int64Tests, TryParse5Test) {
	Int64	value = 0;
	String	str(L"-11");
	Boolean goodParse = Int64Value::TryParse(&str, value);
	ASSERT_TRUE(goodParse);
	ASSERT_TRUE(value == -11);
}
TEST(Int64Tests, ParseTest) {
	String	str(L"11");
	Int64	value = Int64Value::Parse(&str);
	ASSERT_TRUE(value == 11);
}
TEST(Int64Tests, getAsTest) {
	Int64Value	value1(11);
	ASSERT_TRUE(value1.get_AsDouble() == 11.0);
	ASSERT_TRUE(value1.get_AsSingle() == 11.0F);
	ASSERT_TRUE(value1.get_AsBoolean());
	ASSERT_TRUE(value1.get_AsInt32() == 11);
}
TEST(Int64Tests, ToStringTest) {
	Int64Value value(22);
	String* str = value.ToString();
	ASSERT_TRUE(wcscmp(str->get_Buffer(), L"22") == 0);
}
