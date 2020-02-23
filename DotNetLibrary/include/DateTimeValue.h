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

	const Int64 MinTicks = 0;
	const Int64 MaxTicks = DaysTo10000 * TicksPerDay - 1;
	const Int64 MaxMillis = (Int64) DaysTo10000 * MillisPerDay;
	const Int64 MaxSeconds = 0x000000d6bf94d5e5LL;
	const Int64 MinSeconds = 0xffffff29406b2a1bLL;
	const Int64 MaxMilliSeconds = 0x000346dc5d638865LL;
	const Int64 MinMilliSeconds = 0xfffcb923a29c779bLL;
	const Int32 DatePartYear = 0;
	const Int32 DatePartDayOfYear = 1;
	const Int32 DatePartMonth = 2;
	const Int32 DatePartDay = 3;
	// Number of days from 1/1/0001 to 12/31/1600
	const Int64 FileTimeOffset = DaysTo1601 * TicksPerDay;
	// Enumeration to represent days in a week
	enum DayOfWeek
	{
		Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday
	};
	/**
	 * Boxing class for DateTime value
	 * Derived from Object so it can be treated as Object*
	 */
	class DLL_EXPORT DateTimeValue: public ValueType
	{
	private:
		DateTime value;

		/**
		 * Get Time zone as TimeSpan
		 * @return Time zone delta as TimeSpan
		 */
		TimeSpan GetTimeZone();
	public:
		DateTimeValue() {
			value = 0;
		}
		DateTimeValue(DateTime val) {
			value.value = val.value;
		}
		/**
		 * Convert as DateTime
		 * @return value as DateTime
		 */
		virtual DateTime get_AsDateTime();
		/**
		 * Get as Date
		 * @return value as Date
		 */
		DateTime get_Date();
		/**
		 * Get as Day
		 * @return value as Day
		 */
		Int32 get_Day();
		/**
		 * Get as Day of Week
		 * @return value as Day of week
		 */
		DayOfWeek get_DayOfWeek();
		/**
		 * Get as Day of Year
		 * @return value as Day of Year
		 */
		Int32 get_DayOfYear();
		/**
		 * Get as Hour
		 * @return value as Hour
		 */
		Int32 get_Hour();
		/**
		 * Get as MilliSecond
		 * @return value as Mi8lliSecond
		 */
		Int32 get_Millisecond();
		/**
		 * Get as Minute
		 * @return value as Minute
		 */
		Int32 get_Minute();
		/**
		 * Get as Month
		 * @return value as Month
		 */
		Int32 get_Month();
		/**
		 * Get as Local Time
		 * @return value as Local Time
		 */
		static DateTime get_Now();
		/**
		 * Get as Seconds
		 * @return value as Seconds
		 */
		Int32 get_Second();
		/**
		 * Get as Ticks
		 * @return value as Ticks
		 */
		Int64 get_Ticks() {
			return (value.value);
		}
		/**
		 * Get as Time of Day
		 * @return value as Time of Day
		 */
		TimeSpan get_TimeOfDay();
		/**
		 * Get todays date
		 * @return todays date
		 */
		static DateTime get_Today();
		/**
		 * Get as UTC Time
		 * @return value as UTC Time
		 */
		static DateTime get_UtcNow();
		/**
		 * Get as Year
		 * @return value as Year
		 */
		Int32 get_Year();
		/**
		 * Add value to date scaled up to prober units
		 * @param value to add
		 * @param scale scale factor
		 * @return DateTime with value added
		 */
		DateTime Add(Double value, Int32 scale);
		/**
		 * Add TimeSpan
		 * @param ts TimeSpan to add
		 * @return DateTime with added TimeSpan
		 */
		DateTime Add(const TimeSpan ts);
		/**
		 * Add days
		 * @param delta amount of days to add
		 * @return DateTime with added value
		 */
		DateTime AddDays(const Double delta);
		/**
		 * Add hours
		 * @param delta amount of hours to add
		 * @return DateTime with added value
		 */
		DateTime AddHours(const Double delta);
		/**
		 * Add Milliseconds
		 * @param delta amount of Milliseconds to add
		 * @return DateTime with added value
		 */
		DateTime AddMilliseconds(const Double delta);
		/**
		 * Add Minutes
		 * @param delta amount of Minutes to add
		 * @return DateTime with added value
		 */
		DateTime AddMinutes(const Double delta);
		/**
		 * Add Months
		 * @param delta amount of Months to add
		 * @return DateTime with added value
		 */
		DateTime AddMonths(const Int32 delta);
		/**
		 * Add Seconds
		 * @param delta amount of Seconds to add
		 * @return DateTime with added value
		 */
		DateTime AddSeconds(const Double delta);
		/**
		 * Add Ticks
		 * @param delta amount of Ticks to add
		 * @return DateTime with added value
		 */
		DateTime AddTicks(const Int64 delta);
		/**
		 * Add Years
		 * @param delta amount of Years to add
		 * @return DateTime with added value
		 */
		DateTime AddYears(const Int32 delta);
		/**
		 * Compare to value -1 < 0 > 1
		 * @param valueToCompare value to compare
		 * @return -1, 0 ,1
		 */
		static Int32 Compare(const DateTime& date1, const DateTime& date2);
		/**
		 * Compare to value -1 < 0 > 1
		 * @param valueToCompare value to compare
		 * @return -1, 0 ,1
		 */
		Int32 CompareTo(const DateTime& ts1);
		/**
		 * Compare to Object value -1 < 0 > 1
		 * @param valueToCompare value to compare
		 * @return -1, 0 ,1
		 */
		Int32 CompareTo(Object* obj);
		/**
		 * Amount of days in month
		 * @param year with months
		 * @param month with days
		 * @return amount of days in this month of year
		 */
		static Int32 DaysInMonth(Int32 year, Int32 month);
		/**
		 * Are values equal
		 * @param valueToCompare value to compare
		 * @return true if equal
		 */
		bool Equals(const DateTime& valueToCompare);
		/**
		 * Are values equal
		 * @param valueToCompare value to compare
		 * @return true if equal
		 */
		static bool Equals(const DateTime& valueToCompare, const DateTime& valueToCompare2);
		/**
		 * Are values equal
		 * @param valueToCompare value to compare
		 * @return true if equal
		 */
		virtual bool Equals(Object* valueToCompare);
		/**
		 * Is this daylight savings time
		 * @return true if is daylight savings time
		 */
		Boolean IsDaylightSavingTime();
		/**
		 * Is this year a leap year
		 * @param year to check
		 * @return true if leap year
		 */
		static Boolean IsLeapYear(Int32 year);
		/**
		 * Format this string
		 * @param where to place characters
		 * @param whereSize size of where
		 * @return amount of characters placed in where
		 */
		virtual Int32 FormatString(Char* where, const Int32 whereSize);
		/**
		 * Get date part
		 * @param part to get
		 * @return part of date
		 */
		Int32 GetDatePart(Int32 part);
		/**
		 * Get date parts
		 * @param year part
		 * @param month part
		 * @param day part
		 */
		void GetDatePart(Int32& year, Int32& month, Int32& day);
		/**
		 * Get raw type of this boxed object
		 * @return raw type
		 */
		virtual DataType GetRawDataType() {
			return (DateTimeType);
		}
		/**
		 * Subtract from date
		 * @param date1 to subtract
		 * @return delta TimeSpan
		 */
		TimeSpan Subtract(const DateTime& date1);
		/**
		 * Subtract from date
		 * @param ts TimeSpan to subtract
		 * @return delta Date
		 */
		DateTime Subtract(const TimeSpan ts);
		/**
		 * Convert to Local time
		 * @return local time
		 */
		DateTime ToLocalTime();
		/**
		 * Convert to local time
		 * @param throwOnOverflow throw exception if overflow
		 * @return local time
		 */
		DateTime ToLocalTime(Boolean throwOnOverflow);
		/**
		 * Convert to UTC
		 * @return UTC
		 */
		DateTime ToUniversalTime();
		/**
		 * Add DateTime to TimeSpan
		 * @param ts1 DateTime
		 * @param ts2 TimeSpan
		 * @return new DateTime
		 */
		static DateTime op_Addition(const DateTime& ts1, const TimeSpan ts2);
		/**
		 * Are two dataTimes Equal
		 * @param ts1 DateTime 1
		 * @param ts2 DateTIme 2
		 * @return true if equal
		 */
		static Boolean op_Equality(const DateTime& ts1, const DateTime& ts2);
		/**
		 * Is one DateTime greater than another
		 * @param ts1 DateTime 1
		 * @param ts2 DateTIme 2
		 * @return true if greater
		 */
		static Boolean op_GreaterThan(const DateTime& ts1, const DateTime& ts2);
		/**
		 * Is one DateTime greater than another or equal to
		 * @param ts1 DateTime 1
		 * @param ts2 DateTIme 2
		 * @return true if greater then or equal to
		 */
		static Boolean op_GreaterThanOrEqual(const DateTime& ts1, const DateTime& ts2);
		/**
		 * Are two dataTimes not Equal
		 * @param ts1 DateTime 1
		 * @param ts2 DateTIme 2
		 * @return true if equal
		 */
		static Boolean op_Inequality(const DateTime& ts1, const DateTime& ts2);
		/**
		 * Is one DateTime less than another
		 * @param ts1 DateTime 1
		 * @param ts2 DateTIme 2
		 * @return true if less
		 */
		static Boolean op_LessThan(const DateTime& ts1, const DateTime& ts2);
		/**
		 * Is one DateTime less than another or equal to
		 * @param ts1 DateTime 1
		 * @param ts2 DateTIme 2
		 * @return true if less then or equal to
		 */
		static Boolean op_LessThanOrEqual(const DateTime& ts1, const DateTime& ts2);
		/**
		 * Subtract from date
		 * @param ts1 DateTime 1
		 * @param ts2 Date to subtract
		 * @return delta TimeSpan
		 */
		static TimeSpan op_Subtraction(const DateTime& ts1, const DateTime& ts2);
		/**
		 * Subtract from date
		 * @param ts1 DateTime 1
		 * @param ts2 TimeSpan to subtract
		 * @return delta DateTime
		 */
		static DateTime op_Subtraction(const DateTime& ts1, const TimeSpan ts2);
		/**
		 * Max value
		 */
		static DateTime MaxValue;
		/**
		 * Min value
		 */
		static DateTime MinValue;
	};
	/**
	 * Convert time parts to ticks
	 * @param days part
	 * @param hour part
	 * @param minute part
	 * @param second part
	 * @param milliseconds part
	 * @return ticks
	 */
	Int64 TimePartsToTicks(Int32 days, Int32 hour, Int32 minute, Int32 second, Int32 milliseconds);
}
