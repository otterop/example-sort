package main

import (
    "fmt"
    "os"
    sortservice "github.com/otterop/example-sort/go/example/sort/service/sortservice/pure"
    quicksortservice "github.com/otterop/example-sort/go/example/sort/service/quicksortservice/pure"
    heapsortservice "github.com/otterop/example-sort/go/example/sort/service/heapsortservice/pure"
    node "github.com/otterop/example-sort/go/example/sort/tree/node/pure"
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

    var sortService sortservice.SortService
    if (isHeap) {
        sortService = heapsortservice.NewHeapsortService()
    } else {
        sortService = quicksortservice.NewQuicksortService()
    }

    ret := sortService.Sort(argsP)

    for i := range ret {
        fmt.Println(*ret[i])
    }

    empty := make([]*node.Node, 0)
    a := node.NewNode(1, empty)
    b := node.NewNode(2, empty)
    c := node.NewNode(3, []*node.Node {a, b})
    d := node.NewNode(4, empty)
    e := node.NewNode(5, empty)
    f := node.NewNode(6, []*node.Node {d, e})
    g := node.NewNode(7, []*node.Node {c, f})

    list := make([]*node.Node, 1)
    list[0] = g
    for len(list) > 0 {
        newList := make([]*node.Node, 0)
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
