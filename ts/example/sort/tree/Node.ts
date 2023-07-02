import { Array } from '@otterop/lang/array';

export class Node {

    private _children : Array<Node>;

    public constructor(children : Array<Node>) {
        this._children = children;
    }

    public child(i : number) : Node {
        let children : Array<Node> = this._children;
        return children.get(i);
    }

    public children() : Array<Node> {
        return this._children;
    }
}

