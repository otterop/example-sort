package example.sort.tree;

import otterop.lang.Array;
import otterop.lang.MakePure;

@MakePure
public class Node {

    private Array<Node> children;

    public Node(Array<Node> children) {
        this.children = children;
    }

    public Node child(int i) {
        Array<Node> children = this.children;
        return children.get(i);
    }

    public Array<Node> children() {
        return this.children;
    }
}
