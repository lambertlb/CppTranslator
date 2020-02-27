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
using System.Collections.Generic;
using System.Text;

namespace CppTranslatorFeatureTest
{
	public class DoubleTest
	{
		FeatureTest featureTest;
		public DoubleTest(FeatureTest featureTest)
		{
			this.featureTest = featureTest;
		}
		public void Run()
		{
			MethodTests();
			OperatorTests();
		}

		private void MethodTests()
		{
			featureTest.FailureMessage = "\tFailed Double Method Test";
			featureTest.Send("Double Method Test");
			Double value1 = 1;
			Double value2 = 2;
			Double value3 = 3;
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
			featureTest.AssertTrue(Double.Parse("33.0") == 33.0);
			String str = (35.3).ToString();
			featureTest.AssertTrue(str == "35.3");
			Double parsed;
			featureTest.AssertTrue(Double.TryParse(str, out parsed));
			featureTest.AssertTrue(parsed == 35.3);
			featureTest.AssertTrue(Double.IsFinite(3.0 / 1));
			featureTest.AssertTrue(!Double.IsInfinity(3.0 / 1));
			featureTest.AssertTrue(Double.IsInfinity(Double.PositiveInfinity));
			featureTest.AssertTrue(!Double.IsNaN(3.0 / 1));
			featureTest.AssertTrue(Double.IsNaN(Double.NaN));
			featureTest.AssertTrue(Double.IsNegativeInfinity(Double.NegativeInfinity));
			featureTest.AssertTrue(!Double.IsNegativeInfinity(Double.PositiveInfinity));
			featureTest.AssertTrue(!Double.IsNegativeInfinity(Double.NaN));
			featureTest.AssertTrue(!Double.IsPositiveInfinity(Double.NegativeInfinity));
			featureTest.AssertTrue(Double.IsPositiveInfinity(Double.PositiveInfinity));
			featureTest.AssertTrue(!Double.IsPositiveInfinity(Double.NaN));
#if V3
			featureTest.AssertTrue(Double.IsFinite(3.0 / 1));
			featureTest.AssertTrue(!Double.IsFinite(Double.NaN));
			featureTest.AssertTrue(Double.IsNegative(-3.0));
			featureTest.AssertTrue(!Double.IsNegative(3.0));
			featureTest.AssertTrue(Double.IsNegative(Double.NaN));
			featureTest.AssertTrue(Double.IsNormal(3.0));
			featureTest.AssertTrue(!Double.IsNormal(Double.PositiveInfinity));
			featureTest.AssertTrue(!Double.IsNormal(Double.NaN));
			featureTest.AssertTrue(Double.IsSubnormal(Double.Epsilon));
			featureTest.AssertTrue(Double.IsSubnormal(2.2250738585072009E-308));
			featureTest.AssertTrue(!Double.IsSubnormal(2.2250738585072014E-308));
#endif
		}

		private void OperatorTests()
		{
			featureTest.FailureMessage = "\tFailed Double Operator Test";
			featureTest.Send("Double Operator Test");
			Double value = 1;
			featureTest.AssertTrue(value > 0);
			featureTest.AssertTrue(value >= 1);
			featureTest.AssertTrue(value < 2);
			featureTest.AssertTrue(value <= 1);
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
			value = -1;
			featureTest.AssertTrue(value == -1);
			value = -(-1);
			featureTest.AssertTrue(value == 1);
			featureTest.AssertTrue(value != 2);
			value = 10;
			featureTest.AssertTrue(value * 2 == 20);
			featureTest.AssertTrue(value * -2 == -20);
			featureTest.AssertTrue(value / 5 == 2);
			featureTest.AssertTrue(value / -5 == -2);
			featureTest.AssertTrue(Math.Abs((value / 3) - 3.33) < 0.01);
			featureTest.AssertTrue(Math.Abs((value / -3) - -3.33) < 0.01);
			featureTest.AssertTrue(value % 5 == 0);
			featureTest.AssertTrue(value % 3 == 1);
			featureTest.AssertTrue(value + 5 == 15);
			featureTest.AssertTrue(value - 5 == 5);
			featureTest.AssertTrue(value + (value * value) == 110);
			Double newvalue = value / 0;
			featureTest.AssertTrue(Double.IsInfinity(newvalue));
			newvalue = 0;
			newvalue /= 0;
			featureTest.AssertTrue(Double.IsNaN(newvalue));
			value = 1;
			featureTest.AssertTrue((value += 1) == 2);
			featureTest.AssertTrue((value -= 1) == 1);
			featureTest.AssertTrue((value *= 2) == 2);
			featureTest.AssertTrue((value /= 2) == 1);
			value = 10;
			featureTest.AssertTrue((value %= 5) == 0);
			value = 10;
			featureTest.AssertTrue((value %= 3) == 1);
		}
	}
}
