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
	class DLL_EXPORT SingleValue: public ValueType
	{
		Single value;
	public:
		SingleValue(Single v) {
			value = v;
		}
		/*!
		 * Convert as Int16
		 * @return value as Int16
		 */
		virtual Int16		get_AsInt16();
		/*!
		 * Convert as UInt16
		 * @return value as UInt16
		 */
		virtual UInt16		get_AsUInt16();
		/*!
		 * Convert as Int32
		 * @return value as Int32
		 */
		virtual Int32		get_AsInt32();
		/*!
		 * Convert as UInt32
		 * @return value as UInt32
		 */
		virtual UInt32		get_AsUInt32();
		/*!
		 * Convert as Int64
		 * @return value as Int64
		 */
		virtual Int64		get_AsInt64();
		/*!
		 * Convert as UInt64
		 * @return value as UInt64
		 */
		virtual UInt64		get_AsUInt64();
		/*!
		 * Convert as Single
		 * @return value as Single
		 */
		virtual Single		get_AsSingle();
		/*!
		 * Convert as Double
		 * @return value as Double
		 */
		virtual Double		get_AsDouble();
		/*!
		 * Compare to value -1 < 0 > 1
		 * @param valueToCompare value to compare
		 * @return -1, 0 ,1
		 */
		virtual Int32 CompareTo(Single valueToCompare);
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
		virtual Boolean Equals(Object* valueToCompare);
		/*!
		 * Are values equal
		 * @param valueToCompare value to compare
		 * @return true if equal
		 */
		virtual Boolean Equals(Single valueToCompare);
		/*!
		 * Is value Finite
		 * @param d value to use
		 * @return true if finite
		 */
		static Boolean IsFinite(Single d);
		/*!
		 * Is value infinite
		 * @param d value to use
		 * @return true if infinite
		 */
		static Boolean IsInfinity(Single v);
		/*!
		 * Is value NaN
		 * @param d value to use
		 * @return true if NaN
		 */
		static Boolean IsNaN(Single v);
		/*!
		 * Is value Negative
		 * @param d value to use
		 * @return true if Negative
		 */
		static Boolean IsNegative(Single v);
		/*!
		 * Is value Negative Infinity
		 * @param d value to use
		 * @return true if Negative Infinity
		 */
		static Boolean IsNegativeInfinity(Single v);
		/*!
		 * Is value Normal
		 * @param d value to use
		 * @return true if Normal
		 */
		static Boolean IsNormal(Single v);
		/*!
		 * Is value Positive Infinity
		 * @param d value to use
		 * @return true if Positive Infinity
		 */
		static Boolean IsPositiveInfinity(Single v);
		/*!
		 * Is value Subnormal
		 * @param d value to use
		 * @return true if Subnormal
		 */
		static Boolean IsSubnormal(Single v);
		/*!
		 * Get raw type of this boxed object
		 * @return raw type
		 */
		virtual DataType GetRawDataType() {
			return (SingleType);
		}
		/*!
		 * Format this string
		 * @param where to place characters
		 * @param whereSize size of where
		 * @return amount of characters placed in where
		 */
		virtual Int32 FormatString(Char* where, const Int32 whereSize);
		/*!
		 * Get Modulo of two numbers
		 * @param v1 value 1
		 * @param v2 value 2
		 * @return Modulo of two numbers
		 */
		static Single Modulus(Single v1, Single v2);
		/*!
		 * Parse value from string
		 * @param stringToParse string to parse
		 * @return value
		 */
		static Single Parse(String* stringToParse);
		/*!
		 * Try parse value from string
		 * @param stringToParse string to parse
		 * @param result parse value
		 * @return true if good parse
		 */
		static Boolean TryParse(String* s, Single& result);
		/*!
		 * Try parse value from string
		 * @param stringToParse string to parse
		 * @param result parse value
		 * @return true if good parse
		 */
		static Boolean TryParseInternal(String* source, Single& result);
		/*!
		 * Try parse value from string
		 * @param source of characters
		 * @param sourceLength length of characters
		 * @param result parse value
		 * @return true if good parse
		 */
		static Boolean TryParseInternal(Char* source, Int32 sourceLength, Single& result);
		/*!
		 * Convert to Single
		 * @param  value to convert
		 * @return Single
		 */
		static Single ToSingle(UInt32);
		/*!
		 * Convert to UInt32
		 * @param  value to convert
		 * @return UInt32
		 */
		static UInt32 ToUInt32(Single);
		/*!
		 * Max value
		 */
		static Single MaxValue;
		/*!
		 * Min value
		 */
		static Single MinValue;
		/*!
		 * smallest positive Double value that is greater than zero
		 */
		static Single Epsilon;
		/*!
		 * value that is not a number (NaN)
		 */
		static Single NaN;
		/*!
		 * positive infinity.
		 */
		static Single PositiveInfinity;
		/*!
		 * negative infinity.
		 */
		static Single NegativeInfinity;
	};
	typedef SingleValue FloatValue;
}
