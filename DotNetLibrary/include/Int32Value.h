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
	class DLL_EXPORT Int32Value : public ValueType {
		Int32 value;
	public:
		static Int32	MaxValue;
		static Int32	MinValue;
		Int32Value(Int32 v) { value = v; }

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
		virtual Int32		CompareTo(Int32 valueToCompare);
		virtual Int32		CompareTo(Object* valueToCompare);
		virtual bool		Equals(Object* valueToCompare);
		virtual bool		Equals(Int32 valueToCompare);
		virtual	Int32		FormatString(Char* where, const Int32 whereSize);
		virtual DataType	GetRawDataType() { return(Int32Type); };
		static Int32		Parse(String* stringToParse);
		static bool			TryParse(String* stringToParse, Int32& result);
	};
}
