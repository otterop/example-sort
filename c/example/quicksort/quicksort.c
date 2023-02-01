#include <example/quicksort/quicksort.h>

typedef struct example_quicksort_Quicksort_s {
    int a;
    double b;
    otterop_lang_String_t *c;
} example_quicksort_Quicksort_t;




void example_quicksort_Quicksort_swap(otterop_lang_Array_t *array, int from_idx, int to_idx);

void example_quicksort_Quicksort_hello(example_quicksort_Quicksort_t *this) {
    otterop_io_Console_println(otterop_lang_String_wrap("world"));
}

void example_quicksort_Quicksort_swap(otterop_lang_Array_t *array, int from_idx, int to_idx) {
    otterop_lang_String_t *tmp = otterop_lang_Array_get(array, to_idx);
    otterop_lang_Array_set(array, to_idx, otterop_lang_Array_get(array, from_idx));
    otterop_lang_Array_set(array, from_idx, tmp);
}

void example_quicksort_Quicksort_quick_sort(otterop_lang_Array_t *array, int from_idx, int to_idx) {
    int i = from_idx;
    int swap_with = -1;
    int pivot = to_idx - 1;
    
    while (i < pivot) {
        otterop_lang_String_t *i_string = otterop_lang_Array_get(array, i);
        otterop_lang_String_t *pivot_string = otterop_lang_Array_get(array, pivot);
        int less_than = otterop_lang_String_compare_to(i_string, pivot_string) < 0;
        
        if (swap_with >= 0 && less_than) {
            example_quicksort_Quicksort_swap(array, swap_with, i);
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
            example_quicksort_Quicksort_swap(array, swap_with, pivot);
            pivot = swap_with;
        }
    }
    
    if (pivot > from_idx + 1) {
        example_quicksort_Quicksort_quick_sort(array, from_idx, pivot);
    }
    
    if (pivot + 1 < to_idx - 1) {
        example_quicksort_Quicksort_quick_sort(array, pivot + 1, to_idx);
    } else {
        otterop_io_Console_println(otterop_lang_String_wrap("foo"));
    }
}

void example_quicksort_Quicksort_main(size_t args_cnt, char *args[]) {
    otterop_lang_Array_t *args_array = otterop_lang_Array_wrap_string(args_cnt, args);
    example_quicksort_Quicksort_quick_sort(args_array, 0, otterop_lang_Array_size(args_array));
    int i = 0;
    
    if (otterop_lang_Array_size(args_array) > 0) {
        otterop_lang_Array_set(args_array, 0, otterop_lang_String_wrap("bbbb"));
    }
    
    while (i < otterop_lang_Array_size(args_array)) {
        otterop_io_Console_println(otterop_lang_Array_get(args_array, i));
        i = i + 1;
    }
    example_quicksort_Quicksort_t *p = example_quicksort_Quicksort_new(2, 4.0, otterop_lang_String_wrap("hello world"));
    example_quicksort_Quicksort_hello(p);
    otterop_io_Console_println(example_quicksort_Quicksort_string(p));
}

example_quicksort_Quicksort_t *example_quicksort_Quicksort_new(int a, double b, otterop_lang_String_t *c) {
    example_quicksort_Quicksort_t *this = GC_malloc(sizeof(example_quicksort_Quicksort_t));
    this->a = a;
    this->b = b;
    this->c = c;
    return this;
}

otterop_lang_String_t *example_quicksort_Quicksort_string(example_quicksort_Quicksort_t *this) {
    return this->c;
}

int main(int args_cnt, char *args_arr[]) {
    args_cnt = args_cnt - 1;
    char **args = args_arr + 1;
    example_quicksort_Quicksort_main(args_cnt, args);
}