#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	Int32 UInt64Value::FormatString(Char* where, const Int32 whereSize)
	{
		return(swprintf(where, whereSize, L"%lld", value));
	}
}
