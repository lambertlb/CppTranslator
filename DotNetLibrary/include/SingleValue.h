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
		virtual bool	Equals(Single valueToCompare) {
			return(false);
		}
		virtual bool	Equals(Int32 valueToCompare) {
			return(false);
		}
		virtual Int32	CompareTo(Single valueToCompare) {
			return(0);
		}
		String* ToString() {
			return(nullptr);
		}
		Double operator %(Double v) { return (int32_t)value % (int32_t)v; };
		Double operator %(Single v) { return (int32_t)value % (int32_t)v; };
	};
	typedef SingleValue Float;
}
