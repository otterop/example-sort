import sys
from example.quicksort.service.quicksort_service import QuicksortService
from otterop.lang.array import Array
from otterop.lang.string import String
from otterop.io.console import Console
println = Console.println

class Quicksort:

    @staticmethod
    def main(args):
        args_array = Array.wrap_string(args)
        QuicksortService.quick_sort(args_array, 0, args_array.size())
        i = 0
        while i < args_array.size():
            println(args_array.get(i))
            i = i + 1

if __name__ == "__main__":
    Quicksort.main(sys.argv[1:])
