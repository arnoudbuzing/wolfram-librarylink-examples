/*************************************************************************
Mathematica source file

Copyright 1986 through 2015 by Wolfram Research Inc.

This material contains trade secrets and may be registered with the
U.S. Copyright Office as an unpublished work, pursuant to Title 17,
U.S. Code, Section 408.  Unauthorized copying, adaptation, distribution
or display is prohibited.

$Id$

*************************************************************************/

#ifndef WOLFRAMIOLIBRARYFUNCTIONS_H
#define WOLFRAMIOLIBRARYFUNCTIONS_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct st_WolframIOLibrary_Functions
{
    mint (*createAsynchronousTaskWithoutThread)();
    
    mint (*createAsynchronousTaskWithThread)(
                                             void (*asyncRunner)(mint asyncTaskID, void* initData),
                                             void* initData
                                             );
    
    void (*raiseAsyncEvent)(mint asyncTaskID, char* eventType, DataStore);
    
    mbool (*asynchronousTaskAliveQ)(mint asyncTaskID);
    mbool (*asynchronousTaskStartedQ)(mint asyncTaskID);
    
    DataStore (*createDataStore)(void);
    
    void (*DataStore_addInteger)(DataStore, mint);
    void (*DataStore_addReal)(DataStore, mreal);
    void (*DataStore_addComplex)(DataStore, mcomplex);
    void (*DataStore_addString)(DataStore, char*);
    void (*DataStore_addMTensor)(DataStore, MTensor);
    void(*DataStore_addMRawArray)(DataStore, MRawArray);
    void(*DataStore_addMImage)(DataStore, MImage);
    void (*DataStore_addDataStore)(DataStore, DataStore);
    
    void (*DataStore_addNamedInteger)(DataStore, char* name, mint);
    void (*DataStore_addNamedReal)(DataStore, char* name, mreal);
    void (*DataStore_addNamedComplex)(DataStore, char* name, mcomplex);
    void (*DataStore_addNamedString)(DataStore, char* name, char*);
    void (*DataStore_addNamedMTensor)(DataStore, char* name, MTensor);
    void(*DataStore_addNamedMRawArray)(DataStore, char* name, MRawArray);
    void(*DataStore_addNamedMImage)(DataStore, char* name, MImage);
    void (*DataStore_addNamedDataStore)(DataStore, char* name, DataStore);
    mint (*removeAsynchronousTask)(mint asyncTaskID);
    
} *WolframIOLibrary_Functions;
#ifdef __cplusplus
}
#endif

#endif
