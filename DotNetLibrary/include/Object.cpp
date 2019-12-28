#pragma once
#include "DotnetTypes.h"
#include <cstdio>

namespace DotnetLibrary
{
	void		Object::Send(String* message) {
		printf("%ls\n", message->Address(0));
	}
}
