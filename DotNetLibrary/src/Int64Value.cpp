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
#include <cwchar>

namespace DotnetLibrary
{
	DLL_EXPORT Int64	Int64Value::MaxValue = 9223372036854775807;
	DLL_EXPORT Int64	Int64Value::MinValue = 0x8000000000000000;

	Boolean Int64Value::get_AsBoolean()
	{
		return value != 0;
	}
	Char Int64Value::get_AsChar()
	{
		return (Char)value;
	}
	Byte Int64Value::get_AsByte()
	{
		return (Byte)value;
	}
	SByte Int64Value::get_AsSByte()
	{
		return (SByte)value;
	}
	Int16 Int64Value::get_AsInt16()
	{
		return (Int64)value;
	}
	UInt16 Int64Value::get_AsUInt16()
	{
		return (UInt64)value;
	}
	Int32 Int64Value::get_AsInt32()
	{
		return (Int32)value;
	}
	UInt32 Int64Value::get_AsUInt32()
	{
		return (UInt32)value;
	}
	Int64 Int64Value::get_AsInt64()
	{
		return (Int64)value;
	}
	UInt64 Int64Value::get_AsUInt64()
	{
		return (UInt64)value;
	}
	Single Int64Value::get_AsSingle()
	{
		return (Single)value;
	}
	Double Int64Value::get_AsDouble()
	{
		return (Double)value;
	}
	Int32 Int64Value::CompareTo(Int64 valueToCompare)
	{
		return value - valueToCompare;
	}
	Int32 Int64Value::CompareTo(Object* valueToCompare)
	{
		if (valueToCompare == nullptr) {
			return 1;
		}
		if (valueToCompare->GetRawDataType() != Int64Type) {
			throw new ArgumentException();
		}
		return value - ((Int64Value*)valueToCompare)->value;
	}
	bool Int64Value::Equals(Object* valueToCompare)
	{
		if (valueToCompare->GetRawDataType() != Int64Type) {
			return false;
		}
		return value == ((Int64Value*)valueToCompare)->value;
	}
	bool Int64Value::Equals(Int64 valueToCompare)
	{
		return value == valueToCompare;
	}
	Int32 Int64Value::FormatString(Char* where, const Int32 whereSize)
	{
#ifdef __MINGW32__
		return(swprintf(where, L"%lld", value));
#else
		return(swprintf(where, whereSize, L"%lld", value));
#endif
	}
	Int64 Int64Value::Parse(String* stringToParse)
	{
		UInt64	value = 0;
		Int32	sign = 0;
		if (!UInt64Value::TryParseInternal(stringToParse, value, sign))
			throw new FormatException();
		return((Int64)value * sign);
	}
	bool Int64Value::TryParse(String* stringToParse, Int64& result)
	{
		Boolean goodNumber = true;
		UInt64	value = 0;
		Int32	sign = 0;
		if (!UInt64Value::TryParseInternal(stringToParse, value, sign))
			goodNumber = false;
		result = (Int64)value * sign;
		return(goodNumber);
	}
}
