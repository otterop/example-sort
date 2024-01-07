add_executable(example_sort_tests
${CMAKE_CURRENT_LIST_DIR}/service/test_heapsort_service.c
${CMAKE_CURRENT_LIST_DIR}/service/test_quicksort_service.c
${CMAKE_CURRENT_LIST_DIR}/__tests_main.c
)
include(${CMAKE_CURRENT_LIST_DIR}/CMakeLists.manual.tests.txt OPTIONAL)
