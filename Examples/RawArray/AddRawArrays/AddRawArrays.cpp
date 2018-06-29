#include "WolframLibrary.h"
#include "WolframRawArrayLibrary.h"

EXTERN_C DLLEXPORT mint WolframLibrary_getVersion( ) { return WolframLibraryVersion; }
EXTERN_C DLLEXPORT int WolframLibrary_initialize( WolframLibraryData libData) { return 0; }
EXTERN_C DLLEXPORT void WolframLibrary_uninitialize( WolframLibraryData libData) { return; }

EXTERN_C DLLEXPORT int AddRawArrays(WolframLibraryData libData, mint Argc, MArgument *Args, MArgument Res) {
	WolframRawArrayLibrary_Functions rawfun = libData->rawarrayLibraryFunctions;
	MRawArray x,y,r;
	rawarray_t type = MRawArray_Type_Ubit8;
	mint dims[1];
	mint rank = 1;
	int err = LIBRARY_NO_ERROR;
	void *xdata, *ydata, *rdata;
	uint8_t *xd, *yd, *rd;
  mint i;

	x = MArgument_getMRawArray(Args[0]);
	y = MArgument_getMRawArray(Args[1]);

	dims[0] = 3;
	err = rawfun->MRawArray_new(type,rank,dims,&r);

	xdata = rawfun->MRawArray_getData(x);
	ydata = rawfun->MRawArray_getData(y);
	rdata = rawfun->MRawArray_getData(r);

	xd = (uint8_t *) xdata;
	yd = (uint8_t *) ydata;
	rd = (uint8_t *) rdata;

  for(i=0; i<3; i++) { rd[i] = xd[i] + yd[i]; }
	if(!err) MArgument_setMRawArray(Res, r);
	return err;
}
