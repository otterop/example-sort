package example.sort.service;
import otterop.lang.Array;
import otterop.lang.String;
import otterop.test.Test;

public class TestQuicksortService {

    @Test
    public void normalSort() {
        Array<String> items = new Array<>(3);
        items.set(0, String.wrap("3"));
        items.set(1, String.wrap("2"));
        items.set(2, String.wrap("1"));
        SortService sortService = new QuicksortService();
        Array<String> itemsSorted = sortService.sort(items);
    }
}
