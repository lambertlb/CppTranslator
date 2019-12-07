#pragma once
#include "CaBlockHeader.h"
namespace MiniTest_NS
{
	Program::Program()
	{
		Int32 x_num = 50;
		Byte x_b = x_num;
		Object* x_obj = new Int32Value(x_num);
		Int32 x_num2 = x_obj->get_AsInt32();
		CxAssert((ByteValue(x_b)).Equals(50));
		CxAssert((Int32Value(x_num2)).Equals(50));
		x_b = ByteValue::MaxValue;
		x_b = ( x_b + 1 );
		CxAssert((ByteValue(x_b)).Equals(0));
		Object* x_obj2 = 5;
		CxAssert(x_obj2->Equals(5));
		CxAssert(((x_obj2->ToString()))->Equals((new String("5"))));
	}
	void Program::CxAssert(Boolean x_isTrue)
	{
	}
	Int32 Program::Main(Array* x_arvs)
	{
		Program* x_program = new Program();
		return 0;
	}
}
