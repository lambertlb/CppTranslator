#pragma once
#include "CaBlockHeader.h"
namespace CABlock_NS
{
	void CABlock::TestFailed(String* x_v)
	{
IL_0000:
		this->Send(x_v);
		return;
	}
	TimeTest::TimeTest(CABlock* x_caBlock)
	{
IL_0000:
		this->x_dat1 = DateTimeValue::get_Now();
		
		this->x_caBlock = x_caBlock;
		return;
	}
	void TimeTest::Test()
	{
IL_0000:
		this->x_caBlock->Send((new String(L"Doing TimeTest")));
		this->x_caBlock->Send((new String(L"\tDoing TestTimeSpan")));
//		this->TestTimeSpan();
		this->x_caBlock->Send((new String(L"\tDoing TestDateTime")));
		this->TestDateTime();
		this->x_caBlock->Send((new String(L"\tDoing DateTimeMethodTests")));
		this->DateTimeMethodTests();
		this->x_caBlock->Send((new String(L"\tDoing TimeArrayTests")));
		this->TimeArrayTests();
		return;
	}
	void TimeTest::TestTimeSpan()
	{
IL_0000:
		TimeSpan x_timeSpan = TimeSpan(100);
		TimeSpan x_timeSpan2 = TimeSpanValue(x_timeSpan).Add(x_timeSpan);
		this->CxAssert((TimeSpanValue(x_timeSpan2).get_Ticks() == 200));
		this->CxAssert((TimeSpanValue::Compare(x_timeSpan, x_timeSpan2) < 0));
		this->CxAssert((TimeSpanValue(x_timeSpan).CompareTo((new TimeSpanValue(x_timeSpan2))) < 0));
		this->CxAssert((TimeSpanValue(x_timeSpan).CompareTo(x_timeSpan2) < 0));
		x_timeSpan = TimeSpanValue(x_timeSpan2).Duration();
		this->CxAssert((TimeSpanValue(x_timeSpan).get_Ticks() == 200));
		this->CxAssert(TimeSpanValue::Equals(x_timeSpan, x_timeSpan2));
		this->CxAssert(TimeSpanValue(x_timeSpan).Equals(x_timeSpan2));
		this->CxAssert((TimeSpanValue((TimeSpanValue::FromDays(22))).get_Ticks() == 19008000000000));
		this->CxAssert((TimeSpanValue((TimeSpanValue::FromHours(10))).get_Ticks() == 360000000000));
		this->CxAssert((TimeSpanValue((TimeSpanValue::FromMilliseconds(100))).get_Ticks() == 1000000));
		this->CxAssert((TimeSpanValue((TimeSpanValue::FromMinutes(25))).get_Ticks() == 15000000000));
		this->CxAssert((TimeSpanValue((TimeSpanValue::FromSeconds(18))).get_Ticks() == 180000000));
		x_timeSpan = TimeSpanValue::FromTicks(6500000);
		this->CxAssert((TimeSpanValue(x_timeSpan).get_Ticks() == 6500000));
		x_timeSpan = TimeSpanValue(x_timeSpan).Negate();
		this->CxAssert((TimeSpanValue(x_timeSpan).get_Ticks() == -6500000));
		this->CxAssert((TimeSpanValue((TimeSpanValue(x_timeSpan).Subtract(x_timeSpan2))).get_Ticks() == -6500200));
		this->CxAssert((TimeSpanValue((TimeSpanValue::Parse((new String(L"1.1:1:1"))))).get_Ticks() == 900610000000));
		this->CxAssert((TimeSpanValue((TimeSpanValue::Parse((new String(L"1.1:1:1.200"))))).get_Ticks() == 900612000000));
		this->CxAssert((TimeSpanValue((TimeSpanValue::Parse((new String(L"1:1:1"))))).get_Ticks() == 36610000000));
		this->CxAssert((TimeSpanValue((TimeSpanValue::Parse((new String(L"22"))))).get_Ticks() == 19008000000000));
		x_timeSpan = TimeSpanValue::Parse((new String(L"1.2:3:4.200")));
		String* x_a = TimeSpanValue(x_timeSpan).ToString();
		this->CxAssert(String::Equals(x_a, (new String(L"1.02:03:04.2000000"))));
		this->CxAssert((TimeSpanValue(x_timeSpan).get_Days() == 1));
		this->CxAssert((TimeSpanValue(x_timeSpan).get_Hours() == 2));
		this->CxAssert((TimeSpanValue(x_timeSpan).get_Minutes() == 3));
		this->CxAssert((TimeSpanValue(x_timeSpan).get_Seconds() == 4));
		this->CxAssert((TimeSpanValue(x_timeSpan).get_Milliseconds() == 200));
		this->CxAssert((TimeSpanValue(x_timeSpan).get_Ticks() == 937842000000));
		this->CxAssert(TimeSpanValue(x_timeSpan).get_TotalDays(), 1.08546527777778);
		this->CxAssert(TimeSpanValue(x_timeSpan).get_TotalHours(), 26.0511666666667);
		this->CxAssert(TimeSpanValue(x_timeSpan).get_TotalMinutes(), 1563.07);
		this->CxAssert(TimeSpanValue(x_timeSpan).get_TotalSeconds(), 93784.2);
		this->CxAssert(TimeSpanValue(x_timeSpan).get_TotalMilliseconds(), 93784200);
		this->CxAssert((TimeSpanValue((TimeSpanValue::op_Addition(x_timeSpan2, x_timeSpan2))).get_Ticks() == 400));
		x_timeSpan = x_timeSpan2;
		this->CxAssert(TimeSpanValue::Equals(x_timeSpan, x_timeSpan2));
		this->CxAssert((TimeSpanValue::op_Inequality(x_timeSpan, x_timeSpan2) == 0));
		x_timeSpan = TimeSpan(100);
		this->CxAssert((TimeSpanValue::op_GreaterThan(x_timeSpan, x_timeSpan2) == 0));
		this->CxAssert((TimeSpanValue::op_GreaterThanOrEqual(x_timeSpan, x_timeSpan2) == 0));
		this->CxAssert((TimeSpanValue::op_LessThan(x_timeSpan2, x_timeSpan) == 0));
		this->CxAssert((TimeSpanValue::op_LessThanOrEqual(x_timeSpan2, x_timeSpan) == 0));
		this->CxAssert(TimeSpanValue::Equals(x_timeSpan, x_timeSpan));
		x_timeSpan = TimeSpanValue::op_Subtraction(x_timeSpan2, x_timeSpan);
		this->CxAssert((TimeSpanValue(x_timeSpan).get_Ticks() == 100));
		x_timeSpan = TimeSpanValue::op_UnaryNegation(x_timeSpan);
		this->CxAssert((TimeSpanValue(x_timeSpan).get_Ticks() == -100));
		this->CxAssert((TimeSpanValue((TimeSpanValue::op_UnaryPlus(x_timeSpan))).get_Ticks() == -100));
		this->CxAssert((TimeSpanValue((TimeSpan(1000))).get_Ticks() == 1000));
		this->CxAssert((TimeSpanValue((TimeSpan(10, 11, 30))).get_Ticks() == 366900000000));
		this->CxAssert((TimeSpanValue((TimeSpan(3, 10, 11, 30))).get_Ticks() == 2958900000000));
		this->CxAssert((TimeSpanValue((TimeSpan(3, 10, 11, 30, 100))).get_Ticks() == 2958901000000));
		this->CxAssert((TimeSpanValue((TimeSpan(3, 10, 11, 30, 100))).get_Ticks() == 2958901000000));
		x_timeSpan = TimeSpan(71, 3, 12, 13);
		this->CxAssert((TimeSpanValue(x_timeSpan).get_Ticks() == 61459330000000));
		String* x_text = TimeSpanValue(x_timeSpan).ToString();
		this->CxAssert(x_text->Equals((new String(L"71.03:12:13"))));
		x_timeSpan = TimeSpan(-71, 3, 12, 13);
		this->CxAssert((TimeSpanValue(x_timeSpan).get_Ticks() == -61228670000000));
		String* x_text2 = TimeSpanValue(x_timeSpan).ToString();
		this->CxAssert(x_text2->Equals((new String(L"-70.20:47:47"))));
		x_timeSpan = TimeSpanValue::Parse((new String(L"-71.03:12:13")));
		this->CxAssert((TimeSpanValue(x_timeSpan).get_Ticks() == -61459330000000));
		String* x_text3 = TimeSpanValue(x_timeSpan).ToString();
		this->CxAssert(x_text3->Equals((new String(L"-71.03:12:13"))));
		Object* x_obj = (new TimeSpanValue(TimeSpanValue::MinValue));
		this->CxAssert((TimeSpanValue((TimeSpan(x_obj->get_AsTimeSpan()))).get_Ticks() == TimeSpanValue((TimeSpanValue::MinValue)).get_Ticks()));
		TimeSpan x_minValue = TimeSpanValue::MinValue;
		this->CxAssert(TimeSpanValue(x_minValue).Equals(x_obj));
		this->CxAssert((TimeSpanValue((TimeSpanValue::MinValue)).CompareTo(x_obj) == 0));
		Int64 x_num = 864000000000;
		this->CxAssert((864000000000 == x_num));
		x_num = 36000000000;
		this->CxAssert((36000000000 == x_num));
		x_num = 600000000;
		this->CxAssert((600000000 == x_num));
		x_num = 10000000;
		this->CxAssert((10000000 == x_num));
		x_num = 10000;
		this->CxAssert((10000 == x_num));
		this->CxAssert(TimeSpanValue::Equals(TimeSpanValue::Zero, TimeSpanValue::Zero));
		this->CxAssert(TimeSpanValue::Equals(TimeSpanValue::MaxValue, TimeSpanValue::MaxValue));
		this->CxAssert(x_obj->Equals((new TimeSpanValue(TimeSpanValue::MinValue))));
		String* x_a2 = x_obj->ToString();
		x_minValue = TimeSpanValue::MinValue;
		this->CxAssert(String::Equals(x_a2, TimeSpanValue(x_minValue).ToString()));
		return;
	}
	void TimeTest::TestDateTime()
	{
IL_0000:
		this->CxAssert((DateTimeValue((DateTime())).get_Ticks() == 0));
		this->CxAssert((DateTimeValue((DateTime(1200))).get_Ticks() == 1200));
		this->CxAssert((DateTimeValue((DateTime(2003, 7, 23))).get_Ticks() == 631945152000000000));
		this->CxAssert((DateTimeValue((DateTime(2003, 7, 23, 12, 30, 30))).get_Ticks() == 631945602300000000));
		DateTime x_dateTime = DateTime(2003, 7, 23, 12, 30, 30, 100);
		this->CxAssert((DateTimeValue(x_dateTime).get_Ticks() == 631945602301000000));
		this->CxAssert((DateTimeValue((DateTimeValue(x_dateTime).get_Date())).get_Ticks() == 631945152000000000));
		Int32 x_day = DateTimeValue(x_dateTime).get_Day();
		this->CxAssert((x_day == 23));
		DayOfWeek x_dayOfWeek = (DayOfWeek)DateTimeValue(x_dateTime).get_DayOfWeek();
		this->CxAssert((x_dayOfWeek == 3));
		Int32 x_dayOfYear = DateTimeValue(x_dateTime).get_DayOfYear();
		this->CxAssert((x_dayOfYear == 204));
		Int32 x_hour = DateTimeValue(x_dateTime).get_Hour();
		this->CxAssert((x_hour == 12));
		Int32 x_millisecond = DateTimeValue(x_dateTime).get_Millisecond();
		this->CxAssert((x_millisecond == 100));
		Int32 x_minute = DateTimeValue(x_dateTime).get_Minute();
		this->CxAssert((x_minute == 30));
		Int32 x_month = DateTimeValue(x_dateTime).get_Month();
		this->CxAssert((x_month == 7));
		DateTime x_now = DateTimeValue::get_Now();
		x_day = DateTimeValue(x_now).get_Day();
		x_dayOfYear = DateTimeValue(x_now).get_DayOfYear();
		x_dayOfWeek = (DayOfWeek)DateTimeValue(x_now).get_DayOfWeek();
		x_hour = DateTimeValue(x_now).get_Hour();
		Int32 x_second = DateTimeValue(x_dateTime).get_Second();
		this->CxAssert((x_second == 30));
		this->CxAssert((TimeSpanValue((DateTimeValue(x_dateTime).get_TimeOfDay())).get_Ticks() == 450301000000));
		DateTime x_today = DateTimeValue::get_Today();
		x_day = DateTimeValue(x_today).get_Day();
		x_dayOfYear = DateTimeValue(x_today).get_DayOfYear();
		x_dayOfWeek = (DayOfWeek)DateTimeValue(x_today).get_DayOfWeek();
		x_hour = DateTimeValue(x_today).get_Hour();
		DateTime x_utcNow = DateTimeValue::get_UtcNow();
		x_day = DateTimeValue(x_utcNow).get_Day();
		x_dayOfYear = DateTimeValue(x_utcNow).get_DayOfYear();
		x_dayOfWeek = (DayOfWeek)DateTimeValue(x_utcNow).get_DayOfWeek();
		x_hour = DateTimeValue(x_utcNow).get_Hour();
		Int32 x_year = DateTimeValue(x_dateTime).get_Year();
		this->CxAssert((x_year == 2003));
		DateTime now = DateTimeValue::get_Now();
		Int32 month = DateTimeValue(now).get_Month();
		Int32 day = DateTimeValue(now).get_Day();
		Int32 year = DateTimeValue(now).get_Year();
		Int32 hour = DateTimeValue(now).get_Hour();
		Int32 minute = DateTimeValue(now).get_Minute();
		Int32 second = DateTimeValue(now).get_Second();
	}
	void TimeTest::DateTimeMethodTests()
	{
IL_0000:
		DateTime x_dateTime = DateTime(2003, 7, 23, 12, 30, 30, 100);
		TimeSpan x_timeSpan = TimeSpan(0, 2, 0, 0);
		this->CxAssert((DateTimeValue((DateTimeValue(x_dateTime).Add(x_timeSpan))).get_Ticks() == 631945674301000000));
		this->CxAssert((DateTimeValue((DateTimeValue(x_dateTime).AddDays(1.5))).get_Ticks() == 631946898301000000));
		this->CxAssert((DateTimeValue((DateTimeValue(x_dateTime).AddHours(2.5))).get_Ticks() == 631945692301000000));
		this->CxAssert((DateTimeValue((DateTimeValue(x_dateTime).AddMilliseconds(159))).get_Ticks() == 631945602302590000));
		this->CxAssert((DateTimeValue((DateTimeValue(x_dateTime).AddMinutes(3.2))).get_Ticks() == 631945604221000000));
		this->CxAssert((DateTimeValue((DateTimeValue(x_dateTime).AddMonths(5))).get_Ticks() == 632077794301000000));
		this->CxAssert((DateTimeValue((DateTimeValue(x_dateTime).AddSeconds(6.66))).get_Ticks() == 631945602367600000));
		this->CxAssert((DateTimeValue((DateTimeValue(x_dateTime).AddTicks(666))).get_Ticks() == 631945602301000666));
		DateTime x_dateTime2 = DateTimeValue(x_dateTime).AddYears(3);
		this->CxAssert((DateTimeValue(x_dateTime2).get_Ticks() == 632892546301000000));
		this->CxAssert((DateTimeValue::Compare(x_dateTime2, x_dateTime) > 0));
		this->CxAssert((DateTimeValue(x_dateTime).CompareTo(x_dateTime2) < 0));
		this->CxAssert((DateTimeValue::DaysInMonth(2003, 1) == 31));
		this->CxAssert((DateTimeValue(x_dateTime).Equals(x_dateTime2) == 0));
		x_dateTime2 = x_dateTime;
		this->CxAssert(DateTimeValue::Equals(x_dateTime, x_dateTime2));
		this->CxAssert(DateTimeValue::IsLeapYear(2004));
		x_dateTime2 = DateTimeValue(x_dateTime).Subtract(x_timeSpan);
		this->CxAssert((DateTimeValue(x_dateTime2).get_Ticks() == 631945530301000000));
		this->CxAssert((TimeSpanValue((DateTimeValue(x_dateTime).Subtract(x_dateTime2))).get_Ticks() == 72000000000));
		x_dateTime2 = DateTimeValue(x_dateTime).ToLocalTime();
		x_dateTime2 = DateTimeValue(x_dateTime).ToUniversalTime();
		x_dateTime2 = DateTimeValue::op_Addition(x_dateTime, x_timeSpan);
		this->CxAssert((DateTimeValue(x_dateTime2).get_Ticks() == 631945674301000000));
		this->CxAssert((DateTimeValue::Equals(x_dateTime2, x_dateTime) == 0));
		this->CxAssert((DateTimeValue::op_GreaterThan(x_dateTime, x_dateTime2) == 0));
		this->CxAssert((DateTimeValue::op_GreaterThanOrEqual(x_dateTime, x_dateTime2) == 0));
		this->CxAssert(DateTimeValue::Equals(x_dateTime2, x_dateTime2));
		this->CxAssert((DateTimeValue::op_LessThan(x_dateTime2, x_dateTime) == 0));
		this->CxAssert((DateTimeValue::op_LessThanOrEqual(x_dateTime2, x_dateTime) == 0));
		x_dateTime2 = DateTimeValue::op_Subtraction(x_dateTime, x_timeSpan);
		this->CxAssert((DateTimeValue(x_dateTime2).get_Ticks() == 631945530301000000));
		this->CxAssert((TimeSpanValue((DateTimeValue::op_Subtraction(x_dateTime, x_dateTime2))).get_Ticks() == 72000000000));
		x_dateTime2 = DateTime(2003, 7, 23, 14, 2, 30, 100);
		this->CxAssert((DateTimeValue(x_dateTime2).get_Ticks() == 631945657501000000));
		this->CxAssert((DateTimeValue(x_dateTime2).get_Hour() == 14));
		String* x_text = DateTimeValue(x_dateTime2).ToString();
		this->CxAssert(x_text->Equals((new String(L"7/23/2003 2:02:30 PM"))));
		x_dateTime2 = DateTime(2003, 7, 23, 2, 20, 1, 100);
		this->CxAssert((DateTimeValue(x_dateTime2).get_Ticks() == 631945236011000000));
		this->CxAssert((DateTimeValue(x_dateTime2).get_Hour() == 2));
		x_text = DateTimeValue(x_dateTime2).ToString();
		this->CxAssert(x_text->Equals((new String(L"7/23/2003 2:20:01 AM"))));
		this->CxAssert((DateTimeValue((DateTimeValue::MinValue)).get_Ticks() == 0));
		this->CxAssert((DateTimeValue((DateTimeValue::MaxValue)).get_Ticks() == 3155378975999999999));
		Object* x_obj = (new DateTimeValue(DateTimeValue::MinValue));
		this->CxAssert((DateTimeValue((DateTime(x_obj->get_AsDateTime()))).get_Ticks() == 0));
		this->CxAssert(DateTimeValue((DateTimeValue::MinValue)).Equals(x_obj));
		this->CxAssert((DateTimeValue((DateTimeValue::MinValue)).CompareTo(x_obj) == 0));
		this->CxAssert(x_obj->Equals((new DateTimeValue(DateTimeValue::MinValue))));
		this->CxAssert(String::Equals(x_obj->ToString(), DateTimeValue((DateTimeValue::MinValue)).ToString()));
		this->CxAssert(DateTimeValue::op_Inequality(x_dateTime2, x_dateTime));
		return;
	}
	void TimeTest::TimeArrayTests()
	{
IL_0000:
		this->DateTimeArrayTests();
		this->TimeSpanArrayTests();
		return;
	}
	void TimeTest::DateTimeArrayTests()
	{
IL_0000:
		Array* x_array = new Array(DateTimeType,5);
		(*((DateTime*)x_array->Address(0))) = DateTime(2000, 4, 6);
		(*((DateTime*)x_array->Address(1))) = DateTime(2000, 4, 7);
		(*((DateTime*)x_array->Address(2))) = DateTime(2000, 4, 8);
		(*((DateTime*)x_array->Address(3))) = DateTime(2000, 4, 9);
		(*((DateTime*)x_array->Address(4))) = DateTime(2000, 4, 10);
		this->CxAssert((x_array->get_Length() == 5));
		this->CxAssert(DateTimeValue::Equals((*((DateTime*)x_array->Address(3))), DateTime(2000, 4, 9)));
		this->CxAssert(DateTimeValue::Equals((*((DateTime*)x_array->Address(1))), DateTime(2000, 4, 7)));
		Array* x_array2 = new Array(DateTimeType,2,4);
		(*((DateTime*)x_array2->Address(0,0))) = DateTime(2000, 4, 6);
		(*((DateTime*)x_array2->Address(0,1))) = DateTime(2000, 4, 7);
		(*((DateTime*)x_array2->Address(0,2))) = DateTime(2000, 4, 8);
		(*((DateTime*)x_array2->Address(0,3))) = DateTime(2000, 4, 9);
		(*((DateTime*)x_array2->Address(1,0))) = DateTime(2000, 4, 10);
		(*((DateTime*)x_array2->Address(1,1))) = DateTime(2000, 4, 11);
		(*((DateTime*)x_array2->Address(1,2))) = DateTime(2000, 4, 12);
		(*((DateTime*)x_array2->Address(1,3))) = DateTime(2000, 4, 13);
		this->CxAssert(DateTimeValue::Equals((*((DateTime*)x_array2->Address(0,2))), DateTime(2000, 4, 8)));
		Array* x_array3 = new Array(DateTimeType,2,2,4);
		(*((DateTime*)x_array3->Address(0,0,0))) = DateTime(2000, 4, 6);
		(*((DateTime*)x_array3->Address(0,0,1))) = DateTime(2000, 4, 7);
		(*((DateTime*)x_array3->Address(0,0,2))) = DateTime(2000, 4, 8);
		(*((DateTime*)x_array3->Address(0,0,3))) = DateTime(2000, 4, 9);
		(*((DateTime*)x_array3->Address(0,1,0))) = DateTime(2000, 4, 10);
		(*((DateTime*)x_array3->Address(0,1,1))) = DateTime(2000, 4, 11);
		(*((DateTime*)x_array3->Address(0,1,2))) = DateTime(2000, 4, 12);
		(*((DateTime*)x_array3->Address(0,1,3))) = DateTime(2000, 4, 13);
		(*((DateTime*)x_array3->Address(1,0,0))) = DateTime(2000, 4, 14);
		(*((DateTime*)x_array3->Address(1,0,1))) = DateTime(2000, 4, 15);
		(*((DateTime*)x_array3->Address(1,0,2))) = DateTime(2000, 4, 16);
		(*((DateTime*)x_array3->Address(1,0,3))) = DateTime(2000, 4, 17);
		(*((DateTime*)x_array3->Address(1,1,0))) = DateTime(2000, 4, 18);
		(*((DateTime*)x_array3->Address(1,1,1))) = DateTime(2000, 4, 19);
		(*((DateTime*)x_array3->Address(1,1,2))) = DateTime(2000, 4, 20);
		(*((DateTime*)x_array3->Address(1,1,3))) = DateTime(2000, 4, 21);
		this->CxAssert(DateTimeValue::Equals((*((DateTime*)x_array3->Address(0,0,3))), DateTime(2000, 4, 9)));
		(*((DateTime*)x_array3->Address(0,0,3))) = DateTime(2000, 4, 27);
		this->CxAssert(DateTimeValue::Equals((*((DateTime*)x_array3->Address(0,0,3))), DateTime(2000, 4, 27)));
		x_array3->SetValue((new DateTimeValue(DateTime(2000, 4, 28))), 0, 0, 3);
		this->CxAssert(DateTimeValue::Equals((*((DateTime*)x_array3->Address(0,0,3))), DateTime(2000, 4, 28)));
		DateTime x_d = (*((DateTime*)x_array->Address(2))) = DateTime(2000, 4, 27);
		this->CxAssert(DateTimeValue::Equals((*((DateTime*)x_array->Address(2))), x_d));
		return;
	}
	void TimeTest::TimeSpanArrayTests()
	{
IL_0000:
		Array* x_array = new Array(TimeSpanType,5);
		(*((TimeSpan*)x_array->Address(0))) = TimeSpan(2000, 4, 6);
		(*((TimeSpan*)x_array->Address(1))) = TimeSpan(2000, 4, 7);
		(*((TimeSpan*)x_array->Address(2))) = TimeSpan(2000, 4, 8);
		(*((TimeSpan*)x_array->Address(3))) = TimeSpan(2000, 4, 9);
		(*((TimeSpan*)x_array->Address(4))) = TimeSpan(2000, 4, 10);
		this->CxAssert((x_array->get_Length() == 5));
		this->CxAssert(TimeSpanValue::Equals((*((TimeSpan*)x_array->Address(3))), TimeSpan(2000, 4, 9)));
		this->CxAssert(TimeSpanValue::Equals((*((TimeSpan*)x_array->Address(1))), TimeSpan(2000, 4, 7)));
		Array* x_array2 = new Array(TimeSpanType,2,4);
		(*((TimeSpan*)x_array2->Address(0,0))) = TimeSpan(2000, 4, 6);
		(*((TimeSpan*)x_array2->Address(0,1))) = TimeSpan(2000, 4, 7);
		(*((TimeSpan*)x_array2->Address(0,2))) = TimeSpan(2000, 4, 8);
		(*((TimeSpan*)x_array2->Address(0,3))) = TimeSpan(2000, 4, 9);
		(*((TimeSpan*)x_array2->Address(1,0))) = TimeSpan(2000, 4, 10);
		(*((TimeSpan*)x_array2->Address(1,1))) = TimeSpan(2000, 4, 11);
		(*((TimeSpan*)x_array2->Address(1,2))) = TimeSpan(2000, 4, 12);
		(*((TimeSpan*)x_array2->Address(1,3))) = TimeSpan(2000, 4, 13);
		this->CxAssert(TimeSpanValue::Equals((*((TimeSpan*)x_array2->Address(0,2))), TimeSpan(2000, 4, 8)));
		Array* x_array3 = new Array(TimeSpanType,2,2,4);
		(*((TimeSpan*)x_array3->Address(0,0,0))) = TimeSpan(2000, 4, 6);
		(*((TimeSpan*)x_array3->Address(0,0,1))) = TimeSpan(2000, 4, 7);
		(*((TimeSpan*)x_array3->Address(0,0,2))) = TimeSpan(2000, 4, 8);
		(*((TimeSpan*)x_array3->Address(0,0,3))) = TimeSpan(2000, 4, 9);
		(*((TimeSpan*)x_array3->Address(0,1,0))) = TimeSpan(2000, 4, 10);
		(*((TimeSpan*)x_array3->Address(0,1,1))) = TimeSpan(2000, 4, 11);
		(*((TimeSpan*)x_array3->Address(0,1,2))) = TimeSpan(2000, 4, 12);
		(*((TimeSpan*)x_array3->Address(0,1,3))) = TimeSpan(2000, 4, 13);
		(*((TimeSpan*)x_array3->Address(1,0,0))) = TimeSpan(2000, 4, 14);
		(*((TimeSpan*)x_array3->Address(1,0,1))) = TimeSpan(2000, 4, 15);
		(*((TimeSpan*)x_array3->Address(1,0,2))) = TimeSpan(2000, 4, 16);
		(*((TimeSpan*)x_array3->Address(1,0,3))) = TimeSpan(2000, 4, 17);
		(*((TimeSpan*)x_array3->Address(1,1,0))) = TimeSpan(2000, 4, 18);
		(*((TimeSpan*)x_array3->Address(1,1,1))) = TimeSpan(2000, 4, 19);
		(*((TimeSpan*)x_array3->Address(1,1,2))) = TimeSpan(2000, 4, 20);
		(*((TimeSpan*)x_array3->Address(1,1,3))) = TimeSpan(2000, 4, 21);
		this->CxAssert(TimeSpanValue::Equals((*((TimeSpan*)x_array3->Address(0,0,3))), TimeSpan(2000, 4, 9)));
		(*((TimeSpan*)x_array3->Address(0,0,3))) = TimeSpan(2000, 4, 27);
		this->CxAssert(TimeSpanValue::Equals((*((TimeSpan*)x_array3->Address(0,0,3))), TimeSpan(2000, 4, 27)));
		x_array3->SetValue((new TimeSpanValue(TimeSpan(2000, 4, 28))), 0, 0, 3);
		this->CxAssert(TimeSpanValue::Equals((*((TimeSpan*)x_array3->Address(0,0,3))), TimeSpan(2000, 4, 28)));
		TimeSpan x_t = (*((TimeSpan*)x_array->Address(2))) = TimeSpan(2000, 4, 27);
		this->CxAssert(TimeSpanValue::Equals((*((TimeSpan*)x_array->Address(2))), x_t));
		return;
	}
	void TimeTest::CxAssert(Double x_x,Double x_y)
	{
IL_0000:
		if ((Math::Abs((x_x - x_y)) > 1E-05))
		{
			this->x_caBlock->TestFailed((new String(L"Time TestFailed")));
		}

		return;
	}
	void TimeTest::CxAssert(Boolean x_x)
	{
IL_0000:
		if ((x_x == 0))
		{
			this->TimeTestFailed();
		}

		return;
	}
	void TimeTest::TimeTestFailed()
	{
IL_0000:
		this->x_caBlock->TestFailed((new String(L"Time TestFailed")));
		return;
	}
}
namespace MiniTest_NS
{
	void Program::Run()
	{
IL_0000:
		CABlock* x_caBlock = (new CABlock());
		TimeTest* x_timeTest = (new TimeTest(x_caBlock));
		x_timeTest->Test();
		return;
	}
	void Program::CxAssert(Boolean x_isTrue)
	{
		return;
	}
	void Program::CxAssert(Double x_x,Double x_y)
	{
		return;
	}
	Int32 Program::Main(Array* x_arvs)
	{
IL_0000:
		Program* x_program = (new Program());
		x_program->Run();
		return((Int32)0);
	}
}
