#pragma once
#include "CaBlockProtos.h"
namespace CABlock_NS
{
	class CABlock : public Object
	{
		public:
		void Send(String* x_v);
		void TestFailed(String* x_v);
	};
}
namespace MiniTest_NS
{
	class Program : public Object
	{
		public:
		static Int32 x_ss;
		Int32 x_jj;
		Program();
		Int32 Doit(Int32 x_x);
		static Boolean Program_Static();
		static Boolean Program_Initilized;
		void CxAssert(Boolean x_isTrue);
		void CxAssert(Double x_x,Double x_y);
		static void Test1(Int32 x_aa);
		static Int32 Main(Array* x_arvs);
	};
using namespace CABlock_NS;
using namespace MiniTest_NS;
}
