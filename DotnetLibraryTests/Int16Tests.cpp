#include "gtest/gtest.h"
#include <DotnetTypes.h>

using namespace DotnetLibrary;

TEST(Int16Tests, CompareToTest) {
	Int16Value	value1(1);
	ASSERT_TRUE(value1.CompareTo(1) == 0);
	ASSERT_TRUE(value1.CompareTo(2) < 0);
	ASSERT_TRUE(value1.CompareTo((Int16)0) > 0);
}
TEST(Int16Tests, CompareTo2Test) {
	Int16Value	value1(1);
	Int16Value	value2(2);
	Int16Value	value3((Int16)0);
	ASSERT_TRUE(value1.CompareTo(&value1) == 0);
	ASSERT_TRUE(value1.CompareTo(&value2) < 0);
	ASSERT_TRUE(value1.CompareTo(&value3) > 0);
}
TEST(Int16Tests, EqualsTest) {
	Int16Value	value1(1);
	ASSERT_TRUE(value1.Equals(1));
	Int16Value	value2(1);
	ASSERT_TRUE(value1.Equals(&value2));
}
TEST(Int16Tests, TryParseTest) {
	Int16	value = 0;
	String	str(L"11");
	Boolean goodParse = Int16Value::TryParse(&str, &value);
	ASSERT_TRUE(goodParse);
	ASSERT_TRUE(value == 11);
}
TEST(Int16Tests, TryParse2Test) {
	Int16	value = 0;
	String	str(L"11A");
	Boolean goodParse = Int16Value::TryParse(&str, &value);
	ASSERT_TRUE(!goodParse);
}
TEST(Int16Tests, TryParse3Test) {
	Int16	value = 0;
	String	str(L" 11 ");
	Boolean goodParse = Int16Value::TryParse(&str, &value);
	ASSERT_TRUE(goodParse);
	ASSERT_TRUE(value == 11);
}
TEST(Int16Tests, TryParse4Test) {
	Int16	value = 0;
	String	str(L"300000");
	Boolean goodParse = Int16Value::TryParse(&str, &value);
	ASSERT_TRUE(!goodParse);
}
TEST(Int16Tests, TryParse5Test) {
	Int16	value = 0;
	String	str(L"-11");
	Boolean goodParse = Int16Value::TryParse(&str, &value);
	ASSERT_TRUE(goodParse);
	ASSERT_TRUE(value == -11);
}
TEST(Int16Tests, ParseTest) {
	String	str(L"11");
	Int16	value = Int16Value::Parse(&str);
	ASSERT_TRUE(value == 11);
}
TEST(Int16Tests, getAsTest) {
	Int16Value	value1(11);
	ASSERT_TRUE(value1.get_AsDouble() == 11.0);
	ASSERT_TRUE(value1.get_AsSingle() == 11.0F);
	ASSERT_TRUE(value1.get_AsBoolean());
	ASSERT_TRUE(value1.get_AsInt32() == 11);
}
TEST(Int16Tests, ToStringTest) {
	Int16Value value(22);
	String* str = value.ToString();
	ASSERT_TRUE(wcscmp(str->get_Buffer(), L"22") == 0);
}
