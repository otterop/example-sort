package sortservice

import (
    array "github.com/otterop/otterop/go/lang/array"
    string "github.com/otterop/otterop/go/lang/string"
)

type SortService interface {
    Sort(array *array.Array[*string.String]) *array.Array[*string.String];
}

