#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	Int32 SingleValue::FormatString(Char* where, const Int32 whereSize)
	{
		return(swprintf(where, whereSize, L"%G", value));
	}
}
