#include <R.h>
#include <Rinternals.h>
#include <Rdefines.h>

SEXP null_xptr(SEXP tag, SEXP protected) {
    return R_MakeExternalPtr(NULL, tag, protected);
}

void check_is_xptr(SEXP s) {
    if (TYPEOF(s) != EXTPTRSXP) {
        error("exptect externalptr");
    }
}

SEXP is_null_xptr(SEXP s){
    check_is_xptr(s);
    return Rf_ScalarLogical(R_ExternalPtrAddr(s) == NULL);
}
