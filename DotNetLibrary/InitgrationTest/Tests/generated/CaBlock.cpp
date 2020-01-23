#pragma once
#include "CaBlockHeader.h"
namespace MiniTest_NS
{
	void Program::Run()
	{
IL_0000:
		CABlock* x_caBlock = (new CABlock());
		BooleanTest* x_booleanTest = (new BooleanTest(x_caBlock));
		x_booleanTest->Test();
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
namespace CABlock_NS
{
	BooleanTest::BooleanTest(CABlock* x_caBlock)
	{
IL_0000:
		
		this->x_caBlock = x_caBlock;
		return;
	}
	void BooleanTest::Test()
	{
IL_0000:
		this->x_caBlock->Send((new String(L"Doing BooleanTest")));
		this->x_caBlock->Send((new String(L"\tDoing RunBooleanTest")));
		this->RunBooleanTest();
		this->x_caBlock->Send((new String(L"\tDoing BoolOperators")));
		this->BoolOperators();
		this->x_caBlock->Send((new String(L"\tDoing BoolBoxTest")));
		this->BoolBoxTest();
		return;
	}
	void BooleanTest::BoolBoxTest()
	{
IL_0000:
		Boolean x_flag = 1;
		Object* x_obj = (new BooleanValue(x_flag));
		this->CxAssert((Boolean)(BooleanValue(x_flag).Equals(x_obj)));
		this->CxAssert((Boolean)(x_obj->Equals(x_obj)));
		this->CxAssert((Boolean)(x_obj->get_AsBoolean()));
		this->CxAssert((Boolean)(String::Equals(x_obj->ToString(), (new String(L"True")))));
		return;
	}
	void BooleanTest::RunBooleanTest()
	{
IL_0000:
		Boolean x_flag = 1;
		Object* x_obj = (new BooleanValue(x_flag));
		this->CxAssert((Boolean)((BooleanValue(x_flag).CompareTo((Boolean)(1)) == 0)));
		this->CxAssert((Boolean)((BooleanValue(x_flag).CompareTo(x_obj) == 0)));
		this->CxAssert((Boolean)(BooleanValue(x_flag).Equals((Boolean)(1))));
		this->CxAssert((Boolean)(BooleanValue::Parse((new String(L"True")))));
		this->CxAssert((Boolean)(String::Equals((new String(L"True")), BooleanValue(x_flag).ToString())));
		this->CxAssert((Boolean)(String::Equals(BooleanValue::FalseString, (new String(L"False")))));
		this->CxAssert((Boolean)(String::Equals(BooleanValue::TrueString, (new String(L"True")))));
		return;
	}
	void BooleanTest::BoolOperators()
	{
IL_0000:
		Boolean x_flag = 1;
		Boolean x_flag2 = 0;
		Boolean x_flag3 = 0;
		Boolean x_flag4 = 1;
		this->CxAssert((Boolean)((x_flag & x_flag2)), (Boolean)(0));
		this->CxAssert((Boolean)((x_flag | x_flag2)));
		this->CxAssert((Boolean)((x_flag ^ x_flag2)));
		this->CxAssert((Boolean)((x_flag == 0)), (Boolean)(0));
		this->CxAssert((Boolean)((x_flag & x_flag2)), (Boolean)(0));
		this->CxAssert((Boolean)((x_flag | x_flag2)));
		this->CxAssert((Boolean)((x_flag == x_flag2)), (Boolean)(0));
		this->CxAssert((Boolean)((x_flag != x_flag2)));
		this->CxAssert((Boolean)(x_flag = (x_flag & x_flag4)));
		this->CxAssert((Boolean)(x_flag = (x_flag | x_flag4)));
		this->CxAssert((Boolean)(x_flag = (x_flag ^ x_flag3)));
		return;
	}
	void BooleanTest::CxAssert(Boolean x_x,Boolean x_y)
	{
IL_0000:
		if ((x_x != x_y))
		{
			this->x_caBlock->TestFailed((new String(L"Boolean TestFailed")));
		}

		return;
	}
	void BooleanTest::CxAssert(Boolean x_x)
	{
IL_0000:
		if ((x_x == 0))
		{
			this->x_caBlock->TestFailed((new String(L"Boolean TestFailed")));
		}

		return;
	}
	void CABlock::TestFailed(String* x_v)
	{
IL_0000:
		this->Send(x_v);
		return;
	}
}
