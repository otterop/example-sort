package main

import (
    "os"
    "github.com/otterop/otterop/go/lang/array"
    "github.com/otterop/otterop/go/lang/string"
    "github.com/otterop/otterop/go/io/console"
)
var Println = console.Println

type Quicksort struct {
    a int
    b float64
    c *string.String
}




func (this *Quicksort) Hello()  {
    Println(string.Wrap("world"))
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
    } else  {
        Println(string.Wrap("foo"))
    }
}

func main()  {
    args := os.Args[1:]
    argsArray := array.WrapString(args)
    QuickSort(argsArray, 0, argsArray.Size())
    i := 0
    
    if argsArray.Size() > 0 {
        argsArray.Set(0, string.Wrap("bbbb"))
    }
    
    for i < argsArray.Size() {
        Println(argsArray.Get(i))
        i = i + 1
    }
    p := NewQuicksort(2, 4.0, string.Wrap("hello world"))
    p.Hello()
    Println(p.String())
}

func NewQuicksort(a int, b float64, c *string.String) *Quicksort {
    this := new(Quicksort)
    this.a = a
    this.b = b
    this.c = c
    return this
}

func (this *Quicksort) String() *string.String {
    return this.c
}