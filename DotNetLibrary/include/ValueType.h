#pragma once
#include "DotnetTypes.h"
#include <cstddef>
#include <cstring>
#include <typeindex>
#include <typeinfo>

namespace DotnetLibrary
{
	template <typename T, std::size_t traits = 0>
	struct ValueType {
		using wrapped_type = T;

		ValueType(T val = T{})
			: value(val) {
		}
		operator T& () {
			return value;
		}
		operator const T& () const {
			return value;
		}
		T* operator &() {
			return &value;
		}
		const T* operator &() const {
			return &value;
		}
		const T* operator ->() const {
			return &value;
		}
		static std::type_index wrapped_type_index() {
			return typeid(wrapped_type);
		}
		static constexpr std::size_t wrapped_type_traits() {
			return traits;
		}
		T	getValue() {
			return(value);
		}
		T value;
	};
	// .Net types to C++ types
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
