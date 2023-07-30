package example.sort.tree.pure;

public class Node {
    private final example.sort.tree.Node _otterop;

    private Node(example.sort.tree.Node wrapped) {
        this._otterop = wrapped;
    }

    public Node(int value, example.sort.tree.pure.Node[] children) {
        var _childrenArray = new example.sort.tree.Node[children.length];
        for (var i = 0; i < children.length; i++) {
            _childrenArray[i] = children[i].unwrap();
        }
        var _children = otterop.lang.Array.wrap(_childrenArray);
        this._otterop = new example.sort.tree.Node(value, _children);
    }

    public int value() {
        var retOtterop = _otterop.value();
        var ret = retOtterop;
        return ret;
    }

    public example.sort.tree.pure.Node child(int i) {
        var retOtterop = _otterop.child(i);
        if (retOtterop == this._otterop) return this;
        var ret = example.sort.tree.pure.Node.wrap(retOtterop);
        return ret;
    }

    public example.sort.tree.pure.Node[] children() {
        var retOtterop = _otterop.children();
        var ret = new example.sort.tree.pure.Node[retOtterop.size()];
        for (var i = 0; i < retOtterop.size(); i++) {
            var retI = retOtterop.get(i);
            if (retI == this._otterop) {
                ret[i] = this;
                continue;
            }
            ret[i] = example.sort.tree.pure.Node.wrap(retI);
        }
        return ret;
    }

    public example.sort.tree.Node unwrap() {
        return this._otterop;
    }

    public static example.sort.tree.pure.Node wrap(example.sort.tree.Node wrapped) {
        return new example.sort.tree.pure.Node(wrapped);
    }
}

