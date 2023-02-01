import sys
from otterop.lang.array import Array
from otterop.lang.string import String
from otterop.io.console import Console
println = Console.println

class Quicksort:

    def hello(self):
        println(String.wrap("world"))

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
                Quicksort.swap(array, swap_with, i)
                swap_with = swap_with + 1
            elif swap_with < 0 and not less_than:
                swap_with = i
            i = i + 1
        if swap_with >= 0 and swap_with < pivot:
            swap_with_string = array.get(swap_with)
            pivot_string = array.get(pivot)
            if swap_with_string.compare_to(pivot_string) >= 0:
                Quicksort.swap(array, swap_with, pivot)
                pivot = swap_with
        if pivot > from_idx + 1:
            Quicksort.quick_sort(array, from_idx, pivot)
        if pivot + 1 < to_idx - 1:
            Quicksort.quick_sort(array, pivot + 1, to_idx)
        else:
            println(String.wrap("foo"))

    @staticmethod
    def main(args):
        args_array = Array.wrap_string(args)
        Quicksort.quick_sort(args_array, 0, args_array.size())
        i = 0
        if args_array.size() > 0:
            args_array.set(0, String.wrap("bbbb"))
        while i < args_array.size():
            println(args_array.get(i))
            i = i + 1
        p = Quicksort(2, 4.0, String.wrap("hello world"))
        p.hello()
        println(p.string())

    def __init__(self, a, b, c):
        self.a = a
        self.b = b
        self.c = c

    def string(self):
        return self.c

if __name__ == "__main__":
    Quicksort.main(sys.argv[1:])
