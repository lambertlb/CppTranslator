#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	class RawObject
	{
	public:
		RawObject() {}
		virtual						~RawObject() {};
		static	Boolean				Equals(PointerType<RawObject> obj1, PointerType<RawObject> obj2) { return(true); }
		virtual Boolean				Equals(PointerType<RawObject> object) { return(true); }
		virtual	String				ToString() { return(nullptr); }
	};
	typedef	PointerType<RawObject>	Object;
}
