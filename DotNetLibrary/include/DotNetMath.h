// Copyright (c) 2019 LLambert
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this
// software and associated documentation files (the "Software"), to deal in the Software
// without restriction, including without limitation the rights to use, copy, modify, merge,
// publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons
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
	enum MidpointRounding
	{
		ToEven = 0,
		AwayFromZero = 1,
		ToZero = 2,
		ToNegativeInfinity = 3,
		ToPositiveInfinity = 4
	};
	class DLL_EXPORT Math {
	public:
		static Double	PI;
		static Double	E;

		static Double	Abs(Double v1);
		static Double	Abs(Int16 v1);
		static Double	Abs(Int32 v1);
		static Double	Abs(Int64 v1);
		static Double	Abs(SByte v1);
		static Double	Abs(Single v1);
		static Double	Acos(Double v1);
		static Double	Acosh(Double v1);
		static Double	Asin(Double v1);
		static Double	Asinh(Double v1);
		static Double	Atan(Double v1);
		static Double	Atan2(Double v1, Double v2);
		static Double	Atanh(Double v1);
		static Int64	BigMul(Int32 v1, Int32 v2);
		static Double	BitDecrement(Double x);
		static Double	BitIncrement(Double x);
		static Double	Cbrt(Double x);
		static Double	Ceiling(Double v1);
		static Byte		Clamp(Byte value, Byte min, Byte max);
		static Double	Clamp(Double value, Double min, Double max);
		static Int16	Clamp(Int16 value, Int16 min, Int16 max);
		static Int32	Clamp(Int32 value, Int32 min, Int32 max);
		static Int64	Clamp(Int64 value, Int64 min, Int64 max);
		static SByte	Clamp(SByte value, SByte min, SByte max);
		static Single	Clamp(Single value, Single min, Single max);
		static UInt16	Clamp(UInt16 value, UInt16 min, UInt16 max);
		static UInt32	Clamp(UInt32 value, UInt32 min, UInt32 max);
		static UInt64	Clamp(UInt64 value, UInt64 min, UInt64 max);
		static Double	CopySign(Double x, Double y);
		static Double	Cos(Double v1);
		static Double	Cosh(Double v1);
		static Int64	Divide(Int64 v1, Int64 v2);
		static Double	Divide(Double v1, Double v2);
		static Int32	DivRem(Int32 a, Int32 b, Int32& result);
		static Int64	DivRem(Int64 a, Int64 b, Int64& result);
		static Double	Exp(Double v1);
		static Int32	ExtractExponentFromBits(UInt64 bits);
		static UInt64	ExtractSignificandFromBits(UInt64 bits);
		static Double	Floor(Double v1);
		static Double	FusedMultiplyAdd(Double x, Double y, Double z);
		static Double	IEEERemainder(Double x, Double y);
		static Int32	ILogB(Double x);
		static Double	Log(Double v1);
		static Double	Log(Double v1, Double v2);
		static Double	Log10(Double v1);
		static Double	Log2(double x);
		static Byte		Max(Byte val1, Byte val2);
		static Double	Max(Double val1, Double val2);
		static Int16	Max(Int16 val1, Int16 val2);
		static Int32	Max(Int32 val1, Int32 val2);
		static Int64	Max(Int64 val1, Int64 val2);
		static SByte	Max(SByte val1, SByte val2);
		static Single	Max(Single val1, Single val2);
		static UInt16	Max(UInt16 val1, UInt16 val2);
		static UInt32	Max(UInt32 val1, UInt32 val2);
		static UInt64	Max(UInt64 val1, UInt64 val2);
		static Double	MaxMagnitude(Double x, Double y);
		static Byte		Min(Byte val1, Byte val2);
		static Double	Min(Double val1, Double val2);
		static Int16	Min(Int16 val1, Int16 val2);
		static Int32	Min(Int32 val1, Int32 val2);
		static Int64	Min(Int64 val1, Int64 val2);
		static SByte	Min(SByte val1, SByte val2);
		static Single	Min(Single val1, Single val2);
		static UInt16	Min(UInt16 val1, UInt16 val2);
		static UInt32	Min(UInt32 val1, UInt32 val2);
		static UInt64	Min(UInt64 val1, UInt64 val2);
		static Double	MinMagnitude(Double x, Double y);
		static Double	Pow(Double x, Double y);
		static Double	Round(Double v1);
		static Double	Round(Double v1, Int32 v2);
		static Double	Round(Double value, Int32 digits, MidpointRounding mode);
		static Double	ScaleB(Double x, Int32 n);
		static Int32	Sign(Double v1);
		static Int32	Sign(Int16 v1);
		static Int32	Sign(Int32 v1);
		static Int32	Sign(Int64 v1);
		static Int32	Sign(SByte v1);
		static Int32	Sign(Single v1);
		static Double	Sin(Double value);
		static Double	Sinh(Double value);
		static Double	Sqrt(Double value);
		static Double	Tan(Double value);
		static Double	Tanh(Double value);
		static Double	Truncate(Double value);
	};
}
