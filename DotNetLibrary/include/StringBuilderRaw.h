#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	class StringBuilderRaw : public ObjectRaw
	{
	public:
		StringBuilderRaw() {
		}
		StringBuilderRaw& Append(Byte v) { return(*this); }
		StringBuilderRaw& Insert(Int32 index, Byte v) { return(*this); }
	private:
		PointerType<ArrayRaw<Char>>	characterData;
	};
	typedef PointerType < StringBuilderRaw > StringBuilder;
}
