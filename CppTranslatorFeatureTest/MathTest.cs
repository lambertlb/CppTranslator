using System;

namespace CppTranslatorFeatureTest
{
	public class MathTest
	{
		FeatureTest featureTest;
		public MathTest(FeatureTest featureTest)
		{
			this.featureTest = featureTest;
		}
		public void Run()
		{
			featureTest.FailureMessage = "\tFailed Math Test";
			featureTest.Send("Math Test");

			featureTest.AssertTrue(Math.Abs(-3.0) == 3.0);
			featureTest.AssertTrue(Math.Abs(3.0) == 3.0);
			featureTest.AssertTrue(Math.Abs(((short)-3)) == 3);
			featureTest.AssertTrue(Math.Abs(((short)3)) == 3);
			featureTest.AssertTrue(Math.Abs(((int)-3)) == 3);
			featureTest.AssertTrue(Math.Abs(((int)3)) == 3);
			featureTest.AssertTrue(Math.Abs(((long)-3)) == 3);
			featureTest.AssertTrue(Math.Abs(((long)3)) == 3);
			featureTest.AssertTrue(Math.Abs(((sbyte)-3)) == 3);
			featureTest.AssertTrue(Math.Abs(((SByte)3)) == 3);
			featureTest.AssertTrue(Math.Abs(((float)-3.0F)) == 3.0);
			featureTest.AssertTrue(Math.Abs(((float)3.0F)) == 3.0);
			featureTest.AssertTrue(Math.Acos(0.5), 1.0471975511966);
			featureTest.AssertTrue(Math.Acosh(4.0), 2.0634370);
			featureTest.AssertTrue(Math.Asin(0.25), 0.25268);
			featureTest.AssertTrue(Math.Asinh(-6.82), -2.61834);
			featureTest.AssertTrue(Math.Atan(57.74), 1.55348);
			featureTest.AssertTrue(Math.Atanh(0.32), 0.331647);
			featureTest.AssertTrue(Math.BigMul(10000, 10000) == 10000 * 10000);
			featureTest.AssertTrue(Math.BitDecrement(0.63661977236758134), 0.63661977236758127);
			featureTest.AssertTrue(Double.IsNaN(Math.BitDecrement(Double.NaN)));
			featureTest.AssertTrue(Math.BitDecrement(0), Double.Epsilon);
			featureTest.AssertTrue(Double.IsNegativeInfinity(Math.BitDecrement(Double.NegativeInfinity)));
			featureTest.AssertTrue(Math.BitIncrement(0.63661977236758134), 0.63661977236758149);
			featureTest.AssertTrue(Double.IsNaN(Math.BitIncrement(Double.NaN)));
			featureTest.AssertTrue(Math.BitIncrement(0), Double.Epsilon);
			featureTest.AssertTrue(Math.BitIncrement(Double.NegativeInfinity), Double.MinValue);
			featureTest.AssertTrue(Math.Cbrt(0.70710678118654752), 0.89089871814033930);
			featureTest.AssertTrue(Double.IsNaN(Math.Cbrt(Double.NaN)));
			featureTest.AssertTrue(Math.Ceiling(0.31830988618379067), 1.0);
			featureTest.AssertTrue(Math.Ceiling(2.3025850929940457), 3.0);
			featureTest.AssertTrue(Math.Ceiling(-3.1415926535897932), -3.0);
			featureTest.AssertTrue(Double.IsNaN(Math.Ceiling(Double.NaN)));
			featureTest.AssertTrue(Math.Clamp((Byte)3, (Byte)2, (Byte)4) == 3);
			featureTest.AssertTrue(Math.Clamp((Byte)1, (Byte)2, (Byte)4) == 2);
			featureTest.AssertTrue(Math.Clamp((Byte)5, (Byte)2, (Byte)4) == 4);
			featureTest.AssertTrue(Math.Clamp((Double)3, (Double)2, (Double)4) == 3);
			featureTest.AssertTrue(Math.Clamp((Double)1, (Double)2, (Double)4) == 2);
			featureTest.AssertTrue(Math.Clamp((Double)5, (Double)2, (Double)4) == 4);
			featureTest.AssertTrue(Math.Clamp((Int16)3, (Int16)2, (Int16)4) == 3);
			featureTest.AssertTrue(Math.Clamp((Int16)1, (Int16)2, (Int16)4) == 2);
			featureTest.AssertTrue(Math.Clamp((Int16)5, (Int16)2, (Int16)4) == 4);
			featureTest.AssertTrue(Math.Clamp((Int32)3, (Int32)2, (Int32)4) == 3);
			featureTest.AssertTrue(Math.Clamp((Int32)1, (Int32)2, (Int32)4) == 2);
			featureTest.AssertTrue(Math.Clamp((Int32)5, (Int32)2, (Int32)4) == 4);
			featureTest.AssertTrue(Math.Clamp((Int64)3, (Int64)2, (Int64)4) == 3);
			featureTest.AssertTrue(Math.Clamp((Int64)1, (Int64)2, (Int64)4) == 2);
			featureTest.AssertTrue(Math.Clamp((Int64)5, (Int64)2, (Int64)4) == 4);
			featureTest.AssertTrue(Math.Clamp((SByte)3, (SByte)2, (SByte)4) == 3);
			featureTest.AssertTrue(Math.Clamp((SByte)1, (SByte)2, (SByte)4) == 2);
			featureTest.AssertTrue(Math.Clamp((SByte)5, (SByte)2, (SByte)4) == 4);
			featureTest.AssertTrue(Math.Clamp((UInt16)3, (UInt16)2, (UInt16)4) == 3);
			featureTest.AssertTrue(Math.Clamp((UInt16)1, (UInt16)2, (UInt16)4) == 2);
			featureTest.AssertTrue(Math.Clamp((UInt16)5, (UInt16)2, (UInt16)4) == 4);
			featureTest.AssertTrue(Math.Clamp((UInt32)3, (UInt32)2, (UInt32)4) == 3);
			featureTest.AssertTrue(Math.Clamp((UInt32)1, (UInt32)2, (UInt32)4) == 2);
			featureTest.AssertTrue(Math.Clamp((UInt32)5, (UInt32)2, (UInt32)4) == 4);
			featureTest.AssertTrue(Math.Clamp((UInt64)3, (UInt64)2, (UInt64)4) == 3);
			featureTest.AssertTrue(Math.Clamp((UInt64)1, (UInt64)2, (UInt64)4) == 2);
			featureTest.AssertTrue(Math.Clamp((UInt64)5, (UInt64)2, (UInt64)4) == 4);
			featureTest.AssertTrue(Math.CopySign(-3.1415926535897932, -3.1415926535897932), -3.1415926535897932);
			featureTest.AssertTrue(Math.CopySign(-3.1415926535897932, 0.0), 3.1415926535897932);
			featureTest.AssertTrue(Math.CopySign(-3.1415926535897932, -0.0), -3.1415926535897932);
			featureTest.AssertTrue(Math.CopySign(-3.1415926535897932, Double.NaN), -3.1415926535897932);
			featureTest.AssertTrue(Math.Cos(-3.1415926535897932), -1.0);
			featureTest.AssertTrue(Math.Cosh(-3.1415926535897932), 11.591953275521521);
			Int32 whole;
			Int32 remainder;
			whole = Math.DivRem(2147483647, 1073741, out remainder);
			featureTest.AssertTrue(whole == 2000 && remainder == 1647);
			Int64 whole2;
			Int64 remainder2;
			whole2 = Math.DivRem(9223372036854775807L, 4611686018427387L, out remainder2);
			featureTest.AssertTrue(whole2 == 2000 && remainder2 == 1807L);
			featureTest.AssertTrue(Math.Exp(-3.1415926535897932), 0.043213918263772250);
			featureTest.AssertTrue(Math.Floor(-3.1415926535897932), -4.0);
			featureTest.AssertTrue(Math.FusedMultiplyAdd(5, 4, 3), 23);
			featureTest.AssertTrue(Math.IEEERemainder(3, 2), -1);
			featureTest.AssertTrue(Math.ILogB(0.11331473229676087), -4.0);
			featureTest.AssertTrue(Math.ILogB(0.5), -1.0);
			featureTest.AssertTrue(Math.Log(0.043213918263772250), -3.1415926535897932);
			featureTest.AssertTrue(Math.Log(14, 3.0), 2.40217350273);
			featureTest.AssertTrue(Math.Log10(6.1009598002416937), 0.78539816339744831);
			featureTest.AssertTrue(Math.Log2(0.58019181037172444), -0.78539816339744831);
			featureTest.AssertTrue(Math.Max((Byte)5, (Byte)3) == 5);
			featureTest.AssertTrue(Math.Max((Double)5, (Double)3) == 5);
			featureTest.AssertTrue(Math.Max((Int16)5, (Int16)3) == 5);
			featureTest.AssertTrue(Math.Max((Int32)5, (Int32)3) == 5);
			featureTest.AssertTrue(Math.Max((Int64)5, (Int64)3) == 5);
			featureTest.AssertTrue(Math.Max((SByte)5, (SByte)3) == 5);
			featureTest.AssertTrue(Math.Max((Single)5, (Single)3) == 5);
			featureTest.AssertTrue(Math.Max((UInt16)5, (UInt16)3) == 5);
			featureTest.AssertTrue(Math.Max((UInt32)5, (UInt32)3) == 5);
			featureTest.AssertTrue(Math.Max((UInt64)5, (UInt64)3) == 5);

			featureTest.AssertTrue(Math.Min((Byte)5, (Byte)3) == 3);
			featureTest.AssertTrue(Math.Min((Double)5, (Double)3) == 3);
			featureTest.AssertTrue(Math.Min((Int16)5, (Int16)3) == 3);
			featureTest.AssertTrue(Math.Min((Int32)5, (Int32)3) == 3);
			featureTest.AssertTrue(Math.Min((Int64)5, (Int64)3) == 3);
			featureTest.AssertTrue(Math.Min((SByte)5, (SByte)3) == 3);
			featureTest.AssertTrue(Math.Min((Single)5, (Single)3) == 3);
			featureTest.AssertTrue(Math.Min((UInt16)5, (UInt16)3) == 3);
			featureTest.AssertTrue(Math.Min((UInt32)5, (UInt32)3) == 3);
			featureTest.AssertTrue(Math.Min((UInt64)5, (UInt64)3) == 3);
			featureTest.AssertTrue(Math.MaxMagnitude(2.0, -3.0) , -3);
			featureTest.AssertTrue(Math.MinMagnitude(2.0, -3.0), 2.0);
			featureTest.AssertTrue(Math.Pow(7.0, 3.0), 343.0);
			featureTest.AssertTrue(Math.Round(1.4), 1.0);
			featureTest.AssertTrue(Math.Round(1.5), 2.0);
			featureTest.AssertTrue(Math.Round(3.42156, 3, MidpointRounding.AwayFromZero), 3.422);
			featureTest.AssertTrue(Math.ScaleB(4.9334096679145963, 2), 19.733638671658387);
			featureTest.AssertTrue(Math.Sign(1.4) == 1);
			featureTest.AssertTrue(Math.Sign(-1.4) == -1);
			featureTest.AssertTrue(Math.Sign((short)2) == 1);
			featureTest.AssertTrue(Math.Sign((short)-2) == -1);
			featureTest.AssertTrue(Math.Sign((int)2) == 1);
			featureTest.AssertTrue(Math.Sign((int)-2) == -1);
			featureTest.AssertTrue(Math.Sign((long)2) == 1);
			featureTest.AssertTrue(Math.Sign((long)-2) == -1);
			featureTest.AssertTrue(Math.Sign((float)2) == 1);
			featureTest.AssertTrue(Math.Sign((float)-2) == -1);
			featureTest.AssertTrue(Math.Sin(1.4426950408889634), 0.99180624439366372);
			featureTest.AssertTrue(Math.Sinh(-1.5707963267948966), -2.3012989023072949);
			featureTest.AssertTrue(Math.Sqrt(0.31830988618379067), 0.56418958354775629);
			featureTest.AssertTrue(Math.Tan(-2.3025850929940457), 1.1134071468135374);
			featureTest.AssertTrue(Math.Truncate(3.14159), 3.0);
		}
	}
}
