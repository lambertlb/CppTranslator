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
	/**
	 * Emulator for the ,Net BitConverter class
	 */
	class DLL_EXPORT BitConverter: public Object
	{
	private:
		/**
		 * Figure out of this machine uses little Endian
		 * @return true if does
		 */
		static Boolean AmILittleEndian();
		/**
		 * Get bytes from pointer into an Byte Array
		 * @param ptr to bytes
		 * @param count how many bytes to get
		 * @return Byte array
		 */
		static Array* GetBytes(Byte* ptr, Int32 count);
		/**
		 * Put bytes in source array into destination array
		 * @param dst destination array
		 * @param src source array
		 * @param start_index starting index in source array
		 * @param count how many bytes to copy
		 */
		static void PutBytes(Byte* dst, Array* src, Int32 start_index, Int32 count);
	public:
		/**
		 * This is a little Endian machine
		 */
		static Boolean IsLittleEndian;
		/**
		 * Convert double to Int64
		 * @param value to convert
		 * @return Int64 with bits of double
		 */
		static Int64 DoubleToInt64Bits(Double value);
		/**
		 * Convert Int64 bits to double
		 * @param value to convert
		 * @return double value
		 */
		static Double Int64BitsToDouble(Int64 value);
		/**
		 * Get value as array of bytes
		 * @param value to convert
		 * @return array of bytes
		 */
		static Array* GetBytes(Boolean value);
		/**
		 * Get value as array of bytes
		 * @param value to convert
		 * @return array of bytes
		 */
		static Array* GetBytes(Char value);
		/**
		 * Get value as array of bytes
		 * @param value to convert
		 * @return array of bytes
		 */
		static Array* GetBytes(Double value);
		/**
		 * Get value as array of bytes
		 * @param value to convert
		 * @return array of bytes
		 */
		static Array* GetBytes(Int16 value);
		/**
		 * Get value as array of bytes
		 * @param value to convert
		 * @return array of bytes
		 */
		static Array* GetBytes(Int32 value);
		/**
		 * Get value as array of bytes
		 * @param value to convert
		 * @return array of bytes
		 */
		static Array* GetBytes(Int64 value);
		/**
		 * Get value as array of bytes
		 * @param value to convert
		 * @return array of bytes
		 */
		static Array* GetBytes(Single value);
		/**
		 * Get value as array of bytes
		 * @param value to convert
		 * @return array of bytes
		 */
		static Array* GetBytes(UInt16 value);
		/**
		 * Get value as array of bytes
		 * @param value to convert
		 * @return array of bytes
		 */
		static Array* GetBytes(UInt32 value);
		/**
		 * Get value as array of bytes
		 * @param value to convert
		 * @return array of bytes
		 */
		static Array* GetBytes(UInt64 value);
		/**
		 * Convert indexed value in array of bytes
		 * @param value array with value
		 * @param startIndex starting index of value
		 * @return bytes converted to value
		 */
		static Boolean ToBoolean(Array* value, Int32 startIndex);
		/**
		 * Convert indexed value in array of bytes
		 * @param value array with value
		 * @param startIndex starting index of value
		 * @return bytes converted to value
		 */
		static Char ToChar(Array* value, Int32 startIndex);
		/**
		 * Convert indexed value in array of bytes
		 * @param value array with value
		 * @param startIndex starting index of value
		 * @return bytes converted to value
		 */
		static Double ToDouble(Array* value, Int32 startIndex);
		/**
		 * Convert indexed value in array of bytes
		 * @param value array with value
		 * @param startIndex starting index of value
		 * @return bytes converted to value
		 */
		static Int16 ToInt16(Array* value, Int32 startIndex);
		/**
		 * Convert indexed value in array of bytes
		 * @param value array with value
		 * @param startIndex starting index of value
		 * @return bytes converted to value
		 */
		static Int32 ToInt32(Array* value, Int32 startIndex);
		/**
		 * Convert indexed value in array of bytes
		 * @param value array with value
		 * @param startIndex starting index of value
		 * @return bytes converted to value
		 */
		static Int64 ToInt64(Array* value, Int32 startIndex);
		/**
		 * Convert indexed value in array of bytes
		 * @param value array with value
		 * @param startIndex starting index of value
		 * @return bytes converted to value
		 */
		static Single ToSingle(Array* value, Int32 startIndex);
		/**
		 * Convert indexed value in array of bytes
		 * @param value array with value
		 * @param startIndex starting index of value
		 * @return bytes converted to value
		 */
		static UInt16 ToUInt16(Array* value, Int32 startIndex);
		/**
		 * Convert indexed value in array of bytes
		 * @param value array with value
		 * @param startIndex starting index of value
		 * @return bytes converted to value
		 */
		static UInt32 ToUInt32(Array* value, Int32 startIndex);
		/**
		 * Convert indexed value in array of bytes
		 * @param value array with value
		 * @param startIndex starting index of value
		 * @return bytes converted to value
		 */
		static UInt64 ToUInt64(Array* value, Int32 startIndex);
		/**
		 * Convert bytes in array to string
		 * @param value array with bytes
		 * @param startIndex index to first byte
		 * @param length how many byte to convert
		 * @return Bytes converted to string
		 */
		static String* ToString(Array* value, Int32 startIndex = 0, Int32 length = -1);
	};
}
