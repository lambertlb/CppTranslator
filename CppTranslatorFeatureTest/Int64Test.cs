﻿// Copyright (c) 2019 LLambert
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
using System;

namespace CppTranslatorFeatureTest
{
	public class Int64Test
	{
		FeatureTest featureTest;
		public Int64Test(FeatureTest featureTest)
		{
			this.featureTest = featureTest;
		}
		public void Run()
		{
			MethodTests();
			OperatorTests();
			BitwiseOperators();
		}
		private void MethodTests()
		{
			featureTest.FailureMessage = "\tFailed Int64 Method Test";
			featureTest.Send("Int64 Method Test");
			Int64 value1 = 1;
			Int64 value2 = 2;
			Int64 value3 = 3;
			Object obj1 = value1;
			Object obj2 = value2;
			Object obj3 = value3;
			featureTest.AssertTrue(value2.CompareTo(value1) > 0);
			featureTest.AssertTrue(value2.CompareTo(value3) < 0);
			featureTest.AssertTrue(value2.CompareTo(value2) == 0);

			featureTest.AssertTrue(value2.CompareTo(obj1) > 0);
			featureTest.AssertTrue(value2.CompareTo(obj3) < 0);
			featureTest.AssertTrue(value2.CompareTo(obj2) == 0);

			featureTest.AssertTrue(!value2.Equals(value1));
			featureTest.AssertTrue(!value2.Equals(value3));
			featureTest.AssertTrue(value2.Equals(value2));

			featureTest.AssertTrue(!value2.Equals(obj1));
			featureTest.AssertTrue(!value2.Equals(obj3));
			featureTest.AssertTrue(value2.Equals(obj2));
			featureTest.AssertTrue(Int64.Parse("33") == 33);
			String str = 35.ToString();
			featureTest.AssertTrue(str == "35");
			Int64 parsed;
			featureTest.AssertTrue(Int64.TryParse(str, out parsed));
			featureTest.AssertTrue(parsed == 35);
		}
		private void OperatorTests()
		{
			featureTest.FailureMessage = "\tFailed Int64 Operator Test";
			featureTest.Send("Int64 Operator Test");
			Int64 value = 1;
			featureTest.AssertTrue(value == 1);
			featureTest.AssertTrue(value++ == 1);
			featureTest.AssertTrue(value == 2);
			featureTest.AssertTrue(value-- == 2);
			featureTest.AssertTrue(value == 1);
			featureTest.AssertTrue(++value == 2);
			featureTest.AssertTrue(value == 2);
			featureTest.AssertTrue(--value == 1);
			featureTest.AssertTrue(value == 1);
			value = +1;
			featureTest.AssertTrue(value == 1);
			value = Int64.MinValue;
			featureTest.AssertTrue(value == Int64.MinValue);
			value = Int64.MinValue;
			featureTest.AssertTrue((Int64)(value - 1) == Int64.MaxValue);
			value = -(-1);
			featureTest.AssertTrue(value == 1);
			value = 10;
			featureTest.AssertTrue(value * 2 == 20);
			featureTest.AssertTrue(value * -2 == -20);
			featureTest.AssertTrue(value / 5 == 2);
			featureTest.AssertTrue(value / -5 == -2);
			featureTest.AssertTrue(value / 3 == 3);
			featureTest.AssertTrue(value / -3 == -3);
			featureTest.AssertTrue(value % 5 == 0);
			featureTest.AssertTrue(value % 3 == 1);
			featureTest.AssertTrue(value + 5 == 15);
			featureTest.AssertTrue(value - 5 == 5);
			featureTest.AssertTrue(value + (value * value) == 110);
			bool gotException = false;
			try
			{
				value = (Int64)(value / 0);
				featureTest.AssertTrue(false);
			}
			catch (Exception)
			{
				gotException = true;
			}
			featureTest.AssertTrue(gotException);
		}
		private void BitwiseOperators()
		{
			featureTest.FailureMessage = "\tFailed Int64 Bitwise Operator Test";
			featureTest.Send("Int64 Bitwise Operator Test");
			Int64 value = 0;
			featureTest.AssertTrue(~value == -1);
			value = 1;
			featureTest.AssertTrue(value << 1 == 2);
			value <<= 1;
			featureTest.AssertTrue(value == 2);
			value = 10;
			featureTest.AssertTrue(value >> 1 == 5);
			value >>= 1;
			featureTest.AssertTrue(value == 5);
			value = 3;
			featureTest.AssertTrue((value & 1) == 1);
			featureTest.AssertTrue((value & 2) == 2);
			featureTest.AssertTrue((value & 3) == 3);
			featureTest.AssertTrue((value & 4) == 0);
			value &= 4;
			featureTest.AssertTrue(value == 0);
			value = 2;
			featureTest.AssertTrue((value ^ 2) == 0);
			featureTest.AssertTrue((value ^ 4) == 6);
			featureTest.AssertTrue((value | 2) == 2);
			featureTest.AssertTrue((value | 4) == 6);
			value |= 4;
			featureTest.AssertTrue(value == 6);
		}
	}
}
