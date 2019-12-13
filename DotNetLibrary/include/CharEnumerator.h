#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{

	class DLL_EXPORT CharEnumerator : public Object
	{
	public:
		CharEnumerator(String* str) {}
		Object*		Clone() { return(nullptr); }
		Char		get_Current() { return('a'); }
		Boolean		MoveNext() { return(false); }
		void		Reset() {}
	};
}
