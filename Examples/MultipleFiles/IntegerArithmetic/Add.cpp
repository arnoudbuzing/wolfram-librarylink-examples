#include "WolframLibrary.h"

EXTERN_C DLLEXPORT int AddIntegers(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {
	mint x,y;
	mint result;
	x = MArgument_getInteger(Args[0]);
	y = MArgument_getInteger(Args[1]);
	result = x+y;
	MArgument_setInteger(Res,result);
	return LIBRARY_NO_ERROR;
}
