#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	DLL_EXPORT UInt16	UInt16Value::MaxValue = 65535;
	DLL_EXPORT UInt16	UInt16Value::MinValue = 0;

	Boolean UInt16Value::get_AsBoolean()
	{
		return value != 0;
	}
	Char UInt16Value::get_AsChar()
	{
		return (Char)value;
	}
	Byte UInt16Value::get_AsByte()
	{
		return (Byte)value;
	}
	SByte UInt16Value::get_AsSByte()
	{
		return (SByte)value;
	}
	Int16 UInt16Value::get_AsInt16()
	{
		return (Int16)value;
	}
	UInt16 UInt16Value::get_AsUInt16()
	{
		return (UInt16)value;
	}
	Int32 UInt16Value::get_AsInt32()
	{
		return (Int32)value;
	}
	UInt32 UInt16Value::get_AsUInt32()
	{
		return (UInt32)value;
	}
	Int64 UInt16Value::get_AsInt64()
	{
		return (Int64)value;
	}
	UInt64 UInt16Value::get_AsUInt64()
	{
		return (UInt64)value;
	}
	Single UInt16Value::get_AsSingle()
	{
		return (Single)value;
	}
	Double UInt16Value::get_AsDouble()
	{
		return (Double)value;
	}
	Int32 UInt16Value::CompareTo(UInt16 valueToCompare)
	{
		return value - valueToCompare;
	}
	Int32 UInt16Value::CompareTo(Object* valueToCompare)
	{
		if (valueToCompare == nullptr) {
			return 1;
		}
		if (valueToCompare->GetRawDataType() != UInt16Type) {
			throw new ArgumentException();
		}
		return value - ((UInt16Value*)valueToCompare)->value;
	}
	bool UInt16Value::Equals(Object* valueToCompare)
	{
		if (valueToCompare->GetRawDataType() != UInt16Type) {
			return false;
		}
		return value == ((UInt16Value*)valueToCompare)->value;
	}
	bool UInt16Value::Equals(UInt16 valueToCompare)
	{
		return value == valueToCompare;
	}
	Int32 UInt16Value::FormatString(Char* where, const Int32 whereSize)
	{
		return(swprintf(where, whereSize, L"%d", value));
	}
	UInt16 UInt16Value::Parse(String* stringToParse)
	{
		UInt64	value = 0;
		Int32	sign = 0;
		if (!UInt64Value::TryParseInternal(stringToParse, value, sign))
			throw new FormatException();
		if (value > MaxValue)
			throw new OverflowException();
		return((UInt16)value * sign);
	}
	bool UInt16Value::TryParse(String* stringToParse, UInt16* result)
	{
		Boolean goodNumber = true;
		UInt64	value = 0;
		Int32	sign = 0;
		if (!UInt64Value::TryParseInternal(stringToParse, value, sign))
			goodNumber = false;
		if (sign < 0 || value > MaxValue)
			goodNumber = false;
		*result = (UInt16)value;
		return(goodNumber);
	}
}
