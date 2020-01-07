#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	StringBuilder::StringBuilder() : StringBuilder(DefaultCapacity, Int32Value::MaxValue)
	{
	}
	StringBuilder::StringBuilder(Int32 capacity) : StringBuilder(capacity, Int32Value::MaxValue)
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
		set_Capacity(Math::Max(capacity, length + 1));
		Char* sourcePtr = value->Address(startIndex);
		memcpy(chunkChars, sourcePtr, length * sizeof(Char));
		chunkOffset = length;
	}
	StringBuilder::~StringBuilder()
	{
		if (chunkChars != nullptr && chunkChars != internalMemory)
			delete chunkChars;
		chunkChars = internalMemory;
	}
	void StringBuilder::Initialize()
	{
		maxCapacity = Int32Value::MaxValue;
		chunkChars = internalMemory;
		chunkOffset = 0;
		chunkLength = DefaultCapacity;
		memset(internalMemory, 0, sizeof(internalMemory));
	}
	Int32 StringBuilder::get_Length()
	{
		return chunkOffset;
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
			chunkOffset = 0;
			memset(chunkChars, 0, chunkLength * sizeof(Char));
			return;
		}
		EnsureCapacity(newLength);
		int delta = newLength - chunkOffset;
		if (delta == 0) {
			return;
		}
		if (delta < 0) {
			memset(chunkChars + (chunkOffset + delta), 0, -delta * sizeof(Char));
		}
		chunkOffset = newLength;
	}
	Int32 StringBuilder::get_Capacity()
	{
		return chunkLength;
	}
	void StringBuilder::set_Capacity(Int32 capacity)
	{
		if (capacity < 0) {
			throw new ArgumentOutOfRangeException();
		}
		if (capacity > maxCapacity) {
			throw new ArgumentOutOfRangeException();
		}
		if (chunkChars != internalMemory && capacity < chunkLength) {
			throw new ArgumentOutOfRangeException();
		}
		if (chunkLength >= capacity) {
			chunkLength = capacity;
			return;
		}
		Char* newArray = internalMemory;
		if (capacity > DefaultCapacity) {
			newArray = new Char[capacity];
			memcpy(newArray, chunkChars, chunkOffset * sizeof(Char));
			if (chunkChars != internalMemory)
				delete chunkChars;
		}
		chunkLength = capacity;
		chunkChars = newArray;
	}
	Int32 StringBuilder::get_MaxCapacity()
	{
		return maxCapacity;
	}
	Char* StringBuilder::Address(Int32 index1, Int32 index2, Int32 index3)
	{
		if (index1 < 0 || index1 >= chunkOffset)
			throw new IndexOutOfRangeException();
		return(&chunkChars[index1]);
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
		return(new String(chunkChars, 0, chunkOffset));
	}
	String* StringBuilder::ToString(Int32 startIndex, Int32 length)
	{
		if (startIndex < 0 || startIndex >= chunkOffset)
			throw new IndexOutOfRangeException();
		if (startIndex + length > chunkOffset)
			throw new IndexOutOfRangeException();
		return(new String(&chunkChars[startIndex], 0, length));
	}
	Int32 StringBuilder::FormatString(Char* where, const Int32 whereSize)
	{
		if (whereSize < chunkOffset)
			throw new IndexOutOfRangeException();
		wcscpy_s(where, whereSize, chunkChars);
		return chunkOffset;
	}
	StringBuilder* StringBuilder::Append(const Char* values, Int32 charCount, Int32 where)
	{
		if (where == -1) {
			where = chunkOffset;
		}
		if (where > chunkOffset) {
			throw new IndexOutOfRangeException();
		}
		EnsureCapacity(chunkOffset + charCount + 1);
		if (where != chunkOffset) {
			memmove(&chunkChars[where + charCount] , &chunkChars[where], (chunkOffset - where) * sizeof(Char));
		}
		memcpy(&chunkChars[where], values, charCount * sizeof(Char));
		chunkOffset += charCount;
		chunkChars[chunkOffset] = 0;
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
		if (values->dataType != CharType) {
			throw new ArgumentOutOfRangeException();
		}
		values->EnsureSingleDimension();
		return(Append((Char*)values->Address(startIndex), charCount, 0));
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
		EnsureCapacity(chunkOffset + repeatCount);
		for (int i = 0; i < repeatCount; ++i) {
			chunkChars[chunkOffset++] = value;
		}
		chunkChars[chunkOffset] = 0;
		return(this);
	}
	StringBuilder* StringBuilder::Append(String* value, Int32 startIndex, Int32 charCount)
	{
		if (charCount < 0)
			charCount = value->length;
		if (startIndex < 0) {
			throw new ArgumentOutOfRangeException();
		}
		if (startIndex > value->get_Length() - charCount) {
			throw new ArgumentOutOfRangeException();
		}
		return(Append(&value->characterData[startIndex], charCount));
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
	StringBuilder* StringBuilder::Remove(Int32 startIndex, Int32 length)
	{
		if (length < 0) {
			throw new ArgumentOutOfRangeException();
		}
		if (startIndex < 0) {
			throw new ArgumentOutOfRangeException();
		}
		if (length > this->chunkOffset - startIndex) {
			throw new ArgumentOutOfRangeException();
		}
		memcpy(&chunkChars[startIndex], &chunkChars[startIndex + length], (chunkOffset - length) * sizeof(char));
		chunkOffset -= length;
		chunkChars[chunkOffset] = 0;
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
		if (values->dataType != CharType) {
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
}
