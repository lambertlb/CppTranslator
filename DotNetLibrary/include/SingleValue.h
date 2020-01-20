#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	class DLL_EXPORT SingleValue : public ValueType {
		Single value;
	public:
		static Single	MaxValue;
		static Single	MinValue;
		static Single	Epsilon;
		static Single	NaN;
		static Single	PositiveInfinity;
		static Single	NegativeInfinity;
		SingleValue(Single v) { value = v; }
		virtual Int16		get_AsInt16();
		virtual UInt16		get_AsUInt16();
		virtual Int32		get_AsInt32();
		virtual UInt32		get_AsUInt32();
		virtual Int64		get_AsInt64();
		virtual UInt64		get_AsUInt64();
		virtual Single		get_AsSingle();
		virtual Double		get_AsDouble();
		virtual Int32		CompareTo(Single valueToCompare);
		virtual Int32		CompareTo(Object* valueToCompare);
		virtual DataType	GetRawDataType() { return(SingleType); };
		virtual Boolean		Equals(Object* valueToCompare);
		virtual Boolean		Equals(Single valueToCompare);
		static Boolean		IsFinite(Single d);
		static Boolean		IsInfinity(Single v);
		static Boolean		IsNaN(Single v);
		static Boolean		IsNegative(Single v);
		static Boolean		IsNegativeInfinity(Single v);
		static Boolean		IsNormal(Single v);
		static Boolean		IsPositiveInfinity(Single v);
		static Boolean		IsSubnormal(Single v);
		virtual	Int32		FormatString(Char* where, const Int32 whereSize);
		static Single		Modulus(Single v1, Single v2);
		static Single		Parse(String* stringToParse);
		static Boolean		TryParse(String* s, Single* result);
		static Boolean		TryParseInternal(String* source, Single& result);
		static Boolean		TryParseInternal(Char* source, Int32 sourceLength, Single& result);
		static Single		ToSingle(UInt32);
		static UInt32		ToUInt32(Single);
	};
	typedef SingleValue FloatValue;
}
