// Copyright (c) 2019 LLambert
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this
// software and associated documentation files (the "Software"), to deal in the Software
// without restriction, including without limitation the rights to use, copy, modify, merge,
// publish, distribute, sub-license, and/or sell copies of the Software, and to permit persons
// to whom the Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or
// substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
// INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
// PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
// FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
// OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	/*!
	 * Emulate .Net Buffer Class to
	 * Manipulates arrays of primitive types.
	 */
	class DLL_EXPORT Buffer
	{
	public:
		/*!
		 * Copies a specified number of bytes from a source array starting at a particular offset to a destination array starting at a particular offset.
		 * @param src source array
		 * @param srcOffset offset into source
		 * @param dst destination array
		 * @param dstOffset offset into destination
		 * @param count how many bytes
		 */
		static void BlockCopy(Array* src, Int32 srcOffset, Array* dst, Int32 dstOffset, Int32 count);
		/*!
		 * Returns the number of bytes in the specified array.
		 * @param array with bytes
		 * @return amount of bytes
		 */
		static Int32 ByteLength(Array* array);
		/*!
		 * Retrieves the byte at the specified location in the specified array.
		 * @param array with bytes
		 * @param index to byte
		 * @return byte at index
		 */
		static Byte GetByte(Array* array, Int32 index);
		/*!
		 * Assigns a specified value to a byte at a particular location in a specified array.
		 * @param array with bytes
		 * @param index to byte
		 * @param value to set in byte
		 */
		static void SetByte(Array* array, Int32 index, Byte value);
	};
}
