#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	struct DateTime : public ObjectRaw {
		DateTime(int64_t val = int64_t{}) : value(val) {
		}
		DateTime(Int32 year, Int32 month, Int32 day, Int32 hour = -1, Int32 minute = -1, Int32 second = -1, Int32 millisecond = -1) {
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
		static DateTime	Now() {
			return(DateTime(0));
		}
		bool	Equals(const DateTime& valueToCOmpare) {
			return(valueToCOmpare.value == value);
		}
		virtual	String				ToString() { return(nullptr); }
		int64_t value;
	};
}
