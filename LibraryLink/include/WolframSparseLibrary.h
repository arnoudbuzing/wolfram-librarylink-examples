/*************************************************************************
                        Mathematica source file

        Copyright 1986 through 2015 by Wolfram Research Inc.

This material contains trade secrets and may be registered with the
U.S. Copyright Office as an unpublished work, pursuant to Title 17,
U.S. Code, Section 408.  Unauthorized copying, adaptation, distribution
or display is prohibited.

$Id$

*************************************************************************/

#ifndef WOLFRAMSPARSELIBRARY_H
#define WOLFRAMSPARSELIBRARY_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct st_WolframSparseLibrary_Functions
{
	int (*MSparseArray_clone)(MSparseArray, MSparseArray *);
	void (*MSparseArray_free)(MSparseArray);
	void (*MSparseArray_disown)(MSparseArray);
	void (*MSparseArray_disownAll)(MSparseArray);
	mint (*MSparseArray_shareCount)(MSparseArray);
	mint (*MSparseArray_getRank)(MSparseArray);
	mint const * (*MSparseArray_getDimensions)(MSparseArray);
	MTensor *(*MSparseArray_getImplicitValue)(MSparseArray);
	MTensor *(*MSparseArray_getExplicitValues)(MSparseArray);
	MTensor *(*MSparseArray_getRowPointers)(MSparseArray);
	MTensor *(*MSparseArray_getColumnIndices)(MSparseArray);
	int (*MSparseArray_getExplicitPositions)(MSparseArray, MTensor *);
	int (*MSparseArray_resetImplicitValue)(MSparseArray, MTensor, MSparseArray *);
	int (*MSparseArray_toMTensor)(MSparseArray, MTensor *);
	int (*MSparseArray_fromMTensor)(MTensor, MTensor, MSparseArray *);
	int (*MSparseArray_fromExplicitPositions)(MTensor, MTensor, MTensor, MTensor, MSparseArray *);
} *WolframSparseLibrary_Functions;

#ifdef __cplusplus
}
#endif

#endif
