#include "DotnetTypes.h"
#include <math.h>
#include <float.h>
#include <cwchar>

namespace DotnetLibrary
{
	DLL_EXPORT Double	DoubleValue::MaxValue = 1.797693134862315E+308;
	DLL_EXPORT Double	DoubleValue::MinValue = -1.797693134862315E+308;
	DLL_EXPORT Double	DoubleValue::Epsilon = 4.94065645841247E-324;
	DLL_EXPORT Double	DoubleValue::NaN = NAN;
	DLL_EXPORT Double	DoubleValue::PositiveInfinity = INFINITY;
	DLL_EXPORT Double	DoubleValue::NegativeInfinity = -INFINITY;
	Int16 DoubleValue::get_AsInt16()
	{
		return (Int16)value;
	}
	UInt16 DoubleValue::get_AsUInt16()
	{
		return (UInt16)value;
	}
	Int32 DoubleValue::get_AsInt32()
	{
		return (Int32)value;
	}
	UInt32 DoubleValue::get_AsUInt32()
	{
		return (UInt32)value;
	}
	Int64 DoubleValue::get_AsInt64()
	{
		return (Int64)value;
	}
	UInt64 DoubleValue::get_AsUInt64()
	{
		return (UInt64)value;
	}
	Single DoubleValue::get_AsSingle()
	{
		return (Single)value;
	}
	Double DoubleValue::get_AsDouble()
	{
		return value;
	}
	Int32 DoubleValue::CompareTo(Double valueToCompare)
	{
		if (value < valueToCompare) return -1;
		if (value > valueToCompare) return 1;
		if (value == valueToCompare) return 0;

		// At least one of the values is NaN.
		if (IsNaN(value))
			return IsNaN(valueToCompare) ? 0 : -1;
		else
			return 1;
	}
	Int32 DoubleValue::CompareTo(Object* valueToCompare)
	{
		if (valueToCompare == nullptr) {
			return 1;
		}
		if (valueToCompare->GetRawDataType() != DoubleType) {
			throw new ArgumentException();
		}
		return CompareTo(valueToCompare->get_AsDouble());
	}
	bool DoubleValue::Equals(Object* valueToCompare)
	{
		if (valueToCompare == nullptr) {
			return false;
		}
		if (valueToCompare->GetRawDataType() != DoubleType) {
			return false;
		}
		return Equals(valueToCompare->get_AsDouble());
	}
	bool DoubleValue::Equals(Double valueToCompare)
	{
		if (valueToCompare == value) {
			return true;
		}
		return IsNaN(valueToCompare) && IsNaN(value);
	}
	Boolean DoubleValue::IsFinite(Double d)
	{
		UInt64 bits = ToUInt64(d);
		return (bits & 0x7FFFFFFFFFFFFFFF) < 0x7FF0000000000000;
	}
	Boolean DoubleValue::IsInfinity(Double v)
	{
		UInt64 bits = ToUInt64(v);
		return (bits & 0x7FFFFFFFFFFFFFFF) == 0x7FF0000000000000;
	}
	Boolean DoubleValue::IsNaN(Double v)
	{
		return v != v;
	}
	Boolean DoubleValue::IsNegative(Double v)
	{
		if (IsNaN(v))
			return(true);
		Int64 bits = (Int64)ToUInt64(v);
		return(bits < 0);
	}
	Boolean DoubleValue::IsNegativeInfinity(Double v)
	{
		return v == NegativeInfinity;
	}
	Boolean DoubleValue::IsNormal(Double v)
	{
		if (IsNaN(v))
			return(false);
		UInt64 bits = ToUInt64(v);
		bits &= 0x7FFFFFFFFFFFFFFF;
		return (bits < 0x7FF0000000000000) && (bits != 0) && ((bits & 0x7FF0000000000000) != 0);
	}
	Boolean DoubleValue::IsPositiveInfinity(Double v)
	{
		return v == PositiveInfinity;
	}
	Boolean DoubleValue::IsSubnormal(Double v)
	{
		UInt64 bits = ToUInt64(v);
		bits &= 0x7FFFFFFFFFFFFFFF;
		return (bits < 0x7FF0000000000000) && (bits != 0) && ((bits & 0x7FF0000000000000) == 0);
	}
	Int32 DoubleValue::FormatString(Char* where, const Int32 whereSize)
	{
#ifdef __MINGW32__
		return(swprintf(where, L"%G", value));
#else
		return(swprintf(where, whereSize, L"%G", value));
#endif
	}
	Double DoubleValue::Modulus(Double v1, Double v2)
	{
		return fmod(v1, v2);
	}
	Double DoubleValue::Parse(String* stringToParse)
	{
		Double   rtn;
		swscanf(stringToParse->get_Buffer(), L"%lG", &rtn);
		return(rtn);
	}
	Boolean DoubleValue::TryParse(String* source, Double& result)
	{
		Boolean goodNumber = true;
		Double	value = 0;
		if (source == nullptr)
			return(false);
		goodNumber = TryParseInternal(source->get_Buffer(), source->get_Length(), value);
		result = value;
		return(goodNumber);
	}
	Boolean DoubleValue::TryParseInternal(String* source, Double& result)
	{
		if (source == nullptr)
			throw new ArgumentNullException();
		return(TryParseInternal(source->get_Buffer(), source->get_Length(), result));
	}
	Boolean DoubleValue::TryParseInternal(Char* source, Int32 sourceLength, Double& result)
	{
		result = 0;
		Boolean gotNumber = false;
		while (*source != 0 && sourceLength > 0) {
			if (!CharValue::IsWhiteSpace(*source))
				break;
			++source;
			--sourceLength;
		}
		Double   rtn;
		gotNumber = swscanf(source, L"%lG", &rtn) == 1;
		result = rtn;
		return(gotNumber);
	}
	Double DoubleValue::ToDouble(UInt64 v)
	{
		union
		{
			UInt64	uintData;
			Double	doubleData;
		}u;
		u.uintData = v;
		return(u.doubleData);
	}
	UInt64 DoubleValue::ToUInt64(Double v)
	{
		union
		{
			UInt64	uintData;
			Double	doubleData;
		}u;
		u.doubleData = v;
		return(u.uintData);
	}
}
