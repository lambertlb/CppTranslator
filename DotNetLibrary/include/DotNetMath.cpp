#pragma once
#include "DotnetTypes.h"
#include <math.h>
namespace DotnetLibrary
{
	DLL_EXPORT Double	Math::PI = 3.14159265358979;
	DLL_EXPORT Double	Math::E = 2.71828182845905;

	Double Math::Abs(Double v1)
	{
		return fabs(v1);
	}
	Double Math::Abs(Int16 v1)
	{
		return abs(v1);
	}
	Double Math::Abs(Int32 v1)
	{
		return abs(v1);
	}
	Double Math::Abs(Int64 v1)
	{
		return abs(v1);
	}
	Double Math::Abs(SByte v1)
	{
		return abs(v1);
	}
	Double Math::Abs(Single v1)
	{
		return fabs(v1);
	}
	Double Math::Acos(Double v1)
	{
		return acos(v1);
	}
	Double Math::Acosh(Double v1)
	{
		return acosh(v1);
	}
	Double Math::Asin(Double v1)
	{
		return asin(v1);
	}
	Double Math::Asinh(Double v1)
	{
		return asinh(v1);
	}
	Double Math::Atan(Double v1)
	{
		return atan(v1);
	}
	Double Math::Atan2(Double v1, Double v2)
	{
		return atan2(v1, v2);
	}
	Double Math::Atanh(Double v1)
	{
		return atanh(v1);
	}
	Int64 Math::BigMul(Int32 v1, Int32 v2)
	{
		return (Int64)v1 * v2;
	}
	Double Math::BitDecrement(Double x)
	{
		Int64 bits = DoubleValue::ToUInt64(x);

		if (((bits >> 32) & 0x7FF00000) >= 0x7FF00000) {
			// NaN returns NaN
			// -Infinity returns -Infinity
			// +Infinity returns double.MaxValue
			return (bits == 0x7FF0000000000000) ? DoubleValue::MaxValue : x;
		}

		if (bits == 0x0000000000000000) {
			// +0.0 returns -double.Epsilon
			return -DoubleValue::Epsilon;
		}

		// Negative values need to be incremented
		// Positive values need to be decremented

		bits += ((bits < 0) ? +1 : -1);
		return DoubleValue::ToDouble(bits);
	}
	Double Math::BitIncrement(Double x)
	{
		Int64 bits = DoubleValue::ToUInt64(x);

		if (((bits >> 32) & 0x7FF00000) >= 0x7FF00000) {
			// NaN returns NaN
			// -Infinity returns double.MinValue
			// +Infinity returns +Infinity
			return (bits == (Int64)(0xFFF0000000000000)) ? DoubleValue::MinValue : x;
		}

		if (bits == (Int64)(0x8000000000000000)) {
			// -0.0 returns double.Epsilon
			return DoubleValue::Epsilon;
		}

		// Negative values need to be decremented
		// Positive values need to be incremented

		bits += ((bits < 0) ? -1 : +1);
		return DoubleValue::ToDouble(bits);
	}
}
