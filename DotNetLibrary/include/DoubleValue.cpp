#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	Int32 DoubleValue::FormatString(Char* where, const Int32 whereSize)
	{
		return(swprintf(where, whereSize, L"%G", value));
	}
}
