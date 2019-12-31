#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{

	TimeSpan DotnetLibrary::TimeSpanValue::get_AsTimeSpan()
	{
		return value;
	}
}