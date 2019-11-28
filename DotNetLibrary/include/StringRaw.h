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
		//friend bool operator== (const StringRaw& lhs, const StringRaw& rhs) noexcept {
		//	return(true);
		//}
		//friend bool operator== (const char* lhs, const StringRaw& rhs) {
		//	return(true);
		//}
		//friend bool operator== (const StringRaw& lhs, const char* rhs) {
		//	return(true);
		//}
		//friend bool operator== (const StringRaw& lhs, const void* rhs) {
		//	return(true);
		//}
	private:
		PointerType<ArrayRaw<Char>>	characterData;
	};
}
