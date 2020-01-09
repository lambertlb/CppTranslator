#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	Int32 BooleanValue::FormatString(Char* where, const Int32 whereSize)
	{
		Int32 rtn;
		if (value) {
			wcscpy_s(where, whereSize, TrueString->get_Buffer());
			rtn = TrueString->get_Length();
		}
		else {
			wcscpy_s(where, whereSize, FalseString->get_Buffer());
			rtn = FalseString->get_Length();
		}
		return rtn;
	}
}
