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

TEST(BufferTests, BlockCopyTest) {
	Array	array(Int32Type, 10);
	Int32	intData[] = { 1,2,3,4,5,6,7,8,9,0 };
	array.Initialize(intData);
	Array	array2(Int32Type, 10);
	Buffer::BlockCopy(&array, 0, &array2, 0, array.get_Length() * sizeof(Int32));
	ASSERT_TRUE(*(Int32*)array.Address(0) == *(Int32*)array2.Address(0));
	ASSERT_TRUE(*(Int32*)array.Address(1) == *(Int32*)array2.Address(1));
	ASSERT_TRUE(*(Int32*)array.Address(2) == *(Int32*)array2.Address(2));
	ASSERT_TRUE(*(Int32*)array.Address(3) == *(Int32*)array2.Address(3));
	ASSERT_TRUE(*(Int32*)array.Address(4) == *(Int32*)array2.Address(4));
	ASSERT_TRUE(*(Int32*)array.Address(5) == *(Int32*)array2.Address(5));
	ASSERT_TRUE(*(Int32*)array.Address(6) == *(Int32*)array2.Address(6));
	ASSERT_TRUE(*(Int32*)array.Address(7) == *(Int32*)array2.Address(7));
	ASSERT_TRUE(*(Int32*)array.Address(8) == *(Int32*)array2.Address(8));
	ASSERT_TRUE(*(Int32*)array.Address(9) == *(Int32*)array2.Address(9));
}
TEST(BufferTests, BlockCopy2Test) {
	Array	array(Int32Type, 10);
	Int32	intData[] = { 1,2,3,4,5,6,7,8,9,0 };
	array.Initialize(intData);
	Array	array2(Int32Type, 10);
	Buffer::BlockCopy(&array, 2 * sizeof(Int32), &array2, 7 * sizeof(Int32), 2 * sizeof(Int32));
	ASSERT_TRUE(*(Int32*)array2.Address(0) == 0);
	ASSERT_TRUE(*(Int32*)array2.Address(1) == 0);
	ASSERT_TRUE(*(Int32*)array2.Address(2) == 0);
	ASSERT_TRUE(*(Int32*)array2.Address(3) == 0);
	ASSERT_TRUE(*(Int32*)array2.Address(4) == 0);
	ASSERT_TRUE(*(Int32*)array2.Address(5) == 0);
	ASSERT_TRUE(*(Int32*)array2.Address(6) == 0);
	ASSERT_TRUE(*(Int32*)array2.Address(7) == *(Int32*)array.Address(2));
	ASSERT_TRUE(*(Int32*)array2.Address(8) == *(Int32*)array.Address(3));
	ASSERT_TRUE(*(Int32*)array2.Address(9) == 0);
}
TEST(BufferTests, ByteLengthTest) {
	Array	array(Int32Type, 10);
	Int32	intData[] = { 1,2,3,4,5,6,7,8,9,0 };
	array.Initialize(intData);
	ASSERT_TRUE(Buffer::ByteLength(&array) == array.get_Length() * sizeof(Int32));
}
TEST(BufferTests, GetByteTest) {
	Array	array(Int32Type, 10);
	Int32	intData[] = { 1,2,3,4,5,6,7,8,9,10 };
	array.Initialize(intData);
	ASSERT_TRUE(Buffer::GetByte(&array, 0) == 1);
	ASSERT_TRUE(Buffer::GetByte(&array, 4) == 2);
	ASSERT_TRUE(Buffer::GetByte(&array, 8) == 3);
	ASSERT_TRUE(Buffer::GetByte(&array, 12) == 4);
	ASSERT_TRUE(Buffer::GetByte(&array, 16) == 5);
	ASSERT_TRUE(Buffer::GetByte(&array, 20) == 6);
	ASSERT_TRUE(Buffer::GetByte(&array, 24) == 7);
	ASSERT_TRUE(Buffer::GetByte(&array, 28) == 8);
	ASSERT_TRUE(Buffer::GetByte(&array, 32) == 9);
	ASSERT_TRUE(Buffer::GetByte(&array, 36) == 10);
	ASSERT_TRUE(Buffer::GetByte(&array, 1) == 0);
}
TEST(BufferTests, SetByteTest) {
	Array	array(Int32Type, 10);
	Int32	intData[] = { 1,2,3,4,5,6,7,8,9,10 };
	array.Initialize(intData);
	Buffer::SetByte(&array, 1, 1);
	ASSERT_TRUE(*(Int32*)array.Address(0) == 256 + 1);
	Buffer::SetByte(&array, 37, 1);
	ASSERT_TRUE(*(Int32*)array.Address(9) == 256 + 10);
}
