package example.sort;

import example.sort.service.QuicksortService;
import example.sort.service.SortService;
import otterop.lang.Array;
import otterop.lang.String;
import otterop.lang.Result;

import static otterop.io.Console.println;

public class Sort {

    public static void main(java.lang.String[] args) {
        Array<String> argsArray = Array.wrapString(args);
        SortService sortService = new QuicksortService();
        sortService.sort(argsArray, 0, argsArray.size());
        for (int i = 0; i< argsArray.size(); i++) {
            println(argsArray.get(i));
        }
        Result.of(String.wrap(""), String.wrap(""));
    }
}
