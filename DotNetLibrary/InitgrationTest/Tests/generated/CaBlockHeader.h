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

	struct TestStruct
	{
		Int32 x_data;
		Int32 get_Data();
		void set_Data(Int32 x_value );
		Int32 get_Data2();
		void set_Data2(Int32 x_value );
		TestStruct(Int32 x_i);
	};

}
