// Copyright (c) 2019 LLambert
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this
// software and associated documentation files (the "Software"), to deal in the Software
// without restriction, including without limitation the rights to use, copy, modify, merge,
// publish, distribute, sub-license, and/or sell copies of the Software, and to permit persons
// to whom the Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or
// substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
// INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
// PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
// FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
// OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	/**
	 * Specifies how mathematical rounding methods should process a number that is midway between two numbers
	 */
	enum MidpointRounding
	{
		ToEven = 0,            //!< ToEven
		AwayFromZero = 1,      //!< AwayFromZero
		ToZero = 2,            //!< ToZero
		ToNegativeInfinity = 3,            //!< ToNegativeInfinity
		ToPositiveInfinity = 4 //!< ToPositiveInfinity
	};
	/**
	 * Provides constants and static methods for trigonometric, logarithmic, and other common mathematical functions
	 */
	class DLL_EXPORT Math
	{
	public:
		/**
		 * Absolute value
		 * @param v1 value to use
		 * @return Absolute value
		 */
		static Double Abs(Double v1);
		/**
		 * Absolute value
		 * @param v1 value to use
		 * @return Absolute value
		 */
		static Double Abs(Int16 v1);
		/**
		 * Absolute value
		 * @param v1 value to use
		 * @return Absolute value
		 */
		static Double Abs(Int32 v1);
		/**
		 * Absolute value
		 * @param v1 value to use
		 * @return Absolute value
		 */
		static Double Abs(Int64 v1);
		/**
		 * Absolute value
		 * @param v1 value to use
		 * @return Absolute value
		 */
		static Double Abs(SByte v1);
		/**
		 * Absolute value
		 * @param v1 value to use
		 * @return Absolute value
		 */
		static Double Abs(Single v1);
		/**
		 * Cosine of number
		 * @param v1 value to use
		 * @return Cosine of number
		 */
		static Double Acos(Double v1);
		/**
		 * hyperbolic Cosine of number
		 * @param v1 value to use
		 * @return hyperbolic Cosine of number
		 */
		static Double Acosh(Double v1);
		/**
		 * Sine of number
		 * @param v1 value to use
		 * @return Sine of number
		 */
		static Double Asin(Double v1);
		/**
		 * hyperbolic Sine of number
		 * @param v1 value to use
		 * @return hyperbolic Sine of number
		 */
		static Double Asinh(Double v1);
		/**
		 * Tangent of number
		 * @param v1 value to use
		 * @return Tangent of number
		 */
		static Double Atan(Double v1);
		/**
		 * Tangent of number as quotient
		 * @param v1 value to use
		 * @return Tangent of number
		 */
		static Double Atan2(Double v1, Double v2);
		/**
		 * hyperbolic Tangent of number
		 * @param v1 value to use
		 * @return hyperbolic Tangent of number
		 */
		static Double Atanh(Double v1);
		/**
		 * Produces the full product of two 32-bit numbers.
		 * @param v1 value 1
		 * @param v2 value 2
		 * @return product of two numbers
		 */
		static Int64 BigMul(Int32 v1, Int32 v2);
		/**
		 * smallest value that compares less than x
		 * @param x value to compare
		 * @return value that compares less than x
		 */
		static Double BitDecrement(Double x);
		/**
		 * largest value that compares greater than x
		 * @param x value to compare
		 * @return value that compares greater than x
		 */
		static Double BitIncrement(Double x);
		/**
		 * Cube root of value
		 * @param x value to use
		 * @return Cube Root
		 */
		static Double Cbrt(Double x);
		/**
		 * smallest integral value greater than or equal to the
		 * @param v1 value to use
		 * @return smallest integral value greater than or equal to the
		 */
		static Double Ceiling(Double v1);
		/**
		 * value clamped to the inclusive range of min and max
		 * @param value to clamp
		 * @param min clamp
		 * @param max clamp
		 * @return value clamped to the inclusive range of min and max
		 */
		static Byte Clamp(Byte value, Byte min, Byte max);
		/**
		 * value clamped to the inclusive range of min and max
		 * @param value to clamp
		 * @param min clamp
		 * @param max clamp
		 * @return value clamped to the inclusive range of min and max
		 */
		static Double Clamp(Double value, Double min, Double max);
		/**
		 * value clamped to the inclusive range of min and max
		 * @param value to clamp
		 * @param min clamp
		 * @param max clamp
		 * @return value clamped to the inclusive range of min and max
		 */
		static Int16 Clamp(Int16 value, Int16 min, Int16 max);
		/**
		 * value clamped to the inclusive range of min and max
		 * @param value to clamp
		 * @param min clamp
		 * @param max clamp
		 * @return value clamped to the inclusive range of min and max
		 */
		static Int32 Clamp(Int32 value, Int32 min, Int32 max);
		/**
		 * value clamped to the inclusive range of min and max
		 * @param value to clamp
		 * @param min clamp
		 * @param max clamp
		 * @return value clamped to the inclusive range of min and max
		 */
		static Int64 Clamp(Int64 value, Int64 min, Int64 max);
		/**
		 * value clamped to the inclusive range of min and max
		 * @param value to clamp
		 * @param min clamp
		 * @param max clamp
		 * @return value clamped to the inclusive range of min and max
		 */
		static SByte Clamp(SByte value, SByte min, SByte max);
		/**
		 * value clamped to the inclusive range of min and max
		 * @param value to clamp
		 * @param min clamp
		 * @param max clamp
		 * @return value clamped to the inclusive range of min and max
		 */
		static Single Clamp(Single value, Single min, Single max);
		/**
		 * value clamped to the inclusive range of min and max
		 * @param value to clamp
		 * @param min clamp
		 * @param max clamp
		 * @return value clamped to the inclusive range of min and max
		 */
		static UInt16 Clamp(UInt16 value, UInt16 min, UInt16 max);
		/**
		 * value clamped to the inclusive range of min and max
		 * @param value to clamp
		 * @param min clamp
		 * @param max clamp
		 * @return value clamped to the inclusive range of min and max
		 */
		static UInt32 Clamp(UInt32 value, UInt32 min, UInt32 max);
		/**
		 * value clamped to the inclusive range of min and max
		 * @param value to clamp
		 * @param min clamp
		 * @param max clamp
		 * @return value clamped to the inclusive range of min and max
		 */
		static UInt64 Clamp(UInt64 value, UInt64 min, UInt64 max);
		/**
		 * value with the magnitude of x and the sign of y
		 * @param x magnitude is used in the result
		 * @param y sign is the used in the result
		 * @return value with the magnitude of x and the sign of y
		 */
		static Double CopySign(Double x, Double y);
		/**
		 * Cosine root of value
		 * @param x value to use
		 * @return Cosine of value
		 */
		static Double Cos(Double v1);
		/**
		 * hyperbolic Cosine root of value
		 * @param x value to use
		 * @return hyperbolic Cosine of value
		 */
		static Double Cosh(Double v1);
		/**
		 * Dive two values and check for divide by zero
		 * @param v1 value 1
		 * @param v2 value 2
		 * @return v1 divided by v2 throw DivideByZero if appropriate
		 */
		static Int64 Divide(Int64 v1, Int64 v2);
		/**
		 * Dive two values and check for divide by zero
		 * @param v1 value 1
		 * @param v2 value 2
		 * @return v1 divided by v2 throw DivideByZero if appropriate
		 */
		static Double Divide(Double v1, Double v2);
		/**
		 * quotient of two numbers and also returns the remainder in an output parameter
		 * @param a value 1
		 * @param b value 2
		 * @param result quotient
		 * @return remainder
		 */
		static Int32 DivRem(Int32 a, Int32 b, Int32& result);
		/**
		 * quotient of two numbers and also returns the remainder in an output parameter
		 * @param a value 1
		 * @param b value 2
		 * @param result quotient
		 * @return remainder
		 */
		static Int64 DivRem(Int64 a, Int64 b, Int64& result);
		/**
		 * Value raised to the specified power.
		 * @param v1 value to raise
		 * @return new value
		 */
		static Double Exp(Double v1);
		/**
		 * get exponent part of bits
		 * @param bits with exponent
		 * @return exponent part
		 */
		static Int32 ExtractExponentFromBits(UInt64 bits);
		/**
		 * get significant part of bits
		 * @param bits with significant
		 * @return significant part
		 */
		static UInt64 ExtractSignificandFromBits(UInt64 bits);
		/**
		 * value less than or equal to the specified number.
		 * @param v1 number to check
		 * @return floor of number
		 */
		static Double Floor(Double v1);
		/**
		 * (x * y) + z, rounded as one ternary operation.
		 * @param x value 1
		 * @param y value 2
		 * @param z value 3
		 * @return (x * y) + z, rounded as one ternary operation.
		 */
		static Double FusedMultiplyAdd(Double x, Double y, Double z);
		/**
		 * remainder resulting from the division of a specified number by another specified number.
		 * @param x number 1
		 * @param y number 2
		 * @return remainder
		 */
		static Double IEEERemainder(Double x, Double y);
		/**
		 * base 2 integer logarithm of a value
		 * @param x value
		 * @return base 2 integer logarithm of a value
		 */
		static Int32 ILogB(Double x);
		/**
		 * natural (base e) logarithm of a specified number.
		 * @param v1 number
		 * @return natural (base e) logarithm of a specified number.
		 */
		static Double Log(Double v1);
		/**
		 * logarithm of a specified number in a specified base.
		 * @param v1 number
		 * @param v2 base
		 * @return logarithm of a specified number in a specified base.
		 */
		static Double Log(Double v1, Double v2);
		/**
		 * base 10 logarithm of a specified number.
		 * @param v1 number
		 * @return base 10 logarithm of a specified number.
		 */
		static Double Log10(Double v1);
		/**
		 * base 2 logarithm of a specified number.
		 * @param x number
		 * @return base 2 logarithm of a specified number.
		 */
		static Double Log2(double x);
		/**
		 * Maximum of two numbers
		 * @param val1 number 1
		 * @param val2 number 2
		 * @return Maximum of two numbers
		 */
		static Byte Max(Byte val1, Byte val2);
		/**
		 * Maximum of two numbers
		 * @param val1 number 1
		 * @param val2 number 2
		 * @return Maximum of two numbers
		 */
		static Double Max(Double val1, Double val2);
		/**
		 * Maximum of two numbers
		 * @param val1 number 1
		 * @param val2 number 2
		 * @return Maximum of two numbers
		 */
		static Int16 Max(Int16 val1, Int16 val2);
		/**
		 * Maximum of two numbers
		 * @param val1 number 1
		 * @param val2 number 2
		 * @return Maximum of two numbers
		 */
		static Int32 Max(Int32 val1, Int32 val2);
		/**
		 * Maximum of two numbers
		 * @param val1 number 1
		 * @param val2 number 2
		 * @return Maximum of two numbers
		 */
		static Int64 Max(Int64 val1, Int64 val2);
		/**
		 * Maximum of two numbers
		 * @param val1 number 1
		 * @param val2 number 2
		 * @return Maximum of two numbers
		 */
		static SByte Max(SByte val1, SByte val2);
		/**
		 * Maximum of two numbers
		 * @param val1 number 1
		 * @param val2 number 2
		 * @return Maximum of two numbers
		 */
		static Single Max(Single val1, Single val2);
		/**
		 * Maximum of two numbers
		 * @param val1 number 1
		 * @param val2 number 2
		 * @return Maximum of two numbers
		 */
		static UInt16 Max(UInt16 val1, UInt16 val2);
		/**
		 * Maximum of two numbers
		 * @param val1 number 1
		 * @param val2 number 2
		 * @return Maximum of two numbers
		 */
		static UInt32 Max(UInt32 val1, UInt32 val2);
		/**
		 * Maximum of two numbers
		 * @param val1 number 1
		 * @param val2 number 2
		 * @return Maximum of two numbers
		 */
		static UInt64 Max(UInt64 val1, UInt64 val2);
		/**
		 * larger magnitude of two double-precision floating-point numbers.
		 * @param x number 1
		 * @param y number 2
		 * @return larger magnitude of two double-precision floating-point numbers.
		 */
		static Double MaxMagnitude(Double x, Double y);
		/**
		 * Minimum of two numbers
		 * @param val1 number 1
		 * @param val2 number 2
		 * @return Minimum of two numbers
		 */
		static Byte Min(Byte val1, Byte val2);
		/**
		 * Minimum of two numbers
		 * @param val1 number 1
		 * @param val2 number 2
		 * @return Minimum of two numbers
		 */
		static Double Min(Double val1, Double val2);
		/**
		 * Minimum of two numbers
		 * @param val1 number 1
		 * @param val2 number 2
		 * @return Minimum of two numbers
		 */
		static Int16 Min(Int16 val1, Int16 val2);
		/**
		 * Minimum of two numbers
		 * @param val1 number 1
		 * @param val2 number 2
		 * @return Minimum of two numbers
		 */
		static Int32 Min(Int32 val1, Int32 val2);
		/**
		 * Minimum of two numbers
		 * @param val1 number 1
		 * @param val2 number 2
		 * @return Minimum of two numbers
		 */
		static Int64 Min(Int64 val1, Int64 val2);
		/**
		 * Minimum of two numbers
		 * @param val1 number 1
		 * @param val2 number 2
		 * @return Minimum of two numbers
		 */
		static SByte Min(SByte val1, SByte val2);
		/**
		 * Minimum of two numbers
		 * @param val1 number 1
		 * @param val2 number 2
		 * @return Minimum of two numbers
		 */
		static Single Min(Single val1, Single val2);
		/**
		 * Minimum of two numbers
		 * @param val1 number 1
		 * @param val2 number 2
		 * @return Minimum of two numbers
		 */
		static UInt16 Min(UInt16 val1, UInt16 val2);
		/**
		 * Minimum of two numbers
		 * @param val1 number 1
		 * @param val2 number 2
		 * @return Minimum of two numbers
		 */
		static UInt32 Min(UInt32 val1, UInt32 val2);
		/**
		 * Minimum of two numbers
		 * @param val1 number 1
		 * @param val2 number 2
		 * @return Minimum of two numbers
		 */
		static UInt64 Min(UInt64 val1, UInt64 val2);
		/**
		 * smaller magnitude of two double-precision floating-point numbers.
		 * @param x number 1
		 * @param y number 2
		 * @return smaller magnitude of two double-precision floating-point numbers.
		 */
		static Double MinMagnitude(Double x, Double y);
		/**
		 * number raised to the specified power.
		 * @param x number
		 * @param y power
		 * @return number raised to the specified power.
		 */
		static Double Pow(Double x, Double y);
		/**
		 * Rounds a value to the nearest integer or to the specified number of fractional digits.
		 * @param v1 value to round
		 * @return Rounds a value to the nearest integer or to the specified number of fractional digits.
		 */
		static Double Round(Double v1);
		/**
		 * Rounds a value to the nearest integer or to the specified number of fractional digits.
		 * @param v1 number
		 * @param v2 decimals
		 * @return Rounds a value to the nearest integer or to the specified number of fractional digits.
		 */
		static Double Round(Double v1, Int32 v2);
		/**
		 * Rounds a value to the nearest integer or to the specified number of fractional digits.
		 * @param value to use
		 * @param digits to use
		 * @param mode of rounding
		 * @return Rounds a value to the nearest integer or to the specified number of fractional digits.
		 */
		static Double Round(Double value, Int32 digits, MidpointRounding mode);
		/**
		 * x * 2^n computed efficiently.
		 * @param x value
		 * @param n value
		 * @return x * 2^n computed efficiently.
		 */
		static Double ScaleB(Double x, Int32 n);
		/**
		 * integer that indicates the sign of a number.
		 * @param v1 number with sign
		 * @return -1, 1
		 */
		static Int32 Sign(Double v1);
		/**
		 * integer that indicates the sign of a number.
		 * @param v1 number with sign
		 * @return -1, 1
		 */
		static Int32 Sign(Int16 v1);
		/**
		 * integer that indicates the sign of a number.
		 * @param v1 number with sign
		 * @return -1, 1
		 */
		static Int32 Sign(Int32 v1);
		/**
		 * integer that indicates the sign of a number.
		 * @param v1 number with sign
		 * @return -1, 1
		 */
		static Int32 Sign(Int64 v1);
		/**
		 * integer that indicates the sign of a number.
		 * @param v1 number with sign
		 * @return -1, 1
		 */
		static Int32 Sign(SByte v1);
		/**
		 * integer that indicates the sign of a number.
		 * @param v1 number with sign
		 * @return -1, 1
		 */
		static Int32 Sign(Single v1);
		/**
		 * sine of the specified angle.
		 * @param value to use
		 * @return sine of the specified angle.
		 */
		static Double Sin(Double value);
		/**
		 * hyperbolic sine of the specified angle.
		 * @param value to use
		 * @return hyperbolic sine of the specified angle.
		 */
		static Double Sinh(Double value);
		/**
		 * square root of a specified number.
		 * @param value to use
		 * @return square root of a specified number.
		 */
		static Double Sqrt(Double value);
		/**
		 * tangent of the specified angle.
		 * @param value angle
		 * @return tangent of the specified angle.
		 */
		static Double Tan(Double value);
		/**
		 * hyperbolic tangent of the specified angle.
		 * @param value angle
		 * @return hyperbolic tangent of the specified angle.
		 */
		static Double Tanh(Double value);
		/**
		 * Calculates the integral part of a number.
		 * @param value integral
		 * @return Calculates the integral part of a number.
		 */
		static Double Truncate(Double value);
		/**
		 * natural logarithmic base, specified by the constant, e
		 */
		static Double PI;
		/**
		 * ratio of the circumference of a circle to its diameter, specified by the constant
		 */
		static Double E;
	};
}
