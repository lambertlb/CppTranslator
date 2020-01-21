#include "gtest/gtest.h"
#include <DotnetTypes.h>

using namespace DotnetLibrary;
void	AssertFloatEquals(Double n1, Double n2);

TEST(TimeSpanTests, ConstructorTest) {
	TimeSpan	timeSpan(2222);
	ASSERT_TRUE(TimeSpanValue(timeSpan).get_Ticks() == 2222);
}
TEST(TimeSpanTests, Constructor2Test) {
	TimeSpan	timeSpan(10, 20, 30);
	ASSERT_TRUE(TimeSpanValue(timeSpan).get_Hours() == 10);
	ASSERT_TRUE(TimeSpanValue(timeSpan).get_Minutes() == 20);
	ASSERT_TRUE(TimeSpanValue(timeSpan).get_Seconds() == 30);
}
TEST(TimeSpanTests, Constructor3Test) {
	TimeSpan	timeSpan(5, 10, 20, 30);
	ASSERT_TRUE(TimeSpanValue(timeSpan).get_Days() == 5);
	ASSERT_TRUE(TimeSpanValue(timeSpan).get_Hours() == 10);
	ASSERT_TRUE(TimeSpanValue(timeSpan).get_Minutes() == 20);
	ASSERT_TRUE(TimeSpanValue(timeSpan).get_Seconds() == 30);
}
TEST(TimeSpanTests, Constructor4Test) {
	TimeSpan	timeSpan(5, 10, 20, 30, 100);
	ASSERT_TRUE(TimeSpanValue(timeSpan).get_Days() == 5);
	ASSERT_TRUE(TimeSpanValue(timeSpan).get_Hours() == 10);
	ASSERT_TRUE(TimeSpanValue(timeSpan).get_Minutes() == 20);
	ASSERT_TRUE(TimeSpanValue(timeSpan).get_Seconds() == 30);
	ASSERT_TRUE(TimeSpanValue(timeSpan).get_Milliseconds() == 100);
}
TEST(TimeSpanTests, PropertyTest) {
	TimeSpan	timeSpan(0, 1, 0, 0, 0);
	ASSERT_TRUE(TimeSpanValue(timeSpan).get_Days() == 0);
	ASSERT_TRUE(TimeSpanValue(timeSpan).get_Hours() == 1);
	ASSERT_TRUE(TimeSpanValue(timeSpan).get_Minutes() == 0);
	ASSERT_TRUE(TimeSpanValue(timeSpan).get_Seconds() == 0);
	ASSERT_TRUE(TimeSpanValue(timeSpan).get_Milliseconds() == 0);
	AssertFloatEquals(TimeSpanValue(timeSpan).get_TotalDays(), 1 / 24.0);
	AssertFloatEquals(TimeSpanValue(timeSpan).get_TotalHours(), 1);
	AssertFloatEquals(TimeSpanValue(timeSpan).get_TotalMilliseconds(), 3600000);
	AssertFloatEquals(TimeSpanValue(timeSpan).get_TotalMinutes(), 60);
	AssertFloatEquals(TimeSpanValue(timeSpan).get_TotalSeconds(), 3600);
}
TEST(TimeSpanTests, AddTest) {
	TimeSpan	timeSpan(1, 2, 3, 4, 5);
	TimeSpan	timeSpan2(10, 12, 13, 14, 15);
	TimeSpan	answer(11, 14, 16, 18, 20);
	TimeSpan	result(TimeSpanValue(timeSpan).Add(timeSpan2));
	ASSERT_TRUE(TimeSpanValue(result).get_Ticks() == TimeSpanValue(answer).get_Ticks());
}
TEST(TimeSpanTests, CompareTest) {
	TimeSpan	timeSpan(1000);
	TimeSpan	timeSpan2(2000);
	ASSERT_TRUE(TimeSpanValue::Compare(timeSpan, timeSpan2) == -1);
	ASSERT_TRUE(TimeSpanValue(timeSpan).CompareTo(timeSpan2) == -1);
	TimeSpanValue tsValue(timeSpan2);
	ASSERT_TRUE(TimeSpanValue(timeSpan).CompareTo((Object*)&tsValue) == -1);
}
TEST(TimeSpanTests, Compare2Test) {
	TimeSpan	timeSpan(2000);
	TimeSpan	timeSpan2(1000);
	ASSERT_TRUE(TimeSpanValue::Compare(timeSpan, timeSpan2) == 1);
	ASSERT_TRUE(TimeSpanValue(timeSpan).CompareTo(timeSpan2) == 1);
	TimeSpanValue tsValue(timeSpan2);
	ASSERT_TRUE(TimeSpanValue(timeSpan).CompareTo((Object*)&tsValue) == 1);
}
TEST(TimeSpanTests, Compare3Test) {
	TimeSpan	timeSpan(1000);
	TimeSpan	timeSpan2(1000);
	ASSERT_TRUE(TimeSpanValue::Compare(timeSpan, timeSpan2) == 0);
	ASSERT_TRUE(TimeSpanValue(timeSpan).CompareTo(timeSpan2) == 0);
	TimeSpanValue tsValue(timeSpan2);
	ASSERT_TRUE(TimeSpanValue(timeSpan).CompareTo((Object*)&tsValue) == 0);
}
TEST(TimeSpanTests, DivideTest) {
	TimeSpan	timeSpan(2, 30, 0);
	TimeSpan	anwser(TimeSpanValue(timeSpan).Divide(1.0 / 2.0));
	TimeSpan	result(TimeSpan(5, 0, 0));
	ASSERT_TRUE(TimeSpanValue(result).get_Ticks() == TimeSpanValue(anwser).get_Ticks());
}
TEST(TimeSpanTests, Divide2Test) {
	TimeSpan	timeSpan(2, 30, 0);
	TimeSpan	result(TimeSpan(5, 0, 0));
	ASSERT_TRUE(TimeSpanValue(result).Divide(timeSpan) == 2.0);
}
TEST(TimeSpanTests, DurationTest) {
	TimeSpan	timeSpan(12345);
	TimeSpan	timeSpan2(-12345);
	ASSERT_TRUE(TimeSpanValue(timeSpan).Duration().value == timeSpan.value);
	ASSERT_TRUE(TimeSpanValue(timeSpan2).Duration().value == timeSpan.value);
}
TEST(TimeSpanTests, EqualsTest) {
	TimeSpan first(12345);
	TimeSpan second(12346);
	ASSERT_TRUE(TimeSpanValue(first).Equals(first));
	ASSERT_TRUE(!TimeSpanValue(first).Equals(second));
	ASSERT_TRUE(TimeSpanValue::Equals(first, first));
	ASSERT_TRUE(!TimeSpanValue::Equals(first, second));
	TimeSpanValue	firstValue(first);
	TimeSpanValue	secondValue(second);
	ASSERT_TRUE(TimeSpanValue(first).Equals((Object*)&firstValue));
	ASSERT_TRUE(!TimeSpanValue(first).Equals((Object*)&secondValue));
}
TEST(TimeSpanTests, FromDaysTest) {
	TimeSpan	timeSpan = TimeSpanValue::FromDays(100.5);
	TimeSpan	answer(100, 12, 0, 0);
	ASSERT_TRUE(timeSpan.value == answer.value);
}
TEST(TimeSpanTests, FromHoursTest) {
	TimeSpan	timeSpan = TimeSpanValue::FromHours(100.5);
	TimeSpan	answer(4, 4, 30, 0);
	ASSERT_TRUE(timeSpan.value == answer.value);
}
TEST(TimeSpanTests, FromMillisecondsTest) {
	TimeSpan	timeSpan = TimeSpanValue::FromMilliseconds(1500.5);
	TimeSpan	answer(15005000);
	ASSERT_TRUE(timeSpan.value == answer.value);
}
TEST(TimeSpanTests, FromMinutesTest) {
	TimeSpan	timeSpan = TimeSpanValue::FromMinutes(1.23456);
	ASSERT_TRUE(timeSpan.value == (Int64)(1.23456 * 60 * 10000000));
}
TEST(TimeSpanTests, FromSecondsTest) {
	TimeSpan	timeSpan = TimeSpanValue::FromSeconds(1.23456);
	ASSERT_TRUE(timeSpan.value == 12345600);
}
TEST(TimeSpanTests, MultiplyTest) {
	TimeSpan	timeSpan(2, 30, 0);
	TimeSpan	anwser(TimeSpanValue(timeSpan).Multiply(2.0));
	TimeSpan	result(TimeSpan(5, 0, 0));
	ASSERT_TRUE(TimeSpanValue(result).get_Ticks() == TimeSpanValue(anwser).get_Ticks());
}
TEST(TimeSpanTests, NegateTest) {
	TimeSpan	timeSpan(1, 2, 3);
	TimeSpan	answer(-1, -2, -3);
	TimeSpan	result(TimeSpanValue(timeSpan).Negate());
	ASSERT_TRUE(result.value == answer.value);
}
TEST(TimeSpanTests, Negate2Test) {
	TimeSpan	timeSpan(-1, -2, -3);
	TimeSpan	answer(1, 2, 3);
	TimeSpan	result(TimeSpanValue(timeSpan).Negate());
	ASSERT_TRUE(result.value == answer.value);
}
TEST(TimeSpanTests, SubtractTest) {
	TimeSpan	timeSpan(1, 2, 3, 4, 5);
	TimeSpan	timeSpan2(1, 2, 3);
	TimeSpan	answer(1, 1, 1, 1, 5);
	TimeSpan	result(TimeSpanValue(timeSpan).Subtract(timeSpan2));
	ASSERT_TRUE(TimeSpanValue(result).get_Ticks() == TimeSpanValue(answer).get_Ticks());
}
TEST(TimeSpanTests, ToStringTest) {
	TimeSpan	timeSpan(0, 23, 59, 59, 999);
	String* answer = TimeSpanValue(timeSpan).ToString();
	ASSERT_TRUE(wcscmp(answer->get_Buffer(), L"0:23:59:59.9990000") == 0);
}