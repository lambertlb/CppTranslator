#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	class RawStringBuilder : public RawObject
	{
	public:
		RawStringBuilder() {
		}
	private:
		PointerType<RawArray<Char>>	characterData;
	};
	typedef PointerType < RawStringBuilder > StringBuilder;
}
