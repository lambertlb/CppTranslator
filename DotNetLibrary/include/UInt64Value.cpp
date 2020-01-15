#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	Boolean UInt64Value::TryParseInternal(String* source, UInt64& result, Int32& sign)
	{
		if (source == nullptr)
			throw new ArgumentNullException();
		return(TryParseInternal(source->get_Buffer(), source->get_Length(), result, sign));
	}
	Boolean UInt64Value::TryParseInternal(Char* source, Int32 sourceLength, UInt64& result, Int32& sign)
	{
		result = 0;
		sign = 0;
		Boolean gotNumber = false;
		while (*source != 0 && sourceLength > 0) {
			if (!CharValue::IsWhiteSpace(*source))
				break;
			++source;
			--sourceLength;
		}
		if (*source != 0 && sourceLength > 0) {
			if (*source == L'-') {
				sign = -1;
				++source;
				--sourceLength;
			}
			else if (*source == L'+') {
				++source;
				--sourceLength;
			}
		}
		while (*source != 0 && sourceLength > 0) {
			if (!CharValue::IsDigit(*source))
				break;
			result = 10 * result + *source - '0';
			++source;
			--sourceLength;
			gotNumber = true;
		}
		if (sourceLength > 0 && !CharValue::IsWhiteSpace(*source))
			gotNumber = false;
		return(gotNumber);
	}
	Int32 UInt64Value::FormatString(Char* where, const Int32 whereSize)
	{
		return(swprintf(where, whereSize, L"%lld", value));
	}
}
