#pragma once
#pragma once
#include "DotnetTypes.h"
using namespace DotnetLibrary;

namespace DotnetLibrary
{
	template<class T>
	class BoxTypeRaw : public ObjectRaw {
		T value;
	public:
		BoxTypeRaw() :value() {}
		BoxTypeRaw(T v) :value(v) {}
		operator T() const { return value; }
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

	// .Net types to C++ box type
	typedef	BoxTypeRaw<Boolean>		BooleanBox;
	typedef	BoxTypeRaw <Char>		CharBox;
	typedef	BoxTypeRaw <Byte>		ByteBox;
	typedef	BoxTypeRaw <SByte>		SByteBox;
	typedef	BoxTypeRaw <Int16>		Int16Box;
	typedef	BoxTypeRaw <UInt16>		UInt16Box;
	typedef	BoxTypeRaw <Int32>		Int32Box;
	typedef	BoxTypeRaw <UInt32>		UInt32Box;
	typedef	BoxTypeRaw <Int64>		Int64Box;
	typedef	BoxTypeRaw <UInt64>		UInt64Box;
	typedef	BoxTypeRaw<Single>		SingleBox;
	typedef	BoxTypeRaw<Double>		DoubleBox;
	typedef	BoxTypeRaw<TimeSpan>	TimeSpanBox;
	typedef	BoxTypeRaw<DateTime>	DateTimeBox;
}
