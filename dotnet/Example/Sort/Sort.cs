namespace Example.Sort
{
    public class Sort
    {
        public static void Main(string[] args)
        {
            Otterop.Lang.Array<Otterop.Lang.String> argsArray = Otterop.Lang.Array.WrapString(args);
            Example.Sort.Service.SortService sortService = new Example.Sort.Service.QuicksortService();
            sortService.Sort(argsArray, 0, argsArray.Size());
            for (int i = 0; i < argsArray.Size(); i++)
            {
                Otterop.Io.Console.Println(argsArray.Get(i));
            }

            Otterop.Lang.Result.Of(Otterop.Lang.String.Wrap(""), Otterop.Lang.String.Wrap(""));
        }

    }

}
