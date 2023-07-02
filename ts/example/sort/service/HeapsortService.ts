import { Array } from '@otterop/lang/array';
import { String } from '@otterop/lang/string';

export class HeapsortService {

    public constructor() {
    }

    swap(array : Array<String>, fromIdx : number, toIdx : number) : void {
        let tmp : String = array.get(toIdx);
        array.set(toIdx, array.get(fromIdx));
        array.set(fromIdx, tmp);
    }

    heapify(array : Array<String>, parent : number, size : number) : void {
        let largest : number = parent;
        let leftChild : number = parent * 2 + 1;
        let rightChild : number = parent * 2 + 2;
        
        if (leftChild < size) {
            let leftS : String = array.get(leftChild);
            
            if (leftS.compareTo(array.get(largest)) > 0) {
                largest = leftChild;
            }
        }
        
        if (rightChild < size) {
            let rightS : String = array.get(rightChild);
            
            if (rightS.compareTo(array.get(largest)) > 0) {
                largest = rightChild;
            }
        }
        
        if (largest != parent) {
            this.swap(array, parent, largest);
            this.heapify(array, largest, size);
        }
    }

    public sort(array : Array<String>, fromIdx : number, toIdx : number) : void {
        let n : number = array.size();
        for (let i : number = Math.floor(n / 2) - 1; i >= 0; i--) {
            this.heapify(array, i, n);
        }
        for (let i : number = n - 1; i >= 0; i--) {
            this.swap(array, 0, i);
            this.heapify(array, 0, i);
        }
    }
}

