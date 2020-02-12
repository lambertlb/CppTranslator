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
			StringBuilder sb = new StringBuilder();
			sb.Append("ABC");
			String value = sb.ToString();
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
