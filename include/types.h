/*************************************************************************
                        Mathematica source file

        Copyright 1986 through 2000 by Wolfram Research Inc.

This material contains trade secrets and may be registered with the
U.S. Copyright Office as an unpublished work, pursuant to Title 17,
U.S. Code, Section 408.  Unauthorized copying, adaptation, distribution
or display is prohibited.

$Id$

*************************************************************************/

#ifndef TYPES_H
#define TYPES_H

/* Support for fixed width integer types */

#include <stdint.h>

#define True	1
#define False	0

#ifndef PRECOMPUTED_H

#define FALSE 0
#define TRUE 1

#ifdef MINT_32
typedef int32_t mint;
#else
typedef int64_t mint;
#endif

typedef int mbool;
typedef double mreal;
typedef float msingle;

#endif /* PRECOMPUTED_H */

#endif /* TYPES_H */

