#pragma once
#include "DotnetTypes.h"

void*	operator	new (size_t size);
void	operator	delete(void*);
namespace DotnetLibrary
{
	class DLL_EXPORT Object
	{
	public:
		Object() {}
		virtual				~Object() {};
		static	Boolean		Equals(Object* obj1, Object* obj2);
		virtual Boolean		Equals(Object* object);
		static Boolean		IsPrimativeType(DataType type);
		virtual	String*		ToString();
		virtual	Int32		FormatString(Char* where, const Int32 whereSize);
		virtual void		Send(String* message);
		virtual DataType	GetRawDataType() { return(ObjectType); }
		virtual Boolean		get_AsBoolean();
		virtual Char		get_AsChar();
		virtual Byte		get_AsByte();
		virtual SByte		get_AsSByte();
		virtual Int16		get_AsInt16();
		virtual UInt16		get_AsUInt16();
		virtual Int32		get_AsInt32();
		virtual UInt32		get_AsUInt32();
		virtual Int64		get_AsInt64();
		virtual UInt64		get_AsUInt64();
		virtual Single		get_AsSingle();
		virtual Double		get_AsDouble();
		virtual TimeSpan	get_AsTimeSpan();
		virtual DateTime	get_AsDateTime();
	};
	class BlockBase : public Object
	{
	public:
	};

}
