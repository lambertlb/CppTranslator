#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	class DLL_EXPORT UInt16Value : public ValueType {
		UInt16 value;
	public:
		UInt16Value(UInt16 v)
		{
			value = v;
		}
		// .Net functions
		virtual bool	Equals(Object* valueToCompare) {
			return(false);
		}
		virtual bool	Equals(UInt16 valueToCompare) {
			return(false);
		}
		virtual Int32	CompareTo(UInt16 valueToCompare) {
			return(0);
		}
		virtual Int32	CompareTo(Object* valueToCompare) {
			return(0);
		}
		static UInt16 Parse(String* stringToParse) {
			return(0);
		}
		String* ToString() {
			return(nullptr);
		}
		static UInt16	MaxValue;
		static UInt16	MinValue;
	};
}
