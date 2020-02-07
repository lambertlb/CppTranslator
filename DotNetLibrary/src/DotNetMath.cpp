#include "DotnetTypes.h"
#include <math.h>
namespace DotnetLibrary
{
	DLL_EXPORT Double	Math::PI = 3.14159265358979;
	DLL_EXPORT Double	Math::E = 2.71828182845905;
	const UInt64		ExponentMask = 0x7FF0000000000000;
	const Int32			ExponentShift = 52;
	const Int32			ShiftedExponentMask = (Int32)(ExponentMask >> ExponentShift);
	const UInt64		SignificandMask = 0x000FFFFFFFFFFFFF;
	const Int32			maxRoundingDigits = 15;
	const Double		doubleRoundLimit = 1e+16;
	Double				roundPower10Double[] = {
		1E0, 1E1, 1E2, 1E3, 1E4, 1E5, 1E6, 1E7, 1E8,
			1E9, 1E10, 1E11, 1E12, 1E13, 1E14, 1E15
	};

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
		if (DoubleValue::IsNaN(y))
			y = -0.0;
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
	Int64 Math::Divide(Int64 v1, Int64 v2)
	{
		if (v2 == 0)
			throw new DivideByZeroException();
		return v1 / v2;
	}
	Double Math::Divide(Double v1, Double v2)
	{
		if (v2 == 0) {
			if (v1 == 0)
				return(DoubleValue::NaN);
			return(DoubleValue::PositiveInfinity);
		}
		return v1 / v2;
	}
	Int32 Math::DivRem(Int32 a, Int32 b, Int32& result)
	{
		if (b == 0)
			throw new DivideByZeroException();
		Int32 div = a / b;
		result = a - (div * b);
		return div;
	}
	Int64 Math::DivRem(Int64 a, Int64 b, Int64& result)
	{
		if (b == 0)
			throw new DivideByZeroException();
		Int32 div = a / b;
		result = a - (div * b);
		return div;
	}
	Double Math::Exp(Double v1)
	{
		return exp(v1);
	}
	Int32 Math::ExtractExponentFromBits(UInt64 bits)
	{
		return (Int32)(bits >> ExponentShift)& ShiftedExponentMask;
	}
	UInt64 Math::ExtractSignificandFromBits(UInt64 bits)
	{
		return bits & SignificandMask;
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
	Byte Math::Max(Byte val1, Byte val2)
	{
		return (val1 >= val2) ? val1 : val2;
	}
	Double Math::Max(Double val1, Double val2)
	{
		if ((val1 > val2) || DoubleValue::IsNaN(val1)) {
			return val1;
		}
		if (val1 == val2) {
			return DoubleValue::IsNegative(val1) ? val2 : val1;
		}
		return val2;
	}
	Int16 Math::Max(Int16 val1, Int16 val2)
	{
		return (val1 >= val2) ? val1 : val2;
	}
	Int32 Math::Max(Int32 val1, Int32 val2)
	{
		return (val1 >= val2) ? val1 : val2;
	}
	Int64 Math::Max(Int64 val1, Int64 val2)
	{
		return (val1 >= val2) ? val1 : val2;
	}
	SByte Math::Max(SByte val1, SByte val2)
	{
		return (val1 >= val2) ? val1 : val2;
	}
	Single Math::Max(Single val1, Single val2)
	{
		if ((val1 > val2) || SingleValue::IsNaN(val1)) {
			return val1;
		}
		if (val1 == val2) {
			return DoubleValue::IsNegative(val1) ? val2 : val1;
		}
		return val2;
	}
	UInt16 Math::Max(UInt16 val1, UInt16 val2)
	{
		return (val1 >= val2) ? val1 : val2;
	}
	UInt32 Math::Max(UInt32 val1, UInt32 val2)
	{
		return (val1 >= val2) ? val1 : val2;
	}
	UInt64 Math::Max(UInt64 val1, UInt64 val2)
	{
		return (val1 >= val2) ? val1 : val2;
	}
	Double Math::MaxMagnitude(Double x, Double y)
	{
		Double ax = Abs(x);
		Double ay = Abs(y);

		if ((ax > ay) || DoubleValue::IsNaN(ax)) {
			return x;
		}
		if (ax == ay) {
			return DoubleValue::IsNegative(x) ? y : x;
		}
		return y;
	}

	Byte Math::Min(Byte val1, Byte val2)
	{
		return (val1 <= val2) ? val1 : val2;
	}
	Double Math::Min(Double val1, Double val2)
	{
		if ((val1 < val2) || DoubleValue::IsNaN(val1)) {
			return val1;
		}
		if (val1 == val2) {
			return DoubleValue::IsNegative(val1) ? val1 : val2;
		}
		return val2;
	}
	Int16 Math::Min(Int16 val1, Int16 val2)
	{
		return (val1 <= val2) ? val1 : val2;
	}
	Int32 Math::Min(Int32 val1, Int32 val2)
	{
		return (val1 <= val2) ? val1 : val2;
	}
	Int64 Math::Min(Int64 val1, Int64 val2)
	{
		return (val1 <= val2) ? val1 : val2;
	}
	SByte Math::Min(SByte val1, SByte val2)
	{
		return (val1 <= val2) ? val1 : val2;
	}
	Single Math::Min(Single val1, Single val2)
	{
		if ((val1 < val2) || SingleValue::IsNaN(val1)) {
			return val1;
		}
		if (val1 == val2) {
			return DoubleValue::IsNegative(val1) ? val1 : val2;
		}
		return val2;
	}
	UInt16 Math::Min(UInt16 val1, UInt16 val2)
	{
		return (val1 <= val2) ? val1 : val2;
	}
	UInt32 Math::Min(UInt32 val1, UInt32 val2)
	{
		return (val1 <= val2) ? val1 : val2;
	}
	UInt64 Math::Min(UInt64 val1, UInt64 val2)
	{
		return (val1 <= val2) ? val1 : val2;
	}
	Double Math::MinMagnitude(Double x, Double y)
	{
		Double ax = Abs(x);
		Double ay = Abs(y);

		if ((ax < ay) || DoubleValue::IsNaN(ax)) {
			return x;
		}
		if (ax == ay) {
			return DoubleValue::IsNegative(x) ? x : y;
		}
		return y;
	}
	Double Math::Pow(Double x, Double y)
	{
		return pow(x, y);
	}

	Double Math::Round(Double a)
	{
		UInt64 bits = DoubleValue::ToUInt64(a);
		int exponent = ExtractExponentFromBits(bits);

		if (exponent <= 0x03FE) {
			if ((bits << 1) == 0) {
				return a;
			}
			Double result = ((exponent == 0x03FE) && (ExtractSignificandFromBits(bits) != 0)) ? 1.0 : 0.0;
			return CopySign(result, a);
		}
		if (exponent >= 0x0433) {
			return a;
		}
		UInt64 lastBitMask = (UInt64)1 << (Int64)(0x0433L - (Int64)exponent);
		UInt64 roundBitsMask = lastBitMask - 1;
		bits += lastBitMask >> 1;
		if ((bits & roundBitsMask) == 0) {
			bits &= ~lastBitMask;
		}
		else {
			bits &= ~roundBitsMask;
		}
		return DoubleValue::ToDouble((Int64)bits);
	}

	Double Math::Round(Double value, Int32 digits)
	{
		return Round(value, digits, ToEven);
	}

	Double Math::Round(Double value, Int32 digits, MidpointRounding mode)
	{
		if ((digits < 0) || (digits > maxRoundingDigits)) {
			throw new ArgumentOutOfRangeException();
		}
		if (mode < ToEven || mode > ToPositiveInfinity) {
			throw new ArgumentException();
		}
		if (Abs(value) < doubleRoundLimit) {
			Double power10 = roundPower10Double[digits];
			value *= power10;
			switch (mode) {
			case ToEven:
			{
				value = Round(value);
				break;
			}
			case AwayFromZero:
			{
				Double fraction = modf(value, &value);

				if (Abs(fraction) >= 0.5) {
					value += Sign(fraction);
				}
				break;
			}
			case ToZero:
			{
				value = Truncate(value);
				break;
			}
			case ToNegativeInfinity:
			{
				value = Floor(value);
				break;
			}
			case ToPositiveInfinity:
			{
				value = Ceiling(value);
				break;
			}
			default:
			{
				throw new ArgumentException();
			}
			}
			value /= power10;
		}
		return value;
	}

	Double Math::ScaleB(Double x, Int32 n)
	{
		return scalbn(x, n);
	}

	Int32 Math::Sign(Double value)
	{
		if (value < 0) {
			return -1;
		}
		else if (value > 0) {
			return 1;
		}
		else if (value == 0) {
			return 0;
		}
		throw new ArithmeticException();
	}

	Int32 Math::Sign(Int16 value)
	{
		return Sign((Int32)value);
	}

	Int32 Math::Sign(Int32 value)
	{
		return value >> 31 | (Int32)((UInt32)-value >> 31);
	}

	Int32 Math::Sign(Int64 value)
	{
		return (Int32)(value >> 63 | (long)((UInt64)-value >> 63));
	}

	Int32 Math::Sign(SByte value)
	{
		return Sign((Int32)value);
	}

	Int32 Math::Sign(Single value)
	{
		if (value < 0) {
			return -1;
		}
		else if (value > 0) {
			return 1;
		}
		else if (value == 0) {
			return 0;
		}
		throw new ArithmeticException();
	}

	Double Math::Sin(Double value)
	{
		return sin(value);
	}

	Double Math::Sinh(Double value)
	{
		return sinh(value);
	}

	Double Math::Sqrt(Double value)
	{
		return sqrt(value);
	}

	Double Math::Tan(Double value)
	{
		return tan(value);
	}

	Double Math::Tanh(Double value)
	{
		return tanh(value);
	}

	Double Math::Truncate(Double value)
	{
		return trunc(value);
	}

}
