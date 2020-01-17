#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	class DLL_EXPORT Int16Value : public ValueType {
		Int16 value;
	public:
		static Int16	MaxValue;
		static Int16	MinValue;
		Int16Value(Int16 v) { value = v; }

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
		virtual Int32		CompareTo(Int16 valueToCompare);
		virtual Int32		CompareTo(Object* valueToCompare);
		virtual bool		Equals(Object* valueToCompare);
		virtual bool		Equals(Int16 valueToCompare);
		virtual	Int32		FormatString(Char* where, const Int32 whereSize);
		virtual DataType	GetRawDataType() { return(Int16Type); };
		static Int16		Parse(String* stringToParse);
		static bool			TryParse(String* stringToParse, Int16* result);
	};
}
