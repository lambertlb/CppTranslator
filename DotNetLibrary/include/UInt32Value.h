#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	class DLL_EXPORT UInt32Value : public ValueType {
		UInt32 value;
	public:
		UInt32Value(UInt32 v)
		{
			value = v;
		}
		virtual DataType GetRawDataType() { return(UInt32Type); };
		virtual Double		get_AsDouble();
		virtual bool	Equals(Object* valueToCompare) {
			return(false);
		}
		virtual bool	Equals(UInt32 valueToCompare) {
			return(false);
		}
		//virtual bool	Equals(Int32 valueToCompare) {
		//	return(false);
		//}
		virtual Int32	CompareTo(UInt32 valueToCompare) {
			return(0);
		}
		virtual Int32	CompareTo(Object* valueToCompare) {
			return(0);
		}
		static UInt32 Parse(String* stringToParse) {
			return(0);
		}
		virtual	Int32	FormatString(Char* where, const Int32 whereSize);
		static UInt32	MaxValue;
		static UInt32	MinValue;
	};
}
