#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	class  Int32Value : public ValueType {
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
		String* ToString() {
			return(nullptr);
		}
	};
}
