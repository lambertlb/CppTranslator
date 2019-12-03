#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	class ObjectRaw;
	class StringRaw;
	template<class T>
	class  ValueType {
		T value;
	public:
		ValueType() :value() {}
		ValueType(T v) :value(v) {}
		operator T() const { return value; }

		//modifiers
		ValueType& operator=(T v) { value = v; return *this; }
		ValueType& operator+=(T v) { value += v; return *this; }
		ValueType& operator-=(T v) { value -= v; return *this; }
		ValueType& operator*=(T v) { value *= value; return *this; }
		ValueType& operator/=(T v) { value /= value; return *this; }
		ValueType& operator%=(T v) { value %= value; return *this; }
		ValueType& operator++() { ++value; return *this; }
		ValueType& operator--() { --value; return *this; }
		ValueType operator++(int) { return ValueType(value++); }
		ValueType operator--(int) { return ValueType(value--); }
		ValueType& operator&=(T v) { value &= v; return *this; }
		ValueType& operator|=(T v) { value |= v; return *this; }
		ValueType& operator^=(T v) { value ^= v; return *this; }
		ValueType& operator<<=(T v) { value <<= v; return *this; }
		ValueType& operator>>=(T v) { value >>= v; return *this; }

		//accessors
		ValueType operator+() const { return ValueType(+value); }
		ValueType operator-() const { return ValueType(-value); }
		ValueType operator!() const { return ValueType(!value); }
		ValueType operator~() const { return ValueType(~value); }

		//friends
		friend ValueType operator+(ValueType iw, ValueType v) { return iw += v; }
		friend ValueType operator+(ValueType iw, T v) { return iw += v; }
		friend ValueType operator+(T v, ValueType iw) { return ValueType(v) += iw; }
		friend ValueType operator-(ValueType iw, ValueType v) { return iw -= v; }
		friend ValueType operator-(ValueType iw, T v) { return iw -= v; }
		friend ValueType operator-(T v, ValueType iw) { return ValueType(v) -= iw; }
		friend ValueType operator*(ValueType iw, ValueType v) { return iw *= v; }
		friend ValueType operator*(ValueType iw, T v) { return iw *= v; }
		friend ValueType operator*(T v, ValueType iw) { return ValueType(v) *= iw; }
		friend ValueType operator/(ValueType iw, ValueType v) { return iw /= v; }
		friend ValueType operator/(ValueType iw, T v) { return iw /= v; }
		friend ValueType operator/(T v, ValueType iw) { return ValueType(v) /= iw; }
		friend ValueType operator%(ValueType iw, ValueType v) { return iw %= v; }
		friend ValueType operator%(ValueType iw, T v) { return iw %= v; }
		friend ValueType operator%(T v, ValueType iw) { return ValueType(v) %= iw; }
		friend ValueType operator&(ValueType iw, ValueType v) { return iw &= v; }
		friend ValueType operator&(ValueType iw, T v) { return iw &= v; }
		friend ValueType operator&(T v, ValueType iw) { return ValueType(v) &= iw; }
		friend ValueType operator|(ValueType iw, ValueType v) { return iw |= v; }
		friend ValueType operator|(ValueType iw, T v) { return iw |= v; }
		friend ValueType operator|(T v, ValueType iw) { return ValueType(v) |= iw; }
		friend ValueType operator^(ValueType iw, ValueType v) { return iw ^= v; }
		friend ValueType operator^(ValueType iw, T v) { return iw ^= v; }
		friend ValueType operator^(T v, ValueType iw) { return ValueType(v) ^= iw; }
		friend ValueType operator<<(ValueType iw, ValueType v) { return iw <<= v; }
		friend ValueType operator<<(ValueType iw, T v) { return iw <<= v; }
		friend ValueType operator<<(T v, ValueType iw) { return ValueType(v) <<= iw; }
		friend ValueType operator>>(ValueType iw, ValueType v) { return iw >>= v; }
		friend ValueType operator>>(ValueType iw, T v) { return iw >>= v; }
		friend ValueType operator>>(T v, ValueType iw) { return ValueType(v) >>= iw; }

		// .Net functions
		bool	Equals(T valueToCOmpare) {
			return(valueToCOmpare == value);
		}
		bool	Equals(ObjectRaw* valueToCOmpare) {
			return(true);
		}
		ValueType <int32_t>	CompareTo(int32_t valueToCOmpare) {
			return(0);
		}
		ValueType <int32_t>	CompareTo(ObjectRaw* valueToCOmpare) {
			return(0);
		}
		//ValueType <int32_t>	CompareTo(ObjectRaw& valueToCOmpare) {
		//	return(0);
		//}
		StringRaw* ToString() {
			return(nullptr);
		}
		static StringRaw* FalseString;
		static StringRaw* TrueString;
	};

	// .Net types to C++ value type
	typedef	ValueType<bool>			Boolean;
	typedef	ValueType <int8_t>		Char;
	typedef	ValueType <uint8_t>		Byte;
	typedef	ValueType <int8_t>		SByte;
	typedef	ValueType <int16_t>		Int16;
	typedef	ValueType <uint16_t>	UInt16;
	typedef	ValueType <int32_t>		Int32;
	typedef	ValueType <uint32_t>	UInt32;
	typedef	ValueType <int64_t>		Int64;
	typedef	ValueType <uint64_t>	UInt64;
	typedef	ValueType<float>		Single;
	typedef	ValueType<double>		Double;

}
