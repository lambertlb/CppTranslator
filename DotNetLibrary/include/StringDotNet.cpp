#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	String::String(const Char* string)
	{
		this->length = wcslen(string);
		characterData = (Char*)string;
		allocate = false;
	}
	DotnetLibrary::String::String(const Char* string, const Int32 startIndex, Int32 length)
	{
		allocate = true;
		if (length < 0)
			length = wcslen(string);
		this->length = length;
		characterData = new Char[(DataTypeSize[ByteType] * length) + 1];
		for (size_t i = 0; i < length; ++i) {
			characterData[i] = string[i];
		}
	}
	String::String(Array* chrs, const Int32 startIndex, const Int32 length)
	{
		allocate = false;
	}
	String::~String()
	{
		if (allocate && characterData != nullptr)
			delete characterData;
		characterData = nullptr;
	}
	String* String::ToString()
	{
		return this;
	}
	Int32 String::FormatString(Char* where, const Int32 whereSize)
	{
		if (whereSize < this->length)
			throw new IndexOutOfRangeException();
		wcscpy_s(where, whereSize, this->characterData);
		return this->length;
	}
}