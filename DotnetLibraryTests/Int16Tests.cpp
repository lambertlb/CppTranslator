// Copyright (c) 2019 LLambert
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this
// software and associated documentation files (the "Software"), to deal in the Software
// without restriction, including without limitation the rights to use, copy, modify, merge,
// publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons
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
	Boolean goodParse = Int16Value::TryParse(&str, value);
	ASSERT_TRUE(goodParse);
	ASSERT_TRUE(value == 11);
}
TEST(Int16Tests, TryParse2Test) {
	Int16	value = 0;
	String	str(L"11A");
	Boolean goodParse = Int16Value::TryParse(&str, value);
	ASSERT_TRUE(!goodParse);
}
TEST(Int16Tests, TryParse3Test) {
	Int16	value = 0;
	String	str(L" 11 ");
	Boolean goodParse = Int16Value::TryParse(&str, value);
	ASSERT_TRUE(goodParse);
	ASSERT_TRUE(value == 11);
}
TEST(Int16Tests, TryParse4Test) {
	Int16	value = 0;
	String	str(L"300000");
	Boolean goodParse = Int16Value::TryParse(&str, value);
	ASSERT_TRUE(!goodParse);
}
TEST(Int16Tests, TryParse5Test) {
	Int16	value = 0;
	String	str(L"-11");
	Boolean goodParse = Int16Value::TryParse(&str, value);
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
