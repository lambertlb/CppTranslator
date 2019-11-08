#pragma once
#include "CaBlockProtos.h"
namespace TranslationTests_NS
{
	class BooleanTestsRaw
	{
		public:
		void Run();
		void BooleanOperatorTests();
	};

	class ByteTestsRaw
	{
		public:
		void Run();
		void ByteComparisonTests();
		void ByteEqualityTests();
		void ByteBitwiseOperators();
		void ByteOperatorTests();
	};

	class DoubleTestsRaw
	{
		public:
		void Run();
		void DoubleComparisonTests();
		void DoubleEqualityTests();
		void DoubleOperatorTests();
	};

	class SingleTestsRaw
	{
		public:
		struct TestStructRaw
		{
			Single X;
		};
		class BaseRaw
		{
			public:
		};
		class DerivedRaw
		{
			public:
		};
		void Run();
		void SingleComparisonTests();
		void SingleEqualityTests();
		void SingleOperatorTests();
	};

	class Int16TestsRaw
	{
		public:
		void Run();
		void Int16ComparisonTests();
		void Int16EqualityTests();
		void Int16BitwiseOperators();
		void Int16OperatorTests();
	};

	class Int32TestsRaw
	{
		public:
		void Run();
		void Int32ComparisonTests();
		void Int32NullableComparisonTests();
		void Int32EqualityTests();
		void Int32BitwiseOperators();
		void Int32OperatorTests();
	};

	class Int64TestsRaw
	{
		public:
		void Run();
		void Int64ComparisonTests();
		void Int64EqualityTests();
		void Int64BitwiseOperators();
		void Int64OperatorTests();
	};

	class ProgramRaw
	{
		public:
		Int32 x_failedTests;
		Int32 x_totalTests;
		static void RunTests();
		static void Main(PointerType<RawArray<String>> x_args);
		static void LocalAssert(Boolean x_testPasses);
	};

	class SByteTestsRaw
	{
		public:
		void Run();
		void SByteComparisonTests();
		void SByteEqualityTests();
		void SByteBitwiseOperators();
		void SByteOperatorTests();
	};

	class StringTestsRaw
	{
		public:
		void Run();
	};

	class UInt16TestsRaw
	{
		public:
		void Run();
		void UInt16ComparisonTests();
		void UInt16EqualityTests();
		void UInt16BitwiseOperators();
		void UIn16OperatorTests();
	};

	class UInt32TestsRaw
	{
		public:
		void Run();
		void UInt32ComparisonTests();
		void UInt32EqualityTests();
		void UInt32BitwiseOperators();
		void UIn32OperatorTests();
	};

	class UInt64TestsRaw
	{
		public:
		void Run();
		void UInt64ComparisonTests();
		void UInt64EqualityTests();
		void UInt64BitwiseOperators();
		void UInt64OperatorTests();
	};

}
