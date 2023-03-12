package main

import (
    "os"
    "github.com/otterop/example-quicksort/go/example/sort/service/quicksortservice"
    "github.com/otterop/otterop/go/lang/array"
    "github.com/otterop/otterop/go/lang/string"
    "github.com/otterop/otterop/go/lang/result"
    "github.com/otterop/otterop/go/io/console"
)
var Println = console.Println

type Sort struct {
}




func main()  {
    args := os.Args[1:]
    argsArray := array.WrapString(args)
    sortService := quicksortservice.NewQuicksortService()
    sortService.Sort(argsArray, 0, argsArray.Size())
    for i := 0; i < argsArray.Size(); i++ {
        Println(argsArray.Get(i))
    }
    result.Of(string.Wrap(""), string.Wrap(""))
}