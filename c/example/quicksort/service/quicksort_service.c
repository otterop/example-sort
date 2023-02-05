#include <example/quicksort/service/quicksort_service.h>

typedef struct example_quicksort_service_QuicksortService_s {
} example_quicksort_service_QuicksortService_t;




void example_quicksort_service_QuicksortService_swap(otterop_lang_Array_t *array, int from_idx, int to_idx);


void example_quicksort_service_QuicksortService_swap(otterop_lang_Array_t *array, int from_idx, int to_idx) {
    otterop_lang_String_t *tmp = otterop_lang_Array_get(array, to_idx);
    otterop_lang_Array_set(array, to_idx, otterop_lang_Array_get(array, from_idx));
    otterop_lang_Array_set(array, from_idx, tmp);
}

void example_quicksort_service_QuicksortService_quick_sort(otterop_lang_Array_t *array, int from_idx, int to_idx) {
    int i = from_idx;
    int swap_with = -1;
    int pivot = to_idx - 1;
    
    while (i < pivot) {
        otterop_lang_String_t *i_string = otterop_lang_Array_get(array, i);
        otterop_lang_String_t *pivot_string = otterop_lang_Array_get(array, pivot);
        int less_than = otterop_lang_String_compare_to(i_string, pivot_string) < 0;
        
        if (swap_with >= 0 && less_than) {
            example_quicksort_service_QuicksortService_swap(array, swap_with, i);
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
            example_quicksort_service_QuicksortService_swap(array, swap_with, pivot);
            pivot = swap_with;
        }
    }
    
    if (pivot > from_idx + 1) {
        example_quicksort_service_QuicksortService_quick_sort(array, from_idx, pivot);
    }
    
    if (pivot + 1 < to_idx - 1) {
        example_quicksort_service_QuicksortService_quick_sort(array, pivot + 1, to_idx);
    }
}