package node

import (
    "github.com/otterop/otterop/go/lang/array"
)

type Node struct {
    children *array.Array[*Node]
}




func NewNode(children *array.Array[*Node]) *Node {
    this := new(Node)
    this.children = children
    return this
}

func (this *Node) Child(i int) *Node {
    var children *array.Array[*Node] = this.children
    return children.Get(i)
}

func (this *Node) Children() *array.Array[*Node] {
    return this.children
}