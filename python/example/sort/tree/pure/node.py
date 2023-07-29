import otterop.lang.array
import example.sort.tree.node

class Node:
    def __init__(self, value, children):
        _children_array = [None] * len(children)
        for i in range(len(children)):
            _children_array[i] = children[i].unwrap()
        _children = otterop.lang.array.Array.wrap(_children_array)
        self.otterop = example.sort.tree.node.Node(value, _children)

    def value(self):
        ret_otterop = self.otterop.value()
        ret = ret_otterop
        return ret


    def child(self, i):
        ret_otterop = self.otterop.child(i)
        if ret_otterop is self.otterop:
            return self
        ret = example.sort.tree.pure.node.Node.wrap(ret_otterop)
        return ret


    def children(self):
        ret_otterop = self.otterop.children()
        ret = [None] * ret_otterop.size()
        for i in range(len(ret)):
            ret_i = ret_otterop.get(i)
            if ret_i is self.otterop:
                ret[i] = self
                continue
            ret[i] = example.sort.tree.pure.node.Node.wrap(ret_i)
        return ret

    def unwrap(self):
        return self.otterop

    @staticmethod
    def wrap(wrapped):
        ret = example.sort.tree.pure.node.Node.__new__(example.sort.tree.pure.node.Node)
        ret.otterop = wrapped
        return ret
