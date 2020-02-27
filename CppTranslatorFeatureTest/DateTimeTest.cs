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
using System;

namespace CppTranslatorFeatureTest
{
	public class DateTimeTest
	{
		FeatureTest featureTest;
		public DateTimeTest(FeatureTest featureTest)
		{
			this.featureTest = featureTest;
		}
		public void Run()
		{
			MethodTests();
			OperatorTests();
			PropertyTests();
		}

		private void PropertyTests()
		{
			featureTest.FailureMessage = "\tFailed DateTime Property Test";
			featureTest.Send("DateTime Property Test");
			DateTime date1 = new DateTime(2003, 8, 23, 10, 30, 30, 100);
			featureTest.AssertTrue(date1.Date == new DateTime(2003, 8, 23));
			featureTest.AssertTrue(date1.Day == 23);
			featureTest.AssertTrue(date1.DayOfWeek == DayOfWeek.Saturday);
			featureTest.AssertTrue(date1.DayOfYear == 235);
			featureTest.AssertTrue(date1.Hour == 10);
			featureTest.AssertTrue(date1.Millisecond == 100);
			featureTest.AssertTrue(date1.Minute == 30);
			featureTest.AssertTrue(date1.Month == 8);
			featureTest.AssertTrue(date1.Second == 30);
			featureTest.AssertTrue(date1.Ticks == 631972314301000000);
			featureTest.AssertTrue(date1.TimeOfDay == new TimeSpan(0,10,30,30,100));
			featureTest.AssertTrue(date1.Year == 2003);
			DateTime localTime = DateTime.Now;
			DateTime localTimeSansTime = new DateTime(localTime.Year, localTime.Month, localTime.Day);
			featureTest.AssertTrue(DateTime.Today == localTimeSansTime);
		}

		private void OperatorTests()
		{
			featureTest.FailureMessage = "\tFailed DateTime Operator Test";
			featureTest.Send("DateTime Operator Test");
			DateTime date1 = new DateTime(2003, 8, 23, 10, 30, 30, 100);
			DateTime date2 = new DateTime(2003, 8, 23, 11, 30, 30, 100);
			DateTime date2a = new DateTime(2003, 8, 23, 11, 30, 30, 100);
			DateTime date3 = new DateTime(2003, 8, 23, 12, 30, 30, 100);
			TimeSpan span1 = new TimeSpan(0, 2, 0, 0);
			featureTest.AssertTrue((date1 + span1) == date3);
			featureTest.AssertTrue(date2 != date1);
			featureTest.AssertTrue(date2 == date2a);
			featureTest.AssertTrue(date2 > date1);
			featureTest.AssertTrue(!(date2 > date2a));
			featureTest.AssertTrue(date2 >= date1);
			featureTest.AssertTrue(date2 >= date2a);
			featureTest.AssertTrue(!(date2 >= date3));
			featureTest.AssertTrue(date2 < date3);
			featureTest.AssertTrue(!(date2 < date2a));
			featureTest.AssertTrue(date2 <= date3);
			featureTest.AssertTrue(date2 <= date2a);
			featureTest.AssertTrue(!(date2 <= date1));
			featureTest.AssertTrue((date3 - date1) == span1);
			featureTest.AssertTrue((date3 - span1) == date1);
		}
		private void MethodTests()
		{
			featureTest.FailureMessage = "\tFailed DateTime Method Test";
			featureTest.Send("DateTime Method Test");
			DateTime date1 = new DateTime(2003, 8, 23, 10, 30, 30, 100);
			DateTime date2 = new DateTime(2003, 8, 23, 11, 30, 30, 100);
			DateTime date2a = new DateTime(2003, 8, 23, 11, 30, 30, 100);
			DateTime date3 = new DateTime(2003, 8, 23, 12, 30, 30, 100);
			TimeSpan span1 = new TimeSpan(0, 2, 0, 0);
			Object obj1 = date1;
			Object obj2a = date2a;
			Object obj3 = date3;

			featureTest.AssertTrue(date1.Add(span1) == date3);
			featureTest.AssertTrue(date1.AddDays(2) == new DateTime(2003, 8, 25, 10, 30, 30, 100));
			featureTest.AssertTrue(date1.AddHours(2) == new DateTime(2003, 8, 23, 12, 30, 30, 100));
			featureTest.AssertTrue(date1.AddMilliseconds(2) == new DateTime(2003, 8, 23, 10, 30, 30, 102));
			featureTest.AssertTrue(date1.AddMinutes(2) == new DateTime(2003, 8, 23, 10, 32, 30, 100));
			featureTest.AssertTrue(date1.AddMonths(2) == new DateTime(2003, 10, 23, 10, 30, 30, 100));
			featureTest.AssertTrue(date1.AddSeconds(2) == new DateTime(2003, 8, 23, 10, 30, 32, 100));
			featureTest.AssertTrue(date1.AddTicks(20000) == new DateTime(2003, 8, 23, 10, 30, 30, 102));
			featureTest.AssertTrue(date1.AddYears(2) == new DateTime(2005, 8, 23, 10, 30, 30, 100));
			featureTest.AssertTrue(DateTime.Compare(date2, date1) > 0);
			featureTest.AssertTrue(DateTime.Compare(date2, date3) < 0);
			featureTest.AssertTrue(DateTime.Compare(date2, date2a) == 0);
			featureTest.AssertTrue(date2.CompareTo(date1) > 0);
			featureTest.AssertTrue(date2.CompareTo(obj1) > 0);
			featureTest.AssertTrue(date2.CompareTo(date3) < 0);
			featureTest.AssertTrue(date2.CompareTo(obj3) < 0);
			featureTest.AssertTrue(date2.CompareTo(date2a) == 0);
			featureTest.AssertTrue(date2.CompareTo(obj2a) == 0);
			featureTest.AssertTrue(DateTime.DaysInMonth(2001,7) == 31);
			featureTest.AssertTrue(date2.Equals(date2a));
			featureTest.AssertTrue(!date2.Equals(date1));
			featureTest.AssertTrue(DateTime.Equals(date2,date2a));
			featureTest.AssertTrue(!DateTime.Equals(date2, date1));
			featureTest.AssertTrue(date2.Equals(obj2a));
			featureTest.AssertTrue(!date2.Equals(obj1));
			featureTest.AssertTrue(new DateTime(2003, 1, 23, 12, 30, 30, 100).IsDaylightSavingTime() == false);
			featureTest.AssertTrue(new DateTime(2003, 9, 23, 12, 30, 30, 100).IsDaylightSavingTime());
			featureTest.AssertTrue(DateTime.IsLeapYear(2004));
			featureTest.AssertTrue(!DateTime.IsLeapYear(2005));
			featureTest.AssertTrue(date3.Subtract(date1) == span1);
			featureTest.AssertTrue(date3.Subtract(span1) == date1);
			DateTime localTime = DateTime.Now;
			DateTime utcTime = DateTime.UtcNow;
			DateTime localTimeSansMillisectonds = new DateTime(localTime.Year,localTime.Month,localTime.Day,localTime.Hour,localTime.Minute,localTime.Second);
			DateTime utcTimeSansMillisectonds = new DateTime(utcTime.Year, utcTime.Month, utcTime.Day, utcTime.Hour, utcTime.Minute, utcTime.Second);
			featureTest.AssertTrue(utcTimeSansMillisectonds.ToLocalTime() == localTimeSansMillisectonds);
			featureTest.AssertTrue(localTimeSansMillisectonds.ToUniversalTime() == utcTimeSansMillisectonds);
		}
	}
}
