#define R_NO_REMAP
#include <R.h>
#include <Rinternals.h>

#ifndef R_PRIdXLEN_T
#  ifdef LONG_VECTOR_SUPPORT
#    define R_PRIdXLEN_T "td"
#  else
#    define R_PRIdXLEN_T "d"
#  endif
#endif

void R_init_format(DllInfo *dll) {
#ifdef LONG_VECTOR_SUPPORT
  Rprintf("Long vectors supported\n");
#else
  Rprintf("long vectors not supported\n");
#endif
  Rprintf("Zero length: %" R_PRIdXLEN_T "\n", Rf_xlength(R_NilValue));
  Rprintf("Max  length: %" R_PRIdXLEN_T "\n", R_XLEN_T_MAX);

  R_registerRoutines(dll, NULL, NULL, NULL, NULL);
  R_useDynamicSymbols(dll, FALSE);
  R_forceSymbols(dll, TRUE);
}
