#ifndef __example_sort_service_SortService
#define __example_sort_service_SortService
#include <otterop/lang/array.h>
#include <otterop/lang/string.h>

typedef struct example_sort_service_SortService_s example_sort_service_SortService_t;


example_sort_service_SortService_t *example_sort_service_SortService_new(void *implementation, void (*sort)(void *, otterop_lang_Array_t *, int, int));


void example_sort_service_SortService_sort(example_sort_service_SortService_t *this, otterop_lang_Array_t *array, int from_idx, int to_idx);
#endif
