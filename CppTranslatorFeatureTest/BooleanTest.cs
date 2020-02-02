using System;
using System.Collections.Generic;
using System.Text;

namespace CppTranslatorFeatureTest
{
	public class BooleanTest
	{
		FeatureTest featureTest;
		public BooleanTest(FeatureTest featureTest)
		{
			this.featureTest = featureTest;
		}
		public void	Run()
		{
			MethodTests();
			OperatorsTests();
		}

		private void OperatorsTests()
		{
			featureTest.FailureMessage = "\tFailed Boolean Operators Test";
			featureTest.Send("Boolean Operators Test");
			bool value1 = false;
			bool value2 = false;
			featureTest.AssertTrue(!value1);
			value1 = true;
			featureTest.AssertTrue(value1);
			featureTest.AssertTrue(true);
			featureTest.AssertTrue(!false);
			value1 = value2 = true;
			featureTest.AssertTrue(value1 & value2);
			value2 = false;
			featureTest.AssertTrue(!(value1 & value2));
			value1 = value2 = true;
			featureTest.AssertTrue(!(value1 ^ value2));
			value2 = false;
			featureTest.AssertTrue(value1 ^ value2);
			value1 = value2 = true;
			featureTest.AssertTrue(value1 | value2);
			value2 = false;
			featureTest.AssertTrue(value1 | value2);
			value1 = false;
			featureTest.AssertTrue(!(value1 | value2));
			value1 = value2 = true;
			featureTest.AssertTrue(value1 && value2);
			value2 = false;
			featureTest.AssertTrue(!(value1 && value2));
			value1 = value2 = true;
			featureTest.AssertTrue(value1 || value2);
			value2 = false;
			featureTest.AssertTrue(value1 || value2);
			value1 = false;
			featureTest.AssertTrue(!(value1 || value2));
		}

		public void	MethodTests()
		{
			featureTest.FailureMessage = "\tFailed Boolean Method Test";
			featureTest.Send("Boolean Method Test");
			bool value1 = true;
			bool value2 = false;
			featureTest.AssertTrue(value1.CompareTo(true) == 0);
			featureTest.AssertTrue(value2.CompareTo(false) == 0);
			featureTest.AssertTrue(value1.CompareTo(false) == 1);
			featureTest.AssertTrue(value2.CompareTo(true) == -1);

			featureTest.AssertTrue(value1.CompareTo((Object)true) == 0);
			featureTest.AssertTrue(value2.CompareTo((Object)false) == 0);
			featureTest.AssertTrue(value1.CompareTo((Object)false) == 1);
			featureTest.AssertTrue(value2.CompareTo((Object)true) == -1);

			featureTest.AssertTrue(value1.Equals(true));
			featureTest.AssertTrue(value2.Equals(false));
			featureTest.AssertTrue(!value1.Equals(false));
			featureTest.AssertTrue(!value2.Equals(true));

			featureTest.AssertTrue(value1.Equals((Object)true));
			featureTest.AssertTrue(value2.Equals((Object)false));
			featureTest.AssertTrue(!value1.Equals((Object)false));
			featureTest.AssertTrue(!value2.Equals((Object)true));
			featureTest.AssertTrue(Boolean.Parse("true"));
			featureTest.AssertTrue(!Boolean.Parse("false"));
			bool hadException = false;
			try
			{
				bool val = Boolean.Parse("Bad");
			} catch(Exception)
			{
				hadException = true;
			}
			featureTest.AssertTrue(hadException);
			featureTest.AssertTrue(value1.ToString().Equals(Boolean.TrueString));
			featureTest.AssertTrue(value2.ToString().Equals(Boolean.FalseString));
			featureTest.AssertTrue(((Object)value1).ToString().Equals(Boolean.TrueString));
			featureTest.AssertTrue(((Object)value2).ToString().Equals(Boolean.FalseString));
		}
	}
}
