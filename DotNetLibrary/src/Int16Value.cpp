#include "DotnetTypes.h"
#include <cwchar>
namespace DotnetLibrary
{
	DLL_EXPORT Int16	Int16Value::MaxValue = 32767;
	DLL_EXPORT Int16	Int16Value::MinValue = -32768;

	Boolean Int16Value::get_AsBoolean()
	{
		return value != 0;
	}
	Char Int16Value::get_AsChar()
	{
		return (Char)value;
	}
	Byte Int16Value::get_AsByte()
	{
		return (Byte)value;
	}
	SByte Int16Value::get_AsSByte()
	{
		return (SByte)value;
	}
	Int16 Int16Value::get_AsInt16()
	{
		return (Int16)value;
	}
	UInt16 Int16Value::get_AsUInt16()
	{
		return (UInt16)value;
	}
	Int32 Int16Value::get_AsInt32()
	{
		return (Int32)value;
	}
	UInt32 Int16Value::get_AsUInt32()
	{
		return (UInt32)value;
	}
	Int64 Int16Value::get_AsInt64()
	{
		return (Int64)value;
	}
	UInt64 Int16Value::get_AsUInt64()
	{
		return (UInt64)value;
	}
	Single Int16Value::get_AsSingle()
	{
		return (Single)value;
	}
	Double Int16Value::get_AsDouble()
	{
		return (Double)value;
	}
	Int32 Int16Value::CompareTo(Int16 valueToCompare)
	{
		return value - valueToCompare;
	}
	Int32 Int16Value::CompareTo(Object* valueToCompare)
	{
		if (valueToCompare == nullptr) {
			return 1;
		}
		if (valueToCompare->GetRawDataType() != Int16Type) {
			throw new ArgumentException();
		}
		return value - ((Int16Value*)valueToCompare)->value;
	}
	bool Int16Value::Equals(Object* valueToCompare)
	{
		if (valueToCompare->GetRawDataType() != Int16Type) {
			return false;
		}
		return value == ((Int16Value*)valueToCompare)->value;
	}
	bool Int16Value::Equals(Int16 valueToCompare)
	{
		return value == valueToCompare;
	}
	Int32 Int16Value::FormatString(Char* where, const Int32 whereSize)
	{
#ifdef __MINGW32__
		return(swprintf(where, L"%d", value));
#else
		return(swprintf(where, whereSize, L"%d", value));
#endif
	}
	Int16 Int16Value::Parse(String* stringToParse)
	{
		UInt64	value = 0;
		Int32	sign = 0;
		if (!UInt64Value::TryParseInternal(stringToParse, value, sign))
			throw new FormatException();
		if (sign > 0 && value > MaxValue)
			throw new OverflowException();
		if (sign < 0 && (Int64)value < MinValue)
			throw new OverflowException();
		return((Int16)value * sign);
	}
	bool Int16Value::TryParse(String* stringToParse, Int16& result)
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
		result = (Int16)value * sign;
		return(goodNumber);
	}
}
