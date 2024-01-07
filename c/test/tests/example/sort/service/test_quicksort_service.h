#ifndef __example_sort_service_TestQuicksortService
#define __example_sort_service_TestQuicksortService
#include <otterop/lang/array.h>
#include <otterop/lang/string.h>
#include <otterop/test/test_base.h>

typedef struct example_sort_service_TestQuicksortService_s example_sort_service_TestQuicksortService_t;




void example_sort_service_TestQuicksortService_normal_sort(example_sort_service_TestQuicksortService_t *this);


void example_sort_service_TestQuicksortService_single_item(example_sort_service_TestQuicksortService_t *this);


void example_sort_service_TestQuicksortService_same_item(example_sort_service_TestQuicksortService_t *this);


void example_sort_service_TestQuicksortService_assert_true(example_sort_service_TestQuicksortService_t *this, int arg0, otterop_lang_String_t *arg1);
#endif
