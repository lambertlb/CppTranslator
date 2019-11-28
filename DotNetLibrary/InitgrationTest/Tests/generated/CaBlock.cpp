#pragma once
#include "CaBlockHeader.h"
namespace MiniTest_NS
{
	ProgramRaw::ProgramRaw()
	{
		String x_data = new StringRaw("Test");
		Boolean x_flag = x_data->Equals(nullptr);
		RefMethod(x_data);
		Boolean x_flag2 = x_data->Equals(new StringRaw("x"));
	}
	void ProgramRaw::RefMethod(String&  x_data)
	{
		if ( x_data->Equals(nullptr) )
		{
			x_data.Assign(new StringRaw("x"));
		}
	}
	Int32 ProgramRaw::Main(PointerType<ArrayRaw<String>> x_arvs)
	{
		return 0;
	}
}
