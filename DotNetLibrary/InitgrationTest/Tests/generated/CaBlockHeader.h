#pragma once
#include "CaBlockProtos.h"
namespace MiniTest_NS
{
	class Program : public Object
	{
		public:
		void Run();
		void CxAssert(Boolean x_isTrue);
		void CxAssert(Double x_x,Double x_y);
		static Int32 Main(Array* x_arvs);
	};
}
namespace CABlock_NS
{
	class BooleanTest : public Object
	{
		public:
		CABlock* x_caBlock;
		BooleanTest(CABlock* x_caBlock);
		void Test();
		void BoolBoxTest();
		void RunBooleanTest();
		void BoolOperators();
		void CxAssert(Boolean x_x,Boolean x_y);
		void CxAssert(Boolean x_x);
	};
	class CABlock : public BlockBase
	{
		public:
		void TestFailed(String* x_v);
	};
}
using namespace MiniTest_NS;
using namespace CABlock_NS;
