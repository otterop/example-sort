package example.sort.service;

import otterop.lang.Array;
import otterop.lang.MakePure;
import otterop.lang.String;

@MakePure
public interface SortService {
    void sort(Array<String> array, int fromIdx, int toIdx);
}
