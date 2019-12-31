#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	class DLL_EXPORT BooleanValue : public ValueType {
		Boolean value;
	public:
		BooleanValue(Boolean v)
		{
			value = v;
		}
		virtual DataType GetRawDataType() { return(BooleanType); };
		virtual bool	Equals(Object* valueToCompare) {
			return(false);
		}
		virtual bool	Equals(Boolean valueToCompare) {
			return(false);
		}
		virtual bool	Equals(Int32 valueToCompare) {
			return(false);
		}
		virtual Int32	CompareTo(Boolean valueToCompare) {
			return(0);
		}
		String* ToString() {
			return(nullptr);
		}
		static Boolean Parse(String* stringToParse) {
			return(false);
		}
		static String* TrueString;
		static String* FalseString;
	};
}
