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
	 * Boxing class for UInt16 value
	 * Derived from Object so it can be treated as Object*
	 */
	class DLL_EXPORT UInt16Value: public ValueType
	{
		UInt16 value;
	public:
		UInt16Value(UInt16 v) {
			value = v;
		}

		/*!
		 * Convert as boolean
		 * @return value as boolean
		 */
		virtual Boolean get_AsBoolean();
		/*!
		 * Convert as Char
		 * @return value as Char
		 */
		virtual Char get_AsChar();
		/*!
		 * Convert as Byte
		 * @return value as Byte
		 */
		virtual Byte get_AsByte();
		/*!
		 * Convert as SByte
		 * @return value as SByte
		 */
		virtual SByte get_AsSByte();
		/*!
		 * Convert as Int16
		 * @return value as Int16
		 */
		virtual Int16 get_AsInt16();
		/*!
		 * Convert as UInt16
		 * @return value as UInt16
		 */
		virtual UInt16 get_AsUInt16();
		/*!
		 * Convert as Int32
		 * @return value as Int32
		 */
		virtual Int32 get_AsInt32();
		/*!
		 * Convert as UInt32
		 * @return value as UInt32
		 */
		virtual UInt32 get_AsUInt32();
		/*!
		 * Convert as Int64
		 * @return value as Int64
		 */
		virtual Int64 get_AsInt64();
		/*!
		 * Convert as UInt64
		 * @return value as UInt64
		 */
		virtual UInt64 get_AsUInt64();
		/*!
		 * Convert as Single
		 * @return value as Single
		 */
		virtual Single get_AsSingle();
		/*!
		 * Convert as Double
		 * @return value as Double
		 */
		virtual Double get_AsDouble();
		/*!
		 * Compare to value -1 < 0 > 1
		 * @param valueToCompare value to compare
		 * @return -1, 0 ,1
		 */
		virtual Int32 CompareTo(UInt16 valueToCompare);
		/*!
		 * Compare to Object value -1 < 0 > 1
		 * @param valueToCompare value to compare
		 * @return -1, 0 ,1
		 */
		virtual Int32 CompareTo(Object* valueToCompare);
		/*!
		 * Are values equal
		 * @param valueToCompare value to compare
		 * @return true if equal
		 */
		virtual bool Equals(Object* valueToCompare);
		/*!
		 * Are values equal
		 * @param valueToCompare value to compare
		 * @return true if equal
		 */
		virtual bool Equals(UInt16 valueToCompare);
		/*!
		 * Format this string
		 * @param where to place characters
		 * @param whereSize size of where
		 * @return amount of characters placed in where
		 */
		virtual Int32 FormatString(Char* where, const Int32 whereSize);
		/*!
		 * Get raw type of this boxed object
		 * @return raw type
		 */
		virtual DataType GetRawDataType() {
			return (UInt16Type);
		}
		/*!
		 * Parse value from string
		 * @param stringToParse string to parse
		 * @return value
		 */
		static UInt16 Parse(String* stringToParse);
		/*!
		 * Try parse value from string
		 * @param stringToParse string to parse
		 * @param result parse value
		 * @return true if good parse
		 */
		static bool TryParse(String* stringToParse, UInt16& result);
		/*!
		 * Max value
		 */
		static UInt16 MaxValue;
		/*!
		 * Min value
		 */
		static UInt16 MinValue;
	};
}
