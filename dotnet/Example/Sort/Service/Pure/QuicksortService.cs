namespace Example.Sort.Service.Pure
{
    public class QuicksortService : Example.Sort.Service.Pure.SortService
    {
        private Example.Sort.Service.QuicksortService otterop;

        private QuicksortService(Example.Sort.Service.QuicksortService wrapped)
        {
            this.otterop = wrapped;
        }
        public QuicksortService()
        {
            this.otterop = new Example.Sort.Service.QuicksortService();
        }

        public void Sort(string[] array, int fromIdx, int toIdx)
        {
            var _arrayArray = new Otterop.Lang.String[array.Count()];
            for (var i = 0; i < array.Count(); i++)
            {
                _arrayArray[i] = Otterop.Lang.String.wrap(array[i]);
            }
            var _array = Otterop.Lang.Array.Wrap(_arrayArray);
            otterop.Sort(_array, fromIdx, toIdx);
        }

        public Example.Sort.Service.QuicksortService unwrap()
        {
            return this.otterop;
        }

        public static Example.Sort.Service.Pure.QuicksortService wrap(Example.Sort.Service.QuicksortService wrapped)
        {
            return new Example.Sort.Service.Pure.QuicksortService(wrapped);
        }
    }

}
