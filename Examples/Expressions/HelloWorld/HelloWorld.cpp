#include "WolframLibrary.h"
#include "wstp.h"

EXTERN_C DLLEXPORT mint WolframLibrary_getVersion( ) { return WolframLibraryVersion; }
EXTERN_C DLLEXPORT int WolframLibrary_initialize( WolframLibraryData libData) { return 0; }
EXTERN_C DLLEXPORT void WolframLibrary_uninitialize( WolframLibraryData libData) { return; }

EXTERN_C DLLEXPORT int HelloWorld(WolframLibraryData libData, WSLINK ws) {
	long length;

	WSCheckFunction(ws, "List", &length);
	WSPutString(ws, "Hello World");
	return LIBRARY_NO_ERROR;
}
