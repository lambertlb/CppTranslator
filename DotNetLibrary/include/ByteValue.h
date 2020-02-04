#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	class DLL_EXPORT ByteValue : public ValueType {
		Byte value;
	public:
		ByteValue(Byte v) {value = v;}
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
		virtual Int32		CompareTo(Byte valueToCompare);
		virtual Int32		CompareTo(Object* valueToCompare);
		virtual Boolean		Equals(Object* valueToCompare);
		virtual Boolean		Equals(Byte valueToCompare);
		virtual	Int32		FormatString(Char* where, const Int32 whereSize);
		virtual DataType	GetRawDataType() { return(ByteType); };
		static Byte			Parse(String* stringToParse);
		static bool			TryParse(String* stringToParse, Byte& result);
		static Byte	MaxValue;
		static Byte	MinValue;
	};
}
