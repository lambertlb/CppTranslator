#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	class DLL_EXPORT Int16Value : public ValueType {
		Int16 value;
	public:
		Int16Value(Int16 v)
		{
			value = v;
		}
		// .Net functions
		virtual bool	Equals(Object* valueToCompare) {
			return(false);
		}
		virtual bool	Equals(Int16 valueToCompare) {
			return(false);
		}
		virtual Int32	CompareTo(Int16 valueToCompare) {
			return(0);
		}
		virtual Int32	CompareTo(Object* valueToCompare) {
			return(0);
		}
		static Int16 Parse(String* stringToParse) {
			return(0);
		}
		String* ToString() {
			return(nullptr);
		}
		static Int16	MaxValue;
		static Int16	MinValue;
	};
}
