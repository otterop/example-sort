package example.sort.service;

import otterop.lang.Array;
import otterop.lang.MakePure;
import otterop.lang.String;

@MakePure
public class HeapsortService implements SortService {
    public HeapsortService() {
    }

    private void swap(Array<String> array, int fromIdx, int toIdx) {
        String tmp = array.get(toIdx);
        array.set(toIdx, array.get(fromIdx));
        array.set(fromIdx, tmp);
    }

    private void heapify(Array<String> array, int parent, int size) {
        int largest = parent;
        int leftChild = parent * 2 + 1;
        int rightChild = parent * 2 + 2;

        if (leftChild < size) {
            String leftS = array.get(leftChild);
            if (leftS.compareTo(array.get(largest)) > 0){
                largest = leftChild;
            }
        }

        if (rightChild < size) {
            String rightS = array.get(rightChild);
            if (rightS.compareTo(array.get(largest)) > 0){
                largest = rightChild;
            }
        }

        if (largest != parent) {
            this.swap(array, parent, largest);
            this.heapify(array, largest, size);
        }
    }

    public void sort(Array<String> array, int fromIdx, int toIdx) {
        int n = array.size();
        for (int i = n / 2 - 1; i >= 0; i--) {
            this.heapify(array, i, n);
        }

        for (int i = n - 1; i >= 0; i--) {
            this.swap(array, 0, i);
            this.heapify(array, 0, i);
        }
    }
}
