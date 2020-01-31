#pragma once
#include "CaBlockProtos.h"
namespace CABlock_NS
{
	struct TestStruct : public Object
	{
		Int32 x_data;
		Int32 get_Data();
		void set_Data(Int32 x_value );
		TestStruct(Int32 x_i);
		static TestStruct op_Addition(TestStruct x_ts,Int32 x_newData);
		static TestStruct op_BitwiseAnd(TestStruct x_ts,Int32 x_newData);
	};
	struct TestStruct2 : public Object
	{
		Int32 x_data;
	};
	struct TestStruct3 : public Object
	{
		TestStruct2 x_ts;
	};
}
namespace UNNAMED
{
	class Typedef : public Object
	{
		public:
		TestNameEnu x_friend;
		TestNameEnu get_Friend();
		void set_Friend(TestNameEnu x_value );
	};
	class Typedef1 : public Object
	{
		public:
		TestNameEnu x_friend();
	};
}
namespace CABlock_Extra_NS
{
	class TestNamespaceClass : public Object
	{
		public:
	};
}
namespace CABlock_NS
{
	class ArrayTest : public Object
	{
		public:
		CABlock* x_caBlock;
		Array* x_boolArray;
		Array* x_int1dArray;
		Array* x_int2dArray;
		Array* x_int3dArray;
		Array* x_double1dArray;
		Array* x_double2dArray;
		Array* x_double3dArray;
		Array* x_dateTime1dArray;
		Array* x_dateTime2dArray;
		Array* x_dateTime3dArray;
		Array* x_timeSpan1dArray;
		Array* x_timeSpan2dArray;
		Array* x_timeSpan3dArray;
		ArrayTest(CABlock* x_caBlock);
		void Test();
		void TestArrayCreation();
		void MiscTest();
		void ArrayMethodTests();
		void CxAssert(Boolean x_x);
	};
	class BasicTest : public Object
	{
		public:
		CABlock* x_caBlock;
		Int32 x_field1;
		TestStruct3 x_ts3;
		BasicTest(CABlock* x_caBlock);
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
		void RefMethod(String*&  x_data);
		void RefMethod(TestAbstract*&  x_data);
		void TestUsingNamespace();
		void CxAssert(Boolean x_x);
		void ComplexConditions();
		Boolean TestThis(Int32 x_a,Int32 x_b);
		void TestNames();
	};
	class Abstract : public Object
	{
		public:
		Int32 x_data1;
		Int32 x_data2;
		Abstract(Int32 x_i,Int32 x_j);
		virtual Int32 MustImplement() = 0;
		virtual Int32 MustImplement(Int32 x_i) = 0;
		virtual Int32 MustImplement(Int64 x_i) = 0;
		Int32 DidImplement();
	};
	class TestAbstract : public Abstract
	{
		public:
		TestAbstract();
		Int32 MustImplement();
		Int32 MustImplement(Int32 x_i);
		Int32 MustImplement(Int64 x_i);
		String* ToString();
	};
	class BooleanTest : public Object
	{
		public:
		CABlock* x_caBlock;
		BooleanTest(CABlock* x_caBlock);
		void Test();
		void BoolBoxTest();
		void RunBooleanTest();
		void BoolOperators();
		void CxAssert(Boolean x_x,Boolean x_y);
		void CxAssert(Boolean x_x);
	};
	class BufferTest : public Object
	{
		public:
		CABlock* x_caBlock;
		Array* x_in1dArray;
		Array* x_out1dArray;
		BufferTest(CABlock* x_caBlock);
		void Test();
		void CxAssert(Boolean x_x);
	};
	class ByteTest : public Object
	{
		public:
		CABlock* x_caBlock;
		ByteTest(CABlock* x_caBlock);
		void Test();
		void ByteMethodsTest();
		void DoUnSignedMath();
		void ByteOperators();
		void ByteArrayTests();
		void ByteMiscTests();
		void CxAssert(Boolean x_x);
		void CxAssert(Boolean x_x,Boolean x_y);
	};
	class CharTest : public Object
	{
		public:
		CABlock* x_caBlock;
		CharTest(CABlock* x_caBlock);
		void Test();
		void CharMethodsTest();
		void CharOperators();
		void CharArrayTests();
		void CharMiscTests();
		void CxAssert(Boolean x_x);
		void CxAssert(Boolean x_x,Boolean x_y);
	};
	class DoubleTest : public Object
	{
		public:
		CABlock* x_caBlock;
		DoubleTest(CABlock* x_caBlock);
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
	class EnumTest : public Object
	{
		public:
		CABlock* x_caBlock;
		EnumTest(CABlock* x_caBlock);
		void Test();
		void Test1(TestEnum x_testEnum);
		void Test1(TestEnum2 x_testEnum);
		void EnumTestFailed();
	};
	class CABlock : public BlockBase
	{
		public:
		static Int32 x_intConstant;
		FredEnum x_fe;
		CABlock();
		CABlock(Int32 x_i);
		void Initialize();
		void Execute();
		void RunTests(FredEnum x_fre);
		void TestFailed(String* x_reason);
	};
	class Int16Test : public Object
	{
		public:
		CABlock* x_caBlock;
		Int16Test(CABlock* x_caBlock);
		void Test();
		void Int16MethodsTest();
		void Int16MathTest();
		void Int16Operators();
		void Int16ArrayTests();
		void Int16MiscTests();
		void CxAssert(Boolean x_x);
		void CxAssert(Boolean x_x,Boolean x_y);
	};
	class Int32Test : public Object
	{
		public:
		CABlock* x_caBlock;
		Int32Test(CABlock* x_caBlock);
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
	class Int64Test : public Object
	{
		public:
		CABlock* x_caBlock;
		Int64Test(CABlock* x_caBlock);
		void Test();
		void Int64MethodsTest();
		void Int64MathTest();
		void Int64Operators();
		void Int64ArrayTests();
		void Int64MiscTests();
		void CxAssert(Boolean x_x);
		void CxAssert(Boolean x_x,Boolean x_y);
	};
	class MathTest : public Object
	{
		public:
		CABlock* x_caBlock;
		MathTest(CABlock* x_caBlock);
		void Test();
		void DoMathTest();
		void DoubleCompare(Double x_n1,Double x_n2,Double x_resolution);
		void CxAssert(Double x_x,Double x_y);
		void CxAssert(Boolean x_x);
	};
	class SByteTest : public Object
	{
		public:
		CABlock* x_caBlock;
		SByteTest(CABlock* x_caBlock);
		void Test();
		void SByteMethodsTest();
		void SByteMathTest();
		void SByteOperators();
		void SByteArrayTests();
		void SByteMiscTests();
		void CxAssert(Boolean x_x);
		void CxAssert(Boolean x_x,Boolean x_y);
	};
	class SingleTest : public Object
	{
		public:
		CABlock* x_caBlock;
		SingleTest(CABlock* x_caBlock);
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
	class StringBuilderTest : public Object
	{
		public:
		CABlock* x_caBlock;
		StringBuilder* x_sb;
		StringBuilderTest(CABlock* x_caBlock);
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
	class StringTest : public Object
	{
		public:
		CABlock* x_caBlock;
		StringTest(CABlock* x_caBlock);
		void Test();
		void DoIndexTest();
		void DoMiscTest();
		static void TestConcat(String* x_str1,Int32 x_index,String* x_str4,Int32 x_i,Double x_dbl);
		void DoEqualsTest();
		void DoParsingTest();
		void DoConcatTest();
		void CxAssert(Boolean x_x);
	};
	class TimeTest : public Object
	{
		public:
		CABlock* x_caBlock;
		DateTime x_dat1;
		TimeTest(CABlock* x_caBlock);
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
	class TimingTest : public Object
	{
		public:
		TimingTest();
		static Int32 DoTimingTest(Int32 x_a,Int32 x_b,Int32 x_c);
	};
	class TestException : public Exception
	{
		public:
		TestException();
		TestException(String* x_msg);
		TestException(String* x_msg,Exception* x_baseException);
	};
	class TryCatchTest : public Object
	{
		public:
		void Test();
		void DoSimpleTryCatch();
		void DoComplexTryCatch();
		void ExceptionTestFailed();
		void CxAssert(Boolean x_x);
	};
	class UInt16Test : public Object
	{
		public:
		CABlock* x_caBlock;
		UInt16Test(CABlock* x_caBlock);
		void Test();
		void UInt16MethodsTest();
		void DoUnSignedMath();
		void UInt16Operators();
		void UInt16ArrayTest();
		void UInt16MiscTests();
		void CxAssert(Boolean x_x);
		void CxAssert(Boolean x_x,Boolean x_y);
	};
	class UInt32Test : public Object
	{
		public:
		CABlock* x_caBlock;
		UInt32Test(CABlock* x_caBlock);
		void Test();
		void UInt32MethodsTest();
		void DoUnSignedMath();
		void UInt32Operators();
		void UInt32ArrayTest();
		void UInt32MiscTests();
		void CxAssert(Boolean x_x);
		void CxAssert(Boolean x_x,Boolean x_y);
	};
	class UInt64Test : public Object
	{
		public:
		CABlock* x_caBlock;
		UInt64Test(CABlock* x_caBlock);
		void Test();
		void UInt64MethodsTest();
		void UInt64UnSignedMath();
		void UInt64Operators();
		void UInt64ArrayTest();
		void UInt64MiscTests();
		void CxAssert(Boolean x_x);
		void CxAssert(Boolean x_x,Boolean x_y);
	};
}
using namespace CABlock_NS;
using namespace UNNAMED;
using namespace CABlock_Extra_NS;
