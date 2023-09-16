#ifndef __example_sort_service_pure_QuicksortService
#define __example_sort_service_pure_QuicksortService
#include <otterop/lang/array.h>
#include <otterop/lang/string.h>
#include <example/sort/service/quicksort_service.h>
#include <example/sort/service/pure/sort_service.h>

typedef struct example_sort_service_pure_QuicksortService_s example_sort_service_pure_QuicksortService_t;
typedef struct example_sort_service_pure_QuicksortService_s example_sort_service_pure_QuicksortService_t;




example_sort_service_pure_QuicksortService_t *example_sort_service_pure_QuicksortService_new();

void example_sort_service_pure_QuicksortService_swap(example_sort_service_pure_QuicksortService_t *this, char **array, size_t array_cnt, int from_idx, int to_idx);


char **example_sort_service_pure_QuicksortService_sort(example_sort_service_pure_QuicksortService_t *this, char **array, size_t array_cnt, size_t *_ret_cnt);

example_sort_service_QuicksortService_t *example_sort_service_pure_QuicksortService_unwrap(example_sort_service_pure_QuicksortService_t *this);


example_sort_service_pure_SortService_t
*example_sort_service_pure_QuicksortService__to_example_sort_service_pure_SortService(example_sort_service_pure_QuicksortService_t *this);

#endif
