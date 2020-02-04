#include "gtest/gtest.h"
#include <DotnetTypes.h>

using namespace DotnetLibrary;

TEST(Int32Tests, CompareToTest) {
	Int32Value	value1(1);
	ASSERT_TRUE(value1.CompareTo(1) == 0);
	ASSERT_TRUE(value1.CompareTo(2) < 0);
	ASSERT_TRUE(value1.CompareTo((Int32)0) > 0);
}
TEST(Int32Tests, CompareTo2Test) {
	Int32Value	value1(1);
	Int32Value	value2(2);
	Int32Value	value3((Int32)0);
	ASSERT_TRUE(value1.CompareTo(&value1) == 0);
	ASSERT_TRUE(value1.CompareTo(&value2) < 0);
	ASSERT_TRUE(value1.CompareTo(&value3) > 0);
}
TEST(Int32Tests, EqualsTest) {
	Int32Value	value1(1);
	ASSERT_TRUE(value1.Equals(1));
	Int32Value	value2(1);
	ASSERT_TRUE(value1.Equals(&value2));
}
TEST(Int32Tests, TryParseTest) {
	Int32	value = 0;
	String	str(L"11");
	Boolean goodParse = Int32Value::TryParse(&str, value);
	ASSERT_TRUE(goodParse);
	ASSERT_TRUE(value == 11);
}
TEST(Int32Tests, TryParse2Test) {
	Int32	value = 0;
	String	str(L"11A");
	Boolean goodParse = Int32Value::TryParse(&str, value);
	ASSERT_TRUE(!goodParse);
}
TEST(Int32Tests, TryParse3Test) {
	Int32	value = 0;
	String	str(L" 11 ");
	Boolean goodParse = Int32Value::TryParse(&str, value);
	ASSERT_TRUE(goodParse);
	ASSERT_TRUE(value == 11);
}
TEST(Int32Tests, TryParse4Test) {
	Int32	value = 0;
	String	str(L"30000000000");
	Boolean goodParse = Int32Value::TryParse(&str, value);
	ASSERT_TRUE(!goodParse);
}
TEST(Int32Tests, TryParse5Test) {
	Int32	value = 0;
	String	str(L"-11");
	Boolean goodParse = Int32Value::TryParse(&str, value);
	ASSERT_TRUE(goodParse);
	ASSERT_TRUE(value == -11);
}
TEST(Int32Tests, ParseTest) {
	String	str(L"11");
	Int32	value = Int32Value::Parse(&str);
	ASSERT_TRUE(value == 11);
}
TEST(Int32Tests, getAsTest) {
	Int32Value	value1(11);
	ASSERT_TRUE(value1.get_AsDouble() == 11.0);
	ASSERT_TRUE(value1.get_AsSingle() == 11.0F);
	ASSERT_TRUE(value1.get_AsBoolean());
	ASSERT_TRUE(value1.get_AsInt32() == 11);
}
TEST(Int32Tests, ToStringTest) {
	Int32Value value(22);
	String* str = value.ToString();
	ASSERT_TRUE(wcscmp(str->get_Buffer(), L"22") == 0);
}
