#include "CaBlockHeader.h"
namespace UNNAMED
{
	TestNameEnu Typedef::get_Friend()
	{
		return((TestNameEnu)this->x_friend);
	}
	void Typedef::set_Friend(TestNameEnu x_value )
	{
IL_0000:
		this->x_friend = (TestNameEnu)x_value;
		return;
	}
	TestNameEnu Typedef1::x_friend()
	{
		return((TestNameEnu)0);
	}
}
namespace CABlock_Extra_NS
{
}
namespace CABlock_NS
{
	ArrayTest::ArrayTest(CABlock* x_caBlock)
	{
IL_0000:
		this->x_dateTime2dArray = new Array(DateTimeType,4,4);
		this->x_dateTime3dArray = new Array(DateTimeType,4,4,4);
		this->x_timeSpan1dArray = new Array(TimeSpanType,4);
		this->x_timeSpan2dArray = new Array(TimeSpanType,4,4);
		this->x_timeSpan3dArray = new Array(TimeSpanType,4,4,4);
		
		this->x_caBlock = x_caBlock;
		return;
	}
	void ArrayTest::Test()
	{
IL_0000:
		Int32 x_num = 0;
		Int32 x_num2 = 0;
		Int32 x_num3 = 0;
		Int32 x_num4 = (((((x_num++ + x_num2++) + x_num3--) + x_num) + x_num2) + x_num3);
		this->CxAssert((Boolean)(((x_num4) != 0)));
		this->x_caBlock->Send((new String(L"Doing ArrayTest")));
		this->x_caBlock->Send((new String(L"\tDoing TestArrayCreation")));
		this->TestArrayCreation();
		this->x_caBlock->Send((new String(L"\tDoing MiscTest")));
		this->MiscTest();
		this->x_caBlock->Send((new String(L"\tDoing ArrayMethodTests")));
		this->ArrayMethodTests();
		return;
	}
	void ArrayTest::TestArrayCreation()
	{
IL_0000:
		this->x_boolArray = new Array(BooleanType,4);
		this->x_int1dArray = new Array(Int32Type,4);
		(*((Int32*)x_int1dArray->Address(0))) = 1;
		(*((Int32*)x_int1dArray->Address(1))) = 2;
		(*((Int32*)x_int1dArray->Address(2))) = 3;
		(*((Int32*)x_int1dArray->Address(3))) = 4;
		this->CxAssert((Boolean)((((*((Int32*)this->x_int1dArray->Address(1)))) == 2)));
		this->x_int2dArray = new Array(Int32Type,2,4);
		(*((Int32*)x_int2dArray->Address(0,0))) = 1;
		(*((Int32*)x_int2dArray->Address(0,1))) = 2;
		(*((Int32*)x_int2dArray->Address(0,2))) = 3;
		(*((Int32*)x_int2dArray->Address(0,3))) = 4;
		(*((Int32*)x_int2dArray->Address(1,0))) = 4;
		(*((Int32*)x_int2dArray->Address(1,1))) = 5;
		(*((Int32*)x_int2dArray->Address(1,2))) = 6;
		(*((Int32*)x_int2dArray->Address(1,3))) = 7;
		this->CxAssert((Boolean)((((*((Int32*)this->x_int2dArray->Address(0,2)))) == 3)));
		this->x_int3dArray = new Array(Int32Type,2,2,4);
		(*((Int32*)x_int3dArray->Address(0,0,0))) = 1;
		(*((Int32*)x_int3dArray->Address(0,0,1))) = 2;
		(*((Int32*)x_int3dArray->Address(0,0,2))) = 3;
		(*((Int32*)x_int3dArray->Address(0,0,3))) = 4;
		(*((Int32*)x_int3dArray->Address(0,1,0))) = 5;
		(*((Int32*)x_int3dArray->Address(0,1,1))) = 6;
		(*((Int32*)x_int3dArray->Address(0,1,2))) = 7;
		(*((Int32*)x_int3dArray->Address(0,1,3))) = 8;
		(*((Int32*)x_int3dArray->Address(1,0,0))) = 9;
		(*((Int32*)x_int3dArray->Address(1,0,1))) = 10;
		(*((Int32*)x_int3dArray->Address(1,0,2))) = 11;
		(*((Int32*)x_int3dArray->Address(1,0,3))) = 12;
		(*((Int32*)x_int3dArray->Address(1,1,0))) = 13;
		(*((Int32*)x_int3dArray->Address(1,1,1))) = 14;
		(*((Int32*)x_int3dArray->Address(1,1,2))) = 15;
		(*((Int32*)x_int3dArray->Address(1,1,3))) = 16;
		this->CxAssert((Boolean)((((*((Int32*)this->x_int3dArray->Address(0,0,3)))) == 4)));
		this->x_double1dArray = new Array(DoubleType,4);
		(*((Double*)x_double1dArray->Address(0))) = 1;
		(*((Double*)x_double1dArray->Address(1))) = 2;
		(*((Double*)x_double1dArray->Address(2))) = 3;
		(*((Double*)x_double1dArray->Address(3))) = 4;
		this->CxAssert((Boolean)((((*((Double*)this->x_double1dArray->Address(1)))) == 2)));
		this->x_double2dArray = new Array(DoubleType,2,4);
		(*((Double*)x_double2dArray->Address(0,0))) = 1;
		(*((Double*)x_double2dArray->Address(0,1))) = 2;
		(*((Double*)x_double2dArray->Address(0,2))) = 3;
		(*((Double*)x_double2dArray->Address(0,3))) = 4;
		(*((Double*)x_double2dArray->Address(1,0))) = 4;
		(*((Double*)x_double2dArray->Address(1,1))) = 5;
		(*((Double*)x_double2dArray->Address(1,2))) = 6;
		(*((Double*)x_double2dArray->Address(1,3))) = 7;
		this->CxAssert((Boolean)((((*((Double*)this->x_double2dArray->Address(0,2)))) == 3)));
		this->x_double3dArray = new Array(DoubleType,2,2,4);
		(*((Double*)x_double3dArray->Address(0,0,0))) = 1;
		(*((Double*)x_double3dArray->Address(0,0,1))) = 2;
		(*((Double*)x_double3dArray->Address(0,0,2))) = 3;
		(*((Double*)x_double3dArray->Address(0,0,3))) = 4;
		(*((Double*)x_double3dArray->Address(0,1,0))) = 5;
		(*((Double*)x_double3dArray->Address(0,1,1))) = 6;
		(*((Double*)x_double3dArray->Address(0,1,2))) = 7;
		(*((Double*)x_double3dArray->Address(0,1,3))) = 8;
		(*((Double*)x_double3dArray->Address(1,0,0))) = 9;
		(*((Double*)x_double3dArray->Address(1,0,1))) = 10;
		(*((Double*)x_double3dArray->Address(1,0,2))) = 11;
		(*((Double*)x_double3dArray->Address(1,0,3))) = 12;
		(*((Double*)x_double3dArray->Address(1,1,0))) = 13;
		(*((Double*)x_double3dArray->Address(1,1,1))) = 14;
		(*((Double*)x_double3dArray->Address(1,1,2))) = 15;
		(*((Double*)x_double3dArray->Address(1,1,3))) = 16;
		this->CxAssert((Boolean)((((*((Double*)this->x_double3dArray->Address(0,0,3)))) == 4)));
		this->x_dateTime1dArray = new Array(DateTimeType,4);
		(*((DateTime*)x_dateTime1dArray->Address(0))) = DateTime((Int32)(2003), (Int32)(7), (Int32)(23), (Int32)(12), (Int32)(30), (Int32)(30), (Int32)(100));
		(*((DateTime*)x_dateTime1dArray->Address(1))) = DateTime((Int32)(2003), (Int32)(7), (Int32)(23), (Int32)(12), (Int32)(30), (Int32)(30), (Int32)(200));
		(*((DateTime*)x_dateTime1dArray->Address(2))) = DateTime((Int32)(2003), (Int32)(7), (Int32)(23), (Int32)(12), (Int32)(30), (Int32)(30), (Int32)(300));
		(*((DateTime*)x_dateTime1dArray->Address(3))) = DateTime((Int32)(2003), (Int32)(7), (Int32)(23), (Int32)(12), (Int32)(30), (Int32)(30), (Int32)(400));
		this->CxAssert((Boolean)(DateTimeValue((*((DateTime*)this->x_dateTime1dArray->Address(2)))).Equals((DateTime)(DateTime((Int32)(2003), (Int32)(7), (Int32)(23), (Int32)(12), (Int32)(30), (Int32)(30), (Int32)(300))))));
		(*((DateTime*)this->x_dateTime2dArray->Address(1,1))) = DateTime((Int32)(2003), (Int32)(7), (Int32)(23), (Int32)(12), (Int32)(30), (Int32)(30), (Int32)(100));
		(*((DateTime*)this->x_dateTime3dArray->Address(1,1,1))) = DateTime((Int32)(2003), (Int32)(7), (Int32)(23), (Int32)(12), (Int32)(30), (Int32)(30), (Int32)(100));
		(*((TimeSpan*)this->x_timeSpan1dArray->Address(0))) = TimeSpan();
		(*((TimeSpan*)this->x_timeSpan1dArray->Address(0))) = TimeSpan((Int32)(5), (Int32)(4), (Int32)(3), (Int32)(2), (Int32)(100));
		(*((TimeSpan*)this->x_timeSpan1dArray->Address(1))) = TimeSpan((Int32)(5), (Int32)(4), (Int32)(3), (Int32)(2), (Int32)(200));
		(*((TimeSpan*)this->x_timeSpan1dArray->Address(2))) = TimeSpan((Int32)(5), (Int32)(4), (Int32)(3), (Int32)(2), (Int32)(300));
		(*((TimeSpan*)this->x_timeSpan1dArray->Address(3))) = TimeSpan((Int32)(5), (Int32)(4), (Int32)(3), (Int32)(2), (Int32)(400));
		(*((TimeSpan*)this->x_timeSpan2dArray->Address(1,1))) = TimeSpan((Int32)(5), (Int32)(4), (Int32)(3), (Int32)(2), (Int32)(100));
		(*((TimeSpan*)this->x_timeSpan3dArray->Address(1,1,1))) = TimeSpan((Int32)(5), (Int32)(4), (Int32)(3), (Int32)(2), (Int32)(100));
		return;
	}
	void ArrayTest::MiscTest()
	{
IL_0000:
		this->CxAssert((Boolean)(((this->x_int3dArray->GetLength((Int32)(2))) == 4)));
		this->CxAssert((Boolean)(((this->x_int3dArray->GetLowerBound((Int32)(2))) == 0)));
		this->CxAssert((Boolean)(((this->x_int3dArray->GetUpperBound((Int32)(2))) == 3)));
		Array* x_array = this->x_dateTime1dArray;
		Int32 x_i = 0;
		
		{
IL_0065:
			if (((x_i) < x_array->get_Length()))
			{
				goto IL_0056;
			}
			else
			{
				goto leaveBlock2;
			}

		}
		{
IL_0056:
			DateTime x_dateTime = (*((DateTime*)x_array->Address(x_i)));
			String* x_text = DateTimeValue(x_dateTime).ToString();
			goto IL_0064;
		}
		{
IL_0064:
			++x_i;
			goto IL_0065;
		}
leaveBlock2:

		return;
	}
	void ArrayTest::ArrayMethodTests()
	{
IL_0000:
		Int32 x_length = this->x_int3dArray->get_Length();
		this->CxAssert((Boolean)(((x_length) == 16)));
		this->CxAssert((Boolean)(((this->x_int1dArray->get_Rank()) == 1)));
		this->CxAssert((Boolean)(((this->x_int2dArray->get_Rank()) == 2)));
		this->CxAssert((Boolean)(((this->x_int3dArray->get_Rank()) == 3)));
		Array* x_array = new Array(DateTimeType,5);
		Array::Copy(this->x_dateTime1dArray, x_array, (Int32)(this->x_dateTime1dArray->get_Length()));
		Int32 x_i = 0;
		
		{
IL_00aa:
			if (((x_i) < this->x_dateTime1dArray->get_Length()))
			{
				goto IL_0087;
			}
			else
			{
				goto leaveBlock2;
			}

		}
		{
IL_0087:
			DateTime x_d = (*((DateTime*)this->x_dateTime1dArray->Address(x_i)));
			DateTime x_d2 = (*((DateTime*)x_array->Address(x_i)));
			this->CxAssert((Boolean)(DateTimeValue::Equals((DateTime)(x_d), (DateTime)(x_d2))));
			goto IL_00a8;
		}
		{
IL_00a8:
			++x_i;
			goto IL_00aa;
		}
leaveBlock2:

		this->x_dateTime1dArray->CopyTo(x_array, (Int32)(1));
		Int32 x_j = 1;
		
		{
IL_00f8:
			if (((x_j) < x_array->get_Length()))
			{
				goto IL_00ec;
			}
			else
			{
				goto leaveBlock3;
			}

		}
		{
IL_00ec:
			this->CxAssert((Boolean)(DateTimeValue::Equals((DateTime)((*((DateTime*)this->x_dateTime1dArray->Address((x_j - 1))))), (DateTime)((*((DateTime*)x_array->Address(x_j)))))));
			goto IL_00f6;
		}
		{
IL_00f6:
			++x_j;
			goto IL_00f8;
		}
leaveBlock3:

		this->CxAssert((Boolean)(TimeSpanValue((TimeSpan((Int32)(5), (Int32)(4), (Int32)(3), (Int32)(2), (Int32)(100)))).Equals(this->x_timeSpan3dArray->GetValue((Int32)(1), (Int32)(1), (Int32)(1)))));
		TimeSpan x_timeSpan = TimeSpan((Int32)(5), (Int32)(4), (Int32)(3), (Int32)(2), (Int32)(101));
		Array* x_indices = new Array(Int32Type,3);
		(*((Int32*)x_indices->Address(0))) = 1;
		(*((Int32*)x_indices->Address(1))) = 1;
		(*((Int32*)x_indices->Address(2))) = 1;
		this->x_timeSpan3dArray->SetValue((new TimeSpanValue(x_timeSpan)), x_indices);
		this->CxAssert((Boolean)(TimeSpanValue(x_timeSpan).Equals(this->x_timeSpan3dArray->GetValue(x_indices))));
		(*((Double*)this->x_double3dArray->Address(1,1,3))) = 22;
		Double x_num = (*((Double*)this->x_double3dArray->Address(1,1,3)));
		this->CxAssert((Boolean)(((x_num) == 22)));
		this->CxAssert((Boolean)(DoubleValue((22)).Equals(this->x_double3dArray->GetValue((Int32)(1), (Int32)(1), (Int32)(3)))));
		this->x_timeSpan3dArray->SetValue((new TimeSpanValue(x_timeSpan)), (Int32)(0), (Int32)(0), (Int32)(0));
		this->CxAssert((Boolean)(TimeSpanValue::Equals((TimeSpan)((*((TimeSpan*)this->x_timeSpan3dArray->Address(0,0,0)))), (TimeSpan)(x_timeSpan))));
		(*((SByte*)this->x_boolArray->Address(0))) = 1;
		this->CxAssert((Boolean)((*((Byte*)this->x_boolArray->Address(0)))));
		Array::Clear(this->x_boolArray, (Int32)(0), (Int32)(this->x_boolArray->get_Length()));
		this->CxAssert((Boolean)((((*((Byte*)this->x_boolArray->Address(0)))) == 0)));
		this->x_int1dArray->SetValue((new Int32Value(1)), (Int32)(2));
		this->CxAssert((Boolean)((((*((Int32*)this->x_int1dArray->Address(1)))) == 2)));
		Array* x_array2 = new Array(DoubleType,4);
		(*((Double*)x_array2->Address(0))) = 1;
		(*((Double*)x_array2->Address(1))) = 2;
		(*((Double*)x_array2->Address(2))) = 3;
		(*((Double*)x_array2->Address(3))) = 4;
		x_array2->SetValue((new Int32Value(2)), (Int32)(1));
		this->CxAssert((Boolean)((((*((Double*)x_array2->Address(1)))) == 2)));
		x_array2->SetValue((new UInt32Value(2)), (Int32)(1));
		this->CxAssert((Boolean)((((*((Double*)x_array2->Address(1)))) == 2)));
		return;
	}
	void ArrayTest::CxAssert(Boolean x_x)
	{
IL_0000:
		if (((x_x) == 0))
		{
			this->x_caBlock->TestFailed((new String(L"Array TestFailed")));
		}

		return;
	}
	BasicTest::BasicTest(CABlock* x_caBlock)
	{
IL_0000:
		this->x_field1 = 0;
		
		this->x_caBlock = x_caBlock;
		return;
	}
	void BasicTest::Test()
	{
IL_0000:
		this->x_caBlock->Send((new String(L"Doing BasicTest")));
		this->x_caBlock->Send((new String(L"\tDoing FieldTest")));
		this->FieldTest();
		this->x_caBlock->Send((new String(L"\tDoing SwitchTest")));
		this->SwitchTest();
		this->x_caBlock->Send((new String(L"\tDoing IfThenElseTest")));
		this->IfThenElseTest();
		this->x_caBlock->Send((new String(L"\tDoing StructTest")));
		this->StructTest();
		this->x_caBlock->Send((new String(L"\tDoing StructTest2")));
		this->StructTest2();
		this->x_caBlock->Send((new String(L"\tDoing VirtualMethodTest")));
		this->VirtualMethodTest();
		this->x_caBlock->Send((new String(L"\tDoing PassByReferenceTest")));
		this->PassByReferenceTest();
		this->x_caBlock->Send((new String(L"\tDoing Namespace Test")));
		this->TestUsingNamespace();
		this->x_caBlock->Send((new String(L"\tDoing Complex conditions")));
		this->ComplexConditions();
		this->x_caBlock->Send((new String(L"\tDoing Naming test")));
		this->TestNames();
		return;
	}
	void BasicTest::FieldTest()
	{
IL_0000:
		BasicTest* x_basicTest = (new BasicTest(this->x_caBlock));
		Int32 x_num = this->x_field1;
		this->CxAssert((Boolean)(((x_num) == this->x_field1)));
		Int32 x_num2 = x_basicTest->x_field1;
		this->CxAssert((Boolean)(((x_num2) == x_basicTest->x_field1)));
		DateTime x_maxValue = DateTimeValue::MaxValue;
		this->CxAssert((Boolean)(DateTimeValue::Equals((DateTime)(x_maxValue), (DateTime)(DateTimeValue::MaxValue))));
		Object* x_obj = (new Object());
		this->CxAssert((Boolean)(((x_obj->ToString()) != nullptr)));
		this->CxAssert((Boolean)(x_obj->Equals(x_obj)));
		this->CxAssert((Boolean)(Object::Equals(x_obj, x_obj)));
		return;
	}
	void BasicTest::SwitchTest()
	{
IL_0000:
		this->x_field1 = 1;
		Int32 x_num = -1;
		
		{
IL_001e:
			switch(this->x_field1++)
			{
				case 0:
				goto IL_003f;
				case 1:
				goto IL_0043;
				case 1000:
				goto IL_0047;
				case 100000:
				goto IL_004f;
				default:
				goto leaveBlock2;
			}

		}
		{
IL_004f:
			x_num = 100000;
			goto leaveBlock2;
		}
		{
IL_0047:
			x_num = 1000;
			goto leaveBlock2;
		}
		{
IL_0043:
			x_num = 1;
			goto leaveBlock2;
		}
		{
IL_003f:
			x_num = 0;
			goto leaveBlock2;
		}
leaveBlock2:

		this->CxAssert((Boolean)(((x_num) == 1)));
		this->CxAssert((Boolean)(((this->x_field1) == 2)));
		return;
	}
	void BasicTest::IfThenElseTest()
	{
IL_0000:
		this->x_field1 = 1;
		if (((this->x_field1) == 1))
		{
			this->x_field1 = 2;
			if (((this->x_field1) == 3))
			{
				this->x_field1 = 4;
			}
			else
			{
				this->x_field1 = 5;
			}

		}
		else
		{
			this->x_field1 = 6;
		}

		this->CxAssert((Boolean)(((this->x_field1) == 5)));
		this->CxAssert((Boolean)(Object::Equals(nullptr, nullptr)));
		return;
	}
	void BasicTest::StructTest()
	{
IL_0000:
		TestStruct x_ts = TestStruct((Int32)(2));
		this->CxAssert((Boolean)(((x_ts.get_Data()) == 2)));
		x_ts.set_Data((Int32)(3));
		this->CxAssert((Boolean)(((x_ts.get_Data()) == 3)));
		x_ts = TestStruct::op_Addition(x_ts,1);
		this->CxAssert((Boolean)(((x_ts.get_Data()) == 4)));
		this->CxAssert((Boolean)((((TestStruct::op_BitwiseAnd(x_ts, (Int32)(1))).get_Data()) == 0)));
		return;
	}
	void BasicTest::StructTest2()
	{
IL_0000:
		TestStruct3 x_testStruct;
		x_testStruct.x_ts.x_data = 6;
		this->CxAssert((Boolean)((((x_testStruct.x_ts).x_data) == 6)));
		this->x_ts3.x_ts.x_data = 7;
		this->CxAssert((Boolean)(((this->x_ts3.x_ts.x_data) == 7)));
		return;
	}
	void BasicTest::VirtualMethodTest()
	{
IL_0000:
		TestAbstract* x_testAbstract = (new TestAbstract());
		this->CxAssert((Boolean)(((x_testAbstract->MustImplement()) == 2)));
		this->CxAssert((Boolean)(((x_testAbstract->DidImplement()) == 1)));
		return;
	}
	void BasicTest::PassByReferenceTest()
	{
IL_0000:
		Int32 x_data = 0;
		DateTime x_data2 = DateTime();
		TimeSpan x_data3 = TimeSpan();
		String* x_data4 = nullptr;
		TestAbstract* x_data5 = nullptr;
		this->RefMethod(x_data);
		this->CxAssert((Boolean)(((x_data) == 1)));
		this->RefMethod(x_data2);
		this->CxAssert((Boolean)(((DateTimeValue(x_data2).get_Ticks()) == ((Int64)1000))));
		this->RefMethod(x_data3);
		this->CxAssert((Boolean)(((TimeSpanValue(x_data3).get_Ticks()) == ((Int64)1000))));
		this->RefMethod(x_data4);
		this->CxAssert((Boolean)(String::Equals(x_data4, (new String(L"Test")))));
		this->RefMethod(x_data5);
		this->CxAssert((Boolean)(((x_data5->MustImplement()) == 2)));
		return;
	}
	void BasicTest::RefMethod(Int32&  x_data)
	{
IL_0000:
		if (((x_data) == 0))
		{
			x_data = 1;
		}

		return;
	}
	void BasicTest::RefMethod(DateTime&  x_data)
	{
IL_0000:
		x_data = DateTime((Int64)(((Int64)1000)));
		return;
	}
	void BasicTest::RefMethod(TimeSpan&  x_data)
	{
IL_0000:
		x_data = TimeSpan((Int64)(((Int64)1000)));
		return;
	}
	void BasicTest::RefMethod(String*&  x_data)
	{
IL_0000:
		if (((x_data) == nullptr))
		{
			x_data = (new String(L"Test"));
		}

		return;
	}
	void BasicTest::RefMethod(TestAbstract*&  x_data)
	{
IL_0000:
		if (((x_data) == nullptr))
		{
			x_data = (new TestAbstract());
		}

		return;
	}
	void BasicTest::TestUsingNamespace()
	{
IL_0000:
		TestNamespaceClass* x_testNamespaceClass = (new TestNamespaceClass());
		this->CxAssert((Boolean)(((x_testNamespaceClass) != nullptr)));
		return;
	}
	void BasicTest::CxAssert(Boolean x_x)
	{
IL_0000:
		if (((x_x) == 0))
		{
			this->x_caBlock->TestFailed((new String(L"BaseTest TestFailed")));
		}

		return;
	}
	void BasicTest::ComplexConditions()
	{
IL_0000:
		this->x_field1 = 0;
		this->CxAssert((Boolean)((((this->x_field1) < 1) && ((this->x_field1) < 2) && ((this->x_field1) < 3))));
		this->x_field1 = 10;
		this->CxAssert((Boolean)((((this->x_field1) >= 1) || ((this->x_field1) >= 2) || ((this->x_field1) >= 3))));
		this->x_field1 = 2;
		Boolean x_flag = ((this->x_field1) < 1);
		Boolean x_flag2 = ((this->x_field1) < 2);
		Boolean x_flag3 = ((this->x_field1) < 3);
		Boolean x_flag4 = ((this->x_field1) < 4);
		Boolean x_flag5 = ((this->x_field1) < 5);
		this->CxAssert((Boolean)((((((x_flag | x_flag2) & x_flag3)) == 0) || (((x_flag4 & x_flag5) & x_flag3) | x_flag2))));
		this->CxAssert((Boolean)(((((((x_flag) == 0) && ((x_flag2) == 0)) & x_flag3) & x_flag4) & x_flag5)));
		this->CxAssert((Boolean)(((x_flag | x_flag2) || ((x_flag3 & x_flag4) & x_flag5))));
		this->CxAssert((Boolean)(((((((x_flag) == 0) & x_flag3) && ((x_flag2) == 0)) & x_flag4) & x_flag5)));
		this->CxAssert((Boolean)(this->TestThis((Int32)(1), (Int32)(2))));
		this->CxAssert((Boolean)(((this->TestThis((Int32)(6), (Int32)(2))) == 0)));
		this->CxAssert((Boolean)(this->TestThis((Int32)(60), (Int32)(2))));
		return;
	}
	Boolean BasicTest::TestThis(Int32 x_a,Int32 x_b)
	{
		return((Boolean)(((x_a) < 5) && ((x_b) < 3) || (((x_a + x_b)) > 20)));
	}
	void BasicTest::TestNames()
	{
IL_0000:
		Typedef* x_typedef = (new Typedef());
		x_typedef->set_Friend((TestNameEnu)(0));
		this->CxAssert((Boolean)(((x_typedef->get_Friend()) == 0)));
		return;
	}
	TestAbstract::TestAbstract() : Abstract (1,2)
	{
IL_0000:
		
		return;
	}
	Int32 TestAbstract::MustImplement()
	{
		return((Int32)this->x_data2);
	}
	Int32 TestAbstract::MustImplement(Int32 x_i)
	{
		return((Int32)this->x_data2);
	}
	Int32 TestAbstract::MustImplement(Int64 x_i)
	{
		return((Int32)this->x_data2);
	}
	String* TestAbstract::ToString()
	{
		return((String*)(new String(L"TestAbstract")));
	}
	Int32 TestStruct::get_Data()
	{
		return((Int32)this->x_data);
	}
	void TestStruct::set_Data(Int32 x_value )
	{
IL_0000:
		this->x_data = x_value;
		return;
	}
	TestStruct::TestStruct(Int32 x_i)
	{
IL_0000:
		this->x_data = x_i;
		return;
	}
	TestStruct TestStruct::op_Addition(TestStruct x_ts,Int32 x_newData)
	{
IL_0000:
		x_ts.x_data += x_newData;
		return((TestStruct)x_ts);
	}
	TestStruct TestStruct::op_BitwiseAnd(TestStruct x_ts,Int32 x_newData)
	{
IL_0000:
		x_ts.x_data &= x_newData;
		return((TestStruct)x_ts);
	}
	Abstract::Abstract(Int32 x_i,Int32 x_j)
	{
IL_0000:
		
		this->x_data1 = x_i;
		this->x_data2 = x_j;
		return;
	}
	Int32 Abstract::DidImplement()
	{
		return((Int32)this->x_data1);
	}
	BooleanTest::BooleanTest(CABlock* x_caBlock)
	{
IL_0000:
		
		this->x_caBlock = x_caBlock;
		return;
	}
	void BooleanTest::Test()
	{
IL_0000:
		this->x_caBlock->Send((new String(L"Doing BooleanTest")));
		this->x_caBlock->Send((new String(L"\tDoing RunBooleanTest")));
		this->RunBooleanTest();
		this->x_caBlock->Send((new String(L"\tDoing BoolOperators")));
		this->BoolOperators();
		this->x_caBlock->Send((new String(L"\tDoing BoolBoxTest")));
		this->BoolBoxTest();
		return;
	}
	void BooleanTest::BoolBoxTest()
	{
IL_0000:
		Boolean x_flag = 1;
		Object* x_obj = (new BooleanValue(x_flag));
		this->CxAssert((Boolean)(BooleanValue(x_flag).Equals(x_obj)));
		this->CxAssert((Boolean)(x_obj->Equals(x_obj)));
		this->CxAssert((Boolean)(x_obj->get_AsBoolean()));
		this->CxAssert((Boolean)(String::Equals(x_obj->ToString(), (new String(L"True")))));
		return;
	}
	void BooleanTest::RunBooleanTest()
	{
IL_0000:
		Boolean x_flag = 1;
		Object* x_obj = (new BooleanValue(x_flag));
		this->CxAssert((Boolean)(((BooleanValue(x_flag).CompareTo((Boolean)(1))) == 0)));
		this->CxAssert((Boolean)(((BooleanValue(x_flag).CompareTo(x_obj)) == 0)));
		this->CxAssert((Boolean)(BooleanValue(x_flag).Equals((Boolean)(1))));
		this->CxAssert((Boolean)(BooleanValue::Parse((new String(L"True")))));
		this->CxAssert((Boolean)(String::Equals((new String(L"True")), BooleanValue(x_flag).ToString())));
		this->CxAssert((Boolean)(String::Equals(BooleanValue::FalseString, (new String(L"False")))));
		this->CxAssert((Boolean)(String::Equals(BooleanValue::TrueString, (new String(L"True")))));
		return;
	}
	void BooleanTest::BoolOperators()
	{
IL_0000:
		Boolean x_flag = 1;
		Boolean x_flag2 = 0;
		this->CxAssert((Boolean)((x_flag & x_flag2)), (Boolean)(0));
		this->CxAssert((Boolean)((x_flag | x_flag2)));
		this->CxAssert((Boolean)((x_flag ^ x_flag2)));
		this->CxAssert((Boolean)(((x_flag) == 0)), (Boolean)(0));
		this->CxAssert((Boolean)((x_flag & x_flag2)), (Boolean)(0));
		this->CxAssert((Boolean)((x_flag | x_flag2)));
		this->CxAssert((Boolean)(((x_flag) == x_flag2)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_flag) != x_flag2)));
		this->CxAssert((Boolean)(x_flag = x_flag));
		this->CxAssert((Boolean)(x_flag = (x_flag | 1)));
		this->CxAssert((Boolean)(x_flag = x_flag));
		return;
	}
	void BooleanTest::CxAssert(Boolean x_x,Boolean x_y)
	{
IL_0000:
		if (((x_x) != x_y))
		{
			this->x_caBlock->TestFailed((new String(L"Boolean TestFailed")));
		}

		return;
	}
	void BooleanTest::CxAssert(Boolean x_x)
	{
IL_0000:
		if (((x_x) == 0))
		{
			this->x_caBlock->TestFailed((new String(L"Boolean TestFailed")));
		}

		return;
	}
	BufferTest::BufferTest(CABlock* x_caBlock)
	{
IL_0000:
		
		this->x_caBlock = x_caBlock;
		return;
	}
	void BufferTest::Test()
	{
IL_0000:
		this->x_caBlock->Send((new String(L"Doing Buffer Test")));
		this->x_in1dArray = new Array(Int32Type,5);
		(*((Int32*)x_in1dArray->Address(0))) = 0;
		(*((Int32*)x_in1dArray->Address(1))) = 1;
		(*((Int32*)x_in1dArray->Address(2))) = 2;
		(*((Int32*)x_in1dArray->Address(3))) = 3;
		(*((Int32*)x_in1dArray->Address(4))) = 4;
		this->x_out1dArray = new Array(Int32Type,5);
		(*((Int32*)x_out1dArray->Address(0))) = 5;
		(*((Int32*)x_out1dArray->Address(1))) = 4;
		(*((Int32*)x_out1dArray->Address(2))) = 3;
		(*((Int32*)x_out1dArray->Address(3))) = 2;
		(*((Int32*)x_out1dArray->Address(4))) = 1;
		Int32 x_count = (this->x_in1dArray->GetLength((Int32)(0)) * 4);
		Buffer::BlockCopy(this->x_in1dArray, (Int32)(0), this->x_out1dArray, (Int32)(0), (Int32)(x_count));
		Boolean x_x = 1;
		Int32 x_i = 0;
		
		{
IL_008e:
			if (((x_i) < 5))
			{
				goto IL_0082;
			}
			else
			{
				goto leaveBlock2;
			}

		}
		{
IL_0082:
			if ((((*((Int32*)this->x_in1dArray->Address(x_i)))) != (*((Int32*)this->x_out1dArray->Address(x_i)))))
			{
				x_x = 0;
				goto leaveBlock2;
			}

			goto IL_008d;
		}
		{
IL_008d:
			++x_i;
			goto IL_008e;
		}
leaveBlock2:

		this->CxAssert((Boolean)(x_x));
		return;
	}
	void BufferTest::CxAssert(Boolean x_x)
	{
IL_0000:
		if (((x_x) == 0))
		{
			this->x_caBlock->TestFailed((new String(L"Buffer Test Failed")));
		}

		return;
	}
	ByteTest::ByteTest(CABlock* x_caBlock)
	{
IL_0000:
		
		this->x_caBlock = x_caBlock;
		return;
	}
	void ByteTest::Test()
	{
IL_0000:
		this->x_caBlock->Send((new String(L"Doing ByteTest")));
		this->x_caBlock->Send((new String(L"\tDoing ByteMethodsTest")));
		this->ByteMethodsTest();
		this->x_caBlock->Send((new String(L"\tDoing DoUnSignedMath")));
		this->DoUnSignedMath();
		this->x_caBlock->Send((new String(L"\tDoing ByteOperators")));
		this->ByteOperators();
		this->x_caBlock->Send((new String(L"\tDoing ByteArrayTests")));
		this->ByteArrayTests();
		this->x_caBlock->Send((new String(L"\tDoing ByteMiscTests")));
		this->ByteMiscTests();
		return;
	}
	void ByteTest::ByteMethodsTest()
	{
IL_0000:
		Byte x_b = 5;
		this->CxAssert((Boolean)(((ByteValue(x_b).CompareTo((Byte)(5))) == 0)));
		this->CxAssert((Boolean)(((ByteValue(x_b).CompareTo((new ByteValue(5)))) == 0)));
		this->CxAssert((Boolean)(ByteValue(x_b).Equals((Byte)(5))));
		this->CxAssert((Boolean)(ByteValue(x_b).Equals((new ByteValue(5)))));
		this->CxAssert((Boolean)(((ByteValue::Parse((new String(L"77")))) == 77)));
		this->CxAssert((Boolean)(String::Equals((new String(L"5")), ByteValue(x_b).ToString())));
		x_b = ByteValue::MaxValue;
		this->CxAssert((Boolean)(((ByteValue::MaxValue) == x_b)));
		x_b = 0;
		this->CxAssert((Boolean)(((x_b) == 0)));
		String* x_text = ByteValue((ByteValue::MaxValue)).ToString();
		this->CxAssert((Boolean)(String::Equals(x_text, (new String(L"255")))));
		this->CxAssert((Boolean)(((ByteValue::Parse(x_text)) == ByteValue::MaxValue)));
		String* x_text2 = ByteValue((0)).ToString();
		this->CxAssert((Boolean)(String::Equals(x_text2, (new String(L"0")))));
		this->CxAssert((Boolean)(((ByteValue::Parse(x_text2)) == 0)));
		Int32 x_num = 50;
		Byte x_b2 = ((Byte)x_num);
		Object* x_obj = (new Int32Value(x_num));
		Int32 x_num2 = x_obj->get_AsInt32();
		this->CxAssert((Boolean)(((x_b2) == 50)));
		this->CxAssert((Boolean)(((x_num2) == 50)));
		x_b2 = ByteValue::MaxValue;
		x_b2 = ((Byte)(x_b2 + 1));
		this->CxAssert((Boolean)(((x_b2) == 0)));
		Object* x_obj2 = (new ByteValue(5));
		this->CxAssert((Boolean)(x_obj2->Equals((new ByteValue(5)))));
		this->CxAssert((Boolean)(String::Equals(x_obj2->ToString(), (new String(L"5")))));
		return;
	}
	void ByteTest::DoUnSignedMath()
	{
IL_0000:
		Byte x_b = 60;
		Byte x_b2 = 120;
		Byte x_b3 = 6;
		Byte x_b4 = 12;
		Int32 x_num = 1;
		this->CxAssert((Boolean)(((1) <= x_b)));
		this->CxAssert((Boolean)(((x_b) >= 1)));
		this->CxAssert((Boolean)(((x_b) >= x_num)));
		this->CxAssert((Boolean)(((x_num) <= x_b)));
		x_num = (x_num + x_b);
		this->CxAssert((Boolean)(((x_num) == 61)));
		this->CxAssert((Boolean)((((x_b + x_b2)) == 180)));
		Byte x_b5 = ((Byte)(x_b - x_b2));
		this->CxAssert((Boolean)(((x_b5) == 196)));
		this->CxAssert((Boolean)(((((Byte)(x_b - x_b2))) == 196)));
		this->CxAssert((Boolean)((((x_b3 * x_b4)) == 72)));
		this->CxAssert((Boolean)((((x_b2 / x_b)) == 2)));
		this->CxAssert((Boolean)((((x_b >> 2)) == 15)));
		this->CxAssert((Boolean)((((x_b << 1)) == 120)));
		Int32 x_num2 = 11;
		this->CxAssert((Boolean)((((x_num2 % 5)) == 1)));
		x_num2 = 8;
		this->CxAssert((Boolean)((((x_num2 | 1)) == 9)));
		this->CxAssert((Boolean)((((x_num2 & 1)) == 0)));
		this->CxAssert((Boolean)(((++x_num2) == 9)));
		this->CxAssert((Boolean)(((--x_num2) == 8)));
		this->CxAssert((Boolean)(((x_num2 = (x_num2 * 2)) == 16)));
		this->CxAssert((Boolean)(((x_num2 = (x_num2 / 2)) == 8)));
		this->CxAssert((Boolean)(((x_num2 = (x_num2 % 2)) == 0)));
		this->CxAssert((Boolean)(((x_num2 = (x_num2 | 4)) == 4)));
		this->CxAssert((Boolean)(((x_num2 = (x_num2 & 4)) == 4)));
		this->CxAssert((Boolean)((((0 - x_b)) == -60)));
		this->CxAssert((Boolean)(((x_b) == 60)));
		Byte x_b6 = 0;
		this->CxAssert((Boolean)(((((Byte)~x_b6)) == ByteValue::MaxValue)));
		this->CxAssert((Boolean)(((x_b6 = ((Byte)(x_b6 + 1))) == 1)));
		this->CxAssert((Boolean)(((x_b6 = ((Byte)(x_b6 - 1))) == 0)));
		return;
	}
	void ByteTest::ByteOperators()
	{
IL_0000:
		Byte x_b = 66;
		Char x_c = 1;
		Byte x_b2 = 1;
		SByte x_b3 = 1;
		Int16 x_num = 1;
		Int32 x_num2 = 1;
		Int64 x_num3 = ((Int64)1);
		UInt16 x_num4 = 1;
		UInt32 x_num5 = 1;
		UInt64 x_num6 = ((Int64)1);
		Single x_num7 = 1;
		Double x_num8 = 1;
		this->CxAssert((Boolean)(((x_b) == 66)));
		this->CxAssert((Boolean)((((x_b + x_c)) == 67)));
		this->CxAssert((Boolean)((((x_b + x_b2)) == 67)));
		this->CxAssert((Boolean)((((x_b + x_b3)) == 67)));
		this->CxAssert((Boolean)((((x_b + x_num)) == 67)));
		this->CxAssert((Boolean)((((x_b + x_num2)) == 67)));
		this->CxAssert((Boolean)((((((UInt64)x_b) + x_num3)) == ((Int64)67))));
		this->CxAssert((Boolean)((((x_b + x_num4)) == 67)));
		this->CxAssert((Boolean)((((x_b + x_num5)) == 67)));
		this->CxAssert((Boolean)((((((UInt64)x_b) + x_num6)) == ((Int64)67))));
		this->CxAssert((Boolean)((((((Single)x_b) + x_num7)) == 67)));
		this->CxAssert((Boolean)((((((Double)x_b) + x_num8)) == 67)));
		this->CxAssert((Boolean)((((x_b - x_c)) == 65)));
		this->CxAssert((Boolean)((((x_b - x_b2)) == 65)));
		this->CxAssert((Boolean)((((x_b - x_b3)) == 65)));
		this->CxAssert((Boolean)((((x_b - x_num)) == 65)));
		this->CxAssert((Boolean)((((x_b - x_num2)) == 65)));
		this->CxAssert((Boolean)((((((UInt64)x_b) - x_num3)) == ((Int64)65))));
		this->CxAssert((Boolean)((((x_b - x_num4)) == 65)));
		this->CxAssert((Boolean)((((x_b - x_num5)) == 65)));
		this->CxAssert((Boolean)((((((UInt64)x_b) - x_num6)) == ((Int64)65))));
		this->CxAssert((Boolean)((((((Single)x_b) - x_num7)) == 65)));
		this->CxAssert((Boolean)((((((Double)x_b) - x_num8)) == 65)));
		this->CxAssert((Boolean)((((x_b * x_c)) == 66)));
		this->CxAssert((Boolean)((((x_b * x_b2)) == 66)));
		this->CxAssert((Boolean)((((x_b * x_b3)) == 66)));
		this->CxAssert((Boolean)((((x_b * x_num)) == 66)));
		this->CxAssert((Boolean)((((x_b * x_num2)) == 66)));
		this->CxAssert((Boolean)((((((UInt64)x_b) * x_num3)) == ((Int64)66))));
		this->CxAssert((Boolean)((((x_b * x_num4)) == 66)));
		this->CxAssert((Boolean)((((x_b * x_num5)) == 66)));
		this->CxAssert((Boolean)((((((UInt64)x_b) * x_num6)) == ((Int64)66))));
		this->CxAssert((Boolean)((((((Single)x_b) * x_num7)) == 66)));
		this->CxAssert((Boolean)((((((Double)x_b) * x_num8)) == 66)));
		this->CxAssert((Boolean)((((x_b / x_c)) == 66)));
		this->CxAssert((Boolean)((((x_b / x_b2)) == 66)));
		this->CxAssert((Boolean)((((x_b / x_b3)) == 66)));
		this->CxAssert((Boolean)((((x_b / x_num)) == 66)));
		this->CxAssert((Boolean)((((x_b / x_num2)) == 66)));
		this->CxAssert((Boolean)((((((UInt64)x_b) / x_num3)) == ((Int64)66))));
		this->CxAssert((Boolean)((((x_b / x_num4)) == 66)));
		this->CxAssert((Boolean)((((x_b / x_num5)) == 66)));
		this->CxAssert((Boolean)((((((UInt64)x_b) / x_num6)) == ((Int64)66))));
		this->CxAssert((Boolean)((((((Single)x_b) / x_num7)) == 66)));
		this->CxAssert((Boolean)((((((Double)x_b) / x_num8)) == 66)));
		this->CxAssert((Boolean)((((x_b % x_c)) == 0)));
		this->CxAssert((Boolean)((((x_b % x_b2)) == 0)));
		this->CxAssert((Boolean)((((x_b % x_b3)) == 0)));
		this->CxAssert((Boolean)((((x_b % x_num)) == 0)));
		this->CxAssert((Boolean)((((x_b % x_num2)) == 0)));
		this->CxAssert((Boolean)((((((UInt64)x_b) % x_num3)) == ((Int64)0))));
		this->CxAssert((Boolean)((((x_b % x_num4)) == 0)));
		this->CxAssert((Boolean)((((x_b % x_num5)) == 0)));
		this->CxAssert((Boolean)((((((UInt64)x_b) % x_num6)) == ((Int64)0))));
		this->CxAssert((Boolean)(((DoubleValue::Modulus(((Single)x_b),x_num7)) == 0)));
		this->CxAssert((Boolean)(((DoubleValue::Modulus(((Double)x_b),x_num8)) == 0)));
		this->CxAssert((Boolean)((((x_b & x_c)) == 0)));
		this->CxAssert((Boolean)((((x_b & x_b2)) == 0)));
		this->CxAssert((Boolean)((((x_b & x_b3)) == 0)));
		this->CxAssert((Boolean)((((x_b & x_num)) == 0)));
		this->CxAssert((Boolean)((((x_b & x_num2)) == 0)));
		this->CxAssert((Boolean)((((((UInt64)x_b) & x_num3)) == ((Int64)0))));
		this->CxAssert((Boolean)((((x_b & x_num4)) == 0)));
		this->CxAssert((Boolean)((((x_b & x_num5)) == 0)));
		this->CxAssert((Boolean)((((((UInt64)x_b) & x_num6)) == ((Int64)0))));
		this->CxAssert((Boolean)((((x_b | x_c)) == 67)));
		this->CxAssert((Boolean)((((x_b | x_b2)) == 67)));
		this->CxAssert((Boolean)((((x_b | x_b3)) == 67)));
		this->CxAssert((Boolean)((((x_b | x_num)) == 67)));
		this->CxAssert((Boolean)((((x_b | x_num2)) == 67)));
		this->CxAssert((Boolean)((((((UInt64)x_b) | x_num3)) == ((Int64)67))));
		this->CxAssert((Boolean)((((x_b | x_num4)) == 67)));
		this->CxAssert((Boolean)((((x_b | x_num5)) == 67)));
		this->CxAssert((Boolean)((((((UInt64)x_b) | x_num6)) == ((Int64)67))));
		this->CxAssert((Boolean)((((x_b ^ x_c)) == 67)));
		this->CxAssert((Boolean)((((x_b ^ x_b2)) == 67)));
		this->CxAssert((Boolean)((((x_b ^ x_b3)) == 67)));
		this->CxAssert((Boolean)((((x_b ^ x_num)) == 67)));
		this->CxAssert((Boolean)((((x_b ^ x_num2)) == 67)));
		this->CxAssert((Boolean)((((((UInt64)x_b) ^ x_num3)) == ((Int64)67))));
		this->CxAssert((Boolean)((((x_b ^ x_num4)) == 67)));
		this->CxAssert((Boolean)((((x_b ^ x_num5)) == 67)));
		this->CxAssert((Boolean)((((((UInt64)x_b) ^ x_num6)) == ((Int64)67))));
		this->CxAssert((Boolean)(((((Byte)~x_b)) == 189)));
		this->CxAssert((Boolean)(((x_c) < x_b)));
		this->CxAssert((Boolean)(((x_b2) < x_b)));
		this->CxAssert((Boolean)(((x_b3) < x_b)));
		this->CxAssert((Boolean)(((x_num) < x_b)));
		this->CxAssert((Boolean)(((x_num2) < x_b)));
		this->CxAssert((Boolean)(((x_num3) < ((UInt64)x_b))));
		this->CxAssert((Boolean)(((x_num4) < x_b)));
		this->CxAssert((Boolean)(((x_num5) < x_b)));
		this->CxAssert((Boolean)(((x_num6) < ((UInt64)x_b))));
		this->CxAssert((Boolean)(((x_num7) < ((Single)x_b))));
		this->CxAssert((Boolean)(((x_num8) < ((Double)x_b))));
		this->CxAssert((Boolean)(((x_c) > x_b)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_b2) > x_b)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_b3) > x_b)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num) > x_b)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num2) > x_b)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num3) > ((UInt64)x_b))), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num4) > x_b)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num5) > x_b)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num6) > ((UInt64)x_b))), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num7) > ((Single)x_b))), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num8) > ((Double)x_b))), (Boolean)(0));
		this->CxAssert((Boolean)(((x_b = ((Byte)(x_b + 1))) == 67)));
		this->CxAssert((Boolean)(((x_b = ((Byte)(x_b - 1))) == 66)));
		this->CxAssert((Boolean)(((x_b++) == 66)));
		this->CxAssert((Boolean)(((x_b--) == 67)));
		this->CxAssert((Boolean)((((x_b << 1)) == 132)));
		this->CxAssert((Boolean)((((x_b >> 1)) == 33)));
		this->CxAssert((Boolean)(((x_c) == x_b)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_b2) == x_b)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_b3) == x_b)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num) == x_b)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num2) == x_b)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num3) == ((UInt64)x_b))), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num4) == x_b)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num5) == x_b)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num6) == ((UInt64)x_b))), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num7) == ((Single)x_b))), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num8) == ((Double)x_b))), (Boolean)(0));
		this->CxAssert((Boolean)(((x_c) != x_b)));
		this->CxAssert((Boolean)(((x_b2) != x_b)));
		this->CxAssert((Boolean)(((x_b3) != x_b)));
		this->CxAssert((Boolean)(((x_num) != x_b)));
		this->CxAssert((Boolean)(((x_num2) != x_b)));
		this->CxAssert((Boolean)(((x_num3) != ((UInt64)x_b))));
		this->CxAssert((Boolean)(((x_num4) != x_b)));
		this->CxAssert((Boolean)(((x_num5) != x_b)));
		this->CxAssert((Boolean)(((x_num6) != ((UInt64)x_b))));
		this->CxAssert((Boolean)(((x_num7) != ((Single)x_b))));
		this->CxAssert((Boolean)(((x_num8) != ((Double)x_b))));
		this->CxAssert((Boolean)(((x_c) <= x_b)));
		this->CxAssert((Boolean)(((x_b2) <= x_b)));
		this->CxAssert((Boolean)(((x_b3) <= x_b)));
		this->CxAssert((Boolean)(((x_num) <= x_b)));
		this->CxAssert((Boolean)(((x_num2) <= x_b)));
		this->CxAssert((Boolean)(((x_num3) <= ((UInt64)x_b))));
		this->CxAssert((Boolean)(((x_num4) <= x_b)));
		this->CxAssert((Boolean)(((x_num5) <= x_b)));
		this->CxAssert((Boolean)(((x_num6) <= ((UInt64)x_b))));
		this->CxAssert((Boolean)(((x_num7) <= ((Single)x_b))));
		this->CxAssert((Boolean)(((x_num8) <= ((Double)x_b))));
		this->CxAssert((Boolean)(((x_c) >= x_b)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_b2) >= x_b)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_b3) >= x_b)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num) >= x_b)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num2) >= x_b)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num3) >= ((UInt64)x_b))), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num4) >= x_b)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num5) >= x_b)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num6) >= ((UInt64)x_b))), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num7) >= ((Single)x_b))), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num8) >= ((Double)x_b))), (Boolean)(0));
		this->CxAssert((Boolean)(((x_b = ((Byte)(x_b + ((Byte)x_c)))) == 67)));
		this->CxAssert((Boolean)(((x_b = ((Byte)(x_b - ((Byte)x_c)))) == 66)));
		this->CxAssert((Boolean)(((x_b = ((Byte)(x_b + ((Byte)x_num5)))) == 67)));
		this->CxAssert((Boolean)(((x_b = ((Byte)(x_b - ((Byte)x_num5)))) == 66)));
		this->CxAssert((Boolean)(((x_b = ((Byte)(x_b * ((Byte)x_c)))) == 66)));
		this->CxAssert((Boolean)(((x_b = ((Byte)(x_b / ((Byte)x_c)))) == 66)));
		this->CxAssert((Boolean)(((x_b = ((Byte)(x_b * ((Byte)x_num5)))) == 66)));
		this->CxAssert((Boolean)(((x_b = ((Byte)(x_b / ((Byte)x_num5)))) == 66)));
		this->CxAssert((Boolean)(((x_b = ((Byte)(x_b % ((Byte)x_c)))) == 0)));
		x_b = 66;
		this->CxAssert((Boolean)(((x_b = ((Byte)(x_b % ((Byte)x_num5)))) == 0)));
		x_b = 66;
		this->CxAssert((Boolean)(((x_b = ((Byte)(x_b & ((Byte)x_c)))) == 0)));
		x_b = 66;
		this->CxAssert((Boolean)(((x_b = ((Byte)(x_b & ((Byte)x_num5)))) == 0)));
		x_b = 66;
		this->CxAssert((Boolean)(((x_b = ((Byte)(x_b | ((Byte)x_c)))) == 67)));
		x_b = 66;
		this->CxAssert((Boolean)(((x_b = ((Byte)(x_b | ((Byte)x_num5)))) == 67)));
		x_b = 66;
		this->CxAssert((Boolean)(((x_b = ((Byte)(x_b ^ ((Byte)x_c)))) == 67)));
		x_b = 66;
		this->CxAssert((Boolean)(((x_b = ((Byte)(x_b ^ ((Byte)x_num5)))) == 67)));
		x_b = 66;
		this->CxAssert((Boolean)(((x_b = ((Byte)(x_b << x_c))) == 132)));
		x_b = 66;
		this->CxAssert((Boolean)(((x_b = ((Byte)(x_b << x_num2))) == 132)));
		x_b = 66;
		this->CxAssert((Boolean)(((x_b = ((Byte)(x_b >> x_c))) == 33)));
		x_b = 66;
		this->CxAssert((Boolean)(((x_b = ((Byte)(x_b >> x_num2))) == 33)));
		x_b = 66;
		Char x_c2 = 66;
		this->CxAssert((Boolean)(((x_c2 = ((UInt16)(x_c2 << x_c))) == 132)));
		return;
	}
	void ByteTest::ByteArrayTests()
	{
IL_0000:
		Array* x_array = new Array(ByteType,10);
		Array* x_array2 = new Array(ByteType,10);
		Int32 x_i = 0;
		
		{
IL_0023:
			if (((x_i) < 10))
			{
				goto IL_001c;
			}
			else
			{
				goto leaveBlock2;
			}

		}
		{
IL_001c:
			(*((SByte*)x_array->Address(x_i))) = ((Byte)x_i);
			goto IL_0021;
		}
		{
IL_0021:
			++x_i;
			goto IL_0023;
		}
leaveBlock2:

		Int32 x_j = 0;
		
		{
IL_0042:
			if (((x_j) < 10))
			{
				goto IL_003b;
			}
			else
			{
				goto leaveBlock3;
			}

		}
		{
IL_003b:
			(*((SByte*)x_array2->Address(x_j))) = (*((Byte*)x_array->Address(x_j)));
			goto IL_0040;
		}
		{
IL_0040:
			++x_j;
			goto IL_0042;
		}
leaveBlock3:

		this->CxAssert((Boolean)((((*((Byte*)x_array2->Address(0)))) == 0)));
		this->CxAssert((Boolean)((((*((Byte*)x_array2->Address(9)))) == 9)));
		Int32 x_k = 0;
		
		{
IL_007a:
			if (((x_k) < 10))
			{
				goto IL_0073;
			}
			else
			{
				goto leaveBlock4;
			}

		}
		{
IL_0073:
			(*((SByte*)x_array->Address(x_k))) = 1;
			goto IL_0078;
		}
		{
IL_0078:
			++x_k;
			goto IL_007a;
		}
leaveBlock4:

		Array* x_array3 = new Array(Int32Type,10);
		Buffer::BlockCopy(x_array, (Int32)(0), x_array3, (Int32)(0), (Int32)(10));
		Buffer::BlockCopy(x_array, (Int32)(0), x_array3, (Int32)(10), (Int32)(10));
		Buffer::BlockCopy(x_array, (Int32)(0), x_array3, (Int32)(20), (Int32)(10));
		Buffer::BlockCopy(x_array, (Int32)(0), x_array3, (Int32)(30), (Int32)(10));
		this->CxAssert((Boolean)((((*((Int32*)x_array3->Address(0)))) == 16843009)));
		this->CxAssert((Boolean)((((*((Int32*)x_array3->Address(9)))) == 16843009)));
		Array* x_array4 = new Array(ByteType,5);
		(*((Byte*)x_array4->Address(0))) = 1;
		(*((Byte*)x_array4->Address(1))) = 2;
		(*((Byte*)x_array4->Address(2))) = 3;
		(*((Byte*)x_array4->Address(3))) = 4;
		(*((Byte*)x_array4->Address(4))) = 5;
		this->CxAssert((Boolean)(((x_array4->get_Length()) == 5)));
		this->CxAssert((Boolean)((((*((Byte*)x_array4->Address(3)))) == 4)));
		Array* x_array5 = new Array(ByteType,4);
		(*((Byte*)x_array5->Address(0))) = 1;
		(*((Byte*)x_array5->Address(1))) = 2;
		(*((Byte*)x_array5->Address(2))) = 3;
		(*((Byte*)x_array5->Address(3))) = 4;
		this->CxAssert((Boolean)((((*((Byte*)x_array5->Address(1)))) == 2)));
		Array* x_array6 = new Array(ByteType,2,4);
		(*((Byte*)x_array6->Address(0,0))) = 1;
		(*((Byte*)x_array6->Address(0,1))) = 2;
		(*((Byte*)x_array6->Address(0,2))) = 3;
		(*((Byte*)x_array6->Address(0,3))) = 4;
		(*((Byte*)x_array6->Address(1,0))) = 4;
		(*((Byte*)x_array6->Address(1,1))) = 5;
		(*((Byte*)x_array6->Address(1,2))) = 6;
		(*((Byte*)x_array6->Address(1,3))) = 7;
		this->CxAssert((Boolean)((((*((Byte*)x_array6->Address(0,2)))) == 3)));
		Array* x_array7 = new Array(ByteType,2,2,4);
		(*((Byte*)x_array7->Address(0,0,0))) = 1;
		(*((Byte*)x_array7->Address(0,0,1))) = 2;
		(*((Byte*)x_array7->Address(0,0,2))) = 3;
		(*((Byte*)x_array7->Address(0,0,3))) = 4;
		(*((Byte*)x_array7->Address(0,1,0))) = 5;
		(*((Byte*)x_array7->Address(0,1,1))) = 6;
		(*((Byte*)x_array7->Address(0,1,2))) = 7;
		(*((Byte*)x_array7->Address(0,1,3))) = 8;
		(*((Byte*)x_array7->Address(1,0,0))) = 9;
		(*((Byte*)x_array7->Address(1,0,1))) = 10;
		(*((Byte*)x_array7->Address(1,0,2))) = 11;
		(*((Byte*)x_array7->Address(1,0,3))) = 12;
		(*((Byte*)x_array7->Address(1,1,0))) = 13;
		(*((Byte*)x_array7->Address(1,1,1))) = 14;
		(*((Byte*)x_array7->Address(1,1,2))) = 15;
		(*((Byte*)x_array7->Address(1,1,3))) = 16;
		this->CxAssert((Boolean)((((*((Byte*)x_array7->Address(0,0,3)))) == 4)));
		(*((Byte*)x_array7->Address(0,0,3))) = 6;
		this->CxAssert((Boolean)((((*((Byte*)x_array7->Address(0,0,3)))) == 6)));
		x_array7->SetValue((new ByteValue(4)), (Int32)(0), (Int32)(0), (Int32)(3));
		this->CxAssert((Boolean)((((*((Byte*)x_array7->Address(0,0,3)))) == 4)));
		return;
	}
	void ByteTest::ByteMiscTests()
	{
IL_0000:
		Byte x_b = 0;
		Byte x_val = 1;
		this->CxAssert((Boolean)(((Math::Max((Byte)(x_b), (Byte)(x_val))) == 1)));
		this->CxAssert((Boolean)(((Math::Min((Byte)(x_b), (Byte)(x_val))) == 0)));
		StringBuilder* x_stringBuilder = (new StringBuilder());
		x_stringBuilder->Append((Byte)(x_b));
		this->CxAssert((Boolean)(String::Equals(x_stringBuilder->ToString(), (new String(L"0")))));
		x_stringBuilder->Insert((Int32)(1), (Byte)(x_b));
		this->CxAssert((Boolean)(String::Equals(x_stringBuilder->ToString(), (new String(L"00")))));
		return;
	}
	void ByteTest::CxAssert(Boolean x_x)
	{
IL_0000:
		if (((x_x) == 0))
		{
			this->x_caBlock->TestFailed((new String(L"Byte Test Failed")));
		}

		return;
	}
	void ByteTest::CxAssert(Boolean x_x,Boolean x_y)
	{
IL_0000:
		if (((x_x) != x_y))
		{
			this->x_caBlock->TestFailed((new String(L"Byte Test Failed")));
		}

		return;
	}
	CharTest::CharTest(CABlock* x_caBlock)
	{
IL_0000:
		
		this->x_caBlock = x_caBlock;
		return;
	}
	void CharTest::Test()
	{
IL_0000:
		this->x_caBlock->Send((new String(L"Doing CharTest")));
		this->x_caBlock->Send((new String(L"\tDoing CharMethodsTest")));
		this->CharMethodsTest();
		this->x_caBlock->Send((new String(L"\tDoing CharOperators")));
		this->CharOperators();
		this->x_caBlock->Send((new String(L"\tDoing CharArrayTest")));
		this->CharArrayTests();
		this->x_caBlock->Send((new String(L"\tDoing CharMiscTests")));
		this->CharMiscTests();
		return;
	}
	void CharTest::CharMethodsTest()
	{
IL_0000:
		String* x_s = (new String(L"123aBc\t\n. "));
		Char x_c = 65;
		this->CxAssert((Boolean)(((CharValue(x_c).CompareTo((Char)(66))) < 0)));
		this->CxAssert((Boolean)(CharValue(x_c).Equals((Char)(65))));
		Double x_numericValue = CharValue::GetNumericValue((Char)(53));
		this->CxAssert((Boolean)(((x_numericValue) == 5)));
		x_numericValue = CharValue::GetNumericValue(x_s, (Int32)(2));
		this->CxAssert((Boolean)(((x_numericValue) == 3)));
		this->CxAssert((Boolean)(CharValue::IsControl((Char)(9))));
		this->CxAssert((Boolean)(CharValue::IsControl(x_s, (Int32)(7))));
		this->CxAssert((Boolean)(CharValue::IsDigit((Char)(49))));
		this->CxAssert((Boolean)(CharValue::IsDigit(x_s, (Int32)(2))));
		this->CxAssert((Boolean)(CharValue::IsLetter((Char)(97))));
		this->CxAssert((Boolean)(CharValue::IsLetter(x_s, (Int32)(3))));
		this->CxAssert((Boolean)(CharValue::IsLetterOrDigit((Char)(97))));
		this->CxAssert((Boolean)(CharValue::IsLetterOrDigit(x_s, (Int32)(3))));
		this->CxAssert((Boolean)(CharValue::IsLower((Char)(97))));
		this->CxAssert((Boolean)(CharValue::IsLower(x_s, (Int32)(3))));
		this->CxAssert((Boolean)(CharValue::IsNumber((Char)(49))));
		this->CxAssert((Boolean)(CharValue::IsNumber(x_s, (Int32)(2))));
		this->CxAssert((Boolean)(CharValue::IsPunctuation((Char)(44))));
		this->CxAssert((Boolean)(CharValue::IsPunctuation(x_s, (Int32)(8))));
		this->CxAssert((Boolean)(CharValue::IsSeparator((Char)(32))));
		this->CxAssert((Boolean)(CharValue::IsSeparator(x_s, (Int32)(9))));
		this->CxAssert((Boolean)(CharValue::IsUpper((Char)(66))));
		this->CxAssert((Boolean)(CharValue::IsUpper(x_s, (Int32)(4))));
		this->CxAssert((Boolean)(CharValue::IsWhiteSpace((Char)(32))));
		this->CxAssert((Boolean)(CharValue::IsWhiteSpace(x_s, (Int32)(9))));
		this->CxAssert((Boolean)(((CharValue::ToLower((Char)(65))) == 97)));
		this->CxAssert((Boolean)(((CharValue::ToUpper((Char)(97))) == 65)));
		this->CxAssert((Boolean)((new String(L"a"))->Equals(CharValue((97)).ToString())));
		this->CxAssert((Boolean)((new String(L"a"))->Equals(CharValue::ToString((Char)(97)))));
		this->CxAssert((Boolean)(CharValue((97)).Equals((Char)(CharValue::Parse((new String(L"a")))))));
		Object* x_obj = (new CharValue(x_c));
		this->CxAssert((Boolean)(CharValue((65)).Equals((Char)(x_obj->get_AsChar()))));
		this->CxAssert((Boolean)(CharValue((65)).Equals(x_obj)));
		this->CxAssert((Boolean)(((CharValue((65)).CompareTo(x_obj)) == 0)));
		this->CxAssert((Boolean)(String::Equals(x_obj->ToString(), (new String(L"A")))));
		return;
	}
	void CharTest::CharOperators()
	{
IL_0000:
		Char x_c = 66;
		Char x_c2 = 1;
		Int32 x_num = 1;
		UInt32 x_num2 = 1;
		Int64 x_num3 = ((Int64)1);
		Double x_num4 = 1;
		this->CxAssert((Boolean)(((x_c) == 66)));
		this->CxAssert((Boolean)((((x_c + x_c2)) == 67)));
		this->CxAssert((Boolean)((((x_c + x_num)) == 67)));
		this->CxAssert((Boolean)((((x_c + x_num2)) == 67)));
		this->CxAssert((Boolean)((((((UInt64)x_c) + x_num3)) == ((Int64)67))));
		this->CxAssert((Boolean)((((((Double)x_c) + x_num4)) == 67)));
		this->CxAssert((Boolean)((((x_c - x_c2)) == 65)));
		this->CxAssert((Boolean)((((x_c - x_num)) == 65)));
		this->CxAssert((Boolean)((((x_c - x_num2)) == 65)));
		this->CxAssert((Boolean)((((((UInt64)x_c) - x_num3)) == ((Int64)65))));
		this->CxAssert((Boolean)((((((Double)x_c) - x_num4)) == 65)));
		this->CxAssert((Boolean)((((x_c * x_c2)) == 66)));
		this->CxAssert((Boolean)((((x_c * x_num)) == 66)));
		this->CxAssert((Boolean)((((x_c * x_num2)) == 66)));
		this->CxAssert((Boolean)((((((UInt64)x_c) * x_num3)) == ((Int64)66))));
		this->CxAssert((Boolean)((((((Double)x_c) * x_num4)) == 66)));
		this->CxAssert((Boolean)((((x_c / x_c2)) == 66)));
		this->CxAssert((Boolean)((((x_c / x_num)) == 66)));
		this->CxAssert((Boolean)((((x_c / x_num2)) == 66)));
		this->CxAssert((Boolean)((((((UInt64)x_c) / x_num3)) == ((Int64)66))));
		this->CxAssert((Boolean)((((((Double)x_c) / x_num4)) == 66)));
		this->CxAssert((Boolean)((((x_c % x_c2)) == 0)));
		this->CxAssert((Boolean)((((x_c % x_num)) == 0)));
		this->CxAssert((Boolean)((((x_c % x_num2)) == 0)));
		this->CxAssert((Boolean)((((((UInt64)x_c) % x_num3)) == ((Int64)0))));
		this->CxAssert((Boolean)(((DoubleValue::Modulus(((Double)x_c),x_num4)) == 0)));
		this->CxAssert((Boolean)((((x_c & x_c2)) == 0)));
		this->CxAssert((Boolean)((((x_c & x_num)) == 0)));
		this->CxAssert((Boolean)((((x_c & x_num2)) == 0)));
		this->CxAssert((Boolean)((((((UInt64)x_c) & x_num3)) == ((Int64)0))));
		this->CxAssert((Boolean)((((x_c | x_c2)) == 67)));
		this->CxAssert((Boolean)((((x_c | x_num)) == 67)));
		this->CxAssert((Boolean)((((x_c | x_num2)) == 67)));
		this->CxAssert((Boolean)((((((UInt64)x_c) | x_num3)) == ((Int64)67))));
		this->CxAssert((Boolean)((((x_c ^ x_c2)) == 67)));
		this->CxAssert((Boolean)((((x_c ^ x_num)) == 67)));
		this->CxAssert((Boolean)((((x_c ^ x_num2)) == 67)));
		this->CxAssert((Boolean)((((((UInt64)x_c) ^ x_num3)) == ((Int64)67))));
		this->CxAssert((Boolean)(((~x_c) == -67)));
		this->CxAssert((Boolean)(((x_c2) < x_c)));
		this->CxAssert((Boolean)(((x_num) < x_c)));
		this->CxAssert((Boolean)(((x_num2) < x_c)));
		this->CxAssert((Boolean)(((x_num3) < ((UInt64)x_c))));
		this->CxAssert((Boolean)(((x_num4) < ((Double)x_c))));
		this->CxAssert((Boolean)(((x_c2) > x_c)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num) > x_c)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num2) > x_c)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num3) > ((UInt64)x_c))), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num4) > ((Double)x_c))), (Boolean)(0));
		this->CxAssert((Boolean)(((x_c = ((UInt16)(x_c + 1))) == 67)));
		this->CxAssert((Boolean)(((x_c = ((UInt16)(x_c - 1))) == 66)));
		this->CxAssert((Boolean)(((x_c++) == 66)));
		this->CxAssert((Boolean)(((x_c--) == 67)));
		this->CxAssert((Boolean)((((x_c << 1)) == 132)));
		this->CxAssert((Boolean)((((x_c >> 1)) == 33)));
		this->CxAssert((Boolean)(((x_c2) == x_c)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num) == x_c)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num2) == x_c)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num3) == ((UInt64)x_c))), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num4) == ((Double)x_c))), (Boolean)(0));
		this->CxAssert((Boolean)(((x_c2) != x_c)));
		this->CxAssert((Boolean)(((x_num) != x_c)));
		this->CxAssert((Boolean)(((x_num2) != x_c)));
		this->CxAssert((Boolean)(((x_num3) != ((UInt64)x_c))));
		this->CxAssert((Boolean)(((x_num4) != ((Double)x_c))));
		this->CxAssert((Boolean)(((x_c2) <= x_c)));
		this->CxAssert((Boolean)(((x_num) <= x_c)));
		this->CxAssert((Boolean)(((x_num2) <= x_c)));
		this->CxAssert((Boolean)(((x_num3) <= ((UInt64)x_c))));
		this->CxAssert((Boolean)(((x_num4) <= ((Double)x_c))));
		this->CxAssert((Boolean)(((x_c2) >= x_c)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num) >= x_c)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num2) >= x_c)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num3) >= ((UInt64)x_c))), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num4) >= ((Double)x_c))), (Boolean)(0));
		this->CxAssert((Boolean)(((x_c = ((UInt16)(x_c + x_c2))) == 67)));
		this->CxAssert((Boolean)(((x_c = ((UInt16)(x_c - x_c2))) == 66)));
		this->CxAssert((Boolean)(((x_c = ((UInt16)(x_c * x_c2))) == 66)));
		this->CxAssert((Boolean)(((x_c = ((UInt16)(x_c / x_c2))) == 66)));
		this->CxAssert((Boolean)(((x_c = ((UInt16)(x_c % x_c2))) == 0)));
		x_c = 66;
		this->CxAssert((Boolean)(((x_c = ((UInt16)(x_c & x_c2))) == 0)));
		x_c = 66;
		this->CxAssert((Boolean)(((x_c = ((UInt16)(x_c & x_c2))) == 0)));
		x_c = 66;
		this->CxAssert((Boolean)(((x_c = ((UInt16)(x_c | x_c2))) == 67)));
		x_c = 66;
		this->CxAssert((Boolean)(((x_c = ((UInt16)(x_c ^ x_c2))) == 67)));
		x_c = 66;
		this->CxAssert((Boolean)(((x_c = ((UInt16)(x_c << 1))) == 132)));
		x_c = 66;
		this->CxAssert((Boolean)(((x_c = ((UInt16)(x_c >> 1))) == 33)));
		return;
	}
	void CharTest::CharArrayTests()
	{
IL_0000:
		Array* x_array = new Array(CharType,5);
		(*((Char*)x_array->Address(0))) = 49;
		(*((Char*)x_array->Address(1))) = 50;
		(*((Char*)x_array->Address(2))) = 51;
		(*((Char*)x_array->Address(3))) = 52;
		(*((Char*)x_array->Address(4))) = 53;
		this->CxAssert((Boolean)(((x_array->get_Length()) == 5)));
		this->CxAssert((Boolean)((((*((UInt16*)x_array->Address(3)))) == 52)));
		Array* x_array2 = new Array(CharType,4);
		(*((Char*)x_array2->Address(0))) = 49;
		(*((Char*)x_array2->Address(1))) = 50;
		(*((Char*)x_array2->Address(2))) = 51;
		(*((Char*)x_array2->Address(3))) = 52;
		this->CxAssert((Boolean)((((*((UInt16*)x_array2->Address(1)))) == 50)));
		Array* x_array3 = new Array(CharType,2,4);
		(*((Char*)x_array3->Address(0,0))) = 49;
		(*((Char*)x_array3->Address(0,1))) = 50;
		(*((Char*)x_array3->Address(0,2))) = 51;
		(*((Char*)x_array3->Address(0,3))) = 52;
		(*((Char*)x_array3->Address(1,0))) = 52;
		(*((Char*)x_array3->Address(1,1))) = 53;
		(*((Char*)x_array3->Address(1,2))) = 54;
		(*((Char*)x_array3->Address(1,3))) = 55;
		this->CxAssert((Boolean)((((*((Char*)x_array3->Address(0,2)))) == 51)));
		Array* x_array4 = new Array(CharType,2,2,4);
		(*((Char*)x_array4->Address(0,0,0))) = 49;
		(*((Char*)x_array4->Address(0,0,1))) = 50;
		(*((Char*)x_array4->Address(0,0,2))) = 51;
		(*((Char*)x_array4->Address(0,0,3))) = 52;
		(*((Char*)x_array4->Address(0,1,0))) = 53;
		(*((Char*)x_array4->Address(0,1,1))) = 54;
		(*((Char*)x_array4->Address(0,1,2))) = 55;
		(*((Char*)x_array4->Address(0,1,3))) = 56;
		(*((Char*)x_array4->Address(1,0,0))) = 57;
		(*((Char*)x_array4->Address(1,0,1))) = 65;
		(*((Char*)x_array4->Address(1,0,2))) = 66;
		(*((Char*)x_array4->Address(1,0,3))) = 67;
		(*((Char*)x_array4->Address(1,1,0))) = 68;
		(*((Char*)x_array4->Address(1,1,1))) = 69;
		(*((Char*)x_array4->Address(1,1,2))) = 70;
		(*((Char*)x_array4->Address(1,1,3))) = 71;
		this->CxAssert((Boolean)((((*((Char*)x_array4->Address(0,0,3)))) == 52)));
		(*((Char*)x_array4->Address(0,0,3))) = 54;
		this->CxAssert((Boolean)((((*((Char*)x_array4->Address(0,0,3)))) == 54)));
		x_array4->SetValue((new CharValue(52)), (Int32)(0), (Int32)(0), (Int32)(3));
		this->CxAssert((Boolean)((((*((Char*)x_array4->Address(0,0,3)))) == 52)));
		return;
	}
	void CharTest::CharMiscTests()
	{
IL_0000:
		Char x_c = 48;
		Char x_val = 49;
		this->CxAssert((Boolean)(((Math::Max((UInt16)(x_c), (UInt16)(x_val))) == 49)));
		this->CxAssert((Boolean)(((Math::Min((UInt16)(x_c), (UInt16)(x_val))) == 48)));
		StringBuilder* x_stringBuilder = (new StringBuilder());
		x_stringBuilder->Append((Char)(x_c));
		this->CxAssert((Boolean)(String::Equals(x_stringBuilder->ToString(), (new String(L"0")))));
		return;
	}
	void CharTest::CxAssert(Boolean x_x)
	{
IL_0000:
		if (((x_x) == 0))
		{
			this->x_caBlock->TestFailed((new String(L"Char TestFailed")));
		}

		return;
	}
	void CharTest::CxAssert(Boolean x_x,Boolean x_y)
	{
IL_0000:
		if (((x_x) != x_y))
		{
			this->x_caBlock->TestFailed((new String(L"Char TestFailed")));
		}

		return;
	}
	DoubleTest::DoubleTest(CABlock* x_caBlock)
	{
IL_0000:
		
		this->x_caBlock = x_caBlock;
		return;
	}
	void DoubleTest::Test()
	{
IL_0000:
		this->x_caBlock->Send((new String(L"Doing DoubleTest")));
		this->x_caBlock->Send((new String(L"\tDoing DoDoubleMethodsTest")));
		this->DoDoubleMethodsTest();
		this->x_caBlock->Send((new String(L"\tDoing DoDoubleMath")));
		this->DoDoubleMath();
		this->x_caBlock->Send((new String(L"\tDoing DoubleOperators")));
		this->DoubleOperators();
		this->x_caBlock->Send((new String(L"\tDoing DoubleNanTest")));
		this->DoubleNanTest();
		this->x_caBlock->Send((new String(L"\tDoing DoubleArrayTest")));
		this->DoubleArrayTest();
		this->x_caBlock->Send((new String(L"\tDoing DoubleMiscTests")));
		this->DoubleMiscTests();
		return;
	}
	void DoubleTest::DoDoubleMethodsTest()
	{
IL_0000:
		Double x_num = 3.159;
		this->CxAssert((Boolean)(((DoubleValue(x_num).CompareTo((Double)(3.159))) == 0)));
		this->CxAssert((Boolean)(((DoubleValue(x_num).CompareTo((new DoubleValue(3.159)))) == 0)));
		this->CxAssert((Boolean)(DoubleValue(x_num).Equals((Double)(3.159))));
		this->CxAssert((Boolean)(((DoubleValue::Parse((new String(L"3.159")))) == 3.159)));
		this->CxAssert((Boolean)(String::Equals(DoubleValue(x_num).ToString(), (new String(L"3.159")))));
		String* x_text = DoubleValue((DoubleValue::MinValue)).ToString();
		this->CxAssert((Boolean)((x_text->StartsWith((new String(L"-1.7976"))) && x_text->EndsWith((new String(L"E+308"))))));
		x_num = 1000000000001;
		this->CxAssert((Boolean)(((x_num) > 1000000000000)));
		x_num = -1000000000000;
		this->CxAssert((Boolean)(((x_num) <= -1000000000000)));
		x_num = 10000;
		this->CxAssert((Boolean)(((((Int64)x_num)) == ((Int64)10000))));
		this->CxAssert((Boolean)(((((Int32)x_num)) == 10000)));
		this->CxAssert((Boolean)(((((UInt32)x_num)) == 10000)));
		Object* x_obj = (new DoubleValue(x_num));
		this->CxAssert((Boolean)(((x_obj->get_AsDouble()) == 10000)));
		x_num = DoubleValue::Epsilon;
		this->CxAssert((Boolean)(((x_num) == DoubleValue::Epsilon)));
		x_num = DoubleValue::MaxValue;
		this->CxAssert((Boolean)(((x_num) == DoubleValue::MaxValue)));
		x_num = DoubleValue::MinValue;
		this->CxAssert((Boolean)(((x_num) == DoubleValue::MinValue)));
		x_obj = (new DoubleValue(5));
		this->CxAssert((Boolean)(x_obj->Equals((new DoubleValue(5)))));
		this->CxAssert((Boolean)(String::Equals(x_obj->ToString(), (new String(L"5")))));
		return;
	}
	void DoubleTest::DoDoubleMath()
	{
IL_0000:
		Double x_num = 355;
		Double x_num2 = 113;
		Double x_num3 = (x_num / x_num2);
		this->CxAssert((Double)(x_num3), (Double)(3.14159));
		this->CxAssert((Double)((x_num3 * x_num2)), (Double)(355));
		this->CxAssert((Double)((x_num + x_num2)), (Double)(468));
		this->CxAssert((Double)((x_num - x_num2)), (Double)(242));
		x_num = 2;
		x_num2 = (x_num + DoubleValue::Epsilon);
		this->CxAssert((Boolean)(((x_num2) == 2)));
		x_num = 2;
		x_num2 = (x_num + 4.94065645841247E-24);
		this->CxAssert((Boolean)(((x_num2) == 2)));
		return;
	}
	void DoubleTest::DoubleOperators()
	{
IL_0000:
		Double x_num = 66;
		Char x_c = 1;
		Int32 x_num2 = 1;
		UInt32 x_num3 = 1;
		Int64 x_num4 = ((Int64)1);
		Double x_num5 = 1;
		this->CxAssert((Boolean)(((x_num) == 66)));
		this->CxAssert((Boolean)((((x_num + ((Double)x_c))) == 67)));
		this->CxAssert((Boolean)((((x_num + ((Double)x_num2))) == 67)));
		this->CxAssert((Boolean)((((x_num + ((Double)x_num3))) == 67)));
		this->CxAssert((Boolean)((((x_num + ((Double)x_num4))) == 67)));
		this->CxAssert((Boolean)((((x_num + x_num5)) == 67)));
		this->CxAssert((Boolean)((((x_num - ((Double)x_c))) == 65)));
		this->CxAssert((Boolean)((((x_num - ((Double)x_num2))) == 65)));
		this->CxAssert((Boolean)((((x_num - ((Double)x_num3))) == 65)));
		this->CxAssert((Boolean)((((x_num - ((Double)x_num4))) == 65)));
		this->CxAssert((Boolean)((((x_num - x_num5)) == 65)));
		this->CxAssert((Boolean)((((x_num * ((Double)x_c))) == 66)));
		this->CxAssert((Boolean)((((x_num * ((Double)x_num2))) == 66)));
		this->CxAssert((Boolean)((((x_num * ((Double)x_num3))) == 66)));
		this->CxAssert((Boolean)((((x_num * ((Double)x_num4))) == 66)));
		this->CxAssert((Boolean)((((x_num * x_num5)) == 66)));
		this->CxAssert((Boolean)((((x_num / ((Double)x_c))) == 66)));
		this->CxAssert((Boolean)((((x_num / ((Double)x_num2))) == 66)));
		this->CxAssert((Boolean)((((x_num / ((Double)x_num3))) == 66)));
		this->CxAssert((Boolean)((((x_num / ((Double)x_num4))) == 66)));
		this->CxAssert((Boolean)((((x_num / x_num5)) == 66)));
		this->CxAssert((Boolean)(((DoubleValue::Modulus(x_num,((Double)x_c))) == 0)));
		this->CxAssert((Boolean)(((DoubleValue::Modulus(x_num,((Double)x_num2))) == 0)));
		this->CxAssert((Boolean)(((DoubleValue::Modulus(x_num,((Double)x_num3))) == 0)));
		this->CxAssert((Boolean)(((DoubleValue::Modulus(x_num,((Double)x_num4))) == 0)));
		this->CxAssert((Boolean)(((DoubleValue::Modulus(x_num,x_num5)) == 0)));
		this->CxAssert((Boolean)(((((Double)x_c)) < x_num)));
		this->CxAssert((Boolean)(((((Double)x_num2)) < x_num)));
		this->CxAssert((Boolean)(((((Double)x_num3)) < x_num)));
		this->CxAssert((Boolean)(((((Double)x_num4)) < x_num)));
		this->CxAssert((Boolean)(((x_num5) < x_num)));
		this->CxAssert((Boolean)(((((Double)x_c)) > x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((((Double)x_num2)) > x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((((Double)x_num3)) > x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((((Double)x_num4)) > x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num5) > x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num = (x_num + 1)) == 67)));
		this->CxAssert((Boolean)(((x_num = (x_num - 1)) == 66)));
		this->CxAssert((Boolean)(((x_num++) == 66)));
		this->CxAssert((Boolean)(((x_num--) == 67)));
		this->CxAssert((Boolean)(((((Double)x_c)) == x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((((Double)x_num2)) == x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((((Double)x_num3)) == x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((((Double)x_num4)) == x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num5) == x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((((Double)x_c)) != x_num)));
		this->CxAssert((Boolean)(((((Double)x_num2)) != x_num)));
		this->CxAssert((Boolean)(((((Double)x_num3)) != x_num)));
		this->CxAssert((Boolean)(((((Double)x_num4)) != x_num)));
		this->CxAssert((Boolean)(((x_num5) != x_num)));
		this->CxAssert((Boolean)(((((Double)x_c)) <= x_num)));
		this->CxAssert((Boolean)(((((Double)x_num2)) <= x_num)));
		this->CxAssert((Boolean)(((((Double)x_num3)) <= x_num)));
		this->CxAssert((Boolean)(((((Double)x_num4)) <= x_num)));
		this->CxAssert((Boolean)(((x_num5) <= x_num)));
		this->CxAssert((Boolean)(((((Double)x_c)) >= x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((((Double)x_num2)) >= x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((((Double)x_num3)) >= x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((((Double)x_num4)) >= x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num5) >= x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num = (x_num + ((Double)x_c))) == 67)));
		this->CxAssert((Boolean)(((x_num = (x_num - ((Double)x_c))) == 66)));
		this->CxAssert((Boolean)(((x_num = (x_num + ((Double)x_num2))) == 67)));
		this->CxAssert((Boolean)(((x_num = (x_num - ((Double)x_num2))) == 66)));
		this->CxAssert((Boolean)(((x_num = (x_num + ((Double)x_num3))) == 67)));
		this->CxAssert((Boolean)(((x_num = (x_num - ((Double)x_num3))) == 66)));
		this->CxAssert((Boolean)(((x_num = (x_num + ((Double)x_num4))) == 67)));
		this->CxAssert((Boolean)(((x_num = (x_num - ((Double)x_num4))) == 66)));
		this->CxAssert((Boolean)(((x_num = (x_num * ((Double)x_c))) == 66)));
		this->CxAssert((Boolean)(((x_num = (x_num / ((Double)x_c))) == 66)));
		this->CxAssert((Boolean)(((x_num = (x_num * ((Double)x_num2))) == 66)));
		this->CxAssert((Boolean)(((x_num = (x_num / ((Double)x_num2))) == 66)));
		this->CxAssert((Boolean)(((x_num = (x_num * ((Double)x_num3))) == 66)));
		this->CxAssert((Boolean)(((x_num = (x_num / ((Double)x_num3))) == 66)));
		this->CxAssert((Boolean)(((x_num = (x_num * ((Double)x_num4))) == 66)));
		this->CxAssert((Boolean)(((x_num = (x_num / ((Double)x_num4))) == 66)));
		this->CxAssert((Boolean)(((x_num = DoubleValue::Modulus(x_num,((Double)x_c))) == 0)));
		x_num = 66;
		this->CxAssert((Boolean)(((x_num = DoubleValue::Modulus(x_num,((Double)x_num2))) == 0)));
		x_num = 5;
		this->CxAssert((Double)(DoubleValue::Modulus(x_num,2.2)), (Double)(0.6));
		return;
	}
	void DoubleTest::DoubleNanTest()
	{
IL_0000:
		Double x_num = DoubleValue::NaN;
		Double x_num2 = 1;
		this->CxAssert((Boolean)(DoubleValue::IsNaN((Double)(x_num))));
		this->CxAssert((Boolean)(DoubleValue::IsInfinity((Double)(DoubleValue::PositiveInfinity))));
		this->CxAssert((Boolean)(DoubleValue::IsNegativeInfinity((Double)(DoubleValue::NegativeInfinity))));
		this->CxAssert((Boolean)(DoubleValue::IsPositiveInfinity((Double)(DoubleValue::PositiveInfinity))));
		this->CxAssert((Boolean)(DoubleValue::IsNaN((Double)((x_num * x_num2)))));
		this->CxAssert((Boolean)(DoubleValue::IsNaN((Double)((x_num / x_num2)))));
		this->CxAssert((Boolean)(DoubleValue::IsNaN((Double)((x_num + x_num2)))));
		this->CxAssert((Boolean)(DoubleValue::IsNaN((Double)((x_num - x_num2)))));
		this->CxAssert((Boolean)(DoubleValue::IsNaN((Double)(DoubleValue::Modulus(x_num,x_num2)))));
		this->CxAssert((Boolean)(((x_num) < x_num2)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num) > x_num2)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num) <= x_num2)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num) >= x_num2)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num) == x_num2)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num) == x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num2) < x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num2) > x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num2) <= x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num2) >= x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num) != x_num2)));
		this->CxAssert((Boolean)(((x_num) != x_num)));
		x_num = DoubleValue::NaN;
		x_num2 = DoubleValue::NaN;
		if (((x_num) == x_num2))
		{
			this->DoubleTestFailed();
		}
		else
		{
			this->CxAssert((Boolean)(1));
		}

		if (((x_num) == x_num))
		{
			this->DoubleTestFailed();
		}
		else
		{
			this->CxAssert((Boolean)(1));
		}

		if (((x_num) != x_num2))
		{
			this->CxAssert((Boolean)(1));
		}
		else
		{
			this->DoubleTestFailed();
		}

		if (((x_num) != x_num))
		{
			this->CxAssert((Boolean)(1));
		}
		else
		{
			this->DoubleTestFailed();
		}

		if (((x_num) > x_num2))
		{
			this->DoubleTestFailed();
		}
		else
		{
			this->CxAssert((Boolean)(1));
		}

		if (((x_num) >= x_num2))
		{
			this->DoubleTestFailed();
		}
		else
		{
			this->CxAssert((Boolean)(1));
		}

		if (((x_num) < x_num2))
		{
			this->DoubleTestFailed();
		}
		else
		{
			this->CxAssert((Boolean)(1));
		}

		if (((x_num) <= x_num2))
		{
			this->DoubleTestFailed();
		}
		else
		{
			this->CxAssert((Boolean)(1));
		}

		if (((x_num) == 0))
		{
			this->DoubleTestFailed();
		}
		else
		{
			this->CxAssert((Boolean)(1));
		}

		this->CxAssert((Boolean)(DoubleValue((DoubleValue::NaN)).Equals((Double)(DoubleValue::NaN))));
		return;
	}
	void DoubleTest::DoubleArrayTest()
	{
IL_0000:
		Array* x_array = new Array(DoubleType,4);
		(*((Double*)x_array->Address(0))) = 1;
		(*((Double*)x_array->Address(1))) = 2;
		(*((Double*)x_array->Address(2))) = 3;
		(*((Double*)x_array->Address(3))) = 4;
		this->CxAssert((Boolean)((((*((Double*)x_array->Address(1)))) == 2)));
		Array* x_array2 = new Array(DoubleType,2,4);
		(*((Double*)x_array2->Address(0,0))) = 1;
		(*((Double*)x_array2->Address(0,1))) = 2;
		(*((Double*)x_array2->Address(0,2))) = 3;
		(*((Double*)x_array2->Address(0,3))) = 4;
		(*((Double*)x_array2->Address(1,0))) = 4;
		(*((Double*)x_array2->Address(1,1))) = 5;
		(*((Double*)x_array2->Address(1,2))) = 6;
		(*((Double*)x_array2->Address(1,3))) = 7;
		this->CxAssert((Boolean)((((*((Double*)x_array2->Address(0,2)))) == 3)));
		Array* x_array3 = new Array(DoubleType,2,2,4);
		(*((Double*)x_array3->Address(0,0,0))) = 1;
		(*((Double*)x_array3->Address(0,0,1))) = 2;
		(*((Double*)x_array3->Address(0,0,2))) = 3;
		(*((Double*)x_array3->Address(0,0,3))) = 4;
		(*((Double*)x_array3->Address(0,1,0))) = 5;
		(*((Double*)x_array3->Address(0,1,1))) = 6;
		(*((Double*)x_array3->Address(0,1,2))) = 7;
		(*((Double*)x_array3->Address(0,1,3))) = 8;
		(*((Double*)x_array3->Address(1,0,0))) = 9;
		(*((Double*)x_array3->Address(1,0,1))) = 10;
		(*((Double*)x_array3->Address(1,0,2))) = 11;
		(*((Double*)x_array3->Address(1,0,3))) = 12;
		(*((Double*)x_array3->Address(1,1,0))) = 13;
		(*((Double*)x_array3->Address(1,1,1))) = 14;
		(*((Double*)x_array3->Address(1,1,2))) = 15;
		(*((Double*)x_array3->Address(1,1,3))) = 16;
		this->CxAssert((Boolean)((((*((Double*)x_array3->Address(0,0,3)))) == 4)));
		(*((Double*)x_array3->Address(0,0,3))) = 22;
		this->CxAssert((Boolean)((((*((Double*)x_array3->Address(0,0,3)))) == 22)));
		(*((Double*)x_array2->Address(0,2))) = DoubleValue::NaN;
		this->CxAssert((Boolean)(DoubleValue::IsNaN((Double)((*((Double*)x_array2->Address(0,2)))))));
		x_array3->SetValue((new DoubleValue(4)), (Int32)(0), (Int32)(0), (Int32)(3));
		this->CxAssert((Boolean)((((*((Double*)x_array3->Address(0,0,3)))) == 4)));
		return;
	}
	void DoubleTest::DoubleMiscTests()
	{
IL_0000:
		Double x_num = -1;
		Double x_val = 1;
		this->CxAssert((Boolean)(((Math::Abs((Double)(x_num))) == 1)));
		this->CxAssert((Boolean)(((Math::Max((Double)(x_num), (Double)(x_val))) == 1)));
		this->CxAssert((Boolean)(((Math::Min((Double)(x_num), (Double)(x_val))) == -1)));
		this->CxAssert((Boolean)(((Math::Sign((Double)(x_num))) < 0)));
		StringBuilder* x_stringBuilder = (new StringBuilder());
		x_stringBuilder->Append((Double)(x_num));
		this->CxAssert((Boolean)(String::Equals(x_stringBuilder->ToString(), (new String(L"-1")))));
		return;
	}
	void DoubleTest::DoubleCompare(Double x_n1,Double x_n2,Double x_resolution)
	{
IL_0000:
		if (((Math::Abs((Double)((x_n1 - x_n2)))) > x_resolution))
		{
			this->DoubleTestFailed();
		}

		return;
	}
	void DoubleTest::CxAssert(Double x_x,Double x_y)
	{
IL_0000:
		this->DoubleCompare((Double)(x_x), (Double)(x_y), (Double)(1E-05));
		return;
	}
	void DoubleTest::CxAssert(Boolean x_x)
	{
IL_0000:
		if (((x_x) == 0))
		{
			this->DoubleTestFailed();
		}

		return;
	}
	void DoubleTest::CxAssert(Boolean x_x,Boolean x_y)
	{
IL_0000:
		if (((x_x) != x_y))
		{
			this->DoubleTestFailed();
		}

		return;
	}
	void DoubleTest::DoubleTestFailed()
	{
IL_0000:
		this->x_caBlock->TestFailed((new String(L"Double TestFailed")));
		return;
	}
	EnumTest::EnumTest(CABlock* x_caBlock)
	{
IL_0000:
		
		this->x_caBlock = x_caBlock;
		return;
	}
	void EnumTest::Test()
	{
IL_0000:
		this->x_caBlock->Send((new String(L"Doing EnumTest")));
		this->Test1((TestEnum)(1));
		this->Test1((TestEnum2)(1));
		return;
	}
	void EnumTest::Test1(TestEnum x_testEnum)
	{
IL_0000:
		if (((x_testEnum) == 1))
		{
			x_testEnum = (TestEnum)2;
		}

		if (((x_testEnum) == 2))
		{
			x_testEnum = (TestEnum)5;
		}

		if (((5) != x_testEnum))
		{
			this->EnumTestFailed();
		}

		Int32 x_num = x_testEnum;
		if (((x_num) != 5))
		{
			this->EnumTestFailed();
		}

		Double x_num2 = ((Double)x_testEnum);
		if (((x_num2) != 5))
		{
			this->EnumTestFailed();
		}

		return;
	}
	void EnumTest::Test1(TestEnum2 x_testEnum)
	{
IL_0000:
		if (((x_testEnum) == 1))
		{
			x_testEnum = (TestEnum2)2;
		}

		if (((x_testEnum) == 2))
		{
			x_testEnum = (TestEnum2)5;
		}

		if (((5) != x_testEnum))
		{
			this->EnumTestFailed();
		}

		Int32 x_num = x_testEnum;
		if (((x_num) != 5))
		{
			this->EnumTestFailed();
		}

		Double x_num2 = ((Double)x_testEnum);
		if (((x_num2) != 5))
		{
			this->EnumTestFailed();
		}

		return;
	}
	void EnumTest::EnumTestFailed()
	{
IL_0000:
		this->x_caBlock->TestFailed((new String(L"Enum TestFailed")));
		return;
	}
	CABlock::CABlock()
	{
IL_0000:
		
		return;
	}
	CABlock::CABlock(Int32 x_i)
	{
IL_0000:
		
		return;
	}
	void CABlock::Initialize()
	{
IL_0000:
		this->x_fe = (FredEnum)1;
		return;
	}
	void CABlock::Execute()
	{
IL_0000:
		this->RunTests((FredEnum)(this->x_fe));
		return;
	}
	void CABlock::RunTests(FredEnum x_fre)
	{
IL_0000:
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
		TryCatchTest* x_tryCatchTest = (new TryCatchTest());
		x_tryCatchTest->Test();
		return;
	}
	void CABlock::TestFailed(String* x_reason)
	{
IL_0000:
		this->Send(String::Concat((new String(L"\t\tERROR: ")), x_reason));
		return;
	}
	Int16Test::Int16Test(CABlock* x_caBlock)
	{
IL_0000:
		
		this->x_caBlock = x_caBlock;
		return;
	}
	void Int16Test::Test()
	{
IL_0000:
		this->x_caBlock->Send((new String(L"Doing Int16Test")));
		this->x_caBlock->Send((new String(L"\tDoing Int16MethodsTest")));
		this->Int16MethodsTest();
		this->x_caBlock->Send((new String(L"\tDoing Int16MathTest")));
		this->Int16MathTest();
		this->x_caBlock->Send((new String(L"\tDoing Int16Operators")));
		this->Int16Operators();
		this->x_caBlock->Send((new String(L"\tDoing Int16ArrayTests")));
		this->Int16ArrayTests();
		this->x_caBlock->Send((new String(L"\tDoing Int16MiscTests")));
		this->Int16MiscTests();
		return;
	}
	void Int16Test::Int16MethodsTest()
	{
IL_0000:
		Int16 x_num = 5;
		this->CxAssert((Boolean)(((Int16Value(x_num).CompareTo((Int16)(5))) == 0)));
		this->CxAssert((Boolean)(((Int16Value(x_num).CompareTo((new Int16Value(5)))) == 0)));
		this->CxAssert((Boolean)(Int16Value(x_num).Equals((Int16)(5))));
		this->CxAssert((Boolean)(Int16Value(x_num).Equals((new Int16Value(5)))));
		this->CxAssert((Boolean)(((Int16Value::Parse((new String(L"-55")))) == -55)));
		this->CxAssert((Boolean)(String::Equals((new String(L"-75")), Int32Value((-75)).ToString())));
		String* x_text = Int16Value((Int16Value::MaxValue)).ToString();
		this->CxAssert((Boolean)(String::Equals(x_text, (new String(L"32767")))));
		this->CxAssert((Boolean)(((Int16Value::Parse(x_text)) == Int16Value::MaxValue)));
		String* x_text2 = Int16Value((Int16Value::MinValue)).ToString();
		this->CxAssert((Boolean)(String::Equals(x_text2, (new String(L"-32768")))));
		this->CxAssert((Boolean)(((Int16Value::Parse(x_text2)) == Int16Value::MinValue)));
		Int64 x_num2 = Int64Value::MaxValue;
		x_num = ((Int16)x_num2);
		this->CxAssert((Boolean)(((x_num) == -1)));
		Object* x_obj = (new Int16Value(5));
		this->CxAssert((Boolean)(x_obj->Equals((new Int16Value(5)))));
		this->CxAssert((Boolean)(String::Equals(x_obj->ToString(), (new String(L"5")))));
		return;
	}
	void Int16Test::Int16MathTest()
	{
IL_0000:
		Int16 x_num = 600;
		Int16 x_num2 = 1200;
		this->CxAssert((Boolean)((((x_num + x_num2)) == 1800)));
		this->CxAssert((Boolean)((((x_num - x_num2)) == -600)));
		this->CxAssert((Boolean)((((x_num * x_num2)) == 720000)));
		this->CxAssert((Boolean)((((x_num2 / x_num)) == 2)));
		this->CxAssert((Boolean)((((x_num >> 2)) == 150)));
		this->CxAssert((Boolean)((((x_num << 1)) == 1200)));
		Int32 x_num3 = 11;
		this->CxAssert((Boolean)((((x_num3 % 5)) == 1)));
		x_num3 = 8;
		this->CxAssert((Boolean)((((x_num3 | 1)) == 9)));
		this->CxAssert((Boolean)((((x_num3 & 1)) == 0)));
		this->CxAssert((Boolean)(((++x_num3) == 9)));
		this->CxAssert((Boolean)(((--x_num3) == 8)));
		this->CxAssert((Boolean)(((x_num3 = (x_num3 * 2)) == 16)));
		this->CxAssert((Boolean)(((x_num3 = (x_num3 / 2)) == 8)));
		this->CxAssert((Boolean)(((x_num3 = (x_num3 % 2)) == 0)));
		this->CxAssert((Boolean)(((x_num3 = (x_num3 | 4)) == 4)));
		this->CxAssert((Boolean)(((x_num3 = (x_num3 & 4)) == 4)));
		this->CxAssert((Boolean)((((0 - x_num)) == -600)));
		this->CxAssert((Boolean)(((x_num) == 600)));
		x_num3 = 0;
		this->CxAssert((Boolean)(((~x_num3) == -1)));
		this->CxAssert((Boolean)(((++x_num3) == 1)));
		this->CxAssert((Boolean)(((--x_num3) == 0)));
		this->CxAssert((Boolean)(((x_num) < x_num2)));
		this->CxAssert((Boolean)(((x_num) <= x_num2)));
		this->CxAssert((Boolean)(((x_num2) > x_num)));
		this->CxAssert((Boolean)(((x_num2) >= x_num)));
		return;
	}
	void Int16Test::Int16Operators()
	{
IL_0000:
		Int16 x_num = 66;
		Char x_c = 1;
		Byte x_b = 1;
		SByte x_b2 = 1;
		Int16 x_num2 = 1;
		Int32 x_num3 = 1;
		Int64 x_num4 = ((Int64)1);
		UInt16 x_num5 = 1;
		UInt32 x_num6 = 1;
		Single x_num7 = 1;
		Double x_num8 = 1;
		this->CxAssert((Boolean)(((x_num) == 66)));
		this->CxAssert((Boolean)((((x_num + x_c)) == 67)));
		this->CxAssert((Boolean)((((x_num + x_b)) == 67)));
		this->CxAssert((Boolean)((((x_num + x_b2)) == 67)));
		this->CxAssert((Boolean)((((x_num + x_num2)) == 67)));
		this->CxAssert((Boolean)((((x_num + x_num3)) == 67)));
		this->CxAssert((Boolean)((((((Int64)x_num) + x_num4)) == ((Int64)67))));
		this->CxAssert((Boolean)((((x_num + x_num5)) == 67)));
		this->CxAssert((Boolean)((((((Int64)x_num) + ((UInt64)x_num6))) == ((Int64)67))));
		this->CxAssert((Boolean)((((((Single)x_num) + x_num7)) == 67)));
		this->CxAssert((Boolean)((((((Double)x_num) + x_num8)) == 67)));
		this->CxAssert((Boolean)((((x_num - x_c)) == 65)));
		this->CxAssert((Boolean)((((x_num - x_b)) == 65)));
		this->CxAssert((Boolean)((((x_num - x_b2)) == 65)));
		this->CxAssert((Boolean)((((x_num - x_num2)) == 65)));
		this->CxAssert((Boolean)((((x_num - x_num3)) == 65)));
		this->CxAssert((Boolean)((((((Int64)x_num) - x_num4)) == ((Int64)65))));
		this->CxAssert((Boolean)((((x_num - x_num5)) == 65)));
		this->CxAssert((Boolean)((((((Int64)x_num) - ((UInt64)x_num6))) == ((Int64)65))));
		this->CxAssert((Boolean)((((((Single)x_num) - x_num7)) == 65)));
		this->CxAssert((Boolean)((((((Double)x_num) - x_num8)) == 65)));
		this->CxAssert((Boolean)((((x_num * x_c)) == 66)));
		this->CxAssert((Boolean)((((x_num * x_b)) == 66)));
		this->CxAssert((Boolean)((((x_num * x_b2)) == 66)));
		this->CxAssert((Boolean)((((x_num * x_num2)) == 66)));
		this->CxAssert((Boolean)((((x_num * x_num3)) == 66)));
		this->CxAssert((Boolean)((((((Int64)x_num) * x_num4)) == ((Int64)66))));
		this->CxAssert((Boolean)((((x_num * x_num5)) == 66)));
		this->CxAssert((Boolean)((((((Int64)x_num) * ((UInt64)x_num6))) == ((Int64)66))));
		this->CxAssert((Boolean)((((((Single)x_num) * x_num7)) == 66)));
		this->CxAssert((Boolean)((((((Double)x_num) * x_num8)) == 66)));
		this->CxAssert((Boolean)((((x_num / x_c)) == 66)));
		this->CxAssert((Boolean)((((x_num / x_b)) == 66)));
		this->CxAssert((Boolean)((((x_num / x_b2)) == 66)));
		this->CxAssert((Boolean)((((x_num / x_num2)) == 66)));
		this->CxAssert((Boolean)((((x_num / x_num3)) == 66)));
		this->CxAssert((Boolean)((((((Int64)x_num) / x_num4)) == ((Int64)66))));
		this->CxAssert((Boolean)((((x_num / x_num5)) == 66)));
		this->CxAssert((Boolean)((((((Int64)x_num) / ((UInt64)x_num6))) == ((Int64)66))));
		this->CxAssert((Boolean)((((((Single)x_num) / x_num7)) == 66)));
		this->CxAssert((Boolean)((((((Double)x_num) / x_num8)) == 66)));
		this->CxAssert((Boolean)((((x_num % x_c)) == 0)));
		this->CxAssert((Boolean)((((x_num % x_b)) == 0)));
		this->CxAssert((Boolean)((((x_num % x_b2)) == 0)));
		this->CxAssert((Boolean)((((x_num % x_num2)) == 0)));
		this->CxAssert((Boolean)((((x_num % x_num3)) == 0)));
		this->CxAssert((Boolean)((((((Int64)x_num) % x_num4)) == ((Int64)0))));
		this->CxAssert((Boolean)((((x_num % x_num5)) == 0)));
		this->CxAssert((Boolean)((((((Int64)x_num) % ((UInt64)x_num6))) == ((Int64)0))));
		this->CxAssert((Boolean)(((DoubleValue::Modulus(((Single)x_num),x_num7)) == 0)));
		this->CxAssert((Boolean)(((DoubleValue::Modulus(((Double)x_num),x_num8)) == 0)));
		this->CxAssert((Boolean)((((x_num & x_c)) == 0)));
		this->CxAssert((Boolean)((((x_num & x_b)) == 0)));
		this->CxAssert((Boolean)((((x_num & x_b2)) == 0)));
		this->CxAssert((Boolean)((((x_num & x_num2)) == 0)));
		this->CxAssert((Boolean)((((x_num & x_num3)) == 0)));
		this->CxAssert((Boolean)((((((Int64)x_num) & x_num4)) == ((Int64)0))));
		this->CxAssert((Boolean)((((x_num & x_num5)) == 0)));
		this->CxAssert((Boolean)((((((Int64)x_num) & ((UInt64)x_num6))) == ((Int64)0))));
		this->CxAssert((Boolean)((((x_num | ((Int16)x_c))) == 67)));
		this->CxAssert((Boolean)((((x_num | x_b)) == 67)));
		this->CxAssert((Boolean)((((x_num | x_b2)) == 67)));
		this->CxAssert((Boolean)((((x_num | x_num2)) == 67)));
		this->CxAssert((Boolean)((((x_num | ((Int16)x_num3))) == 67)));
		this->CxAssert((Boolean)((((x_num | ((Int16)x_num4))) == 67)));
		this->CxAssert((Boolean)((((x_num | ((Int16)x_num5))) == 67)));
		this->CxAssert((Boolean)((((x_num | ((Int16)x_num6))) == 67)));
		this->CxAssert((Boolean)((((x_num ^ x_c)) == 67)));
		this->CxAssert((Boolean)((((x_num ^ x_b)) == 67)));
		this->CxAssert((Boolean)((((x_num ^ x_b2)) == 67)));
		this->CxAssert((Boolean)((((x_num ^ x_num2)) == 67)));
		this->CxAssert((Boolean)((((x_num ^ x_num3)) == 67)));
		this->CxAssert((Boolean)((((((Int64)x_num) ^ x_num4)) == ((Int64)67))));
		this->CxAssert((Boolean)((((x_num ^ x_num5)) == 67)));
		this->CxAssert((Boolean)((((((Int64)x_num) ^ ((UInt64)x_num6))) == ((Int64)67))));
		this->CxAssert((Boolean)(((~x_num) == -67)));
		this->CxAssert((Boolean)(((x_c) < x_num)));
		this->CxAssert((Boolean)(((x_b) < x_num)));
		this->CxAssert((Boolean)(((x_b2) < x_num)));
		this->CxAssert((Boolean)(((x_num2) < x_num)));
		this->CxAssert((Boolean)(((x_num3) < x_num)));
		this->CxAssert((Boolean)(((x_num4) < ((Int64)x_num))));
		this->CxAssert((Boolean)(((x_num5) < x_num)));
		this->CxAssert((Boolean)(((((UInt64)x_num6)) < ((Int64)x_num))));
		this->CxAssert((Boolean)(((x_num7) < ((Single)x_num))));
		this->CxAssert((Boolean)(((x_num8) < ((Double)x_num))));
		this->CxAssert((Boolean)(((x_c) > x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_b) > x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_b2) > x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num2) > x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num3) > x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num4) > ((Int64)x_num))), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num5) > x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((((UInt64)x_num6)) > ((Int64)x_num))), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num7) > ((Single)x_num))), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num8) > ((Double)x_num))), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num = ((Int16)(x_num + 1))) == 67)));
		this->CxAssert((Boolean)(((x_num = ((Int16)(x_num - 1))) == 66)));
		this->CxAssert((Boolean)(((x_num++) == 66)));
		this->CxAssert((Boolean)(((x_num--) == 67)));
		this->CxAssert((Boolean)((((x_num << 1)) == 132)));
		this->CxAssert((Boolean)((((x_num >> 1)) == 33)));
		this->CxAssert((Boolean)(((x_c) == x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_b) == x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_b2) == x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num2) == x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num3) == x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num4) == ((Int64)x_num))), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num5) == x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((((UInt64)x_num6)) == ((Int64)x_num))), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num7) == ((Single)x_num))), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num8) == ((Double)x_num))), (Boolean)(0));
		this->CxAssert((Boolean)(((x_c) != x_num)));
		this->CxAssert((Boolean)(((x_b) != x_num)));
		this->CxAssert((Boolean)(((x_b2) != x_num)));
		this->CxAssert((Boolean)(((x_num2) != x_num)));
		this->CxAssert((Boolean)(((x_num3) != x_num)));
		this->CxAssert((Boolean)(((x_num4) != ((Int64)x_num))));
		this->CxAssert((Boolean)(((x_num5) != x_num)));
		this->CxAssert((Boolean)(((((UInt64)x_num6)) != ((Int64)x_num))));
		this->CxAssert((Boolean)(((x_num7) != ((Single)x_num))));
		this->CxAssert((Boolean)(((x_num8) != ((Double)x_num))));
		this->CxAssert((Boolean)(((x_c) <= x_num)));
		this->CxAssert((Boolean)(((x_b) <= x_num)));
		this->CxAssert((Boolean)(((x_b2) <= x_num)));
		this->CxAssert((Boolean)(((x_num2) <= x_num)));
		this->CxAssert((Boolean)(((x_num3) <= x_num)));
		this->CxAssert((Boolean)(((x_num4) <= ((Int64)x_num))));
		this->CxAssert((Boolean)(((x_num5) <= x_num)));
		this->CxAssert((Boolean)(((((UInt64)x_num6)) <= ((Int64)x_num))));
		this->CxAssert((Boolean)(((x_num7) <= ((Single)x_num))));
		this->CxAssert((Boolean)(((x_num8) <= ((Double)x_num))));
		this->CxAssert((Boolean)(((x_c) >= x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_b) >= x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_b2) >= x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num2) >= x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num3) >= x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num4) >= ((Int64)x_num))), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num5) >= x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((((UInt64)x_num6)) >= ((Int64)x_num))), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num7) >= ((Single)x_num))), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num8) >= ((Double)x_num))), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num = ((Int16)(x_num + ((Int16)x_c)))) == 67)));
		this->CxAssert((Boolean)(((x_num = ((Int16)(x_num - ((Int16)x_c)))) == 66)));
		this->CxAssert((Boolean)(((x_num = ((Int16)(x_num + ((Int16)x_num3)))) == 67)));
		this->CxAssert((Boolean)(((x_num = ((Int16)(x_num - ((Int16)x_num3)))) == 66)));
		this->CxAssert((Boolean)(((x_num = ((Int16)(x_num * ((Int16)x_c)))) == 66)));
		this->CxAssert((Boolean)(((x_num = ((Int16)(x_num / ((Int16)x_c)))) == 66)));
		this->CxAssert((Boolean)(((x_num = ((Int16)(x_num * ((Int16)x_num3)))) == 66)));
		this->CxAssert((Boolean)(((x_num = ((Int16)(x_num / ((Int16)x_num3)))) == 66)));
		this->CxAssert((Boolean)(((x_num = ((Int16)(x_num % ((Int16)x_c)))) == 0)));
		x_num = 66;
		this->CxAssert((Boolean)(((x_num = ((Int16)(x_num % ((Int16)x_num3)))) == 0)));
		x_num = 66;
		this->CxAssert((Boolean)(((x_num = ((Int16)(x_num & ((Int16)x_c)))) == 0)));
		x_num = 66;
		this->CxAssert((Boolean)(((x_num = ((Int16)(x_num & ((Int16)x_num3)))) == 0)));
		x_num = 66;
		this->CxAssert((Boolean)(((x_num = ((Int16)(x_num | ((Int16)x_c)))) == 67)));
		x_num = 66;
		this->CxAssert((Boolean)(((x_num = ((Int16)(x_num | ((Int16)x_num3)))) == 67)));
		x_num = 66;
		this->CxAssert((Boolean)(((x_num = ((Int16)(x_num ^ ((Int16)x_c)))) == 67)));
		x_num = 66;
		this->CxAssert((Boolean)(((x_num = ((Int16)(x_num ^ ((Int16)x_num3)))) == 67)));
		x_num = 66;
		this->CxAssert((Boolean)(((x_num = ((Int16)(x_num << x_b))) == 132)));
		x_num = 66;
		this->CxAssert((Boolean)(((x_num = ((Int16)(x_num << x_num2))) == 132)));
		x_num = 66;
		this->CxAssert((Boolean)(((x_num = ((Int16)(x_num << x_c))) == 132)));
		x_num = 66;
		this->CxAssert((Boolean)(((x_num = ((Int16)(x_num << x_num3))) == 132)));
		x_num = 66;
		this->CxAssert((Boolean)(((x_num = ((Int16)(x_num >> x_c))) == 33)));
		x_num = 66;
		this->CxAssert((Boolean)(((x_num = ((Int16)(x_num >> x_num3))) == 33)));
		x_num = 66;
		Int16 x_num9 = 0;
		this->CxAssert((Boolean)(((x_num9) == 0)));
		this->CxAssert((Boolean)(((x_num9) == 0)));
		this->CxAssert((Boolean)(((x_num3) <= 2)));
		this->CxAssert((Boolean)(((x_num3) >= -2)));
		return;
	}
	void Int16Test::Int16ArrayTests()
	{
IL_0000:
		Array* x_array = new Array(Int16Type,5);
		(*((Int16*)x_array->Address(0))) = 1;
		(*((Int16*)x_array->Address(1))) = 2;
		(*((Int16*)x_array->Address(2))) = 3;
		(*((Int16*)x_array->Address(3))) = 4;
		(*((Int16*)x_array->Address(4))) = 5;
		this->CxAssert((Boolean)(((x_array->get_Length()) == 5)));
		this->CxAssert((Boolean)((((*((Int16*)x_array->Address(3)))) == 4)));
		Array* x_array2 = new Array(Int16Type,4);
		(*((Int16*)x_array2->Address(0))) = 1;
		(*((Int16*)x_array2->Address(1))) = 2;
		(*((Int16*)x_array2->Address(2))) = 3;
		(*((Int16*)x_array2->Address(3))) = 4;
		this->CxAssert((Boolean)((((*((Int16*)x_array2->Address(1)))) == 2)));
		Array* x_array3 = new Array(Int16Type,2,4);
		(*((Int16*)x_array3->Address(0,0))) = 1;
		(*((Int16*)x_array3->Address(0,1))) = 2;
		(*((Int16*)x_array3->Address(0,2))) = 3;
		(*((Int16*)x_array3->Address(0,3))) = 4;
		(*((Int16*)x_array3->Address(1,0))) = 4;
		(*((Int16*)x_array3->Address(1,1))) = 5;
		(*((Int16*)x_array3->Address(1,2))) = 6;
		(*((Int16*)x_array3->Address(1,3))) = 7;
		this->CxAssert((Boolean)((((*((Int16*)x_array3->Address(0,2)))) == 3)));
		Array* x_array4 = new Array(Int16Type,2,2,4);
		(*((Int16*)x_array4->Address(0,0,0))) = 1;
		(*((Int16*)x_array4->Address(0,0,1))) = 2;
		(*((Int16*)x_array4->Address(0,0,2))) = 3;
		(*((Int16*)x_array4->Address(0,0,3))) = 4;
		(*((Int16*)x_array4->Address(0,1,0))) = 5;
		(*((Int16*)x_array4->Address(0,1,1))) = 6;
		(*((Int16*)x_array4->Address(0,1,2))) = 7;
		(*((Int16*)x_array4->Address(0,1,3))) = 8;
		(*((Int16*)x_array4->Address(1,0,0))) = 9;
		(*((Int16*)x_array4->Address(1,0,1))) = 10;
		(*((Int16*)x_array4->Address(1,0,2))) = 11;
		(*((Int16*)x_array4->Address(1,0,3))) = 12;
		(*((Int16*)x_array4->Address(1,1,0))) = 13;
		(*((Int16*)x_array4->Address(1,1,1))) = 14;
		(*((Int16*)x_array4->Address(1,1,2))) = 15;
		(*((Int16*)x_array4->Address(1,1,3))) = 16;
		this->CxAssert((Boolean)((((*((Int16*)x_array4->Address(0,0,3)))) == 4)));
		(*((Int16*)x_array4->Address(0,0,3))) = 6;
		this->CxAssert((Boolean)((((*((Int16*)x_array4->Address(0,0,3)))) == 6)));
		x_array4->SetValue((new Int16Value(4)), (Int32)(0), (Int32)(0), (Int32)(3));
		this->CxAssert((Boolean)((((*((Int16*)x_array4->Address(0,0,3)))) == 4)));
		return;
	}
	void Int16Test::Int16MiscTests()
	{
IL_0000:
		Int16 x_num = -1;
		Int16 x_val = 1;
		this->CxAssert((Boolean)(((Math::Abs((Int16)(x_num))) == 1)));
		this->CxAssert((Boolean)(((Math::Max((Int16)(x_num), (Int16)(x_val))) == 1)));
		this->CxAssert((Boolean)(((Math::Min((Int16)(x_num), (Int16)(x_val))) == -1)));
		this->CxAssert((Boolean)(((Math::Sign((Int16)(x_num))) < 0)));
		StringBuilder* x_stringBuilder = (new StringBuilder());
		x_stringBuilder->Append((Int16)(x_num));
		this->CxAssert((Boolean)(String::Equals(x_stringBuilder->ToString(), (new String(L"-1")))));
		x_stringBuilder->Insert((Int32)(2), (Int16)(x_num));
		this->CxAssert((Boolean)(String::Equals(x_stringBuilder->ToString(), (new String(L"-1-1")))));
		return;
	}
	void Int16Test::CxAssert(Boolean x_x)
	{
IL_0000:
		if (((x_x) == 0))
		{
			this->x_caBlock->TestFailed((new String(L"Int16 TestFailed")));
		}

		return;
	}
	void Int16Test::CxAssert(Boolean x_x,Boolean x_y)
	{
IL_0000:
		if (((x_x) != x_y))
		{
			this->x_caBlock->TestFailed((new String(L"Int16 TestFailed")));
		}

		return;
	}
	Int32Test::Int32Test(CABlock* x_caBlock)
	{
IL_0000:
		
		this->x_caBlock = x_caBlock;
		return;
	}
	void Int32Test::Test()
	{
IL_0000:
		this->x_caBlock->Send((new String(L"Doing Int32Test")));
		this->x_caBlock->Send((new String(L"\tDoing Int32MethodsTest")));
		this->Int32MethodsTest();
		this->x_caBlock->Send((new String(L"\tDoing Int32MathTest")));
		this->Int32MathTest();
		this->x_caBlock->Send((new String(L"\tDoing Int32Operators")));
		this->Int32Operators();
		this->x_caBlock->Send((new String(L"\tDoing Int32Conversion")));
		this->Int32Conversion();
		this->x_caBlock->Send((new String(L"\tDoing Int32ArrayTests")));
		this->Int32ArrayTests();
		this->x_caBlock->Send((new String(L"\tDoing Int32MiscTests")));
		this->Int32MiscTests();
		return;
	}
	void Int32Test::Int32Conversion()
	{
IL_0000:
		Double x_num = 1;
		Double x_num2 = 2;
		if (((x_num) < x_num2))
		{
			x_num = 3;
		}

		Int32 x_num3 = ((Int32)x_num);
		this->CxAssert((Boolean)(((x_num3) == 3)));
		return;
	}
	void Int32Test::Int32MethodsTest()
	{
IL_0000:
		Int32 x_num = 5;
		this->CxAssert((Boolean)(((Int32Value(x_num).CompareTo((Int32)(5))) == 0)));
		this->CxAssert((Boolean)(((Int32Value(x_num).CompareTo((new Int32Value(5)))) == 0)));
		this->CxAssert((Boolean)(Int32Value(x_num).Equals((Int32)(5))));
		this->CxAssert((Boolean)(Int32Value(x_num).Equals((new Int32Value(5)))));
		this->CxAssert((Boolean)(((Int32Value::Parse((new String(L"-55")))) == -55)));
		this->CxAssert((Boolean)(String::Equals((new String(L"-75")), Int32Value((-75)).ToString())));
		String* x_text = Int32Value((Int32Value::MaxValue)).ToString();
		this->CxAssert((Boolean)(String::Equals(x_text, (new String(L"2147483647")))));
		this->CxAssert((Boolean)(((Int32Value::Parse(x_text)) == Int32Value::MaxValue)));
		String* x_text2 = Int32Value((Int32Value::MinValue)).ToString();
		this->CxAssert((Boolean)(String::Equals(x_text2, (new String(L"-2147483648")))));
		this->CxAssert((Boolean)(((Int32Value::Parse(x_text2)) == Int32Value::MinValue)));
		Int64 x_num2 = Int64Value::MaxValue;
		x_num = ((Int32)x_num2);
		this->CxAssert((Boolean)(((x_num) == -1)));
		Object* x_obj = (new Int32Value(5));
		this->CxAssert((Boolean)(x_obj->Equals((new Int32Value(5)))));
		return;
	}
	void Int32Test::Int32MathTest()
	{
IL_0000:
		Int32 x_num = 60000;
		Int32 x_num2 = 120000;
		this->CxAssert((Boolean)((((x_num + x_num2)) == 180000)));
		this->CxAssert((Boolean)((((x_num - x_num2)) == -60000)));
		this->CxAssert((Boolean)((((x_num * x_num2)) == -1389934592)));
		this->CxAssert((Boolean)((((x_num2 / x_num)) == 2)));
		this->CxAssert((Boolean)((((x_num >> 2)) == 15000)));
		this->CxAssert((Boolean)((((x_num << 1)) == 120000)));
		Int32 x_num3 = 11;
		this->CxAssert((Boolean)((((x_num3 % 5)) == 1)));
		x_num3 = 8;
		this->CxAssert((Boolean)((((x_num3 | 1)) == 9)));
		this->CxAssert((Boolean)((((x_num3 & 1)) == 0)));
		this->CxAssert((Boolean)(((++x_num3) == 9)));
		this->CxAssert((Boolean)(((--x_num3) == 8)));
		this->CxAssert((Boolean)(((x_num3 = (x_num3 * 2)) == 16)));
		this->CxAssert((Boolean)(((x_num3 = (x_num3 / 2)) == 8)));
		this->CxAssert((Boolean)(((x_num3 = (x_num3 % 2)) == 0)));
		this->CxAssert((Boolean)(((x_num3 = (x_num3 | 4)) == 4)));
		this->CxAssert((Boolean)(((x_num3 = (x_num3 & 4)) == 4)));
		this->CxAssert((Boolean)((((0 - x_num)) == -60000)));
		this->CxAssert((Boolean)(((x_num) == 60000)));
		x_num3 = 0;
		this->CxAssert((Boolean)(((~x_num3) == -1)));
		this->CxAssert((Boolean)(((++x_num3) == 1)));
		this->CxAssert((Boolean)(((--x_num3) == 0)));
		this->CxAssert((Boolean)(((x_num) < x_num2)));
		this->CxAssert((Boolean)(((x_num) <= x_num2)));
		this->CxAssert((Boolean)(((x_num2) > x_num)));
		this->CxAssert((Boolean)(((x_num2) >= x_num)));
		return;
	}
	void Int32Test::Int32Operators()
	{
IL_0000:
		Int32 x_num = 66;
		Char x_c = 1;
		Int32 x_num2 = 1;
		UInt32 x_num3 = 1;
		Int64 x_num4 = ((Int64)1);
		Double x_num5 = 1;
		this->CxAssert((Boolean)(((x_num) == 66)));
		this->CxAssert((Boolean)((((x_num + x_c)) == 67)));
		this->CxAssert((Boolean)((((x_num + x_num2)) == 67)));
		this->CxAssert((Boolean)((((((Int64)x_num) + ((UInt64)x_num3))) == ((Int64)67))));
		this->CxAssert((Boolean)((((((Int64)x_num) + x_num4)) == ((Int64)67))));
		this->CxAssert((Boolean)(((((Int64)(((Double)x_num) + x_num5))) == ((Int64)67))));
		this->CxAssert((Boolean)((((x_num - x_c)) == 65)));
		this->CxAssert((Boolean)((((x_num - x_num2)) == 65)));
		this->CxAssert((Boolean)((((((Int64)x_num) - ((UInt64)x_num3))) == ((Int64)65))));
		this->CxAssert((Boolean)((((((Int64)x_num) - x_num4)) == ((Int64)65))));
		this->CxAssert((Boolean)(((((Int64)(((Double)x_num) - x_num5))) == ((Int64)65))));
		this->CxAssert((Boolean)((((x_num * x_c)) == 66)));
		this->CxAssert((Boolean)((((x_num * x_num2)) == 66)));
		this->CxAssert((Boolean)((((((Int64)x_num) * ((UInt64)x_num3))) == ((Int64)66))));
		this->CxAssert((Boolean)((((((Int64)x_num) * x_num4)) == ((Int64)66))));
		this->CxAssert((Boolean)(((((Int64)(((Double)x_num) * x_num5))) == ((Int64)66))));
		this->CxAssert((Boolean)((((x_num / x_c)) == 66)));
		this->CxAssert((Boolean)((((x_num / x_num2)) == 66)));
		this->CxAssert((Boolean)((((((Int64)x_num) / ((UInt64)x_num3))) == ((Int64)66))));
		this->CxAssert((Boolean)((((((Int64)x_num) / x_num4)) == ((Int64)66))));
		this->CxAssert((Boolean)(((((Int64)(((Double)x_num) / x_num5))) == ((Int64)66))));
		this->CxAssert((Boolean)((((x_num % x_c)) == 0)));
		this->CxAssert((Boolean)((((x_num % x_num2)) == 0)));
		this->CxAssert((Boolean)((((((Int64)x_num) % ((UInt64)x_num3))) == ((Int64)0))));
		this->CxAssert((Boolean)((((((Int64)x_num) % x_num4)) == ((Int64)0))));
		this->CxAssert((Boolean)(((((Int64)DoubleValue::Modulus(((Double)x_num),x_num5))) == ((Int64)0))));
		this->CxAssert((Boolean)((((x_num & x_c)) == 0)));
		this->CxAssert((Boolean)((((x_num & x_num2)) == 0)));
		this->CxAssert((Boolean)((((((Int64)x_num) & ((UInt64)x_num3))) == ((Int64)0))));
		this->CxAssert((Boolean)((((((Int64)x_num) & x_num4)) == ((Int64)0))));
		this->CxAssert((Boolean)((((x_num | x_c)) == 67)));
		this->CxAssert((Boolean)((((x_num | x_num2)) == 67)));
		this->CxAssert((Boolean)((((x_num ^ x_c)) == 67)));
		this->CxAssert((Boolean)((((x_num ^ x_num2)) == 67)));
		this->CxAssert((Boolean)((((((Int64)x_num) ^ ((UInt64)x_num3))) == ((Int64)67))));
		this->CxAssert((Boolean)((((((Int64)x_num) ^ x_num4)) == ((Int64)67))));
		this->CxAssert((Boolean)(((~x_num) == -67)));
		this->CxAssert((Boolean)(((x_c) < x_num)));
		this->CxAssert((Boolean)(((x_num2) < x_num)));
		this->CxAssert((Boolean)(((((UInt64)x_num3)) < ((Int64)x_num))));
		this->CxAssert((Boolean)(((x_num4) < ((Int64)x_num))));
		this->CxAssert((Boolean)(((x_num5) < ((Double)x_num))));
		this->CxAssert((Boolean)(((x_c) > x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num2) > x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((((UInt64)x_num3)) > ((Int64)x_num))), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num4) > ((Int64)x_num))), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num5) > ((Double)x_num))), (Boolean)(0));
		this->CxAssert((Boolean)(((++x_num) == 67)));
		this->CxAssert((Boolean)(((--x_num) == 66)));
		this->CxAssert((Boolean)(((x_num++) == 66)));
		this->CxAssert((Boolean)(((x_num--) == 67)));
		this->CxAssert((Boolean)((((x_num << 1)) == 132)));
		this->CxAssert((Boolean)((((x_num >> 1)) == 33)));
		this->CxAssert((Boolean)(((x_c) == x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num2) == x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((((UInt64)x_num3)) == ((Int64)x_num))), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num4) == ((Int64)x_num))), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num5) == ((Double)x_num))), (Boolean)(0));
		this->CxAssert((Boolean)(((x_c) != x_num)));
		this->CxAssert((Boolean)(((x_num2) != x_num)));
		this->CxAssert((Boolean)(((((UInt64)x_num3)) != ((Int64)x_num))));
		this->CxAssert((Boolean)(((x_num4) != ((Int64)x_num))));
		this->CxAssert((Boolean)(((x_num5) != ((Double)x_num))));
		this->CxAssert((Boolean)(((x_c) <= x_num)));
		this->CxAssert((Boolean)(((x_num2) <= x_num)));
		this->CxAssert((Boolean)(((((UInt64)x_num3)) <= ((Int64)x_num))));
		this->CxAssert((Boolean)(((x_num4) <= ((Int64)x_num))));
		this->CxAssert((Boolean)(((x_num5) <= ((Double)x_num))));
		this->CxAssert((Boolean)(((x_c) >= x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num2) >= x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((((UInt64)x_num3)) >= ((Int64)x_num))), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num4) >= ((Int64)x_num))), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num5) >= ((Double)x_num))), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num = (x_num + x_c)) == 67)));
		this->CxAssert((Boolean)(((x_num = (x_num - x_c)) == 66)));
		this->CxAssert((Boolean)(((x_num = (x_num + x_num2)) == 67)));
		this->CxAssert((Boolean)(((x_num = (x_num - x_num2)) == 66)));
		this->CxAssert((Boolean)(((x_num = (x_num * x_c)) == 66)));
		this->CxAssert((Boolean)(((x_num = (x_num / x_c)) == 66)));
		this->CxAssert((Boolean)(((x_num = (x_num * x_num2)) == 66)));
		this->CxAssert((Boolean)(((x_num = (x_num / x_num2)) == 66)));
		this->CxAssert((Boolean)(((x_num = (x_num % x_c)) == 0)));
		x_num = 66;
		this->CxAssert((Boolean)(((x_num = (x_num % x_num2)) == 0)));
		x_num = 66;
		this->CxAssert((Boolean)(((x_num = (x_num & x_c)) == 0)));
		x_num = 66;
		this->CxAssert((Boolean)(((x_num = (x_num & x_num2)) == 0)));
		x_num = 66;
		this->CxAssert((Boolean)(((x_num = (x_num | x_c)) == 67)));
		x_num = 66;
		this->CxAssert((Boolean)(((x_num = (x_num | x_num2)) == 67)));
		x_num = 66;
		this->CxAssert((Boolean)(((x_num = (x_num ^ x_c)) == 67)));
		x_num = 66;
		this->CxAssert((Boolean)(((x_num = (x_num ^ x_num2)) == 67)));
		x_num = 66;
		this->CxAssert((Boolean)(((x_num = (x_num << x_c)) == 132)));
		x_num = 66;
		this->CxAssert((Boolean)(((x_num = (x_num << x_num2)) == 132)));
		x_num = 66;
		this->CxAssert((Boolean)(((x_num = (x_num >> x_c)) == 33)));
		x_num = 66;
		this->CxAssert((Boolean)(((x_num = (x_num >> x_num2)) == 33)));
		x_num = 66;
		Int32 x_num6 = 0;
		this->CxAssert((Boolean)(((x_num6) == 0)));
		this->CxAssert((Boolean)(((x_num6) == 0)));
		this->CxAssert((Boolean)(((x_num2) <= 2)));
		this->CxAssert((Boolean)(((x_num2) >= -2)));
		return;
	}
	void Int32Test::Int32ArrayTests()
	{
IL_0000:
		Array* x_array = new Array(Int32Type,5);
		(*((Int32*)x_array->Address(0))) = 1;
		(*((Int32*)x_array->Address(1))) = 2;
		(*((Int32*)x_array->Address(2))) = 3;
		(*((Int32*)x_array->Address(3))) = 4;
		(*((Int32*)x_array->Address(4))) = 5;
		this->CxAssert((Boolean)(((x_array->get_Length()) == 5)));
		this->CxAssert((Boolean)((((*((Int32*)x_array->Address(3)))) == 4)));
		Array* x_array2 = new Array(Int32Type,4);
		(*((Int32*)x_array2->Address(0))) = 1;
		(*((Int32*)x_array2->Address(1))) = 2;
		(*((Int32*)x_array2->Address(2))) = 3;
		(*((Int32*)x_array2->Address(3))) = 4;
		this->CxAssert((Boolean)((((*((Int32*)x_array2->Address(1)))) == 2)));
		Array* x_array3 = new Array(Int32Type,2,4);
		(*((Int32*)x_array3->Address(0,0))) = 1;
		(*((Int32*)x_array3->Address(0,1))) = 2;
		(*((Int32*)x_array3->Address(0,2))) = 3;
		(*((Int32*)x_array3->Address(0,3))) = 4;
		(*((Int32*)x_array3->Address(1,0))) = 4;
		(*((Int32*)x_array3->Address(1,1))) = 5;
		(*((Int32*)x_array3->Address(1,2))) = 6;
		(*((Int32*)x_array3->Address(1,3))) = 7;
		this->CxAssert((Boolean)((((*((Int32*)x_array3->Address(0,2)))) == 3)));
		Array* x_array4 = new Array(Int32Type,2,2,4);
		(*((Int32*)x_array4->Address(0,0,0))) = 1;
		(*((Int32*)x_array4->Address(0,0,1))) = 2;
		(*((Int32*)x_array4->Address(0,0,2))) = 3;
		(*((Int32*)x_array4->Address(0,0,3))) = 4;
		(*((Int32*)x_array4->Address(0,1,0))) = 5;
		(*((Int32*)x_array4->Address(0,1,1))) = 6;
		(*((Int32*)x_array4->Address(0,1,2))) = 7;
		(*((Int32*)x_array4->Address(0,1,3))) = 8;
		(*((Int32*)x_array4->Address(1,0,0))) = 9;
		(*((Int32*)x_array4->Address(1,0,1))) = 10;
		(*((Int32*)x_array4->Address(1,0,2))) = 11;
		(*((Int32*)x_array4->Address(1,0,3))) = 12;
		(*((Int32*)x_array4->Address(1,1,0))) = 13;
		(*((Int32*)x_array4->Address(1,1,1))) = 14;
		(*((Int32*)x_array4->Address(1,1,2))) = 15;
		(*((Int32*)x_array4->Address(1,1,3))) = 16;
		this->CxAssert((Boolean)((((*((Int32*)x_array4->Address(0,0,3)))) == 4)));
		(*((Int32*)x_array4->Address(0,0,3))) = 6;
		this->CxAssert((Boolean)((((*((Int32*)x_array4->Address(0,0,3)))) == 6)));
		x_array4->SetValue((new Int32Value(4)), (Int32)(0), (Int32)(0), (Int32)(3));
		this->CxAssert((Boolean)((((*((Int32*)x_array4->Address(0,0,3)))) == 4)));
		this->CxAssert((Boolean)(String::Equals(Int32Value((*((Int32*)x_array4->Address(0,0,3)))).ToString(), (new String(L"4")))));
		return;
	}
	void Int32Test::Int32MiscTests()
	{
IL_0000:
		Int32 x_num = -1;
		Int32 x_val = 1;
		this->CxAssert((Boolean)(((Math::Abs((Int32)(x_num))) == 1)));
		this->CxAssert((Boolean)(((Math::Max((Int32)(x_num), (Int32)(x_val))) == 1)));
		this->CxAssert((Boolean)(((Math::Min((Int32)(x_num), (Int32)(x_val))) == -1)));
		this->CxAssert((Boolean)(((Math::Sign((Int32)(x_num))) < 0)));
		StringBuilder* x_stringBuilder = (new StringBuilder());
		x_stringBuilder->Append((Int32)(x_num));
		this->CxAssert((Boolean)(String::Equals(x_stringBuilder->ToString(), (new String(L"-1")))));
		return;
	}
	void Int32Test::CxAssert(Boolean x_x)
	{
IL_0000:
		if (((x_x) == 0))
		{
			this->x_caBlock->TestFailed((new String(L"Int32 TestFailed")));
		}

		return;
	}
	void Int32Test::CxAssert(Boolean x_x,Boolean x_y)
	{
IL_0000:
		if (((x_x) != x_y))
		{
			this->x_caBlock->TestFailed((new String(L"Int32 TestFailed")));
		}

		return;
	}
	Int64Test::Int64Test(CABlock* x_caBlock)
	{
IL_0000:
		
		this->x_caBlock = x_caBlock;
		return;
	}
	void Int64Test::Test()
	{
IL_0000:
		this->x_caBlock->Send((new String(L"Doing Int64Test")));
		this->x_caBlock->Send((new String(L"\tDoing Int64MethodsTest")));
		this->Int64MethodsTest();
		this->x_caBlock->Send((new String(L"\tDoing Int64MathTest")));
		this->Int64MathTest();
		this->x_caBlock->Send((new String(L"\tDoing Int64Operators")));
		this->Int64Operators();
		this->x_caBlock->Send((new String(L"\tDoing Int64ArrayTests")));
		this->Int64ArrayTests();
		this->x_caBlock->Send((new String(L"\tDoing Int64MiscTests")));
		this->Int64MiscTests();
		return;
	}
	void Int64Test::Int64MethodsTest()
	{
IL_0000:
		Int64 x_num = ((Int64)5);
		this->CxAssert((Boolean)(((Int64Value(x_num).CompareTo((Int64)(((Int64)5)))) == 0)));
		this->CxAssert((Boolean)(((Int64Value(x_num).CompareTo((new Int64Value(((Int64)5))))) == 0)));
		this->CxAssert((Boolean)(Int64Value(x_num).Equals((Int64)(((Int64)5)))));
		this->CxAssert((Boolean)(Int64Value(x_num).Equals((new Int64Value(((Int64)5))))));
		this->CxAssert((Boolean)(((Int64Value::Parse((new String(L"-55")))) == ((Int64)-55))));
		String* x_text = Int64Value((Int64Value::MaxValue)).ToString();
		this->CxAssert((Boolean)(String::Equals(x_text, (new String(L"9223372036854775807")))));
		this->CxAssert((Boolean)(((Int64Value::Parse(x_text)) == Int64Value::MaxValue)));
		String* x_text2 = Int64Value((Int64Value::MinValue)).ToString();
		this->CxAssert((Boolean)(String::Equals(x_text2, (new String(L"-9223372036854775808")))));
		this->CxAssert((Boolean)(((Int64Value::Parse(x_text2)) == Int64Value::MinValue)));
		Object* x_obj = (new Int64Value(((Int64)5)));
		this->CxAssert((Boolean)(x_obj->Equals((new Int64Value(((Int64)5))))));
		this->CxAssert((Boolean)(String::Equals(x_obj->ToString(), (new String(L"5")))));
		return;
	}
	void Int64Test::Int64MathTest()
	{
IL_0000:
		Int64 x_num = ((Int64)60000000);
		Int64 x_num2 = ((Int64)120000000);
		this->CxAssert((Boolean)((((x_num + x_num2)) == ((Int64)180000000))));
		this->CxAssert((Boolean)((((x_num - x_num2)) == ((Int64)-60000000))));
		this->CxAssert((Boolean)((((x_num * x_num2)) == 7200000000000000)));
		this->CxAssert((Boolean)((((x_num * x_num2)) == 7200000000000000)));
		this->CxAssert((Boolean)((((x_num2 / x_num)) == ((Int64)2))));
		this->CxAssert((Boolean)((((x_num << 1)) == ((Int64)120000000))));
		Int32 x_num3 = 11;
		this->CxAssert((Boolean)((((x_num3 % 5)) == 1)));
		x_num3 = 8;
		this->CxAssert((Boolean)((((x_num3 | 1)) == 9)));
		this->CxAssert((Boolean)((((x_num3 & 1)) == 0)));
		this->CxAssert((Boolean)(((++x_num3) == 9)));
		this->CxAssert((Boolean)(((--x_num3) == 8)));
		this->CxAssert((Boolean)(((x_num3 = (x_num3 * 2)) == 16)));
		this->CxAssert((Boolean)(((x_num3 = (x_num3 / 2)) == 8)));
		this->CxAssert((Boolean)(((x_num3 = (x_num3 % 2)) == 0)));
		this->CxAssert((Boolean)(((x_num3 = (x_num3 | 4)) == 4)));
		this->CxAssert((Boolean)(((x_num3 = (x_num3 & 4)) == 4)));
		this->CxAssert((Boolean)((((0 - x_num)) == ((Int64)-60000000))));
		this->CxAssert((Boolean)(((x_num) == ((Int64)60000000))));
		x_num3 = 0;
		this->CxAssert((Boolean)(((~x_num3) == -1)));
		this->CxAssert((Boolean)(((++x_num3) == 1)));
		this->CxAssert((Boolean)(((--x_num3) == 0)));
		return;
	}
	void Int64Test::Int64Operators()
	{
IL_0000:
		Int64 x_num = ((Int64)66);
		Char x_c = 1;
		Int32 x_num2 = 1;
		UInt32 x_num3 = 1;
		Int64 x_num4 = ((Int64)1);
		Double x_num5 = 1;
		this->CxAssert((Boolean)(((x_num) == ((Int64)66))));
		this->CxAssert((Boolean)((((x_num + ((UInt64)x_c))) == ((Int64)67))));
		this->CxAssert((Boolean)((((x_num + ((Int64)x_num2))) == ((Int64)67))));
		this->CxAssert((Boolean)((((x_num + ((UInt64)x_num3))) == ((Int64)67))));
		this->CxAssert((Boolean)((((x_num + x_num4)) == ((Int64)67))));
		this->CxAssert((Boolean)((((((Double)x_num) + x_num5)) == 67)));
		this->CxAssert((Boolean)((((x_num - ((UInt64)x_c))) == ((Int64)65))));
		this->CxAssert((Boolean)((((x_num - ((Int64)x_num2))) == ((Int64)65))));
		this->CxAssert((Boolean)((((x_num - ((UInt64)x_num3))) == ((Int64)65))));
		this->CxAssert((Boolean)((((x_num - x_num4)) == ((Int64)65))));
		this->CxAssert((Boolean)((((((Double)x_num) - x_num5)) == 65)));
		this->CxAssert((Boolean)((((x_num * ((UInt64)x_c))) == ((Int64)66))));
		this->CxAssert((Boolean)((((x_num * ((Int64)x_num2))) == ((Int64)66))));
		this->CxAssert((Boolean)((((x_num * ((UInt64)x_num3))) == ((Int64)66))));
		this->CxAssert((Boolean)((((x_num * x_num4)) == ((Int64)66))));
		this->CxAssert((Boolean)((((((Double)x_num) * x_num5)) == 66)));
		this->CxAssert((Boolean)((((x_num / ((UInt64)x_c))) == ((Int64)66))));
		this->CxAssert((Boolean)((((x_num / ((Int64)x_num2))) == ((Int64)66))));
		this->CxAssert((Boolean)((((x_num / ((UInt64)x_num3))) == ((Int64)66))));
		this->CxAssert((Boolean)((((x_num / x_num4)) == ((Int64)66))));
		this->CxAssert((Boolean)((((((Double)x_num) / x_num5)) == 66)));
		this->CxAssert((Boolean)((((x_num % ((UInt64)x_c))) == ((Int64)0))));
		this->CxAssert((Boolean)((((x_num % ((Int64)x_num2))) == ((Int64)0))));
		this->CxAssert((Boolean)((((x_num % ((UInt64)x_num3))) == ((Int64)0))));
		this->CxAssert((Boolean)((((x_num % x_num4)) == ((Int64)0))));
		this->CxAssert((Boolean)(((DoubleValue::Modulus(((Double)x_num),x_num5)) == 0)));
		this->CxAssert((Boolean)((((x_num & ((UInt64)x_c))) == ((Int64)0))));
		this->CxAssert((Boolean)((((x_num & ((Int64)x_num2))) == ((Int64)0))));
		this->CxAssert((Boolean)((((x_num & ((UInt64)x_num3))) == ((Int64)0))));
		this->CxAssert((Boolean)((((x_num & x_num4)) == ((Int64)0))));
		this->CxAssert((Boolean)((((x_num | ((UInt64)x_c))) == ((Int64)67))));
		this->CxAssert((Boolean)((((x_num | ((UInt64)x_num3))) == ((Int64)67))));
		this->CxAssert((Boolean)((((x_num | x_num4)) == ((Int64)67))));
		this->CxAssert((Boolean)((((x_num ^ ((UInt64)x_c))) == ((Int64)67))));
		this->CxAssert((Boolean)((((x_num ^ ((Int64)x_num2))) == ((Int64)67))));
		this->CxAssert((Boolean)((((x_num ^ ((UInt64)x_num3))) == ((Int64)67))));
		this->CxAssert((Boolean)((((x_num ^ x_num4)) == ((Int64)67))));
		this->CxAssert((Boolean)(((~x_num) == ((Int64)-67))));
		this->CxAssert((Boolean)(((((UInt64)x_c)) < x_num)));
		this->CxAssert((Boolean)(((((Int64)x_num2)) < x_num)));
		this->CxAssert((Boolean)(((((UInt64)x_num3)) < x_num)));
		this->CxAssert((Boolean)(((x_num4) < x_num)));
		this->CxAssert((Boolean)(((x_num5) < ((Double)x_num))));
		this->CxAssert((Boolean)(((((UInt64)x_c)) > x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((((Int64)x_num2)) > x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((((UInt64)x_num3)) > x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num4) > x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num5) > ((Double)x_num))), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num = (x_num + ((Int64)1))) == ((Int64)67))));
		this->CxAssert((Boolean)(((x_num = (x_num - ((Int64)1))) == ((Int64)66))));
		this->CxAssert((Boolean)(((x_num++) == ((Int64)66))));
		this->CxAssert((Boolean)(((x_num--) == ((Int64)67))));
		this->CxAssert((Boolean)((((x_num << 1)) == ((Int64)132))));
		this->CxAssert((Boolean)((((x_num >> 1)) == ((Int64)33))));
		this->CxAssert((Boolean)(((((UInt64)x_c)) == x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((((Int64)x_num2)) == x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((((UInt64)x_num3)) == x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num4) == x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num5) == ((Double)x_num))), (Boolean)(0));
		this->CxAssert((Boolean)(((((UInt64)x_c)) != x_num)));
		this->CxAssert((Boolean)(((((Int64)x_num2)) != x_num)));
		this->CxAssert((Boolean)(((((UInt64)x_num3)) != x_num)));
		this->CxAssert((Boolean)(((x_num4) != x_num)));
		this->CxAssert((Boolean)(((x_num5) != ((Double)x_num))));
		this->CxAssert((Boolean)(((((UInt64)x_c)) <= x_num)));
		this->CxAssert((Boolean)(((((Int64)x_num2)) <= x_num)));
		this->CxAssert((Boolean)(((((UInt64)x_num3)) <= x_num)));
		this->CxAssert((Boolean)(((x_num4) <= x_num)));
		this->CxAssert((Boolean)(((x_num5) <= ((Double)x_num))));
		this->CxAssert((Boolean)(((((UInt64)x_c)) >= x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((((Int64)x_num2)) >= x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((((UInt64)x_num3)) >= x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num4) >= x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num5) >= ((Double)x_num))), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num = (x_num + ((UInt64)x_c))) == ((Int64)67))));
		this->CxAssert((Boolean)(((x_num = (x_num - ((UInt64)x_c))) == ((Int64)66))));
		this->CxAssert((Boolean)(((x_num = (x_num + ((Int64)x_num2))) == ((Int64)67))));
		this->CxAssert((Boolean)(((x_num = (x_num - ((Int64)x_num2))) == ((Int64)66))));
		this->CxAssert((Boolean)(((x_num = (x_num + ((UInt64)x_num3))) == ((Int64)67))));
		this->CxAssert((Boolean)(((x_num = (x_num - ((UInt64)x_num3))) == ((Int64)66))));
		this->CxAssert((Boolean)(((x_num = (x_num + x_num4)) == ((Int64)67))));
		this->CxAssert((Boolean)(((x_num = (x_num - x_num4)) == ((Int64)66))));
		this->CxAssert((Boolean)(((x_num = (x_num * ((UInt64)x_c))) == ((Int64)66))));
		this->CxAssert((Boolean)(((x_num = (x_num / ((UInt64)x_c))) == ((Int64)66))));
		this->CxAssert((Boolean)(((x_num = (x_num * ((Int64)x_num2))) == ((Int64)66))));
		this->CxAssert((Boolean)(((x_num = (x_num / ((Int64)x_num2))) == ((Int64)66))));
		this->CxAssert((Boolean)(((x_num = (x_num * ((UInt64)x_num3))) == ((Int64)66))));
		this->CxAssert((Boolean)(((x_num = (x_num / ((UInt64)x_num3))) == ((Int64)66))));
		this->CxAssert((Boolean)(((x_num = (x_num * x_num4)) == ((Int64)66))));
		this->CxAssert((Boolean)(((x_num = (x_num / x_num4)) == ((Int64)66))));
		this->CxAssert((Boolean)(((x_num = (x_num % ((UInt64)x_c))) == ((Int64)0))));
		x_num = ((Int64)66);
		this->CxAssert((Boolean)(((x_num = (x_num % ((Int64)x_num2))) == ((Int64)0))));
		x_num = ((Int64)66);
		this->CxAssert((Boolean)(((x_num = (x_num % ((UInt64)x_num3))) == ((Int64)0))));
		x_num = ((Int64)66);
		this->CxAssert((Boolean)(((x_num = (x_num % x_num4)) == ((Int64)0))));
		x_num = ((Int64)66);
		this->CxAssert((Boolean)(((x_num = (x_num & ((UInt64)x_c))) == ((Int64)0))));
		x_num = ((Int64)66);
		this->CxAssert((Boolean)(((x_num = (x_num & ((Int64)x_num2))) == ((Int64)0))));
		x_num = ((Int64)66);
		this->CxAssert((Boolean)(((x_num = (x_num & ((UInt64)x_num3))) == ((Int64)0))));
		x_num = ((Int64)66);
		this->CxAssert((Boolean)(((x_num = (x_num & x_num4)) == ((Int64)0))));
		x_num = ((Int64)66);
		this->CxAssert((Boolean)(((x_num = (x_num | ((UInt64)x_c))) == ((Int64)67))));
		x_num = ((Int64)66);
		this->CxAssert((Boolean)(((x_num = (x_num | ((UInt64)x_num3))) == ((Int64)67))));
		x_num = ((Int64)66);
		this->CxAssert((Boolean)(((x_num = (x_num | x_num4)) == ((Int64)67))));
		x_num = ((Int64)66);
		this->CxAssert((Boolean)(((x_num = (x_num ^ ((UInt64)x_c))) == ((Int64)67))));
		x_num = ((Int64)66);
		this->CxAssert((Boolean)(((x_num = (x_num ^ ((Int64)x_num2))) == ((Int64)67))));
		x_num = ((Int64)66);
		this->CxAssert((Boolean)(((x_num = (x_num ^ ((UInt64)x_num3))) == ((Int64)67))));
		x_num = ((Int64)66);
		this->CxAssert((Boolean)(((x_num = (x_num ^ x_num4)) == ((Int64)67))));
		x_num = ((Int64)66);
		this->CxAssert((Boolean)(((x_num = (x_num << x_c)) == ((Int64)132))));
		x_num = ((Int64)66);
		this->CxAssert((Boolean)(((x_num = (x_num << x_num2)) == ((Int64)132))));
		x_num = ((Int64)66);
		this->CxAssert((Boolean)(((x_num = (x_num >> x_c)) == ((Int64)33))));
		x_num = ((Int64)66);
		this->CxAssert((Boolean)(((x_num = (x_num >> x_num2)) == ((Int64)33))));
		x_num = ((Int64)66);
		return;
	}
	void Int64Test::Int64ArrayTests()
	{
IL_0000:
		Array* x_array = new Array(Int64Type,5);
		(*((Int64*)x_array->Address(0))) = 1;
		(*((Int64*)x_array->Address(1))) = 2;
		(*((Int64*)x_array->Address(2))) = 3;
		(*((Int64*)x_array->Address(3))) = 4;
		(*((Int64*)x_array->Address(4))) = 5;
		this->CxAssert((Boolean)(((x_array->get_Length()) == 5)));
		this->CxAssert((Boolean)((((*((Int64*)x_array->Address(3)))) == ((Int64)4))));
		Array* x_array2 = new Array(Int64Type,4);
		(*((Int64*)x_array2->Address(0))) = 1;
		(*((Int64*)x_array2->Address(1))) = 2;
		(*((Int64*)x_array2->Address(2))) = 3;
		(*((Int64*)x_array2->Address(3))) = 4;
		this->CxAssert((Boolean)((((*((Int64*)x_array2->Address(1)))) == ((Int64)2))));
		Array* x_array3 = new Array(Int64Type,2,4);
		(*((Int64*)x_array3->Address(0,0))) = 1;
		(*((Int64*)x_array3->Address(0,1))) = 2;
		(*((Int64*)x_array3->Address(0,2))) = 3;
		(*((Int64*)x_array3->Address(0,3))) = 4;
		(*((Int64*)x_array3->Address(1,0))) = 4;
		(*((Int64*)x_array3->Address(1,1))) = 5;
		(*((Int64*)x_array3->Address(1,2))) = 6;
		(*((Int64*)x_array3->Address(1,3))) = 7;
		this->CxAssert((Boolean)((((*((Int64*)x_array3->Address(0,2)))) == ((Int64)3))));
		Array* x_array4 = new Array(Int64Type,2,2,4);
		(*((Int64*)x_array4->Address(0,0,0))) = 1;
		(*((Int64*)x_array4->Address(0,0,1))) = 2;
		(*((Int64*)x_array4->Address(0,0,2))) = 3;
		(*((Int64*)x_array4->Address(0,0,3))) = 4;
		(*((Int64*)x_array4->Address(0,1,0))) = 5;
		(*((Int64*)x_array4->Address(0,1,1))) = 6;
		(*((Int64*)x_array4->Address(0,1,2))) = 7;
		(*((Int64*)x_array4->Address(0,1,3))) = 8;
		(*((Int64*)x_array4->Address(1,0,0))) = 9;
		(*((Int64*)x_array4->Address(1,0,1))) = 10;
		(*((Int64*)x_array4->Address(1,0,2))) = 11;
		(*((Int64*)x_array4->Address(1,0,3))) = 12;
		(*((Int64*)x_array4->Address(1,1,0))) = 13;
		(*((Int64*)x_array4->Address(1,1,1))) = 14;
		(*((Int64*)x_array4->Address(1,1,2))) = 15;
		(*((Int64*)x_array4->Address(1,1,3))) = 16;
		this->CxAssert((Boolean)((((*((Int64*)x_array4->Address(0,0,3)))) == ((Int64)4))));
		(*((Int64*)x_array4->Address(0,0,3))) = ((Int64)6);
		this->CxAssert((Boolean)((((*((Int64*)x_array4->Address(0,0,3)))) == ((Int64)6))));
		x_array4->SetValue((new Int64Value(((Int64)4))), (Int32)(0), (Int32)(0), (Int32)(3));
		this->CxAssert((Boolean)((((*((Int64*)x_array4->Address(0,0,3)))) == ((Int64)4))));
		return;
	}
	void Int64Test::Int64MiscTests()
	{
IL_0000:
		Int64 x_num = ((Int64)-1);
		Int64 x_val = ((Int64)1);
		this->CxAssert((Boolean)(((Math::Abs((Int64)(x_num))) == ((Int64)1))));
		this->CxAssert((Boolean)(((Math::Max((Int64)(x_num), (Int64)(x_val))) == ((Int64)1))));
		this->CxAssert((Boolean)(((Math::Min((Int64)(x_num), (Int64)(x_val))) == ((Int64)-1))));
		this->CxAssert((Boolean)(((Math::Sign((Int64)(x_num))) < 0)));
		StringBuilder* x_stringBuilder = (new StringBuilder());
		x_stringBuilder->Append((Int64)(x_num));
		this->CxAssert((Boolean)(String::Equals(x_stringBuilder->ToString(), (new String(L"-1")))));
		return;
	}
	void Int64Test::CxAssert(Boolean x_x)
	{
IL_0000:
		if (((x_x) == 0))
		{
			this->x_caBlock->TestFailed((new String(L"Int64 TestFailed")));
		}

		return;
	}
	void Int64Test::CxAssert(Boolean x_x,Boolean x_y)
	{
IL_0000:
		if (((x_x) != x_y))
		{
			this->x_caBlock->TestFailed((new String(L"Int64 TestFailed")));
		}

		return;
	}
	MathTest::MathTest(CABlock* x_caBlock)
	{
IL_0000:
		
		this->x_caBlock = x_caBlock;
		return;
	}
	void MathTest::Test()
	{
IL_0000:
		this->x_caBlock->Send((new String(L"Doing MathTest")));
		this->DoMathTest();
		return;
	}
	void MathTest::DoMathTest()
	{
IL_0000:
		this->CxAssert((Double)(Math::Abs((Double)(-1))), (Double)(1));
		this->CxAssert((Double)(Math::Abs((Double)(1))), (Double)(1));
		this->CxAssert((Boolean)(((Math::Abs((Int32)(-1))) == 1)));
		this->CxAssert((Boolean)(((Math::Abs((Int32)(1))) == 1)));
		this->CxAssert((Boolean)(((Math::Abs((Int64)(((Int64)-1)))) == ((Int64)1))));
		this->CxAssert((Boolean)(((Math::Abs((Int64)(((Int64)1)))) == ((Int64)1))));
		this->CxAssert((Double)(Math::Acos((Double)(0.5))), (Double)(1.0471975511966));
		this->CxAssert((Double)(Math::Asin((Double)(0.5))), (Double)(0.523598775598299));
		this->CxAssert((Double)(Math::Atan((Double)(0.5))), (Double)(0.463647609000806));
		this->CxAssert((Double)(Math::Atan2((Double)(2), (Double)(1))), (Double)(1.10714871779409));
		this->CxAssert((Double)(Math::Ceiling((Double)(1.1))), (Double)(2));
		this->CxAssert((Double)(Math::Cos((Double)(0.5))), (Double)(0.877582561890373));
		this->CxAssert((Double)(Math::Cosh((Double)(0.5))), (Double)(1.12762596520638));
		this->CxAssert((Double)(Math::Exp((Double)(0.5))), (Double)(1.64872127070013));
		this->CxAssert((Double)(Math::Floor((Double)(1.1))), (Double)(1));
		this->CxAssert((Double)(Math::Log((Double)(0.5))), (Double)(-0.693147180559945));
		this->CxAssert((Double)(Math::Log((Double)(0.4), (Double)(0.5))), (Double)(1.32192809488736));
		this->CxAssert((Double)(Math::Log10((Double)(0.5))), (Double)(-0.301029995663981));
		this->CxAssert((Double)(Math::Max((Double)(1.1), (Double)(1.2))), (Double)(1.2));
		this->CxAssert((Boolean)(((Math::Max((Int32)(1), (Int32)(2))) == 2)));
		this->CxAssert((Boolean)(((Math::Max((Int64)(((Int64)1)), (Int64)(((Int64)2)))) == ((Int64)2))));
		this->CxAssert((Boolean)(((Math::Max((UInt32)(1), (UInt32)(2))) == 2)));
		this->CxAssert((Double)(Math::Min((Double)(1.1), (Double)(1.2))), (Double)(1.1));
		this->CxAssert((Boolean)(((Math::Min((Int32)(1), (Int32)(2))) == 1)));
		this->CxAssert((Boolean)(((Math::Min((Int64)(((Int64)1)), (Int64)(((Int64)2)))) == ((Int64)1))));
		this->CxAssert((Boolean)(((Math::Min((UInt32)(1), (UInt32)(2))) == 1)));
		this->CxAssert((Double)(Math::Pow((Double)(0.4), (Double)(0.5))), (Double)(0.632455532033676));
		this->CxAssert((Double)(Math::Round((Double)(4.5))), (Double)(4));
		this->CxAssert((Double)(Math::Round((Double)(4.6))), (Double)(5));
		this->CxAssert((Double)(Math::Round((Double)(DoubleValue::NaN))), (Double)(DoubleValue::NaN));
		this->CxAssert((Double)(Math::Round((Double)(3.45), (Int32)(1))), (Double)(3.4));
		this->CxAssert((Double)(Math::Round((Double)(3.46), (Int32)(1))), (Double)(3.5));
		this->CxAssert((Double)(Math::Round((Double)(-0.123456789), (Int32)(1))), (Double)(-0.1));
		this->CxAssert((Double)(Math::Round((Double)(DoubleValue::NaN), (Int32)(1))), (Double)(DoubleValue::NaN));
		this->CxAssert((Double)(Math::Round((Double)(1.5))), (Double)(2));
		this->CxAssert((Double)(Math::Round((Double)(2.5))), (Double)(2));
		this->CxAssert((Double)(Math::Round((Double)(-1.5))), (Double)(-2));
		this->CxAssert((Double)(Math::Round((Double)(-2.5))), (Double)(-2));
		this->CxAssert((Double)(Math::Round((Double)(DoubleValue::MaxValue))), (Double)(DoubleValue::MaxValue));
		this->CxAssert((Double)(Math::Round((Double)(DoubleValue::MinValue))), (Double)(DoubleValue::MinValue));
		this->CxAssert((Boolean)(((Math::Sign((Int32)(2))) == 1)));
		this->CxAssert((Boolean)(((Math::Sign((Int32)(0))) == 0)));
		this->CxAssert((Boolean)(((Math::Sign((Int32)(-2))) == -1)));
		this->CxAssert((Boolean)(((Math::Sign((Int64)(((Int64)2)))) == 1)));
		this->CxAssert((Boolean)(((Math::Sign((Int64)(((Int64)0)))) == 0)));
		this->CxAssert((Boolean)(((Math::Sign((Int64)(((Int64)-2)))) == -1)));
		this->CxAssert((Boolean)(((Math::Sign((Double)(2))) == 1)));
		this->CxAssert((Boolean)(((Math::Sign((Double)(0))) == 0)));
		this->CxAssert((Boolean)(((Math::Sign((Double)(-2))) == -1)));
		this->CxAssert((Boolean)(((Math::Sign((Double)(DoubleValue::Epsilon))) == 1)));
		this->CxAssert((Double)(Math::Sin((Double)(0.5))), (Double)(0.479425538604203));
		this->CxAssert((Double)(Math::Sinh((Double)(0.5))), (Double)(0.521095305493747));
		this->CxAssert((Double)(Math::Sqrt((Double)(25))), (Double)(5));
		this->CxAssert((Double)(Math::Tan((Double)(0.52))), (Double)(0.572561830251668));
		this->CxAssert((Double)(Math::Tanh((Double)(0.52))), (Double)(0.477700012168498));
		Double x_num = 2.71828182845905;
		this->CxAssert((Boolean)(((2.71828182845905) == x_num)));
		Double x_num2 = 3.14159265358979;
		this->CxAssert((Boolean)(((3.14159265358979) == x_num2)));
		this->CxAssert((Boolean)(((Math::Truncate((Double)(x_num2))) == 3)));
		return;
	}
	void MathTest::DoubleCompare(Double x_n1,Double x_n2,Double x_resolution)
	{
IL_0000:
		if (((Math::Abs((Double)((x_n1 - x_n2)))) > x_resolution))
		{
			this->x_caBlock->TestFailed((new String(L"BaseTest TestFailed")));
		}

		return;
	}
	void MathTest::CxAssert(Double x_x,Double x_y)
	{
IL_0000:
		this->DoubleCompare((Double)(x_x), (Double)(x_y), (Double)(1E-05));
		return;
	}
	void MathTest::CxAssert(Boolean x_x)
	{
IL_0000:
		if (((x_x) == 0))
		{
			this->x_caBlock->TestFailed((new String(L"BaseTest TestFailed")));
		}

		return;
	}
	SByteTest::SByteTest(CABlock* x_caBlock)
	{
IL_0000:
		
		this->x_caBlock = x_caBlock;
		return;
	}
	void SByteTest::Test()
	{
IL_0000:
		this->x_caBlock->Send((new String(L"Doing SByteTest")));
		this->x_caBlock->Send((new String(L"\tDoing SByteMethodsTest")));
		this->SByteMethodsTest();
		this->x_caBlock->Send((new String(L"\tDoing SByteMathTest")));
		this->SByteMathTest();
		this->x_caBlock->Send((new String(L"\tDoing SByteOperators")));
		this->SByteOperators();
		this->x_caBlock->Send((new String(L"\tDoing SByteArrayTests")));
		this->SByteArrayTests();
		this->x_caBlock->Send((new String(L"\tDoing SByteMiscTests")));
		this->SByteMiscTests();
		return;
	}
	void SByteTest::SByteMethodsTest()
	{
IL_0000:
		SByte x_b = 5;
		this->CxAssert((Boolean)(((SByteValue(x_b).CompareTo((SByte)(5))) == 0)));
		this->CxAssert((Boolean)(((SByteValue(x_b).CompareTo((new SByteValue(5)))) == 0)));
		this->CxAssert((Boolean)(SByteValue(x_b).Equals((SByte)(5))));
		this->CxAssert((Boolean)(SByteValue(x_b).Equals((new SByteValue(5)))));
		this->CxAssert((Boolean)(((SByteValue::Parse((new String(L"-55")))) == -55)));
		this->CxAssert((Boolean)(String::Equals((new String(L"-75")), Int32Value((-75)).ToString())));
		String* x_text = SByteValue((SByteValue::MaxValue)).ToString();
		this->CxAssert((Boolean)(String::Equals(x_text, (new String(L"127")))));
		this->CxAssert((Boolean)(((SByteValue::Parse(x_text)) == SByteValue::MaxValue)));
		String* x_text2 = SByteValue((SByteValue::MinValue)).ToString();
		this->CxAssert((Boolean)(String::Equals(x_text2, (new String(L"-128")))));
		this->CxAssert((Boolean)(((SByteValue::Parse(x_text2)) == SByteValue::MinValue)));
		Int64 x_num = Int64Value::MaxValue;
		x_b = ((SByte)x_num);
		this->CxAssert((Boolean)(((x_b) == -1)));
		Object* x_obj = (new SByteValue(5));
		this->CxAssert((Boolean)(x_obj->Equals((new SByteValue(5)))));
		this->CxAssert((Boolean)(String::Equals(x_obj->ToString(), (new String(L"5")))));
		return;
	}
	void SByteTest::SByteMathTest()
	{
IL_0000:
		SByte x_b = 6;
		SByte x_b2 = 12;
		this->CxAssert((Boolean)((((x_b + x_b2)) == 18)));
		this->CxAssert((Boolean)((((x_b - x_b2)) == -6)));
		this->CxAssert((Boolean)((((x_b * x_b2)) == 72)));
		this->CxAssert((Boolean)((((x_b2 / x_b)) == 2)));
		this->CxAssert((Boolean)((((x_b >> 2)) == 1)));
		this->CxAssert((Boolean)((((x_b << 1)) == 12)));
		Int32 x_num = 11;
		this->CxAssert((Boolean)((((x_num % 5)) == 1)));
		x_num = 8;
		this->CxAssert((Boolean)((((x_num | 1)) == 9)));
		this->CxAssert((Boolean)((((x_num & 1)) == 0)));
		this->CxAssert((Boolean)(((++x_num) == 9)));
		this->CxAssert((Boolean)(((--x_num) == 8)));
		this->CxAssert((Boolean)(((x_num = (x_num * 2)) == 16)));
		this->CxAssert((Boolean)(((x_num = (x_num / 2)) == 8)));
		this->CxAssert((Boolean)(((x_num = (x_num % 2)) == 0)));
		this->CxAssert((Boolean)(((x_num = (x_num | 4)) == 4)));
		this->CxAssert((Boolean)(((x_num = (x_num & 4)) == 4)));
		this->CxAssert((Boolean)((((0 - x_b)) == -6)));
		this->CxAssert((Boolean)(((x_b) == 6)));
		x_num = 0;
		this->CxAssert((Boolean)(((~x_num) == -1)));
		this->CxAssert((Boolean)(((++x_num) == 1)));
		this->CxAssert((Boolean)(((--x_num) == 0)));
		this->CxAssert((Boolean)(((x_b) < x_b2)));
		this->CxAssert((Boolean)(((x_b) <= x_b2)));
		this->CxAssert((Boolean)(((x_b2) > x_b)));
		this->CxAssert((Boolean)(((x_b2) >= x_b)));
		return;
	}
	void SByteTest::SByteOperators()
	{
IL_0000:
		SByte x_b = 66;
		Char x_c = 1;
		Byte x_b2 = 1;
		SByte x_b3 = 1;
		SByte x_b4 = 1;
		Int32 x_num = 1;
		Int64 x_num2 = ((Int64)1);
		UInt16 x_num3 = 1;
		UInt32 x_num4 = 1;
		Single x_num5 = 1;
		Double x_num6 = 1;
		this->CxAssert((Boolean)(((x_b) == 66)));
		this->CxAssert((Boolean)((((x_b + x_c)) == 67)));
		this->CxAssert((Boolean)((((x_b + x_b2)) == 67)));
		this->CxAssert((Boolean)((((x_b + x_b3)) == 67)));
		this->CxAssert((Boolean)((((x_b + x_b4)) == 67)));
		this->CxAssert((Boolean)((((x_b + x_num)) == 67)));
		this->CxAssert((Boolean)((((((Int64)x_b) + x_num2)) == ((Int64)67))));
		this->CxAssert((Boolean)((((x_b + x_num3)) == 67)));
		this->CxAssert((Boolean)((((((Int64)x_b) + ((UInt64)x_num4))) == ((Int64)67))));
		this->CxAssert((Boolean)((((((Single)x_b) + x_num5)) == 67)));
		this->CxAssert((Boolean)((((((Double)x_b) + x_num6)) == 67)));
		this->CxAssert((Boolean)((((x_b - x_c)) == 65)));
		this->CxAssert((Boolean)((((x_b - x_b2)) == 65)));
		this->CxAssert((Boolean)((((x_b - x_b3)) == 65)));
		this->CxAssert((Boolean)((((x_b - x_b4)) == 65)));
		this->CxAssert((Boolean)((((x_b - x_num)) == 65)));
		this->CxAssert((Boolean)((((((Int64)x_b) - x_num2)) == ((Int64)65))));
		this->CxAssert((Boolean)((((x_b - x_num3)) == 65)));
		this->CxAssert((Boolean)((((((Int64)x_b) - ((UInt64)x_num4))) == ((Int64)65))));
		this->CxAssert((Boolean)((((((Single)x_b) - x_num5)) == 65)));
		this->CxAssert((Boolean)((((((Double)x_b) - x_num6)) == 65)));
		this->CxAssert((Boolean)((((x_b * x_c)) == 66)));
		this->CxAssert((Boolean)((((x_b * x_b2)) == 66)));
		this->CxAssert((Boolean)((((x_b * x_b3)) == 66)));
		this->CxAssert((Boolean)((((x_b * x_b4)) == 66)));
		this->CxAssert((Boolean)((((x_b * x_num)) == 66)));
		this->CxAssert((Boolean)((((((Int64)x_b) * x_num2)) == ((Int64)66))));
		this->CxAssert((Boolean)((((x_b * x_num3)) == 66)));
		this->CxAssert((Boolean)((((((Int64)x_b) * ((UInt64)x_num4))) == ((Int64)66))));
		this->CxAssert((Boolean)((((((Single)x_b) * x_num5)) == 66)));
		this->CxAssert((Boolean)((((((Double)x_b) * x_num6)) == 66)));
		this->CxAssert((Boolean)((((x_b / x_c)) == 66)));
		this->CxAssert((Boolean)((((x_b / x_b2)) == 66)));
		this->CxAssert((Boolean)((((x_b / x_b3)) == 66)));
		this->CxAssert((Boolean)((((x_b / x_b4)) == 66)));
		this->CxAssert((Boolean)((((x_b / x_num)) == 66)));
		this->CxAssert((Boolean)((((((Int64)x_b) / x_num2)) == ((Int64)66))));
		this->CxAssert((Boolean)((((x_b / x_num3)) == 66)));
		this->CxAssert((Boolean)((((((Int64)x_b) / ((UInt64)x_num4))) == ((Int64)66))));
		this->CxAssert((Boolean)((((((Single)x_b) / x_num5)) == 66)));
		this->CxAssert((Boolean)((((((Double)x_b) / x_num6)) == 66)));
		this->CxAssert((Boolean)((((x_b % x_c)) == 0)));
		this->CxAssert((Boolean)((((x_b % x_b2)) == 0)));
		this->CxAssert((Boolean)((((x_b % x_b3)) == 0)));
		this->CxAssert((Boolean)((((x_b % x_b4)) == 0)));
		this->CxAssert((Boolean)((((x_b % x_num)) == 0)));
		this->CxAssert((Boolean)((((((Int64)x_b) % x_num2)) == ((Int64)0))));
		this->CxAssert((Boolean)((((x_b % x_num3)) == 0)));
		this->CxAssert((Boolean)((((((Int64)x_b) % ((UInt64)x_num4))) == ((Int64)0))));
		this->CxAssert((Boolean)(((DoubleValue::Modulus(((Single)x_b),x_num5)) == 0)));
		this->CxAssert((Boolean)(((DoubleValue::Modulus(((Double)x_b),x_num6)) == 0)));
		this->CxAssert((Boolean)((((x_b & x_c)) == 0)));
		this->CxAssert((Boolean)((((x_b & x_b2)) == 0)));
		this->CxAssert((Boolean)((((x_b & x_b3)) == 0)));
		this->CxAssert((Boolean)((((x_b & x_b4)) == 0)));
		this->CxAssert((Boolean)((((x_b & x_num)) == 0)));
		this->CxAssert((Boolean)((((((Int64)x_b) & x_num2)) == ((Int64)0))));
		this->CxAssert((Boolean)((((x_b & x_num3)) == 0)));
		this->CxAssert((Boolean)((((((Int64)x_b) & ((UInt64)x_num4))) == ((Int64)0))));
		this->CxAssert((Boolean)((((x_b | x_c)) == 67)));
		this->CxAssert((Boolean)((((x_b | x_b2)) == 67)));
		this->CxAssert((Boolean)((((x_b | x_b3)) == 67)));
		this->CxAssert((Boolean)((((x_b | x_b4)) == 67)));
		this->CxAssert((Boolean)((((x_b | x_num)) == 67)));
		this->CxAssert((Boolean)((((((Int64)x_b) | x_num2)) == ((Int64)67))));
		this->CxAssert((Boolean)((((x_b | x_num3)) == 67)));
		this->CxAssert((Boolean)((((((Int64)x_b) | ((UInt64)x_num4))) == ((Int64)67))));
		this->CxAssert((Boolean)((((x_b ^ x_c)) == 67)));
		this->CxAssert((Boolean)((((x_b ^ x_b2)) == 67)));
		this->CxAssert((Boolean)((((x_b ^ x_b3)) == 67)));
		this->CxAssert((Boolean)((((x_b ^ x_b4)) == 67)));
		this->CxAssert((Boolean)((((x_b ^ x_num)) == 67)));
		this->CxAssert((Boolean)((((((Int64)x_b) ^ x_num2)) == ((Int64)67))));
		this->CxAssert((Boolean)((((x_b ^ x_num3)) == 67)));
		this->CxAssert((Boolean)((((((Int64)x_b) ^ ((UInt64)x_num4))) == ((Int64)67))));
		this->CxAssert((Boolean)(((~x_b) == -67)));
		this->CxAssert((Boolean)(((x_c) < x_b)));
		this->CxAssert((Boolean)(((x_b2) < x_b)));
		this->CxAssert((Boolean)(((x_b3) < x_b)));
		this->CxAssert((Boolean)(((x_b4) < x_b)));
		this->CxAssert((Boolean)(((x_num) < x_b)));
		this->CxAssert((Boolean)(((x_num2) < ((Int64)x_b))));
		this->CxAssert((Boolean)(((x_num3) < x_b)));
		this->CxAssert((Boolean)(((((UInt64)x_num4)) < ((Int64)x_b))));
		this->CxAssert((Boolean)(((x_num5) < ((Single)x_b))));
		this->CxAssert((Boolean)(((x_num6) < ((Double)x_b))));
		this->CxAssert((Boolean)(((x_c) > x_b)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_b2) > x_b)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_b3) > x_b)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_b4) > x_b)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num) > x_b)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num2) > ((Int64)x_b))), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num3) > x_b)), (Boolean)(0));
		this->CxAssert((Boolean)(((((UInt64)x_num4)) > ((Int64)x_b))), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num5) > ((Single)x_b))), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num6) > ((Double)x_b))), (Boolean)(0));
		this->CxAssert((Boolean)(((x_b = ((SByte)(x_b + 1))) == 67)));
		this->CxAssert((Boolean)(((x_b = ((SByte)(x_b - 1))) == 66)));
		this->CxAssert((Boolean)(((x_b++) == 66)));
		this->CxAssert((Boolean)(((x_b--) == 67)));
		this->CxAssert((Boolean)((((x_b << 1)) == 132)));
		this->CxAssert((Boolean)((((x_b >> 1)) == 33)));
		this->CxAssert((Boolean)(((x_c) == x_b)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_b2) == x_b)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_b3) == x_b)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_b4) == x_b)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num) == x_b)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num2) == ((Int64)x_b))), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num3) == x_b)), (Boolean)(0));
		this->CxAssert((Boolean)(((((UInt64)x_num4)) == ((Int64)x_b))), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num5) == ((Single)x_b))), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num6) == ((Double)x_b))), (Boolean)(0));
		this->CxAssert((Boolean)(((x_c) != x_b)));
		this->CxAssert((Boolean)(((x_b2) != x_b)));
		this->CxAssert((Boolean)(((x_b3) != x_b)));
		this->CxAssert((Boolean)(((x_b4) != x_b)));
		this->CxAssert((Boolean)(((x_num) != x_b)));
		this->CxAssert((Boolean)(((x_num2) != ((Int64)x_b))));
		this->CxAssert((Boolean)(((x_num3) != x_b)));
		this->CxAssert((Boolean)(((((UInt64)x_num4)) != ((Int64)x_b))));
		this->CxAssert((Boolean)(((x_num5) != ((Single)x_b))));
		this->CxAssert((Boolean)(((x_num6) != ((Double)x_b))));
		this->CxAssert((Boolean)(((x_c) <= x_b)));
		this->CxAssert((Boolean)(((x_b2) <= x_b)));
		this->CxAssert((Boolean)(((x_b3) <= x_b)));
		this->CxAssert((Boolean)(((x_b4) <= x_b)));
		this->CxAssert((Boolean)(((x_num) <= x_b)));
		this->CxAssert((Boolean)(((x_num2) <= ((Int64)x_b))));
		this->CxAssert((Boolean)(((x_num3) <= x_b)));
		this->CxAssert((Boolean)(((((UInt64)x_num4)) <= ((Int64)x_b))));
		this->CxAssert((Boolean)(((x_num5) <= ((Single)x_b))));
		this->CxAssert((Boolean)(((x_num6) <= ((Double)x_b))));
		this->CxAssert((Boolean)(((x_c) >= x_b)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_b2) >= x_b)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_b3) >= x_b)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_b4) >= x_b)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num) >= x_b)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num2) >= ((Int64)x_b))), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num3) >= x_b)), (Boolean)(0));
		this->CxAssert((Boolean)(((((UInt64)x_num4)) >= ((Int64)x_b))), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num5) >= ((Single)x_b))), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num6) >= ((Double)x_b))), (Boolean)(0));
		this->CxAssert((Boolean)(((x_b = ((SByte)(x_b + ((SByte)x_c)))) == 67)));
		this->CxAssert((Boolean)(((x_b = ((SByte)(x_b - ((SByte)x_c)))) == 66)));
		this->CxAssert((Boolean)(((x_b = ((SByte)(x_b + ((SByte)x_num)))) == 67)));
		this->CxAssert((Boolean)(((x_b = ((SByte)(x_b - ((SByte)x_num)))) == 66)));
		this->CxAssert((Boolean)(((x_b = ((SByte)(x_b * ((SByte)x_c)))) == 66)));
		this->CxAssert((Boolean)(((x_b = ((SByte)(x_b / ((SByte)x_c)))) == 66)));
		this->CxAssert((Boolean)(((x_b = ((SByte)(x_b * ((SByte)x_num)))) == 66)));
		this->CxAssert((Boolean)(((x_b = ((SByte)(x_b / ((SByte)x_num)))) == 66)));
		this->CxAssert((Boolean)(((x_b = ((SByte)(x_b % ((SByte)x_c)))) == 0)));
		x_b = 66;
		this->CxAssert((Boolean)(((x_b = ((SByte)(x_b % ((SByte)x_num)))) == 0)));
		x_b = 66;
		this->CxAssert((Boolean)(((x_b = ((SByte)(x_b & ((SByte)x_c)))) == 0)));
		x_b = 66;
		this->CxAssert((Boolean)(((x_b = ((SByte)(x_b & ((SByte)x_num)))) == 0)));
		x_b = 66;
		this->CxAssert((Boolean)(((x_b = ((SByte)(x_b | ((SByte)x_c)))) == 67)));
		x_b = 66;
		this->CxAssert((Boolean)(((x_b = ((SByte)(x_b | ((SByte)x_num)))) == 67)));
		x_b = 66;
		this->CxAssert((Boolean)(((x_b = ((SByte)(x_b ^ ((SByte)x_c)))) == 67)));
		x_b = 66;
		this->CxAssert((Boolean)(((x_b = ((SByte)(x_b ^ ((SByte)x_num)))) == 67)));
		x_b = 66;
		this->CxAssert((Boolean)(((x_b = ((SByte)(x_b << x_b2))) == -124)));
		x_b = 66;
		this->CxAssert((Boolean)(((x_b = ((SByte)(x_b << x_b4))) == -124)));
		x_b = 66;
		this->CxAssert((Boolean)(((x_b = ((SByte)(x_b << x_c))) == -124)));
		x_b = 66;
		this->CxAssert((Boolean)(((x_b = ((SByte)(x_b << x_num))) == -124)));
		x_b = 66;
		this->CxAssert((Boolean)(((x_b = ((SByte)(x_b >> x_c))) == 33)));
		x_b = 66;
		this->CxAssert((Boolean)(((x_b = ((SByte)(x_b >> x_num))) == 33)));
		x_b = 66;
		SByte x_b5 = 0;
		this->CxAssert((Boolean)(((x_b5) == 0)));
		this->CxAssert((Boolean)(((x_b5) == 0)));
		this->CxAssert((Boolean)(((x_num) <= 2)));
		this->CxAssert((Boolean)(((x_num) >= -2)));
		return;
	}
	void SByteTest::SByteArrayTests()
	{
IL_0000:
		Array* x_array = new Array(SByteType,5);
		(*((SByte*)x_array->Address(0))) = 1;
		(*((SByte*)x_array->Address(1))) = 2;
		(*((SByte*)x_array->Address(2))) = 3;
		(*((SByte*)x_array->Address(3))) = 4;
		(*((SByte*)x_array->Address(4))) = 5;
		this->CxAssert((Boolean)(((x_array->get_Length()) == 5)));
		this->CxAssert((Boolean)((((*((SByte*)x_array->Address(3)))) == 4)));
		Array* x_array2 = new Array(SByteType,4);
		(*((SByte*)x_array2->Address(0))) = 1;
		(*((SByte*)x_array2->Address(1))) = 2;
		(*((SByte*)x_array2->Address(2))) = 3;
		(*((SByte*)x_array2->Address(3))) = 4;
		this->CxAssert((Boolean)((((*((SByte*)x_array2->Address(1)))) == 2)));
		Array* x_array3 = new Array(SByteType,2,4);
		(*((SByte*)x_array3->Address(0,0))) = 1;
		(*((SByte*)x_array3->Address(0,1))) = 2;
		(*((SByte*)x_array3->Address(0,2))) = 3;
		(*((SByte*)x_array3->Address(0,3))) = 4;
		(*((SByte*)x_array3->Address(1,0))) = 4;
		(*((SByte*)x_array3->Address(1,1))) = 5;
		(*((SByte*)x_array3->Address(1,2))) = 6;
		(*((SByte*)x_array3->Address(1,3))) = 7;
		this->CxAssert((Boolean)((((*((SByte*)x_array3->Address(0,2)))) == 3)));
		Array* x_array4 = new Array(SByteType,2,2,4);
		(*((SByte*)x_array4->Address(0,0,0))) = 1;
		(*((SByte*)x_array4->Address(0,0,1))) = 2;
		(*((SByte*)x_array4->Address(0,0,2))) = 3;
		(*((SByte*)x_array4->Address(0,0,3))) = 4;
		(*((SByte*)x_array4->Address(0,1,0))) = 5;
		(*((SByte*)x_array4->Address(0,1,1))) = 6;
		(*((SByte*)x_array4->Address(0,1,2))) = 7;
		(*((SByte*)x_array4->Address(0,1,3))) = 8;
		(*((SByte*)x_array4->Address(1,0,0))) = 9;
		(*((SByte*)x_array4->Address(1,0,1))) = 10;
		(*((SByte*)x_array4->Address(1,0,2))) = 11;
		(*((SByte*)x_array4->Address(1,0,3))) = 12;
		(*((SByte*)x_array4->Address(1,1,0))) = 13;
		(*((SByte*)x_array4->Address(1,1,1))) = 14;
		(*((SByte*)x_array4->Address(1,1,2))) = 15;
		(*((SByte*)x_array4->Address(1,1,3))) = 16;
		this->CxAssert((Boolean)((((*((SByte*)x_array4->Address(0,0,3)))) == 4)));
		(*((SByte*)x_array4->Address(0,0,3))) = 6;
		this->CxAssert((Boolean)((((*((SByte*)x_array4->Address(0,0,3)))) == 6)));
		x_array4->SetValue((new SByteValue(4)), (Int32)(0), (Int32)(0), (Int32)(3));
		this->CxAssert((Boolean)((((*((SByte*)x_array4->Address(0,0,3)))) == 4)));
		return;
	}
	void SByteTest::SByteMiscTests()
	{
IL_0000:
		SByte x_b = -1;
		SByte x_val = 1;
		this->CxAssert((Boolean)(((Math::Abs((SByte)(x_b))) == 1)));
		this->CxAssert((Boolean)(((Math::Max((SByte)(x_b), (SByte)(x_val))) == 1)));
		this->CxAssert((Boolean)(((Math::Min((SByte)(x_b), (SByte)(x_val))) == -1)));
		this->CxAssert((Boolean)(((Math::Sign((SByte)(x_b))) < 0)));
		StringBuilder* x_stringBuilder = (new StringBuilder());
		x_stringBuilder->Append((SByte)(x_b));
		this->CxAssert((Boolean)(String::Equals(x_stringBuilder->ToString(), (new String(L"-1")))));
		x_stringBuilder->Insert((Int32)(2), (SByte)(x_b));
		this->CxAssert((Boolean)(String::Equals(x_stringBuilder->ToString(), (new String(L"-1-1")))));
		return;
	}
	void SByteTest::CxAssert(Boolean x_x)
	{
IL_0000:
		if (((x_x) == 0))
		{
			this->x_caBlock->TestFailed((new String(L"SByte TestFailed")));
		}

		return;
	}
	void SByteTest::CxAssert(Boolean x_x,Boolean x_y)
	{
IL_0000:
		if (((x_x) != x_y))
		{
			this->x_caBlock->TestFailed((new String(L"SByte TestFailed")));
		}

		return;
	}
	SingleTest::SingleTest(CABlock* x_caBlock)
	{
IL_0000:
		
		this->x_caBlock = x_caBlock;
		return;
	}
	void SingleTest::Test()
	{
IL_0000:
		this->x_caBlock->Send((new String(L"Doing SingleTest")));
		this->x_caBlock->Send((new String(L"\tDoing DoSingleMethodsTest")));
		this->DoSingleMethodsTest();
		this->x_caBlock->Send((new String(L"\tDoing DoSingleMath")));
		this->DoSingleMath();
		this->x_caBlock->Send((new String(L"\tDoing SingleOperators")));
		this->SingleOperators();
		this->x_caBlock->Send((new String(L"\tDoing SingleNanTest")));
		this->SingleNanTest();
		this->x_caBlock->Send((new String(L"\tDoing SingleArrayTest")));
		this->SingleArrayTest();
		this->x_caBlock->Send((new String(L"\tDoing SingleMiscTests")));
		this->SingleMiscTests();
		return;
	}
	void SingleTest::DoSingleMethodsTest()
	{
IL_0000:
		Single x_num = 3.15899991989136F;
		this->CxAssert((Boolean)(((SingleValue(x_num).CompareTo((Single)(3.15899991989136F))) == 0)));
		this->CxAssert((Boolean)(((SingleValue(x_num).CompareTo((new SingleValue(3.15899991989136F)))) == 0)));
		this->CxAssert((Boolean)(SingleValue(x_num).Equals((Single)(3.15899991989136F))));
		this->CxAssert((Double)(((Double)SingleValue::Parse((new String(L"3.159"))))), (Double)(3.15899991989136));
		this->CxAssert((Boolean)(String::Equals(SingleValue(x_num).ToString(), (new String(L"3.159")))));
		this->CxAssert((Double)(((Double)SingleValue::Parse(SingleValue(x_num).ToString()))), (Double)(((Double)x_num)));
		x_num = 10000001;
		this->CxAssert((Boolean)(((x_num) > 10000000)));
		x_num = -10000000;
		this->CxAssert((Boolean)(((x_num) <= -10000000)));
		x_num = 10000;
		this->CxAssert((Boolean)(((((Int64)x_num)) == ((Int64)10000))));
		this->CxAssert((Boolean)(((((Int32)x_num)) == 10000)));
		this->CxAssert((Boolean)(((((UInt32)x_num)) == 10000)));
		Object* x_obj = (new SingleValue(x_num));
		this->CxAssert((Boolean)(((((Double)x_obj->get_AsSingle())) == 10000)));
		x_num = SingleValue::Epsilon;
		this->CxAssert((Boolean)(((x_num) == SingleValue::Epsilon)));
		x_num = SingleValue::MaxValue;
		this->CxAssert((Boolean)(((x_num) == SingleValue::MaxValue)));
		x_num = SingleValue::MinValue;
		this->CxAssert((Boolean)(((x_num) == SingleValue::MinValue)));
		x_obj = (new SingleValue(5));
		this->CxAssert((Boolean)(x_obj->Equals((new SingleValue(5)))));
		this->CxAssert((Boolean)(String::Equals(x_obj->ToString(), (new String(L"5")))));
		return;
	}
	void SingleTest::DoSingleMath()
	{
IL_0000:
		Single x_num = 355;
		Single x_num2 = 113;
		Single x_num3 = (x_num / x_num2);
		this->CxAssert((Double)(((Double)x_num3)), (Double)(3.14159));
		this->CxAssert((Double)(((Double)(x_num3 * x_num2))), (Double)(355));
		this->CxAssert((Double)(((Double)(x_num + x_num2))), (Double)(468));
		this->CxAssert((Double)(((Double)(x_num - x_num2))), (Double)(242));
		x_num = 1;
		x_num2 = (x_num + SingleValue::Epsilon);
		this->CxAssert((Boolean)(((((Double)x_num2)) == 1)));
		return;
	}
	void SingleTest::SingleOperators()
	{
IL_0000:
		Single x_num = 66;
		Char x_c = 1;
		Int32 x_num2 = 1;
		UInt32 x_num3 = 1;
		Int64 x_num4 = ((Int64)1);
		Double x_num5 = 1;
		this->CxAssert((Boolean)(((x_num) == 66)));
		this->CxAssert((Boolean)((((x_num + ((Single)x_c))) == 67)));
		this->CxAssert((Boolean)((((x_num + ((Single)x_num2))) == 67)));
		this->CxAssert((Boolean)((((x_num + ((Single)x_num3))) == 67)));
		this->CxAssert((Boolean)((((x_num + ((Single)x_num4))) == 67)));
		this->CxAssert((Boolean)((((((Double)x_num) + x_num5)) == 67)));
		this->CxAssert((Boolean)((((x_num - ((Single)x_c))) == 65)));
		this->CxAssert((Boolean)((((x_num - ((Single)x_num2))) == 65)));
		this->CxAssert((Boolean)((((x_num - ((Single)x_num3))) == 65)));
		this->CxAssert((Boolean)((((x_num - ((Single)x_num4))) == 65)));
		this->CxAssert((Boolean)((((((Double)x_num) - x_num5)) == 65)));
		this->CxAssert((Boolean)((((x_num * ((Single)x_c))) == 66)));
		this->CxAssert((Boolean)((((x_num * ((Single)x_num2))) == 66)));
		this->CxAssert((Boolean)((((x_num * ((Single)x_num3))) == 66)));
		this->CxAssert((Boolean)((((x_num * ((Single)x_num4))) == 66)));
		this->CxAssert((Boolean)((((((Double)x_num) * x_num5)) == 66)));
		this->CxAssert((Boolean)((((x_num / ((Single)x_c))) == 66)));
		this->CxAssert((Boolean)((((x_num / ((Single)x_num2))) == 66)));
		this->CxAssert((Boolean)((((x_num / ((Single)x_num3))) == 66)));
		this->CxAssert((Boolean)((((x_num / ((Single)x_num4))) == 66)));
		this->CxAssert((Boolean)((((((Double)x_num) / x_num5)) == 66)));
		this->CxAssert((Boolean)(((DoubleValue::Modulus(x_num,((Single)x_c))) == 0)));
		this->CxAssert((Boolean)(((DoubleValue::Modulus(x_num,((Single)x_num2))) == 0)));
		this->CxAssert((Boolean)(((DoubleValue::Modulus(x_num,((Single)x_num3))) == 0)));
		this->CxAssert((Boolean)(((DoubleValue::Modulus(x_num,((Single)x_num4))) == 0)));
		this->CxAssert((Boolean)(((DoubleValue::Modulus(((Double)x_num),x_num5)) == 0)));
		this->CxAssert((Boolean)(((((Single)x_c)) < x_num)));
		this->CxAssert((Boolean)(((((Single)x_num2)) < x_num)));
		this->CxAssert((Boolean)(((((Single)x_num3)) < x_num)));
		this->CxAssert((Boolean)(((((Single)x_num4)) < x_num)));
		this->CxAssert((Boolean)(((x_num5) < ((Double)x_num))));
		this->CxAssert((Boolean)(((((Single)x_c)) > x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((((Single)x_num2)) > x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((((Single)x_num3)) > x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((((Single)x_num4)) > x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num5) > ((Double)x_num))), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num = (x_num + 1)) == 67)));
		this->CxAssert((Boolean)(((x_num = (x_num - 1)) == 66)));
		this->CxAssert((Boolean)(((x_num++) == 66)));
		this->CxAssert((Boolean)(((x_num--) == 67)));
		this->CxAssert((Boolean)(((((Single)x_c)) == x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((((Single)x_num2)) == x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((((Single)x_num3)) == x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((((Single)x_num4)) == x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num5) == ((Double)x_num))), (Boolean)(0));
		this->CxAssert((Boolean)(((((Single)x_c)) != x_num)));
		this->CxAssert((Boolean)(((((Single)x_num2)) != x_num)));
		this->CxAssert((Boolean)(((((Single)x_num3)) != x_num)));
		this->CxAssert((Boolean)(((((Single)x_num4)) != x_num)));
		this->CxAssert((Boolean)(((x_num5) != ((Double)x_num))));
		this->CxAssert((Boolean)(((((Single)x_c)) <= x_num)));
		this->CxAssert((Boolean)(((((Single)x_num2)) <= x_num)));
		this->CxAssert((Boolean)(((((Single)x_num3)) <= x_num)));
		this->CxAssert((Boolean)(((((Single)x_num4)) <= x_num)));
		this->CxAssert((Boolean)(((x_num5) <= ((Double)x_num))));
		this->CxAssert((Boolean)(((((Single)x_c)) >= x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((((Single)x_num2)) >= x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((((Single)x_num3)) >= x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((((Single)x_num4)) >= x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num5) >= ((Double)x_num))), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num = (x_num + ((Single)x_c))) == 67)));
		this->CxAssert((Boolean)(((x_num = (x_num - ((Single)x_c))) == 66)));
		this->CxAssert((Boolean)(((x_num = (x_num + ((Single)x_num2))) == 67)));
		this->CxAssert((Boolean)(((x_num = (x_num - ((Single)x_num2))) == 66)));
		this->CxAssert((Boolean)(((x_num = (x_num + ((Single)x_num3))) == 67)));
		this->CxAssert((Boolean)(((x_num = (x_num - ((Single)x_num3))) == 66)));
		this->CxAssert((Boolean)(((x_num = (x_num + ((Single)x_num4))) == 67)));
		this->CxAssert((Boolean)(((x_num = (x_num - ((Single)x_num4))) == 66)));
		this->CxAssert((Boolean)(((x_num = (x_num * ((Single)x_c))) == 66)));
		this->CxAssert((Boolean)(((x_num = (x_num / ((Single)x_c))) == 66)));
		this->CxAssert((Boolean)(((x_num = (x_num * ((Single)x_num2))) == 66)));
		this->CxAssert((Boolean)(((x_num = (x_num / ((Single)x_num2))) == 66)));
		this->CxAssert((Boolean)(((x_num = (x_num * ((Single)x_num3))) == 66)));
		this->CxAssert((Boolean)(((x_num = (x_num / ((Single)x_num3))) == 66)));
		this->CxAssert((Boolean)(((x_num = (x_num * ((Single)x_num4))) == 66)));
		this->CxAssert((Boolean)(((x_num = (x_num / ((Single)x_num4))) == 66)));
		this->CxAssert((Boolean)(((x_num = DoubleValue::Modulus(x_num,((Single)x_c))) == 0)));
		x_num = 66;
		this->CxAssert((Boolean)(((x_num = DoubleValue::Modulus(x_num,((Single)x_num2))) == 0)));
		x_num = 5;
		this->CxAssert((Double)(DoubleValue::Modulus(((Double)x_num),2.2)), (Double)(0.6));
		return;
	}
	void SingleTest::SingleNanTest()
	{
IL_0000:
		Single x_num = DoubleValue::NaN;
		Single x_num2 = 1;
		this->CxAssert((Boolean)(SingleValue::IsNaN((Single)(x_num))));
		this->CxAssert((Boolean)(SingleValue::IsInfinity((Single)(DoubleValue::PositiveInfinity))));
		this->CxAssert((Boolean)(SingleValue::IsNegativeInfinity((Single)(DoubleValue::NegativeInfinity))));
		this->CxAssert((Boolean)(SingleValue::IsPositiveInfinity((Single)(DoubleValue::PositiveInfinity))));
		this->CxAssert((Boolean)(SingleValue::IsNaN((Single)((x_num * x_num2)))));
		this->CxAssert((Boolean)(SingleValue::IsNaN((Single)((x_num / x_num2)))));
		this->CxAssert((Boolean)(SingleValue::IsNaN((Single)((x_num + x_num2)))));
		this->CxAssert((Boolean)(SingleValue::IsNaN((Single)((x_num - x_num2)))));
		this->CxAssert((Boolean)(SingleValue::IsNaN((Single)(DoubleValue::Modulus(x_num,x_num2)))));
		this->CxAssert((Boolean)(((x_num) < x_num2)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num) > x_num2)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num) <= x_num2)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num) >= x_num2)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num) == x_num2)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num) == x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num2) < x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num2) > x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num2) <= x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num2) >= x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num) != x_num2)));
		this->CxAssert((Boolean)(((x_num) != x_num)));
		x_num = DoubleValue::NaN;
		x_num2 = DoubleValue::NaN;
		if (((x_num) == x_num2))
		{
			this->SingleTestFailed();
		}
		else
		{
			this->CxAssert((Boolean)(1));
		}

		if (((x_num) == x_num))
		{
			this->SingleTestFailed();
		}
		else
		{
			this->CxAssert((Boolean)(1));
		}

		if (((x_num) != x_num2))
		{
			this->CxAssert((Boolean)(1));
		}
		else
		{
			this->SingleTestFailed();
		}

		if (((x_num) != x_num))
		{
			this->CxAssert((Boolean)(1));
		}
		else
		{
			this->SingleTestFailed();
		}

		if (((x_num) > x_num2))
		{
			this->SingleTestFailed();
		}
		else
		{
			this->CxAssert((Boolean)(1));
		}

		if (((x_num) >= x_num2))
		{
			this->SingleTestFailed();
		}
		else
		{
			this->CxAssert((Boolean)(1));
		}

		if (((x_num) < x_num2))
		{
			this->SingleTestFailed();
		}
		else
		{
			this->CxAssert((Boolean)(1));
		}

		if (((x_num) <= x_num2))
		{
			this->SingleTestFailed();
		}
		else
		{
			this->CxAssert((Boolean)(1));
		}

		if (((x_num) == 0))
		{
			this->SingleTestFailed();
		}
		else
		{
			this->CxAssert((Boolean)(1));
		}

		this->CxAssert((Boolean)(SingleValue((DoubleValue::NaN)).Equals((Single)(DoubleValue::NaN))));
		return;
	}
	void SingleTest::SingleArrayTest()
	{
IL_0000:
		Array* x_array = new Array(SingleType,4);
		(*((Single*)x_array->Address(0))) = 1;
		(*((Single*)x_array->Address(1))) = 2;
		(*((Single*)x_array->Address(2))) = 3;
		(*((Single*)x_array->Address(3))) = 4;
		this->CxAssert((Boolean)((((*((Single*)x_array->Address(1)))) == 2)));
		Array* x_array2 = new Array(SingleType,2,4);
		(*((Single*)x_array2->Address(0,0))) = 1;
		(*((Single*)x_array2->Address(0,1))) = 2;
		(*((Single*)x_array2->Address(0,2))) = 3;
		(*((Single*)x_array2->Address(0,3))) = 4;
		(*((Single*)x_array2->Address(1,0))) = 4;
		(*((Single*)x_array2->Address(1,1))) = 5;
		(*((Single*)x_array2->Address(1,2))) = 6;
		(*((Single*)x_array2->Address(1,3))) = 7;
		this->CxAssert((Boolean)((((*((Single*)x_array2->Address(0,2)))) == 3)));
		Array* x_array3 = new Array(SingleType,2,2,4);
		(*((Single*)x_array3->Address(0,0,0))) = 1;
		(*((Single*)x_array3->Address(0,0,1))) = 2;
		(*((Single*)x_array3->Address(0,0,2))) = 3;
		(*((Single*)x_array3->Address(0,0,3))) = 4;
		(*((Single*)x_array3->Address(0,1,0))) = 5;
		(*((Single*)x_array3->Address(0,1,1))) = 6;
		(*((Single*)x_array3->Address(0,1,2))) = 7;
		(*((Single*)x_array3->Address(0,1,3))) = 8;
		(*((Single*)x_array3->Address(1,0,0))) = 9;
		(*((Single*)x_array3->Address(1,0,1))) = 10;
		(*((Single*)x_array3->Address(1,0,2))) = 11;
		(*((Single*)x_array3->Address(1,0,3))) = 12;
		(*((Single*)x_array3->Address(1,1,0))) = 13;
		(*((Single*)x_array3->Address(1,1,1))) = 14;
		(*((Single*)x_array3->Address(1,1,2))) = 15;
		(*((Single*)x_array3->Address(1,1,3))) = 16;
		this->CxAssert((Boolean)((((*((Single*)x_array3->Address(0,0,3)))) == 4)));
		(*((Single*)x_array3->Address(0,0,3))) = 22;
		this->CxAssert((Boolean)((((*((Single*)x_array3->Address(0,0,3)))) == 22)));
		(*((Single*)x_array2->Address(0,2))) = DoubleValue::NaN;
		this->CxAssert((Boolean)(SingleValue::IsNaN((Single)((*((Single*)x_array2->Address(0,2)))))));
		x_array3->SetValue((new SingleValue(4)), (Int32)(0), (Int32)(0), (Int32)(3));
		this->CxAssert((Boolean)((((*((Single*)x_array3->Address(0,0,3)))) == 4)));
		return;
	}
	void SingleTest::SingleMiscTests()
	{
IL_0000:
		Single x_num = -1;
		Single x_val = 1;
		this->CxAssert((Boolean)(((Math::Abs((Single)(x_num))) == 1)));
		this->CxAssert((Boolean)(((Math::Max((Single)(x_num), (Single)(x_val))) == 1)));
		this->CxAssert((Boolean)(((Math::Min((Single)(x_num), (Single)(x_val))) == -1)));
		this->CxAssert((Boolean)(((Math::Sign((Single)(x_num))) < 0)));
		StringBuilder* x_stringBuilder = (new StringBuilder());
		x_stringBuilder->Append((Single)(x_num));
		this->CxAssert((Boolean)(String::Equals(x_stringBuilder->ToString(), (new String(L"-1")))));
		x_stringBuilder->Insert((Int32)(2), (Single)(x_num));
		this->CxAssert((Boolean)(String::Equals(x_stringBuilder->ToString(), (new String(L"-1-1")))));
		return;
	}
	void SingleTest::SingleCompare(Double x_n1,Double x_n2,Double x_resolution)
	{
IL_0000:
		Double x_num = Math::Abs((Double)((x_n1 - x_n2)));
		if (((x_num) > x_resolution))
		{
			this->SingleTestFailed();
		}

		return;
	}
	void SingleTest::CxAssert(Double x_x,Double x_y)
	{
IL_0000:
		this->SingleCompare((Double)(x_x), (Double)(x_y), (Double)(1E-05));
		return;
	}
	void SingleTest::CxAssert(Boolean x_x)
	{
IL_0000:
		if (((x_x) == 0))
		{
			this->SingleTestFailed();
		}

		return;
	}
	void SingleTest::CxAssert(Boolean x_x,Boolean x_y)
	{
IL_0000:
		if (((x_x) != x_y))
		{
			this->SingleTestFailed();
		}

		return;
	}
	void SingleTest::SingleTestFailed()
	{
IL_0000:
		this->x_caBlock->TestFailed((new String(L"Single TestFailed")));
		return;
	}
	StringBuilderTest::StringBuilderTest(CABlock* x_caBlock)
	{
IL_0000:
		this->x_sb = (new StringBuilder());
		
		this->x_caBlock = x_caBlock;
		return;
	}
	void StringBuilderTest::Test()
	{
IL_0000:
		this->x_caBlock->Send((new String(L"Doing StringBuilderTest")));
		this->x_caBlock->Send((new String(L"\tDoing DoSBConstructTest")));
		this->DoSBConstructTest();
		this->x_caBlock->Send((new String(L"\tDoing DoSBPropertyTest")));
		this->DoSBPropertyTest();
		this->x_caBlock->Send((new String(L"\tDoing DoSBAppendTest")));
		this->DoSBAppendTest();
		this->x_caBlock->Send((new String(L"\tDoing DoSBMiscTest")));
		this->DoSBMiscTest();
		this->x_caBlock->Send((new String(L"\tDoing DoSBInsertTest")));
		this->DoSBInsertTest();
		this->x_caBlock->Send((new String(L"\tDoing DoSBReplaceTest")));
		this->DoSBReplaceTest();
		return;
	}
	void StringBuilderTest::DoSBConstructTest()
	{
IL_0000:
		this->CxAssert((Boolean)(((this->x_sb->get_Length()) == 0)));
		this->x_sb = (new StringBuilder((Int32)(100)));
		this->CxAssert((Boolean)(((this->x_sb->get_Capacity()) == 100)));
		this->x_sb = (new StringBuilder((new String(L"Test"))));
		this->CxAssert((Boolean)(String::Equals(this->x_sb->ToString(), (new String(L"Test")))));
		this->x_sb = (new StringBuilder((Int32)(20), (Int32)(25)));
		this->CxAssert((Boolean)((((this->x_sb->get_Capacity()) == 20) && ((this->x_sb->get_MaxCapacity()) == 25))));
		this->x_sb = (new StringBuilder((new String(L"Test")), (Int32)(20)));
		this->CxAssert((Boolean)((String::Equals(this->x_sb->ToString(), (new String(L"Test"))) && ((this->x_sb->get_Capacity()) == 20))));
		this->x_sb = (new StringBuilder((new String(L"test1234")), (Int32)(1), (Int32)(4), (Int32)(20)));
		this->CxAssert((Boolean)((String::Equals(this->x_sb->ToString(), (new String(L"est1"))) && ((this->x_sb->get_Capacity()) == 20))));
		String* x_a = (new StringBuilder((new String(L"Test"))))->ToString();
		this->CxAssert((Boolean)(String::Equals(x_a, (new String(L"Test")))));
		String* x_b = (new String(L"AB\a\b\t\r\v\f\n\"'\u00c2"));
		Array* x_value = new Array(CharType,12);
		(*((Char*)x_value->Address(0))) = 65;
		(*((Char*)x_value->Address(1))) = 66;
		(*((Char*)x_value->Address(2))) = 7;
		(*((Char*)x_value->Address(3))) = 8;
		(*((Char*)x_value->Address(4))) = 9;
		(*((Char*)x_value->Address(5))) = 13;
		(*((Char*)x_value->Address(6))) = 11;
		(*((Char*)x_value->Address(7))) = 12;
		(*((Char*)x_value->Address(8))) = 10;
		(*((Char*)x_value->Address(9))) = 34;
		(*((Char*)x_value->Address(10))) = 39;
		(*((Char*)x_value->Address(11))) = 194;
		this->x_sb = (new StringBuilder());
		this->x_sb->Append(x_value);
		String* x_text = this->x_sb->ToString();
		this->CxAssert((Boolean)(String::Equals(this->x_sb->ToString(), x_b)));
		return;
	}
	void StringBuilderTest::DoSBPropertyTest()
	{
IL_0000:
		this->x_sb = (new StringBuilder((new String(L"Testing123")), (Int32)(0), (Int32)(10), (Int32)(20)));
		this->CxAssert((Boolean)((((this->x_sb->get_Capacity()) == 20) && ((this->x_sb->get_MaxCapacity()) == Int32Value::MaxValue))));
		this->CxAssert((Boolean)(((this->x_sb->get_Chars((Int32)(7))) == 49)));
		this->CxAssert((Boolean)(((this->x_sb->get_Length()) == 10)));
		this->x_sb->set_Length((Int32)(7));
		this->CxAssert((Boolean)(((this->x_sb->get_Length()) == 7)));
		this->x_sb->set_Capacity((Int32)(22));
		this->CxAssert((Boolean)(((this->x_sb->get_Capacity()) == 22)));
		this->x_sb->set_Chars((Int32)(0), (Char)(116));
		this->CxAssert((Boolean)(String::Equals(this->x_sb->ToString(), (new String(L"testing")))));
		return;
	}
	void StringBuilderTest::DoSBAppendTest()
	{
IL_0000:
		this->x_sb->set_Length((Int32)(0));
		this->x_sb->Append((Boolean)(1));
		this->CxAssert((Boolean)(String::Equals(this->x_sb->ToString(), (new String(L"True")))));
		this->CxAssert((Boolean)(String::Equals(this->x_sb->Append((Char)(65))->ToString(), (new String(L"TrueA")))));
		Array* x_value = new Array(CharType,4);
		(*((Char*)x_value->Address(0))) = 48;
		(*((Char*)x_value->Address(1))) = 49;
		(*((Char*)x_value->Address(2))) = 50;
		(*((Char*)x_value->Address(3))) = 51;
		this->CxAssert((Boolean)(String::Equals(this->x_sb->Append(x_value)->ToString(), (new String(L"TrueA0123")))));
		this->x_sb->set_Length((Int32)(0));
		Double x_value2 = 3.14159;
		this->CxAssert((Boolean)(String::Equals(this->x_sb->Append((Double)(x_value2))->ToString(), (new String(L"3.14159")))));
		this->x_sb->set_Length((Int32)(0));
		Int32 x_value3 = 666;
		this->CxAssert((Boolean)(String::Equals(this->x_sb->Append((Int32)(x_value3))->ToString(), (new String(L"666")))));
		this->x_sb->set_Length((Int32)(0));
		Int64 x_value4 = ((Int64)666666666);
		this->CxAssert((Boolean)(String::Equals(this->x_sb->Append((Int64)(x_value4))->ToString(), (new String(L"666666666")))));
		this->x_sb->set_Length((Int32)(0));
		Object* x_value5 = (new Int32Value(1));
		this->CxAssert((Boolean)(String::Equals(this->x_sb->Append(x_value5)->ToString(), (new String(L"1")))));
		this->x_sb->set_Length((Int32)(0));
		this->CxAssert((Boolean)(String::Equals(this->x_sb->Append((new String(L"fred")))->ToString(), (new String(L"fred")))));
		UInt32 x_value6 = 777;
		this->x_sb->set_Length((Int32)(0));
		this->CxAssert((Boolean)(String::Equals(this->x_sb->Append((UInt32)(x_value6))->ToString(), (new String(L"777")))));
		this->x_sb->set_Length((Int32)(0));
		this->CxAssert((Boolean)(String::Equals(this->x_sb->Append((Char)(65), (Int32)(4))->ToString(), (new String(L"AAAA")))));
		this->x_sb->set_Length((Int32)(0));
		this->CxAssert((Boolean)(String::Equals(this->x_sb->Append(x_value, (Int32)(1), (Int32)(3))->ToString(), (new String(L"123")))));
		this->x_sb->set_Length((Int32)(0));
		this->CxAssert((Boolean)(String::Equals(this->x_sb->Append((new String(L"3210")), (Int32)(1), (Int32)(3))->ToString(), (new String(L"210")))));
		this->x_sb->set_Length((Int32)(0));
		Object* x_value7 = (new String(L"Test string as Object"));
		this->x_sb->set_Length((Int32)(0));
		this->CxAssert((Boolean)(String::Equals(this->x_sb->Append(x_value7)->ToString(), (new String(L"Test string as Object")))));
		TestAbstract* x_value8 = (new TestAbstract());
		this->x_sb->set_Length((Int32)(0));
		this->CxAssert((Boolean)(String::Equals(this->x_sb->Append(x_value8)->ToString(), (new String(L"TestAbstract")))));
		return;
	}
	void StringBuilderTest::DoSBMiscTest()
	{
IL_0000:
		this->x_sb->set_Length((Int32)(0));
		this->x_sb->set_Capacity((Int32)(10));
		this->x_sb->EnsureCapacity((Int32)(30));
		this->CxAssert((Boolean)(((this->x_sb->get_Capacity()) >= 30)));
		this->x_sb->Append((new String(L"Test")));
		StringBuilder* x_stringBuilder = (new StringBuilder((new String(L"Test"))));
		x_stringBuilder->set_Capacity((Int32)(10));
		x_stringBuilder->EnsureCapacity((Int32)(30));
		this->CxAssert((Boolean)(this->x_sb->Equals(x_stringBuilder)));
		this->x_sb->set_Length((Int32)(0));
		this->x_sb->Append((new String(L"1234567890")));
		this->x_sb->Remove((Int32)(1), (Int32)(4));
		this->CxAssert((Boolean)(String::Equals(this->x_sb->ToString(), (new String(L"167890")))));
		this->x_sb->set_Length((Int32)(0));
		this->x_sb->Append((new String(L"1234567890")));
		this->CxAssert((Boolean)(String::Equals(this->x_sb->ToString((Int32)(1), (Int32)(8)), (new String(L"23456789")))));
		return;
	}
	void StringBuilderTest::DoSBInsertTest()
	{
IL_0000:
		String* x_value = (new String(L"{}"));
		this->x_sb->set_Length((Int32)(0));
		this->x_sb->Append(x_value);
		this->x_sb->Insert((Int32)(1), (Boolean)(1));
		this->CxAssert((Boolean)(String::Equals(this->x_sb->ToString(), (new String(L"{True}")))));
		this->CxAssert((Boolean)(String::Equals(this->x_sb->Insert((Int32)(5), (Char)(65))->ToString(), (new String(L"{TrueA}")))));
		Array* x_value2 = new Array(CharType,4);
		(*((Char*)x_value2->Address(0))) = 48;
		(*((Char*)x_value2->Address(1))) = 49;
		(*((Char*)x_value2->Address(2))) = 50;
		(*((Char*)x_value2->Address(3))) = 51;
		this->CxAssert((Boolean)(String::Equals(this->x_sb->Insert((Int32)(6), x_value2)->ToString(), (new String(L"{TrueA0123}")))));
		this->x_sb->set_Length((Int32)(0));
		this->x_sb->Append(x_value);
		Double x_value3 = 3.14159;
		this->CxAssert((Boolean)(String::Equals(this->x_sb->Insert((Int32)(1), (Double)(x_value3))->ToString(), (new String(L"{3.14159}")))));
		this->x_sb->set_Length((Int32)(0));
		this->x_sb->Append(x_value);
		Int32 x_value4 = 666;
		this->CxAssert((Boolean)(String::Equals(this->x_sb->Insert((Int32)(1), (Int32)(x_value4))->ToString(), (new String(L"{666}")))));
		this->x_sb->set_Length((Int32)(0));
		this->x_sb->Append(x_value);
		Int64 x_value5 = ((Int64)666666666);
		this->CxAssert((Boolean)(String::Equals(this->x_sb->Insert((Int32)(1), (Int64)(x_value5))->ToString(), (new String(L"{666666666}")))));
		this->x_sb->set_Length((Int32)(0));
		this->x_sb->Append(x_value);
		Object* x_value6 = (new Int32Value(1));
		this->CxAssert((Boolean)(String::Equals(this->x_sb->Insert((Int32)(1), x_value6)->ToString(), (new String(L"{1}")))));
		this->x_sb->set_Length((Int32)(0));
		this->x_sb->Append(x_value);
		this->CxAssert((Boolean)(String::Equals(this->x_sb->Insert((Int32)(1), (new String(L"fred")))->ToString(), (new String(L"{fred}")))));
		UInt32 x_value7 = 777;
		this->x_sb->set_Length((Int32)(0));
		this->x_sb->Append(x_value);
		this->CxAssert((Boolean)(String::Equals(this->x_sb->Insert((Int32)(1), (UInt32)(x_value7))->ToString(), (new String(L"{777}")))));
		this->x_sb->set_Length((Int32)(0));
		this->x_sb->Append(x_value);
		this->CxAssert((Boolean)(String::Equals(this->x_sb->Insert((Int32)(1), (new String(L"A")), (Int32)(4))->ToString(), (new String(L"{AAAA}")))));
		this->x_sb->set_Length((Int32)(0));
		this->x_sb->Append(x_value);
		this->CxAssert((Boolean)(String::Equals(this->x_sb->Insert((Int32)(1), x_value2, (Int32)(1), (Int32)(3))->ToString(), (new String(L"{123}")))));
		return;
	}
	void StringBuilderTest::DoSBReplaceTest()
	{
IL_0000:
		this->x_sb->set_Length((Int32)(0));
		this->x_sb->Append((new String(L"aaaaaaa")));
		this->CxAssert((Boolean)(String::Equals(this->x_sb->Replace((Char)(97), (Char)(65))->ToString(), (new String(L"AAAAAAA")))));
		this->CxAssert((Boolean)(String::Equals(this->x_sb->Replace((new String(L"AA")), (new String(L"BBB")))->ToString(), (new String(L"BBBBBBBBBA")))));
		this->CxAssert((Boolean)(String::Equals(this->x_sb->Replace((Char)(66), (Char)(67), (Int32)(1), (Int32)(7))->ToString(), (new String(L"BCCCCCCCBA")))));
		this->CxAssert((Boolean)(String::Equals(this->x_sb->Replace((new String(L"CCC")), (new String(L"DDD")), (Int32)(2), (Int32)(5))->ToString(), (new String(L"BCDDDCCCBA")))));
		this->x_sb->set_Length((Int32)(0));
		this->x_sb->Append((new String(L"aaaaaaa")));
		String* x_a = this->x_sb->Replace((new String(L"aa")), (new String(L"BBB")), (Int32)(1), (Int32)(5))->ToString();
		this->CxAssert((Boolean)(String::Equals(x_a, (new String(L"aBBBBBBaa")))));
		return;
	}
	void StringBuilderTest::CxAssert(Boolean x_x)
	{
IL_0000:
		if (((x_x) == 0))
		{
			this->x_caBlock->TestFailed((new String(L"StringBuilder TestFailed")));
		}

		return;
	}
	void StringBuilderTest::CxAssert(Boolean x_x,Boolean x_y)
	{
IL_0000:
		if (((x_x) != x_y))
		{
			this->x_caBlock->TestFailed((new String(L"StringBuilder TestFailed")));
		}

		return;
	}
	StringTest::StringTest(CABlock* x_caBlock)
	{
IL_0000:
		
		this->x_caBlock = x_caBlock;
		return;
	}
	void StringTest::Test()
	{
IL_0000:
		this->x_caBlock->Send((new String(L"Doing StringTest")));
		this->x_caBlock->Send((new String(L"\tDoing DoIndexTest")));
		this->DoIndexTest();
		this->x_caBlock->Send((new String(L"\tDoing DoMiscTest")));
		this->DoMiscTest();
		this->x_caBlock->Send((new String(L"\tDoing DoEqualsTest")));
		this->DoEqualsTest();
		this->x_caBlock->Send((new String(L"\tDoing DoParsingTest")));
		this->DoParsingTest();
		this->x_caBlock->Send((new String(L"\tDoing DoConcatTest")));
		this->DoConcatTest();
		return;
	}
	void StringTest::DoIndexTest()
	{
IL_0000:
		String* x_text = (new String(L"12345"));
		this->CxAssert((Boolean)(((x_text->get_Length()) == 5)));
		this->CxAssert((Boolean)(((x_text->get_Chars((Int32)(0))) == 49)));
		this->CxAssert((Boolean)(((x_text->get_Chars((Int32)(1))) == 50)));
		this->CxAssert((Boolean)(((x_text->get_Chars((Int32)(2))) == 51)));
		this->CxAssert((Boolean)(((x_text->get_Chars((Int32)(3))) == 52)));
		this->CxAssert((Boolean)(((x_text->get_Chars((Int32)(4))) == 53)));
		return;
	}
	void StringTest::DoMiscTest()
	{
IL_0000:
		String* x_text = (new String((Char)(32), (Int32)(10)));
		this->CxAssert((Boolean)(((x_text->get_Length()) == 10)));
		String* x_text2 = (new String(L"12345"));
		Array* x_array = new Array(CharType,30);
		x_text2->CopyTo((Int32)(0), x_array, (Int32)(0), (Int32)(x_text2->get_Length()));
		Int32 x_num = 0;
		String* x_text3 = x_text2;
		Int32 x_i = 0;
		
		{
IL_006a:
			if (((x_i) < x_text3->get_Length()))
			{
				goto IL_004e;
			}
			else
			{
				goto leaveBlock2;
			}

		}
		{
IL_004e:
			Char x_c = x_text3->get_Chars((Int32)(x_i));
			this->CxAssert((Boolean)((((*((UInt16*)x_array->Address(x_num)))) == x_c)));
			++x_num;
			goto IL_0068;
		}
		{
IL_0068:
			++x_i;
			goto IL_006a;
		}
leaveBlock2:

		x_array = x_text2->ToCharArray();
		this->CxAssert((Boolean)((((x_array) != nullptr) && ((x_array->get_Length()) == x_text2->get_Length()))));
		String* x_a = (new String(x_array));
		this->CxAssert((Boolean)(String::Equals(x_a, x_text2)));
		String* x_a2 = (new String(x_array, (Int32)(0), (Int32)(2)));
		this->CxAssert((Boolean)(String::Equals(x_a2, (new String(L"12")))));
		this->CxAssert((Boolean)(String::op_Inequality(x_a2, (new String(L"22")))));
		this->CxAssert((Boolean)(((String::Equals(x_a2, (new String(L"22")))) == 0)));
		x_a2 = (new String(x_text2->ToCharArray(), (Int32)(0), (Int32)(x_text2->get_Length())));
		this->CxAssert((Boolean)(String::Equals(x_a2, x_text2)));
		this->CxAssert((Boolean)(((String::Compare((new String(L"abc")), (new String(L"ABC")), (Boolean)(1))) == 0)));
		this->CxAssert((Boolean)(((String::Compare((new String(L"1abce")), (Int32)(1), (new String(L"abc")), (Int32)(0), (Int32)(3))) == 0)));
		this->CxAssert((Boolean)(((String::Compare((new String(L"1abce")), (Int32)(1), (new String(L"ABC")), (Int32)(0), (Int32)(3), (Boolean)(1))) == 0)));
		this->CxAssert((Boolean)(((String::CompareOrdinal((new String(L"abc")), (new String(L"abc")))) == 0)));
		this->CxAssert((Boolean)(((String::CompareOrdinal((new String(L"1abce")), (Int32)(1), (new String(L"abc")), (Int32)(0), (Int32)(3))) == 0)));
		x_a2 = String::Copy(x_text2);
		this->CxAssert((Boolean)(String::Equals(x_a2, x_text2)));
		String* x_empty = String::Empty;
		CharEnumerator* x_enumerator = x_a2->GetEnumerator();
		Int32 x_num2 = 0;
		
		{
IL_01ec:
			if (x_enumerator->MoveNext())
			{
				goto IL_01d0;
			}
			else
			{
				goto leaveBlock3;
			}

		}
		{
IL_01d0:
			Char x_current = x_enumerator->get_Current();
			this->CxAssert((Boolean)(((x_current) == x_a2->get_Chars((Int32)(x_num2++)))));
			goto IL_01ec;
		}
leaveBlock3:

		x_enumerator->Reset();
		Double x_num3 = 2;
		String* x_text4 = String::Concat(x_text2, x_empty, (new Int32Value(x_num2)), (new DoubleValue(x_num3)), (new Int32Value(x_num)));
		StringTest::TestConcat(x_text2, (Int32)(x_num), x_empty, (Int32)(x_num2), (Double)(x_num3));
		String* x_a3 = (new String(L"\""));
		this->CxAssert((Boolean)(String::Equals(x_a3, (new String(L"\"")))));
		x_a3 = (new String(L"c:\\Retest"));
		this->CxAssert((Boolean)(String::Equals(x_a3, (new String(L"c:\\Retest")))));
		x_a3 = (new String(L"c:\\Retest"));
		this->CxAssert((Boolean)(String::Equals(x_a3, (new String(L"c:\\Retest")))));
		return;
	}
	void StringTest::TestConcat(String* x_str1,Int32 x_index,String* x_str4,Int32 x_i,Double x_dbl)
	{
IL_0000:
		String* x_text = String::Concat(x_str1, x_str4, (new Int32Value(x_i)), (new DoubleValue(x_dbl)), (new Int32Value(x_index)));
		return;
	}
	void StringTest::DoEqualsTest()
	{
IL_0000:
		String* x_text = (new String(L"12345"));
		this->CxAssert((Boolean)(String::Equals(x_text, (new String(L"12345")))));
		this->CxAssert((Boolean)(String::Equals(x_text, (new String(L"12345")))));
		this->CxAssert((Boolean)(x_text->Equals(x_text)));
		this->CxAssert((Boolean)(x_text->Equals(x_text)));
		return;
	}
	void StringTest::DoParsingTest()
	{
IL_0000:
		String* x_text = (new String(L"12 34 56"));
		String* x_b = x_text->Substring((Int32)(3));
		this->CxAssert((Boolean)(String::Equals((new String(L"34 56")), x_b)));
		x_b = x_text->Substring((Int32)(3), (Int32)(2));
		this->CxAssert((Boolean)(String::Equals((new String(L"34")), x_b)));
		String* x_text2 = (new String(L"  12345  "));
		String* x_b2 = x_text2->Trim();
		this->CxAssert((Boolean)(String::Equals((new String(L"12345")), x_b2)));
		String* x_text3 = (new String(L"*;|@123***456@|;*"));
		String* x_text4 = (new String(L"*;|@"));
		Array* x_trimChars = x_text4->ToCharArray();
		x_b2 = x_text3->Trim(x_trimChars);
		this->CxAssert((Boolean)(String::Equals((new String(L"123***456")), x_b2)));
		x_b2 = x_text2->TrimStart(new Array(CharType,0));
		this->CxAssert((Boolean)(String::Equals((new String(L"12345  ")), x_b2)));
		x_b2 = x_text3->TrimStart(x_trimChars);
		this->CxAssert((Boolean)(String::Equals((new String(L"123***456@|;*")), x_b2)));
		x_b2 = x_text2->TrimEnd(new Array(CharType,0));
		this->CxAssert((Boolean)(String::Equals((new String(L"  12345")), x_b2)));
		x_b2 = x_text3->TrimEnd(x_trimChars);
		this->CxAssert((Boolean)(String::Equals((new String(L"*;|@123***456")), x_b2)));
		Int32 x_num = String::Compare(x_text, x_text2);
		this->CxAssert((Boolean)(((x_num) > 0)));
		x_num = x_text2->CompareTo(x_text);
		this->CxAssert((Boolean)(((x_num) < 0)));
		x_num = x_text2->CompareTo(x_text);
		this->CxAssert((Boolean)(((x_num) < 0)));
		this->CxAssert((Boolean)(x_text->EndsWith((new String(L"56")))));
		Array* x_array = new Array(CharType,2);
		(*((Char*)x_array->Address(0))) = 51;
		(*((Char*)x_array->Address(1))) = 52;
		this->CxAssert((Boolean)(((x_text->IndexOfAny(x_array)) == 3)));
		this->CxAssert((Boolean)(((x_text->IndexOfAny(x_array, (Int32)(1))) == 3)));
		this->CxAssert((Boolean)(((x_text->IndexOfAny(x_array, (Int32)(1), (Int32)(3))) == 3)));
		this->CxAssert((Boolean)(((x_text->IndexOf((Char)(53))) == 6)));
		this->CxAssert((Boolean)(((x_text->IndexOf((Char)(32), (Int32)(3))) == 5)));
		this->CxAssert((Boolean)(((x_text->IndexOf((Char)(32), (Int32)(3), (Int32)(3))) == 5)));
		this->CxAssert((Boolean)(((x_text->IndexOf((new String(L"56")))) == 6)));
		this->CxAssert((Boolean)(((x_text->IndexOf((new String(L" ")), (Int32)(3))) == 5)));
		this->CxAssert((Boolean)(((x_text->IndexOf((new String(L" ")), (Int32)(3), (Int32)(3))) == 5)));
		String* x_text5 = (new String(L"11223311"));
		this->CxAssert((Boolean)(((x_text5->LastIndexOf((Char)(49))) == 7)));
		this->CxAssert((Boolean)(((x_text5->LastIndexOf((Char)(49), (Int32)(4))) == 1)));
		this->CxAssert((Boolean)(((x_text5->LastIndexOf((Char)(49), (Int32)(4), (Int32)(4))) == 1)));
		this->CxAssert((Boolean)(((x_text5->LastIndexOf((new String(L"11")))) == 6)));
		this->CxAssert((Boolean)(((x_text5->LastIndexOf((new String(L"11")), (Int32)(4))) == 0)));
		this->CxAssert((Boolean)(((x_text5->LastIndexOf((new String(L"11")), (Int32)(4), (Int32)(5))) == 0)));
		(*((Int16*)x_array->Address(0))) = 49;
		(*((Int16*)x_array->Address(1))) = 50;
		this->CxAssert((Boolean)(((x_text5->LastIndexOfAny(x_array)) == 7)));
		this->CxAssert((Boolean)(((x_text5->LastIndexOfAny(x_array, (Int32)(4))) == 3)));
		this->CxAssert((Boolean)(((x_text5->LastIndexOfAny(x_array, (Int32)(4), (Int32)(4))) == 3)));
		String* x_a = x_text5->PadLeft((Int32)((3 + x_text5->get_Length())));
		this->CxAssert((Boolean)(String::Equals(x_a, (new String(L"   11223311")))));
		x_a = x_text5->PadLeft((Int32)((3 + x_text5->get_Length())), (Char)(45));
		this->CxAssert((Boolean)(String::Equals(x_a, (new String(L"---11223311")))));
		x_a = x_text5->PadRight((Int32)((3 + x_text5->get_Length())));
		this->CxAssert((Boolean)(String::Equals(x_a, (new String(L"11223311   ")))));
		x_a = x_text5->PadRight((Int32)((3 + x_text5->get_Length())), (Char)(45));
		this->CxAssert((Boolean)(String::Equals(x_a, (new String(L"11223311---")))));
		this->CxAssert((Boolean)(x_text5->StartsWith((new String(L"1122")))));
		this->CxAssert((Boolean)(String::Equals(x_text5->Replace((Char)(49), (Char)(120)), (new String(L"xx2233xx")))));
		this->CxAssert((Boolean)(String::Equals(x_text5->Replace((new String(L"1")), (new String(L"x"))), (new String(L"xx2233xx")))));
		this->CxAssert((Boolean)(String::Equals(x_text5->Replace((new String(L"11")), (new String(L"x"))), (new String(L"x2233x")))));
		this->CxAssert((Boolean)(String::Equals(x_text5->Remove((Int32)(2), (Int32)(2)), (new String(L"113311")))));
		this->CxAssert((Boolean)(String::Equals((new String(L"aaAAaaAA"))->ToUpper(), (new String(L"AAAAAAAA")))));
		this->CxAssert((Boolean)(String::Equals((new String(L"aaAAaaAA"))->ToLower(), (new String(L"aaaaaaaa")))));
		Array* x_value = new Array(StringType,3);
		(*((String**)x_value->Address(0))) = (new String(L"1"));
		(*((String**)x_value->Address(1))) = (new String(L"2"));
		(*((String**)x_value->Address(2))) = (new String(L"3"));
		this->CxAssert((Boolean)(String::Equals(String::Join((new String(L",")), x_value), (new String(L"1,2,3")))));
		this->CxAssert((Boolean)(String::Equals(String::Join((new String(L",")), x_value, (Int32)(1), (Int32)(2)), (new String(L"2,3")))));
		x_text5 = x_text->Insert((Int32)(3), (new String(L"111")));
		this->CxAssert((Boolean)(String::Equals(x_text5, (new String(L"12 11134 56")))));
		String* x_text6 = (new String(L"3.33"));
		if (x_text6->CompareTo((new String(L"3.33"))))
		{
			this->CxAssert((Boolean)(0));
		}

		return;
	}
	void StringTest::DoConcatTest()
	{
IL_0000:
		Array* x_array = new Array(ObjectType,4);
		(*((Object**)x_array->Address(0))) = (new String(L"1 "));
		(*((Object**)x_array->Address(1))) = (new String(L"2 "));
		(*((Object**)x_array->Address(2))) = (new String(L"3 "));
		(*((Object**)x_array->Address(3))) = (new String(L"4"));
		String* x_a = String::Concat((*((Object**)x_array->Address(0))));
		this->CxAssert((Boolean)(String::Equals(x_a, (new String(L"1 ")))));
		x_a = String::Concat(x_array);
		this->CxAssert((Boolean)(String::Equals(x_a, (new String(L"1 2 3 4")))));
		Array* x_array2 = new Array(StringType,4);
		(*((String**)x_array2->Address(0))) = (new String(L"1 "));
		(*((String**)x_array2->Address(1))) = (new String(L"2 "));
		(*((String**)x_array2->Address(2))) = (new String(L"3 "));
		(*((String**)x_array2->Address(3))) = (new String(L"4"));
		x_a = String::Concat(x_array2);
		this->CxAssert((Boolean)(String::Equals(x_a, (new String(L"1 2 3 4")))));
		x_a = String::Concat((*((Object**)x_array->Address(0))), (*((Object**)x_array->Address(1))));
		this->CxAssert((Boolean)(String::Equals(x_a, (new String(L"1 2 ")))));
		x_a = String::Concat((*((Object**)x_array2->Address(0))), (*((Object**)x_array2->Address(1))));
		this->CxAssert((Boolean)(String::Equals(x_a, (new String(L"1 2 ")))));
		x_a = String::Concat((*((Object**)x_array->Address(0))), (*((Object**)x_array->Address(1))), (*((Object**)x_array->Address(2))));
		this->CxAssert((Boolean)(String::Equals(x_a, (new String(L"1 2 3 ")))));
		x_a = String::Concat((*((Object**)x_array2->Address(0))), (*((Object**)x_array2->Address(1))), (*((Object**)x_array2->Address(2))));
		this->CxAssert((Boolean)(String::Equals(x_a, (new String(L"1 2 3 ")))));
		x_a = String::Concat((*((Object**)x_array2->Address(0))), (*((Object**)x_array2->Address(1))), (*((Object**)x_array2->Address(2))), (*((Object**)x_array2->Address(3))));
		this->CxAssert((Boolean)(String::Equals(x_a, (new String(L"1 2 3 4")))));
		return;
	}
	void StringTest::CxAssert(Boolean x_x)
	{
IL_0000:
		if (((x_x) == 0))
		{
			this->x_caBlock->TestFailed((new String(L"String TestFailed")));
		}

		return;
	}
	TimeTest::TimeTest(CABlock* x_caBlock)
	{
IL_0000:
		this->x_dat1 = DateTimeValue::get_Now();
		
		this->x_caBlock = x_caBlock;
		return;
	}
	void TimeTest::Test()
	{
IL_0000:
		this->x_caBlock->Send((new String(L"Doing TimeTest")));
		this->x_caBlock->Send((new String(L"\tDoing TestTimeSpan")));
		this->TestTimeSpan();
		this->x_caBlock->Send((new String(L"\tDoing TestDateTime")));
		this->TestDateTime();
		this->x_caBlock->Send((new String(L"\tDoing DateTimeMethodTests")));
		this->DateTimeMethodTests();
		this->x_caBlock->Send((new String(L"\tDoing TimeArrayTests")));
		this->TimeArrayTests();
		return;
	}
	void TimeTest::TestTimeSpan()
	{
IL_0000:
		TimeSpan x_timeSpan = TimeSpan((Int64)(((Int64)100)));
		TimeSpan x_timeSpan2 = TimeSpanValue(x_timeSpan).Add((TimeSpan)(x_timeSpan));
		this->CxAssert((Boolean)(((TimeSpanValue(x_timeSpan2).get_Ticks()) == ((Int64)200))));
		this->CxAssert((Boolean)(((TimeSpanValue::Compare((TimeSpan)(x_timeSpan), (TimeSpan)(x_timeSpan2))) < 0)));
		this->CxAssert((Boolean)(((TimeSpanValue(x_timeSpan).CompareTo((new TimeSpanValue(x_timeSpan2)))) < 0)));
		this->CxAssert((Boolean)(((TimeSpanValue(x_timeSpan).CompareTo((TimeSpan)(x_timeSpan2))) < 0)));
		x_timeSpan = TimeSpanValue(x_timeSpan2).Duration();
		this->CxAssert((Boolean)(((TimeSpanValue(x_timeSpan).get_Ticks()) == ((Int64)200))));
		this->CxAssert((Boolean)(TimeSpanValue::Equals((TimeSpan)(x_timeSpan), (TimeSpan)(x_timeSpan2))));
		this->CxAssert((Boolean)(TimeSpanValue(x_timeSpan).Equals((TimeSpan)(x_timeSpan2))));
		this->CxAssert((Boolean)(((TimeSpanValue((TimeSpanValue::FromDays((Double)(22)))).get_Ticks()) == 19008000000000)));
		this->CxAssert((Boolean)(((TimeSpanValue((TimeSpanValue::FromHours((Double)(10)))).get_Ticks()) == 360000000000)));
		this->CxAssert((Boolean)(((TimeSpanValue((TimeSpanValue::FromMilliseconds((Double)(100)))).get_Ticks()) == ((Int64)1000000))));
		this->CxAssert((Boolean)(((TimeSpanValue((TimeSpanValue::FromMinutes((Double)(25)))).get_Ticks()) == 15000000000)));
		this->CxAssert((Boolean)(((TimeSpanValue((TimeSpanValue::FromSeconds((Double)(18)))).get_Ticks()) == ((Int64)180000000))));
		x_timeSpan = TimeSpanValue::FromTicks((Int64)(((Int64)6500000)));
		this->CxAssert((Boolean)(((TimeSpanValue(x_timeSpan).get_Ticks()) == ((Int64)6500000))));
		x_timeSpan = TimeSpanValue(x_timeSpan).Negate();
		this->CxAssert((Boolean)(((TimeSpanValue(x_timeSpan).get_Ticks()) == ((Int64)-6500000))));
		this->CxAssert((Boolean)(((TimeSpanValue((TimeSpanValue(x_timeSpan).Subtract((TimeSpan)(x_timeSpan2)))).get_Ticks()) == ((Int64)-6500200))));
		this->CxAssert((Boolean)(((TimeSpanValue((TimeSpanValue::Parse((new String(L"1.1:1:1"))))).get_Ticks()) == 900610000000)));
		this->CxAssert((Boolean)(((TimeSpanValue((TimeSpanValue::Parse((new String(L"1.1:1:1.200"))))).get_Ticks()) == 900612000000)));
		this->CxAssert((Boolean)(((TimeSpanValue((TimeSpanValue::Parse((new String(L"1:1:1"))))).get_Ticks()) == 36610000000)));
		this->CxAssert((Boolean)(((TimeSpanValue((TimeSpanValue::Parse((new String(L"22"))))).get_Ticks()) == 19008000000000)));
		x_timeSpan = TimeSpanValue::Parse((new String(L"1.2:3:4.200")));
		String* x_a = TimeSpanValue(x_timeSpan).ToString();
		this->CxAssert((Boolean)(String::Equals(x_a, (new String(L"1.02:03:04.2000000")))));
		this->CxAssert((Boolean)(((TimeSpanValue(x_timeSpan).get_Days()) == 1)));
		this->CxAssert((Boolean)(((TimeSpanValue(x_timeSpan).get_Hours()) == 2)));
		this->CxAssert((Boolean)(((TimeSpanValue(x_timeSpan).get_Minutes()) == 3)));
		this->CxAssert((Boolean)(((TimeSpanValue(x_timeSpan).get_Seconds()) == 4)));
		this->CxAssert((Boolean)(((TimeSpanValue(x_timeSpan).get_Milliseconds()) == 200)));
		this->CxAssert((Boolean)(((TimeSpanValue(x_timeSpan).get_Ticks()) == 937842000000)));
		this->CxAssert((Double)(TimeSpanValue(x_timeSpan).get_TotalDays()), (Double)(1.08546527777778));
		this->CxAssert((Double)(TimeSpanValue(x_timeSpan).get_TotalHours()), (Double)(26.0511666666667));
		this->CxAssert((Double)(TimeSpanValue(x_timeSpan).get_TotalMinutes()), (Double)(1563.07));
		this->CxAssert((Double)(TimeSpanValue(x_timeSpan).get_TotalSeconds()), (Double)(93784.2));
		this->CxAssert((Double)(TimeSpanValue(x_timeSpan).get_TotalMilliseconds()), (Double)(93784200));
		this->CxAssert((Boolean)(((TimeSpanValue((TimeSpanValue::op_Addition((TimeSpan)(x_timeSpan2), (TimeSpan)(x_timeSpan2)))).get_Ticks()) == ((Int64)400))));
		x_timeSpan = x_timeSpan2;
		this->CxAssert((Boolean)(TimeSpanValue::Equals((TimeSpan)(x_timeSpan), (TimeSpan)(x_timeSpan2))));
		this->CxAssert((Boolean)(((TimeSpanValue::op_Inequality((TimeSpan)(x_timeSpan), (TimeSpan)(x_timeSpan2))) == 0)));
		x_timeSpan = TimeSpan((Int64)(((Int64)100)));
		this->CxAssert((Boolean)(((TimeSpanValue::op_GreaterThan((TimeSpan)(x_timeSpan), (TimeSpan)(x_timeSpan2))) == 0)));
		this->CxAssert((Boolean)(((TimeSpanValue::op_GreaterThanOrEqual((TimeSpan)(x_timeSpan), (TimeSpan)(x_timeSpan2))) == 0)));
		this->CxAssert((Boolean)(((TimeSpanValue::op_LessThan((TimeSpan)(x_timeSpan2), (TimeSpan)(x_timeSpan))) == 0)));
		this->CxAssert((Boolean)(((TimeSpanValue::op_LessThanOrEqual((TimeSpan)(x_timeSpan2), (TimeSpan)(x_timeSpan))) == 0)));
		this->CxAssert((Boolean)(TimeSpanValue::Equals((TimeSpan)(x_timeSpan), (TimeSpan)(x_timeSpan))));
		x_timeSpan = TimeSpanValue::op_Subtraction((TimeSpan)(x_timeSpan2), (TimeSpan)(x_timeSpan));
		this->CxAssert((Boolean)(((TimeSpanValue(x_timeSpan).get_Ticks()) == ((Int64)100))));
		x_timeSpan = TimeSpanValue::op_UnaryNegation((TimeSpan)(x_timeSpan));
		this->CxAssert((Boolean)(((TimeSpanValue(x_timeSpan).get_Ticks()) == ((Int64)-100))));
		this->CxAssert((Boolean)(((TimeSpanValue((TimeSpanValue::op_UnaryPlus((TimeSpan)(x_timeSpan)))).get_Ticks()) == ((Int64)-100))));
		this->CxAssert((Boolean)(((TimeSpanValue((TimeSpan((Int64)(((Int64)1000))))).get_Ticks()) == ((Int64)1000))));
		this->CxAssert((Boolean)(((TimeSpanValue((TimeSpan((Int32)(10), (Int32)(11), (Int32)(30)))).get_Ticks()) == 366900000000)));
		this->CxAssert((Boolean)(((TimeSpanValue((TimeSpan((Int32)(3), (Int32)(10), (Int32)(11), (Int32)(30)))).get_Ticks()) == 2958900000000)));
		this->CxAssert((Boolean)(((TimeSpanValue((TimeSpan((Int32)(3), (Int32)(10), (Int32)(11), (Int32)(30), (Int32)(100)))).get_Ticks()) == 2958901000000)));
		this->CxAssert((Boolean)(((TimeSpanValue((TimeSpan((Int32)(3), (Int32)(10), (Int32)(11), (Int32)(30), (Int32)(100)))).get_Ticks()) == 2958901000000)));
		x_timeSpan = TimeSpan((Int32)(71), (Int32)(3), (Int32)(12), (Int32)(13));
		this->CxAssert((Boolean)(((TimeSpanValue(x_timeSpan).get_Ticks()) == 61459330000000)));
		String* x_text = TimeSpanValue(x_timeSpan).ToString();
		this->CxAssert((Boolean)(x_text->Equals((new String(L"71.03:12:13")))));
		x_timeSpan = TimeSpan((Int32)(-71), (Int32)(3), (Int32)(12), (Int32)(13));
		this->CxAssert((Boolean)(((TimeSpanValue(x_timeSpan).get_Ticks()) == -61228670000000)));
		String* x_text2 = TimeSpanValue(x_timeSpan).ToString();
		this->CxAssert((Boolean)(x_text2->Equals((new String(L"-70.20:47:47")))));
		x_timeSpan = TimeSpanValue::Parse((new String(L"-71.03:12:13")));
		this->CxAssert((Boolean)(((TimeSpanValue(x_timeSpan).get_Ticks()) == -61459330000000)));
		String* x_text3 = TimeSpanValue(x_timeSpan).ToString();
		this->CxAssert((Boolean)(x_text3->Equals((new String(L"-71.03:12:13")))));
		Object* x_obj = (new TimeSpanValue(TimeSpanValue::MinValue));
		this->CxAssert((Boolean)(((TimeSpanValue((TimeSpan(x_obj->get_AsTimeSpan()))).get_Ticks()) == TimeSpanValue((TimeSpanValue::MinValue)).get_Ticks())));
		TimeSpan x_minValue = TimeSpanValue::MinValue;
		this->CxAssert((Boolean)(TimeSpanValue(x_minValue).Equals(x_obj)));
		this->CxAssert((Boolean)(((TimeSpanValue((TimeSpanValue::MinValue)).CompareTo(x_obj)) == 0)));
		Int64 x_num = 864000000000;
		this->CxAssert((Boolean)(((864000000000) == x_num)));
		x_num = 36000000000;
		this->CxAssert((Boolean)(((36000000000) == x_num)));
		x_num = ((Int64)600000000);
		this->CxAssert((Boolean)(((((Int64)600000000)) == x_num)));
		x_num = ((Int64)10000000);
		this->CxAssert((Boolean)(((((Int64)10000000)) == x_num)));
		x_num = ((Int64)10000);
		this->CxAssert((Boolean)(((((Int64)10000)) == x_num)));
		this->CxAssert((Boolean)(TimeSpanValue::Equals((TimeSpan)(TimeSpanValue::Zero), (TimeSpan)(TimeSpanValue::Zero))));
		this->CxAssert((Boolean)(TimeSpanValue::Equals((TimeSpan)(TimeSpanValue::MaxValue), (TimeSpan)(TimeSpanValue::MaxValue))));
		this->CxAssert((Boolean)(x_obj->Equals((new TimeSpanValue(TimeSpanValue::MinValue)))));
		String* x_a2 = x_obj->ToString();
		x_minValue = TimeSpanValue::MinValue;
		this->CxAssert((Boolean)(String::Equals(x_a2, TimeSpanValue(x_minValue).ToString())));
		return;
	}
	void TimeTest::TestDateTime()
	{
IL_0000:
		this->CxAssert((Boolean)(((DateTimeValue((DateTime())).get_Ticks()) == ((Int64)0))));
		this->CxAssert((Boolean)(((DateTimeValue((DateTime((Int64)(((Int64)1200))))).get_Ticks()) == ((Int64)1200))));
		this->CxAssert((Boolean)(((DateTimeValue((DateTime((Int32)(2003), (Int32)(7), (Int32)(23)))).get_Ticks()) == 631945152000000000)));
		this->CxAssert((Boolean)(((DateTimeValue((DateTime((Int32)(2003), (Int32)(7), (Int32)(23), (Int32)(12), (Int32)(30), (Int32)(30)))).get_Ticks()) == 631945602300000000)));
		DateTime x_dateTime = DateTime((Int32)(2003), (Int32)(7), (Int32)(23), (Int32)(12), (Int32)(30), (Int32)(30), (Int32)(100));
		this->CxAssert((Boolean)(((DateTimeValue(x_dateTime).get_Ticks()) == 631945602301000000)));
		this->CxAssert((Boolean)(((DateTimeValue((DateTimeValue(x_dateTime).get_Date())).get_Ticks()) == 631945152000000000)));
		Int32 x_day = DateTimeValue(x_dateTime).get_Day();
		this->CxAssert((Boolean)(((x_day) == 23)));
		DayOfWeek x_dayOfWeek = (DayOfWeek)DateTimeValue(x_dateTime).get_DayOfWeek();
		this->CxAssert((Boolean)(((x_dayOfWeek) == 3)));
		Int32 x_dayOfYear = DateTimeValue(x_dateTime).get_DayOfYear();
		this->CxAssert((Boolean)(((x_dayOfYear) == 204)));
		Int32 x_hour = DateTimeValue(x_dateTime).get_Hour();
		this->CxAssert((Boolean)(((x_hour) == 12)));
		Int32 x_millisecond = DateTimeValue(x_dateTime).get_Millisecond();
		this->CxAssert((Boolean)(((x_millisecond) == 100)));
		Int32 x_minute = DateTimeValue(x_dateTime).get_Minute();
		this->CxAssert((Boolean)(((x_minute) == 30)));
		Int32 x_month = DateTimeValue(x_dateTime).get_Month();
		this->CxAssert((Boolean)(((x_month) == 7)));
		DateTime x_now = DateTimeValue::get_Now();
		x_day = DateTimeValue(x_now).get_Day();
		x_dayOfYear = DateTimeValue(x_now).get_DayOfYear();
		x_dayOfWeek = (DayOfWeek)DateTimeValue(x_now).get_DayOfWeek();
		x_hour = DateTimeValue(x_now).get_Hour();
		Int32 x_second = DateTimeValue(x_dateTime).get_Second();
		this->CxAssert((Boolean)(((x_second) == 30)));
		this->CxAssert((Boolean)(((TimeSpanValue((DateTimeValue(x_dateTime).get_TimeOfDay())).get_Ticks()) == 450301000000)));
		DateTime x_today = DateTimeValue::get_Today();
		x_day = DateTimeValue(x_today).get_Day();
		x_dayOfYear = DateTimeValue(x_today).get_DayOfYear();
		x_dayOfWeek = (DayOfWeek)DateTimeValue(x_today).get_DayOfWeek();
		x_hour = DateTimeValue(x_today).get_Hour();
		DateTime x_utcNow = DateTimeValue::get_UtcNow();
		x_day = DateTimeValue(x_utcNow).get_Day();
		x_dayOfYear = DateTimeValue(x_utcNow).get_DayOfYear();
		x_dayOfWeek = (DayOfWeek)DateTimeValue(x_utcNow).get_DayOfWeek();
		x_hour = DateTimeValue(x_utcNow).get_Hour();
		Int32 x_year = DateTimeValue(x_dateTime).get_Year();
		this->CxAssert((Boolean)(((x_year) == 2003)));
		return;
	}
	void TimeTest::DateTimeMethodTests()
	{
IL_0000:
		DateTime x_dateTime = DateTime((Int32)(2003), (Int32)(7), (Int32)(23), (Int32)(12), (Int32)(30), (Int32)(30), (Int32)(100));
		TimeSpan x_timeSpan = TimeSpan((Int32)(0), (Int32)(2), (Int32)(0), (Int32)(0));
		this->CxAssert((Boolean)(((DateTimeValue((DateTimeValue(x_dateTime).Add((TimeSpan)(x_timeSpan)))).get_Ticks()) == 631945674301000000)));
		this->CxAssert((Boolean)(((DateTimeValue((DateTimeValue(x_dateTime).AddDays((Double)(1.5)))).get_Ticks()) == 631946898301000000)));
		this->CxAssert((Boolean)(((DateTimeValue((DateTimeValue(x_dateTime).AddHours((Double)(2.5)))).get_Ticks()) == 631945692301000000)));
		this->CxAssert((Boolean)(((DateTimeValue((DateTimeValue(x_dateTime).AddMilliseconds((Double)(159)))).get_Ticks()) == 631945602302590000)));
		this->CxAssert((Boolean)(((DateTimeValue((DateTimeValue(x_dateTime).AddMinutes((Double)(3.2)))).get_Ticks()) == 631945604221000000)));
		this->CxAssert((Boolean)(((DateTimeValue((DateTimeValue(x_dateTime).AddMonths((Int32)(5)))).get_Ticks()) == 632077794301000000)));
		this->CxAssert((Boolean)(((DateTimeValue((DateTimeValue(x_dateTime).AddSeconds((Double)(6.66)))).get_Ticks()) == 631945602367600000)));
		this->CxAssert((Boolean)(((DateTimeValue((DateTimeValue(x_dateTime).AddTicks((Int64)(((Int64)666))))).get_Ticks()) == 631945602301000666)));
		DateTime x_dateTime2 = DateTimeValue(x_dateTime).AddYears((Int32)(3));
		this->CxAssert((Boolean)(((DateTimeValue(x_dateTime2).get_Ticks()) == 632892546301000000)));
		this->CxAssert((Boolean)(((DateTimeValue::Compare((DateTime)(x_dateTime2), (DateTime)(x_dateTime))) > 0)));
		this->CxAssert((Boolean)(((DateTimeValue(x_dateTime).CompareTo((DateTime)(x_dateTime2))) < 0)));
		this->CxAssert((Boolean)(((DateTimeValue::DaysInMonth((Int32)(2003), (Int32)(1))) == 31)));
		this->CxAssert((Boolean)(((DateTimeValue(x_dateTime).Equals((DateTime)(x_dateTime2))) == 0)));
		x_dateTime2 = x_dateTime;
		this->CxAssert((Boolean)(DateTimeValue::Equals((DateTime)(x_dateTime), (DateTime)(x_dateTime2))));
		this->CxAssert((Boolean)(DateTimeValue::IsLeapYear((Int32)(2004))));
		x_dateTime2 = DateTimeValue(x_dateTime).Subtract((TimeSpan)(x_timeSpan));
		this->CxAssert((Boolean)(((DateTimeValue(x_dateTime2).get_Ticks()) == 631945530301000000)));
		this->CxAssert((Boolean)(((TimeSpanValue((DateTimeValue(x_dateTime).Subtract((DateTime)(x_dateTime2)))).get_Ticks()) == 72000000000)));
		x_dateTime2 = DateTimeValue(x_dateTime).ToLocalTime();
		x_dateTime2 = DateTimeValue(x_dateTime).ToUniversalTime();
		x_dateTime2 = DateTimeValue::op_Addition((DateTime)(x_dateTime), (TimeSpan)(x_timeSpan));
		this->CxAssert((Boolean)(((DateTimeValue(x_dateTime2).get_Ticks()) == 631945674301000000)));
		this->CxAssert((Boolean)(((DateTimeValue::Equals((DateTime)(x_dateTime2), (DateTime)(x_dateTime))) == 0)));
		this->CxAssert((Boolean)(((DateTimeValue::op_GreaterThan((DateTime)(x_dateTime), (DateTime)(x_dateTime2))) == 0)));
		this->CxAssert((Boolean)(((DateTimeValue::op_GreaterThanOrEqual((DateTime)(x_dateTime), (DateTime)(x_dateTime2))) == 0)));
		this->CxAssert((Boolean)(DateTimeValue::Equals((DateTime)(x_dateTime2), (DateTime)(x_dateTime2))));
		this->CxAssert((Boolean)(((DateTimeValue::op_LessThan((DateTime)(x_dateTime2), (DateTime)(x_dateTime))) == 0)));
		this->CxAssert((Boolean)(((DateTimeValue::op_LessThanOrEqual((DateTime)(x_dateTime2), (DateTime)(x_dateTime))) == 0)));
		x_dateTime2 = DateTimeValue::op_Subtraction((DateTime)(x_dateTime), (TimeSpan)(x_timeSpan));
		this->CxAssert((Boolean)(((DateTimeValue(x_dateTime2).get_Ticks()) == 631945530301000000)));
		this->CxAssert((Boolean)(((TimeSpanValue((DateTimeValue::op_Subtraction((DateTime)(x_dateTime), (DateTime)(x_dateTime2)))).get_Ticks()) == 72000000000)));
		x_dateTime2 = DateTime((Int32)(2003), (Int32)(7), (Int32)(23), (Int32)(14), (Int32)(2), (Int32)(30), (Int32)(100));
		this->CxAssert((Boolean)(((DateTimeValue(x_dateTime2).get_Ticks()) == 631945657501000000)));
		this->CxAssert((Boolean)(((DateTimeValue(x_dateTime2).get_Hour()) == 14)));
		String* x_text = DateTimeValue(x_dateTime2).ToString();
		this->CxAssert((Boolean)(x_text->Equals((new String(L"7/23/2003 2:02:30 PM")))));
		x_dateTime2 = DateTime((Int32)(2003), (Int32)(7), (Int32)(23), (Int32)(2), (Int32)(20), (Int32)(1), (Int32)(100));
		this->CxAssert((Boolean)(((DateTimeValue(x_dateTime2).get_Ticks()) == 631945236011000000)));
		this->CxAssert((Boolean)(((DateTimeValue(x_dateTime2).get_Hour()) == 2)));
		x_text = DateTimeValue(x_dateTime2).ToString();
		this->CxAssert((Boolean)(x_text->Equals((new String(L"7/23/2003 2:20:01 AM")))));
		this->CxAssert((Boolean)(((DateTimeValue((DateTimeValue::MinValue)).get_Ticks()) == ((Int64)0))));
		this->CxAssert((Boolean)(((DateTimeValue((DateTimeValue::MaxValue)).get_Ticks()) == 3155378975999999999)));
		Object* x_obj = (new DateTimeValue(DateTimeValue::MinValue));
		this->CxAssert((Boolean)(((DateTimeValue((DateTime(x_obj->get_AsDateTime()))).get_Ticks()) == ((Int64)0))));
		this->CxAssert((Boolean)(DateTimeValue((DateTimeValue::MinValue)).Equals(x_obj)));
		this->CxAssert((Boolean)(((DateTimeValue((DateTimeValue::MinValue)).CompareTo(x_obj)) == 0)));
		this->CxAssert((Boolean)(x_obj->Equals((new DateTimeValue(DateTimeValue::MinValue)))));
		this->CxAssert((Boolean)(String::Equals(x_obj->ToString(), DateTimeValue((DateTimeValue::MinValue)).ToString())));
		this->CxAssert((Boolean)(DateTimeValue::op_Inequality((DateTime)(x_dateTime2), (DateTime)(x_dateTime))));
		return;
	}
	void TimeTest::TimeArrayTests()
	{
IL_0000:
		this->DateTimeArrayTests();
		this->TimeSpanArrayTests();
		return;
	}
	void TimeTest::DateTimeArrayTests()
	{
IL_0000:
		Array* x_array = new Array(DateTimeType,5);
		(*((DateTime*)x_array->Address(0))) = DateTime((Int32)(2000), (Int32)(4), (Int32)(6));
		(*((DateTime*)x_array->Address(1))) = DateTime((Int32)(2000), (Int32)(4), (Int32)(7));
		(*((DateTime*)x_array->Address(2))) = DateTime((Int32)(2000), (Int32)(4), (Int32)(8));
		(*((DateTime*)x_array->Address(3))) = DateTime((Int32)(2000), (Int32)(4), (Int32)(9));
		(*((DateTime*)x_array->Address(4))) = DateTime((Int32)(2000), (Int32)(4), (Int32)(10));
		this->CxAssert((Boolean)(((x_array->get_Length()) == 5)));
		this->CxAssert((Boolean)(DateTimeValue::Equals((DateTime)((*((DateTime*)x_array->Address(3)))), (DateTime)(DateTime((Int32)(2000), (Int32)(4), (Int32)(9))))));
		this->CxAssert((Boolean)(DateTimeValue::Equals((DateTime)((*((DateTime*)x_array->Address(1)))), (DateTime)(DateTime((Int32)(2000), (Int32)(4), (Int32)(7))))));
		Array* x_array2 = new Array(DateTimeType,2,4);
		(*((DateTime*)x_array2->Address(0,0))) = DateTime((Int32)(2000), (Int32)(4), (Int32)(6));
		(*((DateTime*)x_array2->Address(0,1))) = DateTime((Int32)(2000), (Int32)(4), (Int32)(7));
		(*((DateTime*)x_array2->Address(0,2))) = DateTime((Int32)(2000), (Int32)(4), (Int32)(8));
		(*((DateTime*)x_array2->Address(0,3))) = DateTime((Int32)(2000), (Int32)(4), (Int32)(9));
		(*((DateTime*)x_array2->Address(1,0))) = DateTime((Int32)(2000), (Int32)(4), (Int32)(10));
		(*((DateTime*)x_array2->Address(1,1))) = DateTime((Int32)(2000), (Int32)(4), (Int32)(11));
		(*((DateTime*)x_array2->Address(1,2))) = DateTime((Int32)(2000), (Int32)(4), (Int32)(12));
		(*((DateTime*)x_array2->Address(1,3))) = DateTime((Int32)(2000), (Int32)(4), (Int32)(13));
		this->CxAssert((Boolean)(DateTimeValue::Equals((DateTime)((*((DateTime*)x_array2->Address(0,2)))), (DateTime)(DateTime((Int32)(2000), (Int32)(4), (Int32)(8))))));
		Array* x_array3 = new Array(DateTimeType,2,2,4);
		(*((DateTime*)x_array3->Address(0,0,0))) = DateTime((Int32)(2000), (Int32)(4), (Int32)(6));
		(*((DateTime*)x_array3->Address(0,0,1))) = DateTime((Int32)(2000), (Int32)(4), (Int32)(7));
		(*((DateTime*)x_array3->Address(0,0,2))) = DateTime((Int32)(2000), (Int32)(4), (Int32)(8));
		(*((DateTime*)x_array3->Address(0,0,3))) = DateTime((Int32)(2000), (Int32)(4), (Int32)(9));
		(*((DateTime*)x_array3->Address(0,1,0))) = DateTime((Int32)(2000), (Int32)(4), (Int32)(10));
		(*((DateTime*)x_array3->Address(0,1,1))) = DateTime((Int32)(2000), (Int32)(4), (Int32)(11));
		(*((DateTime*)x_array3->Address(0,1,2))) = DateTime((Int32)(2000), (Int32)(4), (Int32)(12));
		(*((DateTime*)x_array3->Address(0,1,3))) = DateTime((Int32)(2000), (Int32)(4), (Int32)(13));
		(*((DateTime*)x_array3->Address(1,0,0))) = DateTime((Int32)(2000), (Int32)(4), (Int32)(14));
		(*((DateTime*)x_array3->Address(1,0,1))) = DateTime((Int32)(2000), (Int32)(4), (Int32)(15));
		(*((DateTime*)x_array3->Address(1,0,2))) = DateTime((Int32)(2000), (Int32)(4), (Int32)(16));
		(*((DateTime*)x_array3->Address(1,0,3))) = DateTime((Int32)(2000), (Int32)(4), (Int32)(17));
		(*((DateTime*)x_array3->Address(1,1,0))) = DateTime((Int32)(2000), (Int32)(4), (Int32)(18));
		(*((DateTime*)x_array3->Address(1,1,1))) = DateTime((Int32)(2000), (Int32)(4), (Int32)(19));
		(*((DateTime*)x_array3->Address(1,1,2))) = DateTime((Int32)(2000), (Int32)(4), (Int32)(20));
		(*((DateTime*)x_array3->Address(1,1,3))) = DateTime((Int32)(2000), (Int32)(4), (Int32)(21));
		this->CxAssert((Boolean)(DateTimeValue::Equals((DateTime)((*((DateTime*)x_array3->Address(0,0,3)))), (DateTime)(DateTime((Int32)(2000), (Int32)(4), (Int32)(9))))));
		(*((DateTime*)x_array3->Address(0,0,3))) = DateTime((Int32)(2000), (Int32)(4), (Int32)(27));
		this->CxAssert((Boolean)(DateTimeValue::Equals((DateTime)((*((DateTime*)x_array3->Address(0,0,3)))), (DateTime)(DateTime((Int32)(2000), (Int32)(4), (Int32)(27))))));
		x_array3->SetValue((new DateTimeValue(DateTime((Int32)(2000), (Int32)(4), (Int32)(28)))), (Int32)(0), (Int32)(0), (Int32)(3));
		this->CxAssert((Boolean)(DateTimeValue::Equals((DateTime)((*((DateTime*)x_array3->Address(0,0,3)))), (DateTime)(DateTime((Int32)(2000), (Int32)(4), (Int32)(28))))));
		DateTime x_d = (*((DateTime*)x_array->Address(2))) = DateTime((Int32)(2000), (Int32)(4), (Int32)(27));
		this->CxAssert((Boolean)(DateTimeValue::Equals((DateTime)((*((DateTime*)x_array->Address(2)))), (DateTime)(x_d))));
		return;
	}
	void TimeTest::TimeSpanArrayTests()
	{
IL_0000:
		Array* x_array = new Array(TimeSpanType,5);
		(*((TimeSpan*)x_array->Address(0))) = TimeSpan((Int32)(2000), (Int32)(4), (Int32)(6));
		(*((TimeSpan*)x_array->Address(1))) = TimeSpan((Int32)(2000), (Int32)(4), (Int32)(7));
		(*((TimeSpan*)x_array->Address(2))) = TimeSpan((Int32)(2000), (Int32)(4), (Int32)(8));
		(*((TimeSpan*)x_array->Address(3))) = TimeSpan((Int32)(2000), (Int32)(4), (Int32)(9));
		(*((TimeSpan*)x_array->Address(4))) = TimeSpan((Int32)(2000), (Int32)(4), (Int32)(10));
		this->CxAssert((Boolean)(((x_array->get_Length()) == 5)));
		this->CxAssert((Boolean)(TimeSpanValue::Equals((TimeSpan)((*((TimeSpan*)x_array->Address(3)))), (TimeSpan)(TimeSpan((Int32)(2000), (Int32)(4), (Int32)(9))))));
		this->CxAssert((Boolean)(TimeSpanValue::Equals((TimeSpan)((*((TimeSpan*)x_array->Address(1)))), (TimeSpan)(TimeSpan((Int32)(2000), (Int32)(4), (Int32)(7))))));
		Array* x_array2 = new Array(TimeSpanType,2,4);
		(*((TimeSpan*)x_array2->Address(0,0))) = TimeSpan((Int32)(2000), (Int32)(4), (Int32)(6));
		(*((TimeSpan*)x_array2->Address(0,1))) = TimeSpan((Int32)(2000), (Int32)(4), (Int32)(7));
		(*((TimeSpan*)x_array2->Address(0,2))) = TimeSpan((Int32)(2000), (Int32)(4), (Int32)(8));
		(*((TimeSpan*)x_array2->Address(0,3))) = TimeSpan((Int32)(2000), (Int32)(4), (Int32)(9));
		(*((TimeSpan*)x_array2->Address(1,0))) = TimeSpan((Int32)(2000), (Int32)(4), (Int32)(10));
		(*((TimeSpan*)x_array2->Address(1,1))) = TimeSpan((Int32)(2000), (Int32)(4), (Int32)(11));
		(*((TimeSpan*)x_array2->Address(1,2))) = TimeSpan((Int32)(2000), (Int32)(4), (Int32)(12));
		(*((TimeSpan*)x_array2->Address(1,3))) = TimeSpan((Int32)(2000), (Int32)(4), (Int32)(13));
		this->CxAssert((Boolean)(TimeSpanValue::Equals((TimeSpan)((*((TimeSpan*)x_array2->Address(0,2)))), (TimeSpan)(TimeSpan((Int32)(2000), (Int32)(4), (Int32)(8))))));
		Array* x_array3 = new Array(TimeSpanType,2,2,4);
		(*((TimeSpan*)x_array3->Address(0,0,0))) = TimeSpan((Int32)(2000), (Int32)(4), (Int32)(6));
		(*((TimeSpan*)x_array3->Address(0,0,1))) = TimeSpan((Int32)(2000), (Int32)(4), (Int32)(7));
		(*((TimeSpan*)x_array3->Address(0,0,2))) = TimeSpan((Int32)(2000), (Int32)(4), (Int32)(8));
		(*((TimeSpan*)x_array3->Address(0,0,3))) = TimeSpan((Int32)(2000), (Int32)(4), (Int32)(9));
		(*((TimeSpan*)x_array3->Address(0,1,0))) = TimeSpan((Int32)(2000), (Int32)(4), (Int32)(10));
		(*((TimeSpan*)x_array3->Address(0,1,1))) = TimeSpan((Int32)(2000), (Int32)(4), (Int32)(11));
		(*((TimeSpan*)x_array3->Address(0,1,2))) = TimeSpan((Int32)(2000), (Int32)(4), (Int32)(12));
		(*((TimeSpan*)x_array3->Address(0,1,3))) = TimeSpan((Int32)(2000), (Int32)(4), (Int32)(13));
		(*((TimeSpan*)x_array3->Address(1,0,0))) = TimeSpan((Int32)(2000), (Int32)(4), (Int32)(14));
		(*((TimeSpan*)x_array3->Address(1,0,1))) = TimeSpan((Int32)(2000), (Int32)(4), (Int32)(15));
		(*((TimeSpan*)x_array3->Address(1,0,2))) = TimeSpan((Int32)(2000), (Int32)(4), (Int32)(16));
		(*((TimeSpan*)x_array3->Address(1,0,3))) = TimeSpan((Int32)(2000), (Int32)(4), (Int32)(17));
		(*((TimeSpan*)x_array3->Address(1,1,0))) = TimeSpan((Int32)(2000), (Int32)(4), (Int32)(18));
		(*((TimeSpan*)x_array3->Address(1,1,1))) = TimeSpan((Int32)(2000), (Int32)(4), (Int32)(19));
		(*((TimeSpan*)x_array3->Address(1,1,2))) = TimeSpan((Int32)(2000), (Int32)(4), (Int32)(20));
		(*((TimeSpan*)x_array3->Address(1,1,3))) = TimeSpan((Int32)(2000), (Int32)(4), (Int32)(21));
		this->CxAssert((Boolean)(TimeSpanValue::Equals((TimeSpan)((*((TimeSpan*)x_array3->Address(0,0,3)))), (TimeSpan)(TimeSpan((Int32)(2000), (Int32)(4), (Int32)(9))))));
		(*((TimeSpan*)x_array3->Address(0,0,3))) = TimeSpan((Int32)(2000), (Int32)(4), (Int32)(27));
		this->CxAssert((Boolean)(TimeSpanValue::Equals((TimeSpan)((*((TimeSpan*)x_array3->Address(0,0,3)))), (TimeSpan)(TimeSpan((Int32)(2000), (Int32)(4), (Int32)(27))))));
		x_array3->SetValue((new TimeSpanValue(TimeSpan((Int32)(2000), (Int32)(4), (Int32)(28)))), (Int32)(0), (Int32)(0), (Int32)(3));
		this->CxAssert((Boolean)(TimeSpanValue::Equals((TimeSpan)((*((TimeSpan*)x_array3->Address(0,0,3)))), (TimeSpan)(TimeSpan((Int32)(2000), (Int32)(4), (Int32)(28))))));
		TimeSpan x_t = (*((TimeSpan*)x_array->Address(2))) = TimeSpan((Int32)(2000), (Int32)(4), (Int32)(27));
		this->CxAssert((Boolean)(TimeSpanValue::Equals((TimeSpan)((*((TimeSpan*)x_array->Address(2)))), (TimeSpan)(x_t))));
		return;
	}
	void TimeTest::CxAssert(Double x_x,Double x_y)
	{
IL_0000:
		if (((Math::Abs((Double)((x_x - x_y)))) > 1E-05))
		{
			this->x_caBlock->TestFailed((new String(L"Time TestFailed")));
		}

		return;
	}
	void TimeTest::CxAssert(Boolean x_x)
	{
IL_0000:
		if (((x_x) == 0))
		{
			this->TimeTestFailed();
		}

		return;
	}
	void TimeTest::TimeTestFailed()
	{
IL_0000:
		this->x_caBlock->TestFailed((new String(L"Time TestFailed")));
		return;
	}
	TimingTest::TimingTest()
	{
IL_0000:
		
		return;
	}
	Int32 TimingTest::DoTimingTest(Int32 x_a,Int32 x_b,Int32 x_c)
	{
IL_0000:
		Int32 x_result = 0;
		Int32 x_i = 0;
		
		{
IL_0021:
			if (((x_i) < x_a))
			{
				goto IL_0008;
			}
			else
			{
				goto leaveBlock2;
			}

		}
		{
IL_0008:
			Int32 x_j = 0;
			
			{
IL_0015:
				if (((x_j) < x_b))
				{
					goto IL_0010;
				}
				else
				{
					goto leaveBlock3;
				}

			}
			{
IL_0010:
				x_result = ((x_i * x_j) + x_c);
				goto IL_0014;
			}
			{
IL_0014:
				++x_j;
				goto IL_0015;
			}
leaveBlock3:

			goto IL_0020;
		}
		{
IL_0020:
			++x_i;
			goto IL_0021;
		}
leaveBlock2:

		return((Int32)x_result);
	}
	TestException::TestException() : Exception ((new String(L"Test Exception")))
	{
IL_0000:
		
		return;
	}
	TestException::TestException(String* x_msg) : Exception (x_msg)
	{
IL_0000:
		
		return;
	}
	TestException::TestException(String* x_msg,Exception* x_baseException) : Exception (x_msg,x_baseException)
	{
IL_0000:
		
		return;
	}
	void TryCatchTest::Test()
	{
IL_0000:
		this->DoSimpleTryCatch();
		this->DoComplexTryCatch();
		return;
	}
	void TryCatchTest::DoSimpleTryCatch()
	{
IL_0000:
		try
		{
IL_0001:
			Exception* x_baseException = (new TestException((new String(L"Test1"))));
			throw ((new TestException((new String(L"Test2")), x_baseException)));
		}
		catch (TestException* x_ex)
		{
IL_0019:
			if (((x_ex) == nullptr))
			{
				this->ExceptionTestFailed();
			}

			if (String::op_Inequality((new String(L"Test2")), x_ex->get_Message()))
			{
				this->ExceptionTestFailed();
			}

			if (String::op_Inequality((new String(L"Test1")), x_ex->get_InnerException()->get_Message()))
			{
				this->ExceptionTestFailed();
			}

			if (((String::op_Inequality((new String(L"Test1")), x_ex->GetBaseException()->get_Message())) == 0))
			{
				return;
			}

			this->ExceptionTestFailed();
			goto leaveBlock2;
		}
leaveBlock2:;

		this->ExceptionTestFailed();
		return;
	}
	void TryCatchTest::DoComplexTryCatch()
	{
IL_0000:
		Int32 x_num = 0;
		try
		{
IL_0003:
			try
			{
IL_0004:
				++x_num;
				throw ((new TestException()));
			}
			catch (TestException* x_ex)
			{
IL_000f:
				++x_num;
				throw;
			}
leaveBlock4:;

		}
		catch (TestException* x_ex2)
		{
IL_0017:
			++x_num;
			goto leaveBlock2;
		}
		catch (Exception* x_ex3)
		{
IL_0020:
			++x_num;
			goto leaveBlock2;
		}
leaveBlock2:;

		if (((x_num) != 3))
		{
			this->ExceptionTestFailed();
		}

		return;
	}
	void TryCatchTest::ExceptionTestFailed()
	{
IL_0000:
		throw ((new Exception((new String(L"Exception TestFailed")))));
	}
	void TryCatchTest::CxAssert(Boolean x_x)
	{
IL_0000:
		if (((x_x) == 0))
		{
			this->ExceptionTestFailed();
		}

		return;
	}
	UInt16Test::UInt16Test(CABlock* x_caBlock)
	{
IL_0000:
		
		this->x_caBlock = x_caBlock;
		return;
	}
	void UInt16Test::Test()
	{
IL_0000:
		this->x_caBlock->Send((new String(L"Doing UInt16Test")));
		this->x_caBlock->Send((new String(L"\tDoing UInt16MethodsTest")));
		this->UInt16MethodsTest();
		this->x_caBlock->Send((new String(L"\tDoing DoUnSignedMath")));
		this->DoUnSignedMath();
		this->x_caBlock->Send((new String(L"\tDoing UInt16Operators")));
		this->UInt16Operators();
		this->x_caBlock->Send((new String(L"\tDoing UInt16ArrayTest")));
		this->UInt16ArrayTest();
		this->x_caBlock->Send((new String(L"\tDoing UInt16MiscTests")));
		this->UInt16MiscTests();
		return;
	}
	void UInt16Test::UInt16MethodsTest()
	{
IL_0000:
		UInt16 x_num = 5;
		this->CxAssert((Boolean)(((UInt16Value(x_num).CompareTo((UInt16)(5))) == 0)));
		this->CxAssert((Boolean)(((UInt16Value(x_num).CompareTo((new UInt16Value(5)))) == 0)));
		this->CxAssert((Boolean)(UInt16Value(x_num).Equals((UInt16)(5))));
		this->CxAssert((Boolean)(UInt16Value(x_num).Equals((new UInt16Value(5)))));
		this->CxAssert((Boolean)(((UInt16Value::Parse((new String(L"77")))) == 77)));
		this->CxAssert((Boolean)(String::Equals((new String(L"5")), UInt16Value(x_num).ToString())));
		x_num = UInt16Value::MaxValue;
		this->CxAssert((Boolean)(((UInt16Value::MaxValue) == x_num)));
		x_num = 0;
		this->CxAssert((Boolean)(((x_num) == 0)));
		String* x_text = UInt16Value((UInt16Value::MaxValue)).ToString();
		this->CxAssert((Boolean)(String::Equals(x_text, (new String(L"65535")))));
		this->CxAssert((Boolean)(((UInt16Value::Parse(x_text)) == UInt16Value::MaxValue)));
		String* x_text2 = UInt16Value((0)).ToString();
		this->CxAssert((Boolean)(String::Equals(x_text2, (new String(L"0")))));
		this->CxAssert((Boolean)(((UInt16Value::Parse(x_text2)) == 0)));
		Object* x_obj = (new UInt16Value(5));
		this->CxAssert((Boolean)(x_obj->Equals((new UInt16Value(5)))));
		this->CxAssert((Boolean)(String::Equals(x_obj->ToString(), (new String(L"5")))));
		return;
	}
	void UInt16Test::DoUnSignedMath()
	{
IL_0000:
		UInt16 x_num = 600;
		UInt16 x_num2 = 1200;
		Int32 x_num3 = 1;
		this->CxAssert((Boolean)(((1) <= x_num)));
		this->CxAssert((Boolean)(((x_num) >= 1)));
		this->CxAssert((Boolean)(((x_num) >= x_num3)));
		this->CxAssert((Boolean)(((x_num3) <= x_num)));
		x_num3 = (x_num3 + x_num);
		this->CxAssert((Boolean)(((x_num3) == 601)));
		this->CxAssert((Boolean)((((x_num + x_num2)) == 1800)));
		this->CxAssert((Boolean)((((x_num - x_num2)) == -600)));
		this->CxAssert((Boolean)((((x_num * x_num2)) == 720000)));
		this->CxAssert((Boolean)((((x_num2 / x_num)) == 2)));
		this->CxAssert((Boolean)((((x_num >> 2)) == 150)));
		this->CxAssert((Boolean)((((x_num << 1)) == 1200)));
		Int32 x_num4 = 11;
		this->CxAssert((Boolean)((((x_num4 % 5)) == 1)));
		x_num4 = 8;
		this->CxAssert((Boolean)((((x_num4 | 1)) == 9)));
		this->CxAssert((Boolean)((((x_num4 & 1)) == 0)));
		this->CxAssert((Boolean)(((++x_num4) == 9)));
		this->CxAssert((Boolean)(((--x_num4) == 8)));
		this->CxAssert((Boolean)(((x_num4 = (x_num4 * 2)) == 16)));
		this->CxAssert((Boolean)(((x_num4 = (x_num4 / 2)) == 8)));
		this->CxAssert((Boolean)(((x_num4 = (x_num4 % 2)) == 0)));
		this->CxAssert((Boolean)(((x_num4 = (x_num4 | 4)) == 4)));
		this->CxAssert((Boolean)(((x_num4 = (x_num4 & 4)) == 4)));
		this->CxAssert((Boolean)((((0 - x_num)) == -600)));
		this->CxAssert((Boolean)(((x_num) == 600)));
		UInt32 x_num5 = 0;
		this->CxAssert((Boolean)(((~x_num5) == -1)));
		this->CxAssert((Boolean)(((++x_num5) == 1)));
		this->CxAssert((Boolean)(((--x_num5) == 0)));
		return;
	}
	void UInt16Test::UInt16Operators()
	{
IL_0000:
		UInt16 x_num = 66;
		Char x_c = 1;
		Int32 x_num2 = 1;
		UInt16 x_num3 = 1;
		Int64 x_num4 = ((Int64)1);
		Double x_num5 = 1;
		this->CxAssert((Boolean)(((x_num) == 66)));
		this->CxAssert((Boolean)((((x_num + x_c)) == 67)));
		this->CxAssert((Boolean)((((x_num + x_num2)) == 67)));
		this->CxAssert((Boolean)((((x_num + x_num3)) == 67)));
		this->CxAssert((Boolean)((((((UInt64)x_num) + x_num4)) == ((Int64)67))));
		this->CxAssert((Boolean)((((((Double)x_num) + x_num5)) == 67)));
		this->CxAssert((Boolean)((((x_num - x_c)) == 65)));
		this->CxAssert((Boolean)((((x_num - x_num2)) == 65)));
		this->CxAssert((Boolean)((((x_num - x_num3)) == 65)));
		this->CxAssert((Boolean)((((((UInt64)x_num) - x_num4)) == ((Int64)65))));
		this->CxAssert((Boolean)((((((Double)x_num) - x_num5)) == 65)));
		this->CxAssert((Boolean)((((x_num * x_c)) == 66)));
		this->CxAssert((Boolean)((((x_num * x_num2)) == 66)));
		this->CxAssert((Boolean)((((x_num * x_num3)) == 66)));
		this->CxAssert((Boolean)((((((UInt64)x_num) * x_num4)) == ((Int64)66))));
		this->CxAssert((Boolean)((((((Double)x_num) * x_num5)) == 66)));
		this->CxAssert((Boolean)((((x_num / x_c)) == 66)));
		this->CxAssert((Boolean)((((x_num / x_num2)) == 66)));
		this->CxAssert((Boolean)((((x_num / x_num3)) == 66)));
		this->CxAssert((Boolean)((((((UInt64)x_num) / x_num4)) == ((Int64)66))));
		this->CxAssert((Boolean)((((((Double)x_num) / x_num5)) == 66)));
		this->CxAssert((Boolean)((((x_num % x_c)) == 0)));
		this->CxAssert((Boolean)((((x_num % x_num2)) == 0)));
		this->CxAssert((Boolean)((((x_num % x_num3)) == 0)));
		this->CxAssert((Boolean)((((((UInt64)x_num) % x_num4)) == ((Int64)0))));
		this->CxAssert((Boolean)(((DoubleValue::Modulus(((Double)x_num),x_num5)) == 0)));
		this->CxAssert((Boolean)((((x_num & x_c)) == 0)));
		this->CxAssert((Boolean)((((x_num & x_num2)) == 0)));
		this->CxAssert((Boolean)((((x_num & x_num3)) == 0)));
		this->CxAssert((Boolean)((((((UInt64)x_num) & x_num4)) == ((Int64)0))));
		this->CxAssert((Boolean)((((x_num | x_c)) == 67)));
		this->CxAssert((Boolean)((((x_num | x_num3)) == 67)));
		this->CxAssert((Boolean)((((((UInt64)x_num) | x_num4)) == ((Int64)67))));
		this->CxAssert((Boolean)((((x_num ^ x_c)) == 67)));
		this->CxAssert((Boolean)((((x_num ^ x_num2)) == 67)));
		this->CxAssert((Boolean)((((x_num ^ x_num3)) == 67)));
		this->CxAssert((Boolean)((((((UInt64)x_num) ^ x_num4)) == ((Int64)67))));
		this->CxAssert((Boolean)(((~x_num) == -67)));
		this->CxAssert((Boolean)(((x_c) < x_num)));
		this->CxAssert((Boolean)(((x_num2) < x_num)));
		this->CxAssert((Boolean)(((x_num3) < x_num)));
		this->CxAssert((Boolean)(((x_num4) < ((UInt64)x_num))));
		this->CxAssert((Boolean)(((x_num5) < ((Double)x_num))));
		this->CxAssert((Boolean)(((x_c) > x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num2) > x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num3) > x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num4) > ((UInt64)x_num))), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num5) > ((Double)x_num))), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num = ((UInt16)(x_num + 1))) == 67)));
		this->CxAssert((Boolean)(((x_num = ((UInt16)(x_num - 1))) == 66)));
		this->CxAssert((Boolean)(((x_num++) == 66)));
		this->CxAssert((Boolean)(((x_num--) == 67)));
		this->CxAssert((Boolean)((((x_num << 1)) == 132)));
		this->CxAssert((Boolean)((((x_num >> 1)) == 33)));
		this->CxAssert((Boolean)(((x_c) == x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num2) == x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num3) == x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num4) == ((UInt64)x_num))), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num5) == ((Double)x_num))), (Boolean)(0));
		this->CxAssert((Boolean)(((x_c) != x_num)));
		this->CxAssert((Boolean)(((x_num2) != x_num)));
		this->CxAssert((Boolean)(((x_num3) != x_num)));
		this->CxAssert((Boolean)(((x_num4) != ((UInt64)x_num))));
		this->CxAssert((Boolean)(((x_num5) != ((Double)x_num))));
		this->CxAssert((Boolean)(((x_c) <= x_num)));
		this->CxAssert((Boolean)(((x_num2) <= x_num)));
		this->CxAssert((Boolean)(((x_num3) <= x_num)));
		this->CxAssert((Boolean)(((x_num4) <= ((UInt64)x_num))));
		this->CxAssert((Boolean)(((x_num5) <= ((Double)x_num))));
		this->CxAssert((Boolean)(((x_c) >= x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num2) >= x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num3) >= x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num4) >= ((UInt64)x_num))), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num5) >= ((Double)x_num))), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num = ((UInt16)(x_num + x_c))) == 67)));
		this->CxAssert((Boolean)(((x_num = ((UInt16)(x_num - x_c))) == 66)));
		this->CxAssert((Boolean)(((x_num = ((UInt16)(x_num + x_num3))) == 67)));
		this->CxAssert((Boolean)(((x_num = ((UInt16)(x_num - x_num3))) == 66)));
		this->CxAssert((Boolean)(((x_num = ((UInt16)(x_num * x_c))) == 66)));
		this->CxAssert((Boolean)(((x_num = ((UInt16)(x_num / x_c))) == 66)));
		this->CxAssert((Boolean)(((x_num = ((UInt16)(x_num * x_num3))) == 66)));
		this->CxAssert((Boolean)(((x_num = ((UInt16)(x_num / x_num3))) == 66)));
		this->CxAssert((Boolean)(((x_num = ((UInt16)(x_num % x_c))) == 0)));
		x_num = 66;
		this->CxAssert((Boolean)(((x_num = ((UInt16)(x_num % x_num3))) == 0)));
		x_num = 66;
		this->CxAssert((Boolean)(((x_num = ((UInt16)(x_num & x_c))) == 0)));
		x_num = 66;
		this->CxAssert((Boolean)(((x_num = ((UInt16)(x_num & x_num3))) == 0)));
		x_num = 66;
		this->CxAssert((Boolean)(((x_num = ((UInt16)(x_num | x_c))) == 67)));
		x_num = 66;
		this->CxAssert((Boolean)(((x_num = ((UInt16)(x_num | x_num3))) == 67)));
		x_num = 66;
		this->CxAssert((Boolean)(((x_num = ((UInt16)(x_num ^ x_c))) == 67)));
		x_num = 66;
		this->CxAssert((Boolean)(((x_num = ((UInt16)(x_num ^ x_num3))) == 67)));
		x_num = 66;
		this->CxAssert((Boolean)(((x_num = ((UInt16)(x_num << x_c))) == 132)));
		x_num = 66;
		this->CxAssert((Boolean)(((x_num = ((UInt16)(x_num << x_num2))) == 132)));
		x_num = 66;
		this->CxAssert((Boolean)(((x_num = ((UInt16)(x_num >> x_c))) == 33)));
		x_num = 66;
		this->CxAssert((Boolean)(((x_num = ((UInt16)(x_num >> x_num2))) == 33)));
		x_num = 66;
		return;
	}
	void UInt16Test::UInt16ArrayTest()
	{
IL_0000:
		Array* x_array = new Array(UInt16Type,5);
		(*((UInt16*)x_array->Address(0))) = 1;
		(*((UInt16*)x_array->Address(1))) = 2;
		(*((UInt16*)x_array->Address(2))) = 3;
		(*((UInt16*)x_array->Address(3))) = 4;
		(*((UInt16*)x_array->Address(4))) = 5;
		this->CxAssert((Boolean)(((x_array->get_Length()) == 5)));
		this->CxAssert((Boolean)((((*((UInt16*)x_array->Address(3)))) == 4)));
		Array* x_array2 = new Array(UInt16Type,4);
		(*((UInt16*)x_array2->Address(0))) = 1;
		(*((UInt16*)x_array2->Address(1))) = 2;
		(*((UInt16*)x_array2->Address(2))) = 3;
		(*((UInt16*)x_array2->Address(3))) = 4;
		this->CxAssert((Boolean)((((*((UInt16*)x_array2->Address(1)))) == 2)));
		Array* x_array3 = new Array(UInt16Type,2,4);
		(*((UInt16*)x_array3->Address(0,0))) = 1;
		(*((UInt16*)x_array3->Address(0,1))) = 2;
		(*((UInt16*)x_array3->Address(0,2))) = 3;
		(*((UInt16*)x_array3->Address(0,3))) = 4;
		(*((UInt16*)x_array3->Address(1,0))) = 4;
		(*((UInt16*)x_array3->Address(1,1))) = 5;
		(*((UInt16*)x_array3->Address(1,2))) = 6;
		(*((UInt16*)x_array3->Address(1,3))) = 7;
		this->CxAssert((Boolean)((((*((UInt16*)x_array3->Address(0,2)))) == 3)));
		Array* x_array4 = new Array(UInt16Type,2,2,4);
		(*((UInt16*)x_array4->Address(0,0,0))) = 1;
		(*((UInt16*)x_array4->Address(0,0,1))) = 2;
		(*((UInt16*)x_array4->Address(0,0,2))) = 3;
		(*((UInt16*)x_array4->Address(0,0,3))) = 4;
		(*((UInt16*)x_array4->Address(0,1,0))) = 5;
		(*((UInt16*)x_array4->Address(0,1,1))) = 6;
		(*((UInt16*)x_array4->Address(0,1,2))) = 7;
		(*((UInt16*)x_array4->Address(0,1,3))) = 8;
		(*((UInt16*)x_array4->Address(1,0,0))) = 9;
		(*((UInt16*)x_array4->Address(1,0,1))) = 10;
		(*((UInt16*)x_array4->Address(1,0,2))) = 11;
		(*((UInt16*)x_array4->Address(1,0,3))) = 12;
		(*((UInt16*)x_array4->Address(1,1,0))) = 13;
		(*((UInt16*)x_array4->Address(1,1,1))) = 14;
		(*((UInt16*)x_array4->Address(1,1,2))) = 15;
		(*((UInt16*)x_array4->Address(1,1,3))) = 16;
		this->CxAssert((Boolean)((((*((UInt16*)x_array4->Address(0,0,3)))) == 4)));
		(*((UInt16*)x_array4->Address(0,0,3))) = 6;
		this->CxAssert((Boolean)((((*((UInt16*)x_array4->Address(0,0,3)))) == 6)));
		x_array4->SetValue((new UInt16Value(4)), (Int32)(0), (Int32)(0), (Int32)(3));
		this->CxAssert((Boolean)((((*((UInt16*)x_array4->Address(0,0,3)))) == 4)));
		return;
	}
	void UInt16Test::UInt16MiscTests()
	{
IL_0000:
		UInt16 x_num = 0;
		UInt16 x_num2 = 1;
		this->CxAssert((Boolean)(((Math::Max((UInt16)(x_num), (UInt16)(x_num2))) == 1)));
		this->CxAssert((Boolean)(((Math::Min((UInt16)(x_num), (UInt16)(x_num2))) == 0)));
		StringBuilder* x_stringBuilder = (new StringBuilder());
		x_stringBuilder->Append((UInt16)(x_num2));
		this->CxAssert((Boolean)(String::Equals(x_stringBuilder->ToString(), (new String(L"1")))));
		x_stringBuilder->Insert((Int32)(1), (UInt16)(x_num));
		this->CxAssert((Boolean)(String::Equals(x_stringBuilder->ToString(), (new String(L"10")))));
		return;
	}
	void UInt16Test::CxAssert(Boolean x_x)
	{
IL_0000:
		if (((x_x) == 0))
		{
			this->x_caBlock->TestFailed((new String(L"UInt16 TestFailed")));
		}

		return;
	}
	void UInt16Test::CxAssert(Boolean x_x,Boolean x_y)
	{
IL_0000:
		if (((x_x) != x_y))
		{
			this->x_caBlock->TestFailed((new String(L"UInt16 TestFailed")));
		}

		return;
	}
	UInt32Test::UInt32Test(CABlock* x_caBlock)
	{
IL_0000:
		
		this->x_caBlock = x_caBlock;
		return;
	}
	void UInt32Test::Test()
	{
IL_0000:
		this->x_caBlock->Send((new String(L"Doing UInt32Test")));
		this->x_caBlock->Send((new String(L"\tDoing UInt32MethodsTest")));
		this->UInt32MethodsTest();
		this->x_caBlock->Send((new String(L"\tDoing DoUnSignedMath")));
		this->DoUnSignedMath();
		this->x_caBlock->Send((new String(L"\tDoing UInt32Operators")));
		this->UInt32Operators();
		this->x_caBlock->Send((new String(L"\tDoing UInt32ArrayTest")));
		this->UInt32ArrayTest();
		this->x_caBlock->Send((new String(L"\tDoing UInt32MiscTests")));
		this->UInt32MiscTests();
		return;
	}
	void UInt32Test::UInt32MethodsTest()
	{
IL_0000:
		UInt32 x_num = 5;
		this->CxAssert((Boolean)(((UInt32Value(x_num).CompareTo((UInt32)(5))) == 0)));
		this->CxAssert((Boolean)(((UInt32Value(x_num).CompareTo((new UInt32Value(5)))) == 0)));
		this->CxAssert((Boolean)(UInt32Value(x_num).Equals((UInt32)(5))));
		this->CxAssert((Boolean)(UInt32Value(x_num).Equals((new UInt32Value(5)))));
		this->CxAssert((Boolean)(((UInt32Value::Parse((new String(L"77")))) == 77)));
		this->CxAssert((Boolean)(String::Equals((new String(L"5")), UInt32Value(x_num).ToString())));
		x_num = -1;
		this->CxAssert((Boolean)(((-1) == x_num)));
		x_num = 0;
		this->CxAssert((Boolean)(((x_num) == 0)));
		String* x_text = UInt32Value((-1)).ToString();
		this->CxAssert((Boolean)(String::Equals(x_text, (new String(L"4294967295")))));
		this->CxAssert((Boolean)(((UInt32Value::Parse(x_text)) == -1)));
		String* x_text2 = UInt32Value((0)).ToString();
		this->CxAssert((Boolean)(String::Equals(x_text2, (new String(L"0")))));
		this->CxAssert((Boolean)(((UInt32Value::Parse(x_text2)) == 0)));
		Object* x_obj = (new UInt32Value(5));
		this->CxAssert((Boolean)(x_obj->Equals((new UInt32Value(5)))));
		this->CxAssert((Boolean)(String::Equals(x_obj->ToString(), (new String(L"5")))));
		return;
	}
	void UInt32Test::DoUnSignedMath()
	{
IL_0000:
		UInt32 x_num = 60000;
		UInt32 x_num2 = 120000;
		Int32 x_num3 = 1;
		this->CxAssert((Boolean)(((1) <= x_num)));
		this->CxAssert((Boolean)(((x_num) >= 1)));
		this->CxAssert((Boolean)(((((UInt64)x_num)) >= ((Int64)x_num3))));
		this->CxAssert((Boolean)(((((Int64)x_num3)) <= ((UInt64)x_num))));
		x_num3 = (x_num3 + x_num);
		this->CxAssert((Boolean)(((x_num3) == 60001)));
		this->CxAssert((Boolean)((((x_num + x_num2)) == 180000)));
		this->CxAssert((Boolean)((((x_num - x_num2)) == -60000)));
		this->CxAssert((Boolean)((((x_num * x_num2)) == -1389934592)));
		this->CxAssert((Boolean)((((x_num2 / x_num)) == 2)));
		this->CxAssert((Boolean)((((x_num >> 2)) == 15000)));
		this->CxAssert((Boolean)((((x_num << 1)) == 120000)));
		Int32 x_num4 = 11;
		this->CxAssert((Boolean)((((x_num4 % 5)) == 1)));
		x_num4 = 8;
		this->CxAssert((Boolean)((((x_num4 | 1)) == 9)));
		this->CxAssert((Boolean)((((x_num4 & 1)) == 0)));
		this->CxAssert((Boolean)(((++x_num4) == 9)));
		this->CxAssert((Boolean)(((--x_num4) == 8)));
		this->CxAssert((Boolean)(((x_num4 = (x_num4 * 2)) == 16)));
		this->CxAssert((Boolean)(((x_num4 = (x_num4 / 2)) == 8)));
		this->CxAssert((Boolean)(((x_num4 = (x_num4 % 2)) == 0)));
		this->CxAssert((Boolean)(((x_num4 = (x_num4 | 4)) == 4)));
		this->CxAssert((Boolean)(((x_num4 = (x_num4 & 4)) == 4)));
		this->CxAssert((Boolean)((((0 - ((UInt64)x_num))) == ((Int64)-60000))));
		this->CxAssert((Boolean)(((x_num) == 60000)));
		UInt32 x_num5 = 0;
		this->CxAssert((Boolean)(((~x_num5) == -1)));
		this->CxAssert((Boolean)(((++x_num5) == 1)));
		this->CxAssert((Boolean)(((--x_num5) == 0)));
		return;
	}
	void UInt32Test::UInt32Operators()
	{
IL_0000:
		UInt32 x_num = 66;
		Char x_c = 1;
		Int32 x_num2 = 1;
		UInt32 x_num3 = 1;
		Int64 x_num4 = ((Int64)1);
		Double x_num5 = 1;
		this->CxAssert((Boolean)(((x_num) == 66)));
		this->CxAssert((Boolean)((((x_num + x_c)) == 67)));
		this->CxAssert((Boolean)((((((UInt64)x_num) + ((Int64)x_num2))) == ((Int64)67))));
		this->CxAssert((Boolean)((((x_num + x_num3)) == 67)));
		this->CxAssert((Boolean)((((((UInt64)x_num) + x_num4)) == ((Int64)67))));
		this->CxAssert((Boolean)((((((Double)x_num) + x_num5)) == 67)));
		this->CxAssert((Boolean)((((x_num - x_c)) == 65)));
		this->CxAssert((Boolean)((((((UInt64)x_num) - ((Int64)x_num2))) == ((Int64)65))));
		this->CxAssert((Boolean)((((x_num - x_num3)) == 65)));
		this->CxAssert((Boolean)((((((UInt64)x_num) - x_num4)) == ((Int64)65))));
		this->CxAssert((Boolean)((((((Double)x_num) - x_num5)) == 65)));
		this->CxAssert((Boolean)((((x_num * x_c)) == 66)));
		this->CxAssert((Boolean)((((((UInt64)x_num) * ((Int64)x_num2))) == ((Int64)66))));
		this->CxAssert((Boolean)((((x_num * x_num3)) == 66)));
		this->CxAssert((Boolean)((((((UInt64)x_num) * x_num4)) == ((Int64)66))));
		this->CxAssert((Boolean)((((((Double)x_num) * x_num5)) == 66)));
		this->CxAssert((Boolean)((((x_num / x_c)) == 66)));
		this->CxAssert((Boolean)((((((UInt64)x_num) / ((Int64)x_num2))) == ((Int64)66))));
		this->CxAssert((Boolean)((((x_num / x_num3)) == 66)));
		this->CxAssert((Boolean)((((((UInt64)x_num) / x_num4)) == ((Int64)66))));
		this->CxAssert((Boolean)((((((Double)x_num) / x_num5)) == 66)));
		this->CxAssert((Boolean)((((x_num % x_c)) == 0)));
		this->CxAssert((Boolean)((((((UInt64)x_num) % ((Int64)x_num2))) == ((Int64)0))));
		this->CxAssert((Boolean)((((x_num % x_num3)) == 0)));
		this->CxAssert((Boolean)((((((UInt64)x_num) % x_num4)) == ((Int64)0))));
		this->CxAssert((Boolean)(((DoubleValue::Modulus(((Double)x_num),x_num5)) == 0)));
		this->CxAssert((Boolean)((((x_num & x_c)) == 0)));
		this->CxAssert((Boolean)((((((UInt64)x_num) & ((Int64)x_num2))) == ((Int64)0))));
		this->CxAssert((Boolean)((((x_num & x_num3)) == 0)));
		this->CxAssert((Boolean)((((((UInt64)x_num) & x_num4)) == ((Int64)0))));
		this->CxAssert((Boolean)((((x_num | x_c)) == 67)));
		this->CxAssert((Boolean)((((x_num | x_num3)) == 67)));
		this->CxAssert((Boolean)((((((UInt64)x_num) | x_num4)) == ((Int64)67))));
		this->CxAssert((Boolean)((((x_num ^ x_c)) == 67)));
		this->CxAssert((Boolean)((((((UInt64)x_num) ^ ((Int64)x_num2))) == ((Int64)67))));
		this->CxAssert((Boolean)((((x_num ^ x_num3)) == 67)));
		this->CxAssert((Boolean)((((((UInt64)x_num) ^ x_num4)) == ((Int64)67))));
		this->CxAssert((Boolean)(((~x_num) == -67)));
		this->CxAssert((Boolean)(((x_c) < x_num)));
		this->CxAssert((Boolean)(((((Int64)x_num2)) < ((UInt64)x_num))));
		this->CxAssert((Boolean)(((x_num3) < x_num)));
		this->CxAssert((Boolean)(((x_num4) < ((UInt64)x_num))));
		this->CxAssert((Boolean)(((x_num5) < ((Double)x_num))));
		this->CxAssert((Boolean)(((x_c) > x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((((Int64)x_num2)) > ((UInt64)x_num))), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num3) > x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num4) > ((UInt64)x_num))), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num5) > ((Double)x_num))), (Boolean)(0));
		this->CxAssert((Boolean)(((++x_num) == 67)));
		this->CxAssert((Boolean)(((--x_num) == 66)));
		this->CxAssert((Boolean)(((x_num++) == 66)));
		this->CxAssert((Boolean)(((x_num--) == 67)));
		this->CxAssert((Boolean)((((x_num << 1)) == 132)));
		this->CxAssert((Boolean)((((x_num >> 1)) == 33)));
		this->CxAssert((Boolean)(((x_c) == x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((((Int64)x_num2)) == ((UInt64)x_num))), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num3) == x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num4) == ((UInt64)x_num))), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num5) == ((Double)x_num))), (Boolean)(0));
		this->CxAssert((Boolean)(((x_c) != x_num)));
		this->CxAssert((Boolean)(((((Int64)x_num2)) != ((UInt64)x_num))));
		this->CxAssert((Boolean)(((x_num3) != x_num)));
		this->CxAssert((Boolean)(((x_num4) != ((UInt64)x_num))));
		this->CxAssert((Boolean)(((x_num5) != ((Double)x_num))));
		this->CxAssert((Boolean)(((x_c) <= x_num)));
		this->CxAssert((Boolean)(((((Int64)x_num2)) <= ((UInt64)x_num))));
		this->CxAssert((Boolean)(((x_num3) <= x_num)));
		this->CxAssert((Boolean)(((x_num4) <= ((UInt64)x_num))));
		this->CxAssert((Boolean)(((x_num5) <= ((Double)x_num))));
		this->CxAssert((Boolean)(((x_c) >= x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((((Int64)x_num2)) >= ((UInt64)x_num))), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num3) >= x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num4) >= ((UInt64)x_num))), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num5) >= ((Double)x_num))), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num = (x_num + x_c)) == 67)));
		this->CxAssert((Boolean)(((x_num = (x_num - x_c)) == 66)));
		this->CxAssert((Boolean)(((x_num = (x_num + x_num3)) == 67)));
		this->CxAssert((Boolean)(((x_num = (x_num - x_num3)) == 66)));
		this->CxAssert((Boolean)(((x_num = (x_num * x_c)) == 66)));
		this->CxAssert((Boolean)(((x_num = (x_num / x_c)) == 66)));
		this->CxAssert((Boolean)(((x_num = (x_num * x_num3)) == 66)));
		this->CxAssert((Boolean)(((x_num = (x_num / x_num3)) == 66)));
		this->CxAssert((Boolean)(((x_num = (x_num % x_c)) == 0)));
		x_num = 66;
		this->CxAssert((Boolean)(((x_num = (x_num % x_num3)) == 0)));
		x_num = 66;
		this->CxAssert((Boolean)(((x_num = (x_num & x_c)) == 0)));
		x_num = 66;
		this->CxAssert((Boolean)(((x_num = (x_num & x_num3)) == 0)));
		x_num = 66;
		this->CxAssert((Boolean)(((x_num = (x_num | x_c)) == 67)));
		x_num = 66;
		this->CxAssert((Boolean)(((x_num = (x_num | x_num3)) == 67)));
		x_num = 66;
		this->CxAssert((Boolean)(((x_num = (x_num ^ x_c)) == 67)));
		x_num = 66;
		this->CxAssert((Boolean)(((x_num = (x_num ^ x_num3)) == 67)));
		x_num = 66;
		this->CxAssert((Boolean)(((x_num = (x_num << x_c)) == 132)));
		x_num = 66;
		this->CxAssert((Boolean)(((x_num = (x_num << x_num2)) == 132)));
		x_num = 66;
		this->CxAssert((Boolean)(((x_num = (x_num >> x_c)) == 33)));
		x_num = 66;
		this->CxAssert((Boolean)(((x_num = (x_num >> x_num2)) == 33)));
		x_num = 66;
		return;
	}
	void UInt32Test::UInt32ArrayTest()
	{
IL_0000:
		Array* x_array = new Array(UInt32Type,5);
		(*((UInt32*)x_array->Address(0))) = 1;
		(*((UInt32*)x_array->Address(1))) = 2;
		(*((UInt32*)x_array->Address(2))) = 3;
		(*((UInt32*)x_array->Address(3))) = 4;
		(*((UInt32*)x_array->Address(4))) = 5;
		this->CxAssert((Boolean)(((x_array->get_Length()) == 5)));
		this->CxAssert((Boolean)((((*((UInt32*)x_array->Address(3)))) == 4)));
		Array* x_array2 = new Array(UInt32Type,4);
		(*((UInt32*)x_array2->Address(0))) = 1;
		(*((UInt32*)x_array2->Address(1))) = 2;
		(*((UInt32*)x_array2->Address(2))) = 3;
		(*((UInt32*)x_array2->Address(3))) = 4;
		this->CxAssert((Boolean)((((*((UInt32*)x_array2->Address(1)))) == 2)));
		Array* x_array3 = new Array(UInt32Type,2,4);
		(*((UInt32*)x_array3->Address(0,0))) = 1;
		(*((UInt32*)x_array3->Address(0,1))) = 2;
		(*((UInt32*)x_array3->Address(0,2))) = 3;
		(*((UInt32*)x_array3->Address(0,3))) = 4;
		(*((UInt32*)x_array3->Address(1,0))) = 4;
		(*((UInt32*)x_array3->Address(1,1))) = 5;
		(*((UInt32*)x_array3->Address(1,2))) = 6;
		(*((UInt32*)x_array3->Address(1,3))) = 7;
		this->CxAssert((Boolean)((((*((UInt32*)x_array3->Address(0,2)))) == 3)));
		Array* x_array4 = new Array(UInt32Type,2,2,4);
		(*((UInt32*)x_array4->Address(0,0,0))) = 1;
		(*((UInt32*)x_array4->Address(0,0,1))) = 2;
		(*((UInt32*)x_array4->Address(0,0,2))) = 3;
		(*((UInt32*)x_array4->Address(0,0,3))) = 4;
		(*((UInt32*)x_array4->Address(0,1,0))) = 5;
		(*((UInt32*)x_array4->Address(0,1,1))) = 6;
		(*((UInt32*)x_array4->Address(0,1,2))) = 7;
		(*((UInt32*)x_array4->Address(0,1,3))) = 8;
		(*((UInt32*)x_array4->Address(1,0,0))) = 9;
		(*((UInt32*)x_array4->Address(1,0,1))) = 10;
		(*((UInt32*)x_array4->Address(1,0,2))) = 11;
		(*((UInt32*)x_array4->Address(1,0,3))) = 12;
		(*((UInt32*)x_array4->Address(1,1,0))) = 13;
		(*((UInt32*)x_array4->Address(1,1,1))) = 14;
		(*((UInt32*)x_array4->Address(1,1,2))) = 15;
		(*((UInt32*)x_array4->Address(1,1,3))) = 16;
		this->CxAssert((Boolean)((((*((UInt32*)x_array4->Address(0,0,3)))) == 4)));
		(*((UInt32*)x_array4->Address(0,0,3))) = 6;
		this->CxAssert((Boolean)((((*((UInt32*)x_array4->Address(0,0,3)))) == 6)));
		x_array4->SetValue((new UInt32Value(4)), (Int32)(0), (Int32)(0), (Int32)(3));
		this->CxAssert((Boolean)((((*((UInt32*)x_array4->Address(0,0,3)))) == 4)));
		return;
	}
	void UInt32Test::UInt32MiscTests()
	{
IL_0000:
		UInt32 x_val = 0;
		UInt32 x_num = 1;
		this->CxAssert((Boolean)(((Math::Max((UInt32)(x_val), (UInt32)(x_num))) == 1)));
		this->CxAssert((Boolean)(((Math::Min((UInt32)(x_val), (UInt32)(x_num))) == 0)));
		StringBuilder* x_stringBuilder = (new StringBuilder());
		x_stringBuilder->Append((UInt32)(x_num));
		this->CxAssert((Boolean)(String::Equals(x_stringBuilder->ToString(), (new String(L"1")))));
		return;
	}
	void UInt32Test::CxAssert(Boolean x_x)
	{
IL_0000:
		if (((x_x) == 0))
		{
			this->x_caBlock->TestFailed((new String(L"UInt32 TestFailed")));
		}

		return;
	}
	void UInt32Test::CxAssert(Boolean x_x,Boolean x_y)
	{
IL_0000:
		if (((x_x) != x_y))
		{
			this->x_caBlock->TestFailed((new String(L"UInt32 TestFailed")));
		}

		return;
	}
	UInt64Test::UInt64Test(CABlock* x_caBlock)
	{
IL_0000:
		
		this->x_caBlock = x_caBlock;
		return;
	}
	void UInt64Test::Test()
	{
IL_0000:
		this->x_caBlock->Send((new String(L"Doing UInt64Test")));
		this->x_caBlock->Send((new String(L"\tDoing UInt64MethodsTest")));
		this->UInt64MethodsTest();
		this->x_caBlock->Send((new String(L"\tDoing UInt64UnSignedMath")));
		this->UInt64UnSignedMath();
		this->x_caBlock->Send((new String(L"\tDoing UInt64Operators")));
		this->UInt64Operators();
		this->x_caBlock->Send((new String(L"\tDoing UInt64ArrayTest")));
		this->UInt64ArrayTest();
		this->x_caBlock->Send((new String(L"\tDoing UInt64MiscTests")));
		this->UInt64MiscTests();
		return;
	}
	void UInt64Test::UInt64MethodsTest()
	{
IL_0000:
		UInt64 x_num = ((Int64)5);
		this->CxAssert((Boolean)(((UInt64Value(x_num).CompareTo((UInt64)(((Int64)5)))) == 0)));
		this->CxAssert((Boolean)(((UInt64Value(x_num).CompareTo((new UInt64Value(((Int64)5))))) == 0)));
		this->CxAssert((Boolean)(UInt64Value(x_num).Equals((UInt64)(((Int64)5)))));
		this->CxAssert((Boolean)(UInt64Value(x_num).Equals((new UInt64Value(((Int64)5))))));
		this->CxAssert((Boolean)(((UInt64Value::Parse((new String(L"77")))) == ((Int64)77))));
		this->CxAssert((Boolean)(String::Equals((new String(L"5")), UInt64Value(x_num).ToString())));
		x_num = ((Int64)-1);
		this->CxAssert((Boolean)(((((Int64)-1)) == x_num)));
		x_num = ((Int64)0);
		this->CxAssert((Boolean)(((x_num) == ((Int64)0))));
		String* x_text = UInt64Value((((Int64)-1))).ToString();
		this->CxAssert((Boolean)(String::Equals(x_text, (new String(L"18446744073709551615")))));
		this->CxAssert((Boolean)(((UInt64Value::Parse(x_text)) == ((Int64)-1))));
		String* x_text2 = UInt64Value((((Int64)0))).ToString();
		this->CxAssert((Boolean)(String::Equals(x_text2, (new String(L"0")))));
		this->CxAssert((Boolean)(((UInt64Value::Parse(x_text2)) == ((Int64)0))));
		Object* x_obj = (new UInt64Value(((Int64)5)));
		this->CxAssert((Boolean)(x_obj->Equals((new UInt64Value(((Int64)5))))));
		this->CxAssert((Boolean)(String::Equals(x_obj->ToString(), (new String(L"5")))));
		return;
	}
	void UInt64Test::UInt64UnSignedMath()
	{
IL_0000:
		UInt64 x_num = ((Int64)60000);
		UInt64 x_num2 = ((Int64)120000);
		UInt64 x_num3 = ((Int64)1);
		this->CxAssert((Boolean)(((((Int64)1)) <= x_num)));
		this->CxAssert((Boolean)(((x_num) >= ((Int64)1))));
		this->CxAssert((Boolean)(((x_num) >= x_num3)));
		this->CxAssert((Boolean)(((x_num3) <= x_num)));
		x_num3 = (x_num3 + x_num);
		this->CxAssert((Boolean)(((x_num3) == ((Int64)60001))));
		this->CxAssert((Boolean)((((x_num + x_num2)) == ((Int64)180000))));
		UInt64 x_num4 = (x_num - x_num2);
		this->CxAssert((Boolean)((((x_num - x_num2)) == ((Int64)-60000))));
		UInt64 x_num5 = (x_num * x_num2);
		this->CxAssert((Boolean)((((x_num * x_num2)) == 7200000000)));
		this->CxAssert((Boolean)((((x_num2 / x_num)) == ((Int64)2))));
		this->CxAssert((Boolean)((((x_num >> 2)) == ((Int64)15000))));
		this->CxAssert((Boolean)((((x_num << 1)) == ((Int64)120000))));
		Int32 x_num6 = 11;
		this->CxAssert((Boolean)((((x_num6 % 5)) == 1)));
		x_num6 = 8;
		this->CxAssert((Boolean)((((x_num6 | 1)) == 9)));
		this->CxAssert((Boolean)((((x_num6 & 1)) == 0)));
		this->CxAssert((Boolean)(((++x_num6) == 9)));
		this->CxAssert((Boolean)(((--x_num6) == 8)));
		this->CxAssert((Boolean)(((x_num6 = (x_num6 * 2)) == 16)));
		this->CxAssert((Boolean)(((x_num6 = (x_num6 / 2)) == 8)));
		this->CxAssert((Boolean)(((x_num6 = (x_num6 % 2)) == 0)));
		this->CxAssert((Boolean)(((x_num6 = (x_num6 | 4)) == 4)));
		this->CxAssert((Boolean)(((x_num6 = (x_num6 & 4)) == 4)));
		this->CxAssert((Boolean)(((x_num) == ((Int64)60000))));
		UInt32 x_num7 = 0;
		this->CxAssert((Boolean)(((~x_num7) == -1)));
		this->CxAssert((Boolean)(((++x_num7) == 1)));
		this->CxAssert((Boolean)(((--x_num7) == 0)));
		return;
	}
	void UInt64Test::UInt64Operators()
	{
IL_0000:
		UInt64 x_num = ((Int64)66);
		Char x_c = 1;
		Byte x_b = 1;
		SByte x_b2 = 1;
		Int16 x_num2 = 1;
		Int32 x_num3 = 1;
		Int64 x_num4 = ((Int64)1);
		UInt16 x_num5 = 1;
		UInt32 x_num6 = 1;
		UInt64 x_num7 = ((Int64)1);
		Single x_num8 = 1;
		Double x_num9 = 1;
		this->CxAssert((Boolean)(((x_num) == ((Int64)66))));
		this->CxAssert((Boolean)((((x_num + ((UInt64)x_c))) == ((Int64)67))));
		this->CxAssert((Boolean)((((x_num + ((UInt64)x_b))) == ((Int64)67))));
		this->CxAssert((Boolean)((((x_num + ((Int64)x_b2))) == ((Int64)67))));
		this->CxAssert((Boolean)((((x_num + ((Int64)x_num2))) == ((Int64)67))));
		this->CxAssert((Boolean)((((x_num + ((Int64)x_num3))) == ((Int64)67))));
		this->CxAssert((Boolean)((((x_num + x_num4)) == ((Int64)67))));
		this->CxAssert((Boolean)((((x_num + ((UInt64)x_num5))) == ((Int64)67))));
		this->CxAssert((Boolean)((((x_num + ((UInt64)x_num6))) == ((Int64)67))));
		this->CxAssert((Boolean)((((x_num + x_num7)) == ((Int64)67))));
		this->CxAssert((Boolean)((((((Single)x_num) + x_num8)) == 67)));
		this->CxAssert((Boolean)((((((Double)x_num) + x_num9)) == 67)));
		this->CxAssert((Boolean)((((x_num - ((UInt64)x_c))) == ((Int64)65))));
		this->CxAssert((Boolean)((((x_num - ((UInt64)x_b))) == ((Int64)65))));
		this->CxAssert((Boolean)((((x_num - ((Int64)x_b2))) == ((Int64)65))));
		this->CxAssert((Boolean)((((x_num - ((Int64)x_num2))) == ((Int64)65))));
		this->CxAssert((Boolean)((((x_num - ((Int64)x_num3))) == ((Int64)65))));
		this->CxAssert((Boolean)((((x_num - x_num4)) == ((Int64)65))));
		this->CxAssert((Boolean)((((x_num - ((UInt64)x_num5))) == ((Int64)65))));
		this->CxAssert((Boolean)((((x_num - ((UInt64)x_num6))) == ((Int64)65))));
		this->CxAssert((Boolean)((((x_num - x_num7)) == ((Int64)65))));
		this->CxAssert((Boolean)((((((Single)x_num) - x_num8)) == 65)));
		this->CxAssert((Boolean)((((((Double)x_num) - x_num9)) == 65)));
		this->CxAssert((Boolean)((((x_num * ((UInt64)x_c))) == ((Int64)66))));
		this->CxAssert((Boolean)((((x_num * ((UInt64)x_b))) == ((Int64)66))));
		this->CxAssert((Boolean)((((x_num * ((Int64)x_b2))) == ((Int64)66))));
		this->CxAssert((Boolean)((((x_num * ((Int64)x_num2))) == ((Int64)66))));
		this->CxAssert((Boolean)((((x_num * ((Int64)x_num3))) == ((Int64)66))));
		this->CxAssert((Boolean)((((x_num * x_num4)) == ((Int64)66))));
		this->CxAssert((Boolean)((((x_num * ((UInt64)x_num5))) == ((Int64)66))));
		this->CxAssert((Boolean)((((x_num * ((UInt64)x_num6))) == ((Int64)66))));
		this->CxAssert((Boolean)((((x_num * x_num7)) == ((Int64)66))));
		this->CxAssert((Boolean)((((((Single)x_num) * x_num8)) == 66)));
		this->CxAssert((Boolean)((((((Double)x_num) * x_num9)) == 66)));
		this->CxAssert((Boolean)((((x_num / ((UInt64)x_c))) == ((Int64)66))));
		this->CxAssert((Boolean)((((x_num / ((UInt64)x_b))) == ((Int64)66))));
		this->CxAssert((Boolean)((((x_num / ((Int64)x_b2))) == ((Int64)66))));
		this->CxAssert((Boolean)((((x_num / ((Int64)x_num2))) == ((Int64)66))));
		this->CxAssert((Boolean)((((x_num / ((Int64)x_num3))) == ((Int64)66))));
		this->CxAssert((Boolean)((((x_num / x_num4)) == ((Int64)66))));
		this->CxAssert((Boolean)((((x_num / ((UInt64)x_num5))) == ((Int64)66))));
		this->CxAssert((Boolean)((((x_num / ((UInt64)x_num6))) == ((Int64)66))));
		this->CxAssert((Boolean)((((x_num / x_num7)) == ((Int64)66))));
		this->CxAssert((Boolean)((((((Single)x_num) / x_num8)) == 66)));
		this->CxAssert((Boolean)((((((Double)x_num) / x_num9)) == 66)));
		this->CxAssert((Boolean)((((x_num % ((UInt64)x_c))) == ((Int64)0))));
		this->CxAssert((Boolean)((((x_num % ((UInt64)x_b))) == ((Int64)0))));
		this->CxAssert((Boolean)((((x_num % ((Int64)x_b2))) == ((Int64)0))));
		this->CxAssert((Boolean)((((x_num % ((Int64)x_num2))) == ((Int64)0))));
		this->CxAssert((Boolean)((((x_num % ((Int64)x_num3))) == ((Int64)0))));
		this->CxAssert((Boolean)((((x_num % x_num4)) == ((Int64)0))));
		this->CxAssert((Boolean)((((x_num % ((UInt64)x_num5))) == ((Int64)0))));
		this->CxAssert((Boolean)((((x_num % ((UInt64)x_num6))) == ((Int64)0))));
		this->CxAssert((Boolean)((((x_num % x_num7)) == ((Int64)0))));
		this->CxAssert((Boolean)(((DoubleValue::Modulus(((Single)x_num),x_num8)) == 0)));
		this->CxAssert((Boolean)(((DoubleValue::Modulus(((Double)x_num),x_num9)) == 0)));
		this->CxAssert((Boolean)((((x_num & ((UInt64)x_c))) == ((Int64)0))));
		this->CxAssert((Boolean)((((x_num & ((UInt64)x_b))) == ((Int64)0))));
		this->CxAssert((Boolean)((((x_num & ((Int64)x_b2))) == ((Int64)0))));
		this->CxAssert((Boolean)((((x_num & ((Int64)x_num2))) == ((Int64)0))));
		this->CxAssert((Boolean)((((x_num & ((Int64)x_num3))) == ((Int64)0))));
		this->CxAssert((Boolean)((((x_num & x_num4)) == ((Int64)0))));
		this->CxAssert((Boolean)((((x_num & ((UInt64)x_num5))) == ((Int64)0))));
		this->CxAssert((Boolean)((((x_num & ((UInt64)x_num6))) == ((Int64)0))));
		this->CxAssert((Boolean)((((x_num & x_num7)) == ((Int64)0))));
		this->CxAssert((Boolean)((((x_num | ((UInt64)x_c))) == ((Int64)67))));
		this->CxAssert((Boolean)((((x_num | ((UInt64)x_b))) == ((Int64)67))));
		this->CxAssert((Boolean)((((x_num | ((Int64)x_b2))) == ((Int64)67))));
		this->CxAssert((Boolean)((((x_num | ((Int64)x_num2))) == ((Int64)67))));
		this->CxAssert((Boolean)((((x_num | ((Int64)x_num3))) == ((Int64)67))));
		this->CxAssert((Boolean)((((x_num | x_num4)) == ((Int64)67))));
		this->CxAssert((Boolean)((((x_num | ((UInt64)x_num5))) == ((Int64)67))));
		this->CxAssert((Boolean)((((x_num | ((UInt64)x_num6))) == ((Int64)67))));
		this->CxAssert((Boolean)((((x_num | x_num7)) == ((Int64)67))));
		this->CxAssert((Boolean)((((x_num ^ ((UInt64)x_c))) == ((Int64)67))));
		this->CxAssert((Boolean)((((x_num ^ ((UInt64)x_b))) == ((Int64)67))));
		this->CxAssert((Boolean)((((x_num ^ ((Int64)x_b2))) == ((Int64)67))));
		this->CxAssert((Boolean)((((x_num ^ ((Int64)x_num2))) == ((Int64)67))));
		this->CxAssert((Boolean)((((x_num ^ ((Int64)x_num3))) == ((Int64)67))));
		this->CxAssert((Boolean)((((x_num ^ x_num4)) == ((Int64)67))));
		this->CxAssert((Boolean)((((x_num ^ ((UInt64)x_num5))) == ((Int64)67))));
		this->CxAssert((Boolean)((((x_num ^ ((UInt64)x_num6))) == ((Int64)67))));
		this->CxAssert((Boolean)((((x_num ^ x_num7)) == ((Int64)67))));
		this->CxAssert((Boolean)(((((Byte)~x_num)) == 189)));
		this->CxAssert((Boolean)(((((UInt64)x_c)) < x_num)));
		this->CxAssert((Boolean)(((((UInt64)x_b)) < x_num)));
		this->CxAssert((Boolean)(((((Int64)x_b2)) < x_num)));
		this->CxAssert((Boolean)(((((Int64)x_num2)) < x_num)));
		this->CxAssert((Boolean)(((((Int64)x_num3)) < x_num)));
		this->CxAssert((Boolean)(((x_num4) < x_num)));
		this->CxAssert((Boolean)(((((UInt64)x_num5)) < x_num)));
		this->CxAssert((Boolean)(((((UInt64)x_num6)) < x_num)));
		this->CxAssert((Boolean)(((x_num7) < x_num)));
		this->CxAssert((Boolean)(((x_num8) < ((Single)x_num))));
		this->CxAssert((Boolean)(((x_num9) < ((Double)x_num))));
		this->CxAssert((Boolean)(((((UInt64)x_c)) > x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((((UInt64)x_b)) > x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((((Int64)x_b2)) > x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((((Int64)x_num2)) > x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((((Int64)x_num3)) > x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num4) > x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((((UInt64)x_num5)) > x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((((UInt64)x_num6)) > x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num7) > x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num8) > ((Single)x_num))), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num9) > ((Double)x_num))), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num = (x_num + ((Int64)1))) == ((Int64)67))));
		this->CxAssert((Boolean)(((x_num = (x_num - ((Int64)1))) == ((Int64)66))));
		this->CxAssert((Boolean)(((x_num++) == ((Int64)66))));
		this->CxAssert((Boolean)(((x_num--) == ((Int64)67))));
		this->CxAssert((Boolean)((((x_num << 1)) == ((Int64)132))));
		this->CxAssert((Boolean)((((x_num >> 1)) == ((Int64)33))));
		this->CxAssert((Boolean)(((((UInt64)x_c)) == x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((((UInt64)x_b)) == x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((((Int64)x_b2)) == x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((((Int64)x_num2)) == x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((((Int64)x_num3)) == x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num4) == x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((((UInt64)x_num5)) == x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((((UInt64)x_num6)) == x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num7) == x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num8) == ((Single)x_num))), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num9) == ((Double)x_num))), (Boolean)(0));
		this->CxAssert((Boolean)(((((UInt64)x_c)) != x_num)));
		this->CxAssert((Boolean)(((((UInt64)x_b)) != x_num)));
		this->CxAssert((Boolean)(((((Int64)x_b2)) != x_num)));
		this->CxAssert((Boolean)(((((Int64)x_num2)) != x_num)));
		this->CxAssert((Boolean)(((((Int64)x_num3)) != x_num)));
		this->CxAssert((Boolean)(((x_num4) != x_num)));
		this->CxAssert((Boolean)(((((UInt64)x_num5)) != x_num)));
		this->CxAssert((Boolean)(((((UInt64)x_num6)) != x_num)));
		this->CxAssert((Boolean)(((x_num7) != x_num)));
		this->CxAssert((Boolean)(((x_num8) != ((Single)x_num))));
		this->CxAssert((Boolean)(((x_num9) != ((Double)x_num))));
		this->CxAssert((Boolean)(((((UInt64)x_c)) <= x_num)));
		this->CxAssert((Boolean)(((((UInt64)x_b)) <= x_num)));
		this->CxAssert((Boolean)(((((Int64)x_b2)) <= x_num)));
		this->CxAssert((Boolean)(((((Int64)x_num2)) <= x_num)));
		this->CxAssert((Boolean)(((((Int64)x_num3)) <= x_num)));
		this->CxAssert((Boolean)(((x_num4) <= x_num)));
		this->CxAssert((Boolean)(((((UInt64)x_num5)) <= x_num)));
		this->CxAssert((Boolean)(((((UInt64)x_num6)) <= x_num)));
		this->CxAssert((Boolean)(((x_num7) <= x_num)));
		this->CxAssert((Boolean)(((x_num8) <= ((Single)x_num))));
		this->CxAssert((Boolean)(((x_num9) <= ((Double)x_num))));
		this->CxAssert((Boolean)(((((UInt64)x_c)) >= x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((((UInt64)x_b)) >= x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((((Int64)x_b2)) >= x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((((Int64)x_num2)) >= x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((((Int64)x_num3)) >= x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num4) >= x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((((UInt64)x_num5)) >= x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((((UInt64)x_num6)) >= x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num7) >= x_num)), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num8) >= ((Single)x_num))), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num9) >= ((Double)x_num))), (Boolean)(0));
		this->CxAssert((Boolean)(((x_num = (x_num + ((UInt64)((Byte)x_c)))) == ((Int64)67))));
		this->CxAssert((Boolean)(((x_num = (x_num - ((UInt64)((Byte)x_c)))) == ((Int64)66))));
		this->CxAssert((Boolean)(((x_num = (x_num + ((UInt64)((Byte)x_num6)))) == ((Int64)67))));
		this->CxAssert((Boolean)(((x_num = (x_num - ((UInt64)((Byte)x_num6)))) == ((Int64)66))));
		this->CxAssert((Boolean)(((x_num = (x_num * ((UInt64)((Byte)x_c)))) == ((Int64)66))));
		this->CxAssert((Boolean)(((x_num = (x_num / ((UInt64)((Byte)x_c)))) == ((Int64)66))));
		this->CxAssert((Boolean)(((x_num = (x_num * ((UInt64)((Byte)x_num6)))) == ((Int64)66))));
		this->CxAssert((Boolean)(((x_num = (x_num / ((UInt64)((Byte)x_num6)))) == ((Int64)66))));
		this->CxAssert((Boolean)(((x_num = (x_num % ((UInt64)((Byte)x_c)))) == ((Int64)0))));
		x_num = ((Int64)66);
		this->CxAssert((Boolean)(((x_num = (x_num % ((UInt64)((Byte)x_num6)))) == ((Int64)0))));
		x_num = ((Int64)66);
		this->CxAssert((Boolean)(((x_num = (x_num & ((UInt64)((Byte)x_c)))) == ((Int64)0))));
		x_num = ((Int64)66);
		this->CxAssert((Boolean)(((x_num = (x_num & ((UInt64)((Byte)x_num6)))) == ((Int64)0))));
		x_num = ((Int64)66);
		this->CxAssert((Boolean)(((x_num = (x_num | ((UInt64)((Byte)x_c)))) == ((Int64)67))));
		x_num = ((Int64)66);
		this->CxAssert((Boolean)(((x_num = (x_num | ((UInt64)((Byte)x_num6)))) == ((Int64)67))));
		x_num = ((Int64)66);
		this->CxAssert((Boolean)(((x_num = (x_num ^ ((UInt64)((Byte)x_c)))) == ((Int64)67))));
		x_num = ((Int64)66);
		this->CxAssert((Boolean)(((x_num = (x_num ^ ((UInt64)((Byte)x_num6)))) == ((Int64)67))));
		x_num = ((Int64)66);
		this->CxAssert((Boolean)(((x_num = (x_num << x_c)) == ((Int64)132))));
		x_num = ((Int64)66);
		this->CxAssert((Boolean)(((x_num = (x_num << x_num3)) == ((Int64)132))));
		x_num = ((Int64)66);
		this->CxAssert((Boolean)(((x_num = (x_num >> x_c)) == ((Int64)33))));
		x_num = ((Int64)66);
		this->CxAssert((Boolean)(((x_num = (x_num >> x_num3)) == ((Int64)33))));
		x_num = ((Int64)66);
		Char x_c2 = 66;
		this->CxAssert((Boolean)(((x_c2 = ((UInt16)(x_c2 << x_c))) == 132)));
		return;
	}
	void UInt64Test::UInt64ArrayTest()
	{
IL_0000:
		Array* x_array = new Array(UInt64Type,5);
		(*((UInt64*)x_array->Address(0))) = 1;
		(*((UInt64*)x_array->Address(1))) = 2;
		(*((UInt64*)x_array->Address(2))) = 3;
		(*((UInt64*)x_array->Address(3))) = 4;
		(*((UInt64*)x_array->Address(4))) = 5;
		this->CxAssert((Boolean)(((x_array->get_Length()) == 5)));
		this->CxAssert((Boolean)((((*((Int64*)x_array->Address(3)))) == ((Int64)4))));
		Array* x_array2 = new Array(UInt64Type,4);
		(*((UInt64*)x_array2->Address(0))) = 1;
		(*((UInt64*)x_array2->Address(1))) = 2;
		(*((UInt64*)x_array2->Address(2))) = 3;
		(*((UInt64*)x_array2->Address(3))) = 4;
		this->CxAssert((Boolean)((((*((Int64*)x_array2->Address(1)))) == ((Int64)2))));
		Array* x_array3 = new Array(UInt64Type,2,4);
		(*((UInt64*)x_array3->Address(0,0))) = 1;
		(*((UInt64*)x_array3->Address(0,1))) = 2;
		(*((UInt64*)x_array3->Address(0,2))) = 3;
		(*((UInt64*)x_array3->Address(0,3))) = 4;
		(*((UInt64*)x_array3->Address(1,0))) = 4;
		(*((UInt64*)x_array3->Address(1,1))) = 5;
		(*((UInt64*)x_array3->Address(1,2))) = 6;
		(*((UInt64*)x_array3->Address(1,3))) = 7;
		this->CxAssert((Boolean)((((*((UInt64*)x_array3->Address(0,2)))) == ((Int64)3))));
		Array* x_array4 = new Array(UInt64Type,2,2,4);
		(*((UInt64*)x_array4->Address(0,0,0))) = 1;
		(*((UInt64*)x_array4->Address(0,0,1))) = 2;
		(*((UInt64*)x_array4->Address(0,0,2))) = 3;
		(*((UInt64*)x_array4->Address(0,0,3))) = 4;
		(*((UInt64*)x_array4->Address(0,1,0))) = 5;
		(*((UInt64*)x_array4->Address(0,1,1))) = 6;
		(*((UInt64*)x_array4->Address(0,1,2))) = 7;
		(*((UInt64*)x_array4->Address(0,1,3))) = 8;
		(*((UInt64*)x_array4->Address(1,0,0))) = 9;
		(*((UInt64*)x_array4->Address(1,0,1))) = 10;
		(*((UInt64*)x_array4->Address(1,0,2))) = 11;
		(*((UInt64*)x_array4->Address(1,0,3))) = 12;
		(*((UInt64*)x_array4->Address(1,1,0))) = 13;
		(*((UInt64*)x_array4->Address(1,1,1))) = 14;
		(*((UInt64*)x_array4->Address(1,1,2))) = 15;
		(*((UInt64*)x_array4->Address(1,1,3))) = 16;
		this->CxAssert((Boolean)((((*((UInt64*)x_array4->Address(0,0,3)))) == ((Int64)4))));
		(*((UInt64*)x_array4->Address(0,0,3))) = ((Int64)6);
		this->CxAssert((Boolean)((((*((UInt64*)x_array4->Address(0,0,3)))) == ((Int64)6))));
		x_array4->SetValue((new UInt64Value(((Int64)4))), (Int32)(0), (Int32)(0), (Int32)(3));
		this->CxAssert((Boolean)((((*((UInt64*)x_array4->Address(0,0,3)))) == ((Int64)4))));
		return;
	}
	void UInt64Test::UInt64MiscTests()
	{
IL_0000:
		UInt64 x_num = ((Int64)0);
		UInt64 x_num2 = ((Int64)1);
		this->CxAssert((Boolean)(((Math::Max((UInt64)(x_num), (UInt64)(x_num2))) == ((Int64)1))));
		this->CxAssert((Boolean)(((Math::Min((UInt64)(x_num), (UInt64)(x_num2))) == ((Int64)0))));
		StringBuilder* x_stringBuilder = (new StringBuilder());
		x_stringBuilder->Append((UInt64)(x_num2));
		this->CxAssert((Boolean)(String::Equals(x_stringBuilder->ToString(), (new String(L"1")))));
		x_stringBuilder->Insert((Int32)(1), (UInt64)(x_num));
		this->CxAssert((Boolean)(String::Equals(x_stringBuilder->ToString(), (new String(L"10")))));
		return;
	}
	void UInt64Test::CxAssert(Boolean x_x)
	{
IL_0000:
		if (((x_x) == 0))
		{
			this->x_caBlock->TestFailed((new String(L"UInt64 TestFailed")));
		}

		return;
	}
	void UInt64Test::CxAssert(Boolean x_x,Boolean x_y)
	{
IL_0000:
		if (((x_x) != x_y))
		{
			this->x_caBlock->TestFailed((new String(L"UInt64 TestFailed")));
		}

		return;
	}
}
