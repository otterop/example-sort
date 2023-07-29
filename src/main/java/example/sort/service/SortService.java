package example.sort.service;

import otterop.lang.Array;
import otterop.lang.MakePure;
import otterop.lang.String;

@MakePure
public interface SortService {
    Array<String> sort(Array<String> array);
}
