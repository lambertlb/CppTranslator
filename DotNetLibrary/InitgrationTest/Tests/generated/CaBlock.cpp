#pragma once
#include "CaBlockHeader.h"
namespace CABlock_NS
{
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
namespace MiniTest_NS
{
	Program::Program()
	{
		
		Int32 x_num = 0;
		Int32 x_num2 = 0;
		Int32 x_num3 = 0;
		Int32 x_num4 = 0;
		Int32 x_num5 = (((++x_num + --x_num2) + x_num3++) + x_num4--);
		this->CxAssert(x_num5 == 0);
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
