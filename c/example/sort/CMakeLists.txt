add_executable(example_sort example/sort/sort.c
example/sort/service/sort_service.c
example/sort/service/quicksort_service.c)
include(./otterop/io/CMakeLists.txt)
find_static_library(gc GC)
target_link_libraries(example_sort otterop_io otterop_lang ${GC} pthread dl)
set_property(TARGET example_sort PROPERTY C_STANDARD 99)
