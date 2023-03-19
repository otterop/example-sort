namespace Example.Sort
{
    public class Sort
    {
        private static int TEST = 111;
        static void Main(string[] args)
        {
            Otterop.Lang.String quick = Otterop.Lang.String.Wrap("quick");
            Otterop.Lang.String heap = Otterop.Lang.String.Wrap("heap");
            Otterop.Lang.Array<Otterop.Lang.String> argsArray = Otterop.Lang.Array.WrapString(args);
            if (argsArray.Size() < 1)
            {
                Otterop.Io.Console.Println(Otterop.Lang.String.Wrap("Usage: <quick|heap> ...values"));
                return ;
            }

            Otterop.Lang.String sortAlgorithm = argsArray.Get(0);
            bool isQuick = sortAlgorithm.CompareTo(quick) == 0;
            bool isHeap = sortAlgorithm.CompareTo(heap) == 0;
            if (!(isQuick || isHeap))
            {
                Otterop.Io.Console.Println(Otterop.Lang.String.Wrap("Usage: <quick|heap> ...values"));
                return ;
            }

            argsArray = argsArray.Slice(1, argsArray.Size());
            Example.Sort.Service.SortService sortService = new Example.Sort.Service.QuicksortService();
            if (isHeap)
            {
                sortService = new Example.Sort.Service.HeapsortService();
            }

            sortService.Sort(argsArray, 0, argsArray.Size());
            for (int i = 0; i < argsArray.Size(); i++)
            {
                Otterop.Io.Console.Println(argsArray.Get(i));
            }

            Otterop.Lang.Result.Of(Otterop.Lang.String.Wrap(""), Otterop.Lang.String.Wrap(""));
        }

    }

}
