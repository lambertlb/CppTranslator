#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	Int32 SByteValue::FormatString(Char* where, const Int32 whereSize)
	{
		return(swprintf(where, whereSize, L"%d", value));
	}
}