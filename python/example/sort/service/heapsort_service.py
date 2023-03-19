from otterop.io.console import Console
from otterop.lang.array import Array
from otterop.lang.string import String

class HeapsortService:

    def __init__(self):
        pass
    def swap(self, array, from_idx, to_idx):
        tmp = array.get(to_idx)
        array.set(to_idx, array.get(from_idx))
        array.set(from_idx, tmp)

    def heapify(self, array, parent, size):
        largest = parent
        left_child = parent * 2 + 1
        right_child = parent * 2 + 2
        if left_child < size:
            left_s = array.get(left_child)
            if left_s.compare_to(array.get(largest)) > 0:
                largest = left_child
        if right_child < size:
            right_s = array.get(right_child)
            if right_s.compare_to(array.get(largest)) > 0:
                largest = right_child
        if largest != parent:
            self.swap(array, parent, largest)
            self.heapify(array, largest, size)

    def sort(self, array, from_idx, to_idx):
        n = array.size()
        i = n // 2 - 1
        while i >= 0:
            self.heapify(array, i, n)
            i -= 1
        i = n - 1
        while i >= 0:
            self.swap(array, 0, i)
            self.heapify(array, 0, i)
            i -= 1
