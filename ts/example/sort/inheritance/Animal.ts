import { Node } from '../tree/Node';
import { String } from '@otterop/lang/String';

export class Animal {

    private _word : String;

    public constructor(word : String) {
        this._word = word;
    }

    public act() : String {
        return this._word;
    }

    public species() : String {
        return String.wrap("unknown");
    }
}

