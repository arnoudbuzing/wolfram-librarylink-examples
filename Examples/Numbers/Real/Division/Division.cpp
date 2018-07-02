#include "WolframLibrary.h"

EXTERN_C DLLEXPORT mint WolframLibrary_getVersion( ) { return WolframLibraryVersion; }
EXTERN_C DLLEXPORT int WolframLibrary_initialize( WolframLibraryData libData) { return 0; }
EXTERN_C DLLEXPORT void WolframLibrary_uninitialize( WolframLibraryData libData) { return; }

EXTERN_C DLLEXPORT int Division(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {
	mreal x,y,z;
	x = MArgument_getReal(Args[0]);
	y = MArgument_getReal(Args[1]);
	z = x/y;
	MArgument_setReal(Res,z);
	return LIBRARY_NO_ERROR;
}
