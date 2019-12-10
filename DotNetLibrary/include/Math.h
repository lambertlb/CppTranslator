#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	class DLL_EXPORT Math {
	public:
		static Byte	Max(Byte v1, Byte v2) { return(v1 > v2 ? v1 : v2); }
		static Byte	Min(Byte v1, Byte v2) { return(v1 < v2 ? v1 : v2); }
		static Double	Abs(Double v1) { return(v1); }
		static Double	Acos(Double v1) { return(v1); }
		static Double	Sign(Double v1) { return(v1); }
		static Double	Asin(Double v1) { return(v1); }
		static Double	Atan(Double v1) { return(v1); }
		static Double	Atan2(Double v1, Double v2) { return(v1); }
		static Double	Ceiling(Double v1) { return(v1); }
		static Double	Cos(Double v1) { return(v1); }
		static Double	Cosh(Double v1) { return(v1); }
		static Double	Exp(Double v1) { return(v1); }
		static Double	Floor(Double v1) { return(v1); }
		static Double	Log(Double v1) { return(v1); }
		static Double	Log(Double v1, Double v2) { return(v1); }
		static Double	Log10(Double v1) { return(v1); }
		static Double	Pow(Double v1, Double v2) { return(v1); }
		static Double	Round(Double v1) { return(v1); }
		static Double	Round(Double v1, Int32 v2) { return(v1); }
		static Double	Sin(Double v1) { return(v1); }
		static Double	Sinh(Double v1) { return(v1); }
		static Double	Sqrt(Double v1) { return(v1); }
		static Double	Tan(Double v1) { return(v1); }
		static Double	Tanh(Double v1) { return(v1); }
		static Double	Truncate(Double v1) { return(v1); }

		static Double	PI;
		static Double	E;
	};
}
