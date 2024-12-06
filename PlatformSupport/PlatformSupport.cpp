// Copyright (c) 2019 LLambert
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this
// software and associated documentation files (the "Software"), to deal in the Software
// without restriction, including without limitation the rights to use, copy, modify, merge,
// publish, distribute, sub-license, and/or sell copies of the Software, and to permit persons
// to whom the Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or
// substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
// INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
// PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
// FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
// OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
#include "PlatformSupport.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef MEMORY_SIZE
#define		MEMORY_SIZE 32767
#endif // !MEMORY_SIZE

uint32_t memorySize;
uint32_t memoryUsed;
char* currentMemory = nullptr;
char* memory = nullptr;

DLL_PLATFORMSUPPORT_EXPORTS void* CDECL my_operator_new_replacement(size_t size)
{
	// Use malloc if not setup such as when unit tests run.
	if (memory == nullptr) {
		void* mem = malloc(size);
		memset(mem, 0, size);
		return(mem);
	}
	uint32_t required = (uint32_t)size;
	required = Align(required, sizeof(double));
	if (memoryUsed + required > memorySize)
		return(nullptr);
	memoryUsed += required;
	char* ret = currentMemory;
	currentMemory += required;
	memset(ret, 0, size);
	return(ret);
}
DLL_PLATFORMSUPPORT_EXPORTS void CDECL my_operator_delete_replacement(void* mem)
{
	if (memory == nullptr)
		free(mem);
}

DLL_PLATFORMSUPPORT_EXPORTS void PlatformSetup()
{
	PlatformMemorySetup();
}

void PlatformMemorySetup()
{
	if (memory == nullptr) {
		memory = (char*)malloc(MEMORY_SIZE);
		memorySize = MEMORY_SIZE;
	}
	memoryUsed = 0;
	currentMemory = memory;
}
