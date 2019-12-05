#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	class DateTime : public ValueType {
		UInt64	value;
	public:
		DateTime(uint64_t val) : value(val) {
		}
		DateTime(Int32 year, Int32 month, Int32 day, Int32 hour = -1, Int32 minute = -1, Int32 second = -1, Int32 millisecond = -1) {
			value = 0;
		}
		static DateTime	Now() {
			return(DateTime(0));
		}
		// .Net functions
		virtual bool	Equals(Object* valueToCompare) {
			return(false);
		}
		virtual Int32	CompareTo(Object* valueToCompare) {
			return(0);
		}
		bool	Equals(const DateTime& valueToCOmpare) {
			return(false);
		}
		Int64 get_Ticks() {
			return(0);
		}
		virtual	String*	ToString() { return(nullptr); }
	};
}
