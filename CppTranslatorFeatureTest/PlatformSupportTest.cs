using System;

namespace CppTranslatorFeatureTest
{
	public class PlatformSupportTest
	{
		FeatureTest featureTest;
		public PlatformSupportTest(FeatureTest featureTest)
		{
			this.featureTest = featureTest;
		}
		public void Run()
		{
			featureTest.FailureMessage = "\tFailed Platform Support Test";
			featureTest.Send("Platform Support Test");
			featureTest.AssertTrue(featureTest.ArrayData != null);
			featureTest.AssertTrue(featureTest.ArrayData.Length == 4);
			featureTest.AssertTrue(featureTest.DoubleData == 5.5);
		}
	}
}
