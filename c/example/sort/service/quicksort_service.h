#ifndef __example_sort_service_QuicksortService
#define __example_sort_service_QuicksortService
#include <otterop/lang/array.h>
#include <otterop/lang/string.h>
#include <example/sort/service/sort_service.h>

typedef struct example_sort_service_QuicksortService_s example_sort_service_QuicksortService_t;




example_sort_service_QuicksortService_t *example_sort_service_QuicksortService_new();

void example_sort_service_QuicksortService_swap(example_sort_service_QuicksortService_t *this, otterop_lang_Array_t *array, int from_idx, int to_idx);


otterop_lang_Array_t *example_sort_service_QuicksortService_sort(example_sort_service_QuicksortService_t *this, otterop_lang_Array_t *array);


example_sort_service_SortService_t
*example_sort_service_QuicksortService__to_example_sort_service_SortService(example_sort_service_QuicksortService_t *this);


#endif
