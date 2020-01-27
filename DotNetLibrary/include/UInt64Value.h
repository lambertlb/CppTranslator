#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	enum ParsingStatus
	{
		OK,
		Failed,
		Overflow
	};

	class DLL_EXPORT UInt64Value : public ValueType {
		UInt64 value;
	public:
		static UInt64	MaxValue;
		static UInt64	MinValue;
		UInt64Value(UInt64 v) { value = v; }

		virtual Boolean		get_AsBoolean();
		virtual Char		get_AsChar();
		virtual Byte		get_AsByte();
		virtual SByte		get_AsSByte();
		virtual Int16		get_AsInt16();
		virtual UInt16		get_AsUInt16();
		virtual Int32		get_AsInt32();
		virtual UInt32		get_AsUInt32();
		virtual Int64		get_AsInt64();
		virtual UInt64		get_AsUInt64();
		virtual Single		get_AsSingle();
		virtual Double		get_AsDouble();
		virtual Int32		CompareTo(UInt64 valueToCompare);
		virtual Int32		CompareTo(Object* valueToCompare);
		virtual bool		Equals(Object* valueToCompare);
		virtual bool		Equals(UInt64 valueToCompare);
		virtual	Int32		FormatString(Char* where, const Int32 whereSize);
		virtual DataType	GetRawDataType() { return(UInt64Type); };
		static UInt64		Parse(String* stringToParse);
		static bool			TryParse(String* stringToParse, UInt64* result);
		static Boolean		TryParseInternal(String* source, UInt64& result, Int32& sign);
		static Boolean		TryParseInternal(Char* source, Int32 sourceLength, UInt64& result, Int32& sign);
	};
}
