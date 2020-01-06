#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	class DLL_EXPORT Int32Value : public ValueType {
		Int32 value;
	public:
		Int32Value(Int32 v)
		{
			value = v;
		}
		virtual DataType GetRawDataType() { return(Int32Type); };
		virtual Int32		get_AsInt32();
		virtual Double		get_AsDouble();
		virtual bool	Equals(Object* valueToCompare) {
			return(false);
		}
		virtual bool	Equals(Int32 valueToCompare) {
			return(false);
		}
		virtual Int32	CompareTo(Int32 valueToCompare) {
			return(0);
		}
		virtual Int32	CompareTo(Object* valueToCompare) {
			return(0);
		}
		static Int32 Parse(String* stringToParse) {
			return(0);
		}
		virtual	Int32	FormatString(Char* where, const Int32 whereSize);
		static Int32	MaxValue;
		static Int32	MinValue;
	};
}
