#include "gtest/gtest.h"
#include <DotnetTypes.h>

using namespace DotnetLibrary;

TEST(StringbuilderTests, ConstructorTest) {
	StringBuilder	stringBuilder;
	ASSERT_TRUE(stringBuilder.chunkChars == stringBuilder.internalMemory);
	ASSERT_TRUE(stringBuilder.chunkLength == DefaultCapacity);
	ASSERT_TRUE(stringBuilder.chunkOffset == 0);
	ASSERT_TRUE(stringBuilder.maxCapacity == Int32Value::MaxValue);
}

TEST(StringbuilderTests, ConstructorTest2) {
	StringBuilder	stringBuilder(50);
	ASSERT_TRUE(stringBuilder.chunkChars == stringBuilder.internalMemory);
	ASSERT_TRUE(stringBuilder.chunkLength == 50);
	ASSERT_TRUE(stringBuilder.chunkOffset == 0);
	ASSERT_TRUE(stringBuilder.maxCapacity == Int32Value::MaxValue);
}

TEST(StringbuilderTests, ConstructorTest3) {
	StringBuilder	stringBuilder(50, 100);
	ASSERT_TRUE(stringBuilder.chunkChars == stringBuilder.internalMemory);
	ASSERT_TRUE(stringBuilder.chunkLength == 50);
	ASSERT_TRUE(stringBuilder.chunkOffset == 0);
	ASSERT_TRUE(stringBuilder.maxCapacity == 100);
}

TEST(StringbuilderTests, ConstructorTest4) {
	StringBuilder	stringBuilder(256);
	ASSERT_TRUE(stringBuilder.chunkChars != stringBuilder.internalMemory);
	ASSERT_TRUE(stringBuilder.chunkLength == 256);
	ASSERT_TRUE(stringBuilder.chunkOffset == 0);
	ASSERT_TRUE(stringBuilder.maxCapacity == Int32Value::MaxValue);
}

TEST(StringbuilderTests, ConstructorTest5) {
	String str(L"TESTING");
	StringBuilder	stringBuilder(&str);
	ASSERT_TRUE(stringBuilder.chunkChars == stringBuilder.internalMemory);
	ASSERT_TRUE(stringBuilder.chunkLength == DefaultCapacity);
	ASSERT_TRUE(stringBuilder.chunkOffset == 7);
	ASSERT_TRUE(stringBuilder.maxCapacity == Int32Value::MaxValue);
}

TEST(StringbuilderTests, ConstructorTest6) {
	String str(L"TESTING");
	StringBuilder	stringBuilder(&str, 100);
	ASSERT_TRUE(stringBuilder.chunkChars == stringBuilder.internalMemory);
	ASSERT_TRUE(stringBuilder.chunkLength == 100);
	ASSERT_TRUE(stringBuilder.chunkOffset == 7);
	ASSERT_TRUE(stringBuilder.maxCapacity == Int32Value::MaxValue);
}

TEST(StringbuilderTests, ConstructorTest7) {
	String str(L"TESTING");
	StringBuilder	stringBuilder(&str, 1, 6, 100);
	ASSERT_TRUE(stringBuilder.chunkChars == stringBuilder.internalMemory);
	ASSERT_TRUE(stringBuilder.chunkLength == 100);
	ASSERT_TRUE(stringBuilder.chunkOffset == 6);
	ASSERT_TRUE(stringBuilder.maxCapacity == Int32Value::MaxValue);
	ASSERT_TRUE(stringBuilder.chunkChars[0] == 'E');
}

TEST(StringbuilderTests, GetPropertyTest) {
	String str(L"TESTING1234");
	StringBuilder	stringBuilder(&str);
	ASSERT_TRUE(stringBuilder.get_Length() == 11);
	ASSERT_TRUE(stringBuilder.get_Capacity() == DefaultCapacity);
	ASSERT_TRUE(stringBuilder.get_MaxCapacity() == Int32Value::MaxValue);
	ASSERT_TRUE(stringBuilder.get_Chars(1) == 'E');
}
TEST(StringbuilderTests, SetPropertyTest) {
	String str(L"TESTING1234");
	StringBuilder	stringBuilder(&str);
	stringBuilder.set_Length(7);
	ASSERT_TRUE(stringBuilder.get_Length() == 7);
	ASSERT_TRUE(stringBuilder.get_Capacity() == DefaultCapacity);
	ASSERT_TRUE(stringBuilder.get_MaxCapacity() == Int32Value::MaxValue);
	ASSERT_TRUE(stringBuilder.get_Chars(6) == 'G');
	Boolean hadException = false;
	try {
		ASSERT_TRUE(stringBuilder.get_Chars(7) == 'G');
	}
	catch (IndexOutOfRangeException* ex) {
		hadException = true;
	}
	ASSERT_TRUE(hadException);
	stringBuilder.set_Capacity(256);
	ASSERT_TRUE(stringBuilder.chunkChars != stringBuilder.internalMemory);
	ASSERT_TRUE(stringBuilder.chunkLength == 256);
	ASSERT_TRUE(stringBuilder.get_Length() == 7);
	ASSERT_TRUE(stringBuilder.get_Chars(6) == 'G');
	stringBuilder.set_Chars(0, 't');
	ASSERT_TRUE(stringBuilder.get_Chars(0) == 't');
}
TEST(StringbuilderTests, IndexerTest) {
	String str(L"TESTING1234");
	StringBuilder	stringBuilder(&str);
	ASSERT_TRUE(stringBuilder.Address(0) == stringBuilder.chunkChars);
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
	ASSERT_TRUE(stringBuilder.EnsureCapacity(200) == 200);
}
TEST(StringbuilderTests, ToStringTest) {
	String str(L"TESTING1234");
	StringBuilder	stringBuilder(&str);
	String* test1 = stringBuilder.ToString();
	ASSERT_TRUE(test1 != nullptr);
	ASSERT_TRUE(test1->length == 11);
	ASSERT_TRUE(wcscmp(test1->characterData,L"TESTING1234") == 0);
	String* test2 = stringBuilder.ToString(7,4);
	ASSERT_TRUE(test2 != nullptr);
	ASSERT_TRUE(test2->length == 4);
	ASSERT_TRUE(wcscmp(test2->characterData, L"1234") == 0);
}
TEST(StringbuilderTests, AppendArrayTest) {
	StringBuilder	stringBuilder;
	String str(L"TESTING1234");
	stringBuilder.Append(str.characterData, str.length);
	ASSERT_TRUE(wcscmp(stringBuilder.chunkChars, L"TESTING1234") == 0);
}
TEST(StringbuilderTests, AppendBooleanTest) {
	StringBuilder	stringBuilder;
	stringBuilder.Append(true);
	ASSERT_TRUE(wcscmp(stringBuilder.chunkChars, L"true") == 0);
	stringBuilder.set_Length(0);
	stringBuilder.Append(false);
	ASSERT_TRUE(wcscmp(stringBuilder.chunkChars, L"false") == 0);
}
TEST(StringbuilderTests, AppendByteTest) {
	StringBuilder	stringBuilder;
	stringBuilder.Append((Byte)2);
	ASSERT_TRUE(wcscmp(stringBuilder.chunkChars, L"2") == 0);
}
TEST(StringbuilderTests, AppendDoubleTest) {
	StringBuilder	stringBuilder;
	stringBuilder.Append(3.14159);
	ASSERT_TRUE(wcscmp(stringBuilder.chunkChars, L"3.14159") == 0);
}
TEST(StringbuilderTests, AppendInt16Test) {
	StringBuilder	stringBuilder;
	stringBuilder.Append((Int16)3);
	ASSERT_TRUE(wcscmp(stringBuilder.chunkChars, L"3") == 0);
}
TEST(StringbuilderTests, AppendInt32Test) {
	StringBuilder	stringBuilder;
	stringBuilder.Append((Int32)4);
	ASSERT_TRUE(wcscmp(stringBuilder.chunkChars, L"4") == 0);
}
TEST(StringbuilderTests, AppendInt64Test) {
	StringBuilder	stringBuilder;
	stringBuilder.Append((Int64)5);
	ASSERT_TRUE(wcscmp(stringBuilder.chunkChars, L"5") == 0);
}
TEST(StringbuilderTests, AppendObjectTest) {
	StringBuilder	stringBuilder;
	String str(L"TESTING1234");
	stringBuilder.Append((Object*)&str);
	ASSERT_TRUE(wcscmp(stringBuilder.chunkChars, L"TESTING1234") == 0);
}
TEST(StringbuilderTests, AppendStringTest) {
	StringBuilder	stringBuilder;
	String str(L"TESTING1234");
	stringBuilder.Append(&str);
	ASSERT_TRUE(wcscmp(stringBuilder.chunkChars, L"TESTING1234") == 0);
	stringBuilder.set_Length(0);
	stringBuilder.Append(&str, 7, 4);
	ASSERT_TRUE(wcscmp(stringBuilder.chunkChars, L"1234") == 0);
}
TEST(StringbuilderTests, AppendSByteTest) {
	StringBuilder	stringBuilder;
	stringBuilder.Append((SByte)6);
	ASSERT_TRUE(wcscmp(stringBuilder.chunkChars, L"6") == 0);
}
TEST(StringbuilderTests, AppendSingleTest) {
	StringBuilder	stringBuilder;
	stringBuilder.Append(555.666F);
	ASSERT_TRUE(wcscmp(stringBuilder.chunkChars, L"555.666") == 0);
}
TEST(StringbuilderTests, AppendUInt16Test) {
	StringBuilder	stringBuilder;
	stringBuilder.Append((UInt16)7);
	ASSERT_TRUE(wcscmp(stringBuilder.chunkChars, L"7") == 0);
}
TEST(StringbuilderTests, AppendUInt32Test) {
	StringBuilder	stringBuilder;
	stringBuilder.Append((UInt32)8);
	ASSERT_TRUE(wcscmp(stringBuilder.chunkChars, L"8") == 0);
}
TEST(StringbuilderTests, AppendUInt64Test) {
	StringBuilder	stringBuilder;
	stringBuilder.Append((UInt64)9);
	ASSERT_TRUE(wcscmp(stringBuilder.chunkChars, L"9") == 0);
}
TEST(StringbuilderTests, AppendCharsTest) {
	StringBuilder	stringBuilder;
	stringBuilder.Append(L'A');
	ASSERT_TRUE(wcscmp(stringBuilder.chunkChars, L"A") == 0);
	stringBuilder.set_Length(0);
	stringBuilder.Append(L'A', 5);
	ASSERT_TRUE(wcscmp(stringBuilder.chunkChars, L"AAAAA") == 0);
}
TEST(StringbuilderTests, AppendFromArrayTest) {
	Array array(CharType, 6);
	Char	data[] = {'A','B', 'C', 'D', 'E', 'F'};
	array.Initialize(data);
	StringBuilder	stringBuilder;
	stringBuilder.Append(&array);
	ASSERT_TRUE(wcscmp(stringBuilder.chunkChars, L"ABCDEF") == 0);
	stringBuilder.set_Length(0);
	stringBuilder.Append(&array, 2, 2);
	ASSERT_TRUE(wcscmp(stringBuilder.chunkChars, L"CD") == 0);
}
TEST(StringbuilderTests, RemoveTest) {
	String str(L"TESTING1234");
	StringBuilder	stringBuilder(&str);
	stringBuilder.Remove(4,3);
	ASSERT_TRUE(wcscmp(stringBuilder.chunkChars, L"TEST1234") == 0);
	stringBuilder.Remove(0, 8);
	ASSERT_TRUE(wcscmp(stringBuilder.chunkChars, L"") == 0);
}
TEST(StringbuilderTests, InsertBooleanTest) {
	String str(L"TESTING1234");
	StringBuilder	stringBuilder(&str);
	stringBuilder.Insert(7, true);
	ASSERT_TRUE(wcscmp(stringBuilder.chunkChars, L"TESTINGtrue1234") == 0);
}
TEST(StringbuilderTests, InsertByteTest) {
	String str(L"TESTING1234");
	StringBuilder	stringBuilder(&str);
	stringBuilder.Insert(7, (Byte)1);
	ASSERT_TRUE(wcscmp(stringBuilder.chunkChars, L"TESTING11234") == 0);
}
TEST(StringbuilderTests, InsertCharTest) {
	String str(L"TESTING1234");
	StringBuilder	stringBuilder(&str);
	stringBuilder.Insert(7, (Char)'Z');
	ASSERT_TRUE(wcscmp(stringBuilder.chunkChars, L"TESTINGZ1234") == 0);
}
TEST(StringbuilderTests, InsertFromArrayTest) {
	Array array(CharType, 6);
	Char	data[] = { 'A','B', 'C', 'D', 'E', 'F' };
	array.Initialize(data);
	String str(L"TESTING1234");
	StringBuilder	stringBuilder(&str);
	stringBuilder.Insert(7, &array);
	ASSERT_TRUE(wcscmp(stringBuilder.chunkChars, L"TESTINGABCDEF1234") == 0);
}
TEST(StringbuilderTests, InsertFromArray2Test) {
	Array array(CharType, 6);
	Char	data[] = { 'A','B', 'C', 'D', 'E', 'F' };
	array.Initialize(data);
	String str(L"TESTING1234");
	StringBuilder	stringBuilder(&str);
	stringBuilder.Insert(7, &array, 2, 2);
	ASSERT_TRUE(wcscmp(stringBuilder.chunkChars, L"TESTINGCD1234") == 0);
}
TEST(StringbuilderTests, InsertDoubleTest) {
	String str(L"TESTING1234");
	StringBuilder	stringBuilder(&str);
	stringBuilder.Insert(7, 3.14159);
	ASSERT_TRUE(wcscmp(stringBuilder.chunkChars, L"TESTING3.141591234") == 0);
}
TEST(StringbuilderTests, InsertInt16Test) {
	String str(L"TESTING1234");
	StringBuilder	stringBuilder(&str);
	stringBuilder.Insert(7, (Int16)5);
	ASSERT_TRUE(wcscmp(stringBuilder.chunkChars, L"TESTING51234") == 0);
}
TEST(StringbuilderTests, InsertInt32Test) {
	String str(L"TESTING1234");
	StringBuilder	stringBuilder(&str);
	stringBuilder.Insert(7, (Int32)6);
	ASSERT_TRUE(wcscmp(stringBuilder.chunkChars, L"TESTING61234") == 0);
}
TEST(StringbuilderTests, InsertInt64Test) {
	String str(L"TESTING1234");
	StringBuilder	stringBuilder(&str);
	stringBuilder.Insert(7, (Int64)7);
	ASSERT_TRUE(wcscmp(stringBuilder.chunkChars, L"TESTING71234") == 0);
}
TEST(StringbuilderTests, InsertObjectTest) {
	String str(L"TESTING1234");
	StringBuilder	stringBuilder(&str);
	String str2(L"GG");
	stringBuilder.Insert(7, (Object*)&str2);
	ASSERT_TRUE(wcscmp(stringBuilder.chunkChars, L"TESTINGGG1234") == 0);
}
TEST(StringbuilderTests, InsertStringTest) {
	String str(L"TESTING1234");
	StringBuilder	stringBuilder(&str);
	String str2(L"GG");
	stringBuilder.Insert(7, &str2);
	ASSERT_TRUE(wcscmp(stringBuilder.chunkChars, L"TESTINGGG1234") == 0);
}
TEST(StringbuilderTests, InsertString2Test) {
	String str(L"TESTING1234");
	StringBuilder	stringBuilder(&str);
	String str2(L"GG");
	stringBuilder.Insert(7, &str2, 3);
	ASSERT_TRUE(wcscmp(stringBuilder.chunkChars, L"TESTINGGGGGGG1234") == 0);
}
TEST(StringbuilderTests, InsertSByteTest) {
	String str(L"TESTING1234");
	StringBuilder	stringBuilder(&str);
	stringBuilder.Insert(7, (SByte)8);
	ASSERT_TRUE(wcscmp(stringBuilder.chunkChars, L"TESTING81234") == 0);
}
TEST(StringbuilderTests, InsertSingleTest) {
	String str(L"TESTING1234");
	StringBuilder	stringBuilder(&str);
	stringBuilder.Insert(7, 55.5678F);
	ASSERT_TRUE(wcscmp(stringBuilder.chunkChars, L"TESTING55.56781234") == 0);
}
TEST(StringbuilderTests, InsertUInt16Test) {
	String str(L"TESTING1234");
	StringBuilder	stringBuilder(&str);
	stringBuilder.Insert(7, (UInt16)9);
	ASSERT_TRUE(wcscmp(stringBuilder.chunkChars, L"TESTING91234") == 0);
}
TEST(StringbuilderTests, InsertUInt32Test) {
	String str(L"TESTING1234");
	StringBuilder	stringBuilder(&str);
	stringBuilder.Insert(7, (UInt32)10);
	ASSERT_TRUE(wcscmp(stringBuilder.chunkChars, L"TESTING101234") == 0);
}
TEST(StringbuilderTests, InsertUInt64Test) {
	String str(L"TESTING1234");
	StringBuilder	stringBuilder(&str);
	stringBuilder.Insert(7, (UInt64)11);
	ASSERT_TRUE(wcscmp(stringBuilder.chunkChars, L"TESTING111234") == 0);
}
