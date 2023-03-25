package main

import (
    "os"
    "github.com/otterop/example-sort/go/example/sort/service/heapsortservice"
    "github.com/otterop/example-sort/go/example/sort/service/quicksortservice"
    "github.com/otterop/example-sort/go/example/sort/service/sortservice"
    "github.com/otterop/otterop/go/lang/array"
    "github.com/otterop/otterop/go/lang/string"
    "github.com/otterop/otterop/go/lang/result"
    "github.com/otterop/otterop/go/io/console"
)
var Println = console.Println

type Sort struct {
    TEST int
}


var TEST int = 111


func main()  {
    args := os.Args[1:]
    var quick *string.String = string.Wrap("quick")
    var heap *string.String = string.Wrap("heap")
    var argsArray *array.Array[*string.String] = array.WrapString(args)
    
    if argsArray.Size() < 1 {
        Println(string.Wrap("Usage: <quick|heap> ...values"))
        return 
    }
    var sortAlgorithm *string.String = argsArray.Get(0)
    var isQuick bool = sortAlgorithm.CompareTo(quick) == 0
    var isHeap bool = sortAlgorithm.CompareTo(heap) == 0
    
    if !(isQuick || isHeap) {
        Println(string.Wrap("Usage: <quick|heap> ...values"))
        return 
    }
    argsArray = argsArray.Slice(1, argsArray.Size())
    var sortService sortservice.SortService = quicksortservice.NewQuicksortService()
    
    if isHeap {
        sortService = heapsortservice.NewHeapsortService()
    }
    sortService.Sort(argsArray, 0, argsArray.Size())
    for i := 0; i < argsArray.Size(); i++ {
        Println(argsArray.Get(i))
    }
    result.Of(string.Wrap(""), string.Wrap(""))
}