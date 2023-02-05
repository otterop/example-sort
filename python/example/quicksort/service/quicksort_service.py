from otterop.lang.array import Array
from otterop.lang.string import String

class QuicksortService:

    @staticmethod
    def swap(array, from_idx, to_idx):
        tmp = array.get(to_idx)
        array.set(to_idx, array.get(from_idx))
        array.set(from_idx, tmp)

    @staticmethod
    def quick_sort(array, from_idx, to_idx):
        i = from_idx
        swap_with = -1
        pivot = to_idx - 1
        while i < pivot:
            i_string = array.get(i)
            pivot_string = array.get(pivot)
            less_than = i_string.compare_to(pivot_string) < 0
            if swap_with >= 0 and less_than:
                QuicksortService.swap(array, swap_with, i)
                swap_with = swap_with + 1
            elif swap_with < 0 and not less_than:
                swap_with = i
            i = i + 1
        if swap_with >= 0 and swap_with < pivot:
            swap_with_string = array.get(swap_with)
            pivot_string = array.get(pivot)
            if swap_with_string.compare_to(pivot_string) >= 0:
                QuicksortService.swap(array, swap_with, pivot)
                pivot = swap_with
        if pivot > from_idx + 1:
            QuicksortService.quick_sort(array, from_idx, pivot)
        if pivot + 1 < to_idx - 1:
            QuicksortService.quick_sort(array, pivot + 1, to_idx)
