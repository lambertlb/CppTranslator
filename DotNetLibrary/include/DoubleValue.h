#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	class  DoubleValue : public ValueType {
		Double value;
	public:
		DoubleValue(Double v)
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
