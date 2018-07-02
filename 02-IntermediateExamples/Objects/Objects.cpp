#include "WolframLibrary.h"
#include "Rectangle.h"

EXTERN_C DLLEXPORT mint WolframLibrary_getVersion( ) { return WolframLibraryVersion; }
EXTERN_C DLLEXPORT int WolframLibrary_initialize( WolframLibraryData libData) { return 0; }
EXTERN_C DLLEXPORT void WolframLibrary_uninitialize( WolframLibraryData libData) { return; }

Rectangle r;

EXTERN_C DLLEXPORT int set(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {
	mint x,y;
	x = MArgument_getInteger(Args[0]);
	y = MArgument_getInteger(Args[1]);
	r.set(x,y);
	return LIBRARY_NO_ERROR;
}

EXTERN_C DLLEXPORT int get_w(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {
	MArgument_setInteger(Res,r.get_w());
	return LIBRARY_NO_ERROR;
}

EXTERN_C DLLEXPORT int get_h(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {
	MArgument_setInteger(Res,r.get_h());
	return LIBRARY_NO_ERROR;
}

EXTERN_C DLLEXPORT int compute(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {
	mint result;
	result = r.area();
	MArgument_setInteger(Res,result);
	return LIBRARY_NO_ERROR;
}
