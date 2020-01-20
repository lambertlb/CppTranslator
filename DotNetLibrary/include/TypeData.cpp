#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	DLL_EXPORT Int32	DataTypeSize[] =
	{
		0,				//NullType
		sizeof(void*),	//ObjectType
		sizeof(Boolean),//BooleanType
		sizeof(Char),	//CharType
		sizeof(SByte),	//SByteType
		sizeof(Byte),	//ByteType
		sizeof(Int16),	//Int16Type
		sizeof(UInt16),	//UInt16Type
		sizeof(Int32),	//Int32Type
		sizeof(UInt32),	//UInt32Type
		sizeof(Int64),	//Int64Type
		sizeof(UInt64),	//UInt64Type
		sizeof(Single),	//SingleType
		sizeof(Double),	//DoubleType
		sizeof(void*),	//DecimalType
		sizeof(UInt64),	//DateTimeType
		sizeof(UInt64),	//TimeSpanType
		sizeof(void*)	//StringType
	};
	DLL_EXPORT TimeSpan	TimeSpanValue::MaxValue = TimeSpan(UInt64Value::MaxValue);
	DLL_EXPORT TimeSpan	TimeSpanValue::MinValue = TimeSpan(UInt64Value::MinValue);
	DLL_EXPORT TimeSpan	TimeSpanValue::Zero = TimeSpan(0);

	DLL_EXPORT Single	SingleValue::MaxValue = 255;
	DLL_EXPORT Single	SingleValue::MinValue = 0;
	DLL_EXPORT Single	SingleValue::Epsilon = 0;
	DLL_EXPORT Single	SingleValue::NaN = 0;
	DLL_EXPORT Single	SingleValue::PositiveInfinity = 0;
	DLL_EXPORT Single	SingleValue::NegativeInfinity = 0;

	DLL_EXPORT Single	FloatValue::MaxValue = 255;
	DLL_EXPORT Single	FloatValue::MinValue = 0;
	DLL_EXPORT Single	FloatValue::Epsilon = 0;
	DLL_EXPORT Single	FloatValue::NaN = 0;
	DLL_EXPORT Single	FloatValue::PositiveInfinity = 0;
	DLL_EXPORT Single	FloatValue::NegativeInfinity = 0;
	DLL_EXPORT UInt16	UInt16Value::MaxValue = 255;
	DLL_EXPORT UInt16	UInt16Value::MinValue = 0;
	DLL_EXPORT UInt64	UInt64Value::MaxValue = 255;
	DLL_EXPORT UInt64	UInt64Value::MinValue = 0;
	DLL_EXPORT UInt32	UInt32Value::MaxValue = 255;
	DLL_EXPORT UInt32	UInt32Value::MinValue = 0;
	DLL_EXPORT String* String::Empty = new String(L"");
}