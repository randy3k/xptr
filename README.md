# Manipulating External Pointer

`xptr` provides functions to verify, create and modify `externalptr` objects.

### Usage

```r
library(xptr)
a <- new_xptr("0x11a888090")
b <- new_xptr("0x11a888098")
xptr_address(b)
#> [1] "0x11a888098"
xptr_clear(b)
xptr_address(b)
#> [1] "0x0"
is_null_xptr(b)
#> [1] TRUE
set_xptr_address(b, xptr_address(a))
xptr_address(b)
#> [1] "0x11a888090"
```
