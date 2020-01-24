#pragma once
#include "DotnetTypes.h"
#include <wchar.h>

namespace DotnetLibrary
{
	DLL_EXPORT String* String::Empty = new String(L"");
	// all possible whitespace characters
	Char	WhiteSpaceChars[] =
	{ (Char)0x9, (Char)0xA, (Char)0xB, (Char)0xC,
	(Char)0xD, (Char)0x20, (Char)0xA0, (Char)0x2000,
	(Char)0x2001, (Char)0x2002, (Char)0x2003, (Char)0x2004,
	(Char)0x2005,(Char)0x2006, (Char)0x2007, (Char)0x2008,
	(Char)0x2009, (Char)0x200A, (Char)0x200B, (Char)0x3000, (Char)0xFEFF };

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
		if (values->GetElementType() != CharType) {
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
		if (chr == 0)
			return;
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
	Boolean String::EndsWith(String* what)
	{
		if (what == nullptr) {
			throw new ArgumentNullException();
		}
		if (this == what) {
			return true;
		}
		if (what->length == 0) {
			return true;
		}
		StringBuilder sb(this);
		return(sb.CountSubStrings(what, length - what->get_Length(), what->get_Length()) != 0);
	}
	Boolean String::EndsWith(Char what)
	{
		int lastPos = get_Length() - 1;
		if (lastPos < 0)
			return(false);
		return (characterData[lastPos] == what);
	}
	Boolean String::op_Inequality(String* str, String* str2)
	{
		if (str == str2) {
			return false;
		}
		if (str == nullptr || str2 == nullptr || str->get_Length() != str2->get_Length()) {
			return true;
		}
		return wcscmp(str->get_Buffer(), str2->get_Buffer()) != 0;
	}
	Boolean String::Equals(Object* object)
	{
		if (object == nullptr || object->GetRawDataType() != StringType)
			return(false);
		return !op_Inequality(this, (String*)object);
	}
	Boolean String::Equals(String* object)
	{
		return !op_Inequality(this, object);
	}
	Boolean String::Equals(String* object, Object* object2)
	{
		if (object2 == nullptr || object2->GetRawDataType() != StringType)
			return(false);
		return !op_Inequality(object, (String*)object2);
	}
	String* String::Format(String* format, Array* args)
	{
//		throw new NotImplementedException();
		return String::Empty;
	}
	String* String::Format(String* format, Object* arg1, Object* arg2, Object* arg3)
	{
//		throw new NotImplementedException();
		return String::Empty;
	}
	CharEnumerator* String::GetEnumerator()
	{
		return(new CharEnumerator(this));
	}
	Int32 String::IndexOf(const Char value)
	{
		return IndexOf(value, 0, length);
	}
	Int32 String::IndexOf(const Char value, const Int32 startIndex)
	{
		return IndexOf(value, startIndex, length - startIndex);
	}
	Int32 String::IndexOf(const Char value, const Int32 startIndex, const Int32 count)
	{
		if (count > length - startIndex)
			throw new ArgumentNullException();
		Int32 endIndex = startIndex + count;
		for (Int32 index = startIndex; index < endIndex; ++index) {
			if (get_Chars(index) == value)
				return(index);
		}
		return(-1);
	}
	Int32 String::IndexOf(String* value)
	{
		if (value == nullptr)
			throw new ArgumentNullException();
		return IndexOf(value, 0, length);
	}
	Int32 String::IndexOf(String* value, const Int32 startIndex)
	{
		if (value == nullptr)
			throw new ArgumentNullException();
		return IndexOf(value, startIndex, length - startIndex);
	}
	Int32 String::IndexOf(String* value, const Int32 startIndex, const Int32 count)
	{
		if (value == nullptr)
			throw new ArgumentNullException();
		if (startIndex < 0 || count < 0)
			throw new ArgumentNullException();
		if (count > length - startIndex)
			throw new ArgumentNullException();
		Char* found = wcsstr(get_Buffer() + startIndex, value->get_Buffer());
		if (found == nullptr)
			return(-1);
		Int32 delta = found - get_Buffer();
		Int32 endIndex = startIndex + count;
		return(delta > endIndex ? -1 : delta);
	}
	Int32 String::IndexOfAny(Array* arr)
	{
		if (arr == nullptr)
			throw new ArgumentNullException();
		return IndexOfAny(arr, 0, get_Length());
	}
	Int32 String::IndexOfAny(Array* arr, const Int32 startIndex)
	{
		if (arr == nullptr)
			throw new ArgumentNullException();
		return IndexOfAny(arr, startIndex, get_Length() - startIndex);
	}
	Int32 String::IndexOfAny(Array* arr, const Int32 startIndex, const Int32 count)
	{
		if (arr == nullptr)
			throw new ArgumentNullException();
		if (startIndex < 0 || count < 0)
			throw new ArgumentNullException();
		if (count > length - startIndex)
			throw new ArgumentNullException();
		arr->EnsureSingleDimension();
		if (arr->GetElementType() != CharType)
			throw new ArgumentNullException();
		Int32 endIndex = startIndex + count;
		for (Int32 index = startIndex; index < endIndex; ++index) {
			for (Int32 arrayIndex = 0; arrayIndex < arr->get_Length(); ++arrayIndex) {
				Char* xx = (Char*)arr->Address(arrayIndex);
				if (*xx == get_Chars(index)) {
					return(index);
				}
			}
		}
		return(-1);
	}
	String* String::Insert(const Int32 startIndex, String* value)
	{
		if (value == nullptr)
			throw new ArgumentNullException();
		if (startIndex < 0 || startIndex > length)
			throw new ArgumentOutOfRangeException();
		StringBuilder	sb(this);
		sb.Insert(startIndex, value);
		return(sb.ToString());
	}
	Boolean String::IsNullOrEmpty(String* value)
	{
		return(value == nullptr || value->get_Length() == 0);
	}
	Boolean String::IsNullOrWhiteSpace(String* value)
	{
		if (IsNullOrEmpty(value))
			return(true);
		for (Int32 i = 0; i < value->length; ++i) {
			if (!iswspace(value->characterData[i]))
				return(false);
		}
		return(true);
	}
	String* String::Join(String* separator, Array* values, const Int32 startIndex, Int32 count)
	{
		if (values == nullptr) {
			throw new ArgumentNullException();
		}
		if (values->get_Length() == 0) {
			return String::Empty;
		}
		values->EnsureSingleDimension();
		if (values->GetRawDataType() != ObjectType && values->GetRawDataType() != StringType)
			throw new ArgumentNullException();
		if (startIndex < 0)
			throw new ArgumentNullException();
		if (count < 0)
			count = values->get_Length() - startIndex;
		if (count > values->get_Length() - startIndex)
			throw new ArgumentNullException();
		Int32 endIndex = count + startIndex;
		StringBuilder sb;
		Boolean isFirst = true;
		for (int i = startIndex; i < endIndex; ++i) {
			if (!isFirst)
				sb.Append(separator);
			isFirst = false;
			sb.Append(*(Object**)values->Address(i));
		}
		return(sb.ToString());
	}
	Int32 String::LastIndexOf(const Char value, Int32 startIndex, Int32 count)
	{
		if (startIndex < 0)
			startIndex = length - 1;
		if (count < 0)
			count = startIndex + 1;
		Int32 endIndex = startIndex - count;
		for (Int32 index = startIndex; index > endIndex; --index) {
			if (get_Chars(index) == value)
				return(index);
		}
		return(-1);
	}
	Int32 String::LastIndexOf(String* value, Int32 startIndex, Int32 count)
	{
		if (value == nullptr)
			throw new ArgumentNullException();
		if (startIndex < 0)
			startIndex = length - 1;
		if (count < 0)
			count = startIndex + 1;
		Int32 endIndex = startIndex - count;
		for (Int32 i = startIndex; i > endIndex; --i) {
			Char* found = wcsstr(get_Buffer() + i, value->get_Buffer());
			if (found != nullptr) {
				Int32 delta = found - get_Buffer();
				if (delta <= startIndex)
					return(delta);
			}
		}
		return -1;
	}
	Int32 String::LastIndexOfAny(Array* arr, Int32 startIndex, Int32 count)
	{
		if (arr == nullptr)
			throw new ArgumentNullException();
		if (startIndex < 0)
			startIndex = length - 1;
		if (count < 0)
			count = startIndex + 1;
		arr->EnsureSingleDimension();
		if (arr->GetElementType() != CharType)
			throw new ArgumentNullException();
		Int32 endIndex = startIndex - count;
		for (Int32 index = startIndex; index > endIndex; --index) {
			for (Int32 arrayIndex = 0; arrayIndex < arr->get_Length(); ++arrayIndex) {
				Char* xx = (Char*)arr->Address(arrayIndex);
				if (*xx == get_Chars(index)) {
					return(index);
				}
			}
		}
		return(-1);
	}
	String* String::PadLeft(const Int32 width, const Char chr)
	{
		if (width < 0)
			throw new ArgumentOutOfRangeException();
		int oldLength = length;
		int count = width - oldLength;
		if (count <= 0)
			return this;
		StringBuilder	sb(length + width);
		sb.Append(chr, count);
		sb.Append(this);
		return(sb.ToString());
	}
	String* String::PadRight(const Int32 width, const Char chr)
	{
		if (width < 0)
			throw new ArgumentOutOfRangeException();
		int oldLength = length;
		int count = width - oldLength;
		if (count <= 0)
			return this;
		StringBuilder	sb(length + width);
		sb.Append(this);
		sb.Append(chr, count);
		return(sb.ToString());
	}
	String* String::Remove(const Int32 startIndex, Int32 count)
	{
		StringBuilder	sb(this);
		if (count < 0)
			count = length - startIndex;
		sb.Remove(startIndex, count);
		return(sb.ToString());
	}
	String* String::Replace(const Char oldChar, const Char newChar)
	{
		StringBuilder	sb(this);
		sb.Replace(oldChar, newChar);
		return(sb.ToString());
	}
	String* String::Replace(String* oldValue, String* newValue)
	{
		StringBuilder	sb(this);
		sb.Replace(oldValue, newValue);
		return(sb.ToString());
	}
	Array* String::Split(Array* separator, const Int32 count)
	{
//		throw new NotImplementedException();
		return(new Array(StringType, 0));
	}
	Boolean String::StartsWith(String* what)
	{
		if (what == nullptr) {
			throw new ArgumentNullException();
		}
		if (this == what) {
			return true;
		}
		if (what->length == 0) {
			return true;
		}
		StringBuilder sb(this);
		return(sb.CountSubStrings(what, 0, what->get_Length()) != 0);
	}
	String* String::Substring(const Int32 startIndex, Int32 length)
	{
		if (startIndex < 0) {
			throw new ArgumentOutOfRangeException();
		}
		if (startIndex > get_Length()) {
			throw new ArgumentOutOfRangeException();
		}
		if (length < 0) {
			length = get_Length() - startIndex;
		}
		if (startIndex > get_Length() - length) {
			throw new ArgumentOutOfRangeException();
		}
		if (length == 0) {
			return String::Empty;
		}
		if (startIndex == 0 && length == get_Length()) {
			return this;
		}
		return(new String(this->characterData, startIndex, length));
	}
	Array* String::ToCharArray(Int32 startIndex, Int32 length)
	{
		if (startIndex < 0) {
			throw new ArgumentOutOfRangeException();
		}
		if (length < 0) {
			length = get_Length() - startIndex;
		}
		if (startIndex > get_Length() - length) {
			throw new ArgumentOutOfRangeException();
		}
		Int32 endIndex = startIndex + length;
		Array* array = new Array(CharType, length);
		Int32 arrayIndex = 0;
		for (Int32 i = startIndex; i < endIndex; ++i) {
			*(Char*)array->Address(arrayIndex++) = get_Chars(i);
		}
		return(array);
	}
	String* String::ToLower()
	{
		Char* str1 = characterData;
		Int32 size = length;
		String* lower = new String((Char)0, size);
		Char* str2 = lower->characterData;
		for (Int32 i = 0; i < size; ++i) {
			*str2++ = towlower(*str1++);
		}
		return(lower);
	}
	String* String::ToLowerInvariant()
	{
		return ToLower();
	}
	String* String::ToString()
	{
		return this;
	}
	String* String::ToUpper()
	{
		Char* str1 = characterData;
		Int32 size = length;
		String* upper = new String((Char)0, size);
		Char* str2 = upper->characterData;
		for (Int32 i = 0; i < size; ++i) {
			*str2++ = towupper(*str1++);
		}
		return(upper);
	}
	String* String::ToUpperInvariant()
	{
		return ToUpper();
	}
	String* String::Trim()
	{
		return(TrimHelper(WhiteSpaceChars, sizeof(WhiteSpaceChars) / sizeof(char), true, true));
	}
	String* String::Trim(Array* separator)
	{
		return(TrimHelper(separator, true, true));
	}
	String* String::TrimHelper(Array* separator, Boolean trimStart, Boolean trimEnd)
	{
		if (separator == nullptr || separator->get_Length() == 0)
			return(TrimHelper(WhiteSpaceChars, sizeof(WhiteSpaceChars) / sizeof(char), trimStart, trimEnd));
		if (separator->GetElementType() != CharType) {
			throw new ArgumentOutOfRangeException();
		}
		separator->EnsureSingleDimension();
		return(TrimHelper((Char*)separator->Address(0), separator->get_Length(), trimStart, trimEnd));
	}
	String* String::TrimEnd(Array* separator)
	{
		if (separator == nullptr || separator->get_Length() == 0)
			return(TrimHelper(WhiteSpaceChars, sizeof(WhiteSpaceChars) / sizeof(char), false, true));
		if (separator->GetElementType() != CharType) {
			throw new ArgumentOutOfRangeException();
		}
		separator->EnsureSingleDimension();
		return(TrimHelper((Char*)separator->Address(0), separator->get_Length(), false, true));
	}
	String* String::TrimStart(Array* separator)
	{
		if (separator == nullptr || separator->get_Length() == 0)
			return(TrimHelper(WhiteSpaceChars, sizeof(WhiteSpaceChars) / sizeof(char), true, false));
		if (separator->GetElementType() != CharType) {
			throw new ArgumentOutOfRangeException();
		}
		separator->EnsureSingleDimension();
		return(TrimHelper((Char*)separator->Address(0), separator->get_Length(), true, false));
	}
	String* String::TrimHelper(Char* separator, Int32 separaterSize, Boolean trimStart, Boolean trimEnd)
	{

		Int32 end = length - 1;
		Int32 start = 0;
		if (trimStart) {
			for (start = 0; start < length; start++) {
				if (!IsWhiteSpace(get_Chars(start), separator, separaterSize)) {
					break;
				}
			}
		}
		if (trimEnd) {
			for (end = length - 1; end >= start; end--) {
				if (!IsWhiteSpace(get_Chars(end), separator, separaterSize)) {
					break;
				}
			}
		}
		return (new String(get_Buffer(), start, (end - start) + 1));
	}
	Boolean String::IsWhiteSpace(Char value, Char* separators, Int32 separatorSize)
	{
		for (Int32 i = 0; i < separatorSize; ++i) {
			if (value == *separators++)
				return(true);
		}
		return(false);
	}
	Int32 String::FormatString(Char* where, const Int32 whereSize)
	{
		if (whereSize < this->length)
			throw new IndexOutOfRangeException();
		wcscpy_s(where, whereSize, this->characterData);
		return this->length;
	}
}