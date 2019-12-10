#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	class DLL_EXPORT SByteValue : public ValueType {
		SByte value;
	public:
		SByteValue(SByte v)
		{
			value = v;
		}
		// .Net functions
		virtual bool	Equals(Object* valueToCompare) {
			return(false);
		}
		virtual bool	Equals(SByte valueToCompare) {
			return(false);
		}
		virtual Int32	CompareTo(SByte valueToCompare) {
			return(0);
		}
		virtual Int32	CompareTo(Object* valueToCompare) {
			return(0);
		}
		String* ToString() {
			return(nullptr);
		}
		static SByte Parse(String* stringToParse) {
			return(0);
		}
		static SByte	MaxValue;
		static SByte	MinValue;
	};
}