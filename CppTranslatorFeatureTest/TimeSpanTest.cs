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
	public class TimeSpanTest
	{
		FeatureTest featureTest;
		public TimeSpanTest(FeatureTest featureTest)
		{
			this.featureTest = featureTest;
		}
		public void Run()
		{
			PropertyTest();
			MethodTests();
			OperatorTests();
		}

		private void PropertyTest()
		{
			featureTest.FailureMessage = "\tFailed TimeSpan Property Test";
			featureTest.Send("TimeSpan Property Test");
			TimeSpan timeSpan = new TimeSpan(1, 2, 3, 4, 5);
			featureTest.AssertTrue(timeSpan.Days == 1);
			featureTest.AssertTrue(timeSpan.Hours == 2);
			featureTest.AssertTrue(timeSpan.Milliseconds == 5);
			featureTest.AssertTrue(timeSpan.Minutes == 3);
			featureTest.AssertTrue(timeSpan.Seconds == 4);
			featureTest.AssertTrue(timeSpan.Ticks == 937840050000);
			featureTest.AssertTrue(timeSpan.TotalDays , 1.0854630208333333);
			featureTest.AssertTrue(timeSpan.TotalHours == 26.0511125);
			featureTest.AssertTrue(timeSpan.TotalMilliseconds == 93784005);
			featureTest.AssertTrue(timeSpan.TotalMinutes == 1563.06675);
			featureTest.AssertTrue(timeSpan.TotalSeconds , 93784.005);
		}
		private void OperatorTests()
		{
			featureTest.FailureMessage = "\tFailed TimeSpan Operator Test";
			featureTest.Send("TimeSpan Operator Test");
			TimeSpan timeSpan = new TimeSpan(1, 2, 3, 4, 5);
			TimeSpan timeSpan2 = new TimeSpan(10, 12, 13, 14, 15);
			featureTest.AssertTrue((timeSpan + timeSpan2) == new TimeSpan(11, 14, 16, 18, 20));
			featureTest.AssertTrue((new TimeSpan(2, 30, 0) / (1.0 / 2.0)) == new TimeSpan(5, 0, 0));
			featureTest.AssertTrue(new TimeSpan(5, 0, 0) / new TimeSpan(2, 30, 0) == 2.0);
			featureTest.AssertTrue(new TimeSpan(5, 0, 0) > new TimeSpan(2, 30, 0));
			featureTest.AssertTrue(new TimeSpan(5, 0, 0) >= new TimeSpan(2, 30, 0));
			featureTest.AssertTrue(new TimeSpan(5, 0, 0) >= new TimeSpan(5, 0, 0));
			featureTest.AssertTrue(new TimeSpan(5, 0, 0) != new TimeSpan(2, 30, 0));
			featureTest.AssertTrue(new TimeSpan(2, 30, 0) < new TimeSpan(5, 0, 0));
			featureTest.AssertTrue(new TimeSpan(2, 30, 0) <= new TimeSpan(5, 0, 0));
			featureTest.AssertTrue(new TimeSpan(2, 30, 0) <= new TimeSpan(2, 30, 0));
			featureTest.AssertTrue((new TimeSpan(2, 30, 0) * 2.0) == new TimeSpan(5, 0, 0));
			featureTest.AssertTrue((2 * new TimeSpan(2, 30, 0)) == new TimeSpan(5, 0, 0));
			featureTest.AssertTrue((new TimeSpan(1, 2, 3, 4, 5) - new TimeSpan(1, 2, 3)) == new TimeSpan(1, 1, 1, 1, 5));
			featureTest.AssertTrue(-(new TimeSpan(1, 2, 3)) == new TimeSpan(-1, -2, -3));
		}
		private void MethodTests()
		{
			featureTest.FailureMessage = "\tFailed TimeSpan Method Test";
			featureTest.Send("TimeSpan Method Test");
			TimeSpan timeSpan = new TimeSpan(1, 2, 3, 4, 5);
			TimeSpan timeSpan2 = new TimeSpan(10, 12, 13, 14, 15);
			featureTest.AssertTrue(timeSpan.Add(timeSpan2) == new TimeSpan(11, 14, 16, 18, 20));
			featureTest.AssertTrue(TimeSpan.Compare(new TimeSpan(1000), new TimeSpan(2000)) == -1);
			featureTest.AssertTrue(TimeSpan.Compare(new TimeSpan(2000), new TimeSpan(1000)) == 1);
			featureTest.AssertTrue(TimeSpan.Compare(new TimeSpan(2000), new TimeSpan(2000)) == 0);
			featureTest.AssertTrue(new TimeSpan(1000).CompareTo(new TimeSpan(2000)) == -1);
			featureTest.AssertTrue(new TimeSpan(2000).CompareTo(new TimeSpan(1000)) == 1);
			featureTest.AssertTrue(new TimeSpan(2000).CompareTo(new TimeSpan(2000)) == 0);
			featureTest.AssertTrue(new TimeSpan(1000).CompareTo((Object)new TimeSpan(2000)) == -1);
			featureTest.AssertTrue(new TimeSpan(2000).CompareTo((Object)new TimeSpan(1000)) == 1);
			featureTest.AssertTrue(new TimeSpan(2000).CompareTo((Object)new TimeSpan(2000)) == 0);
			featureTest.AssertTrue((new TimeSpan(2, 30, 0).Divide(1.0 / 2.0)) == new TimeSpan(5, 0, 0));
			featureTest.AssertTrue(new TimeSpan(5, 0, 0).Divide(new TimeSpan(2, 30, 0)) == 2.0);
			featureTest.AssertTrue(new TimeSpan(12345).Duration() == new TimeSpan(12345));
			featureTest.AssertTrue(new TimeSpan(-12345).Duration() == new TimeSpan(12345));
			featureTest.AssertTrue(TimeSpan.Equals(timeSpan, timeSpan));
			featureTest.AssertTrue(timeSpan.Equals(timeSpan));
			featureTest.AssertTrue(timeSpan.Equals((Object)timeSpan));
			featureTest.AssertTrue(TimeSpan.FromDays(100.5) == new TimeSpan(100, 12, 0, 0));
			featureTest.AssertTrue(TimeSpan.FromHours(100.5) == new TimeSpan(4, 4, 30, 0));
			featureTest.AssertTrue(TimeSpan.FromMilliseconds(1500.0) == new TimeSpan(15000000));
			featureTest.AssertTrue(TimeSpan.FromMinutes(12.0) == new TimeSpan((Int64)(12L * 60 * 10000000)));
			featureTest.AssertTrue(TimeSpan.FromSeconds(1.0) == new TimeSpan(10000000));
			featureTest.AssertTrue(TimeSpan.FromTicks(12345600) == new TimeSpan(12345600));
			featureTest.AssertTrue(new TimeSpan(2, 30, 0).Multiply(2.0) == new TimeSpan(5, 0, 0));
			featureTest.AssertTrue(new TimeSpan(1, 2, 3).Negate() == new TimeSpan(-1, -2, -3));
			featureTest.AssertTrue(TimeSpan.Parse("1.00:00:00") == new TimeSpan(1, 0, 0, 0, 0));
			featureTest.AssertTrue(TimeSpan.Parse("0.23:59:59.9990000") == new TimeSpan(0, 23, 59, 59, 999));
			featureTest.AssertTrue(new TimeSpan(1, 2, 3, 4, 5).Subtract(new TimeSpan(1, 2, 3)) == new TimeSpan(1, 1, 1, 1, 5));
			featureTest.AssertTrue(new TimeSpan(0, 23, 59, 59, 999).ToString() == "23:59:59.9990000");
			featureTest.AssertTrue(new TimeSpan(-71, 3, 12, 13).ToString() == "-70.20:47:47");
			TimeSpan result;
			featureTest.AssertTrue(TimeSpan.TryParse("0:23:59:59.9990000", out result));
			featureTest.AssertTrue(result == new TimeSpan(0, 23, 59, 59, 999));
			featureTest.AssertTrue(TimeSpan.TryParse("-70.20:47:47", out result));
			featureTest.AssertTrue(result == new TimeSpan(-71, 3, 12, 13));
		}
	}
}
