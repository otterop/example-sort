package example.sort.service.pure;

public class HeapsortService implements example.sort.service.pure.SortService {
    private final example.sort.service.HeapsortService _otterop;

    private HeapsortService(example.sort.service.HeapsortService wrapped) {
        this._otterop = wrapped;
    }

    public HeapsortService() {
        this._otterop = new example.sort.service.HeapsortService();
    }

    public String[] sort(String[] array) {
        var _arrayArray = new otterop.lang.String[array.length];
        for (var i = 0; i < array.length; i++) {
            _arrayArray[i] = otterop.lang.String.wrap(array[i]);
        }
        var _array = otterop.lang.Array.wrap(_arrayArray);
        var retOtterop = _otterop.sort(_array);
        var ret = new String[retOtterop.size()];
        for (var i = 0; i < retOtterop.size(); i++) {
            var retI = retOtterop.get(i);
            ret[i] = retI.unwrap();
        }
        return ret;
    }

    public example.sort.service.HeapsortService unwrap() {
        return this._otterop;
    }

    public static example.sort.service.pure.HeapsortService wrap(example.sort.service.HeapsortService wrapped) {
        return new example.sort.service.pure.HeapsortService(wrapped);
    }
}

