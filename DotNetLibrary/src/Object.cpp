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
#include <cstdlib>
#include <cstdio>
#include <cwchar>

namespace DotnetLibrary
{
	Boolean Object::Equals(Object* obj1, Object* obj2) {
		if (obj1 == obj2)
			return true;
		if (obj1 == nullptr || obj2 == nullptr)
			return false;
		return obj1->Equals(obj2);
	}
	Boolean Object::Equals(Object* object) {
		return (this == object);
	}
	Boolean Object::IsPrimitiveType(DataType type) {
		return (type != ObjectType && type != StringType && type != NullType);
	}
	String* Object::ToString() {
		Char chars[128];
		Int32 length = FormatString(chars, 128);
		chars[length] = 0;
		return (new String(chars, 0, length));
	}
	Int32 Object::FormatString(Char* where, const Int32 whereSize) {
		CopyChars(where, whereSize, (Char*) L"Object", 6);
		return ((Int32) wcslen((Char*) L"Object"));
	}
	Boolean Object::get_AsBoolean() {
		throw new InvalidCastException();
	}
	Char Object::get_AsChar() {
		throw new InvalidCastException();
	}
	Byte Object::get_AsByte() {
		throw new InvalidCastException();
	}
	SByte Object::get_AsSByte() {
		throw new InvalidCastException();
	}
	Int16 Object::get_AsInt16() {
		throw new InvalidCastException();
	}
	UInt16 Object::get_AsUInt16() {
		throw new InvalidCastException();
	}
	Int32 Object::get_AsInt32() {
		throw new InvalidCastException();
	}
	UInt32 Object::get_AsUInt32() {
		throw new InvalidCastException();
	}
	Int64 Object::get_AsInt64() {
		throw new InvalidCastException();
	}
	UInt64 Object::get_AsUInt64() {
		throw new InvalidCastException();
	}
	Single Object::get_AsSingle() {
		throw new InvalidCastException();
	}
	Double Object::get_AsDouble() {
		throw new InvalidCastException();
	}
	TimeSpan Object::get_AsTimeSpan() {
		throw new InvalidCastException();
	}
	DateTime Object::get_AsDateTime() {
		throw new InvalidCastException();
	}
}
