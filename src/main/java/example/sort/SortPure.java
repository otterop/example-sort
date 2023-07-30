package example.sort;

import example.sort.service.pure.HeapsortService;
import example.sort.service.pure.QuicksortService;
import example.sort.service.pure.SortService;
import example.sort.tree.pure.Node;

public class SortPure {

    public static void main(String[] args) {
        if (args.length < 1) {
            System.out.println("Usage: <quick|heap> ...values");
            return;
        }

        String sortAlgorithm = args[0];

        boolean isQuick = sortAlgorithm.compareTo("quick") == 0;
        boolean isHeap = sortAlgorithm.compareTo("heap") == 0;

        if (!(isQuick || isHeap)) {
            System.out.println("Usage: <quick|heap> ...values");
            return;
        }

        var slicedArray = new String[args.length - 1];
        System.arraycopy(args, 1, slicedArray, 0, args.length - 1);

        SortService sortService = new QuicksortService();
        if (isHeap) {
            sortService = new HeapsortService();
        }

        String[] ret = sortService.sort(slicedArray);
        for (int i = 0; i< ret.length; i++) {
            System.out.println(ret[i]);
        }

        var a = new Node(1, new Node[]{});
        var b = new Node(2, new Node[]{});
        var c = new Node(3, new Node[]{a,b});
        var d = new Node(4, new Node[]{});
        var e = new Node(5, new Node[]{});
        var f = new Node(6, new Node[]{d,e});
        var g = new Node(7, new Node[]{c,f});

        System.out.println(g.value() + " " + g.children().length);
    }
}
