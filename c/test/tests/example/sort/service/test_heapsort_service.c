#include "unity.h"
#include "unity_fixture.h"
#include <example/sort/service/test_heapsort_service.h>
#include <stdlib.h>
#include <example/sort/service/sort_service.h>
#include <example/sort/service/heapsort_service.h>

typedef struct example_sort_service_TestHeapsortService_s {
    otterop_test_TestBase_t *_super;
} example_sort_service_TestHeapsortService_t;




void example_sort_service_TestHeapsortService_normal_sort(example_sort_service_TestHeapsortService_t *this) {
    otterop_lang_String_t *item;
    otterop_lang_Array_t *items = otterop_lang_Array_new_array(3, (otterop_lang_String_t *) NULL);
    otterop_lang_Array_set(items, 0, otterop_lang_String_wrap("3"));
    otterop_lang_Array_set(items, 1, otterop_lang_String_wrap("2"));
    otterop_lang_Array_set(items, 2, otterop_lang_String_wrap("1"));
    example_sort_service_SortService_t *sort_service = example_sort_service_HeapsortService__to_example_sort_service_SortService(example_sort_service_HeapsortService_new());
    otterop_lang_Array_t *items_sorted = example_sort_service_SortService_sort(sort_service, items);
    example_sort_service_TestHeapsortService_assert_true(this, otterop_lang_Array_size(items_sorted) == 3, otterop_lang_String_wrap("itemsSorted should have size 3"));
    item = otterop_lang_Array_get(items_sorted, 0);
    example_sort_service_TestHeapsortService_assert_true(this, otterop_lang_String_compare_to(item, otterop_lang_String_wrap("1")) == 0, otterop_lang_String_wrap("expected 1 as first element"));
    item = otterop_lang_Array_get(items_sorted, 1);
    example_sort_service_TestHeapsortService_assert_true(this, otterop_lang_String_compare_to(item, otterop_lang_String_wrap("2")) == 0, otterop_lang_String_wrap("expected 2 as second element"));
    item = otterop_lang_Array_get(items_sorted, 2);
    example_sort_service_TestHeapsortService_assert_true(this, otterop_lang_String_compare_to(item, otterop_lang_String_wrap("3")) == 0, otterop_lang_String_wrap("expected 3 as third element"));
}

void example_sort_service_TestHeapsortService_single_item(example_sort_service_TestHeapsortService_t *this) {
    otterop_lang_String_t *item;
    otterop_lang_Array_t *items = otterop_lang_Array_new_array(1, (otterop_lang_String_t *) NULL);
    otterop_lang_Array_set(items, 0, otterop_lang_String_wrap("1"));
    example_sort_service_SortService_t *sort_service = example_sort_service_HeapsortService__to_example_sort_service_SortService(example_sort_service_HeapsortService_new());
    otterop_lang_Array_t *items_sorted = example_sort_service_SortService_sort(sort_service, items);
    example_sort_service_TestHeapsortService_assert_true(this, otterop_lang_Array_size(items_sorted) == 1, otterop_lang_String_wrap("itemsSorted should have size 1"));
    item = otterop_lang_Array_get(items_sorted, 0);
    example_sort_service_TestHeapsortService_assert_true(this, otterop_lang_String_compare_to(item, otterop_lang_String_wrap("1")) == 0, otterop_lang_String_wrap("expected 1 as first element"));
}

void example_sort_service_TestHeapsortService_same_item(example_sort_service_TestHeapsortService_t *this) {
    otterop_lang_String_t *item;
    otterop_lang_Array_t *items = otterop_lang_Array_new_array(3, (otterop_lang_String_t *) NULL);
    otterop_lang_Array_set(items, 0, otterop_lang_String_wrap("1"));
    otterop_lang_Array_set(items, 1, otterop_lang_String_wrap("1"));
    otterop_lang_Array_set(items, 2, otterop_lang_String_wrap("1"));
    example_sort_service_SortService_t *sort_service = example_sort_service_HeapsortService__to_example_sort_service_SortService(example_sort_service_HeapsortService_new());
    otterop_lang_Array_t *items_sorted = example_sort_service_SortService_sort(sort_service, items);
    example_sort_service_TestHeapsortService_assert_true(this, otterop_lang_Array_size(items_sorted) == 3, otterop_lang_String_wrap("itemsSorted should have size 3"));
    item = otterop_lang_Array_get(items_sorted, 0);
    example_sort_service_TestHeapsortService_assert_true(this, otterop_lang_String_compare_to(item, otterop_lang_String_wrap("1")) == 0, otterop_lang_String_wrap("expected 1 as first element"));
    item = otterop_lang_Array_get(items_sorted, 1);
    example_sort_service_TestHeapsortService_assert_true(this, otterop_lang_String_compare_to(item, otterop_lang_String_wrap("1")) == 0, otterop_lang_String_wrap("expected 1 as second element"));
    item = otterop_lang_Array_get(items_sorted, 2);
    example_sort_service_TestHeapsortService_assert_true(this, otterop_lang_String_compare_to(item, otterop_lang_String_wrap("1")) == 0, otterop_lang_String_wrap("expected 1 as third element"));
}

void example_sort_service_TestHeapsortService_assert_true(example_sort_service_TestHeapsortService_t *this, int arg0, otterop_lang_String_t *arg1) {
    return  otterop_test_TestBase_assert_true(this->_super, arg0, arg1);
}

example_sort_service_TestHeapsortService_t* example_sort_service_TestHeapsortService_new() {
    example_sort_service_TestHeapsortService_t *this = GC_malloc(sizeof(*this));
    this->_super = otterop_test_TestBase_new();
    return this;
}

TEST_GROUP(example_sort_service_TestHeapsortService);

TEST_SETUP(example_sort_service_TestHeapsortService) {}

TEST_TEAR_DOWN(example_sort_service_TestHeapsortService) {}

TEST(example_sort_service_TestHeapsortService, example_sort_service_TestHeapsortService_normal_sort) {
    example_sort_service_TestHeapsortService_normal_sort(example_sort_service_TestHeapsortService_new());
}

TEST(example_sort_service_TestHeapsortService, example_sort_service_TestHeapsortService_single_item) {
    example_sort_service_TestHeapsortService_single_item(example_sort_service_TestHeapsortService_new());
}

TEST(example_sort_service_TestHeapsortService, example_sort_service_TestHeapsortService_same_item) {
    example_sort_service_TestHeapsortService_same_item(example_sort_service_TestHeapsortService_new());
}

TEST_GROUP_RUNNER(example_sort_service_TestHeapsortService) {
    RUN_TEST_CASE(example_sort_service_TestHeapsortService, example_sort_service_TestHeapsortService_normal_sort);
    RUN_TEST_CASE(example_sort_service_TestHeapsortService, example_sort_service_TestHeapsortService_single_item);
    RUN_TEST_CASE(example_sort_service_TestHeapsortService, example_sort_service_TestHeapsortService_same_item);
}
