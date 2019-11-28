#pragma once
#include "CaBlockProtos.h"
namespace MiniTest_NS
{
	class ProgramRaw : public ObjectRaw
	{
		public:
		ProgramRaw();
		void RefMethod(String&  x_data);
		static Int32 Main(PointerType<ArrayRaw<String>> x_arvs);
	};
using namespace MiniTest_NS;
}
