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
#include "gtest/gtest.h"
#include <DotnetTypes.h>
#include <time.h>
using namespace DotnetLibrary;

TEST(DateTimeTests, ConstructorTest) {
	DateTimeValue	value(DateTime(DateTimeValue::MaxValue.value));
	String* time = value.ToString();
	DateTimeValue	value2(DateTime(DateTimeValue::MinValue.value));
	String* time2 = value2.ToString();
	ASSERT_TRUE(wcscmp(time->get_Buffer(), L"12/31/9999 11:59:59 PM") == 0);
	ASSERT_TRUE(wcscmp(time2->get_Buffer(), L"1/1/1 0:00:00 AM") == 0);
}
TEST(DateTimeTests, get_DateTest) {
	DateTimeValue	value(DateTime(2003, 7, 23, 12, 30, 30, 100));
	DateTime date = value.get_Date();
	ASSERT_TRUE(DateTimeValue(date).get_Ticks() == 631945152000000000);
}
TEST(DateTimeTests, get_DayTest) {
	DateTimeValue	value(DateTime(2003, 7, 23, 12, 30, 30, 100));
	ASSERT_TRUE(value.get_Day() == 23);
}
TEST(DateTimeTests, get_DayOfWeekTest) {
	DateTimeValue	value(DateTime(2003, 7, 23, 12, 30, 30, 100));
	ASSERT_TRUE(value.get_DayOfWeek() == Wednesday);
}
TEST(DateTimeTests, get_DayOfYearTest) {
	DateTimeValue	value(DateTime(2003, 7, 23, 12, 30, 30, 100));
	ASSERT_TRUE(value.get_DayOfYear() == 204);
}
TEST(DateTimeTests, get_HourTest) {
	DateTimeValue	value(DateTime(2003, 7, 23, 12, 30, 30, 100));
	ASSERT_TRUE(value.get_Hour() == 12);
}
TEST(DateTimeTests, get_MillisecondTest) {
	DateTimeValue	value(DateTime(2003, 7, 23, 12, 30, 30, 100));
	ASSERT_TRUE(value.get_Millisecond() == 100);
}
TEST(DateTimeTests, get_MinuteTest) {
	DateTimeValue	value(DateTime(2003, 7, 23, 12, 30, 30, 100));
	ASSERT_TRUE(value.get_Minute() == 30);
}
TEST(DateTimeTests, get_MonthTest) {
	DateTimeValue	value(DateTime(2003, 7, 23, 12, 30, 30, 100));
	ASSERT_TRUE(value.get_Month() == 7);
}
TEST(DateTimeTests, get_NowTest) {
	DateTimeValue	value(DateTimeValue::get_Now());
	time_t rawtime;
	struct tm* timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	ASSERT_TRUE(value.get_Month() == timeinfo->tm_mon + 1);
	ASSERT_TRUE(value.get_Day() == timeinfo->tm_mday);
	ASSERT_TRUE(value.get_Year() == timeinfo->tm_year + 1900);
	ASSERT_TRUE(value.get_Hour() == timeinfo->tm_hour);
	ASSERT_TRUE(value.get_Minute() == timeinfo->tm_min);
	ASSERT_TRUE(value.get_Second() == timeinfo->tm_sec);
}
TEST(DateTimeTests, get_SecondTest) {
	DateTimeValue	value(DateTime(2003, 7, 23, 12, 30, 30, 100));
	ASSERT_TRUE(value.get_Second() == 30);
}
TEST(DateTimeTests, get_TimeOfDayTest) {
	DateTimeValue	value(DateTime(2003, 7, 23, 12, 30, 30, 100));
	TimeSpan date = value.get_TimeOfDay();
	ASSERT_TRUE(TimeSpanValue(date).get_Ticks() == 450301000000);
}
TEST(DateTimeTests, get_TodayTest) {
	DateTimeValue	value(DateTimeValue::get_Today());
	time_t rawtime;
	struct tm* timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	ASSERT_TRUE(value.get_Month() == timeinfo->tm_mon + 1);
	ASSERT_TRUE(value.get_Day() == timeinfo->tm_mday);
	ASSERT_TRUE(value.get_Year() == timeinfo->tm_year + 1900);
	ASSERT_TRUE(value.get_Hour() == 0);
	ASSERT_TRUE(value.get_Minute() == 0);
	ASSERT_TRUE(value.get_Second() == 0);
}
TEST(DateTimeTests, get_UtcNowTest) {
	DateTimeValue	value(DateTimeValue::get_UtcNow());
	time_t rawtime;
	struct tm* timeinfo;

	time(&rawtime);
	timeinfo = gmtime(&rawtime);
	ASSERT_TRUE(value.get_Month() == timeinfo->tm_mon + 1);
	ASSERT_TRUE(value.get_Day() == timeinfo->tm_mday);
	ASSERT_TRUE(value.get_Year() == timeinfo->tm_year + 1900);
	ASSERT_TRUE(value.get_Hour() == timeinfo->tm_hour);
	ASSERT_TRUE(value.get_Minute() == timeinfo->tm_min);
	ASSERT_TRUE(value.get_Second() == timeinfo->tm_sec);
}
TEST(DateTimeTests, get_YearTest) {
	DateTimeValue	value(DateTime(2003, 7, 23, 12, 30, 30, 100));
	ASSERT_TRUE(value.get_Year() == 2003);
}
TEST(DateTimeTests, AddTest) {
	DateTimeValue	value(DateTime(2003, 7, 23, 12, 30, 30, 100));
	TimeSpan	value2(0, 2, 0, 0);
	ASSERT_TRUE(DateTimeValue(value.Add(value2)).get_Ticks() == 631945674301000000);
}
TEST(DateTimeTests, AddDaysTest) {
	DateTimeValue	value(DateTime(2003, 7, 23, 12, 30, 30, 100));
	ASSERT_TRUE(DateTimeValue(value.AddDays(1.5)).get_Ticks() == 631946898301000000);
}
TEST(DateTimeTests, AddHoursTest) {
	DateTimeValue	value(DateTime(2003, 7, 23, 12, 30, 30, 100));
	ASSERT_TRUE(DateTimeValue(value.AddHours(2.5)).get_Ticks() == 631945692301000000);
}
TEST(DateTimeTests, AddMillisecondsTest) {
	DateTimeValue	value(DateTime(2003, 7, 23, 12, 30, 30, 100));
	ASSERT_TRUE(DateTimeValue(value.AddMilliseconds(159)).get_Ticks() == 631945602302590000);
}
TEST(DateTimeTests, AddMinutesTest) {
	DateTimeValue	value(DateTime(2003, 7, 23, 12, 30, 30, 100));
	ASSERT_TRUE(DateTimeValue(value.AddMinutes(3.2)).get_Ticks() == 631945604221000000);
}
TEST(DateTimeTests, AddMonthsTest) {
	DateTimeValue	value(DateTime(2003, 7, 23, 12, 30, 30, 100));
	ASSERT_TRUE(DateTimeValue(value.AddMonths(5)).get_Ticks() == 632077794301000000);
}
TEST(DateTimeTests, AddSecondsTest) {
	DateTimeValue	value(DateTime(2003, 7, 23, 12, 30, 30, 100));
	ASSERT_TRUE(DateTimeValue(value.AddSeconds(6.66)).get_Ticks() == 631945602367600000);
}
TEST(DateTimeTests, AddTicksTest) {
	DateTimeValue	value(DateTime(2003, 7, 23, 12, 30, 30, 100));
	ASSERT_TRUE(DateTimeValue(value.AddTicks(666)).get_Ticks() == 631945602301000666);
}
TEST(DateTimeTests, AddYearsTest) {
	DateTimeValue	value(DateTime(2003, 7, 23, 12, 30, 30, 100));
	ASSERT_TRUE(DateTimeValue(value.AddYears(3)).get_Ticks() == 632892546301000000);
}
TEST(DateTimeTests, CompareTest) {
	DateTimeValue	value(DateTime(2003, 7, 23, 12, 30, 30, 100));
	DateTime		value2 = value.AddYears(3);
	ASSERT_TRUE(DateTimeValue::Compare(value.get_AsDateTime(), value2) < 0);
}
TEST(DateTimeTests, CompareToTest) {
	DateTimeValue	value(DateTime(2003, 7, 23, 12, 30, 30, 100));
	DateTimeValue	value2(value.AddYears(3));
	ASSERT_TRUE(value.CompareTo(value2.get_AsDateTime()) < 0);
	ASSERT_TRUE(value.CompareTo(&value2) < 0);
}
TEST(DateTimeTests, DaysInMonthTest) {
	ASSERT_TRUE(DateTimeValue::DaysInMonth(2003, 1) == 31);
}
TEST(DateTimeTests, EqualsTest) {
	DateTimeValue	value(DateTime(2003, 7, 23, 12, 30, 30, 100));
	DateTimeValue	value2(value.AddYears(3));
	ASSERT_TRUE(!value.Equals(value2.get_AsDateTime()));
	ASSERT_TRUE(value.Equals(value.get_AsDateTime()));
	ASSERT_TRUE(value.Equals(&value));
	ASSERT_TRUE(!value.Equals(&value2));
	ASSERT_TRUE(DateTimeValue::Equals(value.get_AsDateTime(), value.get_AsDateTime()));
	ASSERT_TRUE(!DateTimeValue::Equals(value.get_AsDateTime(), value2.get_AsDateTime()));
}
// Test may fail based on timezone
TEST(DateTimeTests, IsDaylightSavingTimeTest) {
	DateTimeValue	value(DateTime(2003, 1, 23, 12, 30, 30, 100));
	DateTimeValue	value2(DateTime(2003, 9, 23, 12, 30, 30, 100));
	ASSERT_TRUE(!value.IsDaylightSavingTime());
	ASSERT_TRUE(value2.IsDaylightSavingTime());
}
TEST(DateTimeTests, IsLeapYearTest) {
	ASSERT_TRUE(DateTimeValue::IsLeapYear(2004));
	ASSERT_TRUE(!DateTimeValue::IsLeapYear(2005));
}
TEST(DateTimeTests, FormatStringTest) {
	DateTimeValue	value(DateTime(2003, 7, 23, 11, 30, 30, 100));
	DateTimeValue	value2(DateTime(2003, 7, 23, 14, 30, 30, 100));
	Char where[128];
	value.FormatString(where, 128);
	ASSERT_TRUE(wcscmp(where, L"7/23/2003 11:30:30 AM") == 0);
	value2.FormatString(where, 128);
	ASSERT_TRUE(wcscmp(where, L"7/23/2003 2:30:30 PM") == 0);
}
TEST(DateTimeTests, SubtractTest) {
	DateTimeValue	date1(DateTime(1996, 6, 3, 22, 15, 0));
	DateTimeValue	date2(DateTime(1996, 12, 6, 13, 2, 0));
	DateTimeValue	date3(DateTime(1996, 10, 12, 8, 42, 0));
	TimeSpan diff1(date2.Subtract(date1.get_AsDateTime()));
	DateTime date4(date3.Subtract(diff1));
	TimeSpan diff2 = date2.Subtract(date3.get_AsDateTime());
	DateTime date5 = date1.Subtract(diff2);
	// date4 gets 4/9/1996 5:55:00 PM.
	DateTime	result1(1996, 4, 9, 17, 55, 0);
	ASSERT_TRUE(DateTimeValue(result1).Equals(date5));
	ASSERT_TRUE(DateTimeValue(result1).Equals(date4));
}
// may fail because of timing between the two calls
TEST(DateTimeTests, ToLocalTimeTest) {
	DateTimeValue	date1(DateTimeValue::get_Now());
	DateTimeValue	date2(DateTimeValue::get_UtcNow());
	DateTime	localTime = date2.ToLocalTime();
	ASSERT_TRUE(date1.Equals(localTime));
}
// may fail because of timing between the two calls
TEST(DateTimeTests, ToUniversalTimeTest) {
	DateTimeValue	date1(DateTimeValue::get_Now());
	DateTimeValue	date2(DateTimeValue::get_UtcNow());
	DateTime	utc = date1.ToUniversalTime();
	ASSERT_TRUE(date2.Equals(utc));
}
TEST(DateTimeTests, ToStringTest) {
	DateTimeValue	value(DateTime(2003, 7, 23, 11, 30, 30, 100));
	String* result = value.ToString();
	ASSERT_TRUE(wcscmp(result->get_Buffer(), L"7/23/2003 11:30:30 AM") == 0);
}
TEST(DateTimeTests, op_AdditionTest) {
	DateTimeValue	value(DateTime(2003, 7, 23, 12, 30, 30, 100));
	TimeSpan	value2(0, 2, 0, 0);
	ASSERT_TRUE(DateTimeValue(DateTimeValue::op_Addition(value.get_AsDateTime(), value2)).get_Ticks() == 631945674301000000);
}
TEST(DateTimeTests, op_EqualityTest) {
	DateTimeValue	value(DateTime(2003, 7, 23, 12, 30, 30, 100));
	DateTimeValue	value2(DateTime(2003, 8, 23, 12, 30, 30, 100));
	ASSERT_TRUE(DateTimeValue::op_Equality(value.get_AsDateTime(), value.get_AsDateTime()));
	ASSERT_TRUE(!DateTimeValue::op_Equality(value.get_AsDateTime(), value2.get_AsDateTime()));
}
TEST(DateTimeTests, op_GreaterThanTest) {
	DateTimeValue	value(DateTime(2003, 7, 23, 12, 30, 30, 100));
	DateTimeValue	value2(DateTime(2003, 8, 23, 12, 30, 30, 100));
	ASSERT_TRUE(DateTimeValue::op_GreaterThan(value2.get_AsDateTime(), value.get_AsDateTime()));
}
TEST(DateTimeTests, op_GreaterThanOrEqualTest) {
	DateTimeValue	value(DateTime(2003, 7, 23, 12, 30, 30, 100));
	DateTimeValue	value2(DateTime(2003, 8, 23, 12, 30, 30, 100));
	ASSERT_TRUE(DateTimeValue::op_GreaterThanOrEqual(value2.get_AsDateTime(), value.get_AsDateTime()));
	ASSERT_TRUE(DateTimeValue::op_GreaterThanOrEqual(value2.get_AsDateTime(), value2.get_AsDateTime()));
}
TEST(DateTimeTests, op_InequalityTest) {
	DateTimeValue	value(DateTime(2003, 7, 23, 12, 30, 30, 100));
	DateTimeValue	value2(DateTime(2003, 8, 23, 12, 30, 30, 100));
	ASSERT_TRUE(DateTimeValue::op_Inequality(value.get_AsDateTime(), value2.get_AsDateTime()));
	ASSERT_TRUE(!DateTimeValue::op_Inequality(value.get_AsDateTime(), value.get_AsDateTime()));
}
TEST(DateTimeTests, op_LessThanTest) {
	DateTimeValue	value(DateTime(2003, 7, 23, 12, 30, 30, 100));
	DateTimeValue	value2(DateTime(2003, 8, 23, 12, 30, 30, 100));
	ASSERT_TRUE(DateTimeValue::op_LessThan(value.get_AsDateTime(), value2.get_AsDateTime()));
}
TEST(DateTimeTests, op_LessThanOrEqualTest) {
	DateTimeValue	value(DateTime(2003, 7, 23, 12, 30, 30, 100));
	DateTimeValue	value2(DateTime(2003, 8, 23, 12, 30, 30, 100));
	ASSERT_TRUE(DateTimeValue::op_LessThanOrEqual(value.get_AsDateTime(), value2.get_AsDateTime()));
	ASSERT_TRUE(DateTimeValue::op_LessThanOrEqual(value2.get_AsDateTime(), value2.get_AsDateTime()));
}
TEST(DateTimeTests, op_SubtractionTest) {
	DateTimeValue	date1(DateTime(1996, 6, 3, 22, 15, 0));
	DateTimeValue	date2(DateTime(1996, 12, 6, 13, 2, 0));
	DateTimeValue	date3(DateTime(1996, 10, 12, 8, 42, 0));
	TimeSpan diff1 = DateTimeValue::op_Subtraction(date2.get_AsDateTime(), date1.get_AsDateTime());
	DateTime date4 = DateTimeValue::op_Subtraction(date3.get_AsDateTime(), diff1);
	TimeSpan diff2 = DateTimeValue::op_Subtraction(date2.get_AsDateTime(), date3.get_AsDateTime());
	DateTime date5 = DateTimeValue::op_Subtraction(date1.get_AsDateTime(), diff2);
	// date4 gets 4/9/1996 5:55:00 PM.
	DateTime	result1(1996, 4, 9, 17, 55, 0);
	ASSERT_TRUE(DateTimeValue(result1).Equals(date5));
	ASSERT_TRUE(DateTimeValue(result1).Equals(date4));
}
