#pragma once
#include "CaBlockHeader.h"
namespace MiniTest_NS
{
	Int64 ProgramRaw::x_maxInt64 = 9223372036854775807;
	ProgramRaw::ProgramRaw()
	{
		x_bigNumber = -33;
		Int32 x_num = 2147483647;
		String x_text = new StringRaw("AB\t");
	}
	Int32 ProgramRaw::Main(PointerType<ArrayRaw<String>> x_arvs)
	{
		PointerType<ProgramRaw> x_program = new ProgramRaw();
		return 0;
	}

}
