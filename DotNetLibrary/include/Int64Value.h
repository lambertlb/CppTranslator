#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	class  Int64Value : public ValueType {
		Int64 value;
	public:
		Int64Value(Int64 v)
		{
			value = v;
		}
		// .Net functions
		virtual bool	Equals(Object* valueToCompare) {
			return(false);
		}
		virtual bool	Equals(Int64 valueToCompare) {
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
