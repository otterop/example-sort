import { String as StringOtterOP } from '@otterop/lang/string';
import { Array as ArrayOtterOP } from '@otterop/lang/array';
import { HeapsortService as HeapsortServiceOtterOP } from '../HeapsortService';
import { SortService } from './SortService';

export class HeapsortService implements SortService {

    private otterop : HeapsortServiceOtterOP;

    public static wrap(otterop :HeapsortServiceOtterOP) : HeapsortService {
        return new HeapsortService(otterop);
    }

    public constructor();
    public constructor(wrapped : HeapsortServiceOtterOP);
    public constructor(...__args: any[]) {
        if (__args.length === 1 && __args[0] instanceof HeapsortServiceOtterOP) {
            this.otterop = __args[0];
            return;
        }
        this.otterop = new HeapsortServiceOtterOP();
    }

    public sort(array : string[]) : string[] {
        const _arrayArray = new Array(array.length);
        for (let i = 0; i < array.length; i++) {
            _arrayArray[i] = StringOtterOP.wrap(array[i])
        }
        const _array = ArrayOtterOP.wrap(_arrayArray);
        const retOtterop = this.otterop.sort(_array);
        const ret = new Array(retOtterop.size());
        for (let i = 0; i < ret.length; i++) {
            const retI = retOtterop.get(i);
            ret[i] = retI.unwrap();
        }
        return ret;
    }

    public unwrap() : HeapsortServiceOtterOP {
        return this.otterop;
    }
}

