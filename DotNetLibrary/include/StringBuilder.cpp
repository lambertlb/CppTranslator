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
			memcpy(newArray, chunkChars, chunkOffset);
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
		if (index1 < 0 || index1 >= chunkOffset - 1)
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
		return(new String(chunkChars,0,chunkOffset));
	}
	String* StringBuilder::ToString(Int32 startIndex, Int32 length)
	{
		if (startIndex < 0 || startIndex >= chunkOffset)
			throw new IndexOutOfRangeException();
		if (startIndex + length >= chunkOffset)
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
}
