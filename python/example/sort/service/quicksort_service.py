from otterop.lang.array import Array
from otterop.lang.string import String

class QuicksortService:

    def __init__(self):
        pass
    def swap(self, array, from_idx, to_idx):
        tmp = array.get(to_idx)
        array.set(to_idx, array.get(from_idx))
        array.set(from_idx, tmp)

    def sort_with_indices(self, array, from_idx, to_idx):
        i = from_idx
        swap_with = -1
        pivot = to_idx - 1
        while i < pivot:
            i_string = array.get(i)
            pivot_string = array.get(pivot)
            less_than = i_string.compare_to(pivot_string) < 0
            if swap_with >= 0 and less_than:
                self.swap(array, swap_with, i)
                swap_with = swap_with + 1
            elif swap_with < 0 and not less_than:
                swap_with = i
            i = i + 1
        if swap_with >= 0 and swap_with < pivot:
            swap_with_string = array.get(swap_with)
            pivot_string = array.get(pivot)
            if swap_with_string.compare_to(pivot_string) >= 0:
                self.swap(array, swap_with, pivot)
                pivot = swap_with
        if pivot > from_idx + 1:
            self.sort_with_indices(array, from_idx, pivot)
        if pivot + 1 < to_idx - 1:
            self.sort_with_indices(array, pivot + 1, to_idx)

    def sort(self, array):
        self.sort_with_indices(array, 0, array.size())
        return array
