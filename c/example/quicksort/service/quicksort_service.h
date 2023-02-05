#ifndef __example_quicksort_service_QuicksortService
#define __example_quicksort_service_QuicksortService
#include <otterop/lang/array.h>
#include <otterop/lang/string.h>

typedef struct example_quicksort_service_QuicksortService_s example_quicksort_service_QuicksortService_t;




void example_quicksort_service_QuicksortService_quick_sort(otterop_lang_Array_t *array, int from_idx, int to_idx);
#endif
