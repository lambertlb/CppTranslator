#pragma once
#include "DotnetTypes.h"
#ifdef WIN32
#include <Windows.h>
#include <time.h>
#else
#include <sys/time.h>
#include <ctime>
#endif

namespace DotnetLibrary
{
	Int32	daysToMonth365[] =
	{
		0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365
	};
	Int32	daysToMonth366[] =
	{
		0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366
	};
	Boolean		IsLeapYear(Int32 year)
	{
		return((year % 4 == 0) && (year % 100 != 0 || year % 400 == 0));
	}
	Int32* GetDaysArray(Int32 year)
	{
		return(IsLeapYear(year) ? daysToMonth366 : daysToMonth365);
	}
	Int64	DateToTicks(Int32 year, Int32 month, Int32 day)
	{
		if (year < 1 || year > 9999 || month < 1 || month > 12 || day < 1)
			throw new ArgumentOutOfRangeException();
		Int32* days = GetDaysArray(year);
		if (day > (days[month] - days[month - 1]))
			throw new ArgumentOutOfRangeException();
		Int32 yr = year - 1;
		Int32 ndays = (yr * 365) + (yr / 4) - (yr / 100) + (yr / 400) + days[month - 1] + day - 1;
		return(ndays * TicksPerDay);
	}
	Int64 TimePartsToTicks(Int32 days, Int32 hour, Int32 minute, Int32 second, Int32 milliseconds)
	{
		Int64 totalSeconds = (Int64)days * 3600 * 24 + (Int64)hour * 3600 + (Int64)minute * 60 + (Int64)second;
		if (totalSeconds > MaxSeconds || totalSeconds < MinSeconds)
			throw new ArgumentOutOfRangeException();
		if (milliseconds < 0 || milliseconds > 1000)
			throw new ArgumentOutOfRangeException();
		return ((totalSeconds * TicksPerSecond) + (milliseconds * TicksPerMillisecond));
	}
	Int64 TimeToTicks(Int32 hour, Int32 minute, Int32 second, Int32 milliseconds)
	{
		if (hour < 0 || hour >= 24 || minute < 0 || minute >= 60 || second < 0 || second >= 60)
			throw new ArgumentOutOfRangeException();
		return (TimePartsToTicks(0, hour, minute, second, milliseconds));
	}
	DateTime::DateTime(UInt64 ticks) {
		if (ticks < MinTicks || ticks > MaxTicks)
			throw new ArgumentOutOfRangeException();
		value = ticks;
	}
	DateTime::DateTime() {
		value = 0;
	}
	DateTime::DateTime(const DateTime& val) {
		value = val.value;
	}
	DateTime::DateTime(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 minute, Int32 second, Int32 millisecond) {
		value = DateToTicks(year, month, day);
		if (hour >= 0)
			value += TimeToTicks(hour, minute, second, millisecond);
	}

	DateTime	DateTimeValue::get_UtcNow() {
#ifdef WIN32
		/* Windows */
		FILETIME ft;
		LARGE_INTEGER li;
		GetSystemTimeAsFileTime(&ft);
		li.LowPart = ft.dwLowDateTime;
		li.HighPart = ft.dwHighDateTime;
		UInt64 ret = li.QuadPart + FileTimeOffset;
		return ret;
#else
		/* Linux */
		struct timeval tv;

		gettimeofday(&tv, NULL);

		uint64 ret = tv.tv_usec;
		/* Convert from micro seconds (10^-6) to milliseconds (10^-3) */
		ret /= 1000;

		/* Adds the seconds (10^0) after converting them to milliseconds (10^-3) */
		ret += (tv.tv_sec * 1000);

		return ret;
#endif
	}
	Int32 DateTimeValue::get_Year()
	{
		return GetDatePart(DatePartYear);
	}
	DateTime DateTimeValue::Add(const TimeSpan ts)
	{
		return AddTicks(ts.value);
	}
	DateTime DateTimeValue::Add(Double value, Int32 scale)
	{
		Double millis_double = value * (Double)scale + (value >= 0 ? 0.5 : -0.5);

		if (millis_double <= (Double)-MaxMillis || millis_double >= (Double)MaxMillis)
			throw new ArgumentOutOfRangeException();

		return AddTicks((Int64)millis_double * TicksPerMillisecond);
	}
	DateTime DateTimeValue::AddDays(const Double delta)
	{
		return Add(delta, MillisPerDay);
	}
	DateTime DateTimeValue::AddHours(const Double delta)
	{
		return Add(delta, MillisPerHour);
	}
	DateTime DateTimeValue::AddMilliseconds(const Double delta)
	{
		return Add(delta, 1);
	}
	DateTime DateTimeValue::AddMinutes(const Double delta)
	{
		return Add(delta, MillisPerMinute);
	}
	void DateTimeValue::GetDatePart(Int32& year, Int32& month, Int32& day)
	{
		Int64 ticks = value.value;
		// n = number of days since 1/1/0001
		Int32 n = (Int32)(ticks / TicksPerDay);
		// y400 = number of whole 400-year periods since 1/1/0001
		Int32 y400 = n / DaysPer400Years;
		// n = day number within 400-year period
		n -= y400 * DaysPer400Years;
		// y100 = number of whole 100-year periods within 400-year period
		Int32 y100 = n / DaysPer100Years;
		// Last 100-year period has an extra day, so decrement result if 4
		if (y100 == 4) y100 = 3;
		// n = day number within 100-year period
		n -= y100 * DaysPer100Years;
		// y4 = number of whole 4-year periods within 100-year period
		Int32 y4 = n / DaysPer4Years;
		// n = day number within 4-year period
		n -= y4 * DaysPer4Years;
		// y1 = number of whole years within 4-year period
		Int32 y1 = n / DaysPerYear;
		// Last year has an extra day, so decrement result if 4
		if (y1 == 4) y1 = 3;
		// compute year
		year = y400 * 400 + y100 * 100 + y4 * 4 + y1 + 1;
		// n = day number within year
		n -= y1 * DaysPerYear;
		// dayOfYear = n + 1;
		// Leap year calculation looks different from IsLeapYear since y1, y4,
		// and y100 are relative to year 1, not year 0
		Boolean leapYear = y1 == 3 && (y4 != 24 || y100 == 3);
		Int32* days = leapYear ? daysToMonth366 : daysToMonth365;
		// All months have less than 32 days, so n >> 5 is a good conservative
		// estimate for the month
		Int32 m = (n >> 5) + 1;
		// m = 1-based month number
		while (n >= days[m]) m++;
		// compute month and day
		month = m;
		day = n - days[m - 1] + 1;
	}
	DateTime DateTimeValue::AddMonths(const Int32 months)
	{
		if (months < -120000 || months > 120000)
			throw new ArgumentOutOfRangeException();
		Int32	year;
		Int32	month;
		Int32	day;
		GetDatePart(year, month, day);
		Int32 i = month - 1 + months;
		if (i >= 0)
		{
			month = i % 12 + 1;
			year += i / 12;
		}
		else
		{
			month = 12 + (i + 1) % 12;
			year += (i - 11) / 12;
		}
		if (year < 1 || year > 9999)
		{
			throw new ArgumentOutOfRangeException();
		}
		Int32 days = DaysInMonth(year, month);
		if (day > days) day = days;
		return DateTime((UInt64)(DateToTicks(year, month, day) + value.value % TicksPerDay));
	}
	DateTime DateTimeValue::AddSeconds(const Double delta)
	{
		return Add(delta, MillisPerSecond);
	}
	DateTime DateTimeValue::AddTicks(const Int64 delta)
	{
		Int64 ticks = value.value;
		if (delta > MaxTicks - ticks || delta < MinTicks - ticks) {
			throw new ArgumentOutOfRangeException();
		}
		return DateTime((UInt64)(ticks + delta));
	}
	DateTime DateTimeValue::AddYears(const Int32 delta)
	{
		if (delta < -10000 || delta > 10000)
		{
			throw new ArgumentOutOfRangeException();
		}
		return AddMonths(delta * 12);
	}
	Int32 DateTimeValue::DaysInMonth(Int32 year, Int32 month)
	{
		if (month < 1 || month > 12)
			throw new ArgumentOutOfRangeException();
		// IsLeapYear checks the year argument
		Int32* days = IsLeapYear(year) ? daysToMonth366 : daysToMonth365;
		return days[month] - days[month - 1];
	}
	Boolean DateTimeValue::IsLeapYear(Int32 year)
	{
		if (year < 1 || year > 9999)
		{
			throw new ArgumentOutOfRangeException();
		}
		return (year & 3) == 0 && ((year & 15) == 0 || (year % 25) != 0);
	}
	TimeSpan DateTimeValue::Subtract(const DateTime& date1)
	{
		return TimeSpan(value.value - date1.value);
	}
	DateTime DateTimeValue::Subtract(const TimeSpan ts)
	{
		Int64 ticks = value.value;
		Int64 valueTicks = ts.value;
		if (ticks - MinTicks < valueTicks || ticks - MaxTicks > valueTicks)
		{
			throw new ArgumentOutOfRangeException();
		}
		return DateTime((UInt64)(ticks - valueTicks));
	}
	DateTime DateTimeValue::ToLocalTime()
	{
		return ToLocalTime(false);
	}
	DateTime DateTimeValue::ToLocalTime(Boolean throwOnOverflow)
	{
		FILETIME ft;
		FILETIME st;
		LARGE_INTEGER li;
		li.QuadPart = value.value - FileTimeOffset;
		ft.dwLowDateTime = li.LowPart;
		ft.dwHighDateTime = li.HighPart;
		FileTimeToLocalFileTime(&ft, &st);
		li.LowPart = st.dwLowDateTime;
		li.HighPart = st.dwHighDateTime;
		UInt64 tick = li.QuadPart + FileTimeOffset;

		if (tick > MaxTicks)
		{
			if (throwOnOverflow)
				throw new ArgumentOutOfRangeException();
			else
				return DateTime(MaxTicks);
		}
		if (tick < MinTicks)
		{
			if (throwOnOverflow)
				throw new ArgumentOutOfRangeException();
			else
				return DateTime(MinTicks);
		}
		return DateTime(tick);
	}
	DateTime DateTimeValue::ToUniversalTime()
	{
		FILETIME ft;
		FILETIME st;
		LARGE_INTEGER li;
		li.QuadPart = value.value - FileTimeOffset;
		ft.dwLowDateTime = li.LowPart;
		ft.dwHighDateTime = li.HighPart;
		LocalFileTimeToFileTime(&ft, &st);
		li.LowPart = st.dwLowDateTime;
		li.HighPart = st.dwHighDateTime;
		UInt64 tick = li.QuadPart + FileTimeOffset;
		return DateTime(tick);
	}
	DateTime DateTimeValue::op_Addition(const DateTime& ts1, const TimeSpan ts2)
	{
		return(DateTimeValue(ts1).Add(ts2));
	}
	TimeSpan DateTimeValue::op_Subtraction(const DateTime& ts1, const DateTime& ts2)
	{
		return(DateTimeValue(ts1).Subtract(ts2));
	}
	DateTime DateTimeValue::op_Subtraction(const DateTime& ts1, const TimeSpan ts2)
	{
		return(DateTimeValue(ts1).Subtract(ts2));
	}
	Boolean DateTimeValue::op_GreaterThan(const DateTime& ts1, const DateTime& ts2)
	{
		return ts1.value > ts2.value;
	}
	Boolean DateTimeValue::op_GreaterThanOrEqual(const DateTime& ts1, const DateTime& ts2)
	{
		return ts1.value >= ts2.value;
	}
	Boolean DateTimeValue::op_LessThan(const DateTime& ts1, const DateTime& ts2)
	{
		return ts1.value < ts2.value;
	}
	Boolean DateTimeValue::op_LessThanOrEqual(const DateTime& ts1, const DateTime& ts2)
	{
		return ts1.value <= ts2.value;
	}
	DateTime DateTimeValue::get_Now()
	{
		FILETIME ft;
		FILETIME st;
		LARGE_INTEGER li;
		GetSystemTimeAsFileTime(&ft);
		FileTimeToLocalFileTime(&ft, &st);
		li.LowPart = st.dwLowDateTime;
		li.HighPart = st.dwHighDateTime;
		UInt64 tick = li.QuadPart + FileTimeOffset;
		if (tick > MaxTicks)
		{
			return DateTime(MaxTicks);
		}
		if (tick < MinTicks)
		{
			return DateTime(MinTicks);
		}
		return DateTime(tick);
	}
	Int32 DateTimeValue::get_Second()
	{
		return (Int32)((value.value / TicksPerSecond) % 60);
	}
	TimeSpan DateTimeValue::get_TimeOfDay()
	{
		return TimeSpan(value.value % TicksPerDay);
	}
	DateTime DateTimeValue::get_Today()
	{
		DateTime rtn = (DateTimeValue(get_Now())).get_Date();
		return	rtn;
	}
	Int32 DateTimeValue::CompareTo(const DateTime& dataTime)
	{
		return Compare(value, dataTime);
	}
	Int32 DateTimeValue::Compare(const DateTime& date1, const DateTime& date2)
	{
		Int64 ticks1 = date1.value;
		Int64 ticks2 = date2.value;
		if (ticks1 > ticks2) return 1;
		if (ticks1 < ticks2) return -1;
		return 0;
	}
	bool DateTimeValue::Equals(const DateTime& valueToCOmpare)
	{
		return value.value == valueToCOmpare.value;
	}
	bool DateTimeValue::Equals(const DateTime& valueToCOmpare, const DateTime& valueToCOmpare2)
	{
		return valueToCOmpare.value == valueToCOmpare2.value;
	}
	Int32 DateTimeValue::FormatString(Char* where, const Int32 whereSize)
	{
		StringBuilder stringBuilder;
		Int32	month = this->get_Month();
		Int32	day = this->get_Day();
		Int32	year = this->get_Year();
		Int32	hour = this->get_Hour();
		Int32	minute = this->get_Minute();
		Int32	second = this->get_Second();
		Boolean	isPm = false;
		if (hour > 12)
		{
			hour -= 12;
			isPm = true;
		}
		Char	dateTime[128];
		Int32 length = swprintf(dateTime, 128, L"%d/%d/%d %d:%02d:%02d ", month, day, year, hour, minute, second);
		stringBuilder.Append(dateTime, length);
		if (isPm)
			stringBuilder.Append(L"PM",2);
		else
			stringBuilder.Append(L"AM", 2);
		return(stringBuilder.FormatString(where, whereSize));
	}
	DateTime	DateTimeValue::get_Date() {
		UInt64 ticks = value.value;
		return DateTime((UInt64)(ticks - ticks % TicksPerDay));
	}
	Int32 DateTimeValue::get_Day()
	{
		return GetDatePart(DatePartDay);
	}
	Int32 DateTimeValue::GetDatePart(Int32 part)
	{
		UInt64 ticks = value.value;
		// n = number of days since 1/1/0001
		Int32 n = (Int32)(ticks / TicksPerDay);
		// y400 = number of whole 400-year periods since 1/1/0001
		Int32 y400 = n / DaysPer400Years;
		// n = day number within 400-year period
		n -= y400 * DaysPer400Years;
		// y100 = number of whole 100-year periods within 400-year period
		Int32 y100 = n / DaysPer100Years;
		// Last 100-year period has an extra day, so decrement result if 4
		if (y100 == 4) y100 = 3;
		// n = day number within 100-year period
		n -= y100 * DaysPer100Years;
		// y4 = number of whole 4-year periods within 100-year period
		Int32 y4 = n / DaysPer4Years;
		// n = day number within 4-year period
		n -= y4 * DaysPer4Years;
		// y1 = number of whole years within 4-year period
		Int32 y1 = n / DaysPerYear;
		// Last year has an extra day, so decrement result if 4
		if (y1 == 4) y1 = 3;
		// If year was requested, compute and return it
		if (part == DatePartYear)
		{
			return y400 * 400 + y100 * 100 + y4 * 4 + y1 + 1;
		}
		// n = day number within year
		n -= y1 * DaysPerYear;
		// If day-of-year was requested, return it
		if (part == DatePartDayOfYear) return n + 1;
		// Leap year calculation looks different from IsLeapYear since y1, y4,
		// and y100 are relative to year 1, not year 0
		bool leapYear = y1 == 3 && (y4 != 24 || y100 == 3);
		Int32* days = leapYear ? daysToMonth366 : daysToMonth365;
		// All months have less than 32 days, so n >> 5 is a good conservative
		// estimate for the month
		Int32 m = (n >> 5) + 1;
		// m = 1-based month number
		while (n >= days[m]) m++;
		// If month was requested, return it
		if (part == DatePartMonth) return m;
		// Return 1-based day-of-month
		return n - days[m - 1] + 1;
	}
	DayOfWeek DateTimeValue::get_DayOfWeek()
	{
		return (DayOfWeek)((value.value / TicksPerDay + 1) % 7);
	}
	Int32 DateTimeValue::get_DayOfYear()
	{
		return GetDatePart(DatePartDayOfYear);
	}
	Int32 DateTimeValue::get_Hour()
	{
		return (Int32)((value.value / TicksPerHour) % 24);
	}
	Int32 DateTimeValue::get_Millisecond()
	{
		return (Int32)((value.value / TicksPerMillisecond) % 1000);
	}
	Int32 DateTimeValue::get_Minute()
	{
		return (Int32)((value.value / TicksPerMinute) % 60);
	}
	Int32 DateTimeValue::get_Month()
	{
		return GetDatePart(DatePartMonth);
	}
}