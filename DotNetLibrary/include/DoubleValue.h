#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	class DLL_EXPORT DoubleValue : public ValueType {
		Double value;
	public:
		DoubleValue(Double v)
		{
			value = v;
		}
		// .Net functions
		virtual bool	Equals(Object* valueToCompare) {
			return(false);
		}
		virtual bool	Equals(Double valueToCompare) {
			return(false);
		}
		virtual bool	Equals(Int32 valueToCompare) {
			return(false);
		}
		virtual Int32	CompareTo(Double valueToCompare) {
			return(0);
		}
		virtual Int32	CompareTo(Object* valueToCompare) {
			return(0);
		}
		String* ToString() {
			return(nullptr);
		}
		static Double Parse(String* stringToParse) {
			return(0);
		}
		static Boolean IsNaN(Double v) { return(false); }
		static Boolean IsInfinity(Double v) { return(false); }
		static Boolean IsNegativeInfinity(Double v) { return(false); }
		static Boolean IsPositiveInfinity(Double v) { return(false); }
		Double operator %(Double v) { return (int32_t)value % (int32_t)v; };
		static Double	MaxValue;
		static Double	MinValue;
		static Double	Epsilon;
		static Double	NaN;
		static Double	PositiveInfinity;
		static Double	NegativeInfinity;
	};
}
