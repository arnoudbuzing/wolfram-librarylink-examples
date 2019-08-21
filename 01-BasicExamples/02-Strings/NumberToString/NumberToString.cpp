#include <iostream>
#include <cstdlib>
#include <string>
#include "WolframLibrary.h"

EXTERN_C DLLEXPORT mint WolframLibrary_getVersion( ) { return WolframLibraryVersion; }
EXTERN_C DLLEXPORT int WolframLibrary_initialize( WolframLibraryData libData) { return 0; }
EXTERN_C DLLEXPORT void WolframLibrary_uninitialize( WolframLibraryData libData) { return; }

EXTERN_C DLLEXPORT int wolfram_dtoa(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {
  mreal num;
  std::string tmp;
  char *result;
  num = MArgument_getReal(Args[0]);
  tmp = std::to_string((double)num);
  result = (char*)tmp.c_str();
  std::cout << result;
  std::cout << "\n";
  MArgument_setUTF8String(Res, result);
  return LIBRARY_NO_ERROR;
}
