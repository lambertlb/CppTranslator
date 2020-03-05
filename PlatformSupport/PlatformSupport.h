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
#pragma once
#ifdef WIN32
#pragma warning( disable : 4244 )
#pragma warning( disable : 4018 )
#pragma warning( disable : 4102 )
#pragma warning( disable : 4101 )
#pragma warning( disable : 26812 )
#pragma warning( disable : 26495 )
#pragma warning( disable : 4595 )
#define		CDECL __cdecl
#ifdef	PLATFORMSUPPORT_EXPORTS
#define	DLL_PLATFORMSUPPORT_EXPORTS	__declspec( dllexport )
#else
#define	DLL_PLATFORMSUPPORT_EXPORTS	__declspec( dllimport )
#endif
#else
#define	DLL_PLATFORMSUPPORT_EXPORTS	
#define		CDECL
#endif
#include <stdint.h>
#include <cstdio>
#include <new>
/*!
 * Align a value to the a certain size.
 * For example double. 
 */
#define	Align(a,b) ((a + (b - 1)) & ~(b - 1))

/*!
 * Platform Replacement for new operator
 * The current implementation is not thread safe.
 * It is meant to recycle the memory between executions.
 * This means there can be no persistent items between executions.
 * All persistent items must be handled in the library support data access area.
 * 
 * \param size required
 * \return pointer to memory or nullptr
 */
DLL_PLATFORMSUPPORT_EXPORTS void* CDECL my_operator_new_replacement(size_t size);

/*!
 * free up a piece of memory.
 * Currently this does nothing.
 * 
 * \param memory
 */
DLL_PLATFORMSUPPORT_EXPORTS void CDECL my_operator_delete_replacement(void* memory);

inline void* operator new  (size_t size) {return(my_operator_new_replacement(size));}
inline void* operator new[]  (size_t size) { return(my_operator_new_replacement(size)); }
inline void	operator	delete(void* memory) { my_operator_delete_replacement(memory); }
inline void	operator	delete[](void* memory) { my_operator_delete_replacement(memory); }

/*!
 * Handle platform setup tasks before start of execution.
 */
DLL_PLATFORMSUPPORT_EXPORTS void	PlatformSetup();
/*!
 * Handle memory setup tasks before start of execution.
 */
void	PlatformMemorySetup();
