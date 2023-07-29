#ifndef __example_sort_service_SortService
#define __example_sort_service_SortService
#include <otterop/lang/array.h>
#include <otterop/lang/string.h>

typedef struct example_sort_service_SortService_s example_sort_service_SortService_t;


example_sort_service_SortService_t *example_sort_service_SortService_new(void *implementation, otterop_lang_Array_t *(*sort)(void *, otterop_lang_Array_t *));


otterop_lang_Array_t *example_sort_service_SortService_sort(example_sort_service_SortService_t *this, otterop_lang_Array_t *array);
#endif
