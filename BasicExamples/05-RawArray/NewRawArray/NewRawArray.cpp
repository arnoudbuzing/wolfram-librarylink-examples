#include "WolframLibrary.h"
#include "WolframRawArrayLibrary.h"

EXTERN_C DLLEXPORT mint WolframLibrary_getVersion( ) { return WolframLibraryVersion; }
EXTERN_C DLLEXPORT int WolframLibrary_initialize( WolframLibraryData libData) { return 0; }
EXTERN_C DLLEXPORT void WolframLibrary_uninitialize( WolframLibraryData libData) { return; }

EXTERN_C DLLEXPORT int NewRawArray(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {
	WolframRawArrayLibrary_Functions rawfun = libData->rawarrayLibraryFunctions;
	MRawArray x;
	rawarray_t type = MRawArray_Type_Real64;
	mint dims[1];
	mint rank = 1;
	int err = LIBRARY_NO_ERROR;
	void *data;
	double *ddata;
  mint i;

	dims[0] = 3;
	err = rawfun->MRawArray_new(type,rank,dims,&x);
	data = rawfun->MRawArray_getData(x);
	ddata = (double *) data;
  for(i=0; i<3; i++) { ddata[i] = (double)i; }
	if(!err) MArgument_setMRawArray(Res, x);
	return err;
}
