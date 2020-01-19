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
	Double Math::Cbrt(Double x)
	{
		return cbrt(x);
	}
	Double Math::Ceiling(Double v1)
	{
		return ceil(v1);
	}
	Byte Math::Clamp(Byte value, Byte min, Byte max)
	{
		if (min > max) {
			throw new ThrowMinMaxException();
		}
		if (value < min) {
			return min;
		}
		else if (value > max) {
			return max;
		}
		return value;
	}
	UInt16 Math::Clamp(UInt16 value, UInt16 min, UInt16 max)
	{
		if (min > max) {
			throw new ThrowMinMaxException();
		}
		if (value < min) {
			return min;
		}
		else if (value > max) {
			return max;
		}
		return value;
	}
	UInt32 Math::Clamp(UInt32 value, UInt32 min, UInt32 max)
	{
		if (min > max) {
			throw new ThrowMinMaxException();
		}
		if (value < min) {
			return min;
		}
		else if (value > max) {
			return max;
		}
		return value;
	}
	UInt64 Math::Clamp(UInt64 value, UInt64 min, UInt64 max)
	{
		if (min > max) {
			throw new ThrowMinMaxException();
		}
		if (value < min) {
			return min;
		}
		else if (value > max) {
			return max;
		}
		return value;
	}
	Double Math::CopySign(Double x, Double y)
	{
		// This method is required to work for all inputs,
		 // including NaN, so we operate on the raw bits.

		Int64 xbits = DoubleValue::ToUInt64(x);
		Int64 ybits = DoubleValue::ToUInt64(y);

		// If the sign bits of x and y are not the same,
		// flip the sign bit of x and return the new value;
		// otherwise, just return x

		if ((xbits ^ ybits) < 0) {
			return DoubleValue::ToDouble(xbits ^ Int64Value::MinValue);
		}

		return x;
	}
	Double Math::Clamp(Double value, Double min, Double max)
	{
		if (min > max) {
			throw new ThrowMinMaxException();
		}
		if (value < min) {
			return min;
		}
		else if (value > max) {
			return max;
		}
		return value;
	}
	Int16 Math::Clamp(Int16 value, Int16 min, Int16 max)
	{
		if (min > max) {
			throw new ThrowMinMaxException();
		}
		if (value < min) {
			return min;
		}
		else if (value > max) {
			return max;
		}
		return value;
	}
	Int32 Math::Clamp(Int32 value, Int32 min, Int32 max)
	{
		if (min > max) {
			throw new ThrowMinMaxException();
		}
		if (value < min) {
			return min;
		}
		else if (value > max) {
			return max;
		}
		return value;
	}
	Int64 Math::Clamp(Int64 value, Int64 min, Int64 max)
	{
		if (min > max) {
			throw new ThrowMinMaxException();
		}
		if (value < min) {
			return min;
		}
		else if (value > max) {
			return max;
		}
		return value;
	}
	SByte Math::Clamp(SByte value, SByte min, SByte max)
	{
		if (min > max) {
			throw new ThrowMinMaxException();
		}
		if (value < min) {
			return min;
		}
		else if (value > max) {
			return max;
		}
		return value;
	}
	Single Math::Clamp(Single value, Single min, Single max)
	{
		if (min > max) {
			throw new ThrowMinMaxException();
		}
		if (value < min) {
			return min;
		}
		else if (value > max) {
			return max;
		}
		return value;
	}
	Double Math::Cos(Double v1)
	{
		return cos(v1);
	}
	Double Math::Cosh(Double v1)
	{
		return cosh(v1);
	}
	Int32 Math::DivRem(Int32 a, Int32 b, Int32* result)
	{
		Int32 div = a / b;
		*result = a - (div * b);
		return div;
	}
	Int64 Math::DivRem(Int64 a, Int64 b, Int64* result)
	{
		Int32 div = a / b;
		*result = a - (div * b);
		return div;
	}
	Double Math::Exp(Double v1)
	{
		return exp(v1);
	}
	Double Math::Floor(Double v1)
	{
		return floor(v1);
	}
	Double Math::FusedMultiplyAdd(Double x, Double y, Double z)
	{
		return (x * y) + z;
	}
	Double Math::IEEERemainder(Double x, Double y)
	{
		return remainder(x, y);
	}
	Int32 Math::ILogB(Double x)
	{
		return logb(x);
	}
	Double Math::Log(Double v1)
	{
		return log(v1);
	}
	Double Math::Log(Double a, Double newBase)
	{
		if (DoubleValue::IsNaN(a)) {
			return a; // IEEE 754-2008: NaN payload must be preserved
		}
		if (DoubleValue::IsNaN(newBase)) {
			return newBase; // IEEE 754-2008: NaN payload must be preserved
		}
		if (newBase == 1) {
			return DoubleValue::NaN;
		}
		if ((a != 1) && ((newBase == 0) || DoubleValue::IsPositiveInfinity(newBase))) {
			return DoubleValue::NaN;
		}
		return Log(a) / Log(newBase);
	}
	Double Math::Log10(Double v1)
	{
		return log10(v1);
	}
	Double Math::Log2(double x)
	{
		return log2(x);
	}
}
