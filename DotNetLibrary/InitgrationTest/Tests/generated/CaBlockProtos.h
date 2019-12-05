#pragma once
#include "DotnetTypes.h"
using namespace DotnetLibrary;

namespace UNNAMED
{
	enum TestNameEnu
	{
		x_friend_TestNameEnu,
		x_enemy_TestNameEnu
	};

	class x_typedef;
	class x_typedef1;
}
namespace CABlock_Extra_NS
{
	class TestNamespaceClass;
}
namespace CABlock_NS
{
	class ArrayTest;
	class BasicTest;
	class TestAbstract;
	struct TestStruct;
	struct TestStruct2;
	struct TestStruct3;
	class Abstract;
	class BigEndianBitConverterTest;
	class BooleanTest;
	class BufferTest;
	class ByteTest;
	class CharTest;
	class DoubleTest;
	class EncodingTest;
	enum TestEnum
	{
		Value1_TestEnum = 1,
		Value2_TestEnum = 2,
		Value3_TestEnum = 5
	};

	enum TestEnum2
	{
		Value1_TestEnum2 = 1,
		Value2_TestEnum2 = 2,
		Value3_TestEnum2 = 5
	};

	class EnumTest;
	enum FredEnum
	{
		FredValue1_FredEnum = 1,
		FredValue2_FredEnum = 2,
		FredValue3_FredEnum = 5
	};

	class CABlock;
	class Int16Test;
	class Int32Test;
	class Int64Test;
	class MathTest;
	class SByteTest;
	class SingleTest;
	class StringBuilderTest;
	class StringTest;
	class TimeTest;
	class TimingTest;
	class UInt16Test;
	class UInt32Test;
	class UInt64Test;
}
