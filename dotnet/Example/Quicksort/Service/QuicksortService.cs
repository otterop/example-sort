namespace Example.Quicksort.Service
{
    public class QuicksortService
    {
        static void Swap(Otterop.Lang.Array<Otterop.Lang.String> array, int fromIdx, int toIdx)
        {
            Otterop.Lang.String tmp = array.Get(toIdx);
            array.Set(toIdx, array.Get(fromIdx));
            array.Set(fromIdx, tmp);
        }

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

        }

    }

}
