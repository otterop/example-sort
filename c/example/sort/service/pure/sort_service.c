#include <gc.h>
#include <example/sort/service/pure/sort_service.h>

typedef struct example_sort_service_pure_SortService_s {
    void *implementation;
    char **(*sort)(void *, char **, size_t, size_t *);
} example_sort_service_pure_SortService_t;


example_sort_service_pure_SortService_t *example_sort_service_pure_SortService_new(void *implementation, char **(*sort)(void *, char **, size_t, size_t *)) {
    example_sort_service_pure_SortService_t *this = GC_malloc(sizeof(example_sort_service_pure_SortService_t));
    this->implementation = implementation;
    this->sort = sort;
    return this;
}


char **example_sort_service_pure_SortService_sort(example_sort_service_pure_SortService_t *this, char **array, size_t array_cnt, size_t *_ret_cnt);


char **example_sort_service_pure_SortService_sort(example_sort_service_pure_SortService_t *this, char **array, size_t array_cnt, size_t *_ret_cnt) {
    return this->sort(this->implementation, array, array_cnt, _ret_cnt);
}