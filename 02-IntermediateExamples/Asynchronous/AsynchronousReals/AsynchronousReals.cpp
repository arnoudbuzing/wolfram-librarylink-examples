#include <stdlib.h>
#include <windows.h>

#include "WolframLibrary.h"
#include "WolframIOLibraryFunctions.h"

EXTERN_C DLLEXPORT mint WolframLibrary_getVersion( ) { return WolframLibraryVersion; }
EXTERN_C DLLEXPORT int WolframLibrary_initialize( WolframLibraryData libData) { return 0; }
EXTERN_C DLLEXPORT void WolframLibrary_uninitialize( WolframLibraryData libData) { return; }

typedef struct thread_struct
{
	WolframIOLibrary_Functions ioLibrary;
	mint pausemillis;
	mreal eventdata;
} *thread_struct_pointer;

static void return_real(mint, void*);
static void run_background_task(mint, void*);

EXTERN_C DLLEXPORT int start_background_task(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res)
{
	mint asyncid;
	WolframIOLibrary_Functions ioLibrary = libData->ioLibraryFunctions;
	thread_struct_pointer thread_arguments = (thread_struct_pointer)malloc(sizeof(struct thread_struct));
	if(Argc != 2)
		return LIBRARY_FUNCTION_ERROR;
	thread_arguments->ioLibrary = ioLibrary;
	thread_arguments->pausemillis = MArgument_getInteger(Args[0]);
	thread_arguments->eventdata = MArgument_getReal(Args[1]);
	asyncid = ioLibrary->createAsynchronousTaskWithThread(run_background_task, thread_arguments);
	MArgument_setInteger(Res, asyncid);
	return LIBRARY_NO_ERROR;
}

static void return_real(mint asyncid, void* vtarg)
{
	thread_struct_pointer targ = (thread_struct_pointer)vtarg;
	WolframIOLibrary_Functions ioLibrary = targ->ioLibrary;
	mint pausems = targ->pausemillis;
	mreal eventdata = targ->eventdata;
	DataStore ds;
	free(targ);

	Sleep((int)pausems);
	ds = ioLibrary->createDataStore();
	ioLibrary->DataStore_addReal(ds, eventdata);
	ioLibrary->raiseAsyncEvent(asyncid, "return_real", ds);
}

static void run_background_task(mint asyncid, void* vtarg)
{
		while(1) {
				return_real(asyncid,vtarg);
		}
}
