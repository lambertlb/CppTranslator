#pragma once
#include "DotnetTypes.h"
#include <string.h>

namespace DotnetLibrary
{
	class CharEnumerator;

	class DLL_EXPORT String : public Object
	{
		Char* characterData;
		size_t	length;
		Boolean allocate;
	public:
		String(const Char* string);
		String(const Char* string, Int32 startIndex, Int32 length = -1);
		String(Array* chrs,  Int32 startIndex = 0, Int32 length = -1);
		String(const Char chr, const Int32 amount);
		virtual				~String();
		Char*				get_Buffer() { return(characterData); }
		Char				get_Chars(const Int32 index);
		Int32				get_Length() { return(length); };
		Char*				Address(Int32 index1, Int32 index2 = -1, Int32 index3 = -1);
		static	Int32		Compare(Char* s1, Int32 s1Index, Char* s2, Int32 s2Index, Int32 length, Boolean ignoreCase);
		static	Int32		Compare(String* s1, String* s2, Boolean ignoreCase = false);
		static	Int32		Compare(String* s1, const Int32 index1, String* s2, const Int32 index2, const Int32 length, Boolean ignoreCase = false);
		static	Int32		CompareOrdinal(String* s1, String* s2);
		static	Int32		CompareOrdinal(String* s1, const Int32 index1, String* s2, const Int32 index2, const Int32 length);
		Int32				CompareTo(Object* value);
		Int32				CompareTo(String* str);
		static	String*		Concat(Array* values);
		static	String*		Concat(Object* o1, Object* o2 = nullptr, Object* o3 = nullptr, Object* o4 = nullptr, Object* o5 = nullptr, Object* o6 = nullptr, Object* o7 = nullptr);
		Boolean				Contains(String* substring);
		static	String*		Copy(String* str);
		void				CopyTo(Int32 sourceIndex, Array* destination, Int32 destinationIndex, Int32 count);
		virtual Boolean		EndsWith(String* what);
		virtual Boolean		EndsWith(Char what);
		static Boolean		op_Inequality(String* str, String* str2);
		virtual Boolean		Equals(Object* object);
		virtual Boolean		Equals(String* object);
		static Boolean		Equals(String* object, Object* object2);
		static	String*		Format(String* format, Array* args);
		static	String*		Format(String* format, Object* arg1, Object* arg2 = nullptr, Object* arg3 = nullptr);
		virtual	Int32		FormatString(Char* where, const Int32 whereSize);
		CharEnumerator*		GetEnumerator();
		virtual DataType	GetRawDataType() { return(StringType); };
		Int32				IndexOf(const Char value);
		Int32				IndexOf(String* value);
		Int32				IndexOf(const Char value, const Int32 startIndex);
		Int32				IndexOf(String* value, const Int32 startIndex);
		Int32				IndexOf(const Char value, const Int32 startIndex, const Int32 count);
		Int32				IndexOf(String* value, const Int32 startIndex, const Int32 count);
		Int32				IndexOfAny(Array* arr);
		Int32				IndexOfAny(Array* arr, const Int32 startIndex);
		Int32				IndexOfAny(Array* arr, const Int32 startIndex, const Int32 count);
		String*				Insert(const Int32 startIndex, String* value);
		Boolean				IsAllocated() { return(allocate); }
		static Boolean		IsNullOrEmpty(String* value);
		static Boolean		IsNullOrWhiteSpace(String* value);
		static Boolean		IsWhiteSpace(Char value, Char* separators, Int32 separatorSize);
		static	String*		Join(String* separator, Array* values, const Int32 startIndex = 0, Int32 count = -1);
		Int32				LastIndexOf(const Char value, Int32 startIndex = -1, Int32 count = -1);
		Int32				LastIndexOf(String* value, Int32 startIndex = -1, Int32 count = -1);
		Int32				LastIndexOfAny(Array* arr, Int32 startIndex = -1, Int32 count = -1);
		String*				PadLeft(const Int32 width, const Char chr = L' ');
		String*				PadRight(const Int32 width, const Char chr = L' ');
		String*				Remove(const Int32 startIndex, Int32 count = -1);
		String*				Replace(const Char oldChar, const Char newChar);
		String*				Replace(String* oldValue, String* newValue);
		Array*				Split(Array* separator, const Int32 count = -1);
		virtual Boolean		StartsWith(String* what);
		String*				Substring(const Int32 startIndex, Int32 length = -1);
		Array*				ToCharArray(Int32 startIndex = 0, Int32 length = -1);
		String*				ToLower();
		String*				ToLowerInvariant();
		virtual	String*		ToString();
		String*				ToUpper();
		String*				ToUpperInvariant();
		String*				Trim();
		String*				Trim(Array* separator);
		String*				TrimHelper(Array* separator, Boolean trimStart, Boolean trimEnd);
		String*				TrimHelper(Char* separator, Int32 separaterSize, Boolean trimStart, Boolean trimEnd);
		String*				TrimEnd(Array* separator);
		String*				TrimStart(Array* separator);
		static String*		Empty;
	};
	void CopyChars(Char* where, Int32 whereSize, Char* source, Int32 sourceSize);
}
