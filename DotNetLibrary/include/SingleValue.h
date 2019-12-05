#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	class  SingleValue : public ValueType {
		Single value;
	public:
		SingleValue(Single v)
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
	typedef SingleValue Float;
}
