#pragma once
#include "CaBlockProtos.h"
namespace MiniTest_NS
{
	class ProgramRaw : public ObjectRaw
	{
		public:
		ProgramRaw();
		static Int32 Main(PointerType<ArrayRaw<String>> x_arvs);
	};
	class AbstractRaw : public ObjectRaw
	{
		public:
		Int32 x_data1;
		Int32 x_data2;
		AbstractRaw(Int32 x_i,Int32 x_j);
		virtual Int32 MustImplement() = 0
;
		virtual Int32 MustImplement(Int32 x_i) = 0
;
		virtual Int32 MustImplement(Int64 x_i) = 0
;
		Int32 DidImplement();
	};
	class TestAbstractRaw : public AbstractRaw
	{
		public:
		TestAbstractRaw();
		Int32 MustImplement();
		Int32 MustImplement(Int32 x_i);
		Int32 MustImplement(Int64 x_i);
		String ToString();
	};
}
