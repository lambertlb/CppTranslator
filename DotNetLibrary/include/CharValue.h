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
	 * Boxing class for Char value
	 * Derived from Object so it can be treated as Object*
	 */
	class DLL_EXPORT CharValue: public ValueType
	{
		Char value;
	public:
		CharValue(Char v) {
			value = v;
		}
		/**
		 * Convert as Char
		 * @return value as Char
		 */
		virtual Char get_AsChar();
		/**
		 * Convert as Byte
		 * @return value as Byte
		 */
		virtual Byte get_AsByte();
		/**
		 * Convert as SByte
		 * @return value as SByte
		 */
		virtual SByte get_AsSByte();
		/**
		 * Convert as Int16
		 * @return value as Int16
		 */
		virtual Int16 get_AsInt16();
		/**
		 * Convert as UInt16
		 * @return value as UInt16
		 */
		virtual UInt16 get_AsUInt16();
		/**
		 * Convert as Int32
		 * @return value as Int32
		 */
		virtual Int32 get_AsInt32();
		/**
		 * Convert as UInt32
		 * @return value as UInt32
		 */
		virtual UInt32 get_AsUInt32();
		/**
		 * Convert as Int64
		 * @return value as Int64
		 */
		virtual Int64 get_AsInt64();
		/**
		 * Convert as UInt64
		 * @return value as UInt64
		 */
		virtual UInt64 get_AsUInt64();
		/**
		 * Convert as Single
		 * @return value as Single
		 */
		virtual Single get_AsSingle();
		/**
		 * Convert as Double
		 * @return value as Double
		 */
		virtual Double get_AsDouble();
		/**
		 * Get raw type of this boxed object
		 * @return raw type
		 */
		virtual DataType GetRawDataType() {
			return (CharType);
		}
		/**
		 * Compare to value -1 < 0 > 1
		 * @param valueToCompare value to compare
		 * @return -1, 0 ,1
		 */
		virtual Int32 CompareTo(Char valueToCompare);
		/**
		 * Compare to Object value -1 < 0 > 1
		 * @param valueToCompare value to compare
		 * @return -1, 0 ,1
		 */
		virtual Int32 CompareTo(Object* valueToCompare);
		/**
		 * Are values equal
		 * @param valueToCompare value to compare
		 * @return true if equal
		 */
		virtual bool Equals(Object* valueToCompare);
		/**
		 * Are values equal
		 * @param valueToCompare value to compare
		 * @return true if equal
		 */
		virtual bool Equals(Char valueToCompare);
		/**
		 * Format this string
		 * @param where to place characters
		 * @param whereSize size of where
		 * @return amount of characters placed in where
		 */
		virtual Int32 FormatString(Char* where, const Int32 whereSize);
		/**
		 * Converts a specified numeric Unicode character to a double-precision floating-point number.
		 * @param v value to convert
		 * @return value to converted to double
		 */
		static Double GetNumericValue(Char v);
		/**
		 * Converts a specified numeric Unicode character to a double-precision floating-point number.
		 * @param v string value to convert
		 * @param index to character
		 * @return value to converted to double
		 */
		static Double GetNumericValue(String* v, Int32 index);
		/**
		 * Indicates whether a specified Unicode character is categorized as a control character.
		 * @param v Character to check
		 * @return true if control
		 */
		static Boolean IsControl(Char v);
		/**
		 * Indicates whether a specified Unicode character is categorized as a control character.
		 * @param v String with Character to check
		 * @param index to character
		 * @return true if control
		 */
		static Boolean IsControl(String* v, Int32 index);
		/**
		 * Indicates whether a specified Unicode character is categorized as a Digit.
		 * @param v Character to check
		 * @return true if digit
		 */
		static Boolean IsDigit(Char v);
		/**
		 * Indicates whether a specified Unicode character is categorized as a Digit.
		 * @param v String with Character to check
		 * @param index to character
		 * @return true if Digit
		 */
		static Boolean IsDigit(String* v, Int32 index);
		/**
		 * Indicates whether a specified Unicode character is categorized as a Letter.
		 * @param v Character to check
		 * @return true if letter
		 */
		static Boolean IsLetter(Char v);
		/**
		 * Indicates whether a specified Unicode character is categorized as a Letter.
		 * @param v String with Character to check
		 * @param index to character
		 * @return true if Letter
		 */
		static Boolean IsLetter(String* v, Int32 index);
		/**
		 * Indicates whether a specified Unicode character is categorized as a Letter or Digit.
		 * @param v Character to check
		 * @return true if letter or Digit
		 */
		static Boolean IsLetterOrDigit(Char v);
		/**
		 * Indicates whether a specified Unicode character is categorized as a Letter or Digit.
		 * @param v String with Character to check
		 * @param index to character
		 * @return true if Letter or Digit
		 */
		static Boolean IsLetterOrDigit(String* v, Int32 index);
		/**
		 * Indicates whether a specified Unicode character is categorized as lower.
		 * @param v Character to check
		 * @return true if lower
		 */
		static Boolean IsLower(Char v);
		/**
		 * Indicates whether a specified Unicode character is categorized as lower.
		 * @param v String with Character to check
		 * @param index to character
		 * @return true if lower
		 */
		static Boolean IsLower(String* v, Int32 index);
		/**
		 * Indicates whether a specified Unicode character is categorized as number.
		 * @param v Character to check
		 * @return true if number
		 */
		static Boolean IsNumber(Char v);
		/**
		 * Indicates whether a specified Unicode character is categorized as number.
		 * @param v String with Character to check
		 * @param index to character
		 * @return true if number
		 */
		static Boolean IsNumber(String* v, Int32 index);
		/**
		 * Indicates whether a specified Unicode character is categorized as Punctuation.
		 * @param v Character to check
		 * @return true if Punctuation
		 */
		static Boolean IsPunctuation(Char v);
		/**
		 * Indicates whether a specified Unicode character is categorized as Punctuation.
		 * @param v String with Character to check
		 * @param index to character
		 * @return true if Punctuation
		 */
		static Boolean IsPunctuation(String* v, Int32 index);
		/**
		 * Indicates whether a specified Unicode character is categorized as Separator.
		 * @param v Character to check
		 * @return true if Separator
		 */
		static Boolean IsSeparator(Char v);
		/**
		 * Indicates whether a specified Unicode character is categorized as Separator.
		 * @param v String with Character to check
		 * @param index to character
		 * @return true if Separator
		 */
		static Boolean IsSeparator(String* v, Int32 index);
		/**
		 * Indicates whether a specified Unicode character is categorized as upper.
		 * @param v Character to check
		 * @return true if upper
		 */
		static Boolean IsUpper(Char v);
		/**
		 * Indicates whether a specified Unicode character is categorized as upper.
		 * @param v String with Character to check
		 * @param index to character
		 * @return true if upper
		 */
		static Boolean IsUpper(String* v, Int32 index);
		/**
		 * Indicates whether a specified Unicode character is categorized as WhiteSpace.
		 * @param v Character to check
		 * @return true if WhiteSpace
		 */
		static Boolean IsWhiteSpace(Char v);
		/**
		 * Indicates whether a specified Unicode character is categorized as WhiteSpace.
		 * @param v String with Character to check
		 * @param index to character
		 * @return true if WhiteSpace
		 */
		static Boolean IsWhiteSpace(String* v, Int32 index);
		/**
		 * Parse value from string
		 * @param stringToParse string to parse
		 * @return value
		 */
		static Char Parse(String* stringToParse);
		/**
		 * Converts the value of a Unicode character to its lower case equivalent.
		 * @param v Char to convert
		 * @return converted to lower
		 */
		static Char ToLower(Char v);
		/**
		 * Converts the value of a Unicode character to its upper case equivalent.
		 * @param v Char to convert
		 * @return converted to upper
		 */
		static Char ToUpper(Char v);
		/**
		 * Try parse value from string
		 * @param stringToParse string to parse
		 * @param result parse value
		 * @return true if good parse
		 */
		static Boolean TryParse(String* s, Char& result);
		/**
		 * Convert to String
		 * @return value converted to string
		 */
		String* ToString();
		/**
		 * Convert to String
		 * @param value to convert
		 * @return value converted to string
		 */
		static String* ToString(Char v);
		/**
		 * Max value
		 */
		static Char MaxValue;
		/**
		 * Min value
		 */
		static Char MinValue;
	};
}
