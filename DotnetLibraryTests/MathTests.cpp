#include "gtest/gtest.h"
#include <DotnetTypes.h>

using namespace DotnetLibrary;

Boolean	FloatingCompare(Double n1, Double n2, Double tolerance)
{
	Double diff = n1 - n2;
	return(Math::Abs(diff) < tolerance);
}
void	AssertFloatEquals(Double n1, Double n2)
{
	ASSERT_TRUE(FloatingCompare(n1, n2, .0001));
}
TEST(MathTests, CompareToTest) {
	AssertFloatEquals(Math::Abs((Double)3.3), 3.3);
	AssertFloatEquals(Math::Abs((Double)-3.3), 3.3);
	AssertFloatEquals(Math::Abs((Single)3.3), 3.3);
	AssertFloatEquals(Math::Abs((Single)-3.3), 3.3);
	ASSERT_TRUE(Math::Abs((Int16)3) == 3);
	ASSERT_TRUE(Math::Abs((Int16)-3) == 3);
	ASSERT_TRUE(Math::Abs((Int32)3) == 3);
	ASSERT_TRUE(Math::Abs((Int32)-3) == 3);
	ASSERT_TRUE(Math::Abs((Int64)3) == 3);
	ASSERT_TRUE(Math::Abs((Int64)-3) == 3);
	ASSERT_TRUE(Math::Abs((SByte)3) == 3);
	ASSERT_TRUE(Math::Abs((SByte)-3) == 3);
}
TEST(MathTests, AcosTest) {
	AssertFloatEquals(Math::Acos(0.5), 1.0471975511966);
}
TEST(MathTests, AcoshTest) {
	AssertFloatEquals(Math::Acosh(4), 2.0634370);
}
TEST(MathTests, AsinTest) {
	AssertFloatEquals(Math::Asin(.25), 0.25268);
}
TEST(MathTests, AsinhTest) {
	AssertFloatEquals(Math::Asinh(-6.82), -2.61834);
}
TEST(MathTests, AtanTest) {
	AssertFloatEquals(Math::Atan(57.74), 1.55348);
}
TEST(MathTests, Atan2Test) {
	AssertFloatEquals(Math::Atan2(-10, 10), -0.785398);
}
TEST(MathTests, AtanhTest) {
	AssertFloatEquals(Math::Atanh(0.32), 0.331647);
}
TEST(MathTests, BigMulTest) {
	ASSERT_TRUE(Math::BigMul(10000, 10000) == 10000 * 10000);
}
TEST(MathTests, BitDecrementTest) {
	AssertFloatEquals(Math::BitDecrement(0.63661977236758134), 0.63661977236758127);
	ASSERT_TRUE(DoubleValue::IsNaN(Math::BitDecrement(DoubleValue::NaN)));
	AssertFloatEquals(Math::BitDecrement(0), DoubleValue::Epsilon);
	ASSERT_TRUE(DoubleValue::IsNegativeInfinity(Math::BitDecrement(DoubleValue::NegativeInfinity)));
}
TEST(MathTests, BitIncrement) {
	AssertFloatEquals(Math::BitIncrement(0.63661977236758134), 0.63661977236758149);
	ASSERT_TRUE(DoubleValue::IsNaN(Math::BitIncrement(DoubleValue::NaN)));
	AssertFloatEquals(Math::BitIncrement(0), DoubleValue::Epsilon);
	AssertFloatEquals(Math::BitIncrement(DoubleValue::NegativeInfinity), DoubleValue::MinValue);
}
TEST(MathTests, CbrtTest) {
	AssertFloatEquals(Math::Cbrt(0.70710678118654752), 0.89089871814033930);
	ASSERT_TRUE(DoubleValue::IsNaN(Math::Cbrt(DoubleValue::NaN)));
}
TEST(MathTests, CeilingTest) {
	AssertFloatEquals(Math::Ceiling(0.31830988618379067), 1.0);
	AssertFloatEquals(Math::Ceiling(2.3025850929940457), 3.0);
	AssertFloatEquals(Math::Ceiling(-3.1415926535897932), -3.0);
	ASSERT_TRUE(DoubleValue::IsNaN(Math::Ceiling(DoubleValue::NaN)));
}
TEST(MathTests, ClampTest) {
	ASSERT_TRUE(Math::Clamp((Byte)3, (Byte)2, (Byte)4) == 3);
	ASSERT_TRUE(Math::Clamp((Byte)1, (Byte)2, (Byte)4) == 2);
	ASSERT_TRUE(Math::Clamp((Byte)5, (Byte)2, (Byte)4) == 4);

	ASSERT_TRUE(Math::Clamp((Double)3, (Double)2, (Double)4) == 3);
	ASSERT_TRUE(Math::Clamp((Double)1, (Double)2, (Double)4) == 2);
	ASSERT_TRUE(Math::Clamp((Double)5, (Double)2, (Double)4) == 4);

	ASSERT_TRUE(Math::Clamp((Int16)3, (Int16)2, (Int16)4) == 3);
	ASSERT_TRUE(Math::Clamp((Int16)1, (Int16)2, (Int16)4) == 2);
	ASSERT_TRUE(Math::Clamp((Int16)5, (Int16)2, (Int16)4) == 4);

	ASSERT_TRUE(Math::Clamp((Int32)3, (Int32)2, (Int32)4) == 3);
	ASSERT_TRUE(Math::Clamp((Int32)1, (Int32)2, (Int32)4) == 2);
	ASSERT_TRUE(Math::Clamp((Int32)5, (Int32)2, (Int32)4) == 4);

	ASSERT_TRUE(Math::Clamp((Int64)3, (Int64)2, (Int64)4) == 3);
	ASSERT_TRUE(Math::Clamp((Int64)1, (Int64)2, (Int64)4) == 2);
	ASSERT_TRUE(Math::Clamp((Int64)5, (Int64)2, (Int64)4) == 4);

	ASSERT_TRUE(Math::Clamp((SByte)3, (SByte)2, (SByte)4) == 3);
	ASSERT_TRUE(Math::Clamp((SByte)1, (SByte)2, (SByte)4) == 2);
	ASSERT_TRUE(Math::Clamp((SByte)5, (SByte)2, (SByte)4) == 4);

	ASSERT_TRUE(Math::Clamp((Single)3, (Single)2, (Single)4) == 3);
	ASSERT_TRUE(Math::Clamp((Single)1, (Single)2, (Single)4) == 2);
	ASSERT_TRUE(Math::Clamp((Single)5, (Single)2, (Single)4) == 4);

	ASSERT_TRUE(Math::Clamp((UInt16)3, (UInt16)2, (UInt16)4) == 3);
	ASSERT_TRUE(Math::Clamp((UInt16)1, (UInt16)2, (UInt16)4) == 2);
	ASSERT_TRUE(Math::Clamp((UInt16)5, (UInt16)2, (UInt16)4) == 4);

	ASSERT_TRUE(Math::Clamp((UInt32)3, (UInt32)2, (UInt32)4) == 3);
	ASSERT_TRUE(Math::Clamp((UInt32)1, (UInt32)2, (UInt32)4) == 2);
	ASSERT_TRUE(Math::Clamp((UInt32)5, (UInt32)2, (UInt32)4) == 4);

	ASSERT_TRUE(Math::Clamp((UInt64)3, (UInt64)2, (UInt64)4) == 3);
	ASSERT_TRUE(Math::Clamp((UInt64)1, (UInt64)2, (UInt64)4) == 2);
	ASSERT_TRUE(Math::Clamp((UInt64)5, (UInt64)2, (UInt64)4) == 4);
}
TEST(MathTests, CopySignTest) {
	ASSERT_TRUE(Math::CopySign(-3.1415926535897932, -3.1415926535897932) == -3.1415926535897932);
	AssertFloatEquals(Math::CopySign(-3.1415926535897932, 0.0), 3.1415926535897932);
	AssertFloatEquals(Math::CopySign(3.1415926535897932, -0.0), -3.1415926535897932);
	AssertFloatEquals(Math::CopySign(3.1415926535897932, DoubleValue::NaN), -3.1415926535897932);
}
TEST(MathTests, CosTest) {
	AssertFloatEquals(Math::Cos(-3.1415926535897932), -1);
}
TEST(MathTests, CoshTest) {
	AssertFloatEquals(Math::Cosh(-3.1415926535897932), 11.591953275521521);
}
TEST(MathTests, DivRemTest) {
	Int32 whole;
	Int32 remainder;
	whole = Math::DivRem(2147483647, 1073741, remainder);
	ASSERT_TRUE(whole == 2000 && remainder == 1647);
	Int64 whole2;
	Int64 remainder2;
	whole2 = Math::DivRem(9223372036854775807L, 4611686018427387L, remainder2);
	ASSERT_TRUE(whole2 == 2000 && remainder2 == 1807L);
}
TEST(MathTests, ExpTest) {
	AssertFloatEquals(Math::Exp(-3.1415926535897932), 0.043213918263772250);
}
TEST(MathTests, FloorTest) {
	AssertFloatEquals(Math::Floor(-3.1415926535897932), -4.0);
}
TEST(MathTests, FusedMultiplyAddTest) {
	AssertFloatEquals(Math::FusedMultiplyAdd(5, 4, 3), 23);
}
TEST(MathTests, IEEERemainderTest) {
	AssertFloatEquals(Math::IEEERemainder(3, 2), -1);
}
TEST(MathTests, ILogBTest) {
	ASSERT_TRUE(Math::ILogB(0.11331473229676087) == -4);
	ASSERT_TRUE(Math::ILogB(0.5) == -1);
}
TEST(MathTests, LogTest) {
	AssertFloatEquals(Math::Log(0.043213918263772250), -3.1415926535897932);
	AssertFloatEquals(Math::Log(14, 3.0), 2.40217350273);
}
TEST(MathTests, Log10Test) {
	AssertFloatEquals(Math::Log10(6.1009598002416937), 0.78539816339744831);
}
TEST(MathTests, Log2Test) {
	AssertFloatEquals(Math::Log2(0.58019181037172444), -0.78539816339744831);
}
TEST(MathTests, MaxTest) {
	ASSERT_TRUE(Math::Max((Byte)5, (Byte)3) == 5);
	ASSERT_TRUE(Math::Max((Double)5, (Double)3) == 5);
	ASSERT_TRUE(Math::Max((Int16)5, (Int16)3) == 5);
	ASSERT_TRUE(Math::Max((Int32)5, (Int32)3) == 5);
	ASSERT_TRUE(Math::Max((Int64)5, (Int64)3) == 5);
	ASSERT_TRUE(Math::Max((SByte)5, (SByte)3) == 5);
	ASSERT_TRUE(Math::Max((Single)5, (Single)3) == 5);
	ASSERT_TRUE(Math::Max((UInt16)5, (UInt16)3) == 5);
	ASSERT_TRUE(Math::Max((UInt32)5, (UInt32)3) == 5);
	ASSERT_TRUE(Math::Max((UInt64)5, (UInt64)3) == 5);
}
TEST(MathTests, MinTest) {
	ASSERT_TRUE(Math::Min((Byte)5, (Byte)3) == 3);
	ASSERT_TRUE(Math::Min((Double)5, (Double)3) == 3);
	ASSERT_TRUE(Math::Min((Int16)5, (Int16)3) == 3);
	ASSERT_TRUE(Math::Min((Int32)5, (Int32)3) == 3);
	ASSERT_TRUE(Math::Min((Int64)5, (Int64)3) == 3);
	ASSERT_TRUE(Math::Min((SByte)5, (SByte)3) == 3);
	ASSERT_TRUE(Math::Min((Single)5, (Single)3) == 3);
	ASSERT_TRUE(Math::Min((UInt16)5, (UInt16)3) == 3);
	ASSERT_TRUE(Math::Min((UInt32)5, (UInt32)3) == 3);
	ASSERT_TRUE(Math::Min((UInt64)5, (UInt64)3) == 3);
}
TEST(MathTests, MaxMagnitudeTest) {
	AssertFloatEquals(Math::MaxMagnitude(2.0, -3.0), -3.0);
}
TEST(MathTests, MinMagnitudeTest) {
	AssertFloatEquals(Math::MinMagnitude(2.0, -3.0), 2.0);
}
TEST(MathTests, PowTest) {
	AssertFloatEquals(Math::Pow(7.0, 3.0), 343.0);
}
TEST(MathTests, RoundTest) {
	AssertFloatEquals(Math::Round(1.4), 1.0);
	AssertFloatEquals(Math::Round(1.5), 2.0);
	AssertFloatEquals(Math::Round(3.42156, 3, AwayFromZero), 3.422);
}
TEST(MathTests, ScaleBTest) {
	AssertFloatEquals(Math::ScaleB(4.9334096679145963, 2), 19.733638671658387);
}
TEST(MathTests, SignTest) {
	ASSERT_TRUE(Math::Sign(1.4) == 1);
	ASSERT_TRUE(Math::Sign(-1.4) == -1);
	ASSERT_TRUE(Math::Sign((Int16)2) == 1);
	ASSERT_TRUE(Math::Sign((Int16)-2) == -1);
	ASSERT_TRUE(Math::Sign((Int32)2) == 1);
	ASSERT_TRUE(Math::Sign((Int32)-2) == -1);
	ASSERT_TRUE(Math::Sign((Int64)2) == 1);
	ASSERT_TRUE(Math::Sign((Int64)-2) == -1);
	ASSERT_TRUE(Math::Sign((Single)1.4) == 1);
	ASSERT_TRUE(Math::Sign((Single)-1.4) == -1);
}
TEST(MathTests, SinTest) {
	AssertFloatEquals(Math::Sin(1.4426950408889634), 0.99180624439366372);
}
TEST(MathTests, SinhTest) {
	AssertFloatEquals(Math::Sinh(-1.5707963267948966), -2.3012989023072949);
}
TEST(MathTests, SqrtTest) {
	AssertFloatEquals(Math::Sqrt(0.31830988618379067), 0.56418958354775629);
}
TEST(MathTests, TanTest) {
	AssertFloatEquals(Math::Tan(-2.3025850929940457), 1.1134071468135374);
}
TEST(MathTests, TruncateTest) {
	AssertFloatEquals(Math::Truncate(3.14159), 3.0);
}
