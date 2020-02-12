using System;
using System.Collections.Generic;
using System.Text;

namespace CppTranslatorFeatureTest
{
	public class SingleTest
	{
		FeatureTest featureTest;
		public SingleTest(FeatureTest featureTest)
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
			featureTest.FailureMessage = "\tFailed Single Method Test";
			featureTest.Send("Single Method Test");
			Single value1 = 1;
			Single value2 = 2;
			Single value3 = 3;
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
			featureTest.AssertTrue(Single.Parse("33.0") == 33.0F);
			String str = (35.3).ToString();
			featureTest.AssertTrue(str == "35.3");
			Single parsed;
			featureTest.AssertTrue(Single.TryParse(str, out parsed));
			featureTest.AssertTrue(parsed == 35.3F);
			featureTest.AssertTrue(Single.IsFinite(3.0F / 1F));
			featureTest.AssertTrue(!Single.IsInfinity(3.0F / 1F));
			featureTest.AssertTrue(Single.IsInfinity(Single.PositiveInfinity));
			featureTest.AssertTrue(!Single.IsNaN(3.0F / 1F));
			featureTest.AssertTrue(Single.IsNaN(Single.NaN));
			featureTest.AssertTrue(Single.IsNegativeInfinity(Single.NegativeInfinity));
			featureTest.AssertTrue(!Single.IsNegativeInfinity(Single.PositiveInfinity));
			featureTest.AssertTrue(!Single.IsNegativeInfinity(Single.NaN));
			featureTest.AssertTrue(!Single.IsPositiveInfinity(Single.NegativeInfinity));
			featureTest.AssertTrue(Single.IsPositiveInfinity(Single.PositiveInfinity));
			featureTest.AssertTrue(!Single.IsPositiveInfinity(Single.NaN));
#if V3
			featureTest.AssertTrue(Single.IsFinite(3.0F / 1F));
			featureTest.AssertTrue(!Single.IsFinite(Single.NaN));
			featureTest.AssertTrue(Single.IsNegative(-3.0F));
			featureTest.AssertTrue(!Single.IsNegative(3.0F));
			featureTest.AssertTrue(Single.IsNegative(Single.NaN));
			featureTest.AssertTrue(Single.IsNormal(3.0F));
			featureTest.AssertTrue(!Single.IsNormal(Single.PositiveInfinity));
			featureTest.AssertTrue(!Single.IsNormal(Single.NaN));
			featureTest.AssertTrue(Single.IsSubnormal(-1.401298E-45f));
			featureTest.AssertTrue(Single.IsSubnormal(1.17549421E-38f));
			featureTest.AssertTrue(!Single.IsSubnormal(1.17549435E-38f));
#endif
		}

		private void OperatorTests()
		{
			featureTest.FailureMessage = "\tFailed Single Operator Test";
			featureTest.Send("Single Operator Test");
			Single value = 1;
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
			Single newvalue = value / 0;
			featureTest.AssertTrue(Single.IsInfinity(newvalue));
			newvalue = 0;
			newvalue /= 0;
			featureTest.AssertTrue(Single.IsNaN(newvalue));
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
