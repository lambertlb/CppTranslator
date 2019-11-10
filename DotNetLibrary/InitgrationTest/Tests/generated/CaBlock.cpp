#pragma once
#include "CaBlockHeader.h"
namespace MiniTest_NS
{
	Int64 ProgramRaw::x_maxInt64 = Int64::MaxValue;
	ProgramRaw::ProgramRaw()
	{
		x_bigNumber = -33;
		Int32 x_num = Int32::MaxValue;
		String x_text = "AB\t";
	}
	Int32 ProgramRaw::Main(PointerType<RawArray<String>> x_arvs)
	{
		PointerType<ProgramRaw> x_program = new ProgramRaw();
		return 0;
	}

}
