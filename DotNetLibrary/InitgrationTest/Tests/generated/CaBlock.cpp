#pragma once
#include "CaBlockHeader.h"
namespace MiniTest_NS
{
	ProgramRaw::ProgramRaw()
	{
		Byte x_b = (( Byte ) 60);
		Int32 x_num = (( Int32 ) 1);
		x_num = x_num + x_b;
		CxAssert(x_num.Equals((( Int32 ) 61)));
	}
	void ProgramRaw::CxAssert(Boolean x_isTrue)
	{
	}
	Int32 ProgramRaw::Main(PointerType<ArrayRaw<String>> x_arvs)
	{
		PointerType<ProgramRaw> x_program = new ProgramRaw();
		return 0;
	}
}
