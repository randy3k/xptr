#include <R.h>
#include <Rinternals.h>
#include <Rdefines.h>
#include <stdio.h>


void check_is_xptr(SEXP s) {
    if (TYPEOF(s) != EXTPTRSXP) {
        error("exptect an externalptr");
    }
}

void* str2ptr(SEXP p) {
    if (!isString(p)) error("expect a string of pointer address");
    return (void*) strtol(CHAR(STRING_PTR(p)[0]), NULL, 0);
}

SEXP create_xptr(SEXP p, SEXP tag, SEXP protected) {
    return R_MakeExternalPtr(str2ptr(p), tag, protected);
}

SEXP null_xptr(SEXP tag, SEXP protected) {
    return R_MakeExternalPtr(NULL, tag, protected);
}

SEXP is_null_xptr(SEXP s) {
    check_is_xptr(s);
    return Rf_ScalarLogical(R_ExternalPtrAddr(s) == NULL);
}

SEXP xptr_address(SEXP s) {
    check_is_xptr(s);
    char* buf[20];
    sprintf((char*) buf, "%p", R_ExternalPtrAddr(s));
    return Rf_mkString((char*) buf);
}

SEXP xptr_tag(SEXP s) {
    check_is_xptr(s);
    return R_ExternalPtrTag(s);
}

SEXP xptr_protected(SEXP s) {
    check_is_xptr(s);
    return R_ExternalPtrProtected(s);
}

void xptr_clear(SEXP s){
    check_is_xptr(s);
    R_ClearExternalPtr(s);
}

void set_xptr_address(SEXP s, SEXP p) {
    check_is_xptr(s);
    R_SetExternalPtrAddr(s, str2ptr(p));
}

void set_xptr_tag(SEXP s, SEXP tag) {
    check_is_xptr(s);
    R_SetExternalPtrTag(s, tag);
}

void set_xptr_protected(SEXP s, SEXP protected) {
    check_is_xptr(s);
    R_SetExternalPtrProtected(s, protected);
}

void register_xtr_finalizer(SEXP s, SEXP f, SEXP onexit) {
    check_is_xptr(s);
    if (!isFunction(f)) error("expect a function");
    if (!isNumeric(onexit)) error("expect TRUE/FALSE");
    R_RegisterFinalizerEx(s, f, Rf_asLogical(onexit));
}


static const R_CallMethodDef CallEntries[] = {
    {"create_xptr", (DL_FUNC) &create_xptr, 3},
    {"null_xptr", (DL_FUNC) &null_xptr, 2},
    {"is_null_xptr", (DL_FUNC) &is_null_xptr, 1},
    {"xptr_address", (DL_FUNC) &xptr_address, 1},
    {"xptr_tag", (DL_FUNC) &xptr_tag, 1},
    {"xptr_protected", (DL_FUNC) &xptr_protected, 1},
    {"xptr_clear", (DL_FUNC) &xptr_clear, 1},
    {"set_xptr_address", (DL_FUNC) &set_xptr_address, 2},
    {"set_xptr_tag", (DL_FUNC) &set_xptr_tag, 2},
    {"set_xptr_protected", (DL_FUNC) &set_xptr_protected, 2},
    {"register_xtr_finalizer", (DL_FUNC) &register_xtr_finalizer, 3},
    {NULL, NULL, 0}
};

void R_init_xptr(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
