using System;
using CppTranslatorSupport;

namespace MiniTest
{
	public class Program : DataAccess
	{
		public Program()
		{
		}
		public override void RunCode()
		{
			String value = new String("Test String");
			AssertTrue(value.Length == 11);
		}
		public void AssertTrue(bool value)
		{
			if (!value)
				Send("Failed");
		}
		public void AssertTrue(Double value1, Double value2)
		{
			AssertTrue(Math.Round(value1, 4) == Math.Round(value2, 4));
		}
		public static int Main(String[] arvs)
		{
			Program featureTest = new Program();
			featureTest.RunCode();
			return (0);
		}
	}
}
