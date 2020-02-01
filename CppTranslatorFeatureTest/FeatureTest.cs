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
	}
}
