#pragma once
#include "DotnetTypes.h"
#include <cstdio>

namespace DotnetLibrary
{
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
