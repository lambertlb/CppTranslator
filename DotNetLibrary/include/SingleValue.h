#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	class DLL_EXPORT SingleValue : public ValueType {
		Single value;
	public:
		SingleValue(Single v)
		{
			value = v;
		}
		virtual DataType GetRawDataType() { return(SingleType); };
		virtual bool	Equals(Object* valueToCompare) {
			return(false);
		}
		virtual bool	Equals(Single valueToCompare) {
			return(false);
		}
		virtual bool	Equals(Int32 valueToCompare) {
			return(false);
		}
		virtual bool	Equals(Double valueToCompare) {
			return(false);
		}
		virtual Int32	CompareTo(Single valueToCompare) {
			return(0);
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
		static Single Parse(String* stringToParse) {
			return(0);
		}
		static Boolean IsNaN(Single v) { return(false); }
		static Boolean IsInfinity(Single v) { return(false); }
		static Boolean IsNegativeInfinity(Single v) { return(false); }
		static Boolean IsPositiveInfinity(Single v) { return(false); }
		static Single	MaxValue;
		static Single	MinValue;
		static Single	Epsilon;
		static Single	NaN;
		static Single	PositiveInfinity;
		static Single	NegativeInfinity;
	};
	class DLL_EXPORT FloatValue : public SingleValue {
	public:
		static Single	MaxValue;
		static Single	MinValue;
		static Single	Epsilon;
		static Single	NaN;
		static Single	PositiveInfinity;
		static Single	NegativeInfinity;
	};
}
