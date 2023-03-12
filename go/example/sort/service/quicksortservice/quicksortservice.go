package quicksortservice

import (
    "github.com/otterop/otterop/go/lang/array"
    "github.com/otterop/otterop/go/lang/string"
)

type QuicksortService struct {
}




func NewQuicksortService() *QuicksortService {
    this := new(QuicksortService)
    return this
}

func (this *QuicksortService) swap(array *array.Array[*string.String], fromIdx int, toIdx int)  {
    tmp := array.Get(toIdx)
    array.Set(toIdx, array.Get(fromIdx))
    array.Set(fromIdx, tmp)
}

func (this *QuicksortService) Sort(array *array.Array[*string.String], fromIdx int, toIdx int)  {
    i := fromIdx
    swapWith := -1
    pivot := toIdx - 1
    
    for i < pivot {
        iString := array.Get(i)
        pivotString := array.Get(pivot)
        lessThan := iString.CompareTo(pivotString) < 0
        
        if swapWith >= 0 && lessThan {
            this.swap(array, swapWith, i)
            swapWith = swapWith + 1
        } else if swapWith < 0 && !lessThan {
            swapWith = i
        }
        i = i + 1
    }
    
    if swapWith >= 0 && swapWith < pivot {
        swapWithString := array.Get(swapWith)
        pivotString := array.Get(pivot)
        
        if swapWithString.CompareTo(pivotString) >= 0 {
            this.swap(array, swapWith, pivot)
            pivot = swapWith
        }
    }
    
    if pivot > fromIdx + 1 {
        this.Sort(array, fromIdx, pivot)
    }
    
    if pivot + 1 < toIdx - 1 {
        this.Sort(array, pivot + 1, toIdx)
    }
}