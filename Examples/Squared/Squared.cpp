#include "WolframLibrary.h"

EXTERN_C DLLEXPORT mint WolframLibrary_getVersion( ) { return WolframLibraryVersion; }
EXTERN_C DLLEXPORT int WolframLibrary_initialize( WolframLibraryData libData) { return 0; }
EXTERN_C DLLEXPORT void WolframLibrary_uninitialize( WolframLibraryData libData) { return; }

EXTERN_C DLLEXPORT int Squared(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {
	mint x;
	mint result;
	x = MArgument_getInteger(Args[0]);
	result = x*x;
	MArgument_setInteger(Res,result);
	return LIBRARY_NO_ERROR;
}
