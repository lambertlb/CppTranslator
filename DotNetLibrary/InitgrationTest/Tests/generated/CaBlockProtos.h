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
	class typedefRaw;
	typedef PointerType<typedefRaw>	x_typedef;
	class typedef1Raw;
	typedef PointerType<typedef1Raw>	x_typedef1;
}
namespace CABlock_Extra_NS
{
	class TestNamespaceClassRaw;
	typedef PointerType<TestNamespaceClassRaw>	TestNamespaceClass;
}
namespace CABlock_NS
{
	class ArrayTestRaw;
	typedef PointerType<ArrayTestRaw>	ArrayTest;
	class BasicTestRaw;
	typedef PointerType<BasicTestRaw>	BasicTest;
	class TestAbstractRaw;
	typedef PointerType<TestAbstractRaw>	TestAbstract;
	struct TestStruct;	struct TestStruct2;	struct TestStruct3;	class AbstractRaw;
	typedef PointerType<AbstractRaw>	Abstract;
	class BigEndianBitConverterTestRaw;
	typedef PointerType<BigEndianBitConverterTestRaw>	BigEndianBitConverterTest;
	class BooleanTestRaw;
	typedef PointerType<BooleanTestRaw>	BooleanTest;
	class BufferTestRaw;
	typedef PointerType<BufferTestRaw>	BufferTest;
	class ByteTestRaw;
	typedef PointerType<ByteTestRaw>	ByteTest;
	class CharTestRaw;
	typedef PointerType<CharTestRaw>	CharTest;
	class DoubleTestRaw;
	typedef PointerType<DoubleTestRaw>	DoubleTest;
	class EncodingTestRaw;
	typedef PointerType<EncodingTestRaw>	EncodingTest;
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
	class EnumTestRaw;
	typedef PointerType<EnumTestRaw>	EnumTest;
	enum FredEnum
	{
		FredValue1_FredEnum = 1,
		FredValue2_FredEnum = 2,
		FredValue3_FredEnum = 5
	};
	class CABlockRaw;
	typedef PointerType<CABlockRaw>	CABlock;
	class Int16TestRaw;
	typedef PointerType<Int16TestRaw>	Int16Test;
	class Int32TestRaw;
	typedef PointerType<Int32TestRaw>	Int32Test;
	class Int64TestRaw;
	typedef PointerType<Int64TestRaw>	Int64Test;
	class MathTestRaw;
	typedef PointerType<MathTestRaw>	MathTest;
	class SByteTestRaw;
	typedef PointerType<SByteTestRaw>	SByteTest;
	class SingleTestRaw;
	typedef PointerType<SingleTestRaw>	SingleTest;
	class StringBuilderTestRaw;
	typedef PointerType<StringBuilderTestRaw>	StringBuilderTest;
	class StringTestRaw;
	typedef PointerType<StringTestRaw>	StringTest;
	class TimeTestRaw;
	typedef PointerType<TimeTestRaw>	TimeTest;
	class TimingTestRaw;
	typedef PointerType<TimingTestRaw>	TimingTest;
	class UInt16TestRaw;
	typedef PointerType<UInt16TestRaw>	UInt16Test;
	class UInt32TestRaw;
	typedef PointerType<UInt32TestRaw>	UInt32Test;
	class UInt64TestRaw;
	typedef PointerType<UInt64TestRaw>	UInt64Test;
}
