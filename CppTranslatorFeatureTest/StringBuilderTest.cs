// Copyright (c) 2019 LLambert
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this
// software and associated documentation files (the "Software"), to deal in the Software
// without restriction, including without limitation the rights to use, copy, modify, merge,
// publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons
// to whom the Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or
// substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
// INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
// PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
// FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
// OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
using System;
using System.Text;

namespace CppTranslatorFeatureTest
{
	public class StringBuilderTest
	{
		FeatureTest featureTest;
		public StringBuilderTest(FeatureTest featureTest)
		{
			this.featureTest = featureTest;
		}
		public void Run()
		{
			PropertyTests();
			MethodTests();
		}

		private void PropertyTests()
		{
			featureTest.FailureMessage = "\tFailed StringBuilder Property Test";
			featureTest.Send("StringBuilder Property Test");
			StringBuilder sb = new StringBuilder("123", 0, 3, 128);
			featureTest.AssertTrue(sb.Capacity == 128);
			sb.Capacity = 256;
			featureTest.AssertTrue(sb.Capacity == 256);
			featureTest.AssertTrue(sb[0] == '1');
			featureTest.AssertTrue(sb[1] == '2');
			featureTest.AssertTrue(sb[2] == '3');
			sb[1] = '5';
			featureTest.AssertTrue(sb[1] == '5');
			featureTest.AssertTrue(sb.Length == 3);
			sb.Length = 0;
			featureTest.AssertTrue(sb.Length == 0);
			featureTest.AssertTrue(sb.MaxCapacity == int.MaxValue);
		}

		private void MethodTests()
		{
			featureTest.FailureMessage = "\tFailed StringBuilder Method Test";
			featureTest.Send("StringBuilder Method Test");
			AppendTest();
			InsertTest();
			ReplaceTest();
			String str1 = "ABC";
			StringBuilder sb = new StringBuilder(str1);
			sb.Clear();
			featureTest.AssertTrue(sb.Length == 0);
			sb.Append(str1);
			featureTest.AssertTrue(sb.ToString() == "ABC");
			featureTest.AssertTrue(sb.ToString(1,2) == "BC");
			StringBuilder sb2 = new StringBuilder(str1);
			featureTest.AssertTrue(sb.Equals(sb2));
			featureTest.AssertTrue(sb.EnsureCapacity(128) == 128);
		}

		private void AppendTest()
		{
			StringBuilder sb = new StringBuilder();
			Char[] chars = new char[] { 'A', 'B', 'C' };
			sb.Append(chars);
			featureTest.AssertTrue(sb.Length == 3 && sb[0] == 'A' && sb[1] == 'B' && sb[2] == 'C');
			sb.Length = 0;
			sb.Append(chars,0,chars.Length);
			featureTest.AssertTrue(sb.Length == 3 && sb[0] == 'A' && sb[1] == 'B' && sb[2] == 'C');
			featureTest.AssertTrue(sb.ToString() == "ABC");
			sb.Length = 0;
			sb.Append(true);
			featureTest.AssertTrue(sb.ToString() == "True");
			sb.Length = 0;
			sb.Append((Byte)1);
			featureTest.AssertTrue(sb.Length == 1 && sb[0] == '1');
			sb.Length = 0;
			sb.Append(1.1);
			featureTest.AssertTrue(sb.ToString() == "1.1");
			sb.Length = 0;
			sb.Append((Int16)2);
			featureTest.AssertTrue(sb.ToString() == "2");
			sb.Length = 0;
			sb.Append((Int32)3);
			featureTest.AssertTrue(sb.ToString() == "3");
			sb.Length = 0;
			sb.Append((Int64)4);
			featureTest.AssertTrue(sb.ToString() == "4");
			sb.Length = 0;
			sb.Append((Object)5);
			featureTest.AssertTrue(sb.ToString() == "5");
			sb.Length = 0;
			sb.Append('Z');
			featureTest.AssertTrue(sb.ToString() == "Z");
			sb.Length = 0;
			sb.Append('Z', 4);
			featureTest.AssertTrue(sb.ToString() == "ZZZZ");
			sb.Length = 0;
			sb.Append("ABCDEFG", 1, 3);
			featureTest.AssertTrue(sb.ToString() == "BCD");
			sb.Length = 0;
			sb.Append((sbyte)-1);
			featureTest.AssertTrue(sb.ToString() == "-1");
			sb.Length = 0;
			sb.Append(2.2F);
			featureTest.AssertTrue(sb.ToString() == "2.2");
			sb.Length = 0;
			sb.Append((UInt16)2);
			featureTest.AssertTrue(sb.ToString() == "2");
			sb.Length = 0;
			sb.Append((UInt32)3);
			featureTest.AssertTrue(sb.ToString() == "3");
			sb.Length = 0;
			sb.Append((UInt64)4);
			featureTest.AssertTrue(sb.ToString() == "4");
			sb.Length = 0;
			sb.AppendLine();
			featureTest.AssertTrue(sb.ToString() == "\r\n");
			sb.Length = 0;
			sb.AppendLine("ABC");
			featureTest.AssertTrue(sb.ToString() == "ABC\r\n");
		}
		private void InsertTest()
		{
			StringBuilder sb = new StringBuilder();
			Char[] chars = new char[] { 'A', 'B', 'C' };
			String value = "TESTING1234";
			sb.Append(value);
			featureTest.AssertTrue(sb.Insert(7, true).ToString() == "TESTINGTrue1234");
			sb.Clear();
			sb.Append(value);
			featureTest.AssertTrue(sb.Insert(7, (Byte)1).ToString() == "TESTING11234");
			sb.Clear();
			sb.Append(value);
			featureTest.AssertTrue(sb.Insert(7, 'Z').ToString() == "TESTINGZ1234");
			sb.Clear();
			sb.Append(value);
			featureTest.AssertTrue(sb.Insert(7, chars).ToString() == "TESTINGABC1234");
			sb.Clear();
			sb.Append(value);
			featureTest.AssertTrue(sb.Insert(7, chars, 1, 2).ToString() == "TESTINGBC1234");
			sb.Clear();
			sb.Append(value);
			featureTest.AssertTrue(sb.Insert(7, 1.1).ToString() == "TESTING1.11234");
			sb.Clear();
			sb.Append(value);
			featureTest.AssertTrue(sb.Insert(7, (Int16)2).ToString() == "TESTING21234");
			sb.Clear();
			sb.Append(value);
			featureTest.AssertTrue(sb.Insert(7, (Int32)3).ToString() == "TESTING31234");
			sb.Clear();
			sb.Append(value);
			featureTest.AssertTrue(sb.Insert(7, (Int64)4).ToString() == "TESTING41234");
			sb.Clear();
			sb.Append(value);
			featureTest.AssertTrue(sb.Insert(7, (Object)5).ToString() == "TESTING51234");
			sb.Clear();
			sb.Append(value);
			featureTest.AssertTrue(sb.Insert(7, "33", 2).ToString() == "TESTING33331234");
			sb.Clear();
			sb.Append(value);
			featureTest.AssertTrue(sb.Insert(7, (sbyte)-1).ToString() == "TESTING-11234");
			sb.Clear();
			sb.Append(value);
			featureTest.AssertTrue(sb.Insert(7, 2.2F).ToString() == "TESTING2.21234");
			sb.Clear();
			sb.Append(value);
			featureTest.AssertTrue(sb.Insert(7, (UInt16)2).ToString() == "TESTING21234");
			sb.Clear();
			sb.Append(value);
			featureTest.AssertTrue(sb.Insert(7, (UInt32)3).ToString() == "TESTING31234");
			sb.Clear();
			sb.Append(value);
			featureTest.AssertTrue(sb.Insert(7, (UInt64)4).ToString() == "TESTING41234");
			sb.Clear();
			sb.Append(value);
		}
		private void ReplaceTest()
		{
			StringBuilder sb = new StringBuilder();
			Char[] chars = new char[] { 'A', 'B', 'C' };
			String value = "The dog brown dog jumps over the lazy dog";
			sb.Append(value);
			featureTest.AssertTrue(sb.Replace("dog", "cat").ToString() == "The cat brown cat jumps over the lazy cat");
			sb.Clear();
			sb.Append(value);
			featureTest.AssertTrue(sb.Replace("dog", "cat", 10, 10).ToString() == "The dog brown cat jumps over the lazy dog");
			sb.Clear();
			sb.Append(value);
			featureTest.AssertTrue(sb.Replace("dog", "").ToString() == "The  brown  jumps over the lazy ");
			String value2 = "BCCCCCCCBA";
			sb.Clear();
			sb.Append(value2);
			featureTest.AssertTrue(sb.Replace("CCC", "DDD", 2, 5).ToString() == "BCDDDCCCBA");
			String value3 = "The quick #brown dog jumps over the lazy #dog#";
			sb.Clear();
			sb.Append(value3);
			featureTest.AssertTrue(sb.Replace('#', '-').ToString() == "The quick -brown dog jumps over the lazy -dog-");
			String value4 = "The quick #brown dog jumps over the #lazy #dog#";
			sb.Clear();
			sb.Append(value4);
			featureTest.AssertTrue(sb.Replace('#', '-', 5, 15).ToString() == "The quick -brown dog jumps over the #lazy #dog#");
		}
	}
}
