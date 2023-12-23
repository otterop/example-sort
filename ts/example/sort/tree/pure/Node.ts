import { String as StringOtterOP } from '@otterop/lang/string';
import { Array as ArrayOtterOP } from '@otterop/lang/array';
import { Node as NodeOtterOP } from '../Node';

export class Node {

    private otterop : NodeOtterOP;

    public static wrap(otterop :NodeOtterOP) : Node {
        return new Node(otterop);
    }

    public constructor(value : number, children : Node[]);
    public constructor(wrapped : NodeOtterOP);
    public constructor(...__args: any[]) {
        if (__args.length === 1 && __args[0] instanceof NodeOtterOP) {
            this.otterop = __args[0];
            return;
        }
        const [value, children] = __args;
        const _childrenArray = new Array(children.length);
        for (let i = 0; i < children.length; i++) {
            _childrenArray[i] = children[i].unwrap()
        }
        const _children = ArrayOtterOP.wrap(_childrenArray);
        this.otterop = new NodeOtterOP(value, _children);
    }

    public value() : number {
        const retOtterop = this.otterop.value();
        const ret = retOtterop;
        return ret;
    }


    public child(i : number) : Node {
        const retOtterop = this.otterop.child(i);
        if (Object.is(retOtterop, this.otterop)) {
            return this;
        }
        const ret = Node.wrap(retOtterop);
        return ret;
    }


    public children() : Node[] {
        const retOtterop = this.otterop.children();
        const ret = new Array(retOtterop.size());
        for (let i = 0; i < ret.length; i++) {
            const retI = retOtterop.get(i);
            if (Object.is(retI, this.otterop)) {
                ret[i] = this;
                continue;
            }
            ret[i] = Node.wrap(retI);
        }
        return ret;
    }

    public unwrap() : NodeOtterOP {
        return this.otterop;
    }
}

