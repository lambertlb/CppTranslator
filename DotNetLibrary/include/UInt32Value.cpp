#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{

	Double DotnetLibrary::UInt32Value::get_AsDouble()
	{
		return value;
	}
	Int32 UInt32Value::FormatString(Char* where, const Int32 whereSize)
	{
		return(swprintf(where, whereSize, L"%d", value));
	}
}