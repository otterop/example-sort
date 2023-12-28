#include <example/sort/service/heapsort_service.h>
#include <gc.h>

typedef struct example_sort_service_HeapsortService_s {
} example_sort_service_HeapsortService_t;




void example_sort_service_HeapsortService_heapify(example_sort_service_HeapsortService_t *this, otterop_lang_Array_t *array, int parent, int size);


void example_sort_service_HeapsortService_sort_with_indices(example_sort_service_HeapsortService_t *this, otterop_lang_Array_t *array, int from_idx, int to_idx);


example_sort_service_HeapsortService_t *example_sort_service_HeapsortService_new() {
    example_sort_service_HeapsortService_t *this = GC_malloc(sizeof(example_sort_service_HeapsortService_t));
    return this;
}

void example_sort_service_HeapsortService_swap(example_sort_service_HeapsortService_t *this, otterop_lang_Array_t *array, int from_idx, int to_idx) {
    otterop_lang_String_t *tmp = otterop_lang_Array_get(array, to_idx);
    otterop_lang_Array_set(array, to_idx, otterop_lang_Array_get(array, from_idx));
    otterop_lang_Array_set(array, from_idx, tmp);
}

void example_sort_service_HeapsortService_heapify(example_sort_service_HeapsortService_t *this, otterop_lang_Array_t *array, int parent, int size) {
    int largest = parent;
    int left_child = parent * 2 + 1;
    int right_child = parent * 2 + 2;
    
    if (left_child < size) {
        otterop_lang_String_t *left_s = otterop_lang_Array_get(array, left_child);
        
        if (otterop_lang_String_compare_to(left_s, otterop_lang_Array_get(array, largest)) > 0) {
            largest = left_child;
        }
    }
    
    if (right_child < size) {
        otterop_lang_String_t *right_s = otterop_lang_Array_get(array, right_child);
        
        if (otterop_lang_String_compare_to(right_s, otterop_lang_Array_get(array, largest)) > 0) {
            largest = right_child;
        }
    }
    
    if (largest != parent) {
        example_sort_service_HeapsortService_swap(this, array, parent, largest);
        example_sort_service_HeapsortService_heapify(this, array, largest, size);
    }
}

void example_sort_service_HeapsortService_sort_with_indices(example_sort_service_HeapsortService_t *this, otterop_lang_Array_t *array, int from_idx, int to_idx) {
    int n = otterop_lang_Array_size(array);
    for (int i = n / 2 - 1; i >= 0; i--) {
        example_sort_service_HeapsortService_heapify(this, array, i, n);
    }
    for (int i = n - 1; i >= 0; i--) {
        example_sort_service_HeapsortService_swap(this, array, 0, i);
        example_sort_service_HeapsortService_heapify(this, array, 0, i);
    }
}

otterop_lang_Array_t *example_sort_service_HeapsortService_sort(example_sort_service_HeapsortService_t *this, otterop_lang_Array_t *array) {
    example_sort_service_HeapsortService_sort_with_indices(this, array, 0, otterop_lang_Array_size(array));
    return array;
}

example_sort_service_SortService_t
*example_sort_service_HeapsortService__to_example_sort_service_SortService(example_sort_service_HeapsortService_t *this) {
    return example_sort_service_SortService_new(this,
        (otterop_lang_Array_t * (*)(void *, otterop_lang_Array_t *)) example_sort_service_HeapsortService_sort);
}


