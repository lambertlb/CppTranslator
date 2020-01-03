#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	class DLL_EXPORT TimeSpanValue : public ValueType {
		UInt64	value;
	public:
		TimeSpanValue() { value = 0; }
		TimeSpanValue(const UInt64 value2) { value = value2; };
		TimeSpanValue(Int32 hours, Int32 minutes, Int32 seconds) { value = 0; }
		TimeSpanValue(Int32 days, Int32 hours, Int32 minutes, Int32 seconds, Int32 milliseconds = 0) { value = 0; }
		virtual DataType	GetRawDataType() { return(TimeSpanType); };
		virtual TimeSpan	get_AsTimeSpan();

		bool	Equals(const TimeSpan& valueToCOmpare) {
			return(valueToCOmpare.value == value);
		}
		static bool	Equals(const TimeSpan& valueToCOmpare, const TimeSpan& valueToCOmpare2) {
			return(false);
		}
		virtual bool	Equals(Object* valueToCompare) {
			return(false);
		}
		virtual Int32	CompareTo(TimeSpan valueToCompare) {
			return(0);
		}
		Int32					CompareTo(Object* obj) { return(0); }
		TimeSpan				Duration() { return(0); }
		bool	Equals(const DateTime& valueToCOmpare) {
			return(false);
		}
		static	TimeSpan		FromDays(const Double data) { return(0); }
		static	TimeSpan		FromHours(const Double data) { return(0); }
		static	TimeSpan		FromMilliseconds(const Double data) { return(0); }
		static	TimeSpan		FromMinutes(const Double data) { return(0); }
		static	TimeSpan		FromSeconds(const Double data) { return(0); }
		static	TimeSpan		FromTicks(const Int64 data) { return(0); }
		TimeSpan				Negate() { return(0); }
		TimeSpan				Subtract(const TimeSpan& ts1) { return(0); }
		static TimeSpan			Parse(String* val) { return(0); }
		String* ToString() {
			return(nullptr);
		}
		TimeSpan				Add(const TimeSpan& ts) { return(TimeSpan(0)); }
		static	Int32			Compare(const TimeSpan& ts1, const TimeSpan& ts2) { return(0); }
		Int32					get_Days() { return(0); }
		Int32					get_Hours() { return(0); }
		Int32					get_Milliseconds() { return(0); }
		Int32					get_Minutes() { return(0); }
		Int32					get_Seconds() { return(0); }
		Int64					get_Ticks() { return(0); }
		Double					get_TotalDays() { return(0); }
		Double					get_TotalHours() { return(0); }
		Double					get_TotalMilliseconds() { return(0); }
		Double					get_TotalMinutes() { return(0); }
		Double					get_TotalSeconds() { return(0); }
		static TimeSpan			op_Addition(const TimeSpan& ts1, const TimeSpan& ts2) { return(0); }
		static TimeSpan			op_Subtraction(const TimeSpan& ts1, const TimeSpan& ts2) { return(0); }
		static TimeSpan			op_UnaryNegation(const TimeSpan& ts1) { return(0); }
		static TimeSpan			op_UnaryPlus(const TimeSpan& ts1) { return(0); }

		static Boolean			op_Inequality(const TimeSpan& ts1, const TimeSpan& ts2) { return(false); }
		static Boolean			op_GreaterThan(const TimeSpan& ts1, const TimeSpan& ts2) { return(false); }
		static Boolean			op_GreaterThanOrEqual(const TimeSpan& ts1, const TimeSpan& ts2) { return(false); }
		static Boolean			op_LessThan(const TimeSpan& ts1, const TimeSpan& ts2) { return(false); }
		static Boolean			op_LessThanOrEqual(const TimeSpan& ts1, const TimeSpan& ts2) { return(false); }
		static TimeSpan	MaxValue;
		static TimeSpan	MinValue;
		static TimeSpan	Zero;
	};
}
