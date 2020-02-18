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
DLL_PLATFORMSUPPORT_EXPORTS void* CDECL my_operator_new_replacement(size_t size);
DLL_PLATFORMSUPPORT_EXPORTS void CDECL my_operator_delete_replacement(void* memory);

inline void* operator new  (size_t size) {return(my_operator_new_replacement(size));}
inline void* operator new[]  (size_t size) { return(my_operator_new_replacement(size)); }
inline void	operator	delete(void* memory) { my_operator_delete_replacement(memory); }
inline void	operator	delete[](void* memory) { my_operator_delete_replacement(memory); }
