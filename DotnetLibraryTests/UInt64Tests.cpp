// Copyright (c) 2019 LLambert
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this
// software and associated documentation files (the "Software"), to deal in the Software
// without restriction, including without limitation the rights to use, copy, modify, merge,
// publish, distribute, sub-license, and/or sell copies of the Software, and to permit persons
// to whom the Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or
// substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
// INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
// PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
// FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
// OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
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
