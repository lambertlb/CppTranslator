#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	DLL_EXPORT Int32	Int32Value::MaxValue = 2147483647;
	DLL_EXPORT Int32	Int32Value::MinValue = -2147483648;

	Boolean Int32Value::get_AsBoolean()
	{
		return value != 0;
	}
	Char Int32Value::get_AsChar()
	{
		return (Char)value;
	}
	Byte Int32Value::get_AsByte()
	{
		return (Byte)value;
	}
	SByte Int32Value::get_AsSByte()
	{
		return (SByte)value;
	}
	Int16 Int32Value::get_AsInt16()
	{
		return (Int16)value;
	}
	UInt16 Int32Value::get_AsUInt16()
	{
		return (UInt16)value;
	}
	Int32 Int32Value::get_AsInt32()
	{
		return (Int32)value;
	}
	UInt32 Int32Value::get_AsUInt32()
	{
		return (UInt32)value;
	}
	Int64 Int32Value::get_AsInt64()
	{
		return (Int64)value;
	}
	UInt64 Int32Value::get_AsUInt64()
	{
		return (UInt64)value;
	}
	Single Int32Value::get_AsSingle()
	{
		return (Single)value;
	}
	Double Int32Value::get_AsDouble()
	{
		return (Double)value;
	}
	Int32 Int32Value::CompareTo(Int32 valueToCompare)
	{
		return value - valueToCompare;
	}
	Int32 Int32Value::CompareTo(Object* valueToCompare)
	{
		if (valueToCompare == nullptr) {
			return 1;
		}
		if (valueToCompare->GetRawDataType() != Int32Type) {
			throw new ArgumentException();
		}
		return value - ((Int32Value*)valueToCompare)->value;
	}
	bool Int32Value::Equals(Object* valueToCompare)
	{
		if (valueToCompare->GetRawDataType() != Int32Type) {
			return false;
		}
		return value == ((Int32Value*)valueToCompare)->value;
	}
	bool Int32Value::Equals(Int32 valueToCompare)
	{
		return value == valueToCompare;
	}
	Int32 Int32Value::FormatString(Char* where, const Int32 whereSize)
	{
		return(swprintf(where, whereSize, L"%d", value));
	}
	Int32 Int32Value::Parse(String* stringToParse)
	{
		UInt64	value = 0;
		Int32	sign = 0;
		if (!UInt64Value::TryParseInternal(stringToParse, value, sign))
			throw new FormatException();
		if (sign > 0 && value > MaxValue)
			throw new OverflowException();
		if (sign < 0 && (Int64)value < MinValue)
			throw new OverflowException();
		return((Int32)value * sign);
	}
	bool Int32Value::TryParse(String* stringToParse, Int32* result)
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
		*result = (Int32)value * sign;
		return(goodNumber);
	}
}
