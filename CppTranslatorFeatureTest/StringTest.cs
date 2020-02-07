using System;

namespace CppTranslatorFeatureTest
{
	public class StringTest
	{
		FeatureTest featureTest;
		public StringTest(FeatureTest featureTest)
		{
			this.featureTest = featureTest;
		}
		public void Run()
		{
			PropertyTests();
			OperatorTests();
			MethodTests();
		}
		private void PropertyTests()
		{
			featureTest.FailureMessage = "\tFailed String Property Test";
			featureTest.Send("String Property Test");
			String value = new String("Test String");
			featureTest.AssertTrue(value.Length == 11);
			featureTest.AssertTrue(value[0] == 'T');
			featureTest.AssertTrue(value[10] == 'g');
			bool gotException = false;
			try
			{
				featureTest.AssertTrue(value[20] == '?');
			}
			catch (IndexOutOfRangeException ex)
			{
				gotException = true;
			}
			featureTest.AssertTrue(gotException);
		}
		private void OperatorTests()
		{
			featureTest.FailureMessage = "\tFailed String Operator Test";
			featureTest.Send("String Operator Test");
			String value = new String("Test String");
			featureTest.AssertTrue(value == "Test String");
			featureTest.AssertTrue(value != "Test StringA");
		}
		private void MethodTests()
		{
			featureTest.FailureMessage = "\tFailed String Method Test";
			featureTest.Send("String Method Test");
			String value1 = new String("1ABCDEFGHI");
			String value2 = new String("2ABCDEFGHI");
			String value2a = new String("2ABCDEFGHI");
			String value2b = new String("2abcdefghi");
			String value3 = new String("3ABCDEFGHI");
			featureTest.AssertTrue(String.Compare(value2, value2a) == 0);
			featureTest.AssertTrue(String.Compare(value2, value2b) > 0);
			featureTest.AssertTrue(String.Compare(value2, value1) > 0);
			featureTest.AssertTrue(String.Compare(value2, value3) < 0);

			featureTest.AssertTrue(String.Compare(value2, value2a, true) == 0);
			featureTest.AssertTrue(String.Compare(value2, value2b, true) == 0);
			featureTest.AssertTrue(String.Compare(value2, value1, true) > 0);
			featureTest.AssertTrue(String.Compare(value2, value3, true) < 0);

			featureTest.AssertTrue(String.Compare(value2, 1, value3, 1, 4) == 0);
			featureTest.AssertTrue(String.CompareOrdinal(value2, value2a) == 0);
			featureTest.AssertTrue(String.CompareOrdinal(value2, value2b) < 0);
			featureTest.AssertTrue(String.CompareOrdinal(value2, 1, value3, 1, 4) == 0);
			featureTest.AssertTrue(value2.CompareTo(value2a) == 0);
			featureTest.AssertTrue(value2.CompareTo(value2b) > 0);
			featureTest.AssertTrue(value2.CompareTo(value3) < 0);
			featureTest.AssertTrue(value2.CompareTo((Object)value2a) == 0);
			featureTest.AssertTrue(value2.CompareTo((Object)value2b) > 0);
			featureTest.AssertTrue(value2.CompareTo((Object)value3) < 0);
		}
	}
}
