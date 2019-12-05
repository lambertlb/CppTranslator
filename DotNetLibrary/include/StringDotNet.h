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
	private:
		Char*	characterData;
	};
	struct CharRaw {
		static Double	GetNumericValue(Char v) {
			return(0);
		}
		static Double	GetNumericValue(String* v, Int32 index) {
			return(0);
		}
		static Boolean	IsControl(Char v) {
			return(false);
		}
		static Boolean	IsControl(String* v, Int32 index) {
			return(false);
		}
		static Boolean	IsDigit(Char v) {
			return(false);
		}
		static Boolean	IsDigit(String* v, Int32 index) {
			return(false);
		}
		static Boolean	IsLetter(Char v) {
			return(false);
		}
		static Boolean	IsLetter(String* v, Int32 index) {
			return(false);
		}
		static Boolean	IsLetterOrDigit(Char v) {
			return(false);
		}
		static Boolean	IsLetterOrDigit(String* v, Int32 index) {
			return(false);
		}
		static Boolean	IsLower(Char v) {
			return(false);
		}
		static Boolean	IsLower(String* v, Int32 index) {
			return(false);
		}
		static Boolean	IsNumber(Char v) {
			return(false);
		}
		static Boolean	IsNumber(String* v, Int32 index) {
			return(false);
		}
		static Boolean	IsPunctuation(Char v) {
			return(false);
		}
		static Boolean	IsPunctuation(String* v, Int32 index) {
			return(false);
		}
		static Boolean	IsSeparator(Char v) {
			return(false);
		}
		static Boolean	IsSeparator(String* v, Int32 index) {
			return(false);
		}
		static Boolean	IsUpper(Char v) {
			return(false);
		}
		static Boolean	IsUpper(String* v, Int32 index) {
			return(false);
		}
		static Boolean	IsWhiteSpace(Char v) {
			return(false);
		}
		static Boolean	IsWhiteSpace(String* v, Int32 index) {
			return(false);
		}
		static Char	ToLower(Char v) {
			return(0);
		}
		static Char	ToUpper(Char v) {
			return(0);
		}
		static String*	ToString(Char v) {
			return(nullptr);
		}
		static Char	Parse(String* string) {
			return(0);
		}
	};
}
