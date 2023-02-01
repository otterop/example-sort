namespace Example.Quicksort
{
    class Quicksort
    {
        public void Hello()
        {
            Otterop.Io.Console.Println(Otterop.Lang.String.Wrap("world"));
        }

        static void Swap(Otterop.Lang.Array<Otterop.Lang.String> array, int fromIdx, int toIdx)
        {
            Otterop.Lang.String tmp = array.Get(toIdx);
            array.Set(toIdx, array.Get(fromIdx));
            array.Set(fromIdx, tmp);
        }

        int a;
        public static void QuickSort(Otterop.Lang.Array<Otterop.Lang.String> array, int fromIdx, int toIdx)
        {
            int i = fromIdx;
            int swapWith = -1;
            int pivot = toIdx - 1;
            while (i < pivot)
            {
                Otterop.Lang.String iString = array.Get(i);
                Otterop.Lang.String pivotString = array.Get(pivot);
                bool lessThan = iString.CompareTo(pivotString) < 0;
                if (swapWith >= 0 && lessThan)
                {
                    Swap(array, swapWith, i);
                    swapWith = swapWith + 1;
                }
                else if (swapWith < 0 && !lessThan)
                {
                    swapWith = i;
                }

                i = i + 1;
            }

            if (swapWith >= 0 && swapWith < pivot)
            {
                Otterop.Lang.String swapWithString = array.Get(swapWith);
                Otterop.Lang.String pivotString = array.Get(pivot);
                if (swapWithString.CompareTo(pivotString) >= 0)
                {
                    Swap(array, swapWith, pivot);
                    pivot = swapWith;
                }

            }

            if (pivot > fromIdx + 1)
            {
                QuickSort(array, fromIdx, pivot);
            }

            if (pivot + 1 < toIdx - 1)
            {
                QuickSort(array, pivot + 1, toIdx);
            }
            else
            {
                Otterop.Io.Console.Println(Otterop.Lang.String.Wrap("foo"));
            }

        }

        double b;
        public static void Main(string[] args)
        {
            Otterop.Lang.Array<Otterop.Lang.String> argsArray = Otterop.Lang.Array.WrapString(args);
            QuickSort(argsArray, 0, argsArray.Size());
            int i = 0;
            if (argsArray.Size() > 0)
            {
                argsArray.Set(0, Otterop.Lang.String.Wrap("bbbb"));
            }

            while (i < argsArray.Size())
            {
                Otterop.Io.Console.Println(argsArray.Get(i));
                i = i + 1;
            }

            Quicksort p = new Quicksort(2, 4.0, Otterop.Lang.String.Wrap("hello world"));
            p.Hello();
            Otterop.Io.Console.Println(p.String());
        }

        public Quicksort(int a, double b, Otterop.Lang.String c)
        {
            this.a = a;
            this.b = b;
            this.c = c;
        }

        Otterop.Lang.String c;
        public Otterop.Lang.String String()
        {
            return this.c;
        }

    }

}
