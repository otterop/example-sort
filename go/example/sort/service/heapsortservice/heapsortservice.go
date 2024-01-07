package heapsortservice

import (
    array "github.com/otterop/otterop/go/lang/array"
    string "github.com/otterop/otterop/go/lang/string"
)


type HeapsortService struct {
}




func NewHeapsortService() *HeapsortService {
    this := new(HeapsortService)
    return this
}

func (this *HeapsortService) swap(array *array.Array[*string.String], fromIdx int, toIdx int)  {
    var tmp *string.String = array.Get(toIdx)
    array.Set(toIdx, array.Get(fromIdx))
    array.Set(fromIdx, tmp)
}

func (this *HeapsortService) heapify(array *array.Array[*string.String], parent int, size int)  {
    var largest int = parent
    var leftChild int = parent * 2 + 1
    var rightChild int = parent * 2 + 2
    
    if leftChild < size {
        var leftS *string.String = array.Get(leftChild)
        
        if leftS.CompareTo(array.Get(largest)) > 0 {
            largest = leftChild
        }
    }
    
    if rightChild < size {
        var rightS *string.String = array.Get(rightChild)
        
        if rightS.CompareTo(array.Get(largest)) > 0 {
            largest = rightChild
        }
    }
    
    if largest != parent {
        this.swap(array, parent, largest)
        this.heapify(array, largest, size)
    }
}

func (this *HeapsortService) sortWithIndices(array *array.Array[*string.String], fromIdx int, toIdx int)  {
    var n int = array.Size()
    for i := n / 2 - 1; i >= 0; i-- {
        this.heapify(array, i, n)
    }
    for i := n - 1; i >= 0; i-- {
        this.swap(array, 0, i)
        this.heapify(array, 0, i)
    }
}

func (this *HeapsortService) Sort(array *array.Array[*string.String]) *array.Array[*string.String] {
    this.sortWithIndices(array, 0, array.Size())
    return array
}