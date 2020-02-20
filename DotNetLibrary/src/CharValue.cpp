// Copyright (c) 2019 LLambert
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this
// software and associated documentation files (the "Software"), to deal in the Software
// without restriction, including without limitation the rights to use, copy, modify, merge,
// publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons
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
#include "DotnetTypes.h"
#include <wctype.h>

namespace DotnetLibrary
{
	Char	CharValue::MaxValue = 0XFFFF;
	Char	CharValue::MinValue = 0;
	Char CharValue::get_AsChar()
	{
		return value;
	}
	Byte CharValue::get_AsByte()
	{
		return value;
	}
	SByte CharValue::get_AsSByte()
	{
		return value;
	}
	Int16 CharValue::get_AsInt16()
	{
		return value;
	}
	UInt16 CharValue::get_AsUInt16()
	{
		return value;
	}
	Int32 CharValue::get_AsInt32()
	{
		return value;
	}
	UInt32 CharValue::get_AsUInt32()
	{
		return value;
	}
	Int64 CharValue::get_AsInt64()
	{
		return value;
	}
	UInt64 CharValue::get_AsUInt64()
	{
		return value;
	}
	Single CharValue::get_AsSingle()
	{
		return value;
	}
	Double CharValue::get_AsDouble()
	{
		return value;
	}
	Int32 CharValue::CompareTo(Char valueToCompare)
	{
		return value - valueToCompare;
	}
	Int32 CharValue::CompareTo(Object* valueToCompare)
	{
		if (valueToCompare == nullptr) {
			return 1;
		}
		if (valueToCompare->GetRawDataType() != CharType) {
			throw new ArgumentException();
		}
		return value - ((CharValue*)valueToCompare)->value;
	}
	bool CharValue::Equals(Object* valueToCompare)
	{
		if (valueToCompare->GetRawDataType() != CharType) {
			return false;
		}
		return value == ((CharValue*)valueToCompare)->value;
	}
	bool CharValue::Equals(Char valueToCompare)
	{
		return value == valueToCompare;
	}
	Int32 CharValue::FormatString(Char* where, const Int32 whereSize)
	{
		if (whereSize < 2)
			throw new IndexOutOfRangeException();
		*where = value;
		return 1;
	}
	Double CharValue::GetNumericValue(String* v, Int32 index)
	{
		if (v == nullptr)
			throw new ArgumentNullException();
		if (index >= v->get_Length())
			throw new ArgumentOutOfRangeException();
		return(GetNumericValue(v->get_Chars(index)));
	}
	Double CharValue::GetNumericValue(Char v)
	{
		if (!IsDigit(v))
			return(-1);
		return(v - L'0');
	}
	Boolean CharValue::IsControl(Char v)
	{
		return iswcntrl(v);
	}
	Boolean CharValue::IsControl(String* v, Int32 index)
	{
		if (v == nullptr)
			throw new ArgumentNullException();
		if (index >= v->get_Length())
			throw new ArgumentOutOfRangeException();
		return(IsControl(v->get_Chars(index)));
	}
	Boolean CharValue::IsDigit(Char v)
	{
		return(iswdigit(v));
	}
	Boolean CharValue::IsDigit(String* v, Int32 index)
	{
		if (v == nullptr)
			throw new ArgumentNullException();
		if (index >= v->get_Length())
			throw new ArgumentOutOfRangeException();
		return(IsDigit(v->get_Chars(index)));
	}
	Boolean CharValue::IsLetter(Char v)
	{
		return(iswalpha(v));
	}
	Boolean CharValue::IsLetter(String* v, Int32 index)
	{
		if (v == nullptr)
			throw new ArgumentNullException();
		if (index >= v->get_Length())
			throw new ArgumentOutOfRangeException();
		return(IsLetter(v->get_Chars(index)));
	}
	Boolean CharValue::IsLetterOrDigit(Char v)
	{
		return(iswalnum(v));
	}
	Boolean CharValue::IsLetterOrDigit(String* v, Int32 index)
	{
		if (v == nullptr)
			throw new ArgumentNullException();
		if (index >= v->get_Length())
			throw new ArgumentOutOfRangeException();
		return(IsLetterOrDigit(v->get_Chars(index)));
	}
	Boolean CharValue::IsLower(Char v)
	{
		return(iswlower(v));
	}
	Boolean CharValue::IsLower(String* v, Int32 index)
	{
		if (v == nullptr)
			throw new ArgumentNullException();
		if (index >= v->get_Length())
			throw new ArgumentOutOfRangeException();
		return(IsLower(v->get_Chars(index)));
	}
	Boolean CharValue::IsNumber(Char v)
	{
		return IsDigit(v);
	}
	Boolean CharValue::IsNumber(String* v, Int32 index)
	{
		return IsDigit(v, index);
	}
	Boolean CharValue::IsPunctuation(Char v)
	{
		return(iswpunct(v));
	}
	Boolean CharValue::IsPunctuation(String* v, Int32 index)
	{
		if (v == nullptr)
			throw new ArgumentNullException();
		if (index >= v->get_Length())
			throw new ArgumentOutOfRangeException();
		return(IsPunctuation(v->get_Chars(index)));
	}
	Boolean CharValue::IsSeparator(Char v)
	{
		return IsWhiteSpace(v);
	}
	Boolean CharValue::IsSeparator(String* v, Int32 index)
	{
		if (v == nullptr)
			throw new ArgumentNullException();
		if (index >= v->get_Length())
			throw new ArgumentOutOfRangeException();
		return(IsSeparator(v->get_Chars(index)));
	}
	Boolean CharValue::IsUpper(Char v)
	{
		return(iswupper(v));
	}
	Boolean CharValue::IsUpper(String* v, Int32 index)
	{
		if (v == nullptr)
			throw new ArgumentNullException();
		if (index >= v->get_Length())
			throw new ArgumentOutOfRangeException();
		return(IsUpper(v->get_Chars(index)));
	}
	Boolean CharValue::IsWhiteSpace(Char v)
	{
		return(iswspace(v));
	}
	Boolean CharValue::IsWhiteSpace(String* v, Int32 index)
	{
		if (v == nullptr)
			throw new ArgumentNullException();
		if (index >= v->get_Length())
			throw new ArgumentOutOfRangeException();
		return(IsWhiteSpace(v->get_Chars(index)));
	}
	Char CharValue::Parse(String* stringToParse)
	{
		if (stringToParse == nullptr) {
			throw new ArgumentNullException();
		}
		if (stringToParse->get_Length() != 1) {
			throw new FormatException();
		}
		return stringToParse->get_Chars(0);
	}
	Char CharValue::ToLower(Char v)
	{
		return(towlower(v));
	}
	Char CharValue::ToUpper(Char v)
	{
		return(towupper(v));
	}
	Boolean CharValue::TryParse(String* stringToParse, Char& result)
	{
		result = L'\0';
		if (stringToParse == nullptr) {
			return false;
		}
		if (stringToParse->get_Length() != 1) {
			return false;
		}
		result = stringToParse->get_Chars(0);
		return true;
	}
	String* CharValue::ToString()
	{
		return(Object::ToString());
	}
	String* CharValue::ToString(Char v)
	{
		return CharValue(v).ToString();
	}
}