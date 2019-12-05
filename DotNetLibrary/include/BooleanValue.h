#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	class  BooleanValue : public ValueType {
		Boolean value;
	public:
		BooleanValue(Boolean v)
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
