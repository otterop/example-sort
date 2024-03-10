package main

import (
    "fmt"
    "os"
    service "github.com/otterop/example-sort/go/example/sort/service/pure"
    tree "github.com/otterop/example-sort/go/example/sort/tree/pure"
)

func main() {
    args := os.Args[1:]

    if len(args) < 1 {
        fmt.Println("Usage: <quick|heap> ...values")
        return
    }

    sortAlgorithm := args[0]
    isQuick := sortAlgorithm == "quick";
    isHeap := sortAlgorithm == "heap";
    if !(isQuick || isHeap) {
        fmt.Println("Usage: <quick|heap> ...values")
        return
    }

    if len(args) == 0 {
        fmt.Println("Usage: <quick|heap> ...values")
        return
    }

    slicedArray := args[1:]
    var argsP = make([]*string, len(slicedArray))
    for i := range slicedArray {
        argsP[i] = &slicedArray[i]
    }

    var sortService service.SortService
    if (isHeap) {
        sortService = service.HeapsortServiceNew()
    } else {
        sortService = service.QuicksortServiceNew()
    }

    ret := sortService.Sort(argsP)

    for i := range ret {
        fmt.Println(*ret[i])
    }

    empty := make([]*tree.Node, 0)
    a := tree.NodeNew(1, empty)
    b := tree.NodeNew(2, empty)
    c := tree.NodeNew(3, []*tree.Node {a, b})
    d := tree.NodeNew(4, empty)
    e := tree.NodeNew(5, empty)
    f := tree.NodeNew(6, []*tree.Node {d, e})
    g := tree.NodeNew(7, []*tree.Node {c, f})

    list := make([]*tree.Node, 1)
    list[0] = g
    for len(list) > 0 {
        newList := make([]*tree.Node, 0)
        rest := false
        for _, el := range list {
            if rest {
                fmt.Print(" ")
            }
            fmt.Printf("value: %d", el.Value())
            newList = append(newList, el.Children()...)
            rest = true
        }
        fmt.Println()
        list = newList
    }
}
