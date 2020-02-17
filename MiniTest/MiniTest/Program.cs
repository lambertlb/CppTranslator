using System;
using System.Text;
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
			Int32 value = 2;
			value = value == 2 ? 3 : 1;
			AssertTrue(value == 3);
			value = value <= 3 ? 1 : 0;
			AssertTrue(value == 1);
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
