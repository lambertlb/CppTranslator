#pragma once
#include "CaBlockHeader.h"
namespace UNNAMED
{

	TestNameEnu typedefRaw::get_Friend()
	{
		return x_friend;
	}
	void typedefRaw::set_Friend(TestNameEnu x_value )
	{
		x_friend = x_value;
	}
	typedefRaw::typedefRaw()
	{
	}

	TestNameEnu typedef1Raw::x_friend()
	{
		return x_friend_TestNameEnu;
	}
	typedef1Raw::typedef1Raw()
	{
	}

}
namespace CABlock_Extra_NS
{
	TestNamespaceClassRaw::TestNamespaceClassRaw()
	{
	}

}
namespace CABlock_NS
{
	ArrayTestRaw::ArrayTestRaw(CABlock x_caBlock)
	{
		x_dateTime2dArray = (new ArrayRaw<DateTime>(4,4));
		x_dateTime3dArray = (new ArrayRaw<DateTime>(4,4,4));
		x_timeSpan1dArray = (new ArrayRaw<TimeSpan>(4));
		x_timeSpan2dArray = (new ArrayRaw<TimeSpan>(4,4));
		x_timeSpan3dArray = (new ArrayRaw<TimeSpan>(4,4,4));
		this->x_caBlock.Assign(x_caBlock);
	}
	void ArrayTestRaw::Test()
	{
		Int32 x_num = 0;
		Int32 x_num2 = 0;
		Int32 x_num3 = 0;
		Int32 x_num4 = x_num++ + x_num2++ + x_num3-- + x_num + x_num2 + x_num3;
		CxAssert(x_num4 != 0);
		x_caBlock->Send(new StringRaw("Doing ArrayTest"));
		x_caBlock->Send(new StringRaw("\tDoing TestArrayCreation"));
		TestArrayCreation();
		x_caBlock->Send(new StringRaw("\tDoing MiscTest"));
		MiscTest();
		x_caBlock->Send(new StringRaw("\tDoing ArrayMethodTests"));
		ArrayMethodTests();
	}
	void ArrayTestRaw::TestArrayCreation()
	{
		static Int32 TestArrayCreationArray0[4] = {1,2,3,4};
		static Int32 TestArrayCreationArray1[2][4] = {{1,2,3,4},{4,5,6,7}};
		static Int32 TestArrayCreationArray2[2][2][4] = {{{1,2,3,4},{5,6,7,8}},{{9,10,11,12},{13,14,15,16}}};
		static Double TestArrayCreationArray3[4] = {1,2,3,4};
		static Double TestArrayCreationArray4[2][4] = {{1,2,3,4},{4,5,6,7}};
		static Double TestArrayCreationArray5[2][2][4] = {{{1,2,3,4},{5,6,7,8}},{{9,10,11,12},{13,14,15,16}}};
		static DateTime TestArrayCreationArray6[4] = {DateTime(2003,7,23,12,30,30,100),DateTime(2003,7,23,12,30,30,200),DateTime(2003,7,23,12,30,30,300),DateTime(2003,7,23,12,30,30,400)};
		x_boolArray.Assign((new ArrayRaw<Boolean>(4)));
		x_int1dArray.Assign((new ArrayRaw<Int32>(4))->Initialize((Int32*) TestArrayCreationArray0));
		CxAssert((*x_int1dArray->Address(1)) == 2);
		x_int2dArray.Assign((new ArrayRaw<Int32>(2,4))->Initialize((Int32*) TestArrayCreationArray1));
		CxAssert((*x_int2dArray->Address(0,2)) == 3);
		x_int3dArray.Assign((new ArrayRaw<Int32>(2,2,4))->Initialize((Int32*) TestArrayCreationArray2));
		CxAssert((*x_int3dArray->Address(0,0,3)) == 4);
		x_double1dArray.Assign((new ArrayRaw<Double>(4))->Initialize((Double*) TestArrayCreationArray3));
		CxAssert((*x_double1dArray->Address(1)) == 2);
		x_double2dArray.Assign((new ArrayRaw<Double>(2,4))->Initialize((Double*) TestArrayCreationArray4));
		CxAssert((*x_double2dArray->Address(0,2)) == 3);
		x_double3dArray.Assign((new ArrayRaw<Double>(2,2,4))->Initialize((Double*) TestArrayCreationArray5));
		CxAssert((*x_double3dArray->Address(0,0,3)) == 4);
		x_dateTime1dArray.Assign((new ArrayRaw<DateTime>(4))->Initialize((DateTime*) TestArrayCreationArray6));
		CxAssert(((DateTime)(*x_dateTime1dArray->Address(2))).Equals(DateTime(2003,7,23,12,30,30,300)));
		(*x_dateTime2dArray->Address(1,1)) = DateTime(2003,7,23,12,30,30,100);
		(*x_dateTime3dArray->Address(1,1,1)) = DateTime(2003,7,23,12,30,30,100);
		(*x_timeSpan1dArray->Address(0)) = TimeSpan();
		(*x_timeSpan1dArray->Address(0)) = TimeSpan(5,4,3,2,100);
		(*x_timeSpan1dArray->Address(1)) = TimeSpan(5,4,3,2,200);
		(*x_timeSpan1dArray->Address(2)) = TimeSpan(5,4,3,2,300);
		(*x_timeSpan1dArray->Address(3)) = TimeSpan(5,4,3,2,400);
		(*x_timeSpan2dArray->Address(1,1)) = TimeSpan(5,4,3,2,100);
		(*x_timeSpan3dArray->Address(1,1,1)) = TimeSpan(5,4,3,2,100);
	}
	void ArrayTestRaw::MiscTest()
	{
		CxAssert(x_int3dArray->GetLength(2) == 4);
		CxAssert(x_int3dArray->GetLowerBound(2) == 0);
		CxAssert(x_int3dArray->GetUpperBound(2) == 3);
		PointerType<ArrayRaw<DateTime>> x_array = x_dateTime1dArray;
		for ( int foreachi = 0; foreachi < x_array->GetLength(0) ; ++foreachi ) 
		{
			DateTime x_dateTime = x_array->GetValue(foreachi);
			String x_text = ((DateTime)x_dateTime).ToString();
		}
	}
	void ArrayTestRaw::ArrayMethodTests()
	{
		static Int32 ArrayMethodTestsArray0[3] = {1,1,1};
		static Double ArrayMethodTestsArray1[4] = {1,2,3,4};
		Int32 x_length = x_int3dArray->get_Length();
		CxAssert(x_length == 16);
		CxAssert(x_int1dArray->get_Rank() == 1);
		CxAssert(x_int2dArray->get_Rank() == 2);
		CxAssert(x_int3dArray->get_Rank() == 3);
		PointerType<ArrayRaw<DateTime>> x_array = (new ArrayRaw<DateTime>(5));
		ArrayBase::Copy(x_dateTime1dArray,x_array,x_dateTime1dArray->get_Length());
		for ( Int32 x_i = 0 ;  x_i < x_dateTime1dArray->get_Length() ;   x_i++ )
		{
			DateTime x_d = (*x_dateTime1dArray->Address(x_i));
			DateTime x_d2 = (*x_array->Address(x_i));
			CxAssert(x_d == x_d2);
		}
		x_dateTime1dArray->CopyTo(x_array,1);
		for ( Int32 x_j = 1 ;  x_j < x_array->get_Length() ;   x_j++ )
		{
			CxAssert((*x_dateTime1dArray->Address(x_j - 1)) == (*x_array->Address(x_j)));
		}
		CxAssert(TimeSpan(5,4,3,2,100).Equals(x_timeSpan3dArray->GetValue(1,1,1)));
		TimeSpan x_timeSpan = TimeSpan(5,4,3,2,101);
		PointerType<ArrayRaw<Int32>> x_indices = (new ArrayRaw<Int32>(3))->Initialize((Int32*) ArrayMethodTestsArray0);
		x_timeSpan3dArray->SetValue(x_timeSpan,x_indices);
		CxAssert(x_timeSpan.Equals(x_timeSpan3dArray->GetValue(x_indices)));
		(*x_double3dArray->Address(1,1,3)) = 22;
		Double x_num = (*x_double3dArray->Address(1,1,3));
		CxAssert(x_num == 22);
		CxAssert(((Double)22).Equals(x_double3dArray->GetValue(1,1,3)));
		x_timeSpan3dArray->SetValue(x_timeSpan,0,0,0);
		CxAssert((*x_timeSpan3dArray->Address(0,0,0)) == x_timeSpan);
		(*x_boolArray->Address(0)) = true;
		CxAssert((*x_boolArray->Address(0)));
		ArrayBase::Clear(x_boolArray,0,x_boolArray->get_Length());
		CxAssert(!(*x_boolArray->Address(0)));
		x_int1dArray->SetValue(1,2);
		CxAssert((*x_int1dArray->Address(1)) == 2);
		PointerType<ArrayRaw<Double>> x_array2 = (new ArrayRaw<Double>(4))->Initialize((Double*) ArrayMethodTestsArray1);
		x_array2->SetValue(2,1);
		CxAssert((*x_array2->Address(1)) == 2);
		x_array2->SetValue(2,1);
		CxAssert((*x_array2->Address(1)) == 2);
	}
	void ArrayTestRaw::CxAssert(Boolean x_x)
	{
		if ( !x_x )
		{
			x_caBlock->TestFailed(new StringRaw("Array TestFailed"));
		}
	}

	BasicTestRaw::BasicTestRaw(CABlock x_caBlock)
	{
		x_field1 = 0;
		this->x_caBlock.Assign(x_caBlock);
	}
	void BasicTestRaw::Test()
	{
		x_caBlock->Send(new StringRaw("Doing BasicTest"));
		x_caBlock->Send(new StringRaw("\tDoing FieldTest"));
		FieldTest();
		x_caBlock->Send(new StringRaw("\tDoing SwitchTest"));
		SwitchTest();
		x_caBlock->Send(new StringRaw("\tDoing IfThenElseTest"));
		IfThenElseTest();
		x_caBlock->Send(new StringRaw("\tDoing StructTest"));
		StructTest();
		x_caBlock->Send(new StringRaw("\tDoing StructTest2"));
		StructTest2();
		x_caBlock->Send(new StringRaw("\tDoing VirtualMethodTest"));
		VirtualMethodTest();
		x_caBlock->Send(new StringRaw("\tDoing PassByReferenceTest"));
		PassByReferenceTest();
		x_caBlock->Send(new StringRaw("\tDoing Namespace Test"));
		TestUsingNamespace();
		x_caBlock->Send(new StringRaw("\tDoing Complex conditions"));
		ComplexConditions();
		x_caBlock->Send(new StringRaw("\tDoing Naming test"));
		TestNames();
	}
	void BasicTestRaw::FieldTest()
	{
		PointerType<BasicTestRaw> x_basicTest = new BasicTestRaw(x_caBlock);
		Int32 x_num = x_field1;
		CxAssert(x_num == x_field1);
		Int32 x_num2 = x_basicTest->x_field1;
		CxAssert(x_num2 == x_basicTest->x_field1);
		DateTime x_maxValue = 3155378975999999999;
		CxAssert(x_maxValue == 3155378975999999999);
		Object x_obj = new ObjectRaw();
		CxAssert(x_obj->ToString() != nullptr);
		CxAssert(x_obj->Equals(x_obj));
		CxAssert(ObjectRaw::Equals(x_obj,x_obj));
	}
	void BasicTestRaw::SwitchTest()
	{
		x_field1 = 1;
		Int32 x_num = -1;
		switch ( x_field1++ )
		{
			case 0:
			x_num = 0;
			break;
			case 1:
			x_num = 1;
			break;
			case 1000:
			x_num = 1000;
			break;
			case 100000:
			x_num = 100000;
			break;
		}
		CxAssert(x_num == 1);
		CxAssert(x_field1 == 2);
	}
	void BasicTestRaw::IfThenElseTest()
	{
		x_field1 = 1;
		if ( x_field1 == 1 )
		{
			x_field1 = 2;
			if ( x_field1 == 3 )
			{
				x_field1 = 4;
			}
			else
			{
				x_field1 = 5;
			}
		}
		else
		{
			x_field1 = 6;
		}
		CxAssert(x_field1 == 5);
		CxAssert(ObjectRaw::Equals(nullptr,nullptr));
	}
	void BasicTestRaw::StructTest()
	{
		TestStruct x_ts = TestStruct(2);
		CxAssert(x_ts.get_Data() == 2);
		x_ts.set_Data(3);
		CxAssert(x_ts.get_Data() == 3);
		x_ts += 1;
		CxAssert(x_ts.get_Data() == 4);
		CxAssert(( x_ts & 1 )->get_Data() == 0);
	}
	void BasicTestRaw::StructTest2()
	{
		TestStruct3 x_testStruct = TestStruct3();
		x_testStruct.x_ts.x_data = 6;
		CxAssert(x_testStruct.x_ts.x_data == 6);
		x_ts3.x_ts.x_data = 7;
		CxAssert(x_ts3.x_ts.x_data == 7);
	}
	void BasicTestRaw::VirtualMethodTest()
	{
		PointerType<TestAbstractRaw> x_testAbstract = new TestAbstractRaw();
		CxAssert(x_testAbstract->MustImplement() == 2);
		CxAssert(x_testAbstract->DidImplement() == 1);
	}
	void BasicTestRaw::PassByReferenceTest()
	{
		Int32 x_data = 0;
		DateTime x_data2 = DateTime();
		TimeSpan x_data3 = TimeSpan();
		String x_data4 = nullptr;
		PointerType<TestAbstractRaw> x_data5 = nullptr;
		RefMethod(ref x_data);
		CxAssert(x_data == 1);
		RefMethod(ref x_data2);
		CxAssert(x_data2.get_Ticks() == 1000);
		RefMethod(ref x_data3);
		CxAssert(x_data3.get_Ticks() == 1000);
		RefMethod(ref x_data4);
		CxAssert(x_data4 == new StringRaw("Test"));
		RefMethod(ref x_data5);
		CxAssert(x_data5->MustImplement() == 2);
	}
	void BasicTestRaw::RefMethod(Int32 x_data)
	{
		if ( x_data == 0 )
		{
			x_data = 1;
		}
	}
	void BasicTestRaw::RefMethod(DateTime x_data)
	{
		x_data = DateTime(1000);
	}
	void BasicTestRaw::RefMethod(TimeSpan x_data)
	{
		x_data = TimeSpan(1000);
	}
	void BasicTestRaw::RefMethod(String x_data)
	{
		if ( x_data == nullptr )
		{
			x_data.Assign(new StringRaw("Test"));
		}
	}
	void BasicTestRaw::RefMethod(TestAbstract x_data)
	{
		if ( x_data == nullptr )
		{
			x_data.Assign(new TestAbstractRaw());
		}
	}
	void BasicTestRaw::TestUsingNamespace()
	{
		PointerType<TestNamespaceClassRaw> x_testNamespaceClass = new TestNamespaceClassRaw();
		CxAssert(x_testNamespaceClass != nullptr);
	}
	void BasicTestRaw::CxAssert(Boolean x_x)
	{
		if ( !x_x )
		{
			x_caBlock->TestFailed(new StringRaw("BaseTest TestFailed"));
		}
	}
	void BasicTestRaw::ComplexConditions()
	{
		x_field1 = 0;
		CxAssert(x_field1 < 1 && x_field1 < 2 && x_field1 < 3);
		x_field1 = 10;
		CxAssert(x_field1 >= 1 || x_field1 >= 2 || x_field1 >= 3);
		x_field1 = 2;
		Boolean x_flag = x_field1 < 1;
		Boolean x_flag2 = x_field1 < 2;
		Boolean x_flag3 = x_field1 < 3;
		Boolean x_flag4 = x_field1 < 4;
		Boolean x_flag5 = x_field1 < 5;
		CxAssert(!( x_flag | x_flag2 ) || !x_flag3 || ( ( ( x_flag4 && x_flag5 ) & x_flag3 ) | x_flag2 ));
		CxAssert(( !x_flag && !x_flag2 ) & x_flag3 & x_flag4 & x_flag5);
		CxAssert(( x_flag | x_flag2 ) || ( ( x_flag3 && x_flag4 ) & x_flag5 ));
		CxAssert(( !x_flag && x_flag3 && !x_flag2 ) & x_flag4 & x_flag5);
		CxAssert(TestThis(1,2));
		CxAssert(!TestThis(6,2));
		CxAssert(TestThis(60,2));
	}
	Boolean BasicTestRaw::TestThis(Int32 x_a,Int32 x_b)
	{
		return ( x_a < 5 && x_b < 3 ) || x_a + x_b > 20;
	}
	void BasicTestRaw::TestNames()
	{
		PointerType<typedefRaw> x_typedef = new typedefRaw();
		Friend_TestNameEnu(x_friend_TestNameEnu);
		CxAssert(Friend_TestNameEnu == x_friend_TestNameEnu);
	}

	TestAbstractRaw::TestAbstractRaw()
	{
	}
	Int32 TestAbstractRaw::MustImplement()
	{
		return x_data2;
	}
	Int32 TestAbstractRaw::MustImplement(Int32 x_i)
	{
		return x_data2;
	}
	Int32 TestAbstractRaw::MustImplement(Int64 x_i)
	{
		return x_data2;
	}
	String TestAbstractRaw::ToString()
	{
		return new StringRaw("TestAbstract");
	}

	Int32 TestStruct::get_Data()
	{
		return x_data;
	}
	void TestStruct::set_Data(Int32 x_value )
	{
		x_data = x_value;
	}
	TestStruct::TestStruct(Int32 x_i)
	{
		x_data = x_i;
	}

	TestStruct2::TestStruct2()
	{
	}

	TestStruct3::TestStruct3()
	{
	}

	AbstractRaw::AbstractRaw(Int32 x_i,Int32 x_j)
	{
		x_data1 = x_i;
		x_data2 = x_j;
	}
	Int32 AbstractRaw::MustImplement()
	{
	}
	Int32 AbstractRaw::MustImplement(Int32 x_i)
	{
	}
	Int32 AbstractRaw::MustImplement(Int64 x_i)
	{
	}
	Int32 AbstractRaw::DidImplement()
	{
		return x_data1;
	}

	BigEndianBitConverterTestRaw::BigEndianBitConverterTestRaw(CABlock x_caBlock)
	{
		this->x_caBlock.Assign(x_caBlock);
	}
	void BigEndianBitConverterTestRaw::Test()
	{
		static Byte TestArray0[44] = {1,0,65,64,80,170,61,112,163,215,10,26,10,255,255,229,246,0,0,0,0,39,188,134,170,66,92,0,0,21,179,0,84,197,99,0,0,0,0,33,29,26,227,0};
		x_caBlock->Send(new StringRaw("Doing BigEndianBitConverterTest"));
		x_caBlock->Send(new StringRaw("\tDoing BigEndianBitConverterMethodsTest"));
		PointerType<ArrayRaw<Byte>> x_array = (new ArrayRaw<Byte>(44))->Initialize((Byte*) TestArray0);
		CxAssert(BigEndianBitConverterRaw::ToBoolean(x_array,0));
		CxAssert(BigEndianBitConverterRaw::ToChar(x_array,1) == 'A');
		CxAssert(BigEndianBitConverterRaw::ToDouble(x_array,3) == 66.66);
		CxAssert(BigEndianBitConverterRaw::ToInt16(x_array,11) == 6666);
		CxAssert(BigEndianBitConverterRaw::ToInt32(x_array,13) == -6666);
		CxAssert(BigEndianBitConverterRaw::ToInt64(x_array,17) == 666666666);
		CxAssert(( Double ) BigEndianBitConverterRaw::ToSingle(x_array,25) == 55);
		CxAssert(BigEndianBitConverterRaw::ToUInt16(x_array,29) == 5555);
		CxAssert(BigEndianBitConverterRaw::ToUInt32(x_array,31) == 5555555);
		CxAssert(BigEndianBitConverterRaw::ToUInt64(x_array,35) == 555555555);
		CxAssert(BigEndianBitConverterRaw::DoubleToInt64Bits(7777) == 4665272916630306816);
		CxAssert(BigEndianBitConverterRaw::Int64BitsToDouble(4665272916630306816) == 7777);
		CompareBits(BigEndianBitConverterRaw::GetBytes(true),0,x_array);
		CompareBits(BigEndianBitConverterRaw::GetBytes('A'),1,x_array);
		CompareBits(BigEndianBitConverterRaw::GetBytes(66.66),3,x_array);
		CompareBits(BigEndianBitConverterRaw::GetBytes(( Int16 ) 6666),11,x_array);
		CompareBits(BigEndianBitConverterRaw::GetBytes(-6666),13,x_array);
		CompareBits(BigEndianBitConverterRaw::GetBytes(666666666),17,x_array);
		CompareBits(BigEndianBitConverterRaw::GetBytes(55),25,x_array);
		CompareBits(BigEndianBitConverterRaw::GetBytes(( UInt16 ) 5555),29,x_array);
		CompareBits(BigEndianBitConverterRaw::GetBytes(5555555),31,x_array);
		CompareBits(BigEndianBitConverterRaw::GetBytes(555555555),35,x_array);
	}
	void BigEndianBitConverterTestRaw::CompareBits(PointerType<ArrayRaw<Byte>> x_converted,Int32 x_startingIndex,PointerType<ArrayRaw<Byte>> x_bytes)
	{
		for ( Int32 x_i = 0 ;  x_i < x_converted->get_Length() ;   x_i++ )
		{
			CxAssert((*x_converted->Address(x_i)) == (*x_bytes->Address(x_i + x_startingIndex)));
		}
	}
	void BigEndianBitConverterTestRaw::CxAssert(Boolean x_x)
	{
		if ( !x_x )
		{
			x_caBlock->TestFailed(new StringRaw("BigEndianBitConverterTest Failed"));
		}
	}
	void BigEndianBitConverterTestRaw::CxAssert(Boolean x_x,Boolean x_y)
	{
		if ( x_x != x_y )
		{
			x_caBlock->TestFailed(new StringRaw("BigEndianBitConverterTest Failed"));
		}
	}

	BooleanTestRaw::BooleanTestRaw(CABlock x_caBlock)
	{
		this->x_caBlock.Assign(x_caBlock);
	}
	void BooleanTestRaw::Test()
	{
		x_caBlock->Send(new StringRaw("Doing BooleanTest"));
		x_caBlock->Send(new StringRaw("\tDoing RunBooleanTest"));
		RunBooleanTest();
		x_caBlock->Send(new StringRaw("\tDoing BoolOperators"));
		BoolOperators();
		x_caBlock->Send(new StringRaw("\tDoing BoolBoxTest"));
		BoolBoxTest();
	}
	void BooleanTestRaw::BoolBoxTest()
	{
		Boolean x_flag = true;
		Object x_obj = x_flag;
		CxAssert(((Boolean)x_flag).Equals(x_obj));
		CxAssert(x_obj->Equals(x_obj));
		CxAssert(( Boolean ) x_obj);
		CxAssert(x_obj->ToString() == new StringRaw("True"));
	}
	void BooleanTestRaw::RunBooleanTest()
	{
		Boolean x_flag = true;
		Object x_obj = x_flag;
		CxAssert(((Boolean)x_flag).CompareTo(true) == 0);
		CxAssert(((Boolean)x_flag).CompareTo(x_obj) == 0);
		CxAssert(((Boolean)x_flag).Equals(true));
		CxAssert(BooleanRaw::Parse(new StringRaw("True")));
		CxAssert(new StringRaw("True") == ((Boolean)x_flag).ToString());
		CxAssert(Boolean::FalseString == new StringRaw("False"));
		CxAssert(Boolean::TrueString == new StringRaw("True"));
	}
	void BooleanTestRaw::BoolOperators()
	{
		Boolean x_flag = true;
		Boolean x_flag2 = false;
		CxAssert(x_flag && x_flag2,false);
		CxAssert(x_flag | x_flag2);
		CxAssert(x_flag ^ x_flag2);
		CxAssert(!x_flag,false);
		CxAssert(x_flag && x_flag2,false);
		CxAssert(x_flag | x_flag2);
		CxAssert(x_flag == x_flag2,false);
		CxAssert(x_flag != x_flag2);
		CxAssert(x_flag = x_flag);
		Int32 x_num = ( x_flag ? 1 : 0 ) | 1;
		x_flag = ( ( Byte ) x_num != 0 );
		CxAssert(( Byte ) x_num != 0);
		CxAssert(x_flag = x_flag);
	}
	void BooleanTestRaw::CxAssert(Boolean x_x,Boolean x_y)
	{
		if ( x_x != x_y )
		{
			x_caBlock->TestFailed(new StringRaw("Boolean TestFailed"));
		}
	}
	void BooleanTestRaw::CxAssert(Boolean x_x)
	{
		if ( !x_x )
		{
			x_caBlock->TestFailed(new StringRaw("Boolean TestFailed"));
		}
	}

	BufferTestRaw::BufferTestRaw(CABlock x_caBlock)
	{
		this->x_caBlock.Assign(x_caBlock);
	}
	void BufferTestRaw::Test()
	{
		static Int32 TestArray0[5] = {0,1,2,3,4};
		static Int32 TestArray1[5] = {5,4,3,2,1};
		x_caBlock->Send(new StringRaw("Doing Buffer Test"));
		x_in1dArray.Assign((new ArrayRaw<Int32>(5))->Initialize((Int32*) TestArray0));
		x_out1dArray.Assign((new ArrayRaw<Int32>(5))->Initialize((Int32*) TestArray1));
		Int32 x_count = x_in1dArray->GetLength(0) * 4;
		BufferRaw::BlockCopy(x_in1dArray,0,x_out1dArray,0,x_count);
		Boolean x_x = true;
		for ( Int32 x_i = 0 ;  x_i < 5 ;   x_i++ )
		{
			if ( (*x_in1dArray->Address(x_i)) != (*x_out1dArray->Address(x_i)) )
			{
				x_x = false;
				break;
			}
		}
		CxAssert(x_x);
	}
	void BufferTestRaw::CxAssert(Boolean x_x)
	{
		if ( !x_x )
		{
			x_caBlock->TestFailed(new StringRaw("Buffer Test Failed"));
		}
	}

	ByteTestRaw::ByteTestRaw(CABlock x_caBlock)
	{
		this->x_caBlock.Assign(x_caBlock);
	}
	void ByteTestRaw::Test()
	{
		x_caBlock->Send(new StringRaw("Doing ByteTest"));
		x_caBlock->Send(new StringRaw("\tDoing ByteMethodsTest"));
		ByteMethodsTest();
		x_caBlock->Send(new StringRaw("\tDoing DoUnSignedMath"));
		DoUnSignedMath();
		x_caBlock->Send(new StringRaw("\tDoing ByteOperators"));
		ByteOperators();
		x_caBlock->Send(new StringRaw("\tDoing ByteArrayTests"));
		ByteArrayTests();
		x_caBlock->Send(new StringRaw("\tDoing ByteMiscTests"));
		ByteMiscTests();
	}
	void ByteTestRaw::ByteMethodsTest()
	{
		Byte x_b = 5;
		CxAssert(((Byte)x_b).CompareTo(5) == 0);
		CxAssert(((Byte)x_b).CompareTo(( Object ) ( Byte ) 5) == 0);
		CxAssert(((Byte)x_b).Equals(5));
		CxAssert(((Byte)x_b).Equals(( Object ) ( Byte ) 5));
		CxAssert(ByteRaw::Parse(new StringRaw("77")) == 77);
		CxAssert(new StringRaw("5") == ((Byte)x_b).ToString());
		x_b = 255;
		CxAssert(255 == x_b);
		x_b = 0;
		CxAssert(x_b == 0);
		String x_text = ((Byte)255).ToString();
		CxAssert(x_text == new StringRaw("255"));
		CxAssert(ByteRaw::Parse(x_text) == 255);
		String x_text2 = ( ( Byte ) 0 )->ToString();
		CxAssert(x_text2 == new StringRaw("0"));
		CxAssert(ByteRaw::Parse(x_text2) == 0);
		Int32 x_num = 50;
		Byte x_b2 = ( Byte ) x_num;
		Object x_obj = x_num;
		Int32 x_num2 = ( Int32 ) x_obj;
		CxAssert(x_b2 == 50);
		CxAssert(x_num2 == 50);
		x_b2 = 255;
		x_b2 = ( Byte ) ( x_b2 + 1 );
		CxAssert(x_b2 == 0);
		Object x_obj2 = ( Byte ) 5;
		CxAssert(x_obj2->Equals(( Byte ) 5));
		CxAssert(x_obj2->ToString() == new StringRaw("5"));
	}
	void ByteTestRaw::DoUnSignedMath()
	{
		Byte x_b = 60;
		Byte x_b2 = 120;
		Byte x_b3 = 6;
		Byte x_b4 = 12;
		Int32 x_num = 1;
		CxAssert(1 <= x_b);
		CxAssert(x_b >= 1);
		CxAssert(x_b >= x_num);
		CxAssert(x_num <= x_b);
		x_num += x_b;
		CxAssert(x_num == 61);
		CxAssert(x_b + x_b2 == 180);
		Byte x_b5 = ( Byte ) ( x_b - x_b2 );
		CxAssert(x_b5 == 196);
		CxAssert(( Byte ) ( x_b - x_b2 ) == 196);
		CxAssert(x_b3 * x_b4 == 72);
		CxAssert(( Int32 ) x_b2 / ( Int32 ) x_b == 2);
		CxAssert(x_b >> 2 == 15);
		CxAssert(x_b << 1 == 120);
		Int32 x_num2 = 11;
		CxAssert(x_num2 % 5 == 1);
		x_num2 = 8;
		CxAssert(( x_num2 | 1 ) == 9);
		CxAssert(( x_num2 & 1 ) == 0);
		CxAssert(++x_num2 == 9);
		CxAssert(--x_num2 == 8);
		CxAssert(( x_num2 *= 2 ) == 16);
		CxAssert(( x_num2 /= 2 ) == 8);
		CxAssert(( x_num2 %= 2 ) == 0);
		CxAssert(( x_num2 |= 4 ) == 4);
		CxAssert(( x_num2 &= 4 ) == 4);
		CxAssert(-x_b == -60);
		CxAssert(x_b == 60);
		Byte x_b6 = 0;
		CxAssert(( Byte ) ( ~x_b6 ) == 255);
		CxAssert(( x_b6 = ( Byte ) ( x_b6 + 1 ) ) == 1);
		CxAssert(( x_b6 = ( Byte ) ( x_b6 - 1 ) ) == 0);
	}
	void ByteTestRaw::ByteOperators()
	{
		Byte x_b = 66;
		Char x_c = '';
		Byte x_b2 = 1;
		SByte x_b3 = 1;
		Int16 x_num = 1;
		Int32 x_num2 = 1;
		Int64 x_num3 = 1;
		UInt16 x_num4 = 1;
		UInt32 x_num5 = 1;
		UInt64 x_num6 = 1;
		Float x_num7 = 1;
		Double x_num8 = 1;
		CxAssert(x_b == 66);
		CxAssert(x_b + x_c == 67);
		CxAssert(x_b + x_b2 == 67);
		CxAssert(x_b + x_b3 == 67);
		CxAssert(x_b + x_num == 67);
		CxAssert(x_b + x_num2 == 67);
		CxAssert(x_b + x_num3 == 67);
		CxAssert(x_b + x_num4 == 67);
		CxAssert(x_b + x_num5 == 67);
		CxAssert(x_b + x_num6 == 67);
		CxAssert(( Float ) ( Int32 ) x_b + x_num7 == 67);
		CxAssert(( Double ) ( Int32 ) x_b + x_num8 == 67);
		CxAssert(x_b - x_c == 65);
		CxAssert(x_b - x_b2 == 65);
		CxAssert(x_b - x_b3 == 65);
		CxAssert(x_b - x_num == 65);
		CxAssert(x_b - x_num2 == 65);
		CxAssert(x_b - x_num3 == 65);
		CxAssert(x_b - x_num4 == 65);
		CxAssert(x_b - x_num5 == 65);
		CxAssert(x_b - x_num6 == 65);
		CxAssert(( Float ) ( Int32 ) x_b - x_num7 == 65);
		CxAssert(( Double ) ( Int32 ) x_b - x_num8 == 65);
		CxAssert(x_b * x_c == 66);
		CxAssert(x_b * x_b2 == 66);
		CxAssert(x_b * x_b3 == 66);
		CxAssert(x_b * x_num == 66);
		CxAssert(x_b * x_num2 == 66);
		CxAssert(x_b * x_num3 == 66);
		CxAssert(x_b * x_num4 == 66);
		CxAssert(x_b * x_num5 == 66);
		CxAssert(x_b * x_num6 == 66);
		CxAssert(( Float ) ( Int32 ) x_b * x_num7 == 66);
		CxAssert(( Double ) ( Int32 ) x_b * x_num8 == 66);
		CxAssert(( Int32 ) x_b / ( Int32 ) x_c == 66);
		CxAssert(( Int32 ) x_b / ( Int32 ) x_b2 == 66);
		CxAssert(( Int32 ) x_b / ( Int32 ) x_b3 == 66);
		CxAssert(( Int32 ) x_b / ( Int32 ) x_num == 66);
		CxAssert(( Int32 ) x_b / x_num2 == 66);
		CxAssert(( Int64 ) x_b / x_num3 == 66);
		CxAssert(( Int32 ) x_b / ( Int32 ) x_num4 == 66);
		CxAssert(x_b / x_num5 == 66);
		CxAssert(x_b / x_num6 == 66);
		CxAssert(( Float ) ( Int32 ) x_b / x_num7 == 66);
		CxAssert(( Double ) ( Int32 ) x_b / x_num8 == 66);
		CxAssert(( Int32 ) x_b % ( Int32 ) x_c == 0);
		CxAssert(( Int32 ) x_b % ( Int32 ) x_b2 == 0);
		CxAssert(( Int32 ) x_b % ( Int32 ) x_b3 == 0);
		CxAssert(( Int32 ) x_b % ( Int32 ) x_num == 0);
		CxAssert(( Int32 ) x_b % x_num2 == 0);
		CxAssert(( Int64 ) x_b % x_num3 == 0);
		CxAssert(( Int32 ) x_b % ( Int32 ) x_num4 == 0);
		CxAssert(x_b % x_num5 == 0);
		CxAssert(x_b % x_num6 == 0);
		CxAssert(( Float ) ( Int32 ) x_b % x_num7 == 0);
		CxAssert(( Double ) ( Int32 ) x_b % x_num8 == 0);
		CxAssert(( x_b & x_c ) == 0);
		CxAssert(( x_b & x_b2 ) == 0);
		CxAssert(( x_b & x_b3 ) == 0);
		CxAssert(( x_b & x_num ) == 0);
		CxAssert(( x_b & x_num2 ) == 0);
		CxAssert(( x_b & x_num3 ) == 0);
		CxAssert(( x_b & x_num4 ) == 0);
		CxAssert(( x_b & x_num5 ) == 0);
		CxAssert(( x_b & x_num6 ) == 0);
		CxAssert(( x_b | x_c ) == 67);
		CxAssert(( x_b | x_b2 ) == 67);
		CxAssert(( x_b | x_b3 ) == 67);
		CxAssert(( x_b | x_num ) == 67);
		CxAssert(( x_b | x_num2 ) == 67);
		CxAssert(( x_b | x_num3 ) == 67);
		CxAssert(( x_b | x_num4 ) == 67);
		CxAssert(( x_b | x_num5 ) == 67);
		CxAssert(( x_b | x_num6 ) == 67);
		CxAssert(( x_b ^ x_c ) == 67);
		CxAssert(( x_b ^ x_b2 ) == 67);
		CxAssert(( x_b ^ x_b3 ) == 67);
		CxAssert(( x_b ^ x_num ) == 67);
		CxAssert(( x_b ^ x_num2 ) == 67);
		CxAssert(( x_b ^ x_num3 ) == 67);
		CxAssert(( x_b ^ x_num4 ) == 67);
		CxAssert(( x_b ^ x_num5 ) == 67);
		CxAssert(( x_b ^ x_num6 ) == 67);
		CxAssert(( Byte ) ( ~x_b ) == 189);
		CxAssert(x_c < x_b);
		CxAssert(x_b2 < x_b);
		CxAssert(x_b3 < x_b);
		CxAssert(x_num < x_b);
		CxAssert(x_num2 < x_b);
		CxAssert(x_num3 < x_b);
		CxAssert(x_num4 < x_b);
		CxAssert(x_num5 < x_b);
		CxAssert(x_num6 < x_b);
		CxAssert(x_num7 < ( Float ) ( Int32 ) x_b);
		CxAssert(x_num8 < ( Double ) ( Int32 ) x_b);
		CxAssert(x_c > x_b,false);
		CxAssert(x_b2 > x_b,false);
		CxAssert(x_b3 > x_b,false);
		CxAssert(x_num > x_b,false);
		CxAssert(x_num2 > x_b,false);
		CxAssert(x_num3 > x_b,false);
		CxAssert(x_num4 > x_b,false);
		CxAssert(x_num5 > x_b,false);
		CxAssert(x_num6 > x_b,false);
		CxAssert(x_num7 > ( Float ) ( Int32 ) x_b,false);
		CxAssert(x_num8 > ( Double ) ( Int32 ) x_b,false);
		CxAssert(( x_b = ( Byte ) ( x_b + 1 ) ) == 67);
		CxAssert(( x_b = ( Byte ) ( x_b - 1 ) ) == 66);
		CxAssert(x_b++ == 66);
		CxAssert(x_b-- == 67);
		CxAssert(x_b << 1 == 132);
		CxAssert(x_b >> 1 == 33);
		CxAssert(x_c == x_b,false);
		CxAssert(x_b2 == x_b,false);
		CxAssert(x_b3 == x_b,false);
		CxAssert(x_num == x_b,false);
		CxAssert(x_num2 == x_b,false);
		CxAssert(x_num3 == x_b,false);
		CxAssert(x_num4 == x_b,false);
		CxAssert(x_num5 == x_b,false);
		CxAssert(x_num6 == x_b,false);
		CxAssert(x_num7 == ( Float ) ( Int32 ) x_b,false);
		CxAssert(x_num8 == ( Double ) ( Int32 ) x_b,false);
		CxAssert(x_c != x_b);
		CxAssert(x_b2 != x_b);
		CxAssert(x_b3 != x_b);
		CxAssert(x_num != x_b);
		CxAssert(x_num2 != x_b);
		CxAssert(x_num3 != x_b);
		CxAssert(x_num4 != x_b);
		CxAssert(x_num5 != x_b);
		CxAssert(x_num6 != x_b);
		CxAssert(x_num7 != ( Float ) ( Int32 ) x_b);
		CxAssert(x_num8 != ( Double ) ( Int32 ) x_b);
		CxAssert(x_c <= x_b);
		CxAssert(x_b2 <= x_b);
		CxAssert(x_b3 <= x_b);
		CxAssert(x_num <= x_b);
		CxAssert(x_num2 <= x_b);
		CxAssert(x_num3 <= x_b);
		CxAssert(x_num4 <= x_b);
		CxAssert(x_num5 <= x_b);
		CxAssert(x_num6 <= x_b);
		CxAssert(x_num7 <= ( Float ) ( Int32 ) x_b);
		CxAssert(x_num8 <= ( Double ) ( Int32 ) x_b);
		CxAssert(x_c >= x_b,false);
		CxAssert(x_b2 >= x_b,false);
		CxAssert(x_b3 >= x_b,false);
		CxAssert(x_num >= x_b,false);
		CxAssert(x_num2 >= x_b,false);
		CxAssert(x_num3 >= x_b,false);
		CxAssert(x_num4 >= x_b,false);
		CxAssert(x_num5 >= x_b,false);
		CxAssert(x_num6 >= x_b,false);
		CxAssert(x_num7 >= ( Float ) ( Int32 ) x_b,false);
		CxAssert(x_num8 >= ( Double ) ( Int32 ) x_b,false);
		CxAssert(( x_b = ( Byte ) ( x_b + ( Byte ) x_c ) ) == 67);
		CxAssert(( x_b = ( Byte ) ( x_b - ( Byte ) x_c ) ) == 66);
		CxAssert(( x_b = ( Byte ) ( x_b + ( Byte ) x_num5 ) ) == 67);
		CxAssert(( x_b = ( Byte ) ( x_b - ( Byte ) x_num5 ) ) == 66);
		CxAssert(( x_b = ( Byte ) ( x_b * ( Byte ) x_c ) ) == 66);
		CxAssert(( x_b = ( Byte ) ( ( Int32 ) x_b / ( Int32 ) ( Byte ) x_c ) ) == 66);
		CxAssert(( x_b = ( Byte ) ( x_b * ( Byte ) x_num5 ) ) == 66);
		CxAssert(( x_b = ( Byte ) ( ( Int32 ) x_b / ( Int32 ) ( Byte ) x_num5 ) ) == 66);
		CxAssert(( x_b = ( Byte ) ( ( Int32 ) x_b % ( Int32 ) ( Byte ) x_c ) ) == 0);
		x_b = 66;
		CxAssert(( x_b = ( Byte ) ( ( Int32 ) x_b % ( Int32 ) ( Byte ) x_num5 ) ) == 0);
		x_b = 66;
		CxAssert(( x_b = ( Byte ) ( x_b & ( Byte ) x_c ) ) == 0);
		x_b = 66;
		CxAssert(( x_b = ( Byte ) ( x_b & ( Byte ) x_num5 ) ) == 0);
		x_b = 66;
		CxAssert(( x_b = ( Byte ) ( x_b | ( Byte ) x_c ) ) == 67);
		x_b = 66;
		CxAssert(( x_b = ( Byte ) ( x_b | ( Byte ) x_num5 ) ) == 67);
		x_b = 66;
		CxAssert(( x_b = ( Byte ) ( x_b ^ ( Byte ) x_c ) ) == 67);
		x_b = 66;
		CxAssert(( x_b = ( Byte ) ( x_b ^ ( Byte ) x_num5 ) ) == 67);
		x_b = 66;
		CxAssert(( x_b = ( Byte ) ( x_b << ( Int32 ) x_c ) ) == 132);
		x_b = 66;
		CxAssert(( x_b = ( Byte ) ( x_b << x_num2 ) ) == 132);
		x_b = 66;
		CxAssert(( x_b = ( Byte ) ( x_b >> ( Int32 ) x_c ) ) == 33);
		x_b = 66;
		CxAssert(( x_b = ( Byte ) ( x_b >> x_num2 ) ) == 33);
		x_b = 66;
		Char x_c2 = 'B';
		CxAssert(( x_c2 = ( Char ) ( ( UInt32 ) x_c2 << ( Int32 ) x_c ) ) == '');
	}
	void ByteTestRaw::ByteArrayTests()
	{
		static Byte ByteArrayTestsArray0[5] = {1,2,3,4,5};
		static Byte ByteArrayTestsArray1[4] = {1,2,3,4};
		static Byte ByteArrayTestsArray2[2][4] = {{1,2,3,4},{4,5,6,7}};
		static Byte ByteArrayTestsArray3[2][2][4] = {{{1,2,3,4},{5,6,7,8}},{{9,10,11,12},{13,14,15,16}}};
		PointerType<ArrayRaw<Byte>> x_array = (new ArrayRaw<Byte>(10));
		PointerType<ArrayRaw<Byte>> x_array2 = (new ArrayRaw<Byte>(10));
		for ( Int32 x_i = 0 ;  x_i < 10 ;   x_i++ )
		{
			(*x_array->Address(x_i)) = ( Byte ) x_i;
		}
		for ( Int32 x_j = 0 ;  x_j < 10 ;   x_j++ )
		{
			(*x_array2->Address(x_j)) = (*x_array->Address(x_j));
		}
		CxAssert((*x_array2->Address(0)) == 0);
		CxAssert((*x_array2->Address(9)) == 9);
		for ( Int32 x_k = 0 ;  x_k < 10 ;   x_k++ )
		{
			(*x_array->Address(x_k)) = 1;
		}
		PointerType<ArrayRaw<Int32>> x_array3 = (new ArrayRaw<Int32>(10));
		BufferRaw::BlockCopy(x_array,0,x_array3,0,10);
		BufferRaw::BlockCopy(x_array,0,x_array3,10,10);
		BufferRaw::BlockCopy(x_array,0,x_array3,20,10);
		BufferRaw::BlockCopy(x_array,0,x_array3,30,10);
		CxAssert((*x_array3->Address(0)) == 16843009);
		CxAssert((*x_array3->Address(9)) == 16843009);
		PointerType<ArrayRaw<Byte>> x_array4 = (new ArrayRaw<Byte>(5))->Initialize((Byte*) ByteArrayTestsArray0);
		CxAssert(x_array4->get_Length() == 5);
		CxAssert((*x_array4->Address(3)) == 4);
		PointerType<ArrayRaw<Byte>> x_array5 = (new ArrayRaw<Byte>(4))->Initialize((Byte*) ByteArrayTestsArray1);
		CxAssert((*x_array5->Address(1)) == 2);
		PointerType<ArrayRaw<Byte>> x_array6 = (new ArrayRaw<Byte>(2,4))->Initialize((Byte*) ByteArrayTestsArray2);
		CxAssert((*x_array6->Address(0,2)) == 3);
		PointerType<ArrayRaw<Byte>> x_array7 = (new ArrayRaw<Byte>(2,2,4))->Initialize((Byte*) ByteArrayTestsArray3);
		CxAssert((*x_array7->Address(0,0,3)) == 4);
		(*x_array7->Address(0,0,3)) = 6;
		CxAssert((*x_array7->Address(0,0,3)) == 6);
		x_array7->SetValue(( Byte ) 4,0,0,3);
		CxAssert((*x_array7->Address(0,0,3)) == 4);
	}
	void ByteTestRaw::ByteMiscTests()
	{
		Byte x_b = 0;
		Byte x_val = 1;
		CxAssert(MathRaw::Max(x_b,x_val) == 1);
		CxAssert(MathRaw::Min(x_b,x_val) == 0);
		PointerType<StringBuilderRaw> x_stringBuilder = new StringBuilderRaw();
		x_stringBuilder->Append(x_b);
		CxAssert(x_stringBuilder->ToString() == new StringRaw("0"));
		x_stringBuilder->Insert(1,x_b);
		CxAssert(x_stringBuilder->ToString() == new StringRaw("00"));
	}
	void ByteTestRaw::CxAssert(Boolean x_x)
	{
		if ( !x_x )
		{
			x_caBlock->TestFailed(new StringRaw("Byte Test Failed"));
		}
	}
	void ByteTestRaw::CxAssert(Boolean x_x,Boolean x_y)
	{
		if ( x_x != x_y )
		{
			x_caBlock->TestFailed(new StringRaw("Byte Test Failed"));
		}
	}

	CharTestRaw::CharTestRaw(CABlock x_caBlock)
	{
		this->x_caBlock.Assign(x_caBlock);
	}
	void CharTestRaw::Test()
	{
		x_caBlock->Send(new StringRaw("Doing CharTest"));
		x_caBlock->Send(new StringRaw("\tDoing CharMethodsTest"));
		CharMethodsTest();
		x_caBlock->Send(new StringRaw("\tDoing CharOperators"));
		CharOperators();
		x_caBlock->Send(new StringRaw("\tDoing CharArrayTest"));
		CharArrayTests();
		x_caBlock->Send(new StringRaw("\tDoing CharMiscTests"));
		CharMiscTests();
	}
	void CharTestRaw::CharMethodsTest()
	{
		String x_s = new StringRaw("123aBc\t\n. ");
		Char x_c = 'A';
		CxAssert(((Char)x_c).CompareTo('B') < 0);
		CxAssert(((Char)x_c).Equals('A'));
		Double x_numericValue = CharRaw::GetNumericValue('5');
		CxAssert(x_numericValue == 5);
		x_numericValue = CharRaw::GetNumericValue(x_s,2);
		CxAssert(x_numericValue == 3);
		CxAssert(CharRaw::IsControl('	'));
		CxAssert(CharRaw::IsControl(x_s,7));
		CxAssert(CharRaw::IsDigit('1'));
		CxAssert(CharRaw::IsDigit(x_s,2));
		CxAssert(CharRaw::IsLetter('a'));
		CxAssert(CharRaw::IsLetter(x_s,3));
		CxAssert(CharRaw::IsLetterOrDigit('a'));
		CxAssert(CharRaw::IsLetterOrDigit(x_s,3));
		CxAssert(CharRaw::IsLower('a'));
		CxAssert(CharRaw::IsLower(x_s,3));
		CxAssert(CharRaw::IsNumber('1'));
		CxAssert(CharRaw::IsNumber(x_s,2));
		CxAssert(CharRaw::IsPunctuation(','));
		CxAssert(CharRaw::IsPunctuation(x_s,8));
		CxAssert(CharRaw::IsSeparator(' '));
		CxAssert(CharRaw::IsSeparator(x_s,9));
		CxAssert(CharRaw::IsUpper('B'));
		CxAssert(CharRaw::IsUpper(x_s,4));
		CxAssert(CharRaw::IsWhiteSpace(' '));
		CxAssert(CharRaw::IsWhiteSpace(x_s,9));
		CxAssert(CharRaw::ToLower('A') == 'a');
		CxAssert(CharRaw::ToUpper('a') == 'A');
		CxAssert(((String)new StringRaw("a"))->Equals(((Char)'a').ToString()));
		CxAssert(((String)new StringRaw("a"))->Equals(CharRaw::ToString('a')));
		CxAssert(((Char)'a').Equals(CharRaw::Parse(new StringRaw("a"))));
		Object x_obj = x_c;
		CxAssert(((Char)'A').Equals(( Char ) x_obj));
		CxAssert(((Char)'A').Equals(x_obj));
		CxAssert(((Char)'A').CompareTo(x_obj) == 0);
		CxAssert(x_obj->ToString() == new StringRaw("A"));
	}
	void CharTestRaw::CharOperators()
	{
		Char x_c = 'B';
		Char x_c2 = '';
		Int32 x_num = 1;
		UInt32 x_num2 = 1;
		Int64 x_num3 = 1;
		Double x_num4 = 1;
		CxAssert(x_c == 'B');
		CxAssert(x_c + x_c2 == 67);
		CxAssert(x_c + x_num == 67);
		CxAssert(x_c + x_num2 == 67);
		CxAssert(x_c + x_num3 == 67);
		CxAssert(( Double ) ( Int32 ) x_c + x_num4 == 67);
		CxAssert(x_c - x_c2 == 65);
		CxAssert(x_c - x_num == 65);
		CxAssert(x_c - x_num2 == 65);
		CxAssert(x_c - x_num3 == 65);
		CxAssert(( Double ) ( Int32 ) x_c - x_num4 == 65);
		CxAssert(x_c * x_c2 == 66);
		CxAssert(x_c * x_num == 66);
		CxAssert(x_c * x_num2 == 66);
		CxAssert(x_c * x_num3 == 66);
		CxAssert(( Double ) ( Int32 ) x_c * x_num4 == 66);
		CxAssert(( Int32 ) x_c / ( Int32 ) x_c2 == 66);
		CxAssert(( Int32 ) x_c / x_num == 66);
		CxAssert(x_c / x_num2 == 66);
		CxAssert(( Int64 ) x_c / x_num3 == 66);
		CxAssert(( Double ) ( Int32 ) x_c / x_num4 == 66);
		CxAssert(( Int32 ) x_c % ( Int32 ) x_c2 == 0);
		CxAssert(( Int32 ) x_c % x_num == 0);
		CxAssert(x_c % x_num2 == 0);
		CxAssert(( Int64 ) x_c % x_num3 == 0);
		CxAssert(( Double ) ( Int32 ) x_c % x_num4 == 0);
		CxAssert(( x_c & x_c2 ) == 0);
		CxAssert(( x_c & x_num ) == 0);
		CxAssert(( x_c & x_num2 ) == 0);
		CxAssert(( x_c & x_num3 ) == 0);
		CxAssert(( x_c | x_c2 ) == 67);
		CxAssert(( x_c | x_num ) == 67);
		CxAssert(( x_c | x_num2 ) == 67);
		CxAssert(( x_c | x_num3 ) == 67);
		CxAssert(( x_c ^ x_c2 ) == 67);
		CxAssert(( x_c ^ x_num ) == 67);
		CxAssert(( x_c ^ x_num2 ) == 67);
		CxAssert(( x_c ^ x_num3 ) == 67);
		CxAssert(~( UInt32 ) x_c == 4294967229);
		CxAssert(x_c2 < x_c);
		CxAssert(x_num < x_c);
		CxAssert(x_num2 < x_c);
		CxAssert(x_num3 < x_c);
		CxAssert(x_num4 < ( Double ) ( Int32 ) x_c);
		CxAssert(x_c2 > x_c,false);
		CxAssert(x_num > x_c,false);
		CxAssert(x_num2 > x_c,false);
		CxAssert(x_num3 > x_c,false);
		CxAssert(x_num4 > ( Double ) ( Int32 ) x_c,false);
		CxAssert(( x_c = ( Char ) ( x_c + 1 ) ) == 'C');
		CxAssert(( x_c = ( Char ) ( x_c - 1 ) ) == 'B');
		CxAssert(x_c++ == 'B');
		CxAssert(x_c-- == 'C');
		CxAssert(( UInt32 ) x_c << 1 == 132);
		CxAssert(( Int32 ) x_c >> 1 == 33);
		CxAssert(x_c2 == x_c,false);
		CxAssert(x_num == x_c,false);
		CxAssert(x_num2 == x_c,false);
		CxAssert(x_num3 == x_c,false);
		CxAssert(x_num4 == ( Double ) ( Int32 ) x_c,false);
		CxAssert(x_c2 != x_c);
		CxAssert(x_num != x_c);
		CxAssert(x_num2 != x_c);
		CxAssert(x_num3 != x_c);
		CxAssert(x_num4 != ( Double ) ( Int32 ) x_c);
		CxAssert(x_c2 <= x_c);
		CxAssert(x_num <= x_c);
		CxAssert(x_num2 <= x_c);
		CxAssert(x_num3 <= x_c);
		CxAssert(x_num4 <= ( Double ) ( Int32 ) x_c);
		CxAssert(x_c2 >= x_c,false);
		CxAssert(x_num >= x_c,false);
		CxAssert(x_num2 >= x_c,false);
		CxAssert(x_num3 >= x_c,false);
		CxAssert(x_num4 >= ( Double ) ( Int32 ) x_c,false);
		CxAssert(( x_c = ( Char ) ( x_c + x_c2 ) ) == 'C');
		CxAssert(( x_c = ( Char ) ( x_c - x_c2 ) ) == 'B');
		CxAssert(( x_c = ( Char ) ( x_c * x_c2 ) ) == 'B');
		CxAssert(( x_c = ( Char ) ( ( Int32 ) x_c / ( Int32 ) x_c2 ) ) == 'B');
		CxAssert(( x_c = ( Char ) ( ( Int32 ) x_c % ( Int32 ) x_c2 ) ) == ' ');
		x_c = 'B';
		CxAssert(( x_c = ( Char ) ( x_c & x_c2 ) ) == ' ');
		x_c = 'B';
		CxAssert(( x_c = ( Char ) ( x_c & x_c2 ) ) == ' ');
		x_c = 'B';
		CxAssert(( x_c = ( Char ) ( x_c | x_c2 ) ) == 'C');
		x_c = 'B';
		CxAssert(( x_c = ( Char ) ( x_c ^ x_c2 ) ) == 'C');
		x_c = 'B';
		CxAssert(( x_c = ( Char ) ( ( UInt32 ) x_c << 1 ) ) == '');
		x_c = 'B';
		CxAssert(( x_c = ( Char ) ( ( Int32 ) x_c >> 1 ) ) == '!');
	}
	void CharTestRaw::CharArrayTests()
	{
		static Char CharArrayTestsArray0[5] = {'1','2','3','4','5'};
		static Char CharArrayTestsArray1[4] = {'1','2','3','4'};
		static Char CharArrayTestsArray2[2][4] = {{'1','2','3','4'},{'4','5','6','7'}};
		static Char CharArrayTestsArray3[2][2][4] = {{{'1','2','3','4'},{'5','6','7','8'}},{{'9','A','B','C'},{'D','E','F','G'}}};
		PointerType<ArrayRaw<Char>> x_array = (new ArrayRaw<Char>(5))->Initialize((Char*) CharArrayTestsArray0);
		CxAssert(x_array->get_Length() == 5);
		CxAssert((*x_array->Address(3)) == '4');
		PointerType<ArrayRaw<Char>> x_array2 = (new ArrayRaw<Char>(4))->Initialize((Char*) CharArrayTestsArray1);
		CxAssert((*x_array2->Address(1)) == '2');
		PointerType<ArrayRaw<Char>> x_array3 = (new ArrayRaw<Char>(2,4))->Initialize((Char*) CharArrayTestsArray2);
		CxAssert((*x_array3->Address(0,2)) == '3');
		PointerType<ArrayRaw<Char>> x_array4 = (new ArrayRaw<Char>(2,2,4))->Initialize((Char*) CharArrayTestsArray3);
		CxAssert((*x_array4->Address(0,0,3)) == '4');
		(*x_array4->Address(0,0,3)) = '6';
		CxAssert((*x_array4->Address(0,0,3)) == '6');
		x_array4->SetValue('4',0,0,3);
		CxAssert((*x_array4->Address(0,0,3)) == '4');
	}
	void CharTestRaw::CharMiscTests()
	{
		Char x_c = '0';
		Char x_val = '1';
		CxAssert(MathRaw::Max(x_c,x_val) == 49);
		CxAssert(MathRaw::Min(x_c,x_val) == 48);
		PointerType<StringBuilderRaw> x_stringBuilder = new StringBuilderRaw();
		x_stringBuilder->Append(x_c);
		CxAssert(x_stringBuilder->ToString() == new StringRaw("0"));
	}
	void CharTestRaw::CxAssert(Boolean x_x)
	{
		if ( !x_x )
		{
			x_caBlock->TestFailed(new StringRaw("Char TestFailed"));
		}
	}
	void CharTestRaw::CxAssert(Boolean x_x,Boolean x_y)
	{
		if ( x_x != x_y )
		{
			x_caBlock->TestFailed(new StringRaw("Char TestFailed"));
		}
	}

	DoubleTestRaw::DoubleTestRaw(CABlock x_caBlock)
	{
		this->x_caBlock.Assign(x_caBlock);
	}
	void DoubleTestRaw::Test()
	{
		x_caBlock->Send(new StringRaw("Doing DoubleTest"));
		x_caBlock->Send(new StringRaw("\tDoing DoDoubleMethodsTest"));
		DoDoubleMethodsTest();
		x_caBlock->Send(new StringRaw("\tDoing DoDoubleMath"));
		DoDoubleMath();
		x_caBlock->Send(new StringRaw("\tDoing DoubleOperators"));
		DoubleOperators();
		x_caBlock->Send(new StringRaw("\tDoing DoubleNanTest"));
		DoubleNanTest();
		x_caBlock->Send(new StringRaw("\tDoing DoubleArrayTest"));
		DoubleArrayTest();
		x_caBlock->Send(new StringRaw("\tDoing DoubleMiscTests"));
		DoubleMiscTests();
	}
	void DoubleTestRaw::DoDoubleMethodsTest()
	{
		Double x_num = 3.159;
		CxAssert(((Double)x_num).CompareTo(3.159) == 0);
		CxAssert(((Double)x_num).CompareTo(( Object ) 3.159) == 0);
		CxAssert(((Double)x_num).Equals(3.159));
		CxAssert(DoubleRaw::Parse(new StringRaw("3.159")) == 3.159);
		CxAssert(((Double)x_num).ToString() == new StringRaw("3.159"));
		String x_text = ((Double)-1.79769313486232E+308).ToString();
		CxAssert(x_text->StartsWith(new StringRaw("-1.7976")) && x_text->EndsWith(new StringRaw("E+308")));
		x_num = 1000000000001;
		CxAssert(x_num > 1000000000000);
		x_num = -1000000000000;
		CxAssert(x_num <= -1000000000000);
		x_num = 10000;
		CxAssert(( Int64 ) x_num == 10000);
		CxAssert(( Int32 ) x_num == 10000);
		CxAssert(( UInt32 ) x_num == 10000);
		Object x_obj = x_num;
		CxAssert(( Double ) x_obj == 10000);
		x_num = Double::Epsilon;
		CxAssert(x_num == Double::Epsilon);
		x_num = 1.79769313486232E+308;
		CxAssert(x_num == 1.79769313486232E+308);
		x_num = -1.79769313486232E+308;
		CxAssert(x_num == -1.79769313486232E+308);
		x_obj.Assign(5);
		CxAssert(x_obj->Equals(5));
		CxAssert(x_obj->ToString() == new StringRaw("5"));
	}
	void DoubleTestRaw::DoDoubleMath()
	{
		Double x_num = 355;
		Double x_num2 = 113;
		Double x_num3 = x_num / x_num2;
		CxAssert(x_num3,3.14159);
		CxAssert(x_num3 * x_num2,355);
		CxAssert(x_num + x_num2,468);
		CxAssert(x_num - x_num2,242);
		x_num = 2;
		x_num2 = x_num + Double::Epsilon;
		CxAssert(x_num2 == 2);
		x_num = 2;
		x_num2 = x_num + 4.94065645841247E-24;
		CxAssert(x_num2 == 2);
	}
	void DoubleTestRaw::DoubleOperators()
	{
		Double x_num = 66;
		Char x_c = '';
		Int32 x_num2 = 1;
		UInt32 x_num3 = 1;
		Int64 x_num4 = 1;
		Double x_num5 = 1;
		CxAssert(x_num == 66);
		CxAssert(x_num + ( Double ) ( Int32 ) x_c == 67);
		CxAssert(x_num + ( Double ) x_num2 == 67);
		CxAssert(x_num + ( Double ) x_num3 == 67);
		CxAssert(x_num + ( Double ) x_num4 == 67);
		CxAssert(x_num + x_num5 == 67);
		CxAssert(x_num - ( Double ) ( Int32 ) x_c == 65);
		CxAssert(x_num - ( Double ) x_num2 == 65);
		CxAssert(x_num - ( Double ) x_num3 == 65);
		CxAssert(x_num - ( Double ) x_num4 == 65);
		CxAssert(x_num - x_num5 == 65);
		CxAssert(x_num * ( Double ) ( Int32 ) x_c == 66);
		CxAssert(x_num * ( Double ) x_num2 == 66);
		CxAssert(x_num * ( Double ) x_num3 == 66);
		CxAssert(x_num * ( Double ) x_num4 == 66);
		CxAssert(x_num * x_num5 == 66);
		CxAssert(x_num / ( Double ) ( Int32 ) x_c == 66);
		CxAssert(x_num / ( Double ) x_num2 == 66);
		CxAssert(x_num / ( Double ) x_num3 == 66);
		CxAssert(x_num / ( Double ) x_num4 == 66);
		CxAssert(x_num / x_num5 == 66);
		CxAssert(x_num % ( Double ) ( Int32 ) x_c == 0);
		CxAssert(x_num % ( Double ) x_num2 == 0);
		CxAssert(x_num % ( Double ) x_num3 == 0);
		CxAssert(x_num % ( Double ) x_num4 == 0);
		CxAssert(x_num % x_num5 == 0);
		CxAssert(( Double ) ( Int32 ) x_c < x_num);
		CxAssert(( Double ) x_num2 < x_num);
		CxAssert(( Double ) x_num3 < x_num);
		CxAssert(( Double ) x_num4 < x_num);
		CxAssert(x_num5 < x_num);
		CxAssert(( Double ) ( Int32 ) x_c > x_num,false);
		CxAssert(( Double ) x_num2 > x_num,false);
		CxAssert(( Double ) x_num3 > x_num,false);
		CxAssert(( Double ) x_num4 > x_num,false);
		CxAssert(x_num5 > x_num,false);
		CxAssert(( x_num += 1 ) == 67);
		CxAssert(( x_num -= 1 ) == 66);
		CxAssert(x_num++ == 66);
		CxAssert(x_num-- == 67);
		CxAssert(( Double ) ( Int32 ) x_c == x_num,false);
		CxAssert(( Double ) x_num2 == x_num,false);
		CxAssert(( Double ) x_num3 == x_num,false);
		CxAssert(( Double ) x_num4 == x_num,false);
		CxAssert(x_num5 == x_num,false);
		CxAssert(( Double ) ( Int32 ) x_c != x_num);
		CxAssert(( Double ) x_num2 != x_num);
		CxAssert(( Double ) x_num3 != x_num);
		CxAssert(( Double ) x_num4 != x_num);
		CxAssert(x_num5 != x_num);
		CxAssert(( Double ) ( Int32 ) x_c <= x_num);
		CxAssert(( Double ) x_num2 <= x_num);
		CxAssert(( Double ) x_num3 <= x_num);
		CxAssert(( Double ) x_num4 <= x_num);
		CxAssert(x_num5 <= x_num);
		CxAssert(( Double ) ( Int32 ) x_c >= x_num,false);
		CxAssert(( Double ) x_num2 >= x_num,false);
		CxAssert(( Double ) x_num3 >= x_num,false);
		CxAssert(( Double ) x_num4 >= x_num,false);
		CxAssert(x_num5 >= x_num,false);
		CxAssert(( x_num += ( Double ) ( Int32 ) x_c ) == 67);
		CxAssert(( x_num -= ( Double ) ( Int32 ) x_c ) == 66);
		CxAssert(( x_num += ( Double ) x_num2 ) == 67);
		CxAssert(( x_num -= ( Double ) x_num2 ) == 66);
		CxAssert(( x_num += ( Double ) x_num3 ) == 67);
		CxAssert(( x_num -= ( Double ) x_num3 ) == 66);
		CxAssert(( x_num += ( Double ) x_num4 ) == 67);
		CxAssert(( x_num -= ( Double ) x_num4 ) == 66);
		CxAssert(( x_num *= ( Double ) ( Int32 ) x_c ) == 66);
		CxAssert(( x_num /= ( Double ) ( Int32 ) x_c ) == 66);
		CxAssert(( x_num *= ( Double ) x_num2 ) == 66);
		CxAssert(( x_num /= ( Double ) x_num2 ) == 66);
		CxAssert(( x_num *= ( Double ) x_num3 ) == 66);
		CxAssert(( x_num /= ( Double ) x_num3 ) == 66);
		CxAssert(( x_num *= ( Double ) x_num4 ) == 66);
		CxAssert(( x_num /= ( Double ) x_num4 ) == 66);
		CxAssert(( x_num %= ( Double ) ( Int32 ) x_c ) == 0);
		x_num = 66;
		CxAssert(( x_num %= ( Double ) x_num2 ) == 0);
		x_num = 5;
		CxAssert(x_num % 2.2,0.6);
	}
	void DoubleTestRaw::DoubleNanTest()
	{
		Double x_num = Double::NaN;
		Double x_num2 = 1;
		CxAssert(DoubleRaw::IsNaN(x_num));
		CxAssert(DoubleRaw::IsInfinity(Double::PositiveInfinity));
		CxAssert(DoubleRaw::IsNegativeInfinity(Double::NegativeInfinity));
		CxAssert(DoubleRaw::IsPositiveInfinity(Double::PositiveInfinity));
		CxAssert(DoubleRaw::IsNaN(x_num * x_num2));
		CxAssert(DoubleRaw::IsNaN(x_num / x_num2));
		CxAssert(DoubleRaw::IsNaN(x_num + x_num2));
		CxAssert(DoubleRaw::IsNaN(x_num - x_num2));
		CxAssert(DoubleRaw::IsNaN(x_num % x_num2));
		CxAssert(x_num < x_num2,false);
		CxAssert(x_num > x_num2,false);
		CxAssert(x_num <= x_num2,false);
		CxAssert(x_num >= x_num2,false);
		CxAssert(x_num == x_num2,false);
		CxAssert(x_num == x_num,false);
		CxAssert(x_num2 < x_num,false);
		CxAssert(x_num2 > x_num,false);
		CxAssert(x_num2 <= x_num,false);
		CxAssert(x_num2 >= x_num,false);
		CxAssert(x_num != x_num2);
		CxAssert(x_num != x_num);
		x_num = Double::NaN;
		x_num2 = Double::NaN;
		if ( x_num == x_num2 )
		{
			DoubleTestFailed();
		}
		else
		{
			CxAssert(true);
		}
		if ( x_num == x_num )
		{
			DoubleTestFailed();
		}
		else
		{
			CxAssert(true);
		}
		if ( x_num != x_num2 )
		{
			CxAssert(true);
		}
		else
		{
			DoubleTestFailed();
		}
		if ( x_num != x_num )
		{
			CxAssert(true);
		}
		else
		{
			DoubleTestFailed();
		}
		if ( x_num > x_num2 )
		{
			DoubleTestFailed();
		}
		else
		{
			CxAssert(true);
		}
		if ( x_num >= x_num2 )
		{
			DoubleTestFailed();
		}
		else
		{
			CxAssert(true);
		}
		if ( x_num < x_num2 )
		{
			DoubleTestFailed();
		}
		else
		{
			CxAssert(true);
		}
		if ( x_num <= x_num2 )
		{
			DoubleTestFailed();
		}
		else
		{
			CxAssert(true);
		}
		if ( x_num == 0 )
		{
			DoubleTestFailed();
		}
		else
		{
			CxAssert(true);
		}
		CxAssert(((Double)Double::NaN).Equals(Double::NaN));
	}
	void DoubleTestRaw::DoubleArrayTest()
	{
		static Double DoubleArrayTestArray0[4] = {1,2,3,4};
		static Double DoubleArrayTestArray1[2][4] = {{1,2,3,4},{4,5,6,7}};
		static Double DoubleArrayTestArray2[2][2][4] = {{{1,2,3,4},{5,6,7,8}},{{9,10,11,12},{13,14,15,16}}};
		PointerType<ArrayRaw<Double>> x_array = (new ArrayRaw<Double>(4))->Initialize((Double*) DoubleArrayTestArray0);
		CxAssert((*x_array->Address(1)) == 2);
		PointerType<ArrayRaw<Double>> x_array2 = (new ArrayRaw<Double>(2,4))->Initialize((Double*) DoubleArrayTestArray1);
		CxAssert((*x_array2->Address(0,2)) == 3);
		PointerType<ArrayRaw<Double>> x_array3 = (new ArrayRaw<Double>(2,2,4))->Initialize((Double*) DoubleArrayTestArray2);
		CxAssert((*x_array3->Address(0,0,3)) == 4);
		(*x_array3->Address(0,0,3)) = 22;
		CxAssert((*x_array3->Address(0,0,3)) == 22);
		(*x_array2->Address(0,2)) = Double::NaN;
		CxAssert(DoubleRaw::IsNaN((*x_array2->Address(0,2))));
		x_array3->SetValue(4,0,0,3);
		CxAssert((*x_array3->Address(0,0,3)) == 4);
	}
	void DoubleTestRaw::DoubleMiscTests()
	{
		Double x_num = -1;
		Double x_val = 1;
		CxAssert(MathRaw::Abs(x_num) == 1);
		CxAssert(MathRaw::Max(x_num,x_val) == 1);
		CxAssert(MathRaw::Min(x_num,x_val) == -1);
		CxAssert(MathRaw::Sign(x_num) < 0);
		PointerType<StringBuilderRaw> x_stringBuilder = new StringBuilderRaw();
		x_stringBuilder->Append(x_num);
		CxAssert(x_stringBuilder->ToString() == new StringRaw("-1"));
	}
	void DoubleTestRaw::DoubleCompare(Double x_n1,Double x_n2,Double x_resolution)
	{
		if ( MathRaw::Abs(x_n1 - x_n2) > x_resolution )
		{
			DoubleTestFailed();
		}
	}
	void DoubleTestRaw::CxAssert(Double x_x,Double x_y)
	{
		DoubleCompare(x_x,x_y,1E-05);
	}
	void DoubleTestRaw::CxAssert(Boolean x_x)
	{
		if ( !x_x )
		{
			DoubleTestFailed();
		}
	}
	void DoubleTestRaw::CxAssert(Boolean x_x,Boolean x_y)
	{
		if ( x_x != x_y )
		{
			DoubleTestFailed();
		}
	}
	void DoubleTestRaw::DoubleTestFailed()
	{
		x_caBlock->TestFailed(new StringRaw("Double TestFailed"));
	}

	EncodingTestRaw::EncodingTestRaw(CABlock x_caBlock)
	{
		this->x_caBlock.Assign(x_caBlock);
	}
	void EncodingTestRaw::Test()
	{
		x_caBlock->Send(new StringRaw("Doing EncodingTest"));
		x_caBlock->Send(new StringRaw("\tDoing EncodingMethodsTest"));
		EncodingMethodsTest();
	}
	void EncodingTestRaw::EncodingMethodsTest()
	{
		static Byte EncodingMethodsTestArray0[7] = {84,101,115,116,63,63,63};
		String x_s = new StringRaw("Test\u0394\u0396\u039f");
		PointerType<ArrayRaw<Byte>> x_myCharsAsBytes = (new ArrayRaw<Byte>(7))->Initialize((Byte*) EncodingMethodsTestArray0);
		PointerType<EncodingRaw> x_aSCII = Encoding::get_ASCII();
		CxAssert(x_aSCII->GetByteCount(x_s) == 7);
		PointerType<ArrayRaw<Byte>> x_bytes = x_aSCII->GetBytes(x_s);
		CxAssert(CompareBytes(x_bytes,x_myCharsAsBytes));
		String x_string = x_aSCII->GetString(x_bytes);
		CxAssert(x_string == new StringRaw("Test???"));
		String x_s2 = new StringRaw("123\u042e\u040b\u042f\u0403\u041c\u0422\u0464\u0460\u046a\u047a");
		CxAssert(x_aSCII->GetByteCount(x_s2) == 13);
		PointerType<ArrayRaw<Byte>> x_bytes2 = x_aSCII->GetBytes(x_s2);
		String x_string2 = x_aSCII->GetString(x_bytes2);
		CxAssert(x_string2 == new StringRaw("123??????????"));
	}
	Boolean EncodingTestRaw::CompareBytes(PointerType<ArrayRaw<Byte>> x_bytes,PointerType<ArrayRaw<Byte>> x_myCharsAsBytes)
	{
		for ( Int32 x_i = 0 ;  x_i < x_bytes->get_Length() ;   x_i++ )
		{
			if ( (*x_bytes->Address(x_i)) != (*x_myCharsAsBytes->Address(x_i)) )
			{
				return false;
			}
		}
		return true;
	}
	void EncodingTestRaw::CxAssert(Boolean x_x)
	{
		if ( !x_x )
		{
			x_caBlock->TestFailed(new StringRaw("Encoding TestFailed"));
		}
	}



	EnumTestRaw::EnumTestRaw(CABlock x_caBlock)
	{
		this->x_caBlock.Assign(x_caBlock);
	}
	void EnumTestRaw::Test()
	{
		x_caBlock->Send(new StringRaw("Doing EnumTest"));
		Test1(Value1_TestEnum);
		Test1(Value1_TestEnum2);
	}
	void EnumTestRaw::Test1(TestEnum x_testEnum)
	{
		if ( x_testEnum == Value1_TestEnum )
		{
			x_testEnum = Value2_TestEnum;
		}
		if ( x_testEnum == Value2_TestEnum )
		{
			x_testEnum = Value3_TestEnum;
		}
		if ( Value3_TestEnum != x_testEnum )
		{
			EnumTestFailed();
		}
		Int32 x_num = ( Int32 ) x_testEnum;
		if ( x_num != 5 )
		{
			EnumTestFailed();
		}
		Double x_num2 = ( Double ) x_testEnum;
		if ( x_num2 != 5 )
		{
			EnumTestFailed();
		}
	}
	void EnumTestRaw::Test1(TestEnum2 x_testEnum)
	{
		if ( x_testEnum == Value1_TestEnum2 )
		{
			x_testEnum = Value2_TestEnum2;
		}
		if ( x_testEnum == Value2_TestEnum2 )
		{
			x_testEnum = Value3_TestEnum2;
		}
		if ( Value3_TestEnum2 != x_testEnum )
		{
			EnumTestFailed();
		}
		Int32 x_num = ( Int32 ) x_testEnum;
		if ( x_num != 5 )
		{
			EnumTestFailed();
		}
		Double x_num2 = ( Double ) x_testEnum;
		if ( x_num2 != 5 )
		{
			EnumTestFailed();
		}
	}
	void EnumTestRaw::EnumTestFailed()
	{
		x_caBlock->TestFailed(new StringRaw("Enum TestFailed"));
	}


	Int32 CABlockRaw::x_intConstant = 8;
	CABlockRaw::CABlockRaw()
	{
	}
	CABlockRaw::CABlockRaw(Int32 x_i)
	{
	}
	void CABlockRaw::Initialize()
	{
		x_fe = FredValue1_FredEnum;
	}
	void CABlockRaw::Execute()
	{
		RunTests(x_fe);
	}
	void CABlockRaw::RunTests(FredEnum x_fre)
	{
		PointerType<BasicTestRaw> x_basicTest = new BasicTestRaw(this);
		x_basicTest->Test();
		PointerType<MathTestRaw> x_mathTest = new MathTestRaw(this);
		x_mathTest->Test();
		PointerType<ArrayTestRaw> x_arrayTest = new ArrayTestRaw(this);
		x_arrayTest->Test();
		PointerType<StringTestRaw> x_stringTest = new StringTestRaw(this);
		x_stringTest->Test();
		PointerType<EnumTestRaw> x_enumTest = new EnumTestRaw(this);
		x_enumTest->Test();
		PointerType<TimeTestRaw> x_timeTest = new TimeTestRaw(this);
		x_timeTest->Test();
		PointerType<CharTestRaw> x_charTest = new CharTestRaw(this);
		x_charTest->Test();
		PointerType<BooleanTestRaw> x_booleanTest = new BooleanTestRaw(this);
		x_booleanTest->Test();
		PointerType<Int32TestRaw> x_int32Test = new Int32TestRaw(this);
		x_int32Test->Test();
		PointerType<UInt32TestRaw> x_uInt32Test = new UInt32TestRaw(this);
		x_uInt32Test->Test();
		PointerType<Int64TestRaw> x_int64Test = new Int64TestRaw(this);
		x_int64Test->Test();
		PointerType<DoubleTestRaw> x_doubleTest = new DoubleTestRaw(this);
		x_doubleTest->Test();
		PointerType<StringBuilderTestRaw> x_stringBuilderTest = new StringBuilderTestRaw(this);
		x_stringBuilderTest->Test();
		PointerType<BufferTestRaw> x_bufferTest = new BufferTestRaw(this);
		x_bufferTest->Test();
		PointerType<ByteTestRaw> x_byteTest = new ByteTestRaw(this);
		x_byteTest->Test();
		PointerType<SByteTestRaw> x_sByteTest = new SByteTestRaw(this);
		x_sByteTest->Test();
		PointerType<Int16TestRaw> x_int16Test = new Int16TestRaw(this);
		x_int16Test->Test();
		PointerType<SingleTestRaw> x_singleTest = new SingleTestRaw(this);
		x_singleTest->Test();
		PointerType<UInt16TestRaw> x_uInt16Test = new UInt16TestRaw(this);
		x_uInt16Test->Test();
		PointerType<UInt64TestRaw> x_uInt64Test = new UInt64TestRaw(this);
		x_uInt64Test->Test();
		PointerType<EncodingTestRaw> x_encodingTest = new EncodingTestRaw(this);
		x_encodingTest->Test();
		PointerType<BigEndianBitConverterTestRaw> x_bigEndianBitConverterTest = new BigEndianBitConverterTestRaw(this);
		x_bigEndianBitConverterTest->Test();
	}
	void CABlockRaw::TestFailed(String x_reason)
	{
		Send(new StringRaw("\t\tERROR: ") + x_reason);
	}

	Int16TestRaw::Int16TestRaw(CABlock x_caBlock)
	{
		this->x_caBlock.Assign(x_caBlock);
	}
	void Int16TestRaw::Test()
	{
		x_caBlock->Send(new StringRaw("Doing Int16Test"));
		x_caBlock->Send(new StringRaw("\tDoing Int16MethodsTest"));
		Int16MethodsTest();
		x_caBlock->Send(new StringRaw("\tDoing Int16MathTest"));
		Int16MathTest();
		x_caBlock->Send(new StringRaw("\tDoing Int16Operators"));
		Int16Operators();
		x_caBlock->Send(new StringRaw("\tDoing Int16ArrayTests"));
		Int16ArrayTests();
		x_caBlock->Send(new StringRaw("\tDoing Int16MiscTests"));
		Int16MiscTests();
	}
	void Int16TestRaw::Int16MethodsTest()
	{
		Int16 x_num = 5;
		CxAssert(((Int16)x_num).CompareTo(5) == 0);
		CxAssert(((Int16)x_num).CompareTo(( Object ) ( Int16 ) 5) == 0);
		CxAssert(((Int16)x_num).Equals(5));
		CxAssert(((Int16)x_num).Equals(( Object ) ( Int16 ) 5));
		CxAssert(Int16Raw::Parse(new StringRaw("-55")) == -55);
		CxAssert(new StringRaw("-75") == ( -75 )->ToString());
		String x_text = ((Int16)32767).ToString();
		CxAssert(x_text == new StringRaw("32767"));
		CxAssert(Int16Raw::Parse(x_text) == 32767);
		String x_text2 = ((Int16)-32768).ToString();
		CxAssert(x_text2 == new StringRaw("-32768"));
		CxAssert(Int16Raw::Parse(x_text2) == -32768);
		Int64 x_num2 = 9223372036854775807;
		x_num = ( Int16 ) x_num2;
		CxAssert(x_num == -1);
		Object x_obj = ( Int16 ) 5;
		CxAssert(x_obj->Equals(( Int16 ) 5));
		CxAssert(x_obj->ToString() == new StringRaw("5"));
	}
	void Int16TestRaw::Int16MathTest()
	{
		Int16 x_num = 600;
		Int16 x_num2 = 1200;
		CxAssert(x_num + x_num2 == 1800);
		CxAssert(x_num - x_num2 == -600);
		CxAssert(x_num * x_num2 == 720000);
		CxAssert(x_num2 / x_num == 2);
		CxAssert(x_num >> 2 == 150);
		CxAssert(x_num << 1 == 1200);
		Int32 x_num3 = 11;
		CxAssert(x_num3 % 5 == 1);
		x_num3 = 8;
		CxAssert(( x_num3 | 1 ) == 9);
		CxAssert(( x_num3 & 1 ) == 0);
		CxAssert(++x_num3 == 9);
		CxAssert(--x_num3 == 8);
		CxAssert(( x_num3 *= 2 ) == 16);
		CxAssert(( x_num3 /= 2 ) == 8);
		CxAssert(( x_num3 %= 2 ) == 0);
		CxAssert(( x_num3 |= 4 ) == 4);
		CxAssert(( x_num3 &= 4 ) == 4);
		CxAssert(-x_num == -600);
		CxAssert(x_num == 600);
		x_num3 = 0;
		CxAssert(~x_num3 == -1);
		CxAssert(++x_num3 == 1);
		CxAssert(--x_num3 == 0);
		CxAssert(x_num < x_num2);
		CxAssert(x_num <= x_num2);
		CxAssert(x_num2 > x_num);
		CxAssert(x_num2 >= x_num);
	}
	void Int16TestRaw::Int16Operators()
	{
		Int16 x_num = 66;
		Char x_c = '';
		Byte x_b = 1;
		SByte x_b2 = 1;
		Int16 x_num2 = 1;
		Int32 x_num3 = 1;
		Int64 x_num4 = 1;
		UInt16 x_num5 = 1;
		UInt32 x_num6 = 1;
		Float x_num7 = 1;
		Double x_num8 = 1;
		CxAssert(x_num == 66);
		CxAssert(x_num + x_c == 67);
		CxAssert(x_num + x_b == 67);
		CxAssert(x_num + x_b2 == 67);
		CxAssert(x_num + x_num2 == 67);
		CxAssert(x_num + x_num3 == 67);
		CxAssert(x_num + x_num4 == 67);
		CxAssert(x_num + x_num5 == 67);
		CxAssert(x_num + x_num6 == 67);
		CxAssert(( Float ) x_num + x_num7 == 67);
		CxAssert(( Double ) x_num + x_num8 == 67);
		CxAssert(x_num - x_c == 65);
		CxAssert(x_num - x_b == 65);
		CxAssert(x_num - x_b2 == 65);
		CxAssert(x_num - x_num2 == 65);
		CxAssert(x_num - x_num3 == 65);
		CxAssert(x_num - x_num4 == 65);
		CxAssert(x_num - x_num5 == 65);
		CxAssert(x_num - x_num6 == 65);
		CxAssert(( Float ) x_num - x_num7 == 65);
		CxAssert(( Double ) x_num - x_num8 == 65);
		CxAssert(x_num * x_c == 66);
		CxAssert(x_num * x_b == 66);
		CxAssert(x_num * x_b2 == 66);
		CxAssert(x_num * x_num2 == 66);
		CxAssert(x_num * x_num3 == 66);
		CxAssert(x_num * x_num4 == 66);
		CxAssert(x_num * x_num5 == 66);
		CxAssert(x_num * x_num6 == 66);
		CxAssert(( Float ) x_num * x_num7 == 66);
		CxAssert(( Double ) x_num * x_num8 == 66);
		CxAssert(( Int32 ) x_num / ( Int32 ) x_c == 66);
		CxAssert(( Int32 ) x_num / ( Int32 ) x_b == 66);
		CxAssert(x_num / x_b2 == 66);
		CxAssert(x_num / x_num2 == 66);
		CxAssert(x_num / x_num3 == 66);
		CxAssert(x_num / x_num4 == 66);
		CxAssert(( Int32 ) x_num / ( Int32 ) x_num5 == 66);
		CxAssert(( Int64 ) x_num / ( Int64 ) x_num6 == 66);
		CxAssert(( Float ) x_num / x_num7 == 66);
		CxAssert(( Double ) x_num / x_num8 == 66);
		CxAssert(( Int32 ) x_num % ( Int32 ) x_c == 0);
		CxAssert(( Int32 ) x_num % ( Int32 ) x_b == 0);
		CxAssert(x_num % x_b2 == 0);
		CxAssert(x_num % x_num2 == 0);
		CxAssert(x_num % x_num3 == 0);
		CxAssert(x_num % x_num4 == 0);
		CxAssert(( Int32 ) x_num % ( Int32 ) x_num5 == 0);
		CxAssert(( Int64 ) x_num % ( Int64 ) x_num6 == 0);
		CxAssert(( Float ) x_num % x_num7 == 0);
		CxAssert(( Double ) x_num % x_num8 == 0);
		CxAssert(( x_num & x_c ) == 0);
		CxAssert(( x_num & x_b ) == 0);
		CxAssert(( x_num & x_b2 ) == 0);
		CxAssert(( x_num & x_num2 ) == 0);
		CxAssert(( x_num & x_num3 ) == 0);
		CxAssert(( x_num & x_num4 ) == 0);
		CxAssert(( x_num & x_num5 ) == 0);
		CxAssert(( x_num & x_num6 ) == 0);
		CxAssert(( x_num | ( Int16 ) x_c ) == 67);
		CxAssert(( x_num | x_b ) == 67);
		CxAssert(( x_num | x_b2 ) == 67);
		CxAssert(( x_num | x_num2 ) == 67);
		CxAssert(( x_num | ( Int16 ) x_num3 ) == 67);
		CxAssert(( x_num | ( Int16 ) x_num4 ) == 67);
		CxAssert(( x_num | ( Int16 ) x_num5 ) == 67);
		CxAssert(( x_num | ( Int16 ) x_num6 ) == 67);
		CxAssert(( x_num ^ x_c ) == 67);
		CxAssert(( x_num ^ x_b ) == 67);
		CxAssert(( x_num ^ x_b2 ) == 67);
		CxAssert(( x_num ^ x_num2 ) == 67);
		CxAssert(( x_num ^ x_num3 ) == 67);
		CxAssert(( x_num ^ x_num4 ) == 67);
		CxAssert(( x_num ^ x_num5 ) == 67);
		CxAssert(( x_num ^ x_num6 ) == 67);
		CxAssert(~x_num == -67);
		CxAssert(x_c < x_num);
		CxAssert(x_b < x_num);
		CxAssert(x_b2 < x_num);
		CxAssert(x_num2 < x_num);
		CxAssert(x_num3 < x_num);
		CxAssert(x_num4 < x_num);
		CxAssert(x_num5 < x_num);
		CxAssert(x_num6 < x_num);
		CxAssert(x_num7 < ( Float ) x_num);
		CxAssert(x_num8 < ( Double ) x_num);
		CxAssert(x_c > x_num,false);
		CxAssert(x_b > x_num,false);
		CxAssert(x_b2 > x_num,false);
		CxAssert(x_num2 > x_num,false);
		CxAssert(x_num3 > x_num,false);
		CxAssert(x_num4 > x_num,false);
		CxAssert(x_num5 > x_num,false);
		CxAssert(x_num6 > x_num,false);
		CxAssert(x_num7 > ( Float ) x_num,false);
		CxAssert(x_num8 > ( Double ) x_num,false);
		CxAssert(( x_num = ( Int16 ) ( x_num + 1 ) ) == 67);
		CxAssert(( x_num = ( Int16 ) ( x_num - 1 ) ) == 66);
		CxAssert(x_num++ == 66);
		CxAssert(x_num-- == 67);
		CxAssert(x_num << 1 == 132);
		CxAssert(x_num >> 1 == 33);
		CxAssert(x_c == x_num,false);
		CxAssert(x_b == x_num,false);
		CxAssert(x_b2 == x_num,false);
		CxAssert(x_num2 == x_num,false);
		CxAssert(x_num3 == x_num,false);
		CxAssert(x_num4 == x_num,false);
		CxAssert(x_num5 == x_num,false);
		CxAssert(x_num6 == x_num,false);
		CxAssert(x_num7 == ( Float ) x_num,false);
		CxAssert(x_num8 == ( Double ) x_num,false);
		CxAssert(x_c != x_num);
		CxAssert(x_b != x_num);
		CxAssert(x_b2 != x_num);
		CxAssert(x_num2 != x_num);
		CxAssert(x_num3 != x_num);
		CxAssert(x_num4 != x_num);
		CxAssert(x_num5 != x_num);
		CxAssert(x_num6 != x_num);
		CxAssert(x_num7 != ( Float ) x_num);
		CxAssert(x_num8 != ( Double ) x_num);
		CxAssert(x_c <= x_num);
		CxAssert(x_b <= x_num);
		CxAssert(x_b2 <= x_num);
		CxAssert(x_num2 <= x_num);
		CxAssert(x_num3 <= x_num);
		CxAssert(x_num4 <= x_num);
		CxAssert(x_num5 <= x_num);
		CxAssert(x_num6 <= x_num);
		CxAssert(x_num7 <= ( Float ) x_num);
		CxAssert(x_num8 <= ( Double ) x_num);
		CxAssert(x_c >= x_num,false);
		CxAssert(x_b >= x_num,false);
		CxAssert(x_b2 >= x_num,false);
		CxAssert(x_num2 >= x_num,false);
		CxAssert(x_num3 >= x_num,false);
		CxAssert(x_num4 >= x_num,false);
		CxAssert(x_num5 >= x_num,false);
		CxAssert(x_num6 >= x_num,false);
		CxAssert(x_num7 >= ( Float ) x_num,false);
		CxAssert(x_num8 >= ( Double ) x_num,false);
		CxAssert(( x_num = ( Int16 ) ( x_num + ( Int16 ) x_c ) ) == 67);
		CxAssert(( x_num = ( Int16 ) ( x_num - ( Int16 ) x_c ) ) == 66);
		CxAssert(( x_num = ( Int16 ) ( x_num + ( Int16 ) x_num3 ) ) == 67);
		CxAssert(( x_num = ( Int16 ) ( x_num - ( Int16 ) x_num3 ) ) == 66);
		CxAssert(( x_num = ( Int16 ) ( x_num * ( Int16 ) x_c ) ) == 66);
		CxAssert(( x_num = ( Int16 ) ( x_num / ( Int16 ) x_c ) ) == 66);
		CxAssert(( x_num = ( Int16 ) ( x_num * ( Int16 ) x_num3 ) ) == 66);
		CxAssert(( x_num = ( Int16 ) ( x_num / ( Int16 ) x_num3 ) ) == 66);
		CxAssert(( x_num = ( Int16 ) ( x_num % ( Int16 ) x_c ) ) == 0);
		x_num = 66;
		CxAssert(( x_num = ( Int16 ) ( x_num % ( Int16 ) x_num3 ) ) == 0);
		x_num = 66;
		CxAssert(( x_num = ( Int16 ) ( x_num & ( Int16 ) x_c ) ) == 0);
		x_num = 66;
		CxAssert(( x_num = ( Int16 ) ( x_num & ( Int16 ) x_num3 ) ) == 0);
		x_num = 66;
		CxAssert(( x_num = ( Int16 ) ( x_num | ( Int16 ) x_c ) ) == 67);
		x_num = 66;
		CxAssert(( x_num = ( Int16 ) ( x_num | ( Int16 ) x_num3 ) ) == 67);
		x_num = 66;
		CxAssert(( x_num = ( Int16 ) ( x_num ^ ( Int16 ) x_c ) ) == 67);
		x_num = 66;
		CxAssert(( x_num = ( Int16 ) ( x_num ^ ( Int16 ) x_num3 ) ) == 67);
		x_num = 66;
		CxAssert(( x_num = ( Int16 ) ( x_num << ( Int32 ) x_b ) ) == 132);
		x_num = 66;
		CxAssert(( x_num = ( Int16 ) ( x_num << ( Int32 ) x_num2 ) ) == 132);
		x_num = 66;
		CxAssert(( x_num = ( Int16 ) ( x_num << ( Int32 ) x_c ) ) == 132);
		x_num = 66;
		CxAssert(( x_num = ( Int16 ) ( x_num << x_num3 ) ) == 132);
		x_num = 66;
		CxAssert(( x_num = ( Int16 ) ( x_num >> ( Int32 ) x_c ) ) == 33);
		x_num = 66;
		CxAssert(( x_num = ( Int16 ) ( x_num >> x_num3 ) ) == 33);
		x_num = 66;
		Int16 x_num9 = 0;
		CxAssert(x_num9 == 0);
		CxAssert(x_num9 == 0);
		CxAssert(x_num3 <= 2);
		CxAssert(x_num3 >= -2);
	}
	void Int16TestRaw::Int16ArrayTests()
	{
		static Int16 Int16ArrayTestsArray0[5] = {1,2,3,4,5};
		static Int16 Int16ArrayTestsArray1[4] = {1,2,3,4};
		static Int16 Int16ArrayTestsArray2[2][4] = {{1,2,3,4},{4,5,6,7}};
		static Int16 Int16ArrayTestsArray3[2][2][4] = {{{1,2,3,4},{5,6,7,8}},{{9,10,11,12},{13,14,15,16}}};
		PointerType<ArrayRaw<Int16>> x_array = (new ArrayRaw<Int16>(5))->Initialize((Int16*) Int16ArrayTestsArray0);
		CxAssert(x_array->get_Length() == 5);
		CxAssert((*x_array->Address(3)) == 4);
		PointerType<ArrayRaw<Int16>> x_array2 = (new ArrayRaw<Int16>(4))->Initialize((Int16*) Int16ArrayTestsArray1);
		CxAssert((*x_array2->Address(1)) == 2);
		PointerType<ArrayRaw<Int16>> x_array3 = (new ArrayRaw<Int16>(2,4))->Initialize((Int16*) Int16ArrayTestsArray2);
		CxAssert((*x_array3->Address(0,2)) == 3);
		PointerType<ArrayRaw<Int16>> x_array4 = (new ArrayRaw<Int16>(2,2,4))->Initialize((Int16*) Int16ArrayTestsArray3);
		CxAssert((*x_array4->Address(0,0,3)) == 4);
		(*x_array4->Address(0,0,3)) = 6;
		CxAssert((*x_array4->Address(0,0,3)) == 6);
		x_array4->SetValue(( Int16 ) 4,0,0,3);
		CxAssert((*x_array4->Address(0,0,3)) == 4);
	}
	void Int16TestRaw::Int16MiscTests()
	{
		Int16 x_num = -1;
		Int16 x_val = 1;
		CxAssert(MathRaw::Abs(x_num) == 1);
		CxAssert(MathRaw::Max(x_num,x_val) == 1);
		CxAssert(MathRaw::Min(x_num,x_val) == -1);
		CxAssert(MathRaw::Sign(x_num) < 0);
		PointerType<StringBuilderRaw> x_stringBuilder = new StringBuilderRaw();
		x_stringBuilder->Append(x_num);
		CxAssert(x_stringBuilder->ToString() == new StringRaw("-1"));
		x_stringBuilder->Insert(2,x_num);
		CxAssert(x_stringBuilder->ToString() == new StringRaw("-1-1"));
	}
	void Int16TestRaw::CxAssert(Boolean x_x)
	{
		if ( !x_x )
		{
			x_caBlock->TestFailed(new StringRaw("Int16 TestFailed"));
		}
	}
	void Int16TestRaw::CxAssert(Boolean x_x,Boolean x_y)
	{
		if ( x_x != x_y )
		{
			x_caBlock->TestFailed(new StringRaw("Int16 TestFailed"));
		}
	}

	Int32TestRaw::Int32TestRaw(CABlock x_caBlock)
	{
		this->x_caBlock.Assign(x_caBlock);
	}
	void Int32TestRaw::Test()
	{
		x_caBlock->Send(new StringRaw("Doing Int32Test"));
		x_caBlock->Send(new StringRaw("\tDoing Int32MethodsTest"));
		Int32MethodsTest();
		x_caBlock->Send(new StringRaw("\tDoing Int32MathTest"));
		Int32MathTest();
		x_caBlock->Send(new StringRaw("\tDoing Int32Operators"));
		Int32Operators();
		x_caBlock->Send(new StringRaw("\tDoing Int32Conversion"));
		Int32Conversion();
		x_caBlock->Send(new StringRaw("\tDoing Int32ArrayTests"));
		Int32ArrayTests();
		x_caBlock->Send(new StringRaw("\tDoing Int32MiscTests"));
		Int32MiscTests();
	}
	void Int32TestRaw::Int32Conversion()
	{
		Double x_num = 1;
		Double x_num2 = 2;
		if ( x_num < x_num2 )
		{
			x_num = 3;
		}
		Int32 x_num3 = ( Int32 ) x_num;
		CxAssert(x_num3 == 3);
	}
	void Int32TestRaw::Int32MethodsTest()
	{
		Int32 x_num = 5;
		CxAssert(((Int32)x_num).CompareTo(5) == 0);
		CxAssert(((Int32)x_num).CompareTo(( Object ) 5) == 0);
		CxAssert(((Int32)x_num).Equals(5));
		CxAssert(((Int32)x_num).Equals(( Object ) 5));
		CxAssert(Int32Raw::Parse(new StringRaw("-55")) == -55);
		CxAssert(new StringRaw("-75") == ( -75 )->ToString());
		String x_text = ((Int32)2147483647).ToString();
		CxAssert(x_text == new StringRaw("2147483647"));
		CxAssert(Int32Raw::Parse(x_text) == 2147483647);
		String x_text2 = ((Int32)-2147483648).ToString();
		CxAssert(x_text2 == new StringRaw("-2147483648"));
		CxAssert(Int32Raw::Parse(x_text2) == -2147483648);
		Int64 x_num2 = 9223372036854775807;
		x_num = ( Int32 ) x_num2;
		CxAssert(x_num == -1);
		Object x_obj = 5;
		CxAssert(x_obj->Equals(5));
	}
	void Int32TestRaw::Int32MathTest()
	{
		Int32 x_num = 60000;
		Int32 x_num2 = 120000;
		CxAssert(x_num + x_num2 == 180000);
		CxAssert(x_num - x_num2 == -60000);
		CxAssert(x_num * x_num2 == -1389934592);
		CxAssert(x_num2 / x_num == 2);
		CxAssert(x_num >> 2 == 15000);
		CxAssert(x_num << 1 == 120000);
		Int32 x_num3 = 11;
		CxAssert(x_num3 % 5 == 1);
		x_num3 = 8;
		CxAssert(( x_num3 | 1 ) == 9);
		CxAssert(( x_num3 & 1 ) == 0);
		CxAssert(++x_num3 == 9);
		CxAssert(--x_num3 == 8);
		CxAssert(( x_num3 *= 2 ) == 16);
		CxAssert(( x_num3 /= 2 ) == 8);
		CxAssert(( x_num3 %= 2 ) == 0);
		CxAssert(( x_num3 |= 4 ) == 4);
		CxAssert(( x_num3 &= 4 ) == 4);
		CxAssert(-x_num == -60000);
		CxAssert(x_num == 60000);
		x_num3 = 0;
		CxAssert(~x_num3 == -1);
		CxAssert(++x_num3 == 1);
		CxAssert(--x_num3 == 0);
		CxAssert(x_num < x_num2);
		CxAssert(x_num <= x_num2);
		CxAssert(x_num2 > x_num);
		CxAssert(x_num2 >= x_num);
	}
	void Int32TestRaw::Int32Operators()
	{
		Int32 x_num = 66;
		Char x_c = '';
		Int32 x_num2 = 1;
		UInt32 x_num3 = 1;
		Int64 x_num4 = 1;
		Double x_num5 = 1;
		CxAssert(x_num == 66);
		CxAssert(x_num + x_c == 67);
		CxAssert(x_num + x_num2 == 67);
		CxAssert(x_num + x_num3 == 67);
		CxAssert(x_num + x_num4 == 67);
		CxAssert(( Int64 ) ( ( Double ) x_num + x_num5 ) == 67);
		CxAssert(x_num - x_c == 65);
		CxAssert(x_num - x_num2 == 65);
		CxAssert(x_num - x_num3 == 65);
		CxAssert(x_num - x_num4 == 65);
		CxAssert(( Int64 ) ( ( Double ) x_num - x_num5 ) == 65);
		CxAssert(x_num * x_c == 66);
		CxAssert(x_num * x_num2 == 66);
		CxAssert(x_num * x_num3 == 66);
		CxAssert(x_num * x_num4 == 66);
		CxAssert(( Int64 ) ( ( Double ) x_num * x_num5 ) == 66);
		CxAssert(x_num / ( Int32 ) x_c == 66);
		CxAssert(x_num / x_num2 == 66);
		CxAssert(( Int64 ) x_num / ( Int64 ) x_num3 == 66);
		CxAssert(x_num / x_num4 == 66);
		CxAssert(( Int64 ) ( ( Double ) x_num / x_num5 ) == 66);
		CxAssert(x_num % ( Int32 ) x_c == 0);
		CxAssert(x_num % x_num2 == 0);
		CxAssert(( Int64 ) x_num % ( Int64 ) x_num3 == 0);
		CxAssert(x_num % x_num4 == 0);
		CxAssert(( Int64 ) ( ( Double ) x_num % x_num5 ) == 0);
		CxAssert(( x_num & x_c ) == 0);
		CxAssert(( x_num & x_num2 ) == 0);
		CxAssert(( x_num & x_num3 ) == 0);
		CxAssert(( x_num & x_num4 ) == 0);
		CxAssert(( x_num | x_c ) == 67);
		CxAssert(( x_num | x_num2 ) == 67);
		CxAssert(( x_num ^ x_c ) == 67);
		CxAssert(( x_num ^ x_num2 ) == 67);
		CxAssert(( x_num ^ x_num3 ) == 67);
		CxAssert(( x_num ^ x_num4 ) == 67);
		CxAssert(~x_num == -67);
		CxAssert(x_c < x_num);
		CxAssert(x_num2 < x_num);
		CxAssert(x_num3 < x_num);
		CxAssert(x_num4 < x_num);
		CxAssert(x_num5 < ( Double ) x_num);
		CxAssert(x_c > x_num,false);
		CxAssert(x_num2 > x_num,false);
		CxAssert(x_num3 > x_num,false);
		CxAssert(x_num4 > x_num,false);
		CxAssert(x_num5 > ( Double ) x_num,false);
		CxAssert(++x_num == 67);
		CxAssert(--x_num == 66);
		CxAssert(x_num++ == 66);
		CxAssert(x_num-- == 67);
		CxAssert(x_num << 1 == 132);
		CxAssert(x_num >> 1 == 33);
		CxAssert(x_c == x_num,false);
		CxAssert(x_num2 == x_num,false);
		CxAssert(x_num3 == x_num,false);
		CxAssert(x_num4 == x_num,false);
		CxAssert(x_num5 == ( Double ) x_num,false);
		CxAssert(x_c != x_num);
		CxAssert(x_num2 != x_num);
		CxAssert(x_num3 != x_num);
		CxAssert(x_num4 != x_num);
		CxAssert(x_num5 != ( Double ) x_num);
		CxAssert(x_c <= x_num);
		CxAssert(x_num2 <= x_num);
		CxAssert(x_num3 <= x_num);
		CxAssert(x_num4 <= x_num);
		CxAssert(x_num5 <= ( Double ) x_num);
		CxAssert(x_c >= x_num,false);
		CxAssert(x_num2 >= x_num,false);
		CxAssert(x_num3 >= x_num,false);
		CxAssert(x_num4 >= x_num,false);
		CxAssert(x_num5 >= ( Double ) x_num,false);
		CxAssert(( x_num += x_c ) == 67);
		CxAssert(( x_num -= x_c ) == 66);
		CxAssert(( x_num += x_num2 ) == 67);
		CxAssert(( x_num -= x_num2 ) == 66);
		CxAssert(( x_num *= x_c ) == 66);
		CxAssert(( x_num /= ( Int32 ) x_c ) == 66);
		CxAssert(( x_num *= x_num2 ) == 66);
		CxAssert(( x_num /= x_num2 ) == 66);
		CxAssert(( x_num %= ( Int32 ) x_c ) == 0);
		x_num = 66;
		CxAssert(( x_num %= x_num2 ) == 0);
		x_num = 66;
		CxAssert(( x_num &= x_c ) == 0);
		x_num = 66;
		CxAssert(( x_num &= x_num2 ) == 0);
		x_num = 66;
		CxAssert(( x_num |= x_c ) == 67);
		x_num = 66;
		CxAssert(( x_num |= x_num2 ) == 67);
		x_num = 66;
		CxAssert(( x_num ^= x_c ) == 67);
		x_num = 66;
		CxAssert(( x_num ^= x_num2 ) == 67);
		x_num = 66;
		CxAssert(( x_num <<= ( Int32 ) x_c ) == 132);
		x_num = 66;
		CxAssert(( x_num <<= x_num2 ) == 132);
		x_num = 66;
		CxAssert(( x_num >>= ( Int32 ) x_c ) == 33);
		x_num = 66;
		CxAssert(( x_num >>= x_num2 ) == 33);
		x_num = 66;
		Int32 x_num6 = 0;
		CxAssert(x_num6 == 0);
		CxAssert(x_num6 == 0);
		CxAssert(x_num2 <= 2);
		CxAssert(x_num2 >= -2);
	}
	void Int32TestRaw::Int32ArrayTests()
	{
		static Int32 Int32ArrayTestsArray0[5] = {1,2,3,4,5};
		static Int32 Int32ArrayTestsArray1[4] = {1,2,3,4};
		static Int32 Int32ArrayTestsArray2[2][4] = {{1,2,3,4},{4,5,6,7}};
		static Int32 Int32ArrayTestsArray3[2][2][4] = {{{1,2,3,4},{5,6,7,8}},{{9,10,11,12},{13,14,15,16}}};
		PointerType<ArrayRaw<Int32>> x_array = (new ArrayRaw<Int32>(5))->Initialize((Int32*) Int32ArrayTestsArray0);
		CxAssert(x_array->get_Length() == 5);
		CxAssert((*x_array->Address(3)) == 4);
		PointerType<ArrayRaw<Int32>> x_array2 = (new ArrayRaw<Int32>(4))->Initialize((Int32*) Int32ArrayTestsArray1);
		CxAssert((*x_array2->Address(1)) == 2);
		PointerType<ArrayRaw<Int32>> x_array3 = (new ArrayRaw<Int32>(2,4))->Initialize((Int32*) Int32ArrayTestsArray2);
		CxAssert((*x_array3->Address(0,2)) == 3);
		PointerType<ArrayRaw<Int32>> x_array4 = (new ArrayRaw<Int32>(2,2,4))->Initialize((Int32*) Int32ArrayTestsArray3);
		CxAssert((*x_array4->Address(0,0,3)) == 4);
		(*x_array4->Address(0,0,3)) = 6;
		CxAssert((*x_array4->Address(0,0,3)) == 6);
		x_array4->SetValue(4,0,0,3);
		CxAssert((*x_array4->Address(0,0,3)) == 4);
		CxAssert(((Int32)(*x_array4->Address(0,0,3))).ToString() == new StringRaw("4"));
	}
	void Int32TestRaw::Int32MiscTests()
	{
		Int32 x_num = -1;
		Int32 x_val = 1;
		CxAssert(MathRaw::Abs(x_num) == 1);
		CxAssert(MathRaw::Max(x_num,x_val) == 1);
		CxAssert(MathRaw::Min(x_num,x_val) == -1);
		CxAssert(MathRaw::Sign(x_num) < 0);
		PointerType<StringBuilderRaw> x_stringBuilder = new StringBuilderRaw();
		x_stringBuilder->Append(x_num);
		CxAssert(x_stringBuilder->ToString() == new StringRaw("-1"));
	}
	void Int32TestRaw::CxAssert(Boolean x_x)
	{
		if ( !x_x )
		{
			x_caBlock->TestFailed(new StringRaw("Int32 TestFailed"));
		}
	}
	void Int32TestRaw::CxAssert(Boolean x_x,Boolean x_y)
	{
		if ( x_x != x_y )
		{
			x_caBlock->TestFailed(new StringRaw("Int32 TestFailed"));
		}
	}

	Int64TestRaw::Int64TestRaw(CABlock x_caBlock)
	{
		this->x_caBlock.Assign(x_caBlock);
	}
	void Int64TestRaw::Test()
	{
		x_caBlock->Send(new StringRaw("Doing Int64Test"));
		x_caBlock->Send(new StringRaw("\tDoing Int64MethodsTest"));
		Int64MethodsTest();
		x_caBlock->Send(new StringRaw("\tDoing Int64MathTest"));
		Int64MathTest();
		x_caBlock->Send(new StringRaw("\tDoing Int64Operators"));
		Int64Operators();
		x_caBlock->Send(new StringRaw("\tDoing Int64ArrayTests"));
		Int64ArrayTests();
		x_caBlock->Send(new StringRaw("\tDoing Int64MiscTests"));
		Int64MiscTests();
	}
	void Int64TestRaw::Int64MethodsTest()
	{
		Int64 x_num = 5;
		CxAssert(((Int64)x_num).CompareTo(5) == 0);
		CxAssert(((Int64)x_num).CompareTo(( Object ) 5) == 0);
		CxAssert(((Int64)x_num).Equals(5));
		CxAssert(((Int64)x_num).Equals(( Object ) 5));
		CxAssert(Int64Raw::Parse(new StringRaw("-55")) == -55);
		String x_text = ((Int64)9223372036854775807).ToString();
		CxAssert(x_text == new StringRaw("9223372036854775807"));
		CxAssert(Int64Raw::Parse(x_text) == 9223372036854775807);
		String x_text2 = ((Int64)-9223372036854775808).ToString();
		CxAssert(x_text2 == new StringRaw("-9223372036854775808"));
		CxAssert(Int64Raw::Parse(x_text2) == -9223372036854775808);
		Object x_obj = 5;
		CxAssert(x_obj->Equals(5));
		CxAssert(x_obj->ToString() == new StringRaw("5"));
	}
	void Int64TestRaw::Int64MathTest()
	{
		Int64 x_num = 60000000;
		Int64 x_num2 = 120000000;
		CxAssert(x_num + x_num2 == 180000000);
		CxAssert(x_num - x_num2 == -60000000);
		CxAssert(x_num * x_num2 == 7200000000000000);
		CxAssert(x_num * x_num2 == 7200000000000000);
		CxAssert(x_num2 / x_num == 2);
		CxAssert(x_num << 1 == 120000000);
		Int32 x_num3 = 11;
		CxAssert(x_num3 % 5 == 1);
		x_num3 = 8;
		CxAssert(( x_num3 | 1 ) == 9);
		CxAssert(( x_num3 & 1 ) == 0);
		CxAssert(++x_num3 == 9);
		CxAssert(--x_num3 == 8);
		CxAssert(( x_num3 *= 2 ) == 16);
		CxAssert(( x_num3 /= 2 ) == 8);
		CxAssert(( x_num3 %= 2 ) == 0);
		CxAssert(( x_num3 |= 4 ) == 4);
		CxAssert(( x_num3 &= 4 ) == 4);
		CxAssert(-x_num == -60000000);
		CxAssert(x_num == 60000000);
		x_num3 = 0;
		CxAssert(~x_num3 == -1);
		CxAssert(++x_num3 == 1);
		CxAssert(--x_num3 == 0);
	}
	void Int64TestRaw::Int64Operators()
	{
		Int64 x_num = 66;
		Char x_c = '';
		Int32 x_num2 = 1;
		UInt32 x_num3 = 1;
		Int64 x_num4 = 1;
		Double x_num5 = 1;
		CxAssert(x_num == 66);
		CxAssert(x_num + x_c == 67);
		CxAssert(x_num + x_num2 == 67);
		CxAssert(x_num + x_num3 == 67);
		CxAssert(x_num + x_num4 == 67);
		CxAssert(( Double ) x_num + x_num5 == 67);
		CxAssert(x_num - x_c == 65);
		CxAssert(x_num - x_num2 == 65);
		CxAssert(x_num - x_num3 == 65);
		CxAssert(x_num - x_num4 == 65);
		CxAssert(( Double ) x_num - x_num5 == 65);
		CxAssert(x_num * x_c == 66);
		CxAssert(x_num * x_num2 == 66);
		CxAssert(x_num * x_num3 == 66);
		CxAssert(x_num * x_num4 == 66);
		CxAssert(( Double ) x_num * x_num5 == 66);
		CxAssert(x_num / ( Int64 ) x_c == 66);
		CxAssert(x_num / x_num2 == 66);
		CxAssert(x_num / ( Int64 ) x_num3 == 66);
		CxAssert(x_num / x_num4 == 66);
		CxAssert(( Double ) x_num / x_num5 == 66);
		CxAssert(x_num % ( Int64 ) x_c == 0);
		CxAssert(x_num % x_num2 == 0);
		CxAssert(x_num % ( Int64 ) x_num3 == 0);
		CxAssert(x_num % x_num4 == 0);
		CxAssert(( Double ) x_num % x_num5 == 0);
		CxAssert(( x_num & x_c ) == 0);
		CxAssert(( x_num & x_num2 ) == 0);
		CxAssert(( x_num & x_num3 ) == 0);
		CxAssert(( x_num & x_num4 ) == 0);
		CxAssert(( x_num | x_c ) == 67);
		CxAssert(( x_num | x_num3 ) == 67);
		CxAssert(( x_num | x_num4 ) == 67);
		CxAssert(( x_num ^ x_c ) == 67);
		CxAssert(( x_num ^ x_num2 ) == 67);
		CxAssert(( x_num ^ x_num3 ) == 67);
		CxAssert(( x_num ^ x_num4 ) == 67);
		CxAssert(~x_num == -67);
		CxAssert(x_c < x_num);
		CxAssert(x_num2 < x_num);
		CxAssert(x_num3 < x_num);
		CxAssert(x_num4 < x_num);
		CxAssert(x_num5 < ( Double ) x_num);
		CxAssert(x_c > x_num,false);
		CxAssert(x_num2 > x_num,false);
		CxAssert(x_num3 > x_num,false);
		CxAssert(x_num4 > x_num,false);
		CxAssert(x_num5 > ( Double ) x_num,false);
		CxAssert(++x_num == 67);
		CxAssert(--x_num == 66);
		CxAssert(x_num++ == 66);
		CxAssert(x_num-- == 67);
		CxAssert(x_num << 1 == 132);
		CxAssert(x_num >> 1 == 33);
		CxAssert(x_c == x_num,false);
		CxAssert(x_num2 == x_num,false);
		CxAssert(x_num3 == x_num,false);
		CxAssert(x_num4 == x_num,false);
		CxAssert(x_num5 == ( Double ) x_num,false);
		CxAssert(x_c != x_num);
		CxAssert(x_num2 != x_num);
		CxAssert(x_num3 != x_num);
		CxAssert(x_num4 != x_num);
		CxAssert(x_num5 != ( Double ) x_num);
		CxAssert(x_c <= x_num);
		CxAssert(x_num2 <= x_num);
		CxAssert(x_num3 <= x_num);
		CxAssert(x_num4 <= x_num);
		CxAssert(x_num5 <= ( Double ) x_num);
		CxAssert(x_c >= x_num,false);
		CxAssert(x_num2 >= x_num,false);
		CxAssert(x_num3 >= x_num,false);
		CxAssert(x_num4 >= x_num,false);
		CxAssert(x_num5 >= ( Double ) x_num,false);
		CxAssert(( x_num += x_c ) == 67);
		CxAssert(( x_num -= x_c ) == 66);
		CxAssert(( x_num += x_num2 ) == 67);
		CxAssert(( x_num -= x_num2 ) == 66);
		CxAssert(( x_num += x_num3 ) == 67);
		CxAssert(( x_num -= x_num3 ) == 66);
		CxAssert(( x_num += x_num4 ) == 67);
		CxAssert(( x_num -= x_num4 ) == 66);
		CxAssert(( x_num *= x_c ) == 66);
		CxAssert(( x_num /= ( Int64 ) x_c ) == 66);
		CxAssert(( x_num *= x_num2 ) == 66);
		CxAssert(( x_num /= x_num2 ) == 66);
		CxAssert(( x_num *= x_num3 ) == 66);
		CxAssert(( x_num /= ( Int64 ) x_num3 ) == 66);
		CxAssert(( x_num *= x_num4 ) == 66);
		CxAssert(( x_num /= x_num4 ) == 66);
		CxAssert(( x_num %= ( Int64 ) x_c ) == 0);
		x_num = 66;
		CxAssert(( x_num %= x_num2 ) == 0);
		x_num = 66;
		CxAssert(( x_num %= ( Int64 ) x_num3 ) == 0);
		x_num = 66;
		CxAssert(( x_num %= x_num4 ) == 0);
		x_num = 66;
		CxAssert(( x_num &= x_c ) == 0);
		x_num = 66;
		CxAssert(( x_num &= x_num2 ) == 0);
		x_num = 66;
		CxAssert(( x_num &= x_num3 ) == 0);
		x_num = 66;
		CxAssert(( x_num &= x_num4 ) == 0);
		x_num = 66;
		CxAssert(( x_num |= x_c ) == 67);
		x_num = 66;
		CxAssert(( x_num |= x_num3 ) == 67);
		x_num = 66;
		CxAssert(( x_num |= x_num4 ) == 67);
		x_num = 66;
		CxAssert(( x_num ^= x_c ) == 67);
		x_num = 66;
		CxAssert(( x_num ^= x_num2 ) == 67);
		x_num = 66;
		CxAssert(( x_num ^= x_num3 ) == 67);
		x_num = 66;
		CxAssert(( x_num ^= x_num4 ) == 67);
		x_num = 66;
		CxAssert(( x_num <<= ( Int32 ) x_c ) == 132);
		x_num = 66;
		CxAssert(( x_num <<= x_num2 ) == 132);
		x_num = 66;
		CxAssert(( x_num >>= ( Int32 ) x_c ) == 33);
		x_num = 66;
		CxAssert(( x_num >>= x_num2 ) == 33);
		x_num = 66;
	}
	void Int64TestRaw::Int64ArrayTests()
	{
		static Int64 Int64ArrayTestsArray0[5] = {1,2,3,4,5};
		static Int64 Int64ArrayTestsArray1[4] = {1,2,3,4};
		static Int64 Int64ArrayTestsArray2[2][4] = {{1,2,3,4},{4,5,6,7}};
		static Int64 Int64ArrayTestsArray3[2][2][4] = {{{1,2,3,4},{5,6,7,8}},{{9,10,11,12},{13,14,15,16}}};
		PointerType<ArrayRaw<Int64>> x_array = (new ArrayRaw<Int64>(5))->Initialize((Int64*) Int64ArrayTestsArray0);
		CxAssert(x_array->get_Length() == 5);
		CxAssert((*x_array->Address(3)) == 4);
		PointerType<ArrayRaw<Int64>> x_array2 = (new ArrayRaw<Int64>(4))->Initialize((Int64*) Int64ArrayTestsArray1);
		CxAssert((*x_array2->Address(1)) == 2);
		PointerType<ArrayRaw<Int64>> x_array3 = (new ArrayRaw<Int64>(2,4))->Initialize((Int64*) Int64ArrayTestsArray2);
		CxAssert((*x_array3->Address(0,2)) == 3);
		PointerType<ArrayRaw<Int64>> x_array4 = (new ArrayRaw<Int64>(2,2,4))->Initialize((Int64*) Int64ArrayTestsArray3);
		CxAssert((*x_array4->Address(0,0,3)) == 4);
		(*x_array4->Address(0,0,3)) = 6;
		CxAssert((*x_array4->Address(0,0,3)) == 6);
		x_array4->SetValue(4,0,0,3);
		CxAssert((*x_array4->Address(0,0,3)) == 4);
	}
	void Int64TestRaw::Int64MiscTests()
	{
		Int64 x_num = -1;
		Int64 x_val = 1;
		CxAssert(MathRaw::Abs(x_num) == 1);
		CxAssert(MathRaw::Max(x_num,x_val) == 1);
		CxAssert(MathRaw::Min(x_num,x_val) == -1);
		CxAssert(MathRaw::Sign(x_num) < 0);
		PointerType<StringBuilderRaw> x_stringBuilder = new StringBuilderRaw();
		x_stringBuilder->Append(x_num);
		CxAssert(x_stringBuilder->ToString() == new StringRaw("-1"));
	}
	void Int64TestRaw::CxAssert(Boolean x_x)
	{
		if ( !x_x )
		{
			x_caBlock->TestFailed(new StringRaw("Int64 TestFailed"));
		}
	}
	void Int64TestRaw::CxAssert(Boolean x_x,Boolean x_y)
	{
		if ( x_x != x_y )
		{
			x_caBlock->TestFailed(new StringRaw("Int64 TestFailed"));
		}
	}

	MathTestRaw::MathTestRaw(CABlock x_caBlock)
	{
		this->x_caBlock.Assign(x_caBlock);
	}
	void MathTestRaw::Test()
	{
		x_caBlock->Send(new StringRaw("Doing MathTest"));
		DoMathTest();
	}
	void MathTestRaw::DoMathTest()
	{
		CxAssert(MathRaw::Abs(-1),1);
		CxAssert(MathRaw::Abs(1),1);
		CxAssert(MathRaw::Abs(-1) == 1);
		CxAssert(MathRaw::Abs(1) == 1);
		CxAssert(MathRaw::Abs(-1) == 1);
		CxAssert(MathRaw::Abs(1) == 1);
		CxAssert(MathRaw::Acos(0.5),Math::PI / 3);
		CxAssert(MathRaw::Asin(0.5),0.523598775598299);
		CxAssert(MathRaw::Atan(0.5),0.463647609000806);
		CxAssert(MathRaw::Atan2(2,1),1.10714871779409);
		CxAssert(MathRaw::Ceiling(1.1),2);
		CxAssert(MathRaw::Cos(0.5),0.877582561890373);
		CxAssert(MathRaw::Cosh(0.5),1.12762596520638);
		CxAssert(MathRaw::Exp(0.5),1.64872127070013);
		CxAssert(MathRaw::Floor(1.1),1);
		CxAssert(MathRaw::Log(0.5),-0.693147180559945);
		CxAssert(MathRaw::Log(0.4,0.5),1.32192809488736);
		CxAssert(MathRaw::Log10(0.5),-0.301029995663981);
		CxAssert(MathRaw::Max(1.1,1.2),1.2);
		CxAssert(MathRaw::Max(1,2) == 2);
		CxAssert(MathRaw::Max(1,2) == 2);
		CxAssert(MathRaw::Max(1,2) == 2);
		CxAssert(MathRaw::Min(1.1,1.2),1.1);
		CxAssert(MathRaw::Min(1,2) == 1);
		CxAssert(MathRaw::Min(1,2) == 1);
		CxAssert(MathRaw::Min(1,2) == 1);
		CxAssert(MathRaw::Pow(0.4,0.5),0.632455532033676);
		CxAssert(MathRaw::Round(4.5),4);
		CxAssert(MathRaw::Round(4.6),5);
		CxAssert(MathRaw::Round(Double::NaN),Double::NaN);
		CxAssert(MathRaw::Round(3.45,1),3.4);
		CxAssert(MathRaw::Round(3.46,1),3.5);
		CxAssert(MathRaw::Round(-0.123456789,1),-0.1);
		CxAssert(MathRaw::Round(Double::NaN,1),Double::NaN);
		CxAssert(MathRaw::Round(1.5),2);
		CxAssert(MathRaw::Round(2.5),2);
		CxAssert(MathRaw::Round(-1.5),-2);
		CxAssert(MathRaw::Round(-2.5),-2);
		CxAssert(MathRaw::Round(1.79769313486232E+308),1.79769313486232E+308);
		CxAssert(MathRaw::Round(-1.79769313486232E+308),-1.79769313486232E+308);
		CxAssert(MathRaw::Sign(2) == 1);
		CxAssert(MathRaw::Sign(0) == 0);
		CxAssert(MathRaw::Sign(-2) == -1);
		CxAssert(MathRaw::Sign(2) == 1);
		CxAssert(MathRaw::Sign(0) == 0);
		CxAssert(MathRaw::Sign(-2) == -1);
		CxAssert(MathRaw::Sign(2) == 1);
		CxAssert(MathRaw::Sign(0) == 0);
		CxAssert(MathRaw::Sign(-2) == -1);
		CxAssert(MathRaw::Sign(Double::Epsilon) == 1);
		CxAssert(MathRaw::Sin(0.5),0.479425538604203);
		CxAssert(MathRaw::Sinh(0.5),0.521095305493747);
		CxAssert(MathRaw::Sqrt(25),5);
		CxAssert(MathRaw::Tan(0.52),0.572561830251668);
		CxAssert(MathRaw::Tanh(0.52),0.477700012168498);
		Double x_num = Math::E;
		CxAssert(Math::E == x_num);
		Double x_num2 = Math::PI;
		CxAssert(Math::PI == x_num2);
		CxAssert(MathRaw::Truncate(x_num2) == 3);
	}
	void MathTestRaw::DoubleCompare(Double x_n1,Double x_n2,Double x_resolution)
	{
		if ( MathRaw::Abs(x_n1 - x_n2) > x_resolution )
		{
			x_caBlock->TestFailed(new StringRaw("BaseTest TestFailed"));
		}
	}
	void MathTestRaw::CxAssert(Double x_x,Double x_y)
	{
		DoubleCompare(x_x,x_y,1E-05);
	}
	void MathTestRaw::CxAssert(Boolean x_x)
	{
		if ( !x_x )
		{
			x_caBlock->TestFailed(new StringRaw("BaseTest TestFailed"));
		}
	}

	SByteTestRaw::SByteTestRaw(CABlock x_caBlock)
	{
		this->x_caBlock.Assign(x_caBlock);
	}
	void SByteTestRaw::Test()
	{
		x_caBlock->Send(new StringRaw("Doing SByteTest"));
		x_caBlock->Send(new StringRaw("\tDoing SByteMethodsTest"));
		SByteMethodsTest();
		x_caBlock->Send(new StringRaw("\tDoing SByteMathTest"));
		SByteMathTest();
		x_caBlock->Send(new StringRaw("\tDoing SByteOperators"));
		SByteOperators();
		x_caBlock->Send(new StringRaw("\tDoing SByteArrayTests"));
		SByteArrayTests();
		x_caBlock->Send(new StringRaw("\tDoing SByteMiscTests"));
		SByteMiscTests();
	}
	void SByteTestRaw::SByteMethodsTest()
	{
		SByte x_b = 5;
		CxAssert(((SByte)x_b).CompareTo(5) == 0);
		CxAssert(((SByte)x_b).CompareTo(( Object ) ( SByte ) 5) == 0);
		CxAssert(((SByte)x_b).Equals(5));
		CxAssert(((SByte)x_b).Equals(( Object ) ( SByte ) 5));
		CxAssert(SByteRaw::Parse(new StringRaw("-55")) == -55);
		CxAssert(new StringRaw("-75") == ( -75 )->ToString());
		String x_text = ((SByte)127).ToString();
		CxAssert(x_text == new StringRaw("127"));
		CxAssert(SByteRaw::Parse(x_text) == 127);
		String x_text2 = ((SByte)-128).ToString();
		CxAssert(x_text2 == new StringRaw("-128"));
		CxAssert(SByteRaw::Parse(x_text2) == -128);
		Int64 x_num = 9223372036854775807;
		x_b = ( SByte ) x_num;
		CxAssert(x_b == -1);
		Object x_obj = ( SByte ) 5;
		CxAssert(x_obj->Equals(( SByte ) 5));
		CxAssert(x_obj->ToString() == new StringRaw("5"));
	}
	void SByteTestRaw::SByteMathTest()
	{
		SByte x_b = 6;
		SByte x_b2 = 12;
		CxAssert(x_b + x_b2 == 18);
		CxAssert(x_b - x_b2 == -6);
		CxAssert(x_b * x_b2 == 72);
		CxAssert(x_b2 / x_b == 2);
		CxAssert(x_b >> 2 == 1);
		CxAssert(x_b << 1 == 12);
		Int32 x_num = 11;
		CxAssert(x_num % 5 == 1);
		x_num = 8;
		CxAssert(( x_num | 1 ) == 9);
		CxAssert(( x_num & 1 ) == 0);
		CxAssert(++x_num == 9);
		CxAssert(--x_num == 8);
		CxAssert(( x_num *= 2 ) == 16);
		CxAssert(( x_num /= 2 ) == 8);
		CxAssert(( x_num %= 2 ) == 0);
		CxAssert(( x_num |= 4 ) == 4);
		CxAssert(( x_num &= 4 ) == 4);
		CxAssert(-x_b == -6);
		CxAssert(x_b == 6);
		x_num = 0;
		CxAssert(~x_num == -1);
		CxAssert(++x_num == 1);
		CxAssert(--x_num == 0);
		CxAssert(x_b < x_b2);
		CxAssert(x_b <= x_b2);
		CxAssert(x_b2 > x_b);
		CxAssert(x_b2 >= x_b);
	}
	void SByteTestRaw::SByteOperators()
	{
		SByte x_b = 66;
		Char x_c = '';
		Byte x_b2 = 1;
		SByte x_b3 = 1;
		SByte x_b4 = 1;
		Int32 x_num = 1;
		Int64 x_num2 = 1;
		UInt16 x_num3 = 1;
		UInt32 x_num4 = 1;
		Float x_num5 = 1;
		Double x_num6 = 1;
		CxAssert(x_b == 66);
		CxAssert(x_b + x_c == 67);
		CxAssert(x_b + x_b2 == 67);
		CxAssert(x_b + x_b3 == 67);
		CxAssert(x_b + x_b4 == 67);
		CxAssert(x_b + x_num == 67);
		CxAssert(x_b + x_num2 == 67);
		CxAssert(x_b + x_num3 == 67);
		CxAssert(x_b + x_num4 == 67);
		CxAssert(( Float ) x_b + x_num5 == 67);
		CxAssert(( Double ) x_b + x_num6 == 67);
		CxAssert(x_b - x_c == 65);
		CxAssert(x_b - x_b2 == 65);
		CxAssert(x_b - x_b3 == 65);
		CxAssert(x_b - x_b4 == 65);
		CxAssert(x_b - x_num == 65);
		CxAssert(x_b - x_num2 == 65);
		CxAssert(x_b - x_num3 == 65);
		CxAssert(x_b - x_num4 == 65);
		CxAssert(( Float ) x_b - x_num5 == 65);
		CxAssert(( Double ) x_b - x_num6 == 65);
		CxAssert(x_b * x_c == 66);
		CxAssert(x_b * x_b2 == 66);
		CxAssert(x_b * x_b3 == 66);
		CxAssert(x_b * x_b4 == 66);
		CxAssert(x_b * x_num == 66);
		CxAssert(x_b * x_num2 == 66);
		CxAssert(x_b * x_num3 == 66);
		CxAssert(x_b * x_num4 == 66);
		CxAssert(( Float ) x_b * x_num5 == 66);
		CxAssert(( Double ) x_b * x_num6 == 66);
		CxAssert(( Int32 ) x_b / ( Int32 ) x_c == 66);
		CxAssert(( Int32 ) x_b / ( Int32 ) x_b2 == 66);
		CxAssert(x_b / x_b3 == 66);
		CxAssert(x_b / x_b4 == 66);
		CxAssert(x_b / x_num == 66);
		CxAssert(x_b / x_num2 == 66);
		CxAssert(( Int32 ) x_b / ( Int32 ) x_num3 == 66);
		CxAssert(( Int64 ) x_b / ( Int64 ) x_num4 == 66);
		CxAssert(( Float ) x_b / x_num5 == 66);
		CxAssert(( Double ) x_b / x_num6 == 66);
		CxAssert(( Int32 ) x_b % ( Int32 ) x_c == 0);
		CxAssert(( Int32 ) x_b % ( Int32 ) x_b2 == 0);
		CxAssert(x_b % x_b3 == 0);
		CxAssert(x_b % x_b4 == 0);
		CxAssert(x_b % x_num == 0);
		CxAssert(x_b % x_num2 == 0);
		CxAssert(( Int32 ) x_b % ( Int32 ) x_num3 == 0);
		CxAssert(( Int64 ) x_b % ( Int64 ) x_num4 == 0);
		CxAssert(( Float ) x_b % x_num5 == 0);
		CxAssert(( Double ) x_b % x_num6 == 0);
		CxAssert(( x_b & x_c ) == 0);
		CxAssert(( x_b & x_b2 ) == 0);
		CxAssert(( x_b & x_b3 ) == 0);
		CxAssert(( x_b & x_b4 ) == 0);
		CxAssert(( x_b & x_num ) == 0);
		CxAssert(( x_b & x_num2 ) == 0);
		CxAssert(( x_b & x_num3 ) == 0);
		CxAssert(( x_b & x_num4 ) == 0);
		CxAssert(( x_b | x_c ) == 67);
		CxAssert(( x_b | x_b2 ) == 67);
		CxAssert(( x_b | x_b3 ) == 67);
		CxAssert(( x_b | x_b4 ) == 67);
		CxAssert(( x_b | x_num ) == 67);
		CxAssert(( x_b | x_num2 ) == 67);
		CxAssert(( x_b | x_num3 ) == 67);
		CxAssert(( x_b | x_num4 ) == 67);
		CxAssert(( x_b ^ x_c ) == 67);
		CxAssert(( x_b ^ x_b2 ) == 67);
		CxAssert(( x_b ^ x_b3 ) == 67);
		CxAssert(( x_b ^ x_b4 ) == 67);
		CxAssert(( x_b ^ x_num ) == 67);
		CxAssert(( x_b ^ x_num2 ) == 67);
		CxAssert(( x_b ^ x_num3 ) == 67);
		CxAssert(( x_b ^ x_num4 ) == 67);
		CxAssert(~x_b == -67);
		CxAssert(x_c < x_b);
		CxAssert(x_b2 < x_b);
		CxAssert(x_b3 < x_b);
		CxAssert(x_b4 < x_b);
		CxAssert(x_num < x_b);
		CxAssert(x_num2 < x_b);
		CxAssert(x_num3 < x_b);
		CxAssert(x_num4 < x_b);
		CxAssert(x_num5 < ( Float ) x_b);
		CxAssert(x_num6 < ( Double ) x_b);
		CxAssert(x_c > x_b,false);
		CxAssert(x_b2 > x_b,false);
		CxAssert(x_b3 > x_b,false);
		CxAssert(x_b4 > x_b,false);
		CxAssert(x_num > x_b,false);
		CxAssert(x_num2 > x_b,false);
		CxAssert(x_num3 > x_b,false);
		CxAssert(x_num4 > x_b,false);
		CxAssert(x_num5 > ( Float ) x_b,false);
		CxAssert(x_num6 > ( Double ) x_b,false);
		CxAssert(( x_b = ( SByte ) ( x_b + 1 ) ) == 67);
		CxAssert(( x_b = ( SByte ) ( x_b - 1 ) ) == 66);
		CxAssert(x_b++ == 66);
		CxAssert(x_b-- == 67);
		CxAssert(x_b << 1 == 132);
		CxAssert(x_b >> 1 == 33);
		CxAssert(x_c == x_b,false);
		CxAssert(x_b2 == x_b,false);
		CxAssert(x_b3 == x_b,false);
		CxAssert(x_b4 == x_b,false);
		CxAssert(x_num == x_b,false);
		CxAssert(x_num2 == x_b,false);
		CxAssert(x_num3 == x_b,false);
		CxAssert(x_num4 == x_b,false);
		CxAssert(x_num5 == ( Float ) x_b,false);
		CxAssert(x_num6 == ( Double ) x_b,false);
		CxAssert(x_c != x_b);
		CxAssert(x_b2 != x_b);
		CxAssert(x_b3 != x_b);
		CxAssert(x_b4 != x_b);
		CxAssert(x_num != x_b);
		CxAssert(x_num2 != x_b);
		CxAssert(x_num3 != x_b);
		CxAssert(x_num4 != x_b);
		CxAssert(x_num5 != ( Float ) x_b);
		CxAssert(x_num6 != ( Double ) x_b);
		CxAssert(x_c <= x_b);
		CxAssert(x_b2 <= x_b);
		CxAssert(x_b3 <= x_b);
		CxAssert(x_b4 <= x_b);
		CxAssert(x_num <= x_b);
		CxAssert(x_num2 <= x_b);
		CxAssert(x_num3 <= x_b);
		CxAssert(x_num4 <= x_b);
		CxAssert(x_num5 <= ( Float ) x_b);
		CxAssert(x_num6 <= ( Double ) x_b);
		CxAssert(x_c >= x_b,false);
		CxAssert(x_b2 >= x_b,false);
		CxAssert(x_b3 >= x_b,false);
		CxAssert(x_b4 >= x_b,false);
		CxAssert(x_num >= x_b,false);
		CxAssert(x_num2 >= x_b,false);
		CxAssert(x_num3 >= x_b,false);
		CxAssert(x_num4 >= x_b,false);
		CxAssert(x_num5 >= ( Float ) x_b,false);
		CxAssert(x_num6 >= ( Double ) x_b,false);
		CxAssert(( x_b = ( SByte ) ( x_b + ( SByte ) x_c ) ) == 67);
		CxAssert(( x_b = ( SByte ) ( x_b - ( SByte ) x_c ) ) == 66);
		CxAssert(( x_b = ( SByte ) ( x_b + ( SByte ) x_num ) ) == 67);
		CxAssert(( x_b = ( SByte ) ( x_b - ( SByte ) x_num ) ) == 66);
		CxAssert(( x_b = ( SByte ) ( x_b * ( SByte ) x_c ) ) == 66);
		CxAssert(( x_b = ( SByte ) ( x_b / ( SByte ) x_c ) ) == 66);
		CxAssert(( x_b = ( SByte ) ( x_b * ( SByte ) x_num ) ) == 66);
		CxAssert(( x_b = ( SByte ) ( x_b / ( SByte ) x_num ) ) == 66);
		CxAssert(( x_b = ( SByte ) ( x_b % ( SByte ) x_c ) ) == 0);
		x_b = 66;
		CxAssert(( x_b = ( SByte ) ( x_b % ( SByte ) x_num ) ) == 0);
		x_b = 66;
		CxAssert(( x_b = ( SByte ) ( x_b & ( SByte ) x_c ) ) == 0);
		x_b = 66;
		CxAssert(( x_b = ( SByte ) ( x_b & ( SByte ) x_num ) ) == 0);
		x_b = 66;
		CxAssert(( x_b = ( SByte ) ( x_b | ( SByte ) x_c ) ) == 67);
		x_b = 66;
		CxAssert(( x_b = ( SByte ) ( x_b | ( SByte ) x_num ) ) == 67);
		x_b = 66;
		CxAssert(( x_b = ( SByte ) ( x_b ^ ( SByte ) x_c ) ) == 67);
		x_b = 66;
		CxAssert(( x_b = ( SByte ) ( x_b ^ ( SByte ) x_num ) ) == 67);
		x_b = 66;
		CxAssert(( x_b = ( SByte ) ( x_b << ( Int32 ) x_b2 ) ) == -124);
		x_b = 66;
		CxAssert(( x_b = ( SByte ) ( x_b << ( Int32 ) x_b4 ) ) == -124);
		x_b = 66;
		CxAssert(( x_b = ( SByte ) ( x_b << ( Int32 ) x_c ) ) == -124);
		x_b = 66;
		CxAssert(( x_b = ( SByte ) ( x_b << x_num ) ) == -124);
		x_b = 66;
		CxAssert(( x_b = ( SByte ) ( x_b >> ( Int32 ) x_c ) ) == 33);
		x_b = 66;
		CxAssert(( x_b = ( SByte ) ( x_b >> x_num ) ) == 33);
		x_b = 66;
		SByte x_b5 = 0;
		CxAssert(x_b5 == 0);
		CxAssert(x_b5 == 0);
		CxAssert(x_num <= 2);
		CxAssert(x_num >= -2);
	}
	void SByteTestRaw::SByteArrayTests()
	{
		static SByte SByteArrayTestsArray0[5] = {1,2,3,4,5};
		static SByte SByteArrayTestsArray1[4] = {1,2,3,4};
		static SByte SByteArrayTestsArray2[2][4] = {{1,2,3,4},{4,5,6,7}};
		static SByte SByteArrayTestsArray3[2][2][4] = {{{1,2,3,4},{5,6,7,8}},{{9,10,11,12},{13,14,15,16}}};
		PointerType<ArrayRaw<SByte>> x_array = (new ArrayRaw<SByte>(5))->Initialize((SByte*) SByteArrayTestsArray0);
		CxAssert(x_array->get_Length() == 5);
		CxAssert((*x_array->Address(3)) == 4);
		PointerType<ArrayRaw<SByte>> x_array2 = (new ArrayRaw<SByte>(4))->Initialize((SByte*) SByteArrayTestsArray1);
		CxAssert((*x_array2->Address(1)) == 2);
		PointerType<ArrayRaw<SByte>> x_array3 = (new ArrayRaw<SByte>(2,4))->Initialize((SByte*) SByteArrayTestsArray2);
		CxAssert((*x_array3->Address(0,2)) == 3);
		PointerType<ArrayRaw<SByte>> x_array4 = (new ArrayRaw<SByte>(2,2,4))->Initialize((SByte*) SByteArrayTestsArray3);
		CxAssert((*x_array4->Address(0,0,3)) == 4);
		(*x_array4->Address(0,0,3)) = 6;
		CxAssert((*x_array4->Address(0,0,3)) == 6);
		x_array4->SetValue(( SByte ) 4,0,0,3);
		CxAssert((*x_array4->Address(0,0,3)) == 4);
	}
	void SByteTestRaw::SByteMiscTests()
	{
		SByte x_b = -1;
		SByte x_val = 1;
		CxAssert(MathRaw::Abs(x_b) == 1);
		CxAssert(MathRaw::Max(x_b,x_val) == 1);
		CxAssert(MathRaw::Min(x_b,x_val) == -1);
		CxAssert(MathRaw::Sign(x_b) < 0);
		PointerType<StringBuilderRaw> x_stringBuilder = new StringBuilderRaw();
		x_stringBuilder->Append(x_b);
		CxAssert(x_stringBuilder->ToString() == new StringRaw("-1"));
		x_stringBuilder->Insert(2,x_b);
		CxAssert(x_stringBuilder->ToString() == new StringRaw("-1-1"));
	}
	void SByteTestRaw::CxAssert(Boolean x_x)
	{
		if ( !x_x )
		{
			x_caBlock->TestFailed(new StringRaw("SByte TestFailed"));
		}
	}
	void SByteTestRaw::CxAssert(Boolean x_x,Boolean x_y)
	{
		if ( x_x != x_y )
		{
			x_caBlock->TestFailed(new StringRaw("SByte TestFailed"));
		}
	}

	SingleTestRaw::SingleTestRaw(CABlock x_caBlock)
	{
		this->x_caBlock.Assign(x_caBlock);
	}
	void SingleTestRaw::Test()
	{
		x_caBlock->Send(new StringRaw("Doing SingleTest"));
		x_caBlock->Send(new StringRaw("\tDoing DoSingleMethodsTest"));
		DoSingleMethodsTest();
		x_caBlock->Send(new StringRaw("\tDoing DoSingleMath"));
		DoSingleMath();
		x_caBlock->Send(new StringRaw("\tDoing SingleOperators"));
		SingleOperators();
		x_caBlock->Send(new StringRaw("\tDoing SingleNanTest"));
		SingleNanTest();
		x_caBlock->Send(new StringRaw("\tDoing SingleArrayTest"));
		SingleArrayTest();
		x_caBlock->Send(new StringRaw("\tDoing SingleMiscTests"));
		SingleMiscTests();
	}
	void SingleTestRaw::DoSingleMethodsTest()
	{
		Float x_num = 3.159;
		CxAssert(((Single)x_num).CompareTo(3.159) == 0);
		CxAssert(((Single)x_num).CompareTo(( Object ) 3.159) == 0);
		CxAssert(((Single)x_num).Equals(3.159));
		CxAssert(SingleRaw::Parse(new StringRaw("3.159")),3.15899991989136);
		CxAssert(((Single)x_num).ToString() == new StringRaw("3.159"));
		CxAssert(SingleRaw::Parse(((Single)x_num).ToString()),x_num);
		x_num = 1E+07;
		CxAssert(x_num > 1E+07);
		x_num = -1E+07;
		CxAssert(x_num <= -1E+07);
		x_num = 10000;
		CxAssert(( Int64 ) x_num == 10000);
		CxAssert(( Int32 ) x_num == 10000);
		CxAssert(( UInt32 ) x_num == 10000);
		Object x_obj = x_num;
		CxAssert(( Double ) ( Float ) x_obj == 10000);
		x_num = Float::Epsilon;
		CxAssert(x_num == Float::Epsilon);
		x_num = 3.402823E+38;
		CxAssert(x_num == 3.402823E+38);
		x_num = -3.402823E+38;
		CxAssert(x_num == -3.402823E+38);
		x_obj.Assign(5);
		CxAssert(x_obj->Equals(5));
		CxAssert(x_obj->ToString() == new StringRaw("5"));
	}
	void SingleTestRaw::DoSingleMath()
	{
		Float x_num = 355;
		Float x_num2 = 113;
		Float x_num3 = x_num / x_num2;
		CxAssert(x_num3,3.14159);
		CxAssert(x_num3 * x_num2,355);
		CxAssert(x_num + x_num2,468);
		CxAssert(x_num - x_num2,242);
		x_num = 1;
		x_num2 = x_num + Float::Epsilon;
		CxAssert(( Double ) x_num2 == 1);
	}
	void SingleTestRaw::SingleOperators()
	{
		Float x_num = 66;
		Char x_c = '';
		Int32 x_num2 = 1;
		UInt32 x_num3 = 1;
		Int64 x_num4 = 1;
		Double x_num5 = 1;
		CxAssert(x_num == 66);
		CxAssert(x_num + ( Float ) ( Int32 ) x_c == 67);
		CxAssert(x_num + ( Float ) x_num2 == 67);
		CxAssert(x_num + ( Float ) x_num3 == 67);
		CxAssert(x_num + ( Float ) x_num4 == 67);
		CxAssert(( Double ) x_num + x_num5 == 67);
		CxAssert(x_num - ( Float ) ( Int32 ) x_c == 65);
		CxAssert(x_num - ( Float ) x_num2 == 65);
		CxAssert(x_num - ( Float ) x_num3 == 65);
		CxAssert(x_num - ( Float ) x_num4 == 65);
		CxAssert(( Double ) x_num - x_num5 == 65);
		CxAssert(x_num * ( Float ) ( Int32 ) x_c == 66);
		CxAssert(x_num * ( Float ) x_num2 == 66);
		CxAssert(x_num * ( Float ) x_num3 == 66);
		CxAssert(x_num * ( Float ) x_num4 == 66);
		CxAssert(( Double ) x_num * x_num5 == 66);
		CxAssert(x_num / ( Float ) ( Int32 ) x_c == 66);
		CxAssert(x_num / ( Float ) x_num2 == 66);
		CxAssert(x_num / ( Float ) x_num3 == 66);
		CxAssert(x_num / ( Float ) x_num4 == 66);
		CxAssert(( Double ) x_num / x_num5 == 66);
		CxAssert(x_num % ( Float ) ( Int32 ) x_c == 0);
		CxAssert(x_num % ( Float ) x_num2 == 0);
		CxAssert(x_num % ( Float ) x_num3 == 0);
		CxAssert(x_num % ( Float ) x_num4 == 0);
		CxAssert(( Double ) x_num % x_num5 == 0);
		CxAssert(( Float ) ( Int32 ) x_c < x_num);
		CxAssert(( Float ) x_num2 < x_num);
		CxAssert(( Float ) x_num3 < x_num);
		CxAssert(( Float ) x_num4 < x_num);
		CxAssert(x_num5 < ( Double ) x_num);
		CxAssert(( Float ) ( Int32 ) x_c > x_num,false);
		CxAssert(( Float ) x_num2 > x_num,false);
		CxAssert(( Float ) x_num3 > x_num,false);
		CxAssert(( Float ) x_num4 > x_num,false);
		CxAssert(x_num5 > ( Double ) x_num,false);
		CxAssert(( x_num += 1 ) == 67);
		CxAssert(( x_num -= 1 ) == 66);
		CxAssert(x_num++ == 66);
		CxAssert(x_num-- == 67);
		CxAssert(( Float ) ( Int32 ) x_c == x_num,false);
		CxAssert(( Float ) x_num2 == x_num,false);
		CxAssert(( Float ) x_num3 == x_num,false);
		CxAssert(( Float ) x_num4 == x_num,false);
		CxAssert(x_num5 == ( Double ) x_num,false);
		CxAssert(( Float ) ( Int32 ) x_c != x_num);
		CxAssert(( Float ) x_num2 != x_num);
		CxAssert(( Float ) x_num3 != x_num);
		CxAssert(( Float ) x_num4 != x_num);
		CxAssert(x_num5 != ( Double ) x_num);
		CxAssert(( Float ) ( Int32 ) x_c <= x_num);
		CxAssert(( Float ) x_num2 <= x_num);
		CxAssert(( Float ) x_num3 <= x_num);
		CxAssert(( Float ) x_num4 <= x_num);
		CxAssert(x_num5 <= ( Double ) x_num);
		CxAssert(( Float ) ( Int32 ) x_c >= x_num,false);
		CxAssert(( Float ) x_num2 >= x_num,false);
		CxAssert(( Float ) x_num3 >= x_num,false);
		CxAssert(( Float ) x_num4 >= x_num,false);
		CxAssert(x_num5 >= ( Double ) x_num,false);
		CxAssert(( x_num += ( Float ) ( Int32 ) x_c ) == 67);
		CxAssert(( x_num -= ( Float ) ( Int32 ) x_c ) == 66);
		CxAssert(( x_num += ( Float ) x_num2 ) == 67);
		CxAssert(( x_num -= ( Float ) x_num2 ) == 66);
		CxAssert(( x_num += ( Float ) x_num3 ) == 67);
		CxAssert(( x_num -= ( Float ) x_num3 ) == 66);
		CxAssert(( x_num += ( Float ) x_num4 ) == 67);
		CxAssert(( x_num -= ( Float ) x_num4 ) == 66);
		CxAssert(( x_num *= ( Float ) ( Int32 ) x_c ) == 66);
		CxAssert(( x_num /= ( Float ) ( Int32 ) x_c ) == 66);
		CxAssert(( x_num *= ( Float ) x_num2 ) == 66);
		CxAssert(( x_num /= ( Float ) x_num2 ) == 66);
		CxAssert(( x_num *= ( Float ) x_num3 ) == 66);
		CxAssert(( x_num /= ( Float ) x_num3 ) == 66);
		CxAssert(( x_num *= ( Float ) x_num4 ) == 66);
		CxAssert(( x_num /= ( Float ) x_num4 ) == 66);
		CxAssert(( x_num %= ( Float ) ( Int32 ) x_c ) == 0);
		x_num = 66;
		CxAssert(( x_num %= ( Float ) x_num2 ) == 0);
		x_num = 5;
		CxAssert(( Double ) x_num % 2.2,0.6);
	}
	void SingleTestRaw::SingleNanTest()
	{
		Float x_num = Float::NaN;
		Float x_num2 = 1;
		CxAssert(SingleRaw::IsNaN(x_num));
		CxAssert(SingleRaw::IsInfinity(Float::PositiveInfinity));
		CxAssert(SingleRaw::IsNegativeInfinity(Float::NegativeInfinity));
		CxAssert(SingleRaw::IsPositiveInfinity(Float::PositiveInfinity));
		CxAssert(SingleRaw::IsNaN(x_num * x_num2));
		CxAssert(SingleRaw::IsNaN(x_num / x_num2));
		CxAssert(SingleRaw::IsNaN(x_num + x_num2));
		CxAssert(SingleRaw::IsNaN(x_num - x_num2));
		CxAssert(SingleRaw::IsNaN(x_num % x_num2));
		CxAssert(x_num < x_num2,false);
		CxAssert(x_num > x_num2,false);
		CxAssert(x_num <= x_num2,false);
		CxAssert(x_num >= x_num2,false);
		CxAssert(x_num == x_num2,false);
		CxAssert(x_num == x_num,false);
		CxAssert(x_num2 < x_num,false);
		CxAssert(x_num2 > x_num,false);
		CxAssert(x_num2 <= x_num,false);
		CxAssert(x_num2 >= x_num,false);
		CxAssert(x_num != x_num2);
		CxAssert(x_num != x_num);
		x_num = Float::NaN;
		x_num2 = Float::NaN;
		if ( x_num == x_num2 )
		{
			SingleTestFailed();
		}
		else
		{
			CxAssert(true);
		}
		if ( x_num == x_num )
		{
			SingleTestFailed();
		}
		else
		{
			CxAssert(true);
		}
		if ( x_num != x_num2 )
		{
			CxAssert(true);
		}
		else
		{
			SingleTestFailed();
		}
		if ( x_num != x_num )
		{
			CxAssert(true);
		}
		else
		{
			SingleTestFailed();
		}
		if ( x_num > x_num2 )
		{
			SingleTestFailed();
		}
		else
		{
			CxAssert(true);
		}
		if ( x_num >= x_num2 )
		{
			SingleTestFailed();
		}
		else
		{
			CxAssert(true);
		}
		if ( x_num < x_num2 )
		{
			SingleTestFailed();
		}
		else
		{
			CxAssert(true);
		}
		if ( x_num <= x_num2 )
		{
			SingleTestFailed();
		}
		else
		{
			CxAssert(true);
		}
		if ( x_num == 0 )
		{
			SingleTestFailed();
		}
		else
		{
			CxAssert(true);
		}
		CxAssert(((Single)Float::NaN).Equals(Float::NaN));
	}
	void SingleTestRaw::SingleArrayTest()
	{
		static Float SingleArrayTestArray0[4] = {1,2,3,4};
		static Float SingleArrayTestArray1[2][4] = {{1,2,3,4},{4,5,6,7}};
		static Float SingleArrayTestArray2[2][2][4] = {{{1,2,3,4},{5,6,7,8}},{{9,10,11,12},{13,14,15,16}}};
		PointerType<ArrayRaw<Single>> x_array = (new ArrayRaw<Float>(4))->Initialize((Float*) SingleArrayTestArray0);
		CxAssert((*x_array->Address(1)) == 2);
		PointerType<ArrayRaw<Single>> x_array2 = (new ArrayRaw<Float>(2,4))->Initialize((Float*) SingleArrayTestArray1);
		CxAssert((*x_array2->Address(0,2)) == 3);
		PointerType<ArrayRaw<Single>> x_array3 = (new ArrayRaw<Float>(2,2,4))->Initialize((Float*) SingleArrayTestArray2);
		CxAssert((*x_array3->Address(0,0,3)) == 4);
		(*x_array3->Address(0,0,3)) = 22;
		CxAssert((*x_array3->Address(0,0,3)) == 22);
		(*x_array2->Address(0,2)) = Float::NaN;
		CxAssert(SingleRaw::IsNaN((*x_array2->Address(0,2))));
		x_array3->SetValue(4,0,0,3);
		CxAssert((*x_array3->Address(0,0,3)) == 4);
	}
	void SingleTestRaw::SingleMiscTests()
	{
		Float x_num = -1;
		Float x_val = 1;
		CxAssert(MathRaw::Abs(x_num) == 1);
		CxAssert(MathRaw::Max(x_num,x_val) == 1);
		CxAssert(MathRaw::Min(x_num,x_val) == -1);
		CxAssert(MathRaw::Sign(x_num) < 0);
		PointerType<StringBuilderRaw> x_stringBuilder = new StringBuilderRaw();
		x_stringBuilder->Append(x_num);
		CxAssert(x_stringBuilder->ToString() == new StringRaw("-1"));
		x_stringBuilder->Insert(2,x_num);
		CxAssert(x_stringBuilder->ToString() == new StringRaw("-1-1"));
	}
	void SingleTestRaw::SingleCompare(Double x_n1,Double x_n2,Double x_resolution)
	{
		Double x_num = MathRaw::Abs(x_n1 - x_n2);
		if ( x_num > x_resolution )
		{
			SingleTestFailed();
		}
	}
	void SingleTestRaw::CxAssert(Double x_x,Double x_y)
	{
		SingleCompare(x_x,x_y,1E-05);
	}
	void SingleTestRaw::CxAssert(Boolean x_x)
	{
		if ( !x_x )
		{
			SingleTestFailed();
		}
	}
	void SingleTestRaw::CxAssert(Boolean x_x,Boolean x_y)
	{
		if ( x_x != x_y )
		{
			SingleTestFailed();
		}
	}
	void SingleTestRaw::SingleTestFailed()
	{
		x_caBlock->TestFailed(new StringRaw("Single TestFailed"));
	}

	StringBuilderTestRaw::StringBuilderTestRaw(CABlock x_caBlock)
	{
		x_sb = new StringBuilderRaw();
		this->x_caBlock.Assign(x_caBlock);
	}
	void StringBuilderTestRaw::Test()
	{
		x_caBlock->Send(new StringRaw("Doing StringBuilderTest"));
		x_caBlock->Send(new StringRaw("\tDoing DoSBConstructTest"));
		DoSBConstructTest();
		x_caBlock->Send(new StringRaw("\tDoing DoSBPropertyTest"));
		DoSBPropertyTest();
		x_caBlock->Send(new StringRaw("\tDoing DoSBAppendTest"));
		DoSBAppendTest();
		x_caBlock->Send(new StringRaw("\tDoing DoSBMiscTest"));
		DoSBMiscTest();
		x_caBlock->Send(new StringRaw("\tDoing DoSBInsertTest"));
		DoSBInsertTest();
		x_caBlock->Send(new StringRaw("\tDoing DoSBReplaceTest"));
		DoSBReplaceTest();
	}
	void StringBuilderTestRaw::DoSBConstructTest()
	{
		static Char DoSBConstructTestArray0[12] = {'A','B','','','	','','','','
','"',''','Â'};
		CxAssert(x_sb->get_Length() == 0);
		x_sb.Assign(new StringBuilderRaw(100));
		CxAssert(x_sb->get_Capacity() == 100);
		x_sb.Assign(new StringBuilderRaw(new StringRaw("Test")));
		CxAssert(x_sb->ToString() == new StringRaw("Test"));
		x_sb.Assign(new StringBuilderRaw(20,25));
		CxAssert(x_sb->get_Capacity() == 20 && x_sb->get_MaxCapacity() == 25);
		x_sb.Assign(new StringBuilderRaw(new StringRaw("Test"),20));
		CxAssert(x_sb->ToString() == new StringRaw("Test") && x_sb->get_Capacity() == 20);
		x_sb.Assign(new StringBuilderRaw(new StringRaw("test1234"),1,4,20));
		CxAssert(x_sb->ToString() == new StringRaw("est1") && x_sb->get_Capacity() == 20);
		String x_a = new StringBuilderRaw(new StringRaw("Test"))->ToString();
		CxAssert(x_a == new StringRaw("Test"));
		String x_b = new StringRaw("AB\a\b\t\r\v\f\n\"'\u00c2");
		PointerType<ArrayRaw<Char>> x_value = (new ArrayRaw<Char>(12))->Initialize((Char*) DoSBConstructTestArray0);
		x_sb.Assign(new StringBuilderRaw());
		x_sb->Append(x_value);
		String x_text = x_sb->ToString();
		CxAssert(x_sb->ToString() == x_b);
	}
	void StringBuilderTestRaw::DoSBPropertyTest()
	{
		x_sb.Assign(new StringBuilderRaw(new StringRaw("Testing123"),0,10,20));
		CxAssert(x_sb->get_Capacity() == 20 && x_sb->get_MaxCapacity() == 2147483647);
		CxAssert((*x_sb->Address(7)) == '1');
		CxAssert(x_sb->get_Length() == 10);
		x_sb->set_Length(7);
		CxAssert(x_sb->get_Length() == 7);
		x_sb->set_Capacity(22);
		CxAssert(x_sb->get_Capacity() == 22);
		(*x_sb->Address(0)) = 't';
		CxAssert(x_sb->ToString() == new StringRaw("testing"));
	}
	void StringBuilderTestRaw::DoSBAppendTest()
	{
		static Char DoSBAppendTestArray0[4] = {'0','1','2','3'};
		static Object DoSBAppendTestArray1[4] = {0,1,2,3};
		x_sb->set_Length(0);
		x_sb->Append(true);
		CxAssert(x_sb->ToString() == new StringRaw("True"));
		CxAssert(x_sb->Append('A')->Append() == new StringRaw("TrueA"));
		PointerType<ArrayRaw<Char>> x_value = (new ArrayRaw<Char>(4))->Initialize((Char*) DoSBAppendTestArray0);
		CxAssert(x_sb->Append(x_value)->Append() == new StringRaw("TrueA0123"));
		x_sb->set_Length(0);
		Double x_value2 = 3.14159;
		CxAssert(x_sb->Append(x_value2)->Append() == new StringRaw("3.14159"));
		x_sb->set_Length(0);
		Int32 x_value3 = 666;
		CxAssert(x_sb->Append(x_value3)->Append() == new StringRaw("666"));
		x_sb->set_Length(0);
		Int64 x_value4 = 666666666;
		CxAssert(x_sb->Append(x_value4)->Append() == new StringRaw("666666666"));
		x_sb->set_Length(0);
		Object x_obj = 1;
		CxAssert(x_sb->Append(x_obj)->Append() == new StringRaw("1"));
		x_sb->set_Length(0);
		CxAssert(x_sb->Append(new StringRaw("fred"))->Append() == new StringRaw("fred"));
		UInt32 x_value5 = 777;
		x_sb->set_Length(0);
		CxAssert(x_sb->Append(x_value5)->Append() == new StringRaw("777"));
		x_sb->set_Length(0);
		CxAssert(x_sb->Append('A',4)->Append() == new StringRaw("AAAA"));
		x_sb->set_Length(0);
		CxAssert(x_sb->Append(x_value,1,3)->Append() == new StringRaw("123"));
		x_sb->set_Length(0);
		CxAssert(x_sb->Append(new StringRaw("3210"),1,3)->Append() == new StringRaw("210"));
		x_sb->set_Length(0);
		CxAssert(x_sb->AppendFormat(new StringRaw("x={0}"),x_obj)->AppendFormat() == new StringRaw("x=1"));
		PointerType<ArrayRaw<Object>> x_array = (new ArrayRaw<Object>(4))->Initialize((Object*) DoSBAppendTestArray1);
		x_sb->set_Length(0);
		CxAssert(x_sb->AppendFormat(new StringRaw("y={0}{1}{2}{3}"),x_array)->AppendFormat() == new StringRaw("y=0123"));
		x_sb->set_Length(0);
		CxAssert(x_sb->AppendFormat(new StringRaw("y={0}{1}"),(*x_array->Address(0)),(*x_array->Address(1)))->AppendFormat() == new StringRaw("y=01"));
		x_sb->set_Length(0);
		CxAssert(x_sb->AppendFormat(new StringRaw("y={0}{1}{2}"),(*x_array->Address(0)),(*x_array->Address(1)),(*x_array->Address(2)))->AppendFormat() == new StringRaw("y=012"));
		x_sb->set_Length(0);
		CxAssert(x_sb->Append('A')->Append() == new StringRaw("A"));
		Object x_value6 = new StringRaw("Test string as Object");
		x_sb->set_Length(0);
		CxAssert(x_sb->Append(x_value6)->Append() == new StringRaw("Test string as Object"));
		PointerType<TestAbstractRaw> x_value7 = new TestAbstractRaw();
		x_sb->set_Length(0);
		CxAssert(x_sb->Append(x_value7)->Append() == new StringRaw("TestAbstract"));
	}
	void StringBuilderTestRaw::DoSBMiscTest()
	{
		x_sb->set_Length(0);
		x_sb->set_Capacity(10);
		x_sb->EnsureCapacity(30);
		CxAssert(x_sb->get_Capacity() >= 30);
		x_sb->Append(new StringRaw("Test"));
		PointerType<StringBuilderRaw> x_stringBuilder = new StringBuilderRaw(new StringRaw("Test"));
		x_stringBuilder->set_Capacity(10);
		x_stringBuilder->EnsureCapacity(30);
		CxAssert(x_sb->Equals(x_stringBuilder));
		x_sb->set_Length(0);
		x_sb->Append(new StringRaw("1234567890"));
		x_sb->Remove(1,4);
		CxAssert(x_sb->ToString() == new StringRaw("167890"));
		x_sb->set_Length(0);
		x_sb->Append(new StringRaw("1234567890"));
		CxAssert(x_sb->ToString(1,8) == new StringRaw("23456789"));
	}
	void StringBuilderTestRaw::DoSBInsertTest()
	{
		static Char DoSBInsertTestArray0[4] = {'0','1','2','3'};
		String x_value = new StringRaw("{}");
		x_sb->set_Length(0);
		x_sb->Append(x_value);
		x_sb->Insert(1,true);
		CxAssert(x_sb->ToString() == new StringRaw("{True}"));
		CxAssert(x_sb->Insert(5,'A')->Insert() == new StringRaw("{TrueA}"));
		PointerType<ArrayRaw<Char>> x_value2 = (new ArrayRaw<Char>(4))->Initialize((Char*) DoSBInsertTestArray0);
		CxAssert(x_sb->Insert(6,x_value2)->Insert() == new StringRaw("{TrueA0123}"));
		x_sb->set_Length(0);
		x_sb->Append(x_value);
		Double x_value3 = 3.14159;
		CxAssert(x_sb->Insert(1,x_value3)->Insert() == new StringRaw("{3.14159}"));
		x_sb->set_Length(0);
		x_sb->Append(x_value);
		Int32 x_value4 = 666;
		CxAssert(x_sb->Insert(1,x_value4)->Insert() == new StringRaw("{666}"));
		x_sb->set_Length(0);
		x_sb->Append(x_value);
		Int64 x_value5 = 666666666;
		CxAssert(x_sb->Insert(1,x_value5)->Insert() == new StringRaw("{666666666}"));
		x_sb->set_Length(0);
		x_sb->Append(x_value);
		Object x_value6 = 1;
		CxAssert(x_sb->Insert(1,x_value6)->Insert() == new StringRaw("{1}"));
		x_sb->set_Length(0);
		x_sb->Append(x_value);
		CxAssert(x_sb->Insert(1,new StringRaw("fred"))->Insert() == new StringRaw("{fred}"));
		UInt32 x_value7 = 777;
		x_sb->set_Length(0);
		x_sb->Append(x_value);
		CxAssert(x_sb->Insert(1,x_value7)->Insert() == new StringRaw("{777}"));
		x_sb->set_Length(0);
		x_sb->Append(x_value);
		CxAssert(x_sb->Insert(1,new StringRaw("A"),4)->Insert() == new StringRaw("{AAAA}"));
		x_sb->set_Length(0);
		x_sb->Append(x_value);
		CxAssert(x_sb->Insert(1,x_value2,1,3)->Insert() == new StringRaw("{123}"));
	}
	void StringBuilderTestRaw::DoSBReplaceTest()
	{
		x_sb->set_Length(0);
		x_sb->Append(new StringRaw("aaaaaaa"));
		CxAssert(x_sb->Replace('a','A')->Replace() == new StringRaw("AAAAAAA"));
		CxAssert(x_sb->Replace(new StringRaw("AA"),new StringRaw("BBB"))->Replace() == new StringRaw("BBBBBBBBBA"));
		CxAssert(x_sb->Replace('B','C',1,7)->Replace() == new StringRaw("BCCCCCCCBA"));
		CxAssert(x_sb->Replace(new StringRaw("CCC"),new StringRaw("DDD"),2,5)->Replace() == new StringRaw("BCDDDCCCBA"));
		x_sb->set_Length(0);
		x_sb->Append(new StringRaw("aaaaaaa"));
		String x_a = x_sb->Replace(new StringRaw("aa"),new StringRaw("BBB"),1,5)->Replace();
		CxAssert(x_a == new StringRaw("aBBBBBBaa"));
	}
	void StringBuilderTestRaw::CxAssert(Boolean x_x)
	{
		if ( !x_x )
		{
			x_caBlock->TestFailed(new StringRaw("StringBuilder TestFailed"));
		}
	}
	void StringBuilderTestRaw::CxAssert(Boolean x_x,Boolean x_y)
	{
		if ( x_x != x_y )
		{
			x_caBlock->TestFailed(new StringRaw("StringBuilder TestFailed"));
		}
	}

	StringTestRaw::StringTestRaw(CABlock x_caBlock)
	{
		this->x_caBlock.Assign(x_caBlock);
	}
	void StringTestRaw::Test()
	{
		x_caBlock->Send(new StringRaw("Doing StringTest"));
		x_caBlock->Send(new StringRaw("\tDoing DoIndexTest"));
		DoIndexTest();
		x_caBlock->Send(new StringRaw("\tDoing DoMiscTest"));
		DoMiscTest();
		x_caBlock->Send(new StringRaw("\tDoing DoEqualsTest"));
		DoEqualsTest();
		x_caBlock->Send(new StringRaw("\tDoing DoParsingTest"));
		DoParsingTest();
		x_caBlock->Send(new StringRaw("\tDoing DoConcatTest"));
		DoConcatTest();
	}
	void StringTestRaw::DoIndexTest()
	{
		String x_text = new StringRaw("12345");
		CxAssert(x_text->get_Length() == 5);
		CxAssert((*x_text->Address(0)) == '1');
		CxAssert((*x_text->Address(1)) == '2');
		CxAssert((*x_text->Address(2)) == '3');
		CxAssert((*x_text->Address(3)) == '4');
		CxAssert((*x_text->Address(4)) == '5');
	}
	void StringTestRaw::DoMiscTest()
	{
		static Object DoMiscTestArray0[3] = {1,2,3};
		String x_text = new StringRaw(' ',10);
		CxAssert(x_text->get_Length() == 10);
		String x_text2 = new StringRaw("12345");
		PointerType<ArrayRaw<Char>> x_array = (new ArrayRaw<Char>(30));
		x_text2->CopyTo(0,x_array,0,x_text2->get_Length());
		Int32 x_num = 0;
		String x_text3 = x_text2;
		foreach (Char x_c in x_text3 )
		{
			CxAssert((*x_array->Address(x_num)) == x_c);
			x_num++;
		}
		x_array.Assign(x_text2->ToCharArray());
		CxAssert(x_array != nullptr && x_array->get_Length() == x_text2->get_Length());
		String x_a = new StringRaw(x_array);
		CxAssert(x_a == x_text2);
		String x_a2 = new StringRaw(x_array,0,2);
		CxAssert(x_a2 == new StringRaw("12"));
		CxAssert(x_a2 != new StringRaw("22"));
		CxAssert(!( x_a2 == new StringRaw("22") ));
		x_a2.Assign(new StringRaw(x_text2->ToCharArray(),0,x_text2->get_Length()));
		CxAssert(x_a2 == x_text2);
		CxAssert(StringRaw::Compare(new StringRaw("abc"),new StringRaw("ABC"),true) == 0);
		CxAssert(StringRaw::Compare(new StringRaw("1abce"),1,new StringRaw("abc"),0,3) == 0);
		CxAssert(StringRaw::Compare(new StringRaw("1abce"),1,new StringRaw("ABC"),0,3,true) == 0);
		CxAssert(StringRaw::CompareOrdinal(new StringRaw("abc"),new StringRaw("abc")) == 0);
		CxAssert(StringRaw::CompareOrdinal(new StringRaw("1abce"),1,new StringRaw("abc"),0,3) == 0);
		x_a2.Assign(StringRaw::Copy(x_text2));
		CxAssert(x_a2 == x_text2);
		x_a2.Assign(StringRaw::Format(new StringRaw("1 = {{{0,-4}}} 2 = {1,4} 3 = {2}!"),1,2,3));
		CxAssert(x_a2 == new StringRaw("1 = {1   } 2 =    2 3 = 3!"));
		String x_a3 = x_a2->ToString();
		CxAssert(x_a3 == new StringRaw("1 = {1   } 2 =    2 3 = 3!"));
		String x_empty = String::Empty;
		CxAssert(x_empty != nullptr && x_empty == new StringRaw(""));
		x_a2.Assign(StringRaw::Format(new StringRaw("1 = {{{0,-4}}} 2 = {1,4}!"),1,2));
		CxAssert(x_a2 == new StringRaw("1 = {1   } 2 =    2!"));
		x_a2.Assign(StringRaw::Format(new StringRaw("1 = {{{0,-4}}}!"),1));
		CxAssert(x_a2 == new StringRaw("1 = {1   }!"));
		PointerType<ArrayRaw<Object>> x_args = (new ArrayRaw<Object>(3))->Initialize((Object*) DoMiscTestArray0);
		x_a2.Assign(StringRaw::Format(new StringRaw("1 = {{{0,-4}}} 2 = {1,4} 3 = {2}!"),x_args));
		PointerType<CharEnumeratorRaw> x_enumerator = x_a2->GetEnumerator();
		Int32 x_num2 = 0;
		while (x_enumerator->MoveNext() )
		{
			Char x_current = x_enumerator->get_Current();
			CxAssert(x_current == (*x_a2->Address(x_num2++)));
		}
		x_enumerator->Reset();
		Double x_num3 = 2;
		String x_text4 = x_text2 + x_empty + x_num2 + x_num3 + x_num;
		StringTestRaw::TestConcat(x_text2,x_num,x_empty,x_num2,x_num3);
		String x_a4 = new StringRaw("\"");
		CxAssert(x_a4 == new StringRaw("\""));
		x_a4.Assign(new StringRaw("c:\\Retest"));
		CxAssert(x_a4 == new StringRaw("c:\\Retest"));
		x_a4.Assign(new StringRaw("c:\\Retest"));
		CxAssert(x_a4 == new StringRaw("c:\\Retest"));
	}
	void StringTestRaw::TestConcat(String x_str1,Int32 x_index,String x_str4,Int32 x_i,Double x_dbl)
	{
		String x_text = x_str1 + x_str4 + x_i + x_dbl + x_index;
	}
	void StringTestRaw::DoEqualsTest()
	{
		String x_text = new StringRaw("12345");
		CxAssert(StringRaw::Equals(x_text,new StringRaw("12345")));
		CxAssert(x_text == new StringRaw("12345"));
		CxAssert(x_text->Equals(( Object ) x_text));
		CxAssert(x_text->Equals(x_text));
	}
	void StringTestRaw::DoParsingTest()
	{
		static Char DoParsingTestArray0[4] = {' ',',','.',':'};
		static Char DoParsingTestArray1[2] = {'3','4'};
		static String DoParsingTestArray2[3] = {new StringRaw("1"),new StringRaw("2"),new StringRaw("3")};
		String x_text = new StringRaw("12 34 56");
		PointerType<ArrayRaw<String>> x_array = x_text->Split(nullptr);
		CxAssert(x_array->get_Length() == 3);
		CxAssert(new StringRaw("12") == (*x_array->Address(0)));
		CxAssert(new StringRaw("34") == (*x_array->Address(1)));
		CxAssert(new StringRaw("56") == (*x_array->Address(2)));
		String x_text2 = new StringRaw("42, 12, 19");
		PointerType<ArrayRaw<Char>> x_separator = (new ArrayRaw<Char>(4))->Initialize((Char*) DoParsingTestArray0);
		x_array.Assign(x_text2->Split(x_separator));
		CxAssert(x_array->get_Length() == 5);
		CxAssert(new StringRaw("42") == (*x_array->Address(0)));
		CxAssert(new StringRaw("") == (*x_array->Address(1)));
		CxAssert(new StringRaw("12") == (*x_array->Address(2)));
		CxAssert(new StringRaw("") == (*x_array->Address(3)));
		CxAssert(new StringRaw("19") == (*x_array->Address(4)));
		x_array.Assign(x_text2->Split(x_separator,2));
		CxAssert(x_array->get_Length() == 2);
		CxAssert(new StringRaw("42") == (*x_array->Address(0)));
		CxAssert(new StringRaw(" 12, 19") == (*x_array->Address(1)));
		String x_b = x_text->Substring(3);
		CxAssert(new StringRaw("34 56") == x_b);
		x_b.Assign(x_text->Substring(3,2));
		CxAssert(new StringRaw("34") == x_b);
		String x_text3 = new StringRaw("  12345  ");
		String x_b2 = x_text3->Trim();
		CxAssert(new StringRaw("12345") == x_b2);
		String x_text4 = new StringRaw("*;|@123***456@|;*");
		String x_text5 = new StringRaw("*;|@");
		PointerType<ArrayRaw<Char>> x_trimChars = x_text5->ToCharArray();
		x_b2.Assign(x_text4->Trim(x_trimChars));
		CxAssert(new StringRaw("123***456") == x_b2);
		x_b2.Assign(x_text3->TrimStart());
		CxAssert(new StringRaw("12345  ") == x_b2);
		x_b2.Assign(x_text4->TrimStart(x_trimChars));
		CxAssert(new StringRaw("123***456@|;*") == x_b2);
		x_b2.Assign(x_text3->TrimEnd());
		CxAssert(new StringRaw("  12345") == x_b2);
		x_b2.Assign(x_text4->TrimEnd(x_trimChars));
		CxAssert(new StringRaw("*;|@123***456") == x_b2);
		Int32 x_num = StringRaw::Compare(x_text,x_text3);
		CxAssert(x_num > 0);
		x_num = x_text3->CompareTo(x_text);
		CxAssert(x_num < 0);
		x_num = x_text3->CompareTo(( Object ) x_text);
		CxAssert(x_num < 0);
		CxAssert(x_text->EndsWith(new StringRaw("56")));
		PointerType<ArrayRaw<Char>> x_array2 = (new ArrayRaw<Char>(2))->Initialize((Char*) DoParsingTestArray1);
		CxAssert(x_text->IndexOfAny(x_array2) == 3);
		CxAssert(x_text->IndexOfAny(x_array2,1) == 3);
		CxAssert(x_text->IndexOfAny(x_array2,1,3) == 3);
		CxAssert(x_text->IndexOf('5') == 6);
		CxAssert(x_text->IndexOf(' ',3) == 5);
		CxAssert(x_text->IndexOf(' ',3,3) == 5);
		CxAssert(x_text->IndexOf(new StringRaw("56")) == 6);
		CxAssert(x_text->IndexOf(new StringRaw(" "),3) == 5);
		CxAssert(x_text->IndexOf(new StringRaw(" "),3,3) == 5);
		String x_text6 = new StringRaw("11223311");
		CxAssert(x_text6->LastIndexOf('1') == 7);
		CxAssert(x_text6->LastIndexOf('1',4) == 1);
		CxAssert(x_text6->LastIndexOf('1',4,4) == 1);
		CxAssert(x_text6->LastIndexOf(new StringRaw("11")) == 6);
		CxAssert(x_text6->LastIndexOf(new StringRaw("11"),4) == 0);
		CxAssert(x_text6->LastIndexOf(new StringRaw("11"),4,5) == 0);
		(*x_array2->Address(0)) = '1';
		(*x_array2->Address(1)) = '2';
		CxAssert(x_text6->LastIndexOfAny(x_array2) == 7);
		CxAssert(x_text6->LastIndexOfAny(x_array2,4) == 3);
		CxAssert(x_text6->LastIndexOfAny(x_array2,4,4) == 3);
		String x_a = x_text6->PadLeft(3 + x_text6->get_Length());
		CxAssert(x_a == new StringRaw("   11223311"));
		x_a.Assign(x_text6->PadLeft(3 + x_text6->get_Length(),'-'));
		CxAssert(x_a == new StringRaw("---11223311"));
		x_a.Assign(x_text6->PadRight(3 + x_text6->get_Length()));
		CxAssert(x_a == new StringRaw("11223311   "));
		x_a.Assign(x_text6->PadRight(3 + x_text6->get_Length(),'-'));
		CxAssert(x_a == new StringRaw("11223311---"));
		CxAssert(x_text6->StartsWith(new StringRaw("1122")));
		CxAssert(x_text6->Replace('1','x') == new StringRaw("xx2233xx"));
		CxAssert(x_text6->Replace(new StringRaw("1"),new StringRaw("x")) == new StringRaw("xx2233xx"));
		CxAssert(x_text6->Replace(new StringRaw("11"),new StringRaw("x")) == new StringRaw("x2233x"));
		CxAssert(x_text6->Remove(2,2) == new StringRaw("113311"));
		CxAssert(((String)new StringRaw("aaAAaaAA"))->ToUpper() == new StringRaw("AAAAAAAA"));
		CxAssert(((String)new StringRaw("aaAAaaAA"))->ToLower() == new StringRaw("aaaaaaaa"));
		PointerType<ArrayRaw<String>> x_value = (new ArrayRaw<String>(3))->Initialize((String*) DoParsingTestArray2);
		CxAssert(StringRaw::Join(new StringRaw(","),x_value) == new StringRaw("1,2,3"));
		CxAssert(StringRaw::Join(new StringRaw(","),x_value,1,2) == new StringRaw("2,3"));
		x_text6.Assign(x_text->Insert(3,new StringRaw("111")));
		CxAssert(x_text6 == new StringRaw("12 11134 56"));
		String x_text7 = new StringRaw("3.33");
		if ( x_text7->CompareTo(new StringRaw("3.33")) != 0 )
		{
			CxAssert(false);
		}
	}
	void StringTestRaw::DoConcatTest()
	{
		static Object DoConcatTestArray0[4] = {new StringRaw("1 "),new StringRaw("2 "),new StringRaw("3 "),new StringRaw("4")};
		static String DoConcatTestArray1[4] = {new StringRaw("1 "),new StringRaw("2 "),new StringRaw("3 "),new StringRaw("4")};
		PointerType<ArrayRaw<Object>> x_array = (new ArrayRaw<Object>(4))->Initialize((Object*) DoConcatTestArray0);
		String x_a = StringRaw::Concat((*x_array->Address(0)));
		CxAssert(x_a == new StringRaw("1 "));
		x_a.Assign(StringRaw::Concat(x_array));
		CxAssert(x_a == new StringRaw("1 2 3 4"));
		PointerType<ArrayRaw<String>> x_array2 = (new ArrayRaw<String>(4))->Initialize((String*) DoConcatTestArray1);
		x_a.Assign(StringRaw::Concat(x_array2));
		CxAssert(x_a == new StringRaw("1 2 3 4"));
		x_a.Assign(StringRaw::Concat((*x_array->Address(0)),(*x_array->Address(1))));
		CxAssert(x_a == new StringRaw("1 2 "));
		x_a.Assign((*x_array2->Address(0)) + (*x_array2->Address(1)));
		CxAssert(x_a == new StringRaw("1 2 "));
		x_a.Assign(StringRaw::Concat((*x_array->Address(0)),(*x_array->Address(1)),(*x_array->Address(2))));
		CxAssert(x_a == new StringRaw("1 2 3 "));
		x_a.Assign((*x_array2->Address(0)) + (*x_array2->Address(1)) + (*x_array2->Address(2)));
		CxAssert(x_a == new StringRaw("1 2 3 "));
		x_a.Assign((*x_array2->Address(0)) + (*x_array2->Address(1)) + (*x_array2->Address(2)) + (*x_array2->Address(3)));
		CxAssert(x_a == new StringRaw("1 2 3 4"));
	}
	void StringTestRaw::CxAssert(Boolean x_x)
	{
		if ( !x_x )
		{
			x_caBlock->TestFailed(new StringRaw("String TestFailed"));
		}
	}

	TimeTestRaw::TimeTestRaw(CABlock x_caBlock)
	{
		x_dat1 = DateTime::get_Now();
		this->x_caBlock.Assign(x_caBlock);
	}
	void TimeTestRaw::Test()
	{
		x_caBlock->Send(new StringRaw("Doing TimeTest"));
		x_caBlock->Send(new StringRaw("\tDoing TestTimeSpan"));
		TestTimeSpan();
		x_caBlock->Send(new StringRaw("\tDoing TestDateTime"));
		TestDateTime();
		x_caBlock->Send(new StringRaw("\tDoing DateTimeMethodTests"));
		DateTimeMethodTests();
		x_caBlock->Send(new StringRaw("\tDoing TimeArrayTests"));
		TimeArrayTests();
	}
	void TimeTestRaw::TestTimeSpan()
	{
		TimeSpan x_timeSpan = TimeSpan(100);
		TimeSpan x_timeSpan2 = ((TimeSpan)x_timeSpan).Add(x_timeSpan);
		CxAssert(x_timeSpan2.get_Ticks() == 200);
		CxAssert(TimeSpanRaw::Compare(x_timeSpan,x_timeSpan2) < 0);
		CxAssert(((TimeSpan)x_timeSpan).CompareTo(( Object ) x_timeSpan2) < 0);
		CxAssert(((TimeSpan)x_timeSpan).CompareTo(x_timeSpan2) < 0);
		x_timeSpan = ((TimeSpan)x_timeSpan2).Duration();
		CxAssert(x_timeSpan.get_Ticks() == 200);
		CxAssert(TimeSpanRaw::Equals(x_timeSpan,x_timeSpan2));
		CxAssert(((TimeSpan)x_timeSpan).Equals(x_timeSpan2));
		CxAssert(TimeSpanRaw::FromDays(22).get_Ticks() == 19008000000000);
		CxAssert(TimeSpanRaw::FromHours(10).get_Ticks() == 360000000000);
		CxAssert(TimeSpanRaw::FromMilliseconds(100).get_Ticks() == 1000000);
		CxAssert(TimeSpanRaw::FromMinutes(25).get_Ticks() == 15000000000);
		CxAssert(TimeSpanRaw::FromSeconds(18).get_Ticks() == 180000000);
		x_timeSpan = TimeSpanRaw::FromTicks(6500000);
		CxAssert(x_timeSpan.get_Ticks() == 6500000);
		x_timeSpan = ((TimeSpan)x_timeSpan).Negate();
		CxAssert(x_timeSpan.get_Ticks() == -6500000);
		CxAssert(((TimeSpan)x_timeSpan).Subtract(x_timeSpan2).get_Ticks() == -6500200);
		CxAssert(TimeSpanRaw::Parse(new StringRaw("1.1:1:1")).get_Ticks() == 900610000000);
		CxAssert(TimeSpanRaw::Parse(new StringRaw("1.1:1:1.200")).get_Ticks() == 900612000000);
		CxAssert(TimeSpanRaw::Parse(new StringRaw("1:1:1")).get_Ticks() == 36610000000);
		CxAssert(TimeSpanRaw::Parse(new StringRaw("22")).get_Ticks() == 19008000000000);
		x_timeSpan = TimeSpanRaw::Parse(new StringRaw("1.2:3:4.200"));
		String x_a = x_timeSpan.ToString();
		CxAssert(x_a == new StringRaw("1.02:03:04.2000000"));
		CxAssert(x_timeSpan.get_Days() == 1);
		CxAssert(x_timeSpan.get_Hours() == 2);
		CxAssert(x_timeSpan.get_Minutes() == 3);
		CxAssert(x_timeSpan.get_Seconds() == 4);
		CxAssert(x_timeSpan.get_Milliseconds() == 200);
		CxAssert(x_timeSpan.get_Ticks() == 937842000000);
		CxAssert(x_timeSpan.get_TotalDays(),1.08546527777778);
		CxAssert(x_timeSpan.get_TotalHours(),26.0511666666667);
		CxAssert(x_timeSpan.get_TotalMinutes(),1563.07);
		CxAssert(x_timeSpan.get_TotalSeconds(),93784.2);
		CxAssert(x_timeSpan.get_TotalMilliseconds(),93784200);
		CxAssert(( x_timeSpan2 + x_timeSpan2 )->get_Ticks() == 400);
		x_timeSpan = x_timeSpan2;
		CxAssert(x_timeSpan == x_timeSpan2);
		CxAssert(!( x_timeSpan != x_timeSpan2 ));
		x_timeSpan = TimeSpan(100);
		CxAssert(!( x_timeSpan > x_timeSpan2 ));
		CxAssert(!( x_timeSpan >= x_timeSpan2 ));
		CxAssert(!( x_timeSpan2 < x_timeSpan ));
		CxAssert(!( x_timeSpan2 <= x_timeSpan ));
		CxAssert(x_timeSpan == x_timeSpan);
		x_timeSpan = x_timeSpan2 - x_timeSpan;
		CxAssert(x_timeSpan.get_Ticks() == 100);
		x_timeSpan = -x_timeSpan;
		CxAssert(x_timeSpan.get_Ticks() == -100);
		CxAssert(( +x_timeSpan )->get_Ticks() == -100);
		CxAssert(TimeSpan(1000).get_Ticks() == 1000);
		CxAssert(TimeSpan(10,11,30).get_Ticks() == 366900000000);
		CxAssert(TimeSpan(3,10,11,30).get_Ticks() == 2958900000000);
		CxAssert(TimeSpan(3,10,11,30,100).get_Ticks() == 2958901000000);
		CxAssert(TimeSpan(3,10,11,30,100).get_Ticks() == 2958901000000);
		x_timeSpan = TimeSpan(71,3,12,13);
		CxAssert(x_timeSpan.get_Ticks() == 61459330000000);
		String x_text = x_timeSpan.ToString();
		CxAssert(x_text->Equals(new StringRaw("71.03:12:13")));
		x_timeSpan = TimeSpan(-71,3,12,13);
		CxAssert(x_timeSpan.get_Ticks() == -61228670000000);
		String x_text2 = x_timeSpan.ToString();
		CxAssert(x_text2->Equals(new StringRaw("-70.20:47:47")));
		x_timeSpan = TimeSpanRaw::Parse(new StringRaw("-71.03:12:13"));
		CxAssert(x_timeSpan.get_Ticks() == -61459330000000);
		String x_text3 = x_timeSpan.ToString();
		CxAssert(x_text3->Equals(new StringRaw("-71.03:12:13")));
		Object x_obj = TimeSpan::MinValue;
		CxAssert(( ( TimeSpan ) x_obj )->get_Ticks() == TimeSpan::MinValue.get_Ticks());
		TimeSpan x_minValue = TimeSpan::MinValue;
		CxAssert(x_minValue.Equals(x_obj));
		CxAssert(((TimeSpan)TimeSpan::MinValue).CompareTo(x_obj) == 0);
		Int64 x_num = 864000000000;
		CxAssert(864000000000 == x_num);
		x_num = 36000000000;
		CxAssert(36000000000 == x_num);
		x_num = 600000000;
		CxAssert(600000000 == x_num);
		x_num = 10000000;
		CxAssert(10000000 == x_num);
		x_num = 10000;
		CxAssert(10000 == x_num);
		CxAssert(TimeSpan::Zero == TimeSpan::Zero);
		CxAssert(TimeSpan::MaxValue == TimeSpan::MaxValue);
		CxAssert(x_obj->Equals(TimeSpan::MinValue));
		String x_a2 = x_obj->ToString();
		x_minValue = TimeSpan::MinValue;
		CxAssert(x_a2 == x_minValue.ToString());
	}
	void TimeTestRaw::TestDateTime()
	{
		CxAssert(DateTime().get_Ticks() == 0);
		CxAssert(DateTime(1200).get_Ticks() == 1200);
		CxAssert(DateTime(2003,7,23).get_Ticks() == 631945152000000000);
		CxAssert(DateTime(2003,7,23,12,30,30).get_Ticks() == 631945602300000000);
		DateTime x_dateTime = DateTime(2003,7,23,12,30,30,100);
		CxAssert(x_dateTime.get_Ticks() == 631945602301000000);
		CxAssert(x_dateTime.get_Date().get_Ticks() == 631945152000000000);
		Int32 x_day = x_dateTime.get_Day();
		CxAssert(x_day == 23);
		DayOfWeek x_dayOfWeek = DayOfWeek_DayOfWeek;
		CxAssert(x_dayOfWeek == Wednesday_DayOfWeek);
		Int32 x_dayOfYear = x_dateTime.get_DayOfYear();
		CxAssert(x_dayOfYear == 204);
		Int32 x_hour = x_dateTime.get_Hour();
		CxAssert(x_hour == 12);
		Int32 x_millisecond = x_dateTime.get_Millisecond();
		CxAssert(x_millisecond == 100);
		Int32 x_minute = x_dateTime.get_Minute();
		CxAssert(x_minute == 30);
		Int32 x_month = x_dateTime.get_Month();
		CxAssert(x_month == 7);
		DateTime x_now = DateTime::get_Now();
		x_day = x_now.get_Day();
		x_dayOfYear = x_now.get_DayOfYear();
		x_dayOfWeek = DayOfWeek_DayOfWeek;
		x_hour = x_now.get_Hour();
		Int32 x_second = x_dateTime.get_Second();
		CxAssert(x_second == 30);
		CxAssert(x_dateTime.get_TimeOfDay().get_Ticks() == 450301000000);
		DateTime x_today = DateTime::get_Today();
		x_day = x_today.get_Day();
		x_dayOfYear = x_today.get_DayOfYear();
		x_dayOfWeek = DayOfWeek_DayOfWeek;
		x_hour = x_today.get_Hour();
		DateTime x_utcNow = DateTime::get_UtcNow();
		x_day = x_utcNow.get_Day();
		x_dayOfYear = x_utcNow.get_DayOfYear();
		x_dayOfWeek = DayOfWeek_DayOfWeek;
		x_hour = x_utcNow.get_Hour();
		Int32 x_year = x_dateTime.get_Year();
		CxAssert(x_year == 2003);
	}
	void TimeTestRaw::DateTimeMethodTests()
	{
		DateTime x_dateTime = DateTime(2003,7,23,12,30,30,100);
		TimeSpan x_timeSpan = TimeSpan(0,2,0,0);
		CxAssert(((DateTime)x_dateTime).Add(x_timeSpan).get_Ticks() == 631945674301000000);
		CxAssert(((DateTime)x_dateTime).AddDays(1.5).get_Ticks() == 631946898301000000);
		CxAssert(((DateTime)x_dateTime).AddHours(2.5).get_Ticks() == 631945692301000000);
		CxAssert(((DateTime)x_dateTime).AddMilliseconds(159).get_Ticks() == 631945602302590000);
		CxAssert(((DateTime)x_dateTime).AddMinutes(3.2).get_Ticks() == 631945604221000000);
		CxAssert(((DateTime)x_dateTime).AddMonths(5).get_Ticks() == 632077794301000000);
		CxAssert(((DateTime)x_dateTime).AddSeconds(6.66).get_Ticks() == 631945602367600000);
		CxAssert(((DateTime)x_dateTime).AddTicks(666).get_Ticks() == 631945602301000666);
		DateTime x_dateTime2 = ((DateTime)x_dateTime).AddYears(3);
		CxAssert(x_dateTime2.get_Ticks() == 632892546301000000);
		CxAssert(DateTimeRaw::Compare(x_dateTime2,x_dateTime) > 0);
		CxAssert(((DateTime)x_dateTime).CompareTo(x_dateTime2) < 0);
		CxAssert(DateTimeRaw::DaysInMonth(2003,1) == 31);
		CxAssert(!((DateTime)x_dateTime).Equals(x_dateTime2));
		x_dateTime2 = x_dateTime;
		CxAssert(DateTimeRaw::Equals(x_dateTime,x_dateTime2));
		CxAssert(DateTimeRaw::IsLeapYear(2004));
		x_dateTime2 = ((DateTime)x_dateTime).Subtract(x_timeSpan);
		CxAssert(x_dateTime2.get_Ticks() == 631945530301000000);
		CxAssert(((DateTime)x_dateTime).Subtract(x_dateTime2).get_Ticks() == 72000000000);
		x_dateTime2 = ((DateTime)x_dateTime).ToLocalTime();
		x_dateTime2 = ((DateTime)x_dateTime).ToUniversalTime();
		x_dateTime2 = x_dateTime + x_timeSpan;
		CxAssert(x_dateTime2.get_Ticks() == 631945674301000000);
		CxAssert(!( x_dateTime2 == x_dateTime ));
		CxAssert(!( x_dateTime > x_dateTime2 ));
		CxAssert(!( x_dateTime >= x_dateTime2 ));
		CxAssert(x_dateTime2 == x_dateTime2);
		CxAssert(!( x_dateTime2 < x_dateTime ));
		CxAssert(!( x_dateTime2 <= x_dateTime ));
		x_dateTime2 = x_dateTime - x_timeSpan;
		CxAssert(x_dateTime2.get_Ticks() == 631945530301000000);
		CxAssert(( x_dateTime - x_dateTime2 )->get_Ticks() == 72000000000);
		x_dateTime2 = DateTime(2003,7,23,14,2,30,100);
		CxAssert(x_dateTime2.get_Ticks() == 631945657501000000);
		CxAssert(x_dateTime2.get_Hour() == 14);
		String x_text = ((DateTime)x_dateTime2).ToString();
		CxAssert(x_text->Equals(new StringRaw("7/23/2003 2:02:30 PM")));
		x_dateTime2 = DateTime(2003,7,23,2,20,1,100);
		CxAssert(x_dateTime2.get_Ticks() == 631945236011000000);
		CxAssert(x_dateTime2.get_Hour() == 2);
		x_text.Assign(((DateTime)x_dateTime2).ToString());
		CxAssert(x_text->Equals(new StringRaw("7/23/2003 2:20:01 AM")));
		CxAssert(0.get_Ticks() == 0);
		CxAssert(3155378975999999999.get_Ticks() == 3155378975999999999);
		Object x_obj = 0;
		CxAssert(( ( DateTime ) x_obj )->get_Ticks() == 0);
		CxAssert(((DateTime)0).Equals(x_obj));
		CxAssert(((DateTime)0).CompareTo(x_obj) == 0);
		CxAssert(x_obj->Equals(0));
		CxAssert(x_obj->ToString() == ((DateTime)0).ToString());
		CxAssert(x_dateTime2 != x_dateTime);
	}
	void TimeTestRaw::TimeArrayTests()
	{
		DateTimeArrayTests();
		TimeSpanArrayTests();
	}
	void TimeTestRaw::DateTimeArrayTests()
	{
		static DateTime DateTimeArrayTestsArray0[5] = {DateTime(2000,4,6),DateTime(2000,4,7),DateTime(2000,4,8),DateTime(2000,4,9),DateTime(2000,4,10)};
		static DateTime DateTimeArrayTestsArray1[2][4] = {{DateTime(2000,4,6),DateTime(2000,4,7),DateTime(2000,4,8),DateTime(2000,4,9)},{DateTime(2000,4,10),DateTime(2000,4,11),DateTime(2000,4,12),DateTime(2000,4,13)}};
		static DateTime DateTimeArrayTestsArray2[2][2][4] = {{{DateTime(2000,4,6),DateTime(2000,4,7),DateTime(2000,4,8),DateTime(2000,4,9)},{DateTime(2000,4,10),DateTime(2000,4,11),DateTime(2000,4,12),DateTime(2000,4,13)}},{{DateTime(2000,4,14),DateTime(2000,4,15),DateTime(2000,4,16),DateTime(2000,4,17)},{DateTime(2000,4,18),DateTime(2000,4,19),DateTime(2000,4,20),DateTime(2000,4,21)}}};
		PointerType<ArrayRaw<DateTime>> x_array = (new ArrayRaw<DateTime>(5))->Initialize((DateTime*) DateTimeArrayTestsArray0);
		CxAssert(x_array->get_Length() == 5);
		CxAssert((*x_array->Address(3)) == DateTime(2000,4,9));
		CxAssert((*x_array->Address(1)) == DateTime(2000,4,7));
		PointerType<ArrayRaw<DateTime>> x_array2 = (new ArrayRaw<DateTime>(2,4))->Initialize((DateTime*) DateTimeArrayTestsArray1);
		CxAssert((*x_array2->Address(0,2)) == DateTime(2000,4,8));
		PointerType<ArrayRaw<DateTime>> x_array3 = (new ArrayRaw<DateTime>(2,2,4))->Initialize((DateTime*) DateTimeArrayTestsArray2);
		CxAssert((*x_array3->Address(0,0,3)) == DateTime(2000,4,9));
		(*x_array3->Address(0,0,3)) = DateTime(2000,4,27);
		CxAssert((*x_array3->Address(0,0,3)) == DateTime(2000,4,27));
		x_array3->SetValue(DateTime(2000,4,28),0,0,3);
		CxAssert((*x_array3->Address(0,0,3)) == DateTime(2000,4,28));
		DateTime x_d = (*x_array->Address(2)) = DateTime(2000,4,27);
		CxAssert((*x_array->Address(2)) == x_d);
	}
	void TimeTestRaw::TimeSpanArrayTests()
	{
		static TimeSpan TimeSpanArrayTestsArray0[5] = {TimeSpan(2000,4,6),TimeSpan(2000,4,7),TimeSpan(2000,4,8),TimeSpan(2000,4,9),TimeSpan(2000,4,10)};
		static TimeSpan TimeSpanArrayTestsArray1[2][4] = {{TimeSpan(2000,4,6),TimeSpan(2000,4,7),TimeSpan(2000,4,8),TimeSpan(2000,4,9)},{TimeSpan(2000,4,10),TimeSpan(2000,4,11),TimeSpan(2000,4,12),TimeSpan(2000,4,13)}};
		static TimeSpan TimeSpanArrayTestsArray2[2][2][4] = {{{TimeSpan(2000,4,6),TimeSpan(2000,4,7),TimeSpan(2000,4,8),TimeSpan(2000,4,9)},{TimeSpan(2000,4,10),TimeSpan(2000,4,11),TimeSpan(2000,4,12),TimeSpan(2000,4,13)}},{{TimeSpan(2000,4,14),TimeSpan(2000,4,15),TimeSpan(2000,4,16),TimeSpan(2000,4,17)},{TimeSpan(2000,4,18),TimeSpan(2000,4,19),TimeSpan(2000,4,20),TimeSpan(2000,4,21)}}};
		PointerType<ArrayRaw<TimeSpan>> x_array = (new ArrayRaw<TimeSpan>(5))->Initialize((TimeSpan*) TimeSpanArrayTestsArray0);
		CxAssert(x_array->get_Length() == 5);
		CxAssert((*x_array->Address(3)) == TimeSpan(2000,4,9));
		CxAssert((*x_array->Address(1)) == TimeSpan(2000,4,7));
		PointerType<ArrayRaw<TimeSpan>> x_array2 = (new ArrayRaw<TimeSpan>(2,4))->Initialize((TimeSpan*) TimeSpanArrayTestsArray1);
		CxAssert((*x_array2->Address(0,2)) == TimeSpan(2000,4,8));
		PointerType<ArrayRaw<TimeSpan>> x_array3 = (new ArrayRaw<TimeSpan>(2,2,4))->Initialize((TimeSpan*) TimeSpanArrayTestsArray2);
		CxAssert((*x_array3->Address(0,0,3)) == TimeSpan(2000,4,9));
		(*x_array3->Address(0,0,3)) = TimeSpan(2000,4,27);
		CxAssert((*x_array3->Address(0,0,3)) == TimeSpan(2000,4,27));
		x_array3->SetValue(TimeSpan(2000,4,28),0,0,3);
		CxAssert((*x_array3->Address(0,0,3)) == TimeSpan(2000,4,28));
		TimeSpan x_t = (*x_array->Address(2)) = TimeSpan(2000,4,27);
		CxAssert((*x_array->Address(2)) == x_t);
	}
	void TimeTestRaw::CxAssert(Double x_x,Double x_y)
	{
		if ( MathRaw::Abs(x_x - x_y) > 1E-05 )
		{
			x_caBlock->TestFailed(new StringRaw("Time TestFailed"));
		}
	}
	void TimeTestRaw::CxAssert(Boolean x_x)
	{
		if ( !x_x )
		{
			TimeTestFailed();
		}
	}
	void TimeTestRaw::TimeTestFailed()
	{
		x_caBlock->TestFailed(new StringRaw("Time TestFailed"));
	}

	TimingTestRaw::TimingTestRaw()
	{
	}
	Int32 TimingTestRaw::DoTimingTest(Int32 x_a,Int32 x_b,Int32 x_c)
	{
		Int32 x_result = 0;
		for ( Int32 x_i = 0 ;  x_i < x_a ;   x_i++ )
		{
			for ( Int32 x_j = 0 ;  x_j < x_b ;   x_j++ )
			{
				x_result = x_i * x_j + x_c;
			}
		}
		return x_result;
	}

	UInt16TestRaw::UInt16TestRaw(CABlock x_caBlock)
	{
		this->x_caBlock.Assign(x_caBlock);
	}
	void UInt16TestRaw::Test()
	{
		x_caBlock->Send(new StringRaw("Doing UInt16Test"));
		x_caBlock->Send(new StringRaw("\tDoing UInt16MethodsTest"));
		UInt16MethodsTest();
		x_caBlock->Send(new StringRaw("\tDoing DoUnSignedMath"));
		DoUnSignedMath();
		x_caBlock->Send(new StringRaw("\tDoing UInt16Operators"));
		UInt16Operators();
		x_caBlock->Send(new StringRaw("\tDoing UInt16ArrayTest"));
		UInt16ArrayTest();
		x_caBlock->Send(new StringRaw("\tDoing UInt16MiscTests"));
		UInt16MiscTests();
	}
	void UInt16TestRaw::UInt16MethodsTest()
	{
		UInt16 x_num = 5;
		CxAssert(((UInt16)x_num).CompareTo(5) == 0);
		CxAssert(((UInt16)x_num).CompareTo(( Object ) ( UInt16 ) 5) == 0);
		CxAssert(((UInt16)x_num).Equals(5));
		CxAssert(((UInt16)x_num).Equals(( Object ) ( UInt16 ) 5));
		CxAssert(UInt16Raw::Parse(new StringRaw("77")) == 77);
		CxAssert(new StringRaw("5") == ((UInt16)x_num).ToString());
		x_num = 65535;
		CxAssert(65535 == x_num);
		x_num = 0;
		CxAssert(x_num == 0);
		String x_text = ((UInt16)65535).ToString();
		CxAssert(x_text == new StringRaw("65535"));
		CxAssert(UInt16Raw::Parse(x_text) == 65535);
		String x_text2 = ( ( UInt16 ) 0 )->ToString();
		CxAssert(x_text2 == new StringRaw("0"));
		CxAssert(UInt16Raw::Parse(x_text2) == 0);
		Object x_obj = ( UInt16 ) 5;
		CxAssert(x_obj->Equals(( UInt16 ) 5));
		CxAssert(x_obj->ToString() == new StringRaw("5"));
	}
	void UInt16TestRaw::DoUnSignedMath()
	{
		UInt16 x_num = 600;
		UInt16 x_num2 = 1200;
		Int32 x_num3 = 1;
		CxAssert(1 <= x_num);
		CxAssert(x_num >= 1);
		CxAssert(x_num >= x_num3);
		CxAssert(x_num3 <= x_num);
		x_num3 += x_num;
		CxAssert(x_num3 == 601);
		CxAssert(x_num + x_num2 == 1800);
		CxAssert(x_num - x_num2 == -600);
		CxAssert(x_num * x_num2 == 720000);
		CxAssert(( Int32 ) x_num2 / ( Int32 ) x_num == 2);
		CxAssert(x_num >> 2 == 150);
		CxAssert(x_num << 1 == 1200);
		Int32 x_num4 = 11;
		CxAssert(x_num4 % 5 == 1);
		x_num4 = 8;
		CxAssert(( x_num4 | 1 ) == 9);
		CxAssert(( x_num4 & 1 ) == 0);
		CxAssert(++x_num4 == 9);
		CxAssert(--x_num4 == 8);
		CxAssert(( x_num4 *= 2 ) == 16);
		CxAssert(( x_num4 /= 2 ) == 8);
		CxAssert(( x_num4 %= 2 ) == 0);
		CxAssert(( x_num4 |= 4 ) == 4);
		CxAssert(( x_num4 &= 4 ) == 4);
		CxAssert(-x_num == -600);
		CxAssert(x_num == 600);
		UInt32 x_num5 = 0;
		CxAssert(~x_num5 == 4294967295);
		CxAssert(++x_num5 == 1);
		CxAssert(--x_num5 == 0);
	}
	void UInt16TestRaw::UInt16Operators()
	{
		UInt16 x_num = 66;
		Char x_c = '';
		Int32 x_num2 = 1;
		UInt16 x_num3 = 1;
		Int64 x_num4 = 1;
		Double x_num5 = 1;
		CxAssert(x_num == 66);
		CxAssert(x_num + x_c == 67);
		CxAssert(x_num + x_num2 == 67);
		CxAssert(x_num + x_num3 == 67);
		CxAssert(x_num + x_num4 == 67);
		CxAssert(( Double ) ( Int32 ) x_num + x_num5 == 67);
		CxAssert(x_num - x_c == 65);
		CxAssert(x_num - x_num2 == 65);
		CxAssert(x_num - x_num3 == 65);
		CxAssert(x_num - x_num4 == 65);
		CxAssert(( Double ) ( Int32 ) x_num - x_num5 == 65);
		CxAssert(x_num * x_c == 66);
		CxAssert(x_num * x_num2 == 66);
		CxAssert(x_num * x_num3 == 66);
		CxAssert(x_num * x_num4 == 66);
		CxAssert(( Double ) ( Int32 ) x_num * x_num5 == 66);
		CxAssert(( Int32 ) x_num / ( Int32 ) x_c == 66);
		CxAssert(( Int32 ) x_num / x_num2 == 66);
		CxAssert(( Int32 ) x_num / ( Int32 ) x_num3 == 66);
		CxAssert(( Int64 ) x_num / x_num4 == 66);
		CxAssert(( Double ) ( Int32 ) x_num / x_num5 == 66);
		CxAssert(( Int32 ) x_num % ( Int32 ) x_c == 0);
		CxAssert(( Int32 ) x_num % x_num2 == 0);
		CxAssert(( Int32 ) x_num % ( Int32 ) x_num3 == 0);
		CxAssert(( Int64 ) x_num % x_num4 == 0);
		CxAssert(( Double ) ( Int32 ) x_num % x_num5 == 0);
		CxAssert(( x_num & x_c ) == 0);
		CxAssert(( x_num & x_num2 ) == 0);
		CxAssert(( x_num & x_num3 ) == 0);
		CxAssert(( x_num & x_num4 ) == 0);
		CxAssert(( x_num | x_c ) == 67);
		CxAssert(( x_num | x_num3 ) == 67);
		CxAssert(( x_num | x_num4 ) == 67);
		CxAssert(( x_num ^ x_c ) == 67);
		CxAssert(( x_num ^ x_num2 ) == 67);
		CxAssert(( x_num ^ x_num3 ) == 67);
		CxAssert(( x_num ^ x_num4 ) == 67);
		CxAssert(~x_num == -67);
		CxAssert(x_c < x_num);
		CxAssert(x_num2 < x_num);
		CxAssert(x_num3 < x_num);
		CxAssert(x_num4 < x_num);
		CxAssert(x_num5 < ( Double ) ( Int32 ) x_num);
		CxAssert(x_c > x_num,false);
		CxAssert(x_num2 > x_num,false);
		CxAssert(x_num3 > x_num,false);
		CxAssert(x_num4 > x_num,false);
		CxAssert(x_num5 > ( Double ) ( Int32 ) x_num,false);
		CxAssert(( x_num = ( UInt16 ) ( x_num + 1 ) ) == 67);
		CxAssert(( x_num = ( UInt16 ) ( x_num - 1 ) ) == 66);
		CxAssert(x_num++ == 66);
		CxAssert(x_num-- == 67);
		CxAssert(x_num << 1 == 132);
		CxAssert(x_num >> 1 == 33);
		CxAssert(x_c == x_num,false);
		CxAssert(x_num2 == x_num,false);
		CxAssert(x_num3 == x_num,false);
		CxAssert(x_num4 == x_num,false);
		CxAssert(x_num5 == ( Double ) ( Int32 ) x_num,false);
		CxAssert(x_c != x_num);
		CxAssert(x_num2 != x_num);
		CxAssert(x_num3 != x_num);
		CxAssert(x_num4 != x_num);
		CxAssert(x_num5 != ( Double ) ( Int32 ) x_num);
		CxAssert(x_c <= x_num);
		CxAssert(x_num2 <= x_num);
		CxAssert(x_num3 <= x_num);
		CxAssert(x_num4 <= x_num);
		CxAssert(x_num5 <= ( Double ) ( Int32 ) x_num);
		CxAssert(x_c >= x_num,false);
		CxAssert(x_num2 >= x_num,false);
		CxAssert(x_num3 >= x_num,false);
		CxAssert(x_num4 >= x_num,false);
		CxAssert(x_num5 >= ( Double ) ( Int32 ) x_num,false);
		CxAssert(( x_num = ( UInt16 ) ( x_num + x_c ) ) == 67);
		CxAssert(( x_num = ( UInt16 ) ( x_num - x_c ) ) == 66);
		CxAssert(( x_num = ( UInt16 ) ( x_num + x_num3 ) ) == 67);
		CxAssert(( x_num = ( UInt16 ) ( x_num - x_num3 ) ) == 66);
		CxAssert(( x_num = ( UInt16 ) ( x_num * x_c ) ) == 66);
		CxAssert(( x_num = ( UInt16 ) ( ( Int32 ) x_num / ( Int32 ) x_c ) ) == 66);
		CxAssert(( x_num = ( UInt16 ) ( x_num * x_num3 ) ) == 66);
		CxAssert(( x_num = ( UInt16 ) ( ( Int32 ) x_num / ( Int32 ) x_num3 ) ) == 66);
		CxAssert(( x_num = ( UInt16 ) ( ( Int32 ) x_num % ( Int32 ) x_c ) ) == 0);
		x_num = 66;
		CxAssert(( x_num = ( UInt16 ) ( ( Int32 ) x_num % ( Int32 ) x_num3 ) ) == 0);
		x_num = 66;
		CxAssert(( x_num = ( UInt16 ) ( x_num & x_c ) ) == 0);
		x_num = 66;
		CxAssert(( x_num = ( UInt16 ) ( x_num & x_num3 ) ) == 0);
		x_num = 66;
		CxAssert(( x_num = ( UInt16 ) ( x_num | x_c ) ) == 67);
		x_num = 66;
		CxAssert(( x_num = ( UInt16 ) ( x_num | x_num3 ) ) == 67);
		x_num = 66;
		CxAssert(( x_num = ( UInt16 ) ( x_num ^ x_c ) ) == 67);
		x_num = 66;
		CxAssert(( x_num = ( UInt16 ) ( x_num ^ x_num3 ) ) == 67);
		x_num = 66;
		CxAssert(( x_num = ( UInt16 ) ( x_num << ( Int32 ) x_c ) ) == 132);
		x_num = 66;
		CxAssert(( x_num = ( UInt16 ) ( x_num << x_num2 ) ) == 132);
		x_num = 66;
		CxAssert(( x_num = ( UInt16 ) ( x_num >> ( Int32 ) x_c ) ) == 33);
		x_num = 66;
		CxAssert(( x_num = ( UInt16 ) ( x_num >> x_num2 ) ) == 33);
		x_num = 66;
	}
	void UInt16TestRaw::UInt16ArrayTest()
	{
		static UInt16 UInt16ArrayTestArray0[5] = {1,2,3,4,5};
		static UInt16 UInt16ArrayTestArray1[4] = {1,2,3,4};
		static UInt16 UInt16ArrayTestArray2[2][4] = {{1,2,3,4},{4,5,6,7}};
		static UInt16 UInt16ArrayTestArray3[2][2][4] = {{{1,2,3,4},{5,6,7,8}},{{9,10,11,12},{13,14,15,16}}};
		PointerType<ArrayRaw<UInt16>> x_array = (new ArrayRaw<UInt16>(5))->Initialize((UInt16*) UInt16ArrayTestArray0);
		CxAssert(x_array->get_Length() == 5);
		CxAssert((*x_array->Address(3)) == 4);
		PointerType<ArrayRaw<UInt16>> x_array2 = (new ArrayRaw<UInt16>(4))->Initialize((UInt16*) UInt16ArrayTestArray1);
		CxAssert((*x_array2->Address(1)) == 2);
		PointerType<ArrayRaw<UInt16>> x_array3 = (new ArrayRaw<UInt16>(2,4))->Initialize((UInt16*) UInt16ArrayTestArray2);
		CxAssert((*x_array3->Address(0,2)) == 3);
		PointerType<ArrayRaw<UInt16>> x_array4 = (new ArrayRaw<UInt16>(2,2,4))->Initialize((UInt16*) UInt16ArrayTestArray3);
		CxAssert((*x_array4->Address(0,0,3)) == 4);
		(*x_array4->Address(0,0,3)) = 6;
		CxAssert((*x_array4->Address(0,0,3)) == 6);
		x_array4->SetValue(( UInt16 ) 4,0,0,3);
		CxAssert((*x_array4->Address(0,0,3)) == 4);
	}
	void UInt16TestRaw::UInt16MiscTests()
	{
		UInt16 x_num = 0;
		UInt16 x_num2 = 1;
		CxAssert(MathRaw::Max(x_num,x_num2) == 1);
		CxAssert(MathRaw::Min(x_num,x_num2) == 0);
		PointerType<StringBuilderRaw> x_stringBuilder = new StringBuilderRaw();
		x_stringBuilder->Append(x_num2);
		CxAssert(x_stringBuilder->ToString() == new StringRaw("1"));
		x_stringBuilder->Insert(1,x_num);
		CxAssert(x_stringBuilder->ToString() == new StringRaw("10"));
	}
	void UInt16TestRaw::CxAssert(Boolean x_x)
	{
		if ( !x_x )
		{
			x_caBlock->TestFailed(new StringRaw("UInt16 TestFailed"));
		}
	}
	void UInt16TestRaw::CxAssert(Boolean x_x,Boolean x_y)
	{
		if ( x_x != x_y )
		{
			x_caBlock->TestFailed(new StringRaw("UInt16 TestFailed"));
		}
	}

	UInt32TestRaw::UInt32TestRaw(CABlock x_caBlock)
	{
		this->x_caBlock.Assign(x_caBlock);
	}
	void UInt32TestRaw::Test()
	{
		x_caBlock->Send(new StringRaw("Doing UInt32Test"));
		x_caBlock->Send(new StringRaw("\tDoing UInt32MethodsTest"));
		UInt32MethodsTest();
		x_caBlock->Send(new StringRaw("\tDoing DoUnSignedMath"));
		DoUnSignedMath();
		x_caBlock->Send(new StringRaw("\tDoing UInt32Operators"));
		UInt32Operators();
		x_caBlock->Send(new StringRaw("\tDoing UInt32ArrayTest"));
		UInt32ArrayTest();
		x_caBlock->Send(new StringRaw("\tDoing UInt32MiscTests"));
		UInt32MiscTests();
	}
	void UInt32TestRaw::UInt32MethodsTest()
	{
		UInt32 x_num = 5;
		CxAssert(((UInt32)x_num).CompareTo(5) == 0);
		CxAssert(((UInt32)x_num).CompareTo(( Object ) 5) == 0);
		CxAssert(((UInt32)x_num).Equals(5));
		CxAssert(((UInt32)x_num).Equals(( Object ) 5));
		CxAssert(UInt32Raw::Parse(new StringRaw("77")) == 77);
		CxAssert(new StringRaw("5") == ((UInt32)x_num).ToString());
		x_num = 4294967295;
		CxAssert(-1 == ( Int32 ) x_num);
		x_num = 0;
		CxAssert(x_num == 0);
		String x_text = ((UInt32)4294967295).ToString();
		CxAssert(x_text == new StringRaw("4294967295"));
		CxAssert(UInt32Raw::Parse(x_text) == 4294967295);
		String x_text2 = ((UInt32)0).ToString();
		CxAssert(x_text2 == new StringRaw("0"));
		CxAssert(UInt32Raw::Parse(x_text2) == 0);
		Object x_obj = 5;
		CxAssert(x_obj->Equals(5));
		CxAssert(x_obj->ToString() == new StringRaw("5"));
	}
	void UInt32TestRaw::DoUnSignedMath()
	{
		UInt32 x_num = 60000;
		UInt32 x_num2 = 120000;
		Int32 x_num3 = 1;
		CxAssert(1 <= x_num);
		CxAssert(x_num >= 1);
		CxAssert(x_num >= x_num3);
		CxAssert(x_num3 <= x_num);
		x_num3 += ( Int32 ) x_num;
		CxAssert(x_num3 == 60001);
		CxAssert(x_num + x_num2 == 180000);
		CxAssert(x_num - x_num2 == 4294907296);
		CxAssert(x_num * x_num2 == 2905032704);
		CxAssert(x_num2 / x_num == 2);
		CxAssert(x_num >> 2 == 15000);
		CxAssert(x_num << 1 == 120000);
		Int32 x_num4 = 11;
		CxAssert(x_num4 % 5 == 1);
		x_num4 = 8;
		CxAssert(( x_num4 | 1 ) == 9);
		CxAssert(( x_num4 & 1 ) == 0);
		CxAssert(++x_num4 == 9);
		CxAssert(--x_num4 == 8);
		CxAssert(( x_num4 *= 2 ) == 16);
		CxAssert(( x_num4 /= 2 ) == 8);
		CxAssert(( x_num4 %= 2 ) == 0);
		CxAssert(( x_num4 |= 4 ) == 4);
		CxAssert(( x_num4 &= 4 ) == 4);
		CxAssert(0 - x_num == -60000);
		CxAssert(x_num == 60000);
		UInt32 x_num5 = 0;
		CxAssert(~x_num5 == 4294967295);
		CxAssert(++x_num5 == 1);
		CxAssert(--x_num5 == 0);
	}
	void UInt32TestRaw::UInt32Operators()
	{
		UInt32 x_num = 66;
		Char x_c = '';
		Int32 x_num2 = 1;
		UInt32 x_num3 = 1;
		Int64 x_num4 = 1;
		Double x_num5 = 1;
		CxAssert(x_num == 66);
		CxAssert(x_num + x_c == 67);
		CxAssert(x_num + x_num2 == 67);
		CxAssert(x_num + x_num3 == 67);
		CxAssert(x_num + x_num4 == 67);
		CxAssert(( Double ) x_num + x_num5 == 67);
		CxAssert(x_num - x_c == 65);
		CxAssert(x_num - x_num2 == 65);
		CxAssert(x_num - x_num3 == 65);
		CxAssert(x_num - x_num4 == 65);
		CxAssert(( Double ) x_num - x_num5 == 65);
		CxAssert(x_num * x_c == 66);
		CxAssert(x_num * x_num2 == 66);
		CxAssert(x_num * x_num3 == 66);
		CxAssert(x_num * x_num4 == 66);
		CxAssert(( Double ) x_num * x_num5 == 66);
		CxAssert(x_num / x_c == 66);
		CxAssert(( Int64 ) x_num / ( Int64 ) x_num2 == 66);
		CxAssert(x_num / x_num3 == 66);
		CxAssert(( Int64 ) x_num / x_num4 == 66);
		CxAssert(( Double ) x_num / x_num5 == 66);
		CxAssert(x_num % x_c == 0);
		CxAssert(( Int64 ) x_num % ( Int64 ) x_num2 == 0);
		CxAssert(x_num % x_num3 == 0);
		CxAssert(( Int64 ) x_num % x_num4 == 0);
		CxAssert(( Double ) x_num % x_num5 == 0);
		CxAssert(( x_num & x_c ) == 0);
		CxAssert(( x_num & x_num2 ) == 0);
		CxAssert(( x_num & x_num3 ) == 0);
		CxAssert(( x_num & x_num4 ) == 0);
		CxAssert(( x_num | x_c ) == 67);
		CxAssert(( x_num | x_num3 ) == 67);
		CxAssert(( x_num | x_num4 ) == 67);
		CxAssert(( x_num ^ x_c ) == 67);
		CxAssert(( x_num ^ x_num2 ) == 67);
		CxAssert(( x_num ^ x_num3 ) == 67);
		CxAssert(( x_num ^ x_num4 ) == 67);
		CxAssert(~x_num == 4294967229);
		CxAssert(x_c < x_num);
		CxAssert(x_num2 < x_num);
		CxAssert(x_num3 < x_num);
		CxAssert(x_num4 < x_num);
		CxAssert(x_num5 < ( Double ) x_num);
		CxAssert(x_c > x_num,false);
		CxAssert(x_num2 > x_num,false);
		CxAssert(x_num3 > x_num,false);
		CxAssert(x_num4 > x_num,false);
		CxAssert(x_num5 > ( Double ) x_num,false);
		CxAssert(++x_num == 67);
		CxAssert(--x_num == 66);
		CxAssert(x_num++ == 66);
		CxAssert(x_num-- == 67);
		CxAssert(x_num << 1 == 132);
		CxAssert(x_num >> 1 == 33);
		CxAssert(x_c == x_num,false);
		CxAssert(x_num2 == x_num,false);
		CxAssert(x_num3 == x_num,false);
		CxAssert(x_num4 == x_num,false);
		CxAssert(x_num5 == ( Double ) x_num,false);
		CxAssert(x_c != x_num);
		CxAssert(x_num2 != x_num);
		CxAssert(x_num3 != x_num);
		CxAssert(x_num4 != x_num);
		CxAssert(x_num5 != ( Double ) x_num);
		CxAssert(x_c <= x_num);
		CxAssert(x_num2 <= x_num);
		CxAssert(x_num3 <= x_num);
		CxAssert(x_num4 <= x_num);
		CxAssert(x_num5 <= ( Double ) x_num);
		CxAssert(x_c >= x_num,false);
		CxAssert(x_num2 >= x_num,false);
		CxAssert(x_num3 >= x_num,false);
		CxAssert(x_num4 >= x_num,false);
		CxAssert(x_num5 >= ( Double ) x_num,false);
		CxAssert(( x_num += x_c ) == 67);
		CxAssert(( x_num -= x_c ) == 66);
		CxAssert(( x_num += x_num3 ) == 67);
		CxAssert(( x_num -= x_num3 ) == 66);
		CxAssert(( x_num *= x_c ) == 66);
		CxAssert(( x_num /= x_c ) == 66);
		CxAssert(( x_num *= x_num3 ) == 66);
		CxAssert(( x_num /= x_num3 ) == 66);
		CxAssert(( x_num %= x_c ) == 0);
		x_num = 66;
		CxAssert(( x_num %= x_num3 ) == 0);
		x_num = 66;
		CxAssert(( x_num &= x_c ) == 0);
		x_num = 66;
		CxAssert(( x_num &= x_num3 ) == 0);
		x_num = 66;
		CxAssert(( x_num |= x_c ) == 67);
		x_num = 66;
		CxAssert(( x_num |= x_num3 ) == 67);
		x_num = 66;
		CxAssert(( x_num ^= x_c ) == 67);
		x_num = 66;
		CxAssert(( x_num ^= x_num3 ) == 67);
		x_num = 66;
		CxAssert(( x_num <<= ( Int32 ) x_c ) == 132);
		x_num = 66;
		CxAssert(( x_num <<= x_num2 ) == 132);
		x_num = 66;
		CxAssert(( x_num >>= ( Int32 ) x_c ) == 33);
		x_num = 66;
		CxAssert(( x_num >>= x_num2 ) == 33);
		x_num = 66;
	}
	void UInt32TestRaw::UInt32ArrayTest()
	{
		static UInt32 UInt32ArrayTestArray0[5] = {1,2,3,4,5};
		static UInt32 UInt32ArrayTestArray1[4] = {1,2,3,4};
		static UInt32 UInt32ArrayTestArray2[2][4] = {{1,2,3,4},{4,5,6,7}};
		static UInt32 UInt32ArrayTestArray3[2][2][4] = {{{1,2,3,4},{5,6,7,8}},{{9,10,11,12},{13,14,15,16}}};
		PointerType<ArrayRaw<UInt32>> x_array = (new ArrayRaw<UInt32>(5))->Initialize((UInt32*) UInt32ArrayTestArray0);
		CxAssert(x_array->get_Length() == 5);
		CxAssert((*x_array->Address(3)) == 4);
		PointerType<ArrayRaw<UInt32>> x_array2 = (new ArrayRaw<UInt32>(4))->Initialize((UInt32*) UInt32ArrayTestArray1);
		CxAssert((*x_array2->Address(1)) == 2);
		PointerType<ArrayRaw<UInt32>> x_array3 = (new ArrayRaw<UInt32>(2,4))->Initialize((UInt32*) UInt32ArrayTestArray2);
		CxAssert((*x_array3->Address(0,2)) == 3);
		PointerType<ArrayRaw<UInt32>> x_array4 = (new ArrayRaw<UInt32>(2,2,4))->Initialize((UInt32*) UInt32ArrayTestArray3);
		CxAssert((*x_array4->Address(0,0,3)) == 4);
		(*x_array4->Address(0,0,3)) = 6;
		CxAssert((*x_array4->Address(0,0,3)) == 6);
		x_array4->SetValue(4,0,0,3);
		CxAssert((*x_array4->Address(0,0,3)) == 4);
	}
	void UInt32TestRaw::UInt32MiscTests()
	{
		UInt32 x_val = 0;
		UInt32 x_num = 1;
		CxAssert(MathRaw::Max(x_val,x_num) == 1);
		CxAssert(MathRaw::Min(x_val,x_num) == 0);
		PointerType<StringBuilderRaw> x_stringBuilder = new StringBuilderRaw();
		x_stringBuilder->Append(x_num);
		CxAssert(x_stringBuilder->ToString() == new StringRaw("1"));
	}
	void UInt32TestRaw::CxAssert(Boolean x_x)
	{
		if ( !x_x )
		{
			x_caBlock->TestFailed(new StringRaw("UInt32 TestFailed"));
		}
	}
	void UInt32TestRaw::CxAssert(Boolean x_x,Boolean x_y)
	{
		if ( x_x != x_y )
		{
			x_caBlock->TestFailed(new StringRaw("UInt32 TestFailed"));
		}
	}

	UInt64TestRaw::UInt64TestRaw(CABlock x_caBlock)
	{
		this->x_caBlock.Assign(x_caBlock);
	}
	void UInt64TestRaw::Test()
	{
		x_caBlock->Send(new StringRaw("Doing UInt64Test"));
		x_caBlock->Send(new StringRaw("\tDoing UInt64MethodsTest"));
		UInt64MethodsTest();
		x_caBlock->Send(new StringRaw("\tDoing UInt64UnSignedMath"));
		UInt64UnSignedMath();
		x_caBlock->Send(new StringRaw("\tDoing UInt64Operators"));
		UInt64Operators();
		x_caBlock->Send(new StringRaw("\tDoing UInt64ArrayTest"));
		UInt64ArrayTest();
		x_caBlock->Send(new StringRaw("\tDoing UInt64MiscTests"));
		UInt64MiscTests();
	}
	void UInt64TestRaw::UInt64MethodsTest()
	{
		UInt64 x_num = 5;
		CxAssert(((UInt64)x_num).CompareTo(5) == 0);
		CxAssert(((UInt64)x_num).CompareTo(( Object ) 5) == 0);
		CxAssert(((UInt64)x_num).Equals(5));
		CxAssert(((UInt64)x_num).Equals(( Object ) 5));
		CxAssert(UInt64Raw::Parse(new StringRaw("77")) == 77);
		CxAssert(new StringRaw("5") == ((UInt64)x_num).ToString());
		x_num = 18446744073709551615;
		CxAssert(18446744073709551615 == x_num);
		x_num = 0;
		CxAssert(x_num == 0);
		String x_text = ((UInt64)18446744073709551615).ToString();
		CxAssert(x_text == new StringRaw("18446744073709551615"));
		CxAssert(UInt64Raw::Parse(x_text) == 18446744073709551615);
		String x_text2 = ((UInt64)0).ToString();
		CxAssert(x_text2 == new StringRaw("0"));
		CxAssert(UInt64Raw::Parse(x_text2) == 0);
		Object x_obj = 5;
		CxAssert(x_obj->Equals(5));
		CxAssert(x_obj->ToString() == new StringRaw("5"));
	}
	void UInt64TestRaw::UInt64UnSignedMath()
	{
		UInt64 x_num = 60000;
		UInt64 x_num2 = 120000;
		UInt64 x_num3 = 1;
		CxAssert(1 <= x_num);
		CxAssert(x_num >= 1);
		CxAssert(x_num >= x_num3);
		CxAssert(x_num3 <= x_num);
		x_num3 += x_num;
		CxAssert(x_num3 == 60001);
		CxAssert(x_num + x_num2 == 180000);
		UInt64 x_num4 = x_num - x_num2;
		CxAssert(x_num - x_num2 == 18446744073709491616);
		UInt64 x_num5 = x_num * x_num2;
		CxAssert(x_num * x_num2 == 7200000000);
		CxAssert(x_num2 / x_num == 2);
		CxAssert(x_num >> 2 == 15000);
		CxAssert(x_num << 1 == 120000);
		Int32 x_num6 = 11;
		CxAssert(x_num6 % 5 == 1);
		x_num6 = 8;
		CxAssert(( x_num6 | 1 ) == 9);
		CxAssert(( x_num6 & 1 ) == 0);
		CxAssert(++x_num6 == 9);
		CxAssert(--x_num6 == 8);
		CxAssert(( x_num6 *= 2 ) == 16);
		CxAssert(( x_num6 /= 2 ) == 8);
		CxAssert(( x_num6 %= 2 ) == 0);
		CxAssert(( x_num6 |= 4 ) == 4);
		CxAssert(( x_num6 &= 4 ) == 4);
		CxAssert(x_num == 60000);
		UInt32 x_num7 = 0;
		CxAssert(~x_num7 == 4294967295);
		CxAssert(++x_num7 == 1);
		CxAssert(--x_num7 == 0);
	}
	void UInt64TestRaw::UInt64Operators()
	{
		UInt64 x_num = 66;
		Char x_c = '';
		Byte x_b = 1;
		SByte x_b2 = 1;
		Int16 x_num2 = 1;
		Int32 x_num3 = 1;
		Int64 x_num4 = 1;
		UInt16 x_num5 = 1;
		UInt32 x_num6 = 1;
		UInt64 x_num7 = 1;
		Float x_num8 = 1;
		Double x_num9 = 1;
		CxAssert(x_num == 66);
		CxAssert(x_num + x_c == 67);
		CxAssert(x_num + x_b == 67);
		CxAssert(( Int64 ) x_num + ( Int64 ) x_b2 == 67);
		CxAssert(( Int64 ) x_num + ( Int64 ) x_num2 == 67);
		CxAssert(( Int64 ) x_num + ( Int64 ) x_num3 == 67);
		CxAssert(( Int64 ) x_num + x_num4 == 67);
		CxAssert(x_num + x_num5 == 67);
		CxAssert(x_num + x_num6 == 67);
		CxAssert(x_num + x_num7 == 67);
		CxAssert(( Float ) x_num + x_num8 == 67);
		CxAssert(( Double ) x_num + x_num9 == 67);
		CxAssert(x_num - x_c == 65);
		CxAssert(x_num - x_b == 65);
		CxAssert(( Int64 ) x_num - ( Int64 ) x_b2 == 65);
		CxAssert(( Int64 ) x_num - ( Int64 ) x_num2 == 65);
		CxAssert(( Int64 ) x_num - ( Int64 ) x_num3 == 65);
		CxAssert(( Int64 ) x_num - x_num4 == 65);
		CxAssert(x_num - x_num5 == 65);
		CxAssert(x_num - x_num6 == 65);
		CxAssert(x_num - x_num7 == 65);
		CxAssert(( Float ) x_num - x_num8 == 65);
		CxAssert(( Double ) x_num - x_num9 == 65);
		CxAssert(x_num * x_c == 66);
		CxAssert(x_num * x_b == 66);
		CxAssert(( Int64 ) x_num * ( Int64 ) x_b2 == 66);
		CxAssert(( Int64 ) x_num * ( Int64 ) x_num2 == 66);
		CxAssert(( Int64 ) x_num * ( Int64 ) x_num3 == 66);
		CxAssert(( Int64 ) x_num * x_num4 == 66);
		CxAssert(x_num * x_num5 == 66);
		CxAssert(x_num * x_num6 == 66);
		CxAssert(x_num * x_num7 == 66);
		CxAssert(( Float ) x_num * x_num8 == 66);
		CxAssert(( Double ) x_num * x_num9 == 66);
		CxAssert(x_num / x_c == 66);
		CxAssert(x_num / x_b == 66);
		CxAssert(x_num / ( UInt64 ) x_b2 == 66);
		CxAssert(x_num / ( UInt64 ) x_num2 == 66);
		CxAssert(x_num / ( UInt64 ) x_num3 == 66);
		CxAssert(x_num / ( UInt64 ) x_num4 == 66);
		CxAssert(x_num / x_num5 == 66);
		CxAssert(x_num / x_num6 == 66);
		CxAssert(x_num / x_num7 == 66);
		CxAssert(( Float ) x_num / x_num8 == 66);
		CxAssert(( Double ) x_num / x_num9 == 66);
		CxAssert(x_num % x_c == 0);
		CxAssert(x_num % x_b == 0);
		CxAssert(x_num % ( UInt64 ) x_b2 == 0);
		CxAssert(x_num % ( UInt64 ) x_num2 == 0);
		CxAssert(x_num % ( UInt64 ) x_num3 == 0);
		CxAssert(x_num % ( UInt64 ) x_num4 == 0);
		CxAssert(x_num % x_num5 == 0);
		CxAssert(x_num % x_num6 == 0);
		CxAssert(x_num % x_num7 == 0);
		CxAssert(( Float ) x_num % x_num8 == 0);
		CxAssert(( Double ) x_num % x_num9 == 0);
		CxAssert(( x_num & x_c ) == 0);
		CxAssert(( x_num & x_b ) == 0);
		CxAssert(( ( Int64 ) x_num & ( Int64 ) x_b2 ) == 0);
		CxAssert(( ( Int64 ) x_num & ( Int64 ) x_num2 ) == 0);
		CxAssert(( ( Int64 ) x_num & ( Int64 ) x_num3 ) == 0);
		CxAssert(( ( Int64 ) x_num & x_num4 ) == 0);
		CxAssert(( x_num & x_num5 ) == 0);
		CxAssert(( x_num & x_num6 ) == 0);
		CxAssert(( x_num & x_num7 ) == 0);
		CxAssert(( x_num | x_c ) == 67);
		CxAssert(( x_num | x_b ) == 67);
		CxAssert(( ( Int64 ) x_num | ( Int64 ) x_b2 ) == 67);
		CxAssert(( ( Int64 ) x_num | ( Int64 ) x_num2 ) == 67);
		CxAssert(( ( Int64 ) x_num | ( Int64 ) x_num3 ) == 67);
		CxAssert(( ( Int64 ) x_num | x_num4 ) == 67);
		CxAssert(( x_num | x_num5 ) == 67);
		CxAssert(( x_num | x_num6 ) == 67);
		CxAssert(( x_num | x_num7 ) == 67);
		CxAssert(( x_num ^ x_c ) == 67);
		CxAssert(( x_num ^ x_b ) == 67);
		CxAssert(( ( Int64 ) x_num ^ ( Int64 ) x_b2 ) == 67);
		CxAssert(( ( Int64 ) x_num ^ ( Int64 ) x_num2 ) == 67);
		CxAssert(( ( Int64 ) x_num ^ ( Int64 ) x_num3 ) == 67);
		CxAssert(( ( Int64 ) x_num ^ x_num4 ) == 67);
		CxAssert(( x_num ^ x_num5 ) == 67);
		CxAssert(( x_num ^ x_num6 ) == 67);
		CxAssert(( x_num ^ x_num7 ) == 67);
		CxAssert(( Byte ) ( ~x_num ) == 189);
		CxAssert(x_c < x_num);
		CxAssert(x_b < x_num);
		CxAssert(( UInt64 ) x_b2 < x_num);
		CxAssert(( UInt64 ) x_num2 < x_num);
		CxAssert(( UInt64 ) x_num3 < x_num);
		CxAssert(( UInt64 ) x_num4 < x_num);
		CxAssert(x_num5 < x_num);
		CxAssert(x_num6 < x_num);
		CxAssert(x_num7 < x_num);
		CxAssert(x_num8 < ( Float ) x_num);
		CxAssert(x_num9 < ( Double ) x_num);
		CxAssert(x_c > x_num,false);
		CxAssert(x_b > x_num,false);
		CxAssert(( UInt64 ) x_b2 > x_num,false);
		CxAssert(( UInt64 ) x_num2 > x_num,false);
		CxAssert(( UInt64 ) x_num3 > x_num,false);
		CxAssert(( UInt64 ) x_num4 > x_num,false);
		CxAssert(x_num5 > x_num,false);
		CxAssert(x_num6 > x_num,false);
		CxAssert(x_num7 > x_num,false);
		CxAssert(x_num8 > ( Float ) x_num,false);
		CxAssert(x_num9 > ( Double ) x_num,false);
		CxAssert(++x_num == 67);
		CxAssert(--x_num == 66);
		CxAssert(x_num++ == 66);
		CxAssert(x_num-- == 67);
		CxAssert(x_num << 1 == 132);
		CxAssert(x_num >> 1 == 33);
		CxAssert(x_c == x_num,false);
		CxAssert(x_b == x_num,false);
		CxAssert(( UInt64 ) x_b2 == x_num,false);
		CxAssert(( UInt64 ) x_num2 == x_num,false);
		CxAssert(( UInt64 ) x_num3 == x_num,false);
		CxAssert(x_num4 == ( Int64 ) x_num,false);
		CxAssert(x_num5 == x_num,false);
		CxAssert(x_num6 == x_num,false);
		CxAssert(x_num7 == x_num,false);
		CxAssert(x_num8 == ( Float ) x_num,false);
		CxAssert(x_num9 == ( Double ) x_num,false);
		CxAssert(x_c != x_num);
		CxAssert(x_b != x_num);
		CxAssert(( UInt64 ) x_b2 != x_num);
		CxAssert(( UInt64 ) x_num2 != x_num);
		CxAssert(( UInt64 ) x_num3 != x_num);
		CxAssert(x_num4 != ( Int64 ) x_num);
		CxAssert(x_num5 != x_num);
		CxAssert(x_num6 != x_num);
		CxAssert(x_num7 != x_num);
		CxAssert(x_num8 != ( Float ) x_num);
		CxAssert(x_num9 != ( Double ) x_num);
		CxAssert(x_c <= x_num);
		CxAssert(x_b <= x_num);
		CxAssert(( UInt64 ) x_b2 <= x_num);
		CxAssert(( UInt64 ) x_num2 <= x_num);
		CxAssert(( UInt64 ) x_num3 <= x_num);
		CxAssert(( UInt64 ) x_num4 <= x_num);
		CxAssert(x_num5 <= x_num);
		CxAssert(x_num6 <= x_num);
		CxAssert(x_num7 <= x_num);
		CxAssert(x_num8 <= ( Float ) x_num);
		CxAssert(x_num9 <= ( Double ) x_num);
		CxAssert(x_c >= x_num,false);
		CxAssert(x_b >= x_num,false);
		CxAssert(( UInt64 ) x_b2 >= x_num,false);
		CxAssert(( UInt64 ) x_num2 >= x_num,false);
		CxAssert(( UInt64 ) x_num3 >= x_num,false);
		CxAssert(( UInt64 ) x_num4 >= x_num,false);
		CxAssert(x_num5 >= x_num,false);
		CxAssert(x_num6 >= x_num,false);
		CxAssert(x_num7 >= x_num,false);
		CxAssert(x_num8 >= ( Float ) x_num,false);
		CxAssert(x_num9 >= ( Double ) x_num,false);
		CxAssert(( x_num += ( Byte ) x_c ) == 67);
		CxAssert(( x_num -= ( Byte ) x_c ) == 66);
		CxAssert(( x_num += ( Byte ) x_num6 ) == 67);
		CxAssert(( x_num -= ( Byte ) x_num6 ) == 66);
		CxAssert(( x_num *= ( Byte ) x_c ) == 66);
		CxAssert(( x_num /= ( Byte ) x_c ) == 66);
		CxAssert(( x_num *= ( Byte ) x_num6 ) == 66);
		CxAssert(( x_num /= ( Byte ) x_num6 ) == 66);
		CxAssert(( x_num %= ( Byte ) x_c ) == 0);
		x_num = 66;
		CxAssert(( x_num %= ( Byte ) x_num6 ) == 0);
		x_num = 66;
		CxAssert(( x_num &= ( Byte ) x_c ) == 0);
		x_num = 66;
		CxAssert(( x_num &= ( Byte ) x_num6 ) == 0);
		x_num = 66;
		CxAssert(( x_num |= ( Byte ) x_c ) == 67);
		x_num = 66;
		CxAssert(( x_num |= ( Byte ) x_num6 ) == 67);
		x_num = 66;
		CxAssert(( x_num ^= ( Byte ) x_c ) == 67);
		x_num = 66;
		CxAssert(( x_num ^= ( Byte ) x_num6 ) == 67);
		x_num = 66;
		CxAssert(( x_num <<= ( Int32 ) x_c ) == 132);
		x_num = 66;
		CxAssert(( x_num <<= x_num3 ) == 132);
		x_num = 66;
		CxAssert(( x_num >>= ( Int32 ) x_c ) == 33);
		x_num = 66;
		CxAssert(( x_num >>= x_num3 ) == 33);
		x_num = 66;
		Char x_c2 = 'B';
		CxAssert(( x_c2 = ( Char ) ( ( UInt32 ) x_c2 << ( Int32 ) x_c ) ) == '');
	}
	void UInt64TestRaw::UInt64ArrayTest()
	{
		static UInt64 UInt64ArrayTestArray0[5] = {1,2,3,4,5};
		static UInt64 UInt64ArrayTestArray1[4] = {1,2,3,4};
		static UInt64 UInt64ArrayTestArray2[2][4] = {{1,2,3,4},{4,5,6,7}};
		static UInt64 UInt64ArrayTestArray3[2][2][4] = {{{1,2,3,4},{5,6,7,8}},{{9,10,11,12},{13,14,15,16}}};
		PointerType<ArrayRaw<UInt64>> x_array = (new ArrayRaw<UInt64>(5))->Initialize((UInt64*) UInt64ArrayTestArray0);
		CxAssert(x_array->get_Length() == 5);
		CxAssert((*x_array->Address(3)) == 4);
		PointerType<ArrayRaw<UInt64>> x_array2 = (new ArrayRaw<UInt64>(4))->Initialize((UInt64*) UInt64ArrayTestArray1);
		CxAssert((*x_array2->Address(1)) == 2);
		PointerType<ArrayRaw<UInt64>> x_array3 = (new ArrayRaw<UInt64>(2,4))->Initialize((UInt64*) UInt64ArrayTestArray2);
		CxAssert((*x_array3->Address(0,2)) == 3);
		PointerType<ArrayRaw<UInt64>> x_array4 = (new ArrayRaw<UInt64>(2,2,4))->Initialize((UInt64*) UInt64ArrayTestArray3);
		CxAssert((*x_array4->Address(0,0,3)) == 4);
		(*x_array4->Address(0,0,3)) = 6;
		CxAssert((*x_array4->Address(0,0,3)) == 6);
		x_array4->SetValue(4,0,0,3);
		CxAssert((*x_array4->Address(0,0,3)) == 4);
	}
	void UInt64TestRaw::UInt64MiscTests()
	{
		UInt64 x_num = 0;
		UInt64 x_num2 = 1;
		CxAssert(MathRaw::Max(x_num,x_num2) == 1);
		CxAssert(MathRaw::Min(x_num,x_num2) == 0);
		PointerType<StringBuilderRaw> x_stringBuilder = new StringBuilderRaw();
		x_stringBuilder->Append(x_num2);
		CxAssert(x_stringBuilder->ToString() == new StringRaw("1"));
		x_stringBuilder->Insert(1,x_num);
		CxAssert(x_stringBuilder->ToString() == new StringRaw("10"));
	}
	void UInt64TestRaw::CxAssert(Boolean x_x)
	{
		if ( !x_x )
		{
			x_caBlock->TestFailed(new StringRaw("UInt64 TestFailed"));
		}
	}
	void UInt64TestRaw::CxAssert(Boolean x_x,Boolean x_y)
	{
		if ( x_x != x_y )
		{
			x_caBlock->TestFailed(new StringRaw("UInt64 TestFailed"));
		}
	}

}
