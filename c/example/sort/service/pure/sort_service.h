#ifndef __example_sort_service_pure_SortService
#define __example_sort_service_pure_SortService
#include <otterop/lang/array.h>
#include <otterop/lang/string.h>

typedef struct example_sort_service_pure_SortService_s example_sort_service_pure_SortService_t;


example_sort_service_pure_SortService_t *example_sort_service_pure_SortService_new(void *implementation, char **(*sort)(void *, char **, size_t, size_t *));


char **example_sort_service_pure_SortService_sort(example_sort_service_pure_SortService_t *this, char **array, size_t array_cnt, size_t *_ret_cnt);
#endif
