using System;

namespace CppTranslatorFeatureTest
{
	public class UInt64Test
	{
		FeatureTest featureTest;
		public UInt64Test(FeatureTest featureTest)
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
			featureTest.FailureMessage = "\tFailed UInt64 Method Test";
			featureTest.Send("UInt64 Method Test");
			UInt64 value1 = 1;
			UInt64 value2 = 2;
			UInt64 value3 = 3;
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
			featureTest.AssertTrue(UInt64.Parse("33") == 33);
			String str = 35.ToString();
			featureTest.AssertTrue(str == "35");
			UInt64 parsed;
			featureTest.AssertTrue(UInt64.TryParse(str, out parsed));
			featureTest.AssertTrue(parsed == 35);
		}
		private void OperatorTests()
		{
			featureTest.FailureMessage = "\tFailed UInt64 Operator Test";
			featureTest.Send("UInt64 Operator Test");
			UInt64 value = 1;
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
			value = UInt64.MinValue;
			featureTest.AssertTrue(value == UInt64.MinValue);
			value = UInt64.MinValue;
			featureTest.AssertTrue((UInt64)(value - 1) == UInt64.MaxValue);
			value = -(-1);
			featureTest.AssertTrue(value == 1);
			value = 10;
			featureTest.AssertTrue(value * 2 == 20);
			featureTest.AssertTrue(value / 5 == 2);
			featureTest.AssertTrue(value / 3 == 3);
			featureTest.AssertTrue(value % 5 == 0);
			featureTest.AssertTrue(value % 3 == 1);
			featureTest.AssertTrue(value + 5 == 15);
			featureTest.AssertTrue(value - 5 == 5);
			featureTest.AssertTrue(value + (value * value) == 110);
			bool gotException = false;
			try
			{
				value = (UInt64)(value / 0);
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
			featureTest.FailureMessage = "\tFailed UInt64 Bitwise Operator Test";
			featureTest.Send("UInt64 Bitwise Operator Test");
			UInt64 value = 0;
			featureTest.AssertTrue(~value == UInt64.MaxValue);
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
