#include "PlatformSupport.h"
#include <cstdio>
#include <cstring>
DLL_PLATFORMSUPPORT_EXPORTS void* CDECL my_operator_new_replacement(size_t size)
{
	void* memory = malloc(size);
	if (memory != nullptr)
		memset(memory, 0, size);
	return(memory);
}
DLL_PLATFORMSUPPORT_EXPORTS void CDECL my_operator_delete_replacement(void* memory)
{
	if (memory != nullptr)
		free(memory);
}
