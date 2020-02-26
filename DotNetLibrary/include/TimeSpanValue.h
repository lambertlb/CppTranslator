// Copyright (c) 2019 LLambert
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this
// software and associated documentation files (the "Software"), to deal in the Software
// without restriction, including without limitation the rights to use, copy, modify, merge,
// publish, distribute, sub-license, and/or sell copies of the Software, and to permit persons
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
#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	/*!
	 * Boxing class for TimeSpan value
	 * Derived from Object so it can be treated as Object*
	 */
	class DLL_EXPORT TimeSpanValue: public ValueType
	{
		TimeSpan value;
	public:
		TimeSpanValue() {
			value = 0;
		}
		TimeSpanValue(const UInt64 value2) {
			value = value2;
		}
		;
		TimeSpanValue(const TimeSpan value2) {
			value = value2.value;
		}
		;

		/*!
		 * Convert to TimeSpan
		 * @return Object converted to TimeSpan
		 */
		virtual TimeSpan get_AsTimeSpan();
		/*!
		 * Get days
		 * @return days
		 */
		Int32 get_Days();
		/*!
		 * Get hours
		 * @return hours
		 */
		Int32 get_Hours();
		/*!
		 * Get Milliseconds
		 * @return Milliseconds
		 */
		Int32 get_Milliseconds();
		/*!
		 * Get Minutes
		 * @return Minutes
		 */
		Int32 get_Minutes();
		/*!
		 * Get Seconds
		 * @return Seconds
		 */
		Int32 get_Seconds();
		/*!
		 * Get Ticks
		 * @return Ticks
		 */
		Int64 get_Ticks();
		/*!
		 * Get Total Days
		 * @return Total Days
		 */
		Double get_TotalDays();
		/*!
		 * Get Total Hours
		 * @return Total Hours
		 */
		Double get_TotalHours();
		/*!
		 * Get Total Milliseconds
		 * @return Total Milliseconds
		 */
		Double get_TotalMilliseconds();
		/*!
		 * Get Total Minutes
		 * @return Total Minutes
		 */
		Double get_TotalMinutes();
		/*!
		 * Get Total Seconds
		 * @return Total Seconds
		 */
		Double get_TotalSeconds();
		/*!
		 * Add to TimeSpan
		 * @param ts TimeSpan to add
		 * @return value of this instance plus the value of ts.
		 */
		TimeSpan Add(const TimeSpan& ts);
		/*!
		 * Compare to value -1 < 0 > 1
		 * @param ts1 TimeSpan 1
		 * @param ts2 TimeSpan 1
		 * @return -1, 0 ,1
		 */
		static Int32 Compare(const TimeSpan& ts1, const TimeSpan& ts2);
		/*!
		 * Compare to Object value -1 < 0 > 1
		 * @param valueToCompare value to compare
		 * @return -1, 0 ,1
		 */
		virtual Int32 CompareTo(TimeSpan valueToCompare);
		/*!
		 * Compare to Object value -1 < 0 > 1
		 * @param valueToCompare value to compare
		 * @return -1, 0 ,1
		 */
		Int32 CompareTo(Object* obj);
		/*!
		 * Divide by TimeSpan
		 * @param ts Divisor
		 * @return result of division of this instance by the value of the ts.
		 */
		Double Divide(TimeSpan ts);
		/*!
		 * Divide by double
		 * @param divisor to divide by
		 * @return result of division of this instance by the value of the divisor.
		 */
		TimeSpan Divide(Double divisor);
		/*!
		 * Absolute value of time
		 * @return Absolute value of time
		 */
		TimeSpan Duration();
		/*!
		 * Are values equal
		 * @param valueToCompare value to compare
		 * @return true if equal
		 */
		Boolean Equals(const TimeSpan& valueToCompare);
		/*!
		 * Are values equal
		 * @param valueToCompare value to compare
		 * @param valueToCompare2 value to compare
		 * @return true if equal
		 */
		static Boolean Equals(const TimeSpan& valueToCompare, const TimeSpan& valueToCompare2);
		/*!
		 * Are values equal
		 * @param valueToCompare value to compare
		 * @return true if equal
		 */
		virtual Boolean Equals(Object* valueToCompare);
		/*!
		 * TimeSpan from Days
		 * @param data Days
		 * @return TimeSpan
		 */
		static TimeSpan FromDays(const Double data);
		/*!
		 * TimeSpan from Milliseconds
		 * @param data Milliseconds
		 * @return TimeSpan
		 */
		static TimeSpan FromHours(const Double data);
		/*!
		 * TimeSpan from Hours
		 * @param data Hours
		 * @return TimeSpan
		 */
		static TimeSpan FromMilliseconds(const Double data);
		/*!
		 * TimeSpan from Minutes
		 * @param data Minutes
		 * @return TimeSpan
		 */
		static TimeSpan FromMinutes(const Double data);
		/*!
		 * TimeSpan from Seconds
		 * @param data Seconds
		 * @return TimeSpan
		 */
		static TimeSpan FromSeconds(const Double data);
		/*!
		 * TimeSpan from Ticks
		 * @param data Ticks
		 * @return TimeSpan
		 */
		static TimeSpan FromTicks(const Int64 data);
		/*!
		 * Format this string
		 * @param where to place characters
		 * @param whereSize size of where
		 * @return amount of characters placed in where
		 */
		virtual Int32 FormatString(Char* where, const Int32 whereSize);
		/*!
		 * Get raw type of this boxed object
		 * @return raw type
		 */
		virtual DataType GetRawDataType() {
			return (TimeSpanType);
		}
		;
		/*!
		 * Convert interval to TimeSpan
		 * @param value interval
		 * @param scale of interval
		 * @return TimeSpan
		 */
		static TimeSpan Interval(Double value, Double scale);
		/*!
		 * Multiply by factor
		 * @param factor to multiply by
		 * @return TimeSpan
		 */
		TimeSpan Multiply(Double factor);
		/*!
		 * Negate TimeSpan
		 * @return Negated TimeSpan
		 */
		TimeSpan Negate();
		/*!
		 * Parse value from string
		 * @param stringToParse string to parse
		 * @return value
		 */
		static TimeSpan Parse(String* s);
		/*!
		 * Subtract two TimeSpans
		 * @param ts1 TimeSpan to Subtract
		 * @return delta TimeSpan
		 */
		TimeSpan Subtract(const TimeSpan& ts1);
		/*!
		 * Try parse value from string
		 * @param stringToParse string to parse
		 * @param result parse value
		 * @return true if good parse
		 */
		static Boolean TryParse(String* s, TimeSpan& result);
		/*!
		 * Add two TimeSpans
		 * @param ts1 TimeSpan 1
		 * @param ts2 TimeSpan 2
		 * @return Sum of two TimeSpans
		 */
		static TimeSpan op_Addition(const TimeSpan& ts1, const TimeSpan& ts2);
		/*!
		 * Divide two TimeSpans
		 * @param ts1 TimeSpan 1
		 * @param ts2 TimeSpan 2
		 * @return Result of dividing two TimeSpans
		 */
		static Double op_Division(const TimeSpan& ts1, const TimeSpan& ts2);
		/*!
		 * Divide TimeSpan by double
		 * @param ts1 TimeSpan 1
		 * @param divisor to divide by
		 * @return Result of division
		 */
		static TimeSpan op_Division(const TimeSpan& ts1, const Double& divisor);
		/*!
		 * Are two TimeSpans Equal
		 * @param ts1 TimeSpan 1
		 * @param ts2 TimeSpan 2
		 * @return true if equal
		 */
		static Boolean op_Equality(const TimeSpan& ts1, const TimeSpan& ts2);
		/*!
		 * Is one TimeSpan greater than another
		 * @param ts1 TimeSpan 1
		 * @param ts2 TimeSpan 2
		 * @return true if greater than
		 */
		static Boolean op_GreaterThan(const TimeSpan& ts1, const TimeSpan& ts2);
		/*!
		 * Is one TimeSpan greater than or equal to another
		 * @param ts1 TimeSpan 1
		 * @param ts2 TimeSpan 2
		 * @return true if greater than or equal to
		 */
		static Boolean op_GreaterThanOrEqual(const TimeSpan& ts1, const TimeSpan& ts2);
		/*!
		 * Are two TimeSpans not Equal
		 * @param ts1 TimeSpan 1
		 * @param ts2 TimeSpan 2
		 * @return true if equal
		 */
		static Boolean op_Inequality(const TimeSpan& ts1, const TimeSpan& ts2);
		/*!
		 * Is one TimeSpan less than another
		 * @param ts1 TimeSpan 1
		 * @param ts2 TimeSpan 2
		 * @return true if less than
		 */
		static Boolean op_LessThan(const TimeSpan& ts1, const TimeSpan& ts2);
		/*!
		 * Is one TimeSpan less than or equal to another
		 * @param ts1 TimeSpan 1
		 * @param ts2 TimeSpan 2
		 * @return true if less than or equal to
		 */
		static Boolean op_LessThanOrEqual(const TimeSpan& ts1, const TimeSpan& ts2);
		/*!
		 * Multiply by factor
		 * @param ts1 TimeSpan 1
		 * @param factor to multiply by
		 * @return TimSpan multiplied by factor
		 */
		static TimeSpan op_Multiply(const TimeSpan& ts1, const Double& factor);
		/*!
		 * Multiply by factor
		 * @param factor to multiply by
		 * @param ts1 TimeSpan 1
		 * @return TimSpan multiplied by factor
		 */
		static TimeSpan op_Multiply(const Double& factor, const TimeSpan& ts1);
		/*!
		 * Subtract two TimeSpans
		 * @param ts1 TimeSpan 1
		 * @param ts2 TimeSpan 2
		 * @return delta TimeSpan
		 */
		static TimeSpan op_Subtraction(const TimeSpan& ts1, const TimeSpan& ts2);
		/*!
		 * Negate TimeSpan
		 * @param ts1 TimeSpan to Negate
		 * @return negated TimeSpan
		 */
		static TimeSpan op_UnaryNegation(const TimeSpan& ts1);
		/*!
		 * Unary plus of TimeSpan
		 * @param ts1 TimeSpan
		 * @return positive TimeSpan
		 */
		static TimeSpan op_UnaryPlus(const TimeSpan& ts1);
		/*!
		 * Max value
		 */
		static TimeSpan MaxValue;
		/*!
		 * Min value
		 */
		static TimeSpan MinValue;
		/*!
		 * number of ticks in 1 Millisecond
		 */
		static Int64 TicksPerMillisecond;
		/*!
		 * number of ticks in 1 Second
		 */
		static Int64 TicksPerSecond;
		/*!
		 * number of ticks in 1 Minute
		 */
		static Int64 TicksPerMinute;
		/*!
		 * number of ticks in 1 Hour
		 */
		static Int64 TicksPerHour;
		/*!
		 * number of ticks in 1 day
		 */
		static Int64 TicksPerDay;
		/*!
		 * Zero TimeSpan
		 */
		static TimeSpan Zero;
	};
}
