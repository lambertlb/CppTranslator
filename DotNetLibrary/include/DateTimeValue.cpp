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
	DateTime DateTimeValue::get_Now()
	{
		FILETIME ft;
		FILETIME st;
		LARGE_INTEGER li;
		GetSystemTimeAsFileTime(&ft);
		FileTimeToLocalFileTime(&ft,&st);
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