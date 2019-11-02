#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	template< class T >
	struct PointerType
	{
	public:
		PointerType(T* val)
		{
			value = val;
		}
		PointerType(const PointerType<T>& val)
		{
			value = val.value;
		}
		PointerType(T& val)
		{
			value = &val;
		}
		PointerType()
		{
			value = 0;
		}
		operator T& ()
		{
			return *value;
		}
		T& operator=(const T a)
		{
			*value = a;
			return *value;
		}
		const T* operator &() const {
			return value;
		}
		T* operator->()
		{
			return value;
		}
		void Assign(T& v)
		{
			value = &v;
		}
		void Assign(T* v)
		{
			value = v;
		}

	private:
		T* value;
	};
}
