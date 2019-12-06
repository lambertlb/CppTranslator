#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	class StringBuilder : public Object
	{
	public:
		StringBuilder() {
		}
		StringBuilder(String* value, Int32 startIndex, Int32 length, Int32 capacity) {
		}
		StringBuilder& Append(Byte v) { return(*this); }
		StringBuilder& Insert(Int32 index, Byte v) { return(*this); }
		Char* Address(Int32 index1, Int32 index2 = -1, Int32 index3 = -1) {
			return(nullptr);
		}
	};
}
