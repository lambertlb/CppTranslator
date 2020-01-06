#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	Int32 Int32Value::get_AsInt32()
	{
		return value;
	}
	Double Int32Value::get_AsDouble()
	{
		return (Double)value;
	}
	Int32 Int32Value::FormatString(Char* where, const Int32 whereSize)
	{
		return(swprintf(where, whereSize, L"%d", value));
	}
}