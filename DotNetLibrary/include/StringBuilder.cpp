#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	StringBuilder::StringBuilder()
	{
		maxCapacity = Int32Value::MaxValue;
		chunkChars = new Char[DefaultCapacity];
		chunkOffset = 0;
		chunkLength = DefaultCapacity;
	}
	StringBuilder::StringBuilder(Int32 capacity) : StringBuilder(capacity, Int32Value::MaxValue)
	{
	}
	StringBuilder::StringBuilder(Int32 capacity, Int32 maxCapacity)
	{
		chunkOffset = 0;
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
		chunkLength = capacity;
		chunkChars = new Char[capacity];
	}
	StringBuilder::StringBuilder(String* value, Int32 capacity) : StringBuilder(value, 0 , value->get_Length(), capacity)
	{
	}
	StringBuilder::StringBuilder(String* value, Int32 startIndex, Int32 length, Int32 capacity)
	{
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
		maxCapacity = Int32Value::MaxValue;
		if (capacity == 0) {
			capacity = DefaultCapacity;
		}
		chunkLength = Math::Max(capacity, length + 1);
		chunkChars = new Char[capacity];
		Char* sourcePtr = value->Address(startIndex);
		memcpy(chunkChars, sourcePtr, length * sizeof(Char));
		chunkOffset = length;
	}
	StringBuilder::~StringBuilder()
	{
		if (chunkChars != nullptr)
			delete chunkChars;
		chunkChars = nullptr;
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
			chunkLength = 0;
			chunkOffset = 0;
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
		if (capacity < chunkLength) {
			throw new ArgumentOutOfRangeException();
		}
		if (chunkLength != capacity) {
			Int32 newLen = capacity - chunkOffset;
			Char* newArray = new Char[capacity];
			memcpy(newArray, chunkChars, chunkOffset + 1);
			delete chunkChars;
			chunkLength = capacity;
			chunkChars = newArray;
		}
	}
	Int32 StringBuilder::get_MaxCapacity()
	{
		return maxCapacity;
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
