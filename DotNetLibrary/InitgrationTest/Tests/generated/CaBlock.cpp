#pragma once
#include "CaBlockHeader.h"
namespace CABlock_NS
{
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
namespace MiniTest_NS
{
	Program::Program()
	{
IL_0000:
		this->x_field1 = 0;
		
		Boolean x_flag = 1;
		Boolean x_flag2 = 0;
		Boolean x_flag3 = 1;
		Boolean x_flag4 = 0;
		Boolean x_flag5 = (((x_flag & x_flag2) & x_flag3) & x_flag4);
		Boolean x_flag6 = (((x_flag | x_flag2) | x_flag3) | x_flag4);
		Boolean x_flag7 = (x_flag || ((x_flag2 & x_flag3) & x_flag4));
		Boolean x_flag8 = (x_flag == 0 && (x_flag2 == 0 && x_flag3 == 0) && x_flag4 == 0);
		if ((((x_flag & x_flag2) & x_flag3) & x_flag4))
		{
			x_flag5 = 1;
		}

		if (this->x_field1 == 0 && this->x_field1 != 1)
		{
			this->x_field1 = 1;
		}
		else
		{
			this->x_field1 = 2;
		}

		this->x_field1 = 0;
		Boolean x_flag9 = (this->x_field1 < 1 && this->x_field1 < 2 && this->x_field1 < 3);
		Boolean x_flag10 = (this->x_field1 < 1 || this->x_field1 < 2 || this->x_field1 < 3);
		Boolean x_flag11 = (this->x_field1 < 1 || (this->x_field1 < 2 && this->x_field1 < 3));
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
	TestStruct2::TestStruct2()
	{
	}
	TestStruct3::TestStruct3()
	{
	}
}
