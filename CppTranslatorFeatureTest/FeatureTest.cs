using CppTranslatorSupport;
using System;

namespace CppTranslatorFeatureTest
{
	public class FeatureTest : DataAccess
	{
		public FeatureTest()
		{
			Send("Starting Feature Tests");
		}
		public override void RunCode()
		{
			Send("Starting Feature Tests");
			Send("Finished Feature Tests");
		}
	}
}
