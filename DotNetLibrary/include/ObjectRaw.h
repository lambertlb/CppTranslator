#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	class ObjectRaw
	{
	public:
		ObjectRaw() {}
		virtual				~ObjectRaw() {};
		static	Boolean		Equals(PointerType<ObjectRaw> obj1, PointerType<ObjectRaw> obj2) { return(true); }
		virtual Boolean		Equals(PointerType<ObjectRaw> object) { return(true); }
		virtual	String		ToString() { return(nullptr); }
		virtual void		Send(PointerType<StringRaw> message) {
		}
		virtual Boolean		get_AsBoolean() {
			return(true);
		}
		virtual Char		get_AsChar() {
			return(0);
		}
		virtual Byte		get_AsByte() {
			return(0);
		}
		virtual SByte		get_AsSByte() {
			return(0);
		}
		virtual Int16		get_AsInt16() {
			return(0);
		}
		virtual UInt16		get_AsUInt16() {
			return(0);
		}
		virtual Int32		get_AsInt32() {
			return(0);
		}
		virtual UInt32		get_AsUInt32() {
			return(0);
		}
		virtual Int64		get_AsInt64() {
			return(0);
		}
		virtual UInt64		get_AsUInt64() {
			return(0);
		}
		virtual Single		get_AsSingle() {
			return(0);
		}
		virtual Double		get_AsDouble() {
			return(0);
		}
	};
	class BlockBaseRaw : public ObjectRaw
	{
	public:
	};
	typedef	PointerType<ObjectRaw>	Object;
	typedef PointerType<BlockBaseRaw> BlockBase;
}
