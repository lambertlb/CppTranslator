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

TEST(SingleTests, CompareToTest) {
	SingleValue	value1(1);
	ASSERT_TRUE(value1.CompareTo(1) == 0);
	ASSERT_TRUE(value1.CompareTo(2) < 0);
	ASSERT_TRUE(value1.CompareTo(0.0) > 0);
	ASSERT_TRUE(value1.CompareTo(SingleValue::NaN) > 0);
}
TEST(SingleTests, CompareTo2Test) {
	SingleValue	value1(1);
	SingleValue	value2(2);
	SingleValue	value3(0.0);
	SingleValue	value4(SingleValue::NaN);
	ASSERT_TRUE(value1.CompareTo(&value1) == 0);
	ASSERT_TRUE(value1.CompareTo(&value2) < 0);
	ASSERT_TRUE(value1.CompareTo(&value3) > 0);
	ASSERT_TRUE(value1.CompareTo(&value4) > 0);
}
TEST(SingleTests, EqualsTest) {
	SingleValue	value1(1);
	ASSERT_TRUE(value1.Equals(1));
	SingleValue	value2(1);
	ASSERT_TRUE(value1.Equals(&value2));
}
TEST(SingleTests, Equals2Test) {
	SingleValue	value1(SingleValue::NaN);
	ASSERT_TRUE(value1.Equals(SingleValue::NaN));
	SingleValue	value2(SingleValue::NaN);
	ASSERT_TRUE(value1.Equals(&value2));
}
TEST(SingleTests, IsFiniteTest) {
	ASSERT_TRUE(SingleValue::IsFinite(3.0 / 1));
	ASSERT_TRUE(!SingleValue::IsFinite(SingleValue::NaN));
}
TEST(SingleTests, IsInfinityTest) {
	ASSERT_TRUE(!SingleValue::IsInfinity(3.0 / 1));
	ASSERT_TRUE(SingleValue::IsInfinity(SingleValue::PositiveInfinity));
}
TEST(SingleTests, IsNaNTest) {
	ASSERT_TRUE(!SingleValue::IsNaN(3.0));
	ASSERT_TRUE(SingleValue::IsNaN(SingleValue::NaN));
}
TEST(SingleTests, IsNegativeTest) {
	ASSERT_TRUE(SingleValue::IsNegative(-3.0));
	ASSERT_TRUE(!SingleValue::IsNegative(3.0));
	ASSERT_TRUE(SingleValue::IsNegative(SingleValue::NaN));
}
TEST(SingleTests, IsNegativeInfinityTest) {
	ASSERT_TRUE(SingleValue::IsNegativeInfinity(SingleValue::NegativeInfinity));
	ASSERT_TRUE(!SingleValue::IsNegativeInfinity(SingleValue::PositiveInfinity));
	ASSERT_TRUE(!SingleValue::IsNegativeInfinity(SingleValue::NaN));
}
TEST(SingleTests, IsNormalTest) {
	ASSERT_TRUE(SingleValue::IsNormal(3.0));
	ASSERT_TRUE(!SingleValue::IsNormal(SingleValue::PositiveInfinity));
	ASSERT_TRUE(!SingleValue::IsNormal(SingleValue::NaN));
}
TEST(SingleTests, IsPositiveInfinityTest) {
	ASSERT_TRUE(!SingleValue::IsPositiveInfinity(SingleValue::NegativeInfinity));
	ASSERT_TRUE(SingleValue::IsPositiveInfinity(SingleValue::PositiveInfinity));
	ASSERT_TRUE(!SingleValue::IsPositiveInfinity(SingleValue::NaN));
}
TEST(SingleTests, IsSubnormalTest) {
	ASSERT_TRUE(SingleValue::IsSubnormal(-1.401298E-45f));
	ASSERT_TRUE(SingleValue::IsSubnormal(1.17549421E-38f));
	ASSERT_TRUE(!SingleValue::IsSubnormal(1.17549435E-38f));
}
TEST(SingleTests, TryParseTest) {
	Single	value = 0;
	String	str(L"11");
	Boolean goodParse = SingleValue::TryParse(&str, value);
	ASSERT_TRUE(goodParse);
	ASSERT_TRUE(value == 11);
}
TEST(SingleTests, TryParse3Test) {
	Single	value = 0;
	String	str(L" 11 ");
	Boolean goodParse = SingleValue::TryParse(&str, value);
	ASSERT_TRUE(goodParse);
	ASSERT_TRUE(value == 11);
}
TEST(SingleTests, TryParse4Test) {
	Single	value = 0;
	String	str(L"AAA");
	Boolean goodParse = SingleValue::TryParse(&str, value);
	ASSERT_TRUE(!goodParse);
}
TEST(SingleTests, TryParse5Test) {
	Single	value = 0;
	String	str(L"-11");
	Boolean goodParse = SingleValue::TryParse(&str, value);
	ASSERT_TRUE(goodParse);
	ASSERT_TRUE(value == -11);
}
TEST(SingleTests, ParseTest) {
	String	str(L"11");
	Single	value = SingleValue::Parse(&str);
	ASSERT_TRUE(value == 11);
}
