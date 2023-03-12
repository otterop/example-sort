#include <example/sort/sort.h>

typedef struct example_sort_Sort_s {
} example_sort_Sort_t;




void example_sort_Sort_main(size_t args_cnt, char *args[]) {
    otterop_lang_Array_t *args_array = otterop_lang_Array_wrap_string(args_cnt, args);
    example_sort_service_SortService_t *sort_service = example_sort_service_QuicksortService__to_example_sort_service_SortService(example_sort_service_QuicksortService_new());
    example_sort_service_SortService_sort(sort_service, args_array, 0, otterop_lang_Array_size(args_array));
    for (int i = 0; i < otterop_lang_Array_size(args_array); i++) {
        otterop_io_Console_println(otterop_lang_Array_get(args_array, i));
    }
    otterop_lang_Result_of(otterop_lang_String_wrap(""), otterop_lang_String_wrap(""));
}

int main(int args_cnt, char *args_arr[]) {
    args_cnt = args_cnt - 1;
    char **args = args_arr + 1;
    example_sort_Sort_main(args_cnt, args);
}