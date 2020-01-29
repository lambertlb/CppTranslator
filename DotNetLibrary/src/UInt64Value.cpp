#include "DotnetTypes.h"
#include <cwchar>

namespace DotnetLibrary
{
	DLL_EXPORT UInt64	UInt64Value::MaxValue = 0XFFFFFFFFFFFFFFFF;
	DLL_EXPORT UInt64	UInt64Value::MinValue = 0;

	Boolean UInt64Value::get_AsBoolean()
	{
		return value != 0;
	}
	Char UInt64Value::get_AsChar()
	{
		return (Char)value;
	}
	Byte UInt64Value::get_AsByte()
	{
		return (Byte)value;
	}
	SByte UInt64Value::get_AsSByte()
	{
		return (SByte)value;
	}
	Int16 UInt64Value::get_AsInt16()
	{
		return (Int16)value;
	}
	UInt16 UInt64Value::get_AsUInt16()
	{
		return (UInt16)value;
	}
	Int32 UInt64Value::get_AsInt32()
	{
		return (Int32)value;
	}
	UInt32 UInt64Value::get_AsUInt32()
	{
		return (UInt32)value;
	}
	Int64 UInt64Value::get_AsInt64()
	{
		return (Int64)value;
	}
	UInt64 UInt64Value::get_AsUInt64()
	{
		return (UInt64)value;
	}
	Single UInt64Value::get_AsSingle()
	{
		return (Single)value;
	}
	Double UInt64Value::get_AsDouble()
	{
		return (Double)value;
	}
	Int32 UInt64Value::CompareTo(UInt64 valueToCompare)
	{
		return value - valueToCompare;
	}
	Int32 UInt64Value::CompareTo(Object* valueToCompare)
	{
		if (valueToCompare == nullptr) {
			return 1;
		}
		if (valueToCompare->GetRawDataType() != UInt64Type) {
			throw new ArgumentException();
		}
		return value - ((UInt64Value*)valueToCompare)->value;
	}
	bool UInt64Value::Equals(Object* valueToCompare)
	{
		if (valueToCompare->GetRawDataType() != UInt64Type) {
			return false;
		}
		return value == ((UInt64Value*)valueToCompare)->value;
	}
	bool UInt64Value::Equals(UInt64 valueToCompare)
	{
		return value == valueToCompare;
	}
	Int32 UInt64Value::FormatString(Char* where, const Int32 whereSize)
	{
#ifdef __MINGW32__
		return(swprintf(where, L"%llu", value));
#else
		return(swprintf(where, whereSize, L"%llu", value));
#endif
	}
	UInt64 UInt64Value::Parse(String* stringToParse)
	{
		UInt64	value = 0;
		Int32	sign = 0;
		if (!UInt64Value::TryParseInternal(stringToParse, value, sign))
			throw new FormatException();
		if (value > MaxValue)
			throw new OverflowException();
		return((UInt64)value);
	}
	bool UInt64Value::TryParse(String* stringToParse, UInt64* result)
	{
		Boolean goodNumber = true;
		UInt64	value = 0;
		Int32	sign = 0;
		if (!UInt64Value::TryParseInternal(stringToParse, value, sign))
			goodNumber = false;
		if (sign < 0 || value > MaxValue)
			goodNumber = false;
		*result = (UInt64)value;
		return(goodNumber);
	}
	Boolean UInt64Value::TryParseInternal(String* source, UInt64& result, Int32& sign)
	{
		if (source == nullptr)
			throw new ArgumentNullException();
		return(TryParseInternal(source->get_Buffer(), source->get_Length(), result, sign));
	}
	Boolean UInt64Value::TryParseInternal(Char* source, Int32 sourceLength, UInt64& result, Int32& sign)
	{
		result = 0;
		sign = 1;
		Boolean gotNumber = false;
		while (*source != 0 && sourceLength > 0) {
			if (!CharValue::IsWhiteSpace(*source))
				break;
			++source;
			--sourceLength;
		}
		if (*source != 0 && sourceLength > 0) {
			if (*source == L'-') {
				sign = -1;
				++source;
				--sourceLength;
			}
			else if (*source == L'+') {
				++source;
				--sourceLength;
			}
		}
		while (*source != 0 && sourceLength > 0) {
			if (!CharValue::IsDigit(*source))
				break;
			result = 10 * result + *source - '0';
			++source;
			--sourceLength;
			gotNumber = true;
		}
		if (sourceLength > 0 && !CharValue::IsWhiteSpace(*source))
			gotNumber = false;
		return(gotNumber);
	}
}
