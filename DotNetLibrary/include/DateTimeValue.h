#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	const	Int32 DaysPer400Years = 146097;
	const	Int32 DaysPer100Years = 36524;
	const	Int32 DaysPer4Years = 1461;
	const	Int32 DaysPerYear = 365;
	const	UInt64 MinTicks = 0;
	const	Int64 MaxTicks = 0x2bca2875f4373fffLL;
	const	Int32 MillisPerSecond = 1000;
	const	Int32 MillisPerMinute = MillisPerSecond * 60;
	const	Int32 MillisPerHour = MillisPerMinute * 60;
	const	Int32 MillisPerDay = MillisPerHour * 24;
	const	Int64 MaxSeconds = 0x000000d6bf94d5e5LL;
	const	Int64 MinSeconds = 0xffffff29406b2a1bLL;
	const	Int64 MaxMilliSeconds = 0x000346dc5d638865LL;
	const	Int64 MinMilliSeconds = 0xfffcb923a29c779bLL;
	const	Int64 TicksPerMillisecond = 10000;
	const	Int64 TicksPerSecond = 10000000LL;
	const	Int64 TicksPerMinute = 600000000LL;
	const	Int64 TicksPerHour = 36000000000LL;
	const	Int64 TicksPerDay = 864000000000LL;
	const	Int32 DatePartYear = 0;
	const	Int32 DatePartDayOfYear = 1;
	const	Int32 DatePartMonth = 2;
	const	Int32 DatePartDay = 3;
	// Number of days from 1/1/0001 to 12/31/1600
	const	Int64 DaysTo1601 = DaysPer400Years * 4;          // 584388
	const	Int64 FileTimeOffset = DaysTo1601 * TicksPerDay;
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
	class DLL_EXPORT DateTimeValue : public ValueType {
		DateTime	value;
	public:
		DateTimeValue() { value = 0; }
		DateTimeValue(DateTime val) { value.value = val.value; }
		virtual DataType	GetRawDataType() { return(DateTimeType); };
		virtual bool		Equals(Object* valueToCompare) { return(false); }
		Int32				CompareTo(const DateTime& ts1) { return(0); }
		Int32				CompareTo(Object* obj) { return(0); }
		static	Int32		Compare(const DateTime& date1, const DateTime& date2) { return(0); }
		bool				Equals(const DateTime& valueToCOmpare) { return(false); }
		static bool			Equals(const DateTime& valueToCOmpare, const DateTime& valueToCOmpare2) { return(false); }
		virtual	String*		ToString() { return(nullptr); }
		DateTime			get_Date();
		Int32				get_Day();
		Int32				GetDatePart(Int32 part);
		DayOfWeek			get_DayOfWeek();
		Int32				get_DayOfYear();
		Int32				get_Hour();
		Int32				get_Millisecond();
		Int32				get_Minute();
		Int32				get_Month();
		static	DateTime	get_Now();
		Int32				get_Second();
		Int64				get_Ticks() { return(value.value); }
		TimeSpan			get_TimeOfDay();
		static	DateTime	get_Today();
		static	DateTime	get_UtcNow();
		Int32				get_Year();
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
	Int64 TimePartsToTicks(Int32 days, Int32 hour, Int32 minute, Int32 second, Int32 milliseconds);
}
