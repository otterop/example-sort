package example.sort.service;
import otterop.lang.Array;
import otterop.lang.String;
import otterop.test.Test;
import otterop.test.TestBase;

public class TestHeapsortService extends TestBase {

    @Test
    public void normalSort() {
        String item;
        Array<String> items = Array.newArray(3, (String) null);
        items.set(0, String.wrap("3"));
        items.set(1, String.wrap("2"));
        items.set(2, String.wrap("1"));
        SortService sortService = new HeapsortService();
        Array<String> itemsSorted = sortService.sort(items);
        this.assertTrue(itemsSorted.size() == 3, String.wrap("itemsSorted should have size 3"));
        item = itemsSorted.get(0);
        this.assertTrue(item.compareTo(String.wrap("1")) == 0,
                String.wrap("expected 1 as first element"));
        item = itemsSorted.get(1);
        this.assertTrue(item.compareTo(String.wrap("2")) == 0,
                String.wrap("expected 2 as second element"));
        item = itemsSorted.get(2);
        this.assertTrue(item.compareTo(String.wrap("3")) == 0,
                String.wrap("expected 3 as third element"));
    }

    @Test
    public void singleItem() {
        String item;
        Array<String> items = Array.newArray(1, (String) null);
        items.set(0, String.wrap("1"));
        SortService sortService = new HeapsortService();
        Array<String> itemsSorted = sortService.sort(items);
        this.assertTrue(itemsSorted.size() == 1, String.wrap("itemsSorted should have size 1"));
        item = itemsSorted.get(0);
        this.assertTrue(item.compareTo(String.wrap("1")) == 0,
                String.wrap("expected 1 as first element"));
    }

    @Test
    public void sameItem() {
        String item;
        Array<String> items = Array.newArray(3, (String) null);
        items.set(0, String.wrap("1"));
        items.set(1, String.wrap("1"));
        items.set(2, String.wrap("1"));

        SortService sortService = new HeapsortService();
        Array<String> itemsSorted = sortService.sort(items);
        this.assertTrue(itemsSorted.size() == 3, String.wrap("itemsSorted should have size 3"));
        item = itemsSorted.get(0);
        this.assertTrue(item.compareTo(String.wrap("1")) == 0,
                String.wrap("expected 1 as first element"));
        item = itemsSorted.get(1);
        this.assertTrue(item.compareTo(String.wrap("1")) == 0,
                String.wrap("expected 1 as second element"));
        item = itemsSorted.get(2);
        this.assertTrue(item.compareTo(String.wrap("1")) == 0,
                String.wrap("expected 1 as third element"));
    }
}
