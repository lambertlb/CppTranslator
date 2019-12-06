#pragma once
#include "pch.h"
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
	DLL_EXPORT DateTime	DateTime::MaxValue = DateTime(-1);
}