#include "DotnetTypes.h"
#include <cwchar>

namespace DotnetLibrary
{
	DLL_EXPORT UInt32	UInt32Value::MaxValue = 4294967295;
	DLL_EXPORT UInt32	UInt32Value::MinValue = 0;

	Boolean UInt32Value::get_AsBoolean()
	{
		return value != 0;
	}
	Char UInt32Value::get_AsChar()
	{
		return (Char)value;
	}
	Byte UInt32Value::get_AsByte()
	{
		return (Byte)value;
	}
	SByte UInt32Value::get_AsSByte()
	{
		return (SByte)value;
	}
	Int16 UInt32Value::get_AsInt16()
	{
		return (Int16)value;
	}
	UInt16 UInt32Value::get_AsUInt16()
	{
		return (UInt16)value;
	}
	Int32 UInt32Value::get_AsInt32()
	{
		return (Int32)value;
	}
	UInt32 UInt32Value::get_AsUInt32()
	{
		return (UInt32)value;
	}
	Int64 UInt32Value::get_AsInt64()
	{
		return (Int64)value;
	}
	UInt64 UInt32Value::get_AsUInt64()
	{
		return (UInt64)value;
	}
	Single UInt32Value::get_AsSingle()
	{
		return (Single)value;
	}
	Double UInt32Value::get_AsDouble()
	{
		return (Double)value;
	}
	Int32 UInt32Value::CompareTo(UInt32 valueToCompare)
	{
		return value - valueToCompare;
	}
	Int32 UInt32Value::CompareTo(Object* valueToCompare)
	{
		if (valueToCompare == nullptr) {
			return 1;
		}
		if (valueToCompare->GetRawDataType() != UInt32Type) {
			throw new ArgumentException();
		}
		return value - ((UInt32Value*)valueToCompare)->value;
	}
	bool UInt32Value::Equals(Object* valueToCompare)
	{
		if (valueToCompare->GetRawDataType() != UInt32Type) {
			return false;
		}
		return value == ((UInt32Value*)valueToCompare)->value;
	}
	bool UInt32Value::Equals(UInt32 valueToCompare)
	{
		return value == valueToCompare;
	}
	Int32 UInt32Value::FormatString(Char* where, const Int32 whereSize)
	{
#ifdef __MINGW32__
		return(swprintf(where, L"%u", value));
#else
		return(swprintf(where, whereSize, L"%u", value));
#endif
	}
	UInt32 UInt32Value::Parse(String* stringToParse)
	{
		UInt64	value = 0;
		Int32	sign = 0;
		if (!UInt64Value::TryParseInternal(stringToParse, value, sign))
			throw new FormatException();
		if (value > MaxValue)
			throw new OverflowException();
		return((UInt32)value * sign);
	}
	bool UInt32Value::TryParse(String* stringToParse, UInt32* result)
	{
		Boolean goodNumber = true;
		UInt64	value = 0;
		Int32	sign = 0;
		if (!UInt64Value::TryParseInternal(stringToParse, value, sign))
			goodNumber = false;
		if (sign < 0 || value > MaxValue)
			goodNumber = false;
		*result = (UInt32)value;
		return(goodNumber);
	}
}
