#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	class  ByteValue : public ValueType {
		Byte value;
	public:
		ByteValue(Byte v)
		{
			value = v;
		}
		// .Net functions
		virtual bool	Equals(Object* valueToCompare) {
			return(false);
		}
		virtual bool	Equals(Char valueToCompare) {
			return(false);
		}
		virtual Int32	CompareTo(Object* valueToCompare) {
			return(0);
		}
		String* ToString() {
			return(nullptr);
		}
	};
	typedef ByteValue CharValue;
}
