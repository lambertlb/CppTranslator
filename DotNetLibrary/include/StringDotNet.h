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
		virtual Boolean StartsWith(String* what) {
			return(false);
		}
		virtual Boolean EndsWith(String* what) {
			return(false);
		}
		virtual String* Combine(String* v) { return(nullptr); }
	private:
		Char*	characterData;
	};
}
