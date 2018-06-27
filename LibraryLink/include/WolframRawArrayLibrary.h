/*************************************************************************
                        Mathematica source file

        Copyright 1986 through 2000 by Wolfram Research Inc.

This material contains trade secrets and may be registered with the
U.S. Copyright Office as an unpublished work, pursuant to Title 17,
U.S. Code, Section 408.  Unauthorized copying, adaptation, distribution
or display is prohibited.

$Id: WolframRawArrayLibrary.h,v  Exp $

*************************************************************************/

#ifndef WOLFRAMLIBRARY_H
#error "WolframLibrary.h needs to be included before WolframRawArrayLibrary.h"
#endif

#ifndef WOLFRAMRAWARRAYLIBRARY_H
#define WOLFRAMRAWARRAYLIBRARY_H

#ifdef __cplusplus
extern "C" {
#endif

enum MRawArray_Data_Type {
	MRawArray_Type_Undef = 0,
	MRawArray_Type_Bit8 = 1,
	MRawArray_Type_Ubit8, 
	MRawArray_Type_Bit16,
	MRawArray_Type_Ubit16,
	MRawArray_Type_Bit32,
	MRawArray_Type_Ubit32,
	MRawArray_Type_Bit64,
	MRawArray_Type_Ubit64,
	MRawArray_Type_Real32,
	MRawArray_Type_Real64,
	MRawArray_Type_Float_Complex,
	MRawArray_Type_Double_Complex
};

typedef enum MRawArray_Data_Type rawarray_t;

typedef struct st_WolframRawArrayLibrary_Functions
{
	int(*MRawArray_new)(rawarray_t, mint, mint const*, MRawArray *);
	void (*MRawArray_free)(MRawArray);
	int(*MRawArray_clone)(MRawArray, MRawArray *);
	void (*MRawArray_disown)(MRawArray);
	void (*MRawArray_disownAll)(MRawArray);
	mint (*MRawArray_shareCount)(MRawArray);
	
	rawarray_t (*MRawArray_getType)( MRawArray);
	mint (*MRawArray_getRank)(MRawArray);
	mint const * (*MRawArray_getDimensions)(MRawArray);
	mint (*MRawArray_getFlattenedLength)(MRawArray);
	void* (*MRawArray_getData)(MRawArray);
	MRawArray (*MRawArray_convertType)(MRawArray, rawarray_t);
} *WolframRawArrayLibrary_Functions;

#ifdef __cplusplus
}
#endif

#endif

