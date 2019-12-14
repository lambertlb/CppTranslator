#pragma once
#include "CaBlockHeader.h"
namespace MiniTest_NS
{
	Int32 Program::get_Fred()
	{
		return(this->Fredk__BackingField);
	}
	void Program::set_Fred(Int32 x_value )
	{
		this->Fredk__BackingField = x_value;
		return;
	}
	String* Program::get_Name()
	{
		return(this->x_name);
	}
	void Program::set_Name(String* x_value )
	{
		this->x_name = x_value;
		return;
	}
	Program::Program()
	{
		
		this->set_Fred(1);
		Int32 x_fred = this->get_Fred();
		this->set_Name(new String(L"Fred"));
		
		String* x_text = new String(L"12345");
		Boolean x_flag = x_text->Equals(new String(L""));
		this->CxAssert(1);
		Program::Test1(1);
		return;
	}
	void Program::CxAssert(Boolean x_isTrue)
	{
		return;
	}
	void Program::CxAssert(Double x_x,Double x_y)
	{
		return;
	}
	void Program::Test1(Int32 x_aa)
	{
		return;
	}
	Int32 Program::Main(Array* x_arvs)
	{
		Program* x_program = new Program();
		return((Int32)0);
	}
}
namespace CABlock_NS
{
	void ArrayTest::TestArrayCreation()
	{
		this->x_boolArray = new Array(BooleanType,4);
		this->x_int1dArray = new Array(Int32Type,4);
		*((Int32*)this->x_int1dArray->Address(0)) = 1;
		*((Int32*)this->x_int1dArray->Address(1)) = 2;
		*((Int32*)this->x_int1dArray->Address(2)) = 3;
		*((Int32*)this->x_int1dArray->Address(3)) = 4;
		this->CxAssert();
		this->x_int2dArray = new Array(Int32Type,2,4);
		*((Int32*)this->x_int2dArray->Address(0,0)) = 1;
		*((Int32*)this->x_int2dArray->Address(0,1)) = 2;
		*((Int32*)this->x_int2dArray->Address(0,2)) = 3;
		*((Int32*)this->x_int2dArray->Address(0,3)) = 4;
		*((Int32*)this->x_int2dArray->Address(1,0)) = 4;
		*((Int32*)this->x_int2dArray->Address(1,1)) = 5;
		*((Int32*)this->x_int2dArray->Address(1,2)) = 6;
		*((Int32*)this->x_int2dArray->Address(1,3)) = 7;
		this->CxAssert();
		this->x_int3dArray = new Array(Int32Type,2,2,4);
		*((Int32*)this->x_int3dArray->Address(0,0,0)) = 1;
		*((Int32*)this->x_int3dArray->Address(0,0,1)) = 2;
		*((Int32*)this->x_int3dArray->Address(0,0,2)) = 3;
		*((Int32*)this->x_int3dArray->Address(0,0,3)) = 4;
		*((Int32*)this->x_int3dArray->Address(0,1,0)) = 5;
		*((Int32*)this->x_int3dArray->Address(0,1,1)) = 6;
		*((Int32*)this->x_int3dArray->Address(0,1,2)) = 7;
		*((Int32*)this->x_int3dArray->Address(0,1,3)) = 8;
		*((Int32*)this->x_int3dArray->Address(1,0,0)) = 9;
		*((Int32*)this->x_int3dArray->Address(1,0,1)) = 10;
		*((Int32*)this->x_int3dArray->Address(1,0,2)) = 11;
		*((Int32*)this->x_int3dArray->Address(1,0,3)) = 12;
		*((Int32*)this->x_int3dArray->Address(1,1,0)) = 13;
		*((Int32*)this->x_int3dArray->Address(1,1,1)) = 14;
		*((Int32*)this->x_int3dArray->Address(1,1,2)) = 15;
		*((Int32*)this->x_int3dArray->Address(1,1,3)) = 16;
		this->CxAssert();
		this->x_double1dArray = new Array(DoubleType,4);
		*((Double*)this->x_double1dArray->Address(0)) = 1;
		*((Double*)this->x_double1dArray->Address(1)) = 2;
		*((Double*)this->x_double1dArray->Address(2)) = 3;
		*((Double*)this->x_double1dArray->Address(3)) = 4;
		this->CxAssert();
		this->x_double2dArray = new Array(DoubleType,2,4);
		*((Double*)this->x_double2dArray->Address(0,0)) = 1;
		*((Double*)this->x_double2dArray->Address(0,1)) = 2;
		*((Double*)this->x_double2dArray->Address(0,2)) = 3;
		*((Double*)this->x_double2dArray->Address(0,3)) = 4;
		*((Double*)this->x_double2dArray->Address(1,0)) = 4;
		*((Double*)this->x_double2dArray->Address(1,1)) = 5;
		*((Double*)this->x_double2dArray->Address(1,2)) = 6;
		*((Double*)this->x_double2dArray->Address(1,3)) = 7;
		this->CxAssert();
		this->x_double3dArray = new Array(DoubleType,2,2,4);
		*((Double*)this->x_double3dArray->Address(0,0,0)) = 1;
		*((Double*)this->x_double3dArray->Address(0,0,1)) = 2;
		*((Double*)this->x_double3dArray->Address(0,0,2)) = 3;
		*((Double*)this->x_double3dArray->Address(0,0,3)) = 4;
		*((Double*)this->x_double3dArray->Address(0,1,0)) = 5;
		*((Double*)this->x_double3dArray->Address(0,1,1)) = 6;
		*((Double*)this->x_double3dArray->Address(0,1,2)) = 7;
		*((Double*)this->x_double3dArray->Address(0,1,3)) = 8;
		*((Double*)this->x_double3dArray->Address(1,0,0)) = 9;
		*((Double*)this->x_double3dArray->Address(1,0,1)) = 10;
		*((Double*)this->x_double3dArray->Address(1,0,2)) = 11;
		*((Double*)this->x_double3dArray->Address(1,0,3)) = 12;
		*((Double*)this->x_double3dArray->Address(1,1,0)) = 13;
		*((Double*)this->x_double3dArray->Address(1,1,1)) = 14;
		*((Double*)this->x_double3dArray->Address(1,1,2)) = 15;
		*((Double*)this->x_double3dArray->Address(1,1,3)) = 16;
		this->CxAssert();
		this->x_dateTime1dArray = new Array(DateTimeType,4);
		*((DateTime*)this->x_dateTime1dArray->Address(0)) = new DateTime(2003, 7, 23, 12, 30, 30, 100);
		*((DateTime*)this->x_dateTime1dArray->Address(1)) = new DateTime(2003, 7, 23, 12, 30, 30, 200);
		*((DateTime*)this->x_dateTime1dArray->Address(2)) = new DateTime(2003, 7, 23, 12, 30, 30, 300);
		*((DateTime*)this->x_dateTime1dArray->Address(3)) = new DateTime(2003, 7, 23, 12, 30, 30, 400);
		this->CxAssert(((DateTime*)this->x_dateTime1dArray->Address(2)).Equals(new DateTime(2003, 7, 23, 12, 30, 30, 300)));
		((DateTime*)this->x_dateTime2dArray->Address(1,1)) = new DateTime(2003, 7, 23, 12, 30, 30, 100);
		((DateTime*)this->x_dateTime3dArray->Address(1,1,1)) = new DateTime(2003, 7, 23, 12, 30, 30, 100);
		((TimeSpan*)this->x_timeSpan1dArray->Address(0)) = ;
		((TimeSpan*)this->x_timeSpan1dArray->Address(0)) = new TimeSpan(5, 4, 3, 2, 100);
		((TimeSpan*)this->x_timeSpan1dArray->Address(1)) = new TimeSpan(5, 4, 3, 2, 200);
		((TimeSpan*)this->x_timeSpan1dArray->Address(2)) = new TimeSpan(5, 4, 3, 2, 300);
		((TimeSpan*)this->x_timeSpan1dArray->Address(3)) = new TimeSpan(5, 4, 3, 2, 400);
		((TimeSpan*)this->x_timeSpan2dArray->Address(1,1)) = new TimeSpan(5, 4, 3, 2, 100);
		((TimeSpan*)this->x_timeSpan3dArray->Address(1,1,1)) = new TimeSpan(5, 4, 3, 2, 100);
		return;
	}
	ArrayTest::ArrayTest(CABlock* x_caBlock)
	{
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
		Int32 x_num = 0;
		Int32 x_num2 = 0;
		Int32 x_num3 = 0;
		Int32 x_num4 = ;
		this->CxAssert();
		this->x_caBlock->Send(new String(L"Doing ArrayTest"));
		this->x_caBlock->Send(new String(L"	Doing TestArrayCreation"));
		this->TestArrayCreation();
		this->x_caBlock->Send(new String(L"	Doing MiscTest"));
		this->MiscTest();
		this->x_caBlock->Send(new String(L"	Doing ArrayMethodTests"));
		this->ArrayMethodTests();
		return;
	}
	void ArrayTest::MiscTest()
	{
		this->CxAssert();
		this->CxAssert();
		this->CxAssert();
		Array* x_array = this->x_dateTime1dArray;
		Int32 x_i = 0;
		
		{
			
		}
		{
			DateTime x_dateTime = ((DateTime*)x_array->Address(x_i));
			String* x_text = .ToString();
			
		}
		{
			Int32 x_i = ;
			
		}

		return;
	}
	void ArrayTest::ArrayMethodTests()
	{
		Int32 x_length = this->x_int3dArray->get_Length();
		this->CxAssert();
		this->CxAssert();
		this->CxAssert();
		this->CxAssert();
		Array* x_array = new Array(DateTimeType,5);
		Array::Copy(this->x_dateTime1dArray, x_array, );
		Int32 x_i = 0;
		
		{
			
		}
		{
			DateTime x_d = ((DateTime*)this->x_dateTime1dArray->Address(x_i));
			DateTime x_d2 = ((DateTime*)x_array->Address(x_i));
			this->CxAssert(DateTime::op_Equality(x_d, x_d2));
			
		}
		{
			Int32 x_i = ;
			
		}

		this->x_dateTime1dArray->CopyTo(x_array, 1);
		Int32 x_j = 1;
		
		{
			
		}
		{
			this->CxAssert(DateTime::op_Equality(((DateTime*)this->x_dateTime1dArray->Address()), ((DateTime*)x_array->Address(x_j))));
			
		}
		{
			Int32 x_j = ;
			
		}

		this->CxAssert(->Equals(this->x_timeSpan3dArray->GetValue(1, 1, 1)));
		TimeSpan x_timeSpan = new TimeSpan(5, 4, 3, 2, 101);
		Array* x_indices = ;
		this->x_timeSpan3dArray->SetValue(, x_indices);
		this->CxAssert(->Equals(this->x_timeSpan3dArray->GetValue(x_indices)));
		((Double*)this->x_double3dArray->Address(1,1,3)) = 22;
		Double x_num = ((Double*)this->x_double3dArray->Address(1,1,3));
		this->CxAssert();
		this->CxAssert(.Equals(this->x_double3dArray->GetValue(1, 1, 3)));
		this->x_timeSpan3dArray->SetValue(, 0, 0, 0);
		this->CxAssert(TimeSpan::op_Equality(((TimeSpan*)this->x_timeSpan3dArray->Address(0,0,0)), x_timeSpan));
		((SByte*)this->x_boolArray->Address(0)) = 1;
		this->CxAssert(((Byte*)this->x_boolArray->Address(0)));
		Array::Clear(this->x_boolArray, 0, );
		this->CxAssert();
		this->x_int1dArray->SetValue(, 2);
		this->CxAssert();
		Array* x_array2 = ;
		x_array2->SetValue(, 1);
		this->CxAssert();
		x_array2->SetValue(, 1);
		this->CxAssert();
		return;
	}
	void ArrayTest::CxAssert(Boolean x_x)
	{
		
		return;
	}
	ArrayTest::ArrayTest()
	{
	}
	void CABlock::Send(String* x_v)
	{
		
	}
	void CABlock::TestFailed(String* x_v)
	{
		
	}
	CABlock::CABlock()
	{
	}
}
