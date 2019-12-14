#pragma once
#include "CaBlockHeader.h"
namespace MiniTest_NS
{
	Int32 Program::get_Fred()
	{
		return(Fredk__BackingField);
	}
	void Program::set_Fred(Int32 x_value )
	{
		Fredk__BackingField = x_value;
		return;
	}
	String* Program::get_Name()
	{
		return(x_name);
	}
	void Program::set_Name(String* x_value )
	{
		x_name = x_value;
		return;
	}
	Program::Program()
	{
		
		set_Fred(1);
		Int32 x_fred = get_Fred();
		set_Name(new String(L"Fred"));
		
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
		return((Int32)0);
	}
}
