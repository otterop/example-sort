#include <gc.h>
#include <example/sort/service/sort_service.h>

typedef struct example_sort_service_SortService_s {
    void *implementation;
    void (*sort)(void *, otterop_lang_Array_t *, int, int);
} example_sort_service_SortService_t;


example_sort_service_SortService_t *example_sort_service_SortService_new(void *implementation, void (*sort)(void *, otterop_lang_Array_t *, int, int)) {
    example_sort_service_SortService_t *this = GC_malloc(sizeof(example_sort_service_SortService_t));
    this->implementation = implementation;
    this->sort = sort;
    return this;
}


void example_sort_service_SortService_sort(example_sort_service_SortService_t *this, otterop_lang_Array_t *array, int from_idx, int to_idx);


void example_sort_service_SortService_sort(example_sort_service_SortService_t *this, otterop_lang_Array_t *array, int from_idx, int to_idx) {
    this->sort(this->implementation, array, from_idx, to_idx);
}