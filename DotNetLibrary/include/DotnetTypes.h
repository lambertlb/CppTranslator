// Copyright (c) 2019 LLambert
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this
// software and associated documentation files (the "Software"), to deal in the Software
// without restriction, including without limitation the rights to use, copy, modify, merge,
// publish, distribute, sub-license, and/or sell copies of the Software, and to permit persons
// to whom the Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or
// substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
// INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
// PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
// FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
// OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
#pragma once
#ifdef WIN32
#pragma warning( disable : 4244 )
#pragma warning( disable : 4018 )
#pragma warning( disable : 4102 )
#pragma warning( disable : 4101 )
#pragma warning( disable : 26812 )
#pragma warning( disable : 26495 )
#ifdef	DOTNETLIBRARY_EXPORTS
#define	DLL_EXPORT	__declspec( dllexport )
#else
#define	DLL_EXPORT	__declspec( dllimport )
#endif
#else
#define	DLL_EXPORT	
#endif
#include <PlatformSupport.h>
#include <stdint.h>
#include <cstdio>

// alias .Net types
typedef bool Boolean;
typedef wchar_t Char;
typedef uint8_t Byte;
typedef int8_t SByte;
typedef int16_t Int16;
typedef uint16_t UInt16;
typedef int32_t Int32;
typedef uint32_t UInt32;
typedef int64_t Int64;
typedef uint64_t UInt64;
typedef float Single;
typedef Single Float;
typedef double Double;

// forward references
namespace DotnetLibrary
{
	/*!
	 * DateTime structure
	 */
	struct DLL_EXPORT DateTime
	{
		/*!
		 * Value in ticks
		 */
		UInt64 value;
		DateTime(UInt64 ticks);
		DateTime();
		DateTime(const DateTime& val);
		DateTime(Int32 year, Int32 month, Int32 day, Int32 hour = 0, Int32 minute = 0, Int32 second = 0, Int32 millisecond = 0);
	};
	/*!
	 * TimeSpan Structure
	 */
	struct DLL_EXPORT TimeSpan
	{
		/*!
		 * Value in ticks
		 */
		Int64 value;
		TimeSpan() { value = 0; }
		TimeSpan(const Int64 value2) { value = value2; }
		TimeSpan(const TimeSpan& value2) { value = value2.value; }
		TimeSpan(Int32 hours, Int32 minutes, Int32 seconds);
		TimeSpan(Int32 days, Int32 hours, Int32 minutes, Int32 seconds, Int32 milliseconds = 0);
	};
	// Forward reference
	class String;

	/*!
	 * Data types supported in this implementation
	 */
	typedef enum DataType
	{
		NullType, ObjectType, BooleanType, CharType, SByteType, ByteType, Int16Type, UInt16Type, Int32Type, UInt32Type, Int64Type, UInt64Type, SingleType, DoubleType, DecimalType, DateTimeType, TimeSpanType, StringType
	} DataType;
#define FloatType SingleType
	/*!
	 * Array of sizes for values in DataType
	 */
	DLL_EXPORT extern Int32 DataTypeSize[];
}

#include "Object.h"
#include "ValueType.h"
#include "Array.h"
#include "StringDotNet.h"
#include "StringBuilder.h"
#include "DotNetMath.h"
#include "Buffer.h"
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
#include "CharEnumerator.h"
#include "Exception.h"
#include "BitConverter.h"
