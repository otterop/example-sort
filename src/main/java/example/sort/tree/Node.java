package example.sort.tree;

import otterop.lang.Array;
import otterop.lang.MakePure;

@MakePure
public class Node {

    private Array<Node> _children;

    private int _value;

    public Node(int value, Array<Node> children) {
        this._value = value;
        this._children = children;
    }

    public int value() {
        return this._value;
    }

    public Node child(int i) {
        Array<Node> children = this._children;
        return children.get(i);
    }

    public Array<Node> children() {
        return this._children;
    }
}
