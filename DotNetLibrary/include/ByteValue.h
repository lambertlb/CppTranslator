#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	class DLL_EXPORT ByteValue : public ValueType {
		Byte value;
	public:
		ByteValue(Byte v)
		{
			value = v;
		}
		// .Net functions
		virtual bool	Equals(Object* valueToCompare) {
			return(false);
		}
		virtual bool	Equals(Char valueToCompare) {
			return(false);
		}
		virtual bool	Equals(Int32 valueToCompare) {
			return(false);
		}
		virtual Int32	CompareTo(Byte valueToCompare) {
			return(0);
		}
		virtual Int32	CompareTo(Object* valueToCompare) {
			return(0);
		}
		String* ToString() {
			return(nullptr);
		}
		static String* ToString(Char v) {
			return(nullptr);
		}
		static Byte Parse(String* stringToParse) {
			return(0);
		}
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
		static Byte	MaxValue;
		static Byte	MinValue;
	};
	typedef ByteValue CharValue;
}
