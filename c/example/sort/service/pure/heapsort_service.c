#include <example/sort/service/pure/heapsort_service.h>
#include <gc.h>

typedef struct example_sort_service_pure_HeapsortService_s example_sort_service_pure_HeapsortService_t;
typedef struct example_sort_service_pure_HeapsortService_s {
    example_sort_service_HeapsortService_t *_otterop;
} example_sort_service_pure_HeapsortService_t;


static example_sort_service_pure_HeapsortService_t *example_sort_service_pure_HeapsortService_wrap(example_sort_service_HeapsortService_t *wrapped) {
    example_sort_service_pure_HeapsortService_t *this = GC_malloc(sizeof(example_sort_service_pure_HeapsortService_t));
    this->_otterop = wrapped;
    return this;
}


example_sort_service_pure_HeapsortService_t *example_sort_service_pure_HeapsortService_new() {
    example_sort_service_pure_HeapsortService_t *this = GC_malloc(sizeof(example_sort_service_pure_HeapsortService_t));
    this->_otterop = example_sort_service_HeapsortService_new();
    return this;
}



char **example_sort_service_pure_HeapsortService_sort(example_sort_service_pure_HeapsortService_t *this, char **array, size_t array_cnt, size_t *_ret_cnt) {
    size_t i;
    otterop_lang_String_t **_array_array = GC_malloc(array_cnt * sizeof(otterop_lang_String_t *));
    for (i = 0; i < array_cnt; i++) {
        _array_array[i] = otterop_lang_String_wrap(array[i]);
    }
    otterop_lang_Array_t *_array = otterop_lang_Array_wrap(_array_array, array_cnt);
    otterop_lang_Array_t * ret_otterop = example_sort_service_HeapsortService_sort(this->_otterop, _array);
    int _ret_size = otterop_lang_Array_size(ret_otterop), _ret_i;
    *_ret_cnt = _ret_size;
    char **ret = GC_malloc(_ret_size * sizeof(void *));
    for (_ret_i = 0; _ret_i < _ret_size; _ret_i++) {
        otterop_lang_String_t *ret_i = otterop_lang_Array_get(ret_otterop, _ret_i);
        ret[_ret_i] = otterop_lang_String_unwrap(ret_i);
    }
    return ret;
}

example_sort_service_HeapsortService_t *example_sort_service_pure_HeapsortService_unwrap(example_sort_service_pure_HeapsortService_t *this) {
    return this->_otterop;
}


example_sort_service_pure_SortService_t
*example_sort_service_pure_HeapsortService__to_example_sort_service_pure_SortService(example_sort_service_pure_HeapsortService_t *this) {
    return example_sort_service_pure_SortService_new(this,
        (char **(*)(void *, char **, size_t, size_t *)) example_sort_service_pure_HeapsortService_sort);
}

