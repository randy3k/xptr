# Manipulating External Pointer

There is limited native support for external pointers in the R interface.
This package provides some basic tools to verify, create and modify 'externalptr' objects.

- Documentation: https://randy3k.github.io/xptr/
- Source: https://github.com/randy3k/xptr
- References: https://cran.r-project.org/doc/manuals/r-release/R-exts.html#External-pointers-and-weak-references

### Usage

```r
library(xptr)
a <- new_xptr("0x11a888090")
b <- new_xptr("0x11a888098")
is_xptr(a)
#> [1] TRUE
xptr_address(a)
#> [1] "0x11a888090"
xptr_clear(a)
is_null_xptr(a)
#> [1] TRUE
set_xptr_address(a, xptr_address(b))
xptr_address(a)
#> [1] "0x11a888098"
```
