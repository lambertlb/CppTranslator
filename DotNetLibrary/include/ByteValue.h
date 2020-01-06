#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	class DLL_EXPORT ByteValue : public ValueType {
		Byte value;
	public:
		ByteValue(Byte v)
		{
			value = v;
		}
		virtual DataType GetRawDataType() { return(ByteType); };
		virtual bool	Equals(Object* valueToCompare) {
			return(false);
		}
		virtual bool	Equals(Byte valueToCompare) {
			return(false);
		}
		virtual bool	Equals(Int32 valueToCompare) {
			return(false);
		}
		virtual Int32	CompareTo(Byte valueToCompare) {
			return(0);
		}
		virtual Int32	CompareTo(Object* valueToCompare) {
			return(0);
		}
		virtual	Int32	FormatString(Char* where, const Int32 whereSize);
		static Char Parse(String* stringToParse) {
			return(0);
		}
		static Byte	MaxValue;
		static Byte	MinValue;
	};
}
