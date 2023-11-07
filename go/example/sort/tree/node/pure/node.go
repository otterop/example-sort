package pure

import (
    otteropnode "github.com/otterop/example-sort/go/example/sort/tree/node"
    otteroparray "github.com/otterop/otterop/go/lang/array"
)

type Node struct {
    otterop *otteropnode.Node
}


func Wrap(otterop *otteropnode.Node) *Node {
    ret := new(Node)
    ret.otterop = otterop
    return ret
}


func NewNode(value int, children []*Node) *Node {
    var _childrenArray = make([]*otteropnode.Node, len(children))
    for i := 0; i < len(children); i++ {
        _childrenArray[i] = children[i].Unwrap()
    }
    var _children = otteroparray.Wrap(_childrenArray);
    ret := new(Node)
    ret.otterop = otteropnode.NewNode(value, _children)
    return ret
}



func (this *Node) Value() int {
    retOtterop := this.otterop.Value()
    ret := retOtterop
    return ret
}



func (this *Node) Child(i int) *Node {
    retOtterop := this.otterop.Child(i)
    if retOtterop == this.otterop { return this }
    ret := Wrap(retOtterop);
    return ret
}



func (this *Node) Children() []*Node {
    retOtterop := this.otterop.Children()
    ret := make([]*Node, retOtterop.Size())
    for i := 0; i < retOtterop.Size(); i++ {
        retI := retOtterop.Get(i)
        if retI == this.otterop {
            ret[i] = this
            continue
        }
        ret[i] = Wrap(retI)
    }
    return ret
}

func (this *Node) Unwrap() *otteropnode.Node {
    return this.otterop
}
