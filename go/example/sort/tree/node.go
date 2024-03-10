package tree

import (
    lang "github.com/otterop/otterop/go/lang"
)


type Node struct {
    _children *lang.Array[*Node]
    _value int
}




func NodeNew(value int, children *lang.Array[*Node]) *Node {
    this := new(Node)
    this._value = value
    this._children = children
    return this
}

func (this *Node) Value() int {
    return this._value
}

func (this *Node) Child(i int) *Node {
    var children *lang.Array[*Node] = this._children
    return children.Get(i)
}

func (this *Node) Children() *lang.Array[*Node] {
    return this._children
}