#pragma once
#include "CaBlockHeader.h"
namespace MiniTest_NS
{
	ProgramRaw::ProgramRaw()
	{
		Int32 x_data = 0;
		RefMethod(x_data);
		Boolean x_flag = x_data == 1;
	}
	void ProgramRaw::RefMethod(Int32&  x_data)
	{
		if ( x_data == 0 )
		{
			x_data = 1;
		}
	}
	Int32 ProgramRaw::Main(PointerType<ArrayRaw<String>> x_arvs)
	{
		return 0;
	}
}
