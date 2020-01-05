#pragma once
#include "CaBlockProtos.h"
namespace CABlock_NS
{
	class CABlock : public BlockBase
	{
		public:
		void TestFailed(String* x_v);
	};
	class StringBuilderTest : public Object
	{
		public:
		CABlock* x_caBlock;
		StringBuilder* x_sb;
		StringBuilderTest(CABlock* x_caBlock);
		void Test();
		void DoSBConstructTest();
		void DoSBPropertyTest();
		void DoSBAppendTest();
		void DoSBMiscTest();
		void DoSBInsertTest();
		void DoSBReplaceTest();
		void CxAssert(Boolean x_x);
		void CxAssert(Boolean x_x,Boolean x_y);
	};
}
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
using namespace CABlock_NS;
using namespace MiniTest_NS;
