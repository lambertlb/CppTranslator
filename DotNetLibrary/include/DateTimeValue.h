#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	// Number of 100ns ticks per time unit
	const Int64 TicksPerMillisecond = 10000;
	const Int64 TicksPerSecond = TicksPerMillisecond * 1000;
	const Int64 TicksPerMinute = TicksPerSecond * 60;
	const Int64 TicksPerHour = TicksPerMinute * 60;
	const Int64 TicksPerDay = TicksPerHour * 24;

	// Number of milliseconds per time unit
	const Int32 MillisPerSecond = 1000;
	const Int32 MillisPerMinute = MillisPerSecond * 60;
	const Int32 MillisPerHour = MillisPerMinute * 60;
	const Int32 MillisPerDay = MillisPerHour * 24;

	// Number of days in a non-leap year
	const Int32 DaysPerYear = 365;
	// Number of days in 4 years
	const Int32 DaysPer4Years = DaysPerYear * 4 + 1;       // 1461
	// Number of days in 100 years
	const Int32 DaysPer100Years = DaysPer4Years * 25 - 1;  // 36524
	// Number of days in 400 years
	const Int32 DaysPer400Years = DaysPer100Years * 4 + 1; // 146097

	// Number of days from 1/1/0001 to 12/31/1600
	const Int32 DaysTo1601 = DaysPer400Years * 4;          // 584388
	// Number of days from 1/1/0001 to 12/30/1899
	const Int32 DaysTo1899 = DaysPer400Years * 4 + DaysPer100Years * 3 - 367;
	// Number of days from 1/1/0001 to 12/31/1969
	const Int32 DaysTo1970 = DaysPer400Years * 4 + DaysPer100Years * 3 + DaysPer4Years * 17 + DaysPerYear; // 719,162
	// Number of days from 1/1/0001 to 12/31/9999
	const Int32 DaysTo10000 = DaysPer400Years * 25 - 366;  // 3652059

	const	Int64 MinTicks = 0;
	const	Int64 MaxTicks = DaysTo10000 * TicksPerDay - 1;
	const	Int64 MaxMillis = (Int64)DaysTo10000 * MillisPerDay;
	const	Int64 MaxSeconds = 0x000000d6bf94d5e5LL;
	const	Int64 MinSeconds = 0xffffff29406b2a1bLL;
	const	Int64 MaxMilliSeconds = 0x000346dc5d638865LL;
	const	Int64 MinMilliSeconds = 0xfffcb923a29c779bLL;
	const	Int32 DatePartYear = 0;
	const	Int32 DatePartDayOfYear = 1;
	const	Int32 DatePartMonth = 2;
	const	Int32 DatePartDay = 3;
	// Number of days from 1/1/0001 to 12/31/1600
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
		virtual DateTime	get_AsDateTime();
		DateTime			get_Date();
		Int32				get_Day();
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
		DateTime			Add(Double value, Int32 scale);
		DateTime			Add(const TimeSpan ts);
		DateTime			AddDays(const Double delta);
		DateTime			AddHours(const Double delta);
		DateTime			AddMilliseconds(const Double delta);
		DateTime			AddMinutes(const Double delta);
		DateTime			AddMonths(const Int32 delta);
		DateTime			AddSeconds(const Double delta);
		DateTime			AddTicks(const Int64 delta);
		DateTime			AddYears(const Int32 delta);
		static	Int32		Compare(const DateTime& date1, const DateTime& date2);
		Int32				CompareTo(const DateTime& ts1);
		Int32				CompareTo(Object* obj);
		static Int32		DaysInMonth(Int32 year, Int32 month);
		bool				Equals(const DateTime& valueToCompare);
		static bool			Equals(const DateTime& valueToCompare, const DateTime& valueToCompare2);
		virtual bool		Equals(Object* valueToCompare);
		Boolean				IsDaylightSavingTime();
		static Boolean		IsLeapYear(Int32 year);
		virtual	Int32		FormatString(Char* where, const Int32 whereSize);
		Int32				GetDatePart(Int32 part);
		void				GetDatePart(Int32& year, Int32& month, Int32& day);
		virtual DataType	GetRawDataType() { return(DateTimeType); };
		TimeSpan			Subtract(const DateTime& date1);
		DateTime			Subtract(const TimeSpan ts);
		DateTime			ToLocalTime();
		DateTime			ToLocalTime(Boolean throwOnOverflow);
		DateTime			ToUniversalTime();
		static DateTime		op_Addition(const DateTime& ts1, const TimeSpan ts2);
		static Boolean		op_Equality(const DateTime& ts1, const DateTime& ts2);
		static Boolean		op_GreaterThan(const DateTime& ts1, const DateTime& ts2);
		static Boolean		op_GreaterThanOrEqual(const DateTime& ts1, const DateTime& ts2);
		static Boolean		op_Inequality(const DateTime& ts1, const DateTime& ts2);
		static Boolean		op_LessThan(const DateTime& ts1, const DateTime& ts2);
		static Boolean		op_LessThanOrEqual(const DateTime& ts1, const DateTime& ts2);
		static TimeSpan		op_Subtraction(const DateTime& ts1, const DateTime& ts2);
		static DateTime		op_Subtraction(const DateTime& ts1, const TimeSpan ts2);
		static DateTime	MaxValue;
		static DateTime	MinValue;
	};
	Int64 TimePartsToTicks(Int32 days, Int32 hour, Int32 minute, Int32 second, Int32 milliseconds);
}
