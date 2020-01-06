#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	Int64 TimeToTicks(Int32 hour, Int32 minute, Int32 second)
	{
		// totalSeconds is bounded by 2^31 * 2^12 + 2^31 * 2^8 + 2^31,
		// which is less than 2^44, meaning we won't overflow totalSeconds.
		Int64 totalSeconds = (Int64)hour * 3600 + (Int64)minute * 60 + (Int64)second;
		if (totalSeconds > MaxSeconds || totalSeconds < MinSeconds)
			throw new ArgumentOutOfRangeException();
		return totalSeconds * TicksPerSecond;
	}
	TimeSpan::TimeSpan(Int32 hours, Int32 minutes, Int32 seconds)
	{
		value = TimeToTicks(hours, minutes, seconds);
	}
	TimeSpan::TimeSpan(Int32 days, Int32 hours, Int32 minutes, Int32 seconds, Int32 milliseconds)
	{
		Int64 totalMilliSeconds = ((Int64)days * 3600 * 24 + (Int64)hours * 3600 + (Int64)minutes * 60 + seconds) * 1000 + milliseconds;
		if (totalMilliSeconds > MaxMilliSeconds || totalMilliSeconds < MinMilliSeconds)
			throw new ArgumentOutOfRangeException();
		value = (long)totalMilliSeconds * TicksPerMillisecond;
	}
	TimeSpan DotnetLibrary::TimeSpanValue::get_AsTimeSpan()
	{
		return value;
	}
	Int32 TimeSpanValue::FormatString(Char* where, const Int32 whereSize)
	{
		StringBuilder	stringBuilder;

		Int32 day = (Int32)(value.value / TicksPerDay);
		Int64 time = value.value % TicksPerDay;
		if (value.value < 0)
		{
			stringBuilder.Append(L'-');
			day = -day;
			time = -time;
		}
		if (day != 0)
		{
			stringBuilder.Append(day);
			stringBuilder.Append(L'.');
		}
		Int32	hours = (Int32)(time / TicksPerHour) % 24;
		Int32	min = (Int32)(time / TicksPerMinute) % 60;
		Int32	sec = (Int32)(time / TicksPerSecond) % 60;
		Int32	fractional = (Int32)(time % TicksPerSecond);
		Char	date[32];
		Int32 length = swprintf(date, 32, L"%02d:%02d:%02d", hours, min, sec);
		stringBuilder.Append(date, length);
		if (fractional != 0)
		{
			stringBuilder.Append((Char)'.');
			Char	frac[32];
			Int32Value factValue(fractional);
			Int32 fracLength = factValue.FormatString(frac, 32);
			stringBuilder.Append(frac, fracLength);
			stringBuilder.Append(L'0', 7 - fracLength);
		}
		return(stringBuilder.FormatString(where, whereSize));
	}
}