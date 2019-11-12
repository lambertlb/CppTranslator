#pragma once
#include "CaBlockHeader.h"
namespace MiniTest_NS
{
	ProgramRaw::ProgramRaw()
	{
		static Int32 ProgramArray0[2][4] = {{1,2,3,4},{4,5,6,7}};
		x_int2dArraya.Assign((new ArrayRaw<Int32>(2,2)));
		x_int2dArray.Assign((new ArrayRaw<Int32>(2,4))->Initialize((Int32*) ProgramArray0));
		*x_int2dArray->Address(0,2) = 3;
		Boolean x_flag = *x_int2dArray->Address(0,2) == 3;
		Boolean x_flag2 = *x_int2dArray->Address(0,3) == 4;
	}
	Int32 ProgramRaw::Main(PointerType<ArrayRaw<String>> x_arvs)
	{
		return 0;
	}

}
