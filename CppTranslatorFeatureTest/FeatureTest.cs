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
			Int32Test int32Test = new Int32Test(this);
			int32Test.Run();
			Int64Test int64Test = new Int64Test(this);
			int64Test.Run();
			SByteTest sbyteTest = new SByteTest(this);
			sbyteTest.Run();
			UInt16Test uint16Test = new UInt16Test(this);
			uint16Test.Run();
			UInt32Test uint32Test = new UInt32Test(this);
			uint32Test.Run();
			UInt64Test uint64Test = new UInt64Test(this);
			uint64Test.Run();
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
