#pragma once
#ifdef WIN32
#pragma warning( disable : 4244 )
#pragma warning( disable : 4018 )
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
typedef	int16_t		Char;
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
	DLL_EXPORT Int32	DataTypeSize[];
}

#include "Object.h"
#include "Array.h"
#include "StringDotNet.h"
#include "StringBuilder.h"
#include "Math.h"
#include "Buffer.h"
#include "ValueType.h"
#include "BooleanValue.h"
#include "ByteValue.h"
#include "SByteValue.h"
#include "Int16Value.h"
#include "UInt16Value.h"
#include "Int32Value.h"
#include "UInt32Value.h"
#include "Int64Value.h"
#include "UInt64Value.h"
#include "SingleValue.h"
#include "DoubleValue.h"
#include "DateTime.h"
#include "TimeSpan.h"
#include "Encoding.h"
//#include "BoxTypeRaw.h"
//#include "Operators.h"
//#include "PointerType.h"
