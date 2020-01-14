#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	class DLL_EXPORT Buffer {
	public:
		static void BlockCopy(Array* src, Int32 srcOffset, Array* dst, Int32 dstOffset, Int32 count);
		static Int32 ByteLength(Array* array);
		static Byte GetByte(Array* array, Int32 index);
		static void SetByte(Array* array, Int32 index, Byte value);
	};
}
