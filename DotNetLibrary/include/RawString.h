#pragma once
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	class RawString : public RawObject
	{
	public:
		RawString(const PointerType<RawArray<Char>> string) {
			characterData = string;
		}
	private:
		PointerType<RawArray<Char>>	characterData;
	};
	typedef PointerType<RawString>	String;
}
