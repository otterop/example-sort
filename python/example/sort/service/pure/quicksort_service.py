import otterop.lang.array
import otterop.lang.string
import example.sort.service.quicksort_service

class QuicksortService:
    def __init__(self):
        self.otterop = example.sort.service.quicksort_service.QuicksortService()

    def sort(self, array):
        _array_array = [None] * len(array)
        for i in range(len(array)):
            _array_array[i] = otterop.lang.string.String.wrap(array[i])
        _array = otterop.lang.array.Array.wrap(_array_array)
        ret_otterop = self.otterop.sort(_array)
        ret = [None] * ret_otterop.size()
        for i in range(len(ret)):
            ret_i = ret_otterop.get(i)
            ret[i] = ret_i.unwrap()
        return ret

    def unwrap(self):
        return self.otterop

    @staticmethod
    def wrap(wrapped):
        ret = example.sort.service.pure.quicksort_service.QuicksortService.__new__(example.sort.service.pure.quicksort_service.QuicksortService)
        ret.otterop = wrapped
        return ret
