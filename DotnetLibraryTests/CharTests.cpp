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

TEST(CharTests, CompareToTest) {
	CharValue	value1(L'B');
	ASSERT_TRUE(value1.CompareTo(L'B') == 0);
	ASSERT_TRUE(value1.CompareTo(L'C') < 0);
	ASSERT_TRUE(value1.CompareTo(L'A') > 0);
}
TEST(CharTests, CompareTo2Test) {
	CharValue	value1(L'B');
	CharValue	value2(L'C');
	CharValue	value3(L'A');
	ASSERT_TRUE(value1.CompareTo(&value1) == 0);
	ASSERT_TRUE(value1.CompareTo(&value2) < 0);
	ASSERT_TRUE(value1.CompareTo(&value3) > 0);
}
TEST(CharTests, EqualsTest) {
	CharValue	value1(L'B');
	ASSERT_TRUE(value1.Equals(L'B'));
	CharValue	value2(L'B');
	ASSERT_TRUE(value1.Equals(&value2));
}
TEST(CharTests, TryParseTest) {
	Char	value = 0;
	String	str(L"A");
	Boolean goodParse = CharValue::TryParse(&str, value);
	ASSERT_TRUE(goodParse);
	ASSERT_TRUE(value == L'A');
}
TEST(CharTests, TryParse2Test) {
	Char	value = 0;
	String	str(L"AB");
	Boolean goodParse = CharValue::TryParse(&str, value);
	ASSERT_TRUE(!goodParse);
}
TEST(CharTests, ParseTest) {
	String	str(L"A");
	Char	value = CharValue::Parse(&str);
	ASSERT_TRUE(value == L'A');
}
TEST(CharTests, getAsTest) {
	CharValue	value1(L'B');
	ASSERT_TRUE(value1.get_AsInt32() == 0X42);
	ASSERT_TRUE(value1.get_AsDouble() == 66.0);
}
TEST(CharTests, ToStringTest) {
	CharValue	value1(L'B');
	String* str = value1.ToString();
	ASSERT_TRUE(wcscmp(str->get_Buffer(), L"B") == 0);
}
TEST(CharTests, GetNumericValueTest) {
	Double value = CharValue::GetNumericValue(L'1');
	ASSERT_TRUE(value == 1);
	String	str(L"A2");
	Double value2 = CharValue::GetNumericValue(&str, 1);
	ASSERT_TRUE(value2 == 2);
}
TEST(CharTests, IsControlTest) {
	String	str(L"\t");
	ASSERT_TRUE(CharValue::IsControl(L'\t'));
	ASSERT_TRUE(CharValue::IsControl(&str,0));
}
TEST(CharTests, IsDigitTest) {
	String	str(L"1");
	ASSERT_TRUE(CharValue::IsDigit(L'1'));
	ASSERT_TRUE(!CharValue::IsDigit(L'A'));
	ASSERT_TRUE(CharValue::IsDigit(&str, 0));
}
TEST(CharTests, IsLetterTest) {
	String	str(L"A");
	ASSERT_TRUE(CharValue::IsLetter(L'A'));
	ASSERT_TRUE(!CharValue::IsLetter(L'1'));
	ASSERT_TRUE(CharValue::IsLetter(&str, 0));
}
TEST(CharTests, IsLetterOrDigitTest) {
	String	str(L"A");
	ASSERT_TRUE(CharValue::IsLetterOrDigit(L'A'));
	ASSERT_TRUE(CharValue::IsLetterOrDigit(L'1'));
	ASSERT_TRUE(CharValue::IsLetterOrDigit(&str, 0));
}
TEST(CharTests, IsLowerTest) {
	String	str(L"a");
	ASSERT_TRUE(CharValue::IsLower(L'a'));
	ASSERT_TRUE(!CharValue::IsLower(L'A'));
	ASSERT_TRUE(CharValue::IsLower(&str, 0));
}
TEST(CharTests, IsNumberTest) {
	String	str(L"1");
	ASSERT_TRUE(CharValue::IsNumber(L'1'));
	ASSERT_TRUE(!CharValue::IsNumber(L'A'));
	ASSERT_TRUE(CharValue::IsNumber(&str, 0));
}
TEST(CharTests, IsPunctuationTest) {
	String	str(L".");
	ASSERT_TRUE(CharValue::IsPunctuation(L'.'));
	ASSERT_TRUE(!CharValue::IsPunctuation(L'A'));
	ASSERT_TRUE(CharValue::IsPunctuation(&str, 0));
}
TEST(CharTests, IsSeparatorTest) {
	String	str(L" ");
	ASSERT_TRUE(CharValue::IsSeparator(L' '));
	ASSERT_TRUE(!CharValue::IsSeparator(L'A'));
	ASSERT_TRUE(CharValue::IsSeparator(&str, 0));
}
TEST(CharTests, IsUpperTest) {
	String	str(L"A");
	ASSERT_TRUE(CharValue::IsUpper(L'A'));
	ASSERT_TRUE(!CharValue::IsUpper(L'a'));
	ASSERT_TRUE(CharValue::IsUpper(&str, 0));
}
TEST(CharTests, IsWhiteSpaceTest) {
	String	str(L" ");
	ASSERT_TRUE(CharValue::IsWhiteSpace(L' '));
	ASSERT_TRUE(!CharValue::IsWhiteSpace(L'A'));
	ASSERT_TRUE(CharValue::IsWhiteSpace(&str, 0));
}
TEST(CharTests, ToLowerTest) {
	ASSERT_TRUE(CharValue::ToLower(L'A') == L'a');
}
TEST(CharTests, ToUpperTest) {
	ASSERT_TRUE(CharValue::ToUpper(L'a') == L'A');
}
