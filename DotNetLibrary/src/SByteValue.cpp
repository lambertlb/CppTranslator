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
	DLL_EXPORT SByte	SByteValue::MaxValue = 127;
	DLL_EXPORT SByte	SByteValue::MinValue = -128;

	Boolean SByteValue::get_AsBoolean()
	{
		return value != 0;
	}
	Char SByteValue::get_AsChar()
	{
		return (Char)value;
	}
	Byte SByteValue::get_AsByte()
	{
		return (Byte)value;
	}
	SByte SByteValue::get_AsSByte()
	{
		return (SByte)value;
	}
	Int16 SByteValue::get_AsInt16()
	{
		return (Int16)value;
	}
	UInt16 SByteValue::get_AsUInt16()
	{
		return (UInt16)value;
	}
	Int32 SByteValue::get_AsInt32()
	{
		return (Int32)value;
	}
	UInt32 SByteValue::get_AsUInt32()
	{
		return (UInt32)value;
	}
	Int64 SByteValue::get_AsInt64()
	{
		return (Int64)value;
	}
	UInt64 SByteValue::get_AsUInt64()
	{
		return (UInt64)value;
	}
	Single SByteValue::get_AsSingle()
	{
		return (Single)value;
	}
	Double SByteValue::get_AsDouble()
	{
		return (Double)value;
	}
	Int32 SByteValue::CompareTo(SByte valueToCompare)
	{
		return value - valueToCompare;
	}
	Int32 SByteValue::CompareTo(Object* valueToCompare)
	{
		if (valueToCompare == nullptr) {
			return 1;
		}
		if (valueToCompare->GetRawDataType() != SByteType) {
			throw new ArgumentException();
		}
		return value - ((SByteValue*)valueToCompare)->value;
	}
	bool SByteValue::Equals(Object* valueToCompare)
	{
		if (valueToCompare->GetRawDataType() != SByteType) {
			return false;
		}
		return value == ((SByteValue*)valueToCompare)->value;
	}
	bool SByteValue::Equals(SByte valueToCompare)
	{
		return value == valueToCompare;
	}
	Int32 SByteValue::FormatString(Char* where, const Int32 whereSize)
	{
#ifdef __MINGW32__
		return(swprintf(where, L"%d", value));
#else
		return(swprintf(where, whereSize, L"%d", value));
#endif
	}
	SByte SByteValue::Parse(String* stringToParse)
	{
		UInt64	value = 0;
		Int32	sign = 0;
		if (!UInt64Value::TryParseInternal(stringToParse, value, sign))
			throw new FormatException();
		if (sign > 0 && value > MaxValue)
			throw new OverflowException();
		if (sign < 0 && (Int64)value < MinValue)
			throw new OverflowException();
		return((SByte)value * sign);
	}
	bool SByteValue::TryParse(String* stringToParse, SByte& result)
	{
		Boolean goodNumber = true;
		UInt64	value = 0;
		Int32	sign = 0;
		if (!UInt64Value::TryParseInternal(stringToParse, value, sign))
			goodNumber = false;
		if (sign > 0 && value > MaxValue)
			goodNumber = false;
		if (sign < 0 && (Int64)value < MinValue)
			goodNumber = false;
		result = (SByte)value * sign;
		return(goodNumber);
	}
}
