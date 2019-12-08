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
		virtual bool	Equals(Double valueToCompare) {
			return(false);
		}
		virtual bool	Equals(Int32 valueToCompare) {
			return(false);
		}
		virtual Int32	CompareTo(Double valueToCompare) {
			return(0);
		}
		String* ToString() {
			return(nullptr);
		}
		Double operator %(Double v) { return (int32_t)value % (int32_t)v; };
		Double operator %(Single v) { return (int32_t)value % (int32_t)v; };
	};
}
