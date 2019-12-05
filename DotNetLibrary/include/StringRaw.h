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
	struct BooleanRaw {
		static Boolean	Parse(StringRaw* string) {
			return(true);
		}
	};
	struct ByteRaw {
		static Byte	Parse(StringRaw* string) {
			return(true);
		}
	};
	struct CharRaw {
		static Double	GetNumericValue(Char v) {
			return(0);
		}
		static Double	GetNumericValue(StringRaw* v, Int32 index) {
			return(0);
		}
		static Boolean	IsControl(Char v) {
			return(false);
		}
		static Boolean	IsControl(StringRaw* v, Int32 index) {
			return(false);
		}
		static Boolean	IsDigit(Char v) {
			return(false);
		}
		static Boolean	IsDigit(StringRaw* v, Int32 index) {
			return(false);
		}
		static Boolean	IsLetter(Char v) {
			return(false);
		}
		static Boolean	IsLetter(StringRaw* v, Int32 index) {
			return(false);
		}
		static Boolean	IsLetterOrDigit(Char v) {
			return(false);
		}
		static Boolean	IsLetterOrDigit(StringRaw* v, Int32 index) {
			return(false);
		}
		static Boolean	IsLower(Char v) {
			return(false);
		}
		static Boolean	IsLower(StringRaw* v, Int32 index) {
			return(false);
		}
		static Boolean	IsNumber(Char v) {
			return(false);
		}
		static Boolean	IsNumber(StringRaw* v, Int32 index) {
			return(false);
		}
		static Boolean	IsPunctuation(Char v) {
			return(false);
		}
		static Boolean	IsPunctuation(StringRaw* v, Int32 index) {
			return(false);
		}
		static Boolean	IsSeparator(Char v) {
			return(false);
		}
		static Boolean	IsSeparator(StringRaw* v, Int32 index) {
			return(false);
		}
		static Boolean	IsUpper(Char v) {
			return(false);
		}
		static Boolean	IsUpper(StringRaw* v, Int32 index) {
			return(false);
		}
		static Boolean	IsWhiteSpace(Char v) {
			return(false);
		}
		static Boolean	IsWhiteSpace(StringRaw* v, Int32 index) {
			return(false);
		}
		static Char	ToLower(Char v) {
			return(0);
		}
		static Char	ToUpper(Char v) {
			return(0);
		}
		static StringRaw*	ToString(Char v) {
			return(nullptr);
		}
		static Char	Parse(StringRaw* string) {
			return(0);
		}
	};
}
