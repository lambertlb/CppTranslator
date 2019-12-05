#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	class  UInt32Value : public ValueType {
		UInt32 value;
	public:
		UInt32Value(UInt32 v)
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
