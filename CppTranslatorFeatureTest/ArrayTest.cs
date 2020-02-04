using System;

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
			PropertyTests();
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
			Int32[] array = new Int32[] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
			Array.Clear(array, 2, 3);
			featureTest.AssertTrue(array[1] == 2);
			featureTest.AssertTrue(array[2] == 0);
			featureTest.AssertTrue(array[3] == 0);
			featureTest.AssertTrue(array[4] == 0);
			featureTest.AssertTrue(array[5] == 6);

			array = new Int32[] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
			Int32[] array2 = new Int32[] { 11, 12, 13, 14, 15 };
			Array.ConstrainedCopy(array, 2, array2, 1, 3);
			featureTest.AssertTrue(array2[0] == 11);
			featureTest.AssertTrue(array2[1] == 3);
			featureTest.AssertTrue(array2[2] == 4);
			featureTest.AssertTrue(array2[3] == 5);
			featureTest.AssertTrue(array2[4] == 15);
			Int32[] array3 = new Int32[array.Length];
			Array.Copy(array, array3, array.Length);
			for (Int32 i = 0; i < array.Length; ++i)
			{
				featureTest.AssertTrue(array[i] == array3[i]);
			}
			Array.Clear(array3, 0, array3.Length);
			array.CopyTo(array3, 0);
			for (Int32 i = 0; i < array.Length; ++i)
			{
				featureTest.AssertTrue(array[i] == array3[i]);
			}
			featureTest.AssertTrue(int323DArray.GetLength(0) == 2);
			featureTest.AssertTrue(int323DArray.GetLength(1) == 2);
			featureTest.AssertTrue(int323DArray.GetLength(2) == 4);
			featureTest.AssertTrue(int323DArray.GetLowerBound(0) == 0);
			featureTest.AssertTrue(int323DArray.GetLowerBound(1) == 0);
			featureTest.AssertTrue(int323DArray.GetLowerBound(2) == 0);
			featureTest.AssertTrue(int323DArray.GetUpperBound(0) == 1);
			featureTest.AssertTrue(int323DArray.GetUpperBound(1) == 1);
			featureTest.AssertTrue(int323DArray.GetUpperBound(2) == 3);
			featureTest.AssertTrue(!(Boolean)boolean1DArray.GetValue(1));
			featureTest.AssertTrue((Byte)byte1DArray.GetValue(0) == 1);
			featureTest.AssertTrue((Char)char1DArray.GetValue(1) == 'B');
			featureTest.AssertTrue((Double)double1DArray.GetValue(2) == 3.0);
			featureTest.AssertTrue((Int16)int161DArray.GetValue(3) == 4);
			featureTest.AssertTrue((Int32)int321DArray.GetValue(4) == 5);
			featureTest.AssertTrue((Int64)int641DArray.GetValue(5) == 6);
			featureTest.AssertTrue((SByte)sbyte1DArray.GetValue(6) == 7);
			featureTest.AssertTrue((Single)single1DArray.GetValue(7) == 8.0F);
			featureTest.AssertTrue((String)string1DArray.GetValue(8) == "Nine");
			featureTest.AssertTrue((UInt16)uint161DArray.GetValue(9) == 0);
			featureTest.AssertTrue((UInt32)uint321DArray.GetValue(0) == 1);
			featureTest.AssertTrue((UInt64)uint641DArray.GetValue(1) == 2);
			featureTest.AssertTrue((DateTime)dateTime1DArray.GetValue(1) == new DateTime(2020, 2, 3, 8, 30, 40));
			featureTest.AssertTrue((TimeSpan)timeSpan1DArray.GetValue(2) == new TimeSpan(7, 8, 9));
			featureTest.AssertTrue(Array.IndexOf(string1DArray, "Eight") == 7);
			Int32[,,] array3d = new Int32[2,2,4];
			Int32[] indexes = new Int32[] { 1,1,2};
			array3d.SetValue(22, indexes);
			featureTest.AssertTrue(array3d[1,1,2] == 22);
			array3d.SetValue(25, 0,0,1);
			featureTest.AssertTrue(array3d[0, 0, 1] == 25);
		}
		private void PropertyTests()
		{
			featureTest.FailureMessage = "\tFailed Array Property Test";
			featureTest.Send("Array Property Test");
			featureTest.AssertTrue(uint321DArray.Length == 10);
			featureTest.AssertTrue(uint321DArray.Rank == 1);
			featureTest.AssertTrue(int323DArray.Rank == 3);
		}
	}
}
