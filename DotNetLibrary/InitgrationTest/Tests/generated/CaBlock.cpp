#pragma once
#include "CaBlockHeader.h"
namespace MiniTest_NS
{
	ProgramRaw::ProgramRaw()
	{
		PointerType<TestAbstractRaw> x_testAbstract = new TestAbstractRaw();
		Boolean x_flag = x_testAbstract->MustImplement() == 2;
		Boolean x_flag2 = x_testAbstract->DidImplement() == 1;
	}
	Int32 ProgramRaw::Main(PointerType<ArrayRaw<String>> x_arvs)
	{
		return 0;
	}
	AbstractRaw::AbstractRaw(Int32 x_i,Int32 x_j)
	{
		x_data1 = x_i;
		x_data2 = x_j;
	}
	Int32 AbstractRaw::DidImplement()
	{
		return x_data1;
	}
	TestAbstractRaw::TestAbstractRaw() : AbstractRaw (1,2)
	{
	}
	Int32 TestAbstractRaw::MustImplement()
	{
		return x_data2;
	}
	Int32 TestAbstractRaw::MustImplement(Int32 x_i)
	{
		return x_data2;
	}
	Int32 TestAbstractRaw::MustImplement(Int64 x_i)
	{
		return x_data2;
	}
	String TestAbstractRaw::ToString()
	{
		return new StringRaw("TestAbstract");
	}
}
