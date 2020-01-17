#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	Byte	ByteValue::MaxValue = 255;
	Byte	ByteValue::MinValue = 0;
	Boolean ByteValue::get_AsBoolean()
	{
		return value != 0;
	}
	Char ByteValue::get_AsChar()
	{
		return value;
	}
	Byte ByteValue::get_AsByte()
	{
		return value;
	}
	SByte ByteValue::get_AsSByte()
	{
		return value;
	}
	Int16 ByteValue::get_AsInt16()
	{
		return value;
	}
	UInt16 ByteValue::get_AsUInt16()
	{
		return value;
	}
	Int32 ByteValue::get_AsInt32()
	{
		return value;
	}
	UInt32 ByteValue::get_AsUInt32()
	{
		return value;
	}
	Int64 ByteValue::get_AsInt64()
	{
		return value;
	}
	UInt64 ByteValue::get_AsUInt64()
	{
		return value;
	}
	Single ByteValue::get_AsSingle()
	{
		return value;
	}
	Double ByteValue::get_AsDouble()
	{
		return value;
	}
	Int32 ByteValue::CompareTo(Byte valueToCompare)
	{
		return value - valueToCompare;
	}
	Int32 ByteValue::CompareTo(Object* valueToCompare)
	{
		if (valueToCompare == nullptr) {
			return 1;
		}
		if (valueToCompare->GetRawDataType() != ByteType) {
			throw new ArgumentException();
		}
		return value - ((ByteValue*)valueToCompare)->value;
	}
	Boolean ByteValue::Equals(Object* valueToCompare)
	{
		if (valueToCompare->GetRawDataType() != ByteType) {
			return false;
		}
		return value == ((ByteValue*)valueToCompare)->value;
	}
	Boolean ByteValue::Equals(Byte valueToCompare)
	{
		return value == valueToCompare;
	}
	Int32 ByteValue::FormatString(Char* where, const Int32 whereSize)
	{
		return(swprintf(where, whereSize, L"%d", value));
	}
	Byte ByteValue::Parse(String* stringToParse)
	{
		UInt64	value = 0;
		Int32	sign = 0;
		if (!UInt64Value::TryParseInternal(stringToParse, value, sign))
			throw new FormatException();
		if (sign < 0 || value > MaxValue)
			throw new OverflowEception();
		return(value);
	}
	bool ByteValue::TryParse(String* stringToParse, Byte* result)
	{
		Boolean goodNumber = true;
		UInt64	value = 0;
		Int32	sign = 0;
		if (!UInt64Value::TryParseInternal(stringToParse, value, sign))
			goodNumber = false;
		if (sign < 0 || value > MaxValue)
			goodNumber = false;
		*result = (Byte)value;
		return(goodNumber);
	}
}
