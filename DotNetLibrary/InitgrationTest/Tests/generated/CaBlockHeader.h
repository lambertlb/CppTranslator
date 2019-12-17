#pragma once
#include "CaBlockProtos.h"
namespace MiniTest_NS
{
	class Program : public Object
	{
		public:
		Array* x_double3dArray;
		Program();
		void CxAssert(Boolean x_isTrue);
		void CxAssert(Double x_x,Double x_y);
		static void Test1(Int32 x_aa);
		static Int32 Main(Array* x_arvs);
	};
}
namespace CABlock_NS
{
	class ArrayTest : public Object
	{
		public:
		CABlock* x_caBlock;
		Array* x_boolArray;
		Array* x_int1dArray;
		Array* x_int2dArray;
		Array* x_int3dArray;
		Array* x_double1dArray;
		Array* x_double2dArray;
		Array* x_double3dArray;
		Array* x_dateTime1dArray;
		Array* x_dateTime2dArray;
		Array* x_dateTime3dArray;
		Array* x_timeSpan1dArray;
		Array* x_timeSpan2dArray;
		Array* x_timeSpan3dArray;
		void TestArrayCreation();
		ArrayTest(CABlock* x_caBlock);
		void Test();
		void MiscTest();
		void ArrayMethodTests();
		void CxAssert(Boolean x_x);
		ArrayTest();
	};
	class CABlock : public Object
	{
		public:
		void Send(String* x_v);
		void TestFailed(String* x_v);
		CABlock();
	};
using namespace MiniTest_NS;
using namespace CABlock_NS;
}
