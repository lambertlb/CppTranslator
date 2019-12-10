#pragma once
#include "DotnetTypes.h"
#include <string.h>

namespace DotnetLibrary
{
	class String : public Object
	{
	public:
		String(const Char* string) {
			characterData = (Char*)string;
		}
		String(const char* string) {
			size_t length = strlen(string);
			characterData = new Char[DataTypeSize[ByteType] * length];
			for (size_t i = 0; i < length; ++i) {
				characterData[i] = string[i];
			}
		}
		String(const Char chr, const Int32 amount) {}
		virtual Boolean StartsWith(String* what) {
			return(false);
		}
		virtual Boolean EndsWith(String* what) {
			return(false);
		}
		virtual String* Combine(String* v) { return(nullptr); }
		Int32				get_Length() { return(0); }
		Char* Address(Int32 index1, Int32 index2 = -1, Int32 index3 = -1) {
			return(nullptr);
		}
	private:
		Char*	characterData;
	};
}
