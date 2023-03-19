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
    var tmp *string.String = array.Get(toIdx)
    array.Set(toIdx, array.Get(fromIdx))
    array.Set(fromIdx, tmp)
}

func (this *QuicksortService) Sort(array *array.Array[*string.String], fromIdx int, toIdx int)  {
    var i int = fromIdx
    var swapWith int = -1
    var pivot int = toIdx - 1
    
    for i < pivot {
        var iString *string.String = array.Get(i)
        var pivotString *string.String = array.Get(pivot)
        var lessThan bool = iString.CompareTo(pivotString) < 0
        
        if swapWith >= 0 && lessThan {
            this.swap(array, swapWith, i)
            swapWith = swapWith + 1
        } else if swapWith < 0 && !lessThan {
            swapWith = i
        }
        i = i + 1
    }
    
    if swapWith >= 0 && swapWith < pivot {
        var swapWithString *string.String = array.Get(swapWith)
        var pivotString *string.String = array.Get(pivot)
        
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