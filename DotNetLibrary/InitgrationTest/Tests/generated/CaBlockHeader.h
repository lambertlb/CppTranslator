#pragma once
#include "CaBlockProtos.h"
namespace MiniTest_NS
{
	class Program : public Object
	{
		public:
		String* x_name;
		Int32 get_Fred();
		void set_Fred(Int32 x_value );
		Int32 Fredk__BackingField;
		String* get_Name();
		void set_Name(String* x_value );
		Program();
		void CxAssert(Boolean x_isTrue);
		void CxAssert(Double x_x,Double x_y);
		static void Test1(Int32 x_aa);
		static Int32 Main(Array* x_arvs);
	};
using namespace MiniTest_NS;
}
