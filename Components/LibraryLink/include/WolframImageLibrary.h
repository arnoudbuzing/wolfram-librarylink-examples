/*************************************************************************
                        Mathematica source file

        Copyright 1986 through 2015 by Wolfram Research Inc.

This material contains trade secrets and may be registered with the
U.S. Copyright Office as an unpublished work, pursuant to Title 17,
U.S. Code, Section 408.  Unauthorized copying, adaptation, distribution
or display is prohibited.

$Id$

*************************************************************************/

#ifndef WOLFRAMLIBRARY_H
#error "WolframLibrary.h needs to be included before WolframImageLibrary.h"
#endif

#ifndef WOLFRAMIMAGELIBRARY_H
#define WOLFRAMIMAGELIBRARY_H

#if !(defined(MATHEMATICA_KERNEL) || defined(MATHEMATICA_RUNTIME))

typedef unsigned char raw_t_bit;
typedef unsigned char raw_t_ubit8;
typedef unsigned short raw_t_ubit16;
typedef float raw_t_real32;
typedef double raw_t_real64;

#endif

#ifdef __cplusplus
extern "C" {
#endif

enum MImage_Data_Type {
	MImage_Type_Undef = -1,
	MImage_Type_Bit,
	MImage_Type_Bit8,
	MImage_Type_Bit16,
	MImage_Type_Real32,
	MImage_Type_Real
};

typedef enum MImage_Data_Type imagedata_t;

enum MImage_CS_Type {
    MImage_CS_Undef = -1,    
    MImage_CS_Gray,
    MImage_CS_RGB,
    MImage_CS_HSB,
    MImage_CS_CMYK,
    MImage_CS_XYZ,
    MImage_CS_LUV,
    MImage_CS_LAB,
	MImage_CS_LCH,
    MImage_CS_Automatic
};

typedef enum MImage_CS_Type colorspace_t;


typedef struct st_WolframImageLibrary_Functions
{
	int (*MImage_new2D)(mint /* width */, mint /* height */, mint /* channels */, imagedata_t /* type */, colorspace_t /* colorSpace */, mbool /* interleaving */, MImage * /* result */);
	int (*MImage_new3D)(mint /* slices */, mint /* width */, mint /* height */, mint /* channels */, imagedata_t /* type */, colorspace_t /* colorSpace */, mbool /* interleaving */, MImage * /* result */);
	int (*MImage_clone)(MImage, MImage *);
	void (*MImage_free)(MImage);
	void (*MImage_disown)(MImage);
	void (*MImage_disownAll)(MImage);
	mint (*MImage_shareCount)(MImage);
	
	imagedata_t (*MImage_getDataType)(MImage);
	mint (*MImage_getRowCount)(MImage);
	mint (*MImage_getColumnCount)(MImage);
	mint (*MImage_getSliceCount)(MImage);
	mint (*MImage_getRank)(MImage);
	mint (*MImage_getChannels)(MImage);
	mbool (*MImage_alphaChannelQ)(MImage);
	mbool (*MImage_interleavedQ)(MImage);
	colorspace_t (*MImage_getColorSpace)(MImage);
	mint (*MImage_getFlattenedLength)(MImage);
	
	int (*MImage_getBit)(MImage /* image */, mint * /* pos */, mint /* channel */, raw_t_bit * /* result */);
	int (*MImage_getByte)(MImage /* image */, mint * /* pos */, mint /* channel */, raw_t_ubit8 * /* result */);
	int (*MImage_getBit16)(MImage /* image */, mint * /* pos */, mint /* channel */, raw_t_ubit16 * /* result */);
	int (*MImage_getReal32)(MImage /* image */, mint * /* pos */, mint /* channel */, raw_t_real32 * /* result */);
	int (*MImage_getReal)(MImage /* image */, mint * /* pos */, mint /* channel */, raw_t_real64 * /* result */);
	
	int (*MImage_setBit)(MImage /* image */, mint * /* pos */, mint /* channel */, raw_t_bit /* value */);
	int (*MImage_setByte)(MImage /* image */, mint * /* pos */, mint /* channel */, raw_t_ubit8 /* value */);
	int (*MImage_setBit16)(MImage /* image */, mint * /* pos */, mint /* channel */, raw_t_ubit16 /* value */);
	int (*MImage_setReal32)(MImage /* image */, mint * /* pos */, mint /* channel */, raw_t_real32 /* value */);
	int (*MImage_setReal)(MImage /* image */, mint * /* pos */, mint /* channel */, raw_t_real64 /* value */);
	
	void *(*MImage_getRawData)(MImage);
	raw_t_bit* (*MImage_getBitData)(MImage);
	raw_t_ubit8* (*MImage_getByteData)(MImage);
	raw_t_ubit16* (*MImage_getBit16Data)(MImage);
	raw_t_real32* (*MImage_getReal32Data)(MImage);
	raw_t_real64* (*MImage_getRealData)(MImage);

	MImage (*MImage_convertType)(MImage, imagedata_t /* type */, mbool /* interleaving */);


} *WolframImageLibrary_Functions;

#ifdef __cplusplus
}
#endif

#endif

