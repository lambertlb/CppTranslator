#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	class DLL_EXPORT ValueType : public Object {
	public:
		ValueType(){}
		// .Net functions
		virtual bool	Equals(Object* valueToCOmpare) = 0;
		virtual Int32	CompareTo(Object* valueToCOmpare) = 0;
		String* ToString() = 0;
	};
}
