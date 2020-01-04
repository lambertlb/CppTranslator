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
}