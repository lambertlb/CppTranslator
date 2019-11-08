#pragma once
#include "CaBlockHeader.h"
namespace TranslationTests_NS
{
	void BooleanTestsRaw::Run()
	{
		BooleanOperatorTests();
	}
	void BooleanTestsRaw::BooleanOperatorTests()
	{
		Boolean x_flag = false;
		Boolean x_flag2 = false;
		ProgramRaw::LocalAssert(!x_flag);
		x_flag = true;
		ProgramRaw::LocalAssert(x_flag);
		ProgramRaw::LocalAssert(true);
		ProgramRaw::LocalAssert(true);
		x_flag = ( x_flag2 = true );
		ProgramRaw::LocalAssert(x_flag && x_flag2);
		x_flag2 = false;
		ProgramRaw::LocalAssert(!( x_flag && x_flag2 ));
		x_flag = ( x_flag2 = true );
		ProgramRaw::LocalAssert(x_flag == x_flag2);
		x_flag2 = false;
		ProgramRaw::LocalAssert(x_flag ^ x_flag2);
		x_flag = ( x_flag2 = true );
		ProgramRaw::LocalAssert(x_flag | x_flag2);
		x_flag2 = false;
		ProgramRaw::LocalAssert(x_flag | x_flag2);
		x_flag = false;
		ProgramRaw::LocalAssert(!( x_flag | x_flag2 ));
		x_flag = ( x_flag2 = true );
		ProgramRaw::LocalAssert(x_flag && x_flag2);
		x_flag2 = false;
		ProgramRaw::LocalAssert(!( x_flag && x_flag2 ));
		x_flag = ( x_flag2 = true );
		ProgramRaw::LocalAssert(x_flag | x_flag2);
		x_flag2 = false;
		ProgramRaw::LocalAssert(x_flag | x_flag2);
		x_flag = false;
		ProgramRaw::LocalAssert(!( x_flag | x_flag2 ));
	}

	void ByteTestsRaw::Run()
	{
		ByteOperatorTests();
		ByteBitwiseOperators();
		ByteEqualityTests();
		ByteComparisonTests();
	}
	void ByteTestsRaw::ByteComparisonTests()
	{
		Byte x_b = 0;
		ProgramRaw::LocalAssert(x_b < 1);
		ProgramRaw::LocalAssert(1 > x_b);
		ProgramRaw::LocalAssert(x_b <= 0);
		ProgramRaw::LocalAssert(0 >= x_b);
	}
	void ByteTestsRaw::ByteEqualityTests()
	{
		Byte x_b = 0;
		ProgramRaw::LocalAssert(x_b == 0);
		ProgramRaw::LocalAssert(x_b != 1);
		ProgramRaw::LocalAssert(x_b.Equals(0));
		ProgramRaw::LocalAssert(!x_b.Equals(1));
		ProgramRaw::LocalAssert(x_b.Equals(( Object ) ( Byte ) 0));
		ProgramRaw::LocalAssert(!x_b.Equals(( Object ) ( Byte ) 1));
	}
	void ByteTestsRaw::ByteBitwiseOperators()
	{
		Byte x_b = 0;
		ProgramRaw::LocalAssert(~x_b == -1);
		x_b = 1;
		ProgramRaw::LocalAssert(x_b << 1 == 2);
		x_b = ( Byte ) ( x_b << 1 );
		ProgramRaw::LocalAssert(x_b == 2);
		x_b = 10;
		ProgramRaw::LocalAssert(x_b >> 1 == 5);
		x_b = ( Byte ) ( x_b >> 1 );
		ProgramRaw::LocalAssert(x_b == 5);
		x_b = 3;
		ProgramRaw::LocalAssert(( x_b & 1 ) == 1);
		ProgramRaw::LocalAssert(( x_b & 2 ) == 2);
		ProgramRaw::LocalAssert(( x_b & 3 ) == 3);
		ProgramRaw::LocalAssert(( x_b & 4 ) == 0);
		x_b = ( Byte ) ( x_b & 4 );
		ProgramRaw::LocalAssert(x_b == 0);
		x_b = 2;
		ProgramRaw::LocalAssert(( x_b ^ 2 ) == 0);
		ProgramRaw::LocalAssert(( x_b ^ 4 ) == 6);
		ProgramRaw::LocalAssert(( x_b | 2 ) == 2);
		ProgramRaw::LocalAssert(( x_b | 4 ) == 6);
		x_b = ( Byte ) ( x_b | 4 );
		ProgramRaw::LocalAssert(x_b == 6);
	}
	void ByteTestsRaw::ByteOperatorTests()
	{
		Byte x_b = 1;
		ProgramRaw::LocalAssert(x_b == 1);
		ProgramRaw::LocalAssert(x_b++ == 1);
		ProgramRaw::LocalAssert(x_b == 2);
		ProgramRaw::LocalAssert(x_b-- == 2);
		ProgramRaw::LocalAssert(x_b == 1);
		ProgramRaw::LocalAssert(( x_b = ( Byte ) ( x_b + 1 ) ) == 2);
		ProgramRaw::LocalAssert(x_b == 2);
		ProgramRaw::LocalAssert(( x_b = ( Byte ) ( x_b - 1 ) ) == 1);
		ProgramRaw::LocalAssert(x_b == 1);
		x_b = 1;
		ProgramRaw::LocalAssert(x_b == 1);
		x_b = 0;
		ProgramRaw::LocalAssert(x_b == 0);
		x_b = 0;
		ProgramRaw::LocalAssert(( Byte ) ( x_b - 1 ) == Byte::MaxValue);
		x_b = 1;
		ProgramRaw::LocalAssert(x_b == 1);
		x_b = 10;
		ProgramRaw::LocalAssert(x_b * 2 == 20);
		ProgramRaw::LocalAssert(x_b * -2 == -20);
		ProgramRaw::LocalAssert(( Int32 ) x_b / 5 == 2);
		ProgramRaw::LocalAssert(( Int32 ) x_b / -5 == -2);
		ProgramRaw::LocalAssert(( Int32 ) x_b / 3 == 3);
		ProgramRaw::LocalAssert(( Int32 ) x_b / -3 == -3);
		ProgramRaw::LocalAssert(( Int32 ) x_b % 5 == 0);
		ProgramRaw::LocalAssert(( Int32 ) x_b % 3 == 1);
		ProgramRaw::LocalAssert(x_b + 5 == 15);
		ProgramRaw::LocalAssert(x_b - 5 == 5);
		ProgramRaw::LocalAssert(x_b + x_b * x_b == 110);
	}

	void DoubleTestsRaw::Run()
	{
		DoubleOperatorTests();
		DoubleEqualityTests();
		DoubleComparisonTests();
	}
	void DoubleTestsRaw::DoubleComparisonTests()
	{
		Double x_num = 0;
		ProgramRaw::LocalAssert(x_num < 1);
		ProgramRaw::LocalAssert(1 > x_num);
		ProgramRaw::LocalAssert(x_num <= 0);
		ProgramRaw::LocalAssert(0 >= x_num);
		ProgramRaw::LocalAssert(!( Double::NaN >= x_num ));
		ProgramRaw::LocalAssert(!( Double::NaN <= x_num ));
	}
	void DoubleTestsRaw::DoubleEqualityTests()
	{
		Double x_num = 0;
		ProgramRaw::LocalAssert(x_num == 0);
		ProgramRaw::LocalAssert(x_num != 1);
		ProgramRaw::LocalAssert(x_num.Equals(0));
		ProgramRaw::LocalAssert(!x_num.Equals(1));
		ProgramRaw::LocalAssert(x_num.Equals(( Object ) 0));
		ProgramRaw::LocalAssert(!x_num.Equals(( Object ) 1));
	}
	void DoubleTestsRaw::DoubleOperatorTests()
	{
		Double x_num = 1;
		ProgramRaw::LocalAssert(x_num == 1);
		Double x_num2 = x_num;
		x_num = x_num2 + 1;
		ProgramRaw::LocalAssert(x_num2 == 1);
		ProgramRaw::LocalAssert(x_num == 2);
		Double x_num3 = x_num;
		x_num = x_num3 - 1;
		ProgramRaw::LocalAssert(x_num3 == 2);
		ProgramRaw::LocalAssert(x_num == 1);
		ProgramRaw::LocalAssert(( x_num += 1 ) == 2);
		ProgramRaw::LocalAssert(x_num == 2);
		ProgramRaw::LocalAssert(( x_num -= 1 ) == 1);
		ProgramRaw::LocalAssert(x_num == 1);
		x_num = 1;
		ProgramRaw::LocalAssert(x_num == 1);
		x_num = -1;
		ProgramRaw::LocalAssert(x_num == -1);
		x_num = 1;
		ProgramRaw::LocalAssert(x_num == 1);
		x_num = 10;
		ProgramRaw::LocalAssert(x_num * 2 == 20);
		ProgramRaw::LocalAssert(x_num * -2 == -20);
		ProgramRaw::LocalAssert(x_num / 5 == 2);
		ProgramRaw::LocalAssert(x_num / -5 == -2);
		ProgramRaw::LocalAssert(MathRaw::Abs(x_num / 3 - 3.33) < 0.01);
		ProgramRaw::LocalAssert(MathRaw::Abs(x_num / -3 - -3.33) < 0.01);
		ProgramRaw::LocalAssert(x_num % 5 == 0);
		ProgramRaw::LocalAssert(x_num % 3 == 1);
		ProgramRaw::LocalAssert(x_num + 5 == 15);
		ProgramRaw::LocalAssert(x_num - 5 == 5);
		ProgramRaw::LocalAssert(x_num + x_num * x_num == 110);
		Double x_d = x_num / 0;
		ProgramRaw::LocalAssert(Double::IsInfinity(x_d));
		x_d = 0;
		x_d /= 0;
		ProgramRaw::LocalAssert(Double::IsNaN(x_d));
	}

	void DerivedRaw::Run()
	{
		SingleOperatorTests();
		SingleEqualityTests();
		SingleComparisonTests();
	}
	void DerivedRaw::SingleComparisonTests()
	{
		Float x_num = 0;
		ProgramRaw::LocalAssert(x_num < 1);
		ProgramRaw::LocalAssert(1 > x_num);
		ProgramRaw::LocalAssert(x_num <= 0);
		ProgramRaw::LocalAssert(0 >= x_num);
		ProgramRaw::LocalAssert(!( Float::NaN >= x_num ));
		ProgramRaw::LocalAssert(!( Float::NaN <= x_num ));
	}
	void DerivedRaw::SingleEqualityTests()
	{
		Float x_num = 0;
		ProgramRaw::LocalAssert(x_num == 0);
		ProgramRaw::LocalAssert(x_num != 1);
		ProgramRaw::LocalAssert(x_num.Equals(0));
		ProgramRaw::LocalAssert(!x_num.Equals(1));
		ProgramRaw::LocalAssert(x_num.Equals(( Object ) 0));
		ProgramRaw::LocalAssert(!x_num.Equals(( Object ) 1));
	}
	void DerivedRaw::SingleOperatorTests()
	{
		Float x_num = 1;
		ProgramRaw::LocalAssert(x_num == 1);
		Float x_num2 = x_num;
		x_num = x_num2 + 1;
		ProgramRaw::LocalAssert(x_num2 == 1);
		ProgramRaw::LocalAssert(x_num == 2);
		Float x_num3 = x_num;
		x_num = x_num3 - 1;
		ProgramRaw::LocalAssert(x_num3 == 2);
		ProgramRaw::LocalAssert(x_num == 1);
		ProgramRaw::LocalAssert(( x_num += 1 ) == 2);
		ProgramRaw::LocalAssert(x_num == 2);
		ProgramRaw::LocalAssert(( x_num -= 1 ) == 1);
		ProgramRaw::LocalAssert(x_num == 1);
		x_num = 1;
		ProgramRaw::LocalAssert(x_num == 1);
		x_num = -1;
		ProgramRaw::LocalAssert(x_num == -1);
		x_num = 1;
		ProgramRaw::LocalAssert(x_num == 1);
		x_num = 10;
		ProgramRaw::LocalAssert(x_num * 2 == 20);
		ProgramRaw::LocalAssert(x_num * -2 == -20);
		ProgramRaw::LocalAssert(x_num / 5 == 2);
		ProgramRaw::LocalAssert(x_num / -5 == -2);
		ProgramRaw::LocalAssert(MathRaw::Abs(( Double ) ( x_num / 3 ) - 3.33) < 0.01);
		ProgramRaw::LocalAssert(MathRaw::Abs(( Double ) ( x_num / -3 ) - -3.33) < 0.01);
		ProgramRaw::LocalAssert(x_num % 5 == 0);
		ProgramRaw::LocalAssert(x_num % 3 == 1);
		ProgramRaw::LocalAssert(x_num + 5 == 15);
		ProgramRaw::LocalAssert(x_num - 5 == 5);
		ProgramRaw::LocalAssert(x_num + x_num * x_num == 110);
		Float x_f = x_num / 0;
		ProgramRaw::LocalAssert(Float::IsInfinity(x_f));
		x_f = 0;
		x_f /= 0;
		ProgramRaw::LocalAssert(Float::IsNaN(x_f));
	}

	void Int16TestsRaw::Run()
	{
		Int16OperatorTests();
		Int16BitwiseOperators();
		Int16EqualityTests();
		Int16ComparisonTests();
	}
	void Int16TestsRaw::Int16ComparisonTests()
	{
		Int16 x_num = 0;
		ProgramRaw::LocalAssert(x_num < 1);
		ProgramRaw::LocalAssert(1 > x_num);
		ProgramRaw::LocalAssert(x_num <= 0);
		ProgramRaw::LocalAssert(0 >= x_num);
	}
	void Int16TestsRaw::Int16EqualityTests()
	{
		Int16 x_num = 0;
		ProgramRaw::LocalAssert(x_num == 0);
		ProgramRaw::LocalAssert(x_num != 1);
		ProgramRaw::LocalAssert(x_num.Equals(0));
		ProgramRaw::LocalAssert(!x_num.Equals(1));
		ProgramRaw::LocalAssert(x_num.Equals(( Object ) ( Int16 ) 0));
		ProgramRaw::LocalAssert(!x_num.Equals(( Object ) ( Int16 ) 1));
	}
	void Int16TestsRaw::Int16BitwiseOperators()
	{
		Int16 x_num = 0;
		ProgramRaw::LocalAssert(~x_num == -1);
		x_num = 1;
		ProgramRaw::LocalAssert(x_num << 1 == 2);
		x_num = ( Int16 ) ( x_num << 1 );
		ProgramRaw::LocalAssert(x_num == 2);
		x_num = 10;
		ProgramRaw::LocalAssert(x_num >> 1 == 5);
		x_num = ( Int16 ) ( x_num >> 1 );
		ProgramRaw::LocalAssert(x_num == 5);
		x_num = 3;
		ProgramRaw::LocalAssert(( x_num & 1 ) == 1);
		ProgramRaw::LocalAssert(( x_num & 2 ) == 2);
		ProgramRaw::LocalAssert(( x_num & 3 ) == 3);
		ProgramRaw::LocalAssert(( x_num & 4 ) == 0);
		x_num = ( Int16 ) ( x_num & 4 );
		ProgramRaw::LocalAssert(x_num == 0);
		x_num = 2;
		ProgramRaw::LocalAssert(( x_num ^ 2 ) == 0);
		ProgramRaw::LocalAssert(( x_num ^ 4 ) == 6);
		ProgramRaw::LocalAssert(( x_num | 2 ) == 2);
		ProgramRaw::LocalAssert(( x_num | 4 ) == 6);
		x_num = ( Int16 ) ( x_num | 4 );
		ProgramRaw::LocalAssert(x_num == 6);
	}
	void Int16TestsRaw::Int16OperatorTests()
	{
		Int16 x_num = 1;
		ProgramRaw::LocalAssert(x_num == 1);
		ProgramRaw::LocalAssert(x_num++ == 1);
		ProgramRaw::LocalAssert(x_num == 2);
		ProgramRaw::LocalAssert(x_num-- == 2);
		ProgramRaw::LocalAssert(x_num == 1);
		ProgramRaw::LocalAssert(( x_num = ( Int16 ) ( x_num + 1 ) ) == 2);
		ProgramRaw::LocalAssert(x_num == 2);
		ProgramRaw::LocalAssert(( x_num = ( Int16 ) ( x_num - 1 ) ) == 1);
		ProgramRaw::LocalAssert(x_num == 1);
		x_num = 1;
		ProgramRaw::LocalAssert(x_num == 1);
		x_num = -1;
		ProgramRaw::LocalAssert(x_num == -1);
		x_num = 1;
		ProgramRaw::LocalAssert(x_num == 1);
		x_num = 10;
		ProgramRaw::LocalAssert(x_num * 2 == 20);
		ProgramRaw::LocalAssert(x_num * -2 == -20);
		ProgramRaw::LocalAssert(x_num / 5 == 2);
		ProgramRaw::LocalAssert(x_num / -5 == -2);
		ProgramRaw::LocalAssert(x_num / 3 == 3);
		ProgramRaw::LocalAssert(x_num / -3 == -3);
		ProgramRaw::LocalAssert(x_num % 5 == 0);
		ProgramRaw::LocalAssert(x_num % 3 == 1);
		ProgramRaw::LocalAssert(x_num + 5 == 15);
		ProgramRaw::LocalAssert(x_num - 5 == 5);
		ProgramRaw::LocalAssert(x_num + x_num * x_num == 110);
	}

	void Int32TestsRaw::Run()
	{
		Int32OperatorTests();
		Int32BitwiseOperators();
		Int32EqualityTests();
		Int32ComparisonTests();
		Int32NullableComparisonTests();
	}
	void Int32TestsRaw::Int32ComparisonTests()
	{
		Int32 x_num = 0;
		ProgramRaw::LocalAssert(x_num < 1);
		ProgramRaw::LocalAssert(1 > x_num);
		ProgramRaw::LocalAssert(x_num <= 0);
		ProgramRaw::LocalAssert(0 >= x_num);
	}
	void Int32TestsRaw::Int32NullableComparisonTests()
	{
		Int32 x_num = 0;
		ProgramRaw::LocalAssert(x_num < 1);
		ProgramRaw::LocalAssert(1 > x_num);
		ProgramRaw::LocalAssert(x_num <= 0);
		ProgramRaw::LocalAssert(0 >= x_num);
	}
	void Int32TestsRaw::Int32EqualityTests()
	{
		Int32 x_num = 0;
		ProgramRaw::LocalAssert(x_num == 0);
		ProgramRaw::LocalAssert(x_num != 1);
		ProgramRaw::LocalAssert(x_num.Equals(0));
		ProgramRaw::LocalAssert(!x_num.Equals(1));
		ProgramRaw::LocalAssert(x_num.Equals(( Object ) 0));
		ProgramRaw::LocalAssert(!x_num.Equals(( Object ) 1));
	}
	void Int32TestsRaw::Int32BitwiseOperators()
	{
		Int32 x_num = 0;
		ProgramRaw::LocalAssert(~x_num == -1);
		x_num = 1;
		ProgramRaw::LocalAssert(x_num << 1 == 2);
		x_num <<= 1;
		ProgramRaw::LocalAssert(x_num == 2);
		x_num = 10;
		ProgramRaw::LocalAssert(x_num >> 1 == 5);
		x_num >>= 1;
		ProgramRaw::LocalAssert(x_num == 5);
		x_num = 3;
		ProgramRaw::LocalAssert(( x_num & 1 ) == 1);
		ProgramRaw::LocalAssert(( x_num & 2 ) == 2);
		ProgramRaw::LocalAssert(( x_num & 3 ) == 3);
		ProgramRaw::LocalAssert(( x_num & 4 ) == 0);
		x_num &= 4;
		ProgramRaw::LocalAssert(x_num == 0);
		x_num = 2;
		ProgramRaw::LocalAssert(( x_num ^ 2 ) == 0);
		ProgramRaw::LocalAssert(( x_num ^ 4 ) == 6);
		ProgramRaw::LocalAssert(( x_num | 2 ) == 2);
		ProgramRaw::LocalAssert(( x_num | 4 ) == 6);
		x_num |= 4;
		ProgramRaw::LocalAssert(x_num == 6);
	}
	void Int32TestsRaw::Int32OperatorTests()
	{
		Int32 x_num = 1;
		ProgramRaw::LocalAssert(x_num == 1);
		ProgramRaw::LocalAssert(x_num++ == 1);
		ProgramRaw::LocalAssert(x_num == 2);
		ProgramRaw::LocalAssert(x_num-- == 2);
		ProgramRaw::LocalAssert(x_num == 1);
		ProgramRaw::LocalAssert(++x_num == 2);
		ProgramRaw::LocalAssert(x_num == 2);
		ProgramRaw::LocalAssert(--x_num == 1);
		ProgramRaw::LocalAssert(x_num == 1);
		x_num = 1;
		ProgramRaw::LocalAssert(x_num == 1);
		x_num = -1;
		ProgramRaw::LocalAssert(x_num == -1);
		x_num = 1;
		ProgramRaw::LocalAssert(x_num == 1);
		x_num = 10;
		ProgramRaw::LocalAssert(x_num * 2 == 20);
		ProgramRaw::LocalAssert(x_num * -2 == -20);
		ProgramRaw::LocalAssert(x_num / 5 == 2);
		ProgramRaw::LocalAssert(x_num / -5 == -2);
		ProgramRaw::LocalAssert(x_num / 3 == 3);
		ProgramRaw::LocalAssert(x_num / -3 == -3);
		ProgramRaw::LocalAssert(x_num % 5 == 0);
		ProgramRaw::LocalAssert(x_num % 3 == 1);
		ProgramRaw::LocalAssert(x_num + 5 == 15);
		ProgramRaw::LocalAssert(x_num - 5 == 5);
		ProgramRaw::LocalAssert(x_num + x_num * x_num == 110);
	}

	void Int64TestsRaw::Run()
	{
		Int64OperatorTests();
		Int64BitwiseOperators();
		Int64EqualityTests();
		Int64ComparisonTests();
	}
	void Int64TestsRaw::Int64ComparisonTests()
	{
		Int64 x_num = 0;
		ProgramRaw::LocalAssert(x_num < 1);
		ProgramRaw::LocalAssert(1 > x_num);
		ProgramRaw::LocalAssert(x_num <= 0);
		ProgramRaw::LocalAssert(0 >= x_num);
	}
	void Int64TestsRaw::Int64EqualityTests()
	{
		Int64 x_num = 0;
		ProgramRaw::LocalAssert(x_num == 0);
		ProgramRaw::LocalAssert(x_num != 1);
		ProgramRaw::LocalAssert(x_num.Equals(0));
		ProgramRaw::LocalAssert(!x_num.Equals(1));
		ProgramRaw::LocalAssert(x_num.Equals(( Object ) 0));
		ProgramRaw::LocalAssert(!x_num.Equals(( Object ) 1));
	}
	void Int64TestsRaw::Int64BitwiseOperators()
	{
		Int64 x_num = 0;
		ProgramRaw::LocalAssert(~x_num == -1);
		x_num = 1;
		ProgramRaw::LocalAssert(x_num << 1 == 2);
		x_num <<= 1;
		ProgramRaw::LocalAssert(x_num == 2);
		x_num = 10;
		ProgramRaw::LocalAssert(x_num >> 1 == 5);
		x_num >>= 1;
		ProgramRaw::LocalAssert(x_num == 5);
		x_num = 3;
		ProgramRaw::LocalAssert(( x_num & 1 ) == 1);
		ProgramRaw::LocalAssert(( x_num & 2 ) == 2);
		ProgramRaw::LocalAssert(( x_num & 3 ) == 3);
		ProgramRaw::LocalAssert(( x_num & 4 ) == 0);
		x_num &= 4;
		ProgramRaw::LocalAssert(x_num == 0);
		x_num = 2;
		ProgramRaw::LocalAssert(( x_num ^ 2 ) == 0);
		ProgramRaw::LocalAssert(( x_num ^ 4 ) == 6);
		ProgramRaw::LocalAssert(( x_num | 2 ) == 2);
		ProgramRaw::LocalAssert(( x_num | 4 ) == 6);
		x_num |= 4;
		ProgramRaw::LocalAssert(x_num == 6);
	}
	void Int64TestsRaw::Int64OperatorTests()
	{
		Int64 x_num = 1;
		ProgramRaw::LocalAssert(x_num == 1);
		ProgramRaw::LocalAssert(x_num++ == 1);
		ProgramRaw::LocalAssert(x_num == 2);
		ProgramRaw::LocalAssert(x_num-- == 2);
		ProgramRaw::LocalAssert(x_num == 1);
		ProgramRaw::LocalAssert(++x_num == 2);
		ProgramRaw::LocalAssert(x_num == 2);
		ProgramRaw::LocalAssert(--x_num == 1);
		ProgramRaw::LocalAssert(x_num == 1);
		x_num = 1;
		ProgramRaw::LocalAssert(x_num == 1);
		x_num = -1;
		ProgramRaw::LocalAssert(x_num == -1);
		x_num = 1;
		ProgramRaw::LocalAssert(x_num == 1);
		x_num = 10;
		ProgramRaw::LocalAssert(x_num * 2 == 20);
		ProgramRaw::LocalAssert(x_num * -2 == -20);
		ProgramRaw::LocalAssert(x_num / 5 == 2);
		ProgramRaw::LocalAssert(x_num / -5 == -2);
		ProgramRaw::LocalAssert(x_num / 3 == 3);
		ProgramRaw::LocalAssert(x_num / -3 == -3);
		ProgramRaw::LocalAssert(x_num % 5 == 0);
		ProgramRaw::LocalAssert(x_num % 3 == 1);
		ProgramRaw::LocalAssert(x_num + 5 == 15);
		ProgramRaw::LocalAssert(x_num - 5 == 5);
		ProgramRaw::LocalAssert(x_num + x_num * x_num == 110);
	}

	void ProgramRaw::RunTests()
	{
		new Int32TestsRawRaw()->Run();
		new Int64TestsRawRaw()->Run();
		new Int16TestsRawRaw()->Run();
		new SByteTestsRawRaw()->Run();
		new UInt32TestsRawRaw()->Run();
		new UInt64TestsRawRaw()->Run();
		new UInt16TestsRawRaw()->Run();
		new ByteTestsRawRaw()->Run();
		new DoubleTestsRawRaw()->Run();
		new SingleTestsRawRaw()->Run();
		new BooleanTestsRawRaw()->Run();
		new StringTestsRawRaw()->Run();
	}
	void ProgramRaw::Main(PointerType<RawArray<String>> x_args)
	{
		x_failedTests = 0;
		x_totalTests = 0;
		RunTests();
		if ( x_failedTests == 0 )
{
			ConsoleRaw::WriteLine("All {0} Test Passed",x_totalTests);
		}

else
{
			ConsoleRaw::WriteLine("{0} Tests of {1} Failed",x_failedTests,x_totalTests);
		}


		ConsoleRaw::Out->Write("
Hit enter to continue;");
		ConsoleRaw::In->ReadLine();
		EnvironmentRaw::Exit(( x_failedTests != 0 ) ? 1 : 0);
	}
	void ProgramRaw::LocalAssert(Boolean x_testPasses)
	{
		x_totalTests++;
		if ( !x_testPasses )
{
			x_failedTests++;
			StackTraceRaw x_stackTrace = new StackTraceRawRaw(true);
			PointerType<RawArray<StackFrame>> x_frames = x_stackTrace->GetFrames();
			StackFrameRaw x_stackFrame = x_frames [ 1 ];
			String x_fileName = x_stackFrame->GetFileName();
			Int32 x_num = x_fileName.LastIndexOf('\');
			if ( x_num != 0 )
{
				x_num++;
			}


			String x_arg = x_fileName->Substring(x_num);
			ConsoleRaw::Out->WriteLine("Test Failed in Method {0}, in File {1}, at Line {2}",x_stackFrame->GetMethod()->Name,x_arg,x_stackFrame.GetFileLineNumber());
		}


	}

	void SByteTestsRaw::Run()
	{
		SByteOperatorTests();
		SByteBitwiseOperators();
		SByteEqualityTests();
		SByteComparisonTests();
	}
	void SByteTestsRaw::SByteComparisonTests()
	{
		SByte x_b = 0;
		ProgramRaw::LocalAssert(x_b < 1);
		ProgramRaw::LocalAssert(1 > x_b);
		ProgramRaw::LocalAssert(x_b <= 0);
		ProgramRaw::LocalAssert(0 >= x_b);
	}
	void SByteTestsRaw::SByteEqualityTests()
	{
		SByte x_b = 0;
		ProgramRaw::LocalAssert(x_b == 0);
		ProgramRaw::LocalAssert(x_b != 1);
		ProgramRaw::LocalAssert(x_b.Equals(0));
		ProgramRaw::LocalAssert(!x_b.Equals(1));
		ProgramRaw::LocalAssert(x_b.Equals(( Object ) ( SByte ) 0));
		ProgramRaw::LocalAssert(!x_b.Equals(( Object ) ( SByte ) 1));
	}
	void SByteTestsRaw::SByteBitwiseOperators()
	{
		SByte x_b = 0;
		ProgramRaw::LocalAssert(~x_b == -1);
		x_b = 1;
		ProgramRaw::LocalAssert(x_b << 1 == 2);
		x_b = ( SByte ) ( x_b << 1 );
		ProgramRaw::LocalAssert(x_b == 2);
		x_b = 10;
		ProgramRaw::LocalAssert(x_b >> 1 == 5);
		x_b = ( SByte ) ( x_b >> 1 );
		ProgramRaw::LocalAssert(x_b == 5);
		x_b = 3;
		ProgramRaw::LocalAssert(( x_b & 1 ) == 1);
		ProgramRaw::LocalAssert(( x_b & 2 ) == 2);
		ProgramRaw::LocalAssert(( x_b & 3 ) == 3);
		ProgramRaw::LocalAssert(( x_b & 4 ) == 0);
		x_b = ( SByte ) ( x_b & 4 );
		ProgramRaw::LocalAssert(x_b == 0);
		x_b = 2;
		ProgramRaw::LocalAssert(( x_b ^ 2 ) == 0);
		ProgramRaw::LocalAssert(( x_b ^ 4 ) == 6);
		ProgramRaw::LocalAssert(( x_b | 2 ) == 2);
		ProgramRaw::LocalAssert(( x_b | 4 ) == 6);
		x_b = ( SByte ) ( x_b | 4 );
		ProgramRaw::LocalAssert(x_b == 6);
	}
	void SByteTestsRaw::SByteOperatorTests()
	{
		SByte x_b = 1;
		ProgramRaw::LocalAssert(x_b == 1);
		ProgramRaw::LocalAssert(x_b++ == 1);
		ProgramRaw::LocalAssert(x_b == 2);
		ProgramRaw::LocalAssert(x_b-- == 2);
		ProgramRaw::LocalAssert(x_b == 1);
		ProgramRaw::LocalAssert(( x_b = ( SByte ) ( x_b + 1 ) ) == 2);
		ProgramRaw::LocalAssert(x_b == 2);
		ProgramRaw::LocalAssert(( x_b = ( SByte ) ( x_b - 1 ) ) == 1);
		ProgramRaw::LocalAssert(x_b == 1);
		x_b = 1;
		ProgramRaw::LocalAssert(x_b == 1);
		x_b = -1;
		ProgramRaw::LocalAssert(x_b == -1);
		x_b = 1;
		ProgramRaw::LocalAssert(x_b == 1);
		x_b = 10;
		ProgramRaw::LocalAssert(x_b * 2 == 20);
		ProgramRaw::LocalAssert(x_b * -2 == -20);
		ProgramRaw::LocalAssert(x_b / 5 == 2);
		ProgramRaw::LocalAssert(x_b / -5 == -2);
		ProgramRaw::LocalAssert(x_b / 3 == 3);
		ProgramRaw::LocalAssert(x_b / -3 == -3);
		ProgramRaw::LocalAssert(x_b % 5 == 0);
		ProgramRaw::LocalAssert(x_b % 3 == 1);
		ProgramRaw::LocalAssert(x_b + 5 == 15);
		ProgramRaw::LocalAssert(x_b - 5 == 5);
		ProgramRaw::LocalAssert(x_b + x_b * x_b == 110);
	}

	void StringTestsRaw::Run()
	{
	}

	void UInt16TestsRaw::Run()
	{
		UIn16OperatorTests();
		UInt16BitwiseOperators();
		UInt16EqualityTests();
		UInt16ComparisonTests();
	}
	void UInt16TestsRaw::UInt16ComparisonTests()
	{
		UInt16 x_num = 0;
		ProgramRaw::LocalAssert(x_num < 1);
		ProgramRaw::LocalAssert(1 > x_num);
		ProgramRaw::LocalAssert(x_num <= 0);
		ProgramRaw::LocalAssert(0 >= x_num);
	}
	void UInt16TestsRaw::UInt16EqualityTests()
	{
		UInt16 x_num = 0;
		ProgramRaw::LocalAssert(x_num == 0);
		ProgramRaw::LocalAssert(x_num != 1);
		ProgramRaw::LocalAssert(x_num.Equals(0));
		ProgramRaw::LocalAssert(!x_num.Equals(1));
		ProgramRaw::LocalAssert(x_num.Equals(( Object ) ( UInt16 ) 0));
		ProgramRaw::LocalAssert(!x_num.Equals(( Object ) ( UInt16 ) 1));
	}
	void UInt16TestsRaw::UInt16BitwiseOperators()
	{
		UInt16 x_num = 0;
		ProgramRaw::LocalAssert(~x_num == -1);
		x_num = 1;
		ProgramRaw::LocalAssert(x_num << 1 == 2);
		x_num = ( UInt16 ) ( x_num << 1 );
		ProgramRaw::LocalAssert(x_num == 2);
		x_num = 10;
		ProgramRaw::LocalAssert(x_num >> 1 == 5);
		x_num = ( UInt16 ) ( x_num >> 1 );
		ProgramRaw::LocalAssert(x_num == 5);
		x_num = 3;
		ProgramRaw::LocalAssert(( x_num & 1 ) == 1);
		ProgramRaw::LocalAssert(( x_num & 2 ) == 2);
		ProgramRaw::LocalAssert(( x_num & 3 ) == 3);
		ProgramRaw::LocalAssert(( x_num & 4 ) == 0);
		x_num = ( UInt16 ) ( x_num & 4 );
		ProgramRaw::LocalAssert(x_num == 0);
		x_num = 2;
		ProgramRaw::LocalAssert(( x_num ^ 2 ) == 0);
		ProgramRaw::LocalAssert(( x_num ^ 4 ) == 6);
		ProgramRaw::LocalAssert(( x_num | 2 ) == 2);
		ProgramRaw::LocalAssert(( x_num | 4 ) == 6);
		x_num = ( UInt16 ) ( x_num | 4 );
		ProgramRaw::LocalAssert(x_num == 6);
	}
	void UInt16TestsRaw::UIn16OperatorTests()
	{
		UInt16 x_num = 1;
		ProgramRaw::LocalAssert(x_num == 1);
		ProgramRaw::LocalAssert(x_num++ == 1);
		ProgramRaw::LocalAssert(x_num == 2);
		ProgramRaw::LocalAssert(x_num-- == 2);
		ProgramRaw::LocalAssert(x_num == 1);
		ProgramRaw::LocalAssert(( x_num = ( UInt16 ) ( x_num + 1 ) ) == 2);
		ProgramRaw::LocalAssert(x_num == 2);
		ProgramRaw::LocalAssert(( x_num = ( UInt16 ) ( x_num - 1 ) ) == 1);
		ProgramRaw::LocalAssert(x_num == 1);
		x_num = 1;
		ProgramRaw::LocalAssert(x_num == 1);
		x_num = 0;
		ProgramRaw::LocalAssert(x_num == 0);
		x_num = 0;
		ProgramRaw::LocalAssert(( UInt16 ) ( x_num - 1 ) == UInt16::MaxValue);
		x_num = 1;
		ProgramRaw::LocalAssert(x_num == 1);
		x_num = 10;
		ProgramRaw::LocalAssert(x_num * 2 == 20);
		ProgramRaw::LocalAssert(x_num * -2 == -20);
		ProgramRaw::LocalAssert(( Int32 ) x_num / 5 == 2);
		ProgramRaw::LocalAssert(( Int32 ) x_num / -5 == -2);
		ProgramRaw::LocalAssert(( Int32 ) x_num / 3 == 3);
		ProgramRaw::LocalAssert(( Int32 ) x_num / -3 == -3);
		ProgramRaw::LocalAssert(( Int32 ) x_num % 5 == 0);
		ProgramRaw::LocalAssert(( Int32 ) x_num % 3 == 1);
		ProgramRaw::LocalAssert(x_num + 5 == 15);
		ProgramRaw::LocalAssert(x_num - 5 == 5);
		ProgramRaw::LocalAssert(x_num + x_num * x_num == 110);
	}

	void UInt32TestsRaw::Run()
	{
		UIn32OperatorTests();
		UInt32BitwiseOperators();
		UInt32EqualityTests();
		UInt32ComparisonTests();
	}
	void UInt32TestsRaw::UInt32ComparisonTests()
	{
		UInt32 x_num = 0;
		ProgramRaw::LocalAssert(x_num < 1);
		ProgramRaw::LocalAssert(1 > x_num);
		ProgramRaw::LocalAssert(x_num == 0);
		ProgramRaw::LocalAssert(0 >= x_num);
	}
	void UInt32TestsRaw::UInt32EqualityTests()
	{
		UInt32 x_num = 0;
		ProgramRaw::LocalAssert(x_num == 0);
		ProgramRaw::LocalAssert(x_num != 1);
		ProgramRaw::LocalAssert(x_num.Equals(0));
		ProgramRaw::LocalAssert(!x_num.Equals(1));
		ProgramRaw::LocalAssert(x_num.Equals(( Object ) 0));
		ProgramRaw::LocalAssert(!x_num.Equals(( Object ) 1));
	}
	void UInt32TestsRaw::UInt32BitwiseOperators()
	{
		UInt32 x_num = 0;
		ProgramRaw::LocalAssert(~x_num == UInt32::MaxValue);
		x_num = 1;
		ProgramRaw::LocalAssert(x_num << 1 == 2);
		x_num <<= 1;
		ProgramRaw::LocalAssert(x_num == 2);
		x_num = 10;
		ProgramRaw::LocalAssert(x_num >> 1 == 5);
		x_num >>= 1;
		ProgramRaw::LocalAssert(x_num == 5);
		x_num = 3;
		ProgramRaw::LocalAssert(( x_num & 1 ) == 1);
		ProgramRaw::LocalAssert(( x_num & 2 ) == 2);
		ProgramRaw::LocalAssert(( x_num & 3 ) == 3);
		ProgramRaw::LocalAssert(( x_num & 4 ) == 0);
		x_num &= 4;
		ProgramRaw::LocalAssert(x_num == 0);
		x_num = 2;
		ProgramRaw::LocalAssert(( x_num ^ 2 ) == 0);
		ProgramRaw::LocalAssert(( x_num ^ 4 ) == 6);
		ProgramRaw::LocalAssert(( x_num | 2 ) == 2);
		ProgramRaw::LocalAssert(( x_num | 4 ) == 6);
		x_num |= 4;
		ProgramRaw::LocalAssert(x_num == 6);
	}
	void UInt32TestsRaw::UIn32OperatorTests()
	{
		UInt32 x_num = 1;
		ProgramRaw::LocalAssert(x_num == 1);
		ProgramRaw::LocalAssert(x_num++ == 1);
		ProgramRaw::LocalAssert(x_num == 2);
		ProgramRaw::LocalAssert(x_num-- == 2);
		ProgramRaw::LocalAssert(x_num == 1);
		ProgramRaw::LocalAssert(++x_num == 2);
		ProgramRaw::LocalAssert(x_num == 2);
		ProgramRaw::LocalAssert(--x_num == 1);
		ProgramRaw::LocalAssert(x_num == 1);
		x_num = 1;
		ProgramRaw::LocalAssert(x_num == 1);
		x_num = 0;
		ProgramRaw::LocalAssert(x_num == 0);
		x_num = 0;
		ProgramRaw::LocalAssert(x_num - 1 == UInt32::MaxValue);
		x_num = 1;
		ProgramRaw::LocalAssert(x_num == 1);
		x_num = 10;
		ProgramRaw::LocalAssert(x_num * 2 == 20);
		ProgramRaw::LocalAssert(x_num * -2 == -20);
		ProgramRaw::LocalAssert(x_num / 5 == 2);
		ProgramRaw::LocalAssert(( Int64 ) x_num / -5 == -2);
		ProgramRaw::LocalAssert(x_num / 3 == 3);
		ProgramRaw::LocalAssert(( Int64 ) x_num / -3 == -3);
		ProgramRaw::LocalAssert(x_num % 5 == 0);
		ProgramRaw::LocalAssert(x_num % 3 == 1);
		ProgramRaw::LocalAssert(x_num + 5 == 15);
		ProgramRaw::LocalAssert(x_num - 5 == 5);
		ProgramRaw::LocalAssert(x_num + x_num * x_num == 110);
	}

	void UInt64TestsRaw::Run()
	{
		UInt64OperatorTests();
		UInt64BitwiseOperators();
		UInt64EqualityTests();
		UInt64ComparisonTests();
	}
	void UInt64TestsRaw::UInt64ComparisonTests()
	{
		UInt64 x_num = 0;
		ProgramRaw::LocalAssert(x_num < 1);
		ProgramRaw::LocalAssert(1 > x_num);
		ProgramRaw::LocalAssert(x_num == 0);
		ProgramRaw::LocalAssert(0 >= x_num);
	}
	void UInt64TestsRaw::UInt64EqualityTests()
	{
		UInt64 x_num = 0;
		ProgramRaw::LocalAssert(x_num == 0);
		ProgramRaw::LocalAssert(x_num != 1);
		ProgramRaw::LocalAssert(x_num.Equals(0));
		ProgramRaw::LocalAssert(!x_num.Equals(1));
		ProgramRaw::LocalAssert(x_num.Equals(( Object ) 0));
		ProgramRaw::LocalAssert(!x_num.Equals(( Object ) 1));
	}
	void UInt64TestsRaw::UInt64BitwiseOperators()
	{
		UInt64 x_num = 0;
		ProgramRaw::LocalAssert(~x_num == UInt64::MaxValue);
		x_num = 1;
		ProgramRaw::LocalAssert(x_num << 1 == 2);
		x_num <<= 1;
		ProgramRaw::LocalAssert(x_num == 2);
		x_num = 10;
		ProgramRaw::LocalAssert(x_num >> 1 == 5);
		x_num >>= 1;
		ProgramRaw::LocalAssert(x_num == 5);
		x_num = 3;
		ProgramRaw::LocalAssert(( x_num & 1 ) == 1);
		ProgramRaw::LocalAssert(( x_num & 2 ) == 2);
		ProgramRaw::LocalAssert(( x_num & 3 ) == 3);
		ProgramRaw::LocalAssert(( x_num & 4 ) == 0);
		x_num &= 4;
		ProgramRaw::LocalAssert(x_num == 0);
		x_num = 2;
		ProgramRaw::LocalAssert(( x_num ^ 2 ) == 0);
		ProgramRaw::LocalAssert(( x_num ^ 4 ) == 6);
		ProgramRaw::LocalAssert(( x_num | 2 ) == 2);
		ProgramRaw::LocalAssert(( x_num | 4 ) == 6);
		x_num |= 4;
		ProgramRaw::LocalAssert(x_num == 6);
	}
	void UInt64TestsRaw::UInt64OperatorTests()
	{
		UInt64 x_num = 1;
		ProgramRaw::LocalAssert(x_num == 1);
		ProgramRaw::LocalAssert(x_num++ == 1);
		ProgramRaw::LocalAssert(x_num == 2);
		ProgramRaw::LocalAssert(x_num-- == 2);
		ProgramRaw::LocalAssert(x_num == 1);
		ProgramRaw::LocalAssert(++x_num == 2);
		ProgramRaw::LocalAssert(x_num == 2);
		ProgramRaw::LocalAssert(--x_num == 1);
		ProgramRaw::LocalAssert(x_num == 1);
		x_num = 1;
		ProgramRaw::LocalAssert(x_num == 1);
		x_num = 0;
		ProgramRaw::LocalAssert(x_num == 0);
		x_num = 0;
		ProgramRaw::LocalAssert(x_num - 1 == UInt64::MaxValue);
		x_num = 1;
		ProgramRaw::LocalAssert(x_num == 1);
		x_num = 10;
		ProgramRaw::LocalAssert(x_num * 2 == 20);
		ProgramRaw::LocalAssert(x_num / 5 == 2);
		ProgramRaw::LocalAssert(x_num / 3 == 3);
		ProgramRaw::LocalAssert(x_num % 5 == 0);
		ProgramRaw::LocalAssert(x_num % 3 == 1);
		ProgramRaw::LocalAssert(x_num + 5 == 15);
		ProgramRaw::LocalAssert(x_num - 5 == 5);
		ProgramRaw::LocalAssert(x_num + x_num * x_num == 110);
	}

}
