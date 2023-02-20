package example.quicksort;

import example.quicksort.service.QuicksortService;
import otterop.lang.Array;
import otterop.lang.String;
import otterop.lang.Result;

import static otterop.io.Console.println;

public class Quicksort {

    public static void main(java.lang.String[] args) {
        Array<String> argsArray = Array.wrapString(args);
        QuicksortService.quickSort(argsArray, 0, argsArray.size());
        int i = 0;
        while (i< argsArray.size()) {
            println(argsArray.get(i));
            i = i + 1;
        }
        Result.of(String.wrap(""), String.wrap(""));
    }
}
