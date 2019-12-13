#pragma once
#include "DotnetTypes.h"
#include <string.h>

namespace DotnetLibrary
{
	class CharEnumerator;

	class DLL_EXPORT String : public Object
	{
	public:
		String(const Char* string) {
			characterData = (Char*)string;
		}
		String(const char* string, const Int32 startIndex = -1, const Int32 toUse = -1) {
			size_t length = strlen(string);
			characterData = new Char[DataTypeSize[ByteType] * length];
			for (size_t i = 0; i < length; ++i) {
				characterData[i] = string[i];
			}
		}
		String(const Char chr, const Int32 amount) {}

		String(Array* chrs, const Int32 startIndex = -1, const Int32 toUse = -1) {}

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
		void CopyTo(Int32 sourceIndex, Array* destination, Int32 destinationIndex, Int32 count) {}
		Int32	GetLength(Int32 rank) {
			return(length);
		}
		Array* ToCharArray() { return(nullptr); }
		Array* ToCharArray(const Int32 startIndex, const Int32 length) { return(nullptr); }
		static	Int32		Compare(String* s1, String* s2, Boolean ignoreCase = false) { return(0); }
		static	Int32		Compare(String* s1, const Int32 index1, String* s2, const Int32 index2, const Int32 length, Boolean ignoreCase = false) { return(0); }
		static	Int32		CompareOrdinal(String* s1, String* s2) { return(0); }
		static	Int32		CompareOrdinal(String* s1, const Int32 index1, String* s2, const Int32 index2, const Int32 length) { return(0); }
		static	String* Copy(String* str) { return(nullptr); }
		static	String* Format(String* format, Array* args) { return(nullptr); }
		static	String* Format(String* format, Object* arg1, Object* arg2 = nullptr, Object* arg3 = nullptr) { return(nullptr); }
		CharEnumerator* GetEnumerator() { return(nullptr); }
		String operator+=(Object* obj) { return(*this); }
		static String* Empty;
	private:
		Char* characterData;
		Int32	length;
	};
}
