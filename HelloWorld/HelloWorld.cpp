#include "WolframLibrary.h"

/*
EXTERN_C DLLEXPORT mint WolframLibrary_getVersion( ) { return WolframLibraryVersion; }
EXTERN_C DLLEXPORT int WolframLibrary_initialize( WolframLibraryData libData) { return 0; }
EXTERN_C DLLEXPORT void WolframLibrary_uninitialize( WolframLibraryData libData) { return; }
*/

EXTERN_C DLLEXPORT int HelloWorld(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {
	char hello[] = "Hello World";
	MArgument_setUTF8String(Res,hello);
	return LIBRARY_NO_ERROR;
}
