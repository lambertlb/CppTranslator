#pragma once
#ifdef WIN32
#pragma warning( disable : 4244 )
#pragma warning( disable : 4018 )
#pragma warning( disable : 4102 )
#pragma warning( disable : 4101 )
#ifdef	DOTNETLIBRARY_EXPORTS
#define	DLL_EXPORT	__declspec( dllexport )
#else
#define	DLL_EXPORT	__declspec( dllimport )
#endif
#else
#define	DLL_EXPORT	
#endif
#include <stdint.h>

// alias .Net types
typedef	bool		Boolean;
typedef	wchar_t		Char;
typedef	uint8_t		Byte;
typedef	int8_t		SByte;
typedef	int16_t		Int16;
typedef	uint16_t	UInt16;
typedef	int32_t		Int32;
typedef	uint32_t	UInt32;
typedef	int64_t		Int64;
typedef	uint64_t	UInt64;
typedef	float		Single;
typedef Single		Float;
typedef	double		Double;

// forward references
namespace DotnetLibrary
{
	struct DLL_EXPORT DateTime {
		UInt64	value;
		DateTime(UInt64 ticks) { value = ticks; }
		DateTime() { value = 0; }
		DateTime(const DateTime& val) { value = val.value; }
		DateTime(Int32 year, Int32 month, Int32 day, Int32 hour = -1, Int32 minute = -1, Int32 second = -1, Int32 millisecond = -1) { value = 0; }
	};
	struct DLL_EXPORT TimeSpan {
		UInt64	value;
		TimeSpan() { value = 0; }
		TimeSpan(const UInt64 value2) { value = value2; };
		TimeSpan(const TimeSpan& value2) { value = value2.value; };
		TimeSpan(Int32 hours, Int32 minutes, Int32 seconds) { value = 0; }
		TimeSpan(Int32 days, Int32 hours, Int32 minutes, Int32 seconds) { value = 0; }
		TimeSpan(Int32 days, Int32 hours, Int32 minutes, Int32 seconds, Int32 milliseconds) { value = 0; }
	};
	class String;

	typedef	enum DataType
	{
		NullType = 0,
		ObjectType = 1,
		BooleanType = 3,
		CharType = 4,
		SByteType = 5,
		ByteType = 6,
		Int16Type = 7,
		UInt16Type = 8,
		Int32Type = 9,
		UInt32Type = 10,
		Int64Type = 11,
		UInt64Type = 12,
		SingleType = 13,
		DoubleType = 14,
		DecimalType = 15,
		DateTimeType = 16,
		TimeSpanType = 17,
		StringType = 18
	} DataType;
#define FloatType SingleType
	DLL_EXPORT Int32	DataTypeSize[];
}

#include "Object.h"
#include "Array.h"
#include "StringDotNet.h"
#include "StringBuilder.h"
#include "DotNetMath.h"
#include "Buffer.h"
#include "ValueType.h"
#include "BooleanValue.h"
#include "ByteValue.h"
#include "CharValue.h"
#include "SByteValue.h"
#include "Int16Value.h"
#include "UInt16Value.h"
#include "Int32Value.h"
#include "UInt32Value.h"
#include "Int64Value.h"
#include "UInt64Value.h"
#include "SingleValue.h"
#include "DoubleValue.h"
#include "DateTimeValue.h"
#include "TimeSpanValue.h"
#include "Encoding.h"
#include "CharEnumerator.h"
#include "Exception.h"
