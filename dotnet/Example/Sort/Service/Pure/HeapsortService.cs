namespace Example.Sort.Service.Pure
{
    public class HeapsortService : Example.Sort.Service.Pure.SortService
    {
        private Example.Sort.Service.HeapsortService otterop;

        private HeapsortService(Example.Sort.Service.HeapsortService wrapped)
        {
            this.otterop = wrapped;
        }
        public HeapsortService()
        {
            this.otterop = new Example.Sort.Service.HeapsortService();
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

        public Example.Sort.Service.HeapsortService unwrap()
        {
            return this.otterop;
        }

        public static Example.Sort.Service.Pure.HeapsortService wrap(Example.Sort.Service.HeapsortService wrapped)
        {
            return new Example.Sort.Service.Pure.HeapsortService(wrapped);
        }
    }

}
