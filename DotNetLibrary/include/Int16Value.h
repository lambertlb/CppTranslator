#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	class  Int16Value : public ValueType {
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
		String* ToString() {
			return(nullptr);
		}
	};
}
