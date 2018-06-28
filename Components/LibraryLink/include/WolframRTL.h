/*************************************************************************
                        Mathematica source file

        Copyright 1986 through 2015 by Wolfram Research Inc.

This material contains trade secrets and may be registered with the
U.S. Copyright Office as an unpublished work, pursuant to Title 17,
U.S. Code, Section 408.  Unauthorized copying, adaptation, distribution
or display is prohibited.

$Id$

*************************************************************************/

#ifndef WOLFRAMRTL_H
#define WOLFRAMRTL_H

#include "WolframLibrary.h"
#include "WolframCompileLibrary.h"

EXTERN_C RTL_DLL_EXPORT void WolframRTL_initialize(mint version);
EXTERN_C RTL_DLL_EXPORT WolframLibraryData WolframLibraryData_new(mint version);
EXTERN_C RTL_DLL_EXPORT void WolframLibraryData_free(WolframLibraryData data);

EXTERN_C RTL_DLL_EXPORT void *Malloc_fun(size_t);                               
EXTERN_C RTL_DLL_EXPORT void *MallocAlign16_fun(size_t);
EXTERN_C RTL_DLL_EXPORT void *MallocAlign_mreal_fun(size_t);
EXTERN_C RTL_DLL_EXPORT void *Realloc_fun(void *, size_t);                      
EXTERN_C RTL_DLL_EXPORT void *ReallocAlign_mreal_fun(void *, size_t);
EXTERN_C RTL_DLL_EXPORT void *Calloc_fun(size_t, size_t);                       
EXTERN_C RTL_DLL_EXPORT void *CallocAlign16_fun(size_t, size_t);
EXTERN_C RTL_DLL_EXPORT void *CallocAlign_mreal_fun(size_t, size_t);
EXTERN_C RTL_DLL_EXPORT void Free_fun(void *);

#endif
