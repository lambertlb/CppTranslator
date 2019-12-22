#pragma once
#include "CaBlockProtos.h"
namespace CABlock_NS
{
	class CABlock : public Object
	{
		public:
		void Send(String* x_v);
		void TestFailed(String* x_v);
		CABlock();
	};
	class StringTest : public Object
	{
		public:
		CABlock* x_caBlock;
		StringTest(CABlock* x_caBlock);
		void Test();
		void DoIndexTest();
		void DoMiscTest();
		static void TestConcat(String* x_str1,Int32 x_index,String* x_str4,Int32 x_i,Double x_dbl);
		void DoEqualsTest();
		void DoParsingTest();
		void DoConcatTest();
		void CxAssert(Boolean x_x);
		StringTest();
	};
}
namespace MiniTest_NS
{
	class Program : public Object
	{
		public:
		void CxAssert(Boolean x_isTrue);
		void CxAssert(Double x_x,Double x_y);
		static void Test1(Int32 x_aa);
		static Int32 Main(Array* x_arvs);
		Program();
	};
using namespace CABlock_NS;
using namespace MiniTest_NS;
}
