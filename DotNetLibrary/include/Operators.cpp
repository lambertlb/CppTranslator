#pragma once
#include "pch.h"
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	StringRaw* Boolean::FalseString = nullptr;
	StringRaw* Boolean::TrueString = nullptr;

	//(Byte operators
	DLL_EXPORT Int32 operator+(Byte iw, Char v) { return iw.value += v; };
	DLL_EXPORT Int32 operator+(Byte iw, Byte v) { return iw.value += v; };
	DLL_EXPORT Int32 operator+(Byte iw, Int16 v) { return iw.value += v; };
	DLL_EXPORT Int32 operator+(Byte iw, UInt16 v) { return iw.value += v; };
	DLL_EXPORT Int32 operator+(Byte iw, Int32 v) { return iw.value += v; };
	DLL_EXPORT Int32 operator+(Byte iw, UInt32 v) { return iw.value += v; };
	DLL_EXPORT Int32 operator+(Byte iw, Int64 v) { return iw.value += (int32_t)v.value; };
	DLL_EXPORT Int32 operator+(Byte iw, UInt64 v) { return iw.value += (int32_t)v.value; };
	DLL_EXPORT Double operator+(Byte iw, Float v) { return iw.value += (int32_t)v.value; };
	DLL_EXPORT Double operator+(Byte iw, Double v) { return iw.value += (int32_t)v.value; };

	DLL_EXPORT Int32 operator-(Byte iw, Char v) { return iw.value -= v; };
	DLL_EXPORT Int32 operator-(Byte iw, Byte v) { return iw.value -= v; };
	DLL_EXPORT Int32 operator-(Byte iw, Int16 v) { return iw.value -= v; };
	DLL_EXPORT Int32 operator-(Byte iw, UInt16 v) { return iw.value -= v; };
	DLL_EXPORT Int32 operator-(Byte iw, Int32 v) { return iw.value -= v; };
	DLL_EXPORT Int32 operator-(Byte iw, UInt32 v) { return iw.value -= v; };
	DLL_EXPORT Int32 operator-(Byte iw, Int64 v) { return iw.value -= (int32_t)v.value; };
	DLL_EXPORT Int32 operator-(Byte iw, UInt64 v) { return iw.value -= (int32_t)v.value; };
	DLL_EXPORT Double operator-(Byte iw, Float v) { return iw.value -= (int32_t)v.value; };
	DLL_EXPORT Double operator-(Byte iw, Double v) { return iw.value -= (int32_t)v.value; };

	DLL_EXPORT Int32 operator*(Byte iw, Byte v) { return iw.value *= v; }
	DLL_EXPORT Int32 operator*(Byte iw, Char v) { return iw.value *= v; };
	DLL_EXPORT Int32 operator*(Byte iw, Int16 v) { return iw.value *= v; };
	DLL_EXPORT Int32 operator*(Byte iw, UInt16 v) { return iw.value *= v; };
	DLL_EXPORT Int32 operator*(Byte iw, Int32 v) { return iw.value *= v; };
	DLL_EXPORT Int32 operator*(Byte iw, UInt32 v) { return iw.value *= v; };
	DLL_EXPORT Int32 operator*(Byte iw, Int64 v) { return iw.value *= (int32_t)v.value; };
	DLL_EXPORT Int32 operator*(Byte iw, UInt64 v) { return iw.value *= (int32_t)v.value; };
	DLL_EXPORT Double operator*(Byte iw, Float v) { return iw.value *= (int32_t)v.value; };
	DLL_EXPORT Double operator*(Byte iw, Double v) { return iw.value *= (int32_t)v.value; };

	DLL_EXPORT Int32 operator/(Byte iw, Byte v) { return iw.value /= v; }
	DLL_EXPORT Int32 operator/(Byte iw, Char v) { return iw.value /= v; };
	DLL_EXPORT Int32 operator/(Byte iw, Int16 v) { return iw.value /= v; };
	DLL_EXPORT Int32 operator/(Byte iw, UInt16 v) { return iw.value /= v; };
	DLL_EXPORT Int32 operator/(Byte iw, Int32 v) { return iw.value /= v; };
	DLL_EXPORT Int32 operator/(Byte iw, UInt32 v) { return iw.value /= v; };
	DLL_EXPORT Int32 operator/(Byte iw, Int64 v) { return iw.value /= (int32_t)v.value; };
	DLL_EXPORT Int32 operator/(Byte iw, UInt64 v) { return iw.value /= (int32_t)v.value; };
	DLL_EXPORT Double operator/(Byte iw, Float v) { return iw.value /= (int32_t)v.value; };
	DLL_EXPORT Double operator/(Byte iw, Double v) { return iw.value /= (int32_t)v.value; };

	DLL_EXPORT Int32 operator%(Byte iw, Byte v) { return iw.value %= v; }
	DLL_EXPORT Int32 operator%(Byte iw, Char v) { return iw.value %= v; };
	DLL_EXPORT Int32 operator%(Byte iw, Int16 v) { return iw.value %= v; };
	DLL_EXPORT Int32 operator%(Byte iw, UInt16 v) { return iw.value %= v; };
	DLL_EXPORT Int32 operator%(Byte iw, Int32 v) { return iw.value %= v; };
	DLL_EXPORT Int32 operator%(Byte iw, UInt32 v) { return iw.value %= v; };
	DLL_EXPORT Int32 operator%(Byte iw, Int64 v) { return iw.value %= (int32_t)v.value; };
	DLL_EXPORT Int32 operator%(Byte iw, UInt64 v) { return iw.value %= (int32_t)v.value; };
	DLL_EXPORT Double operator%(Byte iw, Float v) { return iw.value %= (int32_t)v.value; };
	DLL_EXPORT Double operator%(Byte iw, Double v) { return iw.value %= (int32_t)v.value; };

	DLL_EXPORT Int32 operator&(Byte iw, Byte v) { return iw.value &= v; }
	DLL_EXPORT Int32 operator&(Byte iw, Char v) { return iw.value &= v; };
	DLL_EXPORT Int32 operator&(Byte iw, Int16 v) { return iw.value &= v; };
	DLL_EXPORT Int32 operator&(Byte iw, UInt16 v) { return iw.value &= v; };
	DLL_EXPORT Int32 operator&(Byte iw, Int32 v) { return iw.value &= v; };
	DLL_EXPORT Int32 operator&(Byte iw, UInt32 v) { return iw.value &= v; };
	DLL_EXPORT Int32 operator&(Byte iw, Int64 v) { return iw.value &= (int32_t)v.value; };
	DLL_EXPORT Int32 operator&(Byte iw, UInt64 v) { return iw.value &= (int32_t)v.value; };
	DLL_EXPORT Double operator&(Byte iw, Float v) { return iw.value &= (int32_t)v.value; };
	DLL_EXPORT Double operator&(Byte iw, Double v) { return iw.value &= (int32_t)v.value; };

	DLL_EXPORT Int32 operator|(Byte iw, Byte v) { return iw.value |= v; }
	DLL_EXPORT Int32 operator|(Byte iw, Char v) { return iw.value |= v; };
	DLL_EXPORT Int32 operator|(Byte iw, Int16 v) { return iw.value |= v; };
	DLL_EXPORT Int32 operator|(Byte iw, UInt16 v) { return iw.value |= v; };
	DLL_EXPORT Int32 operator|(Byte iw, Int32 v) { return iw.value |= v; };
	DLL_EXPORT Int32 operator|(Byte iw, UInt32 v) { return iw.value |= v; };
	DLL_EXPORT Int32 operator|(Byte iw, Int64 v) { return iw.value |= (int32_t)v.value; };
	DLL_EXPORT Int32 operator|(Byte iw, UInt64 v) { return iw.value |= (int32_t)v.value; };
	DLL_EXPORT Double operator|(Byte iw, Float v) { return iw.value |= (int32_t)v.value; };
	DLL_EXPORT Double operator|(Byte iw, Double v) { return iw.value |= (int32_t)v.value; };

	DLL_EXPORT Int32 operator^(Byte iw, Byte v) { return iw.value ^= v; }
	DLL_EXPORT Int32 operator^(Byte iw, Char v) { return iw.value ^= v; };
	DLL_EXPORT Int32 operator^(Byte iw, Int16 v) { return iw.value ^= v; };
	DLL_EXPORT Int32 operator^(Byte iw, UInt16 v) { return iw.value ^= v; };
	DLL_EXPORT Int32 operator^(Byte iw, Int32 v) { return iw.value ^= v; };
	DLL_EXPORT Int32 operator^(Byte iw, UInt32 v) { return iw.value ^= v; };
	DLL_EXPORT Int32 operator^(Byte iw, Int64 v) { return iw.value ^= (int32_t)v.value; };
	DLL_EXPORT Int32 operator^(Byte iw, UInt64 v) { return iw.value ^= (int32_t)v.value; };
	DLL_EXPORT Double operator^(Byte iw, Float v) { return iw.value ^= (int32_t)v.value; };
	DLL_EXPORT Double operator^(Byte iw, Double v) { return iw.value ^= (int32_t)v.value; };

	DLL_EXPORT Int32 operator<<(Byte iw, Byte v) { return iw.value <<= v; }
	DLL_EXPORT Int32 operator<<(Byte iw, Char v) { return iw.value <<= v; };
	DLL_EXPORT Int32 operator<<(Byte iw, Int16 v) { return iw.value <<= v; };
	DLL_EXPORT Int32 operator<<(Byte iw, UInt16 v) { return iw.value <<= v; };
	DLL_EXPORT Int32 operator<<(Byte iw, Int32 v) { return iw.value <<= v; };
	DLL_EXPORT Int32 operator<<(Byte iw, UInt32 v) { return iw.value <<= v; };
	DLL_EXPORT Int32 operator<<(Byte iw, Int64 v) { return iw.value <<= (int32_t)v.value; };
	DLL_EXPORT Int32 operator<<(Byte iw, UInt64 v) { return iw.value <<= (int32_t)v.value; };
	DLL_EXPORT Double operator<<(Byte iw, Float v) { return iw.value <<= (int32_t)v.value; };
	DLL_EXPORT Double operator<<(Byte iw, Double v) { return iw.value <<= (int32_t)v.value; };

	DLL_EXPORT Int32 operator>>(Byte iw, Byte v) { return iw.value >>= v; }
	DLL_EXPORT Int32 operator>>(Byte iw, Char v) { return iw.value >>= v; };
	DLL_EXPORT Int32 operator>>(Byte iw, Int16 v) { return iw.value >>= v; };
	DLL_EXPORT Int32 operator>>(Byte iw, UInt16 v) { return iw.value >>= v; };
	DLL_EXPORT Int32 operator>>(Byte iw, Int32 v) { return iw.value >>= v; };
	DLL_EXPORT Int32 operator>>(Byte iw, UInt32 v) { return iw.value >>= v; };
	DLL_EXPORT Int32 operator>>(Byte iw, Int64 v) { return iw.value >>= (int32_t)v.value; };
	DLL_EXPORT Int32 operator>>(Byte iw, UInt64 v) { return iw.value >>= (int32_t)v.value; };
	DLL_EXPORT Double operator>>(Byte iw, Float v) { return iw.value >>= (int32_t)v.value; };
	DLL_EXPORT Double operator>>(Byte iw, Double v) { return iw.value >>= (int32_t)v.value; };

	//(Int32 operators
	DLL_EXPORT Int32 operator+(Int32 iw, Char v) { return iw.value += v; };
	DLL_EXPORT Int32 operator+(Int32 iw, Byte v) { return iw.value += v; };
	DLL_EXPORT Int32 operator+(Int32 iw, Int16 v) { return iw.value += v; };
	DLL_EXPORT Int32 operator+(Int32 iw, UInt16 v) { return iw.value += v; };
	DLL_EXPORT Int32 operator+(Int32 iw, Int32 v) { return iw.value += v; };
	DLL_EXPORT Int32 operator+(Int32 iw, UInt32 v) { return iw.value += v; };
	DLL_EXPORT Int32 operator+(Int32 iw, Int64 v) { return iw.value += (int32_t)v.value; };
	DLL_EXPORT Int32 operator+(Int32 iw, UInt64 v) { return iw.value += (int32_t)v.value; };
	DLL_EXPORT Double operator+(Int32 iw, Float v) { return iw.value += (int32_t)v.value; };
	DLL_EXPORT Double operator+(Int32 iw, Double v) { return iw.value += (int32_t)v.value; };

	DLL_EXPORT Int32 operator-(Int32 iw, Char v) { return iw.value -= v; };
	DLL_EXPORT Int32 operator-(Int32 iw, Byte v) { return iw.value -= v; };
	DLL_EXPORT Int32 operator-(Int32 iw, Int16 v) { return iw.value -= v; };
	DLL_EXPORT Int32 operator-(Int32 iw, UInt16 v) { return iw.value -= v; };
	DLL_EXPORT Int32 operator-(Int32 iw, Int32 v) { return iw.value -= v; };
	DLL_EXPORT Int32 operator-(Int32 iw, UInt32 v) { return iw.value -= v; };
	DLL_EXPORT Int32 operator-(Int32 iw, Int64 v) { return iw.value -= (int32_t)v.value; };
	DLL_EXPORT Int32 operator-(Int32 iw, UInt64 v) { return iw.value -= (int32_t)v.value; };
	DLL_EXPORT Double operator-(Int32 iw, Float v) { return iw.value -= (int32_t)v.value; };
	DLL_EXPORT Double operator-(Int32 iw, Double v) { return iw.value -= (int32_t)v.value; };

	DLL_EXPORT Int32 operator*(Int32 iw, int32_t v) { return iw.value *= v; };
	DLL_EXPORT Int32 operator*(Int32 iw, Byte v) { return iw.value *= v; }
	DLL_EXPORT Int32 operator*(Int32 iw, Char v) { return iw.value *= v; };
	DLL_EXPORT Int32 operator*(Int32 iw, Int16 v) { return iw.value *= v; };
	DLL_EXPORT Int32 operator*(Int32 iw, UInt16 v) { return iw.value *= v; };
	DLL_EXPORT Int32 operator*(Int32 iw, Int32 v) { return iw.value *= v; };
	DLL_EXPORT Int32 operator*(Int32 iw, UInt32 v) { return iw.value *= v; };
	DLL_EXPORT Int32 operator*(Int32 iw, Int64 v) { return iw.value *= (int32_t)v.value; };
	DLL_EXPORT Int32 operator*(Int32 iw, UInt64 v) { return iw.value *= (int32_t)v.value; };
	DLL_EXPORT Double operator*(Int32 iw, Float v) { return iw.value *= (int32_t)v.value; };
	DLL_EXPORT Double operator*(Int32 iw, Double v) { return iw.value *= (int32_t)v.value; };

	DLL_EXPORT Int32 operator/(Int32 iw, Byte v) { return iw.value /= v; }
	DLL_EXPORT Int32 operator/(Int32 iw, Char v) { return iw.value /= v; };
	DLL_EXPORT Int32 operator/(Int32 iw, Int16 v) { return iw.value /= v; };
	DLL_EXPORT Int32 operator/(Int32 iw, UInt16 v) { return iw.value /= v; };
	DLL_EXPORT Int32 operator/(Int32 iw, Int32 v) { return iw.value /= v; };
	DLL_EXPORT Int32 operator/(Int32 iw, UInt32 v) { return iw.value /= v; };
	DLL_EXPORT Int32 operator/(Int32 iw, Int64 v) { return iw.value /= (int32_t)v.value; };
	DLL_EXPORT Int32 operator/(Int32 iw, UInt64 v) { return iw.value /= (int32_t)v.value; };
	DLL_EXPORT Double operator/(Int32 iw, Float v) { return iw.value /= (int32_t)v.value; };
	DLL_EXPORT Double operator/(Int32 iw, Double v) { return iw.value /= (int32_t)v.value; };

	DLL_EXPORT Int32 operator%(Int32 iw, Byte v) { return iw.value %= v; }
	DLL_EXPORT Int32 operator%(Int32 iw, Char v) { return iw.value %= v; };
	DLL_EXPORT Int32 operator%(Int32 iw, Int16 v) { return iw.value %= v; };
	DLL_EXPORT Int32 operator%(Int32 iw, UInt16 v) { return iw.value %= v; };
	DLL_EXPORT Int32 operator%(Int32 iw, Int32 v) { return iw.value %= v; };
	DLL_EXPORT Int32 operator%(Int32 iw, UInt32 v) { return iw.value %= v; };
	DLL_EXPORT Int32 operator%(Int32 iw, Int64 v) { return iw.value %= (int32_t)v.value; };
	DLL_EXPORT Int32 operator%(Int32 iw, UInt64 v) { return iw.value %= (int32_t)v.value; };
	DLL_EXPORT Double operator%(Int32 iw, Float v) { return iw.value %= (int32_t)v.value; };
	DLL_EXPORT Double operator%(Int32 iw, Double v) { return iw.value %= (int32_t)v.value; };

	DLL_EXPORT Int32 operator&(Int32 iw, Byte v) { return iw.value &= v; }
	DLL_EXPORT Int32 operator&(Int32 iw, Char v) { return iw.value &= v; };
	DLL_EXPORT Int32 operator&(Int32 iw, Int16 v) { return iw.value &= v; };
	DLL_EXPORT Int32 operator&(Int32 iw, UInt16 v) { return iw.value &= v; };
	DLL_EXPORT Int32 operator&(Int32 iw, Int32 v) { return iw.value &= v; };
	DLL_EXPORT Int32 operator&(Int32 iw, UInt32 v) { return iw.value &= v; };
	DLL_EXPORT Int32 operator&(Int32 iw, Int64 v) { return iw.value &= (int32_t)v.value; };
	DLL_EXPORT Int32 operator&(Int32 iw, UInt64 v) { return iw.value &= (int32_t)v.value; };
	DLL_EXPORT Double operator&(Int32 iw, Float v) { return iw.value &= (int32_t)v.value; };
	DLL_EXPORT Double operator&(Int32 iw, Double v) { return iw.value &= (int32_t)v.value; };

	DLL_EXPORT Int32 operator|(Int32 iw, Byte v) { return iw.value |= v; }
	DLL_EXPORT Int32 operator|(Int32 iw, Char v) { return iw.value |= v; };
	DLL_EXPORT Int32 operator|(Int32 iw, Int16 v) { return iw.value |= v; };
	DLL_EXPORT Int32 operator|(Int32 iw, UInt16 v) { return iw.value |= v; };
	DLL_EXPORT Int32 operator|(Int32 iw, Int32 v) { return iw.value |= v; };
	DLL_EXPORT Int32 operator|(Int32 iw, UInt32 v) { return iw.value |= v; };
	DLL_EXPORT Int32 operator|(Int32 iw, Int64 v) { return iw.value |= (int32_t)v.value; };
	DLL_EXPORT Int32 operator|(Int32 iw, UInt64 v) { return iw.value |= (int32_t)v.value; };
	DLL_EXPORT Double operator|(Int32 iw, Float v) { return iw.value |= (int32_t)v.value; };
	DLL_EXPORT Double operator|(Int32 iw, Double v) { return iw.value |= (int32_t)v.value; };

	DLL_EXPORT Int32 operator^(Int32 iw, Byte v) { return iw.value ^= v; }
	DLL_EXPORT Int32 operator^(Int32 iw, Char v) { return iw.value ^= v; };
	DLL_EXPORT Int32 operator^(Int32 iw, Int16 v) { return iw.value ^= v; };
	DLL_EXPORT Int32 operator^(Int32 iw, UInt16 v) { return iw.value ^= v; };
	DLL_EXPORT Int32 operator^(Int32 iw, Int32 v) { return iw.value ^= v; };
	DLL_EXPORT Int32 operator^(Int32 iw, UInt32 v) { return iw.value ^= v; };
	DLL_EXPORT Int32 operator^(Int32 iw, Int64 v) { return iw.value ^= (int32_t)v.value; };
	DLL_EXPORT Int32 operator^(Int32 iw, UInt64 v) { return iw.value ^= (int32_t)v.value; };
	DLL_EXPORT Double operator^(Int32 iw, Float v) { return iw.value ^= (int32_t)v.value; };
	DLL_EXPORT Double operator^(Int32 iw, Double v) { return iw.value ^= (int32_t)v.value; };

	DLL_EXPORT Int32 operator<<(Int32 iw, Byte v) { return iw.value <<= v; }
	DLL_EXPORT Int32 operator<<(Int32 iw, Char v) { return iw.value <<= v; };
	DLL_EXPORT Int32 operator<<(Int32 iw, Int16 v) { return iw.value <<= v; };
	DLL_EXPORT Int32 operator<<(Int32 iw, UInt16 v) { return iw.value <<= v; };
	DLL_EXPORT Int32 operator<<(Int32 iw, Int32 v) { return iw.value <<= v; };
	DLL_EXPORT Int32 operator<<(Int32 iw, UInt32 v) { return iw.value <<= v; };
	DLL_EXPORT Int32 operator<<(Int32 iw, Int64 v) { return iw.value <<= (int32_t)v.value; };
	DLL_EXPORT Int32 operator<<(Int32 iw, UInt64 v) { return iw.value <<= (int32_t)v.value; };
	DLL_EXPORT Double operator<<(Int32 iw, Float v) { return iw.value <<= (int32_t)v.value; };
	DLL_EXPORT Double operator<<(Int32 iw, Double v) { return iw.value <<= (int32_t)v.value; };

	DLL_EXPORT Int32 operator>>(Int32 iw, Byte v) { return iw.value >>= v; }
	DLL_EXPORT Int32 operator>>(Int32 iw, Char v) { return iw.value >>= v; };
	DLL_EXPORT Int32 operator>>(Int32 iw, Int16 v) { return iw.value >>= v; };
	DLL_EXPORT Int32 operator>>(Int32 iw, UInt16 v) { return iw.value >>= v; };
	DLL_EXPORT Int32 operator>>(Int32 iw, Int32 v) { return iw.value >>= v; };
	DLL_EXPORT Int32 operator>>(Int32 iw, UInt32 v) { return iw.value >>= v; };
	DLL_EXPORT Int32 operator>>(Int32 iw, Int64 v) { return iw.value >>= (int32_t)v.value; };
	DLL_EXPORT Int32 operator>>(Int32 iw, UInt64 v) { return iw.value >>= (int32_t)v.value; };
	DLL_EXPORT Double operator>>(Int32 iw, Float v) { return iw.value >>= (int32_t)v.value; };
	DLL_EXPORT Double operator>>(Int32 iw, Double v) { return iw.value >>= (int32_t)v.value; };
}
