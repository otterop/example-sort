#ifndef __example_sort_service_HeapsortService
#define __example_sort_service_HeapsortService
#include <otterop/lang/array.h>
#include <otterop/lang/string.h>
#include <example/sort/service/sort_service.h>

typedef struct example_sort_service_HeapsortService_s example_sort_service_HeapsortService_t;




example_sort_service_HeapsortService_t *example_sort_service_HeapsortService_new();

void example_sort_service_HeapsortService_swap(example_sort_service_HeapsortService_t *this, otterop_lang_Array_t *array, int from_idx, int to_idx);


void example_sort_service_HeapsortService_sort(example_sort_service_HeapsortService_t *this, otterop_lang_Array_t *array, int from_idx, int to_idx);


example_sort_service_SortService_t
*example_sort_service_HeapsortService__to_example_sort_service_SortService(example_sort_service_HeapsortService_t *this);

#endif
