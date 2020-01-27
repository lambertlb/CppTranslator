#include "DotnetTypes.h"

namespace DotnetLibrary
{
	CharEnumerator::CharEnumerator(String* str)
	{
		index = -1;
		string = str;
	}
	Char CharEnumerator::get_Current()
	{
		if (index == -1)
			throw new InvalidOperationException();
		if (index >= string->get_Length())
			throw new InvalidOperationException();
		return currentElement;
	}
	Boolean CharEnumerator::MoveNext()
	{
		if (index < (string->get_Length() - 1))
		{
			index++;
			currentElement = string->get_Chars(index);
			return true;
		}
		else
			index = string->get_Length();
		return false;
	}
	void CharEnumerator::Reset()
	{
		currentElement = (char)0;
		index = -1;
	}
}
