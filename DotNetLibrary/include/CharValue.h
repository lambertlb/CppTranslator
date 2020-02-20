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
	class DLL_EXPORT CharValue : public ValueType {
		Char value;
	public:
		CharValue(Char v) { value = v; }
		virtual Char	get_AsChar();
		virtual Byte	get_AsByte();
		virtual SByte	get_AsSByte();
		virtual Int16	get_AsInt16();
		virtual UInt16	get_AsUInt16();
		virtual Int32	get_AsInt32();
		virtual UInt32	get_AsUInt32();
		virtual Int64	get_AsInt64();
		virtual UInt64	get_AsUInt64();
		virtual Single	get_AsSingle();
		virtual Double	get_AsDouble();
		virtual DataType GetRawDataType() { return(CharType); };
		virtual Int32	CompareTo(Char valueToCompare);
		virtual Int32	CompareTo(Object* valueToCompare);
		virtual bool	Equals(Object* valueToCompare);
		virtual bool	Equals(Char valueToCompare);
		virtual	Int32	FormatString(Char* where, const Int32 whereSize);
		static Double	GetNumericValue(Char v);
		static Double	GetNumericValue(String* v, Int32 index);
		static Boolean	IsControl(Char v);
		static Boolean	IsControl(String* v, Int32 index);
		static Boolean	IsDigit(Char v);
		static Boolean	IsDigit(String* v, Int32 index);
		static Boolean	IsLetter(Char v);
		static Boolean	IsLetter(String* v, Int32 index);
		static Boolean	IsLetterOrDigit(Char v);
		static Boolean	IsLetterOrDigit(String* v, Int32 index);
		static Boolean	IsLower(Char v);
		static Boolean	IsLower(String* v, Int32 index);
		static Boolean	IsNumber(Char v);
		static Boolean	IsNumber(String* v, Int32 index);
		static Boolean	IsPunctuation(Char v);
		static Boolean	IsPunctuation(String* v, Int32 index);
		static Boolean	IsSeparator(Char v);
		static Boolean	IsSeparator(String* v, Int32 index);
		static Boolean	IsUpper(Char v);
		static Boolean	IsUpper(String* v, Int32 index);
		static Boolean	IsWhiteSpace(Char v);
		static Boolean	IsWhiteSpace(String* v, Int32 index);
		static Char		Parse(String* stringToParse);
		static Char		ToLower(Char v);
		static Char		ToUpper(Char v);
		static Boolean	TryParse(String* s, Char& result);
		String*			ToString();
		static String*	ToString(Char v);
		static Char		MaxValue;
		static Char		MinValue;
	};
}
