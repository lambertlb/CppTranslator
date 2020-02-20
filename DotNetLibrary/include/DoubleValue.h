// Copyright (c) 2019 LLambert
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this
// software and associated documentation files (the "Software"), to deal in the Software
// without restriction, including without limitation the rights to use, copy, modify, merge,
// publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons
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
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	class DLL_EXPORT DoubleValue : public ValueType {
		Double value;
	public:
		static Double	MaxValue;
		static Double	MinValue;
		static Double	Epsilon;
		static Double	NaN;
		static Double	PositiveInfinity;
		static Double	NegativeInfinity;
		DoubleValue(Double v) { value = v; }
		virtual Int16		get_AsInt16();
		virtual UInt16		get_AsUInt16();
		virtual Int32		get_AsInt32();
		virtual UInt32		get_AsUInt32();
		virtual Int64		get_AsInt64();
		virtual UInt64		get_AsUInt64();
		virtual Single		get_AsSingle();
		virtual Double		get_AsDouble();
		virtual Int32		CompareTo(Double valueToCompare);
		virtual Int32		CompareTo(Object* valueToCompare);
		virtual DataType	GetRawDataType() { return(DoubleType); };
		virtual Boolean		Equals(Object* valueToCompare);
		virtual Boolean		Equals(Double valueToCompare);
		static Boolean		IsFinite(Double d);
		static Boolean		IsInfinity(Double v);
		static Boolean		IsNaN(Double v);
		static Boolean		IsNegative(Double v);
		static Boolean		IsNegativeInfinity(Double v);
		static Boolean		IsNormal(Double v);
		static Boolean		IsPositiveInfinity(Double v);
		static Boolean		IsSubnormal(Double v);
		virtual	Int32		FormatString(Char* where, const Int32 whereSize);
		static Double		Modulus(Double v1, Double v2);
		static Double		Parse(String* stringToParse);
		static Boolean		TryParse(String* s, Double& result);
		static Boolean		TryParseInternal(String* source, Double& result);
		static Boolean		TryParseInternal(Char* source, Int32 sourceLength, Double& result);
		static Double		ToDouble(UInt64);
		static UInt64		ToUInt64(Double);
	};
}
