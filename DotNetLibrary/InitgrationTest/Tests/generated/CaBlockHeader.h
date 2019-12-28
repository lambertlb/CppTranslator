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
		ArrayTest(CABlock* x_caBlock);
		void Test();
		void TestArrayCreation();
		void MiscTest();
		void ArrayMethodTests();
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
