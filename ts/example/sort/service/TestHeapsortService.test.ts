import { Array } from '@otterop/lang/Array';
import { String } from '@otterop/lang/String';
import { TestBase } from '@otterop/test/TestBase';
import { SortService } from './SortService';
import { HeapsortService } from './HeapsortService';

export class TestHeapsortService extends TestBase {

    public normalSort() : void {
        let item : String;
        let items : Array<String> = Array.newArray(3, (null as unknown as String));
        items.set(0, String.wrap("3"));
        items.set(1, String.wrap("2"));
        items.set(2, String.wrap("1"));
        let sortService : SortService = new HeapsortService();
        let itemsSorted : Array<String> = sortService.sort(items);
        this.assertTrue(itemsSorted.size() == 3, String.wrap("itemsSorted should have size 3"));
        item = itemsSorted.get(0);
        this.assertTrue(item.compareTo(String.wrap("1")) == 0, String.wrap("expected 1 as first element"));
        item = itemsSorted.get(1);
        this.assertTrue(item.compareTo(String.wrap("2")) == 0, String.wrap("expected 2 as second element"));
        item = itemsSorted.get(2);
        this.assertTrue(item.compareTo(String.wrap("3")) == 0, String.wrap("expected 3 as third element"));
    }

    public singleItem() : void {
        let item : String;
        let items : Array<String> = Array.newArray(1, (null as unknown as String));
        items.set(0, String.wrap("1"));
        let sortService : SortService = new HeapsortService();
        let itemsSorted : Array<String> = sortService.sort(items);
        this.assertTrue(itemsSorted.size() == 1, String.wrap("itemsSorted should have size 1"));
        item = itemsSorted.get(0);
        this.assertTrue(item.compareTo(String.wrap("1")) == 0, String.wrap("expected 1 as first element"));
    }

    public sameItem() : void {
        let item : String;
        let items : Array<String> = Array.newArray(3, (null as unknown as String));
        items.set(0, String.wrap("1"));
        items.set(1, String.wrap("1"));
        items.set(2, String.wrap("1"));
        let sortService : SortService = new HeapsortService();
        let itemsSorted : Array<String> = sortService.sort(items);
        this.assertTrue(itemsSorted.size() == 3, String.wrap("itemsSorted should have size 3"));
        item = itemsSorted.get(0);
        this.assertTrue(item.compareTo(String.wrap("1")) == 0, String.wrap("expected 1 as first element"));
        item = itemsSorted.get(1);
        this.assertTrue(item.compareTo(String.wrap("1")) == 0, String.wrap("expected 1 as second element"));
        item = itemsSorted.get(2);
        this.assertTrue(item.compareTo(String.wrap("1")) == 0, String.wrap("expected 1 as third element"));
    }
}


test('normalSort', () => {
    new TestHeapsortService().normalSort();
});

test('singleItem', () => {
    new TestHeapsortService().singleItem();
});

test('sameItem', () => {
    new TestHeapsortService().sameItem();
});
