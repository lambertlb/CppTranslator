#pragma once
#include "CaBlockProtos.h"
namespace CABlock_NS
{
	struct TestStruct : public ObjectRaw
	{
		Int32 x_data;
		Int32 get_Data();
		void set_Data(Int32 x_value );
		TestStruct(Int32 x_i);
		friend TestStruct operator +(TestStruct x_ts,Int32 x_newData);
		friend TestStruct operator &(TestStruct x_ts,Int32 x_newData);
	};
	struct TestStruct2 : public ObjectRaw
	{
		Int32 x_data;
		TestStruct2();
	};
	struct TestStruct3 : public ObjectRaw
	{
		TestStruct2 x_ts;
		TestStruct3();
	};
}
namespace UNNAMED
{
	class typedefRaw : public ObjectRaw
	{
		public:
		TestNameEnu x_friend;
		TestNameEnu get_Friend();
		void set_Friend(TestNameEnu x_value );
		typedefRaw();
	};
	class typedef1Raw : public ObjectRaw
	{
		public:
		TestNameEnu x_friend();
		typedef1Raw();
	};
}
namespace CABlock_Extra_NS
{
	class TestNamespaceClassRaw : public ObjectRaw
	{
		public:
		TestNamespaceClassRaw();
	};
}
namespace CABlock_NS
{
	class ArrayTestRaw : public ObjectRaw
	{
		public:
		CABlock x_caBlock;
		PointerType<ArrayRaw<Boolean>> x_boolArray;
		PointerType<ArrayRaw<Int32>> x_int1dArray;
		PointerType<ArrayRaw<Int32>> x_int2dArray;
		PointerType<ArrayRaw<Int32>> x_int3dArray;
		PointerType<ArrayRaw<Double>> x_double1dArray;
		PointerType<ArrayRaw<Double>> x_double2dArray;
		PointerType<ArrayRaw<Double>> x_double3dArray;
		PointerType<ArrayRaw<DateTime>> x_dateTime1dArray;
		PointerType<ArrayRaw<DateTime>> x_dateTime2dArray;
		PointerType<ArrayRaw<DateTime>> x_dateTime3dArray;
		PointerType<ArrayRaw<TimeSpan>> x_timeSpan1dArray;
		PointerType<ArrayRaw<TimeSpan>> x_timeSpan2dArray;
		PointerType<ArrayRaw<TimeSpan>> x_timeSpan3dArray;
		ArrayTestRaw(CABlock x_caBlock);
		void Test();
		void TestArrayCreation();
		void MiscTest();
		void ArrayMethodTests();
		void CxAssert(Boolean x_x);
	};
	class BasicTestRaw : public ObjectRaw
	{
		public:
		CABlock x_caBlock;
		Int32 x_field1;
		TestStruct3 x_ts3;
		BasicTestRaw(CABlock x_caBlock);
		void Test();
		void FieldTest();
		void SwitchTest();
		void IfThenElseTest();
		void StructTest();
		void StructTest2();
		void VirtualMethodTest();
		void PassByReferenceTest();
		void RefMethod(Int32&  x_data);
		void RefMethod(DateTime&  x_data);
		void RefMethod(TimeSpan&  x_data);
		void RefMethod(String&  x_data);
		void RefMethod(TestAbstract&  x_data);
		void TestUsingNamespace();
		void CxAssert(Boolean x_x);
		void ComplexConditions();
		Boolean TestThis(Int32 x_a,Int32 x_b);
		void TestNames();
	};
	class AbstractRaw : public ObjectRaw
	{
		public:
		Int32 x_data1;
		Int32 x_data2;
		AbstractRaw(Int32 x_i,Int32 x_j);
		virtual Int32 MustImplement() = 0;
		virtual Int32 MustImplement(Int32 x_i) = 0;
		virtual Int32 MustImplement(Int64 x_i) = 0;
		Int32 DidImplement();
	};
	class TestAbstractRaw : public AbstractRaw
	{
		public:
		TestAbstractRaw();
		Int32 MustImplement();
		Int32 MustImplement(Int32 x_i);
		Int32 MustImplement(Int64 x_i);
		String ToString();
	};
	class BigEndianBitConverterTestRaw : public ObjectRaw
	{
		public:
		CABlock x_caBlock;
		BigEndianBitConverterTestRaw(CABlock x_caBlock);
		void Test();
		void CompareBits(PointerType<ArrayRaw<Byte>> x_converted,Int32 x_startingIndex,PointerType<ArrayRaw<Byte>> x_bytes);
		void CxAssert(Boolean x_x);
		void CxAssert(Boolean x_x,Boolean x_y);
	};
	class BooleanTestRaw : public ObjectRaw
	{
		public:
		CABlock x_caBlock;
		BooleanTestRaw(CABlock x_caBlock);
		void Test();
		void BoolBoxTest();
		void RunBooleanTest();
		void BoolOperators();
		void CxAssert(Boolean x_x,Boolean x_y);
		void CxAssert(Boolean x_x);
	};
	class BufferTestRaw : public ObjectRaw
	{
		public:
		CABlock x_caBlock;
		PointerType<ArrayRaw<Int32>> x_in1dArray;
		PointerType<ArrayRaw<Int32>> x_out1dArray;
		BufferTestRaw(CABlock x_caBlock);
		void Test();
		void CxAssert(Boolean x_x);
	};
	class ByteTestRaw : public ObjectRaw
	{
		public:
		CABlock x_caBlock;
		ByteTestRaw(CABlock x_caBlock);
		void Test();
		void ByteMethodsTest();
		void DoUnSignedMath();
		void ByteOperators();
		void ByteArrayTests();
		void ByteMiscTests();
		void CxAssert(Boolean x_x);
		void CxAssert(Boolean x_x,Boolean x_y);
	};
	class CharTestRaw : public ObjectRaw
	{
		public:
		CABlock x_caBlock;
		CharTestRaw(CABlock x_caBlock);
		void Test();
		void CharMethodsTest();
		void CharOperators();
		void CharArrayTests();
		void CharMiscTests();
		void CxAssert(Boolean x_x);
		void CxAssert(Boolean x_x,Boolean x_y);
	};
	class DoubleTestRaw : public ObjectRaw
	{
		public:
		CABlock x_caBlock;
		DoubleTestRaw(CABlock x_caBlock);
		void Test();
		void DoDoubleMethodsTest();
		void DoDoubleMath();
		void DoubleOperators();
		void DoubleNanTest();
		void DoubleArrayTest();
		void DoubleMiscTests();
		void DoubleCompare(Double x_n1,Double x_n2,Double x_resolution);
		void CxAssert(Double x_x,Double x_y);
		void CxAssert(Boolean x_x);
		void CxAssert(Boolean x_x,Boolean x_y);
		void DoubleTestFailed();
	};
	class EncodingTestRaw : public ObjectRaw
	{
		public:
		CABlock x_caBlock;
		EncodingTestRaw(CABlock x_caBlock);
		void Test();
		void EncodingMethodsTest();
		Boolean CompareBytes(PointerType<ArrayRaw<Byte>> x_bytes,PointerType<ArrayRaw<Byte>> x_myCharsAsBytes);
		void CxAssert(Boolean x_x);
	};
	class EnumTestRaw : public ObjectRaw
	{
		public:
		CABlock x_caBlock;
		EnumTestRaw(CABlock x_caBlock);
		void Test();
		void Test1(TestEnum x_testEnum);
		void Test1(TestEnum2 x_testEnum);
		void EnumTestFailed();
	};
	class CABlockRaw : public BlockBaseRaw
	{
		public:
		static Int32 x_intConstant;
		FredEnum x_fe;
		CABlockRaw();
		CABlockRaw(Int32 x_i);
		void Initialize();
		void Execute();
		void RunTests(FredEnum x_fre);
		void TestFailed(String x_reason);
	};
	class Int16TestRaw : public ObjectRaw
	{
		public:
		CABlock x_caBlock;
		Int16TestRaw(CABlock x_caBlock);
		void Test();
		void Int16MethodsTest();
		void Int16MathTest();
		void Int16Operators();
		void Int16ArrayTests();
		void Int16MiscTests();
		void CxAssert(Boolean x_x);
		void CxAssert(Boolean x_x,Boolean x_y);
	};
	class Int32TestRaw : public ObjectRaw
	{
		public:
		CABlock x_caBlock;
		Int32TestRaw(CABlock x_caBlock);
		void Test();
		void Int32Conversion();
		void Int32MethodsTest();
		void Int32MathTest();
		void Int32Operators();
		void Int32ArrayTests();
		void Int32MiscTests();
		void CxAssert(Boolean x_x);
		void CxAssert(Boolean x_x,Boolean x_y);
	};
	class Int64TestRaw : public ObjectRaw
	{
		public:
		CABlock x_caBlock;
		Int64TestRaw(CABlock x_caBlock);
		void Test();
		void Int64MethodsTest();
		void Int64MathTest();
		void Int64Operators();
		void Int64ArrayTests();
		void Int64MiscTests();
		void CxAssert(Boolean x_x);
		void CxAssert(Boolean x_x,Boolean x_y);
	};
	class MathTestRaw : public ObjectRaw
	{
		public:
		CABlock x_caBlock;
		MathTestRaw(CABlock x_caBlock);
		void Test();
		void DoMathTest();
		void DoubleCompare(Double x_n1,Double x_n2,Double x_resolution);
		void CxAssert(Double x_x,Double x_y);
		void CxAssert(Boolean x_x);
	};
	class SByteTestRaw : public ObjectRaw
	{
		public:
		CABlock x_caBlock;
		SByteTestRaw(CABlock x_caBlock);
		void Test();
		void SByteMethodsTest();
		void SByteMathTest();
		void SByteOperators();
		void SByteArrayTests();
		void SByteMiscTests();
		void CxAssert(Boolean x_x);
		void CxAssert(Boolean x_x,Boolean x_y);
	};
	class SingleTestRaw : public ObjectRaw
	{
		public:
		CABlock x_caBlock;
		SingleTestRaw(CABlock x_caBlock);
		void Test();
		void DoSingleMethodsTest();
		void DoSingleMath();
		void SingleOperators();
		void SingleNanTest();
		void SingleArrayTest();
		void SingleMiscTests();
		void SingleCompare(Double x_n1,Double x_n2,Double x_resolution);
		void CxAssert(Double x_x,Double x_y);
		void CxAssert(Boolean x_x);
		void CxAssert(Boolean x_x,Boolean x_y);
		void SingleTestFailed();
	};
	class StringBuilderTestRaw : public ObjectRaw
	{
		public:
		CABlock x_caBlock;
		StringBuilder x_sb;
		StringBuilderTestRaw(CABlock x_caBlock);
		void Test();
		void DoSBConstructTest();
		void DoSBPropertyTest();
		void DoSBAppendTest();
		void DoSBMiscTest();
		void DoSBInsertTest();
		void DoSBReplaceTest();
		void CxAssert(Boolean x_x);
		void CxAssert(Boolean x_x,Boolean x_y);
	};
	class StringTestRaw : public ObjectRaw
	{
		public:
		CABlock x_caBlock;
		StringTestRaw(CABlock x_caBlock);
		void Test();
		void DoIndexTest();
		void DoMiscTest();
		static void TestConcat(String x_str1,Int32 x_index,String x_str4,Int32 x_i,Double x_dbl);
		void DoEqualsTest();
		void DoParsingTest();
		void DoConcatTest();
		void CxAssert(Boolean x_x);
	};
	class TimeTestRaw : public ObjectRaw
	{
		public:
		CABlock x_caBlock;
		DateTime x_dat1;
		TimeTestRaw(CABlock x_caBlock);
		void Test();
		void TestTimeSpan();
		void TestDateTime();
		void DateTimeMethodTests();
		void TimeArrayTests();
		void DateTimeArrayTests();
		void TimeSpanArrayTests();
		void CxAssert(Double x_x,Double x_y);
		void CxAssert(Boolean x_x);
		void TimeTestFailed();
	};
	class TimingTestRaw : public ObjectRaw
	{
		public:
		TimingTestRaw();
		static Int32 DoTimingTest(Int32 x_a,Int32 x_b,Int32 x_c);
	};
	class UInt16TestRaw : public ObjectRaw
	{
		public:
		CABlock x_caBlock;
		UInt16TestRaw(CABlock x_caBlock);
		void Test();
		void UInt16MethodsTest();
		void DoUnSignedMath();
		void UInt16Operators();
		void UInt16ArrayTest();
		void UInt16MiscTests();
		void CxAssert(Boolean x_x);
		void CxAssert(Boolean x_x,Boolean x_y);
	};
	class UInt32TestRaw : public ObjectRaw
	{
		public:
		CABlock x_caBlock;
		UInt32TestRaw(CABlock x_caBlock);
		void Test();
		void UInt32MethodsTest();
		void DoUnSignedMath();
		void UInt32Operators();
		void UInt32ArrayTest();
		void UInt32MiscTests();
		void CxAssert(Boolean x_x);
		void CxAssert(Boolean x_x,Boolean x_y);
	};
	class UInt64TestRaw : public ObjectRaw
	{
		public:
		CABlock x_caBlock;
		UInt64TestRaw(CABlock x_caBlock);
		void Test();
		void UInt64MethodsTest();
		void UInt64UnSignedMath();
		void UInt64Operators();
		void UInt64ArrayTest();
		void UInt64MiscTests();
		void CxAssert(Boolean x_x);
		void CxAssert(Boolean x_x,Boolean x_y);
	};
using namespace CABlock_NS;
using namespace UNNAMED;
using namespace CABlock_Extra_NS;
}
