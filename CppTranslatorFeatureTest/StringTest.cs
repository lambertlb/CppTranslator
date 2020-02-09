using System;

namespace CppTranslatorFeatureTest
{
	public class StringTest
	{
		FeatureTest featureTest;
		public StringTest(FeatureTest featureTest)
		{
			this.featureTest = featureTest;
		}
		public void Run()
		{
			PropertyTests();
			OperatorTests();
			MethodTests();
		}
		private void PropertyTests()
		{
			featureTest.FailureMessage = "\tFailed String Property Test";
			featureTest.Send("String Property Test");
			String value = new String("Test String");
			featureTest.AssertTrue(value.Length == 11);
			featureTest.AssertTrue(value[0] == 'T');
			featureTest.AssertTrue(value[10] == 'g');
			bool gotException = false;
			try
			{
				featureTest.AssertTrue(value[20] == '?');
			}
			catch (IndexOutOfRangeException)
			{
				gotException = true;
			}
			featureTest.AssertTrue(gotException);
		}
		private void OperatorTests()
		{
			featureTest.FailureMessage = "\tFailed String Operator Test";
			featureTest.Send("String Operator Test");
			String value = new String("Test String");
			featureTest.AssertTrue(value == "Test String");
			featureTest.AssertTrue(value != "Test StringA");
		}
		private void MethodTests()
		{
			featureTest.FailureMessage = "\tFailed String Method Test";
			featureTest.Send("String Method Test");
			String value1 = new String("1ABCDEFGHIJKL");
			String value2 = new String("2ABCDEFGHIJKL");
			String value2a = new String("2ABCDEFGHIJKL");
			String value2b = new String("2abcdefghijkl");
			String value3 = new String("3ABCDEFGHIJKL");
			featureTest.AssertTrue(String.Compare(value2, value2a) == 0);
			featureTest.AssertTrue(String.Compare(value2, value2b) > 0);
			featureTest.AssertTrue(String.Compare(value2, value1) > 0);
			featureTest.AssertTrue(String.Compare(value2, value3) < 0);

			featureTest.AssertTrue(String.Compare(value2, value2a, true) == 0);
			featureTest.AssertTrue(String.Compare(value2, value2b, true) == 0);
			featureTest.AssertTrue(String.Compare(value2, value1, true) > 0);
			featureTest.AssertTrue(String.Compare(value2, value3, true) < 0);

			featureTest.AssertTrue(String.Compare(value2, 1, value3, 1, 4) == 0);
			featureTest.AssertTrue(String.CompareOrdinal(value2, value2a) == 0);
			featureTest.AssertTrue(String.CompareOrdinal(value2, value2b) < 0);
			featureTest.AssertTrue(String.CompareOrdinal(value2, 1, value3, 1, 4) == 0);
			featureTest.AssertTrue(value2.CompareTo(value2a) == 0);
			featureTest.AssertTrue(value2.CompareTo(value2b) > 0);
			featureTest.AssertTrue(value2.CompareTo(value3) < 0);
			featureTest.AssertTrue(value2.CompareTo((Object)value2a) == 0);
			featureTest.AssertTrue(value2.CompareTo((Object)value2b) > 0);
			featureTest.AssertTrue(value2.CompareTo((Object)value3) < 0);
			String string1 = new String("ABC");
			String string2 = new String("DEF");
			String string3 = new String("GHI");
			String string4 = new String("JKL");
			String s2 = String.Concat(string1, string2, string3, string4);
			featureTest.AssertTrue(s2 == "ABCDEFGHIJKL");
			String s3 = String.Concat((Object)string1, (Object)string2, (Object)string3, (Object)string4);
			featureTest.AssertTrue(s3 == "ABCDEFGHIJKL");
			Object[] list = new object[] { string1, string2, string3, string4 };
			String s4 = String.Concat(list);
			featureTest.AssertTrue(s4 == "ABCDEFGHIJKL");
			featureTest.AssertTrue(value1.Contains(string1));
			String s5 = new String("1234567890");
			Char[] data = new Char[] { 'A', 'B', 'C', 'D', 'E', 'F' };
			s5.CopyTo(3, data, 2, 3);
			featureTest.AssertTrue(data[0] == 'A');
			featureTest.AssertTrue(data[1] == 'B');
			featureTest.AssertTrue(data[2] == '4');
			featureTest.AssertTrue(data[3] == '5');
			featureTest.AssertTrue(data[4] == '6');
			featureTest.AssertTrue(data[5] == 'F');
			featureTest.AssertTrue(value1.EndsWith(string4));
			featureTest.AssertTrue(!value1.EndsWith(string3));
			featureTest.AssertTrue(value1.EndsWith('L'));
			featureTest.AssertTrue(!value1.EndsWith('Z'));
			featureTest.AssertTrue(value2.Equals(value2a));
			featureTest.AssertTrue(!value2.Equals(value1));
			featureTest.AssertTrue(value2.Equals((Object)value2a));
			featureTest.AssertTrue(!value2.Equals((Object)value1));
			featureTest.AssertTrue(String.Equals(value2, value2a));
			featureTest.AssertTrue(!String.Equals(value2, value1));
			featureTest.AssertTrue(String.Equals(value2,(Object)value2a));
			featureTest.AssertTrue(!String.Equals(value2,(Object)value1));
			CharEnumerator iter = value1.GetEnumerator();
			Int32 i = 0;
			while (iter.MoveNext())
			{
				featureTest.AssertTrue(iter.Current == value1[i++]);
			}
			i = 0;
			iter.Reset();
			while (iter.MoveNext())
			{
				featureTest.AssertTrue(iter.Current == value1[i++]);
			}
			featureTest.AssertTrue(value1.IndexOf('1') == 0);
			featureTest.AssertTrue(value1.IndexOf('A') == 1);
			featureTest.AssertTrue(value1.IndexOf('L') == 12);
			featureTest.AssertTrue(value1.IndexOf("1") == 0);
			featureTest.AssertTrue(value1.IndexOf("A") == 1);
			featureTest.AssertTrue(value1.IndexOf("L") == 12);
			featureTest.AssertTrue(value1.IndexOf("JKL") == 10);
			Char[] chars = new Char[] { 'I', 'C' };
			featureTest.AssertTrue(value1.IndexOfAny(chars) == 3);
			featureTest.AssertTrue(value1.IndexOfAny(chars,5) == 9);
			featureTest.AssertTrue(value1.IndexOfAny(chars, 0, 2) == -1);
			featureTest.AssertTrue(value1.IndexOfAny(chars, 8, 2) == 9);
			featureTest.AssertTrue(string1.Insert(1,string2) == "ADEFBC");
			featureTest.AssertTrue(String.IsNullOrEmpty(null));
			featureTest.AssertTrue(String.IsNullOrEmpty(String.Empty));
			featureTest.AssertTrue(!String.IsNullOrEmpty(value1));
			featureTest.AssertTrue(String.IsNullOrWhiteSpace(null));
			featureTest.AssertTrue(String.IsNullOrWhiteSpace(String.Empty));
			featureTest.AssertTrue(!String.IsNullOrWhiteSpace(value1));
			featureTest.AssertTrue(String.IsNullOrWhiteSpace(" \t "));
			featureTest.AssertTrue(String.Join(',', list) == "ABC,DEF,GHI,JKL");
			featureTest.AssertTrue(String.Join(String.Empty, list) == "ABCDEFGHIJKL");
			String[] stringList = new String[] { string1, string2, string3, string4 };
			featureTest.AssertTrue(String.Join(',', stringList, 1, 3) == "DEF,GHI,JKL");
			featureTest.AssertTrue(String.Join(String.Empty, stringList, 1, 3) == "DEFGHIJKL");
			String  str11 = new String("11223311");
			featureTest.AssertTrue(str11.LastIndexOf('1') == 7);
			featureTest.AssertTrue(str11.LastIndexOf('1', 4) == 1);
			featureTest.AssertTrue(str11.LastIndexOf('1', 4, 4) == 1);
			String subString = new String("11");
			featureTest.AssertTrue(str11.LastIndexOf(subString) == 6);
			featureTest.AssertTrue(str11.LastIndexOf(subString, 4) == 0);
			featureTest.AssertTrue(str11.LastIndexOf(subString, 4, 5) == 0);
			String subString2 = new String("1");
			featureTest.AssertTrue(str11.LastIndexOf(subString2) == 7);
			Char[] data10 = new Char[]{ '1', '2' };
			featureTest.AssertTrue(str11.LastIndexOfAny(data10) == 7);
			featureTest.AssertTrue(str11.LastIndexOfAny(data10, 4) == 3);
			featureTest.AssertTrue(str11.LastIndexOfAny(data10, 4, 4) == 3);
			featureTest.AssertTrue(str11.PadLeft(13) == "     11223311");
			featureTest.AssertTrue(str11.PadLeft(13, '-') == "-----11223311");
			featureTest.AssertTrue(str11.PadRight(13) == "11223311     ");
			featureTest.AssertTrue(str11.PadRight(13, '-') == "11223311-----");
			featureTest.AssertTrue(str11.Remove(2, 2) == "113311");
			featureTest.AssertTrue(str11.Remove(6, 2) == "112233");
			featureTest.AssertTrue(str11.Remove(0, 2) == "223311");
			featureTest.AssertTrue(str11.Replace('1', 'A') == "AA2233AA");
			featureTest.AssertTrue(str11.Replace("11", "ZZ") == "ZZ2233ZZ");
			featureTest.AssertTrue(str11.StartsWith("11"));
			featureTest.AssertTrue(!str11.StartsWith("22"));
			featureTest.AssertTrue(str11.Substring(2) == "223311");
			featureTest.AssertTrue(str11.Substring(6, 2) == "11");
			Char[] characterArray = str11.ToCharArray();
			featureTest.AssertTrue(characterArray.Length == 8);
			featureTest.AssertTrue(characterArray[0] == '1');
			featureTest.AssertTrue(characterArray[7] == '1');
			Char[] characterArray1 = str11.ToCharArray(4,2);
			featureTest.AssertTrue(characterArray1.Length == 2);
			featureTest.AssertTrue(characterArray1[0] == '3');
			featureTest.AssertTrue(characterArray1[1] == '3');
			featureTest.AssertTrue(value1.ToLower() == "1abcdefghijkl");
			featureTest.AssertTrue(value2b.ToUpper() == value2);
			String  str12 = new String(" \tABCDEFGHI\n\r");
			String str13 = new String(" \tABCDEFGHI\n\r\t");
			String str14 = new String("\r \tABCDEFGHI\n\r");
			featureTest.AssertTrue(str12.Trim() == "ABCDEFGHI");
			Char[] white = new char[]{ ' ', '\t' };
			Char[] white2 = new char[] { '\n', '\r' };
			featureTest.AssertTrue(str12.Trim(white) == "ABCDEFGHI\n\r");
			featureTest.AssertTrue(str12.Trim(null) == "ABCDEFGHI");
			featureTest.AssertTrue(str12.TrimEnd(null) == " \tABCDEFGHI");
			featureTest.AssertTrue(str12.TrimEnd(white) == " \tABCDEFGHI\n\r");
			featureTest.AssertTrue(str13.TrimEnd(white) == " \tABCDEFGHI\n\r");
			featureTest.AssertTrue(str12.TrimStart(null) == "ABCDEFGHI\n\r");
			featureTest.AssertTrue(str12.TrimStart(white2) == " \tABCDEFGHI\n\r");
			featureTest.AssertTrue(str14.TrimStart(white2) == " \tABCDEFGHI\n\r");
		}
	}
}
