package service

import (
    lang "github.com/otterop/otterop/go/lang"
)


type HeapsortService struct {
}




func HeapsortServiceNew() *HeapsortService {
    this := new(HeapsortService)
    return this
}

func (this *HeapsortService) swap(array *lang.Array[*lang.String], fromIdx int, toIdx int)  {
    var tmp *lang.String = array.Get(toIdx)
    array.Set(toIdx, array.Get(fromIdx))
    array.Set(fromIdx, tmp)
}

func (this *HeapsortService) heapify(array *lang.Array[*lang.String], parent int, size int)  {
    var largest int = parent
    var leftChild int = parent * 2 + 1
    var rightChild int = parent * 2 + 2
    
    if leftChild < size {
        var leftS *lang.String = array.Get(leftChild)
        
        if leftS.CompareTo(array.Get(largest)) > 0 {
            largest = leftChild
        }
    }
    
    if rightChild < size {
        var rightS *lang.String = array.Get(rightChild)
        
        if rightS.CompareTo(array.Get(largest)) > 0 {
            largest = rightChild
        }
    }
    
    if largest != parent {
        this.swap(array, parent, largest)
        this.heapify(array, largest, size)
    }
}

func (this *HeapsortService) sortWithIndices(array *lang.Array[*lang.String], fromIdx int, toIdx int)  {
    var n int = array.Size()
    for i := n / 2 - 1; i >= 0; i-- {
        this.heapify(array, i, n)
    }
    for i := n - 1; i >= 0; i-- {
        this.swap(array, 0, i)
        this.heapify(array, 0, i)
    }
}

func (this *HeapsortService) Sort(array *lang.Array[*lang.String]) *lang.Array[*lang.String] {
    this.sortWithIndices(array, 0, array.Size())
    return array
}