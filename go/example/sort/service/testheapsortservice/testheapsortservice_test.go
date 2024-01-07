package testheapsortservice

import (
    "testing"
    array "github.com/otterop/otterop/go/lang/array"
    string "github.com/otterop/otterop/go/lang/string"
    testbase "github.com/otterop/otterop/go/test/testbase"
    "github.com/otterop/example-sort/go/example/sort/service/sortservice"
    "github.com/otterop/example-sort/go/example/sort/service/heapsortservice"
)


func NewTestHeapsortService() *TestHeapsortService {
    this := new(TestHeapsortService)
    this.TestBase = testbase.NewTestBase()
    return this
}

type TestHeapsortService struct {
    *testbase.TestBase
}




func (this *TestHeapsortService) NormalSort()  {
    var item *string.String
    var items *array.Array[*string.String] = array.NewArray(3, (*string.String)(nil))
    items.Set(0, string.Wrap(string.Literal("3")))
    items.Set(1, string.Wrap(string.Literal("2")))
    items.Set(2, string.Wrap(string.Literal("1")))
    var sortService sortservice.SortService = heapsortservice.NewHeapsortService()
    var itemsSorted *array.Array[*string.String] = sortService.Sort(items)
    this.AssertTrue(itemsSorted.Size() == 3, string.Wrap(string.Literal("itemsSorted should have size 3")))
    item = itemsSorted.Get(0)
    this.AssertTrue(item.CompareTo(string.Wrap(string.Literal("1"))) == 0, string.Wrap(string.Literal("expected 1 as first element")))
    item = itemsSorted.Get(1)
    this.AssertTrue(item.CompareTo(string.Wrap(string.Literal("2"))) == 0, string.Wrap(string.Literal("expected 2 as second element")))
    item = itemsSorted.Get(2)
    this.AssertTrue(item.CompareTo(string.Wrap(string.Literal("3"))) == 0, string.Wrap(string.Literal("expected 3 as third element")))
}

func (this *TestHeapsortService) SingleItem()  {
    var item *string.String
    var items *array.Array[*string.String] = array.NewArray(1, (*string.String)(nil))
    items.Set(0, string.Wrap(string.Literal("1")))
    var sortService sortservice.SortService = heapsortservice.NewHeapsortService()
    var itemsSorted *array.Array[*string.String] = sortService.Sort(items)
    this.AssertTrue(itemsSorted.Size() == 1, string.Wrap(string.Literal("itemsSorted should have size 1")))
    item = itemsSorted.Get(0)
    this.AssertTrue(item.CompareTo(string.Wrap(string.Literal("1"))) == 0, string.Wrap(string.Literal("expected 1 as first element")))
}

func (this *TestHeapsortService) SameItem()  {
    var item *string.String
    var items *array.Array[*string.String] = array.NewArray(3, (*string.String)(nil))
    items.Set(0, string.Wrap(string.Literal("1")))
    items.Set(1, string.Wrap(string.Literal("1")))
    items.Set(2, string.Wrap(string.Literal("1")))
    var sortService sortservice.SortService = heapsortservice.NewHeapsortService()
    var itemsSorted *array.Array[*string.String] = sortService.Sort(items)
    this.AssertTrue(itemsSorted.Size() == 3, string.Wrap(string.Literal("itemsSorted should have size 3")))
    item = itemsSorted.Get(0)
    this.AssertTrue(item.CompareTo(string.Wrap(string.Literal("1"))) == 0, string.Wrap(string.Literal("expected 1 as first element")))
    item = itemsSorted.Get(1)
    this.AssertTrue(item.CompareTo(string.Wrap(string.Literal("1"))) == 0, string.Wrap(string.Literal("expected 1 as second element")))
    item = itemsSorted.Get(2)
    this.AssertTrue(item.CompareTo(string.Wrap(string.Literal("1"))) == 0, string.Wrap(string.Literal("expected 1 as third element")))
}

func Test(t *testing.T) {
    t.Run("NormalSort", func(t *testing.T) {
        test := NewTestHeapsortService()
        test.SetGoTestingT(t)
        test.NormalSort()
    })
    t.Run("SingleItem", func(t *testing.T) {
        test := NewTestHeapsortService()
        test.SetGoTestingT(t)
        test.SingleItem()
    })
    t.Run("SameItem", func(t *testing.T) {
        test := NewTestHeapsortService()
        test.SetGoTestingT(t)
        test.SameItem()
    })
}
