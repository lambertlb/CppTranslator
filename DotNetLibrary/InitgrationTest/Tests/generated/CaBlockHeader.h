#pragma once
#include "CaBlockProtos.h"
namespace MiniTest_NS
{
	class ProgramRaw : public ObjectRaw
	{
		public:
		PointerType<ArrayRaw<Int32>> x_int2dArray;
		PointerType<ArrayRaw<Int32>> x_int2dArraya;
		ProgramRaw();
		static Int32 Main(PointerType<ArrayRaw<String>> x_arvs);
	};

}
