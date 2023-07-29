package node

import (
    "github.com/otterop/otterop/go/lang/array"
)

type Node struct {
    _children *array.Array[*Node]
    _value int
}




func NewNode(value int, children *array.Array[*Node]) *Node {
    this := new(Node)
    this._value = value
    this._children = children
    return this
}

func (this *Node) Value() int {
    return this._value
}

func (this *Node) Child(i int) *Node {
    var children *array.Array[*Node] = this._children
    return children.Get(i)
}

func (this *Node) Children() *array.Array[*Node] {
    return this._children
}