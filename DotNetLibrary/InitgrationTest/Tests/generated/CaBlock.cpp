#pragma once
#include "CaBlockHeader.h"
namespace UNNAMED
{
	TestNameEnu Typedef::get_Friend()
	{
		return x_friend;
	}
	void Typedef::set_Friend(TestNameEnu x_value )
	{
		x_friend = x_value;
	}
	Typedef::Typedef()
	{
	}
	TestNameEnu Typedef1::x_friend()
	{
		return x_friend_TestNameEnu;
	}
	Typedef1::Typedef1()
	{
	}
}
namespace CABlock_Extra_NS
{
	TestNamespaceClass::TestNamespaceClass()
	{
	}
}
namespace CABlock_NS
{
	ArrayTest::ArrayTest(CABlock* x_caBlock)
	{
		x_dateTime2dArray = (new Array(DateTimeType,4,4));
		x_dateTime3dArray = (new Array(DateTimeType,4,4,4));
		x_timeSpan1dArray = (new Array(TimeSpanType,4));
		x_timeSpan2dArray = (new Array(TimeSpanType,4,4));
		x_timeSpan3dArray = (new Array(TimeSpanType,4,4,4));
		this->x_caBlock = x_caBlock;
	}
	void ArrayTest::Test()
	{
		Int32 x_num = 0;
		Int32 x_num2 = 0;
		Int32 x_num3 = 0;
		Int32 x_num4 = x_num++ + x_num2++ + x_num3-- + x_num + x_num2 + x_num3;
		CxAssert(!(Int32Value(x_num4)).Equals((Int32)0));
		x_caBlock->Send((new String((Char*)L"Doing ArrayTest")));
		x_caBlock->Send((new String((Char*)L"\tDoing TestArrayCreation")));
		TestArrayCreation();
		x_caBlock->Send((new String((Char*)L"\tDoing MiscTest")));
		MiscTest();
		x_caBlock->Send((new String((Char*)L"\tDoing ArrayMethodTests")));
		ArrayMethodTests();
	}
	void ArrayTest::TestArrayCreation()
	{
		static Int32 TestArrayCreationArray0[4] = {1,2,3,4};
		static Int32 TestArrayCreationArray1[2][4] = {{1,2,3,4},{4,5,6,7}};
		static Int32 TestArrayCreationArray2[2][2][4] = {{{1,2,3,4},{5,6,7,8}},{{9,10,11,12},{13,14,15,16}}};
		static Double TestArrayCreationArray3[4] = {1,2,3,4};
		static Double TestArrayCreationArray4[2][4] = {{1,2,3,4},{4,5,6,7}};
		static Double TestArrayCreationArray5[2][2][4] = {{{1,2,3,4},{5,6,7,8}},{{9,10,11,12},{13,14,15,16}}};
		static DateTime TestArrayCreationArray6[4] = {DateTime(2003,7,23,12,30,30,100),DateTime(2003,7,23,12,30,30,200),DateTime(2003,7,23,12,30,30,300),DateTime(2003,7,23,12,30,30,400)};
		x_boolArray = (new Array(BooleanType,4));
		x_int1dArray = (new Array(Int32Type,4))->Initialize((Int32*) TestArrayCreationArray0);
		CxAssert((Int32Value(((*((Int32*)x_int1dArray->Address(1)))))).Equals(2));
		x_int2dArray = (new Array(Int32Type,2,4))->Initialize((Int32*) TestArrayCreationArray1);
		CxAssert((Int32Value(((*((Int32*)x_int2dArray->Address(0,2)))))).Equals(3));
		x_int3dArray = (new Array(Int32Type,2,2,4))->Initialize((Int32*) TestArrayCreationArray2);
		CxAssert((Int32Value(((*((Int32*)x_int3dArray->Address(0,0,3)))))).Equals(4));
		x_double1dArray = (new Array(DoubleType,4))->Initialize((Double*) TestArrayCreationArray3);
		CxAssert((DoubleValue(((*((Double*)x_double1dArray->Address(1)))))).Equals(2));
		x_double2dArray = (new Array(DoubleType,2,4))->Initialize((Double*) TestArrayCreationArray4);
		CxAssert((DoubleValue(((*((Double*)x_double2dArray->Address(0,2)))))).Equals(3));
		x_double3dArray = (new Array(DoubleType,2,2,4))->Initialize((Double*) TestArrayCreationArray5);
		CxAssert((DoubleValue(((*((Double*)x_double3dArray->Address(0,0,3)))))).Equals(4));
		x_dateTime1dArray = (new Array(DateTimeType,4))->Initialize((DateTime*) TestArrayCreationArray6);
		CxAssert(((*((DateTime*)x_dateTime1dArray->Address(2)))).Equals((DateTime(2003,7,23,12,30,30,300))));
		((*((DateTime*)x_dateTime2dArray->Address(1,1)))) = (DateTime(2003,7,23,12,30,30,100));
		((*((DateTime*)x_dateTime3dArray->Address(1,1,1)))) = (DateTime(2003,7,23,12,30,30,100));
		((*((TimeSpan*)x_timeSpan1dArray->Address(0)))) = TimeSpan();
		((*((TimeSpan*)x_timeSpan1dArray->Address(0)))) = (TimeSpan(5,4,3,2,100));
		((*((TimeSpan*)x_timeSpan1dArray->Address(1)))) = (TimeSpan(5,4,3,2,200));
		((*((TimeSpan*)x_timeSpan1dArray->Address(2)))) = (TimeSpan(5,4,3,2,300));
		((*((TimeSpan*)x_timeSpan1dArray->Address(3)))) = (TimeSpan(5,4,3,2,400));
		((*((TimeSpan*)x_timeSpan2dArray->Address(1,1)))) = (TimeSpan(5,4,3,2,100));
		((*((TimeSpan*)x_timeSpan3dArray->Address(1,1,1)))) = (TimeSpan(5,4,3,2,100));
	}
	void ArrayTest::MiscTest()
	{
		CxAssert((Int32Value(x_int3dArray->GetLength(2))).Equals(4));
		CxAssert((Int32Value(x_int3dArray->GetLowerBound(2))).Equals((Int32)0));
		CxAssert((Int32Value(x_int3dArray->GetUpperBound(2))).Equals(3));
		Array* x_array = x_dateTime1dArray;
		for ( Int32 foreachi = 0; foreachi < x_array->GetLength(0) ; ++foreachi ) 
		{
			DateTime x_dateTime = ((*((DateTime*)x_array->Address(foreachi))));			String* x_text = x_dateTime.ToString();
		}
	}
	void ArrayTest::ArrayMethodTests()
	{
		static Int32 ArrayMethodTestsArray0[3] = {1,1,1};
		static Double ArrayMethodTestsArray1[4] = {1,2,3,4};
		Int32 x_length = x_int3dArray->get_Length();
		CxAssert((Int32Value(x_length)).Equals(16));
		CxAssert((Int32Value(x_int1dArray->get_Rank())).Equals(1));
		CxAssert((Int32Value(x_int2dArray->get_Rank())).Equals(2));
		CxAssert((Int32Value(x_int3dArray->get_Rank())).Equals(3));
		Array* x_array = (new Array(DateTimeType,5));
		Array::Copy(x_dateTime1dArray,x_array,x_dateTime1dArray->get_Length());
		for ( Int32 x_i = 0 ;  x_i < x_dateTime1dArray->get_Length() ;   x_i++ )
		{
			DateTime x_d = ((*((DateTime*)x_dateTime1dArray->Address(x_i))));
			DateTime x_d2 = ((*((DateTime*)x_array->Address(x_i))));
			CxAssert(((x_d)).Equals(x_d2));
		}
		x_dateTime1dArray->CopyTo(x_array,1);
		for ( Int32 x_j = 1 ;  x_j < x_array->get_Length() ;   x_j++ )
		{
			CxAssert(((((*((DateTime*)x_dateTime1dArray->Address(x_j - 1)))))).Equals(((*((DateTime*)x_array->Address(x_j))))));
		}
		CxAssert((TimeSpan(5,4,3,2,100)).Equals(x_timeSpan3dArray->GetValue(1,1,1)));
		TimeSpan x_timeSpan = (TimeSpan(5,4,3,2,101));
		Array* x_indices = (new Array(Int32Type,3))->Initialize((Int32*) ArrayMethodTestsArray0);
		x_timeSpan3dArray->SetValue(new TimeSpanValue(x_timeSpan),x_indices);
		CxAssert(x_timeSpan.Equals(x_timeSpan3dArray->GetValue(x_indices)));
		((*((Double*)x_double3dArray->Address(1,1,3)))) = 22;
		Double x_num = ((*((Double*)x_double3dArray->Address(1,1,3))));
		CxAssert((DoubleValue(x_num)).Equals(22));
		CxAssert(((DoubleValue)22).Equals(x_double3dArray->GetValue(1,1,3)));
		x_timeSpan3dArray->SetValue(new TimeSpanValue(x_timeSpan),0,0,0);
		CxAssert(((((*((TimeSpan*)x_timeSpan3dArray->Address(0,0,0)))))).Equals(x_timeSpan));
		((*((Boolean*)x_boolArray->Address(0)))) = true;
		CxAssert(((*((Boolean*)x_boolArray->Address(0)))));
		Array::Clear(x_boolArray,0,x_boolArray->get_Length());
		CxAssert(!((*((Boolean*)x_boolArray->Address(0)))));
		x_int1dArray->SetValue(new Int32Value(1),2);
		CxAssert((Int32Value(((*((Int32*)x_int1dArray->Address(1)))))).Equals(2));
		Array* x_array2 = (new Array(DoubleType,4))->Initialize((Double*) ArrayMethodTestsArray1);
		x_array2->SetValue(new Int32Value(2),1);
		CxAssert((DoubleValue(((*((Double*)x_array2->Address(1)))))).Equals(2));
		x_array2->SetValue(new UInt32Value(2),1);
		CxAssert((DoubleValue(((*((Double*)x_array2->Address(1)))))).Equals(2));
	}
	void ArrayTest::CxAssert(Boolean x_x)
	{
		if ( !x_x )
		{
			x_caBlock->TestFailed((new String((Char*)L"Array TestFailed")));
		}
	}
	ArrayTest::ArrayTest()
	{
	}
	BasicTest::BasicTest(CABlock* x_caBlock)
	{
		x_field1 = 0;
		this->x_caBlock = x_caBlock;
	}
	void BasicTest::Test()
	{
		x_caBlock->Send((new String((Char*)L"Doing BasicTest")));
		x_caBlock->Send((new String((Char*)L"\tDoing FieldTest")));
		FieldTest();
		x_caBlock->Send((new String((Char*)L"\tDoing SwitchTest")));
		SwitchTest();
		x_caBlock->Send((new String((Char*)L"\tDoing IfThenElseTest")));
		IfThenElseTest();
		x_caBlock->Send((new String((Char*)L"\tDoing StructTest")));
		StructTest();
		x_caBlock->Send((new String((Char*)L"\tDoing StructTest2")));
		StructTest2();
		x_caBlock->Send((new String((Char*)L"\tDoing VirtualMethodTest")));
		VirtualMethodTest();
		x_caBlock->Send((new String((Char*)L"\tDoing PassByReferenceTest")));
		PassByReferenceTest();
		x_caBlock->Send((new String((Char*)L"\tDoing Namespace Test")));
		TestUsingNamespace();
		x_caBlock->Send((new String((Char*)L"\tDoing Complex conditions")));
		ComplexConditions();
		x_caBlock->Send((new String((Char*)L"\tDoing Naming test")));
		TestNames();
	}
	void BasicTest::FieldTest()
	{
		BasicTest* x_basicTest = (new BasicTest(x_caBlock));
		Int32 x_num = x_field1;
		CxAssert((Int32Value(x_num)).Equals(x_field1));
		Int32 x_num2 = x_basicTest->x_field1;
		CxAssert((Int32Value(x_num2)).Equals(x_basicTest->x_field1));
		DateTime x_maxValue = DateTime::MaxValue;
		CxAssert(((x_maxValue)).Equals(DateTime::MaxValue));
		Object* x_obj = (new Object());
		CxAssert(!((x_obj->ToString()))->Equals(nullptr));
		CxAssert(x_obj->Equals(x_obj));
		CxAssert(Object::Equals(x_obj,x_obj));
	}
	void BasicTest::SwitchTest()
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
		CxAssert((Int32Value(x_num)).Equals(1));
		CxAssert((Int32Value(x_field1)).Equals(2));
	}
	void BasicTest::IfThenElseTest()
	{
		x_field1 = 1;
		if ( (Int32Value(x_field1)).Equals(1) )
		{
			x_field1 = 2;
			if ( (Int32Value(x_field1)).Equals(3) )
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
		CxAssert((Int32Value(x_field1)).Equals(5));
		CxAssert(Object::Equals(nullptr,nullptr));
	}
	void BasicTest::StructTest()
	{
		TestStruct x_ts = (TestStruct(2));
		CxAssert((Int32Value(x_ts.get_Data())).Equals(2));
		x_ts.set_Data(3);
		CxAssert((Int32Value(x_ts.get_Data())).Equals(3));
		x_ts = x_ts + 1;
		CxAssert((Int32Value(x_ts.get_Data())).Equals(4));
		CxAssert((Int32Value(( x_ts & 1 ).get_Data())).Equals((Int32)0));
	}
	void BasicTest::StructTest2()
	{
		TestStruct3 x_testStruct = TestStruct3();
		x_testStruct.x_ts.x_data = 6;
		CxAssert((Int32Value(x_testStruct.x_ts.x_data)).Equals(6));
		x_ts3.x_ts.x_data = 7;
		CxAssert((Int32Value(x_ts3.x_ts.x_data)).Equals(7));
	}
	void BasicTest::VirtualMethodTest()
	{
		TestAbstract* x_testAbstract = (new TestAbstract());
		CxAssert((Int32Value(x_testAbstract->MustImplement())).Equals(2));
		CxAssert((Int32Value(x_testAbstract->DidImplement())).Equals(1));
	}
	void BasicTest::PassByReferenceTest()
	{
		Int32 x_data = 0;
		DateTime x_data2 = DateTime();
		TimeSpan x_data3 = TimeSpan();
		String* x_data4 = nullptr;
		TestAbstract* x_data5 = nullptr;
		RefMethod(x_data);
		CxAssert((Int32Value(x_data)).Equals(1));
		RefMethod(x_data2);
		CxAssert((Int64Value(x_data2.get_Ticks())).Equals(1000));
		RefMethod(x_data3);
		CxAssert((Int64Value(x_data3.get_Ticks())).Equals(1000));
		RefMethod(x_data4);
		CxAssert(((x_data4))->Equals((new String((Char*)L"Test"))));
		RefMethod(x_data5);
		CxAssert((Int32Value(x_data5->MustImplement())).Equals(2));
	}
	void BasicTest::RefMethod(Int32&  x_data)
	{
		if ( (Int32Value(x_data)).Equals((Int32)0) )
		{
			x_data = 1;
		}
	}
	void BasicTest::RefMethod(DateTime&  x_data)
	{
		x_data = (DateTime(1000));
	}
	void BasicTest::RefMethod(TimeSpan&  x_data)
	{
		x_data = (TimeSpan(1000));
	}
	void BasicTest::RefMethod(String*&  x_data)
	{
		if ( ((x_data))->Equals(nullptr) )
		{
			x_data = (new String((Char*)L"Test"));
		}
	}
	void BasicTest::RefMethod(TestAbstract*&  x_data)
	{
		if ( ((x_data))->Equals(nullptr) )
		{
			x_data = (new TestAbstract());
		}
	}
	void BasicTest::TestUsingNamespace()
	{
		TestNamespaceClass* x_testNamespaceClass = (new TestNamespaceClass());
		CxAssert(!((x_testNamespaceClass))->Equals(nullptr));
	}
	void BasicTest::CxAssert(Boolean x_x)
	{
		if ( !x_x )
		{
			x_caBlock->TestFailed((new String((Char*)L"BaseTest TestFailed")));
		}
	}
	void BasicTest::ComplexConditions()
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
		CxAssert(!( ( x_flag || x_flag2 ) && x_flag3 ) || ( x_flag4 && x_flag5 && x_flag3 ) || x_flag2);
		CxAssert(!x_flag && !x_flag2 && x_flag3 && x_flag4 && x_flag5);
		CxAssert(x_flag || x_flag2 || ( x_flag3 && x_flag4 && x_flag5 ));
		CxAssert(!x_flag && x_flag3 && !x_flag2 && x_flag4 && x_flag5);
		CxAssert(TestThis(1,2));
		CxAssert(!TestThis(6,2));
		CxAssert(TestThis(60,2));
	}
	Boolean BasicTest::TestThis(Int32 x_a,Int32 x_b)
	{
		return ( x_a < 5 && x_b < 3 ) || x_a + x_b > 20;
	}
	void BasicTest::TestNames()
	{
		Typedef* x_typedef = (new Typedef());
		x_typedef->set_Friend(x_friend_TestNameEnu);
		CxAssert(x_typedef->get_Friend() == x_friend_TestNameEnu);
	}
	BasicTest::BasicTest()
	{
	}
	TestAbstract::TestAbstract() : Abstract (1,2)
	{
	}
	Int32 TestAbstract::MustImplement()
	{
		return x_data2;
	}
	Int32 TestAbstract::MustImplement(Int32 x_i)
	{
		return x_data2;
	}
	Int32 TestAbstract::MustImplement(Int64 x_i)
	{
		return x_data2;
	}
	String* TestAbstract::ToString()
	{
		return (new String((Char*)L"TestAbstract"));
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
	TestStruct operator +(TestStruct x_ts,Int32 x_newData)
	{
		x_ts.x_data = x_ts.x_data + x_newData;
		return x_ts;
	}
	TestStruct operator &(TestStruct x_ts,Int32 x_newData)
	{
		x_ts.x_data = x_ts.x_data & x_newData;
		return x_ts;
	}
	TestStruct::TestStruct()
	{
	}
	TestStruct2::TestStruct2()
	{
	}
	TestStruct3::TestStruct3()
	{
	}
	Abstract::Abstract(Int32 x_i,Int32 x_j)
	{
		x_data1 = x_i;
		x_data2 = x_j;
	}
	Int32 Abstract::DidImplement()
	{
		return x_data1;
	}
	Abstract::Abstract()
	{
	}
	BooleanTest::BooleanTest(CABlock* x_caBlock)
	{
		this->x_caBlock = x_caBlock;
	}
	void BooleanTest::Test()
	{
		x_caBlock->Send((new String((Char*)L"Doing BooleanTest")));
		x_caBlock->Send((new String((Char*)L"\tDoing RunBooleanTest")));
		RunBooleanTest();
		x_caBlock->Send((new String((Char*)L"\tDoing BoolOperators")));
		BoolOperators();
		x_caBlock->Send((new String((Char*)L"\tDoing BoolBoxTest")));
		BoolBoxTest();
	}
	void BooleanTest::BoolBoxTest()
	{
		Boolean x_flag = true;
		Object* x_obj = new BooleanValue(x_flag);
		CxAssert(((BooleanValue)x_flag).Equals(x_obj));
		CxAssert(x_obj->Equals(x_obj));
		CxAssert(x_obj->get_AsBoolean());
		CxAssert(((x_obj->ToString()))->Equals((new String((Char*)L"True"))));
	}
	void BooleanTest::RunBooleanTest()
	{
		Boolean x_flag = true;
		Object* x_obj = new BooleanValue(x_flag);
		CxAssert((Int32Value(((BooleanValue)x_flag).CompareTo(true))).Equals((Int32)0));
		CxAssert((Int32Value(((BooleanValue)x_flag).CompareTo(x_obj))).Equals((Int32)0));
		CxAssert(((BooleanValue)x_flag).Equals(true));
		CxAssert(BooleanValue::Parse((new String((Char*)L"True"))));
		CxAssert((((new String((Char*)L"True"))))->Equals(((BooleanValue)x_flag).ToString()));
		CxAssert(((BooleanValue::FalseString))->Equals((new String((Char*)L"False"))));
		CxAssert(((BooleanValue::TrueString))->Equals((new String((Char*)L"True"))));
	}
	void BooleanTest::BoolOperators()
	{
		Boolean x_flag = true;
		Boolean x_flag2 = false;
		CxAssert(x_flag && x_flag2,false);
		CxAssert(x_flag || x_flag2);
		CxAssert(x_flag ^ x_flag2);
		CxAssert(!x_flag,false);
		CxAssert(x_flag && x_flag2,false);
		CxAssert(x_flag || x_flag2);
		CxAssert((BooleanValue(x_flag)).Equals(x_flag2),false);
		CxAssert(!(BooleanValue(x_flag)).Equals(x_flag2));
		CxAssert(x_flag = x_flag);
		CxAssert(x_flag = ( !(ByteValue(( ( x_flag ? 1 : 0 ) | 1 ))).Equals((Byte)0) ));
		CxAssert(x_flag = x_flag);
	}
	void BooleanTest::CxAssert(Boolean x_x,Boolean x_y)
	{
		if ( !(BooleanValue(x_x)).Equals(x_y) )
		{
			x_caBlock->TestFailed((new String((Char*)L"Boolean TestFailed")));
		}
	}
	void BooleanTest::CxAssert(Boolean x_x)
	{
		if ( !x_x )
		{
			x_caBlock->TestFailed((new String((Char*)L"Boolean TestFailed")));
		}
	}
	BooleanTest::BooleanTest()
	{
	}
	BufferTest::BufferTest(CABlock* x_caBlock)
	{
		this->x_caBlock = x_caBlock;
	}
	void BufferTest::Test()
	{
		static Int32 TestArray0[5] = {0,1,2,3,4};
		static Int32 TestArray1[5] = {5,4,3,2,1};
		x_caBlock->Send((new String((Char*)L"Doing Buffer Test")));
		x_in1dArray = (new Array(Int32Type,5))->Initialize((Int32*) TestArray0);
		x_out1dArray = (new Array(Int32Type,5))->Initialize((Int32*) TestArray1);
		Int32 x_count = x_in1dArray->GetLength(0) * 4;
		Buffer::BlockCopy(x_in1dArray,0,x_out1dArray,0,x_count);
		Boolean x_x = true;
		for ( Int32 x_i = 0 ;  x_i < 5 ;   x_i++ )
		{
			if ( !(Int32Value(((*((Int32*)x_in1dArray->Address(x_i)))))).Equals(((*((Int32*)x_out1dArray->Address(x_i))))) )
			{
				x_x = false;
				break;
			}
		}
		CxAssert(x_x);
	}
	void BufferTest::CxAssert(Boolean x_x)
	{
		if ( !x_x )
		{
			x_caBlock->TestFailed((new String((Char*)L"Buffer Test Failed")));
		}
	}
	BufferTest::BufferTest()
	{
	}
	ByteTest::ByteTest(CABlock* x_caBlock)
	{
		this->x_caBlock = x_caBlock;
	}
	void ByteTest::Test()
	{
		x_caBlock->Send((new String((Char*)L"Doing ByteTest")));
		x_caBlock->Send((new String((Char*)L"\tDoing ByteMethodsTest")));
		ByteMethodsTest();
		x_caBlock->Send((new String((Char*)L"\tDoing DoUnSignedMath")));
		DoUnSignedMath();
		x_caBlock->Send((new String((Char*)L"\tDoing ByteOperators")));
		ByteOperators();
		x_caBlock->Send((new String((Char*)L"\tDoing ByteArrayTests")));
		ByteArrayTests();
		x_caBlock->Send((new String((Char*)L"\tDoing ByteMiscTests")));
		ByteMiscTests();
	}
	void ByteTest::ByteMethodsTest()
	{
		Byte x_b = 5;
		CxAssert((Int32Value(((ByteValue)x_b).CompareTo(5))).Equals((Int32)0));
		CxAssert((Int32Value(((ByteValue)x_b).CompareTo((new ByteValue(5))))).Equals((Int32)0));
		CxAssert(((ByteValue)x_b).Equals(5));
		CxAssert(((ByteValue)x_b).Equals((new ByteValue(5))));
		CxAssert((ByteValue(ByteValue::Parse((new String((Char*)L"77"))))).Equals(77));
		CxAssert((((new String((Char*)L"5"))))->Equals(((ByteValue)x_b).ToString()));
		x_b = ByteValue::MaxValue;
		CxAssert((ByteValue(ByteValue::MaxValue)).Equals(x_b));
		x_b = 0;
		CxAssert((ByteValue(x_b)).Equals((Byte)0));
		String* x_text = ((ByteValue)ByteValue::MaxValue).ToString();
		CxAssert(((x_text))->Equals((new String((Char*)L"255"))));
		CxAssert((ByteValue(ByteValue::Parse(x_text))).Equals(ByteValue::MaxValue));
		String* x_text2 = ((ByteValue)( 0 )).ToString();
		CxAssert(((x_text2))->Equals((new String((Char*)L"0"))));
		CxAssert((ByteValue(ByteValue::Parse(x_text2))).Equals((Byte)0));
		Int32 x_num = 50;
		Byte x_b2 = x_num;
		Object* x_obj = new Int32Value(x_num);
		Int32 x_num2 = x_obj->get_AsInt32();
		CxAssert((ByteValue(x_b2)).Equals(50));
		CxAssert((Int32Value(x_num2)).Equals(50));
		x_b2 = ByteValue::MaxValue;
		x_b2 = ( x_b2 + 1 );
		CxAssert((ByteValue(x_b2)).Equals((Byte)0));
		Object* x_obj2 = (new ByteValue(5));
		CxAssert(x_obj2->Equals((new ByteValue(5))));
		CxAssert(((x_obj2->ToString()))->Equals((new String((Char*)L"5"))));
	}
	void ByteTest::DoUnSignedMath()
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
		x_num = x_num + x_b;
		CxAssert((Int32Value(x_num)).Equals(61));
		CxAssert((Int32Value(x_b + x_b2)).Equals(180));
		Byte x_b5 = ( x_b - x_b2 );
		CxAssert((ByteValue(x_b5)).Equals(196));
		CxAssert((ByteValue(( x_b - x_b2 ))).Equals(196));
		CxAssert((Int32Value(x_b3 * x_b4)).Equals(72));
		CxAssert((Int32Value(x_b2 / x_b)).Equals(2));
		CxAssert((Int32Value(x_b >> 2)).Equals(15));
		CxAssert((Int32Value(x_b << 1)).Equals(120));
		Int32 x_num2 = 11;
		CxAssert((Int32Value(x_num2 % 5)).Equals(1));
		x_num2 = 8;
		CxAssert(( x_num2 | 1 ) == 9);
		CxAssert(( x_num2 & 1 ) == 0);
		CxAssert((Int32Value(++x_num2)).Equals(9));
		CxAssert((Int32Value(--x_num2)).Equals(8));
		CxAssert(( x_num2 = x_num2 * 2 ) == 16);
		CxAssert(( x_num2 = x_num2 / 2 ) == 8);
		CxAssert(( x_num2 = x_num2 % 2 ) == 0);
		CxAssert(( x_num2 = x_num2 | 4 ) == 4);
		CxAssert(( x_num2 = x_num2 & 4 ) == 4);
		CxAssert((Int32Value(-x_b)).Equals(-60));
		CxAssert((ByteValue(x_b)).Equals(60));
		Byte x_b6 = 0;
		CxAssert((ByteValue(( ~x_b6 ))).Equals(ByteValue::MaxValue));
		CxAssert(( x_b6 = ( x_b6 + 1 ) ) == 1);
		CxAssert(( x_b6 = ( x_b6 - 1 ) ) == 0);
	}
	void ByteTest::ByteOperators()
	{
		Byte x_b = 66;
		Char x_c = L'\u0001';
		Byte x_b2 = 1;
		SByte x_b3 = 1;
		Int16 x_num = 1;
		Int32 x_num2 = 1;
		Int64 x_num3 = 1;
		UInt16 x_num4 = 1;
		UInt32 x_num5 = 1;
		UInt64 x_num6 = 1;
		Single x_num7 = ((Single)1);
		Double x_num8 = 1;
		CxAssert((ByteValue(x_b)).Equals(66));
		CxAssert((Int32Value(x_b + x_c)).Equals(67));
		CxAssert((Int32Value(x_b + x_b2)).Equals(67));
		CxAssert((Int32Value(x_b + x_b3)).Equals(67));
		CxAssert((Int32Value(x_b + x_num)).Equals(67));
		CxAssert((Int32Value(x_b + x_num2)).Equals(67));
		CxAssert((Int64Value(x_b + x_num3)).Equals(67));
		CxAssert((Int32Value(x_b + x_num4)).Equals(67));
		CxAssert((UInt32Value(x_b + x_num5)).Equals(67));
		CxAssert((UInt64Value(x_b + x_num6)).Equals(67));
		CxAssert((SingleValue(x_b + x_num7)).Equals(((Single)67)));
		CxAssert((DoubleValue(x_b + x_num8)).Equals(67));
		CxAssert((Int32Value(x_b - x_c)).Equals(65));
		CxAssert((Int32Value(x_b - x_b2)).Equals(65));
		CxAssert((Int32Value(x_b - x_b3)).Equals(65));
		CxAssert((Int32Value(x_b - x_num)).Equals(65));
		CxAssert((Int32Value(x_b - x_num2)).Equals(65));
		CxAssert((Int64Value(x_b - x_num3)).Equals(65));
		CxAssert((Int32Value(x_b - x_num4)).Equals(65));
		CxAssert((UInt32Value(x_b - x_num5)).Equals(65));
		CxAssert((UInt64Value(x_b - x_num6)).Equals(65));
		CxAssert((SingleValue(x_b - x_num7)).Equals(((Single)65)));
		CxAssert((DoubleValue(x_b - x_num8)).Equals(65));
		CxAssert((Int32Value(x_b * x_c)).Equals(66));
		CxAssert((Int32Value(x_b * x_b2)).Equals(66));
		CxAssert((Int32Value(x_b * x_b3)).Equals(66));
		CxAssert((Int32Value(x_b * x_num)).Equals(66));
		CxAssert((Int32Value(x_b * x_num2)).Equals(66));
		CxAssert((Int64Value(x_b * x_num3)).Equals(66));
		CxAssert((Int32Value(x_b * x_num4)).Equals(66));
		CxAssert((UInt32Value(x_b * x_num5)).Equals(66));
		CxAssert((UInt64Value(x_b * x_num6)).Equals(66));
		CxAssert((SingleValue(x_b * x_num7)).Equals(((Single)66)));
		CxAssert((DoubleValue(x_b * x_num8)).Equals(66));
		CxAssert((Int32Value(x_b / x_c)).Equals(66));
		CxAssert((Int32Value(x_b / x_b2)).Equals(66));
		CxAssert((Int32Value(x_b / x_b3)).Equals(66));
		CxAssert((Int32Value(x_b / x_num)).Equals(66));
		CxAssert((Int32Value(x_b / x_num2)).Equals(66));
		CxAssert((Int64Value(x_b / x_num3)).Equals(66));
		CxAssert((Int32Value(x_b / x_num4)).Equals(66));
		CxAssert((UInt32Value(x_b / x_num5)).Equals(66));
		CxAssert((UInt64Value(x_b / x_num6)).Equals(66));
		CxAssert((SingleValue(x_b / x_num7)).Equals(((Single)66)));
		CxAssert((DoubleValue(x_b / x_num8)).Equals(66));
		CxAssert((Int32Value(x_b % x_c)).Equals((Int32)0));
		CxAssert((Int32Value(x_b % x_b2)).Equals((Int32)0));
		CxAssert((Int32Value(x_b % x_b3)).Equals((Int32)0));
		CxAssert((Int32Value(x_b % x_num)).Equals((Int32)0));
		CxAssert((Int32Value(x_b % x_num2)).Equals((Int32)0));
		CxAssert((Int64Value(x_b % x_num3)).Equals((Int64)0));
		CxAssert((Int32Value(x_b % x_num4)).Equals((Int32)0));
		CxAssert((UInt32Value(x_b % x_num5)).Equals((UInt32)0));
		CxAssert((UInt64Value(x_b % x_num6)).Equals((UInt64)0));
		CxAssert((SingleValue(((DoubleValue)x_b) % x_num7)).Equals(((Single)0)));
		CxAssert((DoubleValue(((DoubleValue)x_b) % x_num8)).Equals(0));
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
		CxAssert((ByteValue(( ~x_b ))).Equals(189));
		CxAssert(x_c < x_b);
		CxAssert(x_b2 < x_b);
		CxAssert(x_b3 < x_b);
		CxAssert(x_num < x_b);
		CxAssert(x_num2 < x_b);
		CxAssert(x_num3 < x_b);
		CxAssert(x_num4 < x_b);
		CxAssert(x_num5 < x_b);
		CxAssert(x_num6 < x_b);
		CxAssert(x_num7 < x_b);
		CxAssert(x_num8 < x_b);
		CxAssert(x_c > x_b,false);
		CxAssert(x_b2 > x_b,false);
		CxAssert(x_b3 > x_b,false);
		CxAssert(x_num > x_b,false);
		CxAssert(x_num2 > x_b,false);
		CxAssert(x_num3 > x_b,false);
		CxAssert(x_num4 > x_b,false);
		CxAssert(x_num5 > x_b,false);
		CxAssert(x_num6 > x_b,false);
		CxAssert(x_num7 > x_b,false);
		CxAssert(x_num8 > x_b,false);
		CxAssert(( x_b = ( x_b + 1 ) ) == 67);
		CxAssert(( x_b = ( x_b - 1 ) ) == 66);
		CxAssert((ByteValue(x_b++)).Equals(66));
		CxAssert((ByteValue(x_b--)).Equals(67));
		CxAssert((Int32Value(x_b << 1)).Equals(132));
		CxAssert((Int32Value(x_b >> 1)).Equals(33));
		CxAssert((CharValue(x_c)).Equals(x_b),false);
		CxAssert((ByteValue(x_b2)).Equals(x_b),false);
		CxAssert((SByteValue(x_b3)).Equals(x_b),false);
		CxAssert((Int16Value(x_num)).Equals(x_b),false);
		CxAssert((Int32Value(x_num2)).Equals(x_b),false);
		CxAssert((Int64Value(x_num3)).Equals(x_b),false);
		CxAssert((UInt16Value(x_num4)).Equals(x_b),false);
		CxAssert((UInt32Value(x_num5)).Equals(x_b),false);
		CxAssert((UInt64Value(x_num6)).Equals(x_b),false);
		CxAssert((SingleValue(x_num7)).Equals(x_b),false);
		CxAssert((DoubleValue(x_num8)).Equals(x_b),false);
		CxAssert(!(CharValue(x_c)).Equals(x_b));
		CxAssert(!(ByteValue(x_b2)).Equals(x_b));
		CxAssert(!(SByteValue(x_b3)).Equals(x_b));
		CxAssert(!(Int16Value(x_num)).Equals(x_b));
		CxAssert(!(Int32Value(x_num2)).Equals(x_b));
		CxAssert(!(Int64Value(x_num3)).Equals(x_b));
		CxAssert(!(UInt16Value(x_num4)).Equals(x_b));
		CxAssert(!(UInt32Value(x_num5)).Equals(x_b));
		CxAssert(!(UInt64Value(x_num6)).Equals(x_b));
		CxAssert(!(SingleValue(x_num7)).Equals(x_b));
		CxAssert(!(DoubleValue(x_num8)).Equals(x_b));
		CxAssert(x_c <= x_b);
		CxAssert(x_b2 <= x_b);
		CxAssert(x_b3 <= x_b);
		CxAssert(x_num <= x_b);
		CxAssert(x_num2 <= x_b);
		CxAssert(x_num3 <= x_b);
		CxAssert(x_num4 <= x_b);
		CxAssert(x_num5 <= x_b);
		CxAssert(x_num6 <= x_b);
		CxAssert(x_num7 <= x_b);
		CxAssert(x_num8 <= x_b);
		CxAssert(x_c >= x_b,false);
		CxAssert(x_b2 >= x_b,false);
		CxAssert(x_b3 >= x_b,false);
		CxAssert(x_num >= x_b,false);
		CxAssert(x_num2 >= x_b,false);
		CxAssert(x_num3 >= x_b,false);
		CxAssert(x_num4 >= x_b,false);
		CxAssert(x_num5 >= x_b,false);
		CxAssert(x_num6 >= x_b,false);
		CxAssert(x_num7 >= x_b,false);
		CxAssert(x_num8 >= x_b,false);
		CxAssert(( x_b = ( x_b + x_c ) ) == 67);
		CxAssert(( x_b = ( x_b - x_c ) ) == 66);
		CxAssert(( x_b = ( x_b + x_num5 ) ) == 67);
		CxAssert(( x_b = ( x_b - x_num5 ) ) == 66);
		CxAssert(( x_b = ( x_b * x_c ) ) == 66);
		CxAssert(( x_b = ( x_b / x_c ) ) == 66);
		CxAssert(( x_b = ( x_b * x_num5 ) ) == 66);
		CxAssert(( x_b = ( x_b / x_num5 ) ) == 66);
		CxAssert(( x_b = ( x_b % x_c ) ) == 0);
		x_b = 66;
		CxAssert(( x_b = ( x_b % x_num5 ) ) == 0);
		x_b = 66;
		CxAssert(( x_b = ( x_b & x_c ) ) == 0);
		x_b = 66;
		CxAssert(( x_b = ( x_b & x_num5 ) ) == 0);
		x_b = 66;
		CxAssert(( x_b = ( x_b | x_c ) ) == 67);
		x_b = 66;
		CxAssert(( x_b = ( x_b | x_num5 ) ) == 67);
		x_b = 66;
		CxAssert(( x_b = ( x_b ^ x_c ) ) == 67);
		x_b = 66;
		CxAssert(( x_b = ( x_b ^ x_num5 ) ) == 67);
		x_b = 66;
		CxAssert(( x_b = ( x_b << x_c ) ) == 132);
		x_b = 66;
		CxAssert(( x_b = ( x_b << x_num2 ) ) == 132);
		x_b = 66;
		CxAssert(( x_b = ( x_b >> x_c ) ) == 33);
		x_b = 66;
		CxAssert(( x_b = ( x_b >> x_num2 ) ) == 33);
		x_b = 66;
		Char x_c2 = L'B';
		CxAssert(( x_c2 = ( x_c2 << x_c ) ) == L'\u0084');
	}
	void ByteTest::ByteArrayTests()
	{
		static Byte ByteArrayTestsArray0[5] = {1,2,3,4,5};
		static Byte ByteArrayTestsArray1[4] = {1,2,3,4};
		static Byte ByteArrayTestsArray2[2][4] = {{1,2,3,4},{4,5,6,7}};
		static Byte ByteArrayTestsArray3[2][2][4] = {{{1,2,3,4},{5,6,7,8}},{{9,10,11,12},{13,14,15,16}}};
		Array* x_array = (new Array(ByteType,10));
		Array* x_array2 = (new Array(ByteType,10));
		for ( Int32 x_i = 0 ;  x_i < 10 ;   x_i++ )
		{
			((*((Byte*)x_array->Address(x_i)))) = x_i;
		}
		for ( Int32 x_j = 0 ;  x_j < 10 ;   x_j++ )
		{
			((*((Byte*)x_array2->Address(x_j)))) = ((*((Byte*)x_array->Address(x_j))));
		}
		CxAssert((ByteValue(((*((Byte*)x_array2->Address(0)))))).Equals((Byte)0));
		CxAssert((ByteValue(((*((Byte*)x_array2->Address(9)))))).Equals(9));
		for ( Int32 x_k = 0 ;  x_k < 10 ;   x_k++ )
		{
			((*((Byte*)x_array->Address(x_k)))) = 1;
		}
		Array* x_array3 = (new Array(Int32Type,10));
		Buffer::BlockCopy(x_array,0,x_array3,0,10);
		Buffer::BlockCopy(x_array,0,x_array3,10,10);
		Buffer::BlockCopy(x_array,0,x_array3,20,10);
		Buffer::BlockCopy(x_array,0,x_array3,30,10);
		CxAssert((Int32Value(((*((Int32*)x_array3->Address(0)))))).Equals(16843009));
		CxAssert((Int32Value(((*((Int32*)x_array3->Address(9)))))).Equals(16843009));
		Array* x_array4 = (new Array(ByteType,5))->Initialize((Byte*) ByteArrayTestsArray0);
		CxAssert((Int32Value(x_array4->get_Length())).Equals(5));
		CxAssert((ByteValue(((*((Byte*)x_array4->Address(3)))))).Equals(4));
		Array* x_array5 = (new Array(ByteType,4))->Initialize((Byte*) ByteArrayTestsArray1);
		CxAssert((ByteValue(((*((Byte*)x_array5->Address(1)))))).Equals(2));
		Array* x_array6 = (new Array(ByteType,2,4))->Initialize((Byte*) ByteArrayTestsArray2);
		CxAssert((ByteValue(((*((Byte*)x_array6->Address(0,2)))))).Equals(3));
		Array* x_array7 = (new Array(ByteType,2,2,4))->Initialize((Byte*) ByteArrayTestsArray3);
		CxAssert((ByteValue(((*((Byte*)x_array7->Address(0,0,3)))))).Equals(4));
		((*((Byte*)x_array7->Address(0,0,3)))) = 6;
		CxAssert((ByteValue(((*((Byte*)x_array7->Address(0,0,3)))))).Equals(6));
		x_array7->SetValue((new ByteValue(4)),0,0,3);
		CxAssert((ByteValue(((*((Byte*)x_array7->Address(0,0,3)))))).Equals(4));
	}
	void ByteTest::ByteMiscTests()
	{
		Byte x_b = 0;
		Byte x_val = 1;
		CxAssert((ByteValue(Math::Max(x_b,x_val))).Equals(1));
		CxAssert((ByteValue(Math::Min(x_b,x_val))).Equals((Byte)0));
		StringBuilder* x_stringBuilder = (new StringBuilder());
		x_stringBuilder->Append(x_b);
		CxAssert(((x_stringBuilder->ToString()))->Equals((new String((Char*)L"0"))));
		x_stringBuilder->Insert(1,x_b);
		CxAssert(((x_stringBuilder->ToString()))->Equals((new String((Char*)L"00"))));
	}
	void ByteTest::CxAssert(Boolean x_x)
	{
		if ( !x_x )
		{
			x_caBlock->TestFailed((new String((Char*)L"Byte Test Failed")));
		}
	}
	void ByteTest::CxAssert(Boolean x_x,Boolean x_y)
	{
		if ( !(BooleanValue(x_x)).Equals(x_y) )
		{
			x_caBlock->TestFailed((new String((Char*)L"Byte Test Failed")));
		}
	}
	ByteTest::ByteTest()
	{
	}
	CharTest::CharTest(CABlock* x_caBlock)
	{
		this->x_caBlock = x_caBlock;
	}
	void CharTest::Test()
	{
		x_caBlock->Send((new String((Char*)L"Doing CharTest")));
		x_caBlock->Send((new String((Char*)L"\tDoing CharMethodsTest")));
		CharMethodsTest();
		x_caBlock->Send((new String((Char*)L"\tDoing CharOperators")));
		CharOperators();
		x_caBlock->Send((new String((Char*)L"\tDoing CharArrayTest")));
		CharArrayTests();
		x_caBlock->Send((new String((Char*)L"\tDoing CharMiscTests")));
		CharMiscTests();
	}
	void CharTest::CharMethodsTest()
	{
		String* x_s = (new String((Char*)L"123aBc\t\n. "));
		Char x_c = L'A';
		CxAssert(((CharValue)x_c).CompareTo(L'B') < 0);
		CxAssert(((CharValue)x_c).Equals(L'A'));
		Double x_numericValue = CharValue::GetNumericValue(L'5');
		CxAssert((DoubleValue(x_numericValue)).Equals(5));
		x_numericValue = CharValue::GetNumericValue(x_s,2);
		CxAssert((DoubleValue(x_numericValue)).Equals(3));
		CxAssert(CharValue::IsControl(L'\t'));
		CxAssert(CharValue::IsControl(x_s,7));
		CxAssert(CharValue::IsDigit(L'1'));
		CxAssert(CharValue::IsDigit(x_s,2));
		CxAssert(CharValue::IsLetter(L'a'));
		CxAssert(CharValue::IsLetter(x_s,3));
		CxAssert(CharValue::IsLetterOrDigit(L'a'));
		CxAssert(CharValue::IsLetterOrDigit(x_s,3));
		CxAssert(CharValue::IsLower(L'a'));
		CxAssert(CharValue::IsLower(x_s,3));
		CxAssert(CharValue::IsNumber(L'1'));
		CxAssert(CharValue::IsNumber(x_s,2));
		CxAssert(CharValue::IsPunctuation(L','));
		CxAssert(CharValue::IsPunctuation(x_s,8));
		CxAssert(CharValue::IsSeparator(L' '));
		CxAssert(CharValue::IsSeparator(x_s,9));
		CxAssert(CharValue::IsUpper(L'B'));
		CxAssert(CharValue::IsUpper(x_s,4));
		CxAssert(CharValue::IsWhiteSpace(L' '));
		CxAssert(CharValue::IsWhiteSpace(x_s,9));
		CxAssert((CharValue(CharValue::ToLower(L'A'))).Equals(L'a'));
		CxAssert((CharValue(CharValue::ToUpper(L'a'))).Equals(L'A'));
		CxAssert((new String((Char*)L"a"))->Equals(((CharValue)L'a').ToString()));
		CxAssert((new String((Char*)L"a"))->Equals(CharValue::ToString(L'a')));
		CxAssert(((CharValue)L'a').Equals(CharValue::Parse((new String((Char*)L"a")))));
		Object* x_obj = new CharValue(x_c);
		CxAssert(((CharValue)L'A').Equals(x_obj->get_AsChar()));
		CxAssert(((CharValue)L'A').Equals(x_obj));
		CxAssert((Int32Value(((CharValue)L'A').CompareTo(x_obj))).Equals((Int32)0));
		CxAssert(((x_obj->ToString()))->Equals((new String((Char*)L"A"))));
	}
	void CharTest::CharOperators()
	{
		Char x_c = L'B';
		Char x_c2 = L'\u0001';
		Int32 x_num = 1;
		UInt32 x_num2 = 1;
		Int64 x_num3 = 1;
		Double x_num4 = 1;
		CxAssert((CharValue(x_c)).Equals(L'B'));
		CxAssert((Int32Value(x_c + x_c2)).Equals(67));
		CxAssert((Int32Value(x_c + x_num)).Equals(67));
		CxAssert((UInt32Value(x_c + x_num2)).Equals(67));
		CxAssert((Int64Value(x_c + x_num3)).Equals(67));
		CxAssert((DoubleValue(x_c + x_num4)).Equals(67));
		CxAssert((Int32Value(x_c - x_c2)).Equals(65));
		CxAssert((Int32Value(x_c - x_num)).Equals(65));
		CxAssert((UInt32Value(x_c - x_num2)).Equals(65));
		CxAssert((Int64Value(x_c - x_num3)).Equals(65));
		CxAssert((DoubleValue(x_c - x_num4)).Equals(65));
		CxAssert((Int32Value(x_c * x_c2)).Equals(66));
		CxAssert((Int32Value(x_c * x_num)).Equals(66));
		CxAssert((UInt32Value(x_c * x_num2)).Equals(66));
		CxAssert((Int64Value(x_c * x_num3)).Equals(66));
		CxAssert((DoubleValue(x_c * x_num4)).Equals(66));
		CxAssert((Int32Value(x_c / x_c2)).Equals(66));
		CxAssert((Int32Value(x_c / x_num)).Equals(66));
		CxAssert((UInt32Value(x_c / x_num2)).Equals(66));
		CxAssert((Int64Value(x_c / x_num3)).Equals(66));
		CxAssert((DoubleValue(x_c / x_num4)).Equals(66));
		CxAssert((Int32Value(x_c % x_c2)).Equals((Int32)0));
		CxAssert((Int32Value(x_c % x_num)).Equals((Int32)0));
		CxAssert((UInt32Value(x_c % x_num2)).Equals((UInt32)0));
		CxAssert((Int64Value(x_c % x_num3)).Equals((Int64)0));
		CxAssert((DoubleValue(((DoubleValue)x_c) % x_num4)).Equals(0));
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
		CxAssert((UInt32Value(~x_c)).Equals(4294967229));
		CxAssert(x_c2 < x_c);
		CxAssert(x_num < x_c);
		CxAssert(x_num2 < x_c);
		CxAssert(x_num3 < x_c);
		CxAssert(x_num4 < x_c);
		CxAssert(x_c2 > x_c,false);
		CxAssert(x_num > x_c,false);
		CxAssert(x_num2 > x_c,false);
		CxAssert(x_num3 > x_c,false);
		CxAssert(x_num4 > x_c,false);
		CxAssert(( x_c = ( x_c + 1 ) ) == L'C');
		CxAssert(( x_c = ( x_c - 1 ) ) == L'B');
		CxAssert((CharValue(x_c++)).Equals(L'B'));
		CxAssert((CharValue(x_c--)).Equals(L'C'));
		CxAssert((UInt32Value(x_c << 1)).Equals(132));
		CxAssert((Int32Value(x_c >> 1)).Equals(33));
		CxAssert((CharValue(x_c2)).Equals(x_c),false);
		CxAssert((Int32Value(x_num)).Equals(x_c),false);
		CxAssert((UInt32Value(x_num2)).Equals(x_c),false);
		CxAssert((Int64Value(x_num3)).Equals(x_c),false);
		CxAssert((DoubleValue(x_num4)).Equals(x_c),false);
		CxAssert(!(CharValue(x_c2)).Equals(x_c));
		CxAssert(!(Int32Value(x_num)).Equals(x_c));
		CxAssert(!(UInt32Value(x_num2)).Equals(x_c));
		CxAssert(!(Int64Value(x_num3)).Equals(x_c));
		CxAssert(!(DoubleValue(x_num4)).Equals(x_c));
		CxAssert(x_c2 <= x_c);
		CxAssert(x_num <= x_c);
		CxAssert(x_num2 <= x_c);
		CxAssert(x_num3 <= x_c);
		CxAssert(x_num4 <= x_c);
		CxAssert(x_c2 >= x_c,false);
		CxAssert(x_num >= x_c,false);
		CxAssert(x_num2 >= x_c,false);
		CxAssert(x_num3 >= x_c,false);
		CxAssert(x_num4 >= x_c,false);
		CxAssert(( x_c = ( x_c + x_c2 ) ) == L'C');
		CxAssert(( x_c = ( x_c - x_c2 ) ) == L'B');
		CxAssert(( x_c = ( x_c * x_c2 ) ) == L'B');
		CxAssert(( x_c = ( x_c / x_c2 ) ) == L'B');
		CxAssert(( x_c = ( x_c % x_c2 ) ) == L'\u0000');
		x_c = L'B';
		CxAssert(( x_c = ( x_c & x_c2 ) ) == L'\u0000');
		x_c = L'B';
		CxAssert(( x_c = ( x_c & x_c2 ) ) == L'\u0000');
		x_c = L'B';
		CxAssert(( x_c = ( x_c | x_c2 ) ) == L'C');
		x_c = L'B';
		CxAssert(( x_c = ( x_c ^ x_c2 ) ) == L'C');
		x_c = L'B';
		CxAssert(( x_c = ( x_c << 1 ) ) == L'\u0084');
		x_c = L'B';
		CxAssert(( x_c = ( x_c >> 1 ) ) == L'!');
	}
	void CharTest::CharArrayTests()
	{
		static Char CharArrayTestsArray0[5] = {L'1',L'2',L'3',L'4',L'5'};
		static Char CharArrayTestsArray1[4] = {L'1',L'2',L'3',L'4'};
		static Char CharArrayTestsArray2[2][4] = {{L'1',L'2',L'3',L'4'},{L'4',L'5',L'6',L'7'}};
		static Char CharArrayTestsArray3[2][2][4] = {{{L'1',L'2',L'3',L'4'},{L'5',L'6',L'7',L'8'}},{{L'9',L'A',L'B',L'C'},{L'D',L'E',L'F',L'G'}}};
		Array* x_array = (new Array(CharType,5))->Initialize((Char*) CharArrayTestsArray0);
		CxAssert((Int32Value(x_array->get_Length())).Equals(5));
		CxAssert((CharValue(((*((Char*)x_array->Address(3)))))).Equals(L'4'));
		Array* x_array2 = (new Array(CharType,4))->Initialize((Char*) CharArrayTestsArray1);
		CxAssert((CharValue(((*((Char*)x_array2->Address(1)))))).Equals(L'2'));
		Array* x_array3 = (new Array(CharType,2,4))->Initialize((Char*) CharArrayTestsArray2);
		CxAssert((CharValue(((*((Char*)x_array3->Address(0,2)))))).Equals(L'3'));
		Array* x_array4 = (new Array(CharType,2,2,4))->Initialize((Char*) CharArrayTestsArray3);
		CxAssert((CharValue(((*((Char*)x_array4->Address(0,0,3)))))).Equals(L'4'));
		((*((Char*)x_array4->Address(0,0,3)))) = L'6';
		CxAssert((CharValue(((*((Char*)x_array4->Address(0,0,3)))))).Equals(L'6'));
		x_array4->SetValue(new CharValue(L'4'),0,0,3);
		CxAssert((CharValue(((*((Char*)x_array4->Address(0,0,3)))))).Equals(L'4'));
	}
	void CharTest::CharMiscTests()
	{
		Char x_c = L'0';
		Char x_val = L'1';
		CxAssert((UInt16Value(Math::Max(x_c,x_val))).Equals(49));
		CxAssert((UInt16Value(Math::Min(x_c,x_val))).Equals(48));
		StringBuilder* x_stringBuilder = (new StringBuilder());
		x_stringBuilder->Append(x_c);
		CxAssert(((x_stringBuilder->ToString()))->Equals((new String((Char*)L"0"))));
	}
	void CharTest::CxAssert(Boolean x_x)
	{
		if ( !x_x )
		{
			x_caBlock->TestFailed((new String((Char*)L"Char TestFailed")));
		}
	}
	void CharTest::CxAssert(Boolean x_x,Boolean x_y)
	{
		if ( !(BooleanValue(x_x)).Equals(x_y) )
		{
			x_caBlock->TestFailed((new String((Char*)L"Char TestFailed")));
		}
	}
	CharTest::CharTest()
	{
	}
	DoubleTest::DoubleTest(CABlock* x_caBlock)
	{
		this->x_caBlock = x_caBlock;
	}
	void DoubleTest::Test()
	{
		x_caBlock->Send((new String((Char*)L"Doing DoubleTest")));
		x_caBlock->Send((new String((Char*)L"\tDoing DoDoubleMethodsTest")));
		DoDoubleMethodsTest();
		x_caBlock->Send((new String((Char*)L"\tDoing DoDoubleMath")));
		DoDoubleMath();
		x_caBlock->Send((new String((Char*)L"\tDoing DoubleOperators")));
		DoubleOperators();
		x_caBlock->Send((new String((Char*)L"\tDoing DoubleNanTest")));
		DoubleNanTest();
		x_caBlock->Send((new String((Char*)L"\tDoing DoubleArrayTest")));
		DoubleArrayTest();
		x_caBlock->Send((new String((Char*)L"\tDoing DoubleMiscTests")));
		DoubleMiscTests();
	}
	void DoubleTest::DoDoubleMethodsTest()
	{
		Double x_num = 3.159;
		CxAssert((Int32Value(((DoubleValue)x_num).CompareTo(3.159))).Equals((Int32)0));
		CxAssert((Int32Value(((DoubleValue)x_num).CompareTo(new DoubleValue(3.159)))).Equals((Int32)0));
		CxAssert(((DoubleValue)x_num).Equals(3.159));
		CxAssert((DoubleValue(DoubleValue::Parse((new String((Char*)L"3.159"))))).Equals(3.159));
		CxAssert(((((DoubleValue)x_num).ToString()))->Equals((new String((Char*)L"3.159"))));
		String* x_text = ((DoubleValue)DoubleValue::MinValue).ToString();
		CxAssert(x_text->StartsWith((new String((Char*)L"-1.7976"))) && x_text->EndsWith((new String((Char*)L"E+308"))));
		x_num = 1000000000001;
		CxAssert(x_num > 1000000000000);
		x_num = -1000000000000;
		CxAssert(x_num <= -1000000000000);
		x_num = 10000;
		CxAssert((Int64Value(x_num)).Equals(10000));
		CxAssert((Int32Value(x_num)).Equals(10000));
		CxAssert((UInt32Value(x_num)).Equals(10000));
		Object* x_obj = new DoubleValue(x_num);
		CxAssert((DoubleValue(x_obj->get_AsDouble())).Equals(10000));
		x_num = DoubleValue::Epsilon;
		CxAssert((DoubleValue(x_num)).Equals(DoubleValue::Epsilon));
		x_num = DoubleValue::MaxValue;
		CxAssert((DoubleValue(x_num)).Equals(DoubleValue::MaxValue));
		x_num = DoubleValue::MinValue;
		CxAssert((DoubleValue(x_num)).Equals(DoubleValue::MinValue));
		x_obj = new DoubleValue(5);
		CxAssert(x_obj->Equals(new DoubleValue(5)));
		CxAssert(((x_obj->ToString()))->Equals((new String((Char*)L"5"))));
	}
	void DoubleTest::DoDoubleMath()
	{
		Double x_num = 355;
		Double x_num2 = 113;
		Double x_num3 = x_num / x_num2;
		CxAssert(x_num3,3.14159);
		CxAssert(x_num3 * x_num2,355);
		CxAssert(x_num + x_num2,468);
		CxAssert(x_num - x_num2,242);
		x_num = 2;
		x_num2 = x_num + DoubleValue::Epsilon;
		CxAssert((DoubleValue(x_num2)).Equals(2));
		x_num = 2;
		x_num2 = x_num + 4.94065645841247E-24;
		CxAssert((DoubleValue(x_num2)).Equals(2));
	}
	void DoubleTest::DoubleOperators()
	{
		Double x_num = 66;
		Char x_c = L'\u0001';
		Int32 x_num2 = 1;
		UInt32 x_num3 = 1;
		Int64 x_num4 = 1;
		Double x_num5 = 1;
		CxAssert((DoubleValue(x_num)).Equals(66));
		CxAssert((DoubleValue(x_num + x_c)).Equals(67));
		CxAssert((DoubleValue(x_num + x_num2)).Equals(67));
		CxAssert((DoubleValue(x_num + x_num3)).Equals(67));
		CxAssert((DoubleValue(x_num + x_num4)).Equals(67));
		CxAssert((DoubleValue(x_num + x_num5)).Equals(67));
		CxAssert((DoubleValue(x_num - x_c)).Equals(65));
		CxAssert((DoubleValue(x_num - x_num2)).Equals(65));
		CxAssert((DoubleValue(x_num - x_num3)).Equals(65));
		CxAssert((DoubleValue(x_num - x_num4)).Equals(65));
		CxAssert((DoubleValue(x_num - x_num5)).Equals(65));
		CxAssert((DoubleValue(x_num * x_c)).Equals(66));
		CxAssert((DoubleValue(x_num * x_num2)).Equals(66));
		CxAssert((DoubleValue(x_num * x_num3)).Equals(66));
		CxAssert((DoubleValue(x_num * x_num4)).Equals(66));
		CxAssert((DoubleValue(x_num * x_num5)).Equals(66));
		CxAssert((DoubleValue(x_num / x_c)).Equals(66));
		CxAssert((DoubleValue(x_num / x_num2)).Equals(66));
		CxAssert((DoubleValue(x_num / x_num3)).Equals(66));
		CxAssert((DoubleValue(x_num / x_num4)).Equals(66));
		CxAssert((DoubleValue(x_num / x_num5)).Equals(66));
		CxAssert((DoubleValue(((DoubleValue)x_num) % x_c)).Equals(0));
		CxAssert((DoubleValue(((DoubleValue)x_num) % x_num2)).Equals(0));
		CxAssert((DoubleValue(((DoubleValue)x_num) % x_num3)).Equals(0));
		CxAssert((DoubleValue(((DoubleValue)x_num) % x_num4)).Equals(0));
		CxAssert((DoubleValue(((DoubleValue)x_num) % x_num5)).Equals(0));
		CxAssert(x_c < x_num);
		CxAssert(x_num2 < x_num);
		CxAssert(x_num3 < x_num);
		CxAssert(x_num4 < x_num);
		CxAssert(x_num5 < x_num);
		CxAssert(x_c > x_num,false);
		CxAssert(x_num2 > x_num,false);
		CxAssert(x_num3 > x_num,false);
		CxAssert(x_num4 > x_num,false);
		CxAssert(x_num5 > x_num,false);
		CxAssert(( x_num = x_num + 1 ) == 67);
		CxAssert(( x_num = x_num - 1 ) == 66);
		CxAssert((DoubleValue(x_num++)).Equals(66));
		CxAssert((DoubleValue(x_num--)).Equals(67));
		CxAssert((DoubleValue(x_c)).Equals(x_num),false);
		CxAssert((DoubleValue(x_num2)).Equals(x_num),false);
		CxAssert((DoubleValue(x_num3)).Equals(x_num),false);
		CxAssert((DoubleValue(x_num4)).Equals(x_num),false);
		CxAssert((DoubleValue(x_num5)).Equals(x_num),false);
		CxAssert(!(DoubleValue(x_c)).Equals(x_num));
		CxAssert(!(DoubleValue(x_num2)).Equals(x_num));
		CxAssert(!(DoubleValue(x_num3)).Equals(x_num));
		CxAssert(!(DoubleValue(x_num4)).Equals(x_num));
		CxAssert(!(DoubleValue(x_num5)).Equals(x_num));
		CxAssert(x_c <= x_num);
		CxAssert(x_num2 <= x_num);
		CxAssert(x_num3 <= x_num);
		CxAssert(x_num4 <= x_num);
		CxAssert(x_num5 <= x_num);
		CxAssert(x_c >= x_num,false);
		CxAssert(x_num2 >= x_num,false);
		CxAssert(x_num3 >= x_num,false);
		CxAssert(x_num4 >= x_num,false);
		CxAssert(x_num5 >= x_num,false);
		CxAssert(( x_num = x_num + x_c ) == 67);
		CxAssert(( x_num = x_num - x_c ) == 66);
		CxAssert(( x_num = x_num + x_num2 ) == 67);
		CxAssert(( x_num = x_num - x_num2 ) == 66);
		CxAssert(( x_num = x_num + x_num3 ) == 67);
		CxAssert(( x_num = x_num - x_num3 ) == 66);
		CxAssert(( x_num = x_num + x_num4 ) == 67);
		CxAssert(( x_num = x_num - x_num4 ) == 66);
		CxAssert(( x_num = x_num * x_c ) == 66);
		CxAssert(( x_num = x_num / x_c ) == 66);
		CxAssert(( x_num = x_num * x_num2 ) == 66);
		CxAssert(( x_num = x_num / x_num2 ) == 66);
		CxAssert(( x_num = x_num * x_num3 ) == 66);
		CxAssert(( x_num = x_num / x_num3 ) == 66);
		CxAssert(( x_num = x_num * x_num4 ) == 66);
		CxAssert(( x_num = x_num / x_num4 ) == 66);
		CxAssert(( x_num = ((DoubleValue)x_num) % x_c ) == 0);
		x_num = 66;
		CxAssert(( x_num = ((DoubleValue)x_num) % x_num2 ) == 0);
		x_num = 5;
		CxAssert(((DoubleValue)x_num) % 2.2,0.6);
	}
	void DoubleTest::DoubleNanTest()
	{
		Double x_num = DoubleValue::NaN;
		Double x_num2 = 1;
		CxAssert(DoubleValue::IsNaN(x_num));
		CxAssert(DoubleValue::IsInfinity(DoubleValue::PositiveInfinity));
		CxAssert(DoubleValue::IsNegativeInfinity(DoubleValue::NegativeInfinity));
		CxAssert(DoubleValue::IsPositiveInfinity(DoubleValue::PositiveInfinity));
		CxAssert(DoubleValue::IsNaN(x_num * x_num2));
		CxAssert(DoubleValue::IsNaN(x_num / x_num2));
		CxAssert(DoubleValue::IsNaN(x_num + x_num2));
		CxAssert(DoubleValue::IsNaN(x_num - x_num2));
		CxAssert(DoubleValue::IsNaN(((DoubleValue)x_num) % x_num2));
		CxAssert(x_num < x_num2,false);
		CxAssert(x_num > x_num2,false);
		CxAssert(x_num <= x_num2,false);
		CxAssert(x_num >= x_num2,false);
		CxAssert((DoubleValue(x_num)).Equals(x_num2),false);
		CxAssert((DoubleValue(x_num)).Equals(x_num),false);
		CxAssert(x_num2 < x_num,false);
		CxAssert(x_num2 > x_num,false);
		CxAssert(x_num2 <= x_num,false);
		CxAssert(x_num2 >= x_num,false);
		CxAssert(!(DoubleValue(x_num)).Equals(x_num2));
		CxAssert(!(DoubleValue(x_num)).Equals(x_num));
		x_num = DoubleValue::NaN;
		x_num2 = DoubleValue::NaN;
		if ( (DoubleValue(x_num)).Equals(x_num2) )
		{
			DoubleTestFailed();
		}
		else
		{
			CxAssert(true);
		}
		if ( (DoubleValue(x_num)).Equals(x_num) )
		{
			DoubleTestFailed();
		}
		else
		{
			CxAssert(true);
		}
		if ( !(DoubleValue(x_num)).Equals(x_num2) )
		{
			CxAssert(true);
		}
		else
		{
			DoubleTestFailed();
		}
		if ( !(DoubleValue(x_num)).Equals(x_num) )
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
		if ( (DoubleValue(x_num)).Equals(0) )
		{
			DoubleTestFailed();
		}
		else
		{
			CxAssert(true);
		}
		CxAssert(((DoubleValue)DoubleValue::NaN).Equals(DoubleValue::NaN));
	}
	void DoubleTest::DoubleArrayTest()
	{
		static Double DoubleArrayTestArray0[4] = {1,2,3,4};
		static Double DoubleArrayTestArray1[2][4] = {{1,2,3,4},{4,5,6,7}};
		static Double DoubleArrayTestArray2[2][2][4] = {{{1,2,3,4},{5,6,7,8}},{{9,10,11,12},{13,14,15,16}}};
		Array* x_array = (new Array(DoubleType,4))->Initialize((Double*) DoubleArrayTestArray0);
		CxAssert((DoubleValue(((*((Double*)x_array->Address(1)))))).Equals(2));
		Array* x_array2 = (new Array(DoubleType,2,4))->Initialize((Double*) DoubleArrayTestArray1);
		CxAssert((DoubleValue(((*((Double*)x_array2->Address(0,2)))))).Equals(3));
		Array* x_array3 = (new Array(DoubleType,2,2,4))->Initialize((Double*) DoubleArrayTestArray2);
		CxAssert((DoubleValue(((*((Double*)x_array3->Address(0,0,3)))))).Equals(4));
		((*((Double*)x_array3->Address(0,0,3)))) = 22;
		CxAssert((DoubleValue(((*((Double*)x_array3->Address(0,0,3)))))).Equals(22));
		((*((Double*)x_array2->Address(0,2)))) = DoubleValue::NaN;
		CxAssert(DoubleValue::IsNaN(((*((Double*)x_array2->Address(0,2))))));
		x_array3->SetValue(new DoubleValue(4),0,0,3);
		CxAssert((DoubleValue(((*((Double*)x_array3->Address(0,0,3)))))).Equals(4));
	}
	void DoubleTest::DoubleMiscTests()
	{
		Double x_num = -1;
		Double x_val = 1;
		CxAssert((DoubleValue(Math::Abs(x_num))).Equals(1));
		CxAssert((DoubleValue(Math::Max(x_num,x_val))).Equals(1));
		CxAssert((DoubleValue(Math::Min(x_num,x_val))).Equals(-1));
		CxAssert(Math::Sign(x_num) < 0);
		StringBuilder* x_stringBuilder = (new StringBuilder());
		x_stringBuilder->Append(x_num);
		CxAssert(((x_stringBuilder->ToString()))->Equals((new String((Char*)L"-1"))));
	}
	void DoubleTest::DoubleCompare(Double x_n1,Double x_n2,Double x_resolution)
	{
		if ( Math::Abs(x_n1 - x_n2) > x_resolution )
		{
			DoubleTestFailed();
		}
	}
	void DoubleTest::CxAssert(Double x_x,Double x_y)
	{
		DoubleCompare(x_x,x_y,1E-05);
	}
	void DoubleTest::CxAssert(Boolean x_x)
	{
		if ( !x_x )
		{
			DoubleTestFailed();
		}
	}
	void DoubleTest::CxAssert(Boolean x_x,Boolean x_y)
	{
		if ( !(BooleanValue(x_x)).Equals(x_y) )
		{
			DoubleTestFailed();
		}
	}
	void DoubleTest::DoubleTestFailed()
	{
		x_caBlock->TestFailed((new String((Char*)L"Double TestFailed")));
	}
	DoubleTest::DoubleTest()
	{
	}
	EncodingTest::EncodingTest(CABlock* x_caBlock)
	{
		this->x_caBlock = x_caBlock;
	}
	void EncodingTest::Test()
	{
		x_caBlock->Send((new String((Char*)L"Doing EncodingTest")));
		x_caBlock->Send((new String((Char*)L"\tDoing EncodingMethodsTest")));
		EncodingMethodsTest();
	}
	void EncodingTest::EncodingMethodsTest()
	{
		static Byte EncodingMethodsTestArray0[7] = {84,101,115,116,63,63,63};
		String* x_s = (new String((Char*)L"Test\u0394\u0396\u039f"));
		Array* x_myCharsAsBytes = (new Array(ByteType,7))->Initialize((Byte*) EncodingMethodsTestArray0);
		Encoding* x_aSCII = Encoding::get_ASCII();
		CxAssert((Int32Value(x_aSCII->GetByteCount(x_s))).Equals(7));
		Array* x_bytes = x_aSCII->GetBytes(x_s);
		CxAssert(CompareBytes(x_bytes,x_myCharsAsBytes));
		String* x_string = x_aSCII->GetString(x_bytes);
		CxAssert(((x_string))->Equals((new String((Char*)L"Test???"))));
		String* x_s2 = (new String((Char*)L"123\u042e\u040b\u042f\u0403\u041c\u0422\u0464\u0460\u046a\u047a"));
		CxAssert((Int32Value(x_aSCII->GetByteCount(x_s2))).Equals(13));
		Array* x_bytes2 = x_aSCII->GetBytes(x_s2);
		String* x_string2 = x_aSCII->GetString(x_bytes2);
		CxAssert(((x_string2))->Equals((new String((Char*)L"123??????????"))));
	}
	Boolean EncodingTest::CompareBytes(Array* x_bytes,Array* x_myCharsAsBytes)
	{
		for ( Int32 x_i = 0 ;  x_i < x_bytes->get_Length() ;   x_i++ )
		{
			if ( !(ByteValue(((*((Byte*)x_bytes->Address(x_i)))))).Equals(((*((Byte*)x_myCharsAsBytes->Address(x_i))))) )
			{
				return false;
			}
		}
		return true;
	}
	void EncodingTest::CxAssert(Boolean x_x)
	{
		if ( !x_x )
		{
			x_caBlock->TestFailed((new String((Char*)L"Encoding TestFailed")));
		}
	}
	EncodingTest::EncodingTest()
	{
	}
	EnumTest::EnumTest(CABlock* x_caBlock)
	{
		this->x_caBlock = x_caBlock;
	}
	void EnumTest::Test()
	{
		x_caBlock->Send((new String((Char*)L"Doing EnumTest")));
		Test1(Value1_TestEnum);
		Test1(Value1_TestEnum2);
	}
	void EnumTest::Test1(TestEnum x_testEnum)
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
		Int32 x_num = x_testEnum;
		if ( !(Int32Value(x_num)).Equals(5) )
		{
			EnumTestFailed();
		}
		Double x_num2 = x_testEnum;
		if ( !(DoubleValue(x_num2)).Equals(5) )
		{
			EnumTestFailed();
		}
	}
	void EnumTest::Test1(TestEnum2 x_testEnum)
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
		Int32 x_num = x_testEnum;
		if ( !(Int32Value(x_num)).Equals(5) )
		{
			EnumTestFailed();
		}
		Double x_num2 = x_testEnum;
		if ( !(DoubleValue(x_num2)).Equals(5) )
		{
			EnumTestFailed();
		}
	}
	void EnumTest::EnumTestFailed()
	{
		x_caBlock->TestFailed((new String((Char*)L"Enum TestFailed")));
	}
	EnumTest::EnumTest()
	{
	}
	Int32 CABlock::x_intConstant = 8;
	CABlock::CABlock()
	{
	}
	CABlock::CABlock(Int32 x_i)
	{
	}
	void CABlock::Initialize()
	{
		x_fe = FredValue1_FredEnum;
	}
	void CABlock::Execute()
	{
		RunTests(x_fe);
	}
	void CABlock::RunTests(FredEnum x_fre)
	{
		BasicTest* x_basicTest = (new BasicTest(this));
		x_basicTest->Test();
		MathTest* x_mathTest = (new MathTest(this));
		x_mathTest->Test();
		ArrayTest* x_arrayTest = (new ArrayTest(this));
		x_arrayTest->Test();
		StringTest* x_stringTest = (new StringTest(this));
		x_stringTest->Test();
		EnumTest* x_enumTest = (new EnumTest(this));
		x_enumTest->Test();
		TimeTest* x_timeTest = (new TimeTest(this));
		x_timeTest->Test();
		CharTest* x_charTest = (new CharTest(this));
		x_charTest->Test();
		BooleanTest* x_booleanTest = (new BooleanTest(this));
		x_booleanTest->Test();
		Int32Test* x_int32Test = (new Int32Test(this));
		x_int32Test->Test();
		UInt32Test* x_uInt32Test = (new UInt32Test(this));
		x_uInt32Test->Test();
		Int64Test* x_int64Test = (new Int64Test(this));
		x_int64Test->Test();
		DoubleTest* x_doubleTest = (new DoubleTest(this));
		x_doubleTest->Test();
		StringBuilderTest* x_stringBuilderTest = (new StringBuilderTest(this));
		x_stringBuilderTest->Test();
		BufferTest* x_bufferTest = (new BufferTest(this));
		x_bufferTest->Test();
		ByteTest* x_byteTest = (new ByteTest(this));
		x_byteTest->Test();
		SByteTest* x_sByteTest = (new SByteTest(this));
		x_sByteTest->Test();
		Int16Test* x_int16Test = (new Int16Test(this));
		x_int16Test->Test();
		SingleTest* x_singleTest = (new SingleTest(this));
		x_singleTest->Test();
		UInt16Test* x_uInt16Test = (new UInt16Test(this));
		x_uInt16Test->Test();
		UInt64Test* x_uInt64Test = (new UInt64Test(this));
		x_uInt64Test->Test();
		EncodingTest* x_encodingTest = (new EncodingTest(this));
		x_encodingTest->Test();
	}
	void CABlock::TestFailed(String* x_reason)
	{
		Send((new String((Char*)L"\t\tERROR: "))->Combine(x_reason));
	}
	Int16Test::Int16Test(CABlock* x_caBlock)
	{
		this->x_caBlock = x_caBlock;
	}
	void Int16Test::Test()
	{
		x_caBlock->Send((new String((Char*)L"Doing Int16Test")));
		x_caBlock->Send((new String((Char*)L"\tDoing Int16MethodsTest")));
		Int16MethodsTest();
		x_caBlock->Send((new String((Char*)L"\tDoing Int16MathTest")));
		Int16MathTest();
		x_caBlock->Send((new String((Char*)L"\tDoing Int16Operators")));
		Int16Operators();
		x_caBlock->Send((new String((Char*)L"\tDoing Int16ArrayTests")));
		Int16ArrayTests();
		x_caBlock->Send((new String((Char*)L"\tDoing Int16MiscTests")));
		Int16MiscTests();
	}
	void Int16Test::Int16MethodsTest()
	{
		Int16 x_num = 5;
		CxAssert((Int32Value(((Int16Value)x_num).CompareTo(5))).Equals((Int32)0));
		CxAssert((Int32Value(((Int16Value)x_num).CompareTo((new Int16Value(5))))).Equals((Int32)0));
		CxAssert(((Int16Value)x_num).Equals(5));
		CxAssert(((Int16Value)x_num).Equals((new Int16Value(5))));
		CxAssert((Int16Value(Int16Value::Parse((new String((Char*)L"-55"))))).Equals(-55));
		CxAssert((((new String((Char*)L"-75"))))->Equals(((Int32Value)( -75 )).ToString()));
		String* x_text = ((Int16Value)Int16Value::MaxValue).ToString();
		CxAssert(((x_text))->Equals((new String((Char*)L"32767"))));
		CxAssert((Int16Value(Int16Value::Parse(x_text))).Equals(Int16Value::MaxValue));
		String* x_text2 = ((Int16Value)Int16Value::MinValue).ToString();
		CxAssert(((x_text2))->Equals((new String((Char*)L"-32768"))));
		CxAssert((Int16Value(Int16Value::Parse(x_text2))).Equals(Int16Value::MinValue));
		Int64 x_num2 = Int64Value::MaxValue;
		x_num = x_num2;
		CxAssert((Int16Value(x_num)).Equals(-1));
		Object* x_obj = (new Int16Value(5));
		CxAssert(x_obj->Equals((new Int16Value(5))));
		CxAssert(((x_obj->ToString()))->Equals((new String((Char*)L"5"))));
	}
	void Int16Test::Int16MathTest()
	{
		Int16 x_num = 600;
		Int16 x_num2 = 1200;
		CxAssert((Int32Value(x_num + x_num2)).Equals(1800));
		CxAssert((Int32Value(x_num - x_num2)).Equals(-600));
		CxAssert((Int32Value(x_num * x_num2)).Equals(720000));
		CxAssert((Int32Value(x_num2 / x_num)).Equals(2));
		CxAssert((Int32Value(x_num >> 2)).Equals(150));
		CxAssert((Int32Value(x_num << 1)).Equals(1200));
		Int32 x_num3 = 11;
		CxAssert((Int32Value(x_num3 % 5)).Equals(1));
		x_num3 = 8;
		CxAssert(( x_num3 | 1 ) == 9);
		CxAssert(( x_num3 & 1 ) == 0);
		CxAssert((Int32Value(++x_num3)).Equals(9));
		CxAssert((Int32Value(--x_num3)).Equals(8));
		CxAssert(( x_num3 = x_num3 * 2 ) == 16);
		CxAssert(( x_num3 = x_num3 / 2 ) == 8);
		CxAssert(( x_num3 = x_num3 % 2 ) == 0);
		CxAssert(( x_num3 = x_num3 | 4 ) == 4);
		CxAssert(( x_num3 = x_num3 & 4 ) == 4);
		CxAssert((Int32Value(-x_num)).Equals(-600));
		CxAssert((Int16Value(x_num)).Equals(600));
		x_num3 = 0;
		CxAssert((Int32Value(~x_num3)).Equals(-1));
		CxAssert((Int32Value(++x_num3)).Equals(1));
		CxAssert((Int32Value(--x_num3)).Equals((Int32)0));
		CxAssert(x_num < x_num2);
		CxAssert(x_num <= x_num2);
		CxAssert(x_num2 > x_num);
		CxAssert(x_num2 >= x_num);
	}
	void Int16Test::Int16Operators()
	{
		Int16 x_num = 66;
		Char x_c = L'\u0001';
		Byte x_b = 1;
		SByte x_b2 = 1;
		Int16 x_num2 = 1;
		Int32 x_num3 = 1;
		Int64 x_num4 = 1;
		UInt16 x_num5 = 1;
		UInt32 x_num6 = 1;
		Single x_num7 = ((Single)1);
		Double x_num8 = 1;
		CxAssert((Int16Value(x_num)).Equals(66));
		CxAssert((Int32Value(x_num + x_c)).Equals(67));
		CxAssert((Int32Value(x_num + x_b)).Equals(67));
		CxAssert((Int32Value(x_num + x_b2)).Equals(67));
		CxAssert((Int32Value(x_num + x_num2)).Equals(67));
		CxAssert((Int32Value(x_num + x_num3)).Equals(67));
		CxAssert((Int64Value(x_num + x_num4)).Equals(67));
		CxAssert((Int32Value(x_num + x_num5)).Equals(67));
		CxAssert((Int64Value(x_num + x_num6)).Equals(67));
		CxAssert((SingleValue(x_num + x_num7)).Equals(((Single)67)));
		CxAssert((DoubleValue(x_num + x_num8)).Equals(67));
		CxAssert((Int32Value(x_num - x_c)).Equals(65));
		CxAssert((Int32Value(x_num - x_b)).Equals(65));
		CxAssert((Int32Value(x_num - x_b2)).Equals(65));
		CxAssert((Int32Value(x_num - x_num2)).Equals(65));
		CxAssert((Int32Value(x_num - x_num3)).Equals(65));
		CxAssert((Int64Value(x_num - x_num4)).Equals(65));
		CxAssert((Int32Value(x_num - x_num5)).Equals(65));
		CxAssert((Int64Value(x_num - x_num6)).Equals(65));
		CxAssert((SingleValue(x_num - x_num7)).Equals(((Single)65)));
		CxAssert((DoubleValue(x_num - x_num8)).Equals(65));
		CxAssert((Int32Value(x_num * x_c)).Equals(66));
		CxAssert((Int32Value(x_num * x_b)).Equals(66));
		CxAssert((Int32Value(x_num * x_b2)).Equals(66));
		CxAssert((Int32Value(x_num * x_num2)).Equals(66));
		CxAssert((Int32Value(x_num * x_num3)).Equals(66));
		CxAssert((Int64Value(x_num * x_num4)).Equals(66));
		CxAssert((Int32Value(x_num * x_num5)).Equals(66));
		CxAssert((Int64Value(x_num * x_num6)).Equals(66));
		CxAssert((SingleValue(x_num * x_num7)).Equals(((Single)66)));
		CxAssert((DoubleValue(x_num * x_num8)).Equals(66));
		CxAssert((Int32Value(x_num / x_c)).Equals(66));
		CxAssert((Int32Value(x_num / x_b)).Equals(66));
		CxAssert((Int32Value(x_num / x_b2)).Equals(66));
		CxAssert((Int32Value(x_num / x_num2)).Equals(66));
		CxAssert((Int32Value(x_num / x_num3)).Equals(66));
		CxAssert((Int64Value(x_num / x_num4)).Equals(66));
		CxAssert((Int32Value(x_num / x_num5)).Equals(66));
		CxAssert((Int64Value(x_num / x_num6)).Equals(66));
		CxAssert((SingleValue(x_num / x_num7)).Equals(((Single)66)));
		CxAssert((DoubleValue(x_num / x_num8)).Equals(66));
		CxAssert((Int32Value(x_num % x_c)).Equals((Int32)0));
		CxAssert((Int32Value(x_num % x_b)).Equals((Int32)0));
		CxAssert((Int32Value(x_num % x_b2)).Equals((Int32)0));
		CxAssert((Int32Value(x_num % x_num2)).Equals((Int32)0));
		CxAssert((Int32Value(x_num % x_num3)).Equals((Int32)0));
		CxAssert((Int64Value(x_num % x_num4)).Equals((Int64)0));
		CxAssert((Int32Value(x_num % x_num5)).Equals((Int32)0));
		CxAssert((Int64Value(x_num % x_num6)).Equals((Int64)0));
		CxAssert((SingleValue(((DoubleValue)x_num) % x_num7)).Equals(((Single)0)));
		CxAssert((DoubleValue(((DoubleValue)x_num) % x_num8)).Equals(0));
		CxAssert(( x_num & x_c ) == 0);
		CxAssert(( x_num & x_b ) == 0);
		CxAssert(( x_num & x_b2 ) == 0);
		CxAssert(( x_num & x_num2 ) == 0);
		CxAssert(( x_num & x_num3 ) == 0);
		CxAssert(( x_num & x_num4 ) == 0);
		CxAssert(( x_num & x_num5 ) == 0);
		CxAssert(( x_num & x_num6 ) == 0);
		CxAssert(( x_num | x_c ) == 67);
		CxAssert(( x_num | x_b ) == 67);
		CxAssert(( x_num | x_b2 ) == 67);
		CxAssert(( x_num | x_num2 ) == 67);
		CxAssert(( x_num | x_num3 ) == 67);
		CxAssert(( x_num | x_num4 ) == 67);
		CxAssert(( x_num | x_num5 ) == 67);
		CxAssert(( x_num | x_num6 ) == 67);
		CxAssert(( x_num ^ x_c ) == 67);
		CxAssert(( x_num ^ x_b ) == 67);
		CxAssert(( x_num ^ x_b2 ) == 67);
		CxAssert(( x_num ^ x_num2 ) == 67);
		CxAssert(( x_num ^ x_num3 ) == 67);
		CxAssert(( x_num ^ x_num4 ) == 67);
		CxAssert(( x_num ^ x_num5 ) == 67);
		CxAssert(( x_num ^ x_num6 ) == 67);
		CxAssert((Int32Value(~x_num)).Equals(-67));
		CxAssert(x_c < x_num);
		CxAssert(x_b < x_num);
		CxAssert(x_b2 < x_num);
		CxAssert(x_num2 < x_num);
		CxAssert(x_num3 < x_num);
		CxAssert(x_num4 < x_num);
		CxAssert(x_num5 < x_num);
		CxAssert(x_num6 < x_num);
		CxAssert(x_num7 < x_num);
		CxAssert(x_num8 < x_num);
		CxAssert(x_c > x_num,false);
		CxAssert(x_b > x_num,false);
		CxAssert(x_b2 > x_num,false);
		CxAssert(x_num2 > x_num,false);
		CxAssert(x_num3 > x_num,false);
		CxAssert(x_num4 > x_num,false);
		CxAssert(x_num5 > x_num,false);
		CxAssert(x_num6 > x_num,false);
		CxAssert(x_num7 > x_num,false);
		CxAssert(x_num8 > x_num,false);
		CxAssert(( x_num = ( x_num + 1 ) ) == 67);
		CxAssert(( x_num = ( x_num - 1 ) ) == 66);
		CxAssert((Int16Value(x_num++)).Equals(66));
		CxAssert((Int16Value(x_num--)).Equals(67));
		CxAssert((Int32Value(x_num << 1)).Equals(132));
		CxAssert((Int32Value(x_num >> 1)).Equals(33));
		CxAssert((CharValue(x_c)).Equals(x_num),false);
		CxAssert((ByteValue(x_b)).Equals(x_num),false);
		CxAssert((SByteValue(x_b2)).Equals(x_num),false);
		CxAssert((Int16Value(x_num2)).Equals(x_num),false);
		CxAssert((Int32Value(x_num3)).Equals(x_num),false);
		CxAssert((Int64Value(x_num4)).Equals(x_num),false);
		CxAssert((UInt16Value(x_num5)).Equals(x_num),false);
		CxAssert((UInt32Value(x_num6)).Equals(x_num),false);
		CxAssert((SingleValue(x_num7)).Equals(x_num),false);
		CxAssert((DoubleValue(x_num8)).Equals(x_num),false);
		CxAssert(!(CharValue(x_c)).Equals(x_num));
		CxAssert(!(ByteValue(x_b)).Equals(x_num));
		CxAssert(!(SByteValue(x_b2)).Equals(x_num));
		CxAssert(!(Int16Value(x_num2)).Equals(x_num));
		CxAssert(!(Int32Value(x_num3)).Equals(x_num));
		CxAssert(!(Int64Value(x_num4)).Equals(x_num));
		CxAssert(!(UInt16Value(x_num5)).Equals(x_num));
		CxAssert(!(UInt32Value(x_num6)).Equals(x_num));
		CxAssert(!(SingleValue(x_num7)).Equals(x_num));
		CxAssert(!(DoubleValue(x_num8)).Equals(x_num));
		CxAssert(x_c <= x_num);
		CxAssert(x_b <= x_num);
		CxAssert(x_b2 <= x_num);
		CxAssert(x_num2 <= x_num);
		CxAssert(x_num3 <= x_num);
		CxAssert(x_num4 <= x_num);
		CxAssert(x_num5 <= x_num);
		CxAssert(x_num6 <= x_num);
		CxAssert(x_num7 <= x_num);
		CxAssert(x_num8 <= x_num);
		CxAssert(x_c >= x_num,false);
		CxAssert(x_b >= x_num,false);
		CxAssert(x_b2 >= x_num,false);
		CxAssert(x_num2 >= x_num,false);
		CxAssert(x_num3 >= x_num,false);
		CxAssert(x_num4 >= x_num,false);
		CxAssert(x_num5 >= x_num,false);
		CxAssert(x_num6 >= x_num,false);
		CxAssert(x_num7 >= x_num,false);
		CxAssert(x_num8 >= x_num,false);
		CxAssert(( x_num = ( x_num + x_c ) ) == 67);
		CxAssert(( x_num = ( x_num - x_c ) ) == 66);
		CxAssert(( x_num = ( x_num + x_num3 ) ) == 67);
		CxAssert(( x_num = ( x_num - x_num3 ) ) == 66);
		CxAssert(( x_num = ( x_num * x_c ) ) == 66);
		CxAssert(( x_num = ( x_num / x_c ) ) == 66);
		CxAssert(( x_num = ( x_num * x_num3 ) ) == 66);
		CxAssert(( x_num = ( x_num / x_num3 ) ) == 66);
		CxAssert(( x_num = ( x_num % x_c ) ) == 0);
		x_num = 66;
		CxAssert(( x_num = ( x_num % x_num3 ) ) == 0);
		x_num = 66;
		CxAssert(( x_num = ( x_num & x_c ) ) == 0);
		x_num = 66;
		CxAssert(( x_num = ( x_num & x_num3 ) ) == 0);
		x_num = 66;
		CxAssert(( x_num = ( x_num | x_c ) ) == 67);
		x_num = 66;
		CxAssert(( x_num = ( x_num | x_num3 ) ) == 67);
		x_num = 66;
		CxAssert(( x_num = ( x_num ^ x_c ) ) == 67);
		x_num = 66;
		CxAssert(( x_num = ( x_num ^ x_num3 ) ) == 67);
		x_num = 66;
		CxAssert(( x_num = ( x_num << x_b ) ) == 132);
		x_num = 66;
		CxAssert(( x_num = ( x_num << x_num2 ) ) == 132);
		x_num = 66;
		CxAssert(( x_num = ( x_num << x_c ) ) == 132);
		x_num = 66;
		CxAssert(( x_num = ( x_num << x_num3 ) ) == 132);
		x_num = 66;
		CxAssert(( x_num = ( x_num >> x_c ) ) == 33);
		x_num = 66;
		CxAssert(( x_num = ( x_num >> x_num3 ) ) == 33);
		x_num = 66;
		Int16 x_num9 = 0;
		CxAssert((Int16Value(x_num9)).Equals((Int16)0));
		CxAssert((Int16Value(x_num9)).Equals((Int16)0));
		CxAssert(x_num3 <= 2);
		CxAssert(x_num3 >= -2);
	}
	void Int16Test::Int16ArrayTests()
	{
		static Int16 Int16ArrayTestsArray0[5] = {1,2,3,4,5};
		static Int16 Int16ArrayTestsArray1[4] = {1,2,3,4};
		static Int16 Int16ArrayTestsArray2[2][4] = {{1,2,3,4},{4,5,6,7}};
		static Int16 Int16ArrayTestsArray3[2][2][4] = {{{1,2,3,4},{5,6,7,8}},{{9,10,11,12},{13,14,15,16}}};
		Array* x_array = (new Array(Int16Type,5))->Initialize((Int16*) Int16ArrayTestsArray0);
		CxAssert((Int32Value(x_array->get_Length())).Equals(5));
		CxAssert((Int16Value(((*((Int16*)x_array->Address(3)))))).Equals(4));
		Array* x_array2 = (new Array(Int16Type,4))->Initialize((Int16*) Int16ArrayTestsArray1);
		CxAssert((Int16Value(((*((Int16*)x_array2->Address(1)))))).Equals(2));
		Array* x_array3 = (new Array(Int16Type,2,4))->Initialize((Int16*) Int16ArrayTestsArray2);
		CxAssert((Int16Value(((*((Int16*)x_array3->Address(0,2)))))).Equals(3));
		Array* x_array4 = (new Array(Int16Type,2,2,4))->Initialize((Int16*) Int16ArrayTestsArray3);
		CxAssert((Int16Value(((*((Int16*)x_array4->Address(0,0,3)))))).Equals(4));
		((*((Int16*)x_array4->Address(0,0,3)))) = 6;
		CxAssert((Int16Value(((*((Int16*)x_array4->Address(0,0,3)))))).Equals(6));
		x_array4->SetValue((new Int16Value(4)),0,0,3);
		CxAssert((Int16Value(((*((Int16*)x_array4->Address(0,0,3)))))).Equals(4));
	}
	void Int16Test::Int16MiscTests()
	{
		Int16 x_num = -1;
		Int16 x_val = 1;
		CxAssert((Int16Value(Math::Abs(x_num))).Equals(1));
		CxAssert((Int16Value(Math::Max(x_num,x_val))).Equals(1));
		CxAssert((Int16Value(Math::Min(x_num,x_val))).Equals(-1));
		CxAssert(Math::Sign(x_num) < 0);
		StringBuilder* x_stringBuilder = (new StringBuilder());
		x_stringBuilder->Append(x_num);
		CxAssert(((x_stringBuilder->ToString()))->Equals((new String((Char*)L"-1"))));
		x_stringBuilder->Insert(2,x_num);
		CxAssert(((x_stringBuilder->ToString()))->Equals((new String((Char*)L"-1-1"))));
	}
	void Int16Test::CxAssert(Boolean x_x)
	{
		if ( !x_x )
		{
			x_caBlock->TestFailed((new String((Char*)L"Int16 TestFailed")));
		}
	}
	void Int16Test::CxAssert(Boolean x_x,Boolean x_y)
	{
		if ( !(BooleanValue(x_x)).Equals(x_y) )
		{
			x_caBlock->TestFailed((new String((Char*)L"Int16 TestFailed")));
		}
	}
	Int16Test::Int16Test()
	{
	}
	Int32Test::Int32Test(CABlock* x_caBlock)
	{
		this->x_caBlock = x_caBlock;
	}
	void Int32Test::Test()
	{
		x_caBlock->Send((new String((Char*)L"Doing Int32Test")));
		x_caBlock->Send((new String((Char*)L"\tDoing Int32MethodsTest")));
		Int32MethodsTest();
		x_caBlock->Send((new String((Char*)L"\tDoing Int32MathTest")));
		Int32MathTest();
		x_caBlock->Send((new String((Char*)L"\tDoing Int32Operators")));
		Int32Operators();
		x_caBlock->Send((new String((Char*)L"\tDoing Int32Conversion")));
		Int32Conversion();
		x_caBlock->Send((new String((Char*)L"\tDoing Int32ArrayTests")));
		Int32ArrayTests();
		x_caBlock->Send((new String((Char*)L"\tDoing Int32MiscTests")));
		Int32MiscTests();
	}
	void Int32Test::Int32Conversion()
	{
		Double x_num = 1;
		Double x_num2 = 2;
		if ( x_num < x_num2 )
		{
			x_num = 3;
		}
		Int32 x_num3 = x_num;
		CxAssert((Int32Value(x_num3)).Equals(3));
	}
	void Int32Test::Int32MethodsTest()
	{
		Int32 x_num = 5;
		CxAssert((Int32Value(((Int32Value)x_num).CompareTo(5))).Equals((Int32)0));
		CxAssert((Int32Value(((Int32Value)x_num).CompareTo(new Int32Value(5)))).Equals((Int32)0));
		CxAssert(((Int32Value)x_num).Equals(5));
		CxAssert(((Int32Value)x_num).Equals(new Int32Value(5)));
		CxAssert((Int32Value(Int32Value::Parse((new String((Char*)L"-55"))))).Equals(-55));
		CxAssert((((new String((Char*)L"-75"))))->Equals(((Int32Value)( -75 )).ToString()));
		String* x_text = ((Int32Value)Int32Value::MaxValue).ToString();
		CxAssert(((x_text))->Equals((new String((Char*)L"2147483647"))));
		CxAssert((Int32Value(Int32Value::Parse(x_text))).Equals(Int32Value::MaxValue));
		String* x_text2 = ((Int32Value)Int32Value::MinValue).ToString();
		CxAssert(((x_text2))->Equals((new String((Char*)L"-2147483648"))));
		CxAssert((Int32Value(Int32Value::Parse(x_text2))).Equals(Int32Value::MinValue));
		Int64 x_num2 = Int64Value::MaxValue;
		x_num = x_num2;
		CxAssert((Int32Value(x_num)).Equals(-1));
		Object* x_obj = new Int32Value(5);
		CxAssert(x_obj->Equals(new Int32Value(5)));
	}
	void Int32Test::Int32MathTest()
	{
		Int32 x_num = 60000;
		Int32 x_num2 = 120000;
		CxAssert((Int32Value(x_num + x_num2)).Equals(180000));
		CxAssert((Int32Value(x_num - x_num2)).Equals(-60000));
		CxAssert((Int32Value(x_num * x_num2)).Equals(-1389934592));
		CxAssert((Int32Value(x_num2 / x_num)).Equals(2));
		CxAssert((Int32Value(x_num >> 2)).Equals(15000));
		CxAssert((Int32Value(x_num << 1)).Equals(120000));
		Int32 x_num3 = 11;
		CxAssert((Int32Value(x_num3 % 5)).Equals(1));
		x_num3 = 8;
		CxAssert(( x_num3 | 1 ) == 9);
		CxAssert(( x_num3 & 1 ) == 0);
		CxAssert((Int32Value(++x_num3)).Equals(9));
		CxAssert((Int32Value(--x_num3)).Equals(8));
		CxAssert(( x_num3 = x_num3 * 2 ) == 16);
		CxAssert(( x_num3 = x_num3 / 2 ) == 8);
		CxAssert(( x_num3 = x_num3 % 2 ) == 0);
		CxAssert(( x_num3 = x_num3 | 4 ) == 4);
		CxAssert(( x_num3 = x_num3 & 4 ) == 4);
		CxAssert((Int32Value(-x_num)).Equals(-60000));
		CxAssert((Int32Value(x_num)).Equals(60000));
		x_num3 = 0;
		CxAssert((Int32Value(~x_num3)).Equals(-1));
		CxAssert((Int32Value(++x_num3)).Equals(1));
		CxAssert((Int32Value(--x_num3)).Equals((Int32)0));
		CxAssert(x_num < x_num2);
		CxAssert(x_num <= x_num2);
		CxAssert(x_num2 > x_num);
		CxAssert(x_num2 >= x_num);
	}
	void Int32Test::Int32Operators()
	{
		Int32 x_num = 66;
		Char x_c = L'\u0001';
		Int32 x_num2 = 1;
		UInt32 x_num3 = 1;
		Int64 x_num4 = 1;
		Double x_num5 = 1;
		CxAssert((Int32Value(x_num)).Equals(66));
		CxAssert((Int32Value(x_num + x_c)).Equals(67));
		CxAssert((Int32Value(x_num + x_num2)).Equals(67));
		CxAssert((Int64Value(x_num + x_num3)).Equals(67));
		CxAssert((Int64Value(x_num + x_num4)).Equals(67));
		CxAssert((Int64Value(( x_num + x_num5 ))).Equals(67));
		CxAssert((Int32Value(x_num - x_c)).Equals(65));
		CxAssert((Int32Value(x_num - x_num2)).Equals(65));
		CxAssert((Int64Value(x_num - x_num3)).Equals(65));
		CxAssert((Int64Value(x_num - x_num4)).Equals(65));
		CxAssert((Int64Value(( x_num - x_num5 ))).Equals(65));
		CxAssert((Int32Value(x_num * x_c)).Equals(66));
		CxAssert((Int32Value(x_num * x_num2)).Equals(66));
		CxAssert((Int64Value(x_num * x_num3)).Equals(66));
		CxAssert((Int64Value(x_num * x_num4)).Equals(66));
		CxAssert((Int64Value(( x_num * x_num5 ))).Equals(66));
		CxAssert((Int32Value(x_num / x_c)).Equals(66));
		CxAssert((Int32Value(x_num / x_num2)).Equals(66));
		CxAssert((Int64Value(x_num / x_num3)).Equals(66));
		CxAssert((Int64Value(x_num / x_num4)).Equals(66));
		CxAssert((Int64Value(( x_num / x_num5 ))).Equals(66));
		CxAssert((Int32Value(x_num % x_c)).Equals((Int32)0));
		CxAssert((Int32Value(x_num % x_num2)).Equals((Int32)0));
		CxAssert((Int64Value(x_num % x_num3)).Equals((Int64)0));
		CxAssert((Int64Value(x_num % x_num4)).Equals((Int64)0));
		CxAssert((Int64Value(( ((DoubleValue)x_num) % x_num5 ))).Equals((Int64)0));
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
		CxAssert((Int32Value(~x_num)).Equals(-67));
		CxAssert(x_c < x_num);
		CxAssert(x_num2 < x_num);
		CxAssert(x_num3 < x_num);
		CxAssert(x_num4 < x_num);
		CxAssert(x_num5 < x_num);
		CxAssert(x_c > x_num,false);
		CxAssert(x_num2 > x_num,false);
		CxAssert(x_num3 > x_num,false);
		CxAssert(x_num4 > x_num,false);
		CxAssert(x_num5 > x_num,false);
		CxAssert((Int32Value(++x_num)).Equals(67));
		CxAssert((Int32Value(--x_num)).Equals(66));
		CxAssert((Int32Value(x_num++)).Equals(66));
		CxAssert((Int32Value(x_num--)).Equals(67));
		CxAssert((Int32Value(x_num << 1)).Equals(132));
		CxAssert((Int32Value(x_num >> 1)).Equals(33));
		CxAssert((CharValue(x_c)).Equals(x_num),false);
		CxAssert((Int32Value(x_num2)).Equals(x_num),false);
		CxAssert((UInt32Value(x_num3)).Equals(x_num),false);
		CxAssert((Int64Value(x_num4)).Equals(x_num),false);
		CxAssert((DoubleValue(x_num5)).Equals(x_num),false);
		CxAssert(!(CharValue(x_c)).Equals(x_num));
		CxAssert(!(Int32Value(x_num2)).Equals(x_num));
		CxAssert(!(UInt32Value(x_num3)).Equals(x_num));
		CxAssert(!(Int64Value(x_num4)).Equals(x_num));
		CxAssert(!(DoubleValue(x_num5)).Equals(x_num));
		CxAssert(x_c <= x_num);
		CxAssert(x_num2 <= x_num);
		CxAssert(x_num3 <= x_num);
		CxAssert(x_num4 <= x_num);
		CxAssert(x_num5 <= x_num);
		CxAssert(x_c >= x_num,false);
		CxAssert(x_num2 >= x_num,false);
		CxAssert(x_num3 >= x_num,false);
		CxAssert(x_num4 >= x_num,false);
		CxAssert(x_num5 >= x_num,false);
		CxAssert(( x_num = x_num + x_c ) == 67);
		CxAssert(( x_num = x_num - x_c ) == 66);
		CxAssert(( x_num = x_num + x_num2 ) == 67);
		CxAssert(( x_num = x_num - x_num2 ) == 66);
		CxAssert(( x_num = x_num * x_c ) == 66);
		CxAssert(( x_num = x_num / x_c ) == 66);
		CxAssert(( x_num = x_num * x_num2 ) == 66);
		CxAssert(( x_num = x_num / x_num2 ) == 66);
		CxAssert(( x_num = x_num % x_c ) == 0);
		x_num = 66;
		CxAssert(( x_num = x_num % x_num2 ) == 0);
		x_num = 66;
		CxAssert(( x_num = x_num & x_c ) == 0);
		x_num = 66;
		CxAssert(( x_num = x_num & x_num2 ) == 0);
		x_num = 66;
		CxAssert(( x_num = x_num | x_c ) == 67);
		x_num = 66;
		CxAssert(( x_num = x_num | x_num2 ) == 67);
		x_num = 66;
		CxAssert(( x_num = x_num ^ x_c ) == 67);
		x_num = 66;
		CxAssert(( x_num = x_num ^ x_num2 ) == 67);
		x_num = 66;
		CxAssert(( x_num = x_num << x_c ) == 132);
		x_num = 66;
		CxAssert(( x_num = x_num << x_num2 ) == 132);
		x_num = 66;
		CxAssert(( x_num = x_num >> x_c ) == 33);
		x_num = 66;
		CxAssert(( x_num = x_num >> x_num2 ) == 33);
		x_num = 66;
		Int32 x_num6 = 0;
		CxAssert((Int32Value(x_num6)).Equals((Int32)0));
		CxAssert((Int32Value(x_num6)).Equals((Int32)0));
		CxAssert(x_num2 <= 2);
		CxAssert(x_num2 >= -2);
	}
	void Int32Test::Int32ArrayTests()
	{
		static Int32 Int32ArrayTestsArray0[5] = {1,2,3,4,5};
		static Int32 Int32ArrayTestsArray1[4] = {1,2,3,4};
		static Int32 Int32ArrayTestsArray2[2][4] = {{1,2,3,4},{4,5,6,7}};
		static Int32 Int32ArrayTestsArray3[2][2][4] = {{{1,2,3,4},{5,6,7,8}},{{9,10,11,12},{13,14,15,16}}};
		Array* x_array = (new Array(Int32Type,5))->Initialize((Int32*) Int32ArrayTestsArray0);
		CxAssert((Int32Value(x_array->get_Length())).Equals(5));
		CxAssert((Int32Value(((*((Int32*)x_array->Address(3)))))).Equals(4));
		Array* x_array2 = (new Array(Int32Type,4))->Initialize((Int32*) Int32ArrayTestsArray1);
		CxAssert((Int32Value(((*((Int32*)x_array2->Address(1)))))).Equals(2));
		Array* x_array3 = (new Array(Int32Type,2,4))->Initialize((Int32*) Int32ArrayTestsArray2);
		CxAssert((Int32Value(((*((Int32*)x_array3->Address(0,2)))))).Equals(3));
		Array* x_array4 = (new Array(Int32Type,2,2,4))->Initialize((Int32*) Int32ArrayTestsArray3);
		CxAssert((Int32Value(((*((Int32*)x_array4->Address(0,0,3)))))).Equals(4));
		((*((Int32*)x_array4->Address(0,0,3)))) = 6;
		CxAssert((Int32Value(((*((Int32*)x_array4->Address(0,0,3)))))).Equals(6));
		x_array4->SetValue(new Int32Value(4),0,0,3);
		CxAssert((Int32Value(((*((Int32*)x_array4->Address(0,0,3)))))).Equals(4));
		CxAssert(((((Int32Value)((*((Int32*)x_array4->Address(0,0,3))))).ToString()))->Equals((new String((Char*)L"4"))));
	}
	void Int32Test::Int32MiscTests()
	{
		Int32 x_num = -1;
		Int32 x_val = 1;
		CxAssert((Int32Value(Math::Abs(x_num))).Equals(1));
		CxAssert((Int32Value(Math::Max(x_num,x_val))).Equals(1));
		CxAssert((Int32Value(Math::Min(x_num,x_val))).Equals(-1));
		CxAssert(Math::Sign(x_num) < 0);
		StringBuilder* x_stringBuilder = (new StringBuilder());
		x_stringBuilder->Append(x_num);
		CxAssert(((x_stringBuilder->ToString()))->Equals((new String((Char*)L"-1"))));
	}
	void Int32Test::CxAssert(Boolean x_x)
	{
		if ( !x_x )
		{
			x_caBlock->TestFailed((new String((Char*)L"Int32 TestFailed")));
		}
	}
	void Int32Test::CxAssert(Boolean x_x,Boolean x_y)
	{
		if ( !(BooleanValue(x_x)).Equals(x_y) )
		{
			x_caBlock->TestFailed((new String((Char*)L"Int32 TestFailed")));
		}
	}
	Int32Test::Int32Test()
	{
	}
	Int64Test::Int64Test(CABlock* x_caBlock)
	{
		this->x_caBlock = x_caBlock;
	}
	void Int64Test::Test()
	{
		x_caBlock->Send((new String((Char*)L"Doing Int64Test")));
		x_caBlock->Send((new String((Char*)L"\tDoing Int64MethodsTest")));
		Int64MethodsTest();
		x_caBlock->Send((new String((Char*)L"\tDoing Int64MathTest")));
		Int64MathTest();
		x_caBlock->Send((new String((Char*)L"\tDoing Int64Operators")));
		Int64Operators();
		x_caBlock->Send((new String((Char*)L"\tDoing Int64ArrayTests")));
		Int64ArrayTests();
		x_caBlock->Send((new String((Char*)L"\tDoing Int64MiscTests")));
		Int64MiscTests();
	}
	void Int64Test::Int64MethodsTest()
	{
		Int64 x_num = 5;
		CxAssert((Int32Value(((Int64Value)x_num).CompareTo(5))).Equals((Int32)0));
		CxAssert((Int32Value(((Int64Value)x_num).CompareTo(new Int64Value(5)))).Equals((Int32)0));
		CxAssert(((Int64Value)x_num).Equals(5));
		CxAssert(((Int64Value)x_num).Equals(new Int64Value(5)));
		CxAssert((Int64Value(Int64Value::Parse((new String((Char*)L"-55"))))).Equals(-55));
		String* x_text = ((Int64Value)Int64Value::MaxValue).ToString();
		CxAssert(((x_text))->Equals((new String((Char*)L"9223372036854775807"))));
		CxAssert((Int64Value(Int64Value::Parse(x_text))).Equals(Int64Value::MaxValue));
		String* x_text2 = ((Int64Value)Int64Value::MinValue).ToString();
		CxAssert(((x_text2))->Equals((new String((Char*)L"-9223372036854775808"))));
		CxAssert((Int64Value(Int64Value::Parse(x_text2))).Equals(Int64Value::MinValue));
		Object* x_obj = new Int64Value(5);
		CxAssert(x_obj->Equals(new Int64Value(5)));
		CxAssert(((x_obj->ToString()))->Equals((new String((Char*)L"5"))));
	}
	void Int64Test::Int64MathTest()
	{
		Int64 x_num = 60000000;
		Int64 x_num2 = 120000000;
		CxAssert((Int64Value(x_num + x_num2)).Equals(180000000));
		CxAssert((Int64Value(x_num - x_num2)).Equals(-60000000));
		CxAssert((Int64Value(x_num * x_num2)).Equals(7200000000000000));
		CxAssert((Int64Value(x_num * x_num2)).Equals(7200000000000000));
		CxAssert((Int64Value(x_num2 / x_num)).Equals(2));
		CxAssert((Int64Value(x_num << 1)).Equals(120000000));
		Int32 x_num3 = 11;
		CxAssert((Int32Value(x_num3 % 5)).Equals(1));
		x_num3 = 8;
		CxAssert(( x_num3 | 1 ) == 9);
		CxAssert(( x_num3 & 1 ) == 0);
		CxAssert((Int32Value(++x_num3)).Equals(9));
		CxAssert((Int32Value(--x_num3)).Equals(8));
		CxAssert(( x_num3 = x_num3 * 2 ) == 16);
		CxAssert(( x_num3 = x_num3 / 2 ) == 8);
		CxAssert(( x_num3 = x_num3 % 2 ) == 0);
		CxAssert(( x_num3 = x_num3 | 4 ) == 4);
		CxAssert(( x_num3 = x_num3 & 4 ) == 4);
		CxAssert((Int64Value(-x_num)).Equals(-60000000));
		CxAssert((Int64Value(x_num)).Equals(60000000));
		x_num3 = 0;
		CxAssert((Int32Value(~x_num3)).Equals(-1));
		CxAssert((Int32Value(++x_num3)).Equals(1));
		CxAssert((Int32Value(--x_num3)).Equals((Int32)0));
	}
	void Int64Test::Int64Operators()
	{
		Int64 x_num = 66;
		Char x_c = L'\u0001';
		Int32 x_num2 = 1;
		UInt32 x_num3 = 1;
		Int64 x_num4 = 1;
		Double x_num5 = 1;
		CxAssert((Int64Value(x_num)).Equals(66));
		CxAssert((Int64Value(x_num + x_c)).Equals(67));
		CxAssert((Int64Value(x_num + x_num2)).Equals(67));
		CxAssert((Int64Value(x_num + x_num3)).Equals(67));
		CxAssert((Int64Value(x_num + x_num4)).Equals(67));
		CxAssert((DoubleValue(x_num + x_num5)).Equals(67));
		CxAssert((Int64Value(x_num - x_c)).Equals(65));
		CxAssert((Int64Value(x_num - x_num2)).Equals(65));
		CxAssert((Int64Value(x_num - x_num3)).Equals(65));
		CxAssert((Int64Value(x_num - x_num4)).Equals(65));
		CxAssert((DoubleValue(x_num - x_num5)).Equals(65));
		CxAssert((Int64Value(x_num * x_c)).Equals(66));
		CxAssert((Int64Value(x_num * x_num2)).Equals(66));
		CxAssert((Int64Value(x_num * x_num3)).Equals(66));
		CxAssert((Int64Value(x_num * x_num4)).Equals(66));
		CxAssert((DoubleValue(x_num * x_num5)).Equals(66));
		CxAssert((Int64Value(x_num / x_c)).Equals(66));
		CxAssert((Int64Value(x_num / x_num2)).Equals(66));
		CxAssert((Int64Value(x_num / x_num3)).Equals(66));
		CxAssert((Int64Value(x_num / x_num4)).Equals(66));
		CxAssert((DoubleValue(x_num / x_num5)).Equals(66));
		CxAssert((Int64Value(x_num % x_c)).Equals((Int64)0));
		CxAssert((Int64Value(x_num % x_num2)).Equals((Int64)0));
		CxAssert((Int64Value(x_num % x_num3)).Equals((Int64)0));
		CxAssert((Int64Value(x_num % x_num4)).Equals((Int64)0));
		CxAssert((DoubleValue(((DoubleValue)x_num) % x_num5)).Equals(0));
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
		CxAssert((Int64Value(~x_num)).Equals(-67));
		CxAssert(x_c < x_num);
		CxAssert(x_num2 < x_num);
		CxAssert(x_num3 < x_num);
		CxAssert(x_num4 < x_num);
		CxAssert(x_num5 < x_num);
		CxAssert(x_c > x_num,false);
		CxAssert(x_num2 > x_num,false);
		CxAssert(x_num3 > x_num,false);
		CxAssert(x_num4 > x_num,false);
		CxAssert(x_num5 > x_num,false);
		CxAssert((Int64Value(++x_num)).Equals(67));
		CxAssert((Int64Value(--x_num)).Equals(66));
		CxAssert((Int64Value(x_num++)).Equals(66));
		CxAssert((Int64Value(x_num--)).Equals(67));
		CxAssert((Int64Value(x_num << 1)).Equals(132));
		CxAssert((Int64Value(x_num >> 1)).Equals(33));
		CxAssert((CharValue(x_c)).Equals(x_num),false);
		CxAssert((Int32Value(x_num2)).Equals(x_num),false);
		CxAssert((UInt32Value(x_num3)).Equals(x_num),false);
		CxAssert((Int64Value(x_num4)).Equals(x_num),false);
		CxAssert((DoubleValue(x_num5)).Equals(x_num),false);
		CxAssert(!(CharValue(x_c)).Equals(x_num));
		CxAssert(!(Int32Value(x_num2)).Equals(x_num));
		CxAssert(!(UInt32Value(x_num3)).Equals(x_num));
		CxAssert(!(Int64Value(x_num4)).Equals(x_num));
		CxAssert(!(DoubleValue(x_num5)).Equals(x_num));
		CxAssert(x_c <= x_num);
		CxAssert(x_num2 <= x_num);
		CxAssert(x_num3 <= x_num);
		CxAssert(x_num4 <= x_num);
		CxAssert(x_num5 <= x_num);
		CxAssert(x_c >= x_num,false);
		CxAssert(x_num2 >= x_num,false);
		CxAssert(x_num3 >= x_num,false);
		CxAssert(x_num4 >= x_num,false);
		CxAssert(x_num5 >= x_num,false);
		CxAssert(( x_num = x_num + x_c ) == 67);
		CxAssert(( x_num = x_num - x_c ) == 66);
		CxAssert(( x_num = x_num + x_num2 ) == 67);
		CxAssert(( x_num = x_num - x_num2 ) == 66);
		CxAssert(( x_num = x_num + x_num3 ) == 67);
		CxAssert(( x_num = x_num - x_num3 ) == 66);
		CxAssert(( x_num = x_num + x_num4 ) == 67);
		CxAssert(( x_num = x_num - x_num4 ) == 66);
		CxAssert(( x_num = x_num * x_c ) == 66);
		CxAssert(( x_num = x_num / x_c ) == 66);
		CxAssert(( x_num = x_num * x_num2 ) == 66);
		CxAssert(( x_num = x_num / x_num2 ) == 66);
		CxAssert(( x_num = x_num * x_num3 ) == 66);
		CxAssert(( x_num = x_num / x_num3 ) == 66);
		CxAssert(( x_num = x_num * x_num4 ) == 66);
		CxAssert(( x_num = x_num / x_num4 ) == 66);
		CxAssert(( x_num = x_num % x_c ) == 0);
		x_num = 66;
		CxAssert(( x_num = x_num % x_num2 ) == 0);
		x_num = 66;
		CxAssert(( x_num = x_num % x_num3 ) == 0);
		x_num = 66;
		CxAssert(( x_num = x_num % x_num4 ) == 0);
		x_num = 66;
		CxAssert(( x_num = x_num & x_c ) == 0);
		x_num = 66;
		CxAssert(( x_num = x_num & x_num2 ) == 0);
		x_num = 66;
		CxAssert(( x_num = x_num & x_num3 ) == 0);
		x_num = 66;
		CxAssert(( x_num = x_num & x_num4 ) == 0);
		x_num = 66;
		CxAssert(( x_num = x_num | x_c ) == 67);
		x_num = 66;
		CxAssert(( x_num = x_num | x_num3 ) == 67);
		x_num = 66;
		CxAssert(( x_num = x_num | x_num4 ) == 67);
		x_num = 66;
		CxAssert(( x_num = x_num ^ x_c ) == 67);
		x_num = 66;
		CxAssert(( x_num = x_num ^ x_num2 ) == 67);
		x_num = 66;
		CxAssert(( x_num = x_num ^ x_num3 ) == 67);
		x_num = 66;
		CxAssert(( x_num = x_num ^ x_num4 ) == 67);
		x_num = 66;
		CxAssert(( x_num = x_num << x_c ) == 132);
		x_num = 66;
		CxAssert(( x_num = x_num << x_num2 ) == 132);
		x_num = 66;
		CxAssert(( x_num = x_num >> x_c ) == 33);
		x_num = 66;
		CxAssert(( x_num = x_num >> x_num2 ) == 33);
		x_num = 66;
	}
	void Int64Test::Int64ArrayTests()
	{
		static Int64 Int64ArrayTestsArray0[5] = {1,2,3,4,5};
		static Int64 Int64ArrayTestsArray1[4] = {1,2,3,4};
		static Int64 Int64ArrayTestsArray2[2][4] = {{1,2,3,4},{4,5,6,7}};
		static Int64 Int64ArrayTestsArray3[2][2][4] = {{{1,2,3,4},{5,6,7,8}},{{9,10,11,12},{13,14,15,16}}};
		Array* x_array = (new Array(Int64Type,5))->Initialize((Int64*) Int64ArrayTestsArray0);
		CxAssert((Int32Value(x_array->get_Length())).Equals(5));
		CxAssert((Int64Value(((*((Int64*)x_array->Address(3)))))).Equals(4));
		Array* x_array2 = (new Array(Int64Type,4))->Initialize((Int64*) Int64ArrayTestsArray1);
		CxAssert((Int64Value(((*((Int64*)x_array2->Address(1)))))).Equals(2));
		Array* x_array3 = (new Array(Int64Type,2,4))->Initialize((Int64*) Int64ArrayTestsArray2);
		CxAssert((Int64Value(((*((Int64*)x_array3->Address(0,2)))))).Equals(3));
		Array* x_array4 = (new Array(Int64Type,2,2,4))->Initialize((Int64*) Int64ArrayTestsArray3);
		CxAssert((Int64Value(((*((Int64*)x_array4->Address(0,0,3)))))).Equals(4));
		((*((Int64*)x_array4->Address(0,0,3)))) = 6;
		CxAssert((Int64Value(((*((Int64*)x_array4->Address(0,0,3)))))).Equals(6));
		x_array4->SetValue(new Int64Value(4),0,0,3);
		CxAssert((Int64Value(((*((Int64*)x_array4->Address(0,0,3)))))).Equals(4));
	}
	void Int64Test::Int64MiscTests()
	{
		Int64 x_num = -1;
		Int64 x_val = 1;
		CxAssert((Int64Value(Math::Abs(x_num))).Equals(1));
		CxAssert((Int64Value(Math::Max(x_num,x_val))).Equals(1));
		CxAssert((Int64Value(Math::Min(x_num,x_val))).Equals(-1));
		CxAssert(Math::Sign(x_num) < 0);
		StringBuilder* x_stringBuilder = (new StringBuilder());
		x_stringBuilder->Append(x_num);
		CxAssert(((x_stringBuilder->ToString()))->Equals((new String((Char*)L"-1"))));
	}
	void Int64Test::CxAssert(Boolean x_x)
	{
		if ( !x_x )
		{
			x_caBlock->TestFailed((new String((Char*)L"Int64 TestFailed")));
		}
	}
	void Int64Test::CxAssert(Boolean x_x,Boolean x_y)
	{
		if ( !(BooleanValue(x_x)).Equals(x_y) )
		{
			x_caBlock->TestFailed((new String((Char*)L"Int64 TestFailed")));
		}
	}
	Int64Test::Int64Test()
	{
	}
	MathTest::MathTest(CABlock* x_caBlock)
	{
		this->x_caBlock = x_caBlock;
	}
	void MathTest::Test()
	{
		x_caBlock->Send((new String((Char*)L"Doing MathTest")));
		DoMathTest();
	}
	void MathTest::DoMathTest()
	{
		CxAssert(Math::Abs(-1),1);
		CxAssert(Math::Abs(1),1);
		CxAssert((Int32Value(Math::Abs(-1))).Equals(1));
		CxAssert((Int32Value(Math::Abs(1))).Equals(1));
		CxAssert((Int64Value(Math::Abs(-1))).Equals(1));
		CxAssert((Int64Value(Math::Abs(1))).Equals(1));
		CxAssert(Math::Acos(0.5),Math::PI / 3);
		CxAssert(Math::Asin(0.5),0.523598775598299);
		CxAssert(Math::Atan(0.5),0.463647609000806);
		CxAssert(Math::Atan2(2,1),1.10714871779409);
		CxAssert(Math::Ceiling(1.1),2);
		CxAssert(Math::Cos(0.5),0.877582561890373);
		CxAssert(Math::Cosh(0.5),1.12762596520638);
		CxAssert(Math::Exp(0.5),1.64872127070013);
		CxAssert(Math::Floor(1.1),1);
		CxAssert(Math::Log(0.5),-0.693147180559945);
		CxAssert(Math::Log(0.4,0.5),1.32192809488736);
		CxAssert(Math::Log10(0.5),-0.301029995663981);
		CxAssert(Math::Max(1.1,1.2),1.2);
		CxAssert((Int32Value(Math::Max(1,2))).Equals(2));
		CxAssert((Int64Value(Math::Max(1,2))).Equals(2));
		CxAssert((UInt32Value(Math::Max(1,2))).Equals(2));
		CxAssert(Math::Min(1.1,1.2),1.1);
		CxAssert((Int32Value(Math::Min(1,2))).Equals(1));
		CxAssert((Int64Value(Math::Min(1,2))).Equals(1));
		CxAssert((UInt32Value(Math::Min(1,2))).Equals(1));
		CxAssert(Math::Pow(0.4,0.5),0.632455532033676);
		CxAssert(Math::Round(4.5),4);
		CxAssert(Math::Round(4.6),5);
		CxAssert(Math::Round(DoubleValue::NaN),DoubleValue::NaN);
		CxAssert(Math::Round(3.45,1),3.4);
		CxAssert(Math::Round(3.46,1),3.5);
		CxAssert(Math::Round(-0.123456789,1),-0.1);
		CxAssert(Math::Round(DoubleValue::NaN,1),DoubleValue::NaN);
		CxAssert(Math::Round(1.5),2);
		CxAssert(Math::Round(2.5),2);
		CxAssert(Math::Round(-1.5),-2);
		CxAssert(Math::Round(-2.5),-2);
		CxAssert(Math::Round(DoubleValue::MaxValue),DoubleValue::MaxValue);
		CxAssert(Math::Round(DoubleValue::MinValue),DoubleValue::MinValue);
		CxAssert((Int32Value(Math::Sign(2))).Equals(1));
		CxAssert((Int32Value(Math::Sign(0))).Equals((Int32)0));
		CxAssert((Int32Value(Math::Sign(-2))).Equals(-1));
		CxAssert((Int32Value(Math::Sign(2))).Equals(1));
		CxAssert((Int32Value(Math::Sign(0))).Equals((Int32)0));
		CxAssert((Int32Value(Math::Sign(-2))).Equals(-1));
		CxAssert((Int32Value(Math::Sign(2))).Equals(1));
		CxAssert((Int32Value(Math::Sign(0))).Equals((Int32)0));
		CxAssert((Int32Value(Math::Sign(-2))).Equals(-1));
		CxAssert((Int32Value(Math::Sign(DoubleValue::Epsilon))).Equals(1));
		CxAssert(Math::Sin(0.5),0.479425538604203);
		CxAssert(Math::Sinh(0.5),0.521095305493747);
		CxAssert(Math::Sqrt(25),5);
		CxAssert(Math::Tan(0.52),0.572561830251668);
		CxAssert(Math::Tanh(0.52),0.477700012168498);
		Double x_num = Math::E;
		CxAssert((DoubleValue(Math::E)).Equals(x_num));
		Double x_num2 = Math::PI;
		CxAssert((DoubleValue(Math::PI)).Equals(x_num2));
		CxAssert((DoubleValue(Math::Truncate(x_num2))).Equals(3));
	}
	void MathTest::DoubleCompare(Double x_n1,Double x_n2,Double x_resolution)
	{
		if ( Math::Abs(x_n1 - x_n2) > x_resolution )
		{
			x_caBlock->TestFailed((new String((Char*)L"BaseTest TestFailed")));
		}
	}
	void MathTest::CxAssert(Double x_x,Double x_y)
	{
		DoubleCompare(x_x,x_y,1E-05);
	}
	void MathTest::CxAssert(Boolean x_x)
	{
		if ( !x_x )
		{
			x_caBlock->TestFailed((new String((Char*)L"BaseTest TestFailed")));
		}
	}
	MathTest::MathTest()
	{
	}
	SByteTest::SByteTest(CABlock* x_caBlock)
	{
		this->x_caBlock = x_caBlock;
	}
	void SByteTest::Test()
	{
		x_caBlock->Send((new String((Char*)L"Doing SByteTest")));
		x_caBlock->Send((new String((Char*)L"\tDoing SByteMethodsTest")));
		SByteMethodsTest();
		x_caBlock->Send((new String((Char*)L"\tDoing SByteMathTest")));
		SByteMathTest();
		x_caBlock->Send((new String((Char*)L"\tDoing SByteOperators")));
		SByteOperators();
		x_caBlock->Send((new String((Char*)L"\tDoing SByteArrayTests")));
		SByteArrayTests();
		x_caBlock->Send((new String((Char*)L"\tDoing SByteMiscTests")));
		SByteMiscTests();
	}
	void SByteTest::SByteMethodsTest()
	{
		SByte x_b = 5;
		CxAssert((Int32Value(((SByteValue)x_b).CompareTo(5))).Equals((Int32)0));
		CxAssert((Int32Value(((SByteValue)x_b).CompareTo((new SByteValue(5))))).Equals((Int32)0));
		CxAssert(((SByteValue)x_b).Equals(5));
		CxAssert(((SByteValue)x_b).Equals((new SByteValue(5))));
		CxAssert((SByteValue(SByteValue::Parse((new String((Char*)L"-55"))))).Equals(-55));
		CxAssert((((new String((Char*)L"-75"))))->Equals(((Int32Value)( -75 )).ToString()));
		String* x_text = ((SByteValue)SByteValue::MaxValue).ToString();
		CxAssert(((x_text))->Equals((new String((Char*)L"127"))));
		CxAssert((SByteValue(SByteValue::Parse(x_text))).Equals(SByteValue::MaxValue));
		String* x_text2 = ((SByteValue)SByteValue::MinValue).ToString();
		CxAssert(((x_text2))->Equals((new String((Char*)L"-128"))));
		CxAssert((SByteValue(SByteValue::Parse(x_text2))).Equals(SByteValue::MinValue));
		Int64 x_num = Int64Value::MaxValue;
		x_b = x_num;
		CxAssert((SByteValue(x_b)).Equals(-1));
		Object* x_obj = (new SByteValue(5));
		CxAssert(x_obj->Equals((new SByteValue(5))));
		CxAssert(((x_obj->ToString()))->Equals((new String((Char*)L"5"))));
	}
	void SByteTest::SByteMathTest()
	{
		SByte x_b = 6;
		SByte x_b2 = 12;
		CxAssert((Int32Value(x_b + x_b2)).Equals(18));
		CxAssert((Int32Value(x_b - x_b2)).Equals(-6));
		CxAssert((Int32Value(x_b * x_b2)).Equals(72));
		CxAssert((Int32Value(x_b2 / x_b)).Equals(2));
		CxAssert((Int32Value(x_b >> 2)).Equals(1));
		CxAssert((Int32Value(x_b << 1)).Equals(12));
		Int32 x_num = 11;
		CxAssert((Int32Value(x_num % 5)).Equals(1));
		x_num = 8;
		CxAssert(( x_num | 1 ) == 9);
		CxAssert(( x_num & 1 ) == 0);
		CxAssert((Int32Value(++x_num)).Equals(9));
		CxAssert((Int32Value(--x_num)).Equals(8));
		CxAssert(( x_num = x_num * 2 ) == 16);
		CxAssert(( x_num = x_num / 2 ) == 8);
		CxAssert(( x_num = x_num % 2 ) == 0);
		CxAssert(( x_num = x_num | 4 ) == 4);
		CxAssert(( x_num = x_num & 4 ) == 4);
		CxAssert((Int32Value(-x_b)).Equals(-6));
		CxAssert((SByteValue(x_b)).Equals(6));
		x_num = 0;
		CxAssert((Int32Value(~x_num)).Equals(-1));
		CxAssert((Int32Value(++x_num)).Equals(1));
		CxAssert((Int32Value(--x_num)).Equals((Int32)0));
		CxAssert(x_b < x_b2);
		CxAssert(x_b <= x_b2);
		CxAssert(x_b2 > x_b);
		CxAssert(x_b2 >= x_b);
	}
	void SByteTest::SByteOperators()
	{
		SByte x_b = 66;
		Char x_c = L'\u0001';
		Byte x_b2 = 1;
		SByte x_b3 = 1;
		SByte x_b4 = 1;
		Int32 x_num = 1;
		Int64 x_num2 = 1;
		UInt16 x_num3 = 1;
		UInt32 x_num4 = 1;
		Single x_num5 = ((Single)1);
		Double x_num6 = 1;
		CxAssert((SByteValue(x_b)).Equals(66));
		CxAssert((Int32Value(x_b + x_c)).Equals(67));
		CxAssert((Int32Value(x_b + x_b2)).Equals(67));
		CxAssert((Int32Value(x_b + x_b3)).Equals(67));
		CxAssert((Int32Value(x_b + x_b4)).Equals(67));
		CxAssert((Int32Value(x_b + x_num)).Equals(67));
		CxAssert((Int64Value(x_b + x_num2)).Equals(67));
		CxAssert((Int32Value(x_b + x_num3)).Equals(67));
		CxAssert((Int64Value(x_b + x_num4)).Equals(67));
		CxAssert((SingleValue(x_b + x_num5)).Equals(((Single)67)));
		CxAssert((DoubleValue(x_b + x_num6)).Equals(67));
		CxAssert((Int32Value(x_b - x_c)).Equals(65));
		CxAssert((Int32Value(x_b - x_b2)).Equals(65));
		CxAssert((Int32Value(x_b - x_b3)).Equals(65));
		CxAssert((Int32Value(x_b - x_b4)).Equals(65));
		CxAssert((Int32Value(x_b - x_num)).Equals(65));
		CxAssert((Int64Value(x_b - x_num2)).Equals(65));
		CxAssert((Int32Value(x_b - x_num3)).Equals(65));
		CxAssert((Int64Value(x_b - x_num4)).Equals(65));
		CxAssert((SingleValue(x_b - x_num5)).Equals(((Single)65)));
		CxAssert((DoubleValue(x_b - x_num6)).Equals(65));
		CxAssert((Int32Value(x_b * x_c)).Equals(66));
		CxAssert((Int32Value(x_b * x_b2)).Equals(66));
		CxAssert((Int32Value(x_b * x_b3)).Equals(66));
		CxAssert((Int32Value(x_b * x_b4)).Equals(66));
		CxAssert((Int32Value(x_b * x_num)).Equals(66));
		CxAssert((Int64Value(x_b * x_num2)).Equals(66));
		CxAssert((Int32Value(x_b * x_num3)).Equals(66));
		CxAssert((Int64Value(x_b * x_num4)).Equals(66));
		CxAssert((SingleValue(x_b * x_num5)).Equals(((Single)66)));
		CxAssert((DoubleValue(x_b * x_num6)).Equals(66));
		CxAssert((Int32Value(x_b / x_c)).Equals(66));
		CxAssert((Int32Value(x_b / x_b2)).Equals(66));
		CxAssert((Int32Value(x_b / x_b3)).Equals(66));
		CxAssert((Int32Value(x_b / x_b4)).Equals(66));
		CxAssert((Int32Value(x_b / x_num)).Equals(66));
		CxAssert((Int64Value(x_b / x_num2)).Equals(66));
		CxAssert((Int32Value(x_b / x_num3)).Equals(66));
		CxAssert((Int64Value(x_b / x_num4)).Equals(66));
		CxAssert((SingleValue(x_b / x_num5)).Equals(((Single)66)));
		CxAssert((DoubleValue(x_b / x_num6)).Equals(66));
		CxAssert((Int32Value(x_b % x_c)).Equals((Int32)0));
		CxAssert((Int32Value(x_b % x_b2)).Equals((Int32)0));
		CxAssert((Int32Value(x_b % x_b3)).Equals((Int32)0));
		CxAssert((Int32Value(x_b % x_b4)).Equals((Int32)0));
		CxAssert((Int32Value(x_b % x_num)).Equals((Int32)0));
		CxAssert((Int64Value(x_b % x_num2)).Equals((Int64)0));
		CxAssert((Int32Value(x_b % x_num3)).Equals((Int32)0));
		CxAssert((Int64Value(x_b % x_num4)).Equals((Int64)0));
		CxAssert((SingleValue(((DoubleValue)x_b) % x_num5)).Equals(((Single)0)));
		CxAssert((DoubleValue(((DoubleValue)x_b) % x_num6)).Equals(0));
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
		CxAssert((Int32Value(~x_b)).Equals(-67));
		CxAssert(x_c < x_b);
		CxAssert(x_b2 < x_b);
		CxAssert(x_b3 < x_b);
		CxAssert(x_b4 < x_b);
		CxAssert(x_num < x_b);
		CxAssert(x_num2 < x_b);
		CxAssert(x_num3 < x_b);
		CxAssert(x_num4 < x_b);
		CxAssert(x_num5 < x_b);
		CxAssert(x_num6 < x_b);
		CxAssert(x_c > x_b,false);
		CxAssert(x_b2 > x_b,false);
		CxAssert(x_b3 > x_b,false);
		CxAssert(x_b4 > x_b,false);
		CxAssert(x_num > x_b,false);
		CxAssert(x_num2 > x_b,false);
		CxAssert(x_num3 > x_b,false);
		CxAssert(x_num4 > x_b,false);
		CxAssert(x_num5 > x_b,false);
		CxAssert(x_num6 > x_b,false);
		CxAssert(( x_b = ( x_b + 1 ) ) == 67);
		CxAssert(( x_b = ( x_b - 1 ) ) == 66);
		CxAssert((SByteValue(x_b++)).Equals(66));
		CxAssert((SByteValue(x_b--)).Equals(67));
		CxAssert((Int32Value(x_b << 1)).Equals(132));
		CxAssert((Int32Value(x_b >> 1)).Equals(33));
		CxAssert((CharValue(x_c)).Equals(x_b),false);
		CxAssert((ByteValue(x_b2)).Equals(x_b),false);
		CxAssert((SByteValue(x_b3)).Equals(x_b),false);
		CxAssert((SByteValue(x_b4)).Equals(x_b),false);
		CxAssert((Int32Value(x_num)).Equals(x_b),false);
		CxAssert((Int64Value(x_num2)).Equals(x_b),false);
		CxAssert((UInt16Value(x_num3)).Equals(x_b),false);
		CxAssert((UInt32Value(x_num4)).Equals(x_b),false);
		CxAssert((SingleValue(x_num5)).Equals(x_b),false);
		CxAssert((DoubleValue(x_num6)).Equals(x_b),false);
		CxAssert(!(CharValue(x_c)).Equals(x_b));
		CxAssert(!(ByteValue(x_b2)).Equals(x_b));
		CxAssert(!(SByteValue(x_b3)).Equals(x_b));
		CxAssert(!(SByteValue(x_b4)).Equals(x_b));
		CxAssert(!(Int32Value(x_num)).Equals(x_b));
		CxAssert(!(Int64Value(x_num2)).Equals(x_b));
		CxAssert(!(UInt16Value(x_num3)).Equals(x_b));
		CxAssert(!(UInt32Value(x_num4)).Equals(x_b));
		CxAssert(!(SingleValue(x_num5)).Equals(x_b));
		CxAssert(!(DoubleValue(x_num6)).Equals(x_b));
		CxAssert(x_c <= x_b);
		CxAssert(x_b2 <= x_b);
		CxAssert(x_b3 <= x_b);
		CxAssert(x_b4 <= x_b);
		CxAssert(x_num <= x_b);
		CxAssert(x_num2 <= x_b);
		CxAssert(x_num3 <= x_b);
		CxAssert(x_num4 <= x_b);
		CxAssert(x_num5 <= x_b);
		CxAssert(x_num6 <= x_b);
		CxAssert(x_c >= x_b,false);
		CxAssert(x_b2 >= x_b,false);
		CxAssert(x_b3 >= x_b,false);
		CxAssert(x_b4 >= x_b,false);
		CxAssert(x_num >= x_b,false);
		CxAssert(x_num2 >= x_b,false);
		CxAssert(x_num3 >= x_b,false);
		CxAssert(x_num4 >= x_b,false);
		CxAssert(x_num5 >= x_b,false);
		CxAssert(x_num6 >= x_b,false);
		CxAssert(( x_b = ( x_b + x_c ) ) == 67);
		CxAssert(( x_b = ( x_b - x_c ) ) == 66);
		CxAssert(( x_b = ( x_b + x_num ) ) == 67);
		CxAssert(( x_b = ( x_b - x_num ) ) == 66);
		CxAssert(( x_b = ( x_b * x_c ) ) == 66);
		CxAssert(( x_b = ( x_b / x_c ) ) == 66);
		CxAssert(( x_b = ( x_b * x_num ) ) == 66);
		CxAssert(( x_b = ( x_b / x_num ) ) == 66);
		CxAssert(( x_b = ( x_b % x_c ) ) == 0);
		x_b = 66;
		CxAssert(( x_b = ( x_b % x_num ) ) == 0);
		x_b = 66;
		CxAssert(( x_b = ( x_b & x_c ) ) == 0);
		x_b = 66;
		CxAssert(( x_b = ( x_b & x_num ) ) == 0);
		x_b = 66;
		CxAssert(( x_b = ( x_b | x_c ) ) == 67);
		x_b = 66;
		CxAssert(( x_b = ( x_b | x_num ) ) == 67);
		x_b = 66;
		CxAssert(( x_b = ( x_b ^ x_c ) ) == 67);
		x_b = 66;
		CxAssert(( x_b = ( x_b ^ x_num ) ) == 67);
		x_b = 66;
		CxAssert(( x_b = ( x_b << x_b2 ) ) == -124);
		x_b = 66;
		CxAssert(( x_b = ( x_b << x_b4 ) ) == -124);
		x_b = 66;
		CxAssert(( x_b = ( x_b << x_c ) ) == -124);
		x_b = 66;
		CxAssert(( x_b = ( x_b << x_num ) ) == -124);
		x_b = 66;
		CxAssert(( x_b = ( x_b >> x_c ) ) == 33);
		x_b = 66;
		CxAssert(( x_b = ( x_b >> x_num ) ) == 33);
		x_b = 66;
		SByte x_b5 = 0;
		CxAssert((SByteValue(x_b5)).Equals((SByte)0));
		CxAssert((SByteValue(x_b5)).Equals((SByte)0));
		CxAssert(x_num <= 2);
		CxAssert(x_num >= -2);
	}
	void SByteTest::SByteArrayTests()
	{
		static SByte SByteArrayTestsArray0[5] = {1,2,3,4,5};
		static SByte SByteArrayTestsArray1[4] = {1,2,3,4};
		static SByte SByteArrayTestsArray2[2][4] = {{1,2,3,4},{4,5,6,7}};
		static SByte SByteArrayTestsArray3[2][2][4] = {{{1,2,3,4},{5,6,7,8}},{{9,10,11,12},{13,14,15,16}}};
		Array* x_array = (new Array(SByteType,5))->Initialize((SByte*) SByteArrayTestsArray0);
		CxAssert((Int32Value(x_array->get_Length())).Equals(5));
		CxAssert((SByteValue(((*((SByte*)x_array->Address(3)))))).Equals(4));
		Array* x_array2 = (new Array(SByteType,4))->Initialize((SByte*) SByteArrayTestsArray1);
		CxAssert((SByteValue(((*((SByte*)x_array2->Address(1)))))).Equals(2));
		Array* x_array3 = (new Array(SByteType,2,4))->Initialize((SByte*) SByteArrayTestsArray2);
		CxAssert((SByteValue(((*((SByte*)x_array3->Address(0,2)))))).Equals(3));
		Array* x_array4 = (new Array(SByteType,2,2,4))->Initialize((SByte*) SByteArrayTestsArray3);
		CxAssert((SByteValue(((*((SByte*)x_array4->Address(0,0,3)))))).Equals(4));
		((*((SByte*)x_array4->Address(0,0,3)))) = 6;
		CxAssert((SByteValue(((*((SByte*)x_array4->Address(0,0,3)))))).Equals(6));
		x_array4->SetValue((new SByteValue(4)),0,0,3);
		CxAssert((SByteValue(((*((SByte*)x_array4->Address(0,0,3)))))).Equals(4));
	}
	void SByteTest::SByteMiscTests()
	{
		SByte x_b = -1;
		SByte x_val = 1;
		CxAssert((SByteValue(Math::Abs(x_b))).Equals(1));
		CxAssert((SByteValue(Math::Max(x_b,x_val))).Equals(1));
		CxAssert((SByteValue(Math::Min(x_b,x_val))).Equals(-1));
		CxAssert(Math::Sign(x_b) < 0);
		StringBuilder* x_stringBuilder = (new StringBuilder());
		x_stringBuilder->Append(x_b);
		CxAssert(((x_stringBuilder->ToString()))->Equals((new String((Char*)L"-1"))));
		x_stringBuilder->Insert(2,x_b);
		CxAssert(((x_stringBuilder->ToString()))->Equals((new String((Char*)L"-1-1"))));
	}
	void SByteTest::CxAssert(Boolean x_x)
	{
		if ( !x_x )
		{
			x_caBlock->TestFailed((new String((Char*)L"SByte TestFailed")));
		}
	}
	void SByteTest::CxAssert(Boolean x_x,Boolean x_y)
	{
		if ( !(BooleanValue(x_x)).Equals(x_y) )
		{
			x_caBlock->TestFailed((new String((Char*)L"SByte TestFailed")));
		}
	}
	SByteTest::SByteTest()
	{
	}
	SingleTest::SingleTest(CABlock* x_caBlock)
	{
		this->x_caBlock = x_caBlock;
	}
	void SingleTest::Test()
	{
		x_caBlock->Send((new String((Char*)L"Doing SingleTest")));
		x_caBlock->Send((new String((Char*)L"\tDoing DoSingleMethodsTest")));
		DoSingleMethodsTest();
		x_caBlock->Send((new String((Char*)L"\tDoing DoSingleMath")));
		DoSingleMath();
		x_caBlock->Send((new String((Char*)L"\tDoing SingleOperators")));
		SingleOperators();
		x_caBlock->Send((new String((Char*)L"\tDoing SingleNanTest")));
		SingleNanTest();
		x_caBlock->Send((new String((Char*)L"\tDoing SingleArrayTest")));
		SingleArrayTest();
		x_caBlock->Send((new String((Char*)L"\tDoing SingleMiscTests")));
		SingleMiscTests();
	}
	void SingleTest::DoSingleMethodsTest()
	{
		Single x_num = ((Single)3.159);
		CxAssert((Int32Value(((SingleValue)x_num).CompareTo(((Single)3.159)))).Equals((Int32)0));
		CxAssert((Int32Value(((SingleValue)x_num).CompareTo(new SingleValue(((Single)3.159))))).Equals((Int32)0));
		CxAssert(((SingleValue)x_num).Equals(((Single)3.159)));
		CxAssert(SingleValue::Parse((new String((Char*)L"3.159"))),3.15899991989136);
		CxAssert(((((SingleValue)x_num).ToString()))->Equals((new String((Char*)L"3.159"))));
		CxAssert(SingleValue::Parse(((SingleValue)x_num).ToString()),x_num);
		x_num = ((Single)1E+07);
		CxAssert(x_num > ((Single)1E+07));
		x_num = ((Single)-1E+07);
		CxAssert(x_num <= ((Single)-1E+07));
		x_num = ((Single)10000);
		CxAssert((Int64Value(x_num)).Equals(10000));
		CxAssert((Int32Value(x_num)).Equals(10000));
		CxAssert((UInt32Value(x_num)).Equals(10000));
		Object* x_obj = new SingleValue(x_num);
		CxAssert((DoubleValue(x_obj->get_AsSingle())).Equals(10000));
		x_num = FloatValue::Epsilon;
		CxAssert((SingleValue(x_num)).Equals(FloatValue::Epsilon));
		x_num = FloatValue::MaxValue;
		CxAssert((SingleValue(x_num)).Equals(FloatValue::MaxValue));
		x_num = FloatValue::MinValue;
		CxAssert((SingleValue(x_num)).Equals(FloatValue::MinValue));
		x_obj = new SingleValue(((Single)5));
		CxAssert(x_obj->Equals(new SingleValue(((Single)5))));
		CxAssert(((x_obj->ToString()))->Equals((new String((Char*)L"5"))));
	}
	void SingleTest::DoSingleMath()
	{
		Single x_num = ((Single)355);
		Single x_num2 = ((Single)113);
		Single x_num3 = x_num / x_num2;
		CxAssert(x_num3,3.14159);
		CxAssert(x_num3 * x_num2,355);
		CxAssert(x_num + x_num2,468);
		CxAssert(x_num - x_num2,242);
		x_num = ((Single)1);
		x_num2 = x_num + FloatValue::Epsilon;
		CxAssert((DoubleValue(x_num2)).Equals(1));
	}
	void SingleTest::SingleOperators()
	{
		Single x_num = ((Single)66);
		Char x_c = L'\u0001';
		Int32 x_num2 = 1;
		UInt32 x_num3 = 1;
		Int64 x_num4 = 1;
		Double x_num5 = 1;
		CxAssert((SingleValue(x_num)).Equals(((Single)66)));
		CxAssert((SingleValue(x_num + x_c)).Equals(((Single)67)));
		CxAssert((SingleValue(x_num + x_num2)).Equals(((Single)67)));
		CxAssert((SingleValue(x_num + x_num3)).Equals(((Single)67)));
		CxAssert((SingleValue(x_num + x_num4)).Equals(((Single)67)));
		CxAssert((DoubleValue(x_num + x_num5)).Equals(67));
		CxAssert((SingleValue(x_num - x_c)).Equals(((Single)65)));
		CxAssert((SingleValue(x_num - x_num2)).Equals(((Single)65)));
		CxAssert((SingleValue(x_num - x_num3)).Equals(((Single)65)));
		CxAssert((SingleValue(x_num - x_num4)).Equals(((Single)65)));
		CxAssert((DoubleValue(x_num - x_num5)).Equals(65));
		CxAssert((SingleValue(x_num * x_c)).Equals(((Single)66)));
		CxAssert((SingleValue(x_num * x_num2)).Equals(((Single)66)));
		CxAssert((SingleValue(x_num * x_num3)).Equals(((Single)66)));
		CxAssert((SingleValue(x_num * x_num4)).Equals(((Single)66)));
		CxAssert((DoubleValue(x_num * x_num5)).Equals(66));
		CxAssert((SingleValue(x_num / x_c)).Equals(((Single)66)));
		CxAssert((SingleValue(x_num / x_num2)).Equals(((Single)66)));
		CxAssert((SingleValue(x_num / x_num3)).Equals(((Single)66)));
		CxAssert((SingleValue(x_num / x_num4)).Equals(((Single)66)));
		CxAssert((DoubleValue(x_num / x_num5)).Equals(66));
		CxAssert((SingleValue(((DoubleValue)x_num) % x_c)).Equals(((Single)0)));
		CxAssert((SingleValue(((DoubleValue)x_num) % x_num2)).Equals(((Single)0)));
		CxAssert((SingleValue(((DoubleValue)x_num) % x_num3)).Equals(((Single)0)));
		CxAssert((SingleValue(((DoubleValue)x_num) % x_num4)).Equals(((Single)0)));
		CxAssert((DoubleValue(((DoubleValue)x_num) % x_num5)).Equals(0));
		CxAssert(x_c < x_num);
		CxAssert(x_num2 < x_num);
		CxAssert(x_num3 < x_num);
		CxAssert(x_num4 < x_num);
		CxAssert(x_num5 < x_num);
		CxAssert(x_c > x_num,false);
		CxAssert(x_num2 > x_num,false);
		CxAssert(x_num3 > x_num,false);
		CxAssert(x_num4 > x_num,false);
		CxAssert(x_num5 > x_num,false);
		CxAssert(( x_num = x_num + ((Single)1) ) == ((Single)67));
		CxAssert(( x_num = x_num - ((Single)1) ) == ((Single)66));
		CxAssert((SingleValue(x_num++)).Equals(((Single)66)));
		CxAssert((SingleValue(x_num--)).Equals(((Single)67)));
		CxAssert((SingleValue(x_c)).Equals(x_num),false);
		CxAssert((SingleValue(x_num2)).Equals(x_num),false);
		CxAssert((SingleValue(x_num3)).Equals(x_num),false);
		CxAssert((SingleValue(x_num4)).Equals(x_num),false);
		CxAssert((DoubleValue(x_num5)).Equals(x_num),false);
		CxAssert(!(SingleValue(x_c)).Equals(x_num));
		CxAssert(!(SingleValue(x_num2)).Equals(x_num));
		CxAssert(!(SingleValue(x_num3)).Equals(x_num));
		CxAssert(!(SingleValue(x_num4)).Equals(x_num));
		CxAssert(!(DoubleValue(x_num5)).Equals(x_num));
		CxAssert(x_c <= x_num);
		CxAssert(x_num2 <= x_num);
		CxAssert(x_num3 <= x_num);
		CxAssert(x_num4 <= x_num);
		CxAssert(x_num5 <= x_num);
		CxAssert(x_c >= x_num,false);
		CxAssert(x_num2 >= x_num,false);
		CxAssert(x_num3 >= x_num,false);
		CxAssert(x_num4 >= x_num,false);
		CxAssert(x_num5 >= x_num,false);
		CxAssert(( x_num = x_num + x_c ) == ((Single)67));
		CxAssert(( x_num = x_num - x_c ) == ((Single)66));
		CxAssert(( x_num = x_num + x_num2 ) == ((Single)67));
		CxAssert(( x_num = x_num - x_num2 ) == ((Single)66));
		CxAssert(( x_num = x_num + x_num3 ) == ((Single)67));
		CxAssert(( x_num = x_num - x_num3 ) == ((Single)66));
		CxAssert(( x_num = x_num + x_num4 ) == ((Single)67));
		CxAssert(( x_num = x_num - x_num4 ) == ((Single)66));
		CxAssert(( x_num = x_num * x_c ) == ((Single)66));
		CxAssert(( x_num = x_num / x_c ) == ((Single)66));
		CxAssert(( x_num = x_num * x_num2 ) == ((Single)66));
		CxAssert(( x_num = x_num / x_num2 ) == ((Single)66));
		CxAssert(( x_num = x_num * x_num3 ) == ((Single)66));
		CxAssert(( x_num = x_num / x_num3 ) == ((Single)66));
		CxAssert(( x_num = x_num * x_num4 ) == ((Single)66));
		CxAssert(( x_num = x_num / x_num4 ) == ((Single)66));
		CxAssert(( x_num = ((DoubleValue)x_num) % x_c ) == ((Single)0));
		x_num = ((Single)66);
		CxAssert(( x_num = ((DoubleValue)x_num) % x_num2 ) == ((Single)0));
		x_num = ((Single)5);
		CxAssert(((DoubleValue)x_num) % 2.2,0.6);
	}
	void SingleTest::SingleNanTest()
	{
		Single x_num = FloatValue::NaN;
		Single x_num2 = ((Single)1);
		CxAssert(SingleValue::IsNaN(x_num));
		CxAssert(SingleValue::IsInfinity(FloatValue::PositiveInfinity));
		CxAssert(SingleValue::IsNegativeInfinity(FloatValue::NegativeInfinity));
		CxAssert(SingleValue::IsPositiveInfinity(FloatValue::PositiveInfinity));
		CxAssert(SingleValue::IsNaN(x_num * x_num2));
		CxAssert(SingleValue::IsNaN(x_num / x_num2));
		CxAssert(SingleValue::IsNaN(x_num + x_num2));
		CxAssert(SingleValue::IsNaN(x_num - x_num2));
		CxAssert(SingleValue::IsNaN(((DoubleValue)x_num) % x_num2));
		CxAssert(x_num < x_num2,false);
		CxAssert(x_num > x_num2,false);
		CxAssert(x_num <= x_num2,false);
		CxAssert(x_num >= x_num2,false);
		CxAssert((SingleValue(x_num)).Equals(x_num2),false);
		CxAssert((SingleValue(x_num)).Equals(x_num),false);
		CxAssert(x_num2 < x_num,false);
		CxAssert(x_num2 > x_num,false);
		CxAssert(x_num2 <= x_num,false);
		CxAssert(x_num2 >= x_num,false);
		CxAssert(!(SingleValue(x_num)).Equals(x_num2));
		CxAssert(!(SingleValue(x_num)).Equals(x_num));
		x_num = FloatValue::NaN;
		x_num2 = FloatValue::NaN;
		if ( (SingleValue(x_num)).Equals(x_num2) )
		{
			SingleTestFailed();
		}
		else
		{
			CxAssert(true);
		}
		if ( (SingleValue(x_num)).Equals(x_num) )
		{
			SingleTestFailed();
		}
		else
		{
			CxAssert(true);
		}
		if ( !(SingleValue(x_num)).Equals(x_num2) )
		{
			CxAssert(true);
		}
		else
		{
			SingleTestFailed();
		}
		if ( !(SingleValue(x_num)).Equals(x_num) )
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
		if ( (SingleValue(x_num)).Equals(((Single)0)) )
		{
			SingleTestFailed();
		}
		else
		{
			CxAssert(true);
		}
		CxAssert(((SingleValue)FloatValue::NaN).Equals(FloatValue::NaN));
	}
	void SingleTest::SingleArrayTest()
	{
		static Float SingleArrayTestArray0[4] = {((Single)1),((Single)2),((Single)3),((Single)4)};
		static Float SingleArrayTestArray1[2][4] = {{((Single)1),((Single)2),((Single)3),((Single)4)},{((Single)4),((Single)5),((Single)6),((Single)7)}};
		static Float SingleArrayTestArray2[2][2][4] = {{{((Single)1),((Single)2),((Single)3),((Single)4)},{((Single)5),((Single)6),((Single)7),((Single)8)}},{{((Single)9),((Single)10),((Single)11),((Single)12)},{((Single)13),((Single)14),((Single)15),((Single)16)}}};
		Array* x_array = (new Array(FloatType,4))->Initialize((Float*) SingleArrayTestArray0);
		CxAssert((SingleValue(((*((Single*)x_array->Address(1)))))).Equals(((Single)2)));
		Array* x_array2 = (new Array(FloatType,2,4))->Initialize((Float*) SingleArrayTestArray1);
		CxAssert((SingleValue(((*((Single*)x_array2->Address(0,2)))))).Equals(((Single)3)));
		Array* x_array3 = (new Array(FloatType,2,2,4))->Initialize((Float*) SingleArrayTestArray2);
		CxAssert((SingleValue(((*((Single*)x_array3->Address(0,0,3)))))).Equals(((Single)4)));
		((*((Single*)x_array3->Address(0,0,3)))) = ((Single)22);
		CxAssert((SingleValue(((*((Single*)x_array3->Address(0,0,3)))))).Equals(((Single)22)));
		((*((Single*)x_array2->Address(0,2)))) = FloatValue::NaN;
		CxAssert(SingleValue::IsNaN(((*((Single*)x_array2->Address(0,2))))));
		x_array3->SetValue(new SingleValue(((Single)4)),0,0,3);
		CxAssert((SingleValue(((*((Single*)x_array3->Address(0,0,3)))))).Equals(((Single)4)));
	}
	void SingleTest::SingleMiscTests()
	{
		Single x_num = ((Single)-1);
		Single x_val = ((Single)1);
		CxAssert((SingleValue(Math::Abs(x_num))).Equals(((Single)1)));
		CxAssert((SingleValue(Math::Max(x_num,x_val))).Equals(((Single)1)));
		CxAssert((SingleValue(Math::Min(x_num,x_val))).Equals(((Single)-1)));
		CxAssert(Math::Sign(x_num) < 0);
		StringBuilder* x_stringBuilder = (new StringBuilder());
		x_stringBuilder->Append(x_num);
		CxAssert(((x_stringBuilder->ToString()))->Equals((new String((Char*)L"-1"))));
		x_stringBuilder->Insert(2,x_num);
		CxAssert(((x_stringBuilder->ToString()))->Equals((new String((Char*)L"-1-1"))));
	}
	void SingleTest::SingleCompare(Double x_n1,Double x_n2,Double x_resolution)
	{
		Double x_num = Math::Abs(x_n1 - x_n2);
		if ( x_num > x_resolution )
		{
			SingleTestFailed();
		}
	}
	void SingleTest::CxAssert(Double x_x,Double x_y)
	{
		SingleCompare(x_x,x_y,1E-05);
	}
	void SingleTest::CxAssert(Boolean x_x)
	{
		if ( !x_x )
		{
			SingleTestFailed();
		}
	}
	void SingleTest::CxAssert(Boolean x_x,Boolean x_y)
	{
		if ( !(BooleanValue(x_x)).Equals(x_y) )
		{
			SingleTestFailed();
		}
	}
	void SingleTest::SingleTestFailed()
	{
		x_caBlock->TestFailed((new String((Char*)L"Single TestFailed")));
	}
	SingleTest::SingleTest()
	{
	}
	StringBuilderTest::StringBuilderTest(CABlock* x_caBlock)
	{
		x_sb = (new StringBuilder());
		this->x_caBlock = x_caBlock;
	}
	void StringBuilderTest::Test()
	{
		x_caBlock->Send((new String((Char*)L"Doing StringBuilderTest")));
		x_caBlock->Send((new String((Char*)L"\tDoing DoSBConstructTest")));
		DoSBConstructTest();
		x_caBlock->Send((new String((Char*)L"\tDoing DoSBPropertyTest")));
		DoSBPropertyTest();
		x_caBlock->Send((new String((Char*)L"\tDoing DoSBAppendTest")));
		DoSBAppendTest();
		x_caBlock->Send((new String((Char*)L"\tDoing DoSBMiscTest")));
		DoSBMiscTest();
		x_caBlock->Send((new String((Char*)L"\tDoing DoSBInsertTest")));
		DoSBInsertTest();
		x_caBlock->Send((new String((Char*)L"\tDoing DoSBReplaceTest")));
		DoSBReplaceTest();
	}
	void StringBuilderTest::DoSBConstructTest()
	{
		static Char DoSBConstructTestArray0[12] = {L'A',L'B',L'\a',L'\b',L'\t',L'\r',L'\v',L'\f',L'\n',L'\"',L'\'',L'\u00c2'};
		CxAssert((Int32Value(x_sb->get_Length())).Equals((Int32)0));
		x_sb = (new StringBuilder(100));
		CxAssert((Int32Value(x_sb->get_Capacity())).Equals(100));
		x_sb = (new StringBuilder((new String((Char*)L"Test"))));
		CxAssert(((x_sb->ToString()))->Equals((new String((Char*)L"Test"))));
		x_sb = (new StringBuilder(20,25));
		CxAssert((Int32Value(x_sb->get_Capacity())).Equals(20) && (Int32Value(x_sb->get_MaxCapacity())).Equals(25));
		x_sb = (new StringBuilder((new String((Char*)L"Test")),20));
		CxAssert(((x_sb->ToString()))->Equals((new String((Char*)L"Test"))) && (Int32Value(x_sb->get_Capacity())).Equals(20));
		x_sb = (new StringBuilder((new String((Char*)L"test1234")),1,4,20));
		CxAssert(((x_sb->ToString()))->Equals((new String((Char*)L"est1"))) && (Int32Value(x_sb->get_Capacity())).Equals(20));
		String* x_a = (new StringBuilder((new String((Char*)L"Test"))))->ToString();
		CxAssert(((x_a))->Equals((new String((Char*)L"Test"))));
		String* x_b = (new String((Char*)L"AB\a\b\t\r\v\f\n\"'\u00c2"));
		Array* x_value = (new Array(CharType,12))->Initialize((Char*) DoSBConstructTestArray0);
		x_sb = (new StringBuilder());
		x_sb->Append(x_value);
		String* x_text = x_sb->ToString();
		CxAssert(((x_sb->ToString()))->Equals(x_b));
	}
	void StringBuilderTest::DoSBPropertyTest()
	{
		x_sb = (new StringBuilder((new String((Char*)L"Testing123")),0,10,20));
		CxAssert((Int32Value(x_sb->get_Capacity())).Equals(20) && (Int32Value(x_sb->get_MaxCapacity())).Equals(Int32Value::MaxValue));
		CxAssert((CharValue(((*((Char*)x_sb->Address(7)))))).Equals(L'1'));
		CxAssert((Int32Value(x_sb->get_Length())).Equals(10));
		x_sb->set_Length(7);
		CxAssert((Int32Value(x_sb->get_Length())).Equals(7));
		x_sb->set_Capacity(22);
		CxAssert((Int32Value(x_sb->get_Capacity())).Equals(22));
		((*((Char*)x_sb->Address(0)))) = L't';
		CxAssert(((x_sb->ToString()))->Equals((new String((Char*)L"testing"))));
	}
	void StringBuilderTest::DoSBAppendTest()
	{
		static Char DoSBAppendTestArray0[4] = {L'0',L'1',L'2',L'3'};
		static Object* DoSBAppendTestArray1[4] = {new Int32Value(0),new Int32Value(1),new Int32Value(2),new Int32Value(3)};
		x_sb->set_Length(0);
		x_sb->Append(true);
		CxAssert(((x_sb->ToString()))->Equals((new String((Char*)L"True"))));
		CxAssert(((x_sb->Append(L'A')->ToString()))->Equals((new String((Char*)L"TrueA"))));
		Array* x_value = (new Array(CharType,4))->Initialize((Char*) DoSBAppendTestArray0);
		CxAssert(((x_sb->Append(x_value)->ToString()))->Equals((new String((Char*)L"TrueA0123"))));
		x_sb->set_Length(0);
		Double x_value2 = 3.14159;
		CxAssert(((x_sb->Append(x_value2)->ToString()))->Equals((new String((Char*)L"3.14159"))));
		x_sb->set_Length(0);
		Int32 x_value3 = 666;
		CxAssert(((x_sb->Append(x_value3)->ToString()))->Equals((new String((Char*)L"666"))));
		x_sb->set_Length(0);
		Int64 x_value4 = 666666666;
		CxAssert(((x_sb->Append(x_value4)->ToString()))->Equals((new String((Char*)L"666666666"))));
		x_sb->set_Length(0);
		Object* x_obj = new Int32Value(1);
		CxAssert(((x_sb->Append(x_obj)->ToString()))->Equals((new String((Char*)L"1"))));
		x_sb->set_Length(0);
		CxAssert(((x_sb->Append((new String((Char*)L"fred")))->ToString()))->Equals((new String((Char*)L"fred"))));
		UInt32 x_value5 = 777;
		x_sb->set_Length(0);
		CxAssert(((x_sb->Append(x_value5)->ToString()))->Equals((new String((Char*)L"777"))));
		x_sb->set_Length(0);
		CxAssert(((x_sb->Append(L'A',4)->ToString()))->Equals((new String((Char*)L"AAAA"))));
		x_sb->set_Length(0);
		CxAssert(((x_sb->Append(x_value,1,3)->ToString()))->Equals((new String((Char*)L"123"))));
		x_sb->set_Length(0);
		CxAssert(((x_sb->Append((new String((Char*)L"3210")),1,3)->ToString()))->Equals((new String((Char*)L"210"))));
		x_sb->set_Length(0);
		CxAssert(((x_sb->AppendFormat((new String((Char*)L"x={0}")),x_obj)->ToString()))->Equals((new String((Char*)L"x=1"))));
		Array* x_array = (new Array(ObjectType,4))->Initialize((Object*) DoSBAppendTestArray1);
		x_sb->set_Length(0);
		CxAssert(((x_sb->AppendFormat((new String((Char*)L"y={0}{1}{2}{3}")),x_array)->ToString()))->Equals((new String((Char*)L"y=0123"))));
		x_sb->set_Length(0);
		CxAssert(((x_sb->AppendFormat((new String((Char*)L"y={0}{1}")),((*((Object**)x_array->Address(0)))),((*((Object**)x_array->Address(1)))))->ToString()))->Equals((new String((Char*)L"y=01"))));
		x_sb->set_Length(0);
		CxAssert(((x_sb->AppendFormat((new String((Char*)L"y={0}{1}{2}")),((*((Object**)x_array->Address(0)))),((*((Object**)x_array->Address(1)))),((*((Object**)x_array->Address(2)))))->ToString()))->Equals((new String((Char*)L"y=012"))));
		x_sb->set_Length(0);
		CxAssert(((x_sb->Append(L'A')->ToString()))->Equals((new String((Char*)L"A"))));
		Object* x_value6 = (new String((Char*)L"Test string as Object"));
		x_sb->set_Length(0);
		CxAssert(((x_sb->Append(x_value6)->ToString()))->Equals((new String((Char*)L"Test string as Object"))));
		TestAbstract* x_value7 = (new TestAbstract());
		x_sb->set_Length(0);
		CxAssert(((x_sb->Append(x_value7)->ToString()))->Equals((new String((Char*)L"TestAbstract"))));
	}
	void StringBuilderTest::DoSBMiscTest()
	{
		x_sb->set_Length(0);
		x_sb->set_Capacity(10);
		x_sb->EnsureCapacity(30);
		CxAssert(x_sb->get_Capacity() >= 30);
		x_sb->Append((new String((Char*)L"Test")));
		StringBuilder* x_stringBuilder = (new StringBuilder((new String((Char*)L"Test"))));
		x_stringBuilder->set_Capacity(10);
		x_stringBuilder->EnsureCapacity(30);
		CxAssert(x_sb->Equals(x_stringBuilder));
		x_sb->set_Length(0);
		x_sb->Append((new String((Char*)L"1234567890")));
		x_sb->Remove(1,4);
		CxAssert(((x_sb->ToString()))->Equals((new String((Char*)L"167890"))));
		x_sb->set_Length(0);
		x_sb->Append((new String((Char*)L"1234567890")));
		CxAssert(((x_sb->ToString(1,8)))->Equals((new String((Char*)L"23456789"))));
	}
	void StringBuilderTest::DoSBInsertTest()
	{
		static Char DoSBInsertTestArray0[4] = {L'0',L'1',L'2',L'3'};
		String* x_value = (new String((Char*)L"{}"));
		x_sb->set_Length(0);
		x_sb->Append(x_value);
		x_sb->Insert(1,true);
		CxAssert(((x_sb->ToString()))->Equals((new String((Char*)L"{True}"))));
		CxAssert(((x_sb->Insert(5,L'A')->ToString()))->Equals((new String((Char*)L"{TrueA}"))));
		Array* x_value2 = (new Array(CharType,4))->Initialize((Char*) DoSBInsertTestArray0);
		CxAssert(((x_sb->Insert(6,x_value2)->ToString()))->Equals((new String((Char*)L"{TrueA0123}"))));
		x_sb->set_Length(0);
		x_sb->Append(x_value);
		Double x_value3 = 3.14159;
		CxAssert(((x_sb->Insert(1,x_value3)->ToString()))->Equals((new String((Char*)L"{3.14159}"))));
		x_sb->set_Length(0);
		x_sb->Append(x_value);
		Int32 x_value4 = 666;
		CxAssert(((x_sb->Insert(1,x_value4)->ToString()))->Equals((new String((Char*)L"{666}"))));
		x_sb->set_Length(0);
		x_sb->Append(x_value);
		Int64 x_value5 = 666666666;
		CxAssert(((x_sb->Insert(1,x_value5)->ToString()))->Equals((new String((Char*)L"{666666666}"))));
		x_sb->set_Length(0);
		x_sb->Append(x_value);
		Object* x_value6 = new Int32Value(1);
		CxAssert(((x_sb->Insert(1,x_value6)->ToString()))->Equals((new String((Char*)L"{1}"))));
		x_sb->set_Length(0);
		x_sb->Append(x_value);
		CxAssert(((x_sb->Insert(1,(new String((Char*)L"fred")))->ToString()))->Equals((new String((Char*)L"{fred}"))));
		UInt32 x_value7 = 777;
		x_sb->set_Length(0);
		x_sb->Append(x_value);
		CxAssert(((x_sb->Insert(1,x_value7)->ToString()))->Equals((new String((Char*)L"{777}"))));
		x_sb->set_Length(0);
		x_sb->Append(x_value);
		CxAssert(((x_sb->Insert(1,(new String((Char*)L"A")),4)->ToString()))->Equals((new String((Char*)L"{AAAA}"))));
		x_sb->set_Length(0);
		x_sb->Append(x_value);
		CxAssert(((x_sb->Insert(1,x_value2,1,3)->ToString()))->Equals((new String((Char*)L"{123}"))));
	}
	void StringBuilderTest::DoSBReplaceTest()
	{
		x_sb->set_Length(0);
		x_sb->Append((new String((Char*)L"aaaaaaa")));
		CxAssert(((x_sb->Replace(L'a',L'A')->ToString()))->Equals((new String((Char*)L"AAAAAAA"))));
		CxAssert(((x_sb->Replace((new String((Char*)L"AA")),(new String((Char*)L"BBB")))->ToString()))->Equals((new String((Char*)L"BBBBBBBBBA"))));
		CxAssert(((x_sb->Replace(L'B',L'C',1,7)->ToString()))->Equals((new String((Char*)L"BCCCCCCCBA"))));
		CxAssert(((x_sb->Replace((new String((Char*)L"CCC")),(new String((Char*)L"DDD")),2,5)->ToString()))->Equals((new String((Char*)L"BCDDDCCCBA"))));
		x_sb->set_Length(0);
		x_sb->Append((new String((Char*)L"aaaaaaa")));
		String* x_a = x_sb->Replace((new String((Char*)L"aa")),(new String((Char*)L"BBB")),1,5)->ToString();
		CxAssert(((x_a))->Equals((new String((Char*)L"aBBBBBBaa"))));
	}
	void StringBuilderTest::CxAssert(Boolean x_x)
	{
		if ( !x_x )
		{
			x_caBlock->TestFailed((new String((Char*)L"StringBuilder TestFailed")));
		}
	}
	void StringBuilderTest::CxAssert(Boolean x_x,Boolean x_y)
	{
		if ( !(BooleanValue(x_x)).Equals(x_y) )
		{
			x_caBlock->TestFailed((new String((Char*)L"StringBuilder TestFailed")));
		}
	}
	StringBuilderTest::StringBuilderTest()
	{
	}
	StringTest::StringTest(CABlock* x_caBlock)
	{
		this->x_caBlock = x_caBlock;
	}
	void StringTest::Test()
	{
		x_caBlock->Send((new String((Char*)L"Doing StringTest")));
		x_caBlock->Send((new String((Char*)L"\tDoing DoIndexTest")));
		DoIndexTest();
		x_caBlock->Send((new String((Char*)L"\tDoing DoMiscTest")));
		DoMiscTest();
		x_caBlock->Send((new String((Char*)L"\tDoing DoEqualsTest")));
		DoEqualsTest();
		x_caBlock->Send((new String((Char*)L"\tDoing DoParsingTest")));
		DoParsingTest();
		x_caBlock->Send((new String((Char*)L"\tDoing DoConcatTest")));
		DoConcatTest();
	}
	void StringTest::DoIndexTest()
	{
		String* x_text = (new String((Char*)L"12345"));
		CxAssert((Int32Value(x_text->get_Length())).Equals(5));
		CxAssert((CharValue(((*((Char*)x_text->Address(0)))))).Equals(L'1'));
		CxAssert((CharValue(((*((Char*)x_text->Address(1)))))).Equals(L'2'));
		CxAssert((CharValue(((*((Char*)x_text->Address(2)))))).Equals(L'3'));
		CxAssert((CharValue(((*((Char*)x_text->Address(3)))))).Equals(L'4'));
		CxAssert((CharValue(((*((Char*)x_text->Address(4)))))).Equals(L'5'));
	}
	void StringTest::DoMiscTest()
	{
		static Object* DoMiscTestArray0[3] = {new Int32Value(1),new Int32Value(2),new Int32Value(3)};
		String* x_text = (new String(L' ',10));
		CxAssert((Int32Value(x_text->get_Length())).Equals(10));
		String* x_text2 = (new String((Char*)L"12345"));
		Array* x_array = (new Array(CharType,30));
		x_text2->CopyTo(0,x_array,0,x_text2->get_Length());
		Int32 x_num = 0;
		String* x_text3 = x_text2;
		foreach (Char x_c in x_text3 )
		{
			CxAssert((CharValue(((*((Char*)x_array->Address(x_num)))))).Equals(x_c));
			x_num++;
		}
		x_array = x_text2->ToCharArray();
		CxAssert(x_array != nullptr && (Int32Value(x_array->get_Length())).Equals(x_text2->get_Length()));
		String* x_a = (new String(x_array));
		CxAssert(((x_a))->Equals(x_text2));
		String* x_a2 = (new String(x_array,0,2));
		CxAssert(((x_a2))->Equals((new String((Char*)L"12"))));
		CxAssert(!((x_a2))->Equals((new String((Char*)L"22"))));
		CxAssert(!( ((x_a2))->Equals((new String((Char*)L"22"))) ));
		x_a2 = (new String(x_text2->ToCharArray(),0,x_text2->get_Length()));
		CxAssert(((x_a2))->Equals(x_text2));
		CxAssert((Int32Value(String::Compare((new String((Char*)L"abc")),(new String((Char*)L"ABC")),true))).Equals((Int32)0));
		CxAssert((Int32Value(String::Compare((new String((Char*)L"1abce")),1,(new String((Char*)L"abc")),0,3))).Equals((Int32)0));
		CxAssert((Int32Value(String::Compare((new String((Char*)L"1abce")),1,(new String((Char*)L"ABC")),0,3,true))).Equals((Int32)0));
		CxAssert((Int32Value(String::CompareOrdinal((new String((Char*)L"abc")),(new String((Char*)L"abc"))))).Equals((Int32)0));
		CxAssert((Int32Value(String::CompareOrdinal((new String((Char*)L"1abce")),1,(new String((Char*)L"abc")),0,3))).Equals((Int32)0));
		x_a2 = String::Copy(x_text2);
		CxAssert(((x_a2))->Equals(x_text2));
		x_a2 = String::Format((new String((Char*)L"1 = {{{0,-4}}} 2 = {1,4} 3 = {2}!")),new Int32Value(1),new Int32Value(2),new Int32Value(3));
		CxAssert(((x_a2))->Equals((new String((Char*)L"1 = {1   } 2 =    2 3 = 3!"))));
		String* x_a3 = x_a2->ToString();
		CxAssert(((x_a3))->Equals((new String((Char*)L"1 = {1   } 2 =    2 3 = 3!"))));
		String* x_empty = String::Empty;
		CxAssert(!((x_empty))->Equals(nullptr) && ((x_empty))->Equals((new String((Char*)L""))));
		x_a2 = String::Format((new String((Char*)L"1 = {{{0,-4}}} 2 = {1,4}!")),new Int32Value(1),new Int32Value(2));
		CxAssert(((x_a2))->Equals((new String((Char*)L"1 = {1   } 2 =    2!"))));
		x_a2 = String::Format((new String((Char*)L"1 = {{{0,-4}}}!")),new Int32Value(1));
		CxAssert(((x_a2))->Equals((new String((Char*)L"1 = {1   }!"))));
		Array* x_args = (new Array(ObjectType,3))->Initialize((Object*) DoMiscTestArray0);
		x_a2 = String::Format((new String((Char*)L"1 = {{{0,-4}}} 2 = {1,4} 3 = {2}!")),x_args);
		CharEnumerator* x_enumerator = x_a2->GetEnumerator();
		Int32 x_num2 = 0;
		while (x_enumerator->MoveNext() )
		{
			Char x_current = x_enumerator->get_Current();
			CxAssert((CharValue(x_current)).Equals(((*((Char*)x_a2->Address(x_num2++))))));
		}
		x_enumerator->Reset();
		Double x_num3 = 2;
		String* x_text4 = x_text2->Combine(x_empty) + new Int32Value(x_num2) + new DoubleValue(x_num3) + new Int32Value(x_num);
		StringTest::TestConcat(x_text2,x_num,x_empty,x_num2,x_num3);
		String* x_a4 = (new String((Char*)L"\""));
		CxAssert(((x_a4))->Equals((new String((Char*)L"\""))));
		x_a4 = (new String((Char*)L"c:\\Retest"));
		CxAssert(((x_a4))->Equals((new String((Char*)L"c:\\Retest"))));
		x_a4 = (new String((Char*)L"c:\\Retest"));
		CxAssert(((x_a4))->Equals((new String((Char*)L"c:\\Retest"))));
	}
	void StringTest::TestConcat(String* x_str1,Int32 x_index,String* x_str4,Int32 x_i,Double x_dbl)
	{
		String* x_text = x_str1->Combine(x_str4) + new Int32Value(x_i) + new DoubleValue(x_dbl) + new Int32Value(x_index);
	}
	void StringTest::DoEqualsTest()
	{
		String* x_text = (new String((Char*)L"12345"));
		CxAssert(String::Equals(x_text,(new String((Char*)L"12345"))));
		CxAssert(((x_text))->Equals((new String((Char*)L"12345"))));
		CxAssert(x_text->Equals(x_text));
		CxAssert(x_text->Equals(x_text));
	}
	void StringTest::DoParsingTest()
	{
		static Char DoParsingTestArray0[4] = {L' ',L',',L'.',L':'};
		static Char DoParsingTestArray1[2] = {L'3',L'4'};
		static String* DoParsingTestArray2[3] = {(new String((Char*)L"1")),(new String((Char*)L"2")),(new String((Char*)L"3"))};
		String* x_text = (new String((Char*)L"12 34 56"));
		Array* x_array = x_text->Split(nullptr);
		CxAssert((Int32Value(x_array->get_Length())).Equals(3));
		CxAssert((((new String((Char*)L"12"))))->Equals(((*((String**)x_array->Address(0))))));
		CxAssert((((new String((Char*)L"34"))))->Equals(((*((String**)x_array->Address(1))))));
		CxAssert((((new String((Char*)L"56"))))->Equals(((*((String**)x_array->Address(2))))));
		String* x_text2 = (new String((Char*)L"42, 12, 19"));
		Array* x_separator = (new Array(CharType,4))->Initialize((Char*) DoParsingTestArray0);
		x_array = x_text2->Split(x_separator);
		CxAssert((Int32Value(x_array->get_Length())).Equals(5));
		CxAssert((((new String((Char*)L"42"))))->Equals(((*((String**)x_array->Address(0))))));
		CxAssert((((new String((Char*)L""))))->Equals(((*((String**)x_array->Address(1))))));
		CxAssert((((new String((Char*)L"12"))))->Equals(((*((String**)x_array->Address(2))))));
		CxAssert((((new String((Char*)L""))))->Equals(((*((String**)x_array->Address(3))))));
		CxAssert((((new String((Char*)L"19"))))->Equals(((*((String**)x_array->Address(4))))));
		x_array = x_text2->Split(x_separator,2);
		CxAssert((Int32Value(x_array->get_Length())).Equals(2));
		CxAssert((((new String((Char*)L"42"))))->Equals(((*((String**)x_array->Address(0))))));
		CxAssert((((new String((Char*)L" 12, 19"))))->Equals(((*((String**)x_array->Address(1))))));
		String* x_b = x_text->Substring(3);
		CxAssert((((new String((Char*)L"34 56"))))->Equals(x_b));
		x_b = x_text->Substring(3,2);
		CxAssert((((new String((Char*)L"34"))))->Equals(x_b));
		String* x_text3 = (new String((Char*)L"  12345  "));
		String* x_b2 = x_text3->Trim();
		CxAssert((((new String((Char*)L"12345"))))->Equals(x_b2));
		String* x_text4 = (new String((Char*)L"*;|@123***456@|;*"));
		String* x_text5 = (new String((Char*)L"*;|@"));
		Array* x_trimChars = x_text5->ToCharArray();
		x_b2 = x_text4->Trim(x_trimChars);
		CxAssert((((new String((Char*)L"123***456"))))->Equals(x_b2));
		x_b2 = x_text3->TrimStart();
		CxAssert((((new String((Char*)L"12345  "))))->Equals(x_b2));
		x_b2 = x_text4->TrimStart(x_trimChars);
		CxAssert((((new String((Char*)L"123***456@|;*"))))->Equals(x_b2));
		x_b2 = x_text3->TrimEnd();
		CxAssert((((new String((Char*)L"  12345"))))->Equals(x_b2));
		x_b2 = x_text4->TrimEnd(x_trimChars);
		CxAssert((((new String((Char*)L"*;|@123***456"))))->Equals(x_b2));
		Int32 x_num = String::Compare(x_text,x_text3);
		CxAssert(x_num > 0);
		x_num = x_text3->CompareTo(x_text);
		CxAssert(x_num < 0);
		x_num = x_text3->CompareTo(x_text);
		CxAssert(x_num < 0);
		CxAssert(x_text->EndsWith((new String((Char*)L"56"))));
		Array* x_array2 = (new Array(CharType,2))->Initialize((Char*) DoParsingTestArray1);
		CxAssert((Int32Value(x_text->IndexOfAny(x_array2))).Equals(3));
		CxAssert((Int32Value(x_text->IndexOfAny(x_array2,1))).Equals(3));
		CxAssert((Int32Value(x_text->IndexOfAny(x_array2,1,3))).Equals(3));
		CxAssert((Int32Value(x_text->IndexOf(L'5'))).Equals(6));
		CxAssert((Int32Value(x_text->IndexOf(L' ',3))).Equals(5));
		CxAssert((Int32Value(x_text->IndexOf(L' ',3,3))).Equals(5));
		CxAssert((Int32Value(x_text->IndexOf((new String((Char*)L"56"))))).Equals(6));
		CxAssert((Int32Value(x_text->IndexOf((new String((Char*)L" ")),3))).Equals(5));
		CxAssert((Int32Value(x_text->IndexOf((new String((Char*)L" ")),3,3))).Equals(5));
		String* x_text6 = (new String((Char*)L"11223311"));
		CxAssert((Int32Value(x_text6->LastIndexOf(L'1'))).Equals(7));
		CxAssert((Int32Value(x_text6->LastIndexOf(L'1',4))).Equals(1));
		CxAssert((Int32Value(x_text6->LastIndexOf(L'1',4,4))).Equals(1));
		CxAssert((Int32Value(x_text6->LastIndexOf((new String((Char*)L"11"))))).Equals(6));
		CxAssert((Int32Value(x_text6->LastIndexOf((new String((Char*)L"11")),4))).Equals((Int32)0));
		CxAssert((Int32Value(x_text6->LastIndexOf((new String((Char*)L"11")),4,5))).Equals((Int32)0));
		((*((Char*)x_array2->Address(0)))) = L'1';
		((*((Char*)x_array2->Address(1)))) = L'2';
		CxAssert((Int32Value(x_text6->LastIndexOfAny(x_array2))).Equals(7));
		CxAssert((Int32Value(x_text6->LastIndexOfAny(x_array2,4))).Equals(3));
		CxAssert((Int32Value(x_text6->LastIndexOfAny(x_array2,4,4))).Equals(3));
		String* x_a = x_text6->PadLeft(3 + x_text6->get_Length());
		CxAssert(((x_a))->Equals((new String((Char*)L"   11223311"))));
		x_a = x_text6->PadLeft(3 + x_text6->get_Length(),L'-');
		CxAssert(((x_a))->Equals((new String((Char*)L"---11223311"))));
		x_a = x_text6->PadRight(3 + x_text6->get_Length());
		CxAssert(((x_a))->Equals((new String((Char*)L"11223311   "))));
		x_a = x_text6->PadRight(3 + x_text6->get_Length(),L'-');
		CxAssert(((x_a))->Equals((new String((Char*)L"11223311---"))));
		CxAssert(x_text6->StartsWith((new String((Char*)L"1122"))));
		CxAssert(((x_text6->Replace(L'1',L'x')))->Equals((new String((Char*)L"xx2233xx"))));
		CxAssert(((x_text6->Replace((new String((Char*)L"1")),(new String((Char*)L"x")))))->Equals((new String((Char*)L"xx2233xx"))));
		CxAssert(((x_text6->Replace((new String((Char*)L"11")),(new String((Char*)L"x")))))->Equals((new String((Char*)L"x2233x"))));
		CxAssert(((x_text6->Remove(2,2)))->Equals((new String((Char*)L"113311"))));
		CxAssert((((new String((Char*)L"aaAAaaAA"))->ToUpper()))->Equals((new String((Char*)L"AAAAAAAA"))));
		CxAssert((((new String((Char*)L"aaAAaaAA"))->ToLower()))->Equals((new String((Char*)L"aaaaaaaa"))));
		Array* x_value = (new Array(StringType,3))->Initialize((String*) DoParsingTestArray2);
		CxAssert(((String::Join((new String((Char*)L",")),x_value)))->Equals((new String((Char*)L"1,2,3"))));
		CxAssert(((String::Join((new String((Char*)L",")),x_value,1,2)))->Equals((new String((Char*)L"2,3"))));
		x_text6 = x_text->Insert(3,(new String((Char*)L"111")));
		CxAssert(((x_text6))->Equals((new String((Char*)L"12 11134 56"))));
		String* x_text7 = (new String((Char*)L"3.33"));
		if ( !(Int32Value(x_text7->CompareTo((new String((Char*)L"3.33"))))).Equals((Int32)0) )
		{
			CxAssert(false);
		}
	}
	void StringTest::DoConcatTest()
	{
		static Object* DoConcatTestArray0[4] = {(new String((Char*)L"1 ")),(new String((Char*)L"2 ")),(new String((Char*)L"3 ")),(new String((Char*)L"4"))};
		static String* DoConcatTestArray1[4] = {(new String((Char*)L"1 ")),(new String((Char*)L"2 ")),(new String((Char*)L"3 ")),(new String((Char*)L"4"))};
		Array* x_array = (new Array(ObjectType,4))->Initialize((Object*) DoConcatTestArray0);
		String* x_a = String::Concat(((*((Object**)x_array->Address(0)))));
		CxAssert(((x_a))->Equals((new String((Char*)L"1 "))));
		x_a = String::Concat(x_array);
		CxAssert(((x_a))->Equals((new String((Char*)L"1 2 3 4"))));
		Array* x_array2 = (new Array(StringType,4))->Initialize((String*) DoConcatTestArray1);
		x_a = String::Concat(x_array2);
		CxAssert(((x_a))->Equals((new String((Char*)L"1 2 3 4"))));
		x_a = String::Concat(((*((Object**)x_array->Address(0)))),((*((Object**)x_array->Address(1)))));
		CxAssert(((x_a))->Equals((new String((Char*)L"1 2 "))));
		x_a = ((*((String**)x_array2->Address(0))))->Combine(((*((String**)x_array2->Address(1)))));
		CxAssert(((x_a))->Equals((new String((Char*)L"1 2 "))));
		x_a = String::Concat(((*((Object**)x_array->Address(0)))),((*((Object**)x_array->Address(1)))),((*((Object**)x_array->Address(2)))));
		CxAssert(((x_a))->Equals((new String((Char*)L"1 2 3 "))));
		x_a = ((*((String**)x_array2->Address(0))))->Combine(((*((String**)x_array2->Address(1))))) + ((*((String**)x_array2->Address(2))));
		CxAssert(((x_a))->Equals((new String((Char*)L"1 2 3 "))));
		x_a = ((*((String**)x_array2->Address(0))))->Combine(((*((String**)x_array2->Address(1))))) + ((*((String**)x_array2->Address(2)))) + ((*((String**)x_array2->Address(3))));
		CxAssert(((x_a))->Equals((new String((Char*)L"1 2 3 4"))));
	}
	void StringTest::CxAssert(Boolean x_x)
	{
		if ( !x_x )
		{
			x_caBlock->TestFailed((new String((Char*)L"String TestFailed")));
		}
	}
	StringTest::StringTest()
	{
	}
	TimeTest::TimeTest(CABlock* x_caBlock)
	{
		x_dat1 = DateTime::get_Now();
		this->x_caBlock = x_caBlock;
	}
	void TimeTest::Test()
	{
		x_caBlock->Send((new String((Char*)L"Doing TimeTest")));
		x_caBlock->Send((new String((Char*)L"\tDoing TestTimeSpan")));
		TestTimeSpan();
		x_caBlock->Send((new String((Char*)L"\tDoing TestDateTime")));
		TestDateTime();
		x_caBlock->Send((new String((Char*)L"\tDoing DateTimeMethodTests")));
		DateTimeMethodTests();
		x_caBlock->Send((new String((Char*)L"\tDoing TimeArrayTests")));
		TimeArrayTests();
	}
	void TimeTest::TestTimeSpan()
	{
		TimeSpan x_timeSpan = (TimeSpan(100));
		TimeSpan x_timeSpan2 = x_timeSpan.Add(x_timeSpan);
		CxAssert((Int64Value(x_timeSpan2.get_Ticks())).Equals(200));
		CxAssert(TimeSpan::Compare(x_timeSpan,x_timeSpan2) < 0);
		CxAssert(x_timeSpan.CompareTo(new TimeSpanValue(x_timeSpan2)) < 0);
		CxAssert(x_timeSpan.CompareTo(x_timeSpan2) < 0);
		x_timeSpan = x_timeSpan2.Duration();
		CxAssert((Int64Value(x_timeSpan.get_Ticks())).Equals(200));
		CxAssert(TimeSpan::Equals(x_timeSpan,x_timeSpan2));
		CxAssert(x_timeSpan.Equals(x_timeSpan2));
		CxAssert((Int64Value(TimeSpan::FromDays(22).get_Ticks())).Equals(19008000000000));
		CxAssert((Int64Value(TimeSpan::FromHours(10).get_Ticks())).Equals(360000000000));
		CxAssert((Int64Value(TimeSpan::FromMilliseconds(100).get_Ticks())).Equals(1000000));
		CxAssert((Int64Value(TimeSpan::FromMinutes(25).get_Ticks())).Equals(15000000000));
		CxAssert((Int64Value(TimeSpan::FromSeconds(18).get_Ticks())).Equals(180000000));
		x_timeSpan = TimeSpan::FromTicks(6500000);
		CxAssert((Int64Value(x_timeSpan.get_Ticks())).Equals(6500000));
		x_timeSpan = x_timeSpan.Negate();
		CxAssert((Int64Value(x_timeSpan.get_Ticks())).Equals(-6500000));
		CxAssert((Int64Value(x_timeSpan.Subtract(x_timeSpan2).get_Ticks())).Equals(-6500200));
		CxAssert((Int64Value(TimeSpan::Parse((new String((Char*)L"1.1:1:1"))).get_Ticks())).Equals(900610000000));
		CxAssert((Int64Value(TimeSpan::Parse((new String((Char*)L"1.1:1:1.200"))).get_Ticks())).Equals(900612000000));
		CxAssert((Int64Value(TimeSpan::Parse((new String((Char*)L"1:1:1"))).get_Ticks())).Equals(36610000000));
		CxAssert((Int64Value(TimeSpan::Parse((new String((Char*)L"22"))).get_Ticks())).Equals(19008000000000));
		x_timeSpan = TimeSpan::Parse((new String((Char*)L"1.2:3:4.200")));
		String* x_a = x_timeSpan.ToString();
		CxAssert(((x_a))->Equals((new String((Char*)L"1.02:03:04.2000000"))));
		CxAssert((Int32Value(x_timeSpan.get_Days())).Equals(1));
		CxAssert((Int32Value(x_timeSpan.get_Hours())).Equals(2));
		CxAssert((Int32Value(x_timeSpan.get_Minutes())).Equals(3));
		CxAssert((Int32Value(x_timeSpan.get_Seconds())).Equals(4));
		CxAssert((Int32Value(x_timeSpan.get_Milliseconds())).Equals(200));
		CxAssert((Int64Value(x_timeSpan.get_Ticks())).Equals(937842000000));
		CxAssert(x_timeSpan.get_TotalDays(),1.08546527777778);
		CxAssert(x_timeSpan.get_TotalHours(),26.0511666666667);
		CxAssert(x_timeSpan.get_TotalMinutes(),1563.07);
		CxAssert(x_timeSpan.get_TotalSeconds(),93784.2);
		CxAssert(x_timeSpan.get_TotalMilliseconds(),93784200);
		CxAssert((Int64Value(( x_timeSpan2 + x_timeSpan2 ).get_Ticks())).Equals(400));
		x_timeSpan = x_timeSpan2;
		CxAssert(((x_timeSpan)).Equals(x_timeSpan2));
		CxAssert(!( !((x_timeSpan)).Equals(x_timeSpan2) ));
		x_timeSpan = (TimeSpan(100));
		CxAssert(!( x_timeSpan > x_timeSpan2 ));
		CxAssert(!( x_timeSpan >= x_timeSpan2 ));
		CxAssert(!( x_timeSpan2 < x_timeSpan ));
		CxAssert(!( x_timeSpan2 <= x_timeSpan ));
		CxAssert(((x_timeSpan)).Equals(x_timeSpan));
		x_timeSpan = x_timeSpan2 - x_timeSpan;
		CxAssert((Int64Value(x_timeSpan.get_Ticks())).Equals(100));
		x_timeSpan = -x_timeSpan;
		CxAssert((Int64Value(x_timeSpan.get_Ticks())).Equals(-100));
		CxAssert((Int64Value(( +x_timeSpan ).get_Ticks())).Equals(-100));
		CxAssert((Int64Value((TimeSpan(1000)).get_Ticks())).Equals(1000));
		CxAssert((Int64Value((TimeSpan(10,11,30)).get_Ticks())).Equals(366900000000));
		CxAssert((Int64Value((TimeSpan(3,10,11,30)).get_Ticks())).Equals(2958900000000));
		CxAssert((Int64Value((TimeSpan(3,10,11,30,100)).get_Ticks())).Equals(2958901000000));
		CxAssert((Int64Value((TimeSpan(3,10,11,30,100)).get_Ticks())).Equals(2958901000000));
		x_timeSpan = (TimeSpan(71,3,12,13));
		CxAssert((Int64Value(x_timeSpan.get_Ticks())).Equals(61459330000000));
		String* x_text = x_timeSpan.ToString();
		CxAssert(x_text->Equals((new String((Char*)L"71.03:12:13"))));
		x_timeSpan = (TimeSpan(-71,3,12,13));
		CxAssert((Int64Value(x_timeSpan.get_Ticks())).Equals(-61228670000000));
		String* x_text2 = x_timeSpan.ToString();
		CxAssert(x_text2->Equals((new String((Char*)L"-70.20:47:47"))));
		x_timeSpan = TimeSpan::Parse((new String((Char*)L"-71.03:12:13")));
		CxAssert((Int64Value(x_timeSpan.get_Ticks())).Equals(-61459330000000));
		String* x_text3 = x_timeSpan.ToString();
		CxAssert(x_text3->Equals((new String((Char*)L"-71.03:12:13"))));
		Object* x_obj = TimeSpan::MinValue;
		CxAssert((Int64Value(( x_obj->get_AsTimeSpan() ).get_Ticks())).Equals(TimeSpan::MinValue.get_Ticks()));
		TimeSpan x_minValue = TimeSpan::MinValue;
		CxAssert(x_minValue.Equals(x_obj));
		CxAssert((Int32Value(TimeSpan::MinValue.CompareTo(x_obj))).Equals((Int32)0));
		Int64 x_num = 864000000000;
		CxAssert((Int64Value(864000000000)).Equals(x_num));
		x_num = 36000000000;
		CxAssert((Int64Value(36000000000)).Equals(x_num));
		x_num = 600000000;
		CxAssert((Int32Value(600000000)).Equals(x_num));
		x_num = 10000000;
		CxAssert((Int32Value(10000000)).Equals(x_num));
		x_num = 10000;
		CxAssert((Int32Value(10000)).Equals(x_num));
		CxAssert(((TimeSpan::Zero)).Equals(TimeSpan::Zero));
		CxAssert(((TimeSpan::MaxValue)).Equals(TimeSpan::MaxValue));
		CxAssert(x_obj->Equals(TimeSpan::MinValue));
		String* x_a2 = x_obj->ToString();
		x_minValue = TimeSpan::MinValue;
		CxAssert(((x_a2))->Equals(x_minValue.ToString()));
	}
	void TimeTest::TestDateTime()
	{
		CxAssert((Int64Value(DateTime().get_Ticks())).Equals((Int64)0));
		CxAssert((Int64Value((DateTime(1200)).get_Ticks())).Equals(1200));
		CxAssert((Int64Value((DateTime(2003,7,23)).get_Ticks())).Equals(631945152000000000));
		CxAssert((Int64Value((DateTime(2003,7,23,12,30,30)).get_Ticks())).Equals(631945602300000000));
		DateTime x_dateTime = (DateTime(2003,7,23,12,30,30,100));
		CxAssert((Int64Value(x_dateTime.get_Ticks())).Equals(631945602301000000));
		CxAssert((Int64Value(x_dateTime.get_Date().get_Ticks())).Equals(631945152000000000));
		Int32 x_day = x_dateTime.get_Day();
		CxAssert((Int32Value(x_day)).Equals(23));
		DayOfWeek x_dayOfWeek = x_dateTime.get_DayOfWeek();
		CxAssert(x_dayOfWeek == Wednesday_DayOfWeek);
		Int32 x_dayOfYear = x_dateTime.get_DayOfYear();
		CxAssert((Int32Value(x_dayOfYear)).Equals(204));
		Int32 x_hour = x_dateTime.get_Hour();
		CxAssert((Int32Value(x_hour)).Equals(12));
		Int32 x_millisecond = x_dateTime.get_Millisecond();
		CxAssert((Int32Value(x_millisecond)).Equals(100));
		Int32 x_minute = x_dateTime.get_Minute();
		CxAssert((Int32Value(x_minute)).Equals(30));
		Int32 x_month = x_dateTime.get_Month();
		CxAssert((Int32Value(x_month)).Equals(7));
		DateTime x_now = DateTime::get_Now();
		x_day = x_now.get_Day();
		x_dayOfYear = x_now.get_DayOfYear();
		x_dayOfWeek = x_now.get_DayOfWeek();
		x_hour = x_now.get_Hour();
		Int32 x_second = x_dateTime.get_Second();
		CxAssert((Int32Value(x_second)).Equals(30));
		CxAssert((Int64Value(x_dateTime.get_TimeOfDay().get_Ticks())).Equals(450301000000));
		DateTime x_today = DateTime::get_Today();
		x_day = x_today.get_Day();
		x_dayOfYear = x_today.get_DayOfYear();
		x_dayOfWeek = x_today.get_DayOfWeek();
		x_hour = x_today.get_Hour();
		DateTime x_utcNow = DateTime::get_UtcNow();
		x_day = x_utcNow.get_Day();
		x_dayOfYear = x_utcNow.get_DayOfYear();
		x_dayOfWeek = x_utcNow.get_DayOfWeek();
		x_hour = x_utcNow.get_Hour();
		Int32 x_year = x_dateTime.get_Year();
		CxAssert((Int32Value(x_year)).Equals(2003));
	}
	void TimeTest::DateTimeMethodTests()
	{
		DateTime x_dateTime = (DateTime(2003,7,23,12,30,30,100));
		TimeSpan x_timeSpan = (TimeSpan(0,2,0,0));
		CxAssert((Int64Value(x_dateTime.Add(x_timeSpan).get_Ticks())).Equals(631945674301000000));
		CxAssert((Int64Value(x_dateTime.AddDays(1.5).get_Ticks())).Equals(631946898301000000));
		CxAssert((Int64Value(x_dateTime.AddHours(2.5).get_Ticks())).Equals(631945692301000000));
		CxAssert((Int64Value(x_dateTime.AddMilliseconds(159).get_Ticks())).Equals(631945602302590000));
		CxAssert((Int64Value(x_dateTime.AddMinutes(3.2).get_Ticks())).Equals(631945604221000000));
		CxAssert((Int64Value(x_dateTime.AddMonths(5).get_Ticks())).Equals(632077794301000000));
		CxAssert((Int64Value(x_dateTime.AddSeconds(6.66).get_Ticks())).Equals(631945602367600000));
		CxAssert((Int64Value(x_dateTime.AddTicks(666).get_Ticks())).Equals(631945602301000666));
		DateTime x_dateTime2 = x_dateTime.AddYears(3);
		CxAssert((Int64Value(x_dateTime2.get_Ticks())).Equals(632892546301000000));
		CxAssert(DateTime::Compare(x_dateTime2,x_dateTime) > 0);
		CxAssert(x_dateTime.CompareTo(x_dateTime2) < 0);
		CxAssert((Int32Value(DateTime::DaysInMonth(2003,1))).Equals(31));
		CxAssert(!x_dateTime.Equals(x_dateTime2));
		x_dateTime2 = x_dateTime;
		CxAssert(DateTime::Equals(x_dateTime,x_dateTime2));
		CxAssert(DateTime::IsLeapYear(2004));
		x_dateTime2 = x_dateTime.Subtract(x_timeSpan);
		CxAssert((Int64Value(x_dateTime2.get_Ticks())).Equals(631945530301000000));
		CxAssert((Int64Value(x_dateTime.Subtract(x_dateTime2).get_Ticks())).Equals(72000000000));
		x_dateTime2 = x_dateTime.ToLocalTime();
		x_dateTime2 = x_dateTime.ToUniversalTime();
		x_dateTime2 = x_dateTime + x_timeSpan;
		CxAssert((Int64Value(x_dateTime2.get_Ticks())).Equals(631945674301000000));
		CxAssert(!( ((x_dateTime2)).Equals(x_dateTime) ));
		CxAssert(!( x_dateTime > x_dateTime2 ));
		CxAssert(!( x_dateTime >= x_dateTime2 ));
		CxAssert(((x_dateTime2)).Equals(x_dateTime2));
		CxAssert(!( x_dateTime2 < x_dateTime ));
		CxAssert(!( x_dateTime2 <= x_dateTime ));
		x_dateTime2 = x_dateTime - x_timeSpan;
		CxAssert((Int64Value(x_dateTime2.get_Ticks())).Equals(631945530301000000));
		CxAssert((Int64Value(( x_dateTime - x_dateTime2 ).get_Ticks())).Equals(72000000000));
		x_dateTime2 = (DateTime(2003,7,23,14,2,30,100));
		CxAssert((Int64Value(x_dateTime2.get_Ticks())).Equals(631945657501000000));
		CxAssert((Int32Value(x_dateTime2.get_Hour())).Equals(14));
		String* x_text = x_dateTime2.ToString();
		CxAssert(x_text->Equals((new String((Char*)L"7/23/2003 2:02:30 PM"))));
		x_dateTime2 = (DateTime(2003,7,23,2,20,1,100));
		CxAssert((Int64Value(x_dateTime2.get_Ticks())).Equals(631945236011000000));
		CxAssert((Int32Value(x_dateTime2.get_Hour())).Equals(2));
		x_text = x_dateTime2.ToString();
		CxAssert(x_text->Equals((new String((Char*)L"7/23/2003 2:20:01 AM"))));
		CxAssert((Int64Value(DateTime::MinValue.get_Ticks())).Equals((Int64)0));
		CxAssert((Int64Value(DateTime::MaxValue.get_Ticks())).Equals(3155378975999999999));
		Object* x_obj = DateTime::MinValue;
		CxAssert((Int64Value(( x_obj->get_AsDateTime() ).get_Ticks())).Equals((Int64)0));
		CxAssert(DateTime::MinValue.Equals(x_obj));
		CxAssert((Int32Value(DateTime::MinValue.CompareTo(x_obj))).Equals((Int32)0));
		CxAssert(x_obj->Equals(DateTime::MinValue));
		CxAssert(((x_obj->ToString()))->Equals(DateTime::MinValue.ToString()));
		CxAssert(!((x_dateTime2)).Equals(x_dateTime));
	}
	void TimeTest::TimeArrayTests()
	{
		DateTimeArrayTests();
		TimeSpanArrayTests();
	}
	void TimeTest::DateTimeArrayTests()
	{
		static DateTime DateTimeArrayTestsArray0[5] = {DateTime(2000,4,6),DateTime(2000,4,7),DateTime(2000,4,8),DateTime(2000,4,9),DateTime(2000,4,10)};
		static DateTime DateTimeArrayTestsArray1[2][4] = {{DateTime(2000,4,6),DateTime(2000,4,7),DateTime(2000,4,8),DateTime(2000,4,9)},{DateTime(2000,4,10),DateTime(2000,4,11),DateTime(2000,4,12),DateTime(2000,4,13)}};
		static DateTime DateTimeArrayTestsArray2[2][2][4] = {{{DateTime(2000,4,6),DateTime(2000,4,7),DateTime(2000,4,8),DateTime(2000,4,9)},{DateTime(2000,4,10),DateTime(2000,4,11),DateTime(2000,4,12),DateTime(2000,4,13)}},{{DateTime(2000,4,14),DateTime(2000,4,15),DateTime(2000,4,16),DateTime(2000,4,17)},{DateTime(2000,4,18),DateTime(2000,4,19),DateTime(2000,4,20),DateTime(2000,4,21)}}};
		Array* x_array = (new Array(DateTimeType,5))->Initialize((DateTime*) DateTimeArrayTestsArray0);
		CxAssert((Int32Value(x_array->get_Length())).Equals(5));
		CxAssert(((((*((DateTime*)x_array->Address(3)))))).Equals((DateTime(2000,4,9))));
		CxAssert(((((*((DateTime*)x_array->Address(1)))))).Equals((DateTime(2000,4,7))));
		Array* x_array2 = (new Array(DateTimeType,2,4))->Initialize((DateTime*) DateTimeArrayTestsArray1);
		CxAssert(((((*((DateTime*)x_array2->Address(0,2)))))).Equals((DateTime(2000,4,8))));
		Array* x_array3 = (new Array(DateTimeType,2,2,4))->Initialize((DateTime*) DateTimeArrayTestsArray2);
		CxAssert(((((*((DateTime*)x_array3->Address(0,0,3)))))).Equals((DateTime(2000,4,9))));
		((*((DateTime*)x_array3->Address(0,0,3)))) = (DateTime(2000,4,27));
		CxAssert(((((*((DateTime*)x_array3->Address(0,0,3)))))).Equals((DateTime(2000,4,27))));
		x_array3->SetValue((DateTime(2000,4,28)),0,0,3);
		CxAssert(((((*((DateTime*)x_array3->Address(0,0,3)))))).Equals((DateTime(2000,4,28))));
		DateTime x_d = ((*((DateTime*)x_array->Address(2)))) = (DateTime(2000,4,27));
		CxAssert(((((*((DateTime*)x_array->Address(2)))))).Equals(x_d));
	}
	void TimeTest::TimeSpanArrayTests()
	{
		static TimeSpan TimeSpanArrayTestsArray0[5] = {TimeSpan(2000,4,6),TimeSpan(2000,4,7),TimeSpan(2000,4,8),TimeSpan(2000,4,9),TimeSpan(2000,4,10)};
		static TimeSpan TimeSpanArrayTestsArray1[2][4] = {{TimeSpan(2000,4,6),TimeSpan(2000,4,7),TimeSpan(2000,4,8),TimeSpan(2000,4,9)},{TimeSpan(2000,4,10),TimeSpan(2000,4,11),TimeSpan(2000,4,12),TimeSpan(2000,4,13)}};
		static TimeSpan TimeSpanArrayTestsArray2[2][2][4] = {{{TimeSpan(2000,4,6),TimeSpan(2000,4,7),TimeSpan(2000,4,8),TimeSpan(2000,4,9)},{TimeSpan(2000,4,10),TimeSpan(2000,4,11),TimeSpan(2000,4,12),TimeSpan(2000,4,13)}},{{TimeSpan(2000,4,14),TimeSpan(2000,4,15),TimeSpan(2000,4,16),TimeSpan(2000,4,17)},{TimeSpan(2000,4,18),TimeSpan(2000,4,19),TimeSpan(2000,4,20),TimeSpan(2000,4,21)}}};
		Array* x_array = (new Array(TimeSpanType,5))->Initialize((TimeSpan*) TimeSpanArrayTestsArray0);
		CxAssert((Int32Value(x_array->get_Length())).Equals(5));
		CxAssert(((((*((TimeSpan*)x_array->Address(3)))))).Equals((TimeSpan(2000,4,9))));
		CxAssert(((((*((TimeSpan*)x_array->Address(1)))))).Equals((TimeSpan(2000,4,7))));
		Array* x_array2 = (new Array(TimeSpanType,2,4))->Initialize((TimeSpan*) TimeSpanArrayTestsArray1);
		CxAssert(((((*((TimeSpan*)x_array2->Address(0,2)))))).Equals((TimeSpan(2000,4,8))));
		Array* x_array3 = (new Array(TimeSpanType,2,2,4))->Initialize((TimeSpan*) TimeSpanArrayTestsArray2);
		CxAssert(((((*((TimeSpan*)x_array3->Address(0,0,3)))))).Equals((TimeSpan(2000,4,9))));
		((*((TimeSpan*)x_array3->Address(0,0,3)))) = (TimeSpan(2000,4,27));
		CxAssert(((((*((TimeSpan*)x_array3->Address(0,0,3)))))).Equals((TimeSpan(2000,4,27))));
		x_array3->SetValue((TimeSpan(2000,4,28)),0,0,3);
		CxAssert(((((*((TimeSpan*)x_array3->Address(0,0,3)))))).Equals((TimeSpan(2000,4,28))));
		TimeSpan x_t = ((*((TimeSpan*)x_array->Address(2)))) = (TimeSpan(2000,4,27));
		CxAssert(((((*((TimeSpan*)x_array->Address(2)))))).Equals(x_t));
	}
	void TimeTest::CxAssert(Double x_x,Double x_y)
	{
		if ( Math::Abs(x_x - x_y) > 1E-05 )
		{
			x_caBlock->TestFailed((new String((Char*)L"Time TestFailed")));
		}
	}
	void TimeTest::CxAssert(Boolean x_x)
	{
		if ( !x_x )
		{
			TimeTestFailed();
		}
	}
	void TimeTest::TimeTestFailed()
	{
		x_caBlock->TestFailed((new String((Char*)L"Time TestFailed")));
	}
	TimeTest::TimeTest()
	{
	}
	TimingTest::TimingTest()
	{
	}
	Int32 TimingTest::DoTimingTest(Int32 x_a,Int32 x_b,Int32 x_c)
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
	UInt16Test::UInt16Test(CABlock* x_caBlock)
	{
		this->x_caBlock = x_caBlock;
	}
	void UInt16Test::Test()
	{
		x_caBlock->Send((new String((Char*)L"Doing UInt16Test")));
		x_caBlock->Send((new String((Char*)L"\tDoing UInt16MethodsTest")));
		UInt16MethodsTest();
		x_caBlock->Send((new String((Char*)L"\tDoing DoUnSignedMath")));
		DoUnSignedMath();
		x_caBlock->Send((new String((Char*)L"\tDoing UInt16Operators")));
		UInt16Operators();
		x_caBlock->Send((new String((Char*)L"\tDoing UInt16ArrayTest")));
		UInt16ArrayTest();
		x_caBlock->Send((new String((Char*)L"\tDoing UInt16MiscTests")));
		UInt16MiscTests();
	}
	void UInt16Test::UInt16MethodsTest()
	{
		UInt16 x_num = 5;
		CxAssert((Int32Value(((UInt16Value)x_num).CompareTo(5))).Equals((Int32)0));
		CxAssert((Int32Value(((UInt16Value)x_num).CompareTo((new UInt16Value(5))))).Equals((Int32)0));
		CxAssert(((UInt16Value)x_num).Equals(5));
		CxAssert(((UInt16Value)x_num).Equals((new UInt16Value(5))));
		CxAssert((UInt16Value(UInt16Value::Parse((new String((Char*)L"77"))))).Equals(77));
		CxAssert((((new String((Char*)L"5"))))->Equals(((UInt16Value)x_num).ToString()));
		x_num = UInt16Value::MaxValue;
		CxAssert((UInt16Value(UInt16Value::MaxValue)).Equals(x_num));
		x_num = 0;
		CxAssert((UInt16Value(x_num)).Equals((UInt16)0));
		String* x_text = ((UInt16Value)UInt16Value::MaxValue).ToString();
		CxAssert(((x_text))->Equals((new String((Char*)L"65535"))));
		CxAssert((UInt16Value(UInt16Value::Parse(x_text))).Equals(UInt16Value::MaxValue));
		String* x_text2 = ((UInt16Value)( 0 )).ToString();
		CxAssert(((x_text2))->Equals((new String((Char*)L"0"))));
		CxAssert((UInt16Value(UInt16Value::Parse(x_text2))).Equals((UInt16)0));
		Object* x_obj = (new UInt16Value(5));
		CxAssert(x_obj->Equals((new UInt16Value(5))));
		CxAssert(((x_obj->ToString()))->Equals((new String((Char*)L"5"))));
	}
	void UInt16Test::DoUnSignedMath()
	{
		UInt16 x_num = 600;
		UInt16 x_num2 = 1200;
		Int32 x_num3 = 1;
		CxAssert(1 <= x_num);
		CxAssert(x_num >= 1);
		CxAssert(x_num >= x_num3);
		CxAssert(x_num3 <= x_num);
		x_num3 = x_num3 + x_num;
		CxAssert((Int32Value(x_num3)).Equals(601));
		CxAssert((Int32Value(x_num + x_num2)).Equals(1800));
		CxAssert((Int32Value(x_num - x_num2)).Equals(-600));
		CxAssert((Int32Value(x_num * x_num2)).Equals(720000));
		CxAssert((Int32Value(x_num2 / x_num)).Equals(2));
		CxAssert((Int32Value(x_num >> 2)).Equals(150));
		CxAssert((Int32Value(x_num << 1)).Equals(1200));
		Int32 x_num4 = 11;
		CxAssert((Int32Value(x_num4 % 5)).Equals(1));
		x_num4 = 8;
		CxAssert(( x_num4 | 1 ) == 9);
		CxAssert(( x_num4 & 1 ) == 0);
		CxAssert((Int32Value(++x_num4)).Equals(9));
		CxAssert((Int32Value(--x_num4)).Equals(8));
		CxAssert(( x_num4 = x_num4 * 2 ) == 16);
		CxAssert(( x_num4 = x_num4 / 2 ) == 8);
		CxAssert(( x_num4 = x_num4 % 2 ) == 0);
		CxAssert(( x_num4 = x_num4 | 4 ) == 4);
		CxAssert(( x_num4 = x_num4 & 4 ) == 4);
		CxAssert((Int32Value(-x_num)).Equals(-600));
		CxAssert((UInt16Value(x_num)).Equals(600));
		UInt32 x_num5 = 0;
		CxAssert((UInt32Value(~x_num5)).Equals(UInt32Value::MaxValue));
		CxAssert((UInt32Value(++x_num5)).Equals(1));
		CxAssert((UInt32Value(--x_num5)).Equals((UInt32)0));
	}
	void UInt16Test::UInt16Operators()
	{
		UInt16 x_num = 66;
		Char x_c = L'\u0001';
		Int32 x_num2 = 1;
		UInt16 x_num3 = 1;
		Int64 x_num4 = 1;
		Double x_num5 = 1;
		CxAssert((UInt16Value(x_num)).Equals(66));
		CxAssert((Int32Value(x_num + x_c)).Equals(67));
		CxAssert((Int32Value(x_num + x_num2)).Equals(67));
		CxAssert((Int32Value(x_num + x_num3)).Equals(67));
		CxAssert((Int64Value(x_num + x_num4)).Equals(67));
		CxAssert((DoubleValue(x_num + x_num5)).Equals(67));
		CxAssert((Int32Value(x_num - x_c)).Equals(65));
		CxAssert((Int32Value(x_num - x_num2)).Equals(65));
		CxAssert((Int32Value(x_num - x_num3)).Equals(65));
		CxAssert((Int64Value(x_num - x_num4)).Equals(65));
		CxAssert((DoubleValue(x_num - x_num5)).Equals(65));
		CxAssert((Int32Value(x_num * x_c)).Equals(66));
		CxAssert((Int32Value(x_num * x_num2)).Equals(66));
		CxAssert((Int32Value(x_num * x_num3)).Equals(66));
		CxAssert((Int64Value(x_num * x_num4)).Equals(66));
		CxAssert((DoubleValue(x_num * x_num5)).Equals(66));
		CxAssert((Int32Value(x_num / x_c)).Equals(66));
		CxAssert((Int32Value(x_num / x_num2)).Equals(66));
		CxAssert((Int32Value(x_num / x_num3)).Equals(66));
		CxAssert((Int64Value(x_num / x_num4)).Equals(66));
		CxAssert((DoubleValue(x_num / x_num5)).Equals(66));
		CxAssert((Int32Value(x_num % x_c)).Equals((Int32)0));
		CxAssert((Int32Value(x_num % x_num2)).Equals((Int32)0));
		CxAssert((Int32Value(x_num % x_num3)).Equals((Int32)0));
		CxAssert((Int64Value(x_num % x_num4)).Equals((Int64)0));
		CxAssert((DoubleValue(((DoubleValue)x_num) % x_num5)).Equals(0));
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
		CxAssert((Int32Value(~x_num)).Equals(-67));
		CxAssert(x_c < x_num);
		CxAssert(x_num2 < x_num);
		CxAssert(x_num3 < x_num);
		CxAssert(x_num4 < x_num);
		CxAssert(x_num5 < x_num);
		CxAssert(x_c > x_num,false);
		CxAssert(x_num2 > x_num,false);
		CxAssert(x_num3 > x_num,false);
		CxAssert(x_num4 > x_num,false);
		CxAssert(x_num5 > x_num,false);
		CxAssert(( x_num = ( x_num + 1 ) ) == 67);
		CxAssert(( x_num = ( x_num - 1 ) ) == 66);
		CxAssert((UInt16Value(x_num++)).Equals(66));
		CxAssert((UInt16Value(x_num--)).Equals(67));
		CxAssert((Int32Value(x_num << 1)).Equals(132));
		CxAssert((Int32Value(x_num >> 1)).Equals(33));
		CxAssert((CharValue(x_c)).Equals(x_num),false);
		CxAssert((Int32Value(x_num2)).Equals(x_num),false);
		CxAssert((UInt16Value(x_num3)).Equals(x_num),false);
		CxAssert((Int64Value(x_num4)).Equals(x_num),false);
		CxAssert((DoubleValue(x_num5)).Equals(x_num),false);
		CxAssert(!(CharValue(x_c)).Equals(x_num));
		CxAssert(!(Int32Value(x_num2)).Equals(x_num));
		CxAssert(!(UInt16Value(x_num3)).Equals(x_num));
		CxAssert(!(Int64Value(x_num4)).Equals(x_num));
		CxAssert(!(DoubleValue(x_num5)).Equals(x_num));
		CxAssert(x_c <= x_num);
		CxAssert(x_num2 <= x_num);
		CxAssert(x_num3 <= x_num);
		CxAssert(x_num4 <= x_num);
		CxAssert(x_num5 <= x_num);
		CxAssert(x_c >= x_num,false);
		CxAssert(x_num2 >= x_num,false);
		CxAssert(x_num3 >= x_num,false);
		CxAssert(x_num4 >= x_num,false);
		CxAssert(x_num5 >= x_num,false);
		CxAssert(( x_num = ( x_num + x_c ) ) == 67);
		CxAssert(( x_num = ( x_num - x_c ) ) == 66);
		CxAssert(( x_num = ( x_num + x_num3 ) ) == 67);
		CxAssert(( x_num = ( x_num - x_num3 ) ) == 66);
		CxAssert(( x_num = ( x_num * x_c ) ) == 66);
		CxAssert(( x_num = ( x_num / x_c ) ) == 66);
		CxAssert(( x_num = ( x_num * x_num3 ) ) == 66);
		CxAssert(( x_num = ( x_num / x_num3 ) ) == 66);
		CxAssert(( x_num = ( x_num % x_c ) ) == 0);
		x_num = 66;
		CxAssert(( x_num = ( x_num % x_num3 ) ) == 0);
		x_num = 66;
		CxAssert(( x_num = ( x_num & x_c ) ) == 0);
		x_num = 66;
		CxAssert(( x_num = ( x_num & x_num3 ) ) == 0);
		x_num = 66;
		CxAssert(( x_num = ( x_num | x_c ) ) == 67);
		x_num = 66;
		CxAssert(( x_num = ( x_num | x_num3 ) ) == 67);
		x_num = 66;
		CxAssert(( x_num = ( x_num ^ x_c ) ) == 67);
		x_num = 66;
		CxAssert(( x_num = ( x_num ^ x_num3 ) ) == 67);
		x_num = 66;
		CxAssert(( x_num = ( x_num << x_c ) ) == 132);
		x_num = 66;
		CxAssert(( x_num = ( x_num << x_num2 ) ) == 132);
		x_num = 66;
		CxAssert(( x_num = ( x_num >> x_c ) ) == 33);
		x_num = 66;
		CxAssert(( x_num = ( x_num >> x_num2 ) ) == 33);
		x_num = 66;
	}
	void UInt16Test::UInt16ArrayTest()
	{
		static UInt16 UInt16ArrayTestArray0[5] = {1,2,3,4,5};
		static UInt16 UInt16ArrayTestArray1[4] = {1,2,3,4};
		static UInt16 UInt16ArrayTestArray2[2][4] = {{1,2,3,4},{4,5,6,7}};
		static UInt16 UInt16ArrayTestArray3[2][2][4] = {{{1,2,3,4},{5,6,7,8}},{{9,10,11,12},{13,14,15,16}}};
		Array* x_array = (new Array(UInt16Type,5))->Initialize((UInt16*) UInt16ArrayTestArray0);
		CxAssert((Int32Value(x_array->get_Length())).Equals(5));
		CxAssert((UInt16Value(((*((UInt16*)x_array->Address(3)))))).Equals(4));
		Array* x_array2 = (new Array(UInt16Type,4))->Initialize((UInt16*) UInt16ArrayTestArray1);
		CxAssert((UInt16Value(((*((UInt16*)x_array2->Address(1)))))).Equals(2));
		Array* x_array3 = (new Array(UInt16Type,2,4))->Initialize((UInt16*) UInt16ArrayTestArray2);
		CxAssert((UInt16Value(((*((UInt16*)x_array3->Address(0,2)))))).Equals(3));
		Array* x_array4 = (new Array(UInt16Type,2,2,4))->Initialize((UInt16*) UInt16ArrayTestArray3);
		CxAssert((UInt16Value(((*((UInt16*)x_array4->Address(0,0,3)))))).Equals(4));
		((*((UInt16*)x_array4->Address(0,0,3)))) = 6;
		CxAssert((UInt16Value(((*((UInt16*)x_array4->Address(0,0,3)))))).Equals(6));
		x_array4->SetValue((new UInt16Value(4)),0,0,3);
		CxAssert((UInt16Value(((*((UInt16*)x_array4->Address(0,0,3)))))).Equals(4));
	}
	void UInt16Test::UInt16MiscTests()
	{
		UInt16 x_num = 0;
		UInt16 x_num2 = 1;
		CxAssert((UInt16Value(Math::Max(x_num,x_num2))).Equals(1));
		CxAssert((UInt16Value(Math::Min(x_num,x_num2))).Equals((UInt16)0));
		StringBuilder* x_stringBuilder = (new StringBuilder());
		x_stringBuilder->Append(x_num2);
		CxAssert(((x_stringBuilder->ToString()))->Equals((new String((Char*)L"1"))));
		x_stringBuilder->Insert(1,x_num);
		CxAssert(((x_stringBuilder->ToString()))->Equals((new String((Char*)L"10"))));
	}
	void UInt16Test::CxAssert(Boolean x_x)
	{
		if ( !x_x )
		{
			x_caBlock->TestFailed((new String((Char*)L"UInt16 TestFailed")));
		}
	}
	void UInt16Test::CxAssert(Boolean x_x,Boolean x_y)
	{
		if ( !(BooleanValue(x_x)).Equals(x_y) )
		{
			x_caBlock->TestFailed((new String((Char*)L"UInt16 TestFailed")));
		}
	}
	UInt16Test::UInt16Test()
	{
	}
	UInt32Test::UInt32Test(CABlock* x_caBlock)
	{
		this->x_caBlock = x_caBlock;
	}
	void UInt32Test::Test()
	{
		x_caBlock->Send((new String((Char*)L"Doing UInt32Test")));
		x_caBlock->Send((new String((Char*)L"\tDoing UInt32MethodsTest")));
		UInt32MethodsTest();
		x_caBlock->Send((new String((Char*)L"\tDoing DoUnSignedMath")));
		DoUnSignedMath();
		x_caBlock->Send((new String((Char*)L"\tDoing UInt32Operators")));
		UInt32Operators();
		x_caBlock->Send((new String((Char*)L"\tDoing UInt32ArrayTest")));
		UInt32ArrayTest();
		x_caBlock->Send((new String((Char*)L"\tDoing UInt32MiscTests")));
		UInt32MiscTests();
	}
	void UInt32Test::UInt32MethodsTest()
	{
		UInt32 x_num = 5;
		CxAssert((Int32Value(((UInt32Value)x_num).CompareTo(5))).Equals((Int32)0));
		CxAssert((Int32Value(((UInt32Value)x_num).CompareTo(new UInt32Value(5)))).Equals((Int32)0));
		CxAssert(((UInt32Value)x_num).Equals(5));
		CxAssert(((UInt32Value)x_num).Equals(new UInt32Value(5)));
		CxAssert((UInt32Value(UInt32Value::Parse((new String((Char*)L"77"))))).Equals(77));
		CxAssert((((new String((Char*)L"5"))))->Equals(((UInt32Value)x_num).ToString()));
		x_num = UInt32Value::MaxValue;
		CxAssert((Int32Value(-1)).Equals(x_num));
		x_num = 0;
		CxAssert((UInt32Value(x_num)).Equals((UInt32)0));
		String* x_text = ((UInt32Value)UInt32Value::MaxValue).ToString();
		CxAssert(((x_text))->Equals((new String((Char*)L"4294967295"))));
		CxAssert((UInt32Value(UInt32Value::Parse(x_text))).Equals(UInt32Value::MaxValue));
		String* x_text2 = ((UInt32Value)0).ToString();
		CxAssert(((x_text2))->Equals((new String((Char*)L"0"))));
		CxAssert((UInt32Value(UInt32Value::Parse(x_text2))).Equals((UInt32)0));
		Object* x_obj = new UInt32Value(5);
		CxAssert(x_obj->Equals(new UInt32Value(5)));
		CxAssert(((x_obj->ToString()))->Equals((new String((Char*)L"5"))));
	}
	void UInt32Test::DoUnSignedMath()
	{
		UInt32 x_num = 60000;
		UInt32 x_num2 = 120000;
		Int32 x_num3 = 1;
		CxAssert(1 <= x_num);
		CxAssert(x_num >= 1);
		CxAssert(x_num >= x_num3);
		CxAssert(x_num3 <= x_num);
		x_num3 = x_num3 + x_num;
		CxAssert((Int32Value(x_num3)).Equals(60001));
		CxAssert((UInt32Value(x_num + x_num2)).Equals(180000));
		CxAssert((UInt32Value(x_num - x_num2)).Equals(4294907296));
		CxAssert((UInt32Value(x_num * x_num2)).Equals(2905032704));
		CxAssert((UInt32Value(x_num2 / x_num)).Equals(2));
		CxAssert((UInt32Value(x_num >> 2)).Equals(15000));
		CxAssert((UInt32Value(x_num << 1)).Equals(120000));
		Int32 x_num4 = 11;
		CxAssert((Int32Value(x_num4 % 5)).Equals(1));
		x_num4 = 8;
		CxAssert(( x_num4 | 1 ) == 9);
		CxAssert(( x_num4 & 1 ) == 0);
		CxAssert((Int32Value(++x_num4)).Equals(9));
		CxAssert((Int32Value(--x_num4)).Equals(8));
		CxAssert(( x_num4 = x_num4 * 2 ) == 16);
		CxAssert(( x_num4 = x_num4 / 2 ) == 8);
		CxAssert(( x_num4 = x_num4 % 2 ) == 0);
		CxAssert(( x_num4 = x_num4 | 4 ) == 4);
		CxAssert(( x_num4 = x_num4 & 4 ) == 4);
		CxAssert((Int64Value(0 - x_num)).Equals(-60000));
		CxAssert((UInt32Value(x_num)).Equals(60000));
		UInt32 x_num5 = 0;
		CxAssert((UInt32Value(~x_num5)).Equals(UInt32Value::MaxValue));
		CxAssert((UInt32Value(++x_num5)).Equals(1));
		CxAssert((UInt32Value(--x_num5)).Equals((UInt32)0));
	}
	void UInt32Test::UInt32Operators()
	{
		UInt32 x_num = 66;
		Char x_c = L'\u0001';
		Int32 x_num2 = 1;
		UInt32 x_num3 = 1;
		Int64 x_num4 = 1;
		Double x_num5 = 1;
		CxAssert((UInt32Value(x_num)).Equals(66));
		CxAssert((UInt32Value(x_num + x_c)).Equals(67));
		CxAssert((Int64Value(x_num + x_num2)).Equals(67));
		CxAssert((UInt32Value(x_num + x_num3)).Equals(67));
		CxAssert((Int64Value(x_num + x_num4)).Equals(67));
		CxAssert((DoubleValue(x_num + x_num5)).Equals(67));
		CxAssert((UInt32Value(x_num - x_c)).Equals(65));
		CxAssert((Int64Value(x_num - x_num2)).Equals(65));
		CxAssert((UInt32Value(x_num - x_num3)).Equals(65));
		CxAssert((Int64Value(x_num - x_num4)).Equals(65));
		CxAssert((DoubleValue(x_num - x_num5)).Equals(65));
		CxAssert((UInt32Value(x_num * x_c)).Equals(66));
		CxAssert((Int64Value(x_num * x_num2)).Equals(66));
		CxAssert((UInt32Value(x_num * x_num3)).Equals(66));
		CxAssert((Int64Value(x_num * x_num4)).Equals(66));
		CxAssert((DoubleValue(x_num * x_num5)).Equals(66));
		CxAssert((UInt32Value(x_num / x_c)).Equals(66));
		CxAssert((Int64Value(x_num / x_num2)).Equals(66));
		CxAssert((UInt32Value(x_num / x_num3)).Equals(66));
		CxAssert((Int64Value(x_num / x_num4)).Equals(66));
		CxAssert((DoubleValue(x_num / x_num5)).Equals(66));
		CxAssert((UInt32Value(x_num % x_c)).Equals((UInt32)0));
		CxAssert((Int64Value(x_num % x_num2)).Equals((Int64)0));
		CxAssert((UInt32Value(x_num % x_num3)).Equals((UInt32)0));
		CxAssert((Int64Value(x_num % x_num4)).Equals((Int64)0));
		CxAssert((DoubleValue(((DoubleValue)x_num) % x_num5)).Equals(0));
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
		CxAssert((UInt32Value(~x_num)).Equals(4294967229));
		CxAssert(x_c < x_num);
		CxAssert(x_num2 < x_num);
		CxAssert(x_num3 < x_num);
		CxAssert(x_num4 < x_num);
		CxAssert(x_num5 < x_num);
		CxAssert(x_c > x_num,false);
		CxAssert(x_num2 > x_num,false);
		CxAssert(x_num3 > x_num,false);
		CxAssert(x_num4 > x_num,false);
		CxAssert(x_num5 > x_num,false);
		CxAssert((UInt32Value(++x_num)).Equals(67));
		CxAssert((UInt32Value(--x_num)).Equals(66));
		CxAssert((UInt32Value(x_num++)).Equals(66));
		CxAssert((UInt32Value(x_num--)).Equals(67));
		CxAssert((UInt32Value(x_num << 1)).Equals(132));
		CxAssert((UInt32Value(x_num >> 1)).Equals(33));
		CxAssert((CharValue(x_c)).Equals(x_num),false);
		CxAssert((Int32Value(x_num2)).Equals(x_num),false);
		CxAssert((UInt32Value(x_num3)).Equals(x_num),false);
		CxAssert((Int64Value(x_num4)).Equals(x_num),false);
		CxAssert((DoubleValue(x_num5)).Equals(x_num),false);
		CxAssert(!(CharValue(x_c)).Equals(x_num));
		CxAssert(!(Int32Value(x_num2)).Equals(x_num));
		CxAssert(!(UInt32Value(x_num3)).Equals(x_num));
		CxAssert(!(Int64Value(x_num4)).Equals(x_num));
		CxAssert(!(DoubleValue(x_num5)).Equals(x_num));
		CxAssert(x_c <= x_num);
		CxAssert(x_num2 <= x_num);
		CxAssert(x_num3 <= x_num);
		CxAssert(x_num4 <= x_num);
		CxAssert(x_num5 <= x_num);
		CxAssert(x_c >= x_num,false);
		CxAssert(x_num2 >= x_num,false);
		CxAssert(x_num3 >= x_num,false);
		CxAssert(x_num4 >= x_num,false);
		CxAssert(x_num5 >= x_num,false);
		CxAssert(( x_num = x_num + x_c ) == 67);
		CxAssert(( x_num = x_num - x_c ) == 66);
		CxAssert(( x_num = x_num + x_num3 ) == 67);
		CxAssert(( x_num = x_num - x_num3 ) == 66);
		CxAssert(( x_num = x_num * x_c ) == 66);
		CxAssert(( x_num = x_num / x_c ) == 66);
		CxAssert(( x_num = x_num * x_num3 ) == 66);
		CxAssert(( x_num = x_num / x_num3 ) == 66);
		CxAssert(( x_num = x_num % x_c ) == 0);
		x_num = 66;
		CxAssert(( x_num = x_num % x_num3 ) == 0);
		x_num = 66;
		CxAssert(( x_num = x_num & x_c ) == 0);
		x_num = 66;
		CxAssert(( x_num = x_num & x_num3 ) == 0);
		x_num = 66;
		CxAssert(( x_num = x_num | x_c ) == 67);
		x_num = 66;
		CxAssert(( x_num = x_num | x_num3 ) == 67);
		x_num = 66;
		CxAssert(( x_num = x_num ^ x_c ) == 67);
		x_num = 66;
		CxAssert(( x_num = x_num ^ x_num3 ) == 67);
		x_num = 66;
		CxAssert(( x_num = x_num << x_c ) == 132);
		x_num = 66;
		CxAssert(( x_num = x_num << x_num2 ) == 132);
		x_num = 66;
		CxAssert(( x_num = x_num >> x_c ) == 33);
		x_num = 66;
		CxAssert(( x_num = x_num >> x_num2 ) == 33);
		x_num = 66;
	}
	void UInt32Test::UInt32ArrayTest()
	{
		static UInt32 UInt32ArrayTestArray0[5] = {1,2,3,4,5};
		static UInt32 UInt32ArrayTestArray1[4] = {1,2,3,4};
		static UInt32 UInt32ArrayTestArray2[2][4] = {{1,2,3,4},{4,5,6,7}};
		static UInt32 UInt32ArrayTestArray3[2][2][4] = {{{1,2,3,4},{5,6,7,8}},{{9,10,11,12},{13,14,15,16}}};
		Array* x_array = (new Array(UInt32Type,5))->Initialize((UInt32*) UInt32ArrayTestArray0);
		CxAssert((Int32Value(x_array->get_Length())).Equals(5));
		CxAssert((UInt32Value(((*((UInt32*)x_array->Address(3)))))).Equals(4));
		Array* x_array2 = (new Array(UInt32Type,4))->Initialize((UInt32*) UInt32ArrayTestArray1);
		CxAssert((UInt32Value(((*((UInt32*)x_array2->Address(1)))))).Equals(2));
		Array* x_array3 = (new Array(UInt32Type,2,4))->Initialize((UInt32*) UInt32ArrayTestArray2);
		CxAssert((UInt32Value(((*((UInt32*)x_array3->Address(0,2)))))).Equals(3));
		Array* x_array4 = (new Array(UInt32Type,2,2,4))->Initialize((UInt32*) UInt32ArrayTestArray3);
		CxAssert((UInt32Value(((*((UInt32*)x_array4->Address(0,0,3)))))).Equals(4));
		((*((UInt32*)x_array4->Address(0,0,3)))) = 6;
		CxAssert((UInt32Value(((*((UInt32*)x_array4->Address(0,0,3)))))).Equals(6));
		x_array4->SetValue(new UInt32Value(4),0,0,3);
		CxAssert((UInt32Value(((*((UInt32*)x_array4->Address(0,0,3)))))).Equals(4));
	}
	void UInt32Test::UInt32MiscTests()
	{
		UInt32 x_val = 0;
		UInt32 x_num = 1;
		CxAssert((UInt32Value(Math::Max(x_val,x_num))).Equals(1));
		CxAssert((UInt32Value(Math::Min(x_val,x_num))).Equals((UInt32)0));
		StringBuilder* x_stringBuilder = (new StringBuilder());
		x_stringBuilder->Append(x_num);
		CxAssert(((x_stringBuilder->ToString()))->Equals((new String((Char*)L"1"))));
	}
	void UInt32Test::CxAssert(Boolean x_x)
	{
		if ( !x_x )
		{
			x_caBlock->TestFailed((new String((Char*)L"UInt32 TestFailed")));
		}
	}
	void UInt32Test::CxAssert(Boolean x_x,Boolean x_y)
	{
		if ( !(BooleanValue(x_x)).Equals(x_y) )
		{
			x_caBlock->TestFailed((new String((Char*)L"UInt32 TestFailed")));
		}
	}
	UInt32Test::UInt32Test()
	{
	}
	UInt64Test::UInt64Test(CABlock* x_caBlock)
	{
		this->x_caBlock = x_caBlock;
	}
	void UInt64Test::Test()
	{
		x_caBlock->Send((new String((Char*)L"Doing UInt64Test")));
		x_caBlock->Send((new String((Char*)L"\tDoing UInt64MethodsTest")));
		UInt64MethodsTest();
		x_caBlock->Send((new String((Char*)L"\tDoing UInt64UnSignedMath")));
		UInt64UnSignedMath();
		x_caBlock->Send((new String((Char*)L"\tDoing UInt64Operators")));
		UInt64Operators();
		x_caBlock->Send((new String((Char*)L"\tDoing UInt64ArrayTest")));
		UInt64ArrayTest();
		x_caBlock->Send((new String((Char*)L"\tDoing UInt64MiscTests")));
		UInt64MiscTests();
	}
	void UInt64Test::UInt64MethodsTest()
	{
		UInt64 x_num = 5;
		CxAssert((Int32Value(((UInt64Value)x_num).CompareTo(5))).Equals((Int32)0));
		CxAssert((Int32Value(((UInt64Value)x_num).CompareTo(new UInt64Value(5)))).Equals((Int32)0));
		CxAssert(((UInt64Value)x_num).Equals(5));
		CxAssert(((UInt64Value)x_num).Equals(new UInt64Value(5)));
		CxAssert((UInt64Value(UInt64Value::Parse((new String((Char*)L"77"))))).Equals(77));
		CxAssert((((new String((Char*)L"5"))))->Equals(((UInt64Value)x_num).ToString()));
		x_num = UInt64Value::MaxValue;
		CxAssert((UInt64Value(UInt64Value::MaxValue)).Equals(x_num));
		x_num = 0;
		CxAssert((UInt64Value(x_num)).Equals((UInt64)0));
		String* x_text = ((UInt64Value)UInt64Value::MaxValue).ToString();
		CxAssert(((x_text))->Equals((new String((Char*)L"18446744073709551615"))));
		CxAssert((UInt64Value(UInt64Value::Parse(x_text))).Equals(UInt64Value::MaxValue));
		String* x_text2 = ((UInt64Value)0).ToString();
		CxAssert(((x_text2))->Equals((new String((Char*)L"0"))));
		CxAssert((UInt64Value(UInt64Value::Parse(x_text2))).Equals((UInt64)0));
		Object* x_obj = new UInt64Value(5);
		CxAssert(x_obj->Equals(new UInt64Value(5)));
		CxAssert(((x_obj->ToString()))->Equals((new String((Char*)L"5"))));
	}
	void UInt64Test::UInt64UnSignedMath()
	{
		UInt64 x_num = 60000;
		UInt64 x_num2 = 120000;
		UInt64 x_num3 = 1;
		CxAssert(1 <= x_num);
		CxAssert(x_num >= 1);
		CxAssert(x_num >= x_num3);
		CxAssert(x_num3 <= x_num);
		x_num3 = x_num3 + x_num;
		CxAssert((UInt64Value(x_num3)).Equals(60001));
		CxAssert((UInt64Value(x_num + x_num2)).Equals(180000));
		UInt64 x_num4 = x_num - x_num2;
		CxAssert((UInt64Value(x_num - x_num2)).Equals(18446744073709491616));
		UInt64 x_num5 = x_num * x_num2;
		CxAssert((UInt64Value(x_num * x_num2)).Equals(7200000000));
		CxAssert((UInt64Value(x_num2 / x_num)).Equals(2));
		CxAssert((UInt64Value(x_num >> 2)).Equals(15000));
		CxAssert((UInt64Value(x_num << 1)).Equals(120000));
		Int32 x_num6 = 11;
		CxAssert((Int32Value(x_num6 % 5)).Equals(1));
		x_num6 = 8;
		CxAssert(( x_num6 | 1 ) == 9);
		CxAssert(( x_num6 & 1 ) == 0);
		CxAssert((Int32Value(++x_num6)).Equals(9));
		CxAssert((Int32Value(--x_num6)).Equals(8));
		CxAssert(( x_num6 = x_num6 * 2 ) == 16);
		CxAssert(( x_num6 = x_num6 / 2 ) == 8);
		CxAssert(( x_num6 = x_num6 % 2 ) == 0);
		CxAssert(( x_num6 = x_num6 | 4 ) == 4);
		CxAssert(( x_num6 = x_num6 & 4 ) == 4);
		CxAssert((UInt64Value(x_num)).Equals(60000));
		UInt32 x_num7 = 0;
		CxAssert((UInt32Value(~x_num7)).Equals(UInt32Value::MaxValue));
		CxAssert((UInt32Value(++x_num7)).Equals(1));
		CxAssert((UInt32Value(--x_num7)).Equals((UInt32)0));
	}
	void UInt64Test::UInt64Operators()
	{
		UInt64 x_num = 66;
		Char x_c = L'\u0001';
		Byte x_b = 1;
		SByte x_b2 = 1;
		Int16 x_num2 = 1;
		Int32 x_num3 = 1;
		Int64 x_num4 = 1;
		UInt16 x_num5 = 1;
		UInt32 x_num6 = 1;
		UInt64 x_num7 = 1;
		Single x_num8 = ((Single)1);
		Double x_num9 = 1;
		CxAssert((UInt64Value(x_num)).Equals(66));
		CxAssert((UInt64Value(x_num + x_c)).Equals(67));
		CxAssert((UInt64Value(x_num + x_b)).Equals(67));
		CxAssert((Int64Value(x_num + x_b2)).Equals(67));
		CxAssert((Int64Value(x_num + x_num2)).Equals(67));
		CxAssert((Int64Value(x_num + x_num3)).Equals(67));
		CxAssert((Int64Value(x_num + x_num4)).Equals(67));
		CxAssert((UInt64Value(x_num + x_num5)).Equals(67));
		CxAssert((UInt64Value(x_num + x_num6)).Equals(67));
		CxAssert((UInt64Value(x_num + x_num7)).Equals(67));
		CxAssert((SingleValue(x_num + x_num8)).Equals(((Single)67)));
		CxAssert((DoubleValue(x_num + x_num9)).Equals(67));
		CxAssert((UInt64Value(x_num - x_c)).Equals(65));
		CxAssert((UInt64Value(x_num - x_b)).Equals(65));
		CxAssert((Int64Value(x_num - x_b2)).Equals(65));
		CxAssert((Int64Value(x_num - x_num2)).Equals(65));
		CxAssert((Int64Value(x_num - x_num3)).Equals(65));
		CxAssert((Int64Value(x_num - x_num4)).Equals(65));
		CxAssert((UInt64Value(x_num - x_num5)).Equals(65));
		CxAssert((UInt64Value(x_num - x_num6)).Equals(65));
		CxAssert((UInt64Value(x_num - x_num7)).Equals(65));
		CxAssert((SingleValue(x_num - x_num8)).Equals(((Single)65)));
		CxAssert((DoubleValue(x_num - x_num9)).Equals(65));
		CxAssert((UInt64Value(x_num * x_c)).Equals(66));
		CxAssert((UInt64Value(x_num * x_b)).Equals(66));
		CxAssert((Int64Value(x_num * x_b2)).Equals(66));
		CxAssert((Int64Value(x_num * x_num2)).Equals(66));
		CxAssert((Int64Value(x_num * x_num3)).Equals(66));
		CxAssert((Int64Value(x_num * x_num4)).Equals(66));
		CxAssert((UInt64Value(x_num * x_num5)).Equals(66));
		CxAssert((UInt64Value(x_num * x_num6)).Equals(66));
		CxAssert((UInt64Value(x_num * x_num7)).Equals(66));
		CxAssert((SingleValue(x_num * x_num8)).Equals(((Single)66)));
		CxAssert((DoubleValue(x_num * x_num9)).Equals(66));
		CxAssert((UInt64Value(x_num / x_c)).Equals(66));
		CxAssert((UInt64Value(x_num / x_b)).Equals(66));
		CxAssert((UInt64Value(x_num / x_b2)).Equals(66));
		CxAssert((UInt64Value(x_num / x_num2)).Equals(66));
		CxAssert((UInt64Value(x_num / x_num3)).Equals(66));
		CxAssert((UInt64Value(x_num / x_num4)).Equals(66));
		CxAssert((UInt64Value(x_num / x_num5)).Equals(66));
		CxAssert((UInt64Value(x_num / x_num6)).Equals(66));
		CxAssert((UInt64Value(x_num / x_num7)).Equals(66));
		CxAssert((SingleValue(x_num / x_num8)).Equals(((Single)66)));
		CxAssert((DoubleValue(x_num / x_num9)).Equals(66));
		CxAssert((UInt64Value(x_num % x_c)).Equals((UInt64)0));
		CxAssert((UInt64Value(x_num % x_b)).Equals((UInt64)0));
		CxAssert((UInt64Value(x_num % x_b2)).Equals((UInt64)0));
		CxAssert((UInt64Value(x_num % x_num2)).Equals((UInt64)0));
		CxAssert((UInt64Value(x_num % x_num3)).Equals((UInt64)0));
		CxAssert((UInt64Value(x_num % x_num4)).Equals((UInt64)0));
		CxAssert((UInt64Value(x_num % x_num5)).Equals((UInt64)0));
		CxAssert((UInt64Value(x_num % x_num6)).Equals((UInt64)0));
		CxAssert((UInt64Value(x_num % x_num7)).Equals((UInt64)0));
		CxAssert((SingleValue(((DoubleValue)x_num) % x_num8)).Equals(((Single)0)));
		CxAssert((DoubleValue(((DoubleValue)x_num) % x_num9)).Equals(0));
		CxAssert(( x_num & x_c ) == 0);
		CxAssert(( x_num & x_b ) == 0);
		CxAssert(( x_num & x_b2 ) == 0);
		CxAssert(( x_num & x_num2 ) == 0);
		CxAssert(( x_num & x_num3 ) == 0);
		CxAssert(( x_num & x_num4 ) == 0);
		CxAssert(( x_num & x_num5 ) == 0);
		CxAssert(( x_num & x_num6 ) == 0);
		CxAssert(( x_num & x_num7 ) == 0);
		CxAssert(( x_num | x_c ) == 67);
		CxAssert(( x_num | x_b ) == 67);
		CxAssert(( x_num | x_b2 ) == 67);
		CxAssert(( x_num | x_num2 ) == 67);
		CxAssert(( x_num | x_num3 ) == 67);
		CxAssert(( x_num | x_num4 ) == 67);
		CxAssert(( x_num | x_num5 ) == 67);
		CxAssert(( x_num | x_num6 ) == 67);
		CxAssert(( x_num | x_num7 ) == 67);
		CxAssert(( x_num ^ x_c ) == 67);
		CxAssert(( x_num ^ x_b ) == 67);
		CxAssert(( x_num ^ x_b2 ) == 67);
		CxAssert(( x_num ^ x_num2 ) == 67);
		CxAssert(( x_num ^ x_num3 ) == 67);
		CxAssert(( x_num ^ x_num4 ) == 67);
		CxAssert(( x_num ^ x_num5 ) == 67);
		CxAssert(( x_num ^ x_num6 ) == 67);
		CxAssert(( x_num ^ x_num7 ) == 67);
		CxAssert((ByteValue(( ~x_num ))).Equals(189));
		CxAssert(x_c < x_num);
		CxAssert(x_b < x_num);
		CxAssert(x_b2 < x_num);
		CxAssert(x_num2 < x_num);
		CxAssert(x_num3 < x_num);
		CxAssert(x_num4 < x_num);
		CxAssert(x_num5 < x_num);
		CxAssert(x_num6 < x_num);
		CxAssert(x_num7 < x_num);
		CxAssert(x_num8 < x_num);
		CxAssert(x_num9 < x_num);
		CxAssert(x_c > x_num,false);
		CxAssert(x_b > x_num,false);
		CxAssert(x_b2 > x_num,false);
		CxAssert(x_num2 > x_num,false);
		CxAssert(x_num3 > x_num,false);
		CxAssert(x_num4 > x_num,false);
		CxAssert(x_num5 > x_num,false);
		CxAssert(x_num6 > x_num,false);
		CxAssert(x_num7 > x_num,false);
		CxAssert(x_num8 > x_num,false);
		CxAssert(x_num9 > x_num,false);
		CxAssert((UInt64Value(++x_num)).Equals(67));
		CxAssert((UInt64Value(--x_num)).Equals(66));
		CxAssert((UInt64Value(x_num++)).Equals(66));
		CxAssert((UInt64Value(x_num--)).Equals(67));
		CxAssert((UInt64Value(x_num << 1)).Equals(132));
		CxAssert((UInt64Value(x_num >> 1)).Equals(33));
		CxAssert((CharValue(x_c)).Equals(x_num),false);
		CxAssert((ByteValue(x_b)).Equals(x_num),false);
		CxAssert((UInt64Value(x_b2)).Equals(x_num),false);
		CxAssert((UInt64Value(x_num2)).Equals(x_num),false);
		CxAssert((UInt64Value(x_num3)).Equals(x_num),false);
		CxAssert((Int64Value(x_num4)).Equals(x_num),false);
		CxAssert((UInt16Value(x_num5)).Equals(x_num),false);
		CxAssert((UInt32Value(x_num6)).Equals(x_num),false);
		CxAssert((UInt64Value(x_num7)).Equals(x_num),false);
		CxAssert((SingleValue(x_num8)).Equals(x_num),false);
		CxAssert((DoubleValue(x_num9)).Equals(x_num),false);
		CxAssert(!(CharValue(x_c)).Equals(x_num));
		CxAssert(!(ByteValue(x_b)).Equals(x_num));
		CxAssert(!(UInt64Value(x_b2)).Equals(x_num));
		CxAssert(!(UInt64Value(x_num2)).Equals(x_num));
		CxAssert(!(UInt64Value(x_num3)).Equals(x_num));
		CxAssert(!(Int64Value(x_num4)).Equals(x_num));
		CxAssert(!(UInt16Value(x_num5)).Equals(x_num));
		CxAssert(!(UInt32Value(x_num6)).Equals(x_num));
		CxAssert(!(UInt64Value(x_num7)).Equals(x_num));
		CxAssert(!(SingleValue(x_num8)).Equals(x_num));
		CxAssert(!(DoubleValue(x_num9)).Equals(x_num));
		CxAssert(x_c <= x_num);
		CxAssert(x_b <= x_num);
		CxAssert(x_b2 <= x_num);
		CxAssert(x_num2 <= x_num);
		CxAssert(x_num3 <= x_num);
		CxAssert(x_num4 <= x_num);
		CxAssert(x_num5 <= x_num);
		CxAssert(x_num6 <= x_num);
		CxAssert(x_num7 <= x_num);
		CxAssert(x_num8 <= x_num);
		CxAssert(x_num9 <= x_num);
		CxAssert(x_c >= x_num,false);
		CxAssert(x_b >= x_num,false);
		CxAssert(x_b2 >= x_num,false);
		CxAssert(x_num2 >= x_num,false);
		CxAssert(x_num3 >= x_num,false);
		CxAssert(x_num4 >= x_num,false);
		CxAssert(x_num5 >= x_num,false);
		CxAssert(x_num6 >= x_num,false);
		CxAssert(x_num7 >= x_num,false);
		CxAssert(x_num8 >= x_num,false);
		CxAssert(x_num9 >= x_num,false);
		CxAssert(( x_num = x_num + x_c ) == 67);
		CxAssert(( x_num = x_num - x_c ) == 66);
		CxAssert(( x_num = x_num + x_num6 ) == 67);
		CxAssert(( x_num = x_num - x_num6 ) == 66);
		CxAssert(( x_num = x_num * x_c ) == 66);
		CxAssert(( x_num = x_num / x_c ) == 66);
		CxAssert(( x_num = x_num * x_num6 ) == 66);
		CxAssert(( x_num = x_num / x_num6 ) == 66);
		CxAssert(( x_num = x_num % x_c ) == 0);
		x_num = 66;
		CxAssert(( x_num = x_num % x_num6 ) == 0);
		x_num = 66;
		CxAssert(( x_num = x_num & x_c ) == 0);
		x_num = 66;
		CxAssert(( x_num = x_num & x_num6 ) == 0);
		x_num = 66;
		CxAssert(( x_num = x_num | x_c ) == 67);
		x_num = 66;
		CxAssert(( x_num = x_num | x_num6 ) == 67);
		x_num = 66;
		CxAssert(( x_num = x_num ^ x_c ) == 67);
		x_num = 66;
		CxAssert(( x_num = x_num ^ x_num6 ) == 67);
		x_num = 66;
		CxAssert(( x_num = x_num << x_c ) == 132);
		x_num = 66;
		CxAssert(( x_num = x_num << x_num3 ) == 132);
		x_num = 66;
		CxAssert(( x_num = x_num >> x_c ) == 33);
		x_num = 66;
		CxAssert(( x_num = x_num >> x_num3 ) == 33);
		x_num = 66;
		Char x_c2 = L'B';
		CxAssert(( x_c2 = ( x_c2 << x_c ) ) == L'\u0084');
	}
	void UInt64Test::UInt64ArrayTest()
	{
		static UInt64 UInt64ArrayTestArray0[5] = {1,2,3,4,5};
		static UInt64 UInt64ArrayTestArray1[4] = {1,2,3,4};
		static UInt64 UInt64ArrayTestArray2[2][4] = {{1,2,3,4},{4,5,6,7}};
		static UInt64 UInt64ArrayTestArray3[2][2][4] = {{{1,2,3,4},{5,6,7,8}},{{9,10,11,12},{13,14,15,16}}};
		Array* x_array = (new Array(UInt64Type,5))->Initialize((UInt64*) UInt64ArrayTestArray0);
		CxAssert((Int32Value(x_array->get_Length())).Equals(5));
		CxAssert((UInt64Value(((*((UInt64*)x_array->Address(3)))))).Equals(4));
		Array* x_array2 = (new Array(UInt64Type,4))->Initialize((UInt64*) UInt64ArrayTestArray1);
		CxAssert((UInt64Value(((*((UInt64*)x_array2->Address(1)))))).Equals(2));
		Array* x_array3 = (new Array(UInt64Type,2,4))->Initialize((UInt64*) UInt64ArrayTestArray2);
		CxAssert((UInt64Value(((*((UInt64*)x_array3->Address(0,2)))))).Equals(3));
		Array* x_array4 = (new Array(UInt64Type,2,2,4))->Initialize((UInt64*) UInt64ArrayTestArray3);
		CxAssert((UInt64Value(((*((UInt64*)x_array4->Address(0,0,3)))))).Equals(4));
		((*((UInt64*)x_array4->Address(0,0,3)))) = 6;
		CxAssert((UInt64Value(((*((UInt64*)x_array4->Address(0,0,3)))))).Equals(6));
		x_array4->SetValue(new UInt64Value(4),0,0,3);
		CxAssert((UInt64Value(((*((UInt64*)x_array4->Address(0,0,3)))))).Equals(4));
	}
	void UInt64Test::UInt64MiscTests()
	{
		UInt64 x_num = 0;
		UInt64 x_num2 = 1;
		CxAssert((UInt64Value(Math::Max(x_num,x_num2))).Equals(1));
		CxAssert((UInt64Value(Math::Min(x_num,x_num2))).Equals((UInt64)0));
		StringBuilder* x_stringBuilder = (new StringBuilder());
		x_stringBuilder->Append(x_num2);
		CxAssert(((x_stringBuilder->ToString()))->Equals((new String((Char*)L"1"))));
		x_stringBuilder->Insert(1,x_num);
		CxAssert(((x_stringBuilder->ToString()))->Equals((new String((Char*)L"10"))));
	}
	void UInt64Test::CxAssert(Boolean x_x)
	{
		if ( !x_x )
		{
			x_caBlock->TestFailed((new String((Char*)L"UInt64 TestFailed")));
		}
	}
	void UInt64Test::CxAssert(Boolean x_x,Boolean x_y)
	{
		if ( !(BooleanValue(x_x)).Equals(x_y) )
		{
			x_caBlock->TestFailed((new String((Char*)L"UInt64 TestFailed")));
		}
	}
	UInt64Test::UInt64Test()
	{
	}
}
