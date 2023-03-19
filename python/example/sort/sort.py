import sys
from example.sort.service.heapsort_service import HeapsortService
from example.sort.service.quicksort_service import QuicksortService
from example.sort.service.sort_service import SortService
from otterop.lang.array import Array
from otterop.lang.string import String
from otterop.lang.result import Result
from otterop.io.console import Console
println = Console.println

class Sort:
    test = 111

    @staticmethod
    def main(args):
        quick = String.wrap("quick")
        heap = String.wrap("heap")
        args_array = Array.wrap_string(args)
        if args_array.size() < 1:
            println(String.wrap("Usage: <quick|heap> ...values"))
            return 
        sort_algorithm = args_array.get(0)
        is_quick = sort_algorithm.compare_to(quick) == 0
        is_heap = sort_algorithm.compare_to(heap) == 0
        if not (is_quick or is_heap):
            println(String.wrap("Usage: <quick|heap> ...values"))
            return 
        args_array = args_array.slice(1, args_array.size())
        sort_service = QuicksortService()
        if is_heap:
            sort_service = HeapsortService()
        sort_service.sort(args_array, 0, args_array.size())
        i = 0
        while i < args_array.size():
            println(args_array.get(i))
            i += 1
        Result.of(String.wrap(""), String.wrap(""))

if __name__ == "__main__":
    Sort.main(sys.argv[1:])
