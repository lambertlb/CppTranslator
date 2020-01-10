#pragma once
#include "DotnetTypes.h"
#include <wchar.h>

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
	Char String::get_Chars(const Int32 index)
	{
		return *Address(index);
	}
	Char* String::Address(Int32 index1, Int32 index2, Int32 index3)
	{
		if (index1 < 0 || index1 >= length)
			throw new IndexOutOfRangeException();
		return(&characterData[index1]);
	}
	Int32 String::Compare(Char* s1, Int32 s1Index, Char* s2, Int32 s2Index, Int32 length, Boolean ignoreCase)
	{
		Char* str1 = s1 + s1Index;
		Char* str2 = s2 + s2Index;
		Char c1 = 0;
		Char c2 = 0;
		while (length > 0)
		{
			if (ignoreCase) {
				c1 = towlower(*str1++);
				c2 = towlower(*str2++);
			}
			else {
				c1 = *str1++;
				c2 = *str2++;
			}
			if (c1 == L'\0' || c1 != c2)
				return c1 > c2 ? 1 : (c1 < c2 ? -1 : 0);
			--length;
		}
		return 0;
	}
	Int32 String::Compare(String* s1, String* s2, Boolean ignoreCase)
	{
		return(Compare(s1->get_Buffer(), 0, s2->get_Buffer(), 0, s1->get_Length(), ignoreCase));
	}
	Int32 String::Compare(String* s1, const Int32 index1, String* s2, const Int32 index2, const Int32 length, Boolean ignoreCase)
	{
		return(Compare(s1->get_Buffer(), index1, s2->get_Buffer(), index2, length, ignoreCase));
	}
	Int32 String::CompareOrdinal(String* s1, String* s2)
	{
		return(Compare(s1->get_Buffer(), 0, s2->get_Buffer(), 0, s1->get_Length(), false));
	}
	Int32 String::CompareOrdinal(String* s1, const Int32 index1, String* s2, const Int32 index2, const Int32 length)
	{
		return(Compare(s1->get_Buffer(), index1, s2->get_Buffer(), index2, length, false));
	}
	Int32 String::CompareTo(Object* value)
	{
		if (value == nullptr)
			return(1);
		if (value->GetRawDataType() != StringType)
			throw new ArgumentException();
		CompareTo((String*)value);
		return Int32();
	}
	Int32 String::CompareTo(String* str)
	{
		if (str == nullptr)
			return(1);
		return Compare(this, str);
	}
	String* String::Concat(Array* values)
	{
		if (nullptr == values)
			throw new ArgumentNullException();
		values->EnsureSingleDimension();
		if (values->GetRawDataType() != ObjectType && values->GetRawDataType() != StringType)
			throw new ArgumentNullException();
		StringBuilder sb;
		for (int i = 0; i < values->get_Length(); ++i)
			sb.Append(*(Object**)values->Address(i));
		return(sb.ToString());
	}
	String* String::Concat(Object* o1, Object* o2, Object* o3, Object* o4, Object* o5, Object* o6, Object* o7)
	{
		if (nullptr == o1)
			throw new ArgumentNullException();
		StringBuilder sb;
		sb.Append(o1);
		if (o2 != nullptr)
			sb.Append(o2);
		if (o3 != nullptr)
			sb.Append(o3);
		if (o4 != nullptr)
			sb.Append(o4);
		if (o5 != nullptr)
			sb.Append(o5);
		if (o6 != nullptr)
			sb.Append(o6);
		if (o7 != nullptr)
			sb.Append(o7);
		return(sb.ToString());
	}
	Boolean String::Contains(String* substring)
	{
		StringBuilder sb(this);
		return(sb.CountSubStrings(substring, 0, length) != 0);
	}
	String* String::Copy(String* str)
	{
		if (nullptr == str)
			throw new ArgumentNullException();
		return(new String(str->characterData, 0, str->length));
	}
	void String::CopyTo(Int32 sourceIndex, Array* destination, Int32 destinationIndex, Int32 count)
	{
		if (destination == nullptr)
			throw new ArgumentNullException();
		destination->EnsureSingleDimension();
		if (destination->GetElementType() != CharType)
			throw new ArgumentNullException();
		if (count < 0)
			throw new ArgumentNullException();
		if (sourceIndex < 0)
			throw new ArgumentNullException();
		if (count > length - sourceIndex)
			throw new ArgumentNullException();
		if (destinationIndex > destination->get_Length() - count || destinationIndex < 0)
			throw new ArgumentNullException();
		Char* source = Address(sourceIndex);
		Char* dest = (Char*)destination->Address(destinationIndex);
		for (int i = 0; i < count; ++i) {
			*dest++ = *source++;
		}
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