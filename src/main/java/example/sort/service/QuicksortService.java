package example.sort.service;

import otterop.lang.Array;
import otterop.lang.MakePure;
import otterop.lang.String;

@MakePure
public class QuicksortService implements SortService {

    public QuicksortService() {
    }

    private void swap(Array<String> array, int fromIdx, int toIdx) {
        String tmp = array.get(toIdx);
        array.set(toIdx, array.get(fromIdx));
        array.set(fromIdx, tmp);
    }

    public void sort(Array<String> array, int fromIdx, int toIdx) {
        int i = fromIdx;
        int swapWith = -1;
        int pivot = toIdx - 1;
        while (i < pivot) {
            String iString = array.get(i);
            String pivotString = array.get(pivot);
            boolean lessThan = iString.compareTo(pivotString) < 0;
            if (swapWith >= 0 && lessThan) {
                this.swap(array, swapWith, i);
                swapWith = swapWith + 1;
            } else if (swapWith < 0 && !lessThan) {
                swapWith = i;
            }
            i = i + 1;
        }
        if (swapWith >= 0 && swapWith < pivot) {
            String swapWithString = array.get(swapWith);
            String pivotString = array.get(pivot);
            if(swapWithString.compareTo(pivotString) >= 0) {
                this.swap(array, swapWith, pivot);
                pivot = swapWith;
            }
        }
        if(pivot > fromIdx + 1) {
            this.sort(array, fromIdx, pivot);
        }
        if (pivot + 1 < toIdx - 1) {
            this.sort(array, pivot + 1, toIdx);
        }
    }
}
