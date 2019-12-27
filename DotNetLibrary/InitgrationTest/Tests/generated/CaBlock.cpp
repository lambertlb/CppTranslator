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
}
namespace MiniTest_NS
{
	Int32 Program::x_ss;
	Program::Program()
	{
IL_0000:
		
		this->x_jj = 1;
		if ((this->x_jj == 2))
		{
			this->x_jj = this->Doit(this->x_jj);
			return;
		}

		this->x_jj = this->Doit(this->x_jj);
		if ((this->x_jj == 3))
		{
			this->x_jj = this->Doit(this->x_jj);
		}

		return;
	}
	Int32 Program::Doit(Int32 x_x)
	{
		return((Int32)++x_x);
	}
	Boolean Program::Program_Static()
	{
IL_0000:
		Program::x_ss = 1;
		return (true);
	}
	Boolean Program::Program_Initilized = Program::Program_Static();
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
		Program* x_program = (new Program());
		return((Int32)0);
	}
}
