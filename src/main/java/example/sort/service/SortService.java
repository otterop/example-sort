package example.sort.service;

import otterop.lang.Array;
import otterop.lang.String;

public interface SortService {
    void sort(Array<String> array, int fromIdx, int toIdx);
}
