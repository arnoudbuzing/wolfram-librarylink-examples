#include <stdlib.h> // for malloc function
#include <windows.h> // For Sleep function

#include "WolframLibrary.h"
#include "WolframIOLibraryFunctions.h"

EXTERN_C DLLEXPORT mint WolframLibrary_getVersion( ) { return WolframLibraryVersion; }
EXTERN_C DLLEXPORT int WolframLibrary_initialize( WolframLibraryData libData) { return 0; }
EXTERN_C DLLEXPORT void WolframLibrary_uninitialize( WolframLibraryData libData) { return; }

typedef struct background_struct
{
	WolframLibraryData libData;
	mint pause_milliseconds;
	mreal background_real_input;
} *background_struct_pointer;

static void return_real(mint, void*);
static void run_background_task(mint, void*);

//
// Wolfram Language level functions
//

EXTERN_C DLLEXPORT int start_background_task(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res)
{
	background_struct_pointer background_data = (background_struct_pointer)malloc(sizeof(struct background_struct));
	background_data->libData = libData;
	background_data->pause_milliseconds = MArgument_getInteger(Args[0]);
	background_data->background_real_input = MArgument_getReal(Args[1]);

	mint asyncid;
	asyncid = libData->ioLibraryFunctions->createAsynchronousTaskWithThread(run_background_task, background_data);
	MArgument_setInteger(Res, asyncid);

	return LIBRARY_NO_ERROR;
}

EXTERN_C DLLEXPORT int stop_background_task(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res)
{
	mint asyncid;
	WolframIOLibrary_Functions ioLibrary = libData->ioLibraryFunctions;
	asyncid = MArgument_getInteger(Args[0]);
	ioLibrary->removeAsynchronousTask(asyncid);
	return LIBRARY_NO_ERROR;
}

//
// Library private functions
//

static void run_background_task(mint asyncid, void* vtarg) {
	background_struct_pointer targ = (background_struct_pointer) vtarg;
	while(1) { // run forever until stopped or aborted
		mint abortedQ = targ->libData->AbortQ();
		if(abortedQ) break;
		Sleep( (int) targ->pause_milliseconds );
		return_real(asyncid, vtarg);
	}
}

static void return_real(mint asyncid, void* vtarg)
{
	background_struct_pointer targ = (background_struct_pointer) vtarg;
	DataStore ds;
	ds = targ->libData->ioLibraryFunctions->createDataStore();
	targ->libData->ioLibraryFunctions->DataStore_addReal(ds, targ->background_real_input );
	targ->libData->ioLibraryFunctions->raiseAsyncEvent(asyncid, "return_real", ds);
}
