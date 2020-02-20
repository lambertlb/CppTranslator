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

TEST(StringbuilderTests, ConstructorTest) {
	StringBuilder	stringBuilder;
	ASSERT_TRUE(stringBuilder.IsInternal());
	ASSERT_TRUE(stringBuilder.get_Capacity() == DefaultCapacity);
	ASSERT_TRUE(stringBuilder.get_Length() == 0);
	ASSERT_TRUE(stringBuilder.get_MaxCapacity() == MaximumCapacity);
}

TEST(StringbuilderTests, ConstructorTest2) {
	StringBuilder	stringBuilder(50);
	ASSERT_TRUE(stringBuilder.IsInternal());
	ASSERT_TRUE(stringBuilder.get_Capacity() == 50);
	ASSERT_TRUE(stringBuilder.get_Length() == 0);
	ASSERT_TRUE(stringBuilder.get_MaxCapacity() == MaximumCapacity);
}

TEST(StringbuilderTests, ConstructorTest3) {
	StringBuilder	stringBuilder(50, 100);
	ASSERT_TRUE(stringBuilder.IsInternal());
	ASSERT_TRUE(stringBuilder.get_Capacity() == 50);
	ASSERT_TRUE(stringBuilder.get_Length() == 0);
	ASSERT_TRUE(stringBuilder.get_MaxCapacity() == 100);
}

TEST(StringbuilderTests, ConstructorTest4) {
	StringBuilder	stringBuilder(256);
	ASSERT_TRUE(!stringBuilder.IsInternal());
	ASSERT_TRUE(stringBuilder.get_Capacity() == 256);
	ASSERT_TRUE(stringBuilder.get_Length() == 0);
	ASSERT_TRUE(stringBuilder.get_MaxCapacity() == MaximumCapacity);
}

TEST(StringbuilderTests, ConstructorTest5) {
	String str(L"TESTING");
	StringBuilder	stringBuilder(&str);
	ASSERT_TRUE(stringBuilder.IsInternal());
	ASSERT_TRUE(stringBuilder.get_Capacity() == DefaultCapacity);
	ASSERT_TRUE(stringBuilder.get_Length() == 7);
	ASSERT_TRUE(stringBuilder.get_MaxCapacity() == MaximumCapacity);
}

TEST(StringbuilderTests, ConstructorTest6) {
	String str(L"TESTING");
	StringBuilder	stringBuilder(&str, 100);
	ASSERT_TRUE(stringBuilder.IsInternal());
	ASSERT_TRUE(stringBuilder.get_Capacity() == 100);
	ASSERT_TRUE(stringBuilder.get_Length() == 7);
	ASSERT_TRUE(stringBuilder.get_MaxCapacity() == MaximumCapacity);
}

TEST(StringbuilderTests, ConstructorTest7) {
	String str(L"TESTING");
	StringBuilder	stringBuilder(&str, 1, 6, 100);
	ASSERT_TRUE(stringBuilder.IsInternal());
	ASSERT_TRUE(stringBuilder.get_Capacity() == 100);
	ASSERT_TRUE(stringBuilder.get_Length() == 6);
	ASSERT_TRUE(stringBuilder.get_MaxCapacity() == MaximumCapacity);
	ASSERT_TRUE(*stringBuilder.Address(0) == 'E');
}

TEST(StringbuilderTests, GetPropertyTest) {
	String str(L"TESTING1234");
	StringBuilder	stringBuilder(&str);
	ASSERT_TRUE(stringBuilder.get_Length() == 11);
	ASSERT_TRUE(stringBuilder.get_Capacity() == DefaultCapacity);
	ASSERT_TRUE(stringBuilder.get_MaxCapacity() == MaximumCapacity);
	ASSERT_TRUE(*stringBuilder.Address(1) == 'E');
}
TEST(StringbuilderTests, SetPropertyTest) {
	String str(L"TESTING1234");
	StringBuilder	stringBuilder(&str);
	stringBuilder.set_Length(7);
	ASSERT_TRUE(stringBuilder.get_Length() == 7);
	ASSERT_TRUE(stringBuilder.get_Capacity() == DefaultCapacity);
	ASSERT_TRUE(stringBuilder.get_MaxCapacity() == MaximumCapacity);
	ASSERT_TRUE(stringBuilder.get_Chars(6) == 'G');
	Boolean hadException = false;
	try {
		ASSERT_TRUE(stringBuilder.get_Chars(7) == 'G');
	}
	catch (IndexOutOfRangeException * ex) {
		hadException = true;
	}
	ASSERT_TRUE(hadException);
	stringBuilder.set_Capacity(256);
	ASSERT_TRUE(!stringBuilder.IsInternal());
	ASSERT_TRUE(stringBuilder.get_Capacity() == 256);
	ASSERT_TRUE(stringBuilder.get_Length() == 7);
	ASSERT_TRUE(stringBuilder.get_Chars(6) == 'G');
	stringBuilder.set_Chars(0, 't');
	ASSERT_TRUE(stringBuilder.get_Chars(0) == 't');
}
TEST(StringbuilderTests, IndexerTest) {
	String str(L"TESTING1234");
	StringBuilder	stringBuilder(&str);
	ASSERT_TRUE(*stringBuilder.Address(0) == 'T');
	Boolean hadException = false;
	try {
		ASSERT_TRUE(*stringBuilder.Address(-1) == 'T');
	}
	catch (IndexOutOfRangeException * ex) {
		hadException = true;
	}
	ASSERT_TRUE(hadException);
	hadException = false;
	try {
		ASSERT_TRUE(*stringBuilder.Address(20) == 'T');
	}
	catch (Exception * ex) {
		hadException = true;
	}
	ASSERT_TRUE(hadException);
}
TEST(StringbuilderTests, EnsureCapacityTest) {
	String str(L"TESTING1234");
	StringBuilder	stringBuilder(&str);
	ASSERT_TRUE(stringBuilder.EnsureCapacity(100) == DefaultCapacity);
	ASSERT_TRUE(stringBuilder.EnsureCapacity(200) == DefaultCapacity * 2);
}
TEST(StringbuilderTests, EqualsTest) {
	String str(L"TESTING1234");
	StringBuilder	stringBuilder(&str);
	StringBuilder	stringBuilder2(&str);
	ASSERT_TRUE(stringBuilder.Equals(&stringBuilder2));
}
TEST(StringbuilderTests, ToStringTest) {
	String str(L"TESTING1234");
	StringBuilder	stringBuilder(&str);
	String* test1 = stringBuilder.ToString();
	ASSERT_TRUE(test1 != nullptr);
	ASSERT_TRUE(test1->get_Length() == 11);
	ASSERT_TRUE(wcscmp(test1->get_Buffer(), L"TESTING1234") == 0);
	String* test2 = stringBuilder.ToString(7, 4);
	ASSERT_TRUE(test2 != nullptr);
	ASSERT_TRUE(test2->get_Length() == 4);
	ASSERT_TRUE(wcscmp(test2->get_Buffer(), L"1234") == 0);
}
TEST(StringbuilderTests, AppendArrayTest) {
	StringBuilder	stringBuilder;
	String str(L"TESTING1234");
	stringBuilder.Append(str.get_Buffer(), str.get_Length());
	ASSERT_TRUE(wcscmp(stringBuilder.get_Buffer(), L"TESTING1234") == 0);
}
TEST(StringbuilderTests, AppendBooleanTest) {
	StringBuilder	stringBuilder;
	stringBuilder.Append(true);
	ASSERT_TRUE(wcscmp(stringBuilder.get_Buffer(), L"True") == 0);
	stringBuilder.set_Length(0);
	stringBuilder.Append(false);
	ASSERT_TRUE(wcscmp(stringBuilder.get_Buffer(), L"False") == 0);
}
TEST(StringbuilderTests, AppendByteTest) {
	StringBuilder	stringBuilder;
	stringBuilder.Append((Byte)2);
	ASSERT_TRUE(wcscmp(stringBuilder.get_Buffer(), L"2") == 0);
}
TEST(StringbuilderTests, AppendDoubleTest) {
	StringBuilder	stringBuilder;
	stringBuilder.Append(3.14159);
	ASSERT_TRUE(wcscmp(stringBuilder.get_Buffer(), L"3.14159") == 0);
}
TEST(StringbuilderTests, AppendInt16Test) {
	StringBuilder	stringBuilder;
	stringBuilder.Append((Int16)3);
	ASSERT_TRUE(wcscmp(stringBuilder.get_Buffer(), L"3") == 0);
}
TEST(StringbuilderTests, AppendInt32Test) {
	StringBuilder	stringBuilder;
	stringBuilder.Append((Int32)4);
	ASSERT_TRUE(wcscmp(stringBuilder.get_Buffer(), L"4") == 0);
}
TEST(StringbuilderTests, AppendInt64Test) {
	StringBuilder	stringBuilder;
	stringBuilder.Append((Int64)5);
	ASSERT_TRUE(wcscmp(stringBuilder.get_Buffer(), L"5") == 0);
}
TEST(StringbuilderTests, AppendObjectTest) {
	StringBuilder	stringBuilder;
	String str(L"TESTING1234");
	stringBuilder.Append((Object*)&str);
	ASSERT_TRUE(wcscmp(stringBuilder.get_Buffer(), L"TESTING1234") == 0);
}
TEST(StringbuilderTests, AppendStringTest) {
	StringBuilder	stringBuilder;
	String str(L"TESTING1234");
	stringBuilder.Append(&str);
	ASSERT_TRUE(wcscmp(stringBuilder.get_Buffer(), L"TESTING1234") == 0);
	stringBuilder.set_Length(0);
	stringBuilder.Append(&str, 7, 4);
	ASSERT_TRUE(wcscmp(stringBuilder.get_Buffer(), L"1234") == 0);
}
TEST(StringbuilderTests, AppendSByteTest) {
	StringBuilder	stringBuilder;
	stringBuilder.Append((SByte)6);
	ASSERT_TRUE(wcscmp(stringBuilder.get_Buffer(), L"6") == 0);
}
TEST(StringbuilderTests, AppendSingleTest) {
	StringBuilder	stringBuilder;
	stringBuilder.Append(555.666F);
	ASSERT_TRUE(wcscmp(stringBuilder.get_Buffer(), L"555.666") == 0);
}
TEST(StringbuilderTests, AppendUInt16Test) {
	StringBuilder	stringBuilder;
	stringBuilder.Append((UInt16)7);
	ASSERT_TRUE(wcscmp(stringBuilder.get_Buffer(), L"7") == 0);
}
TEST(StringbuilderTests, AppendUInt32Test) {
	StringBuilder	stringBuilder;
	stringBuilder.Append((UInt32)8);
	ASSERT_TRUE(wcscmp(stringBuilder.get_Buffer(), L"8") == 0);
}
TEST(StringbuilderTests, AppendUInt64Test) {
	StringBuilder	stringBuilder;
	stringBuilder.Append((UInt64)9);
	ASSERT_TRUE(wcscmp(stringBuilder.get_Buffer(), L"9") == 0);
}
TEST(StringbuilderTests, AppendCharsTest) {
	StringBuilder	stringBuilder;
	stringBuilder.Append(L'A');
	ASSERT_TRUE(wcscmp(stringBuilder.get_Buffer(), L"A") == 0);
	stringBuilder.set_Length(0);
	stringBuilder.Append(L'A', 5);
	ASSERT_TRUE(wcscmp(stringBuilder.get_Buffer(), L"AAAAA") == 0);
}
TEST(StringbuilderTests, AppendFromArrayTest) {
	Array array(CharType, 6);
	Char	data[] = { 'A','B', 'C', 'D', 'E', 'F' };
	array.Initialize(data);
	StringBuilder	stringBuilder;
	stringBuilder.Append(&array);
	ASSERT_TRUE(wcscmp(stringBuilder.get_Buffer(), L"ABCDEF") == 0);
	stringBuilder.set_Length(0);
	stringBuilder.Append(&array, 2, 2);
	ASSERT_TRUE(wcscmp(stringBuilder.get_Buffer(), L"CD") == 0);
}
TEST(StringbuilderTests, RemoveTest) {
	String str(L"TESTING1234");
	StringBuilder	stringBuilder(&str);
	stringBuilder.Remove(4, 3);
	ASSERT_TRUE(wcscmp(stringBuilder.get_Buffer(), L"TEST1234") == 0);
	stringBuilder.Remove(0, 8);
	ASSERT_TRUE(wcscmp(stringBuilder.get_Buffer(), L"") == 0);
}
TEST(StringbuilderTests, InsertBooleanTest) {
	String str(L"TESTING1234");
	StringBuilder	stringBuilder(&str);
	stringBuilder.Insert(7, true);
	ASSERT_TRUE(wcscmp(stringBuilder.get_Buffer(), L"TESTINGTrue1234") == 0);
}
TEST(StringbuilderTests, InsertByteTest) {
	String str(L"TESTING1234");
	StringBuilder	stringBuilder(&str);
	stringBuilder.Insert(7, (Byte)1);
	ASSERT_TRUE(wcscmp(stringBuilder.get_Buffer(), L"TESTING11234") == 0);
}
TEST(StringbuilderTests, InsertCharTest) {
	String str(L"TESTING1234");
	StringBuilder	stringBuilder(&str);
	stringBuilder.Insert(7, (Char)'Z');
	ASSERT_TRUE(wcscmp(stringBuilder.get_Buffer(), L"TESTINGZ1234") == 0);
}
TEST(StringbuilderTests, InsertFromArrayTest) {
	Array array(CharType, 6);
	Char	data[] = { 'A','B', 'C', 'D', 'E', 'F' };
	array.Initialize(data);
	String str(L"TESTING1234");
	StringBuilder	stringBuilder(&str);
	stringBuilder.Insert(7, &array);
	ASSERT_TRUE(wcscmp(stringBuilder.get_Buffer(), L"TESTINGABCDEF1234") == 0);
}
TEST(StringbuilderTests, InsertFromArray2Test) {
	Array array(CharType, 6);
	Char	data[] = { 'A','B', 'C', 'D', 'E', 'F' };
	array.Initialize(data);
	String str(L"TESTING1234");
	StringBuilder	stringBuilder(&str);
	stringBuilder.Insert(7, &array, 2, 2);
	ASSERT_TRUE(wcscmp(stringBuilder.get_Buffer(), L"TESTINGCD1234") == 0);
}
TEST(StringbuilderTests, InsertDoubleTest) {
	String str(L"TESTING1234");
	StringBuilder	stringBuilder(&str);
	stringBuilder.Insert(7, 3.14159);
	ASSERT_TRUE(wcscmp(stringBuilder.get_Buffer(), L"TESTING3.141591234") == 0);
}
TEST(StringbuilderTests, InsertInt16Test) {
	String str(L"TESTING1234");
	StringBuilder	stringBuilder(&str);
	stringBuilder.Insert(7, (Int16)5);
	ASSERT_TRUE(wcscmp(stringBuilder.get_Buffer(), L"TESTING51234") == 0);
}
TEST(StringbuilderTests, InsertInt32Test) {
	String str(L"TESTING1234");
	StringBuilder	stringBuilder(&str);
	stringBuilder.Insert(7, (Int32)6);
	ASSERT_TRUE(wcscmp(stringBuilder.get_Buffer(), L"TESTING61234") == 0);
}
TEST(StringbuilderTests, InsertInt64Test) {
	String str(L"TESTING1234");
	StringBuilder	stringBuilder(&str);
	stringBuilder.Insert(7, (Int64)7);
	ASSERT_TRUE(wcscmp(stringBuilder.get_Buffer(), L"TESTING71234") == 0);
}
TEST(StringbuilderTests, InsertObjectTest) {
	String str(L"TESTING1234");
	StringBuilder	stringBuilder(&str);
	String str2(L"GG");
	stringBuilder.Insert(7, (Object*)&str2);
	ASSERT_TRUE(wcscmp(stringBuilder.get_Buffer(), L"TESTINGGG1234") == 0);
}
TEST(StringbuilderTests, InsertStringTest) {
	String str(L"TESTING1234");
	StringBuilder	stringBuilder(&str);
	String str2(L"GG");
	stringBuilder.Insert(7, &str2);
	ASSERT_TRUE(wcscmp(stringBuilder.get_Buffer(), L"TESTINGGG1234") == 0);
}
TEST(StringbuilderTests, InsertString2Test) {
	String str(L"TESTING1234");
	StringBuilder	stringBuilder(&str);
	String str2(L"GG");
	stringBuilder.Insert(7, &str2, 3);
	ASSERT_TRUE(wcscmp(stringBuilder.get_Buffer(), L"TESTINGGGGGGG1234") == 0);
}
TEST(StringbuilderTests, InsertSByteTest) {
	String str(L"TESTING1234");
	StringBuilder	stringBuilder(&str);
	stringBuilder.Insert(7, (SByte)8);
	ASSERT_TRUE(wcscmp(stringBuilder.get_Buffer(), L"TESTING81234") == 0);
}
TEST(StringbuilderTests, InsertSingleTest) {
	String str(L"TESTING1234");
	StringBuilder	stringBuilder(&str);
	stringBuilder.Insert(7, 55.5678F);
	ASSERT_TRUE(wcscmp(stringBuilder.get_Buffer(), L"TESTING55.56781234") == 0);
}
TEST(StringbuilderTests, InsertUInt16Test) {
	String str(L"TESTING1234");
	StringBuilder	stringBuilder(&str);
	stringBuilder.Insert(7, (UInt16)9);
	ASSERT_TRUE(wcscmp(stringBuilder.get_Buffer(), L"TESTING91234") == 0);
}
TEST(StringbuilderTests, InsertUInt32Test) {
	String str(L"TESTING1234");
	StringBuilder	stringBuilder(&str);
	stringBuilder.Insert(7, (UInt32)10);
	ASSERT_TRUE(wcscmp(stringBuilder.get_Buffer(), L"TESTING101234") == 0);
}
TEST(StringbuilderTests, InsertUInt64Test) {
	String str(L"TESTING1234");
	StringBuilder	stringBuilder(&str);
	stringBuilder.Insert(7, (UInt64)11);
	ASSERT_TRUE(wcscmp(stringBuilder.get_Buffer(), L"TESTING111234") == 0);
}
TEST(StringbuilderTests, ReplaceStringTest) {
	String str(L"The quick brown dog jumps over the lazy dog");
	String dog(L"dog");
	String cat(L"kitten");
	StringBuilder	stringBuilder(&str);
	stringBuilder.Replace(&dog, &cat);
	ASSERT_TRUE(wcscmp(stringBuilder.get_Buffer(), L"The quick brown kitten jumps over the lazy kitten") == 0);
}
TEST(StringbuilderTests, ReplaceString2Test) {
	String str(L"The dog brown dog jumps over the lazy dog");
	String dog(L"dog");
	String cat(L"kitten");
	StringBuilder	stringBuilder(&str);
	stringBuilder.Replace(&dog, &cat, 10, 10);
	ASSERT_TRUE(wcscmp(stringBuilder.get_Buffer(), L"The dog brown kitten jumps over the lazy dog") == 0);
}
TEST(StringbuilderTests, ReplaceString3Test) {
	String str(L"The dog brown dog jumps over the lazy dog");
	String dog(L"dog");
	String cat(L"");
	StringBuilder	stringBuilder(&str);
	stringBuilder.Replace(&dog, &cat);
	ASSERT_TRUE(wcscmp(stringBuilder.get_Buffer(), L"The  brown  jumps over the lazy ") == 0);
}
TEST(StringbuilderTests, ReplaceString4Test) {
	String str(L"BCCCCCCCBA");
	String str2(L"CCC");
	String str3(L"DDD");
	StringBuilder	stringBuilder(&str);
	stringBuilder.Replace(&str2, &str3, 2, 5);
	ASSERT_TRUE(wcscmp(stringBuilder.get_Buffer(), L"BCDDDCCCBA") == 0);
}
TEST(StringbuilderTests, ReplaceCharsTest) {
	String str(L"The quick #brown dog jumps over the lazy #dog#");
	StringBuilder	stringBuilder(&str);
	stringBuilder.Replace(L'#', L'-');
	ASSERT_TRUE(wcscmp(stringBuilder.get_Buffer(), L"The quick -brown dog jumps over the lazy -dog-") == 0);
}
TEST(StringbuilderTests, ReplaceChars2Test) {
	String str(L"The quick #brown dog jumps over the #lazy #dog#");
	StringBuilder	stringBuilder(&str);
	stringBuilder.Replace(L'#', L'-', 5, 15);
	ASSERT_TRUE(wcscmp(stringBuilder.get_Buffer(), L"The quick -brown dog jumps over the #lazy #dog#") == 0);
}
