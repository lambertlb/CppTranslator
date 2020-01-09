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
		if (string == nullptr)
			throw new ArgumentOutOfRangeException();
		if (length < 0)
			length = wcslen(string);
		if (startIndex < 0 || startIndex > wcslen(string))
			throw new ArgumentOutOfRangeException();

		allocate = true;
		this->length = length;
		characterData = new Char[length + 1];
		for (size_t i = 0; i < length; ++i) {
			characterData[i] = string[i + startIndex];
		}
	}
	String::String(Array* values, Int32 startIndex, Int32 length)
	{
		allocate = true;
		if (length < 0) {
			length = values->get_Length();
		}
		if (values == nullptr || length == 0) {
			this->length = 0;
			characterData = new Char[1];
			return;
		}
		if (startIndex < 0) {
			startIndex = 0;
		}
		if (length > values->get_Length() - startIndex) {
			throw new ArgumentOutOfRangeException();
		}
		if (values->dataType != CharType) {
			throw new ArgumentOutOfRangeException();
		}
		values->EnsureSingleDimension();
		this->length = length;
		characterData = new Char[length + 1];
		for (size_t i = 0; i < length; ++i) {
			characterData[i] = *(Char*)values->Address(i + startIndex);
		}
	}
	String::String(const Char chr, const Int32 amount)
	{
		if (amount < 0) {
			throw new ArgumentOutOfRangeException();
		}
		this->length = amount;
		characterData = new Char[length + 1];
		for (size_t i = 0; i < amount; ++i) {
			characterData[i] = chr;
		}
	}
	String::~String()
	{
		if (allocate && characterData != nullptr)
			delete characterData;
		characterData = nullptr;
	}
	Char* String::Address(Int32 index1, Int32 index2, Int32 index3)
	{
		if (index1 < 0 || index1 >= length)
			throw new IndexOutOfRangeException();
		return(&characterData[index1]);
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