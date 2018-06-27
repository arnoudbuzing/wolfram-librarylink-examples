/*************************************************************************

                           Mathematica source file

		Copyright 1986 through 2015 by Wolfram Research Inc.

This material contains trade secrets and may be registered with the
U.S. Copyright Office as an unpublished work, pursuant to Title 17,
U.S. Code, Section 408.  Unauthorized copying, adaptation, distribution
or display is prohibited.

$Id$

*************************************************************************/

#ifndef WOLFRAM_STREAMS_LIBRARY_H
#define WOLFRAM_STREAMS_LIBRARY_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MSTREAM_TYPEDEF
#define MSTREAM_TYPEDEF
typedef struct st_MInputStream *MInputStream;
typedef struct st_MOutputStream *MOutputStream;
#endif

#ifndef PRECOMPUTED_H
typedef long long int_64;
#endif

enum MStream_StreamUnitSize_t {
	MSTREAM_8BIT = 0, MSTREAM_16BIT};

struct st_MInputStream
{
	char* name;
	char* userSuppliedName; /* name as supplied by user, before path resolution */
	char* expandedName;  /* Absolute file path (if 'name' is a file path) */
	mbool filePathNameQ; /* TRUE iff name and expandedName are file paths */
	mbool hasError;
	mbool messageIssued;
	mbool isClosed;
	void* InternalData;
	void* MSdata;
	void* handlerIdentity;
	struct st_MInputStream* underlyingStream; /* set when this stream is chained */

	mint (*Mfread)( struct st_MInputStream*, void*, size_t);
	int (*Mfseek)( struct st_MInputStream*, int_64 offset);
	int (*Mfeof)( struct st_MInputStream*);
	int_64 (*Mftell)(struct st_MInputStream*);

	char* (*MferrorText)(struct st_MInputStream*);
	void (*Mclearerr)(struct st_MInputStream*);
	int_64 (*Mstreamsize)(struct st_MInputStream*);
	
	void (*MoptionChanges)(struct st_MInputStream*, void* optionsLink);

	mbool (*SeekableQ)(struct st_MInputStream*);
	enum MStream_StreamUnitSize_t (*MstreamUnitSize)(struct st_MInputStream*);
	void (*WaitForInput)(struct st_MInputStream*);

	int (*Mfclose)( struct st_MInputStream*);
};

struct st_MOutputStream
{
	char* name;
	char* userSuppliedName; /* name as supplied by user, before path resolution */
	char* expandedName;  /* Absolute file path (if 'name' is a file path) */
	mbool filePathNameQ; /* TRUE iff name and expandedName are file paths */
	mbool hasError;
	mbool messageIssued;
	mbool isClosed;
	void* InternalData;
	void* MSdata;
	void* handlerIdentity;
	struct st_MOutputStream* underlyingStream; /* set when this stream is chained */

	mint (*Mfwrite)(struct st_MOutputStream*, void*, size_t);
	int (*Mfflush)(struct st_MOutputStream*);
	int_64 (*Mftell)(struct st_MOutputStream*);
	char* (*MferrorText)(struct st_MOutputStream*);
	void (*Mclearerr)(struct st_MOutputStream*);
	int (*Mfclose)(struct st_MOutputStream*);
	void (*MoptionChanges)(struct st_MOutputStream*, void* optionsLink);
	enum MStream_StreamUnitSize_t (*MstreamUnitSize)(struct st_MOutputStream*);
};

#ifdef __cplusplus
}
#endif

#endif
