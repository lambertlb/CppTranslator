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

namespace DotnetLibrary
{
	String	trueString(L"True");
	DLL_EXPORT String* BooleanValue::TrueString =&trueString;
	String	falseString(L"False");
	DLL_EXPORT String* BooleanValue::FalseString = &falseString;

	Boolean BooleanValue::get_AsBoolean()
	{
		return(value);
	}

	Byte BooleanValue::get_AsByte()
	{
		return(value ? 1 : 0);
	}

	SByte BooleanValue::get_AsSByte()
	{
		return(value ? 1 : 0);
	}

	Int16 BooleanValue::get_AsInt16()
	{
		return(value ? 1 : 0);
	}

	UInt16 BooleanValue::get_AsUInt16()
	{
		return(value ? 1 : 0);
	}

	Int32 BooleanValue::get_AsInt32()
	{
		return(value ? 1 : 0);
	}

	UInt32 BooleanValue::get_AsUInt32()
	{
		return(value ? 1 : 0);
	}

	Int64 BooleanValue::get_AsInt64()
	{
		return(value ? 1 : 0);
	}

	UInt64 BooleanValue::get_AsUInt64()
	{
		return(value ? 1 : 0);
	}

	Int32 BooleanValue::CompareTo(Boolean valueToCompare)
	{
		if (value == valueToCompare)
		{
			return 0;
		}
		else if (value == false)
		{
			return -1;
		}
		return 1;
	}

	Int32 BooleanValue::CompareTo(Object* valueToCompare)
	{
		if (valueToCompare == nullptr)
			return(1);
		if (valueToCompare->GetRawDataType() != BooleanType)
			throw new ArgumentException();
		return(CompareTo(((BooleanValue*)valueToCompare)->value));
	}

	bool BooleanValue::Equals(Object* valueToCompare)
	{
		if (valueToCompare == nullptr)
			return(false);
		if (valueToCompare->GetRawDataType() != BooleanType)
			return(false);
		return(valueToCompare->get_AsBoolean() == value);
	}

	bool BooleanValue::Equals(Boolean valueToCompare)
	{
		return valueToCompare == value;
	}

	Int32 BooleanValue::FormatString(Char* where, const Int32 whereSize)
	{
		Int32 rtn;
		if (value) {
			CopyChars(where, whereSize, TrueString->get_Buffer(), TrueString->get_Length());
			rtn = TrueString->get_Length();
		}
		else {
			CopyChars(where, whereSize, FalseString->get_Buffer(), FalseString->get_Length());
			rtn = FalseString->get_Length();
		}
		return rtn;
	}
	Boolean BooleanValue::Parse(String* stringToParse)
	{
		if (stringToParse == nullptr)
			throw new ArgumentException();
		if (String::Compare(stringToParse, TrueString, true) == 0) {
			return true;
		}
		if (String::Compare(stringToParse, FalseString, true) == 0) {
			return false;
		}
		throw new FormatException();
	}
}
