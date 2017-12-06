#' "xptr" provides functions to verify, create and modify "externalptr" objects.
#'
#' @name xptr
#' @title Manipulating External Pointer
#' @docType package
#' @useDynLib xptr
#' @examples
#' library(xptr)
#' a <- new_xptr("0x11a888090")
#' b <- new_xptr("0x11a888098")
#' xptr_address(b)
#' xptr_clear(b)
#' xptr_address(b)
#' is_null_xptr(b)
#' set_xptr_address(b, xptr_address(a))
#' xptr_address(b)
NULL

#' Create an external pointer object.
#' @param address a string of pointer address
#' @param tag an optional tag
#' @param protected an objected to be protected from gc within the lifetime of the external pointer
#' @return an `externalptr` object
#' @export
new_xptr <- function(address = "", tag = NULL, protected = NULL) {
    .Call("new_xptr", PACKAGE = "xptr", address, tag, protected)
}

#' @rdname new_xptr
#' @export
null_xptr <- function(tag = NULL, protected = NULL) {
    .Call("null_xptr", PACKAGE = "xptr", tag, protected)
}

#' Check if the external pointer is null.
#' @param s an `externalptr` object
#' @return TRUE/FALSE
#' @export
is_null_xptr <- function(s) {
    .Call("is_null_xptr", PACKAGE = "xptr", s)
}

#' External pointer address.
#' @param s an `externalptr` object
#' @return a string of pointer address
#' @export
xptr_address <- function(s) {
    .Call("xptr_address", PACKAGE = "xptr", s)
}

#' Tag of the external pointer.
#' @param s an `externalptr` object
#' @return an R object
#' @export
xptr_tag <- function(s) {
    .Call("xptr_tag", PACKAGE = "xptr", s)
}

#' Protected R object of the external pointer.
#' @param s an `externalptr` object
#' @return an R object
#' @export
xptr_protected <- function(s) {
    .Call("xptr_protected", PACKAGE = "xptr", s)
}

#' Clear the pointer address of the external pointer.
#' @param s an `externalptr` object
#' @export
xptr_clear <- function(s) {
    .Call("xptr_clear", PACKAGE = "xptr", s)
    invisible(NULL)
}

#' Set the address of the external pointer.
#' @param s an `externalptr` object
#' @param p a string of pointer address
#' @export
set_xptr_address <- function(s, p) {
    .Call("set_xptr_address", PACKAGE = "xptr", s, p)
    invisible(NULL)
}

#' Set a tag to the external poitner.
#' @param s an `externalptr` object
#' @param tag an R object
#' @export
set_xptr_tag <- function(s, tag) {
    .Call("set_xptr_tag", PACKAGE = "xptr", s, tag)
    invisible(NULL)
}

#' Set a protected R object to the external poitner.
#' @param s an `externalptr` object
#' @param protected an R object
#' @export
set_xptr_protected <- function(s, protected) {
    .Call("set_xptr_protected", PACKAGE = "xptr", s, protected)
    invisible(NULL)
}

#' Register a finalizer for external poitner.
#' @param s an `externalptr` object
#' @param f an R function
#' @param onexit should the finalizer execute on exit?
#' @export
register_xtr_finalizer <- function(s, f, onexit = FALSE) {
    .Call("register_xtr_finalizer", PACKAGE = "xptr", s, f, onexit)
    invisible(NULL)
}
