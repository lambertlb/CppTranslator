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

TEST(DoubleTests, CompareToTest) {
	DoubleValue	value1(1);
	ASSERT_TRUE(value1.CompareTo(1) == 0);
	ASSERT_TRUE(value1.CompareTo(2) < 0);
	ASSERT_TRUE(value1.CompareTo(0.0) > 0);
	ASSERT_TRUE(value1.CompareTo(DoubleValue::NaN) > 0);
}
TEST(DoubleTests, CompareTo2Test) {
	DoubleValue	value1(1);
	DoubleValue	value2(2);
	DoubleValue	value3(0.0);
	DoubleValue	value4(DoubleValue::NaN);
	ASSERT_TRUE(value1.CompareTo(&value1) == 0);
	ASSERT_TRUE(value1.CompareTo(&value2) < 0);
	ASSERT_TRUE(value1.CompareTo(&value3) > 0);
	ASSERT_TRUE(value1.CompareTo(&value4) > 0);
}
TEST(DoubleTests, EqualsTest) {
	DoubleValue	value1(1);
	ASSERT_TRUE(value1.Equals(1));
	DoubleValue	value2(1);
	ASSERT_TRUE(value1.Equals(&value2));
}
TEST(DoubleTests, Equals2Test) {
	DoubleValue	value1(DoubleValue::NaN);
	ASSERT_TRUE(value1.Equals(DoubleValue::NaN));
	DoubleValue	value2(DoubleValue::NaN);
	ASSERT_TRUE(value1.Equals(&value2));
}
TEST(DoubleTests, IsFiniteTest) {
	ASSERT_TRUE(DoubleValue::IsFinite(3.0 / 1));
	ASSERT_TRUE(!DoubleValue::IsFinite(DoubleValue::NaN));
}
TEST(DoubleTests, IsInfinityTest) {
	ASSERT_TRUE(!DoubleValue::IsInfinity(3.0 / 1));
	ASSERT_TRUE(DoubleValue::IsInfinity(DoubleValue::PositiveInfinity));
}
TEST(DoubleTests, IsNaNTest) {
	ASSERT_TRUE(!DoubleValue::IsNaN(3.0));
	ASSERT_TRUE(DoubleValue::IsNaN(DoubleValue::NaN));
}
TEST(DoubleTests, IsNegativeTest) {
	ASSERT_TRUE(DoubleValue::IsNegative(-3.0));
	ASSERT_TRUE(!DoubleValue::IsNegative(3.0));
	ASSERT_TRUE(DoubleValue::IsNegative(DoubleValue::NaN));
}
TEST(DoubleTests, IsNegativeInfinityTest) {
	ASSERT_TRUE(DoubleValue::IsNegativeInfinity(DoubleValue::NegativeInfinity));
	ASSERT_TRUE(!DoubleValue::IsNegativeInfinity(DoubleValue::PositiveInfinity));
	ASSERT_TRUE(!DoubleValue::IsNegativeInfinity(DoubleValue::NaN));
}
TEST(DoubleTests, IsNormalTest) {
	ASSERT_TRUE(DoubleValue::IsNormal(3.0));
	ASSERT_TRUE(!DoubleValue::IsNormal(DoubleValue::PositiveInfinity));
	ASSERT_TRUE(!DoubleValue::IsNormal(DoubleValue::NaN));
}
TEST(DoubleTests, IsPositiveInfinityTest) {
	ASSERT_TRUE(!DoubleValue::IsPositiveInfinity(DoubleValue::NegativeInfinity));
	ASSERT_TRUE(DoubleValue::IsPositiveInfinity(DoubleValue::PositiveInfinity));
	ASSERT_TRUE(!DoubleValue::IsPositiveInfinity(DoubleValue::NaN));
}
TEST(DoubleTests, IsSubnormalTest) {
	ASSERT_TRUE(DoubleValue::IsSubnormal(4.94065645841247E-324));
	ASSERT_TRUE(DoubleValue::IsSubnormal(2.2250738585072009E-308));
	ASSERT_TRUE(!DoubleValue::IsSubnormal(2.2250738585072014E-308));
}
TEST(DoubleTests, TryParseTest) {
	Double	value = 0;
	String	str(L"11");
	Boolean goodParse = DoubleValue::TryParse(&str, value);
	ASSERT_TRUE(goodParse);
	ASSERT_TRUE(value == 11);
}
TEST(DoubleTests, TryParse3Test) {
	Double	value = 0;
	String	str(L" 11 ");
	Boolean goodParse = DoubleValue::TryParse(&str, value);
	ASSERT_TRUE(goodParse);
	ASSERT_TRUE(value == 11);
}
TEST(DoubleTests, TryParse4Test) {
	Double	value = 0;
	String	str(L"AAA");
	Boolean goodParse = DoubleValue::TryParse(&str, value);
	ASSERT_TRUE(!goodParse);
}
TEST(DoubleTests, TryParse5Test) {
	Double	value = 0;
	String	str(L"-11");
	Boolean goodParse = DoubleValue::TryParse(&str, value);
	ASSERT_TRUE(goodParse);
	ASSERT_TRUE(value == -11);
}
TEST(DoubleTests, ParseTest) {
	String	str(L"11");
	Double	value = DoubleValue::Parse(&str);
	ASSERT_TRUE(value == 11);
}
