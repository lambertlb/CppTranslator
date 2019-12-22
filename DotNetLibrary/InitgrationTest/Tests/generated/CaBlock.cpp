#pragma once
#include "CaBlockHeader.h"
namespace CABlock_NS
{
	void CABlock::Send(String* x_v)
	{
		return;
	}
	void CABlock::TestFailed(String* x_v)
	{
		return;
	}
	CABlock::CABlock()
	{
	}
	StringTest::StringTest(CABlock* x_caBlock)
	{
IL_0000:
		
		this->x_caBlock = x_caBlock;
		return;
	}
	void StringTest::Test()
	{
IL_0000:
		this->x_caBlock->Send((new String(L"Doing StringTest")));
		this->x_caBlock->Send((new String(L"\tDoing DoIndexTest")));
		this->DoIndexTest();
		this->x_caBlock->Send((new String(L"\tDoing DoMiscTest")));
		this->DoMiscTest();
		this->x_caBlock->Send((new String(L"\tDoing DoEqualsTest")));
		this->DoEqualsTest();
		this->x_caBlock->Send((new String(L"\tDoing DoParsingTest")));
		this->DoParsingTest();
		this->x_caBlock->Send((new String(L"\tDoing DoConcatTest")));
		this->DoConcatTest();
		return;
	}
	void StringTest::DoIndexTest()
	{
IL_0000:
		String* x_text = (new String(L"12345"));
		this->CxAssert((x_text->get_Length() == 5));
		this->CxAssert((x_text->get_Chars(0) == 49));
		this->CxAssert((x_text->get_Chars(1) == 50));
		this->CxAssert((x_text->get_Chars(2) == 51));
		this->CxAssert((x_text->get_Chars(3) == 52));
		this->CxAssert((x_text->get_Chars(4) == 53));
		return;
	}
	void StringTest::DoMiscTest()
	{
IL_0000:
		String* x_text = (new String(32, 10));
		this->CxAssert((x_text->get_Length() == 10));
		String* x_text2 = (new String(L"12345"));
		Array* x_array = new Array(CharType,30);
		x_text2->CopyTo(0, x_array, 0, x_text2->get_Length());
		Int32 x_num = 0;
		String* x_text3 = x_text2;
		Int32 x_i = 0;
		
		{
IL_006a:
			if ((x_i < x_text3->get_Length()))
			{
				goto IL_004e;
			}
			else
			{
				goto leaveBlock2;
			}

		}
		{
IL_004e:
			Char x_c = x_text3->get_Chars(x_i);
			this->CxAssert(((*((UInt16*)x_array->Address(x_num))) == x_c));
			++x_num;
			goto IL_0068;
		}
		{
IL_0068:
			++x_i;
			goto IL_006a;
		}
leaveBlock2:

		x_array = x_text2->ToCharArray();
		this->CxAssert(((x_array != nullptr) && (x_array->get_Length() == x_text2->get_Length())));
		String* x_a = (new String(x_array));
		this->CxAssert(String::Equals(x_a, x_text2));
		String* x_a2 = (new String(x_array, 0, 2));
		this->CxAssert(String::Equals(x_a2, (new String(L"12"))));
		this->CxAssert(String::op_Inequality(x_a2, (new String(L"22"))));
		this->CxAssert((String::Equals(x_a2, (new String(L"22"))) == 0));
		x_a2 = (new String(x_text2->ToCharArray(), 0, x_text2->get_Length()));
		this->CxAssert(String::Equals(x_a2, x_text2));
		this->CxAssert((String::Compare((new String(L"abc")), (new String(L"ABC")), 1) == 0));
		this->CxAssert((String::Compare((new String(L"1abce")), 1, (new String(L"abc")), 0, 3) == 0));
		this->CxAssert((String::Compare((new String(L"1abce")), 1, (new String(L"ABC")), 0, 3, 1) == 0));
		this->CxAssert((String::CompareOrdinal((new String(L"abc")), (new String(L"abc"))) == 0));
		this->CxAssert((String::CompareOrdinal((new String(L"1abce")), 1, (new String(L"abc")), 0, 3) == 0));
		x_a2 = String::Copy(x_text2);
		this->CxAssert(String::Equals(x_a2, x_text2));
		x_a2 = String::Format((new String(L"1 = {{{0,-4}}} 2 = {1,4} 3 = {2}!")), (new Int32Value(1)), (new Int32Value(2)), (new Int32Value(3)));
		this->CxAssert(String::Equals(x_a2, (new String(L"1 = {1   } 2 =    2 3 = 3!"))));
		String* x_a3 = x_a2->ToString();
		this->CxAssert(String::Equals(x_a3, (new String(L"1 = {1   } 2 =    2 3 = 3!"))));
		String* x_empty = String::Empty;
		this->CxAssert(((x_empty != nullptr) && String::Equals(x_empty, (new String(L"")))));
		x_a2 = String::Format((new String(L"1 = {{{0,-4}}} 2 = {1,4}!")), (new Int32Value(1)), (new Int32Value(2)));
		this->CxAssert(String::Equals(x_a2, (new String(L"1 = {1   } 2 =    2!"))));
		x_a2 = String::Format((new String(L"1 = {{{0,-4}}}!")), (new Int32Value(1)));
		this->CxAssert(String::Equals(x_a2, (new String(L"1 = {1   }!"))));
		Array* x_args = new Array(ObjectType,3);
		(*((Object**)x_args->Address(0))) = (new Int32Value(1));
		(*((Object**)x_args->Address(1))) = (new Int32Value(2));
		(*((Object**)x_args->Address(2))) = (new Int32Value(3));
		x_a2 = String::Format((new String(L"1 = {{{0,-4}}} 2 = {1,4} 3 = {2}!")), x_args);
		CharEnumerator* x_enumerator = x_a2->GetEnumerator();
		Int32 x_num2 = 0;
		
		{
IL_02d4:
			if (x_enumerator->MoveNext())
			{
				goto IL_02b8;
			}
			else
			{
				goto leaveBlock3;
			}

		}
		{
IL_02b8:
			Char x_current = x_enumerator->get_Current();
			this->CxAssert((x_current == x_a2->get_Chars(x_num2++)));
			goto IL_02d4;
		}
leaveBlock3:

		x_enumerator->Reset();
		Double x_num3 = 2;
		//String* x_text4 = String::Concat(Object* I_0 = new Array(ObjectType,5);
		//(*((Object**)I_0->Address(0))) = x_text2;
		//(*((Object**)I_0->Address(1))) = x_empty;
		//(*((Object**)I_0->Address(2))) = (new Int32Value(x_num2));
		//(*((Object**)I_0->Address(3))) = (new DoubleValue(x_num3));
		//(*((Object**)I_0->Address(4))) = (new Int32Value(x_num)));
		StringTest::TestConcat(x_text2, x_num, x_empty, x_num2, x_num3);
		String* x_a4 = (new String(L"\""));
		this->CxAssert(String::Equals(x_a4, (new String(L"\""))));
		x_a4 = (new String(L"c:\\Retest"));
		this->CxAssert(String::Equals(x_a4, (new String(L"c:\\Retest"))));
		x_a4 = (new String(L"c:\\Retest"));
		this->CxAssert(String::Equals(x_a4, (new String(L"c:\\Retest"))));
		return;
	}
	void StringTest::TestConcat(String* x_str1,Int32 x_index,String* x_str4,Int32 x_i,Double x_dbl)
	{
IL_0000:
		//String* x_text = String::Concat(Object* I_0 = new Array(ObjectType,5);
		//(*((Object**)I_0->Address(0))) = x_str1;
		//(*((Object**)I_0->Address(1))) = x_str4;
		//(*((Object**)I_0->Address(2))) = (new Int32Value(x_i));
		//(*((Object**)I_0->Address(3))) = (new DoubleValue(x_dbl));
		//(*((Object**)I_0->Address(4))) = (new Int32Value(x_index)));
		return;
	}
	void StringTest::DoEqualsTest()
	{
IL_0000:
		String* x_text = (new String(L"12345"));
		this->CxAssert(String::Equals(x_text, (new String(L"12345"))));
		this->CxAssert(String::Equals(x_text, (new String(L"12345"))));
		this->CxAssert(x_text->Equals(x_text));
		this->CxAssert(x_text->Equals(x_text));
		return;
	}
	void StringTest::DoParsingTest()
	{
IL_0000:
		String* x_text = (new String(L"12 34 56"));
		Array* x_array = x_text->Split(nullptr);
		this->CxAssert((x_array->get_Length() == 3));
		this->CxAssert(String::Equals((new String(L"12")), (*((Object**)x_array->Address(0)))));
		this->CxAssert(String::Equals((new String(L"34")), (*((Object**)x_array->Address(1)))));
		this->CxAssert(String::Equals((new String(L"56")), (*((Object**)x_array->Address(2)))));
		String* x_text2 = (new String(L"42, 12, 19"));
		Array* x_separator = new Array(CharType,4);
		(*((Char*)x_separator->Address(0))) = 32;
		(*((Char*)x_separator->Address(1))) = 44;
		(*((Char*)x_separator->Address(2))) = 46;
		(*((Char*)x_separator->Address(3))) = 58;
		x_array = x_text2->Split(x_separator);
		this->CxAssert((x_array->get_Length() == 5));
		this->CxAssert(String::Equals((new String(L"42")), (*((Object**)x_array->Address(0)))));
		this->CxAssert(String::Equals((new String(L"")), (*((Object**)x_array->Address(1)))));
		this->CxAssert(String::Equals((new String(L"12")), (*((Object**)x_array->Address(2)))));
		this->CxAssert(String::Equals((new String(L"")), (*((Object**)x_array->Address(3)))));
		this->CxAssert(String::Equals((new String(L"19")), (*((Object**)x_array->Address(4)))));
		x_array = x_text2->Split(x_separator, 2);
		this->CxAssert((x_array->get_Length() == 2));
		this->CxAssert(String::Equals((new String(L"42")), (*((Object**)x_array->Address(0)))));
		this->CxAssert(String::Equals((new String(L" 12, 19")), (*((Object**)x_array->Address(1)))));
		String* x_b = x_text->Substring(3);
		this->CxAssert(String::Equals((new String(L"34 56")), x_b));
		x_b = x_text->Substring(3, 2);
		this->CxAssert(String::Equals((new String(L"34")), x_b));
		String* x_text3 = (new String(L"  12345  "));
		String* x_b2 = x_text3->Trim();
		this->CxAssert(String::Equals((new String(L"12345")), x_b2));
		String* x_text4 = (new String(L"*;|@123***456@|;*"));
		String* x_text5 = (new String(L"*;|@"));
		Array* x_trimChars = x_text5->ToCharArray();
		x_b2 = x_text4->Trim(x_trimChars);
		this->CxAssert(String::Equals((new String(L"123***456")), x_b2));
		x_b2 = x_text3->TrimStart(Array::Empty());
		this->CxAssert(String::Equals((new String(L"12345  ")), x_b2));
		x_b2 = x_text4->TrimStart(x_trimChars);
		this->CxAssert(String::Equals((new String(L"123***456@|;*")), x_b2));
		x_b2 = x_text3->TrimEnd(Array::Empty());
		this->CxAssert(String::Equals((new String(L"  12345")), x_b2));
		x_b2 = x_text4->TrimEnd(x_trimChars);
		this->CxAssert(String::Equals((new String(L"*;|@123***456")), x_b2));
		Int32 x_num = String::Compare(x_text, x_text3);
		this->CxAssert((x_num > 0));
		x_num = x_text3->CompareTo(x_text);
		this->CxAssert((x_num < 0));
		x_num = x_text3->CompareTo(x_text);
		this->CxAssert((x_num < 0));
		this->CxAssert(x_text->EndsWith((new String(L"56"))));
		Array* x_array2 = new Array(CharType,2);
		(*((Char*)x_array2->Address(0))) = 51;
		(*((Char*)x_array2->Address(1))) = 52;
		this->CxAssert((x_text->IndexOfAny(x_array2) == 3));
		this->CxAssert((x_text->IndexOfAny(x_array2, 1) == 3));
		this->CxAssert((x_text->IndexOfAny(x_array2, 1, 3) == 3));
		this->CxAssert((x_text->IndexOf(53) == 6));
		this->CxAssert((x_text->IndexOf(32, 3) == 5));
		this->CxAssert((x_text->IndexOf(32, 3, 3) == 5));
		this->CxAssert((x_text->IndexOf((new String(L"56"))) == 6));
		this->CxAssert((x_text->IndexOf((new String(L" ")), 3) == 5));
		this->CxAssert((x_text->IndexOf((new String(L" ")), 3, 3) == 5));
		String* x_text6 = (new String(L"11223311"));
		this->CxAssert((x_text6->LastIndexOf(49) == 7));
		this->CxAssert((x_text6->LastIndexOf(49, 4) == 1));
		this->CxAssert((x_text6->LastIndexOf(49, 4, 4) == 1));
		this->CxAssert((x_text6->LastIndexOf((new String(L"11"))) == 6));
		this->CxAssert((x_text6->LastIndexOf((new String(L"11")), 4) == 0));
		this->CxAssert((x_text6->LastIndexOf((new String(L"11")), 4, 5) == 0));
		(*((Int16*)x_array2->Address(0))) = 49;
		(*((Int16*)x_array2->Address(1))) = 50;
		this->CxAssert((x_text6->LastIndexOfAny(x_array2) == 7));
		this->CxAssert((x_text6->LastIndexOfAny(x_array2, 4) == 3));
		this->CxAssert((x_text6->LastIndexOfAny(x_array2, 4, 4) == 3));
		String* x_a = x_text6->PadLeft((3 + x_text6->get_Length()));
		this->CxAssert(String::Equals(x_a, (new String(L"   11223311"))));
		x_a = x_text6->PadLeft((3 + x_text6->get_Length()), 45);
		this->CxAssert(String::Equals(x_a, (new String(L"---11223311"))));
		x_a = x_text6->PadRight((3 + x_text6->get_Length()));
		this->CxAssert(String::Equals(x_a, (new String(L"11223311   "))));
		x_a = x_text6->PadRight((3 + x_text6->get_Length()), 45);
		this->CxAssert(String::Equals(x_a, (new String(L"11223311---"))));
		this->CxAssert(x_text6->StartsWith((new String(L"1122"))));
		this->CxAssert(String::Equals(x_text6->Replace(49, 120), (new String(L"xx2233xx"))));
		this->CxAssert(String::Equals(x_text6->Replace((new String(L"1")), (new String(L"x"))), (new String(L"xx2233xx"))));
		this->CxAssert(String::Equals(x_text6->Replace((new String(L"11")), (new String(L"x"))), (new String(L"x2233x"))));
		this->CxAssert(String::Equals(x_text6->Remove(2, 2), (new String(L"113311"))));
		this->CxAssert(String::Equals((new String(L"aaAAaaAA"))->ToUpper(), (new String(L"AAAAAAAA"))));
		this->CxAssert(String::Equals((new String(L"aaAAaaAA"))->ToLower(), (new String(L"aaaaaaaa"))));
		Array* x_value = new Array(StringType,3);
		(*((String**)x_value->Address(0))) = (new String(L"1"));
		(*((String**)x_value->Address(1))) = (new String(L"2"));
		(*((String**)x_value->Address(2))) = (new String(L"3"));
		this->CxAssert(String::Equals(String::Join((new String(L",")), x_value), (new String(L"1,2,3"))));
		this->CxAssert(String::Equals(String::Join((new String(L",")), x_value, 1, 2), (new String(L"2,3"))));
		x_text6 = x_text->Insert(3, (new String(L"111")));
		this->CxAssert(String::Equals(x_text6, (new String(L"12 11134 56"))));
		String* x_text7 = (new String(L"3.33"));
		if (x_text7->CompareTo((new String(L"3.33"))))
		{
			this->CxAssert(0);
		}

		return;
	}
	void StringTest::DoConcatTest()
	{
IL_0000:
		Array* x_array = new Array(ObjectType,4);
		(*((Object**)x_array->Address(0))) = (new String(L"1 "));
		(*((Object**)x_array->Address(1))) = (new String(L"2 "));
		(*((Object**)x_array->Address(2))) = (new String(L"3 "));
		(*((Object**)x_array->Address(3))) = (new String(L"4"));
		String* x_a = String::Concat((*((Object**)x_array->Address(0))));
		this->CxAssert(String::Equals(x_a, (new String(L"1 "))));
		x_a = String::Concat(x_array);
		this->CxAssert(String::Equals(x_a, (new String(L"1 2 3 4"))));
		Array* x_array2 = new Array(StringType,4);
		(*((String**)x_array2->Address(0))) = (new String(L"1 "));
		(*((String**)x_array2->Address(1))) = (new String(L"2 "));
		(*((String**)x_array2->Address(2))) = (new String(L"3 "));
		(*((String**)x_array2->Address(3))) = (new String(L"4"));
		x_a = String::Concat(x_array2);
		this->CxAssert(String::Equals(x_a, (new String(L"1 2 3 4"))));
		x_a = String::Concat((*((Object**)x_array->Address(0))), (*((Object**)x_array->Address(1))));
		this->CxAssert(String::Equals(x_a, (new String(L"1 2 "))));
		x_a = String::Concat((*((Object**)x_array2->Address(0))), (*((Object**)x_array2->Address(1))));
		this->CxAssert(String::Equals(x_a, (new String(L"1 2 "))));
		x_a = String::Concat((*((Object**)x_array->Address(0))), (*((Object**)x_array->Address(1))), (*((Object**)x_array->Address(2))));
		this->CxAssert(String::Equals(x_a, (new String(L"1 2 3 "))));
		x_a = String::Concat((*((Object**)x_array2->Address(0))), (*((Object**)x_array2->Address(1))), (*((Object**)x_array2->Address(2))));
		this->CxAssert(String::Equals(x_a, (new String(L"1 2 3 "))));
		x_a = String::Concat((*((Object**)x_array2->Address(0))), (*((Object**)x_array2->Address(1))), (*((Object**)x_array2->Address(2))), (*((Object**)x_array2->Address(3))));
		this->CxAssert(String::Equals(x_a, (new String(L"1 2 3 4"))));
		return;
	}
	void StringTest::CxAssert(Boolean x_x)
	{
IL_0000:
		if ((x_x == 0))
		{
			this->x_caBlock->TestFailed((new String(L"String TestFailed")));
		}

		return;
	}
	StringTest::StringTest()
	{
	}
}
namespace MiniTest_NS
{
	void Program::CxAssert(Boolean x_isTrue)
	{
		return;
	}
	void Program::CxAssert(Double x_x,Double x_y)
	{
		return;
	}
	void Program::Test1(Int32 x_aa)
	{
		return;
	}
	Int32 Program::Main(Array* x_arvs)
	{
IL_0000:
		Program* x_program = (new Program());
		return((Int32)0);
	}
	Program::Program()
	{
	}
}
