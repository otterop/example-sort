import sys
from example.sort.service.quicksort_service import QuicksortService
from example.sort.service.sort_service import SortService
from otterop.lang.array import Array
from otterop.lang.string import String
from otterop.lang.result import Result
from otterop.io.console import Console
println = Console.println

class Sort:

    @staticmethod
    def main(args):
        args_array = Array.wrap_string(args)
        sort_service = QuicksortService()
        sort_service.sort(args_array, 0, args_array.size())
        i = 0
        while i < args_array.size():
            println(args_array.get(i))
            i += 1
        Result.of(String.wrap(""), String.wrap(""))

if __name__ == "__main__":
    Sort.main(sys.argv[1:])
