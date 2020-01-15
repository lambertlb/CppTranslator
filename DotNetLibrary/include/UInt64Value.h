#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	enum DLL_EXPORT ParsingStatus
	{
		OK,
		Failed,
		Overflow
	};

	class DLL_EXPORT UInt64Value : public ValueType {
	public:
		UInt64 value;
		UInt64Value(UInt64 v)
		{
			value = v;
		}
		virtual DataType GetRawDataType() { return(UInt64Type); };
		virtual bool	Equals(Object* valueToCompare) {
			return(false);
		}
		virtual bool	Equals(UInt64 valueToCompare) {
			return(false);
		}
		virtual bool	Equals(Int32 valueToCompare) {
			return(false);
		}
		virtual Int32	CompareTo(UInt64 valueToCompare) {
			return(0);
		}
		virtual Int32	CompareTo(Object* valueToCompare) {
			return(0);
		}
		static UInt64 Parse(String* stringToParse) {
			return(0);
		}
		static Boolean	TryParseInternal(String* source, UInt64& result, Int32& sign);
		static Boolean	TryParseInternal(Char* source, Int32 sourceLength, UInt64& result, Int32& sign);
		virtual	Int32	FormatString(Char* where, const Int32 whereSize);
		static UInt64	MaxValue;
		static UInt64	MinValue;
	};
}
