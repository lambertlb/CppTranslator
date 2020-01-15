#include "gtest/gtest.h"
#include <DotnetTypes.h>

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
	struct tm timeinfo;

	time(&rawtime);
	localtime_s(&timeinfo , &rawtime);
	ASSERT_TRUE(value.get_Month() == timeinfo.tm_mon + 1);
	ASSERT_TRUE(value.get_Day() == timeinfo.tm_mday);
	ASSERT_TRUE(value.get_Year() == timeinfo.tm_year + 1900);
	ASSERT_TRUE(value.get_Hour() == timeinfo.tm_hour);
	ASSERT_TRUE(value.get_Minute() == timeinfo.tm_min);
	ASSERT_TRUE(value.get_Second() == timeinfo.tm_sec);
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
	struct tm timeinfo;

	time(&rawtime);
	localtime_s(&timeinfo, &rawtime);
	ASSERT_TRUE(value.get_Month() == timeinfo.tm_mon + 1);
	ASSERT_TRUE(value.get_Day() == timeinfo.tm_mday);
	ASSERT_TRUE(value.get_Year() == timeinfo.tm_year + 1900);
	ASSERT_TRUE(value.get_Hour() == 0);
	ASSERT_TRUE(value.get_Minute() == 0);
	ASSERT_TRUE(value.get_Second() == 0);
}
TEST(DateTimeTests, get_UtcNowTest) {
	DateTimeValue	value(DateTimeValue::get_UtcNow());
	time_t rawtime;
	struct tm timeinfo;

	time(&rawtime);
	gmtime_s(&timeinfo, &rawtime);
	ASSERT_TRUE(value.get_Month() == timeinfo.tm_mon + 1);
	ASSERT_TRUE(value.get_Day() == timeinfo.tm_mday);
	ASSERT_TRUE(value.get_Year() == timeinfo.tm_year + 1900);
	ASSERT_TRUE(value.get_Hour() == timeinfo.tm_hour);
	ASSERT_TRUE(value.get_Minute() == timeinfo.tm_min);
	ASSERT_TRUE(value.get_Second() == timeinfo.tm_sec);
}
TEST(DateTimeTests, get_YearTest) {
	DateTimeValue	value(DateTime(2003, 7, 23, 12, 30, 30, 100));
	ASSERT_TRUE(value.get_Year() == 2003);
}
