#include "WolframLibrary.h"

EXTERN_C DLLEXPORT mint WolframLibrary_getVersion( ) { return WolframLibraryVersion; }
EXTERN_C DLLEXPORT int WolframLibrary_initialize( WolframLibraryData libData) { return 0; }
EXTERN_C DLLEXPORT void WolframLibrary_uninitialize( WolframLibraryData libData) { return; }

EXTERN_C DLLEXPORT int Multiplication(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {
	mcomplex x,y,z;

	x = MArgument_getComplex(Args[0]);
	y = MArgument_getComplex(Args[1]);
	mcreal(z) = mcreal(x)*mcreal(y) - mcimag(x)*mcimag(y);
	mcimag(z) = mcreal(x)*mcimag(y) + mcimag(x)*mcreal(y);
	MArgument_setComplex(Res,z);
	return LIBRARY_NO_ERROR;
}
