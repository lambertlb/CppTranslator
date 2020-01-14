#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	class DLL_EXPORT BooleanValue : public ValueType {
		Boolean value;
	public:
		BooleanValue(Boolean v) { value = v; }
		virtual Boolean		get_AsBoolean();
		virtual Byte		get_AsByte();
		virtual SByte		get_AsSByte();
		virtual Int16		get_AsInt16();
		virtual UInt16		get_AsUInt16();
		virtual Int32		get_AsInt32();
		virtual UInt32		get_AsUInt32();
		virtual Int64		get_AsInt64();
		virtual UInt64		get_AsUInt64();
		virtual DataType	GetRawDataType() { return(BooleanType); };
		virtual Int32		CompareTo(Boolean valueToCompare);
		virtual Int32		CompareTo(Object* valueToCompare);
		virtual bool		Equals(Object* valueToCompare);
		virtual bool		Equals(Boolean valueToCompare);
		virtual	Int32		FormatString(Char* where, const Int32 whereSize);
		static Boolean		Parse(String* stringToParse);
		static String*		TrueString;
		static String*		FalseString;
	};
}
