using System;

namespace CppTranslatorFeatureTest
{
	public class Int32Test
	{
		FeatureTest featureTest;
		public Int32Test(FeatureTest featureTest)
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
			featureTest.FailureMessage = "\tFailed Int32 Method Test";
			featureTest.Send("Int32 Method Test");
			Int32 value1 = 1;
			Int32 value2 = 2;
			Int32 value3 = 3;
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
			featureTest.AssertTrue(Int32.Parse("33") == 33);
			String str = 35.ToString();
			featureTest.AssertTrue(str == "35");
			Int32 parsed;
			featureTest.AssertTrue(Int32.TryParse(str, out parsed));
			featureTest.AssertTrue(parsed == 35);
		}
		private void OperatorTests()
		{
			featureTest.FailureMessage = "\tFailed Int32 Operator Test";
			featureTest.Send("Int32 Operator Test");
			Int32 value = 1;
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
			value = Int32.MinValue;
			featureTest.AssertTrue(value == Int32.MinValue);
			value = Int32.MinValue;
			featureTest.AssertTrue((Int32)(value - 1) == Int32.MaxValue);
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
				value = (Int32)(value / 0);
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
			featureTest.FailureMessage = "\tFailed Int32 Bitwise Operator Test";
			featureTest.Send("Int32 Bitwise Operator Test");
			Int32 value = 0;
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
