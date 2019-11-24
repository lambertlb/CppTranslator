#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	struct TimeSpan {
		TimeSpan(int64_t val = int64_t{}) : value(val) {
		}
		TimeSpan(Int32 day, Int32 hour = -1, Int32 minute = -1, Int32 second = -1, Int32 millisecond = -1) {
			value = 0;
		}
		operator int64_t& () {
			return value;
		}
		operator const int64_t& () const {
			return value;
		}
		int64_t* operator &() {
			return &value;
		}
		const int64_t* operator &() const {
			return &value;
		}
		const int64_t* operator ->() const {
			return &value;
		}
		bool	Equals(const TimeSpan& valueToCOmpare) {
			return(valueToCOmpare.value == value);
		}
		int64_t value;
	};
}
