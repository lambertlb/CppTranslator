using System;
using System.Collections.Generic;
using System.Text;

namespace CppTranslatorFeatureTest
{
	public class ArrayTest
	{
		FeatureTest featureTest;
		Boolean[] boolean1DArray = new Boolean[] { true, false, true, false };
		Byte[] byte1DArray = new Byte[] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
		Char[] char1DArray = new Char[] { 'A', 'B', 'C', 'D', 'E', 'F' };
		Double[] double1DArray = new Double[] { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 0.0 };
		Int16[] int161DArray = new Int16[] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
		Int32[] int321DArray = new Int32[] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
		Int64[] int641DArray = new Int64[] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
		SByte[] sbyte1DArray = new SByte[] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
		Single[] single1DArray = new Single[] { 1.0F, 2.0F, 3.0F, 4.0F, 5.0F, 6.0F, 7.0F, 8.0F, 9.0F, 0.0F };
		String[] string1DArray = new String[] { "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten" };
		UInt16[] uint161DArray = new UInt16[] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
		UInt32[] uint321DArray = new UInt32[] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
		UInt64[] uint641DArray = new UInt64[] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
		DateTime[] dateTime1DArray;
		TimeSpan[] timeSpan1DArray;

		Int32[,] int322DArray = new Int32[,] { { 1, 2, 3, 4, 5 }, { 6, 7, 8, 9, 0 } };
		Int32[,,] int323DArray = new Int32[,,] { { { 1, 2, 3, 4 }, { 5, 6, 7, 8 } }, { { 9, 10, 11, 12 }, { 13, 14, 15, 16 } } };

		public ArrayTest(FeatureTest featureTest)
		{
			this.featureTest = featureTest;
		}
		public void Run()
		{
			ConstructorTests();
			ArrayAccessTests();
			MethodTests();
			OperatorsTests();
		}

		private void ConstructorTests()
		{
			featureTest.FailureMessage = "\tFailed Array Constructor Test";
			featureTest.Send("Array Constructor Test");
			dateTime1DArray = new DateTime[] { new DateTime(2020, 2, 2, 8, 30, 40), new DateTime(2020, 2, 3, 8, 30, 40), new DateTime(2020, 2, 4, 8, 30, 40) };
			timeSpan1DArray = new TimeSpan[] { new TimeSpan(1, 2, 3), new TimeSpan(4, 5, 6), new TimeSpan(7, 8, 9) };
			featureTest.AssertTrue(boolean1DArray != null);
			featureTest.AssertTrue(byte1DArray != null);
			featureTest.AssertTrue(char1DArray != null);
			featureTest.AssertTrue(double1DArray != null);
			featureTest.AssertTrue(int161DArray != null);
			featureTest.AssertTrue(int321DArray != null);
			featureTest.AssertTrue(int641DArray != null);
			featureTest.AssertTrue(sbyte1DArray != null);
			featureTest.AssertTrue(single1DArray != null);
			featureTest.AssertTrue(string1DArray != null);
			featureTest.AssertTrue(uint161DArray != null);
			featureTest.AssertTrue(uint321DArray != null);
			featureTest.AssertTrue(uint641DArray != null);
			featureTest.AssertTrue(dateTime1DArray != null);
			featureTest.AssertTrue(timeSpan1DArray != null);
			featureTest.AssertTrue(int322DArray != null);
			featureTest.AssertTrue(int323DArray != null);
		}
		private void ArrayAccessTests()
		{
			featureTest.FailureMessage = "\tFailed Array Access Test";
			featureTest.Send("Array Access Test");
			featureTest.AssertTrue(boolean1DArray[2]);
			featureTest.AssertTrue(byte1DArray[2] == 3);
			featureTest.AssertTrue(char1DArray[3] == 'D');
			featureTest.AssertTrue(double1DArray[4] == 5.0);
			featureTest.AssertTrue(int161DArray[6] == 7);
			featureTest.AssertTrue(int321DArray[7] == 8);
			featureTest.AssertTrue(int641DArray[8] == 9);
			featureTest.AssertTrue(sbyte1DArray[9] == 0);
			featureTest.AssertTrue(single1DArray[0] == 1.0F);
			featureTest.AssertTrue(string1DArray[1] == "Two");
			featureTest.AssertTrue(uint161DArray[2] == 3);
			featureTest.AssertTrue(uint321DArray[3] == 4);
			featureTest.AssertTrue(uint641DArray[4] == 5);
			featureTest.AssertTrue(dateTime1DArray[1] == new DateTime(2020, 2, 3, 8, 30, 40));
			featureTest.AssertTrue(timeSpan1DArray[2] == new TimeSpan(7, 8, 9));
			featureTest.AssertTrue(int322DArray[1, 1] == 7);
			featureTest.AssertTrue(int323DArray[1, 1, 1] == 14);
			bool hadException = false;
			try
			{
				featureTest.AssertTrue(int323DArray[10, 10, 10] == 14);
			}
			catch (IndexOutOfRangeException)
			{
				hadException = true;
			}
			featureTest.AssertTrue(hadException);
		}

		private void MethodTests()
		{
			featureTest.FailureMessage = "\tFailed Array Methods Test";
			featureTest.Send("Array Methods Test");
		}
		private void OperatorsTests()
		{
			featureTest.FailureMessage = "\tFailed Array Operators Test";
			featureTest.Send("Array Operators Test");
		}

	}
}
