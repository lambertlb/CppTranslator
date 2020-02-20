// Copyright (c) 2019 LLambert
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this
// software and associated documentation files (the "Software"), to deal in the Software
// without restriction, including without limitation the rights to use, copy, modify, merge,
// publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons
// to whom the Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or
// substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
// INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
// PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
// FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
// OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
#include "DotnetTypes.h"
#include <cwchar>

namespace DotnetLibrary
{
	DLL_EXPORT TimeSpan	TimeSpanValue::MaxValue = TimeSpan(UInt64Value::MaxValue);
	DLL_EXPORT TimeSpan	TimeSpanValue::MinValue = TimeSpan(UInt64Value::MinValue);
	DLL_EXPORT Int64	TimeSpanValue::TicksPerMillisecond = 10000;
	DLL_EXPORT Int64	TimeSpanValue::TicksPerSecond = TicksPerMillisecond * 1000;
	DLL_EXPORT Int64	TimeSpanValue::TicksPerMinute = TicksPerSecond * 60;
	DLL_EXPORT Int64	TimeSpanValue::TicksPerHour = TicksPerMinute * 60;
	DLL_EXPORT Int64	TimeSpanValue::TicksPerDay = TicksPerHour * 24;
	DLL_EXPORT TimeSpan	TimeSpanValue::Zero = TimeSpan(0);

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
		value = (Int64)totalMilliSeconds * TicksPerMillisecond;
	}
	Int32 TimeSpanValue::get_Days()
	{
		return (Int32)(value.value / TicksPerDay);
	}
	Int32 TimeSpanValue::get_Hours()
	{
		return (Int32)((value.value / TicksPerHour) % 24);
	}
	Int32 TimeSpanValue::get_Milliseconds()
	{
		return (Int32)((value.value / TicksPerMillisecond) % 1000);
	}
	Int32 TimeSpanValue::get_Minutes()
	{
		return (Int32)((value.value / TicksPerMinute) % 60);
	}
	Int32 TimeSpanValue::get_Seconds()
	{
		return (Int32)((value.value / TicksPerSecond) % 60);
	}
	Int64 TimeSpanValue::get_Ticks()
	{
		return value.value;
	}
	Double TimeSpanValue::get_TotalDays()
	{
		return ((Double)value.value) / TicksPerDay;
	}
	Double TimeSpanValue::get_TotalHours()
	{
		return (Double)value.value / TicksPerHour;
	}
	Double TimeSpanValue::get_TotalMilliseconds()
	{
		Double temp = (Double)value.value / TicksPerMillisecond;
		if (temp > MaxMilliSeconds)
			return (Double)MaxMilliSeconds;
		if (temp < MinMilliSeconds)
			return (Double)MinMilliSeconds;
		return temp;
	}
	Double TimeSpanValue::get_TotalMinutes()
	{
		return (Double)value.value / TicksPerMinute;
	}
	Double TimeSpanValue::get_TotalSeconds()
	{
		return (Double)value.value / TicksPerSecond;
	}
	TimeSpan DotnetLibrary::TimeSpanValue::get_AsTimeSpan()
	{
		return value;
	}
	TimeSpan TimeSpanValue::Add(const TimeSpan& ts)
	{
		Int64 result = value.value + ts.value;
		if ((value.value >> 63 == ts.value >> 63) && (value.value >> 63 != result >> 63))
			throw new OverflowException();
		return TimeSpan(result);
	}
	Int32 TimeSpanValue::Compare(const TimeSpan& t1, const TimeSpan& t2)
	{
		if (t1.value > t2.value) return 1;
		if (t1.value < t2.value) return -1;
		return 0;
	}
	Int32 TimeSpanValue::CompareTo(TimeSpan valueToCompare)
	{
		Int64 t = valueToCompare.value;
		if (value.value > t) return 1;
		if (value.value < t) return -1;
		return 0;
	}
	Int32 TimeSpanValue::CompareTo(Object* obj)
	{
		if (obj == nullptr) return 1;
		if (obj->GetRawDataType() != TimeSpanType)
			throw new ArgumentException();
		Int64 t = obj->get_AsTimeSpan().value;
		if (value.value > t) return 1;
		if (value.value < t) return -1;
		return 0;
	}
	Double TimeSpanValue::Divide(TimeSpan ts)
	{
		return (Double)value.value / (Double)ts.value;
	}
	TimeSpan TimeSpanValue::Divide(Double divisor)
	{
		if (DoubleValue::IsNaN(divisor)) {
			throw new ArgumentException();
		}
		Double ticks = Math::Round(value.value / divisor);
		if (ticks > Int64Value::MaxValue || ticks < Int64Value::MinValue || DoubleValue::IsNaN(ticks)) {
			throw new OverflowException();
		}
		return FromTicks((Int64)ticks);
	}
	TimeSpan TimeSpanValue::Duration()
	{
		if (value.value == TimeSpanValue::MinValue.value)
			throw new OverflowException();
		Int64 t = (Int64)value.value;
		return TimeSpan(t >= 0 ? t : -t);
	}
	Boolean TimeSpanValue::Equals(const TimeSpan& valueToCompare)
	{
		return value.value == valueToCompare.value;
	}
	Boolean TimeSpanValue::Equals(const TimeSpan& valueToCompare, const TimeSpan& valueToCompare2)
	{
		return valueToCompare.value == valueToCompare2.value;
	}
	Boolean TimeSpanValue::Equals(Object* valueToCompare)
	{
		if (valueToCompare != nullptr && valueToCompare->GetRawDataType() == TimeSpanType) {
			return value.value == valueToCompare->get_AsTimeSpan().value;
		}
		return false;
	}
	Int32 TimeSpanValue::FormatString(Char* where, const Int32 whereSize)
	{
		StringBuilder	stringBuilder;

		Int32 day = (Int32)(value.value / TicksPerDay);
		Int64 time = value.value % TicksPerDay;
		if (value.value < 0) {
			stringBuilder.Append(L'-');
			day = -day;
			time = -time;
		}
		Int32	hours = (Int32)(time / TicksPerHour) % 24;
		Int32	min = (Int32)(time / TicksPerMinute) % 60;
		Int32	sec = (Int32)(time / TicksPerSecond) % 60;
		Int32	fractional = (Int32)(time % TicksPerSecond);
		Char	date[32];
		Int32 length;
#ifdef __MINGW32__
		if (day != 0)
			length = swprintf(date, L"%d.%02d:%02d:%02d", day, hours, min, sec);
		else
			length = swprintf(date, L"%02d:%02d:%02d", hours, min, sec);
#else
		if (day != 0)
			length = swprintf(date, 32, L"%d.%02d:%02d:%02d", day, hours, min, sec);
		else
			length = swprintf(date, 32, L"%02d:%02d:%02d", hours, min, sec);
#endif
		stringBuilder.Append(date, length);
		if (fractional != 0) {
			stringBuilder.Append((Char)'.');
			Char	frac[32];
			Int32Value factValue(fractional);
			Int32 fracLength = factValue.FormatString(frac, 32);
			stringBuilder.Append(frac, fracLength);
			stringBuilder.Append(L'0', 7 - fracLength);
		}
		return(stringBuilder.FormatString(where, whereSize));
	}
	TimeSpan TimeSpanValue::FromDays(const Double data)
	{
		return Interval(data, TicksPerDay);
	}
	TimeSpan TimeSpanValue::FromHours(const Double data)
	{
		return Interval(data, TicksPerHour);
	}
	TimeSpan TimeSpanValue::FromMilliseconds(const Double data)
	{
		return Interval(data, TicksPerMillisecond);
	}
	TimeSpan TimeSpanValue::FromMinutes(const Double data)
	{
		return Interval(data, TicksPerMinute);
	}
	TimeSpan TimeSpanValue::FromSeconds(const Double data)
	{
		return Interval(data, TicksPerSecond);
	}
	TimeSpan TimeSpanValue::FromTicks(const Int64 data)
	{
		return TimeSpan(data);
	}
	TimeSpan TimeSpanValue::Interval(Double value, Double scale)
	{
		if (DoubleValue::IsNaN(value))
			throw new ArgumentException();
		Double ticks = value * scale;
		if ((ticks > Int64Value::MaxValue) || (ticks < Int64Value::MinValue))
			throw new OverflowException();
		return (Int64)ticks;
	}
	TimeSpan TimeSpanValue::Multiply(Double factor)
	{
		if (DoubleValue::IsNaN(factor)) {
			throw new ArgumentException();
		}
		Double ticks = Math::Round(value.value * factor);
		if (ticks > Int64Value::MaxValue || ticks < Int64Value::MinValue) {
			throw new OverflowException();
		}
		return FromTicks((Int64)ticks);
	}
	TimeSpan TimeSpanValue::Negate()
	{
		if (value.value == TimeSpanValue::MinValue.value)
			throw new OverflowException();
		return -((Int64)value.value);
	}
	TimeSpan TimeSpanValue::Parse(String* s)
	{
		TimeSpan	results;
		if (s == nullptr)
			throw new ArgumentNullException();
		Boolean good = TryParse(s, results);
		if (!good)
			throw new FormatException();
		return(results);
	}
	TimeSpan TimeSpanValue::Subtract(const TimeSpan& ts)
	{
		Int64 result = value.value - ts.value;
		if ((value.value >> 63 == ts.value >> 63) && (value.value >> 63 != result >> 63))
			throw new OverflowException();
		return TimeSpan(result);
	}
	Boolean TimeSpanValue::TryParse(String* s, TimeSpan& result)
	{
		Int64	numbers[] = { 0,0,0,0 };
		Int32	amount = 0;
		Int64	fractional = 0;
		Char* chars = s->get_Buffer();
		Int32	length = s->get_Length();
		Int32	sign;
		Boolean	negate = false;
		if (*chars == L'-') {
			negate = true;
			++chars;
			--length;
		}
		while (length > 0) {
			UInt64	number;
			Int32 digits = 1;
			if (!CharValue::IsDigit(*chars))
				break;
			if (length > 2 && chars[1] != L':' && chars[2] != L':' && chars[2] != L'.' && chars[1] != L'.')
				break;
			if (CharValue::IsDigit(chars[1]))
				digits = 2;
			UInt64Value::TryParseInternal(chars, digits, number, sign);
			numbers[amount++] = (Int64)number;
			chars += digits + 1;
			length -= digits + 1;
		}
		Int64 frac = TicksPerSecond;
		while (frac > 1 && length > 0 && CharValue::IsDigit(*chars)) {
			frac /= 10;
			fractional += (Int64)(*chars - L'0') * frac;
			++chars;
			--length;
		}
		//for (; length > 0; --length) {
		//	if (chars[length - 1] != L'0')
		//		break;
		//}
		//if (length > 0)
		//	if (!UInt64Value::TryParseInternal(chars, length, fractional, sign))
		//		return(false);
	//}
		Int64 days = 0;
		Int64 index = 0;
		if (amount > 3 || amount == 1)
			days += numbers[index++] * TicksPerDay;
		Int64 hours = numbers[index++] * TicksPerHour;
		Int64 minutes = numbers[index++] * TicksPerMinute;
		Int64 seconds = numbers[index++] * TicksPerSecond;
		Int64 ticks = fractional + days + hours + minutes + seconds;
		if (negate)
			ticks = -ticks;
		result = ticks;
		return true;
	}
	TimeSpan TimeSpanValue::op_Addition(const TimeSpan& ts1, const TimeSpan& ts2)
	{
		return TimeSpanValue(ts1).Add(ts2);
	}
	Double TimeSpanValue::op_Division(const TimeSpan& ts1, const TimeSpan& ts2)
	{
		return TimeSpanValue(ts1).Divide(ts2);
	}
	TimeSpan TimeSpanValue::op_Division(const TimeSpan& ts1, const Double& divisor)
	{
		return TimeSpanValue(ts1).Divide(divisor);
	}
	Boolean TimeSpanValue::op_Equality(const TimeSpan& ts1, const TimeSpan& ts2)
	{
		return TimeSpanValue(ts1).Equals(ts2);
	}
	Boolean TimeSpanValue::op_GreaterThan(const TimeSpan& ts1, const TimeSpan& ts2)
	{
		return ts1.value > ts2.value;
	}
	Boolean TimeSpanValue::op_GreaterThanOrEqual(const TimeSpan& ts1, const TimeSpan& ts2)
	{
		return ts1.value >= ts2.value;
	}
	Boolean TimeSpanValue::op_Inequality(const TimeSpan& ts1, const TimeSpan& ts2)
	{
		return !TimeSpanValue(ts1).Equals(ts2);
	}
	Boolean TimeSpanValue::op_LessThan(const TimeSpan& ts1, const TimeSpan& ts2)
	{
		return ts1.value < ts2.value;
	}
	Boolean TimeSpanValue::op_LessThanOrEqual(const TimeSpan& ts1, const TimeSpan& ts2)
	{
		return ts1.value <= ts2.value;
	}
	TimeSpan TimeSpanValue::op_Multiply(const Double& factor, const TimeSpan& ts1)
	{
		return TimeSpanValue(ts1).Multiply(factor);
	}
	TimeSpan TimeSpanValue::op_Multiply(const TimeSpan& ts1, const Double& factor)
	{
		return TimeSpanValue(ts1).Multiply(factor);
	}
	TimeSpan TimeSpanValue::op_Subtraction(const TimeSpan& ts1, const TimeSpan& ts2)
	{
		return TimeSpanValue(ts1).Subtract(ts2);
	}
	TimeSpan TimeSpanValue::op_UnaryNegation(const TimeSpan& t1)
	{
		if (t1.value == TimeSpanValue::MinValue.value)
			throw new OverflowException();
		return TimeSpan(-((Int64)t1.value));
	}
	TimeSpan TimeSpanValue::op_UnaryPlus(const TimeSpan& t1)
	{
		return t1;
	}
}
