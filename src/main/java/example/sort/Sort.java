package example.sort;

import example.sort.service.HeapsortService;
import example.sort.service.QuicksortService;
import example.sort.service.SortService;
import otterop.lang.Array;
import otterop.lang.String;
import otterop.lang.Result;

import static otterop.io.Console.println;

public class Sort {

    public static int TEST = 111;

    public static void main(java.lang.String[] args) {
        String quick = String.wrap("quick");
        String heap = String.wrap("heap");

        Array<String> argsArray = Array.wrapString(args);

        if (argsArray.size() < 1) {
            println(String.wrap("Usage: <quick|heap> ...values"));
            return;
        }

        String sortAlgorithm = argsArray.get(0);

        boolean isQuick = sortAlgorithm.compareTo(quick) == 0;
        boolean isHeap = sortAlgorithm.compareTo(heap) == 0;

        if (!(isQuick || isHeap)) {
            println(String.wrap("Usage: <quick|heap> ...values"));
            return;
        }

        argsArray = argsArray.slice(1, argsArray.size());

        SortService sortService = new QuicksortService();
        if (isHeap) {
            sortService = new HeapsortService();
        }

        Array<String> ret = sortService.sort(argsArray);
        for (int i = 0; i< ret.size(); i++) {
            println(ret.get(i));
        }
        Result.of(String.wrap(""), String.wrap(""));
    }
}
