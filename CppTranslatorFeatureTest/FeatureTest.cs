using CppTranslatorSupport;
using System;

namespace CppTranslatorFeatureTest
{
	public class FeatureTest : DataAccess
	{
		public String FailureMessage { get; set; }
		public FeatureTest()
		{
		}
		public override void RunCode()
		{
			Send("Starting Feature Tests **");
			BooleanTest booleanTest = new BooleanTest(this);
			booleanTest.Run();
			ArrayTest arrayTest = new ArrayTest(this);
			arrayTest.Run();
			BufferTest bufferTest = new BufferTest(this);
			bufferTest.Run();
			ByteTest byteTest = new ByteTest(this);
			byteTest.Run();
			Int16Test int16Test = new Int16Test(this);
			int16Test.Run();
			Send("Finished Feature Tests**");
		}
		public void	AssertTrue(bool value)
		{
			if (!value)
				Send(FailureMessage);
		}
		public void AssertTrue(bool value1, bool value2)
		{
			if (value1 != value2)
				Send(FailureMessage);
		}
		public void AssertTrue(Double value1, Double value2, Double percision)
		{
			Double delta = Math.Abs(value1 - value2);
			if (delta > percision)
				Send(FailureMessage);
		}
		public void AssertTrue(Double value1, Double value2)
		{
			AssertTrue(value1, value2 , 0.000001);
		}
		public static void Main(string[] args)
		{
			FeatureTest featureTest = new FeatureTest();
			featureTest.RunCode();
		}
	}
}
