package service

import (
    "testing"
    lang "github.com/otterop/otterop/go/lang"
    test "github.com/otterop/otterop/go/test"
)


func testQuicksortServiceNew() *TestQuicksortService {
    this := new(TestQuicksortService)
    this.TestBase = test.TestBaseNew()
    return this
}

type TestQuicksortService struct {
    *test.TestBase
}




func (this *TestQuicksortService) normalSort()  {
    var item *lang.String
    var items *lang.Array[*lang.String] = lang.ArrayNewArray(3, (*lang.String)(nil))
    items.Set(0, lang.StringWrap(lang.StringLiteral("3")))
    items.Set(1, lang.StringWrap(lang.StringLiteral("2")))
    items.Set(2, lang.StringWrap(lang.StringLiteral("1")))
    var sortService SortService = QuicksortServiceNew()
    var itemsSorted *lang.Array[*lang.String] = sortService.Sort(items)
    this.AssertTrue(itemsSorted.Size() == 3, lang.StringWrap(lang.StringLiteral("itemsSorted should have size 3")))
    item = itemsSorted.Get(0)
    this.AssertTrue(item.CompareTo(lang.StringWrap(lang.StringLiteral("1"))) == 0, lang.StringWrap(lang.StringLiteral("expected 1 as first element")))
    item = itemsSorted.Get(1)
    this.AssertTrue(item.CompareTo(lang.StringWrap(lang.StringLiteral("2"))) == 0, lang.StringWrap(lang.StringLiteral("expected 2 as second element")))
    item = itemsSorted.Get(2)
    this.AssertTrue(item.CompareTo(lang.StringWrap(lang.StringLiteral("3"))) == 0, lang.StringWrap(lang.StringLiteral("expected 3 as third element")))
}

func (this *TestQuicksortService) singleItem()  {
    var item *lang.String
    var items *lang.Array[*lang.String] = lang.ArrayNewArray(1, (*lang.String)(nil))
    items.Set(0, lang.StringWrap(lang.StringLiteral("1")))
    var sortService SortService = QuicksortServiceNew()
    var itemsSorted *lang.Array[*lang.String] = sortService.Sort(items)
    this.AssertTrue(itemsSorted.Size() == 1, lang.StringWrap(lang.StringLiteral("itemsSorted should have size 1")))
    item = itemsSorted.Get(0)
    this.AssertTrue(item.CompareTo(lang.StringWrap(lang.StringLiteral("1"))) == 0, lang.StringWrap(lang.StringLiteral("expected 1 as first element")))
}

func (this *TestQuicksortService) sameItem()  {
    var item *lang.String
    var items *lang.Array[*lang.String] = lang.ArrayNewArray(3, (*lang.String)(nil))
    items.Set(0, lang.StringWrap(lang.StringLiteral("1")))
    items.Set(1, lang.StringWrap(lang.StringLiteral("1")))
    items.Set(2, lang.StringWrap(lang.StringLiteral("1")))
    var sortService SortService = QuicksortServiceNew()
    var itemsSorted *lang.Array[*lang.String] = sortService.Sort(items)
    this.AssertTrue(itemsSorted.Size() == 3, lang.StringWrap(lang.StringLiteral("itemsSorted should have size 3")))
    item = itemsSorted.Get(0)
    this.AssertTrue(item.CompareTo(lang.StringWrap(lang.StringLiteral("1"))) == 0, lang.StringWrap(lang.StringLiteral("expected 1 as first element")))
    item = itemsSorted.Get(1)
    this.AssertTrue(item.CompareTo(lang.StringWrap(lang.StringLiteral("1"))) == 0, lang.StringWrap(lang.StringLiteral("expected 1 as second element")))
    item = itemsSorted.Get(2)
    this.AssertTrue(item.CompareTo(lang.StringWrap(lang.StringLiteral("1"))) == 0, lang.StringWrap(lang.StringLiteral("expected 1 as third element")))
}

func TestTestQuicksortService(t *testing.T) {
    t.Run("normalSort", func(t *testing.T) {
        test := testQuicksortServiceNew()
        test.SetGoTestingT(t)
        test.normalSort()
    })
    t.Run("singleItem", func(t *testing.T) {
        test := testQuicksortServiceNew()
        test.SetGoTestingT(t)
        test.singleItem()
    })
    t.Run("sameItem", func(t *testing.T) {
        test := testQuicksortServiceNew()
        test.SetGoTestingT(t)
        test.sameItem()
    })
}
