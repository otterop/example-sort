import sys
from example.sort.service.pure.heapsort_service import HeapsortService
from example.sort.service.pure.quicksort_service import QuicksortService
from example.sort.tree.pure.node import Node

class Sort:

    @staticmethod
    def main(args):
        if len(args) < 1:
            print("Usage: <quick|heap> ...values")
            return 
        sort_algorithm = args[0]
        is_quick = sort_algorithm == "quick"
        is_heap = sort_algorithm == "heap"
        if not (is_quick or is_heap):
            print("Usage: <quick|heap> ...values")
            return
        args = args[1:]
        sort_service = QuicksortService()
        if is_heap:
            sort_service = HeapsortService()
        args = sort_service.sort(args)
        for arg in args:
            print(arg)

        a = Node(1, [])
        b = Node(2, [])
        c = Node(3, [a,b])
        d = Node(4, [])
        e = Node(5, [])
        f = Node(6, [d,e])
        g = Node(7, [c,f])

        list = [g]
        while len(list) > 0:
            new_list = []
            rest = False
            for el in list:
                if rest:
                    print(' ', end='')
                print(f'value: {el.value()}', end='')
                new_list.extend(el.children())
                rest = True
            print()
            list = new_list

if __name__ == "__main__":
    Sort.main(sys.argv[1:])
