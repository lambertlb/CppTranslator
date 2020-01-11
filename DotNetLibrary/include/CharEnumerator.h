#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{

	class DLL_EXPORT CharEnumerator : public Object
	{
		Int32	index;
		String* string;
		Char	currentElement;
	public:
		CharEnumerator(String* str);
		Char		get_Current();
		Boolean		MoveNext();
		void		Reset();
	};
}
