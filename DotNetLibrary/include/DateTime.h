#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	struct DateTime {
		DateTime(int64_t val = int64_t{}) : value(val) {
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
		static DateTime	Now() {
			return(DateTime(0));
		}
		int64_t value;
	};
}
