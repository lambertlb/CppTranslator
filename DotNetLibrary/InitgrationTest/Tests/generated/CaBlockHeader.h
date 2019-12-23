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
	class TimeTest : public Object
	{
		public:
		CABlock* x_caBlock;
		DateTime x_dat1;
		TimeTest(CABlock* x_caBlock);
		void Test();
		void TestTimeSpan();
		void TestDateTime();
		void DateTimeMethodTests();
		void TimeArrayTests();
		void DateTimeArrayTests();
		void TimeSpanArrayTests();
		void CxAssert(Double x_x,Double x_y);
		void CxAssert(Boolean x_x);
		void TimeTestFailed();
		TimeTest();
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
