#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	Int32 CharValue::FormatString(Char* where, const Int32 whereSize)
	{
		if (whereSize < 2)
			throw new IndexOutOfRangeException();
		*where = value;
		return 1;
	}
}