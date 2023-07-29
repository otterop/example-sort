#include <example/sort/sort.h>

typedef struct example_sort_Sort_s {
    int test;
} example_sort_Sort_t;


int example_sort_Sort_test;
int example_sort_Sort_test = 111;


void example_sort_Sort_main(size_t args_cnt, char *args[]) {
    otterop_lang_String_t *quick = otterop_lang_String_wrap("quick");
    otterop_lang_String_t *heap = otterop_lang_String_wrap("heap");
    otterop_lang_Array_t *args_array = otterop_lang_Array_wrap_string(args_cnt, args);
    
    if (otterop_lang_Array_size(args_array) < 1) {
        otterop_io_Console_println(otterop_lang_String_wrap("Usage: <quick|heap> ...values"));
        return ;
    }
    otterop_lang_String_t *sort_algorithm = otterop_lang_Array_get(args_array, 0);
    int is_quick = otterop_lang_String_compare_to(sort_algorithm, quick) == 0;
    int is_heap = otterop_lang_String_compare_to(sort_algorithm, heap) == 0;
    
    if (!(is_quick || is_heap)) {
        otterop_io_Console_println(otterop_lang_String_wrap("Usage: <quick|heap> ...values"));
        return ;
    }
    args_array = otterop_lang_Array_slice(args_array, 1, otterop_lang_Array_size(args_array));
    example_sort_service_SortService_t *sort_service = example_sort_service_QuicksortService__to_example_sort_service_SortService(example_sort_service_QuicksortService_new());
    
    if (is_heap) {
        sort_service = example_sort_service_HeapsortService__to_example_sort_service_SortService(example_sort_service_HeapsortService_new());
    }
    otterop_lang_Array_t *ret = example_sort_service_SortService_sort(sort_service, args_array);
    for (int i = 0; i < otterop_lang_Array_size(ret); i++) {
        otterop_io_Console_println(otterop_lang_Array_get(ret, i));
    }
    otterop_lang_Result_of(otterop_lang_String_wrap(""), otterop_lang_String_wrap(""));
}

int main(int args_cnt, char *args_arr[]) {
    args_cnt = args_cnt - 1;
    char **args = args_arr + 1;
    example_sort_Sort_main(args_cnt, args);
}