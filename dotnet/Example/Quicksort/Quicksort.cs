namespace Example.Quicksort
{
    class Quicksort
    {
        public static void Main(string[] args)
        {
            Otterop.Lang.Array<Otterop.Lang.String> argsArray = Otterop.Lang.Array.WrapString(args);
            Example.Quicksort.Service.QuicksortService.QuickSort(argsArray, 0, argsArray.Size());
            int i = 0;
            while (i < argsArray.Size())
            {
                Otterop.Io.Console.Println(argsArray.Get(i));
                i = i + 1;
            }

        }

    }

}
