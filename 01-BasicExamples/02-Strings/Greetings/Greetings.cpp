#include <stdio.h>
#include "WolframLibrary.h"

EXTERN_C DLLEXPORT mint WolframLibrary_getVersion( ) { return WolframLibraryVersion; }
EXTERN_C DLLEXPORT int WolframLibrary_initialize( WolframLibraryData libData) { return 0; }
EXTERN_C DLLEXPORT void WolframLibrary_uninitialize( WolframLibraryData libData) { return; }

EXTERN_C DLLEXPORT int Greetings(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {
  char *name;
  char result[1024];
  name = MArgument_getUTF8String(Args[0]);
  sprintf_s(result,1024,"Greetings %s!", name);
  MArgument_setUTF8String(Res,result);
  return LIBRARY_NO_ERROR;
}
