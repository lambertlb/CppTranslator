#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	class Math {
	public:
		static Byte	Max(Byte v1, Byte v2) { return(v1 > v2 ? v1 : v2); }
		static Byte	Min(Byte v1, Byte v2) { return(v1 < v2 ? v1 : v2); }
	};
}
