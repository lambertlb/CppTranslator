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
		Int32 x_num = (( Int32 ) 0);
		Int32 x_num2 = (( Int32 ) 0);
		Int32 x_num3 = (( Int32 ) 0);
		Int32 x_num4 = ( Int32 ) x_num++ + ( Int32 ) x_num2++ + ( Int32 ) x_num3-- + ( Int32 ) x_num + ( Int32 ) x_num2 + ( Int32 ) x_num3;
		CxAssert(!((Int32)(x_num4)).Equals((( Int32 ) 0)));
		x_caBlock->Send((new StringRaw("Doing ArrayTest")));
		x_caBlock->Send((new StringRaw("\tDoing TestArrayCreation")));
		TestArrayCreation();
		x_caBlock->Send((new StringRaw("\tDoing MiscTest")));
		MiscTest();
		x_caBlock->Send((new StringRaw("\tDoing ArrayMethodTests")));
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
		CxAssert(((Int32)((*x_int1dArray->Address(1)))).Equals((( Int32 ) 2)));
		x_int2dArray.Assign((new ArrayRaw<Int32>(2,4))->Initialize((Int32*) TestArrayCreationArray1));
		CxAssert(((Int32)((*x_int2dArray->Address(0,2)))).Equals((( Int32 ) 3)));
		x_int3dArray.Assign((new ArrayRaw<Int32>(2,2,4))->Initialize((Int32*) TestArrayCreationArray2));
		CxAssert(((Int32)((*x_int3dArray->Address(0,0,3)))).Equals((( Int32 ) 4)));
		x_double1dArray.Assign((new ArrayRaw<Double>(4))->Initialize((Double*) TestArrayCreationArray3));
		CxAssert(((Double)((*x_double1dArray->Address(1)))).Equals((( Double ) 2)));
		x_double2dArray.Assign((new ArrayRaw<Double>(2,4))->Initialize((Double*) TestArrayCreationArray4));
		CxAssert(((Double)((*x_double2dArray->Address(0,2)))).Equals((( Double ) 3)));
		x_double3dArray.Assign((new ArrayRaw<Double>(2,2,4))->Initialize((Double*) TestArrayCreationArray5));
		CxAssert(((Double)((*x_double3dArray->Address(0,0,3)))).Equals((( Double ) 4)));
		x_dateTime1dArray.Assign((new ArrayRaw<DateTime>(4))->Initialize((DateTime*) TestArrayCreationArray6));
		CxAssert((*x_dateTime1dArray->Address(2)).Equals(DateTime(2003,7,23,12,30,30,300)));
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
		CxAssert(((Int32)(x_int3dArray->GetLength(2))).Equals((( Int32 ) 4)));
		CxAssert(((Int32)(x_int3dArray->GetLowerBound(2))).Equals((( Int32 ) 0)));
		CxAssert(((Int32)(x_int3dArray->GetUpperBound(2))).Equals((( Int32 ) 3)));
		PointerType<ArrayRaw<DateTime>> x_array = x_dateTime1dArray;
		for ( int foreachi = 0; foreachi < x_array->GetLength(0) ; ++foreachi ) 
		{
			DateTime x_dateTime = x_array->GetValue(foreachi);
			String x_text = x_dateTime.ToString();
		}
	}
	void ArrayTestRaw::ArrayMethodTests()
	{
		static Int32 ArrayMethodTestsArray0[3] = {1,1,1};
		static Double ArrayMethodTestsArray1[4] = {1,2,3,4};
		Int32 x_length = ( Int32 ) x_int3dArray->get_Length();
		CxAssert(((Int32)(x_length)).Equals((( Int32 ) 16)));
		CxAssert(((Int32)(x_int1dArray->get_Rank())).Equals((( Int32 ) 1)));
		CxAssert(((Int32)(x_int2dArray->get_Rank())).Equals((( Int32 ) 2)));
		CxAssert(((Int32)(x_int3dArray->get_Rank())).Equals((( Int32 ) 3)));
		PointerType<ArrayRaw<DateTime>> x_array = (new ArrayRaw<DateTime>(5));
		ArrayBase::Copy(x_dateTime1dArray,x_array,x_dateTime1dArray->get_Length());
		for ( Int32 x_i = (( Int32 ) 0) ;  x_i < ( Int32 ) x_dateTime1dArray->get_Length() ;   x_i++ )
		{
			DateTime x_d = (*x_dateTime1dArray->Address(x_i));
			DateTime x_d2 = (*x_array->Address(x_i));
			CxAssert((x_d).Equals(x_d2));
		}
		x_dateTime1dArray->CopyTo(x_array,1);
		for ( Int32 x_j = (( Int32 ) 1) ;  x_j < ( Int32 ) x_array->get_Length() ;   x_j++ )
		{
			CxAssert(((*x_dateTime1dArray->Address(x_j - (( Int32 ) 1)))).Equals((*x_array->Address(x_j))));
		}
		CxAssert(TimeSpan(5,4,3,2,100).Equals(x_timeSpan3dArray->GetValue(1,1,1)));
		TimeSpan x_timeSpan = TimeSpan(5,4,3,2,101);
		PointerType<ArrayRaw<Int32>> x_indices = (new ArrayRaw<Int32>(3))->Initialize((Int32*) ArrayMethodTestsArray0);
		x_timeSpan3dArray->SetValue(x_timeSpan,x_indices);
		CxAssert(x_timeSpan.Equals(x_timeSpan3dArray->GetValue(x_indices)));
		(*x_double3dArray->Address(1,1,3)) = (( Double ) 22);
		Double x_num = ( Double ) (*x_double3dArray->Address(1,1,3));
		CxAssert(((Double)(x_num)).Equals((( Double ) 22)));
		CxAssert(((( Double ) 22)).Equals(x_double3dArray->GetValue(1,1,3)));
		x_timeSpan3dArray->SetValue(x_timeSpan,0,0,0);
		CxAssert(((*x_timeSpan3dArray->Address(0,0,0))).Equals(x_timeSpan));
		(*x_boolArray->Address(0)) = true;
		CxAssert((*x_boolArray->Address(0)));
		ArrayBase::Clear(x_boolArray,0,x_boolArray->get_Length());
		CxAssert(!(*x_boolArray->Address(0)));
		x_int1dArray->SetValue(1,2);
		CxAssert(((Int32)((*x_int1dArray->Address(1)))).Equals((( Int32 ) 2)));
		PointerType<ArrayRaw<Double>> x_array2 = (new ArrayRaw<Double>(4))->Initialize((Double*) ArrayMethodTestsArray1);
		x_array2->SetValue(2,1);
		CxAssert(((Double)((*x_array2->Address(1)))).Equals((( Double ) 2)));
		x_array2->SetValue(2,1);
		CxAssert(((Double)((*x_array2->Address(1)))).Equals((( Double ) 2)));
	}
	void ArrayTestRaw::CxAssert(Boolean x_x)
	{
		if ( !x_x )
		{
			x_caBlock->TestFailed((new StringRaw("Array TestFailed")));
		}
	}
	BasicTestRaw::BasicTestRaw(CABlock x_caBlock)
	{
		x_field1 = 0;
		this->x_caBlock.Assign(x_caBlock);
	}
	void BasicTestRaw::Test()
	{
		x_caBlock->Send((new StringRaw("Doing BasicTest")));
		x_caBlock->Send((new StringRaw("\tDoing FieldTest")));
		FieldTest();
		x_caBlock->Send((new StringRaw("\tDoing SwitchTest")));
		SwitchTest();
		x_caBlock->Send((new StringRaw("\tDoing IfThenElseTest")));
		IfThenElseTest();
		x_caBlock->Send((new StringRaw("\tDoing StructTest")));
		StructTest();
		x_caBlock->Send((new StringRaw("\tDoing StructTest2")));
		StructTest2();
		x_caBlock->Send((new StringRaw("\tDoing VirtualMethodTest")));
		VirtualMethodTest();
		x_caBlock->Send((new StringRaw("\tDoing PassByReferenceTest")));
		PassByReferenceTest();
		x_caBlock->Send((new StringRaw("\tDoing Namespace Test")));
		TestUsingNamespace();
		x_caBlock->Send((new StringRaw("\tDoing Complex conditions")));
		ComplexConditions();
		x_caBlock->Send((new StringRaw("\tDoing Naming test")));
		TestNames();
	}
	void BasicTestRaw::FieldTest()
	{
		PointerType<BasicTestRaw> x_basicTest = new BasicTestRaw(x_caBlock);
		Int32 x_num = ( Int32 ) x_field1;
		CxAssert(((Int32)(x_num)).Equals(( Int32 ) x_field1));
		Int32 x_num2 = ( Int32 ) x_basicTest->x_field1;
		CxAssert(((Int32)(x_num2)).Equals(( Int32 ) x_basicTest->x_field1));
		DateTime x_maxValue = ((DateTime)3155378975999999999);
		CxAssert((x_maxValue).Equals(((DateTime)3155378975999999999)));
		Object x_obj = new ObjectRaw();
		CxAssert(!(x_obj->ToString())->Equals(nullptr));
		CxAssert(x_obj->Equals(x_obj));
		CxAssert(ObjectRaw::Equals(x_obj,x_obj));
	}
	void BasicTestRaw::SwitchTest()
	{
		x_field1 = (( Int32 ) 1);
		Int32 x_num = ( Int32 ) -1;
		switch ( x_field1++ )
		{
			case 0:
			x_num = (( Int32 ) 0);
			break;
			case 1:
			x_num = (( Int32 ) 1);
			break;
			case 1000:
			x_num = (( Int32 ) 1000);
			break;
			case 100000:
			x_num = (( Int32 ) 100000);
			break;
		}
		CxAssert(((Int32)(x_num)).Equals((( Int32 ) 1)));
		CxAssert(((Int32)(x_field1)).Equals((( Int32 ) 2)));
	}
	void BasicTestRaw::IfThenElseTest()
	{
		x_field1 = (( Int32 ) 1);
		if ( ((Int32)(x_field1)).Equals((( Int32 ) 1)) )
		{
			x_field1 = (( Int32 ) 2);
			if ( ((Int32)(x_field1)).Equals((( Int32 ) 3)) )
			{
				x_field1 = (( Int32 ) 4);
			}
			else
			{
				x_field1 = (( Int32 ) 5);
			}
		}
		else
		{
			x_field1 = (( Int32 ) 6);
		}
		CxAssert(((Int32)(x_field1)).Equals((( Int32 ) 5)));
		CxAssert(ObjectRaw::Equals(nullptr,nullptr));
	}
	void BasicTestRaw::StructTest()
	{
		TestStruct x_ts = TestStruct(2);
		CxAssert(((Int32)(x_ts.get_Data())).Equals((( Int32 ) 2)));
		x_ts.set_Data(3);
		CxAssert(((Int32)(x_ts.get_Data())).Equals((( Int32 ) 3)));
		x_ts = x_ts + 1;
		CxAssert(((Int32)(x_ts.get_Data())).Equals((( Int32 ) 4)));
		CxAssert(((Int32)(( x_ts & (( Int32 ) 1) ).get_Data())).Equals((( Int32 ) 0)));
	}
	void BasicTestRaw::StructTest2()
	{
		TestStruct3 x_testStruct = ( TestStruct3 ) TestStruct3();
		x_testStruct.x_ts.x_data = (( Int32 ) 6);
		CxAssert(((Int32)(x_testStruct.x_ts.x_data)).Equals((( Int32 ) 6)));
		x_ts3.x_ts.x_data = (( Int32 ) 7);
		CxAssert(((Int32)(x_ts3.x_ts.x_data)).Equals((( Int32 ) 7)));
	}
	void BasicTestRaw::VirtualMethodTest()
	{
		PointerType<TestAbstractRaw> x_testAbstract = new TestAbstractRaw();
		CxAssert(((Int32)(x_testAbstract->MustImplement())).Equals((( Int32 ) 2)));
		CxAssert(((Int32)(x_testAbstract->DidImplement())).Equals((( Int32 ) 1)));
	}
	void BasicTestRaw::PassByReferenceTest()
	{
		Int32 x_data = (( Int32 ) 0);
		DateTime x_data2 = DateTime();
		TimeSpan x_data3 = TimeSpan();
		String x_data4 = ( String ) nullptr;
		PointerType<TestAbstractRaw> x_data5 = ( TestAbstract ) nullptr;
		RefMethod(x_data);
		CxAssert(((Int32)(x_data)).Equals((( Int32 ) 1)));
		RefMethod(x_data2);
		CxAssert(((Int64)(x_data2.get_Ticks())).Equals((( Int64 ) 1000)));
		RefMethod(x_data3);
		CxAssert(((Int64)(x_data3.get_Ticks())).Equals((( Int64 ) 1000)));
		RefMethod(x_data4);
		CxAssert((x_data4)->Equals((new StringRaw("Test"))));
		RefMethod(x_data5);
		CxAssert(((Int32)(x_data5->MustImplement())).Equals((( Int32 ) 2)));
	}
	void BasicTestRaw::RefMethod(Int32&  x_data)
	{
		if ( ((Int32)(x_data)).Equals((( Int32 ) 0)) )
		{
			x_data = (( Int32 ) 1);
		}
	}
	void BasicTestRaw::RefMethod(DateTime&  x_data)
	{
		x_data = DateTime(1000);
	}
	void BasicTestRaw::RefMethod(TimeSpan&  x_data)
	{
		x_data = TimeSpan(1000);
	}
	void BasicTestRaw::RefMethod(String&  x_data)
	{
		if ( (x_data)->Equals(nullptr) )
		{
			x_data.Assign((new StringRaw("Test")));
		}
	}
	void BasicTestRaw::RefMethod(TestAbstract&  x_data)
	{
		if ( (x_data)->Equals(nullptr) )
		{
			x_data.Assign(new TestAbstractRaw());
		}
	}
	void BasicTestRaw::TestUsingNamespace()
	{
		PointerType<TestNamespaceClassRaw> x_testNamespaceClass = new TestNamespaceClassRaw();
		CxAssert(!(x_testNamespaceClass)->Equals(nullptr));
	}
	void BasicTestRaw::CxAssert(Boolean x_x)
	{
		if ( !x_x )
		{
			x_caBlock->TestFailed((new StringRaw("BaseTest TestFailed")));
		}
	}
	void BasicTestRaw::ComplexConditions()
	{
		x_field1 = (( Int32 ) 0);
		CxAssert(x_field1 < (( Int32 ) 1) && x_field1 < (( Int32 ) 2) && x_field1 < (( Int32 ) 3));
		x_field1 = (( Int32 ) 10);
		CxAssert(x_field1 >= (( Int32 ) 1) || x_field1 >= (( Int32 ) 2) || x_field1 >= (( Int32 ) 3));
		x_field1 = (( Int32 ) 2);
		Boolean x_flag = x_field1 < (( Int32 ) 1);
		Boolean x_flag2 = x_field1 < (( Int32 ) 2);
		Boolean x_flag3 = x_field1 < (( Int32 ) 3);
		Boolean x_flag4 = x_field1 < (( Int32 ) 4);
		Boolean x_flag5 = x_field1 < (( Int32 ) 5);
		CxAssert(!( ( x_flag || x_flag2 ) && x_flag3 ) || ( x_flag4 && x_flag5 && x_flag3 ) || x_flag2);
		CxAssert(!x_flag && !x_flag2 && x_flag3 && x_flag4 && x_flag5);
		CxAssert(x_flag || x_flag2 || ( x_flag3 && x_flag4 && x_flag5 ));
		CxAssert(!x_flag && x_flag3 && !x_flag2 && x_flag4 && x_flag5);
		CxAssert(TestThis(1,2));
		CxAssert(!TestThis(6,2));
		CxAssert(TestThis(60,2));
	}
	Boolean BasicTestRaw::TestThis(Int32 x_a,Int32 x_b)
	{
		return ( x_a < (( Int32 ) 5) && x_b < (( Int32 ) 3) ) || x_a + ( Int32 ) x_b > (( Int32 ) 20);
	}
	void BasicTestRaw::TestNames()
	{
		PointerType<typedefRaw> x_typedef = new typedefRaw();
		x_typedef->set_Friend(x_friend_TestNameEnu);
		CxAssert(x_typedef->get_Friend() == x_friend_TestNameEnu);
	}
	TestAbstractRaw::TestAbstractRaw() : AbstractRaw (1,2)
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
		return (new StringRaw("TestAbstract"));
	}
	Int32 TestStruct::get_Data()
	{
		return x_data;
	}
	void TestStruct::set_Data(Int32 x_value )
	{
		x_data = ( Int32 ) x_value;
	}
	TestStruct::TestStruct(Int32 x_i)
	{
		x_data = ( Int32 ) x_i;
	}
	TestStruct operator +(TestStruct x_ts,Int32 x_newData)
	{
		x_ts.x_data = x_ts.x_data + ( Int32 ) x_newData;
		return x_ts;
	}
	TestStruct operator &(TestStruct x_ts,Int32 x_newData)
	{
		x_ts.x_data = x_ts.x_data & ( Int32 ) x_newData;
		return x_ts;
	}
	TestStruct2::TestStruct2()
	{
	}
	TestStruct3::TestStruct3()
	{
	}
	AbstractRaw::AbstractRaw(Int32 x_i,Int32 x_j)
	{
		x_data1 = ( Int32 ) x_i;
		x_data2 = ( Int32 ) x_j;
	}
	Int32 AbstractRaw::DidImplement()
	{
		return x_data1;
	}
	BooleanTestRaw::BooleanTestRaw(CABlock x_caBlock)
	{
		this->x_caBlock.Assign(x_caBlock);
	}
	void BooleanTestRaw::Test()
	{
		x_caBlock->Send((new StringRaw("Doing BooleanTest")));
		x_caBlock->Send((new StringRaw("\tDoing RunBooleanTest")));
		RunBooleanTest();
		x_caBlock->Send((new StringRaw("\tDoing BoolOperators")));
		BoolOperators();
		x_caBlock->Send((new StringRaw("\tDoing BoolBoxTest")));
		BoolBoxTest();
	}
	void BooleanTestRaw::BoolBoxTest()
	{
		Boolean x_flag = true;
		Object x_obj = (new BooleanBox(x_flag ));
		CxAssert(x_flag.Equals(x_obj));
		CxAssert(x_obj->Equals(x_obj));
		CxAssert(( Boolean ) x_obj->get_AsBoolean());
		CxAssert((x_obj->ToString())->Equals((new StringRaw("True"))));
	}
	void BooleanTestRaw::RunBooleanTest()
	{
		Boolean x_flag = true;
		Object x_obj = (new BooleanBox(x_flag ));
		CxAssert(((Int32)(x_flag.CompareTo(true))).Equals((( Int32 ) 0)));
		CxAssert(((Int32)(x_flag.CompareTo(x_obj))).Equals((( Int32 ) 0)));
		CxAssert(x_flag.Equals(true));
		CxAssert(BooleanRaw::Parse((new StringRaw("True"))));
		CxAssert(((new StringRaw("True")))->Equals(x_flag.ToString()));
		CxAssert((Boolean::FalseString)->Equals((new StringRaw("False"))));
		CxAssert((Boolean::TrueString)->Equals((new StringRaw("True"))));
	}
	void BooleanTestRaw::BoolOperators()
	{
		Boolean x_flag = true;
		Boolean x_flag2 = false;
		CxAssert(x_flag && x_flag2,false);
		CxAssert(x_flag || x_flag2);
		CxAssert(x_flag ^ x_flag2);
		CxAssert(!x_flag,false);
		CxAssert(x_flag && x_flag2,false);
		CxAssert(x_flag || x_flag2);
		CxAssert((x_flag).Equals(x_flag2),false);
		CxAssert(!(x_flag).Equals(x_flag2));
	}
	void BooleanTestRaw::CxAssert(Boolean x_x,Boolean x_y)
	{
		if ( !(x_x).Equals(x_y) )
		{
			x_caBlock->TestFailed((new StringRaw("Boolean TestFailed")));
		}
	}
	void BooleanTestRaw::CxAssert(Boolean x_x)
	{
		if ( !x_x )
		{
			x_caBlock->TestFailed((new StringRaw("Boolean TestFailed")));
		}
	}
	ByteTestRaw::ByteTestRaw(CABlock x_caBlock)
	{
		this->x_caBlock.Assign(x_caBlock);
	}
	void ByteTestRaw::Test()
	{
		x_caBlock->Send((new StringRaw("Doing ByteTest")));
		x_caBlock->Send((new StringRaw("\tDoing ByteMethodsTest")));
		ByteMethodsTest();
		x_caBlock->Send((new StringRaw("\tDoing DoUnSignedMath")));
		DoUnSignedMath();
		x_caBlock->Send((new StringRaw("\tDoing ByteOperators")));
		ByteOperators();
		x_caBlock->Send((new StringRaw("\tDoing ByteArrayTests")));
		ByteArrayTests();
		x_caBlock->Send((new StringRaw("\tDoing ByteMiscTests")));
		ByteMiscTests();
	}
	void ByteTestRaw::ByteMethodsTest()
	{
		Byte x_b = (( Byte ) 5);
		CxAssert(((Int32)((( Byte ) x_b).CompareTo(5))).Equals((( Int32 ) 0)));
		CxAssert(((Int32)((( Byte ) x_b).CompareTo((new ByteBox((( Byte ) 5) ))))).Equals((( Int32 ) 0)));
		CxAssert((( Byte ) x_b).Equals(5));
		CxAssert((( Byte ) x_b).Equals((new ByteBox((( Byte ) 5) ))));
		CxAssert(((Byte)(ByteRaw::Parse((new StringRaw("77"))))).Equals((( Byte ) 77)));
		CxAssert(((new StringRaw("5")))->Equals((( Byte ) x_b).ToString()));
		x_b = ( Byte ) ((Byte)255);
		CxAssert(((Byte)(((Byte)255))).Equals(( Byte ) x_b));
		x_b = (( Byte ) 0);
		CxAssert(((Byte)(x_b)).Equals((( Byte ) 0)));
		String x_text = (( Byte ) ((Byte)255)).ToString();
		CxAssert((x_text)->Equals((new StringRaw("255"))));
		CxAssert(((Byte)(ByteRaw::Parse(x_text))).Equals(( Byte ) ((Byte)255)));
		String x_text2 = ( (( Byte ) 0) ).ToString();
		CxAssert((x_text2)->Equals((new StringRaw("0"))));
		CxAssert(((Byte)(ByteRaw::Parse(x_text2))).Equals((( Byte ) 0)));
		Object x_obj = (new ByteBox((( Byte ) 5) ));
		CxAssert(x_obj->Equals((( Byte ) 5)));
		CxAssert((x_obj->ToString())->Equals((new StringRaw("5"))));
	}
	void ByteTestRaw::DoUnSignedMath()
	{
		Byte x_b = (( Byte ) 60);
		Byte x_b2 = (( Byte ) 120);
		Byte x_b3 = (( Byte ) 6);
		Byte x_b4 = (( Byte ) 12);
		Int32 x_num = (( Int32 ) 1);
		CxAssert(1 <= ( Byte ) x_b);
		CxAssert(x_b >= (( Int32 ) 1));
		CxAssert(x_b >= ( Int32 ) x_num);
		CxAssert(x_num <= ( Byte ) x_b);
		x_num = x_num + ( Int32 ) x_b;
		CxAssert(((Int32)(x_num)).Equals((( Int32 ) 61)));
		CxAssert(((Int32)(x_b + ( Byte ) x_b2)).Equals((( Int32 ) 180)));
		Byte x_b5 = ( Byte ) ( Byte ) ( x_b - ( Byte ) x_b2 );
		CxAssert(((Byte)(x_b5)).Equals((( Byte ) 196)));
		CxAssert(((Byte)(( Byte ) ( x_b - ( Byte ) x_b2 ))).Equals((( Byte ) 196)));
		CxAssert(((Int32)(x_b3 * ( Byte ) x_b4)).Equals((( Int32 ) 72)));
		CxAssert(((Int32)(( Int32 ) x_b2 / ( Int32 ) ( Int32 ) x_b)).Equals((( Int32 ) 2)));
		CxAssert(((Int32)(x_b >> (( Int32 ) 2))).Equals((( Int32 ) 15)));
		CxAssert(((Int32)(x_b << (( Int32 ) 1))).Equals((( Int32 ) 120)));
		Int32 x_num2 = (( Int32 ) 11);
		CxAssert(((Int32)(x_num2 % (( Int32 ) 5))).Equals((( Int32 ) 1)));
		x_num2 = (( Int32 ) 8);
		CxAssert(( x_num2 | (( Int32 ) 1) ) == (( Int32 ) 9));
		CxAssert(( x_num2 & (( Int32 ) 1) ) == (( Int32 ) 0));
		CxAssert(((Int32)(++x_num2)).Equals((( Int32 ) 9)));
		CxAssert(((Int32)(--x_num2)).Equals((( Int32 ) 8)));
		CxAssert(( x_num2 = x_num2 * (( Int32 ) 2) ) == (( Int32 ) 16));
		CxAssert(( x_num2 = x_num2 / (( Int32 ) 2) ) == (( Int32 ) 8));
		CxAssert(( x_num2 = x_num2 % (( Int32 ) 2) ) == (( Int32 ) 0));
		CxAssert(( x_num2 = x_num2 | (( Int32 ) 4) ) == (( Int32 ) 4));
		CxAssert(( x_num2 = x_num2 & (( Int32 ) 4) ) == (( Int32 ) 4));
		CxAssert(((Int32)(-x_b)).Equals(( Int32 ) -60));
		CxAssert(((Byte)(x_b)).Equals((( Byte ) 60)));
		Byte x_b6 = (( Byte ) 0);
		CxAssert(((Byte)(( Byte ) ( ~x_b6 ))).Equals(( Byte ) ((Byte)255)));
		CxAssert(( x_b6 = ( Byte ) ( Byte ) ( x_b6 + (( Int32 ) 1) ) ) == (( Int32 ) 1));
		CxAssert(( x_b6 = ( Byte ) ( Byte ) ( x_b6 - (( Int32 ) 1) ) ) == (( Int32 ) 0));
	}
	void ByteTestRaw::ByteOperators()
	{
		Byte x_b = (( Byte ) 66);
		Char x_c = ( Char ) '';
		Byte x_b2 = (( Byte ) 1);
		SByte x_b3 = (( SByte ) 1);
		Int16 x_num = (( Int16 ) 1);
		Int32 x_num2 = (( Int32 ) 1);
		Int64 x_num3 = (( Int64 ) 1);
		UInt16 x_num4 = (( UInt16 ) 1);
		UInt32 x_num5 = (( UInt32 ) 1);
		UInt64 x_num6 = (( UInt64 ) 1);
		Float x_num7 = (( Single ) 1);
		Double x_num8 = (( Double ) 1);
		CxAssert(((Byte)(x_b)).Equals((( Byte ) 66)));
		CxAssert(((Int32)(x_b + ( Char ) x_c)).Equals((( Int32 ) 67)));
		CxAssert(((Int32)(x_b + ( Byte ) x_b2)).Equals((( Int32 ) 67)));
		CxAssert(((Int32)(x_b + ( SByte ) x_b3)).Equals((( Int32 ) 67)));
		CxAssert(((Int32)(x_b + ( Int16 ) x_num)).Equals((( Int32 ) 67)));
		CxAssert(((Int32)(x_b + ( Int32 ) x_num2)).Equals((( Int32 ) 67)));
		CxAssert(((Int64)(x_b + ( Int64 ) x_num3)).Equals((( Int64 ) 67)));
		CxAssert(((Int32)(x_b + ( UInt16 ) x_num4)).Equals((( Int32 ) 67)));
		CxAssert(((UInt32)(x_b + ( UInt32 ) x_num5)).Equals((( UInt32 ) 67)));
		CxAssert(((UInt64)(x_b + ( UInt64 ) x_num6)).Equals((( UInt64 ) 67)));
		CxAssert(((Single)(( Single ) ( Int32 ) x_b + ( Single ) x_num7)).Equals((( Single ) 67)));
		CxAssert(((Double)(( Double ) ( Int32 ) x_b + ( Double ) x_num8)).Equals((( Double ) 67)));
		CxAssert(((Int32)(x_b - ( Char ) x_c)).Equals((( Int32 ) 65)));
		CxAssert(((Int32)(x_b - ( Byte ) x_b2)).Equals((( Int32 ) 65)));
		CxAssert(((Int32)(x_b - ( SByte ) x_b3)).Equals((( Int32 ) 65)));
		CxAssert(((Int32)(x_b - ( Int16 ) x_num)).Equals((( Int32 ) 65)));
		CxAssert(((Int32)(x_b - ( Int32 ) x_num2)).Equals((( Int32 ) 65)));
		CxAssert(((Int64)(x_b - ( Int64 ) x_num3)).Equals((( Int64 ) 65)));
		CxAssert(((Int32)(x_b - ( UInt16 ) x_num4)).Equals((( Int32 ) 65)));
		CxAssert(((UInt32)(x_b - ( UInt32 ) x_num5)).Equals((( UInt32 ) 65)));
		CxAssert(((UInt64)(x_b - ( UInt64 ) x_num6)).Equals((( UInt64 ) 65)));
		CxAssert(((Single)(( Single ) ( Int32 ) x_b - ( Single ) x_num7)).Equals((( Single ) 65)));
		CxAssert(((Double)(( Double ) ( Int32 ) x_b - ( Double ) x_num8)).Equals((( Double ) 65)));
		CxAssert(((Int32)(x_b * ( Char ) x_c)).Equals((( Int32 ) 66)));
		CxAssert(((Int32)(x_b * ( Byte ) x_b2)).Equals((( Int32 ) 66)));
		CxAssert(((Int32)(x_b * ( SByte ) x_b3)).Equals((( Int32 ) 66)));
		CxAssert(((Int32)(x_b * ( Int16 ) x_num)).Equals((( Int32 ) 66)));
		CxAssert(((Int32)(x_b * ( Int32 ) x_num2)).Equals((( Int32 ) 66)));
		CxAssert(((Int64)(x_b * ( Int64 ) x_num3)).Equals((( Int64 ) 66)));
		CxAssert(((Int32)(x_b * ( UInt16 ) x_num4)).Equals((( Int32 ) 66)));
		CxAssert(((UInt32)(x_b * ( UInt32 ) x_num5)).Equals((( UInt32 ) 66)));
		CxAssert(((UInt64)(x_b * ( UInt64 ) x_num6)).Equals((( UInt64 ) 66)));
		CxAssert(((Single)(( Single ) ( Int32 ) x_b * ( Single ) x_num7)).Equals((( Single ) 66)));
		CxAssert(((Double)(( Double ) ( Int32 ) x_b * ( Double ) x_num8)).Equals((( Double ) 66)));
		CxAssert(((Int32)(( Int32 ) x_b / ( Int32 ) ( Int32 ) x_c)).Equals((( Int32 ) 66)));
		CxAssert(((Int32)(( Int32 ) x_b / ( Int32 ) ( Int32 ) x_b2)).Equals((( Int32 ) 66)));
		CxAssert(((Int32)(( Int32 ) x_b / ( Int32 ) ( Int32 ) x_b3)).Equals((( Int32 ) 66)));
		CxAssert(((Int32)(( Int32 ) x_b / ( Int32 ) ( Int32 ) x_num)).Equals((( Int32 ) 66)));
		CxAssert(((Int32)(( Int32 ) x_b / ( Int32 ) x_num2)).Equals((( Int32 ) 66)));
		CxAssert(((Int64)(( Int64 ) x_b / ( Int64 ) x_num3)).Equals((( Int64 ) 66)));
		CxAssert(((Int32)(( Int32 ) x_b / ( Int32 ) ( Int32 ) x_num4)).Equals((( Int32 ) 66)));
		CxAssert(((UInt32)(x_b / ( UInt32 ) x_num5)).Equals((( UInt32 ) 66)));
		CxAssert(((UInt64)(x_b / ( UInt64 ) x_num6)).Equals((( UInt64 ) 66)));
		CxAssert(((Single)(( Single ) ( Int32 ) x_b / ( Single ) x_num7)).Equals((( Single ) 66)));
		CxAssert(((Double)(( Double ) ( Int32 ) x_b / ( Double ) x_num8)).Equals((( Double ) 66)));
		CxAssert(((Int32)(( Int32 ) x_b % ( Int32 ) ( Int32 ) x_c)).Equals((( Int32 ) 0)));
		CxAssert(((Int32)(( Int32 ) x_b % ( Int32 ) ( Int32 ) x_b2)).Equals((( Int32 ) 0)));
		CxAssert(((Int32)(( Int32 ) x_b % ( Int32 ) ( Int32 ) x_b3)).Equals((( Int32 ) 0)));
		CxAssert(((Int32)(( Int32 ) x_b % ( Int32 ) ( Int32 ) x_num)).Equals((( Int32 ) 0)));
		CxAssert(((Int32)(( Int32 ) x_b % ( Int32 ) x_num2)).Equals((( Int32 ) 0)));
		CxAssert(((Int64)(( Int64 ) x_b % ( Int64 ) x_num3)).Equals((( Int64 ) 0)));
		CxAssert(((Int32)(( Int32 ) x_b % ( Int32 ) ( Int32 ) x_num4)).Equals((( Int32 ) 0)));
		CxAssert(((UInt32)(x_b % ( UInt32 ) x_num5)).Equals((( UInt32 ) 0)));
		CxAssert(((UInt64)(x_b % ( UInt64 ) x_num6)).Equals((( UInt64 ) 0)));
		CxAssert(((Single)(( Single ) ( Int32 ) x_b % ( Single ) x_num7)).Equals((( Single ) 0)));
		CxAssert(((Double)(( Double ) ( Int32 ) x_b % ( Double ) x_num8)).Equals((( Double ) 0)));
		CxAssert(( x_b & ( Char ) x_c ) == (( Int32 ) 0));
		CxAssert(( x_b & ( Byte ) x_b2 ) == (( Int32 ) 0));
		CxAssert(( x_b & ( SByte ) x_b3 ) == (( Int32 ) 0));
		CxAssert(( x_b & ( Int16 ) x_num ) == (( Int32 ) 0));
		CxAssert(( x_b & ( Int32 ) x_num2 ) == (( Int32 ) 0));
		CxAssert(( x_b & ( Int64 ) x_num3 ) == (( Int32 ) 0));
		CxAssert(( x_b & ( UInt16 ) x_num4 ) == (( Int32 ) 0));
		CxAssert(( x_b & ( UInt32 ) x_num5 ) == (( Int32 ) 0));
		CxAssert(( x_b & ( UInt64 ) x_num6 ) == (( Int32 ) 0));
		CxAssert(( x_b | ( Char ) x_c ) == (( Int32 ) 67));
		CxAssert(( x_b | ( Byte ) x_b2 ) == (( Int32 ) 67));
		CxAssert(( x_b | ( SByte ) x_b3 ) == (( Int32 ) 67));
		CxAssert(( x_b | ( Int16 ) x_num ) == (( Int32 ) 67));
		CxAssert(( x_b | ( Int32 ) x_num2 ) == (( Int32 ) 67));
		CxAssert(( x_b | ( Int64 ) x_num3 ) == (( Int32 ) 67));
		CxAssert(( x_b | ( UInt16 ) x_num4 ) == (( Int32 ) 67));
		CxAssert(( x_b | ( UInt32 ) x_num5 ) == (( Int32 ) 67));
		CxAssert(( x_b | ( UInt64 ) x_num6 ) == (( Int32 ) 67));
		CxAssert(( x_b ^ ( Char ) x_c ) == (( Int32 ) 67));
		CxAssert(( x_b ^ ( Byte ) x_b2 ) == (( Int32 ) 67));
		CxAssert(( x_b ^ ( SByte ) x_b3 ) == (( Int32 ) 67));
		CxAssert(( x_b ^ ( Int16 ) x_num ) == (( Int32 ) 67));
		CxAssert(( x_b ^ ( Int32 ) x_num2 ) == (( Int32 ) 67));
		CxAssert(( x_b ^ ( Int64 ) x_num3 ) == (( Int32 ) 67));
		CxAssert(( x_b ^ ( UInt16 ) x_num4 ) == (( Int32 ) 67));
		CxAssert(( x_b ^ ( UInt32 ) x_num5 ) == (( Int32 ) 67));
		CxAssert(( x_b ^ ( UInt64 ) x_num6 ) == (( Int32 ) 67));
		CxAssert(((Byte)(( Byte ) ( ~x_b ))).Equals((( Byte ) 189)));
		CxAssert(x_c < ( Byte ) x_b);
		CxAssert(x_b2 < ( Byte ) x_b);
		CxAssert(x_b3 < ( Byte ) x_b);
		CxAssert(x_num < ( Byte ) x_b);
		CxAssert(x_num2 < ( Byte ) x_b);
		CxAssert(x_num3 < ( Byte ) x_b);
		CxAssert(x_num4 < ( Byte ) x_b);
		CxAssert(x_num5 < ( Byte ) x_b);
		CxAssert(x_num6 < ( Byte ) x_b);
		CxAssert(x_num7 < ( Single ) ( Single ) ( Int32 ) x_b);
		CxAssert(x_num8 < ( Double ) ( Double ) ( Int32 ) x_b);
		CxAssert(x_c > ( Byte ) x_b,false);
		CxAssert(x_b2 > ( Byte ) x_b,false);
		CxAssert(x_b3 > ( Byte ) x_b,false);
		CxAssert(x_num > ( Byte ) x_b,false);
		CxAssert(x_num2 > ( Byte ) x_b,false);
		CxAssert(x_num3 > ( Byte ) x_b,false);
		CxAssert(x_num4 > ( Byte ) x_b,false);
		CxAssert(x_num5 > ( Byte ) x_b,false);
		CxAssert(x_num6 > ( Byte ) x_b,false);
		CxAssert(x_num7 > ( Single ) ( Single ) ( Int32 ) x_b,false);
		CxAssert(x_num8 > ( Double ) ( Double ) ( Int32 ) x_b,false);
		CxAssert(( x_b = ( Byte ) ( Byte ) ( x_b + (( Int32 ) 1) ) ) == (( Int32 ) 67));
		CxAssert(( x_b = ( Byte ) ( Byte ) ( x_b - (( Int32 ) 1) ) ) == (( Int32 ) 66));
		CxAssert(((Byte)(x_b++)).Equals((( Byte ) 66)));
		CxAssert(((Byte)(x_b--)).Equals((( Byte ) 67)));
		CxAssert(((Int32)(x_b << (( Int32 ) 1))).Equals((( Int32 ) 132)));
		CxAssert(((Int32)(x_b >> (( Int32 ) 1))).Equals((( Int32 ) 33)));
		CxAssert(((Char)(x_c)).Equals(( Char ) x_b),false);
		CxAssert(((Byte)(x_b2)).Equals(( Byte ) x_b),false);
		CxAssert(((SByte)(x_b3)).Equals(( SByte ) x_b),false);
		CxAssert(((Int16)(x_num)).Equals(( Int16 ) x_b),false);
		CxAssert(((Int32)(x_num2)).Equals(( Int32 ) x_b),false);
		CxAssert(((Int64)(x_num3)).Equals(( Int64 ) x_b),false);
		CxAssert(((UInt16)(x_num4)).Equals(( UInt16 ) x_b),false);
		CxAssert(((UInt32)(x_num5)).Equals(( UInt32 ) x_b),false);
		CxAssert(((UInt64)(x_num6)).Equals(( UInt64 ) x_b),false);
		CxAssert(((Single)(x_num7)).Equals(( Single ) ( Single ) ( Int32 ) x_b),false);
		CxAssert(((Double)(x_num8)).Equals(( Double ) ( Double ) ( Int32 ) x_b),false);
		CxAssert(!((Char)(x_c)).Equals(( Char ) x_b));
		CxAssert(!((Byte)(x_b2)).Equals(( Byte ) x_b));
		CxAssert(!((SByte)(x_b3)).Equals(( SByte ) x_b));
		CxAssert(!((Int16)(x_num)).Equals(( Int16 ) x_b));
		CxAssert(!((Int32)(x_num2)).Equals(( Int32 ) x_b));
		CxAssert(!((Int64)(x_num3)).Equals(( Int64 ) x_b));
		CxAssert(!((UInt16)(x_num4)).Equals(( UInt16 ) x_b));
		CxAssert(!((UInt32)(x_num5)).Equals(( UInt32 ) x_b));
		CxAssert(!((UInt64)(x_num6)).Equals(( UInt64 ) x_b));
		CxAssert(!((Single)(x_num7)).Equals(( Single ) ( Single ) ( Int32 ) x_b));
		CxAssert(!((Double)(x_num8)).Equals(( Double ) ( Double ) ( Int32 ) x_b));
		CxAssert(x_c <= ( Byte ) x_b);
		CxAssert(x_b2 <= ( Byte ) x_b);
		CxAssert(x_b3 <= ( Byte ) x_b);
		CxAssert(x_num <= ( Byte ) x_b);
		CxAssert(x_num2 <= ( Byte ) x_b);
		CxAssert(x_num3 <= ( Byte ) x_b);
		CxAssert(x_num4 <= ( Byte ) x_b);
		CxAssert(x_num5 <= ( Byte ) x_b);
		CxAssert(x_num6 <= ( Byte ) x_b);
		CxAssert(x_num7 <= ( Single ) ( Single ) ( Int32 ) x_b);
		CxAssert(x_num8 <= ( Double ) ( Double ) ( Int32 ) x_b);
		CxAssert(x_c >= ( Byte ) x_b,false);
		CxAssert(x_b2 >= ( Byte ) x_b,false);
		CxAssert(x_b3 >= ( Byte ) x_b,false);
		CxAssert(x_num >= ( Byte ) x_b,false);
		CxAssert(x_num2 >= ( Byte ) x_b,false);
		CxAssert(x_num3 >= ( Byte ) x_b,false);
		CxAssert(x_num4 >= ( Byte ) x_b,false);
		CxAssert(x_num5 >= ( Byte ) x_b,false);
		CxAssert(x_num6 >= ( Byte ) x_b,false);
		CxAssert(x_num7 >= ( Single ) ( Single ) ( Int32 ) x_b,false);
		CxAssert(x_num8 >= ( Double ) ( Double ) ( Int32 ) x_b,false);
		CxAssert(( x_b = ( Byte ) ( Byte ) ( x_b + ( Byte ) ( Byte ) x_c ) ) == (( Int32 ) 67));
		CxAssert(( x_b = ( Byte ) ( Byte ) ( x_b - ( Byte ) ( Byte ) x_c ) ) == (( Int32 ) 66));
		CxAssert(( x_b = ( Byte ) ( Byte ) ( x_b + ( Byte ) ( Byte ) x_num5 ) ) == (( Int32 ) 67));
		CxAssert(( x_b = ( Byte ) ( Byte ) ( x_b - ( Byte ) ( Byte ) x_num5 ) ) == (( Int32 ) 66));
		CxAssert(( x_b = ( Byte ) ( Byte ) ( x_b * ( Byte ) ( Byte ) x_c ) ) == (( Int32 ) 66));
		CxAssert(( x_b = ( Byte ) ( Byte ) ( ( Int32 ) x_b / ( Int32 ) ( Int32 ) ( Byte ) x_c ) ) == (( Int32 ) 66));
		CxAssert(( x_b = ( Byte ) ( Byte ) ( x_b * ( Byte ) ( Byte ) x_num5 ) ) == (( Int32 ) 66));
		CxAssert(( x_b = ( Byte ) ( Byte ) ( ( Int32 ) x_b / ( Int32 ) ( Int32 ) ( Byte ) x_num5 ) ) == (( Int32 ) 66));
		CxAssert(( x_b = ( Byte ) ( Byte ) ( ( Int32 ) x_b % ( Int32 ) ( Int32 ) ( Byte ) x_c ) ) == (( Int32 ) 0));
		x_b = (( Byte ) 66);
		CxAssert(( x_b = ( Byte ) ( Byte ) ( ( Int32 ) x_b % ( Int32 ) ( Int32 ) ( Byte ) x_num5 ) ) == (( Int32 ) 0));
		x_b = (( Byte ) 66);
		CxAssert(( x_b = ( Byte ) ( Byte ) ( x_b & ( Byte ) ( Byte ) x_c ) ) == (( Int32 ) 0));
		x_b = (( Byte ) 66);
		CxAssert(( x_b = ( Byte ) ( Byte ) ( x_b & ( Byte ) ( Byte ) x_num5 ) ) == (( Int32 ) 0));
		x_b = (( Byte ) 66);
		CxAssert(( x_b = ( Byte ) ( Byte ) ( x_b | ( Byte ) ( Byte ) x_c ) ) == (( Int32 ) 67));
		x_b = (( Byte ) 66);
		CxAssert(( x_b = ( Byte ) ( Byte ) ( x_b | ( Byte ) ( Byte ) x_num5 ) ) == (( Int32 ) 67));
		x_b = (( Byte ) 66);
		CxAssert(( x_b = ( Byte ) ( Byte ) ( x_b ^ ( Byte ) ( Byte ) x_c ) ) == (( Int32 ) 67));
		x_b = (( Byte ) 66);
		CxAssert(( x_b = ( Byte ) ( Byte ) ( x_b ^ ( Byte ) ( Byte ) x_num5 ) ) == (( Int32 ) 67));
		x_b = (( Byte ) 66);
		CxAssert(( x_b = ( Byte ) ( Byte ) ( x_b << ( Int32 ) ( Int32 ) x_c ) ) == (( Int32 ) 132));
		x_b = (( Byte ) 66);
		CxAssert(( x_b = ( Byte ) ( Byte ) ( x_b << ( Int32 ) x_num2 ) ) == (( Int32 ) 132));
		x_b = (( Byte ) 66);
		CxAssert(( x_b = ( Byte ) ( Byte ) ( x_b >> ( Int32 ) ( Int32 ) x_c ) ) == (( Int32 ) 33));
		x_b = (( Byte ) 66);
		CxAssert(( x_b = ( Byte ) ( Byte ) ( x_b >> ( Int32 ) x_num2 ) ) == (( Int32 ) 33));
		x_b = (( Byte ) 66);
		Char x_c2 = ( Char ) 'B';
		CxAssert(( x_c2 = ( Char ) ( Char ) ( ( UInt32 ) x_c2 << ( Int32 ) ( Int32 ) x_c ) ) == ( Char ) '');
	}
	void ByteTestRaw::ByteArrayTests()
	{
		static Byte ByteArrayTestsArray0[5] = {1,2,3,4,5};
		static Byte ByteArrayTestsArray1[4] = {1,2,3,4};
		static Byte ByteArrayTestsArray2[2][4] = {{1,2,3,4},{4,5,6,7}};
		static Byte ByteArrayTestsArray3[2][2][4] = {{{1,2,3,4},{5,6,7,8}},{{9,10,11,12},{13,14,15,16}}};
		PointerType<ArrayRaw<Byte>> x_array = (new ArrayRaw<Byte>(10));
		PointerType<ArrayRaw<Byte>> x_array2 = (new ArrayRaw<Byte>(10));
		for ( Int32 x_i = (( Int32 ) 0) ;  x_i < (( Int32 ) 10) ;   x_i++ )
		{
			(*x_array->Address(x_i)) = ( Byte ) ( Byte ) x_i;
		}
		for ( Int32 x_j = (( Int32 ) 0) ;  x_j < (( Int32 ) 10) ;   x_j++ )
		{
			(*x_array2->Address(x_j)) = ( Byte ) (*x_array->Address(x_j));
		}
		CxAssert(((Byte)((*x_array2->Address(0)))).Equals((( Byte ) 0)));
		CxAssert(((Byte)((*x_array2->Address(9)))).Equals((( Byte ) 9)));
		for ( Int32 x_k = (( Int32 ) 0) ;  x_k < (( Int32 ) 10) ;   x_k++ )
		{
			(*x_array->Address(x_k)) = (( Byte ) 1);
		}
		PointerType<ArrayRaw<Int32>> x_array3 = (new ArrayRaw<Int32>(10));
		BufferRaw::BlockCopy(x_array,0,x_array3,0,10);
		BufferRaw::BlockCopy(x_array,0,x_array3,10,10);
		BufferRaw::BlockCopy(x_array,0,x_array3,20,10);
		BufferRaw::BlockCopy(x_array,0,x_array3,30,10);
		CxAssert(((Int32)((*x_array3->Address(0)))).Equals((( Int32 ) 16843009)));
		CxAssert(((Int32)((*x_array3->Address(9)))).Equals((( Int32 ) 16843009)));
		PointerType<ArrayRaw<Byte>> x_array4 = (new ArrayRaw<Byte>(5))->Initialize((Byte*) ByteArrayTestsArray0);
		CxAssert(((Int32)(x_array4->get_Length())).Equals((( Int32 ) 5)));
		CxAssert(((Byte)((*x_array4->Address(3)))).Equals((( Byte ) 4)));
		PointerType<ArrayRaw<Byte>> x_array5 = (new ArrayRaw<Byte>(4))->Initialize((Byte*) ByteArrayTestsArray1);
		CxAssert(((Byte)((*x_array5->Address(1)))).Equals((( Byte ) 2)));
		PointerType<ArrayRaw<Byte>> x_array6 = (new ArrayRaw<Byte>(2,4))->Initialize((Byte*) ByteArrayTestsArray2);
		CxAssert(((Byte)((*x_array6->Address(0,2)))).Equals((( Byte ) 3)));
		PointerType<ArrayRaw<Byte>> x_array7 = (new ArrayRaw<Byte>(2,2,4))->Initialize((Byte*) ByteArrayTestsArray3);
		CxAssert(((Byte)((*x_array7->Address(0,0,3)))).Equals((( Byte ) 4)));
		(*x_array7->Address(0,0,3)) = (( Byte ) 6);
		CxAssert(((Byte)((*x_array7->Address(0,0,3)))).Equals((( Byte ) 6)));
		x_array7->SetValue((( Byte ) 4),0,0,3);
		CxAssert(((Byte)((*x_array7->Address(0,0,3)))).Equals((( Byte ) 4)));
	}
	void ByteTestRaw::ByteMiscTests()
	{
		Byte x_b = (( Byte ) 0);
		Byte x_val = (( Byte ) 1);
		CxAssert(((Byte)(MathRaw::Max(x_b,x_val))).Equals((( Byte ) 1)));
		CxAssert(((Byte)(MathRaw::Min(x_b,x_val))).Equals((( Byte ) 0)));
		PointerType<StringBuilderRaw> x_stringBuilder = new StringBuilderRaw();
		x_stringBuilder->Append(x_b);
		CxAssert((x_stringBuilder->ToString())->Equals((new StringRaw("0"))));
		x_stringBuilder->Insert(1,x_b);
		CxAssert((x_stringBuilder->ToString())->Equals((new StringRaw("00"))));
	}
	void ByteTestRaw::CxAssert(Boolean x_x)
	{
		if ( !x_x )
		{
			x_caBlock->TestFailed((new StringRaw("Byte Test Failed")));
		}
	}
	void ByteTestRaw::CxAssert(Boolean x_x,Boolean x_y)
	{
		if ( !(x_x).Equals(x_y) )
		{
			x_caBlock->TestFailed((new StringRaw("Byte Test Failed")));
		}
	}
	CharTestRaw::CharTestRaw(CABlock x_caBlock)
	{
		this->x_caBlock.Assign(x_caBlock);
	}
	void CharTestRaw::Test()
	{
		x_caBlock->Send((new StringRaw("Doing CharTest")));
		x_caBlock->Send((new StringRaw("\tDoing CharMethodsTest")));
		CharMethodsTest();
		x_caBlock->Send((new StringRaw("\tDoing CharOperators")));
		CharOperators();
		x_caBlock->Send((new StringRaw("\tDoing CharArrayTest")));
		CharArrayTests();
		x_caBlock->Send((new StringRaw("\tDoing CharMiscTests")));
		CharMiscTests();
	}
	void CharTestRaw::CharMethodsTest()
	{
		String x_s = (new StringRaw("123aBc\t\n. "));
		Char x_c = ( Char ) 'A';
		CxAssert((( Char ) x_c).CompareTo('B') < (( Int32 ) 0));
		CxAssert((( Char ) x_c).Equals('A'));
		Double x_numericValue = ( Double ) CharRaw::GetNumericValue('5');
		CxAssert(((Double)(x_numericValue)).Equals((( Double ) 5)));
		x_numericValue = ( Double ) CharRaw::GetNumericValue(x_s,2);
		CxAssert(((Double)(x_numericValue)).Equals((( Double ) 3)));
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
		CxAssert(((Char)(CharRaw::ToLower('A'))).Equals(( Char ) 'a'));
		CxAssert(((Char)(CharRaw::ToUpper('a'))).Equals(( Char ) 'A'));
		CxAssert((new StringRaw("a"))->Equals((( Char ) 'a').ToString()));
		CxAssert((new StringRaw("a"))->Equals(CharRaw::ToString('a')));
		CxAssert((( Char ) 'a').Equals(CharRaw::Parse((new StringRaw("a")))));
		Object x_obj = (new CharBox(x_c ));
		CxAssert((( Char ) 'A').Equals(( Char ) x_obj->get_AsChar()));
		CxAssert((( Char ) 'A').Equals(x_obj));
		CxAssert(((Int32)((( Char ) 'A').CompareTo(x_obj))).Equals((( Int32 ) 0)));
		CxAssert((x_obj->ToString())->Equals((new StringRaw("A"))));
	}
	void CharTestRaw::CharOperators()
	{
		Char x_c = ( Char ) 'B';
		Char x_c2 = ( Char ) '';
		Int32 x_num = (( Int32 ) 1);
		UInt32 x_num2 = (( UInt32 ) 1);
		Int64 x_num3 = (( Int64 ) 1);
		Double x_num4 = (( Double ) 1);
		CxAssert(((Char)(x_c)).Equals(( Char ) 'B'));
		CxAssert(((Int32)(x_c + ( Char ) x_c2)).Equals((( Int32 ) 67)));
		CxAssert(((Int32)(x_c + ( Int32 ) x_num)).Equals((( Int32 ) 67)));
		CxAssert(((UInt32)(x_c + ( UInt32 ) x_num2)).Equals((( UInt32 ) 67)));
		CxAssert(((Int64)(x_c + ( Int64 ) x_num3)).Equals((( Int64 ) 67)));
		CxAssert(((Double)(( Double ) ( Int32 ) x_c + ( Double ) x_num4)).Equals((( Double ) 67)));
		CxAssert(((Int32)(x_c - ( Char ) x_c2)).Equals((( Int32 ) 65)));
		CxAssert(((Int32)(x_c - ( Int32 ) x_num)).Equals((( Int32 ) 65)));
		CxAssert(((UInt32)(x_c - ( UInt32 ) x_num2)).Equals((( UInt32 ) 65)));
		CxAssert(((Int64)(x_c - ( Int64 ) x_num3)).Equals((( Int64 ) 65)));
		CxAssert(((Double)(( Double ) ( Int32 ) x_c - ( Double ) x_num4)).Equals((( Double ) 65)));
		CxAssert(((Int32)(x_c * ( Char ) x_c2)).Equals((( Int32 ) 66)));
		CxAssert(((Int32)(x_c * ( Int32 ) x_num)).Equals((( Int32 ) 66)));
		CxAssert(((UInt32)(x_c * ( UInt32 ) x_num2)).Equals((( UInt32 ) 66)));
		CxAssert(((Int64)(x_c * ( Int64 ) x_num3)).Equals((( Int64 ) 66)));
		CxAssert(((Double)(( Double ) ( Int32 ) x_c * ( Double ) x_num4)).Equals((( Double ) 66)));
		CxAssert(((Int32)(( Int32 ) x_c / ( Int32 ) ( Int32 ) x_c2)).Equals((( Int32 ) 66)));
		CxAssert(((Int32)(( Int32 ) x_c / ( Int32 ) x_num)).Equals((( Int32 ) 66)));
		CxAssert(((UInt32)(x_c / ( UInt32 ) x_num2)).Equals((( UInt32 ) 66)));
		CxAssert(((Int64)(( Int64 ) x_c / ( Int64 ) x_num3)).Equals((( Int64 ) 66)));
		CxAssert(((Double)(( Double ) ( Int32 ) x_c / ( Double ) x_num4)).Equals((( Double ) 66)));
		CxAssert(((Int32)(( Int32 ) x_c % ( Int32 ) ( Int32 ) x_c2)).Equals((( Int32 ) 0)));
		CxAssert(((Int32)(( Int32 ) x_c % ( Int32 ) x_num)).Equals((( Int32 ) 0)));
		CxAssert(((UInt32)(x_c % ( UInt32 ) x_num2)).Equals((( UInt32 ) 0)));
		CxAssert(((Int64)(( Int64 ) x_c % ( Int64 ) x_num3)).Equals((( Int64 ) 0)));
		CxAssert(((Double)(( Double ) ( Int32 ) x_c % ( Double ) x_num4)).Equals((( Double ) 0)));
		CxAssert(( x_c & ( Char ) x_c2 ) == (( Int32 ) 0));
		CxAssert(( x_c & ( Int32 ) x_num ) == (( Int32 ) 0));
		CxAssert(( x_c & ( UInt32 ) x_num2 ) == (( Int32 ) 0));
		CxAssert(( x_c & ( Int64 ) x_num3 ) == (( Int32 ) 0));
		CxAssert(( x_c | ( Char ) x_c2 ) == (( Int32 ) 67));
		CxAssert(( x_c | ( Int32 ) x_num ) == (( Int32 ) 67));
		CxAssert(( x_c | ( UInt32 ) x_num2 ) == (( Int32 ) 67));
		CxAssert(( x_c | ( Int64 ) x_num3 ) == (( Int32 ) 67));
		CxAssert(( x_c ^ ( Char ) x_c2 ) == (( Int32 ) 67));
		CxAssert(( x_c ^ ( Int32 ) x_num ) == (( Int32 ) 67));
		CxAssert(( x_c ^ ( UInt32 ) x_num2 ) == (( Int32 ) 67));
		CxAssert(( x_c ^ ( Int64 ) x_num3 ) == (( Int32 ) 67));
		CxAssert(((UInt32)(~( UInt32 ) x_c)).Equals((( UInt32 ) 4294967229)));
		CxAssert(x_c2 < ( Char ) x_c);
		CxAssert(x_num < ( Char ) x_c);
		CxAssert(x_num2 < ( Char ) x_c);
		CxAssert(x_num3 < ( Char ) x_c);
		CxAssert(x_num4 < ( Double ) ( Double ) ( Int32 ) x_c);
		CxAssert(x_c2 > ( Char ) x_c,false);
		CxAssert(x_num > ( Char ) x_c,false);
		CxAssert(x_num2 > ( Char ) x_c,false);
		CxAssert(x_num3 > ( Char ) x_c,false);
		CxAssert(x_num4 > ( Double ) ( Double ) ( Int32 ) x_c,false);
		CxAssert(( x_c = ( Char ) ( Char ) ( x_c + (( Int32 ) 1) ) ) == ( Char ) 'C');
		CxAssert(( x_c = ( Char ) ( Char ) ( x_c - (( Int32 ) 1) ) ) == ( Char ) 'B');
		CxAssert(((Char)(x_c++)).Equals(( Char ) 'B'));
		CxAssert(((Char)(x_c--)).Equals(( Char ) 'C'));
		CxAssert(((UInt32)(( UInt32 ) x_c << (( Int32 ) 1))).Equals((( UInt32 ) 132)));
		CxAssert(((Int32)(( Int32 ) x_c >> (( Int32 ) 1))).Equals((( Int32 ) 33)));
		CxAssert(((Char)(x_c2)).Equals(( Char ) x_c),false);
		CxAssert(((Int32)(x_num)).Equals(( Int32 ) x_c),false);
		CxAssert(((UInt32)(x_num2)).Equals(( UInt32 ) x_c),false);
		CxAssert(((Int64)(x_num3)).Equals(( Int64 ) x_c),false);
		CxAssert(((Double)(x_num4)).Equals(( Double ) ( Double ) ( Int32 ) x_c),false);
		CxAssert(!((Char)(x_c2)).Equals(( Char ) x_c));
		CxAssert(!((Int32)(x_num)).Equals(( Int32 ) x_c));
		CxAssert(!((UInt32)(x_num2)).Equals(( UInt32 ) x_c));
		CxAssert(!((Int64)(x_num3)).Equals(( Int64 ) x_c));
		CxAssert(!((Double)(x_num4)).Equals(( Double ) ( Double ) ( Int32 ) x_c));
		CxAssert(x_c2 <= ( Char ) x_c);
		CxAssert(x_num <= ( Char ) x_c);
		CxAssert(x_num2 <= ( Char ) x_c);
		CxAssert(x_num3 <= ( Char ) x_c);
		CxAssert(x_num4 <= ( Double ) ( Double ) ( Int32 ) x_c);
		CxAssert(x_c2 >= ( Char ) x_c,false);
		CxAssert(x_num >= ( Char ) x_c,false);
		CxAssert(x_num2 >= ( Char ) x_c,false);
		CxAssert(x_num3 >= ( Char ) x_c,false);
		CxAssert(x_num4 >= ( Double ) ( Double ) ( Int32 ) x_c,false);
		CxAssert(( x_c = ( Char ) ( Char ) ( x_c + ( Char ) x_c2 ) ) == ( Char ) 'C');
		CxAssert(( x_c = ( Char ) ( Char ) ( x_c - ( Char ) x_c2 ) ) == ( Char ) 'B');
		CxAssert(( x_c = ( Char ) ( Char ) ( x_c * ( Char ) x_c2 ) ) == ( Char ) 'B');
		CxAssert(( x_c = ( Char ) ( Char ) ( ( Int32 ) x_c / ( Int32 ) ( Int32 ) x_c2 ) ) == ( Char ) 'B');
		CxAssert(( x_c = ( Char ) ( Char ) ( ( Int32 ) x_c % ( Int32 ) ( Int32 ) x_c2 ) ) == ( Char ) ' ');
		x_c = ( Char ) 'B';
		CxAssert(( x_c = ( Char ) ( Char ) ( x_c & ( Char ) x_c2 ) ) == ( Char ) ' ');
		x_c = ( Char ) 'B';
		CxAssert(( x_c = ( Char ) ( Char ) ( x_c & ( Char ) x_c2 ) ) == ( Char ) ' ');
		x_c = ( Char ) 'B';
		CxAssert(( x_c = ( Char ) ( Char ) ( x_c | ( Char ) x_c2 ) ) == ( Char ) 'C');
		x_c = ( Char ) 'B';
		CxAssert(( x_c = ( Char ) ( Char ) ( x_c ^ ( Char ) x_c2 ) ) == ( Char ) 'C');
		x_c = ( Char ) 'B';
		CxAssert(( x_c = ( Char ) ( Char ) ( ( UInt32 ) x_c << (( Int32 ) 1) ) ) == ( Char ) '');
		x_c = ( Char ) 'B';
		CxAssert(( x_c = ( Char ) ( Char ) ( ( Int32 ) x_c >> (( Int32 ) 1) ) ) == ( Char ) '!');
	}
	void CharTestRaw::CharArrayTests()
	{
		static Char CharArrayTestsArray0[5] = {'1','2','3','4','5'};
		static Char CharArrayTestsArray1[4] = {'1','2','3','4'};
		static Char CharArrayTestsArray2[2][4] = {{'1','2','3','4'},{'4','5','6','7'}};
		static Char CharArrayTestsArray3[2][2][4] = {{{'1','2','3','4'},{'5','6','7','8'}},{{'9','A','B','C'},{'D','E','F','G'}}};
		PointerType<ArrayRaw<Char>> x_array = (new ArrayRaw<Char>(5))->Initialize((Char*) CharArrayTestsArray0);
		CxAssert(((Int32)(x_array->get_Length())).Equals((( Int32 ) 5)));
		CxAssert(((Char)((*x_array->Address(3)))).Equals(( Char ) '4'));
		PointerType<ArrayRaw<Char>> x_array2 = (new ArrayRaw<Char>(4))->Initialize((Char*) CharArrayTestsArray1);
		CxAssert(((Char)((*x_array2->Address(1)))).Equals(( Char ) '2'));
		PointerType<ArrayRaw<Char>> x_array3 = (new ArrayRaw<Char>(2,4))->Initialize((Char*) CharArrayTestsArray2);
		CxAssert(((Char)((*x_array3->Address(0,2)))).Equals(( Char ) '3'));
		PointerType<ArrayRaw<Char>> x_array4 = (new ArrayRaw<Char>(2,2,4))->Initialize((Char*) CharArrayTestsArray3);
		CxAssert(((Char)((*x_array4->Address(0,0,3)))).Equals(( Char ) '4'));
		(*x_array4->Address(0,0,3)) = ( Char ) '6';
		CxAssert(((Char)((*x_array4->Address(0,0,3)))).Equals(( Char ) '6'));
		x_array4->SetValue('4',0,0,3);
		CxAssert(((Char)((*x_array4->Address(0,0,3)))).Equals(( Char ) '4'));
	}
	void CharTestRaw::CharMiscTests()
	{
		Char x_c = ( Char ) '0';
		Char x_val = ( Char ) '1';
		CxAssert(((UInt16)(MathRaw::Max(x_c,x_val))).Equals((( UInt16 ) 49)));
		CxAssert(((UInt16)(MathRaw::Min(x_c,x_val))).Equals((( UInt16 ) 48)));
		PointerType<StringBuilderRaw> x_stringBuilder = new StringBuilderRaw();
		x_stringBuilder->Append(x_c);
		CxAssert((x_stringBuilder->ToString())->Equals((new StringRaw("0"))));
	}
	void CharTestRaw::CxAssert(Boolean x_x)
	{
		if ( !x_x )
		{
			x_caBlock->TestFailed((new StringRaw("Char TestFailed")));
		}
	}
	void CharTestRaw::CxAssert(Boolean x_x,Boolean x_y)
	{
		if ( !(x_x).Equals(x_y) )
		{
			x_caBlock->TestFailed((new StringRaw("Char TestFailed")));
		}
	}
	DoubleTestRaw::DoubleTestRaw(CABlock x_caBlock)
	{
		this->x_caBlock.Assign(x_caBlock);
	}
	void DoubleTestRaw::Test()
	{
		x_caBlock->Send((new StringRaw("Doing DoubleTest")));
		x_caBlock->Send((new StringRaw("\tDoing DoDoubleMethodsTest")));
		DoDoubleMethodsTest();
		x_caBlock->Send((new StringRaw("\tDoing DoDoubleMath")));
		DoDoubleMath();
		x_caBlock->Send((new StringRaw("\tDoing DoubleOperators")));
		DoubleOperators();
		x_caBlock->Send((new StringRaw("\tDoing DoubleNanTest")));
		DoubleNanTest();
		x_caBlock->Send((new StringRaw("\tDoing DoubleArrayTest")));
		DoubleArrayTest();
		x_caBlock->Send((new StringRaw("\tDoing DoubleMiscTests")));
		DoubleMiscTests();
	}
	void DoubleTestRaw::DoDoubleMethodsTest()
	{
		Double x_num = (( Double ) 3.159);
		CxAssert(((Int32)((( Double ) x_num).CompareTo(3.159))).Equals((( Int32 ) 0)));
		CxAssert(((Int32)((( Double ) x_num).CompareTo((new DoubleBox(3.159 ))))).Equals((( Int32 ) 0)));
		CxAssert((( Double ) x_num).Equals(3.159));
		CxAssert(((Double)(DoubleRaw::Parse((new StringRaw("3.159"))))).Equals((( Double ) 3.159)));
		CxAssert(((( Double ) x_num).ToString())->Equals((new StringRaw("3.159"))));
		String x_text = (( Double ) ((Double)-1.79769313486232E+308)).ToString();
		CxAssert(x_text->StartsWith((new StringRaw("-1.7976"))) && x_text->EndsWith((new StringRaw("E+308"))));
		x_num = (( Double ) 1000000000001);
		CxAssert(x_num > (( Double ) 1000000000000));
		x_num = ( Double ) -1000000000000;
		CxAssert(x_num <= ( Double ) -1000000000000);
		x_num = (( Double ) 10000);
		CxAssert(((Int64)(( Int64 ) x_num)).Equals((( Int64 ) 10000)));
		CxAssert(((Int32)(( Int32 ) x_num)).Equals((( Int32 ) 10000)));
		CxAssert(((UInt32)(( UInt32 ) x_num)).Equals((( UInt32 ) 10000)));
		Object x_obj = (new DoubleBox(x_num ));
		CxAssert(((Double)(( Double ) x_obj->get_AsDouble())).Equals((( Double ) 10000)));
		x_num = ( Double ) Double::Epsilon;
		CxAssert(((Double)(x_num)).Equals(( Double ) Double::Epsilon));
		x_num = ( Double ) ((Double)1.79769313486232E+308);
		CxAssert(((Double)(x_num)).Equals(( Double ) ((Double)1.79769313486232E+308)));
		x_num = ( Double ) ((Double)-1.79769313486232E+308);
		CxAssert(((Double)(x_num)).Equals(( Double ) ((Double)-1.79769313486232E+308)));
		x_obj.Assign(5);
		CxAssert(x_obj->Equals(5));
		CxAssert((x_obj->ToString())->Equals((new StringRaw("5"))));
	}
	void DoubleTestRaw::DoDoubleMath()
	{
		Double x_num = (( Double ) 355);
		Double x_num2 = (( Double ) 113);
		Double x_num3 = ( Double ) x_num / ( Double ) x_num2;
		CxAssert(x_num3,3.14159);
		CxAssert(x_num3 * ( Double ) x_num2,355);
		CxAssert(x_num + ( Double ) x_num2,468);
		CxAssert(x_num - ( Double ) x_num2,242);
		x_num = (( Double ) 2);
		x_num2 = ( Double ) x_num + ( Double ) Double::Epsilon;
		CxAssert(((Double)(x_num2)).Equals((( Double ) 2)));
		x_num = (( Double ) 2);
		x_num2 = ( Double ) x_num + (( Double ) 4.94065645841247E-24);
		CxAssert(((Double)(x_num2)).Equals((( Double ) 2)));
	}
	void DoubleTestRaw::DoubleOperators()
	{
		Double x_num = (( Double ) 66);
		Char x_c = ( Char ) '';
		Int32 x_num2 = (( Int32 ) 1);
		UInt32 x_num3 = (( UInt32 ) 1);
		Int64 x_num4 = (( Int64 ) 1);
		Double x_num5 = (( Double ) 1);
		CxAssert(((Double)(x_num)).Equals((( Double ) 66)));
		CxAssert(((Double)(x_num + ( Double ) ( Double ) ( Int32 ) x_c)).Equals((( Double ) 67)));
		CxAssert(((Double)(x_num + ( Double ) ( Double ) x_num2)).Equals((( Double ) 67)));
		CxAssert(((Double)(x_num + ( Double ) ( Double ) x_num3)).Equals((( Double ) 67)));
		CxAssert(((Double)(x_num + ( Double ) ( Double ) x_num4)).Equals((( Double ) 67)));
		CxAssert(((Double)(x_num + ( Double ) x_num5)).Equals((( Double ) 67)));
		CxAssert(((Double)(x_num - ( Double ) ( Double ) ( Int32 ) x_c)).Equals((( Double ) 65)));
		CxAssert(((Double)(x_num - ( Double ) ( Double ) x_num2)).Equals((( Double ) 65)));
		CxAssert(((Double)(x_num - ( Double ) ( Double ) x_num3)).Equals((( Double ) 65)));
		CxAssert(((Double)(x_num - ( Double ) ( Double ) x_num4)).Equals((( Double ) 65)));
		CxAssert(((Double)(x_num - ( Double ) x_num5)).Equals((( Double ) 65)));
		CxAssert(((Double)(x_num * ( Double ) ( Double ) ( Int32 ) x_c)).Equals((( Double ) 66)));
		CxAssert(((Double)(x_num * ( Double ) ( Double ) x_num2)).Equals((( Double ) 66)));
		CxAssert(((Double)(x_num * ( Double ) ( Double ) x_num3)).Equals((( Double ) 66)));
		CxAssert(((Double)(x_num * ( Double ) ( Double ) x_num4)).Equals((( Double ) 66)));
		CxAssert(((Double)(x_num * ( Double ) x_num5)).Equals((( Double ) 66)));
		CxAssert(((Double)(x_num / ( Double ) ( Double ) ( Int32 ) x_c)).Equals((( Double ) 66)));
		CxAssert(((Double)(x_num / ( Double ) ( Double ) x_num2)).Equals((( Double ) 66)));
		CxAssert(((Double)(x_num / ( Double ) ( Double ) x_num3)).Equals((( Double ) 66)));
		CxAssert(((Double)(x_num / ( Double ) ( Double ) x_num4)).Equals((( Double ) 66)));
		CxAssert(((Double)(x_num / ( Double ) x_num5)).Equals((( Double ) 66)));
		CxAssert(((Double)(x_num % ( Double ) ( Double ) ( Int32 ) x_c)).Equals((( Double ) 0)));
		CxAssert(((Double)(x_num % ( Double ) ( Double ) x_num2)).Equals((( Double ) 0)));
		CxAssert(((Double)(x_num % ( Double ) ( Double ) x_num3)).Equals((( Double ) 0)));
		CxAssert(((Double)(x_num % ( Double ) ( Double ) x_num4)).Equals((( Double ) 0)));
		CxAssert(((Double)(x_num % ( Double ) x_num5)).Equals((( Double ) 0)));
		CxAssert(( Double ) ( Int32 ) x_c < ( Double ) x_num);
		CxAssert(( Double ) x_num2 < ( Double ) x_num);
		CxAssert(( Double ) x_num3 < ( Double ) x_num);
		CxAssert(( Double ) x_num4 < ( Double ) x_num);
		CxAssert(x_num5 < ( Double ) x_num);
		CxAssert(( Double ) ( Int32 ) x_c > ( Double ) x_num,false);
		CxAssert(( Double ) x_num2 > ( Double ) x_num,false);
		CxAssert(( Double ) x_num3 > ( Double ) x_num,false);
		CxAssert(( Double ) x_num4 > ( Double ) x_num,false);
		CxAssert(x_num5 > ( Double ) x_num,false);
		CxAssert(( x_num = x_num + (( Double ) 1) ) == (( Double ) 67));
		CxAssert(( x_num = x_num - (( Double ) 1) ) == (( Double ) 66));
		CxAssert(((Double)(x_num++)).Equals((( Double ) 66)));
		CxAssert(((Double)(x_num--)).Equals((( Double ) 67)));
		CxAssert(((Double)(( Double ) ( Int32 ) x_c)).Equals(( Double ) x_num),false);
		CxAssert(((Double)(( Double ) x_num2)).Equals(( Double ) x_num),false);
		CxAssert(((Double)(( Double ) x_num3)).Equals(( Double ) x_num),false);
		CxAssert(((Double)(( Double ) x_num4)).Equals(( Double ) x_num),false);
		CxAssert(((Double)(x_num5)).Equals(( Double ) x_num),false);
		CxAssert(!((Double)(( Double ) ( Int32 ) x_c)).Equals(( Double ) x_num));
		CxAssert(!((Double)(( Double ) x_num2)).Equals(( Double ) x_num));
		CxAssert(!((Double)(( Double ) x_num3)).Equals(( Double ) x_num));
		CxAssert(!((Double)(( Double ) x_num4)).Equals(( Double ) x_num));
		CxAssert(!((Double)(x_num5)).Equals(( Double ) x_num));
		CxAssert(( Double ) ( Int32 ) x_c <= ( Double ) x_num);
		CxAssert(( Double ) x_num2 <= ( Double ) x_num);
		CxAssert(( Double ) x_num3 <= ( Double ) x_num);
		CxAssert(( Double ) x_num4 <= ( Double ) x_num);
		CxAssert(x_num5 <= ( Double ) x_num);
		CxAssert(( Double ) ( Int32 ) x_c >= ( Double ) x_num,false);
		CxAssert(( Double ) x_num2 >= ( Double ) x_num,false);
		CxAssert(( Double ) x_num3 >= ( Double ) x_num,false);
		CxAssert(( Double ) x_num4 >= ( Double ) x_num,false);
		CxAssert(x_num5 >= ( Double ) x_num,false);
		CxAssert(( x_num = x_num + ( Double ) ( Double ) ( Int32 ) x_c ) == (( Double ) 67));
		CxAssert(( x_num = x_num - ( Double ) ( Double ) ( Int32 ) x_c ) == (( Double ) 66));
		CxAssert(( x_num = x_num + ( Double ) ( Double ) x_num2 ) == (( Double ) 67));
		CxAssert(( x_num = x_num - ( Double ) ( Double ) x_num2 ) == (( Double ) 66));
		CxAssert(( x_num = x_num + ( Double ) ( Double ) x_num3 ) == (( Double ) 67));
		CxAssert(( x_num = x_num - ( Double ) ( Double ) x_num3 ) == (( Double ) 66));
		CxAssert(( x_num = x_num + ( Double ) ( Double ) x_num4 ) == (( Double ) 67));
		CxAssert(( x_num = x_num - ( Double ) ( Double ) x_num4 ) == (( Double ) 66));
		CxAssert(( x_num = x_num * ( Double ) ( Double ) ( Int32 ) x_c ) == (( Double ) 66));
		CxAssert(( x_num = x_num / ( Double ) ( Double ) ( Int32 ) x_c ) == (( Double ) 66));
		CxAssert(( x_num = x_num * ( Double ) ( Double ) x_num2 ) == (( Double ) 66));
		CxAssert(( x_num = x_num / ( Double ) ( Double ) x_num2 ) == (( Double ) 66));
		CxAssert(( x_num = x_num * ( Double ) ( Double ) x_num3 ) == (( Double ) 66));
		CxAssert(( x_num = x_num / ( Double ) ( Double ) x_num3 ) == (( Double ) 66));
		CxAssert(( x_num = x_num * ( Double ) ( Double ) x_num4 ) == (( Double ) 66));
		CxAssert(( x_num = x_num / ( Double ) ( Double ) x_num4 ) == (( Double ) 66));
		CxAssert(( x_num = x_num % ( Double ) ( Double ) ( Int32 ) x_c ) == (( Double ) 0));
		x_num = (( Double ) 66);
		CxAssert(( x_num = x_num % ( Double ) ( Double ) x_num2 ) == (( Double ) 0));
		x_num = (( Double ) 5);
		CxAssert(x_num % (( Double ) 2.2),0.6);
	}
	void DoubleTestRaw::DoubleNanTest()
	{
		Double x_num = ( Double ) Double::NaN;
		Double x_num2 = (( Double ) 1);
		CxAssert(DoubleRaw::IsNaN(x_num));
		CxAssert(DoubleRaw::IsInfinity(Double::PositiveInfinity));
		CxAssert(DoubleRaw::IsNegativeInfinity(Double::NegativeInfinity));
		CxAssert(DoubleRaw::IsPositiveInfinity(Double::PositiveInfinity));
		CxAssert(DoubleRaw::IsNaN(x_num * ( Double ) x_num2));
		CxAssert(DoubleRaw::IsNaN(x_num / ( Double ) x_num2));
		CxAssert(DoubleRaw::IsNaN(x_num + ( Double ) x_num2));
		CxAssert(DoubleRaw::IsNaN(x_num - ( Double ) x_num2));
		CxAssert(DoubleRaw::IsNaN(x_num % ( Double ) x_num2));
		CxAssert(x_num < ( Double ) x_num2,false);
		CxAssert(x_num > ( Double ) x_num2,false);
		CxAssert(x_num <= ( Double ) x_num2,false);
		CxAssert(x_num >= ( Double ) x_num2,false);
		CxAssert(((Double)(x_num)).Equals(( Double ) x_num2),false);
		CxAssert(((Double)(x_num)).Equals(( Double ) x_num),false);
		CxAssert(x_num2 < ( Double ) x_num,false);
		CxAssert(x_num2 > ( Double ) x_num,false);
		CxAssert(x_num2 <= ( Double ) x_num,false);
		CxAssert(x_num2 >= ( Double ) x_num,false);
		CxAssert(!((Double)(x_num)).Equals(( Double ) x_num2));
		CxAssert(!((Double)(x_num)).Equals(( Double ) x_num));
		x_num = ( Double ) Double::NaN;
		x_num2 = ( Double ) Double::NaN;
		if ( ((Double)(x_num)).Equals(( Double ) x_num2) )
		{
			DoubleTestFailed();
		}
		else
		{
			CxAssert(true);
		}
		if ( ((Double)(x_num)).Equals(( Double ) x_num) )
		{
			DoubleTestFailed();
		}
		else
		{
			CxAssert(true);
		}
		if ( !((Double)(x_num)).Equals(( Double ) x_num2) )
		{
			CxAssert(true);
		}
		else
		{
			DoubleTestFailed();
		}
		if ( !((Double)(x_num)).Equals(( Double ) x_num) )
		{
			CxAssert(true);
		}
		else
		{
			DoubleTestFailed();
		}
		if ( x_num > ( Double ) x_num2 )
		{
			DoubleTestFailed();
		}
		else
		{
			CxAssert(true);
		}
		if ( x_num >= ( Double ) x_num2 )
		{
			DoubleTestFailed();
		}
		else
		{
			CxAssert(true);
		}
		if ( x_num < ( Double ) x_num2 )
		{
			DoubleTestFailed();
		}
		else
		{
			CxAssert(true);
		}
		if ( x_num <= ( Double ) x_num2 )
		{
			DoubleTestFailed();
		}
		else
		{
			CxAssert(true);
		}
		if ( ((Double)(x_num)).Equals((( Double ) 0)) )
		{
			DoubleTestFailed();
		}
		else
		{
			CxAssert(true);
		}
		CxAssert((( Double ) Double::NaN).Equals(Double::NaN));
	}
	void DoubleTestRaw::DoubleArrayTest()
	{
		static Double DoubleArrayTestArray0[4] = {1,2,3,4};
		static Double DoubleArrayTestArray1[2][4] = {{1,2,3,4},{4,5,6,7}};
		static Double DoubleArrayTestArray2[2][2][4] = {{{1,2,3,4},{5,6,7,8}},{{9,10,11,12},{13,14,15,16}}};
		PointerType<ArrayRaw<Double>> x_array = (new ArrayRaw<Double>(4))->Initialize((Double*) DoubleArrayTestArray0);
		CxAssert(((Double)((*x_array->Address(1)))).Equals((( Double ) 2)));
		PointerType<ArrayRaw<Double>> x_array2 = (new ArrayRaw<Double>(2,4))->Initialize((Double*) DoubleArrayTestArray1);
		CxAssert(((Double)((*x_array2->Address(0,2)))).Equals((( Double ) 3)));
		PointerType<ArrayRaw<Double>> x_array3 = (new ArrayRaw<Double>(2,2,4))->Initialize((Double*) DoubleArrayTestArray2);
		CxAssert(((Double)((*x_array3->Address(0,0,3)))).Equals((( Double ) 4)));
		(*x_array3->Address(0,0,3)) = (( Double ) 22);
		CxAssert(((Double)((*x_array3->Address(0,0,3)))).Equals((( Double ) 22)));
		(*x_array2->Address(0,2)) = ( Double ) Double::NaN;
		CxAssert(DoubleRaw::IsNaN((*x_array2->Address(0,2))));
		x_array3->SetValue(4,0,0,3);
		CxAssert(((Double)((*x_array3->Address(0,0,3)))).Equals((( Double ) 4)));
	}
	void DoubleTestRaw::DoubleMiscTests()
	{
		Double x_num = ( Double ) -1;
		Double x_val = (( Double ) 1);
		CxAssert(((Double)(MathRaw::Abs(x_num))).Equals((( Double ) 1)));
		CxAssert(((Double)(MathRaw::Max(x_num,x_val))).Equals((( Double ) 1)));
		CxAssert(((Double)(MathRaw::Min(x_num,x_val))).Equals(( Double ) -1));
		CxAssert(MathRaw::Sign(x_num) < (( Int32 ) 0));
		PointerType<StringBuilderRaw> x_stringBuilder = new StringBuilderRaw();
		x_stringBuilder->Append(x_num);
		CxAssert((x_stringBuilder->ToString())->Equals((new StringRaw("-1"))));
	}
	void DoubleTestRaw::DoubleCompare(Double x_n1,Double x_n2,Double x_resolution)
	{
		if ( MathRaw::Abs(x_n1 - ( Double ) x_n2) > ( Double ) x_resolution )
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
		if ( !(x_x).Equals(x_y) )
		{
			DoubleTestFailed();
		}
	}
	void DoubleTestRaw::DoubleTestFailed()
	{
		x_caBlock->TestFailed((new StringRaw("Double TestFailed")));
	}
	EncodingTestRaw::EncodingTestRaw(CABlock x_caBlock)
	{
		this->x_caBlock.Assign(x_caBlock);
	}
	void EncodingTestRaw::Test()
	{
		x_caBlock->Send((new StringRaw("Doing EncodingTest")));
		x_caBlock->Send((new StringRaw("\tDoing EncodingMethodsTest")));
		EncodingMethodsTest();
	}
	void EncodingTestRaw::EncodingMethodsTest()
	{
		static Byte EncodingMethodsTestArray0[7] = {84,101,115,116,63,63,63};
		String x_s = (new StringRaw("Test\u0394\u0396\u039f"));
		PointerType<ArrayRaw<Byte>> x_myCharsAsBytes = (new ArrayRaw<Byte>(7))->Initialize((Byte*) EncodingMethodsTestArray0);
		PointerType<EncodingRaw> x_aSCII = Encoding::get_ASCII();
		CxAssert(((Int32)(x_aSCII->GetByteCount(x_s))).Equals((( Int32 ) 7)));
		PointerType<ArrayRaw<Byte>> x_bytes = x_aSCII->GetBytes(x_s);
		CxAssert(CompareBytes(x_bytes,x_myCharsAsBytes));
		String x_string = x_aSCII->GetString(x_bytes);
		CxAssert((x_string)->Equals((new StringRaw("Test???"))));
		String x_s2 = (new StringRaw("123\u042e\u040b\u042f\u0403\u041c\u0422\u0464\u0460\u046a\u047a"));
		CxAssert(((Int32)(x_aSCII->GetByteCount(x_s2))).Equals((( Int32 ) 13)));
		PointerType<ArrayRaw<Byte>> x_bytes2 = x_aSCII->GetBytes(x_s2);
		String x_string2 = x_aSCII->GetString(x_bytes2);
		CxAssert((x_string2)->Equals((new StringRaw("123??????????"))));
	}
	Boolean EncodingTestRaw::CompareBytes(PointerType<ArrayRaw<Byte>> x_bytes,PointerType<ArrayRaw<Byte>> x_myCharsAsBytes)
	{
		for ( Int32 x_i = (( Int32 ) 0) ;  x_i < ( Int32 ) x_bytes->get_Length() ;   x_i++ )
		{
			if ( !((Byte)((*x_bytes->Address(x_i)))).Equals(( Byte ) (*x_myCharsAsBytes->Address(x_i))) )
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
			x_caBlock->TestFailed((new StringRaw("Encoding TestFailed")));
		}
	}
	EnumTestRaw::EnumTestRaw(CABlock x_caBlock)
	{
		this->x_caBlock.Assign(x_caBlock);
	}
	void EnumTestRaw::Test()
	{
		x_caBlock->Send((new StringRaw("Doing EnumTest")));
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
		Int32 x_num = ( Int32 ) ( Int32 ) x_testEnum;
		if ( !((Int32)(x_num)).Equals((( Int32 ) 5)) )
		{
			EnumTestFailed();
		}
		Double x_num2 = ( Double ) ( Double ) x_testEnum;
		if ( !((Double)(x_num2)).Equals((( Double ) 5)) )
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
		Int32 x_num = ( Int32 ) ( Int32 ) x_testEnum;
		if ( !((Int32)(x_num)).Equals((( Int32 ) 5)) )
		{
			EnumTestFailed();
		}
		Double x_num2 = ( Double ) ( Double ) x_testEnum;
		if ( !((Double)(x_num2)).Equals((( Double ) 5)) )
		{
			EnumTestFailed();
		}
	}
	void EnumTestRaw::EnumTestFailed()
	{
		x_caBlock->TestFailed((new StringRaw("Enum TestFailed")));
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
	}
	void CABlockRaw::TestFailed(String x_reason)
	{
		Send((new StringRaw("\t\tERROR: ")) + x_reason);
	}
	Int16TestRaw::Int16TestRaw(CABlock x_caBlock)
	{
		this->x_caBlock.Assign(x_caBlock);
	}
	void Int16TestRaw::Test()
	{
		x_caBlock->Send((new StringRaw("Doing Int16Test")));
		x_caBlock->Send((new StringRaw("\tDoing Int16MethodsTest")));
		Int16MethodsTest();
		x_caBlock->Send((new StringRaw("\tDoing Int16MathTest")));
		Int16MathTest();
		x_caBlock->Send((new StringRaw("\tDoing Int16Operators")));
		Int16Operators();
		x_caBlock->Send((new StringRaw("\tDoing Int16ArrayTests")));
		Int16ArrayTests();
		x_caBlock->Send((new StringRaw("\tDoing Int16MiscTests")));
		Int16MiscTests();
	}
	void Int16TestRaw::Int16MethodsTest()
	{
		Int16 x_num = (( Int16 ) 5);
		CxAssert(((Int32)((( Int16 ) x_num).CompareTo(5))).Equals((( Int32 ) 0)));
		CxAssert(((Int32)((( Int16 ) x_num).CompareTo((new Int16Box((( Int16 ) 5) ))))).Equals((( Int32 ) 0)));
		CxAssert((( Int16 ) x_num).Equals(5));
		CxAssert((( Int16 ) x_num).Equals((new Int16Box((( Int16 ) 5) ))));
		CxAssert(((Int16)(Int16Raw::Parse((new StringRaw("-55"))))).Equals(( Int16 ) -55));
		CxAssert(((new StringRaw("-75")))->Equals(( -75 ).ToString()));
		String x_text = (( Int16 ) ((Int16)32767)).ToString();
		CxAssert((x_text)->Equals((new StringRaw("32767"))));
		CxAssert(((Int16)(Int16Raw::Parse(x_text))).Equals(( Int16 ) ((Int16)32767)));
		String x_text2 = (( Int16 ) ((Int16)-32768)).ToString();
		CxAssert((x_text2)->Equals((new StringRaw("-32768"))));
		CxAssert(((Int16)(Int16Raw::Parse(x_text2))).Equals(( Int16 ) ((Int16)-32768)));
		Int64 x_num2 = ( Int64 ) ((Int64)9223372036854775807);
		x_num = ( Int16 ) ( Int16 ) x_num2;
		CxAssert(((Int16)(x_num)).Equals(( Int16 ) -1));
		Object x_obj = (new Int16Box((( Int16 ) 5) ));
		CxAssert(x_obj->Equals((( Int16 ) 5)));
		CxAssert((x_obj->ToString())->Equals((new StringRaw("5"))));
	}
	void Int16TestRaw::Int16MathTest()
	{
		Int16 x_num = (( Int16 ) 600);
		Int16 x_num2 = (( Int16 ) 1200);
		CxAssert(((Int32)(x_num + ( Int16 ) x_num2)).Equals((( Int32 ) 1800)));
		CxAssert(((Int32)(x_num - ( Int16 ) x_num2)).Equals(( Int32 ) -600));
		CxAssert(((Int32)(x_num * ( Int16 ) x_num2)).Equals((( Int32 ) 720000)));
		CxAssert(((Int32)(x_num2 / ( Int16 ) x_num)).Equals((( Int32 ) 2)));
		CxAssert(((Int32)(x_num >> (( Int32 ) 2))).Equals((( Int32 ) 150)));
		CxAssert(((Int32)(x_num << (( Int32 ) 1))).Equals((( Int32 ) 1200)));
		Int32 x_num3 = (( Int32 ) 11);
		CxAssert(((Int32)(x_num3 % (( Int32 ) 5))).Equals((( Int32 ) 1)));
		x_num3 = (( Int32 ) 8);
		CxAssert(( x_num3 | (( Int32 ) 1) ) == (( Int32 ) 9));
		CxAssert(( x_num3 & (( Int32 ) 1) ) == (( Int32 ) 0));
		CxAssert(((Int32)(++x_num3)).Equals((( Int32 ) 9)));
		CxAssert(((Int32)(--x_num3)).Equals((( Int32 ) 8)));
		CxAssert(( x_num3 = x_num3 * (( Int32 ) 2) ) == (( Int32 ) 16));
		CxAssert(( x_num3 = x_num3 / (( Int32 ) 2) ) == (( Int32 ) 8));
		CxAssert(( x_num3 = x_num3 % (( Int32 ) 2) ) == (( Int32 ) 0));
		CxAssert(( x_num3 = x_num3 | (( Int32 ) 4) ) == (( Int32 ) 4));
		CxAssert(( x_num3 = x_num3 & (( Int32 ) 4) ) == (( Int32 ) 4));
		CxAssert(((Int32)(-x_num)).Equals(( Int32 ) -600));
		CxAssert(((Int16)(x_num)).Equals((( Int16 ) 600)));
		x_num3 = (( Int32 ) 0);
		CxAssert(((Int32)(~x_num3)).Equals(( Int32 ) -1));
		CxAssert(((Int32)(++x_num3)).Equals((( Int32 ) 1)));
		CxAssert(((Int32)(--x_num3)).Equals((( Int32 ) 0)));
		CxAssert(x_num < ( Int16 ) x_num2);
		CxAssert(x_num <= ( Int16 ) x_num2);
		CxAssert(x_num2 > ( Int16 ) x_num);
		CxAssert(x_num2 >= ( Int16 ) x_num);
	}
	void Int16TestRaw::Int16Operators()
	{
		Int16 x_num = (( Int16 ) 66);
		Char x_c = ( Char ) '';
		Byte x_b = (( Byte ) 1);
		SByte x_b2 = (( SByte ) 1);
		Int16 x_num2 = (( Int16 ) 1);
		Int32 x_num3 = (( Int32 ) 1);
		Int64 x_num4 = (( Int64 ) 1);
		UInt16 x_num5 = (( UInt16 ) 1);
		UInt32 x_num6 = (( UInt32 ) 1);
		Float x_num7 = (( Single ) 1);
		Double x_num8 = (( Double ) 1);
		CxAssert(((Int16)(x_num)).Equals((( Int16 ) 66)));
		CxAssert(((Int32)(x_num + ( Char ) x_c)).Equals((( Int32 ) 67)));
		CxAssert(((Int32)(x_num + ( Byte ) x_b)).Equals((( Int32 ) 67)));
		CxAssert(((Int32)(x_num + ( SByte ) x_b2)).Equals((( Int32 ) 67)));
		CxAssert(((Int32)(x_num + ( Int16 ) x_num2)).Equals((( Int32 ) 67)));
		CxAssert(((Int32)(x_num + ( Int32 ) x_num3)).Equals((( Int32 ) 67)));
		CxAssert(((Int64)(x_num + ( Int64 ) x_num4)).Equals((( Int64 ) 67)));
		CxAssert(((Int32)(x_num + ( UInt16 ) x_num5)).Equals((( Int32 ) 67)));
		CxAssert(((Int64)(x_num + ( UInt32 ) x_num6)).Equals((( Int64 ) 67)));
		CxAssert(((Single)(( Single ) x_num + ( Single ) x_num7)).Equals((( Single ) 67)));
		CxAssert(((Double)(( Double ) x_num + ( Double ) x_num8)).Equals((( Double ) 67)));
		CxAssert(((Int32)(x_num - ( Char ) x_c)).Equals((( Int32 ) 65)));
		CxAssert(((Int32)(x_num - ( Byte ) x_b)).Equals((( Int32 ) 65)));
		CxAssert(((Int32)(x_num - ( SByte ) x_b2)).Equals((( Int32 ) 65)));
		CxAssert(((Int32)(x_num - ( Int16 ) x_num2)).Equals((( Int32 ) 65)));
		CxAssert(((Int32)(x_num - ( Int32 ) x_num3)).Equals((( Int32 ) 65)));
		CxAssert(((Int64)(x_num - ( Int64 ) x_num4)).Equals((( Int64 ) 65)));
		CxAssert(((Int32)(x_num - ( UInt16 ) x_num5)).Equals((( Int32 ) 65)));
		CxAssert(((Int64)(x_num - ( UInt32 ) x_num6)).Equals((( Int64 ) 65)));
		CxAssert(((Single)(( Single ) x_num - ( Single ) x_num7)).Equals((( Single ) 65)));
		CxAssert(((Double)(( Double ) x_num - ( Double ) x_num8)).Equals((( Double ) 65)));
		CxAssert(((Int32)(x_num * ( Char ) x_c)).Equals((( Int32 ) 66)));
		CxAssert(((Int32)(x_num * ( Byte ) x_b)).Equals((( Int32 ) 66)));
		CxAssert(((Int32)(x_num * ( SByte ) x_b2)).Equals((( Int32 ) 66)));
		CxAssert(((Int32)(x_num * ( Int16 ) x_num2)).Equals((( Int32 ) 66)));
		CxAssert(((Int32)(x_num * ( Int32 ) x_num3)).Equals((( Int32 ) 66)));
		CxAssert(((Int64)(x_num * ( Int64 ) x_num4)).Equals((( Int64 ) 66)));
		CxAssert(((Int32)(x_num * ( UInt16 ) x_num5)).Equals((( Int32 ) 66)));
		CxAssert(((Int64)(x_num * ( UInt32 ) x_num6)).Equals((( Int64 ) 66)));
		CxAssert(((Single)(( Single ) x_num * ( Single ) x_num7)).Equals((( Single ) 66)));
		CxAssert(((Double)(( Double ) x_num * ( Double ) x_num8)).Equals((( Double ) 66)));
		CxAssert(((Int32)(( Int32 ) x_num / ( Int32 ) ( Int32 ) x_c)).Equals((( Int32 ) 66)));
		CxAssert(((Int32)(( Int32 ) x_num / ( Int32 ) ( Int32 ) x_b)).Equals((( Int32 ) 66)));
		CxAssert(((Int32)(x_num / ( SByte ) x_b2)).Equals((( Int32 ) 66)));
		CxAssert(((Int32)(x_num / ( Int16 ) x_num2)).Equals((( Int32 ) 66)));
		CxAssert(((Int32)(x_num / ( Int32 ) x_num3)).Equals((( Int32 ) 66)));
		CxAssert(((Int64)(x_num / ( Int64 ) x_num4)).Equals((( Int64 ) 66)));
		CxAssert(((Int32)(( Int32 ) x_num / ( Int32 ) ( Int32 ) x_num5)).Equals((( Int32 ) 66)));
		CxAssert(((Int64)(( Int64 ) x_num / ( Int64 ) ( Int64 ) x_num6)).Equals((( Int64 ) 66)));
		CxAssert(((Single)(( Single ) x_num / ( Single ) x_num7)).Equals((( Single ) 66)));
		CxAssert(((Double)(( Double ) x_num / ( Double ) x_num8)).Equals((( Double ) 66)));
		CxAssert(((Int32)(( Int32 ) x_num % ( Int32 ) ( Int32 ) x_c)).Equals((( Int32 ) 0)));
		CxAssert(((Int32)(( Int32 ) x_num % ( Int32 ) ( Int32 ) x_b)).Equals((( Int32 ) 0)));
		CxAssert(((Int32)(x_num % ( SByte ) x_b2)).Equals((( Int32 ) 0)));
		CxAssert(((Int32)(x_num % ( Int16 ) x_num2)).Equals((( Int32 ) 0)));
		CxAssert(((Int32)(x_num % ( Int32 ) x_num3)).Equals((( Int32 ) 0)));
		CxAssert(((Int64)(x_num % ( Int64 ) x_num4)).Equals((( Int64 ) 0)));
		CxAssert(((Int32)(( Int32 ) x_num % ( Int32 ) ( Int32 ) x_num5)).Equals((( Int32 ) 0)));
		CxAssert(((Int64)(( Int64 ) x_num % ( Int64 ) ( Int64 ) x_num6)).Equals((( Int64 ) 0)));
		CxAssert(((Single)(( Single ) x_num % ( Single ) x_num7)).Equals((( Single ) 0)));
		CxAssert(((Double)(( Double ) x_num % ( Double ) x_num8)).Equals((( Double ) 0)));
		CxAssert(( x_num & ( Char ) x_c ) == (( Int32 ) 0));
		CxAssert(( x_num & ( Byte ) x_b ) == (( Int32 ) 0));
		CxAssert(( x_num & ( SByte ) x_b2 ) == (( Int32 ) 0));
		CxAssert(( x_num & ( Int16 ) x_num2 ) == (( Int32 ) 0));
		CxAssert(( x_num & ( Int32 ) x_num3 ) == (( Int32 ) 0));
		CxAssert(( x_num & ( Int64 ) x_num4 ) == (( Int32 ) 0));
		CxAssert(( x_num & ( UInt16 ) x_num5 ) == (( Int32 ) 0));
		CxAssert(( x_num & ( UInt32 ) x_num6 ) == (( Int32 ) 0));
		CxAssert(( x_num | ( Int16 ) ( Int16 ) x_c ) == (( Int32 ) 67));
		CxAssert(( x_num | ( Byte ) x_b ) == (( Int32 ) 67));
		CxAssert(( x_num | ( SByte ) x_b2 ) == (( Int32 ) 67));
		CxAssert(( x_num | ( Int16 ) x_num2 ) == (( Int32 ) 67));
		CxAssert(( x_num | ( Int16 ) ( Int16 ) x_num3 ) == (( Int32 ) 67));
		CxAssert(( x_num | ( Int16 ) ( Int16 ) x_num4 ) == (( Int32 ) 67));
		CxAssert(( x_num | ( Int16 ) ( Int16 ) x_num5 ) == (( Int32 ) 67));
		CxAssert(( x_num | ( Int16 ) ( Int16 ) x_num6 ) == (( Int32 ) 67));
		CxAssert(( x_num ^ ( Char ) x_c ) == (( Int32 ) 67));
		CxAssert(( x_num ^ ( Byte ) x_b ) == (( Int32 ) 67));
		CxAssert(( x_num ^ ( SByte ) x_b2 ) == (( Int32 ) 67));
		CxAssert(( x_num ^ ( Int16 ) x_num2 ) == (( Int32 ) 67));
		CxAssert(( x_num ^ ( Int32 ) x_num3 ) == (( Int32 ) 67));
		CxAssert(( x_num ^ ( Int64 ) x_num4 ) == (( Int32 ) 67));
		CxAssert(( x_num ^ ( UInt16 ) x_num5 ) == (( Int32 ) 67));
		CxAssert(( x_num ^ ( UInt32 ) x_num6 ) == (( Int32 ) 67));
		CxAssert(((Int32)(~x_num)).Equals(( Int32 ) -67));
		CxAssert(x_c < ( Int16 ) x_num);
		CxAssert(x_b < ( Int16 ) x_num);
		CxAssert(x_b2 < ( Int16 ) x_num);
		CxAssert(x_num2 < ( Int16 ) x_num);
		CxAssert(x_num3 < ( Int16 ) x_num);
		CxAssert(x_num4 < ( Int16 ) x_num);
		CxAssert(x_num5 < ( Int16 ) x_num);
		CxAssert(x_num6 < ( Int16 ) x_num);
		CxAssert(x_num7 < ( Single ) ( Single ) x_num);
		CxAssert(x_num8 < ( Double ) ( Double ) x_num);
		CxAssert(x_c > ( Int16 ) x_num,false);
		CxAssert(x_b > ( Int16 ) x_num,false);
		CxAssert(x_b2 > ( Int16 ) x_num,false);
		CxAssert(x_num2 > ( Int16 ) x_num,false);
		CxAssert(x_num3 > ( Int16 ) x_num,false);
		CxAssert(x_num4 > ( Int16 ) x_num,false);
		CxAssert(x_num5 > ( Int16 ) x_num,false);
		CxAssert(x_num6 > ( Int16 ) x_num,false);
		CxAssert(x_num7 > ( Single ) ( Single ) x_num,false);
		CxAssert(x_num8 > ( Double ) ( Double ) x_num,false);
		CxAssert(( x_num = ( Int16 ) ( Int16 ) ( x_num + (( Int32 ) 1) ) ) == (( Int32 ) 67));
		CxAssert(( x_num = ( Int16 ) ( Int16 ) ( x_num - (( Int32 ) 1) ) ) == (( Int32 ) 66));
		CxAssert(((Int16)(x_num++)).Equals((( Int16 ) 66)));
		CxAssert(((Int16)(x_num--)).Equals((( Int16 ) 67)));
		CxAssert(((Int32)(x_num << (( Int32 ) 1))).Equals((( Int32 ) 132)));
		CxAssert(((Int32)(x_num >> (( Int32 ) 1))).Equals((( Int32 ) 33)));
		CxAssert(((Char)(x_c)).Equals(( Char ) x_num),false);
		CxAssert(((Byte)(x_b)).Equals(( Byte ) x_num),false);
		CxAssert(((SByte)(x_b2)).Equals(( SByte ) x_num),false);
		CxAssert(((Int16)(x_num2)).Equals(( Int16 ) x_num),false);
		CxAssert(((Int32)(x_num3)).Equals(( Int32 ) x_num),false);
		CxAssert(((Int64)(x_num4)).Equals(( Int64 ) x_num),false);
		CxAssert(((UInt16)(x_num5)).Equals(( UInt16 ) x_num),false);
		CxAssert(((UInt32)(x_num6)).Equals(( UInt32 ) x_num),false);
		CxAssert(((Single)(x_num7)).Equals(( Single ) ( Single ) x_num),false);
		CxAssert(((Double)(x_num8)).Equals(( Double ) ( Double ) x_num),false);
		CxAssert(!((Char)(x_c)).Equals(( Char ) x_num));
		CxAssert(!((Byte)(x_b)).Equals(( Byte ) x_num));
		CxAssert(!((SByte)(x_b2)).Equals(( SByte ) x_num));
		CxAssert(!((Int16)(x_num2)).Equals(( Int16 ) x_num));
		CxAssert(!((Int32)(x_num3)).Equals(( Int32 ) x_num));
		CxAssert(!((Int64)(x_num4)).Equals(( Int64 ) x_num));
		CxAssert(!((UInt16)(x_num5)).Equals(( UInt16 ) x_num));
		CxAssert(!((UInt32)(x_num6)).Equals(( UInt32 ) x_num));
		CxAssert(!((Single)(x_num7)).Equals(( Single ) ( Single ) x_num));
		CxAssert(!((Double)(x_num8)).Equals(( Double ) ( Double ) x_num));
		CxAssert(x_c <= ( Int16 ) x_num);
		CxAssert(x_b <= ( Int16 ) x_num);
		CxAssert(x_b2 <= ( Int16 ) x_num);
		CxAssert(x_num2 <= ( Int16 ) x_num);
		CxAssert(x_num3 <= ( Int16 ) x_num);
		CxAssert(x_num4 <= ( Int16 ) x_num);
		CxAssert(x_num5 <= ( Int16 ) x_num);
		CxAssert(x_num6 <= ( Int16 ) x_num);
		CxAssert(x_num7 <= ( Single ) ( Single ) x_num);
		CxAssert(x_num8 <= ( Double ) ( Double ) x_num);
		CxAssert(x_c >= ( Int16 ) x_num,false);
		CxAssert(x_b >= ( Int16 ) x_num,false);
		CxAssert(x_b2 >= ( Int16 ) x_num,false);
		CxAssert(x_num2 >= ( Int16 ) x_num,false);
		CxAssert(x_num3 >= ( Int16 ) x_num,false);
		CxAssert(x_num4 >= ( Int16 ) x_num,false);
		CxAssert(x_num5 >= ( Int16 ) x_num,false);
		CxAssert(x_num6 >= ( Int16 ) x_num,false);
		CxAssert(x_num7 >= ( Single ) ( Single ) x_num,false);
		CxAssert(x_num8 >= ( Double ) ( Double ) x_num,false);
		CxAssert(( x_num = ( Int16 ) ( Int16 ) ( x_num + ( Int16 ) ( Int16 ) x_c ) ) == (( Int32 ) 67));
		CxAssert(( x_num = ( Int16 ) ( Int16 ) ( x_num - ( Int16 ) ( Int16 ) x_c ) ) == (( Int32 ) 66));
		CxAssert(( x_num = ( Int16 ) ( Int16 ) ( x_num + ( Int16 ) ( Int16 ) x_num3 ) ) == (( Int32 ) 67));
		CxAssert(( x_num = ( Int16 ) ( Int16 ) ( x_num - ( Int16 ) ( Int16 ) x_num3 ) ) == (( Int32 ) 66));
		CxAssert(( x_num = ( Int16 ) ( Int16 ) ( x_num * ( Int16 ) ( Int16 ) x_c ) ) == (( Int32 ) 66));
		CxAssert(( x_num = ( Int16 ) ( Int16 ) ( x_num / ( Int16 ) ( Int16 ) x_c ) ) == (( Int32 ) 66));
		CxAssert(( x_num = ( Int16 ) ( Int16 ) ( x_num * ( Int16 ) ( Int16 ) x_num3 ) ) == (( Int32 ) 66));
		CxAssert(( x_num = ( Int16 ) ( Int16 ) ( x_num / ( Int16 ) ( Int16 ) x_num3 ) ) == (( Int32 ) 66));
		CxAssert(( x_num = ( Int16 ) ( Int16 ) ( x_num % ( Int16 ) ( Int16 ) x_c ) ) == (( Int32 ) 0));
		x_num = (( Int16 ) 66);
		CxAssert(( x_num = ( Int16 ) ( Int16 ) ( x_num % ( Int16 ) ( Int16 ) x_num3 ) ) == (( Int32 ) 0));
		x_num = (( Int16 ) 66);
		CxAssert(( x_num = ( Int16 ) ( Int16 ) ( x_num & ( Int16 ) ( Int16 ) x_c ) ) == (( Int32 ) 0));
		x_num = (( Int16 ) 66);
		CxAssert(( x_num = ( Int16 ) ( Int16 ) ( x_num & ( Int16 ) ( Int16 ) x_num3 ) ) == (( Int32 ) 0));
		x_num = (( Int16 ) 66);
		CxAssert(( x_num = ( Int16 ) ( Int16 ) ( x_num | ( Int16 ) ( Int16 ) x_c ) ) == (( Int32 ) 67));
		x_num = (( Int16 ) 66);
		CxAssert(( x_num = ( Int16 ) ( Int16 ) ( x_num | ( Int16 ) ( Int16 ) x_num3 ) ) == (( Int32 ) 67));
		x_num = (( Int16 ) 66);
		CxAssert(( x_num = ( Int16 ) ( Int16 ) ( x_num ^ ( Int16 ) ( Int16 ) x_c ) ) == (( Int32 ) 67));
		x_num = (( Int16 ) 66);
		CxAssert(( x_num = ( Int16 ) ( Int16 ) ( x_num ^ ( Int16 ) ( Int16 ) x_num3 ) ) == (( Int32 ) 67));
		x_num = (( Int16 ) 66);
		CxAssert(( x_num = ( Int16 ) ( Int16 ) ( x_num << ( Int32 ) ( Int32 ) x_b ) ) == (( Int32 ) 132));
		x_num = (( Int16 ) 66);
		CxAssert(( x_num = ( Int16 ) ( Int16 ) ( x_num << ( Int32 ) ( Int32 ) x_num2 ) ) == (( Int32 ) 132));
		x_num = (( Int16 ) 66);
		CxAssert(( x_num = ( Int16 ) ( Int16 ) ( x_num << ( Int32 ) ( Int32 ) x_c ) ) == (( Int32 ) 132));
		x_num = (( Int16 ) 66);
		CxAssert(( x_num = ( Int16 ) ( Int16 ) ( x_num << ( Int32 ) x_num3 ) ) == (( Int32 ) 132));
		x_num = (( Int16 ) 66);
		CxAssert(( x_num = ( Int16 ) ( Int16 ) ( x_num >> ( Int32 ) ( Int32 ) x_c ) ) == (( Int32 ) 33));
		x_num = (( Int16 ) 66);
		CxAssert(( x_num = ( Int16 ) ( Int16 ) ( x_num >> ( Int32 ) x_num3 ) ) == (( Int32 ) 33));
		x_num = (( Int16 ) 66);
		Int16 x_num9 = (( Int16 ) 0);
		CxAssert(((Int16)(x_num9)).Equals((( Int16 ) 0)));
		CxAssert(((Int16)(x_num9)).Equals((( Int16 ) 0)));
		CxAssert(x_num3 <= (( Int32 ) 2));
		CxAssert(x_num3 >= ( Int32 ) -2);
	}
	void Int16TestRaw::Int16ArrayTests()
	{
		static Int16 Int16ArrayTestsArray0[5] = {1,2,3,4,5};
		static Int16 Int16ArrayTestsArray1[4] = {1,2,3,4};
		static Int16 Int16ArrayTestsArray2[2][4] = {{1,2,3,4},{4,5,6,7}};
		static Int16 Int16ArrayTestsArray3[2][2][4] = {{{1,2,3,4},{5,6,7,8}},{{9,10,11,12},{13,14,15,16}}};
		PointerType<ArrayRaw<Int16>> x_array = (new ArrayRaw<Int16>(5))->Initialize((Int16*) Int16ArrayTestsArray0);
		CxAssert(((Int32)(x_array->get_Length())).Equals((( Int32 ) 5)));
		CxAssert(((Int16)((*x_array->Address(3)))).Equals((( Int16 ) 4)));
		PointerType<ArrayRaw<Int16>> x_array2 = (new ArrayRaw<Int16>(4))->Initialize((Int16*) Int16ArrayTestsArray1);
		CxAssert(((Int16)((*x_array2->Address(1)))).Equals((( Int16 ) 2)));
		PointerType<ArrayRaw<Int16>> x_array3 = (new ArrayRaw<Int16>(2,4))->Initialize((Int16*) Int16ArrayTestsArray2);
		CxAssert(((Int16)((*x_array3->Address(0,2)))).Equals((( Int16 ) 3)));
		PointerType<ArrayRaw<Int16>> x_array4 = (new ArrayRaw<Int16>(2,2,4))->Initialize((Int16*) Int16ArrayTestsArray3);
		CxAssert(((Int16)((*x_array4->Address(0,0,3)))).Equals((( Int16 ) 4)));
		(*x_array4->Address(0,0,3)) = (( Int16 ) 6);
		CxAssert(((Int16)((*x_array4->Address(0,0,3)))).Equals((( Int16 ) 6)));
		x_array4->SetValue((( Int16 ) 4),0,0,3);
		CxAssert(((Int16)((*x_array4->Address(0,0,3)))).Equals((( Int16 ) 4)));
	}
	void Int16TestRaw::Int16MiscTests()
	{
		Int16 x_num = ( Int16 ) -1;
		Int16 x_val = (( Int16 ) 1);
		CxAssert(((Int16)(MathRaw::Abs(x_num))).Equals((( Int16 ) 1)));
		CxAssert(((Int16)(MathRaw::Max(x_num,x_val))).Equals((( Int16 ) 1)));
		CxAssert(((Int16)(MathRaw::Min(x_num,x_val))).Equals(( Int16 ) -1));
		CxAssert(MathRaw::Sign(x_num) < (( Int32 ) 0));
		PointerType<StringBuilderRaw> x_stringBuilder = new StringBuilderRaw();
		x_stringBuilder->Append(x_num);
		CxAssert((x_stringBuilder->ToString())->Equals((new StringRaw("-1"))));
		x_stringBuilder->Insert(2,x_num);
		CxAssert((x_stringBuilder->ToString())->Equals((new StringRaw("-1-1"))));
	}
	void Int16TestRaw::CxAssert(Boolean x_x)
	{
		if ( !x_x )
		{
			x_caBlock->TestFailed((new StringRaw("Int16 TestFailed")));
		}
	}
	void Int16TestRaw::CxAssert(Boolean x_x,Boolean x_y)
	{
		if ( !(x_x).Equals(x_y) )
		{
			x_caBlock->TestFailed((new StringRaw("Int16 TestFailed")));
		}
	}
	Int32TestRaw::Int32TestRaw(CABlock x_caBlock)
	{
		this->x_caBlock.Assign(x_caBlock);
	}
	void Int32TestRaw::Test()
	{
		x_caBlock->Send((new StringRaw("Doing Int32Test")));
		x_caBlock->Send((new StringRaw("\tDoing Int32MethodsTest")));
		Int32MethodsTest();
		x_caBlock->Send((new StringRaw("\tDoing Int32MathTest")));
		Int32MathTest();
		x_caBlock->Send((new StringRaw("\tDoing Int32Operators")));
		Int32Operators();
		x_caBlock->Send((new StringRaw("\tDoing Int32Conversion")));
		Int32Conversion();
		x_caBlock->Send((new StringRaw("\tDoing Int32ArrayTests")));
		Int32ArrayTests();
		x_caBlock->Send((new StringRaw("\tDoing Int32MiscTests")));
		Int32MiscTests();
	}
	void Int32TestRaw::Int32Conversion()
	{
		Double x_num = (( Double ) 1);
		Double x_num2 = (( Double ) 2);
		if ( x_num < ( Double ) x_num2 )
		{
			x_num = (( Double ) 3);
		}
		Int32 x_num3 = ( Int32 ) ( Int32 ) x_num;
		CxAssert(((Int32)(x_num3)).Equals((( Int32 ) 3)));
	}
	void Int32TestRaw::Int32MethodsTest()
	{
		Int32 x_num = (( Int32 ) 5);
		CxAssert(((Int32)((( Int32 ) x_num).CompareTo(5))).Equals((( Int32 ) 0)));
		CxAssert(((Int32)((( Int32 ) x_num).CompareTo((new Int32Box(5 ))))).Equals((( Int32 ) 0)));
		CxAssert((( Int32 ) x_num).Equals(5));
		CxAssert((( Int32 ) x_num).Equals((new Int32Box(5 ))));
		CxAssert(((Int32)(Int32Raw::Parse((new StringRaw("-55"))))).Equals(( Int32 ) -55));
		CxAssert(((new StringRaw("-75")))->Equals(( -75 ).ToString()));
		String x_text = (( Int32 ) ((Int32)2147483647)).ToString();
		CxAssert((x_text)->Equals((new StringRaw("2147483647"))));
		CxAssert(((Int32)(Int32Raw::Parse(x_text))).Equals(( Int32 ) ((Int32)2147483647)));
		String x_text2 = (( Int32 ) ((Int32)-2147483648)).ToString();
		CxAssert((x_text2)->Equals((new StringRaw("-2147483648"))));
		CxAssert(((Int32)(Int32Raw::Parse(x_text2))).Equals(( Int32 ) ((Int32)-2147483648)));
		Int64 x_num2 = ( Int64 ) ((Int64)9223372036854775807);
		x_num = ( Int32 ) ( Int32 ) x_num2;
		CxAssert(((Int32)(x_num)).Equals(( Int32 ) -1));
		Object x_obj = (new Int32Box(5 ));
		CxAssert(x_obj->Equals(5));
	}
	void Int32TestRaw::Int32MathTest()
	{
		Int32 x_num = (( Int32 ) 60000);
		Int32 x_num2 = (( Int32 ) 120000);
		CxAssert(((Int32)(x_num + ( Int32 ) x_num2)).Equals((( Int32 ) 180000)));
		CxAssert(((Int32)(x_num - ( Int32 ) x_num2)).Equals(( Int32 ) -60000));
		CxAssert(((Int32)(x_num * ( Int32 ) x_num2)).Equals(( Int32 ) -1389934592));
		CxAssert(((Int32)(x_num2 / ( Int32 ) x_num)).Equals((( Int32 ) 2)));
		CxAssert(((Int32)(x_num >> (( Int32 ) 2))).Equals((( Int32 ) 15000)));
		CxAssert(((Int32)(x_num << (( Int32 ) 1))).Equals((( Int32 ) 120000)));
		Int32 x_num3 = (( Int32 ) 11);
		CxAssert(((Int32)(x_num3 % (( Int32 ) 5))).Equals((( Int32 ) 1)));
		x_num3 = (( Int32 ) 8);
		CxAssert(( x_num3 | (( Int32 ) 1) ) == (( Int32 ) 9));
		CxAssert(( x_num3 & (( Int32 ) 1) ) == (( Int32 ) 0));
		CxAssert(((Int32)(++x_num3)).Equals((( Int32 ) 9)));
		CxAssert(((Int32)(--x_num3)).Equals((( Int32 ) 8)));
		CxAssert(( x_num3 = x_num3 * (( Int32 ) 2) ) == (( Int32 ) 16));
		CxAssert(( x_num3 = x_num3 / (( Int32 ) 2) ) == (( Int32 ) 8));
		CxAssert(( x_num3 = x_num3 % (( Int32 ) 2) ) == (( Int32 ) 0));
		CxAssert(( x_num3 = x_num3 | (( Int32 ) 4) ) == (( Int32 ) 4));
		CxAssert(( x_num3 = x_num3 & (( Int32 ) 4) ) == (( Int32 ) 4));
		CxAssert(((Int32)(-x_num)).Equals(( Int32 ) -60000));
		CxAssert(((Int32)(x_num)).Equals((( Int32 ) 60000)));
		x_num3 = (( Int32 ) 0);
		CxAssert(((Int32)(~x_num3)).Equals(( Int32 ) -1));
		CxAssert(((Int32)(++x_num3)).Equals((( Int32 ) 1)));
		CxAssert(((Int32)(--x_num3)).Equals((( Int32 ) 0)));
		CxAssert(x_num < ( Int32 ) x_num2);
		CxAssert(x_num <= ( Int32 ) x_num2);
		CxAssert(x_num2 > ( Int32 ) x_num);
		CxAssert(x_num2 >= ( Int32 ) x_num);
	}
	void Int32TestRaw::Int32Operators()
	{
		Int32 x_num = (( Int32 ) 66);
		Char x_c = ( Char ) '';
		Int32 x_num2 = (( Int32 ) 1);
		UInt32 x_num3 = (( UInt32 ) 1);
		Int64 x_num4 = (( Int64 ) 1);
		Double x_num5 = (( Double ) 1);
		CxAssert(((Int32)(x_num)).Equals((( Int32 ) 66)));
		CxAssert(((Int32)(x_num + ( Char ) x_c)).Equals((( Int32 ) 67)));
		CxAssert(((Int32)(x_num + ( Int32 ) x_num2)).Equals((( Int32 ) 67)));
		CxAssert(((Int64)(x_num + ( UInt32 ) x_num3)).Equals((( Int64 ) 67)));
		CxAssert(((Int64)(x_num + ( Int64 ) x_num4)).Equals((( Int64 ) 67)));
		CxAssert(((Int64)(( Int64 ) ( ( Double ) x_num + ( Double ) x_num5 ))).Equals((( Int64 ) 67)));
		CxAssert(((Int32)(x_num - ( Char ) x_c)).Equals((( Int32 ) 65)));
		CxAssert(((Int32)(x_num - ( Int32 ) x_num2)).Equals((( Int32 ) 65)));
		CxAssert(((Int64)(x_num - ( UInt32 ) x_num3)).Equals((( Int64 ) 65)));
		CxAssert(((Int64)(x_num - ( Int64 ) x_num4)).Equals((( Int64 ) 65)));
		CxAssert(((Int64)(( Int64 ) ( ( Double ) x_num - ( Double ) x_num5 ))).Equals((( Int64 ) 65)));
		CxAssert(((Int32)(x_num * ( Char ) x_c)).Equals((( Int32 ) 66)));
		CxAssert(((Int32)(x_num * ( Int32 ) x_num2)).Equals((( Int32 ) 66)));
		CxAssert(((Int64)(x_num * ( UInt32 ) x_num3)).Equals((( Int64 ) 66)));
		CxAssert(((Int64)(x_num * ( Int64 ) x_num4)).Equals((( Int64 ) 66)));
		CxAssert(((Int64)(( Int64 ) ( ( Double ) x_num * ( Double ) x_num5 ))).Equals((( Int64 ) 66)));
		CxAssert(((Int32)(x_num / ( Int32 ) ( Int32 ) x_c)).Equals((( Int32 ) 66)));
		CxAssert(((Int32)(x_num / ( Int32 ) x_num2)).Equals((( Int32 ) 66)));
		CxAssert(((Int64)(( Int64 ) x_num / ( Int64 ) ( Int64 ) x_num3)).Equals((( Int64 ) 66)));
		CxAssert(((Int64)(x_num / ( Int64 ) x_num4)).Equals((( Int64 ) 66)));
		CxAssert(((Int64)(( Int64 ) ( ( Double ) x_num / ( Double ) x_num5 ))).Equals((( Int64 ) 66)));
		CxAssert(((Int32)(x_num % ( Int32 ) ( Int32 ) x_c)).Equals((( Int32 ) 0)));
		CxAssert(((Int32)(x_num % ( Int32 ) x_num2)).Equals((( Int32 ) 0)));
		CxAssert(((Int64)(( Int64 ) x_num % ( Int64 ) ( Int64 ) x_num3)).Equals((( Int64 ) 0)));
		CxAssert(((Int64)(x_num % ( Int64 ) x_num4)).Equals((( Int64 ) 0)));
		CxAssert(((Int64)(( Int64 ) ( ( Double ) x_num % ( Double ) x_num5 ))).Equals((( Int64 ) 0)));
		CxAssert(( x_num & ( Char ) x_c ) == (( Int32 ) 0));
		CxAssert(( x_num & ( Int32 ) x_num2 ) == (( Int32 ) 0));
		CxAssert(( x_num & ( UInt32 ) x_num3 ) == (( Int32 ) 0));
		CxAssert(( x_num & ( Int64 ) x_num4 ) == (( Int32 ) 0));
		CxAssert(( x_num | ( Char ) x_c ) == (( Int32 ) 67));
		CxAssert(( x_num | ( Int32 ) x_num2 ) == (( Int32 ) 67));
		CxAssert(( x_num ^ ( Char ) x_c ) == (( Int32 ) 67));
		CxAssert(( x_num ^ ( Int32 ) x_num2 ) == (( Int32 ) 67));
		CxAssert(( x_num ^ ( UInt32 ) x_num3 ) == (( Int32 ) 67));
		CxAssert(( x_num ^ ( Int64 ) x_num4 ) == (( Int32 ) 67));
		CxAssert(((Int32)(~x_num)).Equals(( Int32 ) -67));
		CxAssert(x_c < ( Int32 ) x_num);
		CxAssert(x_num2 < ( Int32 ) x_num);
		CxAssert(x_num3 < ( Int32 ) x_num);
		CxAssert(x_num4 < ( Int32 ) x_num);
		CxAssert(x_num5 < ( Double ) ( Double ) x_num);
		CxAssert(x_c > ( Int32 ) x_num,false);
		CxAssert(x_num2 > ( Int32 ) x_num,false);
		CxAssert(x_num3 > ( Int32 ) x_num,false);
		CxAssert(x_num4 > ( Int32 ) x_num,false);
		CxAssert(x_num5 > ( Double ) ( Double ) x_num,false);
		CxAssert(((Int32)(++x_num)).Equals((( Int32 ) 67)));
		CxAssert(((Int32)(--x_num)).Equals((( Int32 ) 66)));
		CxAssert(((Int32)(x_num++)).Equals((( Int32 ) 66)));
		CxAssert(((Int32)(x_num--)).Equals((( Int32 ) 67)));
		CxAssert(((Int32)(x_num << (( Int32 ) 1))).Equals((( Int32 ) 132)));
		CxAssert(((Int32)(x_num >> (( Int32 ) 1))).Equals((( Int32 ) 33)));
		CxAssert(((Char)(x_c)).Equals(( Char ) x_num),false);
		CxAssert(((Int32)(x_num2)).Equals(( Int32 ) x_num),false);
		CxAssert(((UInt32)(x_num3)).Equals(( UInt32 ) x_num),false);
		CxAssert(((Int64)(x_num4)).Equals(( Int64 ) x_num),false);
		CxAssert(((Double)(x_num5)).Equals(( Double ) ( Double ) x_num),false);
		CxAssert(!((Char)(x_c)).Equals(( Char ) x_num));
		CxAssert(!((Int32)(x_num2)).Equals(( Int32 ) x_num));
		CxAssert(!((UInt32)(x_num3)).Equals(( UInt32 ) x_num));
		CxAssert(!((Int64)(x_num4)).Equals(( Int64 ) x_num));
		CxAssert(!((Double)(x_num5)).Equals(( Double ) ( Double ) x_num));
		CxAssert(x_c <= ( Int32 ) x_num);
		CxAssert(x_num2 <= ( Int32 ) x_num);
		CxAssert(x_num3 <= ( Int32 ) x_num);
		CxAssert(x_num4 <= ( Int32 ) x_num);
		CxAssert(x_num5 <= ( Double ) ( Double ) x_num);
		CxAssert(x_c >= ( Int32 ) x_num,false);
		CxAssert(x_num2 >= ( Int32 ) x_num,false);
		CxAssert(x_num3 >= ( Int32 ) x_num,false);
		CxAssert(x_num4 >= ( Int32 ) x_num,false);
		CxAssert(x_num5 >= ( Double ) ( Double ) x_num,false);
		CxAssert(( x_num = x_num + ( Int32 ) x_c ) == (( Int32 ) 67));
		CxAssert(( x_num = x_num - ( Int32 ) x_c ) == (( Int32 ) 66));
		CxAssert(( x_num = x_num + ( Int32 ) x_num2 ) == (( Int32 ) 67));
		CxAssert(( x_num = x_num - ( Int32 ) x_num2 ) == (( Int32 ) 66));
		CxAssert(( x_num = x_num * ( Int32 ) x_c ) == (( Int32 ) 66));
		CxAssert(( x_num = x_num / ( Int32 ) ( Int32 ) x_c ) == (( Int32 ) 66));
		CxAssert(( x_num = x_num * ( Int32 ) x_num2 ) == (( Int32 ) 66));
		CxAssert(( x_num = x_num / ( Int32 ) x_num2 ) == (( Int32 ) 66));
		CxAssert(( x_num = x_num % ( Int32 ) ( Int32 ) x_c ) == (( Int32 ) 0));
		x_num = (( Int32 ) 66);
		CxAssert(( x_num = x_num % ( Int32 ) x_num2 ) == (( Int32 ) 0));
		x_num = (( Int32 ) 66);
		CxAssert(( x_num = x_num & ( Int32 ) x_c ) == (( Int32 ) 0));
		x_num = (( Int32 ) 66);
		CxAssert(( x_num = x_num & ( Int32 ) x_num2 ) == (( Int32 ) 0));
		x_num = (( Int32 ) 66);
		CxAssert(( x_num = x_num | ( Int32 ) x_c ) == (( Int32 ) 67));
		x_num = (( Int32 ) 66);
		CxAssert(( x_num = x_num | ( Int32 ) x_num2 ) == (( Int32 ) 67));
		x_num = (( Int32 ) 66);
		CxAssert(( x_num = x_num ^ ( Int32 ) x_c ) == (( Int32 ) 67));
		x_num = (( Int32 ) 66);
		CxAssert(( x_num = x_num ^ ( Int32 ) x_num2 ) == (( Int32 ) 67));
		x_num = (( Int32 ) 66);
		CxAssert(( x_num = x_num << ( Int32 ) ( Int32 ) x_c ) == (( Int32 ) 132));
		x_num = (( Int32 ) 66);
		CxAssert(( x_num = x_num << ( Int32 ) x_num2 ) == (( Int32 ) 132));
		x_num = (( Int32 ) 66);
		CxAssert(( x_num = x_num >> ( Int32 ) ( Int32 ) x_c ) == (( Int32 ) 33));
		x_num = (( Int32 ) 66);
		CxAssert(( x_num = x_num >> ( Int32 ) x_num2 ) == (( Int32 ) 33));
		x_num = (( Int32 ) 66);
		Int32 x_num6 = (( Int32 ) 0);
		CxAssert(((Int32)(x_num6)).Equals((( Int32 ) 0)));
		CxAssert(((Int32)(x_num6)).Equals((( Int32 ) 0)));
		CxAssert(x_num2 <= (( Int32 ) 2));
		CxAssert(x_num2 >= ( Int32 ) -2);
	}
	void Int32TestRaw::Int32ArrayTests()
	{
		static Int32 Int32ArrayTestsArray0[5] = {1,2,3,4,5};
		static Int32 Int32ArrayTestsArray1[4] = {1,2,3,4};
		static Int32 Int32ArrayTestsArray2[2][4] = {{1,2,3,4},{4,5,6,7}};
		static Int32 Int32ArrayTestsArray3[2][2][4] = {{{1,2,3,4},{5,6,7,8}},{{9,10,11,12},{13,14,15,16}}};
		PointerType<ArrayRaw<Int32>> x_array = (new ArrayRaw<Int32>(5))->Initialize((Int32*) Int32ArrayTestsArray0);
		CxAssert(((Int32)(x_array->get_Length())).Equals((( Int32 ) 5)));
		CxAssert(((Int32)((*x_array->Address(3)))).Equals((( Int32 ) 4)));
		PointerType<ArrayRaw<Int32>> x_array2 = (new ArrayRaw<Int32>(4))->Initialize((Int32*) Int32ArrayTestsArray1);
		CxAssert(((Int32)((*x_array2->Address(1)))).Equals((( Int32 ) 2)));
		PointerType<ArrayRaw<Int32>> x_array3 = (new ArrayRaw<Int32>(2,4))->Initialize((Int32*) Int32ArrayTestsArray2);
		CxAssert(((Int32)((*x_array3->Address(0,2)))).Equals((( Int32 ) 3)));
		PointerType<ArrayRaw<Int32>> x_array4 = (new ArrayRaw<Int32>(2,2,4))->Initialize((Int32*) Int32ArrayTestsArray3);
		CxAssert(((Int32)((*x_array4->Address(0,0,3)))).Equals((( Int32 ) 4)));
		(*x_array4->Address(0,0,3)) = (( Int32 ) 6);
		CxAssert(((Int32)((*x_array4->Address(0,0,3)))).Equals((( Int32 ) 6)));
		x_array4->SetValue(4,0,0,3);
		CxAssert(((Int32)((*x_array4->Address(0,0,3)))).Equals((( Int32 ) 4)));
		CxAssert(((( Int32 ) (*x_array4->Address(0,0,3))).ToString())->Equals((new StringRaw("4"))));
	}
	void Int32TestRaw::Int32MiscTests()
	{
		Int32 x_num = ( Int32 ) -1;
		Int32 x_val = (( Int32 ) 1);
		CxAssert(((Int32)(MathRaw::Abs(x_num))).Equals((( Int32 ) 1)));
		CxAssert(((Int32)(MathRaw::Max(x_num,x_val))).Equals((( Int32 ) 1)));
		CxAssert(((Int32)(MathRaw::Min(x_num,x_val))).Equals(( Int32 ) -1));
		CxAssert(MathRaw::Sign(x_num) < (( Int32 ) 0));
		PointerType<StringBuilderRaw> x_stringBuilder = new StringBuilderRaw();
		x_stringBuilder->Append(x_num);
		CxAssert((x_stringBuilder->ToString())->Equals((new StringRaw("-1"))));
	}
	void Int32TestRaw::CxAssert(Boolean x_x)
	{
		if ( !x_x )
		{
			x_caBlock->TestFailed((new StringRaw("Int32 TestFailed")));
		}
	}
	void Int32TestRaw::CxAssert(Boolean x_x,Boolean x_y)
	{
		if ( !(x_x).Equals(x_y) )
		{
			x_caBlock->TestFailed((new StringRaw("Int32 TestFailed")));
		}
	}
	Int64TestRaw::Int64TestRaw(CABlock x_caBlock)
	{
		this->x_caBlock.Assign(x_caBlock);
	}
	void Int64TestRaw::Test()
	{
		x_caBlock->Send((new StringRaw("Doing Int64Test")));
		x_caBlock->Send((new StringRaw("\tDoing Int64MethodsTest")));
		Int64MethodsTest();
		x_caBlock->Send((new StringRaw("\tDoing Int64MathTest")));
		Int64MathTest();
		x_caBlock->Send((new StringRaw("\tDoing Int64Operators")));
		Int64Operators();
		x_caBlock->Send((new StringRaw("\tDoing Int64ArrayTests")));
		Int64ArrayTests();
		x_caBlock->Send((new StringRaw("\tDoing Int64MiscTests")));
		Int64MiscTests();
	}
	void Int64TestRaw::Int64MethodsTest()
	{
		Int64 x_num = (( Int64 ) 5);
		CxAssert(((Int32)((( Int64 ) x_num).CompareTo(5))).Equals((( Int32 ) 0)));
		CxAssert(((Int32)((( Int64 ) x_num).CompareTo((new Int64Box(5 ))))).Equals((( Int32 ) 0)));
		CxAssert((( Int64 ) x_num).Equals(5));
		CxAssert((( Int64 ) x_num).Equals((new Int64Box(5 ))));
		CxAssert(((Int64)(Int64Raw::Parse((new StringRaw("-55"))))).Equals(( Int64 ) -55));
		String x_text = (( Int64 ) ((Int64)9223372036854775807)).ToString();
		CxAssert((x_text)->Equals((new StringRaw("9223372036854775807"))));
		CxAssert(((Int64)(Int64Raw::Parse(x_text))).Equals(( Int64 ) ((Int64)9223372036854775807)));
		String x_text2 = (( Int64 ) ((Int64)-9223372036854775808)).ToString();
		CxAssert((x_text2)->Equals((new StringRaw("-9223372036854775808"))));
		CxAssert(((Int64)(Int64Raw::Parse(x_text2))).Equals(( Int64 ) ((Int64)-9223372036854775808)));
		Object x_obj = (new Int64Box(5 ));
		CxAssert(x_obj->Equals(5));
		CxAssert((x_obj->ToString())->Equals((new StringRaw("5"))));
	}
	void Int64TestRaw::Int64MathTest()
	{
		Int64 x_num = (( Int64 ) 60000000);
		Int64 x_num2 = (( Int64 ) 120000000);
		CxAssert(((Int64)(x_num + ( Int64 ) x_num2)).Equals((( Int64 ) 180000000)));
		CxAssert(((Int64)(x_num - ( Int64 ) x_num2)).Equals(( Int64 ) -60000000));
		CxAssert(((Int64)(x_num * ( Int64 ) x_num2)).Equals((( Int64 ) 7200000000000000)));
		CxAssert(((Int64)(x_num * ( Int64 ) x_num2)).Equals((( Int64 ) 7200000000000000)));
		CxAssert(((Int64)(x_num2 / ( Int64 ) x_num)).Equals((( Int64 ) 2)));
		CxAssert(((Int64)(x_num << (( Int32 ) 1))).Equals((( Int64 ) 120000000)));
		Int32 x_num3 = (( Int32 ) 11);
		CxAssert(((Int32)(x_num3 % (( Int32 ) 5))).Equals((( Int32 ) 1)));
		x_num3 = (( Int32 ) 8);
		CxAssert(( x_num3 | (( Int32 ) 1) ) == (( Int32 ) 9));
		CxAssert(( x_num3 & (( Int32 ) 1) ) == (( Int32 ) 0));
		CxAssert(((Int32)(++x_num3)).Equals((( Int32 ) 9)));
		CxAssert(((Int32)(--x_num3)).Equals((( Int32 ) 8)));
		CxAssert(( x_num3 = x_num3 * (( Int32 ) 2) ) == (( Int32 ) 16));
		CxAssert(( x_num3 = x_num3 / (( Int32 ) 2) ) == (( Int32 ) 8));
		CxAssert(( x_num3 = x_num3 % (( Int32 ) 2) ) == (( Int32 ) 0));
		CxAssert(( x_num3 = x_num3 | (( Int32 ) 4) ) == (( Int32 ) 4));
		CxAssert(( x_num3 = x_num3 & (( Int32 ) 4) ) == (( Int32 ) 4));
		CxAssert(((Int64)(-x_num)).Equals(( Int64 ) -60000000));
		CxAssert(((Int64)(x_num)).Equals((( Int64 ) 60000000)));
		x_num3 = (( Int32 ) 0);
		CxAssert(((Int32)(~x_num3)).Equals(( Int32 ) -1));
		CxAssert(((Int32)(++x_num3)).Equals((( Int32 ) 1)));
		CxAssert(((Int32)(--x_num3)).Equals((( Int32 ) 0)));
	}
	void Int64TestRaw::Int64Operators()
	{
		Int64 x_num = (( Int64 ) 66);
		Char x_c = ( Char ) '';
		Int32 x_num2 = (( Int32 ) 1);
		UInt32 x_num3 = (( UInt32 ) 1);
		Int64 x_num4 = (( Int64 ) 1);
		Double x_num5 = (( Double ) 1);
		CxAssert(((Int64)(x_num)).Equals((( Int64 ) 66)));
		CxAssert(((Int64)(x_num + ( Char ) x_c)).Equals((( Int64 ) 67)));
		CxAssert(((Int64)(x_num + ( Int32 ) x_num2)).Equals((( Int64 ) 67)));
		CxAssert(((Int64)(x_num + ( UInt32 ) x_num3)).Equals((( Int64 ) 67)));
		CxAssert(((Int64)(x_num + ( Int64 ) x_num4)).Equals((( Int64 ) 67)));
		CxAssert(((Double)(( Double ) x_num + ( Double ) x_num5)).Equals((( Double ) 67)));
		CxAssert(((Int64)(x_num - ( Char ) x_c)).Equals((( Int64 ) 65)));
		CxAssert(((Int64)(x_num - ( Int32 ) x_num2)).Equals((( Int64 ) 65)));
		CxAssert(((Int64)(x_num - ( UInt32 ) x_num3)).Equals((( Int64 ) 65)));
		CxAssert(((Int64)(x_num - ( Int64 ) x_num4)).Equals((( Int64 ) 65)));
		CxAssert(((Double)(( Double ) x_num - ( Double ) x_num5)).Equals((( Double ) 65)));
		CxAssert(((Int64)(x_num * ( Char ) x_c)).Equals((( Int64 ) 66)));
		CxAssert(((Int64)(x_num * ( Int32 ) x_num2)).Equals((( Int64 ) 66)));
		CxAssert(((Int64)(x_num * ( UInt32 ) x_num3)).Equals((( Int64 ) 66)));
		CxAssert(((Int64)(x_num * ( Int64 ) x_num4)).Equals((( Int64 ) 66)));
		CxAssert(((Double)(( Double ) x_num * ( Double ) x_num5)).Equals((( Double ) 66)));
		CxAssert(((Int64)(x_num / ( Int64 ) ( Int64 ) x_c)).Equals((( Int64 ) 66)));
		CxAssert(((Int64)(x_num / ( Int32 ) x_num2)).Equals((( Int64 ) 66)));
		CxAssert(((Int64)(x_num / ( Int64 ) ( Int64 ) x_num3)).Equals((( Int64 ) 66)));
		CxAssert(((Int64)(x_num / ( Int64 ) x_num4)).Equals((( Int64 ) 66)));
		CxAssert(((Double)(( Double ) x_num / ( Double ) x_num5)).Equals((( Double ) 66)));
		CxAssert(((Int64)(x_num % ( Int64 ) ( Int64 ) x_c)).Equals((( Int64 ) 0)));
		CxAssert(((Int64)(x_num % ( Int32 ) x_num2)).Equals((( Int64 ) 0)));
		CxAssert(((Int64)(x_num % ( Int64 ) ( Int64 ) x_num3)).Equals((( Int64 ) 0)));
		CxAssert(((Int64)(x_num % ( Int64 ) x_num4)).Equals((( Int64 ) 0)));
		CxAssert(((Double)(( Double ) x_num % ( Double ) x_num5)).Equals((( Double ) 0)));
		CxAssert(( x_num & ( Char ) x_c ) == (( Int32 ) 0));
		CxAssert(( x_num & ( Int32 ) x_num2 ) == (( Int32 ) 0));
		CxAssert(( x_num & ( UInt32 ) x_num3 ) == (( Int32 ) 0));
		CxAssert(( x_num & ( Int64 ) x_num4 ) == (( Int32 ) 0));
		CxAssert(( x_num | ( Char ) x_c ) == (( Int32 ) 67));
		CxAssert(( x_num | ( UInt32 ) x_num3 ) == (( Int32 ) 67));
		CxAssert(( x_num | ( Int64 ) x_num4 ) == (( Int32 ) 67));
		CxAssert(( x_num ^ ( Char ) x_c ) == (( Int32 ) 67));
		CxAssert(( x_num ^ ( Int32 ) x_num2 ) == (( Int32 ) 67));
		CxAssert(( x_num ^ ( UInt32 ) x_num3 ) == (( Int32 ) 67));
		CxAssert(( x_num ^ ( Int64 ) x_num4 ) == (( Int32 ) 67));
		CxAssert(((Int64)(~x_num)).Equals(( Int64 ) -67));
		CxAssert(x_c < ( Int64 ) x_num);
		CxAssert(x_num2 < ( Int64 ) x_num);
		CxAssert(x_num3 < ( Int64 ) x_num);
		CxAssert(x_num4 < ( Int64 ) x_num);
		CxAssert(x_num5 < ( Double ) ( Double ) x_num);
		CxAssert(x_c > ( Int64 ) x_num,false);
		CxAssert(x_num2 > ( Int64 ) x_num,false);
		CxAssert(x_num3 > ( Int64 ) x_num,false);
		CxAssert(x_num4 > ( Int64 ) x_num,false);
		CxAssert(x_num5 > ( Double ) ( Double ) x_num,false);
		CxAssert(((Int64)(++x_num)).Equals((( Int64 ) 67)));
		CxAssert(((Int64)(--x_num)).Equals((( Int64 ) 66)));
		CxAssert(((Int64)(x_num++)).Equals((( Int64 ) 66)));
		CxAssert(((Int64)(x_num--)).Equals((( Int64 ) 67)));
		CxAssert(((Int64)(x_num << (( Int32 ) 1))).Equals((( Int64 ) 132)));
		CxAssert(((Int64)(x_num >> (( Int32 ) 1))).Equals((( Int64 ) 33)));
		CxAssert(((Char)(x_c)).Equals(( Char ) x_num),false);
		CxAssert(((Int32)(x_num2)).Equals(( Int32 ) x_num),false);
		CxAssert(((UInt32)(x_num3)).Equals(( UInt32 ) x_num),false);
		CxAssert(((Int64)(x_num4)).Equals(( Int64 ) x_num),false);
		CxAssert(((Double)(x_num5)).Equals(( Double ) ( Double ) x_num),false);
		CxAssert(!((Char)(x_c)).Equals(( Char ) x_num));
		CxAssert(!((Int32)(x_num2)).Equals(( Int32 ) x_num));
		CxAssert(!((UInt32)(x_num3)).Equals(( UInt32 ) x_num));
		CxAssert(!((Int64)(x_num4)).Equals(( Int64 ) x_num));
		CxAssert(!((Double)(x_num5)).Equals(( Double ) ( Double ) x_num));
		CxAssert(x_c <= ( Int64 ) x_num);
		CxAssert(x_num2 <= ( Int64 ) x_num);
		CxAssert(x_num3 <= ( Int64 ) x_num);
		CxAssert(x_num4 <= ( Int64 ) x_num);
		CxAssert(x_num5 <= ( Double ) ( Double ) x_num);
		CxAssert(x_c >= ( Int64 ) x_num,false);
		CxAssert(x_num2 >= ( Int64 ) x_num,false);
		CxAssert(x_num3 >= ( Int64 ) x_num,false);
		CxAssert(x_num4 >= ( Int64 ) x_num,false);
		CxAssert(x_num5 >= ( Double ) ( Double ) x_num,false);
		CxAssert(( x_num = x_num + ( Int64 ) x_c ) == (( Int32 ) 67));
		CxAssert(( x_num = x_num - ( Int64 ) x_c ) == (( Int32 ) 66));
		CxAssert(( x_num = x_num + ( Int64 ) x_num2 ) == (( Int32 ) 67));
		CxAssert(( x_num = x_num - ( Int64 ) x_num2 ) == (( Int32 ) 66));
		CxAssert(( x_num = x_num + ( Int64 ) x_num3 ) == (( Int32 ) 67));
		CxAssert(( x_num = x_num - ( Int64 ) x_num3 ) == (( Int32 ) 66));
		CxAssert(( x_num = x_num + ( Int64 ) x_num4 ) == (( Int32 ) 67));
		CxAssert(( x_num = x_num - ( Int64 ) x_num4 ) == (( Int32 ) 66));
		CxAssert(( x_num = x_num * ( Int64 ) x_c ) == (( Int32 ) 66));
		CxAssert(( x_num = x_num / ( Int64 ) ( Int64 ) x_c ) == (( Int32 ) 66));
		CxAssert(( x_num = x_num * ( Int64 ) x_num2 ) == (( Int32 ) 66));
		CxAssert(( x_num = x_num / ( Int64 ) x_num2 ) == (( Int32 ) 66));
		CxAssert(( x_num = x_num * ( Int64 ) x_num3 ) == (( Int32 ) 66));
		CxAssert(( x_num = x_num / ( Int64 ) ( Int64 ) x_num3 ) == (( Int32 ) 66));
		CxAssert(( x_num = x_num * ( Int64 ) x_num4 ) == (( Int32 ) 66));
		CxAssert(( x_num = x_num / ( Int64 ) x_num4 ) == (( Int32 ) 66));
		CxAssert(( x_num = x_num % ( Int64 ) ( Int64 ) x_c ) == (( Int32 ) 0));
		x_num = (( Int64 ) 66);
		CxAssert(( x_num = x_num % ( Int64 ) x_num2 ) == (( Int32 ) 0));
		x_num = (( Int64 ) 66);
		CxAssert(( x_num = x_num % ( Int64 ) ( Int64 ) x_num3 ) == (( Int32 ) 0));
		x_num = (( Int64 ) 66);
		CxAssert(( x_num = x_num % ( Int64 ) x_num4 ) == (( Int32 ) 0));
		x_num = (( Int64 ) 66);
		CxAssert(( x_num = x_num & ( Int64 ) x_c ) == (( Int32 ) 0));
		x_num = (( Int64 ) 66);
		CxAssert(( x_num = x_num & ( Int64 ) x_num2 ) == (( Int32 ) 0));
		x_num = (( Int64 ) 66);
		CxAssert(( x_num = x_num & ( Int64 ) x_num3 ) == (( Int32 ) 0));
		x_num = (( Int64 ) 66);
		CxAssert(( x_num = x_num & ( Int64 ) x_num4 ) == (( Int32 ) 0));
		x_num = (( Int64 ) 66);
		CxAssert(( x_num = x_num | ( Int64 ) x_c ) == (( Int32 ) 67));
		x_num = (( Int64 ) 66);
		CxAssert(( x_num = x_num | ( Int64 ) x_num3 ) == (( Int32 ) 67));
		x_num = (( Int64 ) 66);
		CxAssert(( x_num = x_num | ( Int64 ) x_num4 ) == (( Int32 ) 67));
		x_num = (( Int64 ) 66);
		CxAssert(( x_num = x_num ^ ( Int64 ) x_c ) == (( Int32 ) 67));
		x_num = (( Int64 ) 66);
		CxAssert(( x_num = x_num ^ ( Int64 ) x_num2 ) == (( Int32 ) 67));
		x_num = (( Int64 ) 66);
		CxAssert(( x_num = x_num ^ ( Int64 ) x_num3 ) == (( Int32 ) 67));
		x_num = (( Int64 ) 66);
		CxAssert(( x_num = x_num ^ ( Int64 ) x_num4 ) == (( Int32 ) 67));
		x_num = (( Int64 ) 66);
		CxAssert(( x_num = x_num << ( Int64 ) ( Int32 ) x_c ) == (( Int32 ) 132));
		x_num = (( Int64 ) 66);
		CxAssert(( x_num = x_num << ( Int64 ) x_num2 ) == (( Int32 ) 132));
		x_num = (( Int64 ) 66);
		CxAssert(( x_num = x_num >> ( Int64 ) ( Int32 ) x_c ) == (( Int32 ) 33));
		x_num = (( Int64 ) 66);
		CxAssert(( x_num = x_num >> ( Int64 ) x_num2 ) == (( Int32 ) 33));
		x_num = (( Int64 ) 66);
	}
	void Int64TestRaw::Int64ArrayTests()
	{
		static Int64 Int64ArrayTestsArray0[5] = {1,2,3,4,5};
		static Int64 Int64ArrayTestsArray1[4] = {1,2,3,4};
		static Int64 Int64ArrayTestsArray2[2][4] = {{1,2,3,4},{4,5,6,7}};
		static Int64 Int64ArrayTestsArray3[2][2][4] = {{{1,2,3,4},{5,6,7,8}},{{9,10,11,12},{13,14,15,16}}};
		PointerType<ArrayRaw<Int64>> x_array = (new ArrayRaw<Int64>(5))->Initialize((Int64*) Int64ArrayTestsArray0);
		CxAssert(((Int32)(x_array->get_Length())).Equals((( Int32 ) 5)));
		CxAssert(((Int64)((*x_array->Address(3)))).Equals((( Int64 ) 4)));
		PointerType<ArrayRaw<Int64>> x_array2 = (new ArrayRaw<Int64>(4))->Initialize((Int64*) Int64ArrayTestsArray1);
		CxAssert(((Int64)((*x_array2->Address(1)))).Equals((( Int64 ) 2)));
		PointerType<ArrayRaw<Int64>> x_array3 = (new ArrayRaw<Int64>(2,4))->Initialize((Int64*) Int64ArrayTestsArray2);
		CxAssert(((Int64)((*x_array3->Address(0,2)))).Equals((( Int64 ) 3)));
		PointerType<ArrayRaw<Int64>> x_array4 = (new ArrayRaw<Int64>(2,2,4))->Initialize((Int64*) Int64ArrayTestsArray3);
		CxAssert(((Int64)((*x_array4->Address(0,0,3)))).Equals((( Int64 ) 4)));
		(*x_array4->Address(0,0,3)) = (( Int64 ) 6);
		CxAssert(((Int64)((*x_array4->Address(0,0,3)))).Equals((( Int64 ) 6)));
		x_array4->SetValue(4,0,0,3);
		CxAssert(((Int64)((*x_array4->Address(0,0,3)))).Equals((( Int64 ) 4)));
	}
	void Int64TestRaw::Int64MiscTests()
	{
		Int64 x_num = ( Int64 ) -1;
		Int64 x_val = (( Int64 ) 1);
		CxAssert(((Int64)(MathRaw::Abs(x_num))).Equals((( Int64 ) 1)));
		CxAssert(((Int64)(MathRaw::Max(x_num,x_val))).Equals((( Int64 ) 1)));
		CxAssert(((Int64)(MathRaw::Min(x_num,x_val))).Equals(( Int64 ) -1));
		CxAssert(MathRaw::Sign(x_num) < (( Int32 ) 0));
		PointerType<StringBuilderRaw> x_stringBuilder = new StringBuilderRaw();
		x_stringBuilder->Append(x_num);
		CxAssert((x_stringBuilder->ToString())->Equals((new StringRaw("-1"))));
	}
	void Int64TestRaw::CxAssert(Boolean x_x)
	{
		if ( !x_x )
		{
			x_caBlock->TestFailed((new StringRaw("Int64 TestFailed")));
		}
	}
	void Int64TestRaw::CxAssert(Boolean x_x,Boolean x_y)
	{
		if ( !(x_x).Equals(x_y) )
		{
			x_caBlock->TestFailed((new StringRaw("Int64 TestFailed")));
		}
	}
	MathTestRaw::MathTestRaw(CABlock x_caBlock)
	{
		this->x_caBlock.Assign(x_caBlock);
	}
	void MathTestRaw::Test()
	{
		x_caBlock->Send((new StringRaw("Doing MathTest")));
		DoMathTest();
	}
	void MathTestRaw::DoMathTest()
	{
		CxAssert(MathRaw::Abs(-1),1);
		CxAssert(MathRaw::Abs(1),1);
		CxAssert(((Int32)(MathRaw::Abs(-1))).Equals((( Int32 ) 1)));
		CxAssert(((Int32)(MathRaw::Abs(1))).Equals((( Int32 ) 1)));
		CxAssert(((Int64)(MathRaw::Abs(-1))).Equals((( Int64 ) 1)));
		CxAssert(((Int64)(MathRaw::Abs(1))).Equals((( Int64 ) 1)));
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
		CxAssert(((Int32)(MathRaw::Max(1,2))).Equals((( Int32 ) 2)));
		CxAssert(((Int64)(MathRaw::Max(1,2))).Equals((( Int64 ) 2)));
		CxAssert(((UInt32)(MathRaw::Max(1,2))).Equals((( UInt32 ) 2)));
		CxAssert(MathRaw::Min(1.1,1.2),1.1);
		CxAssert(((Int32)(MathRaw::Min(1,2))).Equals((( Int32 ) 1)));
		CxAssert(((Int64)(MathRaw::Min(1,2))).Equals((( Int64 ) 1)));
		CxAssert(((UInt32)(MathRaw::Min(1,2))).Equals((( UInt32 ) 1)));
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
		CxAssert(MathRaw::Round(((Double)1.79769313486232E+308)),((Double)1.79769313486232E+308));
		CxAssert(MathRaw::Round(((Double)-1.79769313486232E+308)),((Double)-1.79769313486232E+308));
		CxAssert(((Int32)(MathRaw::Sign(2))).Equals((( Int32 ) 1)));
		CxAssert(((Int32)(MathRaw::Sign(0))).Equals((( Int32 ) 0)));
		CxAssert(((Int32)(MathRaw::Sign(-2))).Equals(( Int32 ) -1));
		CxAssert(((Int32)(MathRaw::Sign(2))).Equals((( Int32 ) 1)));
		CxAssert(((Int32)(MathRaw::Sign(0))).Equals((( Int32 ) 0)));
		CxAssert(((Int32)(MathRaw::Sign(-2))).Equals(( Int32 ) -1));
		CxAssert(((Int32)(MathRaw::Sign(2))).Equals((( Int32 ) 1)));
		CxAssert(((Int32)(MathRaw::Sign(0))).Equals((( Int32 ) 0)));
		CxAssert(((Int32)(MathRaw::Sign(-2))).Equals(( Int32 ) -1));
		CxAssert(((Int32)(MathRaw::Sign(Double::Epsilon))).Equals((( Int32 ) 1)));
		CxAssert(MathRaw::Sin(0.5),0.479425538604203);
		CxAssert(MathRaw::Sinh(0.5),0.521095305493747);
		CxAssert(MathRaw::Sqrt(25),5);
		CxAssert(MathRaw::Tan(0.52),0.572561830251668);
		CxAssert(MathRaw::Tanh(0.52),0.477700012168498);
		Double x_num = ( Double ) Math::E;
		CxAssert(((Double)(Math::E)).Equals(( Double ) x_num));
		Double x_num2 = ( Double ) Math::PI;
		CxAssert(((Double)(Math::PI)).Equals(( Double ) x_num2));
		CxAssert(((Double)(MathRaw::Truncate(x_num2))).Equals((( Double ) 3)));
	}
	void MathTestRaw::DoubleCompare(Double x_n1,Double x_n2,Double x_resolution)
	{
		if ( MathRaw::Abs(x_n1 - ( Double ) x_n2) > ( Double ) x_resolution )
		{
			x_caBlock->TestFailed((new StringRaw("BaseTest TestFailed")));
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
			x_caBlock->TestFailed((new StringRaw("BaseTest TestFailed")));
		}
	}
	SByteTestRaw::SByteTestRaw(CABlock x_caBlock)
	{
		this->x_caBlock.Assign(x_caBlock);
	}
	void SByteTestRaw::Test()
	{
		x_caBlock->Send((new StringRaw("Doing SByteTest")));
		x_caBlock->Send((new StringRaw("\tDoing SByteMethodsTest")));
		SByteMethodsTest();
		x_caBlock->Send((new StringRaw("\tDoing SByteMathTest")));
		SByteMathTest();
		x_caBlock->Send((new StringRaw("\tDoing SByteOperators")));
		SByteOperators();
		x_caBlock->Send((new StringRaw("\tDoing SByteArrayTests")));
		SByteArrayTests();
		x_caBlock->Send((new StringRaw("\tDoing SByteMiscTests")));
		SByteMiscTests();
	}
	void SByteTestRaw::SByteMethodsTest()
	{
		SByte x_b = (( SByte ) 5);
		CxAssert(((Int32)((( SByte ) x_b).CompareTo(5))).Equals((( Int32 ) 0)));
		CxAssert(((Int32)((( SByte ) x_b).CompareTo((new SByteBox((( SByte ) 5) ))))).Equals((( Int32 ) 0)));
		CxAssert((( SByte ) x_b).Equals(5));
		CxAssert((( SByte ) x_b).Equals((new SByteBox((( SByte ) 5) ))));
		CxAssert(((SByte)(SByteRaw::Parse((new StringRaw("-55"))))).Equals(( SByte ) -55));
		CxAssert(((new StringRaw("-75")))->Equals(( -75 ).ToString()));
		String x_text = (( SByte ) ((SByte)127)).ToString();
		CxAssert((x_text)->Equals((new StringRaw("127"))));
		CxAssert(((SByte)(SByteRaw::Parse(x_text))).Equals(( SByte ) ((SByte)127)));
		String x_text2 = (( SByte ) ((SByte)-128)).ToString();
		CxAssert((x_text2)->Equals((new StringRaw("-128"))));
		CxAssert(((SByte)(SByteRaw::Parse(x_text2))).Equals(( SByte ) ((SByte)-128)));
		Int64 x_num = ( Int64 ) ((Int64)9223372036854775807);
		x_b = ( SByte ) ( SByte ) x_num;
		CxAssert(((SByte)(x_b)).Equals(( SByte ) -1));
		Object x_obj = (new SByteBox((( SByte ) 5) ));
		CxAssert(x_obj->Equals((( SByte ) 5)));
		CxAssert((x_obj->ToString())->Equals((new StringRaw("5"))));
	}
	void SByteTestRaw::SByteMathTest()
	{
		SByte x_b = (( SByte ) 6);
		SByte x_b2 = (( SByte ) 12);
		CxAssert(((Int32)(x_b + ( SByte ) x_b2)).Equals((( Int32 ) 18)));
		CxAssert(((Int32)(x_b - ( SByte ) x_b2)).Equals(( Int32 ) -6));
		CxAssert(((Int32)(x_b * ( SByte ) x_b2)).Equals((( Int32 ) 72)));
		CxAssert(((Int32)(x_b2 / ( SByte ) x_b)).Equals((( Int32 ) 2)));
		CxAssert(((Int32)(x_b >> (( Int32 ) 2))).Equals((( Int32 ) 1)));
		CxAssert(((Int32)(x_b << (( Int32 ) 1))).Equals((( Int32 ) 12)));
		Int32 x_num = (( Int32 ) 11);
		CxAssert(((Int32)(x_num % (( Int32 ) 5))).Equals((( Int32 ) 1)));
		x_num = (( Int32 ) 8);
		CxAssert(( x_num | (( Int32 ) 1) ) == (( Int32 ) 9));
		CxAssert(( x_num & (( Int32 ) 1) ) == (( Int32 ) 0));
		CxAssert(((Int32)(++x_num)).Equals((( Int32 ) 9)));
		CxAssert(((Int32)(--x_num)).Equals((( Int32 ) 8)));
		CxAssert(( x_num = x_num * (( Int32 ) 2) ) == (( Int32 ) 16));
		CxAssert(( x_num = x_num / (( Int32 ) 2) ) == (( Int32 ) 8));
		CxAssert(( x_num = x_num % (( Int32 ) 2) ) == (( Int32 ) 0));
		CxAssert(( x_num = x_num | (( Int32 ) 4) ) == (( Int32 ) 4));
		CxAssert(( x_num = x_num & (( Int32 ) 4) ) == (( Int32 ) 4));
		CxAssert(((Int32)(-x_b)).Equals(( Int32 ) -6));
		CxAssert(((SByte)(x_b)).Equals((( SByte ) 6)));
		x_num = (( Int32 ) 0);
		CxAssert(((Int32)(~x_num)).Equals(( Int32 ) -1));
		CxAssert(((Int32)(++x_num)).Equals((( Int32 ) 1)));
		CxAssert(((Int32)(--x_num)).Equals((( Int32 ) 0)));
		CxAssert(x_b < ( SByte ) x_b2);
		CxAssert(x_b <= ( SByte ) x_b2);
		CxAssert(x_b2 > ( SByte ) x_b);
		CxAssert(x_b2 >= ( SByte ) x_b);
	}
	void SByteTestRaw::SByteOperators()
	{
		SByte x_b = (( SByte ) 66);
		Char x_c = ( Char ) '';
		Byte x_b2 = (( Byte ) 1);
		SByte x_b3 = (( SByte ) 1);
		SByte x_b4 = (( SByte ) 1);
		Int32 x_num = (( Int32 ) 1);
		Int64 x_num2 = (( Int64 ) 1);
		UInt16 x_num3 = (( UInt16 ) 1);
		UInt32 x_num4 = (( UInt32 ) 1);
		Float x_num5 = (( Single ) 1);
		Double x_num6 = (( Double ) 1);
		CxAssert(((SByte)(x_b)).Equals((( SByte ) 66)));
		CxAssert(((Int32)(x_b + ( Char ) x_c)).Equals((( Int32 ) 67)));
		CxAssert(((Int32)(x_b + ( Byte ) x_b2)).Equals((( Int32 ) 67)));
		CxAssert(((Int32)(x_b + ( SByte ) x_b3)).Equals((( Int32 ) 67)));
		CxAssert(((Int32)(x_b + ( SByte ) x_b4)).Equals((( Int32 ) 67)));
		CxAssert(((Int32)(x_b + ( Int32 ) x_num)).Equals((( Int32 ) 67)));
		CxAssert(((Int64)(x_b + ( Int64 ) x_num2)).Equals((( Int64 ) 67)));
		CxAssert(((Int32)(x_b + ( UInt16 ) x_num3)).Equals((( Int32 ) 67)));
		CxAssert(((Int64)(x_b + ( UInt32 ) x_num4)).Equals((( Int64 ) 67)));
		CxAssert(((Single)(( Single ) x_b + ( Single ) x_num5)).Equals((( Single ) 67)));
		CxAssert(((Double)(( Double ) x_b + ( Double ) x_num6)).Equals((( Double ) 67)));
		CxAssert(((Int32)(x_b - ( Char ) x_c)).Equals((( Int32 ) 65)));
		CxAssert(((Int32)(x_b - ( Byte ) x_b2)).Equals((( Int32 ) 65)));
		CxAssert(((Int32)(x_b - ( SByte ) x_b3)).Equals((( Int32 ) 65)));
		CxAssert(((Int32)(x_b - ( SByte ) x_b4)).Equals((( Int32 ) 65)));
		CxAssert(((Int32)(x_b - ( Int32 ) x_num)).Equals((( Int32 ) 65)));
		CxAssert(((Int64)(x_b - ( Int64 ) x_num2)).Equals((( Int64 ) 65)));
		CxAssert(((Int32)(x_b - ( UInt16 ) x_num3)).Equals((( Int32 ) 65)));
		CxAssert(((Int64)(x_b - ( UInt32 ) x_num4)).Equals((( Int64 ) 65)));
		CxAssert(((Single)(( Single ) x_b - ( Single ) x_num5)).Equals((( Single ) 65)));
		CxAssert(((Double)(( Double ) x_b - ( Double ) x_num6)).Equals((( Double ) 65)));
		CxAssert(((Int32)(x_b * ( Char ) x_c)).Equals((( Int32 ) 66)));
		CxAssert(((Int32)(x_b * ( Byte ) x_b2)).Equals((( Int32 ) 66)));
		CxAssert(((Int32)(x_b * ( SByte ) x_b3)).Equals((( Int32 ) 66)));
		CxAssert(((Int32)(x_b * ( SByte ) x_b4)).Equals((( Int32 ) 66)));
		CxAssert(((Int32)(x_b * ( Int32 ) x_num)).Equals((( Int32 ) 66)));
		CxAssert(((Int64)(x_b * ( Int64 ) x_num2)).Equals((( Int64 ) 66)));
		CxAssert(((Int32)(x_b * ( UInt16 ) x_num3)).Equals((( Int32 ) 66)));
		CxAssert(((Int64)(x_b * ( UInt32 ) x_num4)).Equals((( Int64 ) 66)));
		CxAssert(((Single)(( Single ) x_b * ( Single ) x_num5)).Equals((( Single ) 66)));
		CxAssert(((Double)(( Double ) x_b * ( Double ) x_num6)).Equals((( Double ) 66)));
		CxAssert(((Int32)(( Int32 ) x_b / ( Int32 ) ( Int32 ) x_c)).Equals((( Int32 ) 66)));
		CxAssert(((Int32)(( Int32 ) x_b / ( Int32 ) ( Int32 ) x_b2)).Equals((( Int32 ) 66)));
		CxAssert(((Int32)(x_b / ( SByte ) x_b3)).Equals((( Int32 ) 66)));
		CxAssert(((Int32)(x_b / ( SByte ) x_b4)).Equals((( Int32 ) 66)));
		CxAssert(((Int32)(x_b / ( Int32 ) x_num)).Equals((( Int32 ) 66)));
		CxAssert(((Int64)(x_b / ( Int64 ) x_num2)).Equals((( Int64 ) 66)));
		CxAssert(((Int32)(( Int32 ) x_b / ( Int32 ) ( Int32 ) x_num3)).Equals((( Int32 ) 66)));
		CxAssert(((Int64)(( Int64 ) x_b / ( Int64 ) ( Int64 ) x_num4)).Equals((( Int64 ) 66)));
		CxAssert(((Single)(( Single ) x_b / ( Single ) x_num5)).Equals((( Single ) 66)));
		CxAssert(((Double)(( Double ) x_b / ( Double ) x_num6)).Equals((( Double ) 66)));
		CxAssert(((Int32)(( Int32 ) x_b % ( Int32 ) ( Int32 ) x_c)).Equals((( Int32 ) 0)));
		CxAssert(((Int32)(( Int32 ) x_b % ( Int32 ) ( Int32 ) x_b2)).Equals((( Int32 ) 0)));
		CxAssert(((Int32)(x_b % ( SByte ) x_b3)).Equals((( Int32 ) 0)));
		CxAssert(((Int32)(x_b % ( SByte ) x_b4)).Equals((( Int32 ) 0)));
		CxAssert(((Int32)(x_b % ( Int32 ) x_num)).Equals((( Int32 ) 0)));
		CxAssert(((Int64)(x_b % ( Int64 ) x_num2)).Equals((( Int64 ) 0)));
		CxAssert(((Int32)(( Int32 ) x_b % ( Int32 ) ( Int32 ) x_num3)).Equals((( Int32 ) 0)));
		CxAssert(((Int64)(( Int64 ) x_b % ( Int64 ) ( Int64 ) x_num4)).Equals((( Int64 ) 0)));
		CxAssert(((Single)(( Single ) x_b % ( Single ) x_num5)).Equals((( Single ) 0)));
		CxAssert(((Double)(( Double ) x_b % ( Double ) x_num6)).Equals((( Double ) 0)));
		CxAssert(( x_b & ( Char ) x_c ) == (( Int32 ) 0));
		CxAssert(( x_b & ( Byte ) x_b2 ) == (( Int32 ) 0));
		CxAssert(( x_b & ( SByte ) x_b3 ) == (( Int32 ) 0));
		CxAssert(( x_b & ( SByte ) x_b4 ) == (( Int32 ) 0));
		CxAssert(( x_b & ( Int32 ) x_num ) == (( Int32 ) 0));
		CxAssert(( x_b & ( Int64 ) x_num2 ) == (( Int32 ) 0));
		CxAssert(( x_b & ( UInt16 ) x_num3 ) == (( Int32 ) 0));
		CxAssert(( x_b & ( UInt32 ) x_num4 ) == (( Int32 ) 0));
		CxAssert(( x_b | ( Char ) x_c ) == (( Int32 ) 67));
		CxAssert(( x_b | ( Byte ) x_b2 ) == (( Int32 ) 67));
		CxAssert(( x_b | ( SByte ) x_b3 ) == (( Int32 ) 67));
		CxAssert(( x_b | ( SByte ) x_b4 ) == (( Int32 ) 67));
		CxAssert(( x_b | ( Int32 ) x_num ) == (( Int32 ) 67));
		CxAssert(( x_b | ( Int64 ) x_num2 ) == (( Int32 ) 67));
		CxAssert(( x_b | ( UInt16 ) x_num3 ) == (( Int32 ) 67));
		CxAssert(( x_b | ( UInt32 ) x_num4 ) == (( Int32 ) 67));
		CxAssert(( x_b ^ ( Char ) x_c ) == (( Int32 ) 67));
		CxAssert(( x_b ^ ( Byte ) x_b2 ) == (( Int32 ) 67));
		CxAssert(( x_b ^ ( SByte ) x_b3 ) == (( Int32 ) 67));
		CxAssert(( x_b ^ ( SByte ) x_b4 ) == (( Int32 ) 67));
		CxAssert(( x_b ^ ( Int32 ) x_num ) == (( Int32 ) 67));
		CxAssert(( x_b ^ ( Int64 ) x_num2 ) == (( Int32 ) 67));
		CxAssert(( x_b ^ ( UInt16 ) x_num3 ) == (( Int32 ) 67));
		CxAssert(( x_b ^ ( UInt32 ) x_num4 ) == (( Int32 ) 67));
		CxAssert(((Int32)(~x_b)).Equals(( Int32 ) -67));
		CxAssert(x_c < ( SByte ) x_b);
		CxAssert(x_b2 < ( SByte ) x_b);
		CxAssert(x_b3 < ( SByte ) x_b);
		CxAssert(x_b4 < ( SByte ) x_b);
		CxAssert(x_num < ( SByte ) x_b);
		CxAssert(x_num2 < ( SByte ) x_b);
		CxAssert(x_num3 < ( SByte ) x_b);
		CxAssert(x_num4 < ( SByte ) x_b);
		CxAssert(x_num5 < ( Single ) ( Single ) x_b);
		CxAssert(x_num6 < ( Double ) ( Double ) x_b);
		CxAssert(x_c > ( SByte ) x_b,false);
		CxAssert(x_b2 > ( SByte ) x_b,false);
		CxAssert(x_b3 > ( SByte ) x_b,false);
		CxAssert(x_b4 > ( SByte ) x_b,false);
		CxAssert(x_num > ( SByte ) x_b,false);
		CxAssert(x_num2 > ( SByte ) x_b,false);
		CxAssert(x_num3 > ( SByte ) x_b,false);
		CxAssert(x_num4 > ( SByte ) x_b,false);
		CxAssert(x_num5 > ( Single ) ( Single ) x_b,false);
		CxAssert(x_num6 > ( Double ) ( Double ) x_b,false);
		CxAssert(( x_b = ( SByte ) ( SByte ) ( x_b + (( Int32 ) 1) ) ) == (( Int32 ) 67));
		CxAssert(( x_b = ( SByte ) ( SByte ) ( x_b - (( Int32 ) 1) ) ) == (( Int32 ) 66));
		CxAssert(((SByte)(x_b++)).Equals((( SByte ) 66)));
		CxAssert(((SByte)(x_b--)).Equals((( SByte ) 67)));
		CxAssert(((Int32)(x_b << (( Int32 ) 1))).Equals((( Int32 ) 132)));
		CxAssert(((Int32)(x_b >> (( Int32 ) 1))).Equals((( Int32 ) 33)));
		CxAssert(((Char)(x_c)).Equals(( Char ) x_b),false);
		CxAssert(((Byte)(x_b2)).Equals(( Byte ) x_b),false);
		CxAssert(((SByte)(x_b3)).Equals(( SByte ) x_b),false);
		CxAssert(((SByte)(x_b4)).Equals(( SByte ) x_b),false);
		CxAssert(((Int32)(x_num)).Equals(( Int32 ) x_b),false);
		CxAssert(((Int64)(x_num2)).Equals(( Int64 ) x_b),false);
		CxAssert(((UInt16)(x_num3)).Equals(( UInt16 ) x_b),false);
		CxAssert(((UInt32)(x_num4)).Equals(( UInt32 ) x_b),false);
		CxAssert(((Single)(x_num5)).Equals(( Single ) ( Single ) x_b),false);
		CxAssert(((Double)(x_num6)).Equals(( Double ) ( Double ) x_b),false);
		CxAssert(!((Char)(x_c)).Equals(( Char ) x_b));
		CxAssert(!((Byte)(x_b2)).Equals(( Byte ) x_b));
		CxAssert(!((SByte)(x_b3)).Equals(( SByte ) x_b));
		CxAssert(!((SByte)(x_b4)).Equals(( SByte ) x_b));
		CxAssert(!((Int32)(x_num)).Equals(( Int32 ) x_b));
		CxAssert(!((Int64)(x_num2)).Equals(( Int64 ) x_b));
		CxAssert(!((UInt16)(x_num3)).Equals(( UInt16 ) x_b));
		CxAssert(!((UInt32)(x_num4)).Equals(( UInt32 ) x_b));
		CxAssert(!((Single)(x_num5)).Equals(( Single ) ( Single ) x_b));
		CxAssert(!((Double)(x_num6)).Equals(( Double ) ( Double ) x_b));
		CxAssert(x_c <= ( SByte ) x_b);
		CxAssert(x_b2 <= ( SByte ) x_b);
		CxAssert(x_b3 <= ( SByte ) x_b);
		CxAssert(x_b4 <= ( SByte ) x_b);
		CxAssert(x_num <= ( SByte ) x_b);
		CxAssert(x_num2 <= ( SByte ) x_b);
		CxAssert(x_num3 <= ( SByte ) x_b);
		CxAssert(x_num4 <= ( SByte ) x_b);
		CxAssert(x_num5 <= ( Single ) ( Single ) x_b);
		CxAssert(x_num6 <= ( Double ) ( Double ) x_b);
		CxAssert(x_c >= ( SByte ) x_b,false);
		CxAssert(x_b2 >= ( SByte ) x_b,false);
		CxAssert(x_b3 >= ( SByte ) x_b,false);
		CxAssert(x_b4 >= ( SByte ) x_b,false);
		CxAssert(x_num >= ( SByte ) x_b,false);
		CxAssert(x_num2 >= ( SByte ) x_b,false);
		CxAssert(x_num3 >= ( SByte ) x_b,false);
		CxAssert(x_num4 >= ( SByte ) x_b,false);
		CxAssert(x_num5 >= ( Single ) ( Single ) x_b,false);
		CxAssert(x_num6 >= ( Double ) ( Double ) x_b,false);
		CxAssert(( x_b = ( SByte ) ( SByte ) ( x_b + ( SByte ) ( SByte ) x_c ) ) == (( Int32 ) 67));
		CxAssert(( x_b = ( SByte ) ( SByte ) ( x_b - ( SByte ) ( SByte ) x_c ) ) == (( Int32 ) 66));
		CxAssert(( x_b = ( SByte ) ( SByte ) ( x_b + ( SByte ) ( SByte ) x_num ) ) == (( Int32 ) 67));
		CxAssert(( x_b = ( SByte ) ( SByte ) ( x_b - ( SByte ) ( SByte ) x_num ) ) == (( Int32 ) 66));
		CxAssert(( x_b = ( SByte ) ( SByte ) ( x_b * ( SByte ) ( SByte ) x_c ) ) == (( Int32 ) 66));
		CxAssert(( x_b = ( SByte ) ( SByte ) ( x_b / ( SByte ) ( SByte ) x_c ) ) == (( Int32 ) 66));
		CxAssert(( x_b = ( SByte ) ( SByte ) ( x_b * ( SByte ) ( SByte ) x_num ) ) == (( Int32 ) 66));
		CxAssert(( x_b = ( SByte ) ( SByte ) ( x_b / ( SByte ) ( SByte ) x_num ) ) == (( Int32 ) 66));
		CxAssert(( x_b = ( SByte ) ( SByte ) ( x_b % ( SByte ) ( SByte ) x_c ) ) == (( Int32 ) 0));
		x_b = (( SByte ) 66);
		CxAssert(( x_b = ( SByte ) ( SByte ) ( x_b % ( SByte ) ( SByte ) x_num ) ) == (( Int32 ) 0));
		x_b = (( SByte ) 66);
		CxAssert(( x_b = ( SByte ) ( SByte ) ( x_b & ( SByte ) ( SByte ) x_c ) ) == (( Int32 ) 0));
		x_b = (( SByte ) 66);
		CxAssert(( x_b = ( SByte ) ( SByte ) ( x_b & ( SByte ) ( SByte ) x_num ) ) == (( Int32 ) 0));
		x_b = (( SByte ) 66);
		CxAssert(( x_b = ( SByte ) ( SByte ) ( x_b | ( SByte ) ( SByte ) x_c ) ) == (( Int32 ) 67));
		x_b = (( SByte ) 66);
		CxAssert(( x_b = ( SByte ) ( SByte ) ( x_b | ( SByte ) ( SByte ) x_num ) ) == (( Int32 ) 67));
		x_b = (( SByte ) 66);
		CxAssert(( x_b = ( SByte ) ( SByte ) ( x_b ^ ( SByte ) ( SByte ) x_c ) ) == (( Int32 ) 67));
		x_b = (( SByte ) 66);
		CxAssert(( x_b = ( SByte ) ( SByte ) ( x_b ^ ( SByte ) ( SByte ) x_num ) ) == (( Int32 ) 67));
		x_b = (( SByte ) 66);
		CxAssert(( x_b = ( SByte ) ( SByte ) ( x_b << ( Int32 ) ( Int32 ) x_b2 ) ) == ( Int32 ) -124);
		x_b = (( SByte ) 66);
		CxAssert(( x_b = ( SByte ) ( SByte ) ( x_b << ( Int32 ) ( Int32 ) x_b4 ) ) == ( Int32 ) -124);
		x_b = (( SByte ) 66);
		CxAssert(( x_b = ( SByte ) ( SByte ) ( x_b << ( Int32 ) ( Int32 ) x_c ) ) == ( Int32 ) -124);
		x_b = (( SByte ) 66);
		CxAssert(( x_b = ( SByte ) ( SByte ) ( x_b << ( Int32 ) x_num ) ) == ( Int32 ) -124);
		x_b = (( SByte ) 66);
		CxAssert(( x_b = ( SByte ) ( SByte ) ( x_b >> ( Int32 ) ( Int32 ) x_c ) ) == (( Int32 ) 33));
		x_b = (( SByte ) 66);
		CxAssert(( x_b = ( SByte ) ( SByte ) ( x_b >> ( Int32 ) x_num ) ) == (( Int32 ) 33));
		x_b = (( SByte ) 66);
		SByte x_b5 = (( SByte ) 0);
		CxAssert(((SByte)(x_b5)).Equals((( SByte ) 0)));
		CxAssert(((SByte)(x_b5)).Equals((( SByte ) 0)));
		CxAssert(x_num <= (( Int32 ) 2));
		CxAssert(x_num >= ( Int32 ) -2);
	}
	void SByteTestRaw::SByteArrayTests()
	{
		static SByte SByteArrayTestsArray0[5] = {1,2,3,4,5};
		static SByte SByteArrayTestsArray1[4] = {1,2,3,4};
		static SByte SByteArrayTestsArray2[2][4] = {{1,2,3,4},{4,5,6,7}};
		static SByte SByteArrayTestsArray3[2][2][4] = {{{1,2,3,4},{5,6,7,8}},{{9,10,11,12},{13,14,15,16}}};
		PointerType<ArrayRaw<SByte>> x_array = (new ArrayRaw<SByte>(5))->Initialize((SByte*) SByteArrayTestsArray0);
		CxAssert(((Int32)(x_array->get_Length())).Equals((( Int32 ) 5)));
		CxAssert(((SByte)((*x_array->Address(3)))).Equals((( SByte ) 4)));
		PointerType<ArrayRaw<SByte>> x_array2 = (new ArrayRaw<SByte>(4))->Initialize((SByte*) SByteArrayTestsArray1);
		CxAssert(((SByte)((*x_array2->Address(1)))).Equals((( SByte ) 2)));
		PointerType<ArrayRaw<SByte>> x_array3 = (new ArrayRaw<SByte>(2,4))->Initialize((SByte*) SByteArrayTestsArray2);
		CxAssert(((SByte)((*x_array3->Address(0,2)))).Equals((( SByte ) 3)));
		PointerType<ArrayRaw<SByte>> x_array4 = (new ArrayRaw<SByte>(2,2,4))->Initialize((SByte*) SByteArrayTestsArray3);
		CxAssert(((SByte)((*x_array4->Address(0,0,3)))).Equals((( SByte ) 4)));
		(*x_array4->Address(0,0,3)) = (( SByte ) 6);
		CxAssert(((SByte)((*x_array4->Address(0,0,3)))).Equals((( SByte ) 6)));
		x_array4->SetValue((( SByte ) 4),0,0,3);
		CxAssert(((SByte)((*x_array4->Address(0,0,3)))).Equals((( SByte ) 4)));
	}
	void SByteTestRaw::SByteMiscTests()
	{
		SByte x_b = ( SByte ) -1;
		SByte x_val = (( SByte ) 1);
		CxAssert(((SByte)(MathRaw::Abs(x_b))).Equals((( SByte ) 1)));
		CxAssert(((SByte)(MathRaw::Max(x_b,x_val))).Equals((( SByte ) 1)));
		CxAssert(((SByte)(MathRaw::Min(x_b,x_val))).Equals(( SByte ) -1));
		CxAssert(MathRaw::Sign(x_b) < (( Int32 ) 0));
		PointerType<StringBuilderRaw> x_stringBuilder = new StringBuilderRaw();
		x_stringBuilder->Append(x_b);
		CxAssert((x_stringBuilder->ToString())->Equals((new StringRaw("-1"))));
		x_stringBuilder->Insert(2,x_b);
		CxAssert((x_stringBuilder->ToString())->Equals((new StringRaw("-1-1"))));
	}
	void SByteTestRaw::CxAssert(Boolean x_x)
	{
		if ( !x_x )
		{
			x_caBlock->TestFailed((new StringRaw("SByte TestFailed")));
		}
	}
	void SByteTestRaw::CxAssert(Boolean x_x,Boolean x_y)
	{
		if ( !(x_x).Equals(x_y) )
		{
			x_caBlock->TestFailed((new StringRaw("SByte TestFailed")));
		}
	}
	SingleTestRaw::SingleTestRaw(CABlock x_caBlock)
	{
		this->x_caBlock.Assign(x_caBlock);
	}
	void SingleTestRaw::Test()
	{
		x_caBlock->Send((new StringRaw("Doing SingleTest")));
		x_caBlock->Send((new StringRaw("\tDoing DoSingleMethodsTest")));
		DoSingleMethodsTest();
		x_caBlock->Send((new StringRaw("\tDoing DoSingleMath")));
		DoSingleMath();
		x_caBlock->Send((new StringRaw("\tDoing SingleOperators")));
		SingleOperators();
		x_caBlock->Send((new StringRaw("\tDoing SingleNanTest")));
		SingleNanTest();
		x_caBlock->Send((new StringRaw("\tDoing SingleArrayTest")));
		SingleArrayTest();
		x_caBlock->Send((new StringRaw("\tDoing SingleMiscTests")));
		SingleMiscTests();
	}
	void SingleTestRaw::DoSingleMethodsTest()
	{
		Float x_num = (( Single ) 3.159);
		CxAssert(((Int32)((( Single ) x_num).CompareTo(3.159))).Equals((( Int32 ) 0)));
		CxAssert(((Int32)((( Single ) x_num).CompareTo((new SingleBox(3.159 ))))).Equals((( Int32 ) 0)));
		CxAssert((( Single ) x_num).Equals(3.159));
		CxAssert(SingleRaw::Parse((new StringRaw("3.159"))),3.15899991989136);
		CxAssert(((( Single ) x_num).ToString())->Equals((new StringRaw("3.159"))));
		CxAssert(SingleRaw::Parse((( Single ) x_num).ToString()),x_num);
		x_num = (( Single ) 1E+07);
		CxAssert(x_num > (( Single ) 1E+07));
		x_num = ( Single ) -1E+07;
		CxAssert(x_num <= ( Single ) -1E+07);
		x_num = (( Single ) 10000);
		CxAssert(((Int64)(( Int64 ) x_num)).Equals((( Int64 ) 10000)));
		CxAssert(((Int32)(( Int32 ) x_num)).Equals((( Int32 ) 10000)));
		CxAssert(((UInt32)(( UInt32 ) x_num)).Equals((( UInt32 ) 10000)));
		Object x_obj = (new SingleBox(x_num ));
		CxAssert(((Double)(( Double ) ( Single ) x_obj->get_AsSingle())).Equals((( Double ) 10000)));
		x_num = ( Single ) Float::Epsilon;
		CxAssert(((Single)(x_num)).Equals(( Single ) Float::Epsilon));
		x_num = ( Single ) ((Single)3.402823E+38);
		CxAssert(((Single)(x_num)).Equals(( Single ) ((Single)3.402823E+38)));
		x_num = ( Single ) ((Single)-3.402823E+38);
		CxAssert(((Single)(x_num)).Equals(( Single ) ((Single)-3.402823E+38)));
		x_obj.Assign(5);
		CxAssert(x_obj->Equals(5));
		CxAssert((x_obj->ToString())->Equals((new StringRaw("5"))));
	}
	void SingleTestRaw::DoSingleMath()
	{
		Float x_num = (( Single ) 355);
		Float x_num2 = (( Single ) 113);
		Float x_num3 = ( Single ) x_num / ( Single ) x_num2;
		CxAssert(x_num3,3.14159);
		CxAssert(x_num3 * ( Single ) x_num2,355);
		CxAssert(x_num + ( Single ) x_num2,468);
		CxAssert(x_num - ( Single ) x_num2,242);
		x_num = (( Single ) 1);
		x_num2 = ( Single ) x_num + ( Single ) Float::Epsilon;
		CxAssert(((Double)(( Double ) x_num2)).Equals((( Double ) 1)));
	}
	void SingleTestRaw::SingleOperators()
	{
		Float x_num = (( Single ) 66);
		Char x_c = ( Char ) '';
		Int32 x_num2 = (( Int32 ) 1);
		UInt32 x_num3 = (( UInt32 ) 1);
		Int64 x_num4 = (( Int64 ) 1);
		Double x_num5 = (( Double ) 1);
		CxAssert(((Single)(x_num)).Equals((( Single ) 66)));
		CxAssert(((Single)(x_num + ( Single ) ( Single ) ( Int32 ) x_c)).Equals((( Single ) 67)));
		CxAssert(((Single)(x_num + ( Single ) ( Single ) x_num2)).Equals((( Single ) 67)));
		CxAssert(((Single)(x_num + ( Single ) ( Single ) x_num3)).Equals((( Single ) 67)));
		CxAssert(((Single)(x_num + ( Single ) ( Single ) x_num4)).Equals((( Single ) 67)));
		CxAssert(((Double)(( Double ) x_num + ( Double ) x_num5)).Equals((( Double ) 67)));
		CxAssert(((Single)(x_num - ( Single ) ( Single ) ( Int32 ) x_c)).Equals((( Single ) 65)));
		CxAssert(((Single)(x_num - ( Single ) ( Single ) x_num2)).Equals((( Single ) 65)));
		CxAssert(((Single)(x_num - ( Single ) ( Single ) x_num3)).Equals((( Single ) 65)));
		CxAssert(((Single)(x_num - ( Single ) ( Single ) x_num4)).Equals((( Single ) 65)));
		CxAssert(((Double)(( Double ) x_num - ( Double ) x_num5)).Equals((( Double ) 65)));
		CxAssert(((Single)(x_num * ( Single ) ( Single ) ( Int32 ) x_c)).Equals((( Single ) 66)));
		CxAssert(((Single)(x_num * ( Single ) ( Single ) x_num2)).Equals((( Single ) 66)));
		CxAssert(((Single)(x_num * ( Single ) ( Single ) x_num3)).Equals((( Single ) 66)));
		CxAssert(((Single)(x_num * ( Single ) ( Single ) x_num4)).Equals((( Single ) 66)));
		CxAssert(((Double)(( Double ) x_num * ( Double ) x_num5)).Equals((( Double ) 66)));
		CxAssert(((Single)(x_num / ( Single ) ( Single ) ( Int32 ) x_c)).Equals((( Single ) 66)));
		CxAssert(((Single)(x_num / ( Single ) ( Single ) x_num2)).Equals((( Single ) 66)));
		CxAssert(((Single)(x_num / ( Single ) ( Single ) x_num3)).Equals((( Single ) 66)));
		CxAssert(((Single)(x_num / ( Single ) ( Single ) x_num4)).Equals((( Single ) 66)));
		CxAssert(((Double)(( Double ) x_num / ( Double ) x_num5)).Equals((( Double ) 66)));
		CxAssert(((Single)(x_num % ( Single ) ( Single ) ( Int32 ) x_c)).Equals((( Single ) 0)));
		CxAssert(((Single)(x_num % ( Single ) ( Single ) x_num2)).Equals((( Single ) 0)));
		CxAssert(((Single)(x_num % ( Single ) ( Single ) x_num3)).Equals((( Single ) 0)));
		CxAssert(((Single)(x_num % ( Single ) ( Single ) x_num4)).Equals((( Single ) 0)));
		CxAssert(((Double)(( Double ) x_num % ( Double ) x_num5)).Equals((( Double ) 0)));
		CxAssert(( Single ) ( Int32 ) x_c < ( Single ) x_num);
		CxAssert(( Single ) x_num2 < ( Single ) x_num);
		CxAssert(( Single ) x_num3 < ( Single ) x_num);
		CxAssert(( Single ) x_num4 < ( Single ) x_num);
		CxAssert(x_num5 < ( Double ) ( Double ) x_num);
		CxAssert(( Single ) ( Int32 ) x_c > ( Single ) x_num,false);
		CxAssert(( Single ) x_num2 > ( Single ) x_num,false);
		CxAssert(( Single ) x_num3 > ( Single ) x_num,false);
		CxAssert(( Single ) x_num4 > ( Single ) x_num,false);
		CxAssert(x_num5 > ( Double ) ( Double ) x_num,false);
		CxAssert(( x_num = x_num + (( Single ) 1) ) == (( Single ) 67));
		CxAssert(( x_num = x_num - (( Single ) 1) ) == (( Single ) 66));
		CxAssert(((Single)(x_num++)).Equals((( Single ) 66)));
		CxAssert(((Single)(x_num--)).Equals((( Single ) 67)));
		CxAssert(((Single)(( Single ) ( Int32 ) x_c)).Equals(( Single ) x_num),false);
		CxAssert(((Single)(( Single ) x_num2)).Equals(( Single ) x_num),false);
		CxAssert(((Single)(( Single ) x_num3)).Equals(( Single ) x_num),false);
		CxAssert(((Single)(( Single ) x_num4)).Equals(( Single ) x_num),false);
		CxAssert(((Double)(x_num5)).Equals(( Double ) ( Double ) x_num),false);
		CxAssert(!((Single)(( Single ) ( Int32 ) x_c)).Equals(( Single ) x_num));
		CxAssert(!((Single)(( Single ) x_num2)).Equals(( Single ) x_num));
		CxAssert(!((Single)(( Single ) x_num3)).Equals(( Single ) x_num));
		CxAssert(!((Single)(( Single ) x_num4)).Equals(( Single ) x_num));
		CxAssert(!((Double)(x_num5)).Equals(( Double ) ( Double ) x_num));
		CxAssert(( Single ) ( Int32 ) x_c <= ( Single ) x_num);
		CxAssert(( Single ) x_num2 <= ( Single ) x_num);
		CxAssert(( Single ) x_num3 <= ( Single ) x_num);
		CxAssert(( Single ) x_num4 <= ( Single ) x_num);
		CxAssert(x_num5 <= ( Double ) ( Double ) x_num);
		CxAssert(( Single ) ( Int32 ) x_c >= ( Single ) x_num,false);
		CxAssert(( Single ) x_num2 >= ( Single ) x_num,false);
		CxAssert(( Single ) x_num3 >= ( Single ) x_num,false);
		CxAssert(( Single ) x_num4 >= ( Single ) x_num,false);
		CxAssert(x_num5 >= ( Double ) ( Double ) x_num,false);
		CxAssert(( x_num = x_num + ( Single ) ( Single ) ( Int32 ) x_c ) == (( Single ) 67));
		CxAssert(( x_num = x_num - ( Single ) ( Single ) ( Int32 ) x_c ) == (( Single ) 66));
		CxAssert(( x_num = x_num + ( Single ) ( Single ) x_num2 ) == (( Single ) 67));
		CxAssert(( x_num = x_num - ( Single ) ( Single ) x_num2 ) == (( Single ) 66));
		CxAssert(( x_num = x_num + ( Single ) ( Single ) x_num3 ) == (( Single ) 67));
		CxAssert(( x_num = x_num - ( Single ) ( Single ) x_num3 ) == (( Single ) 66));
		CxAssert(( x_num = x_num + ( Single ) ( Single ) x_num4 ) == (( Single ) 67));
		CxAssert(( x_num = x_num - ( Single ) ( Single ) x_num4 ) == (( Single ) 66));
		CxAssert(( x_num = x_num * ( Single ) ( Single ) ( Int32 ) x_c ) == (( Single ) 66));
		CxAssert(( x_num = x_num / ( Single ) ( Single ) ( Int32 ) x_c ) == (( Single ) 66));
		CxAssert(( x_num = x_num * ( Single ) ( Single ) x_num2 ) == (( Single ) 66));
		CxAssert(( x_num = x_num / ( Single ) ( Single ) x_num2 ) == (( Single ) 66));
		CxAssert(( x_num = x_num * ( Single ) ( Single ) x_num3 ) == (( Single ) 66));
		CxAssert(( x_num = x_num / ( Single ) ( Single ) x_num3 ) == (( Single ) 66));
		CxAssert(( x_num = x_num * ( Single ) ( Single ) x_num4 ) == (( Single ) 66));
		CxAssert(( x_num = x_num / ( Single ) ( Single ) x_num4 ) == (( Single ) 66));
		CxAssert(( x_num = x_num % ( Single ) ( Single ) ( Int32 ) x_c ) == (( Single ) 0));
		x_num = (( Single ) 66);
		CxAssert(( x_num = x_num % ( Single ) ( Single ) x_num2 ) == (( Single ) 0));
		x_num = (( Single ) 5);
		CxAssert(( Double ) x_num % (( Double ) 2.2),0.6);
	}
	void SingleTestRaw::SingleNanTest()
	{
		Float x_num = ( Single ) Float::NaN;
		Float x_num2 = (( Single ) 1);
		CxAssert(SingleRaw::IsNaN(x_num));
		CxAssert(SingleRaw::IsInfinity(Float::PositiveInfinity));
		CxAssert(SingleRaw::IsNegativeInfinity(Float::NegativeInfinity));
		CxAssert(SingleRaw::IsPositiveInfinity(Float::PositiveInfinity));
		CxAssert(SingleRaw::IsNaN(x_num * ( Single ) x_num2));
		CxAssert(SingleRaw::IsNaN(x_num / ( Single ) x_num2));
		CxAssert(SingleRaw::IsNaN(x_num + ( Single ) x_num2));
		CxAssert(SingleRaw::IsNaN(x_num - ( Single ) x_num2));
		CxAssert(SingleRaw::IsNaN(x_num % ( Single ) x_num2));
		CxAssert(x_num < ( Single ) x_num2,false);
		CxAssert(x_num > ( Single ) x_num2,false);
		CxAssert(x_num <= ( Single ) x_num2,false);
		CxAssert(x_num >= ( Single ) x_num2,false);
		CxAssert(((Single)(x_num)).Equals(( Single ) x_num2),false);
		CxAssert(((Single)(x_num)).Equals(( Single ) x_num),false);
		CxAssert(x_num2 < ( Single ) x_num,false);
		CxAssert(x_num2 > ( Single ) x_num,false);
		CxAssert(x_num2 <= ( Single ) x_num,false);
		CxAssert(x_num2 >= ( Single ) x_num,false);
		CxAssert(!((Single)(x_num)).Equals(( Single ) x_num2));
		CxAssert(!((Single)(x_num)).Equals(( Single ) x_num));
		x_num = ( Single ) Float::NaN;
		x_num2 = ( Single ) Float::NaN;
		if ( ((Single)(x_num)).Equals(( Single ) x_num2) )
		{
			SingleTestFailed();
		}
		else
		{
			CxAssert(true);
		}
		if ( ((Single)(x_num)).Equals(( Single ) x_num) )
		{
			SingleTestFailed();
		}
		else
		{
			CxAssert(true);
		}
		if ( !((Single)(x_num)).Equals(( Single ) x_num2) )
		{
			CxAssert(true);
		}
		else
		{
			SingleTestFailed();
		}
		if ( !((Single)(x_num)).Equals(( Single ) x_num) )
		{
			CxAssert(true);
		}
		else
		{
			SingleTestFailed();
		}
		if ( x_num > ( Single ) x_num2 )
		{
			SingleTestFailed();
		}
		else
		{
			CxAssert(true);
		}
		if ( x_num >= ( Single ) x_num2 )
		{
			SingleTestFailed();
		}
		else
		{
			CxAssert(true);
		}
		if ( x_num < ( Single ) x_num2 )
		{
			SingleTestFailed();
		}
		else
		{
			CxAssert(true);
		}
		if ( x_num <= ( Single ) x_num2 )
		{
			SingleTestFailed();
		}
		else
		{
			CxAssert(true);
		}
		if ( ((Single)(x_num)).Equals((( Single ) 0)) )
		{
			SingleTestFailed();
		}
		else
		{
			CxAssert(true);
		}
		CxAssert((( Single ) Float::NaN).Equals(Float::NaN));
	}
	void SingleTestRaw::SingleArrayTest()
	{
		static Float SingleArrayTestArray0[4] = {1,2,3,4};
		static Float SingleArrayTestArray1[2][4] = {{1,2,3,4},{4,5,6,7}};
		static Float SingleArrayTestArray2[2][2][4] = {{{1,2,3,4},{5,6,7,8}},{{9,10,11,12},{13,14,15,16}}};
		PointerType<ArrayRaw<Single>> x_array = (new ArrayRaw<Float>(4))->Initialize((Float*) SingleArrayTestArray0);
		CxAssert(((Single)((*x_array->Address(1)))).Equals((( Single ) 2)));
		PointerType<ArrayRaw<Single>> x_array2 = (new ArrayRaw<Float>(2,4))->Initialize((Float*) SingleArrayTestArray1);
		CxAssert(((Single)((*x_array2->Address(0,2)))).Equals((( Single ) 3)));
		PointerType<ArrayRaw<Single>> x_array3 = (new ArrayRaw<Float>(2,2,4))->Initialize((Float*) SingleArrayTestArray2);
		CxAssert(((Single)((*x_array3->Address(0,0,3)))).Equals((( Single ) 4)));
		(*x_array3->Address(0,0,3)) = (( Single ) 22);
		CxAssert(((Single)((*x_array3->Address(0,0,3)))).Equals((( Single ) 22)));
		(*x_array2->Address(0,2)) = ( Single ) Float::NaN;
		CxAssert(SingleRaw::IsNaN((*x_array2->Address(0,2))));
		x_array3->SetValue(4,0,0,3);
		CxAssert(((Single)((*x_array3->Address(0,0,3)))).Equals((( Single ) 4)));
	}
	void SingleTestRaw::SingleMiscTests()
	{
		Float x_num = ( Single ) -1;
		Float x_val = (( Single ) 1);
		CxAssert(((Single)(MathRaw::Abs(x_num))).Equals((( Single ) 1)));
		CxAssert(((Single)(MathRaw::Max(x_num,x_val))).Equals((( Single ) 1)));
		CxAssert(((Single)(MathRaw::Min(x_num,x_val))).Equals(( Single ) -1));
		CxAssert(MathRaw::Sign(x_num) < (( Int32 ) 0));
		PointerType<StringBuilderRaw> x_stringBuilder = new StringBuilderRaw();
		x_stringBuilder->Append(x_num);
		CxAssert((x_stringBuilder->ToString())->Equals((new StringRaw("-1"))));
		x_stringBuilder->Insert(2,x_num);
		CxAssert((x_stringBuilder->ToString())->Equals((new StringRaw("-1-1"))));
	}
	void SingleTestRaw::SingleCompare(Double x_n1,Double x_n2,Double x_resolution)
	{
		Double x_num = ( Double ) MathRaw::Abs(x_n1 - ( Double ) x_n2);
		if ( x_num > ( Double ) x_resolution )
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
		if ( !(x_x).Equals(x_y) )
		{
			SingleTestFailed();
		}
	}
	void SingleTestRaw::SingleTestFailed()
	{
		x_caBlock->TestFailed((new StringRaw("Single TestFailed")));
	}
	StringBuilderTestRaw::StringBuilderTestRaw(CABlock x_caBlock)
	{
		x_sb = new StringBuilderRaw();
		this->x_caBlock.Assign(x_caBlock);
	}
	void StringBuilderTestRaw::Test()
	{
		x_caBlock->Send((new StringRaw("Doing StringBuilderTest")));
		x_caBlock->Send((new StringRaw("\tDoing DoSBConstructTest")));
		DoSBConstructTest();
		x_caBlock->Send((new StringRaw("\tDoing DoSBPropertyTest")));
		DoSBPropertyTest();
		x_caBlock->Send((new StringRaw("\tDoing DoSBAppendTest")));
		DoSBAppendTest();
		x_caBlock->Send((new StringRaw("\tDoing DoSBMiscTest")));
		DoSBMiscTest();
		x_caBlock->Send((new StringRaw("\tDoing DoSBInsertTest")));
		DoSBInsertTest();
		x_caBlock->Send((new StringRaw("\tDoing DoSBReplaceTest")));
		DoSBReplaceTest();
	}
	void StringBuilderTestRaw::DoSBConstructTest()
	{
		static Char DoSBConstructTestArray0[12] = {'A','B','','','	','','','','
','"',''','Â'};
		CxAssert(((Int32)(x_sb->get_Length())).Equals((( Int32 ) 0)));
		x_sb.Assign(new StringBuilderRaw(100));
		CxAssert(((Int32)(x_sb->get_Capacity())).Equals((( Int32 ) 100)));
		x_sb.Assign(new StringBuilderRaw((new StringRaw("Test"))));
		CxAssert((x_sb->ToString())->Equals((new StringRaw("Test"))));
		x_sb.Assign(new StringBuilderRaw(20,25));
		CxAssert(((Int32)(x_sb->get_Capacity())).Equals((( Int32 ) 20)) && ((Int32)(x_sb->get_MaxCapacity())).Equals((( Int32 ) 25)));
		x_sb.Assign(new StringBuilderRaw((new StringRaw("Test")),20));
		CxAssert((x_sb->ToString())->Equals((new StringRaw("Test"))) && ((Int32)(x_sb->get_Capacity())).Equals((( Int32 ) 20)));
		x_sb.Assign(new StringBuilderRaw((new StringRaw("test1234")),1,4,20));
		CxAssert((x_sb->ToString())->Equals((new StringRaw("est1"))) && ((Int32)(x_sb->get_Capacity())).Equals((( Int32 ) 20)));
		String x_a = new StringBuilderRaw((new StringRaw("Test")))->ToString();
		CxAssert((x_a)->Equals((new StringRaw("Test"))));
		String x_b = (new StringRaw("AB\a\b\t\r\v\f\n\"'\u00c2"));
		PointerType<ArrayRaw<Char>> x_value = (new ArrayRaw<Char>(12))->Initialize((Char*) DoSBConstructTestArray0);
		x_sb.Assign(new StringBuilderRaw());
		x_sb->Append(x_value);
		String x_text = x_sb->ToString();
		CxAssert((x_sb->ToString())->Equals(x_b));
	}
	void StringBuilderTestRaw::DoSBPropertyTest()
	{
		x_sb.Assign(new StringBuilderRaw((new StringRaw("Testing123")),0,10,20));
		CxAssert(((Int32)(x_sb->get_Capacity())).Equals((( Int32 ) 20)) && ((Int32)(x_sb->get_MaxCapacity())).Equals(( Int32 ) ((Int32)2147483647)));
		CxAssert(((Char)((*x_sb->Address(7)))).Equals(( Char ) '1'));
		CxAssert(((Int32)(x_sb->get_Length())).Equals((( Int32 ) 10)));
		x_sb->set_Length(7);
		CxAssert(((Int32)(x_sb->get_Length())).Equals((( Int32 ) 7)));
		x_sb->set_Capacity(22);
		CxAssert(((Int32)(x_sb->get_Capacity())).Equals((( Int32 ) 22)));
		(*x_sb->Address(0)) = ( Char ) 't';
		CxAssert((x_sb->ToString())->Equals((new StringRaw("testing"))));
	}
	void StringBuilderTestRaw::DoSBAppendTest()
	{
		static Char DoSBAppendTestArray0[4] = {'0','1','2','3'};
		static Object DoSBAppendTestArray1[4] = {0,1,2,3};
		x_sb->set_Length(0);
		x_sb->Append(true);
		CxAssert((x_sb->ToString())->Equals((new StringRaw("True"))));
		CxAssert((x_sb->Append('A')->Append())->Equals((new StringRaw("TrueA"))));
		PointerType<ArrayRaw<Char>> x_value = (new ArrayRaw<Char>(4))->Initialize((Char*) DoSBAppendTestArray0);
		CxAssert((x_sb->Append(x_value)->Append())->Equals((new StringRaw("TrueA0123"))));
		x_sb->set_Length(0);
		Double x_value2 = (( Double ) 3.14159);
		CxAssert((x_sb->Append(x_value2)->Append())->Equals((new StringRaw("3.14159"))));
		x_sb->set_Length(0);
		Int32 x_value3 = (( Int32 ) 666);
		CxAssert((x_sb->Append(x_value3)->Append())->Equals((new StringRaw("666"))));
		x_sb->set_Length(0);
		Int64 x_value4 = (( Int64 ) 666666666);
		CxAssert((x_sb->Append(x_value4)->Append())->Equals((new StringRaw("666666666"))));
		x_sb->set_Length(0);
		Object x_obj = (new Int32Box(1 ));
		CxAssert((x_sb->Append(x_obj)->Append())->Equals((new StringRaw("1"))));
		x_sb->set_Length(0);
		CxAssert((x_sb->Append((new StringRaw("fred")))->Append())->Equals((new StringRaw("fred"))));
		UInt32 x_value5 = (( UInt32 ) 777);
		x_sb->set_Length(0);
		CxAssert((x_sb->Append(x_value5)->Append())->Equals((new StringRaw("777"))));
		x_sb->set_Length(0);
		CxAssert((x_sb->Append('A',4)->Append())->Equals((new StringRaw("AAAA"))));
		x_sb->set_Length(0);
		CxAssert((x_sb->Append(x_value,1,3)->Append())->Equals((new StringRaw("123"))));
		x_sb->set_Length(0);
		CxAssert((x_sb->Append((new StringRaw("3210")),1,3)->Append())->Equals((new StringRaw("210"))));
		x_sb->set_Length(0);
		CxAssert((x_sb->AppendFormat((new StringRaw("x={0}")),x_obj)->AppendFormat())->Equals((new StringRaw("x=1"))));
		PointerType<ArrayRaw<Object>> x_array = (new ArrayRaw<Object>(4))->Initialize((Object*) DoSBAppendTestArray1);
		x_sb->set_Length(0);
		CxAssert((x_sb->AppendFormat((new StringRaw("y={0}{1}{2}{3}")),x_array)->AppendFormat())->Equals((new StringRaw("y=0123"))));
		x_sb->set_Length(0);
		CxAssert((x_sb->AppendFormat((new StringRaw("y={0}{1}")),(*x_array->Address(0)),(*x_array->Address(1)))->AppendFormat())->Equals((new StringRaw("y=01"))));
		x_sb->set_Length(0);
		CxAssert((x_sb->AppendFormat((new StringRaw("y={0}{1}{2}")),(*x_array->Address(0)),(*x_array->Address(1)),(*x_array->Address(2)))->AppendFormat())->Equals((new StringRaw("y=012"))));
		x_sb->set_Length(0);
		CxAssert((x_sb->Append('A')->Append())->Equals((new StringRaw("A"))));
		Object x_value6 = (new StringRaw("Test string as Object"));
		x_sb->set_Length(0);
		CxAssert((x_sb->Append(x_value6)->Append())->Equals((new StringRaw("Test string as Object"))));
		PointerType<TestAbstractRaw> x_value7 = new TestAbstractRaw();
		x_sb->set_Length(0);
		CxAssert((x_sb->Append(x_value7)->Append())->Equals((new StringRaw("TestAbstract"))));
	}
	void StringBuilderTestRaw::DoSBMiscTest()
	{
		x_sb->set_Length(0);
		x_sb->set_Capacity(10);
		x_sb->EnsureCapacity(30);
		CxAssert(x_sb->get_Capacity() >= (( Int32 ) 30));
		x_sb->Append((new StringRaw("Test")));
		PointerType<StringBuilderRaw> x_stringBuilder = new StringBuilderRaw((new StringRaw("Test")));
		x_stringBuilder->set_Capacity(10);
		x_stringBuilder->EnsureCapacity(30);
		CxAssert(x_sb->Equals(x_stringBuilder));
		x_sb->set_Length(0);
		x_sb->Append((new StringRaw("1234567890")));
		x_sb->Remove(1,4);
		CxAssert((x_sb->ToString())->Equals((new StringRaw("167890"))));
		x_sb->set_Length(0);
		x_sb->Append((new StringRaw("1234567890")));
		CxAssert((x_sb->ToString(1,8))->Equals((new StringRaw("23456789"))));
	}
	void StringBuilderTestRaw::DoSBInsertTest()
	{
		static Char DoSBInsertTestArray0[4] = {'0','1','2','3'};
		String x_value = (new StringRaw("{}"));
		x_sb->set_Length(0);
		x_sb->Append(x_value);
		x_sb->Insert(1,true);
		CxAssert((x_sb->ToString())->Equals((new StringRaw("{True}"))));
		CxAssert((x_sb->Insert(5,'A')->Insert())->Equals((new StringRaw("{TrueA}"))));
		PointerType<ArrayRaw<Char>> x_value2 = (new ArrayRaw<Char>(4))->Initialize((Char*) DoSBInsertTestArray0);
		CxAssert((x_sb->Insert(6,x_value2)->Insert())->Equals((new StringRaw("{TrueA0123}"))));
		x_sb->set_Length(0);
		x_sb->Append(x_value);
		Double x_value3 = (( Double ) 3.14159);
		CxAssert((x_sb->Insert(1,x_value3)->Insert())->Equals((new StringRaw("{3.14159}"))));
		x_sb->set_Length(0);
		x_sb->Append(x_value);
		Int32 x_value4 = (( Int32 ) 666);
		CxAssert((x_sb->Insert(1,x_value4)->Insert())->Equals((new StringRaw("{666}"))));
		x_sb->set_Length(0);
		x_sb->Append(x_value);
		Int64 x_value5 = (( Int64 ) 666666666);
		CxAssert((x_sb->Insert(1,x_value5)->Insert())->Equals((new StringRaw("{666666666}"))));
		x_sb->set_Length(0);
		x_sb->Append(x_value);
		Object x_value6 = (new Int32Box(1 ));
		CxAssert((x_sb->Insert(1,x_value6)->Insert())->Equals((new StringRaw("{1}"))));
		x_sb->set_Length(0);
		x_sb->Append(x_value);
		CxAssert((x_sb->Insert(1,(new StringRaw("fred")))->Insert())->Equals((new StringRaw("{fred}"))));
		UInt32 x_value7 = (( UInt32 ) 777);
		x_sb->set_Length(0);
		x_sb->Append(x_value);
		CxAssert((x_sb->Insert(1,x_value7)->Insert())->Equals((new StringRaw("{777}"))));
		x_sb->set_Length(0);
		x_sb->Append(x_value);
		CxAssert((x_sb->Insert(1,(new StringRaw("A")),4)->Insert())->Equals((new StringRaw("{AAAA}"))));
		x_sb->set_Length(0);
		x_sb->Append(x_value);
		CxAssert((x_sb->Insert(1,x_value2,1,3)->Insert())->Equals((new StringRaw("{123}"))));
	}
	void StringBuilderTestRaw::DoSBReplaceTest()
	{
		x_sb->set_Length(0);
		x_sb->Append((new StringRaw("aaaaaaa")));
		CxAssert((x_sb->Replace('a','A')->Replace())->Equals((new StringRaw("AAAAAAA"))));
		CxAssert((x_sb->Replace((new StringRaw("AA")),(new StringRaw("BBB")))->Replace())->Equals((new StringRaw("BBBBBBBBBA"))));
		CxAssert((x_sb->Replace('B','C',1,7)->Replace())->Equals((new StringRaw("BCCCCCCCBA"))));
		CxAssert((x_sb->Replace((new StringRaw("CCC")),(new StringRaw("DDD")),2,5)->Replace())->Equals((new StringRaw("BCDDDCCCBA"))));
		x_sb->set_Length(0);
		x_sb->Append((new StringRaw("aaaaaaa")));
		String x_a = x_sb->Replace((new StringRaw("aa")),(new StringRaw("BBB")),1,5)->Replace();
		CxAssert((x_a)->Equals((new StringRaw("aBBBBBBaa"))));
	}
	void StringBuilderTestRaw::CxAssert(Boolean x_x)
	{
		if ( !x_x )
		{
			x_caBlock->TestFailed((new StringRaw("StringBuilder TestFailed")));
		}
	}
	void StringBuilderTestRaw::CxAssert(Boolean x_x,Boolean x_y)
	{
		if ( !(x_x).Equals(x_y) )
		{
			x_caBlock->TestFailed((new StringRaw("StringBuilder TestFailed")));
		}
	}
	StringTestRaw::StringTestRaw(CABlock x_caBlock)
	{
		this->x_caBlock.Assign(x_caBlock);
	}
	void StringTestRaw::Test()
	{
		x_caBlock->Send((new StringRaw("Doing StringTest")));
		x_caBlock->Send((new StringRaw("\tDoing DoIndexTest")));
		DoIndexTest();
		x_caBlock->Send((new StringRaw("\tDoing DoMiscTest")));
		DoMiscTest();
		x_caBlock->Send((new StringRaw("\tDoing DoEqualsTest")));
		DoEqualsTest();
		x_caBlock->Send((new StringRaw("\tDoing DoParsingTest")));
		DoParsingTest();
		x_caBlock->Send((new StringRaw("\tDoing DoConcatTest")));
		DoConcatTest();
	}
	void StringTestRaw::DoIndexTest()
	{
		String x_text = (new StringRaw("12345"));
		CxAssert(((Int32)(x_text->get_Length())).Equals((( Int32 ) 5)));
		CxAssert(((Char)((*x_text->Address(0)))).Equals(( Char ) '1'));
		CxAssert(((Char)((*x_text->Address(1)))).Equals(( Char ) '2'));
		CxAssert(((Char)((*x_text->Address(2)))).Equals(( Char ) '3'));
		CxAssert(((Char)((*x_text->Address(3)))).Equals(( Char ) '4'));
		CxAssert(((Char)((*x_text->Address(4)))).Equals(( Char ) '5'));
	}
	void StringTestRaw::DoMiscTest()
	{
		static Object DoMiscTestArray0[3] = {1,2,3};
		String x_text = new StringRaw(' ',10);
		CxAssert(((Int32)(x_text->get_Length())).Equals((( Int32 ) 10)));
		String x_text2 = (new StringRaw("12345"));
		PointerType<ArrayRaw<Char>> x_array = (new ArrayRaw<Char>(30));
		x_text2->CopyTo(0,x_array,0,x_text2->get_Length());
		Int32 x_num = (( Int32 ) 0);
		String x_text3 = x_text2;
		foreach (Char x_c in x_text3 )
		{
			CxAssert(((Char)((*x_array->Address(x_num)))).Equals(( Char ) x_c));
			x_num++;
		}
		x_array.Assign(x_text2->ToCharArray());
		CxAssert(x_array != nullptr && ((Int32)(x_array->get_Length())).Equals(( Int32 ) x_text2->get_Length()));
		String x_a = new StringRaw(x_array);
		CxAssert((x_a)->Equals(x_text2));
		String x_a2 = new StringRaw(x_array,0,2);
		CxAssert((x_a2)->Equals((new StringRaw("12"))));
		CxAssert(!(x_a2)->Equals((new StringRaw("22"))));
		CxAssert(!( (x_a2)->Equals((new StringRaw("22"))) ));
		x_a2.Assign(new StringRaw(x_text2->ToCharArray(),0,x_text2->get_Length()));
		CxAssert((x_a2)->Equals(x_text2));
		CxAssert(((Int32)(StringRaw::Compare((new StringRaw("abc")),(new StringRaw("ABC")),true))).Equals((( Int32 ) 0)));
		CxAssert(((Int32)(StringRaw::Compare((new StringRaw("1abce")),1,(new StringRaw("abc")),0,3))).Equals((( Int32 ) 0)));
		CxAssert(((Int32)(StringRaw::Compare((new StringRaw("1abce")),1,(new StringRaw("ABC")),0,3,true))).Equals((( Int32 ) 0)));
		CxAssert(((Int32)(StringRaw::CompareOrdinal((new StringRaw("abc")),(new StringRaw("abc"))))).Equals((( Int32 ) 0)));
		CxAssert(((Int32)(StringRaw::CompareOrdinal((new StringRaw("1abce")),1,(new StringRaw("abc")),0,3))).Equals((( Int32 ) 0)));
		x_a2.Assign(StringRaw::Copy(x_text2));
		CxAssert((x_a2)->Equals(x_text2));
		x_a2.Assign(StringRaw::Format((new StringRaw("1 = {{{0,-4}}} 2 = {1,4} 3 = {2}!")),1,2,3));
		CxAssert((x_a2)->Equals((new StringRaw("1 = {1   } 2 =    2 3 = 3!"))));
		String x_a3 = x_a2->ToString();
		CxAssert((x_a3)->Equals((new StringRaw("1 = {1   } 2 =    2 3 = 3!"))));
		String x_empty = String::Empty;
		CxAssert(!(x_empty)->Equals(nullptr) && (x_empty)->Equals((new StringRaw(""))));
		x_a2.Assign(StringRaw::Format((new StringRaw("1 = {{{0,-4}}} 2 = {1,4}!")),1,2));
		CxAssert((x_a2)->Equals((new StringRaw("1 = {1   } 2 =    2!"))));
		x_a2.Assign(StringRaw::Format((new StringRaw("1 = {{{0,-4}}}!")),1));
		CxAssert((x_a2)->Equals((new StringRaw("1 = {1   }!"))));
		PointerType<ArrayRaw<Object>> x_args = (new ArrayRaw<Object>(3))->Initialize((Object*) DoMiscTestArray0);
		x_a2.Assign(StringRaw::Format((new StringRaw("1 = {{{0,-4}}} 2 = {1,4} 3 = {2}!")),x_args));
		PointerType<CharEnumeratorRaw> x_enumerator = x_a2->GetEnumerator();
		Int32 x_num2 = (( Int32 ) 0);
		while (x_enumerator->MoveNext() )
		{
			Char x_current = ( Char ) x_enumerator->get_Current();
			CxAssert(((Char)(x_current)).Equals(( Char ) (*x_a2->Address(x_num2++))));
		}
		x_enumerator->Reset();
		Double x_num3 = (( Double ) 2);
		String x_text4 = x_text2 + x_empty + (new Int32Box(x_num2 )) + (new DoubleBox(x_num3 )) + (new Int32Box(x_num ));
		StringTestRaw::TestConcat(x_text2,x_num,x_empty,x_num2,x_num3);
		String x_a4 = (new StringRaw("\""));
		CxAssert((x_a4)->Equals((new StringRaw("\""))));
		x_a4.Assign((new StringRaw("c:\\Retest")));
		CxAssert((x_a4)->Equals((new StringRaw("c:\\Retest"))));
		x_a4.Assign((new StringRaw("c:\\Retest")));
		CxAssert((x_a4)->Equals((new StringRaw("c:\\Retest"))));
	}
	void StringTestRaw::TestConcat(String x_str1,Int32 x_index,String x_str4,Int32 x_i,Double x_dbl)
	{
		String x_text = x_str1 + x_str4 + (new Int32Box(x_i )) + (new DoubleBox(x_dbl )) + (new Int32Box(x_index ));
	}
	void StringTestRaw::DoEqualsTest()
	{
		String x_text = (new StringRaw("12345"));
		CxAssert(StringRaw::Equals(x_text,(new StringRaw("12345"))));
		CxAssert((x_text)->Equals((new StringRaw("12345"))));
		CxAssert(x_text->Equals(x_text));
		CxAssert(x_text->Equals(x_text));
	}
	void StringTestRaw::DoParsingTest()
	{
		static Char DoParsingTestArray0[4] = {' ',',','.',':'};
		static Char DoParsingTestArray1[2] = {'3','4'};
		static String DoParsingTestArray2[3] = {new StringRaw("1"),new StringRaw("2"),new StringRaw("3")};
		String x_text = (new StringRaw("12 34 56"));
		PointerType<ArrayRaw<String>> x_array = x_text->Split(nullptr);
		CxAssert(((Int32)(x_array->get_Length())).Equals((( Int32 ) 3)));
		CxAssert(((new StringRaw("12")))->Equals((*x_array->Address(0))));
		CxAssert(((new StringRaw("34")))->Equals((*x_array->Address(1))));
		CxAssert(((new StringRaw("56")))->Equals((*x_array->Address(2))));
		String x_text2 = (new StringRaw("42, 12, 19"));
		PointerType<ArrayRaw<Char>> x_separator = (new ArrayRaw<Char>(4))->Initialize((Char*) DoParsingTestArray0);
		x_array.Assign(x_text2->Split(x_separator));
		CxAssert(((Int32)(x_array->get_Length())).Equals((( Int32 ) 5)));
		CxAssert(((new StringRaw("42")))->Equals((*x_array->Address(0))));
		CxAssert(((new StringRaw("")))->Equals((*x_array->Address(1))));
		CxAssert(((new StringRaw("12")))->Equals((*x_array->Address(2))));
		CxAssert(((new StringRaw("")))->Equals((*x_array->Address(3))));
		CxAssert(((new StringRaw("19")))->Equals((*x_array->Address(4))));
		x_array.Assign(x_text2->Split(x_separator,2));
		CxAssert(((Int32)(x_array->get_Length())).Equals((( Int32 ) 2)));
		CxAssert(((new StringRaw("42")))->Equals((*x_array->Address(0))));
		CxAssert(((new StringRaw(" 12, 19")))->Equals((*x_array->Address(1))));
		String x_b = x_text->Substring(3);
		CxAssert(((new StringRaw("34 56")))->Equals(x_b));
		x_b.Assign(x_text->Substring(3,2));
		CxAssert(((new StringRaw("34")))->Equals(x_b));
		String x_text3 = (new StringRaw("  12345  "));
		String x_b2 = x_text3->Trim();
		CxAssert(((new StringRaw("12345")))->Equals(x_b2));
		String x_text4 = (new StringRaw("*;|@123***456@|;*"));
		String x_text5 = (new StringRaw("*;|@"));
		PointerType<ArrayRaw<Char>> x_trimChars = x_text5->ToCharArray();
		x_b2.Assign(x_text4->Trim(x_trimChars));
		CxAssert(((new StringRaw("123***456")))->Equals(x_b2));
		x_b2.Assign(x_text3->TrimStart());
		CxAssert(((new StringRaw("12345  ")))->Equals(x_b2));
		x_b2.Assign(x_text4->TrimStart(x_trimChars));
		CxAssert(((new StringRaw("123***456@|;*")))->Equals(x_b2));
		x_b2.Assign(x_text3->TrimEnd());
		CxAssert(((new StringRaw("  12345")))->Equals(x_b2));
		x_b2.Assign(x_text4->TrimEnd(x_trimChars));
		CxAssert(((new StringRaw("*;|@123***456")))->Equals(x_b2));
		Int32 x_num = ( Int32 ) StringRaw::Compare(x_text,x_text3);
		CxAssert(x_num > (( Int32 ) 0));
		x_num = ( Int32 ) x_text3->CompareTo(x_text);
		CxAssert(x_num < (( Int32 ) 0));
		x_num = ( Int32 ) x_text3->CompareTo(x_text);
		CxAssert(x_num < (( Int32 ) 0));
		CxAssert(x_text->EndsWith((new StringRaw("56"))));
		PointerType<ArrayRaw<Char>> x_array2 = (new ArrayRaw<Char>(2))->Initialize((Char*) DoParsingTestArray1);
		CxAssert(((Int32)(x_text->IndexOfAny(x_array2))).Equals((( Int32 ) 3)));
		CxAssert(((Int32)(x_text->IndexOfAny(x_array2,1))).Equals((( Int32 ) 3)));
		CxAssert(((Int32)(x_text->IndexOfAny(x_array2,1,3))).Equals((( Int32 ) 3)));
		CxAssert(((Int32)(x_text->IndexOf('5'))).Equals((( Int32 ) 6)));
		CxAssert(((Int32)(x_text->IndexOf(' ',3))).Equals((( Int32 ) 5)));
		CxAssert(((Int32)(x_text->IndexOf(' ',3,3))).Equals((( Int32 ) 5)));
		CxAssert(((Int32)(x_text->IndexOf((new StringRaw("56"))))).Equals((( Int32 ) 6)));
		CxAssert(((Int32)(x_text->IndexOf((new StringRaw(" ")),3))).Equals((( Int32 ) 5)));
		CxAssert(((Int32)(x_text->IndexOf((new StringRaw(" ")),3,3))).Equals((( Int32 ) 5)));
		String x_text6 = (new StringRaw("11223311"));
		CxAssert(((Int32)(x_text6->LastIndexOf('1'))).Equals((( Int32 ) 7)));
		CxAssert(((Int32)(x_text6->LastIndexOf('1',4))).Equals((( Int32 ) 1)));
		CxAssert(((Int32)(x_text6->LastIndexOf('1',4,4))).Equals((( Int32 ) 1)));
		CxAssert(((Int32)(x_text6->LastIndexOf((new StringRaw("11"))))).Equals((( Int32 ) 6)));
		CxAssert(((Int32)(x_text6->LastIndexOf((new StringRaw("11")),4))).Equals((( Int32 ) 0)));
		CxAssert(((Int32)(x_text6->LastIndexOf((new StringRaw("11")),4,5))).Equals((( Int32 ) 0)));
		(*x_array2->Address(0)) = ( Char ) '1';
		(*x_array2->Address(1)) = ( Char ) '2';
		CxAssert(((Int32)(x_text6->LastIndexOfAny(x_array2))).Equals((( Int32 ) 7)));
		CxAssert(((Int32)(x_text6->LastIndexOfAny(x_array2,4))).Equals((( Int32 ) 3)));
		CxAssert(((Int32)(x_text6->LastIndexOfAny(x_array2,4,4))).Equals((( Int32 ) 3)));
		String x_a = x_text6->PadLeft(3 + ( Int32 ) x_text6->get_Length());
		CxAssert((x_a)->Equals((new StringRaw("   11223311"))));
		x_a.Assign(x_text6->PadLeft(3 + ( Int32 ) x_text6->get_Length(),'-'));
		CxAssert((x_a)->Equals((new StringRaw("---11223311"))));
		x_a.Assign(x_text6->PadRight(3 + ( Int32 ) x_text6->get_Length()));
		CxAssert((x_a)->Equals((new StringRaw("11223311   "))));
		x_a.Assign(x_text6->PadRight(3 + ( Int32 ) x_text6->get_Length(),'-'));
		CxAssert((x_a)->Equals((new StringRaw("11223311---"))));
		CxAssert(x_text6->StartsWith((new StringRaw("1122"))));
		CxAssert((x_text6->Replace('1','x'))->Equals((new StringRaw("xx2233xx"))));
		CxAssert((x_text6->Replace((new StringRaw("1")),(new StringRaw("x"))))->Equals((new StringRaw("xx2233xx"))));
		CxAssert((x_text6->Replace((new StringRaw("11")),(new StringRaw("x"))))->Equals((new StringRaw("x2233x"))));
		CxAssert((x_text6->Remove(2,2))->Equals((new StringRaw("113311"))));
		CxAssert(((new StringRaw("aaAAaaAA"))->ToUpper())->Equals((new StringRaw("AAAAAAAA"))));
		CxAssert(((new StringRaw("aaAAaaAA"))->ToLower())->Equals((new StringRaw("aaaaaaaa"))));
		PointerType<ArrayRaw<String>> x_value = (new ArrayRaw<String>(3))->Initialize((String*) DoParsingTestArray2);
		CxAssert((StringRaw::Join((new StringRaw(",")),x_value))->Equals((new StringRaw("1,2,3"))));
		CxAssert((StringRaw::Join((new StringRaw(",")),x_value,1,2))->Equals((new StringRaw("2,3"))));
		x_text6.Assign(x_text->Insert(3,(new StringRaw("111"))));
		CxAssert((x_text6)->Equals((new StringRaw("12 11134 56"))));
		String x_text7 = (new StringRaw("3.33"));
		if ( !((Int32)(x_text7->CompareTo((new StringRaw("3.33"))))).Equals((( Int32 ) 0)) )
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
		CxAssert((x_a)->Equals((new StringRaw("1 "))));
		x_a.Assign(StringRaw::Concat(x_array));
		CxAssert((x_a)->Equals((new StringRaw("1 2 3 4"))));
		PointerType<ArrayRaw<String>> x_array2 = (new ArrayRaw<String>(4))->Initialize((String*) DoConcatTestArray1);
		x_a.Assign(StringRaw::Concat(x_array2));
		CxAssert((x_a)->Equals((new StringRaw("1 2 3 4"))));
		x_a.Assign(StringRaw::Concat((*x_array->Address(0)),(*x_array->Address(1))));
		CxAssert((x_a)->Equals((new StringRaw("1 2 "))));
		x_a.Assign((*x_array2->Address(0)) + (*x_array2->Address(1)));
		CxAssert((x_a)->Equals((new StringRaw("1 2 "))));
		x_a.Assign(StringRaw::Concat((*x_array->Address(0)),(*x_array->Address(1)),(*x_array->Address(2))));
		CxAssert((x_a)->Equals((new StringRaw("1 2 3 "))));
		x_a.Assign((*x_array2->Address(0)) + (*x_array2->Address(1)) + (*x_array2->Address(2)));
		CxAssert((x_a)->Equals((new StringRaw("1 2 3 "))));
		x_a.Assign((*x_array2->Address(0)) + (*x_array2->Address(1)) + (*x_array2->Address(2)) + (*x_array2->Address(3)));
		CxAssert((x_a)->Equals((new StringRaw("1 2 3 4"))));
	}
	void StringTestRaw::CxAssert(Boolean x_x)
	{
		if ( !x_x )
		{
			x_caBlock->TestFailed((new StringRaw("String TestFailed")));
		}
	}
	TimeTestRaw::TimeTestRaw(CABlock x_caBlock)
	{
		x_dat1 = DateTime::get_Now();
		this->x_caBlock.Assign(x_caBlock);
	}
	void TimeTestRaw::Test()
	{
		x_caBlock->Send((new StringRaw("Doing TimeTest")));
		x_caBlock->Send((new StringRaw("\tDoing TestTimeSpan")));
		TestTimeSpan();
		x_caBlock->Send((new StringRaw("\tDoing TestDateTime")));
		TestDateTime();
		x_caBlock->Send((new StringRaw("\tDoing DateTimeMethodTests")));
		DateTimeMethodTests();
		x_caBlock->Send((new StringRaw("\tDoing TimeArrayTests")));
		TimeArrayTests();
	}
	void TimeTestRaw::TestTimeSpan()
	{
		TimeSpan x_timeSpan = TimeSpan(100);
		TimeSpan x_timeSpan2 = x_timeSpan.Add(x_timeSpan);
		CxAssert(((Int64)(x_timeSpan2.get_Ticks())).Equals((( Int64 ) 200)));
		CxAssert(TimeSpanRaw::Compare(x_timeSpan,x_timeSpan2) < (( Int32 ) 0));
		CxAssert(x_timeSpan.CompareTo((new TimeSpanBox(x_timeSpan2 ))) < (( Int32 ) 0));
		CxAssert(x_timeSpan.CompareTo(x_timeSpan2) < (( Int32 ) 0));
		x_timeSpan = x_timeSpan2.Duration();
		CxAssert(((Int64)(x_timeSpan.get_Ticks())).Equals((( Int64 ) 200)));
		CxAssert(TimeSpanRaw::Equals(x_timeSpan,x_timeSpan2));
		CxAssert(x_timeSpan.Equals(x_timeSpan2));
		CxAssert(((Int64)(TimeSpanRaw::FromDays(22).get_Ticks())).Equals((( Int64 ) 19008000000000)));
		CxAssert(((Int64)(TimeSpanRaw::FromHours(10).get_Ticks())).Equals((( Int64 ) 360000000000)));
		CxAssert(((Int64)(TimeSpanRaw::FromMilliseconds(100).get_Ticks())).Equals((( Int64 ) 1000000)));
		CxAssert(((Int64)(TimeSpanRaw::FromMinutes(25).get_Ticks())).Equals((( Int64 ) 15000000000)));
		CxAssert(((Int64)(TimeSpanRaw::FromSeconds(18).get_Ticks())).Equals((( Int64 ) 180000000)));
		x_timeSpan = TimeSpanRaw::FromTicks(6500000);
		CxAssert(((Int64)(x_timeSpan.get_Ticks())).Equals((( Int64 ) 6500000)));
		x_timeSpan = x_timeSpan.Negate();
		CxAssert(((Int64)(x_timeSpan.get_Ticks())).Equals(( Int64 ) -6500000));
		CxAssert(((Int64)(x_timeSpan.Subtract(x_timeSpan2).get_Ticks())).Equals(( Int64 ) -6500200));
		CxAssert(((Int64)(TimeSpanRaw::Parse((new StringRaw("1.1:1:1"))).get_Ticks())).Equals((( Int64 ) 900610000000)));
		CxAssert(((Int64)(TimeSpanRaw::Parse((new StringRaw("1.1:1:1.200"))).get_Ticks())).Equals((( Int64 ) 900612000000)));
		CxAssert(((Int64)(TimeSpanRaw::Parse((new StringRaw("1:1:1"))).get_Ticks())).Equals((( Int64 ) 36610000000)));
		CxAssert(((Int64)(TimeSpanRaw::Parse((new StringRaw("22"))).get_Ticks())).Equals((( Int64 ) 19008000000000)));
		x_timeSpan = TimeSpanRaw::Parse((new StringRaw("1.2:3:4.200")));
		String x_a = x_timeSpan.ToString();
		CxAssert((x_a)->Equals((new StringRaw("1.02:03:04.2000000"))));
		CxAssert(((Int32)(x_timeSpan.get_Days())).Equals((( Int32 ) 1)));
		CxAssert(((Int32)(x_timeSpan.get_Hours())).Equals((( Int32 ) 2)));
		CxAssert(((Int32)(x_timeSpan.get_Minutes())).Equals((( Int32 ) 3)));
		CxAssert(((Int32)(x_timeSpan.get_Seconds())).Equals((( Int32 ) 4)));
		CxAssert(((Int32)(x_timeSpan.get_Milliseconds())).Equals((( Int32 ) 200)));
		CxAssert(((Int64)(x_timeSpan.get_Ticks())).Equals((( Int64 ) 937842000000)));
		CxAssert(x_timeSpan.get_TotalDays(),1.08546527777778);
		CxAssert(x_timeSpan.get_TotalHours(),26.0511666666667);
		CxAssert(x_timeSpan.get_TotalMinutes(),1563.07);
		CxAssert(x_timeSpan.get_TotalSeconds(),93784.2);
		CxAssert(x_timeSpan.get_TotalMilliseconds(),93784200);
		CxAssert(((Int64)(( x_timeSpan2 + x_timeSpan2 ).get_Ticks())).Equals((( Int64 ) 400)));
		x_timeSpan = x_timeSpan2;
		CxAssert((x_timeSpan).Equals(x_timeSpan2));
		CxAssert(!( !(x_timeSpan).Equals(x_timeSpan2) ));
		x_timeSpan = TimeSpan(100);
		CxAssert(!( x_timeSpan > x_timeSpan2 ));
		CxAssert(!( x_timeSpan >= x_timeSpan2 ));
		CxAssert(!( x_timeSpan2 < x_timeSpan ));
		CxAssert(!( x_timeSpan2 <= x_timeSpan ));
		CxAssert((x_timeSpan).Equals(x_timeSpan));
		x_timeSpan = x_timeSpan2 - x_timeSpan;
		CxAssert(((Int64)(x_timeSpan.get_Ticks())).Equals((( Int64 ) 100)));
		x_timeSpan = -x_timeSpan;
		CxAssert(((Int64)(x_timeSpan.get_Ticks())).Equals(( Int64 ) -100));
		CxAssert(((Int64)(( +x_timeSpan ).get_Ticks())).Equals(( Int64 ) -100));
		CxAssert(((Int64)(TimeSpan(1000).get_Ticks())).Equals((( Int64 ) 1000)));
		CxAssert(((Int64)(TimeSpan(10,11,30).get_Ticks())).Equals((( Int64 ) 366900000000)));
		CxAssert(((Int64)(TimeSpan(3,10,11,30).get_Ticks())).Equals((( Int64 ) 2958900000000)));
		CxAssert(((Int64)(TimeSpan(3,10,11,30,100).get_Ticks())).Equals((( Int64 ) 2958901000000)));
		CxAssert(((Int64)(TimeSpan(3,10,11,30,100).get_Ticks())).Equals((( Int64 ) 2958901000000)));
		x_timeSpan = TimeSpan(71,3,12,13);
		CxAssert(((Int64)(x_timeSpan.get_Ticks())).Equals((( Int64 ) 61459330000000)));
		String x_text = x_timeSpan.ToString();
		CxAssert(x_text->Equals((new StringRaw("71.03:12:13"))));
		x_timeSpan = TimeSpan(-71,3,12,13);
		CxAssert(((Int64)(x_timeSpan.get_Ticks())).Equals(( Int64 ) -61228670000000));
		String x_text2 = x_timeSpan.ToString();
		CxAssert(x_text2->Equals((new StringRaw("-70.20:47:47"))));
		x_timeSpan = TimeSpanRaw::Parse((new StringRaw("-71.03:12:13")));
		CxAssert(((Int64)(x_timeSpan.get_Ticks())).Equals(( Int64 ) -61459330000000));
		String x_text3 = x_timeSpan.ToString();
		CxAssert(x_text3->Equals((new StringRaw("-71.03:12:13"))));
		Object x_obj = (new TimeSpanBox(TimeSpan::MinValue ));
		CxAssert(((Int64)(( ( TimeSpan ) x_obj->get_AsTimeSpan() ).get_Ticks())).Equals(( Int64 ) TimeSpan::MinValue.get_Ticks()));
		TimeSpan x_minValue = TimeSpan::MinValue;
		CxAssert(x_minValue.Equals(x_obj));
		CxAssert(((Int32)(TimeSpan::MinValue.CompareTo(x_obj))).Equals((( Int32 ) 0)));
		Int64 x_num = (( Int64 ) 864000000000);
		CxAssert(((Int64)(864000000000)).Equals(( Int64 ) x_num));
		x_num = (( Int64 ) 36000000000);
		CxAssert(((Int64)(36000000000)).Equals(( Int64 ) x_num));
		x_num = (( Int64 ) 600000000);
		CxAssert(((Int32)(600000000)).Equals(( Int32 ) x_num));
		x_num = (( Int64 ) 10000000);
		CxAssert(((Int32)(10000000)).Equals(( Int32 ) x_num));
		x_num = (( Int64 ) 10000);
		CxAssert(((Int32)(10000)).Equals(( Int32 ) x_num));
		CxAssert((TimeSpan::Zero).Equals(TimeSpan::Zero));
		CxAssert((TimeSpan::MaxValue).Equals(TimeSpan::MaxValue));
		CxAssert(x_obj->Equals(TimeSpan::MinValue));
		String x_a2 = x_obj->ToString();
		x_minValue = TimeSpan::MinValue;
		CxAssert((x_a2)->Equals(x_minValue.ToString()));
	}
	void TimeTestRaw::TestDateTime()
	{
		CxAssert(((Int64)(DateTime().get_Ticks())).Equals((( Int64 ) 0)));
		CxAssert(((Int64)(DateTime(1200).get_Ticks())).Equals((( Int64 ) 1200)));
		CxAssert(((Int64)(DateTime(2003,7,23).get_Ticks())).Equals((( Int64 ) 631945152000000000)));
		CxAssert(((Int64)(DateTime(2003,7,23,12,30,30).get_Ticks())).Equals((( Int64 ) 631945602300000000)));
		DateTime x_dateTime = DateTime(2003,7,23,12,30,30,100);
		CxAssert(((Int64)(x_dateTime.get_Ticks())).Equals((( Int64 ) 631945602301000000)));
		CxAssert(((Int64)(x_dateTime.get_Date().get_Ticks())).Equals((( Int64 ) 631945152000000000)));
		Int32 x_day = ( Int32 ) x_dateTime.get_Day();
		CxAssert(((Int32)(x_day)).Equals((( Int32 ) 23)));
		DayOfWeek x_dayOfWeek = x_dateTime.get_DayOfWeek();
		CxAssert(x_dayOfWeek == Wednesday_DayOfWeek);
		Int32 x_dayOfYear = ( Int32 ) x_dateTime.get_DayOfYear();
		CxAssert(((Int32)(x_dayOfYear)).Equals((( Int32 ) 204)));
		Int32 x_hour = ( Int32 ) x_dateTime.get_Hour();
		CxAssert(((Int32)(x_hour)).Equals((( Int32 ) 12)));
		Int32 x_millisecond = ( Int32 ) x_dateTime.get_Millisecond();
		CxAssert(((Int32)(x_millisecond)).Equals((( Int32 ) 100)));
		Int32 x_minute = ( Int32 ) x_dateTime.get_Minute();
		CxAssert(((Int32)(x_minute)).Equals((( Int32 ) 30)));
		Int32 x_month = ( Int32 ) x_dateTime.get_Month();
		CxAssert(((Int32)(x_month)).Equals((( Int32 ) 7)));
		DateTime x_now = DateTime::get_Now();
		x_day = ( Int32 ) x_now.get_Day();
		x_dayOfYear = ( Int32 ) x_now.get_DayOfYear();
		x_dayOfWeek = x_now.get_DayOfWeek();
		x_hour = ( Int32 ) x_now.get_Hour();
		Int32 x_second = ( Int32 ) x_dateTime.get_Second();
		CxAssert(((Int32)(x_second)).Equals((( Int32 ) 30)));
		CxAssert(((Int64)(x_dateTime.get_TimeOfDay().get_Ticks())).Equals((( Int64 ) 450301000000)));
		DateTime x_today = DateTime::get_Today();
		x_day = ( Int32 ) x_today.get_Day();
		x_dayOfYear = ( Int32 ) x_today.get_DayOfYear();
		x_dayOfWeek = x_today.get_DayOfWeek();
		x_hour = ( Int32 ) x_today.get_Hour();
		DateTime x_utcNow = DateTime::get_UtcNow();
		x_day = ( Int32 ) x_utcNow.get_Day();
		x_dayOfYear = ( Int32 ) x_utcNow.get_DayOfYear();
		x_dayOfWeek = x_utcNow.get_DayOfWeek();
		x_hour = ( Int32 ) x_utcNow.get_Hour();
		Int32 x_year = ( Int32 ) x_dateTime.get_Year();
		CxAssert(((Int32)(x_year)).Equals((( Int32 ) 2003)));
	}
	void TimeTestRaw::DateTimeMethodTests()
	{
		DateTime x_dateTime = DateTime(2003,7,23,12,30,30,100);
		TimeSpan x_timeSpan = TimeSpan(0,2,0,0);
		CxAssert(((Int64)(x_dateTime.Add(x_timeSpan).get_Ticks())).Equals((( Int64 ) 631945674301000000)));
		CxAssert(((Int64)(x_dateTime.AddDays(1.5).get_Ticks())).Equals((( Int64 ) 631946898301000000)));
		CxAssert(((Int64)(x_dateTime.AddHours(2.5).get_Ticks())).Equals((( Int64 ) 631945692301000000)));
		CxAssert(((Int64)(x_dateTime.AddMilliseconds(159).get_Ticks())).Equals((( Int64 ) 631945602302590000)));
		CxAssert(((Int64)(x_dateTime.AddMinutes(3.2).get_Ticks())).Equals((( Int64 ) 631945604221000000)));
		CxAssert(((Int64)(x_dateTime.AddMonths(5).get_Ticks())).Equals((( Int64 ) 632077794301000000)));
		CxAssert(((Int64)(x_dateTime.AddSeconds(6.66).get_Ticks())).Equals((( Int64 ) 631945602367600000)));
		CxAssert(((Int64)(x_dateTime.AddTicks(666).get_Ticks())).Equals((( Int64 ) 631945602301000666)));
		DateTime x_dateTime2 = x_dateTime.AddYears(3);
		CxAssert(((Int64)(x_dateTime2.get_Ticks())).Equals((( Int64 ) 632892546301000000)));
		CxAssert(DateTimeRaw::Compare(x_dateTime2,x_dateTime) > (( Int32 ) 0));
		CxAssert(x_dateTime.CompareTo(x_dateTime2) < (( Int32 ) 0));
		CxAssert(((Int32)(DateTimeRaw::DaysInMonth(2003,1))).Equals((( Int32 ) 31)));
		CxAssert(!x_dateTime.Equals(x_dateTime2));
		x_dateTime2 = x_dateTime;
		CxAssert(DateTimeRaw::Equals(x_dateTime,x_dateTime2));
		CxAssert(DateTimeRaw::IsLeapYear(2004));
		x_dateTime2 = x_dateTime.Subtract(x_timeSpan);
		CxAssert(((Int64)(x_dateTime2.get_Ticks())).Equals((( Int64 ) 631945530301000000)));
		CxAssert(((Int64)(x_dateTime.Subtract(x_dateTime2).get_Ticks())).Equals((( Int64 ) 72000000000)));
		x_dateTime2 = x_dateTime.ToLocalTime();
		x_dateTime2 = x_dateTime.ToUniversalTime();
		x_dateTime2 = x_dateTime + x_timeSpan;
		CxAssert(((Int64)(x_dateTime2.get_Ticks())).Equals((( Int64 ) 631945674301000000)));
		CxAssert(!( (x_dateTime2).Equals(x_dateTime) ));
		CxAssert(!( x_dateTime > x_dateTime2 ));
		CxAssert(!( x_dateTime >= x_dateTime2 ));
		CxAssert((x_dateTime2).Equals(x_dateTime2));
		CxAssert(!( x_dateTime2 < x_dateTime ));
		CxAssert(!( x_dateTime2 <= x_dateTime ));
		x_dateTime2 = x_dateTime - x_timeSpan;
		CxAssert(((Int64)(x_dateTime2.get_Ticks())).Equals((( Int64 ) 631945530301000000)));
		CxAssert(((Int64)(( x_dateTime - x_dateTime2 ).get_Ticks())).Equals((( Int64 ) 72000000000)));
		x_dateTime2 = DateTime(2003,7,23,14,2,30,100);
		CxAssert(((Int64)(x_dateTime2.get_Ticks())).Equals((( Int64 ) 631945657501000000)));
		CxAssert(((Int32)(x_dateTime2.get_Hour())).Equals((( Int32 ) 14)));
		String x_text = x_dateTime2.ToString();
		CxAssert(x_text->Equals((new StringRaw("7/23/2003 2:02:30 PM"))));
		x_dateTime2 = DateTime(2003,7,23,2,20,1,100);
		CxAssert(((Int64)(x_dateTime2.get_Ticks())).Equals((( Int64 ) 631945236011000000)));
		CxAssert(((Int32)(x_dateTime2.get_Hour())).Equals((( Int32 ) 2)));
		x_text.Assign(x_dateTime2.ToString());
		CxAssert(x_text->Equals((new StringRaw("7/23/2003 2:20:01 AM"))));
		CxAssert(((Int64)(((DateTime)0).get_Ticks())).Equals((( Int64 ) 0)));
		CxAssert(((Int64)(((DateTime)3155378975999999999).get_Ticks())).Equals((( Int64 ) 3155378975999999999)));
		Object x_obj = (new DateTimeBox(((DateTime)0) ));
		CxAssert(((Int64)(( ( DateTime ) x_obj->get_AsDateTime() ).get_Ticks())).Equals((( Int64 ) 0)));
		CxAssert(((DateTime)0).Equals(x_obj));
		CxAssert(((Int32)(((DateTime)0).CompareTo(x_obj))).Equals((( Int32 ) 0)));
		CxAssert(x_obj->Equals(((DateTime)0)));
		CxAssert((x_obj->ToString())->Equals(((DateTime)0).ToString()));
		CxAssert(!(x_dateTime2).Equals(x_dateTime));
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
		CxAssert(((Int32)(x_array->get_Length())).Equals((( Int32 ) 5)));
		CxAssert(((*x_array->Address(3))).Equals(DateTime(2000,4,9)));
		CxAssert(((*x_array->Address(1))).Equals(DateTime(2000,4,7)));
		PointerType<ArrayRaw<DateTime>> x_array2 = (new ArrayRaw<DateTime>(2,4))->Initialize((DateTime*) DateTimeArrayTestsArray1);
		CxAssert(((*x_array2->Address(0,2))).Equals(DateTime(2000,4,8)));
		PointerType<ArrayRaw<DateTime>> x_array3 = (new ArrayRaw<DateTime>(2,2,4))->Initialize((DateTime*) DateTimeArrayTestsArray2);
		CxAssert(((*x_array3->Address(0,0,3))).Equals(DateTime(2000,4,9)));
		(*x_array3->Address(0,0,3)) = DateTime(2000,4,27);
		CxAssert(((*x_array3->Address(0,0,3))).Equals(DateTime(2000,4,27)));
		x_array3->SetValue(DateTime(2000,4,28),0,0,3);
		CxAssert(((*x_array3->Address(0,0,3))).Equals(DateTime(2000,4,28)));
		DateTime x_d = (*x_array->Address(2)) = DateTime(2000,4,27);
		CxAssert(((*x_array->Address(2))).Equals(x_d));
	}
	void TimeTestRaw::TimeSpanArrayTests()
	{
		static TimeSpan TimeSpanArrayTestsArray0[5] = {TimeSpan(2000,4,6),TimeSpan(2000,4,7),TimeSpan(2000,4,8),TimeSpan(2000,4,9),TimeSpan(2000,4,10)};
		static TimeSpan TimeSpanArrayTestsArray1[2][4] = {{TimeSpan(2000,4,6),TimeSpan(2000,4,7),TimeSpan(2000,4,8),TimeSpan(2000,4,9)},{TimeSpan(2000,4,10),TimeSpan(2000,4,11),TimeSpan(2000,4,12),TimeSpan(2000,4,13)}};
		static TimeSpan TimeSpanArrayTestsArray2[2][2][4] = {{{TimeSpan(2000,4,6),TimeSpan(2000,4,7),TimeSpan(2000,4,8),TimeSpan(2000,4,9)},{TimeSpan(2000,4,10),TimeSpan(2000,4,11),TimeSpan(2000,4,12),TimeSpan(2000,4,13)}},{{TimeSpan(2000,4,14),TimeSpan(2000,4,15),TimeSpan(2000,4,16),TimeSpan(2000,4,17)},{TimeSpan(2000,4,18),TimeSpan(2000,4,19),TimeSpan(2000,4,20),TimeSpan(2000,4,21)}}};
		PointerType<ArrayRaw<TimeSpan>> x_array = (new ArrayRaw<TimeSpan>(5))->Initialize((TimeSpan*) TimeSpanArrayTestsArray0);
		CxAssert(((Int32)(x_array->get_Length())).Equals((( Int32 ) 5)));
		CxAssert(((*x_array->Address(3))).Equals(TimeSpan(2000,4,9)));
		CxAssert(((*x_array->Address(1))).Equals(TimeSpan(2000,4,7)));
		PointerType<ArrayRaw<TimeSpan>> x_array2 = (new ArrayRaw<TimeSpan>(2,4))->Initialize((TimeSpan*) TimeSpanArrayTestsArray1);
		CxAssert(((*x_array2->Address(0,2))).Equals(TimeSpan(2000,4,8)));
		PointerType<ArrayRaw<TimeSpan>> x_array3 = (new ArrayRaw<TimeSpan>(2,2,4))->Initialize((TimeSpan*) TimeSpanArrayTestsArray2);
		CxAssert(((*x_array3->Address(0,0,3))).Equals(TimeSpan(2000,4,9)));
		(*x_array3->Address(0,0,3)) = TimeSpan(2000,4,27);
		CxAssert(((*x_array3->Address(0,0,3))).Equals(TimeSpan(2000,4,27)));
		x_array3->SetValue(TimeSpan(2000,4,28),0,0,3);
		CxAssert(((*x_array3->Address(0,0,3))).Equals(TimeSpan(2000,4,28)));
		TimeSpan x_t = (*x_array->Address(2)) = TimeSpan(2000,4,27);
		CxAssert(((*x_array->Address(2))).Equals(x_t));
	}
	void TimeTestRaw::CxAssert(Double x_x,Double x_y)
	{
		if ( MathRaw::Abs(x_x - ( Double ) x_y) > (( Double ) 1E-05) )
		{
			x_caBlock->TestFailed((new StringRaw("Time TestFailed")));
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
		x_caBlock->TestFailed((new StringRaw("Time TestFailed")));
	}
	TimingTestRaw::TimingTestRaw()
	{
	}
	Int32 TimingTestRaw::DoTimingTest(Int32 x_a,Int32 x_b,Int32 x_c)
	{
		Int32 x_result = (( Int32 ) 0);
		for ( Int32 x_i = (( Int32 ) 0) ;  x_i < ( Int32 ) x_a ;   x_i++ )
		{
			for ( Int32 x_j = (( Int32 ) 0) ;  x_j < ( Int32 ) x_b ;   x_j++ )
			{
				x_result = ( Int32 ) x_i * ( Int32 ) x_j + ( Int32 ) x_c;
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
		x_caBlock->Send((new StringRaw("Doing UInt16Test")));
		x_caBlock->Send((new StringRaw("\tDoing UInt16MethodsTest")));
		UInt16MethodsTest();
		x_caBlock->Send((new StringRaw("\tDoing DoUnSignedMath")));
		DoUnSignedMath();
		x_caBlock->Send((new StringRaw("\tDoing UInt16Operators")));
		UInt16Operators();
		x_caBlock->Send((new StringRaw("\tDoing UInt16ArrayTest")));
		UInt16ArrayTest();
		x_caBlock->Send((new StringRaw("\tDoing UInt16MiscTests")));
		UInt16MiscTests();
	}
	void UInt16TestRaw::UInt16MethodsTest()
	{
		UInt16 x_num = (( UInt16 ) 5);
		CxAssert(((Int32)((( UInt16 ) x_num).CompareTo(5))).Equals((( Int32 ) 0)));
		CxAssert(((Int32)((( UInt16 ) x_num).CompareTo((new UInt16Box((( UInt16 ) 5) ))))).Equals((( Int32 ) 0)));
		CxAssert((( UInt16 ) x_num).Equals(5));
		CxAssert((( UInt16 ) x_num).Equals((new UInt16Box((( UInt16 ) 5) ))));
		CxAssert(((UInt16)(UInt16Raw::Parse((new StringRaw("77"))))).Equals((( UInt16 ) 77)));
		CxAssert(((new StringRaw("5")))->Equals((( UInt16 ) x_num).ToString()));
		x_num = ( UInt16 ) ((UInt16)65535);
		CxAssert(((UInt16)(((UInt16)65535))).Equals(( UInt16 ) x_num));
		x_num = (( UInt16 ) 0);
		CxAssert(((UInt16)(x_num)).Equals((( UInt16 ) 0)));
		String x_text = (( UInt16 ) ((UInt16)65535)).ToString();
		CxAssert((x_text)->Equals((new StringRaw("65535"))));
		CxAssert(((UInt16)(UInt16Raw::Parse(x_text))).Equals(( UInt16 ) ((UInt16)65535)));
		String x_text2 = ( (( UInt16 ) 0) ).ToString();
		CxAssert((x_text2)->Equals((new StringRaw("0"))));
		CxAssert(((UInt16)(UInt16Raw::Parse(x_text2))).Equals((( UInt16 ) 0)));
		Object x_obj = (new UInt16Box((( UInt16 ) 5) ));
		CxAssert(x_obj->Equals((( UInt16 ) 5)));
		CxAssert((x_obj->ToString())->Equals((new StringRaw("5"))));
	}
	void UInt16TestRaw::DoUnSignedMath()
	{
		UInt16 x_num = (( UInt16 ) 600);
		UInt16 x_num2 = (( UInt16 ) 1200);
		Int32 x_num3 = (( Int32 ) 1);
		CxAssert(1 <= ( UInt16 ) x_num);
		CxAssert(x_num >= (( Int32 ) 1));
		CxAssert(x_num >= ( Int32 ) x_num3);
		CxAssert(x_num3 <= ( UInt16 ) x_num);
		x_num3 = x_num3 + ( Int32 ) x_num;
		CxAssert(((Int32)(x_num3)).Equals((( Int32 ) 601)));
		CxAssert(((Int32)(x_num + ( UInt16 ) x_num2)).Equals((( Int32 ) 1800)));
		CxAssert(((Int32)(x_num - ( UInt16 ) x_num2)).Equals(( Int32 ) -600));
		CxAssert(((Int32)(x_num * ( UInt16 ) x_num2)).Equals((( Int32 ) 720000)));
		CxAssert(((Int32)(( Int32 ) x_num2 / ( Int32 ) ( Int32 ) x_num)).Equals((( Int32 ) 2)));
		CxAssert(((Int32)(x_num >> (( Int32 ) 2))).Equals((( Int32 ) 150)));
		CxAssert(((Int32)(x_num << (( Int32 ) 1))).Equals((( Int32 ) 1200)));
		Int32 x_num4 = (( Int32 ) 11);
		CxAssert(((Int32)(x_num4 % (( Int32 ) 5))).Equals((( Int32 ) 1)));
		x_num4 = (( Int32 ) 8);
		CxAssert(( x_num4 | (( Int32 ) 1) ) == (( Int32 ) 9));
		CxAssert(( x_num4 & (( Int32 ) 1) ) == (( Int32 ) 0));
		CxAssert(((Int32)(++x_num4)).Equals((( Int32 ) 9)));
		CxAssert(((Int32)(--x_num4)).Equals((( Int32 ) 8)));
		CxAssert(( x_num4 = x_num4 * (( Int32 ) 2) ) == (( Int32 ) 16));
		CxAssert(( x_num4 = x_num4 / (( Int32 ) 2) ) == (( Int32 ) 8));
		CxAssert(( x_num4 = x_num4 % (( Int32 ) 2) ) == (( Int32 ) 0));
		CxAssert(( x_num4 = x_num4 | (( Int32 ) 4) ) == (( Int32 ) 4));
		CxAssert(( x_num4 = x_num4 & (( Int32 ) 4) ) == (( Int32 ) 4));
		CxAssert(((Int32)(-x_num)).Equals(( Int32 ) -600));
		CxAssert(((UInt16)(x_num)).Equals((( UInt16 ) 600)));
		UInt32 x_num5 = (( UInt32 ) 0);
		CxAssert(((UInt32)(~x_num5)).Equals(( UInt32 ) ((UInt32)4294967295)));
		CxAssert(((UInt32)(++x_num5)).Equals((( UInt32 ) 1)));
		CxAssert(((UInt32)(--x_num5)).Equals((( UInt32 ) 0)));
	}
	void UInt16TestRaw::UInt16Operators()
	{
		UInt16 x_num = (( UInt16 ) 66);
		Char x_c = ( Char ) '';
		Int32 x_num2 = (( Int32 ) 1);
		UInt16 x_num3 = (( UInt16 ) 1);
		Int64 x_num4 = (( Int64 ) 1);
		Double x_num5 = (( Double ) 1);
		CxAssert(((UInt16)(x_num)).Equals((( UInt16 ) 66)));
		CxAssert(((Int32)(x_num + ( Char ) x_c)).Equals((( Int32 ) 67)));
		CxAssert(((Int32)(x_num + ( Int32 ) x_num2)).Equals((( Int32 ) 67)));
		CxAssert(((Int32)(x_num + ( UInt16 ) x_num3)).Equals((( Int32 ) 67)));
		CxAssert(((Int64)(x_num + ( Int64 ) x_num4)).Equals((( Int64 ) 67)));
		CxAssert(((Double)(( Double ) ( Int32 ) x_num + ( Double ) x_num5)).Equals((( Double ) 67)));
		CxAssert(((Int32)(x_num - ( Char ) x_c)).Equals((( Int32 ) 65)));
		CxAssert(((Int32)(x_num - ( Int32 ) x_num2)).Equals((( Int32 ) 65)));
		CxAssert(((Int32)(x_num - ( UInt16 ) x_num3)).Equals((( Int32 ) 65)));
		CxAssert(((Int64)(x_num - ( Int64 ) x_num4)).Equals((( Int64 ) 65)));
		CxAssert(((Double)(( Double ) ( Int32 ) x_num - ( Double ) x_num5)).Equals((( Double ) 65)));
		CxAssert(((Int32)(x_num * ( Char ) x_c)).Equals((( Int32 ) 66)));
		CxAssert(((Int32)(x_num * ( Int32 ) x_num2)).Equals((( Int32 ) 66)));
		CxAssert(((Int32)(x_num * ( UInt16 ) x_num3)).Equals((( Int32 ) 66)));
		CxAssert(((Int64)(x_num * ( Int64 ) x_num4)).Equals((( Int64 ) 66)));
		CxAssert(((Double)(( Double ) ( Int32 ) x_num * ( Double ) x_num5)).Equals((( Double ) 66)));
		CxAssert(((Int32)(( Int32 ) x_num / ( Int32 ) ( Int32 ) x_c)).Equals((( Int32 ) 66)));
		CxAssert(((Int32)(( Int32 ) x_num / ( Int32 ) x_num2)).Equals((( Int32 ) 66)));
		CxAssert(((Int32)(( Int32 ) x_num / ( Int32 ) ( Int32 ) x_num3)).Equals((( Int32 ) 66)));
		CxAssert(((Int64)(( Int64 ) x_num / ( Int64 ) x_num4)).Equals((( Int64 ) 66)));
		CxAssert(((Double)(( Double ) ( Int32 ) x_num / ( Double ) x_num5)).Equals((( Double ) 66)));
		CxAssert(((Int32)(( Int32 ) x_num % ( Int32 ) ( Int32 ) x_c)).Equals((( Int32 ) 0)));
		CxAssert(((Int32)(( Int32 ) x_num % ( Int32 ) x_num2)).Equals((( Int32 ) 0)));
		CxAssert(((Int32)(( Int32 ) x_num % ( Int32 ) ( Int32 ) x_num3)).Equals((( Int32 ) 0)));
		CxAssert(((Int64)(( Int64 ) x_num % ( Int64 ) x_num4)).Equals((( Int64 ) 0)));
		CxAssert(((Double)(( Double ) ( Int32 ) x_num % ( Double ) x_num5)).Equals((( Double ) 0)));
		CxAssert(( x_num & ( Char ) x_c ) == (( Int32 ) 0));
		CxAssert(( x_num & ( Int32 ) x_num2 ) == (( Int32 ) 0));
		CxAssert(( x_num & ( UInt16 ) x_num3 ) == (( Int32 ) 0));
		CxAssert(( x_num & ( Int64 ) x_num4 ) == (( Int32 ) 0));
		CxAssert(( x_num | ( Char ) x_c ) == (( Int32 ) 67));
		CxAssert(( x_num | ( UInt16 ) x_num3 ) == (( Int32 ) 67));
		CxAssert(( x_num | ( Int64 ) x_num4 ) == (( Int32 ) 67));
		CxAssert(( x_num ^ ( Char ) x_c ) == (( Int32 ) 67));
		CxAssert(( x_num ^ ( Int32 ) x_num2 ) == (( Int32 ) 67));
		CxAssert(( x_num ^ ( UInt16 ) x_num3 ) == (( Int32 ) 67));
		CxAssert(( x_num ^ ( Int64 ) x_num4 ) == (( Int32 ) 67));
		CxAssert(((Int32)(~x_num)).Equals(( Int32 ) -67));
		CxAssert(x_c < ( UInt16 ) x_num);
		CxAssert(x_num2 < ( UInt16 ) x_num);
		CxAssert(x_num3 < ( UInt16 ) x_num);
		CxAssert(x_num4 < ( UInt16 ) x_num);
		CxAssert(x_num5 < ( Double ) ( Double ) ( Int32 ) x_num);
		CxAssert(x_c > ( UInt16 ) x_num,false);
		CxAssert(x_num2 > ( UInt16 ) x_num,false);
		CxAssert(x_num3 > ( UInt16 ) x_num,false);
		CxAssert(x_num4 > ( UInt16 ) x_num,false);
		CxAssert(x_num5 > ( Double ) ( Double ) ( Int32 ) x_num,false);
		CxAssert(( x_num = ( UInt16 ) ( UInt16 ) ( x_num + (( Int32 ) 1) ) ) == (( Int32 ) 67));
		CxAssert(( x_num = ( UInt16 ) ( UInt16 ) ( x_num - (( Int32 ) 1) ) ) == (( Int32 ) 66));
		CxAssert(((UInt16)(x_num++)).Equals((( UInt16 ) 66)));
		CxAssert(((UInt16)(x_num--)).Equals((( UInt16 ) 67)));
		CxAssert(((Int32)(x_num << (( Int32 ) 1))).Equals((( Int32 ) 132)));
		CxAssert(((Int32)(x_num >> (( Int32 ) 1))).Equals((( Int32 ) 33)));
		CxAssert(((Char)(x_c)).Equals(( Char ) x_num),false);
		CxAssert(((Int32)(x_num2)).Equals(( Int32 ) x_num),false);
		CxAssert(((UInt16)(x_num3)).Equals(( UInt16 ) x_num),false);
		CxAssert(((Int64)(x_num4)).Equals(( Int64 ) x_num),false);
		CxAssert(((Double)(x_num5)).Equals(( Double ) ( Double ) ( Int32 ) x_num),false);
		CxAssert(!((Char)(x_c)).Equals(( Char ) x_num));
		CxAssert(!((Int32)(x_num2)).Equals(( Int32 ) x_num));
		CxAssert(!((UInt16)(x_num3)).Equals(( UInt16 ) x_num));
		CxAssert(!((Int64)(x_num4)).Equals(( Int64 ) x_num));
		CxAssert(!((Double)(x_num5)).Equals(( Double ) ( Double ) ( Int32 ) x_num));
		CxAssert(x_c <= ( UInt16 ) x_num);
		CxAssert(x_num2 <= ( UInt16 ) x_num);
		CxAssert(x_num3 <= ( UInt16 ) x_num);
		CxAssert(x_num4 <= ( UInt16 ) x_num);
		CxAssert(x_num5 <= ( Double ) ( Double ) ( Int32 ) x_num);
		CxAssert(x_c >= ( UInt16 ) x_num,false);
		CxAssert(x_num2 >= ( UInt16 ) x_num,false);
		CxAssert(x_num3 >= ( UInt16 ) x_num,false);
		CxAssert(x_num4 >= ( UInt16 ) x_num,false);
		CxAssert(x_num5 >= ( Double ) ( Double ) ( Int32 ) x_num,false);
		CxAssert(( x_num = ( UInt16 ) ( UInt16 ) ( x_num + ( Char ) x_c ) ) == (( Int32 ) 67));
		CxAssert(( x_num = ( UInt16 ) ( UInt16 ) ( x_num - ( Char ) x_c ) ) == (( Int32 ) 66));
		CxAssert(( x_num = ( UInt16 ) ( UInt16 ) ( x_num + ( UInt16 ) x_num3 ) ) == (( Int32 ) 67));
		CxAssert(( x_num = ( UInt16 ) ( UInt16 ) ( x_num - ( UInt16 ) x_num3 ) ) == (( Int32 ) 66));
		CxAssert(( x_num = ( UInt16 ) ( UInt16 ) ( x_num * ( Char ) x_c ) ) == (( Int32 ) 66));
		CxAssert(( x_num = ( UInt16 ) ( UInt16 ) ( ( Int32 ) x_num / ( Int32 ) ( Int32 ) x_c ) ) == (( Int32 ) 66));
		CxAssert(( x_num = ( UInt16 ) ( UInt16 ) ( x_num * ( UInt16 ) x_num3 ) ) == (( Int32 ) 66));
		CxAssert(( x_num = ( UInt16 ) ( UInt16 ) ( ( Int32 ) x_num / ( Int32 ) ( Int32 ) x_num3 ) ) == (( Int32 ) 66));
		CxAssert(( x_num = ( UInt16 ) ( UInt16 ) ( ( Int32 ) x_num % ( Int32 ) ( Int32 ) x_c ) ) == (( Int32 ) 0));
		x_num = (( UInt16 ) 66);
		CxAssert(( x_num = ( UInt16 ) ( UInt16 ) ( ( Int32 ) x_num % ( Int32 ) ( Int32 ) x_num3 ) ) == (( Int32 ) 0));
		x_num = (( UInt16 ) 66);
		CxAssert(( x_num = ( UInt16 ) ( UInt16 ) ( x_num & ( Char ) x_c ) ) == (( Int32 ) 0));
		x_num = (( UInt16 ) 66);
		CxAssert(( x_num = ( UInt16 ) ( UInt16 ) ( x_num & ( UInt16 ) x_num3 ) ) == (( Int32 ) 0));
		x_num = (( UInt16 ) 66);
		CxAssert(( x_num = ( UInt16 ) ( UInt16 ) ( x_num | ( Char ) x_c ) ) == (( Int32 ) 67));
		x_num = (( UInt16 ) 66);
		CxAssert(( x_num = ( UInt16 ) ( UInt16 ) ( x_num | ( UInt16 ) x_num3 ) ) == (( Int32 ) 67));
		x_num = (( UInt16 ) 66);
		CxAssert(( x_num = ( UInt16 ) ( UInt16 ) ( x_num ^ ( Char ) x_c ) ) == (( Int32 ) 67));
		x_num = (( UInt16 ) 66);
		CxAssert(( x_num = ( UInt16 ) ( UInt16 ) ( x_num ^ ( UInt16 ) x_num3 ) ) == (( Int32 ) 67));
		x_num = (( UInt16 ) 66);
		CxAssert(( x_num = ( UInt16 ) ( UInt16 ) ( x_num << ( Int32 ) ( Int32 ) x_c ) ) == (( Int32 ) 132));
		x_num = (( UInt16 ) 66);
		CxAssert(( x_num = ( UInt16 ) ( UInt16 ) ( x_num << ( Int32 ) x_num2 ) ) == (( Int32 ) 132));
		x_num = (( UInt16 ) 66);
		CxAssert(( x_num = ( UInt16 ) ( UInt16 ) ( x_num >> ( Int32 ) ( Int32 ) x_c ) ) == (( Int32 ) 33));
		x_num = (( UInt16 ) 66);
		CxAssert(( x_num = ( UInt16 ) ( UInt16 ) ( x_num >> ( Int32 ) x_num2 ) ) == (( Int32 ) 33));
		x_num = (( UInt16 ) 66);
	}
	void UInt16TestRaw::UInt16ArrayTest()
	{
		static UInt16 UInt16ArrayTestArray0[5] = {1,2,3,4,5};
		static UInt16 UInt16ArrayTestArray1[4] = {1,2,3,4};
		static UInt16 UInt16ArrayTestArray2[2][4] = {{1,2,3,4},{4,5,6,7}};
		static UInt16 UInt16ArrayTestArray3[2][2][4] = {{{1,2,3,4},{5,6,7,8}},{{9,10,11,12},{13,14,15,16}}};
		PointerType<ArrayRaw<UInt16>> x_array = (new ArrayRaw<UInt16>(5))->Initialize((UInt16*) UInt16ArrayTestArray0);
		CxAssert(((Int32)(x_array->get_Length())).Equals((( Int32 ) 5)));
		CxAssert(((UInt16)((*x_array->Address(3)))).Equals((( UInt16 ) 4)));
		PointerType<ArrayRaw<UInt16>> x_array2 = (new ArrayRaw<UInt16>(4))->Initialize((UInt16*) UInt16ArrayTestArray1);
		CxAssert(((UInt16)((*x_array2->Address(1)))).Equals((( UInt16 ) 2)));
		PointerType<ArrayRaw<UInt16>> x_array3 = (new ArrayRaw<UInt16>(2,4))->Initialize((UInt16*) UInt16ArrayTestArray2);
		CxAssert(((UInt16)((*x_array3->Address(0,2)))).Equals((( UInt16 ) 3)));
		PointerType<ArrayRaw<UInt16>> x_array4 = (new ArrayRaw<UInt16>(2,2,4))->Initialize((UInt16*) UInt16ArrayTestArray3);
		CxAssert(((UInt16)((*x_array4->Address(0,0,3)))).Equals((( UInt16 ) 4)));
		(*x_array4->Address(0,0,3)) = (( UInt16 ) 6);
		CxAssert(((UInt16)((*x_array4->Address(0,0,3)))).Equals((( UInt16 ) 6)));
		x_array4->SetValue((( UInt16 ) 4),0,0,3);
		CxAssert(((UInt16)((*x_array4->Address(0,0,3)))).Equals((( UInt16 ) 4)));
	}
	void UInt16TestRaw::UInt16MiscTests()
	{
		UInt16 x_num = (( UInt16 ) 0);
		UInt16 x_num2 = (( UInt16 ) 1);
		CxAssert(((UInt16)(MathRaw::Max(x_num,x_num2))).Equals((( UInt16 ) 1)));
		CxAssert(((UInt16)(MathRaw::Min(x_num,x_num2))).Equals((( UInt16 ) 0)));
		PointerType<StringBuilderRaw> x_stringBuilder = new StringBuilderRaw();
		x_stringBuilder->Append(x_num2);
		CxAssert((x_stringBuilder->ToString())->Equals((new StringRaw("1"))));
		x_stringBuilder->Insert(1,x_num);
		CxAssert((x_stringBuilder->ToString())->Equals((new StringRaw("10"))));
	}
	void UInt16TestRaw::CxAssert(Boolean x_x)
	{
		if ( !x_x )
		{
			x_caBlock->TestFailed((new StringRaw("UInt16 TestFailed")));
		}
	}
	void UInt16TestRaw::CxAssert(Boolean x_x,Boolean x_y)
	{
		if ( !(x_x).Equals(x_y) )
		{
			x_caBlock->TestFailed((new StringRaw("UInt16 TestFailed")));
		}
	}
	UInt32TestRaw::UInt32TestRaw(CABlock x_caBlock)
	{
		this->x_caBlock.Assign(x_caBlock);
	}
	void UInt32TestRaw::Test()
	{
		x_caBlock->Send((new StringRaw("Doing UInt32Test")));
		x_caBlock->Send((new StringRaw("\tDoing UInt32MethodsTest")));
		UInt32MethodsTest();
		x_caBlock->Send((new StringRaw("\tDoing DoUnSignedMath")));
		DoUnSignedMath();
		x_caBlock->Send((new StringRaw("\tDoing UInt32Operators")));
		UInt32Operators();
		x_caBlock->Send((new StringRaw("\tDoing UInt32ArrayTest")));
		UInt32ArrayTest();
		x_caBlock->Send((new StringRaw("\tDoing UInt32MiscTests")));
		UInt32MiscTests();
	}
	void UInt32TestRaw::UInt32MethodsTest()
	{
		UInt32 x_num = (( UInt32 ) 5);
		CxAssert(((Int32)((( UInt32 ) x_num).CompareTo(5))).Equals((( Int32 ) 0)));
		CxAssert(((Int32)((( UInt32 ) x_num).CompareTo((new UInt32Box(5 ))))).Equals((( Int32 ) 0)));
		CxAssert((( UInt32 ) x_num).Equals(5));
		CxAssert((( UInt32 ) x_num).Equals((new UInt32Box(5 ))));
		CxAssert(((UInt32)(UInt32Raw::Parse((new StringRaw("77"))))).Equals((( UInt32 ) 77)));
		CxAssert(((new StringRaw("5")))->Equals((( UInt32 ) x_num).ToString()));
		x_num = ( UInt32 ) ((UInt32)4294967295);
		CxAssert(((Int32)(-1)).Equals(( Int32 ) ( Int32 ) x_num));
		x_num = (( UInt32 ) 0);
		CxAssert(((UInt32)(x_num)).Equals((( UInt32 ) 0)));
		String x_text = (( UInt32 ) ((UInt32)4294967295)).ToString();
		CxAssert((x_text)->Equals((new StringRaw("4294967295"))));
		CxAssert(((UInt32)(UInt32Raw::Parse(x_text))).Equals(( UInt32 ) ((UInt32)4294967295)));
		String x_text2 = ((( UInt32 ) 0)).ToString();
		CxAssert((x_text2)->Equals((new StringRaw("0"))));
		CxAssert(((UInt32)(UInt32Raw::Parse(x_text2))).Equals((( UInt32 ) 0)));
		Object x_obj = (new UInt32Box(5 ));
		CxAssert(x_obj->Equals(5));
		CxAssert((x_obj->ToString())->Equals((new StringRaw("5"))));
	}
	void UInt32TestRaw::DoUnSignedMath()
	{
		UInt32 x_num = (( UInt32 ) 60000);
		UInt32 x_num2 = (( UInt32 ) 120000);
		Int32 x_num3 = (( Int32 ) 1);
		CxAssert(1 <= ( UInt32 ) x_num);
		CxAssert(x_num >= (( Int32 ) 1));
		CxAssert(x_num >= ( Int32 ) x_num3);
		CxAssert(x_num3 <= ( UInt32 ) x_num);
		x_num3 = x_num3 + ( Int32 ) ( Int32 ) x_num;
		CxAssert(((Int32)(x_num3)).Equals((( Int32 ) 60001)));
		CxAssert(((UInt32)(x_num + ( UInt32 ) x_num2)).Equals((( UInt32 ) 180000)));
		CxAssert(((UInt32)(x_num - ( UInt32 ) x_num2)).Equals((( UInt32 ) 4294907296)));
		CxAssert(((UInt32)(x_num * ( UInt32 ) x_num2)).Equals((( UInt32 ) 2905032704)));
		CxAssert(((UInt32)(x_num2 / ( UInt32 ) x_num)).Equals((( UInt32 ) 2)));
		CxAssert(((UInt32)(x_num >> (( Int32 ) 2))).Equals((( UInt32 ) 15000)));
		CxAssert(((UInt32)(x_num << (( Int32 ) 1))).Equals((( UInt32 ) 120000)));
		Int32 x_num4 = (( Int32 ) 11);
		CxAssert(((Int32)(x_num4 % (( Int32 ) 5))).Equals((( Int32 ) 1)));
		x_num4 = (( Int32 ) 8);
		CxAssert(( x_num4 | (( Int32 ) 1) ) == (( Int32 ) 9));
		CxAssert(( x_num4 & (( Int32 ) 1) ) == (( Int32 ) 0));
		CxAssert(((Int32)(++x_num4)).Equals((( Int32 ) 9)));
		CxAssert(((Int32)(--x_num4)).Equals((( Int32 ) 8)));
		CxAssert(( x_num4 = x_num4 * (( Int32 ) 2) ) == (( Int32 ) 16));
		CxAssert(( x_num4 = x_num4 / (( Int32 ) 2) ) == (( Int32 ) 8));
		CxAssert(( x_num4 = x_num4 % (( Int32 ) 2) ) == (( Int32 ) 0));
		CxAssert(( x_num4 = x_num4 | (( Int32 ) 4) ) == (( Int32 ) 4));
		CxAssert(( x_num4 = x_num4 & (( Int32 ) 4) ) == (( Int32 ) 4));
		CxAssert(((Int64)(0 - ( UInt32 ) x_num)).Equals(( Int64 ) -60000));
		CxAssert(((UInt32)(x_num)).Equals((( UInt32 ) 60000)));
		UInt32 x_num5 = (( UInt32 ) 0);
		CxAssert(((UInt32)(~x_num5)).Equals(( UInt32 ) ((UInt32)4294967295)));
		CxAssert(((UInt32)(++x_num5)).Equals((( UInt32 ) 1)));
		CxAssert(((UInt32)(--x_num5)).Equals((( UInt32 ) 0)));
	}
	void UInt32TestRaw::UInt32Operators()
	{
		UInt32 x_num = (( UInt32 ) 66);
		Char x_c = ( Char ) '';
		Int32 x_num2 = (( Int32 ) 1);
		UInt32 x_num3 = (( UInt32 ) 1);
		Int64 x_num4 = (( Int64 ) 1);
		Double x_num5 = (( Double ) 1);
		CxAssert(((UInt32)(x_num)).Equals((( UInt32 ) 66)));
		CxAssert(((UInt32)(x_num + ( Char ) x_c)).Equals((( UInt32 ) 67)));
		CxAssert(((Int64)(x_num + ( Int32 ) x_num2)).Equals((( Int64 ) 67)));
		CxAssert(((UInt32)(x_num + ( UInt32 ) x_num3)).Equals((( UInt32 ) 67)));
		CxAssert(((Int64)(x_num + ( Int64 ) x_num4)).Equals((( Int64 ) 67)));
		CxAssert(((Double)(( Double ) x_num + ( Double ) x_num5)).Equals((( Double ) 67)));
		CxAssert(((UInt32)(x_num - ( Char ) x_c)).Equals((( UInt32 ) 65)));
		CxAssert(((Int64)(x_num - ( Int32 ) x_num2)).Equals((( Int64 ) 65)));
		CxAssert(((UInt32)(x_num - ( UInt32 ) x_num3)).Equals((( UInt32 ) 65)));
		CxAssert(((Int64)(x_num - ( Int64 ) x_num4)).Equals((( Int64 ) 65)));
		CxAssert(((Double)(( Double ) x_num - ( Double ) x_num5)).Equals((( Double ) 65)));
		CxAssert(((UInt32)(x_num * ( Char ) x_c)).Equals((( UInt32 ) 66)));
		CxAssert(((Int64)(x_num * ( Int32 ) x_num2)).Equals((( Int64 ) 66)));
		CxAssert(((UInt32)(x_num * ( UInt32 ) x_num3)).Equals((( UInt32 ) 66)));
		CxAssert(((Int64)(x_num * ( Int64 ) x_num4)).Equals((( Int64 ) 66)));
		CxAssert(((Double)(( Double ) x_num * ( Double ) x_num5)).Equals((( Double ) 66)));
		CxAssert(((UInt32)(x_num / ( Char ) x_c)).Equals((( UInt32 ) 66)));
		CxAssert(((Int64)(( Int64 ) x_num / ( Int64 ) ( Int64 ) x_num2)).Equals((( Int64 ) 66)));
		CxAssert(((UInt32)(x_num / ( UInt32 ) x_num3)).Equals((( UInt32 ) 66)));
		CxAssert(((Int64)(( Int64 ) x_num / ( Int64 ) x_num4)).Equals((( Int64 ) 66)));
		CxAssert(((Double)(( Double ) x_num / ( Double ) x_num5)).Equals((( Double ) 66)));
		CxAssert(((UInt32)(x_num % ( Char ) x_c)).Equals((( UInt32 ) 0)));
		CxAssert(((Int64)(( Int64 ) x_num % ( Int64 ) ( Int64 ) x_num2)).Equals((( Int64 ) 0)));
		CxAssert(((UInt32)(x_num % ( UInt32 ) x_num3)).Equals((( UInt32 ) 0)));
		CxAssert(((Int64)(( Int64 ) x_num % ( Int64 ) x_num4)).Equals((( Int64 ) 0)));
		CxAssert(((Double)(( Double ) x_num % ( Double ) x_num5)).Equals((( Double ) 0)));
		CxAssert(( x_num & ( Char ) x_c ) == (( Int32 ) 0));
		CxAssert(( x_num & ( Int32 ) x_num2 ) == (( Int32 ) 0));
		CxAssert(( x_num & ( UInt32 ) x_num3 ) == (( Int32 ) 0));
		CxAssert(( x_num & ( Int64 ) x_num4 ) == (( Int32 ) 0));
		CxAssert(( x_num | ( Char ) x_c ) == (( Int32 ) 67));
		CxAssert(( x_num | ( UInt32 ) x_num3 ) == (( Int32 ) 67));
		CxAssert(( x_num | ( Int64 ) x_num4 ) == (( Int32 ) 67));
		CxAssert(( x_num ^ ( Char ) x_c ) == (( Int32 ) 67));
		CxAssert(( x_num ^ ( Int32 ) x_num2 ) == (( Int32 ) 67));
		CxAssert(( x_num ^ ( UInt32 ) x_num3 ) == (( Int32 ) 67));
		CxAssert(( x_num ^ ( Int64 ) x_num4 ) == (( Int32 ) 67));
		CxAssert(((UInt32)(~x_num)).Equals((( UInt32 ) 4294967229)));
		CxAssert(x_c < ( UInt32 ) x_num);
		CxAssert(x_num2 < ( UInt32 ) x_num);
		CxAssert(x_num3 < ( UInt32 ) x_num);
		CxAssert(x_num4 < ( UInt32 ) x_num);
		CxAssert(x_num5 < ( Double ) ( Double ) x_num);
		CxAssert(x_c > ( UInt32 ) x_num,false);
		CxAssert(x_num2 > ( UInt32 ) x_num,false);
		CxAssert(x_num3 > ( UInt32 ) x_num,false);
		CxAssert(x_num4 > ( UInt32 ) x_num,false);
		CxAssert(x_num5 > ( Double ) ( Double ) x_num,false);
		CxAssert(((UInt32)(++x_num)).Equals((( UInt32 ) 67)));
		CxAssert(((UInt32)(--x_num)).Equals((( UInt32 ) 66)));
		CxAssert(((UInt32)(x_num++)).Equals((( UInt32 ) 66)));
		CxAssert(((UInt32)(x_num--)).Equals((( UInt32 ) 67)));
		CxAssert(((UInt32)(x_num << (( Int32 ) 1))).Equals((( UInt32 ) 132)));
		CxAssert(((UInt32)(x_num >> (( Int32 ) 1))).Equals((( UInt32 ) 33)));
		CxAssert(((Char)(x_c)).Equals(( Char ) x_num),false);
		CxAssert(((Int32)(x_num2)).Equals(( Int32 ) x_num),false);
		CxAssert(((UInt32)(x_num3)).Equals(( UInt32 ) x_num),false);
		CxAssert(((Int64)(x_num4)).Equals(( Int64 ) x_num),false);
		CxAssert(((Double)(x_num5)).Equals(( Double ) ( Double ) x_num),false);
		CxAssert(!((Char)(x_c)).Equals(( Char ) x_num));
		CxAssert(!((Int32)(x_num2)).Equals(( Int32 ) x_num));
		CxAssert(!((UInt32)(x_num3)).Equals(( UInt32 ) x_num));
		CxAssert(!((Int64)(x_num4)).Equals(( Int64 ) x_num));
		CxAssert(!((Double)(x_num5)).Equals(( Double ) ( Double ) x_num));
		CxAssert(x_c <= ( UInt32 ) x_num);
		CxAssert(x_num2 <= ( UInt32 ) x_num);
		CxAssert(x_num3 <= ( UInt32 ) x_num);
		CxAssert(x_num4 <= ( UInt32 ) x_num);
		CxAssert(x_num5 <= ( Double ) ( Double ) x_num);
		CxAssert(x_c >= ( UInt32 ) x_num,false);
		CxAssert(x_num2 >= ( UInt32 ) x_num,false);
		CxAssert(x_num3 >= ( UInt32 ) x_num,false);
		CxAssert(x_num4 >= ( UInt32 ) x_num,false);
		CxAssert(x_num5 >= ( Double ) ( Double ) x_num,false);
		CxAssert(( x_num = x_num + ( UInt32 ) x_c ) == (( Int32 ) 67));
		CxAssert(( x_num = x_num - ( UInt32 ) x_c ) == (( Int32 ) 66));
		CxAssert(( x_num = x_num + ( UInt32 ) x_num3 ) == (( Int32 ) 67));
		CxAssert(( x_num = x_num - ( UInt32 ) x_num3 ) == (( Int32 ) 66));
		CxAssert(( x_num = x_num * ( UInt32 ) x_c ) == (( Int32 ) 66));
		CxAssert(( x_num = x_num / ( UInt32 ) x_c ) == (( Int32 ) 66));
		CxAssert(( x_num = x_num * ( UInt32 ) x_num3 ) == (( Int32 ) 66));
		CxAssert(( x_num = x_num / ( UInt32 ) x_num3 ) == (( Int32 ) 66));
		CxAssert(( x_num = x_num % ( UInt32 ) x_c ) == (( Int32 ) 0));
		x_num = (( UInt32 ) 66);
		CxAssert(( x_num = x_num % ( UInt32 ) x_num3 ) == (( Int32 ) 0));
		x_num = (( UInt32 ) 66);
		CxAssert(( x_num = x_num & ( UInt32 ) x_c ) == (( Int32 ) 0));
		x_num = (( UInt32 ) 66);
		CxAssert(( x_num = x_num & ( UInt32 ) x_num3 ) == (( Int32 ) 0));
		x_num = (( UInt32 ) 66);
		CxAssert(( x_num = x_num | ( UInt32 ) x_c ) == (( Int32 ) 67));
		x_num = (( UInt32 ) 66);
		CxAssert(( x_num = x_num | ( UInt32 ) x_num3 ) == (( Int32 ) 67));
		x_num = (( UInt32 ) 66);
		CxAssert(( x_num = x_num ^ ( UInt32 ) x_c ) == (( Int32 ) 67));
		x_num = (( UInt32 ) 66);
		CxAssert(( x_num = x_num ^ ( UInt32 ) x_num3 ) == (( Int32 ) 67));
		x_num = (( UInt32 ) 66);
		CxAssert(( x_num = x_num << ( UInt32 ) ( Int32 ) x_c ) == (( Int32 ) 132));
		x_num = (( UInt32 ) 66);
		CxAssert(( x_num = x_num << ( UInt32 ) x_num2 ) == (( Int32 ) 132));
		x_num = (( UInt32 ) 66);
		CxAssert(( x_num = x_num >> ( UInt32 ) ( Int32 ) x_c ) == (( Int32 ) 33));
		x_num = (( UInt32 ) 66);
		CxAssert(( x_num = x_num >> ( UInt32 ) x_num2 ) == (( Int32 ) 33));
		x_num = (( UInt32 ) 66);
	}
	void UInt32TestRaw::UInt32ArrayTest()
	{
		static UInt32 UInt32ArrayTestArray0[5] = {1,2,3,4,5};
		static UInt32 UInt32ArrayTestArray1[4] = {1,2,3,4};
		static UInt32 UInt32ArrayTestArray2[2][4] = {{1,2,3,4},{4,5,6,7}};
		static UInt32 UInt32ArrayTestArray3[2][2][4] = {{{1,2,3,4},{5,6,7,8}},{{9,10,11,12},{13,14,15,16}}};
		PointerType<ArrayRaw<UInt32>> x_array = (new ArrayRaw<UInt32>(5))->Initialize((UInt32*) UInt32ArrayTestArray0);
		CxAssert(((Int32)(x_array->get_Length())).Equals((( Int32 ) 5)));
		CxAssert(((UInt32)((*x_array->Address(3)))).Equals((( UInt32 ) 4)));
		PointerType<ArrayRaw<UInt32>> x_array2 = (new ArrayRaw<UInt32>(4))->Initialize((UInt32*) UInt32ArrayTestArray1);
		CxAssert(((UInt32)((*x_array2->Address(1)))).Equals((( UInt32 ) 2)));
		PointerType<ArrayRaw<UInt32>> x_array3 = (new ArrayRaw<UInt32>(2,4))->Initialize((UInt32*) UInt32ArrayTestArray2);
		CxAssert(((UInt32)((*x_array3->Address(0,2)))).Equals((( UInt32 ) 3)));
		PointerType<ArrayRaw<UInt32>> x_array4 = (new ArrayRaw<UInt32>(2,2,4))->Initialize((UInt32*) UInt32ArrayTestArray3);
		CxAssert(((UInt32)((*x_array4->Address(0,0,3)))).Equals((( UInt32 ) 4)));
		(*x_array4->Address(0,0,3)) = (( UInt32 ) 6);
		CxAssert(((UInt32)((*x_array4->Address(0,0,3)))).Equals((( UInt32 ) 6)));
		x_array4->SetValue(4,0,0,3);
		CxAssert(((UInt32)((*x_array4->Address(0,0,3)))).Equals((( UInt32 ) 4)));
	}
	void UInt32TestRaw::UInt32MiscTests()
	{
		UInt32 x_val = (( UInt32 ) 0);
		UInt32 x_num = (( UInt32 ) 1);
		CxAssert(((UInt32)(MathRaw::Max(x_val,x_num))).Equals((( UInt32 ) 1)));
		CxAssert(((UInt32)(MathRaw::Min(x_val,x_num))).Equals((( UInt32 ) 0)));
		PointerType<StringBuilderRaw> x_stringBuilder = new StringBuilderRaw();
		x_stringBuilder->Append(x_num);
		CxAssert((x_stringBuilder->ToString())->Equals((new StringRaw("1"))));
	}
	void UInt32TestRaw::CxAssert(Boolean x_x)
	{
		if ( !x_x )
		{
			x_caBlock->TestFailed((new StringRaw("UInt32 TestFailed")));
		}
	}
	void UInt32TestRaw::CxAssert(Boolean x_x,Boolean x_y)
	{
		if ( !(x_x).Equals(x_y) )
		{
			x_caBlock->TestFailed((new StringRaw("UInt32 TestFailed")));
		}
	}
	UInt64TestRaw::UInt64TestRaw(CABlock x_caBlock)
	{
		this->x_caBlock.Assign(x_caBlock);
	}
	void UInt64TestRaw::Test()
	{
		x_caBlock->Send((new StringRaw("Doing UInt64Test")));
		x_caBlock->Send((new StringRaw("\tDoing UInt64MethodsTest")));
		UInt64MethodsTest();
		x_caBlock->Send((new StringRaw("\tDoing UInt64UnSignedMath")));
		UInt64UnSignedMath();
		x_caBlock->Send((new StringRaw("\tDoing UInt64Operators")));
		UInt64Operators();
		x_caBlock->Send((new StringRaw("\tDoing UInt64ArrayTest")));
		UInt64ArrayTest();
		x_caBlock->Send((new StringRaw("\tDoing UInt64MiscTests")));
		UInt64MiscTests();
	}
	void UInt64TestRaw::UInt64MethodsTest()
	{
		UInt64 x_num = (( UInt64 ) 5);
		CxAssert(((Int32)((( UInt64 ) x_num).CompareTo(5))).Equals((( Int32 ) 0)));
		CxAssert(((Int32)((( UInt64 ) x_num).CompareTo((new UInt64Box(5 ))))).Equals((( Int32 ) 0)));
		CxAssert((( UInt64 ) x_num).Equals(5));
		CxAssert((( UInt64 ) x_num).Equals((new UInt64Box(5 ))));
		CxAssert(((UInt64)(UInt64Raw::Parse((new StringRaw("77"))))).Equals((( UInt64 ) 77)));
		CxAssert(((new StringRaw("5")))->Equals((( UInt64 ) x_num).ToString()));
		x_num = ( UInt64 ) ((UInt64)18446744073709551615);
		CxAssert(((UInt64)(((UInt64)18446744073709551615))).Equals(( UInt64 ) x_num));
		x_num = (( UInt64 ) 0);
		CxAssert(((UInt64)(x_num)).Equals((( UInt64 ) 0)));
		String x_text = (( UInt64 ) ((UInt64)18446744073709551615)).ToString();
		CxAssert((x_text)->Equals((new StringRaw("18446744073709551615"))));
		CxAssert(((UInt64)(UInt64Raw::Parse(x_text))).Equals(( UInt64 ) ((UInt64)18446744073709551615)));
		String x_text2 = ((( UInt64 ) 0)).ToString();
		CxAssert((x_text2)->Equals((new StringRaw("0"))));
		CxAssert(((UInt64)(UInt64Raw::Parse(x_text2))).Equals((( UInt64 ) 0)));
		Object x_obj = (new UInt64Box(5 ));
		CxAssert(x_obj->Equals(5));
		CxAssert((x_obj->ToString())->Equals((new StringRaw("5"))));
	}
	void UInt64TestRaw::UInt64UnSignedMath()
	{
		UInt64 x_num = (( UInt64 ) 60000);
		UInt64 x_num2 = (( UInt64 ) 120000);
		UInt64 x_num3 = (( UInt64 ) 1);
		CxAssert(1 <= ( UInt64 ) x_num);
		CxAssert(x_num >= (( Int32 ) 1));
		CxAssert(x_num >= ( UInt64 ) x_num3);
		CxAssert(x_num3 <= ( UInt64 ) x_num);
		x_num3 = x_num3 + ( UInt64 ) x_num;
		CxAssert(((UInt64)(x_num3)).Equals((( UInt64 ) 60001)));
		CxAssert(((UInt64)(x_num + ( UInt64 ) x_num2)).Equals((( UInt64 ) 180000)));
		UInt64 x_num4 = ( UInt64 ) x_num - ( UInt64 ) x_num2;
		CxAssert(((UInt64)(x_num - ( UInt64 ) x_num2)).Equals((( UInt64 ) 18446744073709491616)));
		UInt64 x_num5 = ( UInt64 ) x_num * ( UInt64 ) x_num2;
		CxAssert(((UInt64)(x_num * ( UInt64 ) x_num2)).Equals((( UInt64 ) 7200000000)));
		CxAssert(((UInt64)(x_num2 / ( UInt64 ) x_num)).Equals((( UInt64 ) 2)));
		CxAssert(((UInt64)(x_num >> (( Int32 ) 2))).Equals((( UInt64 ) 15000)));
		CxAssert(((UInt64)(x_num << (( Int32 ) 1))).Equals((( UInt64 ) 120000)));
		Int32 x_num6 = (( Int32 ) 11);
		CxAssert(((Int32)(x_num6 % (( Int32 ) 5))).Equals((( Int32 ) 1)));
		x_num6 = (( Int32 ) 8);
		CxAssert(( x_num6 | (( Int32 ) 1) ) == (( Int32 ) 9));
		CxAssert(( x_num6 & (( Int32 ) 1) ) == (( Int32 ) 0));
		CxAssert(((Int32)(++x_num6)).Equals((( Int32 ) 9)));
		CxAssert(((Int32)(--x_num6)).Equals((( Int32 ) 8)));
		CxAssert(( x_num6 = x_num6 * (( Int32 ) 2) ) == (( Int32 ) 16));
		CxAssert(( x_num6 = x_num6 / (( Int32 ) 2) ) == (( Int32 ) 8));
		CxAssert(( x_num6 = x_num6 % (( Int32 ) 2) ) == (( Int32 ) 0));
		CxAssert(( x_num6 = x_num6 | (( Int32 ) 4) ) == (( Int32 ) 4));
		CxAssert(( x_num6 = x_num6 & (( Int32 ) 4) ) == (( Int32 ) 4));
		CxAssert(((UInt64)(x_num)).Equals((( UInt64 ) 60000)));
		UInt32 x_num7 = (( UInt32 ) 0);
		CxAssert(((UInt32)(~x_num7)).Equals(( UInt32 ) ((UInt32)4294967295)));
		CxAssert(((UInt32)(++x_num7)).Equals((( UInt32 ) 1)));
		CxAssert(((UInt32)(--x_num7)).Equals((( UInt32 ) 0)));
	}
	void UInt64TestRaw::UInt64Operators()
	{
		UInt64 x_num = (( UInt64 ) 66);
		Char x_c = ( Char ) '';
		Byte x_b = (( Byte ) 1);
		SByte x_b2 = (( SByte ) 1);
		Int16 x_num2 = (( Int16 ) 1);
		Int32 x_num3 = (( Int32 ) 1);
		Int64 x_num4 = (( Int64 ) 1);
		UInt16 x_num5 = (( UInt16 ) 1);
		UInt32 x_num6 = (( UInt32 ) 1);
		UInt64 x_num7 = (( UInt64 ) 1);
		Float x_num8 = (( Single ) 1);
		Double x_num9 = (( Double ) 1);
		CxAssert(((UInt64)(x_num)).Equals((( UInt64 ) 66)));
		CxAssert(((UInt64)(x_num + ( Char ) x_c)).Equals((( UInt64 ) 67)));
		CxAssert(((UInt64)(x_num + ( Byte ) x_b)).Equals((( UInt64 ) 67)));
		CxAssert(((Int64)(( Int64 ) x_num + ( Int64 ) ( Int64 ) x_b2)).Equals((( Int64 ) 67)));
		CxAssert(((Int64)(( Int64 ) x_num + ( Int64 ) ( Int64 ) x_num2)).Equals((( Int64 ) 67)));
		CxAssert(((Int64)(( Int64 ) x_num + ( Int64 ) ( Int64 ) x_num3)).Equals((( Int64 ) 67)));
		CxAssert(((Int64)(( Int64 ) x_num + ( Int64 ) x_num4)).Equals((( Int64 ) 67)));
		CxAssert(((UInt64)(x_num + ( UInt16 ) x_num5)).Equals((( UInt64 ) 67)));
		CxAssert(((UInt64)(x_num + ( UInt32 ) x_num6)).Equals((( UInt64 ) 67)));
		CxAssert(((UInt64)(x_num + ( UInt64 ) x_num7)).Equals((( UInt64 ) 67)));
		CxAssert(((Single)(( Single ) x_num + ( Single ) x_num8)).Equals((( Single ) 67)));
		CxAssert(((Double)(( Double ) x_num + ( Double ) x_num9)).Equals((( Double ) 67)));
		CxAssert(((UInt64)(x_num - ( Char ) x_c)).Equals((( UInt64 ) 65)));
		CxAssert(((UInt64)(x_num - ( Byte ) x_b)).Equals((( UInt64 ) 65)));
		CxAssert(((Int64)(( Int64 ) x_num - ( Int64 ) ( Int64 ) x_b2)).Equals((( Int64 ) 65)));
		CxAssert(((Int64)(( Int64 ) x_num - ( Int64 ) ( Int64 ) x_num2)).Equals((( Int64 ) 65)));
		CxAssert(((Int64)(( Int64 ) x_num - ( Int64 ) ( Int64 ) x_num3)).Equals((( Int64 ) 65)));
		CxAssert(((Int64)(( Int64 ) x_num - ( Int64 ) x_num4)).Equals((( Int64 ) 65)));
		CxAssert(((UInt64)(x_num - ( UInt16 ) x_num5)).Equals((( UInt64 ) 65)));
		CxAssert(((UInt64)(x_num - ( UInt32 ) x_num6)).Equals((( UInt64 ) 65)));
		CxAssert(((UInt64)(x_num - ( UInt64 ) x_num7)).Equals((( UInt64 ) 65)));
		CxAssert(((Single)(( Single ) x_num - ( Single ) x_num8)).Equals((( Single ) 65)));
		CxAssert(((Double)(( Double ) x_num - ( Double ) x_num9)).Equals((( Double ) 65)));
		CxAssert(((UInt64)(x_num * ( Char ) x_c)).Equals((( UInt64 ) 66)));
		CxAssert(((UInt64)(x_num * ( Byte ) x_b)).Equals((( UInt64 ) 66)));
		CxAssert(((Int64)(( Int64 ) x_num * ( Int64 ) ( Int64 ) x_b2)).Equals((( Int64 ) 66)));
		CxAssert(((Int64)(( Int64 ) x_num * ( Int64 ) ( Int64 ) x_num2)).Equals((( Int64 ) 66)));
		CxAssert(((Int64)(( Int64 ) x_num * ( Int64 ) ( Int64 ) x_num3)).Equals((( Int64 ) 66)));
		CxAssert(((Int64)(( Int64 ) x_num * ( Int64 ) x_num4)).Equals((( Int64 ) 66)));
		CxAssert(((UInt64)(x_num * ( UInt16 ) x_num5)).Equals((( UInt64 ) 66)));
		CxAssert(((UInt64)(x_num * ( UInt32 ) x_num6)).Equals((( UInt64 ) 66)));
		CxAssert(((UInt64)(x_num * ( UInt64 ) x_num7)).Equals((( UInt64 ) 66)));
		CxAssert(((Single)(( Single ) x_num * ( Single ) x_num8)).Equals((( Single ) 66)));
		CxAssert(((Double)(( Double ) x_num * ( Double ) x_num9)).Equals((( Double ) 66)));
		CxAssert(((UInt64)(x_num / ( Char ) x_c)).Equals((( UInt64 ) 66)));
		CxAssert(((UInt64)(x_num / ( Byte ) x_b)).Equals((( UInt64 ) 66)));
		CxAssert(((UInt64)(x_num / ( UInt64 ) ( UInt64 ) x_b2)).Equals((( UInt64 ) 66)));
		CxAssert(((UInt64)(x_num / ( UInt64 ) ( UInt64 ) x_num2)).Equals((( UInt64 ) 66)));
		CxAssert(((UInt64)(x_num / ( UInt64 ) ( UInt64 ) x_num3)).Equals((( UInt64 ) 66)));
		CxAssert(((UInt64)(x_num / ( UInt64 ) ( UInt64 ) x_num4)).Equals((( UInt64 ) 66)));
		CxAssert(((UInt64)(x_num / ( UInt16 ) x_num5)).Equals((( UInt64 ) 66)));
		CxAssert(((UInt64)(x_num / ( UInt32 ) x_num6)).Equals((( UInt64 ) 66)));
		CxAssert(((UInt64)(x_num / ( UInt64 ) x_num7)).Equals((( UInt64 ) 66)));
		CxAssert(((Single)(( Single ) x_num / ( Single ) x_num8)).Equals((( Single ) 66)));
		CxAssert(((Double)(( Double ) x_num / ( Double ) x_num9)).Equals((( Double ) 66)));
		CxAssert(((UInt64)(x_num % ( Char ) x_c)).Equals((( UInt64 ) 0)));
		CxAssert(((UInt64)(x_num % ( Byte ) x_b)).Equals((( UInt64 ) 0)));
		CxAssert(((UInt64)(x_num % ( UInt64 ) ( UInt64 ) x_b2)).Equals((( UInt64 ) 0)));
		CxAssert(((UInt64)(x_num % ( UInt64 ) ( UInt64 ) x_num2)).Equals((( UInt64 ) 0)));
		CxAssert(((UInt64)(x_num % ( UInt64 ) ( UInt64 ) x_num3)).Equals((( UInt64 ) 0)));
		CxAssert(((UInt64)(x_num % ( UInt64 ) ( UInt64 ) x_num4)).Equals((( UInt64 ) 0)));
		CxAssert(((UInt64)(x_num % ( UInt16 ) x_num5)).Equals((( UInt64 ) 0)));
		CxAssert(((UInt64)(x_num % ( UInt32 ) x_num6)).Equals((( UInt64 ) 0)));
		CxAssert(((UInt64)(x_num % ( UInt64 ) x_num7)).Equals((( UInt64 ) 0)));
		CxAssert(((Single)(( Single ) x_num % ( Single ) x_num8)).Equals((( Single ) 0)));
		CxAssert(((Double)(( Double ) x_num % ( Double ) x_num9)).Equals((( Double ) 0)));
		CxAssert(( x_num & ( Char ) x_c ) == (( Int32 ) 0));
		CxAssert(( x_num & ( Byte ) x_b ) == (( Int32 ) 0));
		CxAssert(( ( Int64 ) x_num & ( Int64 ) ( Int64 ) x_b2 ) == (( Int32 ) 0));
		CxAssert(( ( Int64 ) x_num & ( Int64 ) ( Int64 ) x_num2 ) == (( Int32 ) 0));
		CxAssert(( ( Int64 ) x_num & ( Int64 ) ( Int64 ) x_num3 ) == (( Int32 ) 0));
		CxAssert(( ( Int64 ) x_num & ( Int64 ) x_num4 ) == (( Int32 ) 0));
		CxAssert(( x_num & ( UInt16 ) x_num5 ) == (( Int32 ) 0));
		CxAssert(( x_num & ( UInt32 ) x_num6 ) == (( Int32 ) 0));
		CxAssert(( x_num & ( UInt64 ) x_num7 ) == (( Int32 ) 0));
		CxAssert(( x_num | ( Char ) x_c ) == (( Int32 ) 67));
		CxAssert(( x_num | ( Byte ) x_b ) == (( Int32 ) 67));
		CxAssert(( ( Int64 ) x_num | ( Int64 ) ( Int64 ) x_b2 ) == (( Int32 ) 67));
		CxAssert(( ( Int64 ) x_num | ( Int64 ) ( Int64 ) x_num2 ) == (( Int32 ) 67));
		CxAssert(( ( Int64 ) x_num | ( Int64 ) ( Int64 ) x_num3 ) == (( Int32 ) 67));
		CxAssert(( ( Int64 ) x_num | ( Int64 ) x_num4 ) == (( Int32 ) 67));
		CxAssert(( x_num | ( UInt16 ) x_num5 ) == (( Int32 ) 67));
		CxAssert(( x_num | ( UInt32 ) x_num6 ) == (( Int32 ) 67));
		CxAssert(( x_num | ( UInt64 ) x_num7 ) == (( Int32 ) 67));
		CxAssert(( x_num ^ ( Char ) x_c ) == (( Int32 ) 67));
		CxAssert(( x_num ^ ( Byte ) x_b ) == (( Int32 ) 67));
		CxAssert(( ( Int64 ) x_num ^ ( Int64 ) ( Int64 ) x_b2 ) == (( Int32 ) 67));
		CxAssert(( ( Int64 ) x_num ^ ( Int64 ) ( Int64 ) x_num2 ) == (( Int32 ) 67));
		CxAssert(( ( Int64 ) x_num ^ ( Int64 ) ( Int64 ) x_num3 ) == (( Int32 ) 67));
		CxAssert(( ( Int64 ) x_num ^ ( Int64 ) x_num4 ) == (( Int32 ) 67));
		CxAssert(( x_num ^ ( UInt16 ) x_num5 ) == (( Int32 ) 67));
		CxAssert(( x_num ^ ( UInt32 ) x_num6 ) == (( Int32 ) 67));
		CxAssert(( x_num ^ ( UInt64 ) x_num7 ) == (( Int32 ) 67));
		CxAssert(((Byte)(( Byte ) ( ~x_num ))).Equals((( Byte ) 189)));
		CxAssert(x_c < ( UInt64 ) x_num);
		CxAssert(x_b < ( UInt64 ) x_num);
		CxAssert(( UInt64 ) x_b2 < ( UInt64 ) x_num);
		CxAssert(( UInt64 ) x_num2 < ( UInt64 ) x_num);
		CxAssert(( UInt64 ) x_num3 < ( UInt64 ) x_num);
		CxAssert(( UInt64 ) x_num4 < ( UInt64 ) x_num);
		CxAssert(x_num5 < ( UInt64 ) x_num);
		CxAssert(x_num6 < ( UInt64 ) x_num);
		CxAssert(x_num7 < ( UInt64 ) x_num);
		CxAssert(x_num8 < ( Single ) ( Single ) x_num);
		CxAssert(x_num9 < ( Double ) ( Double ) x_num);
		CxAssert(x_c > ( UInt64 ) x_num,false);
		CxAssert(x_b > ( UInt64 ) x_num,false);
		CxAssert(( UInt64 ) x_b2 > ( UInt64 ) x_num,false);
		CxAssert(( UInt64 ) x_num2 > ( UInt64 ) x_num,false);
		CxAssert(( UInt64 ) x_num3 > ( UInt64 ) x_num,false);
		CxAssert(( UInt64 ) x_num4 > ( UInt64 ) x_num,false);
		CxAssert(x_num5 > ( UInt64 ) x_num,false);
		CxAssert(x_num6 > ( UInt64 ) x_num,false);
		CxAssert(x_num7 > ( UInt64 ) x_num,false);
		CxAssert(x_num8 > ( Single ) ( Single ) x_num,false);
		CxAssert(x_num9 > ( Double ) ( Double ) x_num,false);
		CxAssert(((UInt64)(++x_num)).Equals((( UInt64 ) 67)));
		CxAssert(((UInt64)(--x_num)).Equals((( UInt64 ) 66)));
		CxAssert(((UInt64)(x_num++)).Equals((( UInt64 ) 66)));
		CxAssert(((UInt64)(x_num--)).Equals((( UInt64 ) 67)));
		CxAssert(((UInt64)(x_num << (( Int32 ) 1))).Equals((( UInt64 ) 132)));
		CxAssert(((UInt64)(x_num >> (( Int32 ) 1))).Equals((( UInt64 ) 33)));
		CxAssert(((Char)(x_c)).Equals(( Char ) x_num),false);
		CxAssert(((Byte)(x_b)).Equals(( Byte ) x_num),false);
		CxAssert(((UInt64)(( UInt64 ) x_b2)).Equals(( UInt64 ) x_num),false);
		CxAssert(((UInt64)(( UInt64 ) x_num2)).Equals(( UInt64 ) x_num),false);
		CxAssert(((UInt64)(( UInt64 ) x_num3)).Equals(( UInt64 ) x_num),false);
		CxAssert(((Int64)(x_num4)).Equals(( Int64 ) ( Int64 ) x_num),false);
		CxAssert(((UInt16)(x_num5)).Equals(( UInt16 ) x_num),false);
		CxAssert(((UInt32)(x_num6)).Equals(( UInt32 ) x_num),false);
		CxAssert(((UInt64)(x_num7)).Equals(( UInt64 ) x_num),false);
		CxAssert(((Single)(x_num8)).Equals(( Single ) ( Single ) x_num),false);
		CxAssert(((Double)(x_num9)).Equals(( Double ) ( Double ) x_num),false);
		CxAssert(!((Char)(x_c)).Equals(( Char ) x_num));
		CxAssert(!((Byte)(x_b)).Equals(( Byte ) x_num));
		CxAssert(!((UInt64)(( UInt64 ) x_b2)).Equals(( UInt64 ) x_num));
		CxAssert(!((UInt64)(( UInt64 ) x_num2)).Equals(( UInt64 ) x_num));
		CxAssert(!((UInt64)(( UInt64 ) x_num3)).Equals(( UInt64 ) x_num));
		CxAssert(!((Int64)(x_num4)).Equals(( Int64 ) ( Int64 ) x_num));
		CxAssert(!((UInt16)(x_num5)).Equals(( UInt16 ) x_num));
		CxAssert(!((UInt32)(x_num6)).Equals(( UInt32 ) x_num));
		CxAssert(!((UInt64)(x_num7)).Equals(( UInt64 ) x_num));
		CxAssert(!((Single)(x_num8)).Equals(( Single ) ( Single ) x_num));
		CxAssert(!((Double)(x_num9)).Equals(( Double ) ( Double ) x_num));
		CxAssert(x_c <= ( UInt64 ) x_num);
		CxAssert(x_b <= ( UInt64 ) x_num);
		CxAssert(( UInt64 ) x_b2 <= ( UInt64 ) x_num);
		CxAssert(( UInt64 ) x_num2 <= ( UInt64 ) x_num);
		CxAssert(( UInt64 ) x_num3 <= ( UInt64 ) x_num);
		CxAssert(( UInt64 ) x_num4 <= ( UInt64 ) x_num);
		CxAssert(x_num5 <= ( UInt64 ) x_num);
		CxAssert(x_num6 <= ( UInt64 ) x_num);
		CxAssert(x_num7 <= ( UInt64 ) x_num);
		CxAssert(x_num8 <= ( Single ) ( Single ) x_num);
		CxAssert(x_num9 <= ( Double ) ( Double ) x_num);
		CxAssert(x_c >= ( UInt64 ) x_num,false);
		CxAssert(x_b >= ( UInt64 ) x_num,false);
		CxAssert(( UInt64 ) x_b2 >= ( UInt64 ) x_num,false);
		CxAssert(( UInt64 ) x_num2 >= ( UInt64 ) x_num,false);
		CxAssert(( UInt64 ) x_num3 >= ( UInt64 ) x_num,false);
		CxAssert(( UInt64 ) x_num4 >= ( UInt64 ) x_num,false);
		CxAssert(x_num5 >= ( UInt64 ) x_num,false);
		CxAssert(x_num6 >= ( UInt64 ) x_num,false);
		CxAssert(x_num7 >= ( UInt64 ) x_num,false);
		CxAssert(x_num8 >= ( Single ) ( Single ) x_num,false);
		CxAssert(x_num9 >= ( Double ) ( Double ) x_num,false);
		CxAssert(( x_num = x_num + ( UInt64 ) ( Byte ) x_c ) == (( Int32 ) 67));
		CxAssert(( x_num = x_num - ( UInt64 ) ( Byte ) x_c ) == (( Int32 ) 66));
		CxAssert(( x_num = x_num + ( UInt64 ) ( Byte ) x_num6 ) == (( Int32 ) 67));
		CxAssert(( x_num = x_num - ( UInt64 ) ( Byte ) x_num6 ) == (( Int32 ) 66));
		CxAssert(( x_num = x_num * ( UInt64 ) ( Byte ) x_c ) == (( Int32 ) 66));
		CxAssert(( x_num = x_num / ( UInt64 ) ( Byte ) x_c ) == (( Int32 ) 66));
		CxAssert(( x_num = x_num * ( UInt64 ) ( Byte ) x_num6 ) == (( Int32 ) 66));
		CxAssert(( x_num = x_num / ( UInt64 ) ( Byte ) x_num6 ) == (( Int32 ) 66));
		CxAssert(( x_num = x_num % ( UInt64 ) ( Byte ) x_c ) == (( Int32 ) 0));
		x_num = (( UInt64 ) 66);
		CxAssert(( x_num = x_num % ( UInt64 ) ( Byte ) x_num6 ) == (( Int32 ) 0));
		x_num = (( UInt64 ) 66);
		CxAssert(( x_num = x_num & ( UInt64 ) ( Byte ) x_c ) == (( Int32 ) 0));
		x_num = (( UInt64 ) 66);
		CxAssert(( x_num = x_num & ( UInt64 ) ( Byte ) x_num6 ) == (( Int32 ) 0));
		x_num = (( UInt64 ) 66);
		CxAssert(( x_num = x_num | ( UInt64 ) ( Byte ) x_c ) == (( Int32 ) 67));
		x_num = (( UInt64 ) 66);
		CxAssert(( x_num = x_num | ( UInt64 ) ( Byte ) x_num6 ) == (( Int32 ) 67));
		x_num = (( UInt64 ) 66);
		CxAssert(( x_num = x_num ^ ( UInt64 ) ( Byte ) x_c ) == (( Int32 ) 67));
		x_num = (( UInt64 ) 66);
		CxAssert(( x_num = x_num ^ ( UInt64 ) ( Byte ) x_num6 ) == (( Int32 ) 67));
		x_num = (( UInt64 ) 66);
		CxAssert(( x_num = x_num << ( UInt64 ) ( Int32 ) x_c ) == (( Int32 ) 132));
		x_num = (( UInt64 ) 66);
		CxAssert(( x_num = x_num << ( UInt64 ) x_num3 ) == (( Int32 ) 132));
		x_num = (( UInt64 ) 66);
		CxAssert(( x_num = x_num >> ( UInt64 ) ( Int32 ) x_c ) == (( Int32 ) 33));
		x_num = (( UInt64 ) 66);
		CxAssert(( x_num = x_num >> ( UInt64 ) x_num3 ) == (( Int32 ) 33));
		x_num = (( UInt64 ) 66);
		Char x_c2 = ( Char ) 'B';
		CxAssert(( x_c2 = ( Char ) ( Char ) ( ( UInt32 ) x_c2 << ( Int32 ) ( Int32 ) x_c ) ) == ( Char ) '');
	}
	void UInt64TestRaw::UInt64ArrayTest()
	{
		static UInt64 UInt64ArrayTestArray0[5] = {1,2,3,4,5};
		static UInt64 UInt64ArrayTestArray1[4] = {1,2,3,4};
		static UInt64 UInt64ArrayTestArray2[2][4] = {{1,2,3,4},{4,5,6,7}};
		static UInt64 UInt64ArrayTestArray3[2][2][4] = {{{1,2,3,4},{5,6,7,8}},{{9,10,11,12},{13,14,15,16}}};
		PointerType<ArrayRaw<UInt64>> x_array = (new ArrayRaw<UInt64>(5))->Initialize((UInt64*) UInt64ArrayTestArray0);
		CxAssert(((Int32)(x_array->get_Length())).Equals((( Int32 ) 5)));
		CxAssert(((UInt64)((*x_array->Address(3)))).Equals((( UInt64 ) 4)));
		PointerType<ArrayRaw<UInt64>> x_array2 = (new ArrayRaw<UInt64>(4))->Initialize((UInt64*) UInt64ArrayTestArray1);
		CxAssert(((UInt64)((*x_array2->Address(1)))).Equals((( UInt64 ) 2)));
		PointerType<ArrayRaw<UInt64>> x_array3 = (new ArrayRaw<UInt64>(2,4))->Initialize((UInt64*) UInt64ArrayTestArray2);
		CxAssert(((UInt64)((*x_array3->Address(0,2)))).Equals((( UInt64 ) 3)));
		PointerType<ArrayRaw<UInt64>> x_array4 = (new ArrayRaw<UInt64>(2,2,4))->Initialize((UInt64*) UInt64ArrayTestArray3);
		CxAssert(((UInt64)((*x_array4->Address(0,0,3)))).Equals((( UInt64 ) 4)));
		(*x_array4->Address(0,0,3)) = (( UInt64 ) 6);
		CxAssert(((UInt64)((*x_array4->Address(0,0,3)))).Equals((( UInt64 ) 6)));
		x_array4->SetValue(4,0,0,3);
		CxAssert(((UInt64)((*x_array4->Address(0,0,3)))).Equals((( UInt64 ) 4)));
	}
	void UInt64TestRaw::UInt64MiscTests()
	{
		UInt64 x_num = (( UInt64 ) 0);
		UInt64 x_num2 = (( UInt64 ) 1);
		CxAssert(((UInt64)(MathRaw::Max(x_num,x_num2))).Equals((( UInt64 ) 1)));
		CxAssert(((UInt64)(MathRaw::Min(x_num,x_num2))).Equals((( UInt64 ) 0)));
		PointerType<StringBuilderRaw> x_stringBuilder = new StringBuilderRaw();
		x_stringBuilder->Append(x_num2);
		CxAssert((x_stringBuilder->ToString())->Equals((new StringRaw("1"))));
		x_stringBuilder->Insert(1,x_num);
		CxAssert((x_stringBuilder->ToString())->Equals((new StringRaw("10"))));
	}
	void UInt64TestRaw::CxAssert(Boolean x_x)
	{
		if ( !x_x )
		{
			x_caBlock->TestFailed((new StringRaw("UInt64 TestFailed")));
		}
	}
	void UInt64TestRaw::CxAssert(Boolean x_x,Boolean x_y)
	{
		if ( !(x_x).Equals(x_y) )
		{
			x_caBlock->TestFailed((new StringRaw("UInt64 TestFailed")));
		}
	}
}
