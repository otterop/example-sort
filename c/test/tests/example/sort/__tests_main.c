#include "unity_fixture.h"

static void __run_all_tests(void) {
    RUN_TEST_GROUP(example_sort_service_TestHeapsortService);
    RUN_TEST_GROUP(example_sort_service_TestQuicksortService);
}

int main(int argc, const char *argv[]) {
    return UnityMain(argc, argv, __run_all_tests);
}
