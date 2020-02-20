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
	ASSERT_TRUE(wcscmp(where, L"True") == 0);
	BooleanValue value2(false);
	value2.FormatString(where, 128);
	ASSERT_TRUE(wcscmp(where, L"False") == 0);
}
