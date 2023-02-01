#ifndef __example_quicksort_Quicksort
#define __example_quicksort_Quicksort
#include <otterop/lang/array.h>
#include <otterop/lang/string.h>
#include <otterop/io/console.h>

typedef struct example_quicksort_Quicksort_s example_quicksort_Quicksort_t;




example_quicksort_Quicksort_t *example_quicksort_Quicksort_new(int a, double b, otterop_lang_String_t *c);

void example_quicksort_Quicksort_hello(example_quicksort_Quicksort_t *this);

void example_quicksort_Quicksort_quick_sort(otterop_lang_Array_t *array, int from_idx, int to_idx);

void example_quicksort_Quicksort_main(size_t args_cnt, char *args[]);

otterop_lang_String_t *example_quicksort_Quicksort_string(example_quicksort_Quicksort_t *this);

int main(int args_cnt, char *args_arr[]);
#endif
