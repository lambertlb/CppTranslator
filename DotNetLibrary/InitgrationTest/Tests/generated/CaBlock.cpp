#pragma once
#include "CaBlockHeader.h"
namespace MiniTest_NS
{
	ProgramRaw::ProgramRaw()
	{
		PointerType<typedefRaw> x_typedef = new typedefRaw();
		x_typedef->set_Friend(x_friend_TestNameEnu);
	}
	Int32 ProgramRaw::Main(PointerType<ArrayRaw<String>> x_arvs)
	{
		return 0;
	}
	TestNameEnu typedefRaw::get_Friend()
	{
		return x_friend;
	}
	void typedefRaw::set_Friend(TestNameEnu x_value )
	{
		x_friend = x_value;
	}
	typedefRaw::typedefRaw()
	{
	}
}
