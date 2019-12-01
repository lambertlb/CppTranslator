#pragma once
#ifdef WIN32
#ifdef	BuildDLL
#define	DLL_EXPORT	__declspec( dllexport )
#else
#define	DLL_EXPORT	__declspec( dllimport )
#endif
#else
#define	DLL_EXPORT	
#endif
#include <stdint.h>

#include "ValueType.h"
#include "PointerType.h"
#include "DateTime.h"
#include "TimeSpan.h"
#include "ObjectRaw.h"
#include "BoxTypeRaw.h"
#include "ArrayRaw.h"
#include "StringRaw.h"
#include "StringBuilderRaw.h"
