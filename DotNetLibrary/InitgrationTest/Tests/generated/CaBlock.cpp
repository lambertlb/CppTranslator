#pragma once
#include "CaBlockHeader.h"
namespace MiniTest_NS
{
	Program::Program()
	{
IL_0000:
		
		Double x_num = (*((Double*)this->x_double3dArray->Address(1,1,3)));
		this->CxAssert(x_num == 22);
		this->CxAssert(DoubleValue(22).Equals(this->x_double3dArray->GetValue(1, 1, 3)));
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
IL_0000:
		Program* x_program = new Program();
		return((Int32)0);
	}
}
namespace CABlock_NS
{
	void ArrayTest::TestArrayCreation()
	{
IL_0000:
		this->x_boolArray = new Array(BooleanType,4);
		this->x_int1dArray = new Array(Int32Type,4);
		(*((Int32*)x_int1dArray->Address(0))) = 1;
		(*((Int32*)x_int1dArray->Address(1))) = 2;
		(*((Int32*)x_int1dArray->Address(2))) = 3;
		(*((Int32*)x_int1dArray->Address(3))) = 4;
		this->CxAssert((*((Int32*)this->x_int1dArray->Address(1))) == 2);
		this->x_int2dArray = new Array(Int32Type,2,4);
		(*((Int32*)x_int2dArray->Address(0,0))) = 1;
		(*((Int32*)x_int2dArray->Address(0,1))) = 2;
		(*((Int32*)x_int2dArray->Address(0,2))) = 3;
		(*((Int32*)x_int2dArray->Address(0,3))) = 4;
		(*((Int32*)x_int2dArray->Address(1,0))) = 4;
		(*((Int32*)x_int2dArray->Address(1,1))) = 5;
		(*((Int32*)x_int2dArray->Address(1,2))) = 6;
		(*((Int32*)x_int2dArray->Address(1,3))) = 7;
		this->CxAssert((*((Int32*)this->x_int2dArray->Address(0,2))) == 3);
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
		this->CxAssert((*((Int32*)this->x_int3dArray->Address(0,0,3))) == 4);
		this->x_double1dArray = new Array(DoubleType,4);
		(*((Double*)x_double1dArray->Address(0))) = 1;
		(*((Double*)x_double1dArray->Address(1))) = 2;
		(*((Double*)x_double1dArray->Address(2))) = 3;
		(*((Double*)x_double1dArray->Address(3))) = 4;
		this->CxAssert((*((Double*)this->x_double1dArray->Address(1))) == 2);
		this->x_double2dArray = new Array(DoubleType,2,4);
		(*((Double*)x_double2dArray->Address(0,0))) = 1;
		(*((Double*)x_double2dArray->Address(0,1))) = 2;
		(*((Double*)x_double2dArray->Address(0,2))) = 3;
		(*((Double*)x_double2dArray->Address(0,3))) = 4;
		(*((Double*)x_double2dArray->Address(1,0))) = 4;
		(*((Double*)x_double2dArray->Address(1,1))) = 5;
		(*((Double*)x_double2dArray->Address(1,2))) = 6;
		(*((Double*)x_double2dArray->Address(1,3))) = 7;
		this->CxAssert((*((Double*)this->x_double2dArray->Address(0,2))) == 3);
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
		this->CxAssert((*((Double*)this->x_double3dArray->Address(0,0,3))) == 4);
		this->x_dateTime1dArray = new Array(DateTimeType,4);
		(*((DateTime*)x_dateTime1dArray->Address(0))) = DateTime(2003, 7, 23, 12, 30, 30, 100);
		(*((DateTime*)x_dateTime1dArray->Address(1))) = DateTime(2003, 7, 23, 12, 30, 30, 200);
		(*((DateTime*)x_dateTime1dArray->Address(2))) = DateTime(2003, 7, 23, 12, 30, 30, 300);
		(*((DateTime*)x_dateTime1dArray->Address(3))) = DateTime(2003, 7, 23, 12, 30, 30, 400);
		this->CxAssert((*((DateTime*)this->x_dateTime1dArray->Address(2))).Equals(DateTime(2003, 7, 23, 12, 30, 30, 300)));
		(*((DateTime*)this->x_dateTime2dArray->Address(1,1))) = DateTime(2003, 7, 23, 12, 30, 30, 100);
		(*((DateTime*)this->x_dateTime3dArray->Address(1,1,1))) = DateTime(2003, 7, 23, 12, 30, 30, 100);
		(*((TimeSpan*)this->x_timeSpan1dArray->Address(0))) = TimeSpan();
		(*((TimeSpan*)this->x_timeSpan1dArray->Address(0))) = TimeSpan(5, 4, 3, 2, 100);
		(*((TimeSpan*)this->x_timeSpan1dArray->Address(1))) = TimeSpan(5, 4, 3, 2, 200);
		(*((TimeSpan*)this->x_timeSpan1dArray->Address(2))) = TimeSpan(5, 4, 3, 2, 300);
		(*((TimeSpan*)this->x_timeSpan1dArray->Address(3))) = TimeSpan(5, 4, 3, 2, 400);
		(*((TimeSpan*)this->x_timeSpan2dArray->Address(1,1))) = TimeSpan(5, 4, 3, 2, 100);
		(*((TimeSpan*)this->x_timeSpan3dArray->Address(1,1,1))) = TimeSpan(5, 4, 3, 2, 100);
		return;
	}
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
		this->CxAssert(x_num4 != 0);
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
IL_0000:
		this->CxAssert(this->x_int3dArray->GetLength(2) == 4);
		this->CxAssert(this->x_int3dArray->GetLowerBound(2) == 0);
		this->CxAssert(this->x_int3dArray->GetUpperBound(2) == 3);
		Array* x_array = this->x_dateTime1dArray;
		Int32 x_i = 0;
		
		{
IL_0065:
			if (x_i < x_array->get_Length())
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
			String* x_text = x_dateTime.ToString();
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
		this->CxAssert(x_length == 16);
		this->CxAssert(this->x_int1dArray->get_Rank() == 1);
		this->CxAssert(this->x_int2dArray->get_Rank() == 2);
		this->CxAssert(this->x_int3dArray->get_Rank() == 3);
		Array* x_array = new Array(DateTimeType,5);
		Array::Copy(this->x_dateTime1dArray, x_array, this->x_dateTime1dArray->get_Length());
		Int32 x_i = 0;
		
		{
IL_00aa:
			if (x_i < this->x_dateTime1dArray->get_Length())
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
			this->CxAssert(DateTime::Equals(x_d, x_d2));
			goto IL_00a8;
		}
		{
IL_00a8:
			++x_i;
			goto IL_00aa;
		}
leaveBlock2:

		this->x_dateTime1dArray->CopyTo(x_array, 1);
		Int32 x_j = 1;
		
		{
IL_00f8:
			if (x_j < x_array->get_Length())
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
			this->CxAssert(DateTime::Equals((*((DateTime*)this->x_dateTime1dArray->Address((x_j - 1)))), (*((DateTime*)x_array->Address(x_j)))));
			goto IL_00f6;
		}
		{
IL_00f6:
			++x_j;
			goto IL_00f8;
		}
leaveBlock3:

		this->CxAssert((TimeSpan(5, 4, 3, 2, 100)).Equals(this->x_timeSpan3dArray->GetValue(1, 1, 1)));
		TimeSpan x_timeSpan = TimeSpan(5, 4, 3, 2, 101);
		Array* x_indices = new Array(Int32Type,3);
		(*((Int32*)x_indices->Address(0))) = 1;
		(*((Int32*)x_indices->Address(1))) = 1;
		(*((Int32*)x_indices->Address(2))) = 1;
		this->x_timeSpan3dArray->SetValue((new TimeSpanValue(x_timeSpan)), x_indices);
		this->CxAssert(x_timeSpan.Equals(this->x_timeSpan3dArray->GetValue(x_indices)));
		(*((Double*)this->x_double3dArray->Address(1,1,3))) = 22;
		Double x_num = (*((Double*)this->x_double3dArray->Address(1,1,3)));
		this->CxAssert(x_num == 22);
		this->CxAssert(DoubleValue(22).Equals(this->x_double3dArray->GetValue(1, 1, 3)));
		this->x_timeSpan3dArray->SetValue((new TimeSpanValue(x_timeSpan)), 0, 0, 0);
		this->CxAssert(TimeSpan::Equals((*((TimeSpan*)this->x_timeSpan3dArray->Address(0,0,0))), x_timeSpan));
		(*((SByte*)this->x_boolArray->Address(0))) = 1;
		this->CxAssert((*((Byte*)this->x_boolArray->Address(0))));
		Array::Clear(this->x_boolArray, 0, this->x_boolArray->get_Length());
		this->CxAssert((*((Byte*)this->x_boolArray->Address(0))) == 0);
		this->x_int1dArray->SetValue((new Int32Value(1)), 2);
		this->CxAssert((*((Int32*)this->x_int1dArray->Address(1))) == 2);
		Array* x_array2 = new Array(DoubleType,4);
		(*((Double*)x_array2->Address(0))) = 1;
		(*((Double*)x_array2->Address(1))) = 2;
		(*((Double*)x_array2->Address(2))) = 3;
		(*((Double*)x_array2->Address(3))) = 4;
		x_array2->SetValue((new Int32Value(2)), 1);
		this->CxAssert((*((Double*)x_array2->Address(1))) == 2);
		x_array2->SetValue((new UInt32Value(2)), 1);
		this->CxAssert((*((Double*)x_array2->Address(1))) == 2);
		return;
	}
	void ArrayTest::CxAssert(Boolean x_x)
	{
IL_0000:
		if (x_x == 0)
		{
			this->x_caBlock->TestFailed(new String(L"Array TestFailed"));
		}

		return;
	}
	ArrayTest::ArrayTest()
	{
	}
	void CABlock::Send(String* x_v)
	{
		return;
	}
	void CABlock::TestFailed(String* x_v)
	{
		return;
	}
	CABlock::CABlock()
	{
	}
}
