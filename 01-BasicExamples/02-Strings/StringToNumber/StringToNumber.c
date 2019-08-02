#include <stdlib.h>
#include <stdio.h>
#include "WolframLibrary.h"

EXTERN_C DLLEXPORT mint WolframLibrary_getVersion( ) { return WolframLibraryVersion; }
EXTERN_C DLLEXPORT int WolframLibrary_initialize( WolframLibraryData libData) { return 0; }
EXTERN_C DLLEXPORT void WolframLibrary_uninitialize( WolframLibraryData libData) { return; }

EXTERN_C DLLEXPORT int wolfram_strtol(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {
  char *string;
  int base;
  mint result;
  string = MArgument_getUTF8String(Args[0]);
  base = (int) MArgument_getInteger(Args[1]);
  result = (mint) strtol(string, NULL, base);
  MArgument_setInteger(Res,result);
  return LIBRARY_NO_ERROR;
}

EXTERN_C DLLEXPORT int wolfram_strtod(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {
  char *string;
  mint base;
  mreal result;
  string = MArgument_getUTF8String(Args[0]);
  base = MArgument_getInteger(Args[1]);
  result = strtod(string, NULL);
  MArgument_setReal(Res,result);
  return LIBRARY_NO_ERROR;
}
