package main

import (
    "os"
    "github.com/otterop/example-quicksort/go/example/quicksort/service/quicksortservice"
    "github.com/otterop/otterop/go/lang/array"
    "github.com/otterop/otterop/go/lang/string"
    "github.com/otterop/otterop/go/lang/result"
    "github.com/otterop/otterop/go/io/console"
)
var Println = console.Println

type Quicksort struct {
}




func main()  {
    args := os.Args[1:]
    argsArray := array.WrapString(args)
    quicksortservice.QuickSort(argsArray, 0, argsArray.Size())
    i := 0
    
    for i < argsArray.Size() {
        Println(argsArray.Get(i))
        i = i + 1
    }
    result.Of(string.Wrap(""), string.Wrap(""))
}