#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	DLL_EXPORT String* BooleanValue::TrueString = new String(L"true");
	DLL_EXPORT String* BooleanValue::FalseString = new String(L"false");

	Boolean BooleanValue::get_AsBoolean()
	{
		return(value);
	}

	Byte BooleanValue::get_AsByte()
	{
		return(value ? 1 : 0);
	}

	SByte BooleanValue::get_AsSByte()
	{
		return(value ? 1 : 0);
	}

	Int16 BooleanValue::get_AsInt16()
	{
		return(value ? 1 : 0);
	}

	UInt16 BooleanValue::get_AsUInt16()
	{
		return(value ? 1 : 0);
	}

	Int32 BooleanValue::get_AsInt32()
	{
		return(value ? 1 : 0);
	}

	UInt32 BooleanValue::get_AsUInt32()
	{
		return(value ? 1 : 0);
	}

	Int64 BooleanValue::get_AsInt64()
	{
		return(value ? 1 : 0);
	}

	UInt64 BooleanValue::get_AsUInt64()
	{
		return(value ? 1 : 0);
	}

	Int32 BooleanValue::CompareTo(Boolean valueToCompare)
	{
		if (value == valueToCompare)
		{
			return 0;
		}
		else if (value == false)
		{
			return -1;
		}
		return 1;
	}

	Int32 BooleanValue::CompareTo(Object* valueToCompare)
	{
		if (valueToCompare == nullptr)
			return(1);
		if (valueToCompare->GetRawDataType() != BooleanType)
			throw new ArgumentException();
		return(CompareTo(((BooleanValue*)valueToCompare)->value));
	}

	bool BooleanValue::Equals(Object* valueToCompare)
	{
		if (valueToCompare == nullptr)
			return(false);
		if (valueToCompare->GetRawDataType() != BooleanType)
			return(false);
		return(valueToCompare->get_AsBoolean() == value);
	}

	bool BooleanValue::Equals(Boolean valueToCompare)
	{
		return valueToCompare == value;
	}


	Int32 BooleanValue::FormatString(Char* where, const Int32 whereSize)
	{
		Int32 rtn;
		if (value) {
			wcscpy_s(where, whereSize, TrueString->get_Buffer());
			rtn = TrueString->get_Length();
		}
		else {
			wcscpy_s(where, whereSize, FalseString->get_Buffer());
			rtn = FalseString->get_Length();
		}
		return rtn;
	}
	Boolean BooleanValue::Parse(String* stringToParse)
	{
		if (stringToParse == nullptr)
			throw new ArgumentException();
		if (String::Compare(stringToParse, TrueString, true) == 0) {
			return true;
		}
		if (String::Compare(stringToParse, FalseString, true) == 0) {
			return false;
		}
		throw new FormatException();
	}
}
