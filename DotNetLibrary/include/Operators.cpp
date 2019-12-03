#pragma once
#include "pch.h"
#include "DotnetTypes.h"

namespace DotnetLibrary
{
	StringRaw* Boolean::FalseString = nullptr;
	StringRaw* Boolean::TrueString = nullptr;

	DLL_EXPORT Int32 operator+(Int32 iw, Byte v) { return iw += v; }
}
