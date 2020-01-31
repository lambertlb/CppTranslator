#include "gtest/gtest.h"
#include <DotnetTypes.h>

using namespace DotnetLibrary;

TEST(ByteTests, CompareToTest) {
	ByteValue	value1(1);
	ASSERT_TRUE(value1.CompareTo(1) == 0);
	ASSERT_TRUE(value1.CompareTo(2) < 0);
	ASSERT_TRUE(value1.CompareTo((Byte)0) > 0);
}
TEST(ByteTests, CompareTo2Test) {
	ByteValue	value1(1);
	ByteValue	value2(2);
	ByteValue	value3((Byte)0);
	ASSERT_TRUE(value1.CompareTo(&value1) == 0);
	ASSERT_TRUE(value1.CompareTo(&value2) < 0);
	ASSERT_TRUE(value1.CompareTo(&value3) > 0);
}
TEST(ByteTests, EqualsTest) {
	ByteValue	value1(1);
	ASSERT_TRUE(value1.Equals(1));
	ByteValue	value2(1);
	ASSERT_TRUE(value1.Equals(&value2));
}
TEST(ByteTests, TryParseTest) {
	Byte	value = 0;
	String	str(L"11");
	Boolean goodParse = ByteValue::TryParse(&str, &value);
	ASSERT_TRUE(goodParse);
	ASSERT_TRUE(value == 11);
}
TEST(ByteTests, TryParse2Test) {
	Byte	value = 0;
	String	str(L"11A");
	Boolean goodParse = ByteValue::TryParse(&str, &value);
	ASSERT_TRUE(!goodParse);
}
TEST(ByteTests, TryParse3Test) {
	Byte	value = 0;
	String	str(L" 11 ");
	Boolean goodParse = ByteValue::TryParse(&str, &value);
	ASSERT_TRUE(goodParse);
	ASSERT_TRUE(value == 11);
}
TEST(ByteTests, TryParse4Test) {
	Byte	value = 0;
	String	str(L"300");
	Boolean goodParse = ByteValue::TryParse(&str, &value);
	ASSERT_TRUE(!goodParse);
}
TEST(ByteTests, TryParse5Test) {
	Byte	value = 0;
	String	str(L"-11");
	Boolean goodParse = ByteValue::TryParse(&str, &value);
	ASSERT_TRUE(!goodParse);
}
TEST(ByteTests, ParseTest) {
	String	str(L"11");
	Byte	value = ByteValue::Parse(&str);
	ASSERT_TRUE(value == 11);
}
TEST(ByteTests, getAsTest) {
	ByteValue	value1(11);
	ASSERT_TRUE(value1.get_AsDouble() == 11.0);
	ASSERT_TRUE(value1.get_AsSingle() == 11.0F);
	ASSERT_TRUE(value1.get_AsBoolean());
	ASSERT_TRUE(value1.get_AsInt32() == 11);
}
TEST(ByteTests, ToStringTest) {
	ByteValue value(22);
	String* str = value.ToString();
	ASSERT_TRUE(wcscmp(str->get_Buffer(), L"22") == 0);
}
