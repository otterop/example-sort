import { Array } from '@otterop/lang/array';
import { String } from '@otterop/lang/string';

export class QuicksortService {

    static swap(array : Array<String>, fromIdx : number, toIdx : number) : void {
        let tmp = array.get(toIdx);
        array.set(toIdx, array.get(fromIdx));
        array.set(fromIdx, tmp);
    }

    public static quickSort(array : Array<String>, fromIdx : number, toIdx : number) : void {
        let i = fromIdx;
        let swapWith = -1;
        let pivot = toIdx - 1;
        
        while (i < pivot) {
            let iString = array.get(i);
            let pivotString = array.get(pivot);
            let lessThan = iString.compareTo(pivotString) < 0;
            
            if (swapWith >= 0 && lessThan) {
                QuicksortService.swap(array, swapWith, i);
                swapWith = swapWith + 1;
            } else if (swapWith < 0 && !lessThan) {
                swapWith = i;
            }
            i = i + 1;
        }
        
        if (swapWith >= 0 && swapWith < pivot) {
            let swapWithString = array.get(swapWith);
            let pivotString = array.get(pivot);
            
            if (swapWithString.compareTo(pivotString) >= 0) {
                QuicksortService.swap(array, swapWith, pivot);
                pivot = swapWith;
            }
        }
        
        if (pivot > fromIdx + 1) {
            QuicksortService.quickSort(array, fromIdx, pivot);
        }
        
        if (pivot + 1 < toIdx - 1) {
            QuicksortService.quickSort(array, pivot + 1, toIdx);
        }
    }
}

