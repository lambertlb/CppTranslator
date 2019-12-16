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
}
namespace MiniTest_NS
{
	Program::Program()
	{
IL_0000:
		
		this->x_dateTime1dArray = new Array(DateTimeType,4);
		*((DateTime*)this->x_dateTime1dArray->Address(0)) = DateTime(2003, 7, 23, 12, 30, 30, 100);
		*((DateTime*)this->x_dateTime1dArray->Address(1)) = DateTime(2003, 7, 23, 12, 30, 30, 200);
		*((DateTime*)this->x_dateTime1dArray->Address(2)) = DateTime(2003, 7, 23, 12, 30, 30, 300);
		*((DateTime*)this->x_dateTime1dArray->Address(3)) = DateTime(2003, 7, 23, 12, 30, 30, 400);
		Int32 x_i = 0;
		
		{
IL_00fe:
			if (x_i < this->x_dateTime1dArray->get_Length())
			{
				goto IL_009e;
			}
			else
			{
				goto leaveBlock2;
			}

		}
		{
IL_009e:
			DateTime x_d = *((DateTime*)this->x_dateTime1dArray->Address(x_i));
			this->CxAssert(DateTime::Equals(x_d, *((DateTime*)this->x_dateTime1dArray->Address(x_i))));
			Int32 x_j = 0;
			
			{
IL_00e8:
				if (x_j < this->x_dateTime1dArray->get_Length())
				{
					goto IL_00c9;
				}
				else
				{
					goto leaveBlock3;
				}

			}
			{
IL_00c9:
				DateTime x_d2 = *((DateTime*)this->x_dateTime1dArray->Address(x_j));
				this->CxAssert(DateTime::Equals(x_d2, *((DateTime*)this->x_dateTime1dArray->Address(x_j))));
				goto IL_00e7;
			}
			{
IL_00e7:
				++x_j;
				goto IL_00e8;
			}
leaveBlock3:

			goto IL_00fd;
		}
		{
IL_00fd:
			++x_i;
			goto IL_00fe;
		}
leaveBlock2:

		this->CxAssert(this->x_dateTime1dArray->get_Length() == 4);
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
	void Program::Test1(Int32 x_aa)
	{
		return;
	}
	Int32 Program::Main(Array* x_arvs)
	{
IL_0000:
		Program* x_program = new Program();
		return((Int32)0);
	}
}
