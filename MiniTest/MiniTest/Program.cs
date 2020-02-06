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
			Int32 whole;
			Int32 remainder;
			whole = Math.DivRem(2147483647, 1073741, out remainder);
			AssertTrue(whole == 2000 && remainder == 1647);
			Int64 whole2;
			Int64 remainder2;
			whole2 = Math.DivRem(9223372036854775807L, 4611686018427387L, out remainder2);
			AssertTrue(whole2 == 2000 && remainder2 == 1807L);
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
