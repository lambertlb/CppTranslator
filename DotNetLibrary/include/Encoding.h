#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	class	DLL_EXPORT Encoding : public Object
	{
	private:
		Encoding();
	public:
		static Encoding* get_ASCII() { return(nullptr); }
		virtual ~Encoding() {};
		virtual Int32 GetByteCount(String* string) { return(0); };
		virtual Array* GetBytes(String* string) { return(nullptr); }
		virtual String* GetString(Array* arrayValue) { return(nullptr); }
	};
}
