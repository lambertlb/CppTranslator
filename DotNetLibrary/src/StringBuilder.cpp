#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	StringBuilder::StringBuilder() : StringBuilder(DefaultCapacity, MaximumCapacity)
	{
	}
	StringBuilder::StringBuilder(Int32 capacity) : StringBuilder(capacity, MaximumCapacity)
	{
	}
	StringBuilder::StringBuilder(Int32 capacity, Int32 maxCapacity)
	{
		Initialize();

		if (capacity > maxCapacity) {
			throw new ArgumentOutOfRangeException();
		}
		if (maxCapacity < 1) {
			throw new ArgumentOutOfRangeException();
		}
		if (capacity < 0) {
			throw new ArgumentOutOfRangeException();
		}
		if (capacity == 0) {
			capacity = Math::Min(DefaultCapacity, maxCapacity);
		}
		//Int32	partial = maxCapacity % DefaultCapacity;
		//maxCapacity = (maxCapacity / DefaultCapacity) * DefaultCapacity;
		//if (partial > 0)
		//	maxCapacity += DefaultCapacity;
		this->maxCapacity = maxCapacity;
		set_Capacity(capacity);
	}
	StringBuilder::StringBuilder(String* value, Int32 capacity) : StringBuilder(value, 0, value->get_Length(), capacity)
	{
	}
	StringBuilder::StringBuilder(String* value, Int32 startIndex, Int32 length, Int32 capacity)
	{
		Initialize();
		if (value == nullptr) {
			value = String::Empty;
		}
		if (capacity < 0) {
			throw new ArgumentOutOfRangeException();
		}
		if (length < 0) {
			throw new ArgumentOutOfRangeException();
		}
		if (startIndex < 0) {
			throw new ArgumentOutOfRangeException();
		}
		if (startIndex > value->get_Length() - length) {
			throw new ArgumentOutOfRangeException();
		}
		if (capacity == 0) {
			capacity = DefaultCapacity;
		}
		set_Capacity(Math::Max(capacity, length));
		Char* sourcePtr = value->Address(startIndex);
		memcpy(chunkChars, sourcePtr, length * sizeof(Char));
		currentLength = length;
	}
	StringBuilder::~StringBuilder()
	{
		if (chunkChars != nullptr && chunkChars != internalMemory)
			delete chunkChars;
		chunkChars = internalMemory;
	}
	void StringBuilder::Initialize()
	{
		maxCapacity = MaximumCapacity;
		chunkChars = internalMemory;
		currentLength = 0;
		currentCapacity = DefaultCapacity;
		memset(internalMemory, 0, sizeof(internalMemory));
	}
	Int32 StringBuilder::get_Length()
	{
		return currentLength;
	}
	void StringBuilder::set_Length(Int32 newLength)
	{
		if (newLength < 0) {
			throw new ArgumentOutOfRangeException();
		}
		if (newLength > maxCapacity) {
			throw new ArgumentOutOfRangeException();
		}
		if (newLength == 0) {
			currentLength = 0;
			memset(chunkChars, 0, currentCapacity * sizeof(Char));
			return;
		}
		EnsureCapacity(newLength);
		int delta = newLength - currentLength;
		if (delta == 0) {
			return;
		}
		if (delta < 0) {
			memset(chunkChars + (currentLength + delta), 0, -delta * sizeof(Char));
		}
		currentLength = newLength;
	}
	Int32 StringBuilder::get_Capacity()
	{
		return currentCapacity;
	}
	void StringBuilder::set_Capacity(Int32 capacity)
	{
		if (capacity < 0) {
			throw new ArgumentOutOfRangeException();
		}
		if (capacity > maxCapacity) {
			throw new ArgumentOutOfRangeException();
		}
		if (chunkChars != internalMemory && capacity < currentCapacity) {
			throw new ArgumentOutOfRangeException();
		}
		if (currentCapacity >= capacity) {
			currentCapacity = capacity;
			return;
		}
		Char* newArray = internalMemory;
		if (capacity > DefaultCapacity) {
			Int32	partial = capacity % DefaultCapacity;
			capacity = (capacity / DefaultCapacity) * DefaultCapacity;
			if (partial > 0)
				capacity += DefaultCapacity;
			newArray = new Char[capacity + 1];
			memcpy(newArray, chunkChars, currentLength * sizeof(Char));
			if (chunkChars != internalMemory)
				delete chunkChars;
		}
		currentCapacity = capacity;
		chunkChars = newArray;
	}
	Int32 StringBuilder::get_MaxCapacity()
	{
		return maxCapacity;
	}
	Char* StringBuilder::Address(Int32 index1, Int32 index2, Int32 index3)
	{
		if (index1 < 0 || index1 >= currentLength)
			throw new IndexOutOfRangeException();
		return(&chunkChars[index1]);
	}
	Int32 StringBuilder::CountSubStrings(String* subString, Int32 startIndex, Int32 length)
	{
		Int32	amount = 0;
		Int32	endIndex = startIndex + 1 + length - subString->get_Length();
		Int32	bytesToCompare = subString->get_Length() * sizeof(Char);
		for (int i = startIndex; i < endIndex;)
		{
			if (0 == memcmp(chunkChars + i, subString->get_Buffer(), bytesToCompare))
			{
				++amount;
				i += subString->get_Length();
			}
			else
				++i;
		}
		return(amount);
	}
	Char StringBuilder::get_Chars(Int32 index)
	{
		return(*Address(index));
	}
	void StringBuilder::set_Chars(Int32 index, Char newChar)
	{
		*Address(index) = newChar;
	}
	String* StringBuilder::ToString()
	{
		return(new String(chunkChars, 0, currentLength));
	}
	String* StringBuilder::ToString(Int32 startIndex, Int32 length)
	{
		if (startIndex < 0 || startIndex >= currentLength)
			throw new IndexOutOfRangeException();
		if (startIndex + length > currentLength)
			throw new IndexOutOfRangeException();
		return(new String(&chunkChars[startIndex], 0, length));
	}
	Int32 StringBuilder::FormatString(Char* where, const Int32 whereSize)
	{
		if (whereSize < currentLength)
			throw new IndexOutOfRangeException();
		wcscpy_s(where, whereSize, chunkChars);
		return currentLength;
	}
	StringBuilder* StringBuilder::Append(const Char* values, Int32 charCount, Int32 where)
	{
		if (where == -1) {
			where = currentLength;
		}
		if (where > currentLength) {
			throw new IndexOutOfRangeException();
		}
		EnsureRoomFor(charCount);
		if (where != currentLength) {
			memmove(&chunkChars[where + charCount], &chunkChars[where], (currentLength - where) * sizeof(Char));
		}
		memcpy(&chunkChars[where], values, charCount * sizeof(Char));
		currentLength += charCount;
		chunkChars[currentLength] = 0;
		return(this);
	}
	StringBuilder* StringBuilder::Append(Array* values, Int32 startIndex, Int32 charCount)
	{
		if (values == nullptr) {
			return(this);
		}
		if (startIndex < 0) {
			startIndex = 0;
		}
		if (charCount < 0) {
			charCount = values->get_Length();
		}
		if (charCount == 0) {
			return(this);
		}
		if (charCount > values->get_Length() - startIndex)
		{
			throw new ArgumentOutOfRangeException();
		}
		if (values->GetElementType() != CharType) {
			throw new ArgumentOutOfRangeException();
		}
		values->EnsureSingleDimension();
		return(Append((Char*)values->Address(startIndex), charCount, currentLength));
	}
	StringBuilder* StringBuilder::Append(ValueType& value, Int32 index)
	{
		Char	str[128];
		Int32 size = value.FormatString(str, 128);
		return(Append(str, size, index));
	}
	StringBuilder* StringBuilder::Append(Boolean value)
	{
		BooleanValue data(value);
		return(Append(data));
	}
	StringBuilder* StringBuilder::Append(Byte value)
	{
		ByteValue data(value);
		return(Append(data));
	}
	StringBuilder* StringBuilder::Append(Double value)
	{
		DoubleValue data(value);
		return(Append(data));
	}
	StringBuilder* StringBuilder::Append(Int16 value)
	{
		Int16Value data(value);
		return(Append(data));
	}
	StringBuilder* StringBuilder::Append(Int32 value)
	{
		Int32Value data(value);
		return(Append(data));
	}
	StringBuilder* StringBuilder::Append(Int64 value)
	{
		Int64Value data(value);
		return(Append(data));
	}
	StringBuilder* StringBuilder::Append(Object* value)
	{
		return(Append(value->ToString()));
	}
	StringBuilder* StringBuilder::Append(Char value)
	{
		return(Append(value, 1));
	}
	StringBuilder* StringBuilder::Append(Char value, Int32 repeatCount)
	{
		if (repeatCount < 0) {
			throw new ArgumentOutOfRangeException();
		}
		EnsureCapacity(repeatCount);
		for (int i = 0; i < repeatCount; ++i) {
			chunkChars[currentLength++] = value;
		}
		chunkChars[currentLength] = 0;
		return(this);
	}
	StringBuilder* StringBuilder::Append(String* value, Int32 startIndex, Int32 charCount)
	{
		if (charCount < 0)
			charCount = value->get_Length();
		if (startIndex < 0) {
			throw new ArgumentOutOfRangeException();
		}
		if (startIndex > value->get_Length() - charCount) {
			throw new ArgumentOutOfRangeException();
		}
		return(Append(&(value->get_Buffer()[startIndex]), charCount));
	}
	StringBuilder* StringBuilder::Append(SByte value)
	{
		SByteValue data(value);
		return(Append(data));
	}
	StringBuilder* StringBuilder::Append(Single value)
	{
		SingleValue data(value);
		return(Append(data));
	}
	StringBuilder* StringBuilder::Append(UInt16 value)
	{
		UInt16Value data(value);
		return(Append(data));
	}
	StringBuilder* StringBuilder::Append(UInt32 value)
	{
		UInt32Value data(value);
		return(Append(data));
	}
	StringBuilder* StringBuilder::Append(UInt64 value)
	{
		UInt64Value data(value);
		return(Append(data));
	}
	StringBuilder* StringBuilder::AppendFormat(String* format, Object* arg0)
	{
		throw new NotImplementedException();
	}
	StringBuilder* StringBuilder::AppendFormat(String* format, Array* args)
	{
		throw new NotImplementedException();
	}
	StringBuilder* StringBuilder::AppendFormat(String* format, Object* arg0, Object* arg1)
	{
		throw new NotImplementedException();
	}
	StringBuilder* StringBuilder::AppendFormat(String* format, Object* arg0, Object* arg1, Object* arg2)
	{
		throw new NotImplementedException();
	}
	void StringBuilder::EnsureRoomFor(Int32 amount)
	{
		EnsureCapacity(currentLength + amount);
	}
	Int32 StringBuilder::EnsureCapacity(Int32 capacity)
	{
		if (capacity < 0) {
			throw new ArgumentOutOfRangeException();
		}
		if (get_Capacity() < capacity) {
			set_Capacity(capacity);
		}
		return get_Capacity();
	}
	Boolean StringBuilder::Equals(Object* object)
	{
		StringBuilder* sb = dynamic_cast<StringBuilder*>(object);
		return(Equals(sb));
	}
	Boolean StringBuilder::Equals(StringBuilder* sb)
	{
		if (sb == nullptr || sb->currentCapacity != currentCapacity || sb->maxCapacity != maxCapacity)
			return(false);
		return wcscmp(sb->chunkChars, chunkChars) == 0;
	}
	StringBuilder* StringBuilder::Remove(Int32 startIndex, Int32 length)
	{
		if (length < 0) {
			throw new ArgumentOutOfRangeException();
		}
		if (startIndex < 0) {
			throw new ArgumentOutOfRangeException();
		}
		if (length > this->currentLength - startIndex) {
			throw new ArgumentOutOfRangeException();
		}
		Int32 howmany = currentLength - startIndex - length;
		memcpy(&chunkChars[startIndex], &chunkChars[startIndex + length], howmany * sizeof(Char));
		currentLength -= length;
		chunkChars[currentLength] = 0;
		return this;
	}
	StringBuilder* StringBuilder::Insert(const Int32 index, const Boolean value)
	{
		BooleanValue data(value);
		return(Append(data, index));
	}
	StringBuilder* StringBuilder::Insert(const Int32 index, const Byte value)
	{
		ByteValue data(value);
		return(Append(data, index));
	}
	StringBuilder* StringBuilder::Insert(const Int32 index, const Char value)
	{
		CharValue data(value);
		return(Append(data, index));
	}
	StringBuilder* StringBuilder::Insert(const Int32 index, Array* values, Int32 startIndex, Int32 charCount)
	{
		if (values == nullptr) {
			return(this);
		}
		if (startIndex < 0) {
			startIndex = 0;
		}
		if (charCount < 0) {
			charCount = values->get_Length();
		}
		if (charCount == 0) {
			return(this);
		}
		if (charCount > values->get_Length() - startIndex)
		{
			throw new ArgumentOutOfRangeException();
		}
		if (values->GetElementType() != CharType) {
			throw new ArgumentOutOfRangeException();
		}
		values->EnsureSingleDimension();
		return(Append((Char*)values->Address(startIndex), charCount, index));
	}
	StringBuilder* StringBuilder::Insert(const Int32 index, Double value)
	{
		DoubleValue data(value);
		return(Append(data, index));
	}
	StringBuilder* StringBuilder::Insert(const Int32 index, const Int16 value)
	{
		Int16Value data(value);
		return(Append(data, index));
	}
	StringBuilder* StringBuilder::Insert(const Int32 index, Int32 value)
	{
		Int32Value data(value);
		return(Append(data, index));
	}
	StringBuilder* StringBuilder::Insert(const Int32 index, Int64 value)
	{
		Int64Value data(value);
		return(Append(data, index));
	}
	StringBuilder* StringBuilder::Insert(const Int32 index, Object* value)
	{
		return(Insert(index, value->ToString()));
	}
	StringBuilder* StringBuilder::Insert(const Int32 index, String* value, Int32 count)
	{
		for (int i = 0; i < count; ++i) {
			Append((Char*)value->Address(0), value->get_Length(), index);
		}
		return(this);
	}
	StringBuilder* StringBuilder::Insert(const Int32 index, const SByte value)
	{
		SByteValue data(value);
		return(Append(data, index));
	}
	StringBuilder* StringBuilder::Insert(const Int32 index, const Single value)
	{
		SingleValue data(value);
		return(Append(data, index));
	}
	StringBuilder* StringBuilder::Insert(const Int32 index, const UInt16 value)
	{
		UInt16Value data(value);
		return(Append(data, index));
	}
	StringBuilder* StringBuilder::Insert(const Int32 index, UInt32 value)
	{
		UInt32Value data(value);
		return(Append(data, index));
	}
	StringBuilder* StringBuilder::Insert(const Int32 index, const UInt64 value)
	{
		UInt64Value data(value);
		return(Append(data, index));
	}
	StringBuilder* StringBuilder::Replace(const Char oldChar, const Char newChar)
	{
		return Replace(oldChar, newChar, 0, currentLength);
	}
	StringBuilder* StringBuilder::Replace(String* search, String* replace)
	{
		return Replace(search, replace, 0, currentLength);
	}
	StringBuilder* StringBuilder::Replace(const Char oldChar, const Char newChar, const Int32 startIndex, const Int32 count)
	{
		int length = currentLength;
		if ((UInt32)startIndex > (UInt32)length) {
			throw new ArgumentOutOfRangeException();
		}
		if (count < 0 || startIndex > length - count) {
			throw new ArgumentOutOfRangeException();
		}
		int endIndex = startIndex + count;
		for (int i = startIndex; i < endIndex; ++i) {
			if (chunkChars[i] == oldChar) {
				chunkChars[i] = newChar;
			}
		}
		return this;
	}
	StringBuilder* StringBuilder::Replace(String* search, String* replace, const Int32 startIndex, const Int32 count)
	{
		int length = currentLength;
		if ((UInt32)startIndex > (UInt32)currentLength) {
			throw new ArgumentOutOfRangeException();
		}
		if (count < 0 || startIndex > length - count) {
			throw new ArgumentOutOfRangeException();
		}
		if (search == nullptr) {
			throw new ArgumentOutOfRangeException();
		}
		if (search->get_Length() == 0) {
			throw new ArgumentOutOfRangeException();
		}
		if (replace == nullptr) {
			replace = String::Empty;
		}
		Int32 howMany = CountSubStrings(search, startIndex, count);
		if (howMany == 0) {
			return this;
		}
		Int32	delta = replace->get_Length() - search->get_Length();
		if (delta > 0) {
			EnsureRoomFor(delta * howMany);
		}
		ReplaceSubString(search, replace, startIndex, count);
		return this;
	}
	void StringBuilder::ReplaceSubString(String* search, String* replace, const Int32 startIndex, const Int32 count)
	{
		Int32	endIndex = startIndex + 1 + count - search->get_Length();
		Int32	delta = replace->get_Length() - search->get_Length();
		Int32	bytesToCompare = search->get_Length() * sizeof(Char);
		for (int i = startIndex; i < endIndex;)
		{
			if (0 == memcmp(chunkChars + i, search->get_Buffer(), bytesToCompare))
			{
				Int32 howMuchToMove = currentLength - i - search->get_Length() ;
				memmove(&chunkChars[i + replace->get_Length()], &chunkChars[i + search->get_Length()], howMuchToMove * sizeof(Char));
				currentLength += delta;
				chunkChars[currentLength] = 0;
				endIndex += delta;
				memcpy(&chunkChars[i], replace->get_Buffer(), replace->get_Length() * sizeof(Char));
				i += replace->get_Length();
			}
			else
				++i;
		}
	}
}
