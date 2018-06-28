/*************************************************************************

                        Mathematica source file

        Copyright 1986 through 1999 by Wolfram Research Inc.

This material contains trade secrets and may be registered with the
U.S. Copyright Office as an unpublished work, pursuant to Title 17,
U.S. Code, Section 408.  Unauthorized copying, adaptation, distribution
or display is prohibited.

$Id$

*************************************************************************/

#ifndef RTL_PROCESSOR_COUNT_H
#define RTL_PROCESSOR_COUNT_H

#ifdef __cplusplus
extern "C" {
#endif

int getPhysicalProcessorCount(void);
int getLogicalProcessorCount(void);

int getProcessorCount(void);
int getHyperThreadCount(void);

int getParallelThreadNumber(void);

/*
	Compute the amount of highest level n cache available per CPU core.
	Usually this is level 3 cache but sometimes it is level 4 or level 2.

	This is used to determine how much data should be used on a per thread
	basis in the machfunc functions. Ideally this would allow a thread to run
	to completion requiring fetching from slower DRAM. It also results in better
	average case scheduing since partial jobs not yet completed (due to a busy
	core) can be run in a thread on another core.

	If hyperthreading is enabled then each physical core is divided into two
	logical cores. The size of data that is taken then is only half the cache
	size for that core, allowing another thread to run simultaneously on the
	same core using it's own data in the other half of the cache. Ideally this
	would reduce the possibility of flushing out any data from the cache
	before the thread runs to completion.
*/

size_t getCachePerCore(mbool);
mbool getUseCachePerCore(void);
void setUseCachePerCore(mbool);

/*
	Set the value ParallelThreadNumber and return the old value.
	The old value should be stored in a local variable.
	The old value must be restored using restoreParallelThreadNumber
	before the setting routine exits.
 */

int setParallelThreadNumber(int);
void restoreParallelThreadNumber(int);

#ifdef USE_MKL_LIBRARY

/* MKL equivalents of ParallelThreadNumber */

int getMKLThreadNumber(void);
int setMKLThreadNumber(int);
void restoreMKLThreadNumber(int);
#endif

#ifdef __cplusplus
}
#endif

#endif /* RTL_PROCESSOR_COUNT_H */

