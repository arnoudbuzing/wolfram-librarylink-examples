#include "WolframLibrary.h"

EXTERN_C DLLEXPORT mint WolframLibrary_getVersion( ) { return WolframLibraryVersion; }
EXTERN_C DLLEXPORT int WolframLibrary_initialize( WolframLibraryData libData) { return 0; }
EXTERN_C DLLEXPORT void WolframLibrary_uninitialize( WolframLibraryData libData) { return; }

class obj {
	mint w, h;
public:
	void set(mint, mint);
	mint get_w(void);
	mint get_h(void);
	mint compute(void);
};

void obj::set(mint ww, mint hh) {	w = ww;	h = hh; }
mint obj::get_w(void) {	return w; }
mint obj::get_h(void) {	return h;}
mint obj::compute(void) {	return w*h; }


obj o;

EXTERN_C DLLEXPORT int set(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {
	mint x,y;
	x = MArgument_getInteger(Args[0]);
	y = MArgument_getInteger(Args[1]);
	o.set(x,y);
	return LIBRARY_NO_ERROR;
}

EXTERN_C DLLEXPORT int get_w(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {
	MArgument_setInteger(Res,o.get_w());
	return LIBRARY_NO_ERROR;
}

EXTERN_C DLLEXPORT int get_h(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {
	MArgument_setInteger(Res,o.get_h());
	return LIBRARY_NO_ERROR;
}

EXTERN_C DLLEXPORT int compute(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {
	mint result;
	result = o.compute();
	MArgument_setInteger(Res,result);
	return LIBRARY_NO_ERROR;
}
