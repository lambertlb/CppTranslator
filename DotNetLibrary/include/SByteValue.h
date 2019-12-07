#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	class  SByteValue : public ValueType {
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
		virtual Int32	CompareTo(SByte valueToCompare) {
			return(0);
		}
		String* ToString() {
			return(nullptr);
		}
	};
}