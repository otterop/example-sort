import { Array } from '@otterop/lang/array';
import { String } from '@otterop/lang/string';
import { Console } from '@otterop/io/console';
const { println } = Console;

class Quicksort {

    public hello() : void {
        println(String.wrap("world"));
    }

    static swap(array : Array<String>, fromIdx : number, toIdx : number) : void {
        let tmp = array.get(toIdx);
        array.set(toIdx, array.get(fromIdx));
        array.set(fromIdx, tmp);
    }

    a : number;

    public static quickSort(array : Array<String>, fromIdx : number, toIdx : number) : void {
        let i = fromIdx;
        let swapWith = -1;
        let pivot = toIdx - 1;
        
        while (i < pivot) {
            let iString = array.get(i);
            let pivotString = array.get(pivot);
            let lessThan = iString.compareTo(pivotString) < 0;
            
            if (swapWith >= 0 && lessThan) {
                Quicksort.swap(array, swapWith, i);
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
                Quicksort.swap(array, swapWith, pivot);
                pivot = swapWith;
            }
        }
        
        if (pivot > fromIdx + 1) {
            Quicksort.quickSort(array, fromIdx, pivot);
        }
        
        if (pivot + 1 < toIdx - 1) {
            Quicksort.quickSort(array, pivot + 1, toIdx);
        } else {
            println(String.wrap("foo"));
        }
    }

    b : number;

    public static main(args : string[]) : void {
        let argsArray = Array.wrapString(args);
        Quicksort.quickSort(argsArray, 0, argsArray.size());
        let i = 0;
        
        if (argsArray.size() > 0) {
            argsArray.set(0, String.wrap("bbbb"));
        }
        
        while (i < argsArray.size()) {
            println(argsArray.get(i));
            i = i + 1;
        }
        let p = new Quicksort(2, 4.0, String.wrap("hello world"));
        p.hello();
        println(p.string());
    }

    public constructor(a : number, b : number, c : String) {
        this.a = a;
        this.b = b;
        this.c = c;
    }

    c : String;

    public string() : String {
        return this.c;
    }
}

Quicksort.main(process.argv.slice(2));