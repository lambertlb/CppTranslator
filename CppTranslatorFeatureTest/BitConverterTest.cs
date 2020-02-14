using System;

namespace CppTranslatorFeatureTest
{
	public class BitConverterTest
	{
		FeatureTest featureTest;
		public BitConverterTest(FeatureTest featureTest)
		{
			this.featureTest = featureTest;
		}
		public void Run()
		{
			featureTest.FailureMessage = "\tFailed BitConverter Test";
			featureTest.Send("BitConverter Test");
			featureTest.AssertTrue(BitConverter.IsLittleEndian);
			BooleanTest();
			CharTest();
			DoubleTest();
			Int16Test();
			Int32Test();
			Int64Test();
			SingleTest();
			UInt16Test();
			UInt32Test();
			UInt64Test();
			StringTest();
			String2Test();
			String3Test();
		}
		private void BooleanTest()
		{
			Byte[] bytes = BitConverter.GetBytes(true);
			featureTest.AssertTrue(1 == bytes.Length);
			featureTest.AssertTrue(1 == bytes[0]);
			featureTest.AssertTrue(BitConverter.ToBoolean(bytes, 0));

			bytes = BitConverter.GetBytes(false);
			featureTest.AssertTrue(1 == bytes.Length);
			featureTest.AssertTrue(0 == bytes[0]);
			featureTest.AssertTrue(!BitConverter.ToBoolean(bytes, 0));
		}
		Boolean CompareBytes(Byte[] array1, Byte[] array2, Int32 amount)
		{
			for (int i = 0; i < amount; ++i)
			{
				if (array1[i] != array2[i])
					return (false);
			}
			return (true);
		}
		private void CharTest()
		{
			Char input = 'A';
			Byte[] expected = new Byte[] { 0x41, 0 };
			Byte[] bytes = BitConverter.GetBytes(input);
			featureTest.AssertTrue(CompareBytes(expected, bytes, 2));
			featureTest.AssertTrue(BitConverter.ToChar(bytes, 0) == input);
		}
		private void DoubleTest()
		{
			Double input = 123456.3234;
			Byte[] expected = new Byte[] { 0x78, 0x7a, 0xa5, 0x2c, 0x05, 0x24, 0xfe, 0x40 };
			Byte[] bytes = BitConverter.GetBytes(input);
			featureTest.AssertTrue(CompareBytes(expected, bytes, 8));
			featureTest.AssertTrue(BitConverter.ToDouble(bytes, 0) == input);
		}
		private void Int16Test()
		{
			Int16 input = 0x1234;
			Byte[] expected = new Byte[] { 0x34, 0x12 };
			Byte[] bytes = BitConverter.GetBytes(input);
			featureTest.AssertTrue(CompareBytes(expected, bytes, 2));
			featureTest.AssertTrue(BitConverter.ToInt16(bytes, 0) == input);
		}
		private void Int32Test()
		{
			Int32 input = 0x12345678;
			Byte[] expected = new Byte[] { 0x78, 0x56, 0x34, 0x12 };
			Byte[] bytes = BitConverter.GetBytes(input);
			featureTest.AssertTrue(CompareBytes(expected, bytes, 4));
			featureTest.AssertTrue(BitConverter.ToInt32(bytes, 0) == input);
		}
		private void Int64Test()
		{
			Int64 input = 0x0123456789abcdef;
			Byte[] expected = new Byte[] { 0xef, 0xcd, 0xab, 0x89, 0x67, 0x45, 0x23, 0x01 };
			Byte[] bytes = BitConverter.GetBytes(input);
			featureTest.AssertTrue(CompareBytes(expected, bytes, 8));
			featureTest.AssertTrue(BitConverter.ToInt64(bytes, 0) == input);
		}
		private void SingleTest()
		{
			Single input = 8392.34f;
			Byte[] expected = new Byte[] { 0x5c, 0x21, 0x03, 0x46 };
			Byte[] bytes = BitConverter.GetBytes(input);
			featureTest.AssertTrue(CompareBytes(expected, bytes, 4));
			featureTest.AssertTrue(BitConverter.ToSingle(bytes, 0) == input);
		}
		private void UInt16Test()
		{
			UInt16 input = 0x1234;
			Byte[] expected = new Byte[] { 0x34, 0x12 };
			Byte[] bytes = BitConverter.GetBytes(input);
			featureTest.AssertTrue(CompareBytes(expected, bytes, 2));
			featureTest.AssertTrue(BitConverter.ToUInt16(bytes, 0) == input);
		}
		private void UInt32Test()
		{
			UInt32 input = 0x12345678;
			Byte[] expected = new Byte[] { 0x78, 0x56, 0x34, 0x12 };
			Byte[] bytes = BitConverter.GetBytes(input);
			featureTest.AssertTrue(CompareBytes(expected, bytes, 4));
			featureTest.AssertTrue(BitConverter.ToUInt32(bytes, 0) == input);
		}
		private void UInt64Test()
		{
			UInt64 input = 0x0123456789abcdef;
			Byte[] expected = new Byte[] { 0xef, 0xcd, 0xab, 0x89, 0x67, 0x45, 0x23, 0x01 };
			Byte[] bytes = BitConverter.GetBytes(input);
			featureTest.AssertTrue(CompareBytes(expected, bytes, 8));
			featureTest.AssertTrue(BitConverter.ToUInt64(bytes, 0) == input);
		}
		private void StringTest()
		{
			UInt64 input = 0x0123456789abcdef;
			String expected = "EF-CD-AB-89-67-45-23-01";
			Byte[] bytes = BitConverter.GetBytes(input);
			String answer = BitConverter.ToString(bytes);
			featureTest.AssertTrue(expected == answer);
		}
		private void String2Test()
		{
			UInt64 input = 0x0123456789abcdef;
			String expected = "AB-89-67-45-23-01";
			Byte[] bytes = BitConverter.GetBytes(input);
			String answer = BitConverter.ToString(bytes, 2);
			featureTest.AssertTrue(expected == answer);
		}
		private void String3Test()
		{
			UInt64 input = 0x0123456789abcdef;
			String expected = "AB-89";
			Byte[] bytes = BitConverter.GetBytes(input);
			String answer = BitConverter.ToString(bytes, 2, 2);
			featureTest.AssertTrue(expected == answer);
		}
	}
}
