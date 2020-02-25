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
#define DefaultCapacity 128 // default internal buffer size
#define MaximumCapacity Int32Value::MaxValue// Maximum string builder capacity

	/*!
	 * Emulate .Net StringBuilder class.
	 * This will try to use internal memory unless absolutely necessary.
	 * This is to reduce memory allocations
	 */
	class DLL_EXPORT StringBuilder: public Object
	{
	private:
		Char internalMemory[DefaultCapacity + 1]; // default memory to prevent allocations
		Char* chunkChars;		// array of characters
		Int32 currentCapacity;	// total size of the array
		Int32 currentLength;	// current offset into array for next insert
		Int32 maxCapacity;		// max capacity for this builder
	public:
		StringBuilder();
		StringBuilder(Int32 capacity);
		StringBuilder(Int32 capacity, Int32 maxCapacity);
		StringBuilder(String* value, Int32 capacity = DefaultCapacity);
		StringBuilder(String* value, Int32 startIndex, Int32 length, Int32 capacity);
		virtual ~StringBuilder();
		/*!
		 * Get current memory buffer
		 * @return  current memory buffer
		 */
		Char* get_Buffer() {
			return (chunkChars);
		}
		/*!
		 * Compute the address of a data item in the array.
		 * This is used in place of .net indexer
		 * @param index1 into 1st dimension
		 * @param index2 into 2nd dimension or -1
		 * @param index3 into 3rd dimension or -1
		 * @return pointer to character at index
		 */
		Char* Address(Int32 index1, Int32 index2 = -1, Int32 index3 = -1);
		/*!
		 * Get buffer capacity
		 * @return capacity
		 */
		Int32 get_Capacity();
		/*!
		 * Get character at index
		 * @param index to character
		 * @return character at index
		 */
		Char get_Chars(Int32 index);
		/*!
		 * Get current amount of characters in buffer
		 * @return current amount of characters in buffer
		 */
		Int32 get_Length();
		/*!
		 * Get Max Capacity
		 * @return Max Capacity
		 */
		Int32 get_MaxCapacity();
		/*!
		 * set character at index
		 * @param index to character
		 * @param newChar to set
		 */
		void set_Chars(Int32 index, Char newChar);
		/*!
		 * Set capacity
		 * @param capacity to set
		 */
		void set_Capacity(Int32 capacity);
		/*!
		 * Set new length on buffer
		 * @param newLength to set
		 */
		void set_Length(Int32 newLength);
		/*!
		 * Append these characters into buffer
		 * @param values array of characters
		 * @param charCount how many
		 * @param where at what index
		 * @return StringBuilder
		 */
		StringBuilder* Append(const Char* values, Int32 charCount, Int32 where = -1);
		/*!
		 * Append these characters into buffer
		 * @param values array with characters
		 * @param startIndex starting index in array
		 * @param charCount amount of characters
		 * @return StringBuilder
		 */
		StringBuilder* Append(Array* values, Int32 startIndex = -1, Int32 charCount = -1);
		/*!
		 * Append value type
		 * @param value value to append
		 * @param index character index
		 * @return StringBuilder
		 */
		StringBuilder* Append(ValueType& value, Int32 index = -1);
		/*!
		 * Append Boolean
		 * @param value value to append
		 * @return StringBuilder
		 */
		StringBuilder* Append(Boolean value);
		/*!
		 * Append Byte
		 * @param value value to append
		 * @return StringBuilder
		 */
		StringBuilder* Append(Byte value);
		/*!
		 * Append Char
		 * @param value value to append
		 * @return StringBuilder
		 */
		StringBuilder* Append(Char value);
		/*!
		 * Append a repeated character
		 * @param value to append
		 * @param repeatCount repeat count
		 * @return StringBuilder
		 */
		StringBuilder* Append(Char value, Int32 repeatCount);
		/*!
		 * Append Double
		 * @param value value to append
		 * @return StringBuilder
		 */
		StringBuilder* Append(Double value);
		/*!
		 * Append Int16
		 * @param value value to append
		 * @return StringBuilder
		 */
		StringBuilder* Append(Int16 value);
		/*!
		 * Append Int32
		 * @param value value to append
		 * @return StringBuilder
		 */
		StringBuilder* Append(Int32 value);
		/*!
		 * Append Int64
		 * @param value value to append
		 * @return StringBuilder
		 */
		StringBuilder* Append(Int64 value);
		/*!
		 * Append Object
		 * @param value value to append
		 * @return StringBuilder
		 */
		StringBuilder* Append(Object* value);
		/*!
		 * Append SByte
		 * @param value value to append
		 * @return StringBuilder
		 */
		StringBuilder* Append(SByte value);
		/*!
		 * Append Single
		 * @param value value to append
		 * @return StringBuilder
		 */
		StringBuilder* Append(Single value);
		/*!
		 * Append string
		 * @param value to append
		 * @param startIndex start index
		 * @param charCount character count
		 * @return StringBuilder
		 */
		StringBuilder* Append(String* value, Int32 startIndex = 0, Int32 charCount = -1);
		/*!
		 * Append UInt16
		 * @param value value to append
		 * @return StringBuilder
		 */
		StringBuilder* Append(UInt16 value);
		/*!
		 * Append UInt32
		 * @param value value to append
		 * @return StringBuilder
		 */
		StringBuilder* Append(UInt32 value);
		/*!
		 * Append UInt64
		 * @param value value to append
		 * @return StringBuilder
		 */
		StringBuilder* Append(UInt64 value);
		/*!
		 * Append new line
		 * @return StringBuilder
		 */
		StringBuilder* AppendLine();
		/*!
		 * Append string with new line
		 * @param value to append
		 * @return StringBuilder
		 */
		StringBuilder* AppendLine(String* value);
		/*!
		 * Clear out buffer
		 * @return StringBuilder
		 */
		StringBuilder* Clear();
		/*!
		 * Count sub strings
		 * @param subString to look for
		 * @param startIndex starting index
		 * @param length how far
		 * @return count found
		 */
		Int32 CountSubStrings(String* subString, Int32 startIndex, Int32 length);
		/*!
		 * Ensure enough room for this amount.
		 * Grow buffer if not
		 * @param amount needed
		 */
		void EnsureRoomFor(Int32 amount);
		/*!
		 * Ensure we have this capacity
		 * @param capacity needed
		 * @return current capacity
		 */
		Int32 EnsureCapacity(Int32 capacity);
		/*!
		 * Are these equal
		 * @param object string build to compare
		 * @return True if contents are equal
		 */
		virtual Boolean Equals(StringBuilder* object);
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
			return (ObjectType);
		}
		/*!
		 * Initialize string builder
		 */
		void Initialize();
		/*!
		 * Insert value into builder at index
		 * @param index where to insert
		 * @param value to insert
		 * @return StringBuilder
		 */
		StringBuilder* Insert(const Int32 index, const Boolean value);
		/*!
		 * Insert value into builder at index
		 * @param index where to insert
		 * @param value to insert
		 * @return StringBuilder
		 */
		StringBuilder* Insert(const Int32 index, const Byte value);
		/*!
		 * Insert value into builder at index
		 * @param index where to insert
		 * @param value to insert
		 * @return StringBuilder
		 */
		StringBuilder* Insert(const Int32 index, const Char value);
		/*!
		 * Insert array
		 * @param index where to insert
		 * @param value array to insert
		 * @param startIndex starting index in array
		 * @param charCount how much to insert
		 * @return StringBuilder
		 */
		StringBuilder* Insert(const Int32 index, Array* value, Int32 startIndex = -1, Int32 charCount = -1);
		/*!
		 * Insert value into builder at index
		 * @param index where to insert
		 * @param value to insert
		 * @return StringBuilder
		 */
		StringBuilder* Insert(const Int32 index, Double value);
		/*!
		 * Insert value into builder at index
		 * @param index where to insert
		 * @param value to insert
		 * @return StringBuilder
		 */
		StringBuilder* Insert(const Int32 index, const Int16 value);
		/*!
		 * Insert value into builder at index
		 * @param index where to insert
		 * @param value to insert
		 * @return StringBuilder
		 */
		StringBuilder* Insert(const Int32 index, Int32 value);
		/*!
		 * Insert value into builder at index
		 * @param index where to insert
		 * @param value to insert
		 * @return StringBuilder
		 */
		StringBuilder* Insert(const Int32 index, Int64 value);
		/*!
		 * Insert value into builder at index
		 * @param index where to insert
		 * @param value to insert
		 * @return StringBuilder
		 */
		StringBuilder* Insert(const Int32 index, Object* value);
		/*!
		 * Insert string multiple times
		 * @param index where to insert
		 * @param value string to insert
		 * @param count how many times
		 * @return StringBuilder
		 */
		StringBuilder* Insert(const Int32 index, String* value, Int32 count = 1);
		/*!
		 * Insert value into builder at index
		 * @param index where to insert
		 * @param value to insert
		 * @return StringBuilder
		 */
		StringBuilder* Insert(const Int32 index, const SByte value);
		/*!
		 * Insert value into builder at index
		 * @param index where to insert
		 * @param value to insert
		 * @return StringBuilder
		 */
		StringBuilder* Insert(const Int32 index, const Single value);
		/*!
		 * Insert value into builder at index
		 * @param index where to insert
		 * @param value to insert
		 * @return StringBuilder
		 */
		StringBuilder* Insert(const Int32 index, const UInt16 value);
		/*!
		 * Insert value into builder at index
		 * @param index where to insert
		 * @param value to insert
		 * @return StringBuilder
		 */
		StringBuilder* Insert(const Int32 index, UInt32 value);
		/*!
		 * Insert value into builder at index
		 * @param index where to insert
		 * @param value to insert
		 * @return StringBuilder
		 */
		StringBuilder* Insert(const Int32 index, const UInt64 value);
		/*!
		 * Are we using internal buffer
		 * @return true if we are
		 */
		Boolean IsInternal() {
			return (chunkChars == internalMemory);
		}
		/*!
		 * Remove characters from buffer
		 * @param startIndex starting index
		 * @param length how many
		 * @return StringBuilder
		 */
		StringBuilder* Remove(Int32 startIndex, Int32 length);
		/*!
		 * Replace characters in builder
		 * @param oldChar search character
		 * @param newChar replace character
		 * @return StringBuilder
		 */
		StringBuilder* Replace(const Char oldChar, const Char newChar);
		/*!
		 * Replace string in builder
		 * @param search string
		 * @param replace string
		 * @return StringBuilder
		 */
		StringBuilder* Replace(String* search, String* replace);
		/*!
		 * Replace characters in builder
		 * @param oldChar search character
		 * @param newChar replace character
		 * @param startIndex starting index
		 * @param count amount to search
		 * @return StringBuilder
		 */
		StringBuilder* Replace(const Char oldChar, const Char newChar, const Int32 startIndex, const Int32 count);
		/*!
		 * Replace strings in builder
		 * @param oldChar search string
		 * @param newChar replace string
		 * @param startIndex starting index
		 * @param count amount to search
		 * @return StringBuilder
		 */
		StringBuilder* Replace(String* search, String* replace, const Int32 startIndex, const Int32 count);
		/*!
		 * Replace strings in builder
		 * @param oldChar search string
		 * @param newChar replace string
		 * @param startIndex starting index
		 * @param count amount to search
		 * @return StringBuilder
		 */
		void ReplaceSubString(String* search, String* replace, const Int32 startIndex, const Int32 count);
		/*!
		 * Convert to string
		 * @return string
		 */
		virtual String* ToString();
		/*!
		 * Convert to string
		 * @param startIndex starting character
		 * @param length amount of characters
		 * @return string
		 */
		virtual String* ToString(Int32 startIndex, Int32 length);
	};
}
