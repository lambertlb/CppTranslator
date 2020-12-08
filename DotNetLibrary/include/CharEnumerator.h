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
#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{

	/*!
	 * Emulate .Net CharEnumerator
	 */
	class DLL_EXPORT CharEnumerator: public Object
	{
		Int32	index;
		String* string;
		Char	currentElement;
	public:
		/*!
		 * Construct enumerator
		 * @param str string to enumerate
		 */
		CharEnumerator(String* str);
		/*!
		 * Gets the currently referenced character
		 * @return current character
		 */
		Char get_Current();
		/*!
		 * Increments the internal index to the next character of the enumerated string.
		 * @return true if the index is successfully incremented and within the enumerated string; otherwise, false
		 */
		Boolean MoveNext();
		/*!
		 * Initializes the index to a position logically before the first character of the enumerated string.
		 */
		void Reset();
	};
}
