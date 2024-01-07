namespace Example.Sort.Service
{
    public class TestHeapsortService : Otterop.Test.TestBase
    {
        [Otterop.Test.Test]
        public void NormalSort()
        {
            Otterop.Lang.String item;
            Otterop.Lang.Array<Otterop.Lang.String> items = Otterop.Lang.Array.NewArray(3, (Otterop.Lang.String?) null);
            items.Set(0, Otterop.Lang.String.Wrap("3"));
            items.Set(1, Otterop.Lang.String.Wrap("2"));
            items.Set(2, Otterop.Lang.String.Wrap("1"));
            SortService sortService = new HeapsortService();
            Otterop.Lang.Array<Otterop.Lang.String> itemsSorted = sortService.Sort(items);
            AssertTrue(itemsSorted.Size() == 3, Otterop.Lang.String.Wrap("itemsSorted should have size 3"));
            item = itemsSorted.Get(0);
            AssertTrue(item.CompareTo(Otterop.Lang.String.Wrap("1")) == 0, Otterop.Lang.String.Wrap("expected 1 as first element"));
            item = itemsSorted.Get(1);
            AssertTrue(item.CompareTo(Otterop.Lang.String.Wrap("2")) == 0, Otterop.Lang.String.Wrap("expected 2 as second element"));
            item = itemsSorted.Get(2);
            AssertTrue(item.CompareTo(Otterop.Lang.String.Wrap("3")) == 0, Otterop.Lang.String.Wrap("expected 3 as third element"));
        }

        [Otterop.Test.Test]
        public void SingleItem()
        {
            Otterop.Lang.String item;
            Otterop.Lang.Array<Otterop.Lang.String> items = Otterop.Lang.Array.NewArray(1, (Otterop.Lang.String?) null);
            items.Set(0, Otterop.Lang.String.Wrap("1"));
            SortService sortService = new HeapsortService();
            Otterop.Lang.Array<Otterop.Lang.String> itemsSorted = sortService.Sort(items);
            AssertTrue(itemsSorted.Size() == 1, Otterop.Lang.String.Wrap("itemsSorted should have size 1"));
            item = itemsSorted.Get(0);
            AssertTrue(item.CompareTo(Otterop.Lang.String.Wrap("1")) == 0, Otterop.Lang.String.Wrap("expected 1 as first element"));
        }

        [Otterop.Test.Test]
        public void SameItem()
        {
            Otterop.Lang.String item;
            Otterop.Lang.Array<Otterop.Lang.String> items = Otterop.Lang.Array.NewArray(3, (Otterop.Lang.String?) null);
            items.Set(0, Otterop.Lang.String.Wrap("1"));
            items.Set(1, Otterop.Lang.String.Wrap("1"));
            items.Set(2, Otterop.Lang.String.Wrap("1"));
            SortService sortService = new HeapsortService();
            Otterop.Lang.Array<Otterop.Lang.String> itemsSorted = sortService.Sort(items);
            AssertTrue(itemsSorted.Size() == 3, Otterop.Lang.String.Wrap("itemsSorted should have size 3"));
            item = itemsSorted.Get(0);
            AssertTrue(item.CompareTo(Otterop.Lang.String.Wrap("1")) == 0, Otterop.Lang.String.Wrap("expected 1 as first element"));
            item = itemsSorted.Get(1);
            AssertTrue(item.CompareTo(Otterop.Lang.String.Wrap("1")) == 0, Otterop.Lang.String.Wrap("expected 1 as second element"));
            item = itemsSorted.Get(2);
            AssertTrue(item.CompareTo(Otterop.Lang.String.Wrap("1")) == 0, Otterop.Lang.String.Wrap("expected 1 as third element"));
        }

    }

}
