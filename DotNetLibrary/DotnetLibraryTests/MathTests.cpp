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
