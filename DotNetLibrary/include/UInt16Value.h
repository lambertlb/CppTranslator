#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	class  UInt16Value : public ValueType {
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
		virtual Int32	CompareTo(Object* valueToCompare) {
			return(0);
		}
		String* ToString() {
			return(nullptr);
		}
	};
}
