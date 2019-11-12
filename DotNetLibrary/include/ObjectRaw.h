#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	class ObjectRaw
	{
	public:
		ObjectRaw() {}
		virtual						~ObjectRaw() {};
		static	Boolean				Equals(PointerType<ObjectRaw> obj1, PointerType<ObjectRaw> obj2) { return(true); }
		virtual Boolean				Equals(PointerType<ObjectRaw> object) { return(true); }
		virtual	String				ToString() { return(nullptr); }
		virtual void				Send(PointerType<StringRaw> message) {

		}
	};
	typedef	PointerType<ObjectRaw>	Object;
}
