#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	class DLL_EXPORT BitConverter : public Object
	{
	private:
		static Boolean AmILittleEndian();
		static Array* GetBytes(Byte* ptr, int count);
		static void PutBytes(Byte* dst, Array* src, Int32 start_index, Int32 count);
	public:
		static Boolean	IsLittleEndian;
		static Int64 DoubleToInt64Bits(Double value);
		static Double Int64BitsToDouble(Int64 value);
		static Array* GetBytes(Boolean value);
		static Array* GetBytes(Char value);
		static Array* GetBytes(Double value);
		static Array* GetBytes(Int16 value);
		static Array* GetBytes(Int32 value);
		static Array* GetBytes(Int64 value);
		static Array* GetBytes(Single value);
		static Array* GetBytes(UInt16 value);
		static Array* GetBytes(UInt32 value);
		static Array* GetBytes(UInt64 value);
		static Boolean ToBoolean(Array* value, Int32 startIndex);
		static Char ToChar(Array* value, Int32 startIndex);
		static Double ToDouble(Array* value, Int32 startIndex);
		static Int16 ToInt16(Array* value, Int32 startIndex);
		static Int32 ToInt32(Array* value, Int32 startIndex);
		static Int64 ToInt64(Array* value, Int32 startIndex);
		static Single ToSingle(Array* value, Int32 startIndex);
		static UInt16 ToUInt16(Array* value, Int32 startIndex);
		static UInt32 ToUInt32(Array* value, Int32 startIndex);
		static UInt64 ToUInt64(Array* value, Int32 startIndex);
		static String* ToString(Array* value, Int32 startIndex = 0, Int32 length = -1);
	};
}