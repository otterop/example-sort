package sortservice

import (
    "github.com/otterop/otterop/go/lang/array"
    "github.com/otterop/otterop/go/lang/string"
)

type SortService interface {
     Sort(array *array.Array[*string.String], fromIdx int, toIdx int);
}

