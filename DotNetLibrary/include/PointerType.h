#pragma once

namespace DotnetLibrary
{
	template< typename T >
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
		T* Assign(T& v)
		{
			value = &v;
			return value;
		}
		T* Assign(T* v)
		{
			value = v;
			return value;
		}
	private:
		T* value;
	};
	class StringRaw;
	typedef PointerType<StringRaw> String;
}
