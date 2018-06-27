#include "WolframLibrary.h"

EXTERN_C DLLEXPORT int HelloWorld(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {
        MArgument_setUTF8String(Res,"Hello World");
        return LIBRARY_NO_ERROR;
}
