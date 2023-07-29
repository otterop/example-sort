#include <gc.h>
#include <example/sort/service/sort_service.h>

typedef struct example_sort_service_SortService_s {
    void *implementation;
    otterop_lang_Array_t *(*sort)(void *, otterop_lang_Array_t *);
} example_sort_service_SortService_t;


example_sort_service_SortService_t *example_sort_service_SortService_new(void *implementation, otterop_lang_Array_t *(*sort)(void *, otterop_lang_Array_t *)) {
    example_sort_service_SortService_t *this = GC_malloc(sizeof(example_sort_service_SortService_t));
    this->implementation = implementation;
    this->sort = sort;
    return this;
}


otterop_lang_Array_t *example_sort_service_SortService_sort(example_sort_service_SortService_t *this, otterop_lang_Array_t *array);


otterop_lang_Array_t *example_sort_service_SortService_sort(example_sort_service_SortService_t *this, otterop_lang_Array_t *array) {
    return this->sort(this->implementation, array);
}