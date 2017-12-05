#' @name xptr
#' @title Functions to maniplicate externalptr
#' @docType package
#' @useDynLib xptr
NULL

#' @export
null_xptr <- function(tag = NULL, protected = NULL) {
    .Call("null_xptr", PACKAGE = "xptr", tag, protected)
}

#' @export
is_null_xptr <- function(s) {
    .Call("is_null_xptr", PACKAGE = "xptr", s) == 1
}
