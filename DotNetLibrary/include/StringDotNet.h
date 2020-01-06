#pragma once
#include "DotnetTypes.h"
#include <string.h>

namespace DotnetLibrary
{
	class CharEnumerator;

	class DLL_EXPORT String : public Object
	{
	public:
		Char* characterData;
		size_t	length;
		Boolean allocate;
		String(const Char* string);
		String(const Char* string, const Int32 startIndex, Int32 length = -1);
		String(Array* chrs, const Int32 startIndex = 0, const Int32 length = -1);
		virtual ~String();
		virtual DataType GetRawDataType() { return(StringType); };

		virtual Boolean StartsWith(String* what) {
			return(false);
		}
		virtual Boolean EndsWith(String* what) {
			return(false);
		}
		virtual String* Combine(String* v) { return(nullptr); }
		Int32				get_Length() { return(length); }
		Char* Address(Int32 index1, Int32 index2 = -1, Int32 index3 = -1) {
			return(&characterData[index1]);
		}
		void CopyTo(Int32 sourceIndex, Array* destination, Int32 destinationIndex, Int32 count) {}
		Int32	GetLength(Int32 rank) {
			return(length);
		}
		Int32				CompareTo(Object* value) { return(0); }
		Int32				CompareTo(String* str) { return(0); }
		Array* ToCharArray() { return(nullptr); }
		Array* ToCharArray(const Int32 startIndex, const Int32 length) { return(nullptr); }
		Char				get_Chars(const Int32 index) { return(0); }
		Array* Split(Array* separator) { return(nullptr); }
		Array* Split(Array* separator, const Int32 count) { return(nullptr); }
		String* Substring(const Int32 startIndex) { return(nullptr); }
		String* Substring(const Int32 startIndex, const Int32 length) { return(nullptr); }
		virtual String* ToString();
		virtual	Int32	FormatString(Char* where, const Int32 whereSize);
		String* Trim() { return(nullptr); }
		String* Trim(Array* separator) { return(nullptr); }
		String* TrimEnd(Array* separator) { return(nullptr); }
		String* TrimStart(Array* separator) { return(nullptr); }
		Int32				IndexOf(const Char value) { return(0); }
		Int32				IndexOf(String* value) { return(0); }
		Int32				IndexOf(const Char value, const Int32 startIndex) { return(0); }
		Int32				IndexOf(String* value, const Int32 startIndex) { return(0); }
		Int32				IndexOf(const Char value, const Int32 startIndex, const Int32 count) { return(0); }
		Int32				IndexOf(String* value, const Int32 startIndex, const Int32 count) { return(0); }
		Int32				IndexOfAny(Array* arr) { return(0); }
		Int32				IndexOfAny(Array* arr, const Int32 startIndex) { return(0); }
		Int32				IndexOfAny(Array* arr, const Int32 startIndex, const Int32 count) { return(0); }
		Int32				LastIndexOf(const Char value) { return(0); }
		Int32				LastIndexOf(String* value) { return(0); }
		Int32				LastIndexOf(const Char value, const Int32  startIndex) { return(0); }
		Int32				LastIndexOf(String* value, const Int32 startIndex) { return(0); }
		Int32				LastIndexOf(const Char value, const Int32 startIndex, const Int32 count) { return(0); }
		Int32				LastIndexOf(String* value, const Int32 startIndex, const Int32 count) { return(0); }
		Int32				LastIndexOfAny(Array* arr) { return(0); }
		Int32				LastIndexOfAny(Array* arr, const Int32 startIndex) { return(0); }
		Int32				LastIndexOfAny(Array* arr, const Int32 startIndex, const Int32 count) { return(0); }
		String*			PadLeft(const Int32 width) { return(nullptr); }
		String*			PadLeft(const Int32 width, const Char chr) { return(nullptr); }
		String*			PadRight(const Int32 width) { return(nullptr); }
		String*			PadRight(const Int32 width, const Char chr) { return(nullptr); }
		String* Remove(const Int32 startIndex, const Int32 count) { return(nullptr); }
		String* Replace(const Char oldChar, const Char newChar) { return(nullptr); }
		String* Replace(String* oldValue, String* newValue) { return(nullptr); }
		String* ToLower() { return(nullptr); }
		String* ToUpper() { return(nullptr); }
		String*			Insert(const Int32 startIndex, String* value) { return(nullptr); }
		static	String*	Concat(Array* values) { return(nullptr); }
		static	String*	Concat(Object* s1, ...) { return(nullptr); }

		static	Int32		Compare(String* s1, String* s2, Boolean ignoreCase = false) { return(0); }
		static	Int32		Compare(String* s1, const Int32 index1, String* s2, const Int32 index2, const Int32 length, Boolean ignoreCase = false) { return(0); }
		static	Int32		CompareOrdinal(String* s1, String* s2) { return(0); }
		static	Int32		CompareOrdinal(String* s1, const Int32 index1, String* s2, const Int32 index2, const Int32 length) { return(0); }
		static	String* Copy(String* str) { return(nullptr); }
		static	String* Format(String* format, Array* args) { return(nullptr); }
		static	String* Format(String* format, Object* arg1, Object* arg2 = nullptr, Object* arg3 = nullptr) { return(nullptr); }
		static Boolean op_Inequality(String* str, String* str2) { return(false); }
		static	String* Join(String* separator, Array* values) { return(nullptr); }
		static	String* Join(String* separator, Array* values, const Int32 startIndex, const Int32 count) { return(nullptr); }

		CharEnumerator* GetEnumerator() { return(nullptr); }
		String operator+=(Object* obj) { return(*this); }
		static String* Empty;
	};
}
