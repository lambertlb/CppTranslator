// Copyright (c) 2019 LLambert
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this
// software and associated documentation files (the "Software"), to deal in the Software
// without restriction, including without limitation the rights to use, copy, modify, merge,
// publish, distribute, sub-license, and/or sell copies of the Software, and to permit persons
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
#include "DotnetTypes.h"
#include <cwchar>
namespace DotnetLibrary
{
	Byte ByteValue::MaxValue = 255;
	Byte ByteValue::MinValue = 0;
	Boolean ByteValue::get_AsBoolean() {
		return value != 0;
	}
	Char ByteValue::get_AsChar() {
		return value;
	}
	Byte ByteValue::get_AsByte() {
		return value;
	}
	SByte ByteValue::get_AsSByte() {
		return value;
	}
	Int16 ByteValue::get_AsInt16() {
		return value;
	}
	UInt16 ByteValue::get_AsUInt16() {
		return value;
	}
	Int32 ByteValue::get_AsInt32() {
		return value;
	}
	UInt32 ByteValue::get_AsUInt32() {
		return value;
	}
	Int64 ByteValue::get_AsInt64() {
		return value;
	}
	UInt64 ByteValue::get_AsUInt64() {
		return value;
	}
	Single ByteValue::get_AsSingle() {
		return value;
	}
	Double ByteValue::get_AsDouble() {
		return value;
	}
	Int32 ByteValue::CompareTo(Byte valueToCompare) {
		return value - valueToCompare;
	}
	Int32 ByteValue::CompareTo(Object* valueToCompare) {
		if (valueToCompare == nullptr) {
			return 1;
		}
		if (valueToCompare->GetRawDataType() != ByteType) {
			throw new ArgumentException();
		}
		return value - ((ByteValue*) valueToCompare)->value;
	}
	Boolean ByteValue::Equals(Object* valueToCompare) {
		if (valueToCompare->GetRawDataType() != ByteType) {
			return false;
		}
		return value == ((ByteValue*) valueToCompare)->value;
	}
	Boolean ByteValue::Equals(Byte valueToCompare) {
		return value == valueToCompare;
	}
	Int32 ByteValue::FormatString(Char* where, const Int32 whereSize) {
#ifdef __MINGW32__
		return(swprintf(where, L"%u", value));
#else
		return (swprintf(where, (size_t) whereSize, L"%u", value));
#endif
	}
	Byte ByteValue::Parse(String* stringToParse) {
		UInt64 value = 0;
		Int32 sign = 0;
		if (!UInt64Value::TryParseInternal(stringToParse, value, sign))
			throw new FormatException();
		if (sign < 0 || value > MaxValue)
			throw new OverflowException();
		return (value);
	}
	bool ByteValue::TryParse(String* stringToParse, Byte& result) {
		Boolean goodNumber = true;
		UInt64 value = 0;
		Int32 sign = 0;
		if (!UInt64Value::TryParseInternal(stringToParse, value, sign))
			goodNumber = false;
		if (sign < 0 || value > MaxValue)
			goodNumber = false;
		result = (Byte) value;
		return (goodNumber);
	}
}
