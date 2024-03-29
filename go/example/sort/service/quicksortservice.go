package service

import (
    lang "github.com/otterop/otterop/go/lang"
)


type QuicksortService struct {
}




func QuicksortServiceNew() *QuicksortService {
    this := new(QuicksortService)
    return this
}

func (this *QuicksortService) swap(array *lang.Array[*lang.String], fromIdx int, toIdx int)  {
    var tmp *lang.String = array.Get(toIdx)
    array.Set(toIdx, array.Get(fromIdx))
    array.Set(fromIdx, tmp)
}

func (this *QuicksortService) sortWithIndices(array *lang.Array[*lang.String], fromIdx int, toIdx int)  {
    var i int = fromIdx
    var swapWith int = -1
    var pivot int = toIdx - 1
    
    for i < pivot {
        var iString *lang.String = array.Get(i)
        var pivotString *lang.String = array.Get(pivot)
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
        var swapWithString *lang.String = array.Get(swapWith)
        var pivotString *lang.String = array.Get(pivot)
        
        if swapWithString.CompareTo(pivotString) >= 0 {
            this.swap(array, swapWith, pivot)
            pivot = swapWith
        }
    }
    
    if pivot > fromIdx + 1 {
        this.sortWithIndices(array, fromIdx, pivot)
    }
    
    if pivot + 1 < toIdx - 1 {
        this.sortWithIndices(array, pivot + 1, toIdx)
    }
}

func (this *QuicksortService) Sort(array *lang.Array[*lang.String]) *lang.Array[*lang.String] {
    this.sortWithIndices(array, 0, array.Size())
    return array
}