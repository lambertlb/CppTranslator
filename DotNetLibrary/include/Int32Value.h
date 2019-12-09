#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	class DLL_EXPORT Int32Value : public ValueType {
		Int32 value;
	public:
		Int32Value(Int32 v)
		{
			value = v;
		}
		// .Net functions
		virtual bool	Equals(Object* valueToCompare) {
			return(false);
		}
		virtual bool	Equals(Int32 valueToCompare) {
			return(false);
		}
		virtual Int32	CompareTo(Int32 valueToCompare) {
			return(0);
		}
		virtual Int32	CompareTo(Object* valueToCompare) {
			return(0);
		}
		static Int32 Parse(String* stringToParse) {
			return(0);
		}
		String* ToString() {
			return(nullptr);
		}
		static Int32	MaxValue;
		static Int32	MinValue;
	};
}
