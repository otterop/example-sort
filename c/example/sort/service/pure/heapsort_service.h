#ifndef __example_sort_service_pure_HeapsortService
#define __example_sort_service_pure_HeapsortService
#include <otterop/lang/array.h>
#include <otterop/lang/string.h>
#include <example/sort/service/heapsort_service.h>
#include <example/sort/service/pure/sort_service.h>

typedef struct example_sort_service_pure_HeapsortService_s example_sort_service_pure_HeapsortService_t;
typedef struct example_sort_service_pure_HeapsortService_s example_sort_service_pure_HeapsortService_t;




example_sort_service_pure_HeapsortService_t *example_sort_service_pure_HeapsortService_new();

void example_sort_service_pure_HeapsortService_swap(example_sort_service_pure_HeapsortService_t *this, char **array, size_t array_cnt, int from_idx, int to_idx);


char **example_sort_service_pure_HeapsortService_sort(example_sort_service_pure_HeapsortService_t *this, char **array, size_t array_cnt, size_t *_ret_cnt);

example_sort_service_HeapsortService_t *example_sort_service_pure_HeapsortService_unwrap(example_sort_service_pure_HeapsortService_t *this);


example_sort_service_pure_SortService_t
*example_sort_service_pure_HeapsortService__to_example_sort_service_pure_SortService(example_sort_service_pure_HeapsortService_t *this);

#endif
