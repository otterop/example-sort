"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const array_1 = require("@otterop/lang/array");
const string_1 = require("@otterop/lang/string");
const console_1 = require("@otterop/io/console");
const { println } = console_1.Console;
class Quicksort {
    hello() {
        println(string_1.String.wrap("world"));
    }
    static swap(array, fromIdx, toIdx) {
        let tmp = array.get(toIdx);
        array.set(toIdx, array.get(fromIdx));
        array.set(fromIdx, tmp);
    }
    static quickSort(array, fromIdx, toIdx) {
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
            }
            else if (swapWith < 0 && !lessThan) {
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
        }
        else {
            println(string_1.String.wrap("foo"));
        }
    }
    static main(args) {
        let argsArray = array_1.Array.wrapString(args);
        Quicksort.quickSort(argsArray, 0, argsArray.size());
        let i = 0;
        if (argsArray.size() > 0) {
            argsArray.set(0, string_1.String.wrap("bbbb"));
        }
        while (i < argsArray.size()) {
            println(argsArray.get(i));
            i = i + 1;
        }
        let p = new Quicksort(2, 4.0, string_1.String.wrap("hello world"));
        p.hello();
        println(p.string());
    }
    constructor(a, b, c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }
    string() {
        return this.c;
    }
}
Quicksort.main(process.argv.slice(2));
