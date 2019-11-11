#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	class StringBuilderRaw : public ObjectRaw
	{
	public:
		StringBuilderRaw() {
		}
	private:
		PointerType<ArrayRaw<Char>>	characterData;
	};
	typedef PointerType < StringBuilderRaw > StringBuilder;
}
