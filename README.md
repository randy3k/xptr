# Functions to maniplicate externalptr

R does not come with a set ot functions to maniplicate external pointer. xptr provides some functions to vertify, create and modifiy externalptr objects.

### Usage

```r
library(xptr)
a <- create_xptr("0x11a888090")
b <- create_xptr("0x11a888098")
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