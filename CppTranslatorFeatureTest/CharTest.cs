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

namespace CppTranslatorFeatureTest
{
	public class CharTest
	{
		FeatureTest featureTest;
		public CharTest(FeatureTest featureTest)
		{
			this.featureTest = featureTest;
		}
		public void Run()
		{
			MethodTests();
			OperatorTests();
		}
		private void MethodTests()
		{
			featureTest.FailureMessage = "\tFailed Char Method Test";
			featureTest.Send("Char Method Test");
			String str1 = "123aBc\t\n. ";
			Char value1 = 'A';
			Char value2 = 'B';
			Char value3 = 'C';
			Object obj1 = value1;
			Object obj2 = value2;
			Object obj3 = value3;

			featureTest.AssertTrue(value2.CompareTo(value1) > 0);
			featureTest.AssertTrue(value2.CompareTo(value3) < 0);
			featureTest.AssertTrue(value2.CompareTo(value2) == 0);
			featureTest.AssertTrue(value2.CompareTo(obj1) > 0);
			featureTest.AssertTrue(value2.CompareTo(obj3) < 0);
			featureTest.AssertTrue(value2.CompareTo(obj2) == 0);
			featureTest.AssertTrue(!value2.Equals(value1));
			featureTest.AssertTrue(!value2.Equals(value3));
			featureTest.AssertTrue(value2.Equals(value2));
			Object ob = (Object)value1;
			featureTest.AssertTrue('A'.Equals((Char)ob));
			featureTest.AssertTrue('A'.Equals(ob));
			featureTest.AssertTrue(ob.ToString() == "A");
			featureTest.AssertTrue(!value2.Equals(obj1));
			featureTest.AssertTrue(!value2.Equals(obj3));
			featureTest.AssertTrue(value2.Equals(obj2));
			featureTest.AssertTrue('A'.CompareTo(value1) == 0);
			featureTest.AssertTrue(Char.GetNumericValue('5') == 5);
			featureTest.AssertTrue(Char.GetNumericValue(str1, 2) == 3);
			featureTest.AssertTrue(Char.IsControl('\t'));
			featureTest.AssertTrue(!Char.IsControl('A'));
			featureTest.AssertTrue(Char.IsControl(str1, 7));
			featureTest.AssertTrue(!Char.IsControl(str1, 0));
			featureTest.AssertTrue(Char.IsDigit('1'));
			featureTest.AssertTrue(!Char.IsDigit('A'));
			featureTest.AssertTrue(Char.IsDigit(str1, 2));
			featureTest.AssertTrue(!Char.IsDigit(str1, 7));
			featureTest.AssertTrue(Char.IsLetter('a'));
			featureTest.AssertTrue(!Char.IsLetter('1'));
			featureTest.AssertTrue(Char.IsLetter(str1, 3));
			featureTest.AssertTrue(!Char.IsLetter(str1, 0));
			featureTest.AssertTrue(Char.IsLetterOrDigit('a'));
			featureTest.AssertTrue(Char.IsLetterOrDigit('1'));
			featureTest.AssertTrue(!Char.IsLetterOrDigit('\t'));
			featureTest.AssertTrue(Char.IsLetterOrDigit(str1, 3));
			featureTest.AssertTrue(Char.IsLetterOrDigit(str1, 0));
			featureTest.AssertTrue(!Char.IsLetterOrDigit(str1, 7));
			featureTest.AssertTrue(Char.IsLower('a'));
			featureTest.AssertTrue(!Char.IsLower('A'));
			featureTest.AssertTrue(Char.IsLower(str1, 3));
			featureTest.AssertTrue(!Char.IsLower(str1, 4));
			featureTest.AssertTrue(Char.IsNumber('1'));
			featureTest.AssertTrue(!Char.IsNumber('A'));
			featureTest.AssertTrue(Char.IsNumber(str1, 2));
			featureTest.AssertTrue(!Char.IsNumber(str1, 3));
			featureTest.AssertTrue(Char.IsPunctuation(','));
			featureTest.AssertTrue(!Char.IsPunctuation('A'));
			featureTest.AssertTrue(Char.IsPunctuation(str1, 8));
			featureTest.AssertTrue(!Char.IsPunctuation(str1, 0));
			featureTest.AssertTrue(Char.IsSeparator(' '));
			featureTest.AssertTrue(!Char.IsSeparator('A'));
			featureTest.AssertTrue(Char.IsSeparator(str1, 9));
			featureTest.AssertTrue(!Char.IsSeparator(str1, 0));
			featureTest.AssertTrue(Char.IsUpper('B'));
			featureTest.AssertTrue(!Char.IsUpper('b'));
			featureTest.AssertTrue(Char.IsUpper(str1, 4));
			featureTest.AssertTrue(!Char.IsUpper(str1, 3));
			featureTest.AssertTrue(Char.IsWhiteSpace(' '));
			featureTest.AssertTrue(!Char.IsWhiteSpace('A'));
			featureTest.AssertTrue(Char.IsWhiteSpace(str1, 9));
			featureTest.AssertTrue(!Char.IsWhiteSpace(str1, 0));
			featureTest.AssertTrue(Char.ToLower('A') == 'a');
			featureTest.AssertTrue(Char.ToLower('a') == 'a');
			featureTest.AssertTrue(Char.ToUpper('a') == 'A');
			featureTest.AssertTrue(Char.ToUpper('A') == 'A');
			featureTest.AssertTrue("a".Equals('a'.ToString()));
			featureTest.AssertTrue("a".Equals(Char.ToString('a')));
			featureTest.AssertTrue('a'.Equals(Char.Parse("a")));
			Char result;
			featureTest.AssertTrue(Char.TryParse("A", out result));
			featureTest.AssertTrue(result == 'A');
		}
		private void OperatorTests()
		{
			featureTest.FailureMessage = "\tFailed Char Operator Test";
			featureTest.Send("Char Operator Test");
			Char value = 'B';
			Char chr1 = ((Char)1);
			Int32 int32 = 1;
			UInt32 uint32 = 1;
			Int64 int64 = 1;
			Double dbl = 1;
			featureTest.AssertTrue((+value) == 'B');
			featureTest.AssertTrue((value + chr1) == 'C');
			featureTest.AssertTrue((value + int32) == 'C');
			featureTest.AssertTrue((value + uint32) == 'C');
			featureTest.AssertTrue((value + int64) == 'C');
			featureTest.AssertTrue((value + dbl) == 'C');
			featureTest.AssertTrue((value - chr1) == 'A');
			featureTest.AssertTrue((value - int32) == 'A');
			featureTest.AssertTrue((value - uint32) == 'A');
			featureTest.AssertTrue((value - int64) == 'A');
			featureTest.AssertTrue((value - dbl) == 'A');
			featureTest.AssertTrue((value * chr1) == 'B');
			featureTest.AssertTrue((value * int32) == 'B');
			featureTest.AssertTrue((value * uint32) == 'B');
			featureTest.AssertTrue((value * int64) == 'B');
			featureTest.AssertTrue((value * dbl) == 'B');
			featureTest.AssertTrue((value / chr1) == 'B');
			featureTest.AssertTrue((value / int32) == 'B');
			featureTest.AssertTrue((value / uint32) == 'B');
			featureTest.AssertTrue((value / int64) == 'B');
			featureTest.AssertTrue((value / dbl) == 'B');
			featureTest.AssertTrue((value % chr1) == 0);
			featureTest.AssertTrue((value % int32) == 0);
			featureTest.AssertTrue((value % uint32) == 0);
			featureTest.AssertTrue((value % int64) == 0);
			featureTest.AssertTrue((value % dbl) == 0);
			featureTest.AssertTrue((value & chr1) == 0);
			featureTest.AssertTrue((value & int32) == 0);
			featureTest.AssertTrue((value & uint32) == 0);
			featureTest.AssertTrue((value & int64) == 0);
			featureTest.AssertTrue((value | chr1) == 'C');
			featureTest.AssertTrue((value | int32) == 'C');
			featureTest.AssertTrue((value | uint32) == 'C');
			featureTest.AssertTrue((value | int64) == 'C');
			featureTest.AssertTrue((value ^ chr1) == 'C');
			featureTest.AssertTrue((value ^ int32) == 'C');
			featureTest.AssertTrue((value ^ uint32) == 'C');
			featureTest.AssertTrue((value ^ int64) == 'C');
			featureTest.AssertTrue((~value) == -67);
			featureTest.AssertTrue(chr1 < value);
			featureTest.AssertTrue(int32 < value);
			featureTest.AssertTrue(uint32 < value);
			featureTest.AssertTrue(int64 < value);
			featureTest.AssertTrue(dbl < value);
			featureTest.AssertTrue(chr1 > value, false);
			featureTest.AssertTrue(int32 > value, false);
			featureTest.AssertTrue(uint32 > value, false);
			featureTest.AssertTrue(int64 > value, false);
			featureTest.AssertTrue(dbl > value, false);
			featureTest.AssertTrue((++value) == 'C');
			featureTest.AssertTrue((--value) == 'B');
			featureTest.AssertTrue((value++) == 'B');
			featureTest.AssertTrue((value--) == 'C');
			featureTest.AssertTrue((value << 1) == 132);
			featureTest.AssertTrue((value >> 1) == 33);
			featureTest.AssertTrue(chr1 == value, false);
			featureTest.AssertTrue(int32 == value, false);
			featureTest.AssertTrue(uint32 == value, false);
			featureTest.AssertTrue(int64 == value, false);
			featureTest.AssertTrue(dbl == value, false);
			featureTest.AssertTrue(chr1 != value);
			featureTest.AssertTrue(int32 != value);
			featureTest.AssertTrue(uint32 != value);
			featureTest.AssertTrue(int64 != value);
			featureTest.AssertTrue(dbl != value);
			featureTest.AssertTrue(chr1 <= value);
			featureTest.AssertTrue(int32 <= value);
			featureTest.AssertTrue(uint32 <= value);
			featureTest.AssertTrue(int64 <= value);
			featureTest.AssertTrue(dbl <= value);
			featureTest.AssertTrue(chr1 >= value, false);
			featureTest.AssertTrue(int32 >= value, false);
			featureTest.AssertTrue(uint32 >= value, false);
			featureTest.AssertTrue(int64 >= value, false);
			featureTest.AssertTrue(dbl >= value, false);
			featureTest.AssertTrue((value += chr1) == 'C');
			featureTest.AssertTrue((value -= chr1) == 'B');
			featureTest.AssertTrue((value *= chr1) == 'B');
			featureTest.AssertTrue((value /= chr1) == 'B');
			featureTest.AssertTrue((value %= chr1) == 0);
			value = 'B';
			featureTest.AssertTrue((value &= chr1) == 0);
			value = 'B';
			featureTest.AssertTrue((value &= chr1) == 0);
			value = 'B';
			featureTest.AssertTrue((value |= chr1) == 'C');
			value = 'B';
			featureTest.AssertTrue((value ^= chr1) == 'C');
			value = 'B';
			featureTest.AssertTrue((value <<= 1) == 132);
			value = 'B';
			featureTest.AssertTrue((value >>= 1) == 33);
		}
	}
}
