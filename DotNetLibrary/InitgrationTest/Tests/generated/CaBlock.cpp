#pragma once
#include "CaBlockHeader.h"
namespace CABlock_NS
{
	void CABlock::TestFailed(String* x_v)
	{
IL_0000:
		this->Send(x_v);
		return;
	}
	StringBuilderTest::StringBuilderTest(CABlock* x_caBlock)
	{
IL_0000:
		this->x_sb = (new StringBuilder());
		
		this->x_caBlock = x_caBlock;
		return;
	}
	void StringBuilderTest::Test()
	{
IL_0000:
		this->x_caBlock->Send((new String(L"Doing StringBuilderTest")));
		this->x_caBlock->Send((new String(L"\tDoing DoSBConstructTest")));
		this->DoSBConstructTest();
		this->x_caBlock->Send((new String(L"\tDoing DoSBPropertyTest")));
		this->DoSBPropertyTest();
		this->x_caBlock->Send((new String(L"\tDoing DoSBAppendTest")));
		this->DoSBAppendTest();
		this->x_caBlock->Send((new String(L"\tDoing DoSBMiscTest")));
		this->DoSBMiscTest();
		this->x_caBlock->Send((new String(L"\tDoing DoSBInsertTest")));
		this->DoSBInsertTest();
		this->x_caBlock->Send((new String(L"\tDoing DoSBReplaceTest")));
		this->DoSBReplaceTest();
		return;
	}
	void StringBuilderTest::DoSBConstructTest()
	{
IL_0000:
		this->CxAssert((this->x_sb->get_Length() == 0));
		this->x_sb = (new StringBuilder(100));
		this->CxAssert((this->x_sb->get_Capacity() == 100));
		this->x_sb = (new StringBuilder((new String(L"Test"))));
		this->CxAssert(String::Equals(this->x_sb->ToString(), (new String(L"Test"))));
		this->x_sb = (new StringBuilder(20, 25));
		this->CxAssert(((this->x_sb->get_Capacity() == 20) && (this->x_sb->get_MaxCapacity() == 25)));
		this->x_sb = (new StringBuilder((new String(L"Test")), 20));
		this->CxAssert((String::Equals(this->x_sb->ToString(), (new String(L"Test"))) && (this->x_sb->get_Capacity() == 20)));
		this->x_sb = (new StringBuilder((new String(L"test1234")), 1, 4, 20));
		this->CxAssert((String::Equals(this->x_sb->ToString(), (new String(L"est1"))) && (this->x_sb->get_Capacity() == 20)));
		String* x_a = (new StringBuilder((new String(L"Test"))))->ToString();
		this->CxAssert(String::Equals(x_a, (new String(L"Test"))));
		return;
	}
	void StringBuilderTest::DoSBPropertyTest()
	{
IL_0000:
		this->x_sb = (new StringBuilder((new String(L"Testing123")), 0, 10, 20));
		this->CxAssert(((this->x_sb->get_Capacity() == 20) && (this->x_sb->get_MaxCapacity() == Int32Value::MaxValue)));
		this->CxAssert((this->x_sb->get_Chars(7) == 49));
		this->CxAssert((this->x_sb->get_Length() == 10));
		this->x_sb->set_Length(7);
		this->CxAssert((this->x_sb->get_Length() == 7));
		this->x_sb->set_Capacity(22);
		this->CxAssert((this->x_sb->get_Capacity() == 22));
		this->x_sb->set_Chars(0, 116);
		this->CxAssert(String::Equals(this->x_sb->ToString(), (new String(L"testing"))));
		return;
	}
	void StringBuilderTest::DoSBAppendTest()
	{
IL_0000:
		this->x_sb->set_Length(0);
		this->x_sb->Append(1);
		this->CxAssert(String::Equals(this->x_sb->ToString(), (new String(L"True"))));
		this->CxAssert(String::Equals(this->x_sb->Append(65)->ToString(), (new String(L"TrueA"))));
		Array* x_value = new Array(CharType,4);
		(*((Char*)x_value->Address(0))) = 48;
		(*((Char*)x_value->Address(1))) = 49;
		(*((Char*)x_value->Address(2))) = 50;
		(*((Char*)x_value->Address(3))) = 51;
		this->CxAssert(String::Equals(this->x_sb->Append(x_value)->ToString(), (new String(L"TrueA0123"))));
		this->x_sb->set_Length(0);
		Double x_value2 = 3.14159;
		this->CxAssert(String::Equals(this->x_sb->Append(x_value2)->ToString(), (new String(L"3.14159"))));
		this->x_sb->set_Length(0);
		Int32 x_value3 = 666;
		this->CxAssert(String::Equals(this->x_sb->Append(x_value3)->ToString(), (new String(L"666"))));
		this->x_sb->set_Length(0);
		Int64 x_value4 = 666666666;
		this->CxAssert(String::Equals(this->x_sb->Append(x_value4)->ToString(), (new String(L"666666666"))));
		this->x_sb->set_Length(0);
		Object* x_obj = (new Int32Value(1));
		this->CxAssert(String::Equals(this->x_sb->Append(x_obj)->ToString(), (new String(L"1"))));
		this->x_sb->set_Length(0);
		this->CxAssert(String::Equals(this->x_sb->Append((new String(L"fred")))->ToString(), (new String(L"fred"))));
		UInt32 x_value5 = 777;
		this->x_sb->set_Length(0);
		this->CxAssert(String::Equals(this->x_sb->Append(x_value5)->ToString(), (new String(L"777"))));
		this->x_sb->set_Length(0);
		this->CxAssert(String::Equals(this->x_sb->Append(65, 4)->ToString(), (new String(L"AAAA"))));
		this->x_sb->set_Length(0);
		this->CxAssert(String::Equals(this->x_sb->Append(x_value, 1, 3)->ToString(), (new String(L"123"))));
		this->x_sb->set_Length(0);
		this->CxAssert(String::Equals(this->x_sb->Append((new String(L"3210")), 1, 3)->ToString(), (new String(L"210"))));
		this->x_sb->set_Length(0);
		this->CxAssert(String::Equals(this->x_sb->AppendFormat((new String(L"x={0}")), x_obj)->ToString(), (new String(L"x=1"))));
		Array* x_array = new Array(ObjectType,4);
		(*((Object**)x_array->Address(0))) = (new Int32Value(0));
		(*((Object**)x_array->Address(1))) = (new Int32Value(1));
		(*((Object**)x_array->Address(2))) = (new Int32Value(2));
		(*((Object**)x_array->Address(3))) = (new Int32Value(3));
		this->x_sb->set_Length(0);
		this->CxAssert(String::Equals(this->x_sb->AppendFormat((new String(L"y={0}{1}{2}{3}")), x_array)->ToString(), (new String(L"y=0123"))));
		this->x_sb->set_Length(0);
		this->CxAssert(String::Equals(this->x_sb->AppendFormat((new String(L"y={0}{1}")), (*((Object**)x_array->Address(0))), (*((Object**)x_array->Address(1))))->ToString(), (new String(L"y=01"))));
		this->x_sb->set_Length(0);
		this->CxAssert(String::Equals(this->x_sb->AppendFormat((new String(L"y={0}{1}{2}")), (*((Object**)x_array->Address(0))), (*((Object**)x_array->Address(1))), (*((Object**)x_array->Address(2))))->ToString(), (new String(L"y=012"))));
		this->x_sb->set_Length(0);
		this->CxAssert(String::Equals(this->x_sb->Append(65)->ToString(), (new String(L"A"))));
		Object* x_value6 = (new String(L"Test string as Object"));
		this->x_sb->set_Length(0);
		this->CxAssert(String::Equals(this->x_sb->Append(x_value6)->ToString(), (new String(L"Test string as Object"))));
		String* x_b = (new String(L"AB\a\b\t\r\v\f\n\"'\u00c2"));
		Array* x_value7 = new Array(CharType,12);
		(*((Char*)x_value7->Address(0))) = 65;
		(*((Char*)x_value7->Address(1))) = 66;
		(*((Char*)x_value7->Address(2))) = 7;
		(*((Char*)x_value7->Address(3))) = 8;
		(*((Char*)x_value7->Address(4))) = 9;
		(*((Char*)x_value7->Address(5))) = 13;
		(*((Char*)x_value7->Address(6))) = 11;
		(*((Char*)x_value7->Address(7))) = 12;
		(*((Char*)x_value7->Address(8))) = 10;
		(*((Char*)x_value7->Address(9))) = 34;
		(*((Char*)x_value7->Address(10))) = 39;
		(*((Char*)x_value7->Address(11))) = 194;
		this->x_sb = (new StringBuilder());
		this->x_sb->Append(x_value7);
		String* x_text = this->x_sb->ToString();
		this->CxAssert(String::Equals(this->x_sb->ToString(), x_b));
		return;
	}
	void StringBuilderTest::DoSBMiscTest()
	{
IL_0000:
		this->x_sb->set_Length(0);
		this->x_sb->set_Capacity(10);
		this->x_sb->EnsureCapacity(30);
		this->CxAssert((this->x_sb->get_Capacity() >= 30));
		this->x_sb->Append((new String(L"Test")));
		StringBuilder* x_stringBuilder = (new StringBuilder((new String(L"Test"))));
		x_stringBuilder->set_Capacity(10);
		x_stringBuilder->EnsureCapacity(30);
		this->CxAssert(this->x_sb->Equals(x_stringBuilder));
		this->x_sb->set_Length(0);
		this->x_sb->Append((new String(L"1234567890")));
		this->x_sb->Remove(1, 4);
		this->CxAssert(String::Equals(this->x_sb->ToString(), (new String(L"167890"))));
		this->x_sb->set_Length(0);
		this->x_sb->Append((new String(L"1234567890")));
		this->CxAssert(String::Equals(this->x_sb->ToString(1, 8), (new String(L"23456789"))));
		return;
	}
	void StringBuilderTest::DoSBInsertTest()
	{
IL_0000:
		String* x_value = (new String(L"{}"));
		this->x_sb->set_Length(0);
		this->x_sb->Append(x_value);
		this->x_sb->Insert(1, 1);
		this->CxAssert(String::Equals(this->x_sb->ToString(), (new String(L"{True}"))));
		this->CxAssert(String::Equals(this->x_sb->Insert(5, 65)->ToString(), (new String(L"{TrueA}"))));
		Array* x_value2 = new Array(CharType,4);
		(*((Char*)x_value2->Address(0))) = 48;
		(*((Char*)x_value2->Address(1))) = 49;
		(*((Char*)x_value2->Address(2))) = 50;
		(*((Char*)x_value2->Address(3))) = 51;
		this->CxAssert(String::Equals(this->x_sb->Insert(6, x_value2)->ToString(), (new String(L"{TrueA0123}"))));
		this->x_sb->set_Length(0);
		this->x_sb->Append(x_value);
		Double x_value3 = 3.14159;
		this->CxAssert(String::Equals(this->x_sb->Insert(1, x_value3)->ToString(), (new String(L"{3.14159}"))));
		this->x_sb->set_Length(0);
		this->x_sb->Append(x_value);
		Int32 x_value4 = 666;
		this->CxAssert(String::Equals(this->x_sb->Insert(1, x_value4)->ToString(), (new String(L"{666}"))));
		this->x_sb->set_Length(0);
		this->x_sb->Append(x_value);
		Int64 x_value5 = 666666666;
		this->CxAssert(String::Equals(this->x_sb->Insert(1, x_value5)->ToString(), (new String(L"{666666666}"))));
		this->x_sb->set_Length(0);
		this->x_sb->Append(x_value);
		Object* x_value6 = (new Int32Value(1));
		this->CxAssert(String::Equals(this->x_sb->Insert(1, x_value6)->ToString(), (new String(L"{1}"))));
		this->x_sb->set_Length(0);
		this->x_sb->Append(x_value);
		this->CxAssert(String::Equals(this->x_sb->Insert(1, (new String(L"fred")))->ToString(), (new String(L"{fred}"))));
		UInt32 x_value7 = 777;
		this->x_sb->set_Length(0);
		this->x_sb->Append(x_value);
		this->CxAssert(String::Equals(this->x_sb->Insert(1, x_value7)->ToString(), (new String(L"{777}"))));
		this->x_sb->set_Length(0);
		this->x_sb->Append(x_value);
		this->CxAssert(String::Equals(this->x_sb->Insert(1, (new String(L"A")), 4)->ToString(), (new String(L"{AAAA}"))));
		this->x_sb->set_Length(0);
		this->x_sb->Append(x_value);
		this->CxAssert(String::Equals(this->x_sb->Insert(1, x_value2, 1, 3)->ToString(), (new String(L"{123}"))));
		return;
	}
	void StringBuilderTest::DoSBReplaceTest()
	{
IL_0000:
		this->x_sb->set_Length(0);
		this->x_sb->Append((new String(L"aaaaaaa")));
		this->CxAssert(String::Equals(this->x_sb->Replace(97, 65)->ToString(), (new String(L"AAAAAAA"))));
		this->CxAssert(String::Equals(this->x_sb->Replace((new String(L"AA")), (new String(L"BBB")))->ToString(), (new String(L"BBBBBBBBBA"))));
		this->CxAssert(String::Equals(this->x_sb->Replace(66, 67, 1, 7)->ToString(), (new String(L"BCCCCCCCBA"))));
		this->CxAssert(String::Equals(this->x_sb->Replace((new String(L"CCC")), (new String(L"DDD")), 2, 5)->ToString(), (new String(L"BCDDDCCCBA"))));
		this->x_sb->set_Length(0);
		this->x_sb->Append((new String(L"aaaaaaa")));
		String* x_a = this->x_sb->Replace((new String(L"aa")), (new String(L"BBB")), 1, 5)->ToString();
		this->CxAssert(String::Equals(x_a, (new String(L"aBBBBBBaa"))));
		return;
	}
	void StringBuilderTest::CxAssert(Boolean x_x)
	{
IL_0000:
		if ((x_x == 0))
		{
			this->x_caBlock->TestFailed((new String(L"StringBuilder TestFailed")));
		}

		return;
	}
	void StringBuilderTest::CxAssert(Boolean x_x,Boolean x_y)
	{
IL_0000:
		if ((x_x != x_y))
		{
			this->x_caBlock->TestFailed((new String(L"StringBuilder TestFailed")));
		}

		return;
	}
}
namespace MiniTest_NS
{
	void Program::Run()
	{
IL_0000:
		CABlock* x_caBlock = (new CABlock());
		StringBuilderTest* x_stringBuilderTest = (new StringBuilderTest(x_caBlock));
		x_stringBuilderTest->Test();
		return;
	}
	void Program::CxAssert(Boolean x_isTrue)
	{
		return;
	}
	void Program::CxAssert(Double x_x,Double x_y)
	{
		return;
	}
	Int32 Program::Main(Array* x_arvs)
	{
IL_0000:
		Program* x_program = (new Program());
		x_program->Run();
		return((Int32)0);
	}
}
