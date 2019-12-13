#pragma once
#include "CaBlockHeader.h"
namespace MiniTest_NS
{
	Program::Program()
	{
		
		String* x_text = new String(L"12345");
		Boolean x_flag = x_text->Equals(new String(L""));
		CxAssert(1);
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
		return(0);
	}
}
