#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	class DLL_EXPORT Int64Value : public ValueType {
		Int64 value;
	public:
		Int64Value(Int64 v)
		{
			value = v;
		}
		virtual DataType GetRawDataType() { return(Int64Type); };
		virtual bool	Equals(Object* valueToCompare) {
			return(false);
		}
		virtual bool	Equals(Int64 valueToCompare) {
			return(false);
		}
		virtual bool	Equals(Int32 valueToCompare) {
			return(false);
		}
		virtual Int32	CompareTo(Int64 valueToCompare) {
			return(0);
		}
		virtual Int32	CompareTo(Object* valueToCompare) {
			return(0);
		}
		static Int64 Parse(String* stringToParse) {
			return(0);
		}
		virtual	Int32	FormatString(Char* where, const Int32 whereSize);
		static Int64	MaxValue;
		static Int64	MinValue;
	};
}
