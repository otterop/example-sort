namespace Example.Sort.Service
{
    public class HeapsortService : SortService
    {
        public HeapsortService()
        {
        }

        void Swap(Otterop.Lang.Array<Otterop.Lang.String> array, int fromIdx, int toIdx)
        {
            Otterop.Lang.String tmp = array.Get(toIdx);
            array.Set(toIdx, array.Get(fromIdx));
            array.Set(fromIdx, tmp);
        }

        void Heapify(Otterop.Lang.Array<Otterop.Lang.String> array, int parent, int size)
        {
            int largest = parent;
            int leftChild = parent * 2 + 1;
            int rightChild = parent * 2 + 2;
            if (leftChild < size)
            {
                Otterop.Lang.String leftS = array.Get(leftChild);
                if (leftS.CompareTo(array.Get(largest)) > 0)
                {
                    largest = leftChild;
                }

            }

            if (rightChild < size)
            {
                Otterop.Lang.String rightS = array.Get(rightChild);
                if (rightS.CompareTo(array.Get(largest)) > 0)
                {
                    largest = rightChild;
                }

            }

            if (largest != parent)
            {
                Swap(array, parent, largest);
                Heapify(array, largest, size);
            }

        }

        void SortWithIndices(Otterop.Lang.Array<Otterop.Lang.String> array, int fromIdx, int toIdx)
        {
            int n = array.Size();
            for (int i = n / 2 - 1; i >= 0; i--)
            {
                Heapify(array, i, n);
            }

            for (int i = n - 1; i >= 0; i--)
            {
                Swap(array, 0, i);
                Heapify(array, 0, i);
            }

        }

        public Otterop.Lang.Array<Otterop.Lang.String> Sort(Otterop.Lang.Array<Otterop.Lang.String> array)
        {
            SortWithIndices(array, 0, array.Size());
            return array;
        }

    }

}
