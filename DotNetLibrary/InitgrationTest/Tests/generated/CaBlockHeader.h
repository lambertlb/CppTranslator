#pragma once
#include "CaBlockProtos.h"
namespace MiniTest_NS
{
	class ProgramRaw : public ObjectRaw
	{
		public:
		ProgramRaw();
		void RefMethod(Int32&  x_data);
		static Int32 Main(PointerType<ArrayRaw<String>> x_arvs);
	};
}
