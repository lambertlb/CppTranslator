#include "DotnetTypes.h"
#include <math.h>
#include <float.h>
#include <cwchar>

namespace DotnetLibrary
{
	DLL_EXPORT Single	SingleValue::MaxValue = 3.40282346638528859e+38;
	DLL_EXPORT Single	SingleValue::MinValue = -3.40282346638528859e+38;
	DLL_EXPORT Single	SingleValue::Epsilon = 1.401298E-45F;
	DLL_EXPORT Single	SingleValue::NaN = NAN;
	DLL_EXPORT Single	SingleValue::PositiveInfinity = INFINITY;
	DLL_EXPORT Single	SingleValue::NegativeInfinity = -INFINITY;
	//DLL_EXPORT Single	FloatValue::MaxValue = 3.40282346638528859e+38;
	//DLL_EXPORT Single	FloatValue::MinValue = -3.40282346638528859e+38;
	//DLL_EXPORT Single	FloatValue::Epsilon = FLT_EPSILON;
	//DLL_EXPORT Single	FloatValue::NaN = NAN;
	//DLL_EXPORT Single	FloatValue::PositiveInfinity = INFINITY;
	//DLL_EXPORT Single	FloatValue::NegativeInfinity = -INFINITY;

	Int16 SingleValue::get_AsInt16()
	{
		return (Int16)value;
	}
	UInt16 SingleValue::get_AsUInt16()
	{
		return (UInt16)value;
	}
	Int32 SingleValue::get_AsInt32()
	{
		return (Int32)value;
	}
	UInt32 SingleValue::get_AsUInt32()
	{
		return (UInt32)value;
	}
	Int64 SingleValue::get_AsInt64()
	{
		return (Int64)value;
	}
	UInt64 SingleValue::get_AsUInt64()
	{
		return (UInt64)value;
	}
	Single SingleValue::get_AsSingle()
	{
		return (Single)value;
	}
	Double SingleValue::get_AsDouble()
	{
		return value;
	}
	Int32 SingleValue::CompareTo(Single valueToCompare)
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
	Int32 SingleValue::CompareTo(Object* valueToCompare)
	{
		if (valueToCompare == nullptr) {
			return 1;
		}
		if (valueToCompare->GetRawDataType() != SingleType) {
			throw new ArgumentException();
		}
		return CompareTo(valueToCompare->get_AsSingle());
	}
	bool SingleValue::Equals(Object* valueToCompare)
	{
		if (valueToCompare == nullptr) {
			return false;
		}
		if (valueToCompare->GetRawDataType() != SingleType) {
			return false;
		}
		return Equals(valueToCompare->get_AsSingle());
	}
	bool SingleValue::Equals(Single valueToCompare)
	{
		if (valueToCompare == value) {
			return true;
		}
		return IsNaN(valueToCompare) && IsNaN(value);
	}
	Boolean SingleValue::IsFinite(Single d)
	{
		UInt32 bits = ToUInt32(d);
		return (bits & 0x7FFFFFFF) < 0x7F800000;
	}
	Boolean SingleValue::IsInfinity(Single v)
	{
		UInt32 bits = ToUInt32(v);
		return (bits & 0x7FFFFFFF) == 0x7F800000;
	}
	Boolean SingleValue::IsNaN(Single v)
	{
		return v != v;
	}
	Boolean SingleValue::IsNegative(Single v)
	{
		if (IsNaN(v))
			return(true);
		Int64 bits = (Int32)ToUInt32(v);
		return(bits < 0);
	}
	Boolean SingleValue::IsNegativeInfinity(Single v)
	{
		return v == NegativeInfinity;
	}
	Boolean SingleValue::IsNormal(Single v)
	{
		if (IsNaN(v))
			return(false);
		UInt32 bits = ToUInt32(v);
		bits &= 0x7FFFFFFF;
		return (bits < 0x7F800000) && (bits != 0) && ((bits & 0x7F800000) != 0);
	}
	Boolean SingleValue::IsPositiveInfinity(Single v)
	{
		return v == PositiveInfinity;
	}
	Boolean SingleValue::IsSubnormal(Single v)
	{
		UInt32 bits = ToUInt32(v);
		bits &= 0x7FFFFFFF;
		return (bits < 0x7F800000) && (bits != 0) && ((bits & 0x7F800000) == 0);
	}
	Int32 SingleValue::FormatString(Char* where, const Int32 whereSize)
	{
#ifdef __MINGW32__
		return(swprintf(where, L"%G", value));
#else
		return(swprintf(where, whereSize, L"%G", value));
#endif
	}
	Single SingleValue::Modulus(Single v1, Single v2)
	{
		return fmod(v1, v2);
	}
	Single SingleValue::Parse(String* stringToParse)
	{
		Single   rtn;
		swscanf(stringToParse->get_Buffer(), L"%G", &rtn);
		return(rtn);
	}
	Boolean SingleValue::TryParse(String* source, Single& result)
	{
		Boolean goodNumber = true;
		Single	value = 0;
		if (source == nullptr)
			return(false);
		goodNumber = TryParseInternal(source->get_Buffer(), source->get_Length(), value);
		result = value;
		return(goodNumber);
	}
	Boolean SingleValue::TryParseInternal(String* source, Single& result)
	{
		if (source == nullptr)
			throw new ArgumentNullException();
		return(TryParseInternal(source->get_Buffer(), source->get_Length(), result));
	}
	Boolean SingleValue::TryParseInternal(Char* source, Int32 sourceLength, Single& result)
	{
		result = 0;
		Boolean gotNumber = false;
		while (*source != 0 && sourceLength > 0) {
			if (!CharValue::IsWhiteSpace(*source))
				break;
			++source;
			--sourceLength;
		}
		Single   rtn;
		gotNumber = swscanf(source, L"%G", &rtn) == 1;
		result = rtn;
		return(gotNumber);
	}
	Single SingleValue::ToSingle(UInt32 v)
	{
		union
		{
			UInt32	uintData;
			Single	singleData;
		}u;
		u.uintData = v;
		return(u.singleData);
	}
	UInt32 SingleValue::ToUInt32(Single v)
	{
		union
		{
			UInt32	uintData;
			Single	singleData;
		}u;
		u.singleData = v;
		return(u.uintData);
	}
}
