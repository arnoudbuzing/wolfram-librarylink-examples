#include "WolframLibrary.h"
#include "WolframRawArrayLibrary.h"

EXTERN_C DLLEXPORT mint WolframLibrary_getVersion( ) { return WolframLibraryVersion; }
EXTERN_C DLLEXPORT int WolframLibrary_initialize( WolframLibraryData libData) { return 0; }
EXTERN_C DLLEXPORT void WolframLibrary_uninitialize( WolframLibraryData libData) { return; }

EXTERN_C DLLEXPORT int EchoRawArray(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {
	MRawArray x;
	x = MArgument_getMRawArray(Args[0]);
	MArgument_setMRawArray(Res,x);
	return LIBRARY_NO_ERROR;
}
