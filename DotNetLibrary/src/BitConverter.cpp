#include "BitConverter.h"

namespace DotnetLibrary
{
	Boolean	BitConverter::IsLittleEndian = AmILittleEndian();
	Boolean BitConverter::AmILittleEndian()
	{
		Double d = 1.0;
		Byte* b = (Byte*)&d;
		return (b[0] == 0);
	}
	Array* BitConverter::GetBytes(Byte* ptr, int count)
	{
		Array* ret = new Array(ByteType, count);
		memcpy(ret->Address(0), ptr, count);
		return ret;
	}
	void BitConverter::PutBytes(Byte* dst, Array* src, Int32 start_index, Int32 count)
	{
		if (src == nullptr)
			throw new ArgumentNullException();
		if (start_index < 0 || (start_index > src->get_Length() - 1))
			throw new ArgumentOutOfRangeException();
		// avoid integer overflow (with large pos/neg start_index values)
		if (src->get_Length() - count < start_index)
			throw new ArgumentException();
		memcpy(dst, src->Address(start_index), count);
	}
	Int64 BitConverter::DoubleToInt64Bits(Double value)
	{
		return *(Int64*)&value;
	}
	Double BitConverter::Int64BitsToDouble(Int64 value)
	{
		return *(Double*)&value;
	}
	Array* BitConverter::GetBytes(Boolean value)
	{
		return GetBytes((Byte*)&value, 1);
	}
	Array* BitConverter::GetBytes(Char value)
	{
		Int16 val = (Int16)value;
		return GetBytes((Byte*)&val, sizeof(Int16));
	}
	Array* BitConverter::GetBytes(Double value)
	{
		return GetBytes((Byte*)&value, sizeof(Double));
	}
	Array* BitConverter::GetBytes(Int16 value)
	{
		return GetBytes((Byte*)&value, sizeof(Int16));
	}
	Array* BitConverter::GetBytes(Int32 value)
	{
		return GetBytes((Byte*)&value, sizeof(Int32));
	}
	Array* BitConverter::GetBytes(Int64 value)
	{
		return GetBytes((Byte*)&value, sizeof(Int64));
	}
	Array* BitConverter::GetBytes(Single value)
	{
		return GetBytes((Byte*)&value, sizeof(Single));
	}
	Array* BitConverter::GetBytes(UInt16 value)
	{
		return GetBytes((Byte*)&value, sizeof(UInt16));
	}
	Array* BitConverter::GetBytes(UInt32 value)
	{
		return GetBytes((Byte*)&value, sizeof(UInt32));
	}
	Array* BitConverter::GetBytes(UInt64 value)
	{
		return GetBytes((Byte*)&value, sizeof(UInt64));
	}
	Boolean BitConverter::ToBoolean(Array* value, Int32 startIndex)
	{
		if (value == nullptr)
			throw new ArgumentNullException();
		if (startIndex < 0 || (startIndex > value->get_Length() - 1))
			throw new ArgumentOutOfRangeException();
		if (*(Byte*)value->Address(startIndex) != 0)
			return true;
		return false;
	}
	Char BitConverter::ToChar(Array* value, Int32 startIndex)
	{
		Int16 ret;
		PutBytes((Byte*)&ret, value, startIndex, sizeof(Int16));
		return (Char)ret;
	}
	Double BitConverter::ToDouble(Array* value, Int32 startIndex)
	{
		Double ret;
		PutBytes((Byte*)&ret, value, startIndex, sizeof(Double));
		return ret;
	}
	Int16 BitConverter::ToInt16(Array* value, Int32 startIndex)
	{
		Int16 ret;
		PutBytes((Byte*)&ret, value, startIndex, sizeof(Int16));
		return ret;
	}
	Int32 BitConverter::ToInt32(Array* value, Int32 startIndex)
	{
		Int32 ret;
		PutBytes((Byte*)&ret, value, startIndex, sizeof(Int32));
		return ret;
	}
	Int64 BitConverter::ToInt64(Array* value, Int32 startIndex)
	{
		Int64 ret;
		PutBytes((Byte*)&ret, value, startIndex, sizeof(Int64));
		return ret;
	}
	Single BitConverter::ToSingle(Array* value, Int32 startIndex)
	{
		Single ret;
		PutBytes((Byte*)&ret, value, startIndex, sizeof(Single));
		return ret;
	}
	UInt16 BitConverter::ToUInt16(Array* value, Int32 startIndex)
	{
		UInt16 ret;
		PutBytes((Byte*)&ret, value, startIndex, sizeof(UInt16));
		return ret;
	}
	UInt32 BitConverter::ToUInt32(Array* value, Int32 startIndex)
	{
		UInt32 ret;
		PutBytes((Byte*)&ret, value, startIndex, sizeof(UInt32));
		return ret;
	}
	UInt64 BitConverter::ToUInt64(Array* value, Int32 startIndex)
	{
		UInt64 ret;
		PutBytes((Byte*)&ret, value, startIndex, sizeof(UInt64));
		return ret;
	}
	String* BitConverter::ToString(Array* value, Int32 startIndex, Int32 length)
	{
		if (value == nullptr)
			throw new ArgumentNullException();
		if (length == -1)
			length = value->get_Length() - startIndex;
		if (startIndex < 0 || startIndex >= value->get_Length()) {
			// special (but valid) case (e.g. new byte [0])
			if ((startIndex == 0) && (value->get_Length() == 0))
				return String::Empty;
			throw new ArgumentOutOfRangeException();
		}
		if (length < 0)
			throw new ArgumentOutOfRangeException();
		// note: re-ordered to avoid possible integer overflow
		if (startIndex > value->get_Length() - length)
			throw new ArgumentException();
		if (length == 0)
			return String::Empty;
		StringBuilder builder(length * 3 - 1);
		Int32 end = startIndex + length;

		for (Int32 i = startIndex; i < end; i++) {
			if (i > startIndex)
				builder.Append(L'-');
			Byte byte = *(Byte*)value->Address(i);
			Char high = (Char)((byte >> 4) & 0x0f);
			Char low = (Char)(byte & 0x0f);

			if (high < 10)
				high += L'0';
			else {
				high -= (Char)10;
				high += L'A';
			}

			if (low < 10)
				low += L'0';
			else {
				low -= (Char)10;
				low += L'A';
			}
			builder.Append(high);
			builder.Append(low);
		}

		return builder.ToString();
	}
}
