#include <example/quicksort/quicksort.h>

typedef struct example_quicksort_Quicksort_s {
} example_quicksort_Quicksort_t;




void example_quicksort_Quicksort_main(size_t args_cnt, char *args[]) {
    otterop_lang_Array_t *args_array = otterop_lang_Array_wrap_string(args_cnt, args);
    example_quicksort_service_QuicksortService_quick_sort(args_array, 0, otterop_lang_Array_size(args_array));
    int i = 0;
    
    while (i < otterop_lang_Array_size(args_array)) {
        otterop_io_Console_println(otterop_lang_Array_get(args_array, i));
        i = i + 1;
    }
    otterop_lang_Result_of(otterop_lang_String_wrap(""), otterop_lang_String_wrap(""));
}

int main(int args_cnt, char *args_arr[]) {
    args_cnt = args_cnt - 1;
    char **args = args_arr + 1;
    example_quicksort_Quicksort_main(args_cnt, args);
}