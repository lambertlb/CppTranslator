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
using CppTranslatorSupport;
using System;

namespace CppTranslatorFeatureTest
{
	public class FeatureTest : DataAccess
	{
		public String FailureMessage { get; set; }
		private bool allTestPassed;
		public FeatureTest()
		{
		}
		public override void RunCode()
		{
			allTestPassed = true;
			Send("Starting Feature Tests **");
			try
			{
				BooleanTest booleanTest = new BooleanTest(this);
				booleanTest.Run();
				ArrayTest arrayTest = new ArrayTest(this);
				arrayTest.Run();
				BufferTest bufferTest = new BufferTest(this);
				bufferTest.Run();
				BitConverterTest bitConverterTest = new BitConverterTest(this);
				bitConverterTest.Run();
				ByteTest byteTest = new ByteTest(this);
				byteTest.Run();
				CharTest charTest = new CharTest(this);
				charTest.Run();
				DateTimeTest dateTimeTest = new DateTimeTest(this);
				dateTimeTest.Run();
				DoubleTest doubleTest = new DoubleTest(this);
				doubleTest.Run();
				Int16Test int16Test = new Int16Test(this);
				int16Test.Run();
				Int32Test int32Test = new Int32Test(this);
				int32Test.Run();
				Int64Test int64Test = new Int64Test(this);
				int64Test.Run();
				MathTest mathTest = new MathTest(this);
				mathTest.Run();
				MiscTest miscTest = new MiscTest(this);
				miscTest.Run();
				SByteTest sbyteTest = new SByteTest(this);
				sbyteTest.Run();
				SingleTest singleTest = new SingleTest(this);
				singleTest.Run();
				StringTest stringTest = new StringTest(this);
				stringTest.Run();
				StringBuilderTest stringBuilderTest = new StringBuilderTest(this);
				stringBuilderTest.Run();
				TimeSpanTest timeSpanTest = new TimeSpanTest(this);
				timeSpanTest.Run();
				UInt16Test uint16Test = new UInt16Test(this);
				uint16Test.Run();
				UInt32Test uint32Test = new UInt32Test(this);
				uint32Test.Run();
				UInt64Test uint64Test = new UInt64Test(this);
				uint64Test.Run();
				PlatformSupportTest platformSupportTest = new PlatformSupportTest(this);
				platformSupportTest.Run();
			}
			catch (Exception)
			{
				allTestPassed = false;
			}
			if (allTestPassed)
				Send("==========SUCCESS All tests passed ===");
			else
				Send("==========FAILED some tests failed ===");
		}
		public void AssertTrue(bool value)
		{
			if (!value)
			{
				allTestPassed = false;
				Send(FailureMessage);
			}
		}
		public void AssertTrue(bool value1, bool value2)
		{
			if (value1 != value2)
			{
				allTestPassed = false;
				Send(FailureMessage);
			}
		}
		public void AssertTrue(Double value1, Double value2)
		{
			AssertTrue(Math.Round(value1, 4) == Math.Round(value2, 4));
		}
		public static void Main()
		{
			FeatureTest featureTest = new FeatureTest();
			featureTest.RunCode();
		}
	}
}
