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
