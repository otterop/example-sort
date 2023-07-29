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

        public string[] Sort(string[] array)
        {
            var _arrayArray = new Otterop.Lang.String[array.Count()];
            for (var i = 0; i < array.Count(); i++)
            {
                _arrayArray[i] = Otterop.Lang.String.wrap(array[i]);
            }
            var _array = Otterop.Lang.Array.Wrap(_arrayArray);
            var retOtterop = otterop.Sort(_array);
            var ret = new string[retOtterop.Size()];
            for (var i = 0; i < retOtterop.Size(); i++)
            {
                var retI = retOtterop.Get(i);
                ret[i] = retI.unwrap();
            }
            return ret;
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
