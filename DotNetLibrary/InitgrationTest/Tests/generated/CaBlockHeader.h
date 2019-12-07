#pragma once
#include "CaBlockProtos.h"
namespace MiniTest_NS
{
	class Program : public Object
	{
		public:
		Program();
		void CxAssert(Boolean x_isTrue);
		static Int32 Main(Array* x_arvs);
	};
using namespace MiniTest_NS;
}
