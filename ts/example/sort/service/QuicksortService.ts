import { Array } from '@otterop/lang/array';
import { String } from '@otterop/lang/string';

export class QuicksortService {

    public constructor() {
    }

    swap(array : Array<String>, fromIdx : number, toIdx : number) : void {
        let tmp : String = array.get(toIdx);
        array.set(toIdx, array.get(fromIdx));
        array.set(fromIdx, tmp);
    }

    sortWithIndices(array : Array<String>, fromIdx : number, toIdx : number) : void {
        let i : number = fromIdx;
        let swapWith : number = -1;
        let pivot : number = toIdx - 1;
        
        while (i < pivot) {
            let iString : String = array.get(i);
            let pivotString : String = array.get(pivot);
            let lessThan : boolean = iString.compareTo(pivotString) < 0;
            
            if (swapWith >= 0 && lessThan) {
                this.swap(array, swapWith, i);
                swapWith = swapWith + 1;
            } else if (swapWith < 0 && !lessThan) {
                swapWith = i;
            }
            i = i + 1;
        }
        
        if (swapWith >= 0 && swapWith < pivot) {
            let swapWithString : String = array.get(swapWith);
            let pivotString : String = array.get(pivot);
            
            if (swapWithString.compareTo(pivotString) >= 0) {
                this.swap(array, swapWith, pivot);
                pivot = swapWith;
            }
        }
        
        if (pivot > fromIdx + 1) {
            this.sortWithIndices(array, fromIdx, pivot);
        }
        
        if (pivot + 1 < toIdx - 1) {
            this.sortWithIndices(array, pivot + 1, toIdx);
        }
    }

    public sort(array : Array<String>) : Array<String> {
        this.sortWithIndices(array, 0, array.size());
        return array;
    }
}

