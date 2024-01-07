from otterop.lang.array import Array
from otterop.lang.string import String
from otterop.test.test_base import TestBase
from example.sort.service.quicksort_service import QuicksortService

class TestQuicksortService(TestBase):

    def normal_sort(self):
        
        items = Array.new_array(3, None)
        items.set(0, String.wrap("3"))
        items.set(1, String.wrap("2"))
        items.set(2, String.wrap("1"))
        sort_service = QuicksortService()
        items_sorted = sort_service.sort(items)
        self.assert_true(items_sorted.size() == 3, String.wrap("itemsSorted should have size 3"))
        item = items_sorted.get(0)
        self.assert_true(item.compare_to(String.wrap("1")) == 0, String.wrap("expected 1 as first element"))
        item = items_sorted.get(1)
        self.assert_true(item.compare_to(String.wrap("2")) == 0, String.wrap("expected 2 as second element"))
        item = items_sorted.get(2)
        self.assert_true(item.compare_to(String.wrap("3")) == 0, String.wrap("expected 3 as third element"))

    def single_item(self):
        
        items = Array.new_array(1, None)
        items.set(0, String.wrap("1"))
        sort_service = QuicksortService()
        items_sorted = sort_service.sort(items)
        self.assert_true(items_sorted.size() == 1, String.wrap("itemsSorted should have size 1"))
        item = items_sorted.get(0)
        self.assert_true(item.compare_to(String.wrap("1")) == 0, String.wrap("expected 1 as first element"))

    def same_item(self):
        
        items = Array.new_array(3, None)
        items.set(0, String.wrap("1"))
        items.set(1, String.wrap("1"))
        items.set(2, String.wrap("1"))
        sort_service = QuicksortService()
        items_sorted = sort_service.sort(items)
        self.assert_true(items_sorted.size() == 3, String.wrap("itemsSorted should have size 3"))
        item = items_sorted.get(0)
        self.assert_true(item.compare_to(String.wrap("1")) == 0, String.wrap("expected 1 as first element"))
        item = items_sorted.get(1)
        self.assert_true(item.compare_to(String.wrap("1")) == 0, String.wrap("expected 1 as second element"))
        item = items_sorted.get(2)
        self.assert_true(item.compare_to(String.wrap("1")) == 0, String.wrap("expected 1 as third element"))

def test_normal_sort():
    TestQuicksortService().normal_sort()

def test_single_item():
    TestQuicksortService().single_item()

def test_same_item():
    TestQuicksortService().same_item()
