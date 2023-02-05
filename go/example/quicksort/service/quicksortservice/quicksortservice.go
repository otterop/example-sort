package quicksortservice

import (
    "github.com/otterop/otterop/go/lang/array"
    "github.com/otterop/otterop/go/lang/string"
)

type QuicksortService struct {
}




func swap(array *array.Array[*string.String], fromIdx int, toIdx int)  {
    tmp := array.Get(toIdx)
    array.Set(toIdx, array.Get(fromIdx))
    array.Set(fromIdx, tmp)
}

func QuickSort(array *array.Array[*string.String], fromIdx int, toIdx int)  {
    i := fromIdx
    swapWith := -1
    pivot := toIdx - 1
    
    for i < pivot {
        iString := array.Get(i)
        pivotString := array.Get(pivot)
        lessThan := iString.CompareTo(pivotString) < 0
        
        if swapWith >= 0 && lessThan {
            swap(array, swapWith, i)
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
            swap(array, swapWith, pivot)
            pivot = swapWith
        }
    }
    
    if pivot > fromIdx + 1 {
        QuickSort(array, fromIdx, pivot)
    }
    
    if pivot + 1 < toIdx - 1 {
        QuickSort(array, pivot + 1, toIdx)
    }
}