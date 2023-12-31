import { Array } from '@otterop/lang/Array';

export class Node {

    private __children : Array<Node>;

    private __value : number;

    public constructor(value : number, children : Array<Node>) {
        this.__value = value;
        this.__children = children;
    }

    public value() : number {
        return this.__value;
    }

    public child(i : number) : Node {
        let children : Array<Node> = this.__children;
        return children.get(i);
    }

    public children() : Array<Node> {
        return this.__children;
    }
}

