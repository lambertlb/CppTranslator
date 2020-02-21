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

namespace DotnetLibrary
{
	CharEnumerator::CharEnumerator(String* str) {
		index = -1;
		string = str;
		currentElement = 0;
	}
	Char CharEnumerator::get_Current() {
		if (index == -1)
			throw new InvalidOperationException();
		if (index >= string->get_Length())
			throw new InvalidOperationException();
		return currentElement;
	}
	Boolean CharEnumerator::MoveNext() {
		if (index < (string->get_Length() - 1)) {
			index++;
			currentElement = string->get_Chars(index);
			return true;
		}
		else
			index = string->get_Length();
		return false;
	}
	void CharEnumerator::Reset() {
		currentElement = (char) 0;
		index = -1;
	}
}
