#pragma once
#include "CaBlockHeader.h"
namespace MiniTest_NS
{
	ProgramRaw::ProgramRaw()
	{
		x_dateTime1dArray = (new ArrayRaw<DateTime>(5));
		PointerType<ArrayRaw<DateTime>> x_destinationArray = (new ArrayRaw<DateTime>(5));
		ArrayBase::Copy(x_dateTime1dArray,x_destinationArray,x_dateTime1dArray->get_Length());
	}
	Int32 ProgramRaw::Main(PointerType<ArrayRaw<String>> x_arvs)
	{
		return 0;
	}

}
