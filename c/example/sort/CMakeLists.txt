add_executable(example_sort
${CMAKE_CURRENT_LIST_DIR}/inheritance/animal.c
${CMAKE_CURRENT_LIST_DIR}/inheritance/dog.c
${CMAKE_CURRENT_LIST_DIR}/service/heapsort_service.c
${CMAKE_CURRENT_LIST_DIR}/service/pure/heapsort_service.c
${CMAKE_CURRENT_LIST_DIR}/service/pure/quicksort_service.c
${CMAKE_CURRENT_LIST_DIR}/service/pure/sort_service.c
${CMAKE_CURRENT_LIST_DIR}/service/quicksort_service.c
${CMAKE_CURRENT_LIST_DIR}/service/sort_service.c
${CMAKE_CURRENT_LIST_DIR}/tree/node.c
${CMAKE_CURRENT_LIST_DIR}/tree/pure/node.c
)
add_library(example_sort__lib STATIC
${CMAKE_CURRENT_LIST_DIR}/inheritance/animal.c
${CMAKE_CURRENT_LIST_DIR}/inheritance/dog.c
${CMAKE_CURRENT_LIST_DIR}/service/heapsort_service.c
${CMAKE_CURRENT_LIST_DIR}/service/pure/heapsort_service.c
${CMAKE_CURRENT_LIST_DIR}/service/pure/quicksort_service.c
${CMAKE_CURRENT_LIST_DIR}/service/pure/sort_service.c
${CMAKE_CURRENT_LIST_DIR}/service/quicksort_service.c
${CMAKE_CURRENT_LIST_DIR}/service/sort_service.c
${CMAKE_CURRENT_LIST_DIR}/tree/node.c
${CMAKE_CURRENT_LIST_DIR}/tree/pure/node.c
)
include(${CMAKE_CURRENT_LIST_DIR}/CMakeLists.manual.txt OPTIONAL)
