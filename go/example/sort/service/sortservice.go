package service

import (
    lang "github.com/otterop/otterop/go/lang"
)

type SortService interface {
    Sort(array *lang.Array[*lang.String]) *lang.Array[*lang.String];
}

