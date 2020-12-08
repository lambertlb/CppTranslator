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
TEST(BitConverterTests, IsLittleEndianTest) {
	Int16 s = 1;
	ASSERT_TRUE(BitConverter::IsLittleEndian == (*((Byte*)&s) == 1));
}
TEST(BitConverterTests, DoubleToInt64BitsTest) {
	Double input = 123456.3234;
	Int64 result = BitConverter::DoubleToInt64Bits(input);
	ASSERT_TRUE(4683220267154373240L == result);
	Double roundtripped = BitConverter::Int64BitsToDouble(result);
	ASSERT_TRUE(input == roundtripped);
}
TEST(BitConverterTests, BooleanGetBytesTest) {
	Array* bytes = BitConverter::GetBytes(true);
	ASSERT_TRUE(1 == bytes->get_Length());
	ASSERT_TRUE(1 == *(Byte*)bytes->Address(0));
	ASSERT_TRUE(BitConverter::ToBoolean(bytes, 0));

	bytes = BitConverter::GetBytes(false);
	ASSERT_TRUE(1 == bytes->get_Length());
	ASSERT_TRUE(0 == *(Byte*)bytes->Address(0));
	ASSERT_TRUE(!BitConverter::ToBoolean(bytes, 0));
}
TEST(BitConverterTests, CharGetBytesTest) {
	Char input = 'A';
	Byte expected[]{ 0x41, 0 };
	Array* bytes = BitConverter::GetBytes(input);
	ASSERT_TRUE(memcmp(expected, bytes->Address(0), 2) == 0);
	ASSERT_TRUE(BitConverter::ToChar(bytes, 0) == input);
}
TEST(BitConverterTests, DoubleGetBytesTest) {
	Double input = 123456.3234;
	Byte expected[]{ 0x78, 0x7a, 0xa5, 0x2c, 0x05, 0x24, 0xfe, 0x40 };
	Array* bytes = BitConverter::GetBytes(input);
	ASSERT_TRUE(memcmp(expected, bytes->Address(0), sizeof(Double)) == 0);
	ASSERT_TRUE(BitConverter::ToDouble(bytes, 0) == input);
}
TEST(BitConverterTests, Int16GetBytesTest) {
	Int16 input = 0x1234;
	Byte expected[]{ 0x34, 0x12 };
	Array* bytes = BitConverter::GetBytes(input);
	ASSERT_TRUE(memcmp(expected, bytes->Address(0), sizeof(Int16)) == 0);
	ASSERT_TRUE(BitConverter::ToInt16(bytes, 0) == input);
}
TEST(BitConverterTests, Int32GetBytesTest) {
	Int32 input = 0x12345678;
	Byte expected[]{ 0x78, 0x56, 0x34, 0x12 };
	Array* bytes = BitConverter::GetBytes(input);
	ASSERT_TRUE(memcmp(expected, bytes->Address(0), sizeof(Int32)) == 0);
	ASSERT_TRUE(BitConverter::ToInt32(bytes, 0) == input);
}
TEST(BitConverterTests, Int64GetBytesTest) {
	Int64 input = 0x0123456789abcdef;
	Byte expected[]{ 0xef, 0xcd, 0xab, 0x89, 0x67, 0x45, 0x23, 0x01 };
	Array* bytes = BitConverter::GetBytes(input);
	ASSERT_TRUE(memcmp(expected, bytes->Address(0), sizeof(Int64)) == 0);
	ASSERT_TRUE(BitConverter::ToInt64(bytes, 0) == input);
}
TEST(BitConverterTests, SingleGetBytesTest) {
	Float input = 8392.34f;
	Byte expected[]{ 0x5c, 0x21, 0x03, 0x46 };
	Array* bytes = BitConverter::GetBytes(input);
	ASSERT_TRUE(memcmp(expected, bytes->Address(0), sizeof(Single)) == 0);
	ASSERT_TRUE(BitConverter::ToSingle(bytes, 0) == input);
}
TEST(BitConverterTests, UInt16GetBytesTest) {
	UInt16 input = 0x1234;
	Byte expected[]{ 0x34, 0x12 };
	Array* bytes = BitConverter::GetBytes(input);
	ASSERT_TRUE(memcmp(expected, bytes->Address(0), sizeof(UInt16)) == 0);
	ASSERT_TRUE(BitConverter::ToUInt16(bytes, 0) == input);
}
TEST(BitConverterTests, UInt32GetBytesTest) {
	UInt32 input = 0x12345678;
	Byte expected[]{ 0x78, 0x56, 0x34, 0x12 };
	Array* bytes = BitConverter::GetBytes(input);
	ASSERT_TRUE(memcmp(expected, bytes->Address(0), sizeof(UInt32)) == 0);
	ASSERT_TRUE(BitConverter::ToUInt32(bytes, 0) == input);
}
TEST(BitConverterTests, UInt64GetBytesTest) {
	UInt64 input = 0x0123456789abcdef;
	Byte expected[]{ 0xef, 0xcd, 0xab, 0x89, 0x67, 0x45, 0x23, 0x01 };
	Array* bytes = BitConverter::GetBytes(input);
	ASSERT_TRUE(memcmp(expected, bytes->Address(0), sizeof(UInt64)) == 0);
	ASSERT_TRUE(BitConverter::ToUInt64(bytes, 0) == input);
}
TEST(BitConverterTests,ToStringTest) {
	UInt64 input = 0x0123456789abcdef;
	Char* expected = (Char*)L"EF-CD-AB-89-67-45-23-01";
	Array* bytes = BitConverter::GetBytes(input);
	String* answer = BitConverter::ToString(bytes);
	Char* x = (Char*)answer->Address(0);
	ASSERT_TRUE(wcscmp(x, expected) == 0);
}
TEST(BitConverterTests, ToString2Test) {
	UInt64 input = 0x0123456789abcdef;
	Char* expected = (Char*)L"AB-89-67-45-23-01";
	Array* bytes = BitConverter::GetBytes(input);
	String* answer = BitConverter::ToString(bytes,2);
	Char* x = (Char*)answer->Address(0);
	ASSERT_TRUE(wcscmp(x, expected) == 0);
}
TEST(BitConverterTests, ToString3Test) {
	UInt64 input = 0x0123456789abcdef;
	Char* expected = (Char*)L"AB-89";
	Array* bytes = BitConverter::GetBytes(input);
	String* answer = BitConverter::ToString(bytes,2, 2);
	Char* x = (Char*)answer->Address(0);
	ASSERT_TRUE(wcscmp(x, expected) == 0);
}
