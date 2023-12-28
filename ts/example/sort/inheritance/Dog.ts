import { String } from '@otterop/lang/string';
import { Animal } from './Animal';

export class Dog extends Animal {

    private _dogWord : String;

    public constructor() {
        super(String.wrap("I don't know"));
        this._dogWord = String.wrap("bark");
    }

    public act() : String {
        super.act();
        return this._dogWord;
    }
}

