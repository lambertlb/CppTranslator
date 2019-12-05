#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	class  UInt64Value : public ValueType {
	public:
		UInt64 value;
		UInt64Value(UInt64 v)
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
