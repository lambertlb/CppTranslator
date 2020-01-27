#include "DotnetTypes.h"

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
		return(swprintf(where, L"%lld", value));
	}
	Int64 Int64Value::Parse(String* stringToParse)
	{
		UInt64	value = 0;
		Int32	sign = 0;
		if (!UInt64Value::TryParseInternal(stringToParse, value, sign))
			throw new FormatException();
		return((Int64)value * sign);
	}
	bool Int64Value::TryParse(String* stringToParse, Int64* result)
	{
		Boolean goodNumber = true;
		UInt64	value = 0;
		Int32	sign = 0;
		if (!UInt64Value::TryParseInternal(stringToParse, value, sign))
			goodNumber = false;
		*result = (Int64)value * sign;
		return(goodNumber);
	}
}
