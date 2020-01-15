#pragma once
#include "DotnetTypes.h"
#include <wctype.h>

namespace DotnetLibrary
{
	Int32 CharValue::FormatString(Char* where, const Int32 whereSize)
	{
		if (whereSize < 2)
			throw new IndexOutOfRangeException();
		*where = value;
		return 1;
	}
	Boolean CharValue::IsDigit(Char v)
	{
		return(iswdigit(v));
	}
	Boolean CharValue::IsWhiteSpace(Char v)
	{
		return(iswspace(v));
	}
}