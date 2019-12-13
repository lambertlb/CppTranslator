#pragma once
#include "CaBlockHeader.h"
namespace UNNAMED
{
	TestNameEnu Typedef::get_Friend()
	{
		return(x_friend);
	}
	void Typedef::set_Friend(TestNameEnu x_value )
	{
		x_friend = x_value;
		return;
	}
	Typedef::Typedef()
	{
	}
	TestNameEnu Typedef1::x_friend()
	{
		return((TestNameEnu)0);
	}
	Typedef1::Typedef1()
	{
	}
}
namespace CABlock_Extra_NS
{
	TestNamespaceClass::TestNamespaceClass()
	{
	}
}
namespace CABlock_NS
{
	ArrayTest::ArrayTest(CABlock* x_caBlock)
	{
		x_dateTime2dArray = ;
		x_dateTime3dArray = ;
		x_timeSpan1dArray = ;
		x_timeSpan2dArray = ;
		x_timeSpan3dArray = ;
		
		x_caBlock = x_caBlock;
		return;
	}
	void ArrayTest::Test()
	{
		Int32 x_num = 0;
		Int32 x_num2 = 0;
		Int32 x_num3 = 0;
		Int32 x_num4 = ;
		CxAssert();
		x_caBlock->Send(new String(L"Doing ArrayTest"));
		x_caBlock->Send(new String(L"	Doing TestArrayCreation"));
		TestArrayCreation();
		x_caBlock->Send(new String(L"	Doing MiscTest"));
		MiscTest();
		x_caBlock->Send(new String(L"	Doing ArrayMethodTests"));
		ArrayMethodTests();
		return;
	}
	void ArrayTest::TestArrayCreation()
	{
		x_boolArray = ;
		x_int1dArray = ;
		CxAssert();
		x_int2dArray = ;
		CxAssert();
		x_int3dArray = ;
		CxAssert();
		x_double1dArray = ;
		CxAssert();
		x_double2dArray = ;
		CxAssert();
		x_double3dArray = ;
		CxAssert();
		x_dateTime1dArray = ;
		CxAssert(.Equals(new DateTime(2003, 7, 23, 12, 30, 30, 300)));
		 = new DateTime(2003, 7, 23, 12, 30, 30, 100);
		 = new DateTime(2003, 7, 23, 12, 30, 30, 100);
		 = ;
		 = new TimeSpan(5, 4, 3, 2, 100);
		 = new TimeSpan(5, 4, 3, 2, 200);
		 = new TimeSpan(5, 4, 3, 2, 300);
		 = new TimeSpan(5, 4, 3, 2, 400);
		 = new TimeSpan(5, 4, 3, 2, 100);
		 = new TimeSpan(5, 4, 3, 2, 100);
		return;
	}
	void ArrayTest::MiscTest()
	{
		CxAssert();
		CxAssert();
		CxAssert();
		Array* x_array = x_dateTime1dArray;
		Int32 x_i = 0;
		
		{
			
		}
		{
			DateTime x_dateTime = ;
			String* x_text = .ToString();
			
		}
		{
			Int32 x_i = ;
			
		}

		return;
	}
	void ArrayTest::ArrayMethodTests()
	{
		Int32 x_length = x_int3dArray->get_Length();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		Array* x_array = ;
		Array::Copy(x_dateTime1dArray, x_array, );
		Int32 x_i = 0;
		
		{
			
		}
		{
			DateTime x_d = ;
			DateTime x_d2 = ;
			CxAssert(DateTime::op_Equality(x_d, x_d2));
			
		}
		{
			Int32 x_i = ;
			
		}

		x_dateTime1dArray->CopyTo(x_array, 1);
		Int32 x_j = 1;
		
		{
			
		}
		{
			CxAssert(DateTime::op_Equality(, ));
			
		}
		{
			Int32 x_j = ;
			
		}

		CxAssert(->Equals(x_timeSpan3dArray->GetValue(1, 1, 1)));
		TimeSpan x_timeSpan = new TimeSpan(5, 4, 3, 2, 101);
		Array* x_indices = ;
		x_timeSpan3dArray->SetValue(, x_indices);
		CxAssert(->Equals(x_timeSpan3dArray->GetValue(x_indices)));
		 = 22;
		Double x_num = ;
		CxAssert();
		CxAssert(.Equals(x_double3dArray->GetValue(1, 1, 3)));
		x_timeSpan3dArray->SetValue(, 0, 0, 0);
		CxAssert(TimeSpan::op_Equality(, x_timeSpan));
		 = 1;
		CxAssert();
		Array::Clear(x_boolArray, 0, );
		CxAssert();
		x_int1dArray->SetValue(, 2);
		CxAssert();
		Array* x_array2 = ;
		x_array2->SetValue(, 1);
		CxAssert();
		x_array2->SetValue(, 1);
		CxAssert();
		return;
	}
	void ArrayTest::CxAssert(Boolean x_x)
	{
		
		return;
	}
	ArrayTest::ArrayTest()
	{
	}
	BasicTest::BasicTest(CABlock* x_caBlock)
	{
		x_field1 = 0;
		
		x_caBlock = x_caBlock;
		return;
	}
	void BasicTest::Test()
	{
		x_caBlock->Send(new String(L"Doing BasicTest"));
		x_caBlock->Send(new String(L"	Doing FieldTest"));
		FieldTest();
		x_caBlock->Send(new String(L"	Doing SwitchTest"));
		SwitchTest();
		x_caBlock->Send(new String(L"	Doing IfThenElseTest"));
		IfThenElseTest();
		x_caBlock->Send(new String(L"	Doing StructTest"));
		StructTest();
		x_caBlock->Send(new String(L"	Doing StructTest2"));
		StructTest2();
		x_caBlock->Send(new String(L"	Doing VirtualMethodTest"));
		VirtualMethodTest();
		x_caBlock->Send(new String(L"	Doing PassByReferenceTest"));
		PassByReferenceTest();
		x_caBlock->Send(new String(L"	Doing Namespace Test"));
		TestUsingNamespace();
		x_caBlock->Send(new String(L"	Doing Complex conditions"));
		ComplexConditions();
		x_caBlock->Send(new String(L"	Doing Naming test"));
		TestNames();
		return;
	}
	void BasicTest::FieldTest()
	{
		BasicTest* x_basicTest = new BasicTest(x_caBlock);
		Int32 x_num = x_field1;
		CxAssert();
		Int32 x_num2 = x_field1;
		CxAssert();
		DateTime x_maxValue = DateTime.MaxValue;
		CxAssert(DateTime::op_Equality(x_maxValue, DateTime.MaxValue));
		Object* x_obj = new Object();
		CxAssert();
		CxAssert(x_obj->Equals(x_obj));
		CxAssert(Object::Equals(x_obj, x_obj));
		return;
	}
	void BasicTest::SwitchTest()
	{
		x_field1 = 1;
		Int32 x_num = -1;
		
		{
			
		}
		{
			Int32 x_num = 100000;
			return;
		}
		{
			Int32 x_num = 1000;
			return;
		}
		{
			Int32 x_num = 1;
			return;
		}
		{
			Int32 x_num = 0;
			return;
		}

		CxAssert();
		CxAssert();
		return;
	}
	void BasicTest::IfThenElseTest()
	{
		x_field1 = 1;
		
		CxAssert();
		CxAssert(Object::Equals(, ));
		return;
	}
	void BasicTest::StructTest()
	{
		TestStruct x_ts = new TestStruct(2);
		CxAssert();
		.set_Data(3);
		CxAssert();
		
		CxAssert();
		CxAssert();
		return;
	}
	void BasicTest::StructTest2()
	{
		x_data = 6;
		CxAssert();
		x_data = 7;
		CxAssert();
		return;
	}
	void BasicTest::VirtualMethodTest()
	{
		TestAbstract* x_testAbstract = new TestAbstract();
		CxAssert();
		CxAssert();
		return;
	}
	void BasicTest::PassByReferenceTest()
	{
		Int32 x_data = 0;
		DateTime x_data2 = ;
		TimeSpan x_data3 = ;
		String* x_data4 = ;
		TestAbstract* x_data5 = ;
		RefMethod();
		CxAssert();
		RefMethod();
		CxAssert();
		RefMethod();
		CxAssert();
		RefMethod();
		CxAssert(String::op_Equality(x_data4, new String(L"Test")));
		RefMethod();
		CxAssert();
		return;
	}
	void BasicTest::RefMethod(Int32&  x_data)
	{
		
		return;
	}
	void BasicTest::RefMethod(DateTime&  x_data)
	{
		x_data = new DateTime();
		return;
	}
	void BasicTest::RefMethod(TimeSpan&  x_data)
	{
		x_data = new TimeSpan();
		return;
	}
	void BasicTest::RefMethod(String*&  x_data)
	{
		
		return;
	}
	void BasicTest::RefMethod(TestAbstract*&  x_data)
	{
		
		return;
	}
	void BasicTest::TestUsingNamespace()
	{
		TestNamespaceClass* x_testNamespaceClass = new TestNamespaceClass();
		CxAssert();
		return;
	}
	void BasicTest::CxAssert(Boolean x_x)
	{
		
		return;
	}
	void BasicTest::ComplexConditions()
	{
		x_field1 = 0;
		CxAssert();
		x_field1 = 10;
		CxAssert();
		x_field1 = 2;
		Boolean x_flag = ;
		Boolean x_flag2 = ;
		Boolean x_flag3 = ;
		Boolean x_flag4 = ;
		Boolean x_flag5 = ;
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert(TestThis(1, 2));
		CxAssert();
		CxAssert(TestThis(60, 2));
		return;
	}
	Boolean BasicTest::TestThis(Int32 x_a,Int32 x_b)
	{
		return((Boolean));
	}
	void BasicTest::TestNames()
	{
		Typedef* x_typedef = new Typedef();
		x_typedef->set_Friend(0);
		CxAssert();
		return;
	}
	BasicTest::BasicTest()
	{
	}
	TestAbstract::TestAbstract() : Abstract (1,2)
	{
		
		return;
	}
	Int32 TestAbstract::MustImplement()
	{
		return((Int32)x_data2);
	}
	Int32 TestAbstract::MustImplement(Int32 x_i)
	{
		return((Int32)x_data2);
	}
	Int32 TestAbstract::MustImplement(Int64 x_i)
	{
		return((Int32)x_data2);
	}
	String* TestAbstract::ToString()
	{
		return((String*)new String(L"TestAbstract"));
	}
	Int32 TestStruct::get_Data()
	{
		return((String*)x_data);
	}
	void TestStruct::set_Data(Int32 x_value )
	{
		x_data = x_value;
		return;
	}
	TestStruct::TestStruct(Int32 x_i)
	{
		x_data = x_i;
		return;
	}
	TestStruct operator +(TestStruct x_ts,Int32 x_newData)
	{
		
		return((TestStruct)x_ts);
	}
	TestStruct operator &(TestStruct x_ts,Int32 x_newData)
	{
		
		return((TestStruct)x_ts);
	}
	TestStruct::TestStruct()
	{
	}
	TestStruct2::TestStruct2()
	{
	}
	TestStruct3::TestStruct3()
	{
	}
	Abstract::Abstract(Int32 x_i,Int32 x_j)
	{
		
		x_data1 = x_i;
		x_data2 = x_j;
		return;
	}
	Int32 Abstract::DidImplement()
	{
		return((Int32)x_data1);
	}
	Abstract::Abstract()
	{
	}
	BooleanTest::BooleanTest(CABlock* x_caBlock)
	{
		
		x_caBlock = x_caBlock;
		return;
	}
	void BooleanTest::Test()
	{
		x_caBlock->Send(new String(L"Doing BooleanTest"));
		x_caBlock->Send(new String(L"	Doing RunBooleanTest"));
		RunBooleanTest();
		x_caBlock->Send(new String(L"	Doing BoolOperators"));
		BoolOperators();
		x_caBlock->Send(new String(L"	Doing BoolBoxTest"));
		BoolBoxTest();
		return;
	}
	void BooleanTest::BoolBoxTest()
	{
		Boolean x_flag = 1;
		Object* x_obj = ;
		CxAssert(.Equals(x_obj));
		CxAssert(x_obj->Equals(x_obj));
		CxAssert();
		CxAssert(String::op_Equality(x_obj->ToString(), new String(L"True")));
		return;
	}
	void BooleanTest::RunBooleanTest()
	{
		Boolean x_flag = 1;
		Object* x_obj = ;
		CxAssert();
		CxAssert();
		CxAssert(.Equals(1));
		CxAssert(Boolean::Parse(new String(L"True")));
		CxAssert(String::op_Equality(new String(L"True"), .ToString()));
		CxAssert(String::op_Equality(Boolean.FalseString, new String(L"False")));
		CxAssert(String::op_Equality(Boolean.TrueString, new String(L"True")));
		return;
	}
	void BooleanTest::BoolOperators()
	{
		Boolean x_flag = 1;
		Boolean x_flag2 = 0;
		CxAssert(, 0);
		CxAssert();
		CxAssert();
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert();
		CxAssert(, 0);
		CxAssert();
		CxAssert(x_flag = x_flag);
		CxAssert(x_flag = );
		CxAssert(x_flag = x_flag);
		return;
	}
	void BooleanTest::CxAssert(Boolean x_x,Boolean x_y)
	{
		
		return;
	}
	void BooleanTest::CxAssert(Boolean x_x)
	{
		
		return;
	}
	BooleanTest::BooleanTest()
	{
	}
	BufferTest::BufferTest(CABlock* x_caBlock)
	{
		
		x_caBlock = x_caBlock;
		return;
	}
	void BufferTest::Test()
	{
		x_caBlock->Send(new String(L"Doing Buffer Test"));
		x_in1dArray = ;
		x_out1dArray = ;
		Int32 x_count = ;
		Buffer::BlockCopy(x_in1dArray, 0, x_out1dArray, 0, x_count);
		Boolean x_x = 1;
		Int32 x_i = 0;
		
		{
			
		}
		{
			
			
		}
		{
			Int32 x_i = ;
			
		}

		CxAssert(x_x);
		return;
	}
	void BufferTest::CxAssert(Boolean x_x)
	{
		
		return;
	}
	BufferTest::BufferTest()
	{
	}
	ByteTest::ByteTest(CABlock* x_caBlock)
	{
		
		x_caBlock = x_caBlock;
		return;
	}
	void ByteTest::Test()
	{
		x_caBlock->Send(new String(L"Doing ByteTest"));
		x_caBlock->Send(new String(L"	Doing ByteMethodsTest"));
		ByteMethodsTest();
		x_caBlock->Send(new String(L"	Doing DoUnSignedMath"));
		DoUnSignedMath();
		x_caBlock->Send(new String(L"	Doing ByteOperators"));
		ByteOperators();
		x_caBlock->Send(new String(L"	Doing ByteArrayTests"));
		ByteArrayTests();
		x_caBlock->Send(new String(L"	Doing ByteMiscTests"));
		ByteMiscTests();
		return;
	}
	void ByteTest::ByteMethodsTest()
	{
		Byte x_b = 5;
		CxAssert();
		CxAssert();
		CxAssert(.Equals(5));
		CxAssert(.Equals());
		CxAssert();
		CxAssert(String::op_Equality(new String(L"5"), .ToString()));
		x_b = 255;
		CxAssert();
		x_b = 0;
		CxAssert();
		String* x_text = .ToString();
		CxAssert(String::op_Equality(x_text, new String(L"255")));
		CxAssert();
		String* x_text2 = .ToString();
		CxAssert(String::op_Equality(x_text2, new String(L"0")));
		CxAssert();
		Int32 x_num = 50;
		Byte x_b2 = ;
		Object* x_obj = ;
		Int32 x_num2 = ;
		CxAssert();
		CxAssert();
		x_b2 = 255;
		x_b2 = ;
		CxAssert();
		Object* x_obj2 = ;
		CxAssert(x_obj2->Equals());
		CxAssert(String::op_Equality(x_obj2->ToString(), new String(L"5")));
		return;
	}
	void ByteTest::DoUnSignedMath()
	{
		Byte x_b = 60;
		Byte x_b2 = 120;
		Byte x_b3 = 6;
		Byte x_b4 = 12;
		Int32 x_num = 1;
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		x_num = ;
		CxAssert();
		CxAssert();
		Byte x_b5 = ;
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		Int32 x_num2 = 11;
		CxAssert();
		x_num2 = 8;
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		Byte x_b6 = 0;
		CxAssert();
		CxAssert();
		CxAssert();
		return;
	}
	void ByteTest::ByteOperators()
	{
		Byte x_b = 66;
		Char x_c = 1;
		Byte x_b2 = 1;
		SByte x_b3 = 1;
		Int16 x_num = 1;
		Int32 x_num2 = 1;
		Int64 x_num3 = ;
		UInt16 x_num4 = 1;
		UInt32 x_num5 = 1;
		UInt64 x_num6 = ;
		Single x_num7 = 1;
		Double x_num8 = 1;
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		x_b = 66;
		CxAssert();
		x_b = 66;
		CxAssert();
		x_b = 66;
		CxAssert();
		x_b = 66;
		CxAssert();
		x_b = 66;
		CxAssert();
		x_b = 66;
		CxAssert();
		x_b = 66;
		CxAssert();
		x_b = 66;
		CxAssert();
		x_b = 66;
		CxAssert();
		x_b = 66;
		CxAssert();
		x_b = 66;
		CxAssert();
		x_b = 66;
		Char x_c2 = 66;
		CxAssert();
		return;
	}
	void ByteTest::ByteArrayTests()
	{
		Array* x_array = ;
		Array* x_array2 = ;
		Int32 x_i = 0;
		
		{
			
		}
		{
			 = ;
			
		}
		{
			Int32 x_i = ;
			
		}

		Int32 x_j = 0;
		
		{
			
		}
		{
			 = ;
			
		}
		{
			Int32 x_j = ;
			
		}

		CxAssert();
		CxAssert();
		Int32 x_k = 0;
		
		{
			
		}
		{
			 = 1;
			
		}
		{
			Int32 x_k = ;
			
		}

		Array* x_array3 = ;
		Buffer::BlockCopy(x_array, 0, x_array3, 0, 10);
		Buffer::BlockCopy(x_array, 0, x_array3, 10, 10);
		Buffer::BlockCopy(x_array, 0, x_array3, 20, 10);
		Buffer::BlockCopy(x_array, 0, x_array3, 30, 10);
		CxAssert();
		CxAssert();
		Array* x_array4 = ;
		CxAssert();
		CxAssert();
		Array* x_array5 = ;
		CxAssert();
		Array* x_array6 = ;
		CxAssert();
		Array* x_array7 = ;
		CxAssert();
		 = 6;
		CxAssert();
		x_array7->SetValue(, 0, 0, 3);
		CxAssert();
		return;
	}
	void ByteTest::ByteMiscTests()
	{
		Byte x_b = 0;
		Byte x_val = 1;
		CxAssert();
		CxAssert();
		StringBuilder* x_stringBuilder = new StringBuilder();
		x_stringBuilder->Append(x_b);
		CxAssert(String::op_Equality(x_stringBuilder->ToString(), new String(L"0")));
		x_stringBuilder->Insert(1, x_b);
		CxAssert(String::op_Equality(x_stringBuilder->ToString(), new String(L"00")));
		return;
	}
	void ByteTest::CxAssert(Boolean x_x)
	{
		
		return;
	}
	void ByteTest::CxAssert(Boolean x_x,Boolean x_y)
	{
		
		return;
	}
	ByteTest::ByteTest()
	{
	}
	CharTest::CharTest(CABlock* x_caBlock)
	{
		
		x_caBlock = x_caBlock;
		return;
	}
	void CharTest::Test()
	{
		x_caBlock->Send(new String(L"Doing CharTest"));
		x_caBlock->Send(new String(L"	Doing CharMethodsTest"));
		CharMethodsTest();
		x_caBlock->Send(new String(L"	Doing CharOperators"));
		CharOperators();
		x_caBlock->Send(new String(L"	Doing CharArrayTest"));
		CharArrayTests();
		x_caBlock->Send(new String(L"	Doing CharMiscTests"));
		CharMiscTests();
		return;
	}
	void CharTest::CharMethodsTest()
	{
		String* x_s = new String(L"123aBc	
. ");
		Char x_c = 65;
		CxAssert();
		CxAssert(.Equals(65));
		Double x_numericValue = Char::GetNumericValue(53);
		CxAssert();
		x_numericValue = Char::GetNumericValue(x_s, 2);
		CxAssert();
		CxAssert(Char::IsControl(9));
		CxAssert(Char::IsControl(x_s, 7));
		CxAssert(Char::IsDigit(49));
		CxAssert(Char::IsDigit(x_s, 2));
		CxAssert(Char::IsLetter(97));
		CxAssert(Char::IsLetter(x_s, 3));
		CxAssert(Char::IsLetterOrDigit(97));
		CxAssert(Char::IsLetterOrDigit(x_s, 3));
		CxAssert(Char::IsLower(97));
		CxAssert(Char::IsLower(x_s, 3));
		CxAssert(Char::IsNumber(49));
		CxAssert(Char::IsNumber(x_s, 2));
		CxAssert(Char::IsPunctuation(44));
		CxAssert(Char::IsPunctuation(x_s, 8));
		CxAssert(Char::IsSeparator(32));
		CxAssert(Char::IsSeparator(x_s, 9));
		CxAssert(Char::IsUpper(66));
		CxAssert(Char::IsUpper(x_s, 4));
		CxAssert(Char::IsWhiteSpace(32));
		CxAssert(Char::IsWhiteSpace(x_s, 9));
		CxAssert();
		CxAssert();
		CxAssert(new String(L"a")->Equals(.ToString()));
		CxAssert(new String(L"a")->Equals(Char::ToString(97)));
		CxAssert(.Equals(Char::Parse(new String(L"a"))));
		Object* x_obj = ;
		CxAssert(.Equals());
		CxAssert(.Equals(x_obj));
		CxAssert();
		CxAssert(String::op_Equality(x_obj->ToString(), new String(L"A")));
		return;
	}
	void CharTest::CharOperators()
	{
		Char x_c = 66;
		Char x_c2 = 1;
		Int32 x_num = 1;
		UInt32 x_num2 = 1;
		Int64 x_num3 = ;
		Double x_num4 = 1;
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		x_c = 66;
		CxAssert();
		x_c = 66;
		CxAssert();
		x_c = 66;
		CxAssert();
		x_c = 66;
		CxAssert();
		x_c = 66;
		CxAssert();
		x_c = 66;
		CxAssert();
		return;
	}
	void CharTest::CharArrayTests()
	{
		Array* x_array = ;
		CxAssert();
		CxAssert();
		Array* x_array2 = ;
		CxAssert();
		Array* x_array3 = ;
		CxAssert();
		Array* x_array4 = ;
		CxAssert();
		 = 54;
		CxAssert();
		x_array4->SetValue(, 0, 0, 3);
		CxAssert();
		return;
	}
	void CharTest::CharMiscTests()
	{
		Char x_c = 48;
		Char x_val = 49;
		CxAssert();
		CxAssert();
		StringBuilder* x_stringBuilder = new StringBuilder();
		x_stringBuilder->Append(x_c);
		CxAssert(String::op_Equality(x_stringBuilder->ToString(), new String(L"0")));
		return;
	}
	void CharTest::CxAssert(Boolean x_x)
	{
		
		return;
	}
	void CharTest::CxAssert(Boolean x_x,Boolean x_y)
	{
		
		return;
	}
	CharTest::CharTest()
	{
	}
	DoubleTest::DoubleTest(CABlock* x_caBlock)
	{
		
		x_caBlock = x_caBlock;
		return;
	}
	void DoubleTest::Test()
	{
		x_caBlock->Send(new String(L"Doing DoubleTest"));
		x_caBlock->Send(new String(L"	Doing DoDoubleMethodsTest"));
		DoDoubleMethodsTest();
		x_caBlock->Send(new String(L"	Doing DoDoubleMath"));
		DoDoubleMath();
		x_caBlock->Send(new String(L"	Doing DoubleOperators"));
		DoubleOperators();
		x_caBlock->Send(new String(L"	Doing DoubleNanTest"));
		DoubleNanTest();
		x_caBlock->Send(new String(L"	Doing DoubleArrayTest"));
		DoubleArrayTest();
		x_caBlock->Send(new String(L"	Doing DoubleMiscTests"));
		DoubleMiscTests();
		return;
	}
	void DoubleTest::DoDoubleMethodsTest()
	{
		Double x_num = 3.159;
		CxAssert();
		CxAssert();
		CxAssert(.Equals(3.159));
		CxAssert();
		CxAssert(String::op_Equality(.ToString(), new String(L"3.159")));
		String* x_text = .ToString();
		CxAssert();
		x_num = 1000000000001;
		CxAssert();
		x_num = -1000000000000;
		CxAssert();
		x_num = 10000;
		CxAssert();
		CxAssert();
		CxAssert();
		Object* x_obj = ;
		CxAssert();
		x_num = 4.94065645841247E-324;
		CxAssert();
		x_num = 1.79769313486232E+308;
		CxAssert();
		x_num = -1.79769313486232E+308;
		CxAssert();
		x_obj = ;
		CxAssert(x_obj->Equals());
		CxAssert(String::op_Equality(x_obj->ToString(), new String(L"5")));
		return;
	}
	void DoubleTest::DoDoubleMath()
	{
		Double x_num = 355;
		Double x_num2 = 113;
		Double x_num3 = ;
		CxAssert(x_num3, 3.14159);
		CxAssert(, 355);
		CxAssert(, 468);
		CxAssert(, 242);
		x_num = 2;
		x_num2 = ;
		CxAssert();
		x_num = 2;
		x_num2 = ;
		CxAssert();
		return;
	}
	void DoubleTest::DoubleOperators()
	{
		Double x_num = 66;
		Char x_c = 1;
		Int32 x_num2 = 1;
		UInt32 x_num3 = 1;
		Int64 x_num4 = ;
		Double x_num5 = 1;
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		x_num = 66;
		CxAssert();
		x_num = 5;
		CxAssert(, 0.6);
		return;
	}
	void DoubleTest::DoubleNanTest()
	{
		Double x_num = NaN;
		Double x_num2 = 1;
		CxAssert(Double::IsNaN(x_num));
		CxAssert(Double::IsInfinity(∞));
		CxAssert(Double::IsNegativeInfinity(-∞));
		CxAssert(Double::IsPositiveInfinity(∞));
		CxAssert(Double::IsNaN());
		CxAssert(Double::IsNaN());
		CxAssert(Double::IsNaN());
		CxAssert(Double::IsNaN());
		CxAssert(Double::IsNaN());
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert();
		CxAssert();
		x_num = NaN;
		x_num2 = NaN;
		
		
		
		
		
		
		
		
		
		CxAssert(.Equals(NaN));
		return;
	}
	void DoubleTest::DoubleArrayTest()
	{
		Array* x_array = ;
		CxAssert();
		Array* x_array2 = ;
		CxAssert();
		Array* x_array3 = ;
		CxAssert();
		 = 22;
		CxAssert();
		 = NaN;
		CxAssert(Double::IsNaN());
		x_array3->SetValue(, 0, 0, 3);
		CxAssert();
		return;
	}
	void DoubleTest::DoubleMiscTests()
	{
		Double x_num = -1;
		Double x_val = 1;
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		StringBuilder* x_stringBuilder = new StringBuilder();
		x_stringBuilder->Append(x_num);
		CxAssert(String::op_Equality(x_stringBuilder->ToString(), new String(L"-1")));
		return;
	}
	void DoubleTest::DoubleCompare(Double x_n1,Double x_n2,Double x_resolution)
	{
		
		return;
	}
	void DoubleTest::CxAssert(Double x_x,Double x_y)
	{
		DoubleCompare(x_x, x_y, 1E-05);
		return;
	}
	void DoubleTest::CxAssert(Boolean x_x)
	{
		
		return;
	}
	void DoubleTest::CxAssert(Boolean x_x,Boolean x_y)
	{
		
		return;
	}
	void DoubleTest::DoubleTestFailed()
	{
		x_caBlock->TestFailed(new String(L"Double TestFailed"));
		return;
	}
	DoubleTest::DoubleTest()
	{
	}
	EncodingTest::EncodingTest(CABlock* x_caBlock)
	{
		
		x_caBlock = x_caBlock;
		return;
	}
	void EncodingTest::Test()
	{
		x_caBlock->Send(new String(L"Doing EncodingTest"));
		x_caBlock->Send(new String(L"	Doing EncodingMethodsTest"));
		EncodingMethodsTest();
		return;
	}
	void EncodingTest::EncodingMethodsTest()
	{
		String* x_s = new String(L"TestΔΖΟ");
		Array* x_myCharsAsBytes = ;
		Encoding* x_aSCII = Encoding::get_ASCII();
		CxAssert();
		Array* x_bytes = x_aSCII->GetBytes(x_s);
		CxAssert(CompareBytes(x_bytes, x_myCharsAsBytes));
		String* x_string = x_aSCII->GetString(x_bytes);
		CxAssert(String::op_Equality(x_string, new String(L"Test???")));
		String* x_s2 = new String(L"123ЮЋЯЃМТѤѠѪѺ");
		CxAssert();
		Array* x_bytes2 = x_aSCII->GetBytes(x_s2);
		String* x_string2 = x_aSCII->GetString(x_bytes2);
		CxAssert(String::op_Equality(x_string2, new String(L"123??????????")));
		return;
	}
	Boolean EncodingTest::CompareBytes(Array* x_bytes,Array* x_myCharsAsBytes)
	{
		Int32 x_i = 0;
		
		{
			
		}
		{
			
			
		}
		{
			Int32 x_i = ;
			
		}

		return((Boolean)1);
	}
	void EncodingTest::CxAssert(Boolean x_x)
	{
		
		return;
	}
	EncodingTest::EncodingTest()
	{
	}
	EnumTest::EnumTest(CABlock* x_caBlock)
	{
		
		x_caBlock = x_caBlock;
		return;
	}
	void EnumTest::Test()
	{
		x_caBlock->Send(new String(L"Doing EnumTest"));
		Test1(1);
		Test1(1);
		return;
	}
	void EnumTest::Test1(TestEnum x_testEnum)
	{
		
		
		
		Int32 x_num = x_testEnum;
		
		Double x_num2 = ;
		
		return;
	}
	void EnumTest::Test1(TestEnum2 x_testEnum)
	{
		
		
		
		Int32 x_num = x_testEnum;
		
		Double x_num2 = ;
		
		return;
	}
	void EnumTest::EnumTestFailed()
	{
		x_caBlock->TestFailed(new String(L"Enum TestFailed"));
		return;
	}
	EnumTest::EnumTest()
	{
	}
	Int32 CABlock::x_intConstant = 8;
	CABlock::CABlock()
	{
		
		return;
	}
	CABlock::CABlock(Int32 x_i)
	{
		
		return;
	}
	void CABlock::Initialize()
	{
		x_fe = 1;
		return;
	}
	void CABlock::Execute()
	{
		RunTests(x_fe);
		return;
	}
	void CABlock::RunTests(FredEnum x_fre)
	{
		BasicTest* x_basicTest = new BasicTest();
		x_basicTest->Test();
		MathTest* x_mathTest = new MathTest();
		x_mathTest->Test();
		ArrayTest* x_arrayTest = new ArrayTest();
		x_arrayTest->Test();
		StringTest* x_stringTest = new StringTest();
		x_stringTest->Test();
		EnumTest* x_enumTest = new EnumTest();
		x_enumTest->Test();
		TimeTest* x_timeTest = new TimeTest();
		x_timeTest->Test();
		CharTest* x_charTest = new CharTest();
		x_charTest->Test();
		BooleanTest* x_booleanTest = new BooleanTest();
		x_booleanTest->Test();
		Int32Test* x_int32Test = new Int32Test();
		x_int32Test->Test();
		UInt32Test* x_uInt32Test = new UInt32Test();
		x_uInt32Test->Test();
		Int64Test* x_int64Test = new Int64Test();
		x_int64Test->Test();
		DoubleTest* x_doubleTest = new DoubleTest();
		x_doubleTest->Test();
		StringBuilderTest* x_stringBuilderTest = new StringBuilderTest();
		x_stringBuilderTest->Test();
		BufferTest* x_bufferTest = new BufferTest();
		x_bufferTest->Test();
		ByteTest* x_byteTest = new ByteTest();
		x_byteTest->Test();
		SByteTest* x_sByteTest = new SByteTest();
		x_sByteTest->Test();
		Int16Test* x_int16Test = new Int16Test();
		x_int16Test->Test();
		SingleTest* x_singleTest = new SingleTest();
		x_singleTest->Test();
		UInt16Test* x_uInt16Test = new UInt16Test();
		x_uInt16Test->Test();
		UInt64Test* x_uInt64Test = new UInt64Test();
		x_uInt64Test->Test();
		EncodingTest* x_encodingTest = new EncodingTest();
		x_encodingTest->Test();
		return;
	}
	void CABlock::TestFailed(String* x_reason)
	{
		Send(String::Concat(new String(L"		ERROR: "), x_reason));
		return;
	}
	Int16Test::Int16Test(CABlock* x_caBlock)
	{
		
		x_caBlock = x_caBlock;
		return;
	}
	void Int16Test::Test()
	{
		x_caBlock->Send(new String(L"Doing Int16Test"));
		x_caBlock->Send(new String(L"	Doing Int16MethodsTest"));
		Int16MethodsTest();
		x_caBlock->Send(new String(L"	Doing Int16MathTest"));
		Int16MathTest();
		x_caBlock->Send(new String(L"	Doing Int16Operators"));
		Int16Operators();
		x_caBlock->Send(new String(L"	Doing Int16ArrayTests"));
		Int16ArrayTests();
		x_caBlock->Send(new String(L"	Doing Int16MiscTests"));
		Int16MiscTests();
		return;
	}
	void Int16Test::Int16MethodsTest()
	{
		Int16 x_num = 5;
		CxAssert();
		CxAssert();
		CxAssert(.Equals(5));
		CxAssert(.Equals());
		CxAssert();
		CxAssert(String::op_Equality(new String(L"-75"), .ToString()));
		String* x_text = .ToString();
		CxAssert(String::op_Equality(x_text, new String(L"32767")));
		CxAssert();
		String* x_text2 = .ToString();
		CxAssert(String::op_Equality(x_text2, new String(L"-32768")));
		CxAssert();
		Int64 x_num2 = 9223372036854775807;
		x_num = ;
		CxAssert();
		Object* x_obj = ;
		CxAssert(x_obj->Equals());
		CxAssert(String::op_Equality(x_obj->ToString(), new String(L"5")));
		return;
	}
	void Int16Test::Int16MathTest()
	{
		Int16 x_num = 600;
		Int16 x_num2 = 1200;
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		Int32 x_num3 = 11;
		CxAssert();
		x_num3 = 8;
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		x_num3 = 0;
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		return;
	}
	void Int16Test::Int16Operators()
	{
		Int16 x_num = 66;
		Char x_c = 1;
		Byte x_b = 1;
		SByte x_b2 = 1;
		Int16 x_num2 = 1;
		Int32 x_num3 = 1;
		Int64 x_num4 = ;
		UInt16 x_num5 = 1;
		UInt32 x_num6 = 1;
		Single x_num7 = 1;
		Double x_num8 = 1;
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		x_num = 66;
		CxAssert();
		x_num = 66;
		CxAssert();
		x_num = 66;
		CxAssert();
		x_num = 66;
		CxAssert();
		x_num = 66;
		CxAssert();
		x_num = 66;
		CxAssert();
		x_num = 66;
		CxAssert();
		x_num = 66;
		CxAssert();
		x_num = 66;
		CxAssert();
		x_num = 66;
		CxAssert();
		x_num = 66;
		CxAssert();
		x_num = 66;
		CxAssert();
		x_num = 66;
		CxAssert();
		x_num = 66;
		Int16 x_num9 = 0;
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		return;
	}
	void Int16Test::Int16ArrayTests()
	{
		Array* x_array = ;
		CxAssert();
		CxAssert();
		Array* x_array2 = ;
		CxAssert();
		Array* x_array3 = ;
		CxAssert();
		Array* x_array4 = ;
		CxAssert();
		 = 6;
		CxAssert();
		x_array4->SetValue(, 0, 0, 3);
		CxAssert();
		return;
	}
	void Int16Test::Int16MiscTests()
	{
		Int16 x_num = -1;
		Int16 x_val = 1;
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		StringBuilder* x_stringBuilder = new StringBuilder();
		x_stringBuilder->Append(x_num);
		CxAssert(String::op_Equality(x_stringBuilder->ToString(), new String(L"-1")));
		x_stringBuilder->Insert(2, x_num);
		CxAssert(String::op_Equality(x_stringBuilder->ToString(), new String(L"-1-1")));
		return;
	}
	void Int16Test::CxAssert(Boolean x_x)
	{
		
		return;
	}
	void Int16Test::CxAssert(Boolean x_x,Boolean x_y)
	{
		
		return;
	}
	Int16Test::Int16Test()
	{
	}
	Int32Test::Int32Test(CABlock* x_caBlock)
	{
		
		x_caBlock = x_caBlock;
		return;
	}
	void Int32Test::Test()
	{
		x_caBlock->Send(new String(L"Doing Int32Test"));
		x_caBlock->Send(new String(L"	Doing Int32MethodsTest"));
		Int32MethodsTest();
		x_caBlock->Send(new String(L"	Doing Int32MathTest"));
		Int32MathTest();
		x_caBlock->Send(new String(L"	Doing Int32Operators"));
		Int32Operators();
		x_caBlock->Send(new String(L"	Doing Int32Conversion"));
		Int32Conversion();
		x_caBlock->Send(new String(L"	Doing Int32ArrayTests"));
		Int32ArrayTests();
		x_caBlock->Send(new String(L"	Doing Int32MiscTests"));
		Int32MiscTests();
		return;
	}
	void Int32Test::Int32Conversion()
	{
		Double x_num = 1;
		Double x_num2 = 2;
		
		Int32 x_num3 = ;
		CxAssert();
		return;
	}
	void Int32Test::Int32MethodsTest()
	{
		Int32 x_num = 5;
		CxAssert();
		CxAssert();
		CxAssert(.Equals(5));
		CxAssert(.Equals());
		CxAssert();
		CxAssert(String::op_Equality(new String(L"-75"), .ToString()));
		String* x_text = .ToString();
		CxAssert(String::op_Equality(x_text, new String(L"2147483647")));
		CxAssert();
		String* x_text2 = .ToString();
		CxAssert(String::op_Equality(x_text2, new String(L"-2147483648")));
		CxAssert();
		Int64 x_num2 = 9223372036854775807;
		x_num = ;
		CxAssert();
		Object* x_obj = ;
		CxAssert(x_obj->Equals());
		return;
	}
	void Int32Test::Int32MathTest()
	{
		Int32 x_num = 60000;
		Int32 x_num2 = 120000;
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		Int32 x_num3 = 11;
		CxAssert();
		x_num3 = 8;
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		x_num3 = 0;
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		return;
	}
	void Int32Test::Int32Operators()
	{
		Int32 x_num = 66;
		Char x_c = 1;
		Int32 x_num2 = 1;
		UInt32 x_num3 = 1;
		Int64 x_num4 = ;
		Double x_num5 = 1;
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		x_num = 66;
		CxAssert();
		x_num = 66;
		CxAssert();
		x_num = 66;
		CxAssert();
		x_num = 66;
		CxAssert();
		x_num = 66;
		CxAssert();
		x_num = 66;
		CxAssert();
		x_num = 66;
		CxAssert();
		x_num = 66;
		CxAssert();
		x_num = 66;
		CxAssert();
		x_num = 66;
		CxAssert();
		x_num = 66;
		CxAssert();
		x_num = 66;
		Int32 x_num6 = 0;
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		return;
	}
	void Int32Test::Int32ArrayTests()
	{
		Array* x_array = ;
		CxAssert();
		CxAssert();
		Array* x_array2 = ;
		CxAssert();
		Array* x_array3 = ;
		CxAssert();
		Array* x_array4 = ;
		CxAssert();
		 = 6;
		CxAssert();
		x_array4->SetValue(, 0, 0, 3);
		CxAssert();
		CxAssert(String::op_Equality(.ToString(), new String(L"4")));
		return;
	}
	void Int32Test::Int32MiscTests()
	{
		Int32 x_num = -1;
		Int32 x_val = 1;
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		StringBuilder* x_stringBuilder = new StringBuilder();
		x_stringBuilder->Append(x_num);
		CxAssert(String::op_Equality(x_stringBuilder->ToString(), new String(L"-1")));
		return;
	}
	void Int32Test::CxAssert(Boolean x_x)
	{
		
		return;
	}
	void Int32Test::CxAssert(Boolean x_x,Boolean x_y)
	{
		
		return;
	}
	Int32Test::Int32Test()
	{
	}
	Int64Test::Int64Test(CABlock* x_caBlock)
	{
		
		x_caBlock = x_caBlock;
		return;
	}
	void Int64Test::Test()
	{
		x_caBlock->Send(new String(L"Doing Int64Test"));
		x_caBlock->Send(new String(L"	Doing Int64MethodsTest"));
		Int64MethodsTest();
		x_caBlock->Send(new String(L"	Doing Int64MathTest"));
		Int64MathTest();
		x_caBlock->Send(new String(L"	Doing Int64Operators"));
		Int64Operators();
		x_caBlock->Send(new String(L"	Doing Int64ArrayTests"));
		Int64ArrayTests();
		x_caBlock->Send(new String(L"	Doing Int64MiscTests"));
		Int64MiscTests();
		return;
	}
	void Int64Test::Int64MethodsTest()
	{
		Int64 x_num = ;
		CxAssert();
		CxAssert();
		CxAssert(.Equals());
		CxAssert(.Equals());
		CxAssert();
		String* x_text = .ToString();
		CxAssert(String::op_Equality(x_text, new String(L"9223372036854775807")));
		CxAssert();
		String* x_text2 = .ToString();
		CxAssert(String::op_Equality(x_text2, new String(L"-9223372036854775808")));
		CxAssert();
		Object* x_obj = ;
		CxAssert(x_obj->Equals());
		CxAssert(String::op_Equality(x_obj->ToString(), new String(L"5")));
		return;
	}
	void Int64Test::Int64MathTest()
	{
		Int64 x_num = ;
		Int64 x_num2 = ;
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		Int32 x_num3 = 11;
		CxAssert();
		x_num3 = 8;
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		x_num3 = 0;
		CxAssert();
		CxAssert();
		CxAssert();
		return;
	}
	void Int64Test::Int64Operators()
	{
		Int64 x_num = ;
		Char x_c = 1;
		Int32 x_num2 = 1;
		UInt32 x_num3 = 1;
		Int64 x_num4 = ;
		Double x_num5 = 1;
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		x_num = ;
		CxAssert();
		x_num = ;
		CxAssert();
		x_num = ;
		CxAssert();
		x_num = ;
		CxAssert();
		x_num = ;
		CxAssert();
		x_num = ;
		CxAssert();
		x_num = ;
		CxAssert();
		x_num = ;
		CxAssert();
		x_num = ;
		CxAssert();
		x_num = ;
		CxAssert();
		x_num = ;
		CxAssert();
		x_num = ;
		CxAssert();
		x_num = ;
		CxAssert();
		x_num = ;
		CxAssert();
		x_num = ;
		CxAssert();
		x_num = ;
		CxAssert();
		x_num = ;
		CxAssert();
		x_num = ;
		CxAssert();
		x_num = ;
		return;
	}
	void Int64Test::Int64ArrayTests()
	{
		Array* x_array = ;
		CxAssert();
		CxAssert();
		Array* x_array2 = ;
		CxAssert();
		Array* x_array3 = ;
		CxAssert();
		Array* x_array4 = ;
		CxAssert();
		 = ;
		CxAssert();
		x_array4->SetValue(, 0, 0, 3);
		CxAssert();
		return;
	}
	void Int64Test::Int64MiscTests()
	{
		Int64 x_num = ;
		Int64 x_val = ;
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		StringBuilder* x_stringBuilder = new StringBuilder();
		x_stringBuilder->Append(x_num);
		CxAssert(String::op_Equality(x_stringBuilder->ToString(), new String(L"-1")));
		return;
	}
	void Int64Test::CxAssert(Boolean x_x)
	{
		
		return;
	}
	void Int64Test::CxAssert(Boolean x_x,Boolean x_y)
	{
		
		return;
	}
	Int64Test::Int64Test()
	{
	}
	MathTest::MathTest(CABlock* x_caBlock)
	{
		
		x_caBlock = x_caBlock;
		return;
	}
	void MathTest::Test()
	{
		x_caBlock->Send(new String(L"Doing MathTest"));
		DoMathTest();
		return;
	}
	void MathTest::DoMathTest()
	{
		CxAssert(Math::Abs(-1), 1);
		CxAssert(Math::Abs(1), 1);
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert(Math::Acos(0.5), 1.0471975511966);
		CxAssert(Math::Asin(0.5), 0.523598775598299);
		CxAssert(Math::Atan(0.5), 0.463647609000806);
		CxAssert(Math::Atan2(2, 1), 1.10714871779409);
		CxAssert(Math::Ceiling(1.1), 2);
		CxAssert(Math::Cos(0.5), 0.877582561890373);
		CxAssert(Math::Cosh(0.5), 1.12762596520638);
		CxAssert(Math::Exp(0.5), 1.64872127070013);
		CxAssert(Math::Floor(1.1), 1);
		CxAssert(Math::Log(0.5), -0.693147180559945);
		CxAssert(Math::Log(0.4, 0.5), 1.32192809488736);
		CxAssert(Math::Log10(0.5), -0.301029995663981);
		CxAssert(Math::Max(1.1, 1.2), 1.2);
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert(Math::Min(1.1, 1.2), 1.1);
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert(Math::Pow(0.4, 0.5), 0.632455532033676);
		CxAssert(Math::Round(4.5), 4);
		CxAssert(Math::Round(4.6), 5);
		CxAssert(Math::Round(NaN), NaN);
		CxAssert(Math::Round(3.45, 1), 3.4);
		CxAssert(Math::Round(3.46, 1), 3.5);
		CxAssert(Math::Round(-0.123456789, 1), -0.1);
		CxAssert(Math::Round(NaN, 1), NaN);
		CxAssert(Math::Round(1.5), 2);
		CxAssert(Math::Round(2.5), 2);
		CxAssert(Math::Round(-1.5), -2);
		CxAssert(Math::Round(-2.5), -2);
		CxAssert(Math::Round(1.79769313486232E+308), 1.79769313486232E+308);
		CxAssert(Math::Round(-1.79769313486232E+308), -1.79769313486232E+308);
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert(Math::Sin(0.5), 0.479425538604203);
		CxAssert(Math::Sinh(0.5), 0.521095305493747);
		CxAssert(Math::Sqrt(25), 5);
		CxAssert(Math::Tan(0.52), 0.572561830251668);
		CxAssert(Math::Tanh(0.52), 0.477700012168498);
		Double x_num = 2.71828182845905;
		CxAssert();
		Double x_num2 = 3.14159265358979;
		CxAssert();
		CxAssert();
		return;
	}
	void MathTest::DoubleCompare(Double x_n1,Double x_n2,Double x_resolution)
	{
		
		return;
	}
	void MathTest::CxAssert(Double x_x,Double x_y)
	{
		DoubleCompare(x_x, x_y, 1E-05);
		return;
	}
	void MathTest::CxAssert(Boolean x_x)
	{
		
		return;
	}
	MathTest::MathTest()
	{
	}
	SByteTest::SByteTest(CABlock* x_caBlock)
	{
		
		x_caBlock = x_caBlock;
		return;
	}
	void SByteTest::Test()
	{
		x_caBlock->Send(new String(L"Doing SByteTest"));
		x_caBlock->Send(new String(L"	Doing SByteMethodsTest"));
		SByteMethodsTest();
		x_caBlock->Send(new String(L"	Doing SByteMathTest"));
		SByteMathTest();
		x_caBlock->Send(new String(L"	Doing SByteOperators"));
		SByteOperators();
		x_caBlock->Send(new String(L"	Doing SByteArrayTests"));
		SByteArrayTests();
		x_caBlock->Send(new String(L"	Doing SByteMiscTests"));
		SByteMiscTests();
		return;
	}
	void SByteTest::SByteMethodsTest()
	{
		SByte x_b = 5;
		CxAssert();
		CxAssert();
		CxAssert(.Equals(5));
		CxAssert(.Equals());
		CxAssert();
		CxAssert(String::op_Equality(new String(L"-75"), .ToString()));
		String* x_text = .ToString();
		CxAssert(String::op_Equality(x_text, new String(L"127")));
		CxAssert();
		String* x_text2 = .ToString();
		CxAssert(String::op_Equality(x_text2, new String(L"-128")));
		CxAssert();
		Int64 x_num = 9223372036854775807;
		x_b = ;
		CxAssert();
		Object* x_obj = ;
		CxAssert(x_obj->Equals());
		CxAssert(String::op_Equality(x_obj->ToString(), new String(L"5")));
		return;
	}
	void SByteTest::SByteMathTest()
	{
		SByte x_b = 6;
		SByte x_b2 = 12;
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		Int32 x_num = 11;
		CxAssert();
		x_num = 8;
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		x_num = 0;
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		return;
	}
	void SByteTest::SByteOperators()
	{
		SByte x_b = 66;
		Char x_c = 1;
		Byte x_b2 = 1;
		SByte x_b3 = 1;
		SByte x_b4 = 1;
		Int32 x_num = 1;
		Int64 x_num2 = ;
		UInt16 x_num3 = 1;
		UInt32 x_num4 = 1;
		Single x_num5 = 1;
		Double x_num6 = 1;
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		x_b = 66;
		CxAssert();
		x_b = 66;
		CxAssert();
		x_b = 66;
		CxAssert();
		x_b = 66;
		CxAssert();
		x_b = 66;
		CxAssert();
		x_b = 66;
		CxAssert();
		x_b = 66;
		CxAssert();
		x_b = 66;
		CxAssert();
		x_b = 66;
		CxAssert();
		x_b = 66;
		CxAssert();
		x_b = 66;
		CxAssert();
		x_b = 66;
		CxAssert();
		x_b = 66;
		CxAssert();
		x_b = 66;
		SByte x_b5 = 0;
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		return;
	}
	void SByteTest::SByteArrayTests()
	{
		Array* x_array = ;
		CxAssert();
		CxAssert();
		Array* x_array2 = ;
		CxAssert();
		Array* x_array3 = ;
		CxAssert();
		Array* x_array4 = ;
		CxAssert();
		 = 6;
		CxAssert();
		x_array4->SetValue(, 0, 0, 3);
		CxAssert();
		return;
	}
	void SByteTest::SByteMiscTests()
	{
		SByte x_b = -1;
		SByte x_val = 1;
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		StringBuilder* x_stringBuilder = new StringBuilder();
		x_stringBuilder->Append(x_b);
		CxAssert(String::op_Equality(x_stringBuilder->ToString(), new String(L"-1")));
		x_stringBuilder->Insert(2, x_b);
		CxAssert(String::op_Equality(x_stringBuilder->ToString(), new String(L"-1-1")));
		return;
	}
	void SByteTest::CxAssert(Boolean x_x)
	{
		
		return;
	}
	void SByteTest::CxAssert(Boolean x_x,Boolean x_y)
	{
		
		return;
	}
	SByteTest::SByteTest()
	{
	}
	SingleTest::SingleTest(CABlock* x_caBlock)
	{
		
		x_caBlock = x_caBlock;
		return;
	}
	void SingleTest::Test()
	{
		x_caBlock->Send(new String(L"Doing SingleTest"));
		x_caBlock->Send(new String(L"	Doing DoSingleMethodsTest"));
		DoSingleMethodsTest();
		x_caBlock->Send(new String(L"	Doing DoSingleMath"));
		DoSingleMath();
		x_caBlock->Send(new String(L"	Doing SingleOperators"));
		SingleOperators();
		x_caBlock->Send(new String(L"	Doing SingleNanTest"));
		SingleNanTest();
		x_caBlock->Send(new String(L"	Doing SingleArrayTest"));
		SingleArrayTest();
		x_caBlock->Send(new String(L"	Doing SingleMiscTests"));
		SingleMiscTests();
		return;
	}
	void SingleTest::DoSingleMethodsTest()
	{
		Single x_num = 3.159;
		CxAssert();
		CxAssert();
		CxAssert(.Equals(3.159));
		CxAssert(, 3.15899991989136);
		CxAssert(String::op_Equality(.ToString(), new String(L"3.159")));
		CxAssert(, );
		x_num = 1E+07;
		CxAssert();
		x_num = -1E+07;
		CxAssert();
		x_num = 10000;
		CxAssert();
		CxAssert();
		CxAssert();
		Object* x_obj = ;
		CxAssert();
		x_num = 1.401298E-45;
		CxAssert();
		x_num = 3.402823E+38;
		CxAssert();
		x_num = -3.402823E+38;
		CxAssert();
		x_obj = ;
		CxAssert(x_obj->Equals());
		CxAssert(String::op_Equality(x_obj->ToString(), new String(L"5")));
		return;
	}
	void SingleTest::DoSingleMath()
	{
		Single x_num = 355;
		Single x_num2 = 113;
		Single x_num3 = ;
		CxAssert(, 3.14159);
		CxAssert(, 355);
		CxAssert(, 468);
		CxAssert(, 242);
		x_num = 1;
		x_num2 = ;
		CxAssert();
		return;
	}
	void SingleTest::SingleOperators()
	{
		Single x_num = 66;
		Char x_c = 1;
		Int32 x_num2 = 1;
		UInt32 x_num3 = 1;
		Int64 x_num4 = ;
		Double x_num5 = 1;
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		x_num = 66;
		CxAssert();
		x_num = 5;
		CxAssert(, 0.6);
		return;
	}
	void SingleTest::SingleNanTest()
	{
		Single x_num = NaN;
		Single x_num2 = 1;
		CxAssert(Single::IsNaN(x_num));
		CxAssert(Single::IsInfinity(∞));
		CxAssert(Single::IsNegativeInfinity(-∞));
		CxAssert(Single::IsPositiveInfinity(∞));
		CxAssert(Single::IsNaN());
		CxAssert(Single::IsNaN());
		CxAssert(Single::IsNaN());
		CxAssert(Single::IsNaN());
		CxAssert(Single::IsNaN());
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert();
		CxAssert();
		x_num = NaN;
		x_num2 = NaN;
		
		
		
		
		
		
		
		
		
		CxAssert(.Equals(NaN));
		return;
	}
	void SingleTest::SingleArrayTest()
	{
		Array* x_array = ;
		CxAssert();
		Array* x_array2 = ;
		CxAssert();
		Array* x_array3 = ;
		CxAssert();
		 = 22;
		CxAssert();
		 = NaN;
		CxAssert(Single::IsNaN());
		x_array3->SetValue(, 0, 0, 3);
		CxAssert();
		return;
	}
	void SingleTest::SingleMiscTests()
	{
		Single x_num = -1;
		Single x_val = 1;
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		StringBuilder* x_stringBuilder = new StringBuilder();
		x_stringBuilder->Append(x_num);
		CxAssert(String::op_Equality(x_stringBuilder->ToString(), new String(L"-1")));
		x_stringBuilder->Insert(2, x_num);
		CxAssert(String::op_Equality(x_stringBuilder->ToString(), new String(L"-1-1")));
		return;
	}
	void SingleTest::SingleCompare(Double x_n1,Double x_n2,Double x_resolution)
	{
		Double x_num = Math::Abs();
		
		return;
	}
	void SingleTest::CxAssert(Double x_x,Double x_y)
	{
		SingleCompare(x_x, x_y, 1E-05);
		return;
	}
	void SingleTest::CxAssert(Boolean x_x)
	{
		
		return;
	}
	void SingleTest::CxAssert(Boolean x_x,Boolean x_y)
	{
		
		return;
	}
	void SingleTest::SingleTestFailed()
	{
		x_caBlock->TestFailed(new String(L"Single TestFailed"));
		return;
	}
	SingleTest::SingleTest()
	{
	}
	StringBuilderTest::StringBuilderTest(CABlock* x_caBlock)
	{
		x_sb = new StringBuilder();
		
		x_caBlock = x_caBlock;
		return;
	}
	void StringBuilderTest::Test()
	{
		x_caBlock->Send(new String(L"Doing StringBuilderTest"));
		x_caBlock->Send(new String(L"	Doing DoSBConstructTest"));
		DoSBConstructTest();
		x_caBlock->Send(new String(L"	Doing DoSBPropertyTest"));
		DoSBPropertyTest();
		x_caBlock->Send(new String(L"	Doing DoSBAppendTest"));
		DoSBAppendTest();
		x_caBlock->Send(new String(L"	Doing DoSBMiscTest"));
		DoSBMiscTest();
		x_caBlock->Send(new String(L"	Doing DoSBInsertTest"));
		DoSBInsertTest();
		x_caBlock->Send(new String(L"	Doing DoSBReplaceTest"));
		DoSBReplaceTest();
		return;
	}
	void StringBuilderTest::DoSBConstructTest()
	{
		CxAssert();
		x_sb = new StringBuilder(100);
		CxAssert();
		x_sb = new StringBuilder(new String(L"Test"));
		CxAssert(String::op_Equality(x_sb->ToString(), new String(L"Test")));
		x_sb = new StringBuilder(20, 25);
		CxAssert();
		x_sb = new StringBuilder(new String(L"Test"), 20);
		CxAssert();
		x_sb = new StringBuilder(new String(L"test1234"), 1, 4, 20);
		CxAssert();
		String* x_a = new StringBuilder(new String(L"Test"))->ToString();
		CxAssert(String::op_Equality(x_a, new String(L"Test")));
		String* x_b = new String(L"AB	
"'Â");
		Array* x_value = ;
		x_sb = new StringBuilder();
		x_sb->Append(x_value);
		String* x_text = x_sb->ToString();
		CxAssert(String::op_Equality(x_sb->ToString(), x_b));
		return;
	}
	void StringBuilderTest::DoSBPropertyTest()
	{
		x_sb = new StringBuilder(new String(L"Testing123"), 0, 10, 20);
		CxAssert();
		CxAssert();
		CxAssert();
		x_sb->set_Length(7);
		CxAssert();
		x_sb->set_Capacity(22);
		CxAssert();
		x_sb->set_Chars(0, 116);
		CxAssert(String::op_Equality(x_sb->ToString(), new String(L"testing")));
		return;
	}
	void StringBuilderTest::DoSBAppendTest()
	{
		x_sb->set_Length(0);
		x_sb->Append(1);
		CxAssert(String::op_Equality(x_sb->ToString(), new String(L"True")));
		CxAssert(String::op_Equality(x_sb->Append(65)->ToString(), new String(L"TrueA")));
		Array* x_value = ;
		CxAssert(String::op_Equality(x_sb->Append(x_value)->ToString(), new String(L"TrueA0123")));
		x_sb->set_Length(0);
		Double x_value2 = 3.14159;
		CxAssert(String::op_Equality(x_sb->Append(x_value2)->ToString(), new String(L"3.14159")));
		x_sb->set_Length(0);
		Int32 x_value3 = 666;
		CxAssert(String::op_Equality(x_sb->Append(x_value3)->ToString(), new String(L"666")));
		x_sb->set_Length(0);
		Int64 x_value4 = ;
		CxAssert(String::op_Equality(x_sb->Append(x_value4)->ToString(), new String(L"666666666")));
		x_sb->set_Length(0);
		Object* x_obj = ;
		CxAssert(String::op_Equality(x_sb->Append(x_obj)->ToString(), new String(L"1")));
		x_sb->set_Length(0);
		CxAssert(String::op_Equality(x_sb->Append(new String(L"fred"))->ToString(), new String(L"fred")));
		UInt32 x_value5 = 777;
		x_sb->set_Length(0);
		CxAssert(String::op_Equality(x_sb->Append(x_value5)->ToString(), new String(L"777")));
		x_sb->set_Length(0);
		CxAssert(String::op_Equality(x_sb->Append(65, 4)->ToString(), new String(L"AAAA")));
		x_sb->set_Length(0);
		CxAssert(String::op_Equality(x_sb->Append(x_value, 1, 3)->ToString(), new String(L"123")));
		x_sb->set_Length(0);
		CxAssert(String::op_Equality(x_sb->Append(new String(L"3210"), 1, 3)->ToString(), new String(L"210")));
		x_sb->set_Length(0);
		CxAssert(String::op_Equality(x_sb->AppendFormat(new String(L"x={0}"), x_obj)->ToString(), new String(L"x=1")));
		Array* x_array = ;
		x_sb->set_Length(0);
		CxAssert(String::op_Equality(x_sb->AppendFormat(new String(L"y={0}{1}{2}{3}"), x_array)->ToString(), new String(L"y=0123")));
		x_sb->set_Length(0);
		CxAssert(String::op_Equality(x_sb->AppendFormat(new String(L"y={0}{1}"), , )->ToString(), new String(L"y=01")));
		x_sb->set_Length(0);
		CxAssert(String::op_Equality(x_sb->AppendFormat(new String(L"y={0}{1}{2}"), , , )->ToString(), new String(L"y=012")));
		x_sb->set_Length(0);
		CxAssert(String::op_Equality(x_sb->Append(65)->ToString(), new String(L"A")));
		Object* x_value6 = new String(L"Test string as Object");
		x_sb->set_Length(0);
		CxAssert(String::op_Equality(x_sb->Append(x_value6)->ToString(), new String(L"Test string as Object")));
		TestAbstract* x_value7 = new TestAbstract();
		x_sb->set_Length(0);
		CxAssert(String::op_Equality(x_sb->Append(x_value7)->ToString(), new String(L"TestAbstract")));
		return;
	}
	void StringBuilderTest::DoSBMiscTest()
	{
		x_sb->set_Length(0);
		x_sb->set_Capacity(10);
		x_sb->EnsureCapacity(30);
		CxAssert();
		x_sb->Append(new String(L"Test"));
		StringBuilder* x_stringBuilder = new StringBuilder(new String(L"Test"));
		x_stringBuilder->set_Capacity(10);
		x_stringBuilder->EnsureCapacity(30);
		CxAssert(x_sb->Equals(x_stringBuilder));
		x_sb->set_Length(0);
		x_sb->Append(new String(L"1234567890"));
		x_sb->Remove(1, 4);
		CxAssert(String::op_Equality(x_sb->ToString(), new String(L"167890")));
		x_sb->set_Length(0);
		x_sb->Append(new String(L"1234567890"));
		CxAssert(String::op_Equality(x_sb->ToString(1, 8), new String(L"23456789")));
		return;
	}
	void StringBuilderTest::DoSBInsertTest()
	{
		String* x_value = new String(L"{}");
		x_sb->set_Length(0);
		x_sb->Append(x_value);
		x_sb->Insert(1, 1);
		CxAssert(String::op_Equality(x_sb->ToString(), new String(L"{True}")));
		CxAssert(String::op_Equality(x_sb->Insert(5, 65)->ToString(), new String(L"{TrueA}")));
		Array* x_value2 = ;
		CxAssert(String::op_Equality(x_sb->Insert(6, x_value2)->ToString(), new String(L"{TrueA0123}")));
		x_sb->set_Length(0);
		x_sb->Append(x_value);
		Double x_value3 = 3.14159;
		CxAssert(String::op_Equality(x_sb->Insert(1, x_value3)->ToString(), new String(L"{3.14159}")));
		x_sb->set_Length(0);
		x_sb->Append(x_value);
		Int32 x_value4 = 666;
		CxAssert(String::op_Equality(x_sb->Insert(1, x_value4)->ToString(), new String(L"{666}")));
		x_sb->set_Length(0);
		x_sb->Append(x_value);
		Int64 x_value5 = ;
		CxAssert(String::op_Equality(x_sb->Insert(1, x_value5)->ToString(), new String(L"{666666666}")));
		x_sb->set_Length(0);
		x_sb->Append(x_value);
		Object* x_value6 = ;
		CxAssert(String::op_Equality(x_sb->Insert(1, x_value6)->ToString(), new String(L"{1}")));
		x_sb->set_Length(0);
		x_sb->Append(x_value);
		CxAssert(String::op_Equality(x_sb->Insert(1, new String(L"fred"))->ToString(), new String(L"{fred}")));
		UInt32 x_value7 = 777;
		x_sb->set_Length(0);
		x_sb->Append(x_value);
		CxAssert(String::op_Equality(x_sb->Insert(1, x_value7)->ToString(), new String(L"{777}")));
		x_sb->set_Length(0);
		x_sb->Append(x_value);
		CxAssert(String::op_Equality(x_sb->Insert(1, new String(L"A"), 4)->ToString(), new String(L"{AAAA}")));
		x_sb->set_Length(0);
		x_sb->Append(x_value);
		CxAssert(String::op_Equality(x_sb->Insert(1, x_value2, 1, 3)->ToString(), new String(L"{123}")));
		return;
	}
	void StringBuilderTest::DoSBReplaceTest()
	{
		x_sb->set_Length(0);
		x_sb->Append(new String(L"aaaaaaa"));
		CxAssert(String::op_Equality(x_sb->Replace(97, 65)->ToString(), new String(L"AAAAAAA")));
		CxAssert(String::op_Equality(x_sb->Replace(new String(L"AA"), new String(L"BBB"))->ToString(), new String(L"BBBBBBBBBA")));
		CxAssert(String::op_Equality(x_sb->Replace(66, 67, 1, 7)->ToString(), new String(L"BCCCCCCCBA")));
		CxAssert(String::op_Equality(x_sb->Replace(new String(L"CCC"), new String(L"DDD"), 2, 5)->ToString(), new String(L"BCDDDCCCBA")));
		x_sb->set_Length(0);
		x_sb->Append(new String(L"aaaaaaa"));
		String* x_a = x_sb->Replace(new String(L"aa"), new String(L"BBB"), 1, 5)->ToString();
		CxAssert(String::op_Equality(x_a, new String(L"aBBBBBBaa")));
		return;
	}
	void StringBuilderTest::CxAssert(Boolean x_x)
	{
		
		return;
	}
	void StringBuilderTest::CxAssert(Boolean x_x,Boolean x_y)
	{
		
		return;
	}
	StringBuilderTest::StringBuilderTest()
	{
	}
	StringTest::StringTest(CABlock* x_caBlock)
	{
		
		x_caBlock = x_caBlock;
		return;
	}
	void StringTest::Test()
	{
		x_caBlock->Send(new String(L"Doing StringTest"));
		x_caBlock->Send(new String(L"	Doing DoIndexTest"));
		DoIndexTest();
		x_caBlock->Send(new String(L"	Doing DoMiscTest"));
		DoMiscTest();
		x_caBlock->Send(new String(L"	Doing DoEqualsTest"));
		DoEqualsTest();
		x_caBlock->Send(new String(L"	Doing DoParsingTest"));
		DoParsingTest();
		x_caBlock->Send(new String(L"	Doing DoConcatTest"));
		DoConcatTest();
		return;
	}
	void StringTest::DoIndexTest()
	{
		String* x_text = new String(L"12345");
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		return;
	}
	void StringTest::DoMiscTest()
	{
		String* x_text = new String(32, 10);
		CxAssert();
		String* x_text2 = new String(L"12345");
		Array* x_array = ;
		x_text2->CopyTo(0, x_array, 0, x_text2->get_Length());
		Int32 x_num = 0;
		String* x_text3 = x_text2;
		Int32 x_i = 0;
		
		{
			
		}
		{
			Char x_c = x_text3->get_Chars(x_i);
			CxAssert();
			Int32 x_num = ;
			
		}
		{
			Int32 x_i = ;
			
		}

		x_array = x_text2->ToCharArray();
		CxAssert();
		String* x_a = new String(x_array);
		CxAssert(String::op_Equality(x_a, x_text2));
		String* x_a2 = new String(x_array, 0, 2);
		CxAssert(String::op_Equality(x_a2, new String(L"12")));
		CxAssert(String::op_Inequality(x_a2, new String(L"22")));
		CxAssert();
		x_a2 = new String(x_text2->ToCharArray(), 0, x_text2->get_Length());
		CxAssert(String::op_Equality(x_a2, x_text2));
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		x_a2 = String::Copy(x_text2);
		CxAssert(String::op_Equality(x_a2, x_text2));
		x_a2 = String::Format(new String(L"1 = {{{0,-4}}} 2 = {1,4} 3 = {2}!"), , , );
		CxAssert(String::op_Equality(x_a2, new String(L"1 = {1   } 2 =    2 3 = 3!")));
		String* x_a3 = x_a2->ToString();
		CxAssert(String::op_Equality(x_a3, new String(L"1 = {1   } 2 =    2 3 = 3!")));
		String* x_empty = String.Empty;
		CxAssert();
		x_a2 = String::Format(new String(L"1 = {{{0,-4}}} 2 = {1,4}!"), , );
		CxAssert(String::op_Equality(x_a2, new String(L"1 = {1   } 2 =    2!")));
		x_a2 = String::Format(new String(L"1 = {{{0,-4}}}!"), );
		CxAssert(String::op_Equality(x_a2, new String(L"1 = {1   }!")));
		Array* x_args = ;
		x_a2 = String::Format(new String(L"1 = {{{0,-4}}} 2 = {1,4} 3 = {2}!"), x_args);
		CharEnumerator* x_enumerator = x_a2->GetEnumerator();
		Int32 x_num2 = 0;
		
		{
			
		}
		{
			Char x_current = x_enumerator->get_Current();
			CxAssert();
			
		}

		x_enumerator->Reset();
		Double x_num3 = 2;
		String* x_text4 = String::Concat();
		StringTest::TestConcat(x_text2, x_num, x_empty, x_num2, x_num3);
		String* x_a4 = new String(L""");
		CxAssert(String::op_Equality(x_a4, new String(L""")));
		x_a4 = new String(L"c:\Retest");
		CxAssert(String::op_Equality(x_a4, new String(L"c:\Retest")));
		x_a4 = new String(L"c:\Retest");
		CxAssert(String::op_Equality(x_a4, new String(L"c:\Retest")));
		return;
	}
	void StringTest::TestConcat(String* x_str1,Int32 x_index,String* x_str4,Int32 x_i,Double x_dbl)
	{
		String* x_text = String::Concat();
		return;
	}
	void StringTest::DoEqualsTest()
	{
		String* x_text = new String(L"12345");
		CxAssert(String::Equals(x_text, new String(L"12345")));
		CxAssert(String::op_Equality(x_text, new String(L"12345")));
		CxAssert(x_text->Equals(x_text));
		CxAssert(x_text->Equals(x_text));
		return;
	}
	void StringTest::DoParsingTest()
	{
		String* x_text = new String(L"12 34 56");
		Array* x_array = x_text->Split();
		CxAssert();
		CxAssert(String::op_Equality(new String(L"12"), ));
		CxAssert(String::op_Equality(new String(L"34"), ));
		CxAssert(String::op_Equality(new String(L"56"), ));
		String* x_text2 = new String(L"42, 12, 19");
		Array* x_separator = ;
		x_array = x_text2->Split(x_separator);
		CxAssert();
		CxAssert(String::op_Equality(new String(L"42"), ));
		CxAssert(String::op_Equality(new String(L""), ));
		CxAssert(String::op_Equality(new String(L"12"), ));
		CxAssert(String::op_Equality(new String(L""), ));
		CxAssert(String::op_Equality(new String(L"19"), ));
		x_array = x_text2->Split(x_separator, 2);
		CxAssert();
		CxAssert(String::op_Equality(new String(L"42"), ));
		CxAssert(String::op_Equality(new String(L" 12, 19"), ));
		String* x_b = x_text->Substring(3);
		CxAssert(String::op_Equality(new String(L"34 56"), x_b));
		x_b = x_text->Substring(3, 2);
		CxAssert(String::op_Equality(new String(L"34"), x_b));
		String* x_text3 = new String(L"  12345  ");
		String* x_b2 = x_text3->Trim();
		CxAssert(String::op_Equality(new String(L"12345"), x_b2));
		String* x_text4 = new String(L"*;|@123***456@|;*");
		String* x_text5 = new String(L"*;|@");
		Array* x_trimChars = x_text5->ToCharArray();
		x_b2 = x_text4->Trim(x_trimChars);
		CxAssert(String::op_Equality(new String(L"123***456"), x_b2));
		x_b2 = x_text3->TrimStart();
		CxAssert(String::op_Equality(new String(L"12345  "), x_b2));
		x_b2 = x_text4->TrimStart(x_trimChars);
		CxAssert(String::op_Equality(new String(L"123***456@|;*"), x_b2));
		x_b2 = x_text3->TrimEnd();
		CxAssert(String::op_Equality(new String(L"  12345"), x_b2));
		x_b2 = x_text4->TrimEnd(x_trimChars);
		CxAssert(String::op_Equality(new String(L"*;|@123***456"), x_b2));
		Int32 x_num = String::Compare(x_text, x_text3);
		CxAssert();
		x_num = x_text3->CompareTo(x_text);
		CxAssert();
		x_num = x_text3->CompareTo(x_text);
		CxAssert();
		CxAssert(x_text->EndsWith(new String(L"56")));
		Array* x_array2 = ;
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		String* x_text6 = new String(L"11223311");
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		 = 49;
		 = 50;
		CxAssert();
		CxAssert();
		CxAssert();
		String* x_a = x_text6->PadLeft();
		CxAssert(String::op_Equality(x_a, new String(L"   11223311")));
		x_a = x_text6->PadLeft(, 45);
		CxAssert(String::op_Equality(x_a, new String(L"---11223311")));
		x_a = x_text6->PadRight();
		CxAssert(String::op_Equality(x_a, new String(L"11223311   ")));
		x_a = x_text6->PadRight(, 45);
		CxAssert(String::op_Equality(x_a, new String(L"11223311---")));
		CxAssert(x_text6->StartsWith(new String(L"1122")));
		CxAssert(String::op_Equality(x_text6->Replace(49, 120), new String(L"xx2233xx")));
		CxAssert(String::op_Equality(x_text6->Replace(new String(L"1"), new String(L"x")), new String(L"xx2233xx")));
		CxAssert(String::op_Equality(x_text6->Replace(new String(L"11"), new String(L"x")), new String(L"x2233x")));
		CxAssert(String::op_Equality(x_text6->Remove(2, 2), new String(L"113311")));
		CxAssert(String::op_Equality(new String(L"aaAAaaAA")->ToUpper(), new String(L"AAAAAAAA")));
		CxAssert(String::op_Equality(new String(L"aaAAaaAA")->ToLower(), new String(L"aaaaaaaa")));
		Array* x_value = ;
		CxAssert(String::op_Equality(String::Join(new String(L","), x_value), new String(L"1,2,3")));
		CxAssert(String::op_Equality(String::Join(new String(L","), x_value, 1, 2), new String(L"2,3")));
		x_text6 = x_text->Insert(3, new String(L"111"));
		CxAssert(String::op_Equality(x_text6, new String(L"12 11134 56")));
		String* x_text7 = new String(L"3.33");
		
		return;
	}
	void StringTest::DoConcatTest()
	{
		Array* x_array = ;
		String* x_a = String::Concat();
		CxAssert(String::op_Equality(x_a, new String(L"1 ")));
		x_a = String::Concat(x_array);
		CxAssert(String::op_Equality(x_a, new String(L"1 2 3 4")));
		Array* x_array2 = ;
		x_a = String::Concat(x_array2);
		CxAssert(String::op_Equality(x_a, new String(L"1 2 3 4")));
		x_a = String::Concat(, );
		CxAssert(String::op_Equality(x_a, new String(L"1 2 ")));
		x_a = String::Concat(, );
		CxAssert(String::op_Equality(x_a, new String(L"1 2 ")));
		x_a = String::Concat(, , );
		CxAssert(String::op_Equality(x_a, new String(L"1 2 3 ")));
		x_a = String::Concat(, , );
		CxAssert(String::op_Equality(x_a, new String(L"1 2 3 ")));
		x_a = String::Concat(, , , );
		CxAssert(String::op_Equality(x_a, new String(L"1 2 3 4")));
		return;
	}
	void StringTest::CxAssert(Boolean x_x)
	{
		
		return;
	}
	StringTest::StringTest()
	{
	}
	TimeTest::TimeTest(CABlock* x_caBlock)
	{
		x_dat1 = DateTime::get_Now();
		
		x_caBlock = x_caBlock;
		return;
	}
	void TimeTest::Test()
	{
		x_caBlock->Send(new String(L"Doing TimeTest"));
		x_caBlock->Send(new String(L"	Doing TestTimeSpan"));
		TestTimeSpan();
		x_caBlock->Send(new String(L"	Doing TestDateTime"));
		TestDateTime();
		x_caBlock->Send(new String(L"	Doing DateTimeMethodTests"));
		DateTimeMethodTests();
		x_caBlock->Send(new String(L"	Doing TimeArrayTests"));
		TimeArrayTests();
		return;
	}
	void TimeTest::TestTimeSpan()
	{
		TimeSpan x_timeSpan = new TimeSpan();
		TimeSpan x_timeSpan2 = .Add(x_timeSpan);
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		x_timeSpan = .Duration();
		CxAssert();
		CxAssert(TimeSpan::Equals(x_timeSpan, x_timeSpan2));
		CxAssert(.Equals(x_timeSpan2));
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		x_timeSpan = TimeSpan::FromTicks();
		CxAssert();
		x_timeSpan = .Negate();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		x_timeSpan = TimeSpan::Parse(new String(L"1.2:3:4.200"));
		String* x_a = ->ToString();
		CxAssert(String::op_Equality(x_a, new String(L"1.02:03:04.2000000")));
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert(.get_TotalDays(), 1.08546527777778);
		CxAssert(.get_TotalHours(), 26.0511666666667);
		CxAssert(.get_TotalMinutes(), 1563.07);
		CxAssert(.get_TotalSeconds(), 93784.2);
		CxAssert(.get_TotalMilliseconds(), 93784200);
		CxAssert();
		x_timeSpan = x_timeSpan2;
		CxAssert(TimeSpan::op_Equality(x_timeSpan, x_timeSpan2));
		CxAssert();
		x_timeSpan = new TimeSpan();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert(TimeSpan::op_Equality(x_timeSpan, x_timeSpan));
		x_timeSpan = TimeSpan::op_Subtraction(x_timeSpan2, x_timeSpan);
		CxAssert();
		x_timeSpan = TimeSpan::op_UnaryNegation(x_timeSpan);
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		x_timeSpan = new TimeSpan(71, 3, 12, 13);
		CxAssert();
		String* x_text = ->ToString();
		CxAssert(x_text->Equals(new String(L"71.03:12:13")));
		x_timeSpan = new TimeSpan(-71, 3, 12, 13);
		CxAssert();
		String* x_text2 = ->ToString();
		CxAssert(x_text2->Equals(new String(L"-70.20:47:47")));
		x_timeSpan = TimeSpan::Parse(new String(L"-71.03:12:13"));
		CxAssert();
		String* x_text3 = ->ToString();
		CxAssert(x_text3->Equals(new String(L"-71.03:12:13")));
		Object* x_obj = ;
		CxAssert();
		TimeSpan x_minValue = TimeSpan.MinValue;
		CxAssert(->Equals(x_obj));
		CxAssert();
		Int64 x_num = 864000000000;
		CxAssert();
		x_num = 36000000000;
		CxAssert();
		x_num = ;
		CxAssert();
		x_num = ;
		CxAssert();
		x_num = ;
		CxAssert();
		CxAssert(TimeSpan::op_Equality(TimeSpan.Zero, TimeSpan.Zero));
		CxAssert(TimeSpan::op_Equality(TimeSpan.MaxValue, TimeSpan.MaxValue));
		CxAssert(x_obj->Equals());
		String* x_a2 = x_obj->ToString();
		x_minValue = TimeSpan.MinValue;
		CxAssert(String::op_Equality(x_a2, ->ToString()));
		return;
	}
	void TimeTest::TestDateTime()
	{
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		DateTime x_dateTime = new DateTime(2003, 7, 23, 12, 30, 30, 100);
		CxAssert();
		CxAssert();
		Int32 x_day = .get_Day();
		CxAssert();
		DayOfWeek x_dayOfWeek = .get_DayOfWeek();
		CxAssert();
		Int32 x_dayOfYear = .get_DayOfYear();
		CxAssert();
		Int32 x_hour = .get_Hour();
		CxAssert();
		Int32 x_millisecond = .get_Millisecond();
		CxAssert();
		Int32 x_minute = .get_Minute();
		CxAssert();
		Int32 x_month = .get_Month();
		CxAssert();
		DateTime x_now = DateTime::get_Now();
		x_day = .get_Day();
		x_dayOfYear = .get_DayOfYear();
		x_dayOfWeek = .get_DayOfWeek();
		x_hour = .get_Hour();
		Int32 x_second = .get_Second();
		CxAssert();
		CxAssert();
		DateTime x_today = DateTime::get_Today();
		x_day = .get_Day();
		x_dayOfYear = .get_DayOfYear();
		x_dayOfWeek = .get_DayOfWeek();
		x_hour = .get_Hour();
		DateTime x_utcNow = DateTime::get_UtcNow();
		x_day = .get_Day();
		x_dayOfYear = .get_DayOfYear();
		x_dayOfWeek = .get_DayOfWeek();
		x_hour = .get_Hour();
		Int32 x_year = .get_Year();
		CxAssert();
		return;
	}
	void TimeTest::DateTimeMethodTests()
	{
		DateTime x_dateTime = new DateTime(2003, 7, 23, 12, 30, 30, 100);
		TimeSpan x_timeSpan = new TimeSpan(0, 2, 0, 0);
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		DateTime x_dateTime2 = .AddYears(3);
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		x_dateTime2 = x_dateTime;
		CxAssert(DateTime::Equals(x_dateTime, x_dateTime2));
		CxAssert(DateTime::IsLeapYear(2004));
		x_dateTime2 = .Subtract(x_timeSpan);
		CxAssert();
		CxAssert();
		x_dateTime2 = .ToLocalTime();
		x_dateTime2 = .ToUniversalTime();
		x_dateTime2 = DateTime::op_Addition(x_dateTime, x_timeSpan);
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert(DateTime::op_Equality(x_dateTime2, x_dateTime2));
		CxAssert();
		CxAssert();
		x_dateTime2 = DateTime::op_Subtraction(x_dateTime, x_timeSpan);
		CxAssert();
		CxAssert();
		x_dateTime2 = new DateTime(2003, 7, 23, 14, 2, 30, 100);
		CxAssert();
		CxAssert();
		String* x_text = .ToString();
		CxAssert(x_text->Equals(new String(L"7/23/2003 2:02:30 PM")));
		x_dateTime2 = new DateTime(2003, 7, 23, 2, 20, 1, 100);
		CxAssert();
		CxAssert();
		x_text = .ToString();
		CxAssert(x_text->Equals(new String(L"7/23/2003 2:20:01 AM")));
		CxAssert();
		CxAssert();
		Object* x_obj = ;
		CxAssert();
		CxAssert(.Equals(x_obj));
		CxAssert();
		CxAssert(x_obj->Equals());
		CxAssert(String::op_Equality(x_obj->ToString(), .ToString()));
		CxAssert(DateTime::op_Inequality(x_dateTime2, x_dateTime));
		return;
	}
	void TimeTest::TimeArrayTests()
	{
		DateTimeArrayTests();
		TimeSpanArrayTests();
		return;
	}
	void TimeTest::DateTimeArrayTests()
	{
		Array* x_array = ;
		CxAssert();
		CxAssert(DateTime::op_Equality(, new DateTime(2000, 4, 9)));
		CxAssert(DateTime::op_Equality(, new DateTime(2000, 4, 7)));
		Array* x_array2 = ;
		CxAssert(DateTime::op_Equality(, new DateTime(2000, 4, 8)));
		Array* x_array3 = ;
		CxAssert(DateTime::op_Equality(, new DateTime(2000, 4, 9)));
		 = new DateTime(2000, 4, 27);
		CxAssert(DateTime::op_Equality(, new DateTime(2000, 4, 27)));
		x_array3->SetValue(, 0, 0, 3);
		CxAssert(DateTime::op_Equality(, new DateTime(2000, 4, 28)));
		DateTime x_d =  = new DateTime(2000, 4, 27);
		CxAssert(DateTime::op_Equality(, x_d));
		return;
	}
	void TimeTest::TimeSpanArrayTests()
	{
		Array* x_array = ;
		CxAssert();
		CxAssert(TimeSpan::op_Equality(, new TimeSpan(2000, 4, 9)));
		CxAssert(TimeSpan::op_Equality(, new TimeSpan(2000, 4, 7)));
		Array* x_array2 = ;
		CxAssert(TimeSpan::op_Equality(, new TimeSpan(2000, 4, 8)));
		Array* x_array3 = ;
		CxAssert(TimeSpan::op_Equality(, new TimeSpan(2000, 4, 9)));
		 = new TimeSpan(2000, 4, 27);
		CxAssert(TimeSpan::op_Equality(, new TimeSpan(2000, 4, 27)));
		x_array3->SetValue(, 0, 0, 3);
		CxAssert(TimeSpan::op_Equality(, new TimeSpan(2000, 4, 28)));
		TimeSpan x_t =  = new TimeSpan(2000, 4, 27);
		CxAssert(TimeSpan::op_Equality(, x_t));
		return;
	}
	void TimeTest::CxAssert(Double x_x,Double x_y)
	{
		
		return;
	}
	void TimeTest::CxAssert(Boolean x_x)
	{
		
		return;
	}
	void TimeTest::TimeTestFailed()
	{
		x_caBlock->TestFailed(new String(L"Time TestFailed"));
		return;
	}
	TimeTest::TimeTest()
	{
	}
	TimingTest::TimingTest()
	{
		
		return;
	}
	Int32 TimingTest::DoTimingTest(Int32 x_a,Int32 x_b,Int32 x_c)
	{
		Int32 x_result = 0;
		Int32 x_i = 0;
		
		{
			
		}
		{
			Int32 x_j = 0;
			
			{
				
			}
			{
				Int32 x_result = ;
				
			}
			{
				Int32 x_j = ;
				
			}

			
		}
		{
			Int32 x_i = ;
			
		}

		return((Int32)x_result);
	}
	UInt16Test::UInt16Test(CABlock* x_caBlock)
	{
		
		x_caBlock = x_caBlock;
		return;
	}
	void UInt16Test::Test()
	{
		x_caBlock->Send(new String(L"Doing UInt16Test"));
		x_caBlock->Send(new String(L"	Doing UInt16MethodsTest"));
		UInt16MethodsTest();
		x_caBlock->Send(new String(L"	Doing DoUnSignedMath"));
		DoUnSignedMath();
		x_caBlock->Send(new String(L"	Doing UInt16Operators"));
		UInt16Operators();
		x_caBlock->Send(new String(L"	Doing UInt16ArrayTest"));
		UInt16ArrayTest();
		x_caBlock->Send(new String(L"	Doing UInt16MiscTests"));
		UInt16MiscTests();
		return;
	}
	void UInt16Test::UInt16MethodsTest()
	{
		UInt16 x_num = 5;
		CxAssert();
		CxAssert();
		CxAssert(.Equals(5));
		CxAssert(.Equals());
		CxAssert();
		CxAssert(String::op_Equality(new String(L"5"), .ToString()));
		x_num = 65535;
		CxAssert();
		x_num = 0;
		CxAssert();
		String* x_text = .ToString();
		CxAssert(String::op_Equality(x_text, new String(L"65535")));
		CxAssert();
		String* x_text2 = .ToString();
		CxAssert(String::op_Equality(x_text2, new String(L"0")));
		CxAssert();
		Object* x_obj = ;
		CxAssert(x_obj->Equals());
		CxAssert(String::op_Equality(x_obj->ToString(), new String(L"5")));
		return;
	}
	void UInt16Test::DoUnSignedMath()
	{
		UInt16 x_num = 600;
		UInt16 x_num2 = 1200;
		Int32 x_num3 = 1;
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		x_num3 = ;
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		Int32 x_num4 = 11;
		CxAssert();
		x_num4 = 8;
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		UInt32 x_num5 = 0;
		CxAssert();
		CxAssert();
		CxAssert();
		return;
	}
	void UInt16Test::UInt16Operators()
	{
		UInt16 x_num = 66;
		Char x_c = 1;
		Int32 x_num2 = 1;
		UInt16 x_num3 = 1;
		Int64 x_num4 = ;
		Double x_num5 = 1;
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		x_num = 66;
		CxAssert();
		x_num = 66;
		CxAssert();
		x_num = 66;
		CxAssert();
		x_num = 66;
		CxAssert();
		x_num = 66;
		CxAssert();
		x_num = 66;
		CxAssert();
		x_num = 66;
		CxAssert();
		x_num = 66;
		CxAssert();
		x_num = 66;
		CxAssert();
		x_num = 66;
		CxAssert();
		x_num = 66;
		CxAssert();
		x_num = 66;
		return;
	}
	void UInt16Test::UInt16ArrayTest()
	{
		Array* x_array = ;
		CxAssert();
		CxAssert();
		Array* x_array2 = ;
		CxAssert();
		Array* x_array3 = ;
		CxAssert();
		Array* x_array4 = ;
		CxAssert();
		 = 6;
		CxAssert();
		x_array4->SetValue(, 0, 0, 3);
		CxAssert();
		return;
	}
	void UInt16Test::UInt16MiscTests()
	{
		UInt16 x_num = 0;
		UInt16 x_num2 = 1;
		CxAssert();
		CxAssert();
		StringBuilder* x_stringBuilder = new StringBuilder();
		x_stringBuilder->Append(x_num2);
		CxAssert(String::op_Equality(x_stringBuilder->ToString(), new String(L"1")));
		x_stringBuilder->Insert(1, x_num);
		CxAssert(String::op_Equality(x_stringBuilder->ToString(), new String(L"10")));
		return;
	}
	void UInt16Test::CxAssert(Boolean x_x)
	{
		
		return;
	}
	void UInt16Test::CxAssert(Boolean x_x,Boolean x_y)
	{
		
		return;
	}
	UInt16Test::UInt16Test()
	{
	}
	UInt32Test::UInt32Test(CABlock* x_caBlock)
	{
		
		x_caBlock = x_caBlock;
		return;
	}
	void UInt32Test::Test()
	{
		x_caBlock->Send(new String(L"Doing UInt32Test"));
		x_caBlock->Send(new String(L"	Doing UInt32MethodsTest"));
		UInt32MethodsTest();
		x_caBlock->Send(new String(L"	Doing DoUnSignedMath"));
		DoUnSignedMath();
		x_caBlock->Send(new String(L"	Doing UInt32Operators"));
		UInt32Operators();
		x_caBlock->Send(new String(L"	Doing UInt32ArrayTest"));
		UInt32ArrayTest();
		x_caBlock->Send(new String(L"	Doing UInt32MiscTests"));
		UInt32MiscTests();
		return;
	}
	void UInt32Test::UInt32MethodsTest()
	{
		UInt32 x_num = 5;
		CxAssert();
		CxAssert();
		CxAssert(.Equals(5));
		CxAssert(.Equals());
		CxAssert();
		CxAssert(String::op_Equality(new String(L"5"), .ToString()));
		x_num = -1;
		CxAssert();
		x_num = 0;
		CxAssert();
		String* x_text = .ToString();
		CxAssert(String::op_Equality(x_text, new String(L"4294967295")));
		CxAssert();
		String* x_text2 = .ToString();
		CxAssert(String::op_Equality(x_text2, new String(L"0")));
		CxAssert();
		Object* x_obj = ;
		CxAssert(x_obj->Equals());
		CxAssert(String::op_Equality(x_obj->ToString(), new String(L"5")));
		return;
	}
	void UInt32Test::DoUnSignedMath()
	{
		UInt32 x_num = 60000;
		UInt32 x_num2 = 120000;
		Int32 x_num3 = 1;
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		x_num3 = ;
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		Int32 x_num4 = 11;
		CxAssert();
		x_num4 = 8;
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		UInt32 x_num5 = 0;
		CxAssert();
		CxAssert();
		CxAssert();
		return;
	}
	void UInt32Test::UInt32Operators()
	{
		UInt32 x_num = 66;
		Char x_c = 1;
		Int32 x_num2 = 1;
		UInt32 x_num3 = 1;
		Int64 x_num4 = ;
		Double x_num5 = 1;
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		x_num = 66;
		CxAssert();
		x_num = 66;
		CxAssert();
		x_num = 66;
		CxAssert();
		x_num = 66;
		CxAssert();
		x_num = 66;
		CxAssert();
		x_num = 66;
		CxAssert();
		x_num = 66;
		CxAssert();
		x_num = 66;
		CxAssert();
		x_num = 66;
		CxAssert();
		x_num = 66;
		CxAssert();
		x_num = 66;
		CxAssert();
		x_num = 66;
		return;
	}
	void UInt32Test::UInt32ArrayTest()
	{
		Array* x_array = ;
		CxAssert();
		CxAssert();
		Array* x_array2 = ;
		CxAssert();
		Array* x_array3 = ;
		CxAssert();
		Array* x_array4 = ;
		CxAssert();
		 = 6;
		CxAssert();
		x_array4->SetValue(, 0, 0, 3);
		CxAssert();
		return;
	}
	void UInt32Test::UInt32MiscTests()
	{
		UInt32 x_val = 0;
		UInt32 x_num = 1;
		CxAssert();
		CxAssert();
		StringBuilder* x_stringBuilder = new StringBuilder();
		x_stringBuilder->Append(x_num);
		CxAssert(String::op_Equality(x_stringBuilder->ToString(), new String(L"1")));
		return;
	}
	void UInt32Test::CxAssert(Boolean x_x)
	{
		
		return;
	}
	void UInt32Test::CxAssert(Boolean x_x,Boolean x_y)
	{
		
		return;
	}
	UInt32Test::UInt32Test()
	{
	}
	UInt64Test::UInt64Test(CABlock* x_caBlock)
	{
		
		x_caBlock = x_caBlock;
		return;
	}
	void UInt64Test::Test()
	{
		x_caBlock->Send(new String(L"Doing UInt64Test"));
		x_caBlock->Send(new String(L"	Doing UInt64MethodsTest"));
		UInt64MethodsTest();
		x_caBlock->Send(new String(L"	Doing UInt64UnSignedMath"));
		UInt64UnSignedMath();
		x_caBlock->Send(new String(L"	Doing UInt64Operators"));
		UInt64Operators();
		x_caBlock->Send(new String(L"	Doing UInt64ArrayTest"));
		UInt64ArrayTest();
		x_caBlock->Send(new String(L"	Doing UInt64MiscTests"));
		UInt64MiscTests();
		return;
	}
	void UInt64Test::UInt64MethodsTest()
	{
		UInt64 x_num = ;
		CxAssert();
		CxAssert();
		CxAssert(.Equals());
		CxAssert(.Equals());
		CxAssert();
		CxAssert(String::op_Equality(new String(L"5"), .ToString()));
		x_num = ;
		CxAssert();
		x_num = ;
		CxAssert();
		String* x_text = .ToString();
		CxAssert(String::op_Equality(x_text, new String(L"18446744073709551615")));
		CxAssert();
		String* x_text2 = .ToString();
		CxAssert(String::op_Equality(x_text2, new String(L"0")));
		CxAssert();
		Object* x_obj = ;
		CxAssert(x_obj->Equals());
		CxAssert(String::op_Equality(x_obj->ToString(), new String(L"5")));
		return;
	}
	void UInt64Test::UInt64UnSignedMath()
	{
		UInt64 x_num = ;
		UInt64 x_num2 = ;
		UInt64 x_num3 = ;
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		x_num3 = ;
		CxAssert();
		CxAssert();
		UInt64 x_num4 = ;
		CxAssert();
		UInt64 x_num5 = ;
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		Int32 x_num6 = 11;
		CxAssert();
		x_num6 = 8;
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		UInt32 x_num7 = 0;
		CxAssert();
		CxAssert();
		CxAssert();
		return;
	}
	void UInt64Test::UInt64Operators()
	{
		UInt64 x_num = ;
		Char x_c = 1;
		Byte x_b = 1;
		SByte x_b2 = 1;
		Int16 x_num2 = 1;
		Int32 x_num3 = 1;
		Int64 x_num4 = ;
		UInt16 x_num5 = 1;
		UInt32 x_num6 = 1;
		UInt64 x_num7 = ;
		Single x_num8 = 1;
		Double x_num9 = 1;
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert(, 0);
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		CxAssert();
		x_num = ;
		CxAssert();
		x_num = ;
		CxAssert();
		x_num = ;
		CxAssert();
		x_num = ;
		CxAssert();
		x_num = ;
		CxAssert();
		x_num = ;
		CxAssert();
		x_num = ;
		CxAssert();
		x_num = ;
		CxAssert();
		x_num = ;
		CxAssert();
		x_num = ;
		CxAssert();
		x_num = ;
		CxAssert();
		x_num = ;
		Char x_c2 = 66;
		CxAssert();
		return;
	}
	void UInt64Test::UInt64ArrayTest()
	{
		Array* x_array = ;
		CxAssert();
		CxAssert();
		Array* x_array2 = ;
		CxAssert();
		Array* x_array3 = ;
		CxAssert();
		Array* x_array4 = ;
		CxAssert();
		 = ;
		CxAssert();
		x_array4->SetValue(, 0, 0, 3);
		CxAssert();
		return;
	}
	void UInt64Test::UInt64MiscTests()
	{
		UInt64 x_num = ;
		UInt64 x_num2 = ;
		CxAssert();
		CxAssert();
		StringBuilder* x_stringBuilder = new StringBuilder();
		x_stringBuilder->Append(x_num2);
		CxAssert(String::op_Equality(x_stringBuilder->ToString(), new String(L"1")));
		x_stringBuilder->Insert(1, x_num);
		CxAssert(String::op_Equality(x_stringBuilder->ToString(), new String(L"10")));
		return;
	}
	void UInt64Test::CxAssert(Boolean x_x)
	{
		
		return;
	}
	void UInt64Test::CxAssert(Boolean x_x,Boolean x_y)
	{
		
		return;
	}
	UInt64Test::UInt64Test()
	{
	}
}
