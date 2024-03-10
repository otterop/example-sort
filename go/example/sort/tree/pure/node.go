package pure

import (
    otteroptree "github.com/otterop/example-sort/go/example/sort/tree"
    otteroplang "github.com/otterop/otterop/go/lang"
)

type Node struct {
    otterop *otteroptree.Node
}


func NodeWrap(otterop *otteroptree.Node) *Node {
    ret := new(Node)
    ret.otterop = otterop
    return ret
}


func NodeNew(value int, children []*Node) *Node {
    var _childrenArray = make([]*otteroptree.Node, len(children))
    for i := 0; i < len(children); i++ {
        _childrenArray[i] = children[i].Unwrap()
    }
    var _children = otteroplang.ArrayWrap(_childrenArray);
    ret := new(Node)
    ret.otterop = otteroptree.NodeNew(value, _children)
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
    ret := NodeWrap(retOtterop);
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
        ret[i] = NodeWrap(retI)
    }
    return ret
}

func (this *Node) Unwrap() *otteroptree.Node {
    return this.otterop
}
