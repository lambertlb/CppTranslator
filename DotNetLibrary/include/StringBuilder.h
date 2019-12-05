#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	class StringBuilder : public Object
	{
	public:
		StringBuilder() {
		}
		StringBuilder& Append(Byte v) { return(*this); }
		StringBuilder& Insert(Int32 index, Byte v) { return(*this); }
	};
}
