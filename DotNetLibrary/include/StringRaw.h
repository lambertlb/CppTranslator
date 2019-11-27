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
		//friend Boolean operator==(const StringRaw& string1, const StringRaw& string2) {
		//	return true;
		//}
		//friend Boolean operator==(const StringRaw& string1, const StringRaw* string2) {
		//	return true;
		//}
		//friend Boolean operator==(const StringRaw& string1, const void* string2) {
		//	return true;
		//}
	private:
		PointerType<ArrayRaw<Char>>	characterData;
	};
}
