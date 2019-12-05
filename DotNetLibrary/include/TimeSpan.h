#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	class TimeSpan : public ValueType {
		UInt64	value;
	public:
		TimeSpan(UInt64 val) {
			value = val;
		}
		TimeSpan(Int32 day, Int32 hour = -1, Int32 minute = -1, Int32 second = -1, Int32 millisecond = -1) {
			value = 0;
		}
		bool	Equals(const TimeSpan& valueToCOmpare) {
			return(valueToCOmpare.value == value);
		}
		Int64 get_Ticks() {
			return(value);
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
	};
}
