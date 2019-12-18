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
	struct TestStruct : public Object
	{
		Int32 x_data;
		Int32 get_Data();
		void set_Data(Int32 x_value );
		TestStruct(Int32 x_i);
		static TestStruct op_Addition(TestStruct x_ts,Int32 x_newData);
		static TestStruct op_BitwiseAnd(TestStruct x_ts,Int32 x_newData);
		TestStruct();
	};
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
namespace UNNAMED
{
	class Typedef : public Object
	{
		public:
		TestNameEnu x_friend;
		TestNameEnu get_Friend();
		void set_Friend(TestNameEnu x_value );
		Typedef();
	};
	class Typedef1 : public Object
	{
		public:
		TestNameEnu x_friend();
		Typedef1();
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
}
namespace CABlock_Extra_NS
{
	class TestNamespaceClass : public Object
	{
		public:
		TestNamespaceClass();
	};
}
namespace CABlock_NS
{
	class BasicTest : public Object
	{
		public:
		CABlock* x_caBlock;
		Int32 x_field1;
		TestStruct3 x_ts3;
		BasicTest(CABlock* x_caBlock);
		void Test();
		void FieldTest();
		void SwitchTest();
		void IfThenElseTest();
		void StructTest();
		void StructTest2();
		void VirtualMethodTest();
		void PassByReferenceTest();
		void RefMethod(Int32&  x_data);
		void RefMethod(DateTime&  x_data);
		void RefMethod(TimeSpan&  x_data);
		void RefMethod(String*&  x_data);
		void RefMethod(TestAbstract*&  x_data);
		void TestUsingNamespace();
		void CxAssert(Boolean x_x);
		void ComplexConditions();
		Boolean TestThis(Int32 x_a,Int32 x_b);
		void TestNames();
		BasicTest();
	};
	class Abstract : public Object
	{
		public:
		Int32 x_data1;
		Int32 x_data2;
		Abstract(Int32 x_i,Int32 x_j);
		virtual Int32 MustImplement() = 0;
		virtual Int32 MustImplement(Int32 x_i) = 0;
		virtual Int32 MustImplement(Int64 x_i) = 0;
		Int32 DidImplement();
		Abstract();
	};
	class TestAbstract : public Abstract
	{
		public:
		TestAbstract();
		Int32 MustImplement();
		Int32 MustImplement(Int32 x_i);
		Int32 MustImplement(Int64 x_i);
		String* ToString();
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
using namespace UNNAMED;
using namespace CABlock_Extra_NS;
}
