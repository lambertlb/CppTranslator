#pragma once
#include "CaBlockHeader.h"
namespace MiniTest_NS
{
	ProgramRaw::ProgramRaw()
	{
		TestStruct x_testStruct = TestStruct(2);
		Boolean x_flag = x_testStruct.get_Data() == 2;
		x_testStruct.set_Data(3);
	}
	Int32 ProgramRaw::Main(PointerType<ArrayRaw<String>> x_arvs)
	{
		return 0;
	}

	Int32 TestStruct::get_Data()
	{
		return x_data;
	}
	void TestStruct::set_Data(Int32 x_value )
	{
		x_data = x_value;
	}
	Int32 TestStruct::get_Data2()
	{
		if ( x_data == 0 )
		{
			return x_data;
		}
		return -1;
	}
	void TestStruct::set_Data2(Int32 x_value )
	{
		if ( x_value == 0 )
		{
			x_data = x_value;
		}
		else
		{
			x_data = -1;
		}
	}
	TestStruct::TestStruct(Int32 x_i)
	{
		x_data = x_i;
	}

}
