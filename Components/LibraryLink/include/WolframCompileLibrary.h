/*************************************************************************
                        Mathematica source file

        Copyright 1986 through 2015 by Wolfram Research Inc.

This material contains trade secrets and may be registered with the
U.S. Copyright Office as an unpublished work, pursuant to Title 17,
U.S. Code, Section 408.  Unauthorized copying, adaptation, distribution
or display is prohibited.

$Id$

*************************************************************************/

/*
  WARNING,  the definitions in this file are not guaranteed to work from 
  one version of Mathematica to another.  Do not use these functions directly.
*/

#ifndef WOLFRAMCOMPILELIBRARY_H
#define WOLFRAMCOMPILELIBRARY_H

#define WolframCompileLibraryVersion 1

#if !(defined(MATHEMATICA_KERNEL) || defined(MATHEMATICA_RUNTIME))

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

struct st_MDataArray {
	/* First come the fields that must exactly match the TensorProperty struct fields */
	mreal prec;
	mint *dims;
	mint rank;
	type_t tensor_property_type;
	UBIT32 flags;
	type_t data_type;
	mint nelems; /* Number of elements (should be product of dimensions) */
	void *data; /* Pointer to allocated data */
};

#define MTensor_getDimensionsMacro(mt)		((mt)->dims)

#define MTensor_getIntegerDataMacro(mt)		((mint *) ((mt)->data))
#define MTensor_getRealDataMacro(mt)		((mreal *) ((mt)->data))
#define MTensor_getComplexDataMacro(mt)		((mcomplex *) ((mt)->data))

#define MTensor_getFlattenedLengthMacro(mt) ((mt)->nelems)

#ifdef __cplusplus
}
#endif

#endif

#ifdef __cplusplus
extern "C" {
#endif

typedef struct M_TENSOR_INITIALIZATION_DATA_STRUCT
{
	MTensor *tensors;
	mint n;
	int in_use;
} *MTensorInitializationData;

#ifndef _MATHLINK_H
typedef struct MLINK_STRUCT* MLINK;
#endif

#define MTensorInitializationData_getTensor(data, i) (&((data)->tensors[(i)]))

typedef struct st_WolframRuntimeData* WolframRuntimeData;

typedef int (*LibraryFunctionPointer)(WolframLibraryData, mint, MArgument *, MArgument);
typedef mint (*UnaryMathFunctionPointer)(void *, const void *, const mint, const mint *, const unsigned int);
typedef mint (*BinaryMathFunctionPointer)(void *, const void *, const void *, const mint, const mint *, const unsigned int);

typedef struct st_WolframCompileLibrary_Functions
	{
	mint VersionNumber;
	MTensorInitializationData (*GetInitializedMTensors)(struct st_WolframLibraryData*, mint);
	void (*ReleaseInitializedMTensors)(MTensorInitializationData);
	void (*WolframLibraryData_cleanUp)(struct st_WolframLibraryData*, int);
	MTensor (*MTensor_init)( void);
	int (*MTensor_allocate)(MTensor *, int, mint, mint*);
	int (*MTensor_copy)(MTensor *, MTensor);
	int (*MTensor_copyUnique)(MTensor *, MTensor);
	int (*MTensor_insertMTensor)( MTensor, MTensor, mint *);
	int (*MTensor_getMTensorInitialized)(MTensor *, MTensor, mint *, mint);
	int (*MTensor_getPart)(MTensor *, MTensor, mint, int *, void **);
	int (*MTensor_setPart)(MTensor *, MTensor, mint, int *, void **);
	UnaryMathFunctionPointer (*getUnaryMathFunction)(int, int);
	int (*Math_T_T)(int, const unsigned int, MTensor, int, MTensor *);
	int (*Math_V_V)(int, const unsigned int, int, void *, int, void *);
	BinaryMathFunctionPointer (*getBinaryMathFunction)(int, int, int);
	int (*Math_TT_T)(int, const unsigned int, MTensor, MTensor, int, MTensor *);
	int (*Math_VV_V)(int, const unsigned int, int, void *, int, void *, int, void *);
	mbool (*Compare_R)(int, mreal, mint, mreal *);
	int (*Compare_C)(int, mreal, mint, mcomplex *, mbool *);
	void *(*getExpressionFunctionPointer)(struct st_WolframLibraryData*, const char *);
	int (*evaluateFunctionExpression)(struct st_WolframLibraryData*, void *, mint, mint, mint, int *, void **, int, mint, void *);
	void **(*getArgumentSpace)(struct st_WolframLibraryData*, mint);
	/*
	TODO these two definitions look strange.
	*/
	LibraryFunctionPointer (*getLibraryFunctionPointer)(char *, char *);
	LibraryFunctionPointer (*getFunctionCallPointer)(const char *);
	mbool (*checkFloatingPointException)(void *, int, const unsigned int);
	MTensor (*getRankZeroMTensor)(void *, int, mint);
	int (*MTensor_fillFromMTensor)(MTensor, MTensor *);
	}* WolframCompileLibrary_Functions;

#ifdef __cplusplus
}
#endif

#endif

