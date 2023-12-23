import { String as StringOtterOP } from '@otterop/lang/string';
import { Array as ArrayOtterOP } from '@otterop/lang/array';
import { QuicksortService as QuicksortServiceOtterOP } from '../QuicksortService';
import { SortService } from './SortService';

export class QuicksortService implements SortService {

    private otterop : QuicksortServiceOtterOP;

    public static wrap(otterop :QuicksortServiceOtterOP) : QuicksortService {
        return new QuicksortService(otterop);
    }

    public constructor();
    public constructor(wrapped : QuicksortServiceOtterOP);
    public constructor(...__args: any[]) {
        if (__args.length === 1 && __args[0] instanceof QuicksortServiceOtterOP) {
            this.otterop = __args[0];
            return;
        }
        this.otterop = new QuicksortServiceOtterOP();
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

    public unwrap() : QuicksortServiceOtterOP {
        return this.otterop;
    }
}

