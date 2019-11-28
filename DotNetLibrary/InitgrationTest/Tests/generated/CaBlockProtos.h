#pragma once
#include "DotnetTypes.h"
using namespace DotnetLibrary;

namespace MiniTest_NS
{
	class ProgramRaw;
	typedef PointerType<ProgramRaw>	Program;
	enum TestNameEnu
	{
		x_friend_TestNameEnu,
		x_enemy_TestNameEnu
	};
	class typedefRaw;
	typedef PointerType<typedefRaw>	x_typedef;
}
