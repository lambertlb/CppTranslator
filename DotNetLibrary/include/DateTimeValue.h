#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	// Enumeration to represent days in a week
	enum DayOfWeek
	{
		Sunday,
		Monday,
		Tuesday,
		Wednesday,
		Thursday,
		Friday,
		Saturday
	};
	// Enumeration to represent different parts of the date value
	enum DatePart
	{
		Day,
		DayYear,
		Month,
		Year
	};
	class DLL_EXPORT DateTimeValue : public ValueType {
		DateTime	value;
	public:
		DateTimeValue() { value = 0; }
		DateTimeValue(DateTime val) { value = val; }
		static DateTime	Now() { return(DateTime(0)); }
		virtual DataType GetRawDataType() { return(DateTimeType); };
		virtual bool	Equals(Object* valueToCompare) { return(false); }
		Int32					CompareTo(const DateTime& ts1) { return(0); }
		Int32					CompareTo(Object* obj) { return(0); }
		static	Int32				Compare(const DateTime& date1, const DateTime& date2) { return(0); }
		bool	Equals(const DateTime& valueToCOmpare) { return(false); }
		static bool	Equals(const DateTime& valueToCOmpare, const DateTime& valueToCOmpare2) { return(false); }
		virtual	String* ToString() { return(nullptr); }
		DateTime					get_Date() { return(0); }
		Int32						get_Day() { return(0); }
		DayOfWeek					get_DayOfWeek() { return(Sunday); }
		Int32						get_DayOfYear() { return(0); }
		Int32						get_Hour() { return(0); }
		Int32						get_Millisecond() { return(0); }
		Int32						get_Minute() { return(0); }
		Int32						get_Month() { return(0); }
		static	DateTime			get_Now() { return(0); }
		Int32						get_Second() { return(0); }
		Int64						get_Ticks() { return(0); }
		Int64						get_TimeOfDay() { return(0); }
		static	DateTime			get_Today() { return(0); }
		static	DateTime			get_UtcNow() { return(0); }
		Int32						get_Year() { return(0); }
		DateTime					Add(const TimeSpan ts) { return(0); }
		DateTime					AddDays(const Double delta) { return(0); }
		DateTime					AddHours(const Double delta) { return(0); }
		DateTime					AddMilliseconds(const Double delta) { return(0); }
		DateTime					AddMinutes(const Double delta) { return(0); }
		DateTime					AddMonths(const Int32 delta) { return(0); }
		DateTime					AddSeconds(const Double delta) { return(0); }
		DateTime					AddTicks(const Int64 delta) { return(0); }
		DateTime					AddYears(const Int32 delta) { return(0); }
		static Int64		DateToTicks(Int32 year, Int32 month, Int32 day) { return(0); }
		static Int64		TimeToTicks(Int32 hour, Int32 minute, Int32 second, Int32 milliseconds) { return(0); }
		static Int32		DaysInMonth(Int32 year, Int32 month) { return(0); }
		static Boolean	IsLeapYear(Int32 year) { return(false); }
		TimeSpan					Subtract(const DateTime& date1) { return(0); }
		DateTime					Subtract(const TimeSpan ts) { return(0); }
		DateTime					ToLocalTime() { return(0); }
		DateTime					ToUniversalTime() { return(0); }
		static DateTime			op_Addition(const DateTime& ts1, const DateTime& ts2) { return(0); }
		static DateTime			op_Addition(const DateTime& ts1, const TimeSpan ts2) { return(0); }
		static TimeSpan			op_Subtraction(const DateTime& ts1, const DateTime& ts2) { return(0); }
		static DateTime			op_Subtraction(const DateTime& ts1, const TimeSpan ts2) { return(0); }
		static DateTime			op_UnaryNegation(const DateTime& ts1) { return(0); }
		static DateTime			op_UnaryPlus(const DateTime& ts1) { return(0); }

		static Boolean			op_Inequality(const DateTime& ts1, const DateTime& ts2) { return(false); }
		static Boolean			op_GreaterThan(const DateTime& ts1, const DateTime& ts2) { return(false); }
		static Boolean			op_GreaterThanOrEqual(const DateTime& ts1, const DateTime& ts2) { return(false); }
		static Boolean			op_LessThan(const DateTime& ts1, const DateTime& ts2) { return(false); }
		static Boolean			op_LessThanOrEqual(const DateTime& ts1, const DateTime& ts2) { return(false); }
		static DateTime	MaxValue;
		static DateTime	MinValue;
	};
}
