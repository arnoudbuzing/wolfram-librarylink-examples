#include <stdio.h>
#include <string.h>
#include "WolframLibrary.h"

EXTERN_C DLLEXPORT mint WolframLibrary_getVersion( ) { return WolframLibraryVersion; }
EXTERN_C DLLEXPORT int WolframLibrary_initialize( WolframLibraryData libData) { return 0; }
EXTERN_C DLLEXPORT void WolframLibrary_uninitialize( WolframLibraryData libData) { return; }

EXTERN_C DLLEXPORT int ReverseString(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {
  char *str;
  str = MArgument_getUTF8String(Args[0]);
  MArgument_setUTF8String(Res, strrev(str));
  return LIBRARY_NO_ERROR;
}
