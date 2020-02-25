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
#include <string.h>

namespace DotnetLibrary
{
	class CharEnumerator;

	/*!
	 * Emulate .Net string.
	 * To Conserve memory this will use a supplied string constant
	 * before allocating any new memory
	 */
	class DLL_EXPORT String: public Object
	{
		Char* characterData;
		Int32 length;
		Boolean allocate;
	public:
		String(const Char* string);
		String(const Char* string, Int32 startIndex, Int32 length = -1);
		String(Array* chrs, Int32 startIndex = 0, Int32 length = -1);
		String(const Char chr, const Int32 amount);
		virtual ~String();
		/*!
		 * Get pointer to characters
		 * @return pointer to characters
		 */
		Char* get_Buffer() {
			return (characterData);
		}
		/*!
		 * Get character at index
		 * @param index to character
		 * @return character at index
		 */
		Char get_Chars(const Int32 index);
		/*!
		 * Length of string
		 * @return length of string
		 */
		Int32 get_Length() {
			return ((Int32) length);
		}
		/*!
		 * Compute the address of a character in string.
		 * This is used in place of .net indexer
		 * @param index1 into string
		 * @param index2 into 2nd dimension or -1
		 * @param index3 into 3rd dimension or -1
		 */
		Char* Address(Int32 index1, Int32 index2 = -1, Int32 index3 = -1);
		/*!
		 * Compare two strings
		 * @param s1 array of characters
		 * @param s1Index index in array
		 * @param s2 array 2 of characters
		 * @param s2Index index in array 2
		 * @param length amount to compare
		 * @param ignoreCase true if ignore case
		 * @param doOrdinal do ordinal compare
		 * @return -1 < 0 > 1
		 */
		static Int32 Compare(Char* s1, Int32 s1Index, Char* s2, Int32 s2Index, Int32 length, Boolean ignoreCase,
		                     Boolean doOrdinal);
		/*!
		 * Compare two strings
		 * @param s1 string 1
		 * @param s2 string 2
		 * @param ignoreCase true if ignore case
		 * @return -1 < 0 > 1
		 */
		static Int32 Compare(String* s1, String* s2, Boolean ignoreCase = false);
		/*!
		 * Compare two strings
		 * @param s1 array of characters
		 * @param s1Index index in array
		 * @param s2 array 2 of characters
		 * @param s2Index index in array 2
		 * @param length amount to compare
		 * @param ignoreCase true if ignore case
		 * @param doOrdinal do ordinal compare
		 * @return -1 < 0 > 1
		 */
		static Int32 Compare(String* s1, const Int32 index1, String* s2, const Int32 index2, const Int32 length,
		                     Boolean ignoreCase = false);
		/*!
		 * Compare two strings
		 * @param s1 string 1
		 * @param s2 string 2
		 * @return -1 < 0 > 1
		 */
		static Int32 CompareOrdinal(String* s1, String* s2);
		/*!
		 * Compare two strings
		 * @param s1 array of characters
		 * @param s1Index index in array
		 * @param s2 array 2 of characters
		 * @param s2Index index in array 2
		 * @param length amount to compare
		 * @return -1 < 0 > 1
		 */
		static Int32 CompareOrdinal(String* s1, const Int32 index1, String* s2, const Int32 index2, const Int32 length);
		/*!
		 * Compare to value
		 * @param value to compare
		 * @return -1 < 0 > 1
		 */
		Int32 CompareTo(Object* value);
		/*!
		 * Compare to value
		 * @param value to compare
		 * @return -1 < 0 > 1
		 */
		Int32 CompareTo(String* str);
		/*!
		 * Concatenate array of object values
		 * @param values array of values
		 * @return concatenated string
		 */
		static String* Concat(Array* values);
		/*!
		 * Concatenate strings
		 * @param o1 Object 1
		 * @param o2 Object 2
		 * @param o3 Object 3
		 * @param o4 Object 4
		 * @param o5 Object 5
		 * @param o6 Object 6
		 * @param o7 Object 7
		 * @return concatenated string
		 */
		static String* Concat(Object* o1, Object* o2 = nullptr, Object* o3 = nullptr, Object* o4 = nullptr,
		                      Object* o5 = nullptr, Object* o6 = nullptr, Object* o7 = nullptr);
		/*!
		 * Does string contain substring
		 * @param substring to find
		 * @return true if found
		 */
		Boolean Contains(String* substring);
		/*!
		 * Copy string
		 * @param str to copy
		 * @return copy of string
		 */
		static String* Copy(String* str);
		/*!
		 * Copy characters to array
		 * @param sourceIndex starting character
		 * @param destination destination array
		 * @param destinationIndex index into array
		 * @param count how many characters to copy
		 */
		void CopyTo(Int32 sourceIndex, Array* destination, Int32 destinationIndex, Int32 count);
		/*!
		 * Does string end with
		 * @param what to look for
		 * @return true if found
		 */
		virtual Boolean EndsWith(String* what);
		/*!
		 * Does string end with
		 * @param what to look for
		 * @return true if found
		 */
		virtual Boolean EndsWith(Char what);
		/*!
		 * Are values equal
		 * @param valueToCompare value to compare
		 * @return true if equal
		 */
		virtual Boolean Equals(Object* object);
		/*!
		 * Are values equal
		 * @param valueToCompare value to compare
		 * @return true if equal
		 */
		virtual Boolean Equals(String* object);
		/*!
		 * Are two string equal
		 * @param object string 1
		 * @param object2 string 2
		 * @return true if equal
		 */
		static Boolean Equals(String* object, Object* object2);
		/*!
		 * Are two string equal
		 * @param object string 1
		 * @param object2 string 1
		 * @return true if equal
		 */
		static Boolean Equals(Object* object, String* object2);
		/*!
		 * Are two string equal
		 * @param object string 1
		 * @param object2 string 1
		 * @return true if equal
		 */
		static Boolean Equals(String* object, String* object2);
		/*!
		 * Format this string
		 * @param where to place characters
		 * @param whereSize size of where
		 * @return amount of characters placed in where
		 */
		virtual Int32 FormatString(Char* where, const Int32 whereSize);
		/*!
		 * get character enumerator
		 * @return character enumerator
		 */
		CharEnumerator* GetEnumerator();
		/*!
		 * Get raw type of this boxed object
		 * @return raw type
		 */
		virtual DataType GetRawDataType() {
			return (StringType);
		}
		/*!
		 * Compute index of value
		 * @param value to find
		 * @return index of starting character or -1
		 */
		Int32 IndexOf(const Char value);
		/*!
		 * Compute index of value
		 * @param value to find
		 * @return index of starting character or -1
		 */
		Int32 IndexOf(String* value);
		/*!
		 * Compute index of value
		 * @param value to find
		 * @param startIndex where to look
		 * @return index of starting character or -1
		 */
		Int32 IndexOf(const Char value, const Int32 startIndex);
		/*!
		 * Compute index of value
		 * @param value to find
		 * @param startIndex where to look
		 * @return index of starting character or -1
		 */
		Int32 IndexOf(String* value, const Int32 startIndex);
		/*!
		 * Compute index of value
		 * @param value to find
		 * @param startIndex where to look
		 * @param count how many character to look through
		 * @return index of starting character or -1
		 */
		Int32 IndexOf(const Char value, const Int32 startIndex, const Int32 count);
		/*!
		 * Compute index of value
		 * @param value to find
		 * @param startIndex where to look
		 * @param count how many character to look through
		 * @return index of starting character or -1
		 */
		Int32 IndexOf(String* value, const Int32 startIndex, const Int32 count);
		/*!
		 * Index of any character in this array
		 * @param arr array with characters
		 * @return index of starting character or -1
		 */
		Int32 IndexOfAny(Array* arr);
		/*!
		 * Index of any character in this array
		 * @param arr array with characters
		 * @param startIndex where to look
		 * @return index of starting character or -1
		 */
		Int32 IndexOfAny(Array* arr, const Int32 startIndex);
		/*!
		 * Index of any character in this array
		 * @param arr array with characters
		 * @param startIndex where to look
		 * @param count how many character to look through
		 * @return index of starting character or -1
		 */
		Int32 IndexOfAny(Array* arr, const Int32 startIndex, const Int32 count);
		/*!
		 * Create string by inserting a string at index
		 * @param startIndex where to insert
		 * @param value to insert
		 * @return string
		 */
		String* Insert(const Int32 startIndex, String* value);
		/*!
		 * Was this an allocated string
		 * @return true if allocated
		 */
		Boolean IsAllocated() {
			return (allocate);
		}
		/*!
		 * Is string null or empty
		 * @param value to test
		 * @return true if null or empty
		 */
		static Boolean IsNullOrEmpty(String* value);
		/*!
		 * Is string null or whitespace
		 * @param value to test
		 * @return true if null or whitespace
		 */
		static Boolean IsNullOrWhiteSpace(String* value);
		/*!
		 * Is character in this array of separators
		 * @param value to find
		 * @param separators array to search
		 * @param separatorSize amount of separators
		 * @return true if found
		 */
		static Boolean IsWhiteSpace(Char value, Char* separators, Int32 separatorSize);
		/*!
		 * Join values in array with separators
		 * @param separator to use
		 * @param values to join
		 * @param startIndex starting index in array
		 * @param count amount to join
		 * @return string
		 */
		static String* Join(Char separator, Array* values, const Int32 startIndex = 0, Int32 count = -1);
		/*!
		 * Join values in array with separators
		 * @param separator to use
		 * @param values to join
		 * @param startIndex starting index in array
		 * @param count amount to join
		 * @return string
		 */
		static String* Join(String* separator, Array* values, const Int32 startIndex = 0, Int32 count = -1);
		/*!
		 * Compute index of last value
		 * @param value to find
		 * @param startIndex where to look
		 * @param count how many character to look through
		 * @return index of starting character of last value or -1
		 */
		Int32 LastIndexOf(const Char value, Int32 startIndex = -1, Int32 count = -1);
		/*!
		 * Compute index of last value
		 * @param value to find
		 * @param startIndex where to look
		 * @param count how many character to look through
		 * @return index of starting character of last value or -1
		 */
		Int32 LastIndexOf(String* value, Int32 startIndex = -1, Int32 count = -1);
		/*!
		 * Compute index of any value
		 * @param arr of values to find
		 * @param startIndex where to look
		 * @param count how many character to look through
		 * @return index of starting character of last value or -1
		 */
		Int32 LastIndexOfAny(Array* arr, Int32 startIndex = -1, Int32 count = -1);
		/*!
		 * Pad left with this amount of characters
		 * @param width how many
		 * @param chr to pad
		 * @return String
		 */
		String* PadLeft(const Int32 width, const Char chr = L' ');
		/*!
		 * Pad Right with this amount of characters
		 * @param width how many
		 * @param chr to pad
		 * @return String
		 */
		String* PadRight(const Int32 width, const Char chr = L' ');
		/*!
		 * Remove characters
		 * @param startIndex starting index
		 * @param count how many
		 * @return String
		 */
		String* Remove(const Int32 startIndex, Int32 count = -1);
		/*!
		 * Replace characters
		 * @param oldChar to look for
		 * @param newChar to replace with
		 * @return String
		 */
		String* Replace(const Char oldChar, const Char newChar);
		/*!
		 * Replace characters
		 * @param oldValue to look for
		 * @param newValue to replace with
		 * @return String
		 */
		String* Replace(String* oldValue, String* newValue);
		/*!
		 * Starts with string
		 * @param what to look for
		 * @return true if found
		 */
		virtual Boolean StartsWith(String* what);
		/*!
		 * Extract sub-string
		 * @param startIndex starting index
		 * @param length to extract
		 * @return String
		 */
		String* Substring(const Int32 startIndex, Int32 length = -1);
		/*!
		 * Convert to character array
		 * @param startIndex index to first character
		 * @param length amount of character
		 * @return Array of characters
		 */
		Array* ToCharArray(Int32 startIndex = 0, Int32 length = -1);
		/*!
		 * Convert to lower case
		 * @return String
		 */
		String* ToLower();
		/*!
		 * Convert to lower case
		 * @return String
		 */
		String* ToLowerInvariant();
		/*!
		 * Convert to string
		 * @return String
		 */
		virtual String* ToString();
		/*!
		 * Convert to upper case
		 * @return String
		 */
		String* ToUpper();
		/*!
		 * Convert to upper case
		 * @return String
		 */
		String* ToUpperInvariant();
		/*!
		 * Trim off whitespace
		 * @return String
		 */
		String* Trim();
		/*!
		 * Trim using these characters
		 * @param separator to trim
		 * @return String
		 */
		String* Trim(Array* separator);
		/*!
		 * Trim string
		 * @param separator characters to trim
		 * @param trimStart starting character
		 * @param trimEnd ending character
		 * @return String
		 */
		String* TrimHelper(Array* separator, Boolean trimStart, Boolean trimEnd);
		/*!
		 * Trim String
		 * @param separator characters to trim
		 * @param separaterSize amount of separators
		 * @param trimStart starting character
		 * @param trimEnd ending character
		 * @return String
		 */
		String* TrimHelper(Char* separator, Int32 separaterSize, Boolean trimStart, Boolean trimEnd);
		/*!
		 * Trim end of string
		 * @param separator what to trim
		 * @return String
		 */
		String* TrimEnd(Array* separator);
		/*!
		 * Trim start of string
		 * @param separator what to trim
		 * @return String
		 */
		String* TrimStart(Array* separator);
		/*!
		 * Are two string equal
		 * @param str string 1
		 * @param str2 String 2
		 * @return true if equal
		 */
		static Boolean op_Inequality(String* str, String* str2);
		/*!
		 * Empty String
		 */
		static String* Empty;
	};
	/*!
	 * Copy characters
	 * @param where to copy
	 * @param whereSize size of destination
	 * @param source of characters
	 * @param sourceSize size of source
	 */
	void CopyChars(Char* where, Int32 whereSize, Char* source, Int32 sourceSize);
}
