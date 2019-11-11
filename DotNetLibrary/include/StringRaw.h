#pragma once
#include "DotnetTypes.h"
#include <string.h>

namespace DotnetLibrary
{
	class StringRaw : public ObjectRaw
	{
	public:
		StringRaw(const PointerType<ArrayRaw<Char>> string) {
			characterData = string;
		}
		StringRaw(const char* string) {
			size_t length = strlen(string);
			characterData = new ArrayRaw<Char>(length);
			for (size_t i = 0; i < length; ++i) {
				characterData->SetValue(string[i], i);
			}
		}
	private:
		PointerType<ArrayRaw<Char>>	characterData;
	};
	typedef PointerType<StringRaw>	String;
}
