#include "DotnetTypes.h"
#include <cstdlib>
#include <cstdio>
#include <cwchar>

void* operator new(size_t size)
{
	void* memory = malloc(size);
	if (memory != nullptr)
		memset(memory, 0, size);
	return(memory);
}
void operator delete(void* memory)
{
	if (memory != nullptr)
		free(memory);
}
namespace DotnetLibrary
{
	Boolean Object::Equals(Object* obj1, Object* obj2)
	{
		if (obj1 == obj2)
			return true;
		if (obj1 == nullptr || obj2 == nullptr)
			return false;
		return obj1->Equals(obj2);
	}
	Boolean Object::Equals(Object* object)
	{
		return(this == object);
	}
	Boolean Object::IsPrimativeType(DataType type)
	{
		return(type != ObjectType && type != StringType && type != NullType);
	}
	String* Object::ToString()
	{
		Char	chars[128];
		Int32 length = FormatString(chars, 128);
		chars[length] = 0;
		return(new String(chars, 0, length));
	}
	Int32 Object::FormatString(Char* where, const Int32 whereSize)
	{
		CopyChars(where, whereSize, (Char*)L"Object", 6);
		return(wcslen((Char*)L"Object"));
	}
	void		Object::Send(String* message) {
		printf("%ls\n", message->Address(0));
	}
	Boolean Object::get_AsBoolean()
	{
		throw new InvalidCastException();
	}
	Char Object::get_AsChar()
	{
		throw new InvalidCastException();
	}
	Byte Object::get_AsByte()
	{
		throw new InvalidCastException();
	}
	SByte Object::get_AsSByte()
	{
		throw new InvalidCastException();
	}
	Int16 Object::get_AsInt16()
	{
		throw new InvalidCastException();
	}
	UInt16 Object::get_AsUInt16()
	{
		throw new InvalidCastException();
	}
	Int32 Object::get_AsInt32()
	{
		throw new InvalidCastException();
	}
	UInt32 Object::get_AsUInt32()
	{
		throw new InvalidCastException();
	}
	Int64 Object::get_AsInt64()
	{
		throw new InvalidCastException();
	}
	UInt64 Object::get_AsUInt64()
	{
		throw new InvalidCastException();
	}
	Single Object::get_AsSingle()
	{
		throw new InvalidCastException();
	}
	Double Object::get_AsDouble()
	{
		throw new InvalidCastException();
	}
	TimeSpan Object::get_AsTimeSpan()
	{
		throw new InvalidCastException();
	}
	DateTime Object::get_AsDateTime()
	{
		throw new InvalidCastException();
	}
}
