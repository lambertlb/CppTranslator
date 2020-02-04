using System;

namespace CppTranslatorFeatureTest
{
	public class BufferTest
	{
		FeatureTest featureTest;
		public BufferTest(FeatureTest featureTest)
		{
			this.featureTest = featureTest;
		}
		public void Run()
		{
			featureTest.FailureMessage = "\tFailed Buffer Test";
			featureTest.Send("Buffer Test");
			Int32[] array = new Int32[] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
			Int32[] array2 = new Int32[10];
			Buffer.BlockCopy(array, 0, array2, 0, array.Length * 4);
			for (Int32 i = 0; i < array.Length; ++i)
			{
				featureTest.AssertTrue(array[i] == array2[i]);
			}
			featureTest.AssertTrue(Buffer.ByteLength(array) == 10 * 4);
			featureTest.AssertTrue(Buffer.GetByte(array,4) == 2);
			featureTest.AssertTrue(Buffer.GetByte(array, 5) == 0);
			featureTest.AssertTrue(Buffer.GetByte(array, 6) == 0);
			featureTest.AssertTrue(Buffer.GetByte(array, 7) == 0);
			featureTest.AssertTrue(Buffer.GetByte(array, 8) == 3);
			Buffer.SetByte(array2, 4, 0);
			Buffer.SetByte(array2, 5, 1);
			Buffer.SetByte(array2, 6, 0);
			Buffer.SetByte(array2, 7, 0);
			featureTest.AssertTrue(array2[1] == 1 << 8);
		}
	}
}
