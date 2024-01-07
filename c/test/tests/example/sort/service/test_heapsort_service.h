#ifndef __example_sort_service_TestHeapsortService
#define __example_sort_service_TestHeapsortService
#include <otterop/lang/array.h>
#include <otterop/lang/string.h>
#include <otterop/test/test_base.h>

typedef struct example_sort_service_TestHeapsortService_s example_sort_service_TestHeapsortService_t;




void example_sort_service_TestHeapsortService_normal_sort(example_sort_service_TestHeapsortService_t *this);


void example_sort_service_TestHeapsortService_single_item(example_sort_service_TestHeapsortService_t *this);


void example_sort_service_TestHeapsortService_same_item(example_sort_service_TestHeapsortService_t *this);


void example_sort_service_TestHeapsortService_assert_true(example_sort_service_TestHeapsortService_t *this, int arg0, otterop_lang_String_t *arg1);
#endif
