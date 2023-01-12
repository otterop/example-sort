package example.quicksort;

import otterop.lang.Array;
import otterop.lang.String;

import static otterop.io.Console.println;

public class Quicksort {

    public void hello() {
        println(String.wrap("world"));
    }

    private static void swap(Array<String> array, int fromIdx, int toIdx) {
        String tmp = array.get(toIdx);
        array.set(toIdx, array.get(fromIdx));
        array.set(fromIdx, tmp);
    }

    private int a;

    public static void quickSort(Array<String> array, int fromIdx, int toIdx) {
        int i = fromIdx;
        int swapWith = -1;
        int pivot = toIdx - 1;
        while (i < pivot) {
            String iString = array.get(i);
            String pivotString = array.get(pivot);
            boolean lessThan = iString.compareTo(pivotString) < 0;
            if (swapWith >= 0 && lessThan) {
                Quicksort.swap(array, swapWith, i);
                swapWith = swapWith + 1;
            } else if (swapWith < 0 && !lessThan) {
                swapWith = i;
            }
            i = i + 1;
        }
        if (swapWith >= 0 && swapWith < pivot) {
            String swapWithString = array.get(swapWith);
            String pivotString = array.get(pivot);
            if(swapWithString.compareTo(pivotString) >= 0) {
                Quicksort.swap(array, swapWith, pivot);
                pivot = swapWith;
            }
        }
        if(pivot > fromIdx + 1) {
            Quicksort.quickSort(array, fromIdx, pivot);
        }
        if (pivot + 1 < toIdx - 1) {
            Quicksort.quickSort(array, pivot + 1, toIdx);
        } else {
            println(String.wrap("foo"));
        }
    }

    private double b;

    public static void main(java.lang.String[] args) {
        Array<String> argsArray = Array.wrapString(args);
        Quicksort.quickSort(argsArray, 0, argsArray.size());
        int i = 0;
        if (argsArray.size() > 0) {
            argsArray.set(0, String.wrap("bbbb"));
        }
        while (i< argsArray.size()) {
            println(argsArray.get(i));
            i = i + 1;
        }

        Quicksort p = new Quicksort(2, 4.0, String.wrap("hello world"));
        p.hello();
        println(p.string());
    }

    public Quicksort(int a, double b, String c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }

    private String c;

    public String string() {
        return this.c;
    }
}
