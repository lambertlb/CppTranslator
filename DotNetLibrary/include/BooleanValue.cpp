#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	Int32 BooleanValue::FormatString(Char* where, const Int32 whereSize)
	{
		Int32 rtn;
		if (value) {
			wcscpy_s(where, whereSize, TrueString->characterData);
			rtn = TrueString->length;
		}
		else {
			wcscpy_s(where, whereSize, FalseString->characterData);
			rtn = FalseString->length;
		}
		return rtn;
	}
}
