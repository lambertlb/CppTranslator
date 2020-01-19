#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	class DLL_EXPORT Math {
	public:
		static Double	PI;
		static Double	E;

		static Byte	Max(Byte v1, Byte v2) { return(v1 > v2 ? v1 : v2); }
		static Byte	Min(Byte v1, Byte v2) { return(v1 < v2 ? v1 : v2); }
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
		static Int32	DivRem(Int32 a, Int32 b, Int32* result);
		static Int64	DivRem(Int64 a, Int64 b, Int64* result);
		static Double	Exp(Double v1);
		static Double	Floor(Double v1);
		static Double	FusedMultiplyAdd(Double x, Double y, Double z);
		static Double	IEEERemainder(Double x, Double y);
		static Int32	ILogB(Double x);
		static Double	Log(Double v1);
		static Double	Log(Double v1, Double v2);
		static Double	Log10(Double v1);
		static Double	Log2(double x);
		static Double	Pow(Double v1, Double v2) { return(v1); }
		static Double	Round(Double v1) { return(v1); }
		static Double	Round(Double v1, Int32 v2) { return(v1); }
		static Double	Sin(Double v1) { return(v1); }
		static Double	Sign(Double v1) { return(v1); }
		static Double	Sinh(Double v1) { return(v1); }
		static Double	Sqrt(Double v1) { return(v1); }
		static Double	Tan(Double v1) { return(v1); }
		static Double	Tanh(Double v1) { return(v1); }
		static Double	Truncate(Double v1) { return(v1); }
	};
}
