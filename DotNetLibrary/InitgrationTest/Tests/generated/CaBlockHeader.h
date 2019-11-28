#pragma once
#include "CaBlockProtos.h"
namespace MiniTest_NS
{
	class ProgramRaw : public ObjectRaw
	{
		public:
		ProgramRaw();
		static Int32 Main(PointerType<ArrayRaw<String>> x_arvs);
	};
	class typedefRaw : public ObjectRaw
	{
		public:
		TestNameEnu x_friend;
		TestNameEnu get_Friend();
		void set_Friend(TestNameEnu x_value );
		typedefRaw();
	};
using namespace MiniTest_NS;
}
