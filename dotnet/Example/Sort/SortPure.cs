using Example.Sort.Service.Pure;
using Example.Sort.Tree.Pure;

namespace Example.Sort
{
    public class SortPure
    {
        static void Main(string[] args)
        {
            if (args.Length < 1)
            {
                Console.WriteLine("Usage: <quick|heap> ...values");
                return ;
            }

            var sortAlgorithm = args[0];
            bool isQuick = sortAlgorithm == "quick";
            bool isHeap = sortAlgorithm == "heap";
            if (!(isQuick || isHeap))
            {
                Console.WriteLine("Usage: <quick|heap> ...values");
                return ;
            }

            var slicedArray = new string[args.Length - 1];
            Array.Copy(args, 1, slicedArray, 0, args.Length - 1);
            SortService sortService = new QuicksortService();
            if (isHeap)
            {
                sortService = new HeapsortService();
            }

            var ret = sortService.Sort(slicedArray);
            for (int i = 0; i < ret.Length; i++)
            {
                Console.WriteLine(ret[i]);
            }

            var a = new Node(1, new Node[]{});
            var b = new Node(2, new Node[]{});
            var c = new Node(3, new Node[]{a,b});
            var d = new Node(4, new Node[]{});
            var e = new Node(5, new Node[]{});
            var f = new Node(6, new Node[]{d,e});
            var g = new Node(7, new Node[]{c,f});

            Console.WriteLine($"{g.Value()} {g.Children()}");
        }

    }

}
