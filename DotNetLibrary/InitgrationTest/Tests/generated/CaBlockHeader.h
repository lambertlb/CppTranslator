#pragma once
#include "CaBlockProtos.h"
namespace MiniTest_NS
{
	struct TestStruct2 : public Object
	{
		Int32 x_data;
		TestStruct2();
	};
	struct TestStruct3 : public Object
	{
		TestStruct2 x_ts;
		TestStruct3();
	};
}
namespace CABlock_NS
{
	class CABlock : public Object
	{
		public:
		void Send(String* x_v);
		void TestFailed(String* x_v);
		CABlock();
	};
}
namespace MiniTest_NS
{
	class Program : public Object
	{
		public:
		Int32 x_field1;
		Program();
		void CxAssert(Boolean x_isTrue);
		void CxAssert(Double x_x,Double x_y);
		static void Test1(Int32 x_aa);
		static Int32 Main(Array* x_arvs);
	};
using namespace MiniTest_NS;
using namespace CABlock_NS;
}
