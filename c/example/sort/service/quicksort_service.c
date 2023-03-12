#include <example/sort/service/quicksort_service.h>
#include <gc.h>

typedef struct example_sort_service_QuicksortService_s {
} example_sort_service_QuicksortService_t;




example_sort_service_QuicksortService_t *example_sort_service_QuicksortService_new() {
    example_sort_service_QuicksortService_t *this = GC_malloc(sizeof(example_sort_service_QuicksortService_t));
    return this;
}

void example_sort_service_QuicksortService_swap(example_sort_service_QuicksortService_t *this, otterop_lang_Array_t *array, int from_idx, int to_idx) {
    otterop_lang_String_t *tmp = otterop_lang_Array_get(array, to_idx);
    otterop_lang_Array_set(array, to_idx, otterop_lang_Array_get(array, from_idx));
    otterop_lang_Array_set(array, from_idx, tmp);
}

void example_sort_service_QuicksortService_sort(example_sort_service_QuicksortService_t *this, otterop_lang_Array_t *array, int from_idx, int to_idx) {
    int i = from_idx;
    int swap_with = -1;
    int pivot = to_idx - 1;
    
    while (i < pivot) {
        otterop_lang_String_t *i_string = otterop_lang_Array_get(array, i);
        otterop_lang_String_t *pivot_string = otterop_lang_Array_get(array, pivot);
        int less_than = otterop_lang_String_compare_to(i_string, pivot_string) < 0;
        
        if (swap_with >= 0 && less_than) {
            example_sort_service_QuicksortService_swap(this, array, swap_with, i);
            swap_with = swap_with + 1;
        } else if (swap_with < 0 && !less_than) {
            swap_with = i;
        }
        i = i + 1;
    }
    
    if (swap_with >= 0 && swap_with < pivot) {
        otterop_lang_String_t *swap_with_string = otterop_lang_Array_get(array, swap_with);
        otterop_lang_String_t *pivot_string = otterop_lang_Array_get(array, pivot);
        
        if (otterop_lang_String_compare_to(swap_with_string, pivot_string) >= 0) {
            example_sort_service_QuicksortService_swap(this, array, swap_with, pivot);
            pivot = swap_with;
        }
    }
    
    if (pivot > from_idx + 1) {
        example_sort_service_QuicksortService_sort(this, array, from_idx, pivot);
    }
    
    if (pivot + 1 < to_idx - 1) {
        example_sort_service_QuicksortService_sort(this, array, pivot + 1, to_idx);
    }
}

example_sort_service_SortService_t
*example_sort_service_QuicksortService__to_example_sort_service_SortService(example_sort_service_QuicksortService_t *this) {
    return example_sort_service_SortService_new(this,
        (void (*)(void *, otterop_lang_Array_t *, int, int)) example_sort_service_QuicksortService_sort);
}

